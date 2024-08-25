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

#include "cosmos_node.h"
#include "cosmos.h"
#include "cosmos_compositor.h"
#include "cosmos_control.h"
#include "cosmos_event.h"
#include "cosmos_galaxy.h"
#include "cosmos_winform.h"

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
#include "third_party/blink/renderer/core/xml/dom_parser.h"
// #include
//"third_party/blink/renderer/bindings/core/v8/string_or_trusted_html.h"

namespace blink {

CosmosNode::CosmosNode() : CosmosXobj() {
  rootNode_ = nullptr;
  m_pParentForm = nullptr;
}

CosmosNode::~CosmosNode() {
  Cosmos* pWebRT = cosmos_.Get();
  if (pWebRT) {
    auto it = pWebRT->m_mapWebRTNodeforEvent.find(handle_);
    if (it != pWebRT->m_mapWebRTNodeforEvent.end()) {
      pWebRT->m_mapWebRTNodeforEvent.erase(it);
    }

    auto it2 = pWebRT->m_mapWebRTNode.find(handle_);
    if (it2 != pWebRT->m_mapWebRTNode.end()) {
      pWebRT->m_mapWebRTNode.erase(it2);
    }
  }
  mapWebRTEventCallback_.clear();
}

CosmosNode* CosmosNode::Create(const String& strNodeName) {
  return MakeGarbageCollected<CosmosNode>(strNodeName);
}

CosmosNode::CosmosNode(const String& strNodeName) {
  name_ = strNodeName;
}

String CosmosNode::getid() {
  return id_;
}

long CosmosNode::row() {
  return getLong("row");
}

long CosmosNode::col() {
  return getLong("col");
}

long CosmosNode::rows() {
  return getLong("rows");
}

long CosmosNode::cols() {
  return getLong("cols");
}

CosmosXobj* CosmosNode::parentForm() {
  return (CosmosXobj*)m_pParentForm;
}

CosmosNode* CosmosNode::getChild(long nIndex) {
  return getChild(0, nIndex);
}

CosmosNode* CosmosNode::getChild(long row, long col) {
  int nIndex = col + row * getLong("rows");
  std::string strIndex = base::NumberToString(nIndex);
  String strname = strIndex.c_str();
  int64_t nHandle = getInt64(strname);
  if (nHandle) {
    auto it = cosmos_->m_mapWebRTNode.find(nHandle);
    if (it != cosmos_->m_mapWebRTNode.end()) {
      return it->value.Get();
    }
  }
  return nullptr;
}

CosmosNode* CosmosNode::getChild(const String& strName) {
  auto it = m_mapChildNode2.find(strName);
  if (it != m_mapChildNode2.end()) {
    return it->value.Get();
  }
  return nullptr;
}

CosmosNode* CosmosNode::getXobj(const String& strName) {
  CosmosNode* root_ = root();
  auto it = root_->m_mapXobj.find(strName);
  if (it != root_->m_mapXobj.end()) {
    return it->value.Get();
  }
  return nullptr;
}

void CosmosNode::Trace(blink::Visitor* visitor) const {
    EventTarget::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  CosmosXobj::Trace(visitor);
  visitor->Trace(cosmos_);
  visitor->Trace(m_pParentForm);
  visitor->Trace(rootNode_);
  visitor->Trace(mapWebRTEventCallback_);
  visitor->Trace(m_mapChildNode);
  visitor->Trace(m_mapChildNode2);
  visitor->Trace(m_mapXobj);
}

// void CosmosNode::ShowWebContent(const String& strParentDivName, const String&
// strDivName)
//{
//	String contentname = strDivName;
//	String contentparent = strParentDivName;
//	Element* visibleElem2 = getVisibleElement(contentname);
//	ExceptionState exception_state(nullptr,
//		ExceptionState::kExecutionContext,
//		"MdiChildActive",
//		"");
//	if (visibleElem2 == nullptr)
//	{
//		ClassCollection* contentCollection =
//((Document*)GetExecutionContext())->getElementsByClassName(WebString(contentparent));
//		if (contentCollection)
//		{
//			HTMLCollection* contentsElements =
// contentCollection->item(0)->children(); 			if
// (contentsElements)
//			{
//				String strname = contentname;
//				WebString _strName = strname;
//				for (Element* contentElement :
//*contentsElements)
//				{
//					if
//(contentElement->classList().contains(_strName))
//					{
//						contentElement->classList().remove({
//"hidden" }, exception_state);
// contentElement->classList().add({ "show" }, exception_state);
// setVisibleElement(contentname, contentElement);
// if (m_pVisibleContentElement == nullptr)
// m_pVisibleContentElement = contentElement;
// else
//						{
//							m_pVisibleContentElement->classList().remove({
//"show" }, exception_state);
// m_pVisibleContentElement->classList().add({ "hidden" }, exception_state);
// m_pVisibleContentElement = contentElement;
// break;
//						}
//					}
//					else
//					{
//						contentElement->classList().remove({
//"show" }, exception_state);
// contentElement->classList().add({ "hidden" }, exception_state);
//					}

//				}
//			}
//		}
//	}
//	else
//	{
//		if (m_pVisibleContentElement != visibleElem2)
//		{
//			visibleElem2->classList().remove({ "hidden" },
// exception_state); 			visibleElem2->classList().add({ "show"
// },
// exception_state);
// m_pVisibleContentElement->classList().remove({ "show" }, exception_state);
// m_pVisibleContentElement->classList().add({ "hidden" }, exception_state);
// m_pVisibleContentElement = visibleElem2;
//		}
//	}
//	//var visibleElem = null;
//	//var visibleElem2 = sender.xobj.getVisibleElement(contentname);
//	//if (visibleElem2 == null) {
//	//    var contentElements =
// document.getElementsByClassName(contentparent)[0].children;
//	//    for (var i = 0; i < contentElements.length; i++) {
//	//        var classList = contentElements[i].classList;
//	//        var bContains = classList.contains(contentname);
//	//        if (bContains) {
//	//            classList.remove("hidden");
//	//            classList.add("show");
//	//            sender.xobj.setVisibleElement(contentname,
// contentElements[i]);
//	//            if (visibleElem == null)
//	//                visibleElem = contentElements[i];
//	//            else {
//	//                visibleElem.classList.remove("show");
//	//                visibleElem.classList.add("hidden");
//	//                visibleElem = contentElements[i];
//	//                break;
//	//            }
//	//        } else {
//	//            classList.remove("show");
//	//            classList.add("hidden");
//	//        }
//	//    }
//	//} else {
//	//    if (visibleElem != visibleElem2) {
//	//        visibleElem.classList.remove("show");
//	//        visibleElem.classList.add("hidden");
//	//        visibleElem2.classList.remove("hidden");
//	//        visibleElem2.classList.add("show");
//	//        visibleElem = visibleElem2;
//	//    }
//	//}
//}

void CosmosNode::Observe(const String& strKey, const String& xml) {
  if (m_pRenderframeImpl) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML");
    setStr("openkey", strKey);
    setStr("openxml", xml);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::Observe(const String& strKey,
                         const String& xml,
                         V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl) {
    setStr("senderid", id_);
    String callbackid_ = WTF::CreateCanonicalUUIDString();
    setStr("msgID", "OPEN_XML");
    setStr("open_callbackid", callbackid_);
    setStr("openkey", strKey);
    setStr("openxml", xml);
    std::wstring _strID = Cosmos::S2w(callbackid_);

    m_pRenderframeImpl->m_mapWebRTSession[_strID] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::Observe(const String& strCtrlName,
                         const String& strKey,
                         const String& xml) {
  if (m_pRenderframeImpl) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_CTRL");
    setStr("ctrlName", strCtrlName);
    setStr("openkey", strKey);
    setStr("openxml", xml);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
    setStr("msgID", "");
  }
}

void CosmosNode::Observe(const String& strCtrlName,
                         const String& strKey,
                         const String& xml,
                         V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_CTRL");
    setStr("ctrlName", strCtrlName);
    setStr("openkey", strKey);
    setStr("openxml", xml);
    String callbackid_ = WTF::CreateCanonicalUUIDString();
    setStr("opencallbackid", callbackid_);
    std::wstring _strID = Cosmos::S2w(callbackid_);

    m_pRenderframeImpl->m_mapWebRTSession[_strID] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
    setStr("msgID", "");
  }
}

void CosmosNode::Observe(long row,
                         long col,
                         const String& strKey,
                         const String& xml) {
  if (m_pRenderframeImpl) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_SPLITTER");
    setStr("openkey", strKey);
    setStr("openxml", xml);
    setLong("opencol", col);
    setLong("openrow", row);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::Observe(long row,
                         long col,
                         const String& strKey,
                         const String& xml,
                         V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_SPLITTER");
    setStr("openkey", strKey);
    setStr("openxml", xml);
    setLong("opencol", col);
    setLong("openrow", row);
    String callbackid_ = WTF::CreateCanonicalUUIDString();
    setStr("opencallbackid", callbackid_);
    std::wstring _strID = Cosmos::S2w(callbackid_);
    m_pRenderframeImpl->m_mapWebRTSession[_strID] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::ObserveEx(const String& strKey, Element* elem) {
  if (m_pRenderframeImpl && elem) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML");
    setStr("openkey", strKey);
    setStr("openxml", elem->outerHTML());
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::ObserveEx(const String& strKey,
                           Element* elem,
                           V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl && elem) {
    setStr("senderid", id_);
    String callbackid_ = WTF::CreateCanonicalUUIDString();
    setStr("msgID", "OPEN_XML");
    setStr("open_callbackid", callbackid_);
    setStr("openkey", strKey);
    setStr("openxml", elem->outerHTML());
    std::wstring _strID = Cosmos::S2w(callbackid_);
    m_pRenderframeImpl->m_mapWebRTSession[_strID] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::ObserveEx(const String& strCtrlName,
                           const String& strKey,
                           Element* elem) {
  if (m_pRenderframeImpl && elem) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_CTRL");
    setStr("ctrlName", strCtrlName);
    setStr("openkey", strKey);
    setStr("openxml", elem->outerHTML());
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
    setStr("msgID", "");
  }
}

void CosmosNode::ObserveEx(const String& strCtrlName,
                           const String& strKey,
                           Element* elem,
                           V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl && elem) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_CTRL");
    setStr("ctrlName", strCtrlName);
    setStr("openkey", strKey);
    setStr("openxml", elem->outerHTML());
    String callbackid_ = WTF::CreateCanonicalUUIDString();
    setStr("opencallbackid", callbackid_);
    std::wstring _strID = Cosmos::S2w(callbackid_);
    m_pRenderframeImpl->m_mapWebRTSession[_strID] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
    setStr("msgID", "");
  }
}

void CosmosNode::ObserveEx(long row,
                           long col,
                           const String& strKey,
                           Element* elem) {
  if (m_pRenderframeImpl && elem) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_SPLITTER");
    setStr("openkey", strKey);
    setStr("openxml", elem->outerHTML());
    setLong("opencol", col);
    setLong("openrow", row);
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::ObserveEx(long row,
                           long col,
                           const String& strKey,
                           Element* elem,
                           V8ApplicationCallback* callback) {
  if (m_pRenderframeImpl && elem) {
    setStr("senderid", id_);
    setStr("msgID", "OPEN_XML_SPLITTER");
    setStr("openkey", strKey);
    setStr("openxml", elem->outerHTML());
    setLong("opencol", col);
    setLong("openrow", row);
    String callbackid_ = WTF::CreateCanonicalUUIDString();
    setStr("opencallbackid", callbackid_);
    std::wstring _strID = Cosmos::S2w(callbackid_);
    m_pRenderframeImpl->m_mapWebRTSession[_strID] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
  }
}

void CosmosNode::DispatchXobjEvent(Element* e, const String& eventName) {
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
            if (target != AtomicString("")) {
              AtomicString galaxy = elem->getAttribute(AtomicString("galaxy"));
              AtomicString winNucleus = elem->getAttribute(AtomicString("nucleus"));
              if (galaxy == AtomicString("")) {
                galaxy = AtomicString("default");
              }
              if (winNucleus == AtomicString("")) {
                winNucleus = AtomicString("default");
              }

              CosmosNode* xobjfortarget = nullptr;
              if (m_pParentForm) {
                xobjfortarget =
                    m_pParentForm->getXobj(galaxy, winNucleus, target);
              }
              if (xobjfortarget == nullptr) {
                xobjfortarget =
                    cosmos_.Get()->getXobj(galaxy, winNucleus, target);
              }
              if (!!xobjfortarget) {
                xobjfortarget->setWorkElement(elem);
                String msgID = e->GetIdAttribute() + "_" + eventName;
                xobjfortarget->setMsgID(msgID);
                xobjfortarget->DispatchEvent(*blink::CosmosEvent::Create(
                    blink::webrt_event_type_names::kCloudmessageforxobj,
                    xobjfortarget));
                xobjfortarget->setMsgID(msgID);
                xobjfortarget->setStr("eventdata", elem->outerHTML());
                m_pRenderframeImpl->SendCosmosMessageEx(
                    xobjfortarget->session_);
              }
            }
          }
        }
      }
    }
  }
}

