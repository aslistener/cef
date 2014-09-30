// Copyright (c) 2012 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CEF_LIBCEF_BROWSER_WEB_CONTENTS_VIEW_OSR_H_
#define CEF_LIBCEF_BROWSER_WEB_CONTENTS_VIEW_OSR_H_

#include "content/browser/renderer_host/render_view_host_delegate_view.h"
#include "content/browser/web_contents/web_contents_view.h"

namespace content {
class WebContents;
class WebContentsViewDelegate;
}

class CefRenderWidgetHostViewOSR;

// An implementation of WebContentsView for off-screen rendering.
class CefWebContentsViewOSR : public content::WebContentsView,
                              public content::RenderViewHostDelegateView {
 public:
  CefWebContentsViewOSR();
  virtual ~CefWebContentsViewOSR();

  void set_web_contents(content::WebContents* web_contents);

  // WebContentsView methods.
  virtual gfx::NativeView GetNativeView() const OVERRIDE;
  virtual gfx::NativeView GetContentNativeView() const OVERRIDE;
  virtual gfx::NativeWindow GetTopLevelNativeWindow() const OVERRIDE;
  virtual void GetContainerBounds(gfx::Rect* out) const OVERRIDE;
  virtual void SizeContents(const gfx::Size& size) OVERRIDE;
  virtual void Focus() OVERRIDE;
  virtual void SetInitialFocus() OVERRIDE;
  virtual void StoreFocus() OVERRIDE;
  virtual void RestoreFocus() OVERRIDE;
  virtual content::DropData* GetDropData() const OVERRIDE;
  virtual gfx::Rect GetViewBounds() const OVERRIDE;
  virtual void CreateView(const gfx::Size& initial_size,
                          gfx::NativeView context) OVERRIDE;
  virtual content::RenderWidgetHostViewBase* CreateViewForWidget(
      content::RenderWidgetHost* render_widget_host) OVERRIDE;
  virtual content::RenderWidgetHostViewBase* CreateViewForPopupWidget(
      content::RenderWidgetHost* render_widget_host) OVERRIDE;
  virtual void SetPageTitle(const base::string16& title) OVERRIDE;
  virtual void RenderViewCreated(content::RenderViewHost* host) OVERRIDE;
  virtual void RenderViewSwappedIn(content::RenderViewHost* host) OVERRIDE;
  virtual void SetOverscrollControllerEnabled(bool enabled) OVERRIDE;

#if defined(OS_MACOSX)
  virtual void SetAllowOverlappingViews(bool overlapping) OVERRIDE;
  virtual bool GetAllowOverlappingViews() const OVERRIDE;
  virtual void SetOverlayView(content::WebContentsView* overlay,
                              const gfx::Point& offset) OVERRIDE;
  virtual void RemoveOverlayView() OVERRIDE;
  virtual bool IsEventTracking() const OVERRIDE;
  virtual void CloseTabAfterEventTracking() OVERRIDE;
#endif

  // RenderViewHostDelegateView methods.
  virtual void StartDragging(
      const content::DropData& drop_data,
      blink::WebDragOperationsMask allowed_ops,
      const gfx::ImageSkia& image,
      const gfx::Vector2d& image_offset,
      const content::DragEventSourceInfo& event_info) OVERRIDE;
  virtual void UpdateDragCursor(blink::WebDragOperation operation) OVERRIDE;

 private:
  content::WebContents* web_contents_;
  CefRenderWidgetHostViewOSR* view_;

  DISALLOW_COPY_AND_ASSIGN(CefWebContentsViewOSR);
};

#endif  // CEF_LIBCEF_BROWSER_WEB_CONTENTS_VIEW_OSR_H_
