// Copyright (c) 2019 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=2b22c5afac64be1b40029064da32b16f84e8fe27$
//

#include "libcef_dll/ctocpp/value_ctocpp.h"
#include "libcef_dll/ctocpp/binary_value_ctocpp.h"
#include "libcef_dll/ctocpp/dictionary_value_ctocpp.h"
#include "libcef_dll/ctocpp/list_value_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") CefRefPtr<CefValue> CefValue::Create() {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_value_t* _retval = cef_value_create();

  // Return type: refptr_same
  return CefValueCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::IsValid() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_valid))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_valid(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::IsOwned() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_owned))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_owned(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::IsReadOnly() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_read_only))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_read_only(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::IsSame(CefRefPtr<CefValue> that) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_same))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: that; type: refptr_same
  DCHECK(that.get());
  if (!that.get())
    return false;

  // Execute
  int _retval = _struct->is_same(_struct, CefValueCToCpp::Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefValueCToCpp::IsEqual(CefRefPtr<CefValue> that) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_equal))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: that; type: refptr_same
  DCHECK(that.get());
  if (!that.get())
    return false;

  // Execute
  int _retval = _struct->is_equal(_struct, CefValueCToCpp::Unwrap(that));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefValue> CefValueCToCpp::Copy() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, copy))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_value_t* _retval = _struct->copy(_struct);

  // Return type: refptr_same
  return CefValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefValueType CefValueCToCpp::GetType() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_type))
    return VTYPE_INVALID;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_value_type_t _retval = _struct->get_type(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::GetBool() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_bool))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_bool(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") int CefValueCToCpp::GetInt() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_int))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->get_int(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") double CefValueCToCpp::GetDouble() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_double))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  double _retval = _struct->get_double(_struct);

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall") CefString CefValueCToCpp::GetString() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_string))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_string(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefBinaryValue> CefValueCToCpp::GetBinary() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_binary))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_binary_value_t* _retval = _struct->get_binary(_struct);

  // Return type: refptr_same
  return CefBinaryValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDictionaryValue> CefValueCToCpp::GetDictionary() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_dictionary))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_dictionary_value_t* _retval = _struct->get_dictionary(_struct);

  // Return type: refptr_same
  return CefDictionaryValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") CefRefPtr<CefListValue> CefValueCToCpp::GetList() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_list))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_list_value_t* _retval = _struct->get_list(_struct);

  // Return type: refptr_same
  return CefListValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::SetNull() {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_null))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->set_null(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::SetBool(bool value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_bool))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->set_bool(_struct, value);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::SetInt(int value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_int))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->set_int(_struct, value);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefValueCToCpp::SetDouble(double value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_double))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->set_double(_struct, value);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefValueCToCpp::SetString(const CefString& value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_string))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: value

  // Execute
  int _retval = _struct->set_string(_struct, value.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefValueCToCpp::SetBinary(CefRefPtr<CefBinaryValue> value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_binary))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get())
    return false;

  // Execute
  int _retval =
      _struct->set_binary(_struct, CefBinaryValueCToCpp::Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefValueCToCpp::SetDictionary(CefRefPtr<CefDictionaryValue> value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_dictionary))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get())
    return false;

  // Execute
  int _retval =
      _struct->set_dictionary(_struct, CefDictionaryValueCToCpp::Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefValueCToCpp::SetList(CefRefPtr<CefListValue> value) {
  shutdown_checker::AssertNotShutdown();

  cef_value_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_list))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: value; type: refptr_same
  DCHECK(value.get());
  if (!value.get())
    return false;

  // Execute
  int _retval = _struct->set_list(_struct, CefListValueCToCpp::Unwrap(value));

  // Return type: bool
  return _retval ? true : false;
}

// CONSTRUCTOR - Do not edit by hand.

CefValueCToCpp::CefValueCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefValueCToCpp::~CefValueCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_value_t*
CefCToCppRefCounted<CefValueCToCpp, CefValue, cef_value_t>::UnwrapDerived(
    CefWrapperType type,
    CefValue* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCToCppRefCounted<CefValueCToCpp, CefValue, cef_value_t>::DebugObjCt
        ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType
    CefCToCppRefCounted<CefValueCToCpp, CefValue, cef_value_t>::kWrapperType =
        WT_VALUE;
