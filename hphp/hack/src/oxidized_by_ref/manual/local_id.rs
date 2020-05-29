// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use serde::Serialize;

use ocamlrep_derive::ToOcamlRep;

#[derive(
    Copy, Clone, Debug, Eq, Hash, Ord, PartialEq, PartialOrd, Serialize, ToOcamlRep
)]
pub struct LocalId<'a>(isize, &'a str);

impl<'a> LocalId<'a> {
    pub fn new_unscoped_in(name: &'a str) -> Self {
        Self(0, name)
    }

    pub fn name(self) -> &'a str {
        self.1
    }

    pub fn to_oxidized(&self) -> oxidized::local_id::LocalId {
        let &LocalId(id, name) = self;
        (id, name.to_string())
    }
}

impl<'a> From<&'a oxidized::local_id::LocalId> for LocalId<'a> {
    fn from(x: &'a oxidized::local_id::LocalId) -> LocalId<'a> {
        let (a, b) = x;
        LocalId(*a, b.as_str())
    }
}

pub mod map {
    pub type Map<'a, T> = arena_collections::SortedAssocList<'a, super::LocalId<'a>, T>;
}

pub mod set {
    pub type Set<'a> = arena_collections::SortedSet<'a, super::LocalId<'a>>;
}
