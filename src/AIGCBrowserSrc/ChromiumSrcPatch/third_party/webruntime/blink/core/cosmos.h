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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_H_

#include <iostream>
#include <iterator>
#include <map>
#include <regex>
#include <string>
#include <vector>

#include "base/run_loop.h"
#include "cosmos_xobj.h"
#include "third_party/blink/renderer/core/execution_context/execution_context_lifecycle_observer.h"

#include "third_party/blink/renderer/platform/wtf/uuid.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"

#define IPC_CLR_CONTROL_CREARED 20200220
#define IPC_CLR_CONTROL_CREARED_ID _T("Cosmos_CLR_Control_Created")
#define IPC_NODE_CREARED 20200221
#define IPC_NODE_CREARED_ID _T("Cosmos_WndXobj_Created")
#define IPC_NODE_ONMOUSEACTIVATE 20200222
#define IPC_NODE_ONMOUSEACTIVATE_ID _T("Cosmos_WndXobj_OnMouseActivate")
#define IPC_MDIWINFORM_ACTIVEMDICHILD 20200224
#define IPC_MDIWINFORM_ACTIVEMDICHILD_ID _T("MdiWinForm_ActiveMdiChild")

#define IPC_HUBBLE_MSG_BASE 20201202
#define IPC_HUBBLE_MSG_BindCLRObject (IPC_HUBBLE_MSG_BASE + 1)
#define IPC_HUBBLE_MSG_FIRE_EVENT (IPC_HUBBLE_MSG_BASE + 2)
#define IPC_HUBBLE_MSG_WINFORM_CREATED (IPC_HUBBLE_MSG_BASE + 3)
#define IPC_HUBBLE_MSG_WINFORM_ONCLOSE (IPC_HUBBLE_MSG_BASE + 4)
#define IPC_HUBBLE_MSG_Tangram_WndXobj_Created (IPC_HUBBLE_MSG_BASE + 5)
#define IPC_HUBBLE_MSG_BIND_NATIVEOBJ_IPC_MSG (IPC_HUBBLE_MSG_BASE + 6)
#define IPC_HUBBLE_MSG_MdiWinForm_ActiveMdiChild (IPC_HUBBLE_MSG_BASE + 7)
#define IPC_HUBBLE_MSG_MdiWinForm_Ready (IPC_HUBBLE_MSG_BASE + 8)
#define IPC_HUBBLE_MSG_MDIFORM_ALLMDICHILDREMOVED (IPC_HUBBLE_MSG_BASE + 9)
#define IPC_HUBBLE_MSG_OPEN_XML_SPLITTER (IPC_HUBBLE_MSG_BASE + 10)

