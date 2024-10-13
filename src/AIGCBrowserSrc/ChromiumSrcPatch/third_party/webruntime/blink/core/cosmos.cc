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

#include "cosmos.h"
#include <stdlib.h>
#include <codecvt>
#include <iostream>
#include "base/strings/utf_string_conversions.h"
#include "cosmos_compositor.h"
#include "cosmos_control.h"
#include "cosmos_event.h"
#include "cosmos_galaxy.h"
#include "cosmos_node.h"
#include "cosmos_winform.h"

#include <locale>
// #include "base/guid.h"
#include "base/strings/string_split.h"
#include "third_party/blink/public/platform/scheduler/web_agent_group_scheduler.h"
#include "third_party/blink/public/web/blink.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_application_callback.h"
#include "third_party/blink/renderer/core/dom/class_collection.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/dom/document_fragment.h"
#include "third_party/blink/renderer/core/dom/dom_token_list.h"
#include "third_party/blink/renderer/core/dom/element.h"
#include "third_party/blink/renderer/core/dom/name_node_list.h"
#include "third_party/blink/renderer/core/dom/node.h"
#include "third_party/blink/renderer/core/dom/node_list.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"
#include "third_party/blink/renderer/core/webrt_event_target_names.h"
#include "third_party/blink/renderer/core/xml/dom_parser.h"
#include "third_party/blink/renderer/platform/bindings/callback_function_base.h"
#include "third_party/webruntime/ChromeRenderDomProxy.h"

namespace blink {
// Converting a WChar string to a Ansi string
string Cosmos::w2s(wstring str) {
  return base::WideToUTF8(str);
}

std::wstring Cosmos::s2w(std::string str) {
  return base::UTF8ToWide(str);
}

std::wstring Cosmos::S2w(String str) {
  // return base::UTF16ToWide(str.Characters16());
  std::wstring _strVal = s2w(str.Utf8());
  return _strVal;
}

String Cosmos::w2S(std::wstring str) {
  return String(base::WideToUTF16(str).c_str());
}

Cosmos::Cosmos(LocalDOMWindow* window)
    : CosmosXobj(), ExecutionContextClient(window) {
  url_ = "";
  is_pending_ = false;
  helperElem_ = nullptr;
  CosmosElem_ = nullptr;
  m_pRenderframeImpl = nullptr;
  DocumentFragment_ = nullptr;
  m_pVisibleContentElement = nullptr;

  blink::WebLocalFrame* web_frame =
      WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame());
  v8::Isolate* isolate = web_frame->GetAgentGroupScheduler()->Isolate();

  ExceptionState exception_state(
      isolate,  // blink::GetBlinkIsolate(),
      ExceptionContextType::kConstructorOperationInvoke, "createcosmos",
      "creatHelper");
  helperElem_ = window->document()->CreateElementForBinding(
      AtomicString("cosmos"), exception_state);
}

Cosmos::~Cosmos() {}

void Cosmos::Trace(blink::Visitor* visitor) const {
  EventTarget::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  CosmosXobj::Trace(visitor);
  ExecutionContextClient::Trace(visitor);
  visitor->Trace(helperElem_);
  visitor->Trace(CosmosElem_);
  visitor->Trace(m_mapWinForm);
  visitor->Trace(m_mapWebRTNode);
  visitor->Trace(mapCloudSession_);
  visitor->Trace(m_mapWebRTGalaxy);
  visitor->Trace(mapCallbackFunction_);
  visitor->Trace(m_pVisibleContentElement);
  visitor->Trace(m_mapWebRTNodeforEvent);
  visitor->Trace(m_mapWebRTWinformforEvent);
  visitor->Trace(m_mapWebRTControlforEvent);
  visitor->Trace(m_mapWebRTGalaxy2);
}

v8::Isolate* Cosmos::GetIsolate() {
    blink::WebLocalFrame* web_frame =
        WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame());
    return web_frame->GetAgentGroupScheduler()->Isolate();
}

String Cosmos::url() {
  return DomWindow()->document()->Url().GetString();
}

void Cosmos::wait(bool bwait) {
  if (bwait) {
    run_loop_.Run();
  } else {
    run_loop_.Quit();
  }
}
//
// void Cosmos::AddedEventListener(const AtomicString& event_type,
//                                RegisteredEventListener& registered_listener)
//                                {
//  EventTargetWithInlineData::AddedEventListener(event_type,
//                                                registered_listener);
//}

void Cosmos::sendMessage(const String& id,
                         const String& param1,
                         const String& param2,
                         const String& param3,
                         const String& param4,
                         const String& param5) {
  if (m_pRenderframeImpl == nullptr) {
    m_pRenderframeImpl =
        WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame())->Client();
  }
  if (m_pRenderframeImpl) {
    if (is_pending_) {
      String message = id + "%%%" + param1 + "%%%" + param2 + "%%%" + param3 +
                       "%%%" + param4 + "%%%" + param5;
      pending_messages_.push_back(message);
    } else {
      std::wstring u16_id = S2w(id);
      std::wstring u16_param1 = S2w(param1);
      std::wstring u16_param2 = S2w(param2);
      std::wstring u16_param3 = S2w(param3);
      std::wstring u16_param4 = S2w(param4);
      std::wstring u16_param5 = S2w(param5);
      m_pRenderframeImpl->SendCosmosMessage(u16_id, u16_param1, u16_param2,
                                            u16_param3, u16_param4, u16_param5);
    }
  }
}

// Define a element
void Cosmos::defineElement(const String& tagName, const String& html) {
  sendMessage("DEFINE_ELEMENT", tagName, html, "", "", "");
}

// Render an element.
void Cosmos::renderElement(const String& tagName, const String& html) {
  sendMessage("RENDER_ELEMENT", tagName, html, "", "", "");
}

// Render an element.
void Cosmos::NTPMsg() {
  sendMessage("NTP_Msg", "NTP_Msg", "NTP_Msg", "NTP_Msg", "", "");
}

void Cosmos::waitMessage() {
  is_pending_ = true;
}

void Cosmos::releaseMessage() {
  is_pending_ = false;
  if (m_pRenderframeImpl) {
    if (pending_messages_.size() > 0) {
      String stringBuffer = "";
      for (wtf_size_t i = 0; i < pending_messages_.size(); i++) {
        if (i > 0) {
          stringBuffer = stringBuffer + "$$$";
        }
        stringBuffer = stringBuffer + pending_messages_[i];
      }
      std::wstring type = L"AGGREGATED_MESSAGE";
      std::wstring param1 = S2w(stringBuffer);
      m_pRenderframeImpl->SendCosmosMessage(type, param1, L"1", L"", L"", L"");
      pending_messages_.clear();
    }
  }
  // ExceptionState exception_state(blink::MainThreadIsolate(),
  //     ExceptionState::kSetterContext,
  //     "OpenURL", "start");
  // DomWindow()->open(blink::MainThreadIsolate(),
  // AtomicString("https://www.sina.com.cn"),
  //     AtomicString("_parent"), AtomicString(""), exception_state);
}

CosmosXobj* Cosmos::newVar(const String& strName) {
  CosmosXobj* var = CosmosXobj::Create(strName);
  var->m_pRenderframeImpl = m_pRenderframeImpl;
  var->cosmos_ = this;
  return var;
}

