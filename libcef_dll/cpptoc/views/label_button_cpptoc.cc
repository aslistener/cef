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
// $hash=52fba8dedd3422e2c2fb47ae83a5e6e8ea4cede3$
//

#include "libcef_dll/cpptoc/views/label_button_cpptoc.h"
#include "libcef_dll/cpptoc/image_cpptoc.h"
#include "libcef_dll/cpptoc/views/browser_view_cpptoc.h"
#include "libcef_dll/cpptoc/views/button_cpptoc.h"
#include "libcef_dll/cpptoc/views/menu_button_cpptoc.h"
#include "libcef_dll/cpptoc/views/panel_cpptoc.h"
#include "libcef_dll/cpptoc/views/scroll_view_cpptoc.h"
#include "libcef_dll/cpptoc/views/textfield_cpptoc.h"
#include "libcef_dll/cpptoc/views/view_cpptoc.h"
#include "libcef_dll/cpptoc/views/window_cpptoc.h"
#include "libcef_dll/ctocpp/views/button_delegate_ctocpp.h"
#include "libcef_dll/ctocpp/views/view_delegate_ctocpp.h"

// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_label_button_t* cef_label_button_create(
    cef_button_delegate_t* delegate,
    const cef_string_t* text,
    int with_frame) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: delegate; type: refptr_diff
  DCHECK(delegate);
  if (!delegate)
    return NULL;
  // Unverified params: text

  // Execute
  CefRefPtr<CefLabelButton> _retval = CefLabelButton::CreateLabelButton(
      CefButtonDelegateCToCpp::Wrap(delegate), CefString(text),
      with_frame ? true : false);

  // Return type: refptr_same
  return CefLabelButtonCppToC::Wrap(_retval);
}

namespace {

// MEMBER FUNCTIONS - Body may be edited by hand.

cef_menu_button_t* CEF_CALLBACK
label_button_as_menu_button(struct _cef_label_button_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefMenuButton> _retval =
      CefLabelButtonCppToC::Get(self)->AsMenuButton();

  // Return type: refptr_same
  return CefMenuButtonCppToC::Wrap(_retval);
}

void CEF_CALLBACK label_button_set_text(struct _cef_label_button_t* self,
                                        const cef_string_t* text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: text; type: string_byref_const
  DCHECK(text);
  if (!text)
    return;

  // Execute
  CefLabelButtonCppToC::Get(self)->SetText(CefString(text));
}

cef_string_userfree_t CEF_CALLBACK
label_button_get_text(struct _cef_label_button_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefLabelButtonCppToC::Get(self)->GetText();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK label_button_set_image(struct _cef_label_button_t* self,
                                         cef_button_state_t button_state,
                                         cef_image_t* image) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Unverified params: image

  // Execute
  CefLabelButtonCppToC::Get(self)->SetImage(button_state,
                                            CefImageCppToC::Unwrap(image));
}

cef_image_t* CEF_CALLBACK
label_button_get_image(struct _cef_label_button_t* self,
                       cef_button_state_t button_state) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefImage> _retval =
      CefLabelButtonCppToC::Get(self)->GetImage(button_state);

  // Return type: refptr_same
  return CefImageCppToC::Wrap(_retval);
}

void CEF_CALLBACK label_button_set_text_color(struct _cef_label_button_t* self,
                                              cef_button_state_t for_state,
                                              cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(self)->SetTextColor(for_state, color);
}

void CEF_CALLBACK
label_button_set_enabled_text_colors(struct _cef_label_button_t* self,
                                     cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(self)->SetEnabledTextColors(color);
}

void CEF_CALLBACK label_button_set_font_list(struct _cef_label_button_t* self,
                                             const cef_string_t* font_list) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: font_list; type: string_byref_const
  DCHECK(font_list);
  if (!font_list)
    return;

  // Execute
  CefLabelButtonCppToC::Get(self)->SetFontList(CefString(font_list));
}

void CEF_CALLBACK
label_button_set_horizontal_alignment(struct _cef_label_button_t* self,
                                      cef_horizontal_alignment_t alignment) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(self)->SetHorizontalAlignment(alignment);
}

