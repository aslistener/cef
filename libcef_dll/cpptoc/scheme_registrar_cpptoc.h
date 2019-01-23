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
// $hash=09dd514d043e6bba5ed62369a627a2bb158acc0e$
//

#ifndef CEF_LIBCEF_DLL_CPPTOC_SCHEME_REGISTRAR_CPPTOC_H_
#define CEF_LIBCEF_DLL_CPPTOC_SCHEME_REGISTRAR_CPPTOC_H_
#pragma once

#if !defined(BUILDING_CEF_SHARED)
#error This file can be included DLL-side only
#endif

#include "include/capi/cef_scheme_capi.h"
#include "include/cef_scheme.h"
#include "libcef_dll/cpptoc/cpptoc_scoped.h"

// Wrap a C++ class with a C structure.
// This class may be instantiated and accessed DLL-side only.
class CefSchemeRegistrarCppToC
    : public CefCppToCScoped<CefSchemeRegistrarCppToC,
                             CefSchemeRegistrar,
                             cef_scheme_registrar_t> {
 public:
  CefSchemeRegistrarCppToC();
  virtual ~CefSchemeRegistrarCppToC();
};

#endif  // CEF_LIBCEF_DLL_CPPTOC_SCHEME_REGISTRAR_CPPTOC_H_