void Cosmos::InitWinFormByUrl(const String& url, const int64_t formhandle) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return;
  }
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_URL");
    setStr("openurl", url);
    setLong("BrowserWndOpenDisposition", 1965);
    setInt64("InitFormHandle", formhandle);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::InitWinFormByUrl(const String& url,
                              const int64_t formhandle,
                              V8ApplicationCallback* callback) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return;
  }
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_URL");
    setStr("openurl", url);
    setLong("BrowserWndOpenDisposition", 1965);
    setInt64("InitFormHandle", formhandle);
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::InitWinFormByUrl(const String& url,
                              const int64_t formhandle,
                              V8ApplicationCallback* callback,
                              bool bwait) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return;
  }
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_URL");
    setStr("openurl", url);
    setLong("BrowserWndOpenDisposition", 1965);
    setInt64("InitFormHandle", formhandle);
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  // if (bwait)
  //	run_loop_.Run();
}

CosmosWinform* Cosmos::InitWinForm(const String& strFormXml,
                                   const int64_t formhandle) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return it->value.Get();
  }
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setInt64("InitWinFormHandle", (int64_t)formhandle);
    form->setStr("formXml", strFormXml);
    // form->setLong("formType", FormType);
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::InitWinForm(const String& strFormXml,
                                   const int64_t formhandle,
                                   V8ApplicationCallback* callback) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return it->value.Get();
  }
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  if (callback) {
    mapCallbackFunction_.insert(form->handle_, callback);
  }
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setInt64("InitWinFormHandle", (int64_t)formhandle);
    form->setStr("formXml", strFormXml);
    // form->setLong("formType", FormType);
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::InitWinForm(Element* elem,
                                   const int64_t formhandle,
                                   V8ApplicationCallback* callback) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return it->value.Get();
  }
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  if (callback) {
    mapCallbackFunction_.insert(form->handle_, callback);
  }
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setInt64("InitWinFormHandle", (int64_t)formhandle);
    form->setStr("formXml", elem->outerHTML());
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::InitWinForm(Element* elem, const int64_t formhandle) {
  auto it = m_mapWinForm.find(formhandle);
  if (it != m_mapWinForm.end()) {
    return it->value.Get();
  }
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setInt64("InitWinFormHandle", (int64_t)formhandle);
    form->setStr("formXml", elem->outerHTML());
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::createWinForm(Element* elem, const long FormType) {
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setStr("formXml", elem->outerHTML());
    form->setLong("formType", FormType);
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::createWinForm(Element* elem,
                                     const long FormType,
                                     V8ApplicationCallback* callback) {
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  if (callback) {
    mapCallbackFunction_.insert(form->handle_, callback);
  }
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setStr("formXml", elem->outerHTML());
    form->setLong("formType", FormType);
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::createWinForm(const String& strFormXml,
                                     const long FormType) {
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setStr("formXml", strFormXml);
    form->setLong("formType", FormType);
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosWinform* Cosmos::createWinForm(const String& strFormXml,
                                     const long FormType,
                                     V8ApplicationCallback* callback) {
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = (int64_t)form;
  if (callback) {
    mapCallbackFunction_.insert(form->handle_, callback);
  }
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);

  if (m_pRenderframeImpl) {
    form->setStr("msgID", "CREATE_WINFORM");
    form->setStr("objID", "WinForm");
    form->setInt64("form", (int64_t)form);
    form->setStr("formXml", strFormXml);
    form->setLong("formType", FormType);
    m_pRenderframeImpl->SendCosmosMessageEx(form->session_);
  }
  return form;
}

CosmosXobj* Cosmos::createObject(Element* elem) {
  CosmosXobj* var = CosmosXobj::Create("");
  var->m_pRenderframeImpl = m_pRenderframeImpl;
  var->cosmos_ = this;
  mapCloudSession_.insert(var->id_, var);
  if (m_pRenderframeImpl) {
    var->setStr("msgID", "CREATE_CLROBJ");
    var->setStr("objID", "CLROBJ");
    var->setInt64("objhandle", (int64_t)var);
    var->setStr("objXml", elem->outerHTML());
    m_pRenderframeImpl->SendCosmosMessageEx(var->session_);
  }
  return var;
}

CosmosXobj* Cosmos::createObject(Element* elem,
                                 V8ApplicationCallback* callback) {
  CosmosXobj* var = CosmosXobj::Create("");
  var->m_pRenderframeImpl = m_pRenderframeImpl;
  var->cosmos_ = this;
  mapCloudSession_.insert(var->id_, var);
  if (callback) {
    mapCallbackFunction_.insert((__int64)var, callback);
  }
  if (m_pRenderframeImpl) {
    var->setStr("msgID", "CREATE_CLROBJ");
    var->setStr("objID", "CLROBJ");
    var->setInt64("objhandle", (int64_t)var);
    var->setStr("objXml", elem->outerHTML());
    m_pRenderframeImpl->SendCosmosMessageEx(var->session_);
  }
  return var;
}

CosmosXobj* Cosmos::createObject(const String& strObjXml) {
  CosmosXobj* var = CosmosXobj::Create("");
  var->m_pRenderframeImpl = m_pRenderframeImpl;
  var->cosmos_ = this;
  mapCloudSession_.insert(var->id_, var);
  if (m_pRenderframeImpl) {
    var->setStr("msgID", "CREATE_CLROBJ");
    var->setStr("objID", "CLROBJ");
    var->setInt64("objhandle", (int64_t)var);
    var->setStr("objXml", strObjXml);
    m_pRenderframeImpl->SendCosmosMessageEx(var->session_);
  }
  return var;
}

CosmosXobj* Cosmos::createObject(const String& strObjXml,
                                 V8ApplicationCallback* callback) {
  CosmosXobj* var = CosmosXobj::Create("");
  var->m_pRenderframeImpl = m_pRenderframeImpl;
  var->cosmos_ = this;
  mapCloudSession_.insert(var->id_, var);
  if (callback) {
    mapCallbackFunction_.insert((__int64)var, callback);
  }
  if (m_pRenderframeImpl) {
    var->setStr("msgID", "CREATE_CLROBJ");
    var->setStr("objID", "CLROBJ");
    var->setInt64("objhandle", (int64_t)var);
    var->setStr("objXml", strObjXml);
    m_pRenderframeImpl->SendCosmosMessageEx(var->session_);
  }
  return var;
}
void Cosmos::RecalcLayoutWnd(int64_t hWndHandle, long delaytime) {
  if (m_pRenderframeImpl) {
    this->setStr("msgID", "WebRT_RecalcLayoutWnd");
    this->setStr("objID", "WebRT_RecalcLayoutWnd");
    this->setInt64("workhandle", (int64_t)hWndHandle);
    this->setLong("workdelaytime", delaytime);
    m_pRenderframeImpl->SendCosmosMessageEx(this->session_);
  }
}

void Cosmos::ReDrawWnd(int64_t hWndHandle, long delaytime) {
  if (m_pRenderframeImpl) {
    this->setStr("msgID", "WebRT_ReDrawWnd");
    this->setStr("objID", "WebRT_ReDrawWnd");
    this->setInt64("workhandle", (int64_t)hWndHandle);
    this->setLong("workdelaytime", delaytime);
    m_pRenderframeImpl->SendCosmosMessageEx(this->session_);
  }
}

CosmosWinform* Cosmos::newWinForm(int64_t handle, CosmosXobj* obj) {
  CosmosWinform* form = CosmosWinform::Create("");
  form->cosmos_ = this;
  form->handle_ = handle;
  form->setStr("objID", "WinForm");
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);
  return form;
}

CosmosWinform* Cosmos::CreateForm(int64_t handle, CosmosXobj* obj) {
  CosmosWinform* form = (CosmosWinform*)obj;
  form->cosmos_ = this;
  form->handle_ = handle;
  form->setStr("objID", "WinForm");
  form->m_pRenderframeImpl = m_pRenderframeImpl;
  m_mapWinForm.insert(form->handle_, form);
  form->InitWinForm();

  long nFormType = obj->getLong("WinFormType");
  switch (nFormType) {
    case 0:
      DispatchEvent(*blink::CosmosEvent::Create(
          blink::webrt_event_type_names::kLoadcloudform, obj));
      break;
    case 1:
      DispatchEvent(*blink::CosmosEvent::Create(
          blink::webrt_event_type_names::kLoadmdicloudform, obj));
      break;
    case 2: {
      CosmosWinform* parentform = form->mdiParent();
      if (parentform) {
        parentform->DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kLoadmdichildcloudform, obj));
        // form->DispatchEvent(*blink::CosmosEvent::Create(blink::event_type_names::kMdichildactivate,
        // obj));
        // parentform->DispatchEvent(*blink::CosmosEvent::Create(blink::event_type_names::kMdichildactivate,
        // obj));
      }
    } break;
    default:
      break;
  }
  return form;
}

