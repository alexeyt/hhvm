#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from libc.stdint cimport (
    int8_t as cint8_t,
    int16_t as cint16_t,
    int32_t as cint32_t,
    int64_t as cint64_t,
    uint32_t as cuint32_t,
)
from libcpp.string cimport string
from libcpp cimport bool as cbool, nullptr, nullptr_t
from cpython cimport bool as pbool
from libcpp.memory cimport shared_ptr, unique_ptr
from libcpp.utility cimport move as cmove
from libcpp.vector cimport vector
from libcpp.set cimport set as cset
from libcpp.map cimport map as cmap, pair as cpair
from thrift.py3.exceptions cimport cTException
cimport folly.iobuf as _fbthrift_iobuf
cimport thrift.py3.exceptions
cimport thrift.py3.types
from thrift.py3.types cimport (
    bstring,
    bytes_to_string,
    field_ref as __field_ref,
    optional_field_ref as __optional_field_ref,
    required_field_ref as __required_field_ref,
    terse_field_ref as __terse_field_ref,
    union_field_ref as __union_field_ref,
    get_union_field_value as __get_union_field_value,
)
from thrift.py3.common cimport (
    RpcOptions as __RpcOptions,
    Protocol as __Protocol,
    cThriftMetadata as __fbthrift_cThriftMetadata,
    MetadataBox as __MetadataBox,
)
from folly.optional cimport cOptional as __cOptional
cimport facebook.thrift.annotation.cpp.types as _facebook_thrift_annotation_cpp_types

cimport module.types_fields as _fbthrift_types_fields

cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-py3/module/types.h":
  pass


cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-cpp2/module_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass EnumMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-cpp2/module_types.h" namespace "::cpp2":
    cdef cppclass cMyEnum "::cpp2::MyEnum":
        pass

    cdef cppclass cTypedEnum "::cpp2::TypedEnum":
        pass





cdef class MyEnum(thrift.py3.types.CompiledEnum):
    pass


cdef class TypedEnum(thrift.py3.types.CompiledEnum):
    pass

cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-cpp2/module_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass ExceptionMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-cpp2/module_metadata.h" namespace "apache::thrift::detail::md":
    cdef cppclass StructMetadata[T]:
        @staticmethod
        void gen(__fbthrift_cThriftMetadata &metadata)
cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-cpp2/module_types_custom_protocol.h" namespace "::cpp2":
    cdef enum cMyUnion__type "::cpp2::MyUnion::Type":
        cMyUnion__type___EMPTY__ "::cpp2::MyUnion::Type::__EMPTY__",
        cMyUnion__type_anInteger "::cpp2::MyUnion::Type::anInteger",
        cMyUnion__type_aString "::cpp2::MyUnion::Type::aString",

    cdef cppclass cMyUnion "::cpp2::MyUnion":
        cMyUnion() except +
        cMyUnion(const cMyUnion&) except +
        bint operator==(cMyUnion&)
        bint operator!=(cMyUnion&)
        bint operator<(cMyUnion&)
        bint operator>(cMyUnion&)
        bint operator<=(cMyUnion&)
        bint operator>=(cMyUnion&)
        cMyUnion__type getType() const
        const unique_ptr[cint32_t]& get_anInteger "get_anInteger" () const
        unique_ptr[cint32_t]& set_anInteger "set_anInteger" (const cint32_t&)
        const unique_ptr[string]& get_aString "get_aString" () const
        unique_ptr[string]& set_aString "set_aString" (const string&)


    cdef cppclass cMyField "::cpp2::MyField":
        cMyField() except +
        cMyField(const cMyField&) except +
        bint operator==(cMyField&)
        bint operator!=(cMyField&)
        bint operator<(cMyField&)
        bint operator>(cMyField&)
        bint operator<=(cMyField&)
        bint operator>=(cMyField&)
        unique_ptr[cint64_t] opt_value_ref "opt_value_ref" ()
        unique_ptr[cint64_t] value_ref "value_ref" ()
        unique_ptr[cint64_t] req_value_ref "req_value_ref" ()
        unique_ptr[cMyEnum] opt_enum_value_ref "opt_enum_value_ref" ()
        unique_ptr[cMyEnum] enum_value_ref "enum_value_ref" ()
        unique_ptr[cMyEnum] req_enum_value_ref "req_enum_value_ref" ()
        unique_ptr[string] opt_str_value_ref "opt_str_value_ref" ()
        unique_ptr[string] str_value_ref "str_value_ref" ()
        unique_ptr[string] req_str_value_ref "req_str_value_ref" ()


    cdef cppclass cMyStruct "::cpp2::MyStruct":
        cMyStruct() except +
        cMyStruct(const cMyStruct&) except +
        bint operator==(cMyStruct&)
        bint operator!=(cMyStruct&)
        bint operator<(cMyStruct&)
        bint operator>(cMyStruct&)
        bint operator<=(cMyStruct&)
        bint operator>=(cMyStruct&)
        unique_ptr[cMyField] opt_ref_ref "opt_ref_ref" ()
        unique_ptr[cMyField] ref_ref "ref_ref" ()
        unique_ptr[cMyField] req_ref_ref "req_ref_ref" ()


    cdef cppclass cStructWithUnion "::cpp2::StructWithUnion":
        cStructWithUnion() except +
        cStructWithUnion(const cStructWithUnion&) except +
        bint operator==(cStructWithUnion&)
        bint operator!=(cStructWithUnion&)
        bint operator<(cStructWithUnion&)
        bint operator>(cStructWithUnion&)
        bint operator<=(cStructWithUnion&)
        bint operator>=(cStructWithUnion&)
        unique_ptr[cMyUnion] u_ref "u_ref" ()
        unique_ptr[double] aDouble_ref "aDouble_ref" ()
        __field_ref[cMyField] f_ref "f_ref" ()


    cdef cppclass cRecursiveStruct "::cpp2::RecursiveStruct":
        cRecursiveStruct() except +
        cRecursiveStruct(const cRecursiveStruct&) except +
        bint operator==(cRecursiveStruct&)
        bint operator!=(cRecursiveStruct&)
        bint operator<(cRecursiveStruct&)
        bint operator>(cRecursiveStruct&)
        bint operator<=(cRecursiveStruct&)
        bint operator>=(cRecursiveStruct&)
        __optional_field_ref[vector[cRecursiveStruct]] mes_ref "mes_ref" ()


    cdef cppclass cStructWithContainers "::cpp2::StructWithContainers":
        cStructWithContainers() except +
        cStructWithContainers(const cStructWithContainers&) except +
        bint operator==(cStructWithContainers&)
        bint operator!=(cStructWithContainers&)
        bint operator<(cStructWithContainers&)
        bint operator>(cStructWithContainers&)
        bint operator<=(cStructWithContainers&)
        bint operator>=(cStructWithContainers&)
        unique_ptr[vector[cint32_t]] list_ref_ref "list_ref_ref" ()
        unique_ptr[cset[cint32_t]] set_ref_ref "set_ref_ref" ()
        unique_ptr[cmap[cint32_t,cint32_t]] map_ref_ref "map_ref_ref" ()
        unique_ptr[vector[cint32_t]] list_ref_unique_ref "list_ref_unique_ref" ()
        shared_ptr[cset[cint32_t]] set_ref_shared_ref "set_ref_shared_ref" ()
        shared_ptr[const vector[cint32_t]] list_ref_shared_const_ref "list_ref_shared_const_ref" ()


    cdef cppclass cStructWithSharedConst "::cpp2::StructWithSharedConst":
        cStructWithSharedConst() except +
        cStructWithSharedConst(const cStructWithSharedConst&) except +
        bint operator==(cStructWithSharedConst&)
        bint operator!=(cStructWithSharedConst&)
        bint operator<(cStructWithSharedConst&)
        bint operator>(cStructWithSharedConst&)
        bint operator<=(cStructWithSharedConst&)
        bint operator>=(cStructWithSharedConst&)
        shared_ptr[const cMyField] opt_shared_const_ref "opt_shared_const_ref" ()
        shared_ptr[const cMyField] shared_const_ref "shared_const_ref" ()
        shared_ptr[const cMyField] req_shared_const_ref "req_shared_const_ref" ()


    cdef cppclass cEmpty "::cpp2::Empty":
        cEmpty() except +
        cEmpty(const cEmpty&) except +
        bint operator==(cEmpty&)
        bint operator!=(cEmpty&)
        bint operator<(cEmpty&)
        bint operator>(cEmpty&)
        bint operator<=(cEmpty&)
        bint operator>=(cEmpty&)


    cdef cppclass cStructWithRef "::cpp2::StructWithRef":
        cStructWithRef() except +
        cStructWithRef(const cStructWithRef&) except +
        bint operator==(cStructWithRef&)
        bint operator!=(cStructWithRef&)
        bint operator<(cStructWithRef&)
        bint operator>(cStructWithRef&)
        bint operator<=(cStructWithRef&)
        bint operator>=(cStructWithRef&)
        unique_ptr[cEmpty] def_field_ref "def_field_ref" ()
        unique_ptr[cEmpty] opt_field_ref "opt_field_ref" ()
        unique_ptr[cEmpty] req_field_ref "req_field_ref" ()


    cdef cppclass cStructWithBox "::cpp2::StructWithBox":
        cStructWithBox() except +
        cStructWithBox(const cStructWithBox&) except +
        bint operator==(cStructWithBox&)
        bint operator!=(cStructWithBox&)
        bint operator<(cStructWithBox&)
        bint operator>(cStructWithBox&)
        bint operator<=(cStructWithBox&)
        bint operator>=(cStructWithBox&)
        __optional_field_ref[string] a_ref "a_ref" ()
        __optional_field_ref[vector[cint64_t]] b_ref "b_ref" ()
        __optional_field_ref[cStructWithRef] c_ref "c_ref" ()


    cdef cppclass cStructWithNonOptionalBox "::cpp2::StructWithNonOptionalBox":
        cStructWithNonOptionalBox() except +
        cStructWithNonOptionalBox(const cStructWithNonOptionalBox&) except +
        bint operator==(cStructWithNonOptionalBox&)
        bint operator!=(cStructWithNonOptionalBox&)
        bint operator<(cStructWithNonOptionalBox&)
        bint operator>(cStructWithNonOptionalBox&)
        bint operator<=(cStructWithNonOptionalBox&)
        bint operator>=(cStructWithNonOptionalBox&)
        __field_ref[string] a_ref "a_ref" ()
        __field_ref[vector[cint64_t]] b_ref "b_ref" ()
        __field_ref[cStructWithRef] c_ref "c_ref" ()


    cdef cppclass cStructWithInternBox "::cpp2::StructWithInternBox":
        cStructWithInternBox() except +
        cStructWithInternBox(const cStructWithInternBox&) except +
        bint operator==(cStructWithInternBox&)
        bint operator!=(cStructWithInternBox&)
        bint operator<(cStructWithInternBox&)
        bint operator>(cStructWithInternBox&)
        bint operator<=(cStructWithInternBox&)
        bint operator>=(cStructWithInternBox&)
        __field_ref[cEmpty] field1_ref "field1_ref" ()
        __field_ref[cMyField] field2_ref "field2_ref" ()
        __terse_field_ref[cEmpty] field3_ref "field3_ref" ()
        __terse_field_ref[cMyField] field4_ref "field4_ref" ()


    cdef cppclass cStructWithRefTypeUnique "::cpp2::StructWithRefTypeUnique":
        cStructWithRefTypeUnique() except +
        cStructWithRefTypeUnique(const cStructWithRefTypeUnique&) except +
        bint operator==(cStructWithRefTypeUnique&)
        bint operator!=(cStructWithRefTypeUnique&)
        bint operator<(cStructWithRefTypeUnique&)
        bint operator>(cStructWithRefTypeUnique&)
        bint operator<=(cStructWithRefTypeUnique&)
        bint operator>=(cStructWithRefTypeUnique&)
        unique_ptr[cEmpty] def_field_ref "def_field_ref" ()
        unique_ptr[cEmpty] opt_field_ref "opt_field_ref" ()
        unique_ptr[cEmpty] req_field_ref "req_field_ref" ()


    cdef cppclass cStructWithRefTypeShared "::cpp2::StructWithRefTypeShared":
        cStructWithRefTypeShared() except +
        cStructWithRefTypeShared(const cStructWithRefTypeShared&) except +
        bint operator==(cStructWithRefTypeShared&)
        bint operator!=(cStructWithRefTypeShared&)
        bint operator<(cStructWithRefTypeShared&)
        bint operator>(cStructWithRefTypeShared&)
        bint operator<=(cStructWithRefTypeShared&)
        bint operator>=(cStructWithRefTypeShared&)
        shared_ptr[cEmpty] def_field_ref "def_field_ref" ()
        shared_ptr[cEmpty] opt_field_ref "opt_field_ref" ()
        shared_ptr[cEmpty] req_field_ref "req_field_ref" ()


    cdef cppclass cStructWithRefTypeSharedConst "::cpp2::StructWithRefTypeSharedConst":
        cStructWithRefTypeSharedConst() except +
        cStructWithRefTypeSharedConst(const cStructWithRefTypeSharedConst&) except +
        bint operator==(cStructWithRefTypeSharedConst&)
        bint operator!=(cStructWithRefTypeSharedConst&)
        bint operator<(cStructWithRefTypeSharedConst&)
        bint operator>(cStructWithRefTypeSharedConst&)
        bint operator<=(cStructWithRefTypeSharedConst&)
        bint operator>=(cStructWithRefTypeSharedConst&)
        shared_ptr[const cEmpty] def_field_ref "def_field_ref" ()
        shared_ptr[const cEmpty] opt_field_ref "opt_field_ref" ()
        shared_ptr[const cEmpty] req_field_ref "req_field_ref" ()


    cdef cppclass cStructWithRefAndAnnotCppNoexceptMoveCtor "::cpp2::StructWithRefAndAnnotCppNoexceptMoveCtor":
        cStructWithRefAndAnnotCppNoexceptMoveCtor() except +
        cStructWithRefAndAnnotCppNoexceptMoveCtor(const cStructWithRefAndAnnotCppNoexceptMoveCtor&) except +
        bint operator==(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator!=(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator<(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator>(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator<=(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        bint operator>=(cStructWithRefAndAnnotCppNoexceptMoveCtor&)
        unique_ptr[cEmpty] def_field_ref "def_field_ref" ()


    cdef cppclass cStructWithString "::cpp2::StructWithString":
        cStructWithString() except +
        cStructWithString(const cStructWithString&) except +
        bint operator==(cStructWithString&)
        bint operator!=(cStructWithString&)
        bint operator<(cStructWithString&)
        bint operator>(cStructWithString&)
        bint operator<=(cStructWithString&)
        bint operator>=(cStructWithString&)
        unique_ptr[string] def_unique_string_ref_ref "def_unique_string_ref_ref" ()
        shared_ptr[string] def_shared_string_ref_ref "def_shared_string_ref_ref" ()
        shared_ptr[const string] def_shared_string_const_ref_ref "def_shared_string_const_ref_ref" ()
        unique_ptr[string] unique_string_ref_ref "unique_string_ref_ref" ()
        shared_ptr[string] shared_string_ref_ref "shared_string_ref_ref" ()


cdef class __MyUnionType(thrift.py3.types.CompiledEnum):
    pass




cdef class MyUnion(thrift.py3.types.Union):
    cdef shared_ptr[cMyUnion] _cpp_obj
    cdef readonly __MyUnionType type
    cdef readonly object value
    cdef _load_cache(MyUnion self)

    @staticmethod
    cdef unique_ptr[cMyUnion] _make_instance(
        cMyUnion* base_instance,
        object anInteger,
        str aString
    ) except *

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cMyUnion])



cdef class MyField(thrift.py3.types.Struct):
    cdef shared_ptr[cMyField] _cpp_obj
    cdef _fbthrift_types_fields.__MyField_FieldsSetter _fields_setter
    cdef inline object opt_value_impl(self)
    cdef inline object value_impl(self)
    cdef inline object req_value_impl(self)
    cdef inline object opt_enum_value_impl(self)
    cdef inline object enum_value_impl(self)
    cdef inline object req_enum_value_impl(self)
    cdef inline object opt_str_value_impl(self)
    cdef inline object str_value_impl(self)
    cdef inline object req_str_value_impl(self)
    cdef object __fbthrift_cached_opt_enum_value
    cdef object __fbthrift_cached_enum_value
    cdef object __fbthrift_cached_req_enum_value

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cMyField])



cdef class MyStruct(thrift.py3.types.Struct):
    cdef shared_ptr[cMyStruct] _cpp_obj
    cdef _fbthrift_types_fields.__MyStruct_FieldsSetter _fields_setter
    cdef inline object opt_ref_impl(self)
    cdef inline object ref_impl(self)
    cdef inline object req_ref_impl(self)
    cdef MyField __fbthrift_cached_opt_ref
    cdef MyField __fbthrift_cached_ref
    cdef MyField __fbthrift_cached_req_ref

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cMyStruct])



