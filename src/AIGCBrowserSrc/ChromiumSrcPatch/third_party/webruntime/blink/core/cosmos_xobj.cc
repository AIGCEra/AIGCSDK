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

#include "cosmos_xobj.h"
#include <codecvt>
#include "base/strings/string_split.h"
#include "base/strings/utf_string_conversions.h"
#include "cosmos.h"
#include "cosmos_event.h"
#include "cosmos_node.h"
#include "cosmos_winform.h"

#include "third_party/blink/public/web/blink.h"
#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_application_callback.h"
#include "third_party/blink/renderer/core/dom/class_collection.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/dom/document_fragment.h"
#include "third_party/blink/renderer/core/dom/dom_token_list.h"
#include "third_party/blink/renderer/core/dom/element.h"
#include "third_party/blink/renderer/core/dom/node.h"
#include "third_party/blink/renderer/core/dom/node_list.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"
#include "third_party/blink/renderer/core/webrt_event_target_names.h"

namespace blink {

CosmosXobj::CosmosXobj() {
  uiElem_ = nullptr;
  refElem_ = nullptr;
  sender_ = nullptr;
  hostElem_ = nullptr;
  eventElem_ = nullptr;
  messageElem_ = nullptr;
  propertyElem_ = nullptr;
  DocumentFragment_ = nullptr;
  HostDocumentFragment_ = nullptr;
  m_pRenderframeImpl = nullptr;
  m_pVisibleContentElement = nullptr;
  id_ = WTF::CreateCanonicalUUIDString();
  session_.m_mapString[L"sessionid"] = Cosmos::S2w(id_);
}

CosmosXobj::~CosmosXobj() {
  session_.m_mapString.clear();
  session_.m_mapLong.clear();
  session_.m_mapFloat.clear();
  mapWebRTEventCallback_.clear();
}

CosmosXobj* CosmosXobj::Create(const String& strNodeXml) {
  return MakeGarbageCollected<CosmosXobj>(strNodeXml);
}

CosmosXobj::CosmosXobj(const String& strName) {
  name_ = strName;
}

void CosmosXobj::Trace(blink::Visitor* visitor) const {
  visitor->Trace(mapVisibleElem);
  visitor->Trace(mapWebRTEventCallback_);
  visitor->Trace(sender_);
  visitor->Trace(cosmos_);
  visitor->Trace(element_);
  visitor->Trace(eventElem_);
  visitor->Trace(hostElem_);
  visitor->Trace(uiElem_);
  visitor->Trace(refElem_);
  visitor->Trace(DocumentFragment_);
  visitor->Trace(HostDocumentFragment_);
  visitor->Trace(messageElem_);
  visitor->Trace(propertyElem_);
  visitor->Trace(m_pVisibleContentElement);
  visitor->Trace(m_mapElement);
  ScriptWrappable::Trace(visitor);
  EventTarget::Trace(visitor);
}

void CosmosXobj::ShowWebContent(const String& strParentDivName,
                                const String& strDivName) {
  String contentname = strDivName;
  String contentparent = strParentDivName;
  Element* visibleElem2 = getVisibleElement(contentname);

  ExceptionState exception_state(cosmos_->GetIsolate(),
      ExceptionContextType::kOperationInvoke,
      "MdiChildActive", "MdiChildActive");

  if (visibleElem2 == nullptr) {
    HTMLCollection* contentCollection =
        cosmos_->DomWindow()->document()->getElementsByClassName(
            WebString(contentparent));
    if (contentCollection) {
      HTMLCollection* contentsElements = contentCollection->item(0)->children();
      if (contentsElements) {
        String strname = contentname;
        WebString _strName = strname;
        for (Element* contentElement : *contentsElements) {
          if (contentElement->classList().contains(_strName)) {
            contentElement->classList().remove({"hidden"}, exception_state);
            contentElement->classList().add({"show"}, exception_state);
            setVisibleElement(contentname, contentElement);
            if (m_pVisibleContentElement == nullptr) {
              m_pVisibleContentElement = contentElement;
            } else {
              m_pVisibleContentElement->classList().remove({"show"},
                                                           exception_state);
              m_pVisibleContentElement->classList().add({"hidden"},
                                                        exception_state);
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
    if (m_pVisibleContentElement != visibleElem2) {
      visibleElem2->classList().remove({"hidden"}, exception_state);
      visibleElem2->classList().add({"show"}, exception_state);
      m_pVisibleContentElement->classList().remove({"show"}, exception_state);
      m_pVisibleContentElement->classList().add({"hidden"}, exception_state);
      m_pVisibleContentElement = visibleElem2;
    }
  }
  // var visibleElem = null;
  // var visibleElem2 = sender.xobj.getVisibleElement(contentname);
  // if (visibleElem2 == null) {
  //    var contentElements =
  //    document.getElementsByClassName(contentparent)[0].children; for
  //    (var i = 0; i < contentElements.length; i++) {
  //        var classList = contentElements[i].classList;
  //        var bContains = classList.contains(contentname);
  //        if (bContains) {
  //            classList.remove("hidden");
  //            classList.add("show");
  //            sender.xobj.setVisibleElement(contentname,
  //            contentElements[i]); if (visibleElem == null)
  //                visibleElem = contentElements[i];
  //            else {
  //                visibleElem.classList.remove("show");
  //                visibleElem.classList.add("hidden");
  //                visibleElem = contentElements[i];
  //                break;
  //            }
  //        } else {
  //            classList.remove("show");
  //            classList.add("hidden");
  //        }
  //    }
  //} else {
  //    if (visibleElem != visibleElem2) {
  //        visibleElem.classList.remove("show");
  //        visibleElem.classList.add("hidden");
  //        visibleElem2.classList.remove("hidden");
  //        visibleElem2.classList.add("show");
  //        visibleElem = visibleElem2;
  //    }
  //}
}

void CosmosXobj::AddedEventListener(
    const AtomicString& event_type,
    RegisteredEventListener& registered_listener) {
  EventTarget::AddedEventListener(event_type, registered_listener);
}

const AtomicString& CosmosXobj::InterfaceName() const {
  return webrt_event_target_names::kCosmosXobj;
}

ExecutionContext* CosmosXobj::GetExecutionContext() const {
  return cosmos_->GetExecutionContext();
}

String CosmosXobj::name() {
  String name = getStr("name@page");
  if (name == "") {
    if (hostElem_) {
      name = hostElem_->GetIdAttribute();
      if (name == "" || name.IsNull()) {
        name = hostElem_->tagName().LowerASCII();
      }
    }
  }
  return name;
}

String CosmosXobj::getid() {
  return id_;
}

CosmosXobj* CosmosXobj::form() {
  __int64 nHandle = getInt64("formhandle");
  if (nHandle) {
    return (CosmosWinform*)this;
  }
  return nullptr;
}

CosmosXobj* CosmosXobj::grid() {
  __int64 nHandle = getInt64("xobjhandle");
  if (nHandle) {
    return (CosmosNode*)this;
  }
  return nullptr;
}

CosmosXobj* CosmosXobj::galaxy() {
  __int64 nHandle = getInt64("xobjhandle");
  if (nHandle) {
    return ((CosmosNode*)this)->parentGalaxy();
  }
  return nullptr;
}

void CosmosXobj::setSender(CosmosXobj* xobj) {
  sender_ = xobj;
}

CosmosXobj* CosmosXobj::sender() {
  return sender_.Get();
}

Element* CosmosXobj::element() {
  return hostElem_.Get();
}

Element* CosmosXobj::workElement() {
  return element_.Get();
}

void CosmosXobj::setWorkElement(Element* elem) {
  element_ = elem;
}

Element* CosmosXobj::eventElement() {
  return eventElem_;
}

Element* CosmosXobj::messageElement() {
  return messageElem_;
}

Element* CosmosXobj::uiElement() {
  return uiElem_;
}

Element* CosmosXobj::refElement() {
  return refElem_;
}

Element* CosmosXobj::propertyElement() {
  return propertyElem_;
}

DocumentFragment* CosmosXobj::docFragment() {
  return DocumentFragment_.Get();
}

DocumentFragment* CosmosXobj::hostdocFragment() {
  if (HostDocumentFragment_) {
    return HostDocumentFragment_.Get();
  }
  return nullptr;
}

void CosmosXobj::BindCtrlValue(const String& strcontrols) {
  setStr("eventtype", "BindCtrlValue");
  setStr("ctrls", strcontrols);
  addEventListener("BindCtrlValue", "OnTextChanged");
}

void CosmosXobj::BindCtrlValue(const String& strcontrols,
                               V8ApplicationCallback* callback) {
  if (callback) {
    setStr("eventtype", "BindCtrlValue");
    setStr("ctrls", strcontrols);
    addEventListener("BindCtrlValue", "OnTextChanged", callback);
  }
}

void CosmosXobj::setStr(const String& strKey, const String& value) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  std::wstring _strVal = Cosmos::S2w(value);
  session_.m_mapString[_strKey] = _strVal;
  auto it = session_.m_mapint64.find(_strKey);
  if (it != session_.m_mapint64.end()) {
    setStr("msgID", "MODIFY_CTRL_VALUE");
    setStr("currentsubobjformodify", strKey);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
  if (value == "") {
    auto it1 = session_.m_mapString.find(_strKey);
    if (it1 != session_.m_mapString.end()) {
      session_.m_mapString.erase(it1);
    }
  }
}

String CosmosXobj::getStr(const String& strKey) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  auto it = session_.m_mapString.find(_strKey);
  if (it != session_.m_mapString.end()) {
    return String(base::WideToUTF16(it->second).c_str());
  }
  return "";
}

void CosmosXobj::setLong(const String& strKey, long value) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  session_.m_mapLong[_strKey] = value;
}

long CosmosXobj::getLong(const String& strKey) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  auto it = session_.m_mapLong.find(_strKey);
  if (it != session_.m_mapLong.end()) {
    return it->second;
  }
  return 0;
}

void CosmosXobj::setInt64(const String& strKey, int64_t value) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  auto it = session_.m_mapint64.find(_strKey);
  if (it != session_.m_mapint64.end()) {
    session_.m_mapint64.erase(it);
  }
  session_.m_mapint64[_strKey] = value;
}

int64_t CosmosXobj::getInt64(const String& strKey) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  auto it = session_.m_mapint64.find(_strKey);
  if (it != session_.m_mapint64.end()) {
    return it->second;
  }
  return 0;
}

void CosmosXobj::setFloat(const String& strKey, float value) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  session_.m_mapFloat[_strKey] = value;
}