void Cosmos::InitWebRTApp(CosmosXobj* xobj) {
  DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kInitwebrtapp, xobj));
}

void Cosmos::NewDocument(CosmosXobj* xobj) {
  DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kNewdocument, xobj));
}

void Cosmos::OpenDocument(CosmosXobj* xobj) {
  DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kOpendocument, xobj));
}

void Cosmos::CloseDocument(CosmosXobj* xobj) {
  DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kClosedocument, xobj));
}

void Cosmos::MdiChildActive(CosmosXobj* xobj) {
  __int64 handle = xobj->getInt64("active_mdichildhandle");
  if (handle) {
    CosmosWinform* form = nullptr;
    CosmosWinform* parentmdiform = nullptr;
    auto it = m_mapWinForm.find(handle);
    if (it != m_mapWinForm.end()) {
      form = it->value.Get();
      parentmdiform = form->mdiParent();
      if (!parentmdiform) {
        return;
      }
      parentmdiform->m_pActiveMDIChild = form;
      AtomicString strAppContents = form->m_strAppContents;
      if (strAppContents == AtomicString("") || strAppContents.IsNull()) {
        strAppContents = AtomicString("applicationcontents");
      }
      blink::WebLocalFrame* web_frame =
          WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame());
      v8::Isolate* isolate = web_frame->GetAgentGroupScheduler()->Isolate();
      ExceptionState exception_state(isolate,
                                     ExceptionContextType::kOperationInvoke,
                                     "MdiChildActive", "MdiChildActive");
      if (form->m_pContentElement == nullptr) {
        HTMLCollection* contentCollection =
            DomWindow()->document()->getElementsByClassName(strAppContents);
        if (contentCollection && contentCollection->length()) {
          HTMLCollection* contentsElements =
              contentCollection->item(0)->children();
          if (contentsElements) {
            String strname = form->name();
            WebString _strName = strname;
            for (Element* contentElement : *contentsElements) {
              if (contentElement->classList().contains(_strName)) {
                contentElement->classList().remove({"hidden"}, exception_state);
                contentElement->classList().add({"show"}, exception_state);
                form->m_pContentElement = contentElement;
                if (m_pVisibleContentElement == nullptr) {
                  m_pVisibleContentElement = contentElement;
                } else {
                  if (m_pVisibleContentElement != contentElement) {
                    m_pVisibleContentElement->classList().remove(
                        {"show"}, exception_state);
                    m_pVisibleContentElement->classList().add({"hidden"},
                                                              exception_state);
                  }
                  m_pVisibleContentElement = contentElement;
                  break;
                }
              } else {
                contentElement->classList().remove({"show"}, exception_state);
                contentElement->classList().add({"hidden"}, exception_state);
              }
            }
          }
        }
      } else {
        if (m_pVisibleContentElement != form->m_pContentElement) {
          form->m_pContentElement->classList().remove({"hidden"},
                                                      exception_state);
          form->m_pContentElement->classList().add({"show"}, exception_state);
          if (m_pVisibleContentElement) {
            m_pVisibleContentElement->classList().remove({"show"},
                                                         exception_state);
            m_pVisibleContentElement->classList().add({"hidden"},
                                                      exception_state);
          }
          m_pVisibleContentElement = form->m_pContentElement;
        }
      }
      if (parentmdiform && form) {
        form->DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kMdichildactivate, xobj));
        parentmdiform->DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kMdichildactivate, xobj));
      }
    }
  }
}

void Cosmos::AllMdiChildRemoved(CosmosXobj* xobj) {
  __int64 nHandle = xobj->getInt64("formhandle");
  CosmosWinform* form = nullptr;
  auto it = m_mapWinForm.find(nHandle);
  if (it != m_mapWinForm.end()) {
    form = it->value.Get();
    form->m_pActiveMDIChild = nullptr;
    AtomicString strAppContents = form->m_strAppContents;
    if (strAppContents == AtomicString("") || strAppContents.IsNull()) {
      strAppContents = AtomicString("applicationcontents");
    }
    if (m_pVisibleContentElement) {
      blink::WebLocalFrame* web_frame =
          WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame());
      v8::Isolate* isolate = web_frame->GetAgentGroupScheduler()->Isolate();

      ExceptionState exception_state(
          isolate, ExceptionContextType::kOperationInvoke, "AllMdiChildRemoved",
          "AllMdiChildRemoved");
      m_pVisibleContentElement->classList().remove({"show"}, exception_state);
      m_pVisibleContentElement->classList().add({"hidden"}, exception_state);
      m_pVisibleContentElement = nullptr;
      HTMLCollection* contentCollection =
          DomWindow()->document()->getElementsByClassName(strAppContents);
      if (contentCollection) {
        HTMLCollection* contentsElements =
            contentCollection->item(0)->children();
        if (contentsElements) {
          for (Element* contentElement : *contentsElements) {
            if (contentElement->classList().contains(WebString(form->name()))) {
              contentElement->classList().remove({"hidden"}, exception_state);
              contentElement->classList().add({"show"}, exception_state);
              m_pVisibleContentElement = contentElement;
              break;
            }
          }
        }
      }
    }

    sendMessage("TANGRAM_UI_MESSAGE", "__NATIVE_UI_DEFAULT__", "", "", "", "");
    form->DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kAllmdichildremoved, xobj));
  }
}

