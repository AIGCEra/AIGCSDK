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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_COMPOSITOR_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_COMPOSITOR_H_

#include <map>
#include "cosmos_xobj.h"

namespace blink {

using namespace std;

class Document;
class CosmosXobj;
class ScriptState;
class ExceptionState;
class WebLocalFrameClient;
class SerializedScriptValue;

class CORE_EXPORT CosmosCompositor final : public CosmosXobj{
  DEFINE_WRAPPERTYPEINFO();

 public:
  static CosmosCompositor* Create() { return MakeGarbageCollected<CosmosCompositor>(); }
  static CosmosCompositor* Create(const String& strHandle);

  void Trace(blink::Visitor*)const override;

  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MessageReceived, kCosmoscompositor)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(XobjCreated, kXobjcreated)

  CosmosCompositor();
  CosmosCompositor(const String& strNodeXml);

  ~CosmosCompositor() override;

private:
  String m_strXobjXml;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_COMPOSITOR_H_
