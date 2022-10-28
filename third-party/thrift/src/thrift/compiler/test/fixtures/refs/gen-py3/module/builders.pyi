#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

import typing as _typing

import folly.iobuf as _fbthrift_iobuf
import thrift.py3.builder

import facebook.thrift.annotation.cpp.types as _facebook_thrift_annotation_cpp_types
import facebook.thrift.annotation.cpp.builders as _facebook_thrift_annotation_cpp_builders

import module.types as _module_types


class MyUnion_Builder(thrift.py3.builder.StructBuilder):
    anInteger: _typing.Optional[int]
    aString: _typing.Optional[str]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class MyField_Builder(thrift.py3.builder.StructBuilder):
    opt_value: _typing.Optional[int]
    value: _typing.Optional[int]
    req_value: _typing.Optional[int]
    opt_enum_value: _typing.Optional[_module_types.MyEnum]
    enum_value: _typing.Optional[_module_types.MyEnum]
    req_enum_value: _typing.Optional[_module_types.MyEnum]
    opt_str_value: _typing.Optional[str]
    str_value: _typing.Optional[str]
    req_str_value: _typing.Optional[str]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class MyStruct_Builder(thrift.py3.builder.StructBuilder):
    opt_ref: _typing.Any
    ref: _typing.Any
    req_ref: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithUnion_Builder(thrift.py3.builder.StructBuilder):
    u: _typing.Any
    aDouble: _typing.Optional[float]
    f: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class RecursiveStruct_Builder(thrift.py3.builder.StructBuilder):
    mes: _typing.Optional[list]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithContainers_Builder(thrift.py3.builder.StructBuilder):
    list_ref: _typing.Optional[list]
    set_ref: _typing.Optional[set]
    map_ref: _typing.Optional[dict]
    list_ref_unique: _typing.Optional[list]
    set_ref_shared: _typing.Optional[set]
    list_ref_shared_const: _typing.Optional[list]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithSharedConst_Builder(thrift.py3.builder.StructBuilder):
    opt_shared_const: _typing.Any
    shared_const: _typing.Any
    req_shared_const: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class Empty_Builder(thrift.py3.builder.StructBuilder):

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithRef_Builder(thrift.py3.builder.StructBuilder):
    def_field: _typing.Any
    opt_field: _typing.Any
    req_field: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithBox_Builder(thrift.py3.builder.StructBuilder):
    a: _typing.Optional[str]
    b: _typing.Optional[list]
    c: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithNonOptionalBox_Builder(thrift.py3.builder.StructBuilder):
    a: _typing.Optional[str]
    b: _typing.Optional[list]
    c: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithInternBox_Builder(thrift.py3.builder.StructBuilder):
    field1: _typing.Any
    field2: _typing.Any
    field3: _typing.Any
    field4: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithRefTypeUnique_Builder(thrift.py3.builder.StructBuilder):
    def_field: _typing.Any
    opt_field: _typing.Any
    req_field: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithRefTypeShared_Builder(thrift.py3.builder.StructBuilder):
    def_field: _typing.Any
    opt_field: _typing.Any
    req_field: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithRefTypeSharedConst_Builder(thrift.py3.builder.StructBuilder):
    def_field: _typing.Any
    opt_field: _typing.Any
    req_field: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithRefAndAnnotCppNoexceptMoveCtor_Builder(thrift.py3.builder.StructBuilder):
    def_field: _typing.Any

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


class StructWithString_Builder(thrift.py3.builder.StructBuilder):
    def_unique_string_ref: _typing.Optional[str]
    def_shared_string_ref: _typing.Optional[str]
    def_shared_string_const_ref: _typing.Optional[str]
    unique_string_ref: _typing.Optional[str]
    shared_string_ref: _typing.Optional[str]

    def __iter__(self) -> _typing.Iterator[_typing.Tuple[str, _typing.Any]]: ...