void CEF_CALLBACK
label_button_set_minimum_size(struct _cef_label_button_t* self,
                              const cef_size_t* size) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: size; type: simple_byref_const
  DCHECK(size);
  if (!size)
    return;

  // Translate param: size; type: simple_byref_const
  CefSize sizeVal = size ? *size : CefSize();

  // Execute
  CefLabelButtonCppToC::Get(self)->SetMinimumSize(sizeVal);
}

void CEF_CALLBACK
label_button_set_maximum_size(struct _cef_label_button_t* self,
                              const cef_size_t* size) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: size; type: simple_byref_const
  DCHECK(size);
  if (!size)
    return;

  // Translate param: size; type: simple_byref_const
  CefSize sizeVal = size ? *size : CefSize();

  // Execute
  CefLabelButtonCppToC::Get(self)->SetMaximumSize(sizeVal);
}

cef_label_button_t* CEF_CALLBACK
label_button_as_label_button(struct _cef_button_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefLabelButton> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->AsLabelButton();

  // Return type: refptr_same
  return CefLabelButtonCppToC::Wrap(_retval);
}

void CEF_CALLBACK label_button_set_state(struct _cef_button_t* self,
                                         cef_button_state_t state) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetState(state);
}

cef_button_state_t CEF_CALLBACK
label_button_get_state(struct _cef_button_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CEF_BUTTON_STATE_NORMAL;

  // Execute
  cef_button_state_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetState();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK label_button_set_ink_drop_enabled(struct _cef_button_t* self,
                                                    int enabled) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetInkDropEnabled(enabled ? true : false);
}

void CEF_CALLBACK
label_button_set_tooltip_text(struct _cef_button_t* self,
                              const cef_string_t* tooltip_text) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: tooltip_text; type: string_byref_const
  DCHECK(tooltip_text);
  if (!tooltip_text)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetTooltipText(CefString(tooltip_text));
}

void CEF_CALLBACK label_button_set_accessible_name(struct _cef_button_t* self,
                                                   const cef_string_t* name) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: name; type: string_byref_const
  DCHECK(name);
  if (!name)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetAccessibleName(CefString(name));
}

cef_browser_view_t* CEF_CALLBACK
label_button_as_browser_view(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefBrowserView> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->AsBrowserView();

  // Return type: refptr_same
  return CefBrowserViewCppToC::Wrap(_retval);
}

cef_button_t* CEF_CALLBACK label_button_as_button(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefButton> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->AsButton();

  // Return type: refptr_same
  return CefButtonCppToC::Wrap(_retval);
}

cef_panel_t* CEF_CALLBACK label_button_as_panel(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefPanel> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->AsPanel();

  // Return type: refptr_same
  return CefPanelCppToC::Wrap(_retval);
}

cef_scroll_view_t* CEF_CALLBACK
label_button_as_scroll_view(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefScrollView> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->AsScrollView();

  // Return type: refptr_same
  return CefScrollViewCppToC::Wrap(_retval);
}

cef_textfield_t* CEF_CALLBACK
label_button_as_textfield(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefTextfield> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->AsTextfield();

  // Return type: refptr_same
  return CefTextfieldCppToC::Wrap(_retval);
}

cef_string_userfree_t CEF_CALLBACK
label_button_get_type_string(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetTypeString();

  // Return type: string
  return _retval.DetachToUserFree();
}

cef_string_userfree_t CEF_CALLBACK
label_button_to_string(struct _cef_view_t* self, int include_children) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ToString(include_children ? true : false);

  // Return type: string
  return _retval.DetachToUserFree();
}