void Cosmos::OnMessage(Element* e, const String& eventName) {
  Element* element = static_cast<Element*>(e->childNodes()->item(1));
  if (!!element) {
    for (unsigned int i = 1; i < element->childNodes()->length(); i++) {
      Element* elem = static_cast<Element*>(element->childNodes()->item(i));
      if (elem) {
        CosmosNode* xobjfortarget = nullptr;
        Node* pNode = elem;
        if (pNode->getNodeType() == 1) {
          AtomicString _strHandle = elem->getAttribute(AtomicString(eventName));
          if (_strHandle.IsNull() == false && _strHandle != "") {
            String s = _strHandle;
            wstring _strHandle2 = S2w(s);
            __int64 nHandle = std::stoll(_strHandle2);
            auto it = m_mapWebRTNode.find(nHandle);
            if (it != m_mapWebRTNode.end()) {
              xobjfortarget = it->value.Get();
            }
          }
        }
        if (xobjfortarget == nullptr) {
          xobjfortarget = getXobj(elem, nullptr);
          if (!!xobjfortarget) {
            __int64 nHandle = xobjfortarget->handle();
            wstring strHandle = std::to_wstring(nHandle);
            elem->setAttribute(AtomicString(eventName),
                               AtomicString(String::Number(nHandle)));
          }
        }
        if (!!xobjfortarget) {
          xobjfortarget->setWorkElement(elem);
          String strMsgID = e->GetIdAttribute() + "_" + eventName;
          xobjfortarget->setMsgID(strMsgID);
          xobjfortarget->DispatchEvent(*blink::CosmosEvent::Create(
              blink::webrt_event_type_names::kCloudmessageforxobj,
              xobjfortarget));
        }
      }
    }
  }
}

void Cosmos::OnMessage(Element* e, CosmosXobj* msg, const String& eventName) {
  Element* element = static_cast<Element*>(e->childNodes()->item(1));
  if (!!element) {
    for (unsigned int i = 1; i < element->childNodes()->length(); i++) {
      Element* elem = static_cast<Element*>(element->childNodes()->item(i));
      if (elem) {
        CosmosNode* xobjfortarget = nullptr;
        Node* pNode = elem;
        if (pNode->getNodeType() == 1) {
          AtomicString _strHandle = elem->getAttribute(AtomicString(eventName));
          if (_strHandle.IsNull() == false && _strHandle != "") {
            String s = _strHandle;
            wstring _strHandle2 = S2w(s);
            __int64 nHandle = std::stoll(_strHandle2);

            auto it = m_mapWebRTNode.find(nHandle);
            if (it != m_mapWebRTNode.end()) {
              xobjfortarget = it->value.Get();
            }
          }
        }
        if (xobjfortarget == nullptr) {
          xobjfortarget = getXobj(elem, nullptr);
          if (!!xobjfortarget) {
            __int64 nHandle = xobjfortarget->handle();
            wstring strHandle = std::to_wstring(nHandle);
            elem->setAttribute(AtomicString(eventName),
                               AtomicString(String::Number(nHandle)));
          }
        }
        if (!!xobjfortarget) {
          xobjfortarget->setWorkElement(elem);
          String strMsgID = e->GetIdAttribute() + "_" + eventName;
          if (msg) {
            xobjfortarget->setSender(msg);
          }
          xobjfortarget->setMsgID(strMsgID);
          xobjfortarget->DispatchEvent(*blink::CosmosEvent::Create(
              blink::webrt_event_type_names::kCloudmessageforxobj,
              xobjfortarget));
        }
      }
    }
  }
}

void Cosmos::DispatchXobjEvent(CosmosXobj* xObj,
                               const String& ctrlName,
                               const String& eventName) {
  xObj->fireEvent(eventName + "@" + ctrlName, xObj);
  bool bFormMsgProcessed = false;
  bool bXobjMsgProcessed = false;
  HTMLCollection* list2 = nullptr;
  String ctrlName_ = ctrlName;
  if (ctrlName.IsNull() || ctrlName == "") {
    ctrlName_ = xObj->getStr("name@page");
  }
  xObj->setMsgID(ctrlName_ + "_" + eventName);
  String strXml = xObj->getStr(eventName + "Xml");
  if (strXml.IsNull() || strXml == "") {
    String strEvent = eventName + "@" + ctrlName;
    auto it = xObj->m_mapElement.find(strEvent);
    if (it != xObj->m_mapElement.end()) {
      list2 = it->value->children();
      if (list2 == nullptr && xObj->form() && xObj->form()->eventElem_) {
        HTMLCollection* list = xObj->form()->eventElem_->children();
        if (list->length()) {
          list2 = list;
        }
      }
      HTMLCollection* list =
          xObj->eventElem_->getElementsByTagName(AtomicString(ctrlName));
      if (list->length()) {
        list2 = list;
      }
    }
  } else {
    HTMLCollection* list = xObj->DocumentFragment_->getElementsByTagName(
        AtomicString(xObj->getStr(eventName + "TagName")));
    if (list->length()) {
      list = list->item(0)->getElementsByTagName(
          AtomicString(eventName.LowerASCII()));
      if (list->length()) {
        list2 = list->item(0)->children();
      }
    }
  }
  if (!!list2) {
    for (unsigned int i = 0; i < list2->length(); i++) {
      CosmosNode* xobjfortarget = nullptr;
      Element* elem = (Element*)list2->item(i);
      Node* pNode = elem;
      if (pNode->getNodeType() == 1) {
        AtomicString _strHandle =
            elem->getAttribute(AtomicString("targetgrid"));
        if (_strHandle.IsNull() == false && _strHandle != "") {
          String s = _strHandle;
          wstring _strHandle2 = S2w(s);
          __int64 nHandle = std::stoll(_strHandle2);
          auto it = m_mapWebRTNode.find(nHandle);
          if (it != m_mapWebRTNode.end()) {
            xobjfortarget = it->value.Get();
          }
        }

        if (xobjfortarget == nullptr) {
          AtomicString target = elem->getAttribute(AtomicString("target"));
          if (target == "" || target.IsNull()) {
            if (xObj->grid()) {
              xobjfortarget = (CosmosNode*)xObj->grid();
            } else {
              if (xObj->form()) {
                xObj->form()->element_ = elem;
                xObj->form()->setMsgID(ctrlName_ + "_" + eventName);
                xObj->form()->setSender(xObj);
                bFormMsgProcessed = true;
                xObj->form()->DispatchEvent(*blink::CosmosEvent::Create(
                    blink::webrt_event_type_names::kCloudmessageforcloudform,
                    xObj));
              }
            }
          } else {
            xobjfortarget = getXobj(elem, xObj);
          }
          if (xobjfortarget) {
            bXobjMsgProcessed = true;
            __int64 nHandle = xobjfortarget->handle();
            wstring strHandle = std::to_wstring(nHandle);
            elem->setAttribute(AtomicString("targetgrid"),
                               AtomicString(String::Number(nHandle)));
          }
        }
        if (!!xobjfortarget) {
          xobjfortarget->element_ = elem;
          xobjfortarget->setMsgID(ctrlName_ + "_" + eventName);
          xobjfortarget->setSender(xObj);
          // CosmosEvent* pEvent = blink::CosmosEvent::Create(
          //    blink::event_type_names::kCloudmessageforxobj, xObj);
          CosmosEvent* pEvent = blink::CosmosEvent::Create(
              blink::webrt_event_type_names::kCloudmessageforxobj,
              xobjfortarget);
          xobjfortarget->DispatchEvent(*pEvent);
          xobjfortarget->setMsgID(ctrlName_ + "_" + eventName);
          xobjfortarget->setStr("eventdata", elem->outerHTML());
          m_pRenderframeImpl->SendCosmosMessageEx(xobjfortarget->session_);
        }
      }
    }
  }
  if (xObj->form() && !bFormMsgProcessed) {
    if (xObj->form()->eventElem_) {
      HTMLCollection* eventObjlist =
          xObj->form()->eventElem_->getElementsByTagName(
              AtomicString(ctrlName_));
      if (eventObjlist->length()) {
        xObj->setWorkElement(eventObjlist->item(0));
      }
    }
    xObj->setSender(xObj);
    xObj->DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kCloudmessageforcloudform, xObj));
  } else if (xObj->grid() && !bXobjMsgProcessed) {
    if (xObj->eventElem_ != nullptr) {
      HTMLCollection* eventObjlist =
          xObj->eventElem_->getElementsByTagName(AtomicString(ctrlName_));
      if (eventObjlist->length()) {
        xObj->setWorkElement(eventObjlist->item(0));
      }
    }
    xObj->setSender(xObj);
    xObj->DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kCloudmessageforxobj, xObj));
  }
}

