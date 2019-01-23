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
// $hash=6c30de6fd4234579268912484326cab6431e4264$
//

#include "libcef_dll/cpptoc/task_cpptoc.h"

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK task_execute(struct _cef_task_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefTaskCppToC::Get(self)->Execute();
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefTaskCppToC::CefTaskCppToC() {
  GetStruct()->execute = task_execute;
}

// DESTRUCTOR - Do not edit by hand.

CefTaskCppToC::~CefTaskCppToC() {}

template <>
CefRefPtr<CefTask>
CefCppToCRefCounted<CefTaskCppToC, CefTask, cef_task_t>::UnwrapDerived(
    CefWrapperType type,
    cef_task_t* s) {
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount
    CefCppToCRefCounted<CefTaskCppToC, CefTask, cef_task_t>::DebugObjCt
        ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType
    CefCppToCRefCounted<CefTaskCppToC, CefTask, cef_task_t>::kWrapperType =
        WT_TASK;
