// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use crate::typing_env_types::LocalId;
pub use oxidized::typing_local_types::ExpressionId;
use typing_collections_rust::Map;
use typing_defs_rust::Ty;

#[derive(Debug, Copy, Clone)]
pub struct Local<'a>(pub Ty<'a>, pub ExpressionId);

impl<'a> Local<'a> {
    pub fn to_oxidized(&self) -> oxidized::typing_local_types::Local {
        let Local(ty, eid) = self;
        oxidized::typing_local_types::Local(ty.to_oxidized(), eid.clone())
    }
}

pub type TypingLocalTypes<'a> = Map<'a, LocalId<'a>, &'a Local<'a>>;