float CosmosXobj::getFloat(const String& strKey) {
  std::wstring _strKey = Cosmos::S2w(strKey);
  auto it = session_.m_mapFloat.find(_strKey);
  if (it != session_.m_mapFloat.end()) {
    return it->second;
  }
  return 0;
}

void CosmosXobj::setMsgID(const String& value) {
  session_.m_mapString[L"msgID"] = Cosmos::S2w(value);
}

String CosmosXobj::msgID() {
  WebString str = "msgID";
  auto it = session_.m_mapString.find(L"msgID");
  if (it != session_.m_mapString.end()) {
    std::string _strVal = Cosmos::w2s(it->second);
    return String(_strVal.c_str());
  }
  return "";
}

void CosmosXobj::setCaption(const String& value) {
  std::wstring _strVal = Cosmos::S2w(value);
  session_.m_mapString[L"caption"] = _strVal;
  setStr("msgID", "MODIFY_CTRL_VALUE");
  setStr("currentsubobjformodify", "caption");
  m_pRenderframeImpl->SendCosmosMessageEx(session_);
}

String CosmosXobj::caption() {
  auto it = session_.m_mapString.find(L"caption");
  if (it != session_.m_mapString.end()) {
    return Cosmos::w2S(it->second);
  }
  return "";
}