void CosmosNode::sendMessageToXobj(CosmosXobj* msg) {
  if (msg) {
    Cosmos* pWebRT = cosmos_.Get();
    __int64 nHandle = msg->getInt64("xobjhandle");
    CosmosNode* grid = nullptr;
    if (nHandle) {
      auto it = pWebRT->m_mapWebRTNode.find(nHandle);
      if (it != pWebRT->m_mapWebRTNode.end()) {
        grid = it->value.Get();
        grid->DispatchEvent(*blink::CosmosEvent::Create(
            blink::webrt_event_type_names::kCloudmessageforxobj, msg));
      }
    }
  }
}

void CosmosNode::sendMessageToNode(CosmosNode* grid) {
  grid->DispatchEvent(*blink::CosmosEvent::Create(
      blink::webrt_event_type_names::kCloudmessageforxobj, grid));
}

void CosmosNode::setControlVal(const String& CtrlID,
                               int64_t CtrlHandle,
                               const String& strVal) {
  if (m_pRenderframeImpl) {
    std::wstring _val = Cosmos::S2w(strVal);
    std::wstring _strCtrlID = Cosmos::S2w(CtrlID);
    m_pRenderframeImpl->SendCosmosMessage(L"TANGRAM_CTRL_VALUE_MESSAGE",
                                          _strCtrlID, CtrlHandle, 0, _val, L"");
  }
}