cdef class StructWithUnion(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithUnion] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithUnion_FieldsSetter _fields_setter
    cdef inline object u_impl(self)
    cdef inline object aDouble_impl(self)
    cdef inline object f_impl(self)
    cdef MyUnion __fbthrift_cached_u
    cdef MyField __fbthrift_cached_f

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithUnion])



cdef class RecursiveStruct(thrift.py3.types.Struct):
    cdef shared_ptr[cRecursiveStruct] _cpp_obj
    cdef _fbthrift_types_fields.__RecursiveStruct_FieldsSetter _fields_setter
    cdef inline object mes_impl(self)
    cdef List__RecursiveStruct __fbthrift_cached_mes

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cRecursiveStruct])



cdef class StructWithContainers(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithContainers] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithContainers_FieldsSetter _fields_setter
    cdef inline object list_ref_impl(self)
    cdef inline object set_ref_impl(self)
    cdef inline object map_ref_impl(self)
    cdef inline object list_ref_unique_impl(self)
    cdef inline object set_ref_shared_impl(self)
    cdef inline object list_ref_shared_const_impl(self)
    cdef List__i32 __fbthrift_cached_list_ref
    cdef Set__i32 __fbthrift_cached_set_ref
    cdef Map__i32_i32 __fbthrift_cached_map_ref
    cdef List__i32 __fbthrift_cached_list_ref_unique
    cdef Set__i32 __fbthrift_cached_set_ref_shared
    cdef List__i32 __fbthrift_cached_list_ref_shared_const

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithContainers])