void CosmosXobj::setVisibleElement(const String& strKey, Element* value) {
  auto it = mapVisibleElem.find(strKey);
  if (it == mapVisibleElem.end()) {
    mapVisibleElem.insert(strKey, value);
  } else {
    mapVisibleElem.erase(it);
    mapVisibleElem.insert(strKey, value);
  }
}

Element* CosmosXobj::getVisibleElement(const String& strKey) {
  auto it = mapVisibleElem.find(strKey);
  if (it != mapVisibleElem.end()) {
    return it->value.Get();
  }
  return nullptr;
}

void CosmosXobj::addEventListener(const String& eventName) {}

void CosmosXobj::addEventListener(const String& eventName,
                                  V8ApplicationCallback* callback) {
  if (callback) {
    auto it = session_.m_mapString.find(L"objID");
    if (it != session_.m_mapString.end()) {
      cosmos_->mapCloudSession_.insert(id_, this);
      // 插入callbackID:
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      std::wstring strID = Cosmos::S2w(callbackid_);
      setStr("callbackid", callbackid_);

      mapWebRTEventCallback_.insert(eventName, callback);
      // 绑定事件名称与callbackid建立对应关系：
      session_.m_mapString[strID] = Cosmos::S2w(eventName);
      session_.m_mapString[L"currentsubobjforlistener"] = L"";

      // 允许RenderFrameImpl根据回调id查找对应的session：
      m_pRenderframeImpl->m_mapWebRTSession[strID] = this;
      // 通知客户端建立监听连接：
      m_pRenderframeImpl->SendCosmosMessageEx(session_);
    }
  }
}