void Cosmos::ProcessMessage(CosmosXobj* xobj) {
  long isObj = xobj->getLong("isobject");
  if (isObj) {
    xobj->DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kCloudmessageforobject, xobj));
    DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kCloudmessageforobject, xobj));
    return;
  } else {
    __int64 nHandle = xobj->getInt64("formhandle");
    if (nHandle) {
      CosmosWinform* form = nullptr;
      auto it = m_mapWinForm.find(nHandle);
      if (it != m_mapWinForm.end()) {
        form = it->value.Get();
        form->DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kCloudmessageforcloudform, xobj));
        form->ProcessFormMessage(xobj->getStr("msgID"));
      }
    }
    nHandle = xobj->getInt64("xobjhandle");
    if (nHandle) {
      auto it = m_mapWebRTNode.find(nHandle);
      if (it != m_mapWebRTNode.end()) {
        CosmosNode* grid = it->value.Get();
        grid->DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kCloudmessageforxobj, xobj));
        grid->ProcessNodeMessage(xobj->getStr("msgID"));
      }
    }
  }
  DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kWebrtmessage, xobj));
}

void Cosmos::MdiChildReady(CosmosXobj* xobj) {
  __int64 handle = xobj->getInt64("ready_mdichildhandle");
  if (handle) {
    CosmosWinform* form = nullptr;
    CosmosWinform* parentmdiform = nullptr;
    auto it = m_mapWinForm.find(handle);
    if (it != m_mapWinForm.end()) {
      form = it->value.Get();
      parentmdiform = form->mdiParent();
    }
    if (parentmdiform && form) {
      form->isReady_ = true;
      form->DispatchEvent(*blink::CosmosEvent::Create(
          blink::webrt_event_type_names::kMdichildcloudformready, xobj));
      parentmdiform->DispatchEvent(*blink::CosmosEvent::Create(
          blink::webrt_event_type_names::kMdichildcloudformready, xobj));
    }
  }
}

void Cosmos::CosmosObjCreated(CosmosXobj* xobj) {
  if (CosmosElem_ == nullptr) {
    HTMLCollection* list =
        DomWindow()->document()->getElementsByTagName(AtomicString("cosmos"));
    if (list->length()) {
      CosmosElem_ = list->item(0);
    }
  }
  String ObjTypeTag = xobj->getStr("ObjectTypeTag");
  if (CosmosElem_ && ObjTypeTag != "") {
    String ObjType = xobj->getStr("objid");
    String sessionid = xobj->getStr("sessionid");
    if (ObjType != "" && ObjType.IsNull() == false) {
      HTMLCollection* list =
          CosmosElem_->getElementsByTagName(AtomicString(ObjType.LowerASCII()));
      if (list->length()) {
        list = list->item(0)->getElementsByTagName(
            AtomicString(ObjTypeTag.LowerASCII()));
        if (list->length()) {
          Element* e = list->item(0);
          if (e) {
            mapCloudSession_.insert(sessionid, xobj);
            xobj->setLong("isobject", 1);
            xobj->setStr("objectxml", e->outerHTML());
            xobj->sendMessage(xobj, nullptr);
          }
        }
      }
    }
    DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kWebrtobjectcreated, xobj));
  }
}

