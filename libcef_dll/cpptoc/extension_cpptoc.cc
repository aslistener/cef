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
// $hash=857367991e8792482564288c822b6f042cef1691$
//

#include "libcef_dll/cpptoc/extension_cpptoc.h"
#include "libcef_dll/cpptoc/dictionary_value_cpptoc.h"
#include "libcef_dll/cpptoc/request_context_cpptoc.h"
#include "libcef_dll/ctocpp/extension_handler_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

cef_string_userfree_t CEF_CALLBACK
extension_get_identifier(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefExtensionCppToC::Get(self)->GetIdentifier();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
extension_get_path(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefExtensionCppToC::Get(self)->GetPath();

  // Return type: string
  return _retval.DetachToUserFree();
}

struct _cef_dictionary_value_t* CEF_CALLBACK
extension_get_manifest(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefDictionaryValue> _retval =
      CefExtensionCppToC::Get(self)->GetManifest();

  // Return type: refptr_same
  return CefDictionaryValueCppToC::Wrap(_retval);
}

int CEF_CALLBACK extension_is_same(struct _cef_extension_t* self,
                                   struct _cef_extension_t* that) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: that; type: refptr_same
  DCHECK(that);
  if (!that)
    return 0;

  // Execute
  bool _retval =
      CefExtensionCppToC::Get(self)->IsSame(CefExtensionCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

struct _cef_extension_handler_t* CEF_CALLBACK
extension_get_handler(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefExtensionHandler> _retval =
      CefExtensionCppToC::Get(self)->GetHandler();

  // Return type: refptr_diff
  return CefExtensionHandlerCToCpp::Unwrap(_retval);
}

struct _cef_request_context_t* CEF_CALLBACK
extension_get_loader_context(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefRequestContext> _retval =
      CefExtensionCppToC::Get(self)->GetLoaderContext();

  // Return type: refptr_same
  return CefRequestContextCppToC::Wrap(_retval);
}

int CEF_CALLBACK extension_is_loaded(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefExtensionCppToC::Get(self)->IsLoaded();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK extension_unload(struct _cef_extension_t* self) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefExtensionCppToC::Get(self)->Unload();
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefExtensionCppToC::CefExtensionCppToC() {
  GetStruct()->get_identifier = extension_get_identifier;
  GetStruct()->get_path = extension_get_path;
  GetStruct()->get_manifest = extension_get_manifest;
  GetStruct()->is_same = extension_is_same;
  GetStruct()->get_handler = extension_get_handler;
  GetStruct()->get_loader_context = extension_get_loader_context;
  GetStruct()->is_loaded = extension_is_loaded;
  GetStruct()->unload = extension_unload;
}

// DESTRUCTOR - Do not edit by hand.

CefExtensionCppToC::~CefExtensionCppToC() {
  shutdown_checker::AssertNotShutdown();
}

template <>
CefRefPtr<CefExtension>
CefCppToCRefCounted<CefExtensionCppToC, CefExtension, cef_extension_t>::
    UnwrapDerived(CefWrapperType type, cef_extension_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

template <>
CefWrapperType CefCppToCRefCounted<CefExtensionCppToC,
                                   CefExtension,
                                   cef_extension_t>::kWrapperType =
    WT_EXTENSION;
