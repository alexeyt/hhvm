/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

/*
IR function inliner

Inlining functions at the IR level can be complex, particularly when dealing
with async callees. All inlined regions are setup the same way, though later
optimization passes may attempt to elide elements of this inititalization,
particularly the DefinlineFP. Below is an annotated version of this setup.

  StStk ...  # Stores initiated for parameters as if this was an ordinary call.

  #
  # This is where this module starts to emit instructions, the stores and spills
  # are generated by passing arguments and emitting FCall* instructions, prior
  # to having made a decision about inlining.
  #

  LdStk ...     # The inliner first loads all of the arguments off of the stack,
                # effectively popping them. These loads and the preceding
                # stores are generally elided by load and store elimination.

  BeginInlining # Sets up memory effects for the inlined frame and returns a new
                # fp that can be used for stores into the frame.

  InlineCall    # This instruction links the new frame to the old frame via the
                # m_sfp field and loads the new frame into rvmfp(). It can be
                # thought of as doing the work of a Call.

  StLoc ...     # At this point the arguments are stored back to the frame
                # locations for their corresponding locals in the callee. N.B.
                # that in memory these are the same addresses as the stack
                # locations above.

Once the inlined function returns, the callee must be torn down and the return
value moved into the caller. The sequence for this is annotated below.

  tx := LdLoc ... # Locals are decref'ed inline. A GenericRetDecRefs is never
  DecRef tx       # emitted for inlined regions, in the hopes that IncRefs from
  ...             # pushing arguments will cancel DecRefs from the return.

  ty := LdFrameThis     # The context is DecRef'ed
  DecRef ty

  tz := LdStk     # The InlineReturn instruction will restore rvmfp() to the
  InlineReturn    # Calling frame. The frame itself may still be used but the
  StStk tz        # locals and context have explicitly been decrefed.

  EndInlining     # This instruction marks the end of the inlined region, beyond
                  # this point the frame should no longer considered to be live.

We also support inlining of async functions. Returning from an inlined region
is handled differently depending on whether or not the caller entered the
region using FCall with an async eager offset. If the offset was specified,
the execution continues at that offset. Otherwise the result is wrapped in
a StaticWaitHandle and the execution continues at the next opcode.

Async functions may also exit by suspending. The suspend block is annotated
below:

tCallee := DefLabel   # The callee region may suspend from multiple locations,
                      # but after constructing the waithandle they must all
                      # branch to a common suspend block which will continue
                      # execution of the caller at the opcode following FCall,
                      # usually an Await.

InlineReturn          # The return sequence looks the same as a regular call but
EndInlining           # rather than killing the frame it has been teleported to
                      # the heap.

If a FCall with an async eager offset was followed by an Await, this HHIR
sequence follows the InlineSuspend:

tState := LdWhState   # Check the state of the waithandle representing the
JmpZero succeeded     # suspended callee. It may have finished in meanwhile due
EqInt 1               # to ability of surprise hooks to execute arbitrary Hack
JmpNZero failed       # code, so side-exit if that's the case.

tCaller := CreateAFWH # An AFWH is constructed for the caller, as Await must
                      # suspend if waithandle is not finished.

CheckSurpriseFlags    # The caller suspend hook is entered if requested.

RetCtrl               # Control is returned, suspending the caller. In the case
                      # of nested inlined FCall instructions this return would
                      # simply be a branch to the suspend block for the next
                      # most nested callee.

Calls to async functions without async eager offset use an analogous suspend
block which side-exits rather than continuing at the next opcode. This is done
so that the fast path through the callee will return only StaticWaitHandles
which may be elided by the DCE and simplifier passes.

Inlined regions maintain the following invariants, which later optimization
passes may depend on (most notably DCE and partial-DCE):

  - Every callee region must contain a single BeginInlining
  - BeginInlining must dominate every instruction within the callee.
  - Excluding side-exits and early returns, EndInlining must post-dominate
    every instruction in the callee.
  - The callee must contain a return or await.

When a callee contains awaits, these will be implemented as either an await of
the nested callee (in the case of FCall) or a return from the callee and
side-exit from the caller, unless the callee does not contain a return (e.g.
the caller was profiled as always suspending), in which case the callee will
return the waithandle to the caller rather than side-exiting in the case of a
FCall without async eager offset.

Below is an unmaintainable diagram of a pair of an async function inlined into a
pair of callers with and without (*) async eager offset respectively,


Outer:                                 | Inner:
  ...                                  |   ...
  FCall "Inner" aeo1 or FCall "Inner"  |   FCall "Other" aeo2
  Await                                |   Await
 aeo1:                                 |  aeo2:
  ...                                  |   ...

          ...
           |
           v
+-------------------+
| ...               |
| BeginInlining     |
| InlineCall        |
| StLoc             |
| ...               |
+-------------------+
           |
           v
+-------------------+
| ...               |
| tx = Call "Other" |
| ty = LdTVAux tx   |
| JmpNZero ty       | -> +---------------------+
+-------------------+    | ta = CreateAWFH tx  |
           |             | SuspendHook         |
           v             | StStk ta            |
+-------------------+    | Jmp suspendTarget   |--- or (*) ----+
| StStk tx          |    +---------------------+               |
| ... // aeo2       |               |                          v
| Jmp returnTarget  |               v               +---------------------+
+-------------------+    +---------------------+    | tb = LdStk          |
           |             | tb = LdStk          |    | InlineReturn        |
           v             | InlineSuspend       |    | EndInlining         |
+-------------------+    | StStk tb            |    | StStk tb            |
| DecRef Locals     |    | tc = LdStk          |    +---------------------+
| DecRef This       |    | te = LdWhState tc   |               v
| tr = LdStk        |    | JmpZero te          |--------->*Side Exit*
| InlineReturn      |    +---------------------+
| EndInlining       |               |
| StStk tr          |               |
| CreateSSWH (*)    |               v
+-------------------+    +---------------------+
           |             | td = CreateAFWH tc  |
           v             | SuspendHook         |
          ...            | RetCtrl td          |
                         +---------------------+
*/

