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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_VAR_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_VAR_H_

#include <map>

#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/serialization/transferables.h"
#include "third_party/blink/renderer/core/dom/events/Event.h"
#include "third_party/blink/renderer/core/dom/events/event_target.h"
#include "third_party/blink/renderer/core/webrt_event_type_names.h"
#include "third_party/blink/renderer/core/dom/element.h"
#include "third_party/webruntime/ChromeRenderDomProxy.h"
#include "third_party/blink/public/web/web_local_frame_client.h"

namespace blink {

using namespace std;

class Cosmos;
class CosmosNode;
class CosmosGalaxy;
class CosmosWinform;
class Document;
class ScriptState;
class ExceptionState;
class DocumentFragment;
class WebLocalFrameClient;
class SerializedScriptValue;
class V8ApplicationCallback;

class CORE_EXPORT CosmosXobj : 
    public EventTarget
{
  DEFINE_WRAPPERTYPEINFO();
  friend class Cosmos;

 public:
  static CosmosXobj* Create() { return MakeGarbageCollected<CosmosXobj>(); }
  static CosmosXobj* Create(const String& strName);

  void Trace(blink::Visitor*) const override;

  // Called when an event listener has been successfully added.
  void AddedEventListener(const AtomicString& event_type,
                          RegisteredEventListener&) override;
  // EventTarget overrides:
  const AtomicString& InterfaceName() const override;
  Element* getElementById(const String& strID, long nLevel);
  NodeList* getElementsByName(const String& localName, long nLevel);
  HTMLCollection* getElementsByTagName(const String& localName, long nLevel);
  void ShowWebContent(const String& strParentDivName, const String& strDivName);

  ExecutionContext* GetExecutionContext() const override;

#define DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(lower_name, symbol_name)      \
  EventListener* on##lower_name() {                                           \
    return GetAttributeEventListener(webrt_event_type_names::symbol_name);    \
  }                                                                           \
  void setOn##lower_name(EventListener* listener) {                           \
    SetAttributeEventListener(webrt_event_type_names::symbol_name, listener); \
  }

  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudMessageForObject,
                                          kCloudmessageforobject)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudMessageForCloudForm,
                                          kCloudmessageforcloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudMessageForXobj,
                                          kCloudmessageforxobj)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MessageReceived, kWebrt)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(XobjCreated, kXobjcreated)

  CosmosXobj();
  CosmosXobj(const String& strNodeName);

  ~CosmosXobj() override;

  mutable Member<Element> uiElem_;
  mutable Member<Element> refElem_;
  mutable Member<Element> hostElem_;
  mutable Member<Element> eventElem_;
  mutable Member<Element> messageElem_;
  mutable Member<Element> propertyElem_;
  mutable Member<Element> m_pVisibleContentElement;
  mutable Member<DocumentFragment> DocumentFragment_;
  mutable Member<DocumentFragment> HostDocumentFragment_;

  Member<Element> element_;

  String name();
  String getid();
  CosmosXobj* grid();
  CosmosXobj* form();
  CosmosXobj* galaxy();

  String msgID();
  void setMsgID(const String& value);

  String caption();
  void setCaption(const String& value);

  CosmosXobj* sender();
  void setSender(CosmosXobj* value);

  Element* element();
  Element* workElement();
  void setWorkElement(Element*);

  String getStr(const String& strKey);
  void setStr(const String& strKey, const String& value);
  long getLong(const String& strKey);
  void setLong(const String& strKey, long value);
  int64_t getInt64(const String& strKey);
  void setInt64(const String& strKey, int64_t value);
  float getFloat(const String& strKey);
  void setFloat(const String& strKey, float value);

  Element* uiElement();
  Element* refElement();
  Element* eventElement();
  Element* messageElement();
  Element* propertyElement();
  DocumentFragment* docFragment();
  DocumentFragment* hostdocFragment();
  Element* getVisibleElement(const String& strKey);
  void setVisibleElement(const String& strKey, Element* value);

  void addEventListener(const String& eventName);
  void addEventListener(const String& eventName,
                        V8ApplicationCallback* callback);
  void addEventListener(const String& subObjName, const String& eventName);
  void addEventListener(const String& subObjName,
                        const String& eventName,
                        V8ApplicationCallback* callback);
  void removeEventListener(const String& eventName);
  void disConnect();
  void fireEvent(const String& eventName, CosmosXobj* eventParam);
  void sendMessage();
  void sendMessage(CosmosXobj* msg);
  void sendMessage(CosmosXobj* msg, V8ApplicationCallback* callback);
  void invokeCallback(wstring callbackid, CosmosXobj* callbackParam);
  void ProcessNodeMessage(const String& msgID);
  void DispatchXobjEvent(Element* elem, const String& eventName);
  // Message method
  void BindCtrlValue(const String& strcontrols);
  void BindCtrlValue(const String& strcontrols,
                     V8ApplicationCallback* callback);

  String id_;
  String name_;
  CommonUniverse::IPCSession session_;
  WebLocalFrameClient* m_pRenderframeImpl;
  mutable Member<CosmosXobj> sender_;
  mutable Member<Cosmos> cosmos_;
  HeapHashMap<String, Member<Element>> mapVisibleElem;
  HeapHashMap<String, Member<V8ApplicationCallback>> mapWebRTEventCallback_;
  HeapHashMap<String, Member<Element>> m_mapElement;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_VAR_H_