CosmosNode* Cosmos::createCosmosNode(CosmosXobj* xobj) {
  CosmosNode* node = (CosmosNode*)xobj;
  __int64 handle = node->handle_;
  auto itNode = m_mapWebRTNode.find(handle);
  if (itNode != m_mapWebRTNode.end()) {
    return itNode->value.Get();
  }
  node->cosmos_ = this;
  CosmosWinform* parentform = nullptr;
  CosmosWinform* parentmdiform = nullptr;
  String strGalaxyname = xobj->getStr("galaxy");
  String strClustername = xobj->getStr("nucleus");
  ;
  String strname = xobj->getStr("name@page");
  m_mapWebRTNode.insert(handle, node);

  __int64 nPHandle = xobj->getInt64("parenthandle");
  if (nPHandle) {
    auto it = m_mapWebRTNode.find(nPHandle);
    if (it != m_mapWebRTNode.end()) {
      it->value->m_mapChildNode2.insert(strname, node);
    }
  }
  __int64 nGalaxyHandle = xobj->getInt64("Galaxyhandle");
  blink::CosmosGalaxy* pGalaxy = nullptr;
  CosmosNode* m_pRootNode = nullptr;
  bool bNewGalaxy = false;
  if (nGalaxyHandle) {
    auto it1 = m_mapWebRTGalaxy.find(nGalaxyHandle);
    if (it1 != m_mapWebRTGalaxy.end()) {
      __int64 nRootHandle = xobj->getInt64("rootgridhandle");
      auto it = m_mapWebRTNode.find(nRootHandle);
      if (it != m_mapWebRTNode.end()) {
        m_pRootNode = it->value;
      }
      pGalaxy = it1->value;
    } else {
      bNewGalaxy = true;
      m_pRootNode = node;
    }
  }

  nPHandle = xobj->getInt64("parentFormHandle");
  if (nPHandle) {
    auto it = m_mapWinForm.find(nPHandle);
    if (it != m_mapWinForm.end()) {
      parentform = it->value.Get();
      node->m_pParentForm = parentform;
      if (parentform->m_nMdiwebbindgridhandle == handle) {
        parentform->m_pWebBindMdiNode = node;
      }
      parentform->m_mapWebRTGalaxy.insert(strGalaxyname, pGalaxy);
    }
    it = m_mapWinForm.find(xobj->getInt64("parentMDIFormHandle"));
    if (it != m_mapWinForm.end()) {
      parentmdiform = it->value.Get();
    }
  }

  String strMessageXml = "";

  if (m_pRootNode) {
    node->rootNode_ = m_pRootNode;
    m_pRootNode->m_mapXobj.insert(strname, node);

    strMessageXml = xobj->getStr("formxml");
    // if (enableConsoleInfo_) {
    //  DomWindow()->GetFrame()->AddMessageToConsole(
    //      blink::mojom::ConsoleMessageLevel::kInfo, "Create a New Xobj:\n",
    //      false);
    //  DomWindow()->GetFrame()->AddMessageToConsole(
    //      blink::mojom::ConsoleMessageLevel::kInfo, strMessageXml, false);
    //}
    if (node == m_pRootNode && strMessageXml.IsNull() == false &&
        strMessageXml != "") {
      node->DocumentFragment_ =
          DomWindow()->document()->createDocumentFragment();
      if (node->DocumentFragment_) {
          blink::WebLocalFrame* web_frame =
              WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame());
          v8::Isolate* isolate = web_frame->GetAgentGroupScheduler()->Isolate();
          ExceptionState exception_state(isolate,
                                       ExceptionContextType::kAttributeSet,
                                       "Element", "outerHTML");

        helperElem_->setInnerHTML(strMessageXml, exception_state);
        node->DocumentFragment_->appendChild(helperElem_->firstChild());
      }
    }
    long nodeisform = xobj->getLong("nodeisform");
    if (nodeisform != 1) {
      xobj->setStr("formxml", "");
    }
    if (m_pRootNode->DocumentFragment_) {
      node->DocumentFragment_ = m_pRootNode->DocumentFragment_;
      String name(base::NumberToString(handle).c_str());
      blink::NodeList* list_ =
          m_pRootNode->DocumentFragment_->getElementsByName(AtomicString(name));
      if (list_->length()) {
        node->hostElem_ = (Element*)list_->item(0);
        // if (enableConsoleInfo_) {
        //  DomWindow()->GetFrame()->AddMessageToConsole(
        //      blink::mojom::ConsoleMessageLevel::kInfo, "Xobj HTML Code:\n",
        //      false);
        //  DomWindow()->GetFrame()->AddMessageToConsole(
        //      blink::mojom::ConsoleMessageLevel::kInfo,
        //      node->hostElem_->outerHTML(), false);
        //}
        for (unsigned int i = 0; i < node->hostElem_->children()->length();
             i++) {
          Element* e = node->hostElem_->children()->item(i);
          Node* pNode = e;
          if (pNode->getNodeType() == 1) {
            String strTagName = e->tagName().LowerASCII();
            if (strTagName == "messagemap" && node->messageElem_ == nullptr) {
              node->messageElem_ = e;
            } else if (strTagName == "referencemap" &&
                       node->refElem_ == nullptr) {
              node->refElem_ = e;
              HTMLCollection* list2 = e->children();
              unsigned int nlength = list2->length();
              if (nlength) {
                bool breferenced = false;
                for (unsigned int j = 0; j < nlength; j++) {
                  Element* e2 = list2->item(j);
                  Node* pNode2 = e2;
                  if (pNode2->getNodeType() == 1) {
                    CosmosNode* grid = getXobj(e2, node);
                    if (grid) {
                      breferenced = true;
                      e2->setAttribute(
                          AtomicString("handle"),
                          grid->hostElem_->getAttribute(AtomicString("name")));
                    }
                  }
                }
                if (breferenced) {
                  node->setStr("msgID", "SET_REFGRIDS_IPC_MSG");
                  node->setStr("RefInfo", node->refElem_->outerHTML());
                  m_pRenderframeImpl->SendCosmosMessageEx(node->session_);
                }
              }
            } else if (strTagName == "eventmap" &&
                       node->eventElem_ == nullptr) {
              node->eventElem_ = e;
              HTMLCollection* list = e->children();
              unsigned int nCount = list->length();
              if (nCount) {
                for (unsigned int j = 0; j < nCount; j++) {
                  Element* elemEvent = list->item(j);
                  Node* pNode2 = elemEvent;
                  if (pNode2->getNodeType() == 1) {
                    String name2 = elemEvent->tagName().LowerASCII();
                    String eventname =
                        elemEvent->getAttribute(AtomicString("event"));
                    String strIndex = eventname.LowerASCII() + "@" + name2;
                    auto it = node->m_mapElement.find(strIndex);
                    if (it == node->m_mapElement.end()) {
                      node->setStr("msgID", "BIND_NATIVEOBJ_IPC_MSG");
                      node->setStr("BindObj", name2);
                      node->setStr("Bindevent", eventname);
                      node->m_mapElement.insert(strIndex, elemEvent);
                      m_pRenderframeImpl->SendCosmosMessageEx(node->session_);
                      // if (enableConsoleInfo_)
                      //  DomWindow()->GetFrame()->AddMessageToConsole(
                      //      blink::mojom::ConsoleMessageLevel::kInfo,
                      //      elemEvent->outerHTML(), true);
                    }
                  }
                }
              }
            }
            if (node->messageElem_ && node->refElem_ && node->eventElem_) {
              break;
            }
          }
        }
      }

      node->setStr("msgID", "GRIDOBJ_LOAD_IPC_MSG");
      if (m_pRenderframeImpl == nullptr) {
        m_pRenderframeImpl =
            WebLocalFrameImpl::FromFrame(DomWindow()->GetFrame())->Client();
      }
      if (m_pRenderframeImpl) {
        m_pRenderframeImpl->SendCosmosMessageEx(node->session_);
      }
    }
  }

  if (bNewGalaxy) {
    pGalaxy = CosmosGalaxy::Create(strGalaxyname);
    pGalaxy->cosmos_ = this;
    pGalaxy->handle_ = nGalaxyHandle;
    m_mapWebRTGalaxy.insert(nGalaxyHandle, pGalaxy);
    m_mapWebRTGalaxy2.insert(strGalaxyname, pGalaxy);
    pGalaxy->m_mapRootNode.insert(strClustername, node);
    DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kCosmosgalaxycreated, xobj));
  }

  if (pGalaxy) {
    strClustername = strClustername + "__";
    strClustername = strClustername + strname;
    pGalaxy->m_mapWebRTNode.insert(handle, node);
    pGalaxy->m_mapWebRTNode2.insert(strClustername, node);
    pGalaxy->DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kXobjcreated, xobj));
  }

  if (parentform) {
    if (bNewGalaxy) {
      parentform->DispatchEvent(*blink::CosmosEvent::Create(
          blink::webrt_event_type_names::kCosmosgalaxycreated, xobj));
    }

    parentform->DispatchEvent(*blink::CosmosEvent::Create(
        blink::webrt_event_type_names::kXobjcreated, xobj));
    if (parentmdiform && parentform) {
      CosmosNode* pNode = parentform->mdibindgrid();
      if (pNode == nullptr) {
        int64_t nHandle = xobj->getInt64("BindMdiXobjHandle");
        if (nHandle) {
          auto it1 = m_mapWebRTNode.find(nHandle);
          if (it1 != m_mapWebRTNode.end()) {
            parentform->m_pBindMdiNode = it1->value.Get();
          }
        }

        nHandle = xobj->getInt64("mdiwebbindgridhandle");
        if (nHandle) {
          parentform->m_nMdiwebbindgridhandle = nHandle;
          auto it1 = m_mapWebRTNode.find(nHandle);
          if (it1 != m_mapWebRTNode.end()) {
            parentform->m_pWebBindMdiNode = it1->value.Get();
          }
        }
      }
    }
    return node;
    // else
    //{
    //	if (parentmdiform)
    //	{
    //		parentmdiform->DispatchEvent(*blink::CosmosEvent::Create(blink::event_type_names::kXobjcreated,
    // xobj)); 		return node;
    //	}
    //	if (parentform)
    //	{
    //		parentform->DispatchEvent(*blink::CosmosEvent::Create(blink::event_type_names::kXobjcreated,
    // xobj)); 		return node;
    //	}
    //}
  }
  DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kXobjcreated, xobj));

  return node;
}