void CosmosXobj::addEventListener(const String& SubObjName,
                                  const String& eventName) {
  // auto it = session_.m_mapString.find(L"objID");
  // if (it != session_.m_mapString.end()) {
  //  cosmos_->mapCloudSession_.insert(id_, this);
  //  String eventName_ = eventName + "@" + SubObjName;
  //  //通知客户端建立监听连接：
  //  setStr("msgID", "WINFORM_CREATED");
  //  m_pRenderframeImpl->SendCosmosMessageEx(session_);
  //}
}

void CosmosXobj::addEventListener(const String& SubObjName,
                                  const String& eventName,
                                  V8ApplicationCallback* callback) {
  if (callback) {
    auto it = session_.m_mapString.find(L"objID");
    if (it != session_.m_mapString.end()) {
      cosmos_->mapCloudSession_.insert(id_, this);
      String eventName_ = eventName + "@" + SubObjName;
      auto it1 = mapWebRTEventCallback_.find(eventName_);
      if (it1 == mapWebRTEventCallback_.end()) {
        mapWebRTEventCallback_.insert(eventName_, callback);
        // 插入callbackID:
        String callbackid_ = WTF::CreateCanonicalUUIDString();
        std::wstring strID = Cosmos::S2w(callbackid_);
        setStr("callbackid", callbackid_);
        // 绑定事件名称与callbackid建立对应关系：
        session_.m_mapString[strID] = Cosmos::S2w(eventName_);

        // 允许RenderFrameImpl根据回调id查找对应的session：
        m_pRenderframeImpl->m_mapWebRTSession[strID] = this;
      } else {
        mapWebRTEventCallback_.erase(it1);
        mapWebRTEventCallback_.insert(eventName_, callback);
      }
      // 通知客户端建立监听连接：
      setStr("msgID", "WINFORM_CREATED");
      m_pRenderframeImpl->SendCosmosMessageEx(session_);
    }
  }
}

void CosmosXobj::removeEventListener(const String& eventName) {
  auto it = mapWebRTEventCallback_.find(eventName);
  if (it != mapWebRTEventCallback_.end()) {
    mapWebRTEventCallback_.erase(it);
  }
}

void CosmosXobj::disConnect() {
  int nSize = mapWebRTEventCallback_.size();
  if (nSize) {
    while (mapWebRTEventCallback_.size()) {
      auto it = mapWebRTEventCallback_.begin();
      mapWebRTEventCallback_.erase(it);
    }
  }
}

void CosmosXobj::fireEvent(const String& eventName, CosmosXobj* eventParam) {
  auto itcallback = mapWebRTEventCallback_.find(eventName);
  if (itcallback != mapWebRTEventCallback_.end()) {
    setStr("callbackid", "");
    blink::V8ApplicationCallback* callback =
        (blink::V8ApplicationCallback*)itcallback->value.Get();
    ScriptState* callback_relevant_script_state =
        callback->CallbackRelevantScriptState();
    ScriptState::Scope callback_relevant_context_scope(
        callback_relevant_script_state);
    callback->InvokeAndReportException(nullptr, eventParam);
  }
}