int64_t CosmosNode::hwnd() {
  return handle_;
}

String CosmosNode::objtype() {
  return getStr("objtype");
}

void CosmosNode::sendMessage(const String& id,
                             const String& param1,
                             const String& param2,
                             const String& param3,
                             const String& param4,
                             const String& param5) {
  if (m_pRenderframeImpl) {
    std::wstring u16_id = Cosmos::S2w(id);
    std::wstring u16_param1 = Cosmos::S2w(param1);
    std::wstring u16_param2 = Cosmos::S2w(param2);
    std::wstring u16_param3 = Cosmos::S2w(param3);
    std::wstring u16_param4 = Cosmos::S2w(param4);
    std::wstring u16_param5 = Cosmos::S2w(param5);
    m_pRenderframeImpl->SendCosmosMessage(u16_id, u16_param1, u16_param2,
                                          u16_param3, u16_param4, u16_param5);
  }
}

int64_t CosmosNode::handle() {
  return handle_;
}

CosmosNode* CosmosNode::parent() {
  __int64 nHandle = getInt64("parenthandle");
  if (nHandle) {
    auto it = cosmos_->m_mapWebRTNode.find(nHandle);
    if (it != cosmos_->m_mapWebRTNode.end()) {
      return it->value.Get();
    }
  }
  return nullptr;
}

CosmosNode* CosmosNode::root() {
  return rootNode_;
}

CosmosXobj* CosmosNode::parentGalaxy() {
  __int64 nHandle = getInt64("Galaxyhandle");
  auto it = cosmos_->m_mapWebRTGalaxy.find(nHandle);
  if (it != cosmos_->m_mapWebRTGalaxy.end()) {
    return (CosmosXobj*)it->value.Get();
  }
  return nullptr;
}

CosmosNode* CosmosNode::AddChild(int64_t nHandle,
                                 const String& strNodeName,
                                 blink::Cosmos* pWebRT) {
  CosmosNode* node = nullptr;
  auto it = pWebRT->m_mapWebRTNode.find(nHandle);
  if (it != pWebRT->m_mapWebRTNode.end()) {
    node = it->value;
    int nSize = (int)m_mapChildNode.size();
    m_mapChildNode.insert(nSize, node);
  }
  return node;
}

}  // namespace blink
