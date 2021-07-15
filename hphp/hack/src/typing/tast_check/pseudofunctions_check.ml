(*
 * Copyright (c) 2018, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

open Aast
module Env = Tast_env
module SN = Naming_special_names
module Partial = Partial_provider

let handler =
  object
    inherit Tast_visitor.handler_base

    method! at_expr env ((p, _), _, x) =
      if Partial.should_check_error (Env.get_mode env) 4016 then
        match x with
        (* isset($var) *)
        | Call ((_, _, Id (_, pseudo_func)), _, [(_, _, Lvar _)], _)
        (* isset($var->thing) but not isset($foo->$bar) *)
        | Call
            ( (_, _, Id (_, pseudo_func)),
              _,
              [(_, _, Obj_get (_, (_, _, Id _), _, false))],
              _ )
        (* isset($var::thing) but not isset($foo::$bar) *)
        | Call
            ( (_, _, Id (_, pseudo_func)),
              _,
              [(_, _, Class_get (_, CGexpr (_, _, Id _), _))],
              _ )
          when String.equal pseudo_func SN.PseudoFunctions.isset ->
          Errors.isset_in_strict p
        | _ -> ()
  end