void CosmosXobj::sendMessage() {
  if (m_pRenderframeImpl) {
    CosmosXobj* msg = this;
    String strMsgID = msg->getStr("msgID");
    if (strMsgID == "" || strMsgID.IsNull()) {
      return;
    }
    msg->setStr("senderid", id_);
    __int64 nHandle = getInt64("xobjhandle");
    if (nHandle == 0) {
      nHandle = getInt64("formhandle");
    }
    msg->setInt64("sender", nHandle);
    m_pRenderframeImpl->SendCosmosMessageEx(msg->session_);
    msg->setStr("msgID", "");
  }
}

void CosmosXobj::sendMessage(CosmosXobj* msg) {
  if (m_pRenderframeImpl) {
    if (msg == nullptr) {
      msg = this;
    }
    String strMsgID = msg->getStr("msgID");
    if (strMsgID == "" || strMsgID.IsNull()) {
      return;
    }
    msg->setStr("senderid", id_);
    __int64 nHandle = getInt64("xobjhandle");
    if (nHandle == 0) {
      nHandle = getInt64("formhandle");
    }
    msg->setInt64("sender", nHandle);
    m_pRenderframeImpl->SendCosmosMessageEx(msg->session_);
    msg->setStr("msgID", "");
  }
}

void CosmosXobj::sendMessage(CosmosXobj* msg, V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl) {
    if (msg == nullptr) {
      msg = this;
    }
    String strMsgID = msg->getStr("msgID");
    if (strMsgID == "" || strMsgID.IsNull()) {
      return;
    }
    msg->setStr("senderid", id_);
    __int64 nHandle = getInt64("xobjhandle");
    if (nHandle == 0) {
      nHandle = getInt64("formhandle");
    }
    msg->setInt64("sender", nHandle);
    if (callback) {
      String callbackid_ = WTF::CreateCanonicalUUIDString();
      msg->setStr("callbackid", callbackid_);
      mapWebRTEventCallback_.insert(callbackid_, callback);
      m_pRenderframeImpl->m_mapWebRTSession[Cosmos::S2w(callbackid_)] = this;
    }
    m_pRenderframeImpl->SendCosmosMessageEx(msg->session_);
    msg->setStr("msgID", "");
  }
}

void CosmosXobj::invokeCallback(wstring callbackid, CosmosXobj* callbackParam) {
  auto itcallback = mapWebRTEventCallback_.find(Cosmos::w2S(callbackid));
  if (itcallback != mapWebRTEventCallback_.end()) {
    blink::V8ApplicationCallback* callback =
        (blink::V8ApplicationCallback*)itcallback->value.Get();
    mapWebRTEventCallback_.erase(itcallback);
    ScriptState* callback_relevant_script_state =
        callback->CallbackRelevantScriptState();
    ScriptState::Scope callback_relevant_context_scope(
        callback_relevant_script_state);
    callback->InvokeAndReportException(this, callbackParam);
  }
}