int CEF_CALLBACK label_button_is_valid(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsValid();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK label_button_is_attached(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsAttached();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK label_button_is_same(struct _cef_view_t* self,
                                      struct _cef_view_t* that) {
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
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsSame(CefViewCppToC::Unwrap(that));

  // Return type: bool
  return _retval;
}

struct _cef_view_delegate_t* CEF_CALLBACK
label_button_get_delegate(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefViewDelegate> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetDelegate();

  // Return type: refptr_diff
  return CefViewDelegateCToCpp::Unwrap(_retval);
}

struct _cef_window_t* CEF_CALLBACK
label_button_get_window(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefWindow> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetWindow();

  // Return type: refptr_same
  return CefWindowCppToC::Wrap(_retval);
}

int CEF_CALLBACK label_button_get_id(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetID();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK label_button_set_id(struct _cef_view_t* self, int id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetID(id);
}

int CEF_CALLBACK label_button_get_group_id(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetGroupID();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK label_button_set_group_id(struct _cef_view_t* self,
                                            int group_id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetGroupID(group_id);
}

struct _cef_view_t* CEF_CALLBACK
label_button_get_parent_view(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefView> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetParentView();

  // Return type: refptr_same
  return CefViewCppToC::Wrap(_retval);
}

struct _cef_view_t* CEF_CALLBACK
label_button_get_view_for_id(struct _cef_view_t* self, int id) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefView> _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetViewForID(id);

  // Return type: refptr_same
  return CefViewCppToC::Wrap(_retval);
}

void CEF_CALLBACK label_button_set_bounds(struct _cef_view_t* self,
                                          const cef_rect_t* bounds) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: bounds; type: simple_byref_const
  DCHECK(bounds);
  if (!bounds)
    return;

  // Translate param: bounds; type: simple_byref_const
  CefRect boundsVal = bounds ? *bounds : CefRect();

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetBounds(boundsVal);
}

cef_rect_t CEF_CALLBACK label_button_get_bounds(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefRect();

  // Execute
  cef_rect_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetBounds();

  // Return type: simple
  return _retval;
}

cef_rect_t CEF_CALLBACK
label_button_get_bounds_in_screen(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefRect();

  // Execute
  cef_rect_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetBoundsInScreen();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK label_button_set_size(struct _cef_view_t* self,
                                        const cef_size_t* size) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: size; type: simple_byref_const
  DCHECK(size);
  if (!size)
    return;

  // Translate param: size; type: simple_byref_const
  CefSize sizeVal = size ? *size : CefSize();

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetSize(sizeVal);
}

cef_size_t CEF_CALLBACK label_button_get_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetSize();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK label_button_set_position(struct _cef_view_t* self,
                                            const cef_point_t* position) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: position; type: simple_byref_const
  DCHECK(position);
  if (!position)
    return;

  // Translate param: position; type: simple_byref_const
  CefPoint positionVal = position ? *position : CefPoint();

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetPosition(positionVal);
}

cef_point_t CEF_CALLBACK label_button_get_position(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefPoint();

  // Execute
  cef_point_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetPosition();

  // Return type: simple
  return _retval;
}

cef_size_t CEF_CALLBACK
label_button_get_preferred_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetPreferredSize();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK
label_button_size_to_preferred_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SizeToPreferredSize();
}

cef_size_t CEF_CALLBACK
label_button_get_minimum_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetMinimumSize();

  // Return type: simple
  return _retval;
}

cef_size_t CEF_CALLBACK
label_button_get_maximum_size(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return CefSize();

  // Execute
  cef_size_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetMaximumSize();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK label_button_get_height_for_width(struct _cef_view_t* self,
                                                   int width) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  int _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetHeightForWidth(width);

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK label_button_invalidate_layout(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->InvalidateLayout();
}

void CEF_CALLBACK label_button_set_visible(struct _cef_view_t* self,
                                           int visible) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetVisible(visible ? true : false);
}