cdef class StructWithSharedConst(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithSharedConst] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithSharedConst_FieldsSetter _fields_setter
    cdef inline object opt_shared_const_impl(self)
    cdef inline object shared_const_impl(self)
    cdef inline object req_shared_const_impl(self)
    cdef MyField __fbthrift_cached_opt_shared_const
    cdef MyField __fbthrift_cached_shared_const
    cdef MyField __fbthrift_cached_req_shared_const

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithSharedConst])



cdef class Empty(thrift.py3.types.Struct):
    cdef shared_ptr[cEmpty] _cpp_obj
    cdef _fbthrift_types_fields.__Empty_FieldsSetter _fields_setter

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cEmpty])



cdef class StructWithRef(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithRef] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithRef_FieldsSetter _fields_setter
    cdef inline object def_field_impl(self)
    cdef inline object opt_field_impl(self)
    cdef inline object req_field_impl(self)
    cdef Empty __fbthrift_cached_def_field
    cdef Empty __fbthrift_cached_opt_field
    cdef Empty __fbthrift_cached_req_field

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithRef])



cdef class StructWithBox(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithBox] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithBox_FieldsSetter _fields_setter
    cdef inline object a_impl(self)
    cdef inline object b_impl(self)
    cdef inline object c_impl(self)
    cdef List__i64 __fbthrift_cached_b
    cdef StructWithRef __fbthrift_cached_c

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithBox])



