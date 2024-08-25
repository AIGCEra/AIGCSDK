/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202111090001 *
 ********************************************************************************
 * Copyright (C) 2002-2021 by TangramTeam.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web
 *pages, which are composed of standard DOM elements and binary components
 *supported by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet
 *based on modern javscript/Web technology. Use of this source code is governed
 *by a BSD-style license that can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:TangramTeam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

#include "cosmos_control.h"
#include "cosmos.h"
#include "cosmos_compositor.h"
#include "cosmos_event.h"
#include "cosmos_galaxy.h"
#include "cosmos_node.h"
#include "cosmos_winform.h"

#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_application_callback.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"
#include "third_party/blink/renderer/platform/bindings/callback_function_base.h"

namespace blink {

CosmosControl::CosmosControl() {
  handle_ = 0;
  type_ = "";
  events_ = "";
}

CosmosControl::~CosmosControl() {
  Cosmos* pWebRT = cosmos_.Get();
  if (pWebRT) {
    auto it = pWebRT->m_mapWebRTControlforEvent.find(handle_);
    if (it != pWebRT->m_mapWebRTControlforEvent.end())
      pWebRT->m_mapWebRTControlforEvent.erase(it);
  }
  mapWebRTEventCallback_.clear();
}

CosmosControl* CosmosControl::Create(const String& strNodeName) {
  return MakeGarbageCollected<CosmosControl>(strNodeName);
}

CosmosControl::CosmosControl(const String& strNodeName) {
  name_ = strNodeName;
}

int64_t CosmosControl::handle() {
  return handle_;
}

CosmosNode* CosmosControl::parent() {
  return m_pParentNode;
}

CosmosWinform* CosmosControl::parentForm() {
  return m_pParentForm;
}

CosmosControl* CosmosControl::parentControl() {
  return m_pParentControl;
}

void CosmosControl::BindCtrlEvents(const String& strEvents) {
  if (handle_) {
    if (m_pRenderframeImpl) {
      // m_pRenderframeImpl->m_mapWebRTControl[handle_] = (long)this;
      std::wstring _strBindEvents = Cosmos::S2w(strEvents);
      std::wstring _strCtrlID = Cosmos::S2w(name_);
      std::wstring _strCtrlType = Cosmos::S2w(type_);
      m_pRenderframeImpl->SendCosmosMessage(L"TANGRAM_CTRL_BIND_MESSAGE",
                                            _strCtrlID, handle_, 2020,
                                            _strBindEvents, _strCtrlType);
    }
  }
}

void CosmosControl::Trace(blink::Visitor* visitor) const {
  EventTarget::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  CosmosXobj::Trace(visitor);
  visitor->Trace(cosmos_);
  visitor->Trace(m_pParentNode);
  visitor->Trace(m_pParentForm);
  visitor->Trace(m_pParentControl);
  visitor->Trace(mapWebRTEventCallback_);
}

String CosmosControl::type() {
  return type_;
}
}  // namespace blink
