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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_NODE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_NODE_H_

#include <map>
#include "cosmos_xobj.h"

namespace blink {

using namespace std;

class Cosmos;
class Element;
class DOMParser;
class CosmosXobj;
class CosmosGalaxy;
class CosmosWinform;
class CosmosControl;

class Document;
class ScriptState;
class ExceptionState;
class DocumentFragment;
class V8ApplicationCallback;
class WebLocalFrameClient;
class SerializedScriptValue;

class CORE_EXPORT CosmosNode final : public CosmosXobj {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static CosmosNode* Create() { return MakeGarbageCollected<CosmosNode>(); }
  static CosmosNode* Create(const String& strHandle);

  void Trace(blink::Visitor*) const override;

  long row();
  long col();
  long rows();
  long cols();
  int64_t handle();

  CosmosNode* root();
  CosmosNode* parent();
  CosmosXobj* parentGalaxy();
  CosmosXobj* parentForm();

  int64_t hwnd();
  String objtype();
  String getid();

  // Message method
  void sendMessage(const String& id,
                   const String& param1,
                   const String& param2,
                   const String& param3,
                   const String& param4,
                   const String& param5);
  void sendMessageToXobj(CosmosXobj* msg);
  void sendMessageToNode(CosmosNode* node);
  // void ShowWebContent(const String& strParentDivName, const String&
  // strDivName);

  // Control Bind API:
  void setControlVal(const String& CtrlID,
                     int64_t CtrlHandle,
                     const String& strVal);

  CosmosNode* getChild(long nIndex);
  CosmosNode* getChild(long row, long col);
  CosmosNode* getChild(const String& strName);
  CosmosNode* getXobj(const String& strName);
  void Observe(const String& strKey, const String& xml);
  void Observe(const String& strKey,
               const String& xml,
               V8ApplicationCallback* callback);
  void Observe(const String& strCtrlName,
               const String& strKey,
               const String& xml);
  void Observe(const String& strCtrlName,
               const String& strKey,
               const String& xml,
               V8ApplicationCallback* callback);
  void Observe(long row, long col, const String& strKey, const String& xml);
  void Observe(long row,
               long col,
               const String& strKey,
               const String& xml,
               V8ApplicationCallback* callback);
  void ObserveEx(const String& strKey, Element* elem);
  void ObserveEx(const String& strKey,
                 Element* elem,
                 V8ApplicationCallback* callback);
  void ObserveEx(const String& strCtrlName,
                 const String& strKey,
                 Element* elem);
  void ObserveEx(const String& strCtrlName,
                 const String& strKey,
                 Element* elem,
                 V8ApplicationCallback* callback);
  void ObserveEx(long row, long col, const String& strKey, Element* elem);
  void ObserveEx(long row,
                 long col,
                 const String& strKey,
                 Element* elem,
                 V8ApplicationCallback* callback);
  void DispatchXobjEvent(Element* elem, const String& eventName);

  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MdiChildActivate, kMdichildactivate)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(LoadCloudForm, kLoadcloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudMessageForXobj,
                                          kCloudmessageforxobj)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudFormClosed, kCloudformclosed)

  CosmosNode();
  CosmosNode(const String& strNodeXml);
  CosmosNode* AddChild(int64_t nHandle,
                       const String& strNodeName,
                       blink::Cosmos*);

  ~CosmosNode() override;

  int64_t handle_ = 0;

  String name_;

  mutable Member<CosmosNode> rootNode_;
  mutable Member<CosmosWinform> m_pParentForm;

  HeapHashMap<int, Member<CosmosNode>> m_mapChildNode;
  HeapHashMap<String, Member<CosmosNode>> m_mapXobj;
  HeapHashMap<String, Member<CosmosNode>> m_mapChildNode2;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_NODE_H_
