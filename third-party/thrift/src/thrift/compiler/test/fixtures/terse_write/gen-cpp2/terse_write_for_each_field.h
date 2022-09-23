/**
 * Autogenerated by Thrift for src/terse_write.thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated @nocommit
 */
#pragma once

#include "thrift/compiler/test/fixtures/terse_write/gen-cpp2/terse_write_metadata.h"
#include <thrift/lib/cpp2/visitation/for_each.h>

namespace apache {
namespace thrift {
namespace detail {

template <>
struct ForEachField<::facebook::thrift::test::terse_write::MyStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::MyStructWithCustomDefault> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).field1_ref()...);
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::StructLevelTerseStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).bool_field_ref()...);
    f(1, static_cast<T&&>(t).byte_field_ref()...);
    f(2, static_cast<T&&>(t).short_field_ref()...);
    f(3, static_cast<T&&>(t).int_field_ref()...);
    f(4, static_cast<T&&>(t).long_field_ref()...);
    f(5, static_cast<T&&>(t).float_field_ref()...);
    f(6, static_cast<T&&>(t).double_field_ref()...);
    f(7, static_cast<T&&>(t).string_field_ref()...);
    f(8, static_cast<T&&>(t).binary_field_ref()...);
    f(9, static_cast<T&&>(t).enum_field_ref()...);
    f(10, static_cast<T&&>(t).list_field_ref()...);
    f(11, static_cast<T&&>(t).set_field_ref()...);
    f(12, static_cast<T&&>(t).map_field_ref()...);
    f(13, static_cast<T&&>(t).struct_field_ref()...);
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::FieldLevelTerseStruct> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).terse_bool_field_ref()...);
    f(1, static_cast<T&&>(t).terse_byte_field_ref()...);
    f(2, static_cast<T&&>(t).terse_short_field_ref()...);
    f(3, static_cast<T&&>(t).terse_int_field_ref()...);
    f(4, static_cast<T&&>(t).terse_long_field_ref()...);
    f(5, static_cast<T&&>(t).terse_float_field_ref()...);
    f(6, static_cast<T&&>(t).terse_double_field_ref()...);
    f(7, static_cast<T&&>(t).terse_string_field_ref()...);
    f(8, static_cast<T&&>(t).terse_binary_field_ref()...);
    f(9, static_cast<T&&>(t).terse_enum_field_ref()...);
    f(10, static_cast<T&&>(t).terse_list_field_ref()...);
    f(11, static_cast<T&&>(t).terse_set_field_ref()...);
    f(12, static_cast<T&&>(t).terse_map_field_ref()...);
    f(13, static_cast<T&&>(t).terse_struct_field_ref()...);
    f(14, static_cast<T&&>(t).bool_field_ref()...);
    f(15, static_cast<T&&>(t).byte_field_ref()...);
    f(16, static_cast<T&&>(t).short_field_ref()...);
    f(17, static_cast<T&&>(t).int_field_ref()...);
    f(18, static_cast<T&&>(t).long_field_ref()...);
    f(19, static_cast<T&&>(t).float_field_ref()...);
    f(20, static_cast<T&&>(t).double_field_ref()...);
    f(21, static_cast<T&&>(t).string_field_ref()...);
    f(22, static_cast<T&&>(t).binary_field_ref()...);
    f(23, static_cast<T&&>(t).enum_field_ref()...);
    f(24, static_cast<T&&>(t).list_field_ref()...);
    f(25, static_cast<T&&>(t).set_field_ref()...);
    f(26, static_cast<T&&>(t).map_field_ref()...);
    f(27, static_cast<T&&>(t).struct_field_ref()...);
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::TerseStructWithCustomDefault> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).bool_field_ref()...);
    f(1, static_cast<T&&>(t).byte_field_ref()...);
    f(2, static_cast<T&&>(t).short_field_ref()...);
    f(3, static_cast<T&&>(t).int_field_ref()...);
    f(4, static_cast<T&&>(t).long_field_ref()...);
    f(5, static_cast<T&&>(t).float_field_ref()...);
    f(6, static_cast<T&&>(t).double_field_ref()...);
    f(7, static_cast<T&&>(t).string_field_ref()...);
    f(8, static_cast<T&&>(t).binary_field_ref()...);
    f(9, static_cast<T&&>(t).enum_field_ref()...);
    f(10, static_cast<T&&>(t).list_field_ref()...);
    f(11, static_cast<T&&>(t).set_field_ref()...);
    f(12, static_cast<T&&>(t).map_field_ref()...);
    f(13, static_cast<T&&>(t).struct_field_ref()...);
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::AdaptedFields> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).field1_ref()...);
    f(1, static_cast<T&&>(t).field2_ref()...);
    f(2, static_cast<T&&>(t).field3_ref()...);
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::WrappedFields> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).field1_ref()...);
  }
};

template <>
struct ForEachField<::facebook::thrift::test::terse_write::TerseException> {
  template <typename F, typename... T>
  void operator()(FOLLY_MAYBE_UNUSED F&& f, FOLLY_MAYBE_UNUSED T&&... t) const {
    f(0, static_cast<T&&>(t).msg_ref()...);
  }
};
} // namespace detail
} // namespace thrift
} // namespace apache
