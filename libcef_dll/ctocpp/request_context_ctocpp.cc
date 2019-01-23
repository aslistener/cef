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
// $hash=37d522682ec51c38bb9b4f0e94a46a49c3820046$
//

#include "libcef_dll/ctocpp/request_context_ctocpp.h"
#include "libcef_dll/cpptoc/completion_callback_cpptoc.h"
#include "libcef_dll/cpptoc/extension_handler_cpptoc.h"
#include "libcef_dll/cpptoc/request_context_handler_cpptoc.h"
#include "libcef_dll/cpptoc/resolve_callback_cpptoc.h"
#include "libcef_dll/cpptoc/scheme_handler_factory_cpptoc.h"
#include "libcef_dll/ctocpp/cookie_manager_ctocpp.h"
#include "libcef_dll/ctocpp/dictionary_value_ctocpp.h"
#include "libcef_dll/ctocpp/extension_ctocpp.h"
#include "libcef_dll/ctocpp/value_ctocpp.h"
#include "libcef_dll/transfer_util.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRequestContext> CefRequestContext::GetGlobalContext() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_request_context_t* _retval = cef_request_context_get_global_context();

  // Return type: refptr_same
  return CefRequestContextCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRequestContext> CefRequestContext::CreateContext(
    const CefRequestContextSettings& settings,
    CefRefPtr<CefRequestContextHandler> handler) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: handler

  // Execute
  cef_request_context_t* _retval = cef_request_context_create_context(
      &settings, CefRequestContextHandlerCppToC::Wrap(handler));

  // Return type: refptr_same
  return CefRequestContextCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRequestContext> CefRequestContext::CreateContext(
    CefRefPtr<CefRequestContext> other,
    CefRefPtr<CefRequestContextHandler> handler) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: other; type: refptr_same
  DCHECK(other.get());
  if (!other.get())
    return NULL;
  // Unverified params: handler

  // Execute
  cef_request_context_t* _retval =
      cef_create_context_shared(CefRequestContextCToCpp::Unwrap(other),
                                CefRequestContextHandlerCppToC::Wrap(handler));

  // Return type: refptr_same
  return CefRequestContextCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::IsSame(CefRefPtr<CefRequestContext> other) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_same))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: other; type: refptr_same
  DCHECK(other.get());
  if (!other.get())
    return false;

  // Execute
  int _retval =
      _struct->is_same(_struct, CefRequestContextCToCpp::Unwrap(other));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::IsSharingWith(
    CefRefPtr<CefRequestContext> other) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_sharing_with))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: other; type: refptr_same
  DCHECK(other.get());
  if (!other.get())
    return false;

  // Execute
  int _retval =
      _struct->is_sharing_with(_struct, CefRequestContextCToCpp::Unwrap(other));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall") bool CefRequestContextCToCpp::IsGlobal() {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, is_global))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->is_global(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRequestContextHandler> CefRequestContextCToCpp::GetHandler() {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_request_context_handler_t* _retval = _struct->get_handler(_struct);

  // Return type: refptr_diff
  return CefRequestContextHandlerCppToC::Unwrap(_retval);
}

NO_SANITIZE("cfi-icall") CefString CefRequestContextCToCpp::GetCachePath() {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_cache_path))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = _struct->get_cache_path(_struct);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefCookieManager> CefRequestContextCToCpp::GetDefaultCookieManager(
    CefRefPtr<CefCompletionCallback> callback) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_default_cookie_manager))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: callback

  // Execute
  cef_cookie_manager_t* _retval = _struct->get_default_cookie_manager(
      _struct, CefCompletionCallbackCppToC::Wrap(callback));

  // Return type: refptr_same
  return CefCookieManagerCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::RegisterSchemeHandlerFactory(
    const CefString& scheme_name,
    const CefString& domain_name,
    CefRefPtr<CefSchemeHandlerFactory> factory) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, register_scheme_handler_factory))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: scheme_name; type: string_byref_const
  DCHECK(!scheme_name.empty());
  if (scheme_name.empty())
    return false;
  // Unverified params: domain_name, factory

  // Execute
  int _retval = _struct->register_scheme_handler_factory(
      _struct, scheme_name.GetStruct(), domain_name.GetStruct(),
      CefSchemeHandlerFactoryCppToC::Wrap(factory));

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::ClearSchemeHandlerFactories() {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, clear_scheme_handler_factories))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = _struct->clear_scheme_handler_factories(_struct);

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefRequestContextCToCpp::PurgePluginListCache(bool reload_pages) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, purge_plugin_list_cache))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->purge_plugin_list_cache(_struct, reload_pages);
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::HasPreference(const CefString& name) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, has_preference))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return false;

  // Execute
  int _retval = _struct->has_preference(_struct, name.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefValue> CefRequestContextCToCpp::GetPreference(
    const CefString& name) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_preference))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return NULL;

  // Execute
  cef_value_t* _retval = _struct->get_preference(_struct, name.GetStruct());

  // Return type: refptr_same
  return CefValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefDictionaryValue> CefRequestContextCToCpp::GetAllPreferences(
    bool include_defaults) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_all_preferences))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_dictionary_value_t* _retval =
      _struct->get_all_preferences(_struct, include_defaults);

  // Return type: refptr_same
  return CefDictionaryValueCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::CanSetPreference(const CefString& name) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, can_set_preference))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return false;

  // Execute
  int _retval = _struct->can_set_preference(_struct, name.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::SetPreference(const CefString& name,
                                            CefRefPtr<CefValue> value,
                                            CefString& error) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, set_preference))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return false;
  // Unverified params: value

  // Execute
  int _retval = _struct->set_preference(_struct, name.GetStruct(),
                                        CefValueCToCpp::Unwrap(value),
                                        error.GetWritableStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
void CefRequestContextCToCpp::ClearCertificateExceptions(
    CefRefPtr<CefCompletionCallback> callback) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, clear_certificate_exceptions))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: callback

  // Execute
  _struct->clear_certificate_exceptions(
      _struct, CefCompletionCallbackCppToC::Wrap(callback));
}