CosmosNode* Cosmos::createCosmosWinform(CosmosXobj* xobj) {
  blink::CosmosWinform* form = nullptr;
  __int64 handle = xobj->getInt64("form");
  __int64 formhandle = xobj->getInt64("formhandle");
  long nodeisform = xobj->getLong("nodeisform");
  if (nodeisform == 1 && formhandle) {
    if (handle == 0) {
      form = CosmosWinform::Create("");
      form->cosmos_ = this;
      form->handle_ = formhandle;
      form->setStr("objID", "WinForm");
      form->m_pRenderframeImpl = m_pRenderframeImpl;
      m_mapWinForm.insert(form->handle_, form);

      for (auto it1 : xobj->session_.m_mapString) {
        if (it1.first != L"sessionid") {
          if (it1.first == L"gridxml") {
            form->session_.m_mapString[L"formxml"] = it1.second;
          } else {
            form->session_.m_mapString[it1.first] = it1.second;
          }
        }
      }
      for (auto it2 : xobj->session_.m_mapLong) {
        form->session_.m_mapLong[it2.first] = it2.second;
      }
      for (auto it3 : xobj->session_.m_mapint64) {
        form->session_.m_mapint64[it3.first] = it3.second;
      }
      for (auto it4 : xobj->session_.m_mapFloat) {
        form->session_.m_mapFloat[it4.first] = it4.second;
      }
      form->InitWinForm();
      long nFormType = form->getLong("WinFormType");
      switch (nFormType) {
        case 0:
          DispatchEvent(*blink::CosmosEvent::Create(
              blink::webrt_event_type_names::kLoadcloudform, form));
          break;
        case 1:
          DispatchEvent(*blink::CosmosEvent::Create(
              blink::webrt_event_type_names::kLoadmdicloudform, form));
          break;
        default:
          break;
      }
    }
    return nullptr;
  }
  if (handle) {
    auto it = m_mapWinForm.find(handle);
    if (it != m_mapWinForm.end()) {
      form = it->value;
      handle = xobj->getInt64("formhandle");
      if (handle) {
        m_mapWinForm.erase(it);
        m_mapWinForm.insert(handle, form);
        form->handle_ = handle;
        form->InitWinForm();
      }
      if (form) {
        invokeWinFormCreatedCallback(form);
        DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kLoadcloudform, xobj));
      }
    }
  } else {
    handle = xobj->getInt64("formhandle");
    form = CreateForm(handle, xobj);
  }
  return nullptr;
}

CosmosNode* Cosmos::getXobj(Element* elem) {
  if (elem) {
    Node* pNode = elem;
    if (pNode->getNodeType() == 1) {
      AtomicString target = elem->getAttribute(AtomicString("target"));
      AtomicString galaxy = elem->getAttribute(AtomicString("galaxy"));
      AtomicString winNucleus = elem->getAttribute(AtomicString("nucleus"));
      if (galaxy == AtomicString("") || galaxy.IsNull() == true) {
        galaxy = AtomicString("default");
      }
      if (winNucleus == AtomicString("") || winNucleus.IsNull() == true) {
        winNucleus = AtomicString("__native_ui_default__");
      }
      if (target.IsNull() == true || target == AtomicString("")) {
        auto it = m_mapWebRTGalaxy2.find(galaxy);
        if (it != m_mapWebRTGalaxy2.end()) {
          auto it2 = it->value->m_mapRootNode.find(winNucleus);
          if (it2 != it->value->m_mapRootNode.end()) {
            return it2->value.Get();
          }
          return nullptr;
        }
      } else {
        CosmosNode* xobjfortarget = getXobj(galaxy, winNucleus, target);
        if (!!xobjfortarget) {
          return xobjfortarget;
        }
      }
    }
  }
  return nullptr;
}

CosmosNode* Cosmos::getXobj(Element* elem, CosmosXobj* grid) {
  if (elem) {
    Node* pNode = elem;
    if (pNode->getNodeType() == 1) {
      AtomicString target = elem->getAttribute(AtomicString("target"));
      AtomicString galaxy = elem->getAttribute(AtomicString("galaxy"));
      AtomicString winNucleus = elem->getAttribute(AtomicString("nucleus"));
      if (galaxy == AtomicString("") || galaxy.IsNull() == true) {
        galaxy = AtomicString("default");
      }
      if (winNucleus == AtomicString("") || winNucleus.IsNull() == true) {
        winNucleus = AtomicString("__native_ui_default__");
      }
      if (target.IsNull() == true || target == AtomicString("")) {
        auto it = m_mapWebRTGalaxy2.find(galaxy);
        if (it != m_mapWebRTGalaxy2.end()) {
          auto it2 = it->value->m_mapRootNode.find(winNucleus);
          if (it2 != it->value->m_mapRootNode.end()) {
            return it2->value.Get();
          }
          return nullptr;
        }
      } else {
        CosmosNode* xobjfortarget = getXobj(galaxy, winNucleus, target);
        if (xobjfortarget == nullptr && grid) {
          CosmosWinform* form = (CosmosWinform*)grid->form();
          if (grid->grid()) {
            form = (CosmosWinform*)((CosmosNode*)grid->grid())->parentForm();
          }
          if (form) {
            xobjfortarget = form->getXobj(galaxy, winNucleus, target);
            if (xobjfortarget == nullptr && form->mdiParent()) {
              xobjfortarget =
                  form->mdiParent()->getXobj(galaxy, winNucleus, target);
            }
          }
        }
        if (!!xobjfortarget) {
          return xobjfortarget;
        }
      }
    }
  }
  return nullptr;
}

CosmosNode* Cosmos::getXobj(const int64_t nodeHandle) {
  auto it = m_mapWebRTNode.find(nodeHandle);
  if (it != m_mapWebRTNode.end()) {
    return it->value;
  }
  return nullptr;
}

CosmosNode* Cosmos::getXobj(const String& galaxyName,
                            const String& clusterName,
                            const String& gridName) {
  String clusterName_ = clusterName;
  if (clusterName_ == "" || clusterName_.IsNull() == true) {
    clusterName_ = "default";
  }
  auto it = m_mapWebRTGalaxy2.find(galaxyName);
  if (it != m_mapWebRTGalaxy2.end()) {
    if (gridName == "" || gridName.IsNull() == true) {
      auto it2 = it->value->m_mapRootNode.find(clusterName_);
      if (it2 != it->value->m_mapRootNode.end()) {
        return it2->value.Get();
      }
      return nullptr;
    }

    clusterName_ = clusterName + "__" + gridName;
    auto it2 = it->value->m_mapWebRTNode2.find(clusterName_);
    if (it2 != it->value->m_mapWebRTNode2.end()) {
      return it2->value.Get();
    }
  }
  return nullptr;
}

CosmosGalaxy* Cosmos::getGalaxy(const String& wndName) {
  auto it = m_mapWebRTGalaxy2.find(wndName);
  if (it != m_mapWebRTGalaxy2.end()) {
    return it->value.Get();
  }
  return nullptr;
}

