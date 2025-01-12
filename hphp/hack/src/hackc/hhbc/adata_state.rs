// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.
use crate::{hhas_adata::HhasAdata, typed_value::TypedValue};
use hash::HashMap;

#[derive(Debug, Default)]
pub struct AdataState<'arena> {
    pub array_identifier_counter: usize,
    pub array_identifier_map: HashMap<TypedValue<'arena>, &'arena str>,
    pub adata: Vec<HhasAdata<'arena>>,
}