void CosmosXobj::ProcessNodeMessage(const String& msgID) {
  CosmosNode* thisXobj = (CosmosNode*)grid();
  wstring strHandles = L"";
  if (thisXobj && messageElem_ && msgID.IsNull() == false && msgID != "") {
    wstring _strID = Cosmos::S2w(msgID);
    CosmosNode* xobjfortarget = nullptr;
    HTMLCollection* list =
        messageElem_->getElementsByTagName(AtomicString(msgID.LowerASCII()));
    if (list->length()) {
      Element* msg = list->item(0);
      AtomicString _strHandles = msg->getAttribute(AtomicString("gridhandles"));
      if (_strHandles.IsNull() == false && _strHandles != "") {
        String s = _strHandles;
        strHandles = Cosmos::S2w(s);
        const std::vector<std::wstring> strVecHandles = base::SplitString(
            strHandles, L"|", base::TRIM_WHITESPACE, base::SPLIT_WANT_NONEMPTY);
        int nCount = (int)strVecHandles.size();
        for (int i = 0; i < nCount; i++) {
          __int64 nHandle = std::stoll(strVecHandles[i]);
          if (nHandle) {
            auto it = cosmos_->m_mapWebRTNode.find(nHandle);
            if (it != cosmos_->m_mapWebRTNode.end()) {
              Element* elem = nullptr;
              auto it1 = m_mapElement.find(msgID + "__" +
                                           Cosmos::w2S(strVecHandles[i]));
              if (it1 != m_mapElement.end()) {
                elem = it1->value.Get();
              }
              xobjfortarget = it->value.Get();
              if (!!xobjfortarget) {
                xobjfortarget->setWorkElement(elem);
                xobjfortarget->setMsgID(msgID);
                xobjfortarget->setSender(this);
                xobjfortarget->DispatchEvent(*blink::CosmosEvent::Create(
                    blink::webrt_event_type_names::kCloudmessageforxobj,
                    xobjfortarget));
              }
            }
          }
        }
      } else {
        HTMLCollection* plist = msg->children();
        for (unsigned int i = 0; i < plist->length(); i++) {
          Element* elem = plist->item(i);
          AtomicString target = AtomicString("");
          target = elem->getAttribute(AtomicString("target"));
          if (target.IsNull() || target == AtomicString("")) {
            xobjfortarget = thisXobj;
          } else {
            AtomicString galaxy = elem->getAttribute(AtomicString("galaxy"));
            AtomicString winNucleus = elem->getAttribute(AtomicString("nucleus"));
            if (galaxy == AtomicString("")) {
              galaxy = AtomicString("default");
            }
            if (winNucleus == AtomicString("")) {
              winNucleus = AtomicString("__native_ui_default__");
            }

            xobjfortarget = cosmos_->getXobj(galaxy, winNucleus, target);
            if (xobjfortarget == nullptr) {
              CosmosWinform* form = (CosmosWinform*)thisXobj->parentForm();
              if (form) {
                xobjfortarget = form->getXobj(galaxy, winNucleus, target);
              }
            }
          }
          if (!!xobjfortarget) {
            __int64 nHandle = xobjfortarget->handle();
            wstring strHandle = std::to_wstring(nHandle);
            strHandles += strHandle + L"|";
            m_mapElement.insert(msgID + "__" + Cosmos::w2S(strHandle), elem);
            xobjfortarget->setWorkElement(elem);
            xobjfortarget->setMsgID(msgID);
            xobjfortarget->setSender(this);
            xobjfortarget->DispatchEvent(*blink::CosmosEvent::Create(
                blink::webrt_event_type_names::kCloudmessageforxobj,
                xobjfortarget));
          }
        }
        if (strHandles != L"") {
          msg->setAttribute(AtomicString("gridhandles"),
                            AtomicString(Cosmos::w2S(strHandles)));
        }
      }
    }
  }
}

void CosmosXobj::DispatchXobjEvent(Element* e, const String& eventName) {
  Element* element = static_cast<Element*>(e->childNodes()->item(1));
  if (!!element) {
    for (unsigned int i = 1; i < element->childNodes()->length(); i++) {
      Element* elem = static_cast<Element*>(element->childNodes()->item(i));
      if (elem) {
        Node* pNode = elem;
        if (pNode->getNodeType() == 1) {
          AtomicString target = AtomicString("");
          if (elem->hasAttribute(AtomicString("target"))) {
            target = elem->getAttribute(AtomicString("target"));
            if (target != "") {
              AtomicString galaxy = elem->getAttribute(AtomicString("galaxy"));
              AtomicString winNucleus = elem->getAttribute(AtomicString("nucleus"));
              if (galaxy == "") {
                galaxy = AtomicString("default");
              }
              if (winNucleus == AtomicString("")) {
                winNucleus = AtomicString("__native_ui_default__");
              }

              CosmosNode* xobjfortarget =
                  cosmos_->getXobj(galaxy, winNucleus, target);
              if (xobjfortarget == nullptr) {
                CosmosNode* thisXobj = (CosmosNode*)grid();
                if (thisXobj && thisXobj->m_pParentForm) {
                  xobjfortarget = thisXobj->m_pParentForm->getXobj(
                      galaxy, winNucleus, target);
                } else {
                  CosmosWinform* form_ = (CosmosWinform*)form();
                  if (form_) {
                    xobjfortarget = form_->getXobj(galaxy, winNucleus, target);
                  }
                }
              }
              if (!!xobjfortarget) {
                xobjfortarget->setWorkElement(elem);
                xobjfortarget->setMsgID(e->GetIdAttribute() + "_" + eventName);
                xobjfortarget->DispatchEvent(*blink::CosmosEvent::Create(
                    blink::webrt_event_type_names::kCloudmessageforxobj,
                    xobjfortarget));
              }
            }
          }
        }
      }
    }
  }
}

