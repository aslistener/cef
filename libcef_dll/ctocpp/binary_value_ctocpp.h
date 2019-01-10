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
// $hash=8341ed8de354de4f2ad2b6ed087021b230b9fc29$
//

#ifndef CEF_LIBCEF_DLL_CTOCPP_BINARY_VALUE_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_BINARY_VALUE_CTOCPP_H_
#pragma once

#if !defined(WRAPPING_CEF_SHARED)
#error This file can be included wrapper-side only
#endif

#include "include/capi/cef_values_capi.h"
#include "include/cef_values.h"
#include "libcef_dll/ctocpp/ctocpp_ref_counted.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed wrapper-side only.
class CefBinaryValueCToCpp : public CefCToCppRefCounted<CefBinaryValueCToCpp,
                                                        CefBinaryValue,
                                                        cef_binary_value_t> {
 public:
  CefBinaryValueCToCpp();

  // CefBinaryValue methods.
  bool IsValid() OVERRIDE;
  bool IsOwned() OVERRIDE;
  bool IsSame(CefRefPtr<CefBinaryValue> that) OVERRIDE;
  bool IsEqual(CefRefPtr<CefBinaryValue> that) OVERRIDE;
  CefRefPtr<CefBinaryValue> Copy() OVERRIDE;
  size_t GetSize() OVERRIDE;
  size_t GetData(void* buffer, size_t buffer_size, size_t data_offset) OVERRIDE;
};

#endif  // CEF_LIBCEF_DLL_CTOCPP_BINARY_VALUE_CTOCPP_H_