CosmosGalaxy* Cosmos::getGalaxy(const int64_t wndHandle) {
  if (wndHandle) {
    auto it = m_mapWebRTGalaxy.find(wndHandle);
    if (it != m_mapWebRTGalaxy.end()) {
      return it->value.Get();
    }
  }
  return nullptr;
}

const AtomicString& Cosmos::InterfaceName() const {
  return webrt_event_target_names::kWebrt;
}

DocumentFragment* Cosmos::createDocumentFragment() {
  return DomWindow()->document()->createDocumentFragment();
}

ExecutionContext* Cosmos::GetExecutionContext() const {
  return ExecutionContextClient::GetExecutionContext();
}

void Cosmos::Observe(const String& key, const String& strXml) {
  sendMessage("TANGRAM_UI_MESSAGE", key, "", strXml, "", "");
}

void Cosmos::Observe(const String& key,
                     const String& strXml,
                     V8ApplicationCallback* callback) {
  sendMessage("TANGRAM_UI_MESSAGE", key, "", strXml, "", "");
}

void Cosmos::Observe(const String& key, Element* elem) {
  sendMessage("TANGRAM_UI_MESSAGE", key, "", elem->outerHTML(), "", "");
}

void Cosmos::Observe(const String& key,
                     Element* elem,
                     V8ApplicationCallback* callback) {
  sendMessage("TANGRAM_UI_MESSAGE", key, "", elem->outerHTML(), "", "");
}

void Cosmos::ObserveClient(const String& key, const String& strXml) {
  sendMessage("Client_UI_MESSAGE", key, "", strXml, "", "");
}

void Cosmos::ObserveClient(const String& key,
                           const String& strXml,
                           V8ApplicationCallback* callback) {
  sendMessage("Client_UI_MESSAGE", key, "", strXml, "", "");
}

void Cosmos::ObserveClient(const String& key, Element* elem) {
  sendMessage("Client_UI_MESSAGE", key, "", elem->outerHTML(), "", "");
}

void Cosmos::ObserveClient(const String& key,
                           Element* elem,
                           V8ApplicationCallback* callback) {
  sendMessage("Client_UI_MESSAGE", key, "", elem->outerHTML(), "", "");
}

void Cosmos::invokeWinFormCreatedCallback(CosmosWinform* form) {
  auto itcallback = mapCallbackFunction_.find((int64_t)form);
  if (itcallback != mapCallbackFunction_.end()) {
    blink::V8ApplicationCallback* callback =
        (blink::V8ApplicationCallback*)itcallback->value.Get();
    ScriptState* callback_relevant_script_state =
        callback->CallbackRelevantScriptState();
    ScriptState::Scope callback_relevant_context_scope(
        callback_relevant_script_state);
    callback->InvokeAndReportException(form, form);
    mapCallbackFunction_.erase(itcallback);
  }
}

void Cosmos::sendMessage(CosmosXobj* msg,
                         V8ApplicationCallback* callback,
                         bool bwait = false) {
  if (m_pRenderframeImpl) {
    if (msg == nullptr) {
      msg = this;
    }
    msg->setStr("senderid", getid());
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      msg->setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(msg->session_);
  }
  // DomWindow()->GetFrame()->AddMessageToConsole(
  //    blink::mojom::ConsoleMessageLevel::kInfo, "test", true);
  //((RenderFrame*)m_pRenderframeImpl)->AddMessageToConsole(blink::mojom::ConsoleMessageLevel::kInfo,
  //	"test");
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::sendMessage(CosmosXobj* msg) {
  if (m_pRenderframeImpl) {
    if (msg == nullptr) {
      msg = this;
    }
    msg->setStr("senderid", getid());
    m_pRenderframeImpl->SendCosmosMessageEx(msg->session_);
  }
  // DomWindow()->GetFrame()->AddMessageToConsole(
  //    blink::mojom::ConsoleMessageLevel::kInfo, "test", true);
  //((RenderFrame*)m_pRenderframeImpl)->AddMessageToConsole(blink::mojom::ConsoleMessageLevel::kInfo,
  //	"test");
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::sendMessage(CosmosXobj* msg, V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl) {
    if (msg == nullptr) {
      msg = this;
    }
    msg->setStr("senderid", getid());
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      msg->setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(msg->session_);
  }
  // DomWindow()->GetFrame()->AddMessageToConsole(
  //    blink::mojom::ConsoleMessageLevel::kInfo, "test", true);
  //((RenderFrame*)m_pRenderframeImpl)->AddMessageToConsole(blink::mojom::ConsoleMessageLevel::kInfo,
  //	"test");
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::openMainWndUrls(String strUrls) {
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_MainWindowURLs");
    setStr("openurl", strUrls);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void Cosmos::openUrl(const String& url, long nBrowserWndOpenDisposition) {
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_URL");
    setStr("openurl", url);
    setLong("BrowserWndOpenDisposition", nBrowserWndOpenDisposition);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::openUrl(const String& url,
                     long nBrowserWndOpenDisposition,
                     V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_URL");
    setStr("openurl", url);
    setLong("BrowserWndOpenDisposition", nBrowserWndOpenDisposition);
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  // if (bwait)
  //	run_loop_.Run();
}

void Cosmos::openUrl(const String& url,
                     long nBrowserWndOpenDisposition,
                     V8ApplicationCallback* callback,
                     bool bwait = false) {
  if (m_pRenderframeImpl) {
    setStr("senderid", getid());
    setStr("msgID", "OPEN_URL");
    setStr("openurl", url);
    setLong("BrowserWndOpenDisposition", nBrowserWndOpenDisposition);
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  // if (bwait)
  //	run_loop_.Run();
}

CosmosXobj* Cosmos::getNamedItem(const AtomicString& name) const {
  auto it = mapCloudSession_.find(name);
  if (it != mapCloudSession_.end()) {
    return it->value.Get();
  }
  return nullptr;
}

void Cosmos::setNamedItem(const String& name,
                          CosmosXobj* var,
                          ExceptionState&) {
  DCHECK(var);
  mapCloudSession_.insert(name, var);
}

CosmosXobj* Cosmos::setNamedItem(CosmosXobj* var,
                                 ExceptionState& exception_state) {
  DCHECK(var);
  mapCloudSession_.insert(var->name(), var);
  return var;
}

void Cosmos::NamedPropertyEnumerator(Vector<String>& names,
                                     ExceptionState&) const {
  for (auto& it : mapCloudSession_) {
    names.UncheckedAppend(it.value->name());
  }
}

bool Cosmos::NamedPropertyQuery(const AtomicString& name,
                                ExceptionState& exception_state) const {
  Vector<String> properties;
  NamedPropertyEnumerator(properties, exception_state);
  return properties.Contains(name);
}

void Cosmos::Close() {
  while (mapCloudSession_.size()) {
    mapCloudSession_.erase(mapCloudSession_.begin());
  }
  while (m_mapWebRTNode.size()) {
    m_mapWebRTNode.erase(m_mapWebRTNode.begin());
  }
  while (m_mapWebRTGalaxy.size()) {
    m_mapWebRTGalaxy.erase(m_mapWebRTGalaxy.begin());
  }
  while (m_mapWinForm.size()) {
    m_mapWinForm.erase(m_mapWinForm.begin());
  }
  while (mapCallbackFunction_.size()) {
    mapCallbackFunction_.erase(mapCallbackFunction_.begin());
  }
}

}  // namespace blink