Element* CosmosXobj::getElementById(const String& strID, long nLevel) {
  CosmosNode* thisXobj = (CosmosNode*)grid();
  if (thisXobj == nullptr && DocumentFragment_) {
    return DocumentFragment_->getElementById(AtomicString(strID));
  }
  if (thisXobj) {
    if (HostDocumentFragment_ == nullptr) {
      if (thisXobj->root() == thisXobj) {
        HostDocumentFragment_ = DocumentFragment_;
      } else {
        HostDocumentFragment_ = cosmos_->createDocumentFragment();
        HostDocumentFragment_->appendChild(element());
      }
    }
  }
  switch (nLevel) {
    case 0: {
      if (thisXobj) {
        return HostDocumentFragment_->getElementById(AtomicString(strID));
      }
    } break;
    case 1: {
      if (thisXobj) {
        CosmosNode* thisParentObj = thisXobj->parent();
        if (thisParentObj) {
          return thisParentObj->getElementById(strID, nLevel);
        }
      }
    } break;
    default:
      if (DocumentFragment_)
        return DocumentFragment_->getElementById(AtomicString(strID));
  }
  return nullptr;
}

NodeList* CosmosXobj::getElementsByName(const String& localName, long nLevel) {
  CosmosNode* thisXobj = (CosmosNode*)grid();
  if (thisXobj == nullptr && DocumentFragment_) {
    return DocumentFragment_->getElementsByName(AtomicString(localName));
  }
  if (thisXobj) {
    if (HostDocumentFragment_ == nullptr) {
      if (thisXobj->root() == thisXobj) {
        HostDocumentFragment_ = DocumentFragment_;
      } else {
        HostDocumentFragment_ = cosmos_->createDocumentFragment();
        HostDocumentFragment_->appendChild(element());
      }
    }
  }
  switch (nLevel) {
    case 0: {
      if (thisXobj) {
        return HostDocumentFragment_->getElementsByName(
            AtomicString(localName));
      }
    } break;
    case 1: {
      if (thisXobj) {
        CosmosNode* thisParentObj = thisXobj->parent();
        if (thisParentObj) {
          return thisParentObj->getElementsByName(localName, nLevel);
        }
      }
    } break;
    default:
      if (DocumentFragment_)
        return DocumentFragment_->getElementsByName(AtomicString(localName));
  }
  return nullptr;
}

HTMLCollection* CosmosXobj::getElementsByTagName(const String& localName,
                                                 long nLevel) {
  CosmosNode* thisXobj = (CosmosNode*)grid();
  if (thisXobj == nullptr && DocumentFragment_) {
    return DocumentFragment_->getElementsByTagName(AtomicString(localName));
  }
  if (thisXobj) {
    if (HostDocumentFragment_ == nullptr) {
      if (thisXobj->root() == thisXobj) {
        HostDocumentFragment_ = DocumentFragment_;
      } else {
        HostDocumentFragment_ = cosmos_->createDocumentFragment();
        HostDocumentFragment_->appendChild(element());
      }
    }
  }
  switch (nLevel) {
    case 0: {
      if (thisXobj) {
        return HostDocumentFragment_->getElementsByTagName(
            AtomicString(localName));
      }
    } break;
    case 1: {
      if (thisXobj) {
        CosmosNode* thisParentObj = thisXobj->parent();
        if (thisParentObj) {
          return thisParentObj->getElementsByTagName(localName, nLevel);
        }
      }
    } break;
    default:
      if (DocumentFragment_)
        return DocumentFragment_->getElementsByTagName(AtomicString(localName));
  }
  return nullptr;
}
}  // namespace blink
