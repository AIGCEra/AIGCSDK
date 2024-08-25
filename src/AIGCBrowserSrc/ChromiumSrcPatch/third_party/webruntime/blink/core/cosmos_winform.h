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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_WINFORM_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_WINFORM_H_

#include <map>
#include "cosmos_xobj.h"

namespace blink {

using namespace std;

class Cosmos;
class DOMParser;
class CosmosXobj;
class CosmosNode;
class CosmosGalaxy;
class CosmosWinform;
class CosmosControl;

// for callback:
class CallbackFunctionBase;
class V8ApplicationCallback;

class Document;
class ScriptState;
class ExceptionState;
class DocumentFragment;
class WebLocalFrameClient;
class SerializedScriptValue;
class V8ApplicationCallback;

class CORE_EXPORT CosmosWinform final : public CosmosXobj {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static CosmosWinform* Create() {
    return MakeGarbageCollected<CosmosWinform>();
  }
  static CosmosWinform* Create(const String& strFormXml);

  void Trace(blink::Visitor*)const override;

  int64_t handle();
  bool isReady();
  long formType();

  CosmosNode* mdibindgrid();
  CosmosWinform* mdiParent();
  CosmosWinform* activeMDIChild();
  CosmosNode* mdiwebbindgrid();
  CosmosNode* getXobj(Element* elem);
  CosmosNode* getXobj(const String& galaxyName,
                      const String& clusterName,
                      const String& gridName);
  void Observe(const String& strCtrlName,
               const String& strKey,
               const String& xml);
  void Observe(const String& strCtrlName,
               const String& strKey,
               const String& xml,
               V8ApplicationCallback* callback);
  void Observe(const String& strCtrlName,
               const String& strKey,
               Element* elem);
  void Observe(const String& strCtrlName,
               const String& strKey,
               Element* elem,
               V8ApplicationCallback* callback);

  CosmosGalaxy* getGalaxy(const String& galaxyName);
  void DispatchXobjEvent(Element* elem, const String& eventName);
  void ProcessFormMessage(const String& msgID);

  void InitWinForm();

  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MdiChildActivate, kMdichildactivate)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(GalaxyCreated, kCosmosgalaxycreated)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(AllMdiChildRemoved, kAllmdichildremoved)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(LoadMdiChildCloudForm, kLoadmdichildcloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudMessageForCloudForm,
                                  kCloudmessageforcloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MdiChildCloudFormReady,
                                  kMdichildcloudformready)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MdiCloudFormReady, kMdicloudformready)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudFormReady, kCloudformready)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(LoadCloudForm, kLoadcloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudFormClosed, kCloudformclosed)

  CosmosWinform();
  CosmosWinform(const String& strNodeXml);

  ~CosmosWinform() override;

  bool isReady_ = false;
  int64_t handle_ = 0;
  int64_t m_nMdiwebbindgridhandle = 0;
  AtomicString m_strAppContents;
  mutable Member<Element> m_pContentElement;
  mutable Member<CosmosNode> m_pBindMdiNode;
  mutable Member<CosmosNode> m_pWebBindMdiNode;
  mutable Member<CosmosWinform> m_pMDIParent;
  mutable Member<CosmosWinform> m_pActiveMDIChild;

  HeapHashMap<String, Member<CosmosGalaxy>> m_mapWebRTGalaxy;
  HeapHashMap<String, Member<CosmosWinform>> m_mapControlBars;

  HeapHashMap<int64_t, Member<CosmosControl>> m_mapChildControl;
  HeapHashMap<String, Member<CosmosControl>> m_mapChildControl2;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_WINFORM_H_