int CEF_CALLBACK label_button_is_visible(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsVisible();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK label_button_is_drawn(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsDrawn();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK label_button_set_enabled(struct _cef_view_t* self,
                                           int enabled) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetEnabled(enabled ? true : false);
}

int CEF_CALLBACK label_button_is_enabled(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsEnabled();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK label_button_set_focusable(struct _cef_view_t* self,
                                             int focusable) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetFocusable(focusable ? true : false);
}

int CEF_CALLBACK label_button_is_focusable(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsFocusable();

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
label_button_is_accessibility_focusable(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->IsAccessibilityFocusable();

  // Return type: bool
  return _retval;
}

void CEF_CALLBACK label_button_request_focus(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->RequestFocus();
}

void CEF_CALLBACK label_button_set_background_color(struct _cef_view_t* self,
                                                    cef_color_t color) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
      ->SetBackgroundColor(color);
}

cef_color_t CEF_CALLBACK
label_button_get_background_color(struct _cef_view_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  cef_color_t _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->GetBackgroundColor();

  // Return type: simple
  return _retval;
}

int CEF_CALLBACK label_button_convert_point_to_screen(struct _cef_view_t* self,
                                                      cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point ? *point : CefPoint();

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ConvertPointToScreen(pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
label_button_convert_point_from_screen(struct _cef_view_t* self,
                                       cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point ? *point : CefPoint();

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ConvertPointFromScreen(pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK label_button_convert_point_to_window(struct _cef_view_t* self,
                                                      cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point ? *point : CefPoint();

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ConvertPointToWindow(pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK
label_button_convert_point_from_window(struct _cef_view_t* self,
                                       cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point ? *point : CefPoint();

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ConvertPointFromWindow(pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK label_button_convert_point_to_view(struct _cef_view_t* self,
                                                    struct _cef_view_t* view,
                                                    cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: view; type: refptr_same
  DCHECK(view);
  if (!view)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point ? *point : CefPoint();

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ConvertPointToView(CefViewCppToC::Unwrap(view), pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK label_button_convert_point_from_view(struct _cef_view_t* self,
                                                      struct _cef_view_t* view,
                                                      cef_point_t* point) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: view; type: refptr_same
  DCHECK(view);
  if (!view)
    return 0;
  // Verify param: point; type: simple_byref
  DCHECK(point);
  if (!point)
    return 0;

  // Translate param: point; type: simple_byref
  CefPoint pointVal = point ? *point : CefPoint();

  // Execute
  bool _retval =
      CefLabelButtonCppToC::Get(reinterpret_cast<cef_label_button_t*>(self))
          ->ConvertPointFromView(CefViewCppToC::Unwrap(view), pointVal);

  // Restore param: point; type: simple_byref
  if (point)
    *point = pointVal;

  // Return type: bool
  return _retval;
}

}  // namespace

// CONSTRUCTOR - Do not edit by hand.

CefLabelButtonCppToC::CefLabelButtonCppToC() {
  GetStruct()->as_menu_button = label_button_as_menu_button;
  GetStruct()->set_text = label_button_set_text;
  GetStruct()->get_text = label_button_get_text;
  GetStruct()->set_image = label_button_set_image;
  GetStruct()->get_image = label_button_get_image;
  GetStruct()->set_text_color = label_button_set_text_color;
  GetStruct()->set_enabled_text_colors = label_button_set_enabled_text_colors;
  GetStruct()->set_font_list = label_button_set_font_list;
  GetStruct()->set_horizontal_alignment = label_button_set_horizontal_alignment;
  GetStruct()->set_minimum_size = label_button_set_minimum_size;
  GetStruct()->set_maximum_size = label_button_set_maximum_size;
  GetStruct()->base.as_label_button = label_button_as_label_button;
  GetStruct()->base.set_state = label_button_set_state;
  GetStruct()->base.get_state = label_button_get_state;
  GetStruct()->base.set_ink_drop_enabled = label_button_set_ink_drop_enabled;
  GetStruct()->base.set_tooltip_text = label_button_set_tooltip_text;
  GetStruct()->base.set_accessible_name = label_button_set_accessible_name;
  GetStruct()->base.base.as_browser_view = label_button_as_browser_view;
  GetStruct()->base.base.as_button = label_button_as_button;
  GetStruct()->base.base.as_panel = label_button_as_panel;
  GetStruct()->base.base.as_scroll_view = label_button_as_scroll_view;
  GetStruct()->base.base.as_textfield = label_button_as_textfield;
  GetStruct()->base.base.get_type_string = label_button_get_type_string;
  GetStruct()->base.base.to_string = label_button_to_string;
  GetStruct()->base.base.is_valid = label_button_is_valid;
  GetStruct()->base.base.is_attached = label_button_is_attached;
  GetStruct()->base.base.is_same = label_button_is_same;
  GetStruct()->base.base.get_delegate = label_button_get_delegate;
  GetStruct()->base.base.get_window = label_button_get_window;
  GetStruct()->base.base.get_id = label_button_get_id;
  GetStruct()->base.base.set_id = label_button_set_id;
  GetStruct()->base.base.get_group_id = label_button_get_group_id;
  GetStruct()->base.base.set_group_id = label_button_set_group_id;
  GetStruct()->base.base.get_parent_view = label_button_get_parent_view;
  GetStruct()->base.base.get_view_for_id = label_button_get_view_for_id;
  GetStruct()->base.base.set_bounds = label_button_set_bounds;
  GetStruct()->base.base.get_bounds = label_button_get_bounds;
  GetStruct()->base.base.get_bounds_in_screen =
      label_button_get_bounds_in_screen;
  GetStruct()->base.base.set_size = label_button_set_size;
  GetStruct()->base.base.get_size = label_button_get_size;
  GetStruct()->base.base.set_position = label_button_set_position;
  GetStruct()->base.base.get_position = label_button_get_position;
  GetStruct()->base.base.get_preferred_size = label_button_get_preferred_size;
  GetStruct()->base.base.size_to_preferred_size =
      label_button_size_to_preferred_size;
  GetStruct()->base.base.get_minimum_size = label_button_get_minimum_size;
  GetStruct()->base.base.get_maximum_size = label_button_get_maximum_size;
  GetStruct()->base.base.get_height_for_width =
      label_button_get_height_for_width;
  GetStruct()->base.base.invalidate_layout = label_button_invalidate_layout;
  GetStruct()->base.base.set_visible = label_button_set_visible;
  GetStruct()->base.base.is_visible = label_button_is_visible;
  GetStruct()->base.base.is_drawn = label_button_is_drawn;
  GetStruct()->base.base.set_enabled = label_button_set_enabled;
  GetStruct()->base.base.is_enabled = label_button_is_enabled;
  GetStruct()->base.base.set_focusable = label_button_set_focusable;
  GetStruct()->base.base.is_focusable = label_button_is_focusable;
  GetStruct()->base.base.is_accessibility_focusable =
      label_button_is_accessibility_focusable;
  GetStruct()->base.base.request_focus = label_button_request_focus;
  GetStruct()->base.base.set_background_color =
      label_button_set_background_color;
  GetStruct()->base.base.get_background_color =
      label_button_get_background_color;
  GetStruct()->base.base.convert_point_to_screen =
      label_button_convert_point_to_screen;
  GetStruct()->base.base.convert_point_from_screen =
      label_button_convert_point_from_screen;
  GetStruct()->base.base.convert_point_to_window =
      label_button_convert_point_to_window;
  GetStruct()->base.base.convert_point_from_window =
      label_button_convert_point_from_window;
  GetStruct()->base.base.convert_point_to_view =
      label_button_convert_point_to_view;
  GetStruct()->base.base.convert_point_from_view =
      label_button_convert_point_from_view;
}

template <>
CefRefPtr<CefLabelButton>
CefCppToCRefCounted<CefLabelButtonCppToC, CefLabelButton, cef_label_button_t>::
    UnwrapDerived(CefWrapperType type, cef_label_button_t* s) {
  if (type == WT_MENU_BUTTON) {
    return CefMenuButtonCppToC::Unwrap(reinterpret_cast<cef_menu_button_t*>(s));
  }
  NOTREACHED() << "Unexpected class type: " << type;
  return NULL;
}

#if DCHECK_IS_ON()
template <>
base::AtomicRefCount CefCppToCRefCounted<CefLabelButtonCppToC,
                                         CefLabelButton,
                                         cef_label_button_t>::DebugObjCt
    ATOMIC_DECLARATION;
#endif

template <>
CefWrapperType CefCppToCRefCounted<CefLabelButtonCppToC,
                                   CefLabelButton,
                                   cef_label_button_t>::kWrapperType =
    WT_LABEL_BUTTON;