NO_SANITIZE("cfi-icall")
void CefRequestContextCToCpp::CloseAllConnections(
    CefRefPtr<CefCompletionCallback> callback) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, close_all_connections))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: callback

  // Execute
  _struct->close_all_connections(_struct,
                                 CefCompletionCallbackCppToC::Wrap(callback));
}

NO_SANITIZE("cfi-icall")
void CefRequestContextCToCpp::ResolveHost(
    const CefString& origin,
    CefRefPtr<CefResolveCallback> callback) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, resolve_host))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: origin; type: string_byref_const
  DCHECK(!origin.empty());
  if (origin.empty())
    return;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return;

  // Execute
  _struct->resolve_host(_struct, origin.GetStruct(),
                        CefResolveCallbackCppToC::Wrap(callback));
}

NO_SANITIZE("cfi-icall")
cef_errorcode_t CefRequestContextCToCpp::ResolveHostCached(
    const CefString& origin,
    std::vector<CefString>& resolved_ips) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, resolve_host_cached))
    return ERR_FAILED;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: origin; type: string_byref_const
  DCHECK(!origin.empty());
  if (origin.empty())
    return ERR_FAILED;

  // Translate param: resolved_ips; type: string_vec_byref
  cef_string_list_t resolved_ipsList = cef_string_list_alloc();
  DCHECK(resolved_ipsList);
  if (resolved_ipsList)
    transfer_string_list_contents(resolved_ips, resolved_ipsList);

  // Execute
  cef_errorcode_t _retval = _struct->resolve_host_cached(
      _struct, origin.GetStruct(), resolved_ipsList);

  // Restore param:resolved_ips; type: string_vec_byref
  if (resolved_ipsList) {
    resolved_ips.clear();
    transfer_string_list_contents(resolved_ipsList, resolved_ips);
    cef_string_list_free(resolved_ipsList);
  }

  // Return type: simple
  return _retval;
}

NO_SANITIZE("cfi-icall")
void CefRequestContextCToCpp::LoadExtension(
    const CefString& root_directory,
    CefRefPtr<CefDictionaryValue> manifest,
    CefRefPtr<CefExtensionHandler> handler) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, load_extension))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: root_directory; type: string_byref_const
  DCHECK(!root_directory.empty());
  if (root_directory.empty())
    return;
  // Unverified params: manifest, handler

  // Execute
  _struct->load_extension(_struct, root_directory.GetStruct(),
                          CefDictionaryValueCToCpp::Unwrap(manifest),
                          CefExtensionHandlerCppToC::Wrap(handler));
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::DidLoadExtension(const CefString& extension_id) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, did_load_extension))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: extension_id; type: string_byref_const
  DCHECK(!extension_id.empty());
  if (extension_id.empty())
    return false;

  // Execute
  int _retval = _struct->did_load_extension(_struct, extension_id.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::HasExtension(const CefString& extension_id) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, has_extension))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: extension_id; type: string_byref_const
  DCHECK(!extension_id.empty());
  if (extension_id.empty())
    return false;

  // Execute
  int _retval = _struct->has_extension(_struct, extension_id.GetStruct());

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
bool CefRequestContextCToCpp::GetExtensions(
    std::vector<CefString>& extension_ids) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_extensions))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: extension_ids; type: string_vec_byref
  cef_string_list_t extension_idsList = cef_string_list_alloc();
  DCHECK(extension_idsList);
  if (extension_idsList)
    transfer_string_list_contents(extension_ids, extension_idsList);

  // Execute
  int _retval = _struct->get_extensions(_struct, extension_idsList);

  // Restore param:extension_ids; type: string_vec_byref
  if (extension_idsList) {
    extension_ids.clear();
    transfer_string_list_contents(extension_idsList, extension_ids);
    cef_string_list_free(extension_idsList);
  }

  // Return type: bool
  return _retval ? true : false;
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefExtension> CefRequestContextCToCpp::GetExtension(
    const CefString& extension_id) {
  cef_request_context_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_extension))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: extension_id; type: string_byref_const
  DCHECK(!extension_id.empty());
  if (extension_id.empty())
    return NULL;

  // Execute
  cef_extension_t* _retval =
      _struct->get_extension(_struct, extension_id.GetStruct());

  // Return type: refptr_same
  return CefExtensionCToCpp::Wrap(_retval);
}

// CONSTRUCTOR - Do not edit by hand.

CefRequestContextCToCpp::CefRequestContextCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefRequestContextCToCpp::~CefRequestContextCToCpp() {}

template <>
cef_request_context_t* CefCToCppRefCounted<
    CefRequestContextCToCpp,
    CefRequestContext,
    cef_request_context_t>::UnwrapDerived(CefWrapperType type,
                                          CefRequestContext* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

template <>
CefWrapperType CefCToCppRefCounted<CefRequestContextCToCpp,
                                   CefRequestContext,
                                   cef_request_context_t>::kWrapperType =
    WT_REQUEST_CONTEXT;
