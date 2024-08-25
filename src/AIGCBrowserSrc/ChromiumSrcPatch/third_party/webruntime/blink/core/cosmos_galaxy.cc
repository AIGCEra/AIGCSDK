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

#include "cosmos_galaxy.h"
#include "cosmos.h"
#include "cosmos_compositor.h"
#include "cosmos_event.h"
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

namespace blink {

CosmosGalaxy::CosmosGalaxy() : CosmosXobj() {}

CosmosGalaxy::~CosmosGalaxy() {
  Cosmos* pWebRT = cosmos_.Get();
  if (pWebRT) {
    auto it = pWebRT->m_mapWebRTGalaxy2.find(name_);
    if (it != pWebRT->m_mapWebRTGalaxy2.end()) {
      pWebRT->m_mapWebRTGalaxy2.erase(it);
    }

    auto it2 = pWebRT->m_mapWebRTGalaxy.find(handle_);
    if (it2 != pWebRT->m_mapWebRTGalaxy.end()) {
      pWebRT->m_mapWebRTGalaxy.erase(it2);
    }
  }
}

CosmosGalaxy* CosmosGalaxy::Create(const String& strWindowName) {
  return MakeGarbageCollected<CosmosGalaxy>(strWindowName);
}

CosmosGalaxy::CosmosGalaxy(const String& strWindowName) {
  name_ = strWindowName;
}

void CosmosGalaxy::Trace(blink::Visitor* visitor) const {
    EventTarget::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  CosmosXobj::Trace(visitor);
  visitor->Trace(m_mapRootNode);
  visitor->Trace(m_mapWebRTNode);
  visitor->Trace(m_mapWebRTNode2);
}

String CosmosGalaxy::name() {
  return name_;
}

String CosmosGalaxy::getid() {
  return id_;
}

int64_t CosmosGalaxy::handle() {
  return handle_;
}

CosmosNode* CosmosGalaxy::getXobj(const String& clusterName,
                                  const String& nodeName) {
  // if (nodeName == "undefined")
  //{
  //	auto it = m_mapRootNode.find(WebString(clusterName).Utf16());
  //	if (it != m_mapRootNode.end())
  //		return it->second;
  //	return nullptr;
  //}
  String strName = clusterName + "__" + nodeName;
  auto it = m_mapWebRTNode2.find(strName);
  if (it != m_mapWebRTNode2.end()) {
    return it->value.Get();
  }
  return nullptr;
}

CosmosNode* CosmosGalaxy::getXobj(const long nodeHandle) {
  auto it = m_mapWebRTNode.find(nodeHandle);
  if (it != m_mapWebRTNode.end()) {
    return it->value.Get();
  }
  return nullptr;
}

}  // namespace blink
