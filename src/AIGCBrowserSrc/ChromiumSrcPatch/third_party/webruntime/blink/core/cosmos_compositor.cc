/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202111090001           *
 ********************************************************************************
 * Copyright (C) 2002-2021 by TangramTeam.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:TangramTeam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

#include "cosmos.h"
#include "cosmos_node.h"
#include "cosmos_event.h"
#include "cosmos_winform.h"
#include "cosmos_compositor.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"

namespace blink {

CosmosCompositor::CosmosCompositor() : CosmosXobj() {
	m_pRenderframeImpl = nullptr;
	id_ = WTF::CreateCanonicalUUIDString();
}

CosmosCompositor::~CosmosCompositor() {
}

CosmosCompositor* CosmosCompositor::Create(const String& strNodeXml) {
	return MakeGarbageCollected<CosmosCompositor>(strNodeXml);
}

CosmosCompositor::CosmosCompositor(const String& strNodeXml)
{
	m_strXobjXml = strNodeXml;
}

void CosmosCompositor::Trace(blink::Visitor* visitor)const {
	EventTarget::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  CosmosXobj::Trace(visitor);
}
}  // namespace blink