cdef class StructWithNonOptionalBox(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithNonOptionalBox] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithNonOptionalBox_FieldsSetter _fields_setter
    cdef inline object a_impl(self)
    cdef inline object b_impl(self)
    cdef inline object c_impl(self)
    cdef List__i64 __fbthrift_cached_b
    cdef StructWithRef __fbthrift_cached_c

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithNonOptionalBox])



cdef class StructWithInternBox(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithInternBox] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithInternBox_FieldsSetter _fields_setter
    cdef inline object field1_impl(self)
    cdef inline object field2_impl(self)
    cdef inline object field3_impl(self)
    cdef inline object field4_impl(self)
    cdef Empty __fbthrift_cached_field1
    cdef MyField __fbthrift_cached_field2
    cdef Empty __fbthrift_cached_field3
    cdef MyField __fbthrift_cached_field4

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithInternBox])



cdef class StructWithRefTypeUnique(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithRefTypeUnique] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithRefTypeUnique_FieldsSetter _fields_setter
    cdef inline object def_field_impl(self)
    cdef inline object opt_field_impl(self)
    cdef inline object req_field_impl(self)
    cdef Empty __fbthrift_cached_def_field
    cdef Empty __fbthrift_cached_opt_field
    cdef Empty __fbthrift_cached_req_field

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithRefTypeUnique])



