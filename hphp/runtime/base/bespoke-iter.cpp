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

#include "hphp/runtime/base/bespoke-iter.h"

#include "hphp/runtime/base/bespoke/struct-dict.h"

namespace HPHP::bespoke {

bool IsStructDict(const ArrayData* ad) {
  if (ad->isVanilla()) return false;
  auto const index = BespokeArray::asBespoke(ad)->layoutIndex();
  return StructLayout::IsStructLayout(index);
}

TypedValue GetStructDictKey(const ArrayData* ad, int64_t pos) {
  return StructDict::GetPosKey(StructDict::As(ad), pos);
}

TypedValue GetStructDictVal(const ArrayData* ad, int64_t pos) {
  return StructDict::GetPosVal(StructDict::As(ad), pos);
}

tv_lval GetStructDictLval(ArrayData* ad, int64_t pos) {
  auto const sd = StructDict::As(ad);
  auto const slot = sd->rawPositions()[pos];
  return tv_lval{&sd->rawTypes()[slot], &sd->rawValues()[slot]};
}

}