namespace blink {
using namespace std;

class Element;
class LocalFrame;
class Document;
class ScriptState;
class CosmosXobj;
class CosmosNode;
class CosmosEvent;
class CosmosGalaxy;
class CosmosControl;
class CosmosWinform;
class ExceptionState;
class CosmosCompositor;
class DocumentFragment;
class WebLocalFrameClient;
class SerializedScriptValue;

// for callback:
class CallbackFunctionBase;

class V8ApplicationCallback;

class CORE_EXPORT Cosmos final : public CosmosXobj,
                                 public ExecutionContextClient {
  DEFINE_WRAPPERTYPEINFO();

  friend class CosmosWinform;

 public:
  static std::wstring S2w(String str);
  static String w2S(std::wstring str);
  static std::wstring s2w(std::string str);
  static std::string w2s(std::wstring str);

  static Cosmos* Create(LocalDOMWindow* window) {
    return MakeGarbageCollected<Cosmos>(window);
  }

  void Trace(blink::Visitor*) const override;
  void NTPMsg();

  void openMainWndUrls(String strs);

  v8::Isolate* GetIsolate();
  // Called when an event listener has been successfully added.
  // void AddedEventListener(const AtomicString& event_type,
  //                        RegisteredEventListener&) override;

  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MessageReceived, kWebrt)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(InitWebRTApp, kInitwebrtapp)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(NewDocument, kNewdocument)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(OpenDocument, kOpendocument)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloseDocument, kClosedocument)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(WebrtMessageReceived,
                                          kWebrtmessage)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(MdiChildActivate, kMdichildactivate)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(XobjCreated, kXobjcreated)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(GalaxyCreated, kCosmosgalaxycreated)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(LoadCloudForm, kLoadcloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(LoadMdiCloudForm, kLoadmdicloudform)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudFormClosed, kCloudformclosed)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(WebrtObjectCreated,
                                          kWebrtobjectcreated)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(BindCLRObject, kBindclrobject)
  DEFINE_ATTRIBUTE_EVENT_LISTENER_BYWEBRT(CloudMessageForObject,
                                          kCloudmessageforobject)

  String url();
  CosmosXobj* getNamedItem(const AtomicString&) const;
  CosmosXobj* setNamedItem(CosmosXobj*, ExceptionState&);
  void setNamedItem(const String& name, CosmosXobj* var, ExceptionState&);

  void NamedPropertyEnumerator(Vector<String>& names, ExceptionState&) const;
  bool NamedPropertyQuery(const AtomicString&, ExceptionState&) const;

  void wait(bool bwait);
  void sendMessage(const String& id,
                   const String& param1,
                   const String& param2,
                   const String& param3,
                   const String& param4,
                   const String& param5);
  void sendMessage(CosmosXobj* msg);
  void sendMessage(CosmosXobj* msg, V8ApplicationCallback* callback);
  void sendMessage(CosmosXobj* msg,
                   V8ApplicationCallback* callback,
                   bool bwait);
  void openUrl(const String& url, long nBrowserWndOpenDisposition);
  void openUrl(const String& url,
               long nBrowserWndOpenDisposition,
               V8ApplicationCallback* callback);
  void openUrl(const String& url,
               long nBrowserWndOpenDisposition,
               V8ApplicationCallback* callback,
               bool bwait);
  void Observe(const String& key, const String& strXml);
  void Observe(const String& key,
               const String& strXml,
               V8ApplicationCallback* callback);
  void Observe(const String& key, Element* elem);
  void Observe(const String& key,
               Element* elem,
               V8ApplicationCallback* callback);
  void ObserveClient(const String& key, const String& strXml);
  void ObserveClient(const String& key,
                     const String& strXml,
                     V8ApplicationCallback* callback);
  void ObserveClient(const String& key, Element* elem);
  void ObserveClient(const String& key,
                     Element* elem,
                     V8ApplicationCallback* callback);

  // DOM method
  void defineElement(const String& tagName, const String& html);
  void renderElement(const String& tagName, const String& html);

  // WinForm API:
  void InitWinFormByUrl(const String& url,
                        const int64_t formhandle);
  void InitWinFormByUrl(const String& url,
                        const int64_t formhandle,
                        V8ApplicationCallback* callback);
  void InitWinFormByUrl(const String& url,
                        const int64_t formhandle,
                        V8ApplicationCallback* callback,
                        bool bwait);
  CosmosWinform* InitWinForm(const String& strFormXml,
                             const int64_t formhandle);
  CosmosWinform* InitWinForm(const String& strFormXml,
                             const int64_t formhandle,
                             V8ApplicationCallback* callback);
  CosmosWinform* InitWinForm(Element* elem,
                             const int64_t formhandle);
  CosmosWinform* InitWinForm(Element* elem,
                             const int64_t formhandle,
                             V8ApplicationCallback* callback);
  CosmosWinform* createWinForm(Element* elem,
                               const long FormType);
  CosmosWinform* createWinForm(Element* elem,
                               const long FormType,
                               V8ApplicationCallback* callback);
  CosmosWinform* createWinForm(const String& strFormXml,
                               const long FormType);
  CosmosWinform* createWinForm(const String& strFormXml,
                               const long FormType,
                               V8ApplicationCallback* callback);
  CosmosWinform* newWinForm(int64_t handle, CosmosXobj* obj);
  CosmosWinform* CreateForm(int64_t handle, CosmosXobj* obj);
  // CLR API:
  CosmosXobj* createObject(Element* elem);
  CosmosXobj* createObject(Element* elem, V8ApplicationCallback* callback);
  CosmosXobj* createObject(const String& strObjXml);
  CosmosXobj* createObject(const String& strObjXml,
                           V8ApplicationCallback* callback);

  void RecalcLayoutWnd(int64_t hWndHandle, long delaytime);
  void ReDrawWnd(int64_t hWndHandle, long delaytime);

  // CosmosNode API
  void InitWebRTApp(CosmosXobj* xobj);
  void NewDocument(CosmosXobj* xobj);
  void OpenDocument(CosmosXobj* xobj);
  void CloseDocument(CosmosXobj* xobj);
  void MdiChildActive(CosmosXobj* xobj);
  void MdiChildReady(CosmosXobj* xobj);
  void AllMdiChildRemoved(CosmosXobj* xobj);
  void ProcessMessage(CosmosXobj* xobj);
  void OnMessage(Element* elem, const String& eventName);
  void OnMessage(Element* elem, CosmosXobj* msg, const String& eventName);
  void DispatchXobjEvent(CosmosXobj* xObj,
                         const String& ctrlName,
                         const String& eventName);

  CosmosNode* createCosmosNode(CosmosXobj* xobj);
  CosmosNode* createCosmosWinform(CosmosXobj* xobj);
  void CosmosObjCreated(CosmosXobj* xobj);
  CosmosNode* getXobj(Element* elem);
  CosmosNode* getXobj(Element* elem, CosmosXobj* grid);
  CosmosNode* getXobj(const int64_t nodeHandle);
  CosmosNode* getXobj(const String& galaxyName,
                      const String& clusterName,
                      const String& gridName);

  CosmosGalaxy* getGalaxy(const String& wndName);
  CosmosGalaxy* getGalaxy(const int64_t wndHandle);

  // Non-js method
  void waitMessage();
  void releaseMessage();

  // EventTarget overrides:
  const AtomicString& InterfaceName() const override;
  ExecutionContext* GetExecutionContext() const override;

  explicit Cosmos(LocalDOMWindow* window);
  ~Cosmos() override;
  void Close();

  DocumentFragment* createDocumentFragment();
  CosmosXobj* newVar(const String& strName);
  void invokeWinFormCreatedCallback(CosmosWinform* form);
  bool enableConsoleInfo_ = false;
  String url_;
  mutable Member<Element> helperElem_;
  mutable Member<Element> CosmosElem_;
  mutable Member<Element> m_pVisibleContentElement;

  HeapHashMap<String, Member<CosmosXobj>> mapCloudSession_;
  HeapHashMap<int64_t, Member<CosmosNode>> m_mapWebRTNode;
  HeapHashMap<int64_t, Member<CosmosGalaxy>> m_mapWebRTGalaxy;
  HeapHashMap<int64_t, Member<CosmosWinform>> m_mapWinForm;

  HeapHashMap<int64_t, Member<CosmosNode>> m_mapWebRTNodeforEvent;
  HeapHashMap<int64_t, Member<CosmosWinform>> m_mapWebRTWinformforEvent;
  HeapHashMap<int64_t, Member<CosmosControl>> m_mapWebRTControlforEvent;
  HeapHashMap<String, Member<CosmosGalaxy>> m_mapWebRTGalaxy2;

 private:
  base::RunLoop run_loop_;
  bool is_pending_;
  Vector<String> pending_messages_;
  HeapHashMap<int64_t, Member<CallbackFunctionBase>> mapCallbackFunction_;
};
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_H_