cdef class StructWithRefTypeShared(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithRefTypeShared] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithRefTypeShared_FieldsSetter _fields_setter
    cdef inline object def_field_impl(self)
    cdef inline object opt_field_impl(self)
    cdef inline object req_field_impl(self)
    cdef Empty __fbthrift_cached_def_field
    cdef Empty __fbthrift_cached_opt_field
    cdef Empty __fbthrift_cached_req_field

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithRefTypeShared])



cdef class StructWithRefTypeSharedConst(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithRefTypeSharedConst] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithRefTypeSharedConst_FieldsSetter _fields_setter
    cdef inline object def_field_impl(self)
    cdef inline object opt_field_impl(self)
    cdef inline object req_field_impl(self)
    cdef Empty __fbthrift_cached_def_field
    cdef Empty __fbthrift_cached_opt_field
    cdef Empty __fbthrift_cached_req_field

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithRefTypeSharedConst])



cdef class StructWithRefAndAnnotCppNoexceptMoveCtor(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithRefAndAnnotCppNoexceptMoveCtor_FieldsSetter _fields_setter
    cdef inline object def_field_impl(self)
    cdef Empty __fbthrift_cached_def_field

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithRefAndAnnotCppNoexceptMoveCtor])



cdef class StructWithString(thrift.py3.types.Struct):
    cdef shared_ptr[cStructWithString] _cpp_obj
    cdef _fbthrift_types_fields.__StructWithString_FieldsSetter _fields_setter
    cdef inline object def_unique_string_ref_impl(self)
    cdef inline object def_shared_string_ref_impl(self)
    cdef inline object def_shared_string_const_ref_impl(self)
    cdef inline object unique_string_ref_impl(self)
    cdef inline object shared_string_ref_impl(self)

    @staticmethod
    cdef _fbthrift_create(shared_ptr[cStructWithString])


cdef class List__RecursiveStruct(thrift.py3.types.List):
    cdef shared_ptr[vector[cRecursiveStruct]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[cRecursiveStruct]])
    @staticmethod
    cdef shared_ptr[vector[cRecursiveStruct]] _make_instance(object items) except *

cdef class List__i32(thrift.py3.types.List):
    cdef shared_ptr[vector[cint32_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[cint32_t]])
    @staticmethod
    cdef shared_ptr[vector[cint32_t]] _make_instance(object items) except *

cdef class Set__i32(thrift.py3.types.Set):
    cdef shared_ptr[cset[cint32_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cset[cint32_t]])
    @staticmethod
    cdef shared_ptr[cset[cint32_t]] _make_instance(object items) except *

cdef class Map__i32_i32(thrift.py3.types.Map):
    cdef shared_ptr[cmap[cint32_t,cint32_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[cmap[cint32_t,cint32_t]])
    @staticmethod
    cdef shared_ptr[cmap[cint32_t,cint32_t]] _make_instance(object items) except *

cdef class List__i64(thrift.py3.types.List):
    cdef shared_ptr[vector[cint64_t]] _cpp_obj
    @staticmethod
    cdef _fbthrift_create(shared_ptr[vector[cint64_t]])
    @staticmethod
    cdef shared_ptr[vector[cint64_t]] _make_instance(object items) except *


cdef extern from "thrift/compiler/test/fixtures/refs/src/gen-cpp2/module_constants.h" namespace "::cpp2":
    cdef cStructWithRef ckStructWithRef "::cpp2::module_constants::kStructWithRef"()
    cdef cStructWithRefTypeUnique ckStructWithRefTypeUnique "::cpp2::module_constants::kStructWithRefTypeUnique"()
    cdef cStructWithRefTypeShared ckStructWithRefTypeShared "::cpp2::module_constants::kStructWithRefTypeShared"()
    cdef cStructWithRefTypeSharedConst ckStructWithRefTypeSharedConst "::cpp2::module_constants::kStructWithRefTypeSharedConst"()
