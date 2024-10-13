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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_WINDOW_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_WINDOW_H_

#include <map>
#include "cosmos_xobj.h"

namespace blink {

using namespace std;

class Cosmos;
class Document;
class ScriptState;
class CosmosXobj;
class CosmosNode;
class ExceptionState;
class WebLocalFrameClient;
class SerializedScriptValue;
class V8ApplicationCallback;

class CORE_EXPORT CosmosGalaxy final : public CosmosXobj{
  DEFINE_WRAPPERTYPEINFO();

 public:
  static CosmosGalaxy* Create() { return MakeGarbageCollected<CosmosGalaxy>(); }
  static CosmosGalaxy* Create(const String& strName);

  void Trace(blink::Visitor*)const override;

  int64_t handle();
  String name();
  String getid();

  //CosmosNode* getXobj(const String& clusterName);
  CosmosNode* getXobj(const String& clusterName, const String& nodeName);
  CosmosNode* getXobj(const long nodeHandle);

  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MdiChildActivate, kMdichildactivate)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(XobjCreated, kXobjcreated)

  CosmosGalaxy();
  CosmosGalaxy(const String& strWindowName);

  ~CosmosGalaxy() override;

  int64_t handle_ = 0;

  HeapHashMap<String, Member<CosmosNode>> m_mapRootNode;
  HeapHashMap<int64_t, Member<CosmosNode>> m_mapWebRTNode;
  HeapHashMap<String, Member<CosmosNode>> m_mapWebRTNode2;
private:
  String m_strWindowXml;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_WINDOW_H_