#include "hphp/runtime/vm/jit/irgen-inlining.h"

#include "hphp/runtime/vm/jit/analysis.h"
#include "hphp/runtime/vm/jit/mutation.h"

#include "hphp/runtime/vm/jit/irgen.h"
#include "hphp/runtime/vm/jit/irgen-call.h"
#include "hphp/runtime/vm/jit/irgen-control.h"
#include "hphp/runtime/vm/jit/irgen-create.h"
#include "hphp/runtime/vm/jit/irgen-exit.h"
#include "hphp/runtime/vm/jit/irgen-internal.h"
#include "hphp/runtime/vm/jit/irgen-func-prologue.h"
#include "hphp/runtime/vm/jit/irgen-sprop-global.h"

#include "hphp/runtime/vm/hhbc-codec.h"
#include "hphp/runtime/vm/resumable.h"

namespace HPHP { namespace jit { namespace irgen {

bool isInlining(const IRGS& env) {
  return env.inlineState.depth > 0;
}

uint16_t inlineDepth(const IRGS& env) {
  return env.inlineState.depth;
}

void beginInlining(IRGS& env,
                   const Func* target,
                   const FCallArgs& fca,
                   SSATmp* ctx,
                   bool dynamicCall,
                   Op writeArOpc,
                   SrcKey startSk,
                   Offset callBcOffset,
                   InlineReturnTarget returnTarget,
                   int cost) {
  assertx(callBcOffset >= 0 && "callBcOffset before beginning of caller");
  // curFunc is null when called from conjureBeginInlining
  assertx((!curFunc(env) ||
          curFunc(env)->base() + callBcOffset < curFunc(env)->past()) &&
         "callBcOffset past end of caller");
  assertx(fca.numArgs >= target->numRequiredParams());
  assertx(fca.numArgs <= target->numNonVariadicParams());
  assertx(!fca.hasUnpack() || fca.numArgs == target->numNonVariadicParams());
  assertx(!fca.hasUnpack() || target->hasVariadicCaptureParam());

  FTRACE(1, "[[[ begin inlining: {}\n", target->fullName()->data());

  auto const numArgsInclUnpack = fca.numArgs + (fca.hasUnpack() ? 1U : 0U);

  // For cost calculation, use the most permissive coeffect
  auto const coeffects =
    curFunc(env) ? curCoeffects(env) : RuntimeCoeffects::none();

  auto const callFlags = cns(env, CallFlags(
    fca.hasGenerics(),
    dynamicCall,
    returnTarget.asyncEagerOffset != kInvalidOffset,
    0, // call offset unused by the logic below
    0,
    coeffects
  ).value());

  // Callee checks and input initialization.
  emitCalleeGenericsChecks(env, target, callFlags, fca.hasGenerics());
  emitCalleeDynamicCallChecks(env, target, callFlags);
  emitCalleeCoeffectChecks(env, target, callFlags);
  emitCalleeImplicitContextChecks(env, target);
  emitInitFuncInputs(env, target, numArgsInclUnpack);

  auto const closure = target->isClosureBody()
    ? gen(env, AssertType, Type::ExactObj(target->implCls()), ctx)
    : nullptr;

  ctx = [&] () -> SSATmp* {
    if (target->isClosureBody()) {
      if (!target->cls()) return cns(env, nullptr);
      if (target->isStatic()) {
        return gen(env, LdClosureCls, Type::SubCls(target->cls()), closure);
      }
      auto const closureCtx =
        gen(env, LdClosureThis, Type::SubObj(target->cls()), closure);
      gen(env, IncRef, closureCtx);
      return closureCtx;
    }

    if (!target->cls()) {
      assertx(ctx->isA(TNullptr));
      return ctx;
    }
    assertx(!ctx->type().maybe(TNullptr));

    if (ctx->isA(TBottom)) return ctx;

    if (target->isStatic()) {
      assertx(ctx->isA(TCls));
      if (ctx->hasConstVal(TCls)) {
        return ctx;
      }

      auto const ty = ctx->type() & Type::SubCls(target->cls());
      if (ctx->type() <= ty) return ctx;
      return gen(env, AssertType, ty, ctx);
    }

    assertx(ctx->type().maybe(TObj));
    auto const ty = ctx->type() & thisTypeFromFunc(target);
    if (ctx->type() <= ty) return ctx;
    return gen(env, AssertType, ty, ctx);
  }();

  auto const numTotalInputs =
    target->numParams() + (target->hasReifiedGenerics() ? 1U : 0U);
  jit::vector<SSATmp*> inputs{numTotalInputs};
  for (auto i = 0; i < numTotalInputs; ++i) {
    inputs[numTotalInputs - i - 1] = popC(env);
  }

  // NB: Now that we've popped the callee's arguments off the stack
  // and thus modified the caller's frame state, we're committed to
  // inlining. If we bail out from now on, the caller's frame state
  // will be as if the arguments don't exist on the stack (even though
  // they do).

  // The top of the stack now points to the space for ActRec.
  IRSPRelOffset calleeAROff = spOffBCFromIRSP(env);

  auto const calleeFP = gen(
    env,
    BeginInlining,
    BeginInliningData{calleeAROff, target, cost, int(numArgsInclUnpack)},
    sp(env),
    fp(env)
  );

  StFrameMetaData meta;
  meta.callBCOff     = callBcOffset;
  meta.asyncEagerReturn = returnTarget.asyncEagerOffset != kInvalidOffset;

  gen(env, StFrameMeta, meta, calleeFP);
  gen(env, StFrameFunc, FuncData { target }, calleeFP);

  InlineCallData data;
  data.spOffset = calleeAROff;
  data.syncVmpc = nullptr;

  assertx(startSk.func() == target &&
          startSk.offset() == target->getEntryForNumArgs(numArgsInclUnpack) &&
          startSk.resumeMode() == ResumeMode::None);

  env.inlineState.depth++;
  env.inlineState.costStack.emplace_back(env.inlineState.cost);
  env.inlineState.returnTarget.emplace_back(returnTarget);
  env.inlineState.bcStateStack.emplace_back(env.bcState);
  env.inlineState.cost += cost;
  env.inlineState.stackDepth += target->maxStackCells();
  env.bcState = startSk;
  updateMarker(env);

  gen(env, InlineCall, data, calleeFP, fp(env));

  if (!(ctx->type() <= TNullptr)) gen(env, StFrameCtx, fp(env), ctx);

  // We have entered a new frame.
  updateMarker(env);
  env.irb->exceptionStackBoundary();

  for (auto i = 0; i < numTotalInputs; ++i) {
    stLocRaw(env, i, calleeFP, inputs[i]);
  }
  emitInitFuncLocals(env, target, closure);

  assertx(startSk.hasThis() == startSk.func()->hasThisInBody());
  assertx(
    ctx->isA(TBottom) ||
    (ctx->isA(TNullptr) && !target->cls()) ||
    (ctx->isA(TCls) && target->cls() && target->isStatic()) ||
    (ctx->isA(TObj) && target->cls() && !target->isStatic())
  );
}

void conjureBeginInlining(IRGS& env,
                          const Func* func,
                          SrcKey startSk,
                          Type thisType,
                          const std::vector<Type>& args,
                          InlineReturnTarget returnTarget) {
  auto conjure = [&](Type t) {
    return t.admitsSingleVal() ? cns(env, t) : gen(env, Conjure, t);
  };

  always_assert(isFCall(env.context.initSrcKey.op()));
  always_assert(thisType != TBottom);
  auto const hasUnpack = args.size() > func->numNonVariadicParams();
  auto const numParams = safe_cast<uint32_t>(args.size()) - (hasUnpack ? 1 : 0);

  // Push space for out parameters
  for (auto i = 0; i < func->numInOutParams(); i++) {
    push(env, cns(env, TUninit));
  }

  allocActRec(env);
  for (auto const argType : args) {
    push(env, conjure(argType));
  }

  // beginInlining() assumes synced state.
  updateMarker(env);
  env.irb->exceptionStackBoundary();

  auto const flags = hasUnpack
    ? FCallArgs::Flags::HasUnpack : FCallArgs::Flags::None;

  // thisType is the context type inside the closure, but beginInlining()'s ctx
  // is a context given to the prologue.
  auto const ctx = func->isClosureBody()
    ? conjure(Type::ExactObj(func->implCls()))
    : conjure(thisType);

  // FIXME: conjure generics; otherwise this translation will have tiny cost
  // as it will fail early due to generics mismatch, causing us to inline
  // huge functions if they have reified generics
  beginInlining(
    env,
    func,
    FCallArgs(flags, numParams, 1, nullptr, kInvalidOffset, nullptr),
    ctx,
    false,
    env.context.initSrcKey.op(),
    startSk,
    0 /* callBcOffset */,
    returnTarget,
    9 /* cost */
  );
}

namespace {
struct InlineFrame {
  SrcKey bcState;
  InlineReturnTarget target;
};

InlineFrame popInlineFrame(IRGS& env) {
  always_assert(env.inlineState.depth > 0);
  always_assert(env.inlineState.returnTarget.size() > 0);
  always_assert(env.inlineState.bcStateStack.size() > 0);

  InlineFrame inlineFrame {
    env.bcState,
    env.inlineState.returnTarget.back()
  };

  // Pop the inlined frame in our IRGS.  Be careful between here and the
  // updateMarker() below, where the caller state isn't entirely set up.
  env.inlineState.depth--;
  env.inlineState.cost = env.inlineState.costStack.back();
  env.inlineState.costStack.pop_back();
  env.inlineState.stackDepth -= inlineFrame.bcState.func()->maxStackCells();
  env.inlineState.returnTarget.pop_back();
  env.bcState = env.inlineState.bcStateStack.back();
  env.inlineState.bcStateStack.pop_back();
  updateMarker(env);

  return inlineFrame;
}

void pushInlineFrame(IRGS& env, const InlineFrame& inlineFrame) {
  // No need to preserve and update cost, as we are not going to recursively
  // inline anything during a single Jmp opcode we are restoring the state for.
  env.inlineState.depth++;
  env.inlineState.costStack.emplace_back(env.inlineState.cost);
  env.inlineState.returnTarget.emplace_back(inlineFrame.target);
  env.inlineState.bcStateStack.emplace_back(env.bcState);
  env.inlineState.stackDepth += inlineFrame.bcState.func()->maxStackCells();
  env.bcState = inlineFrame.bcState;
  updateMarker(env);
}

InlineFrame implInlineReturn(IRGS& env, bool suspend) {
  assertx(resumeMode(env) == ResumeMode::None);

  auto const& fs = env.irb->fs();

  // The offset of our caller's FP relative to our own.
  auto const callerFPOff =
    // Offset of the (unchanged) vmsp relative to our fp...
    - fs.irSPOff()
    // ...plus the offset of our parent's fp relative to vmsp.
    + FPInvOffset{0}.to<IRSPRelOffset>(fs.callerIRSPOff()).offset;

  auto const calleeFp = fp(env);
  auto const prevFp = calleeFp->inst()->src(1);
  // Return to the caller function.
  gen(env, InlineReturn, FPRelOffsetData { callerFPOff }, fp(env), prevFp);
  gen(env, EndInlining, calleeFp);

  return popInlineFrame(env);
}

void implReturnBlock(IRGS& env, const RegionDesc& calleeRegion) {
  auto const rt = env.inlineState.returnTarget.back();

  // The IR instructions should be associated with one of the return bytecodes;
  // all predecessors of this block should be valid options. Choose the hottest
  // predecessor in order to get the most-likely DecRefProfiles.
  auto const curBlock = env.irb->curBlock();
  always_assert(curBlock && !curBlock->preds().empty());
  auto best = curBlock->preds().front().inst();
  for (auto const& pred : curBlock->preds()) {
    if (pred.inst()->block()->profCount() > best->block()->profCount()) {
      best = pred.inst();
    }
  }
  auto const bcContext = best->bcctx();
  env.bcState.setOffset(bcContext.marker.sk().offset());
  env.irb->setCurMarker(bcContext.marker);

  // At this point, env.profTransIDs and env.region are already set with the
  // caller's information.  We temporarily reset both of these with the callee's
  // information, so that the HHIR instructions emitted for the RetC have their
  // markers associated with the callee.  This is necessary to successfully look
  // up any profile data associated with them.
  auto const callerProfTransIDs = env.profTransIDs;
  auto const callerRegion       = env.region;
  SCOPE_EXIT{
    env.profTransIDs = callerProfTransIDs;
    env.region       = callerRegion;
  };
  auto const& calleeTransIDs = bcContext.marker.profTransIDs();
  env.profTransIDs = calleeTransIDs;
  env.region = &calleeRegion;
  updateMarker(env);
  env.irb->resetCurIROff(bcContext.iroff + 1);

  decRefLocalsInline(env);
  decRefThis(env);

  auto const callee = curFunc(env);

  auto const nret = callee->numInOutParams() + 1;
  jit::vector<SSATmp*> retVals{nret, nullptr};
  for (auto& v : retVals) v = pop(env, DataTypeGeneric);

  implInlineReturn(env, false);

  // Pop the NullUninit values from the stack.
  for (uint32_t idx = 0; idx < nret - 1; ++idx) pop(env);

  if (!callee->isAsyncFunction()) {
    // Non-async function. Just push the result on the stack.
    if (nret > 1) {
      for (int32_t idx = nret - 2; idx >= 0; --idx) {
        auto const val = retVals[idx];
        push(env, gen(env, AssertType, callOutType(callee, idx), val));
      }
    }
    push(env, gen(env, AssertType, callReturnType(callee), retVals.back()));
    return;
  }

  assertx(nret == 1);
  auto const retVal =
    gen(env, AssertType, awaitedCallReturnType(callee), retVals.back());
  if (rt.asyncEagerOffset == kInvalidOffset) {
    // Async eager return was not requested. Box the returned value and
    // continue execution at the next opcode.
    push(env, gen(env, CreateSSWH, retVal));
  } else {
    // Async eager return was requested. Continue execution at the async eager
    // offset with the returned value.
    push(env, retVal);
    jmpImpl(env, bcOff(env) + rt.asyncEagerOffset);
  }
}

bool implSuspendBlock(IRGS& env, bool exitOnAwait) {
  auto const rt = env.inlineState.returnTarget.back();
  // Start a new IR block to hold the remainder of this block.
  auto const did_start = env.irb->startBlock(rt.suspendTarget, false);
  if (!did_start) return false;

  // We strive to inline regions which will mostly eagerly terminate.
  if (exitOnAwait) hint(env, Block::Hint::Unlikely);

  assertx(curFunc(env)->isAsyncFunction());
  auto block = rt.suspendTarget;
  auto const label = env.unit.defLabel(1, block, env.irb->nextBCContext());
  auto const wh = label->dst(0);
  retypeDests(label, &env.unit);

  auto const inlineFrame = implInlineReturn(env, exitOnAwait);
  SCOPE_EXIT { if (exitOnAwait) pushInlineFrame(env, inlineFrame); };

  push(env, wh);
  if (exitOnAwait) {
    if (rt.asyncEagerOffset == kInvalidOffset) {
      gen(env, Jmp, makeExit(env, nextSrcKey(env)));
    } else {
      jmpImpl(env, nextBcOff(env));
    }
  }
  return true;
}

////////////////////////////////////////////////////////////////////////////////
}

void implInlineReturn(IRGS& env) {
  implInlineReturn(env, false);
}

bool endInlining(IRGS& env, const RegionDesc& calleeRegion) {
  auto const rt = env.inlineState.returnTarget.back();

  if (env.irb->canStartBlock(rt.callerTarget)) {
    implSuspendBlock(env, true);
  } else {
    return implSuspendBlock(env, false);
  }

  auto const did_start = env.irb->startBlock(rt.callerTarget, false);
  always_assert(did_start);

  implReturnBlock(env, calleeRegion);

  FTRACE(1, "]]] end inlining: {}\n", curFunc(env)->fullName()->data());
  return true;
}

bool conjureEndInlining(IRGS& env, const RegionDesc& calleeRegion,
                        bool builtin) {
  if (!builtin) {
    if (!endInlining(env, calleeRegion)) return false;
  }
  gen(env, ConjureUse, pop(env));
  gen(env, EndBlock, ASSERT_REASON);
  return true;
}

void retFromInlined(IRGS& env) {
  gen(env, Jmp, env.inlineState.returnTarget.back().callerTarget);
}

void suspendFromInlined(IRGS& env, SSATmp* waitHandle) {
  gen(env, Jmp, env.inlineState.returnTarget.back().suspendTarget, waitHandle);
}

//////////////////////////////////////////////////////////////////////

}}}
