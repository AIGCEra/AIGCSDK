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

#include "cosmos_winform.h"
#include "cosmos.h"
#include "cosmos_compositor.h"
#include "cosmos_control.h"
#include "cosmos_event.h"
#include "cosmos_galaxy.h"
#include "cosmos_node.h"

#include "third_party/blink/public/web/blink.h"
#include "third_party/blink/renderer/bindings/core/v8/v8_application_callback.h"
#include "third_party/blink/renderer/core/dom/class_collection.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/dom/document_fragment.h"
#include "third_party/blink/renderer/core/dom/node.h"
#include "third_party/blink/renderer/core/dom/node_list.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"
#include "third_party/blink/renderer/core/xml/dom_parser.h"
#include "third_party/blink/renderer/platform/wtf/uuid.h"
#include "third_party/webruntime/ChromeRenderDomProxy.h"

namespace blink {

CosmosWinform::CosmosWinform() : CosmosXobj() {
  m_strAppContents = AtomicString("");
  m_pBindMdiNode = nullptr;
  m_pWebBindMdiNode = nullptr;
  m_pRenderframeImpl = nullptr;
  m_pContentElement = nullptr;
  m_pMDIParent = nullptr;
  m_pActiveMDIChild = nullptr;
}

CosmosWinform::CosmosWinform(const String& strNodeName) {
  name_ = "";
}

CosmosWinform::~CosmosWinform() {
  Cosmos* pWebRT = cosmos_.Get();
  if (pWebRT) {
    auto it = pWebRT->m_mapWebRTWinformforEvent.find(handle_);
    if (it != pWebRT->m_mapWebRTWinformforEvent.end()) {
      pWebRT->m_mapWebRTWinformforEvent.erase(it);
    }

    auto it2 = pWebRT->m_mapWinForm.find(handle_);
    if (it2 != pWebRT->m_mapWinForm.end()) {
      pWebRT->m_mapWinForm.erase(it2);
    }
  }
  mapWebRTEventCallback_.clear();
}

CosmosWinform* CosmosWinform::Create(const String& strFormXml) {
  return MakeGarbageCollected<CosmosWinform>(strFormXml);
}

void CosmosWinform::Trace(blink::Visitor* visitor) const {
  EventTarget::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  CosmosXobj::Trace(visitor);
  visitor->Trace(cosmos_);
  visitor->Trace(m_pBindMdiNode);
  visitor->Trace(m_pMDIParent);
  visitor->Trace(m_pActiveMDIChild);
  visitor->Trace(m_pContentElement);
  visitor->Trace(m_pWebBindMdiNode);
  visitor->Trace(m_mapWebRTGalaxy);
  visitor->Trace(m_mapControlBars);
  visitor->Trace(m_mapChildControl);
  visitor->Trace(m_mapChildControl2);
}

CosmosNode* CosmosWinform::mdibindgrid() {
  if (m_pBindMdiNode) {
    return m_pBindMdiNode;
  }
  return nullptr;
}

CosmosNode* CosmosWinform::mdiwebbindgrid() {
  if (m_nMdiwebbindgridhandle) {
    if (m_pWebBindMdiNode == nullptr) {
      Cosmos* pWebRT = cosmos_.Get();
      auto it1 = pWebRT->m_mapWebRTNode.find(m_nMdiwebbindgridhandle);
      if (it1 != pWebRT->m_mapWebRTNode.end()) {
        m_pWebBindMdiNode = it1->value.Get();
      }
    }
  }
  if (m_pWebBindMdiNode) {
    return m_pWebBindMdiNode;
  }
  return nullptr;
}

CosmosWinform* CosmosWinform::mdiParent() {
  if (m_pMDIParent == nullptr) {
    Cosmos* pWebRT = cosmos_.Get();
    int64_t nHandle = getInt64("mdiformhandle");
    if (nHandle && pWebRT) {
      pWebRT->m_mapWinForm.find(nHandle);
      auto it1 = pWebRT->m_mapWinForm.find(nHandle);
      if (it1 != pWebRT->m_mapWinForm.end()) {
        m_pMDIParent = it1->value;
        return it1->value.Get();
      }
    }
  }
  return m_pMDIParent.Get();
}

CosmosGalaxy* CosmosWinform::getGalaxy(const String& galaxyName) {
  auto it = m_mapWebRTGalaxy.find(galaxyName);
  if (it != m_mapWebRTGalaxy.end()) {
    return it->value.Get();
  }
  return nullptr;
}

CosmosNode* CosmosWinform::getXobj(const String& galaxyName,
                                   const String& clusterName,
                                   const String& gridName) {
  String clusterName_ = clusterName;
  if (clusterName == "undefined" || clusterName == "" ||
      clusterName.IsNull() == true) {
    clusterName_ = "default";
  }
  String gridName_ = gridName;
  if (gridName == "undefined" || gridName == "" || gridName.IsNull() == true) {
    gridName_ = "default";
  }
  auto it = m_mapWebRTGalaxy.find(galaxyName);
  if (it != m_mapWebRTGalaxy.end()) {
    clusterName_ = clusterName_ + "__" + gridName_;
    auto it2 = it->value->m_mapWebRTNode2.find(clusterName_);
    if (it2 != it->value->m_mapWebRTNode2.end()) {
      return it2->value.Get();
    }
  }
  return nullptr;
}

CosmosNode* CosmosWinform::getXobj(Element* elem) {
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
        winNucleus = AtomicString("default");
      }
      if (target.IsNull() == true || target == AtomicString("")) {
        auto it = m_mapWebRTGalaxy.find(galaxy);
        if (it != m_mapWebRTGalaxy.end()) {
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
        } else {
          return cosmos_->getXobj(elem, this);
        }
      }
    }
  }
  return nullptr;
}

long CosmosWinform::formType() {
  long nFormType = getLong("WinFormType");

  return nFormType;
}

bool CosmosWinform::isReady() {
  if (isReady_) {
    return true;
  }
  return false;
}

int64_t CosmosWinform::handle() {
  return getInt64("formhandle");
}

void CosmosWinform::DispatchXobjEvent(Element* e, const String& eventName) {
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
              AtomicString winNucleus =
                  elem->getAttribute(AtomicString("nucleus"));
              if (galaxy == AtomicString("")) {
                galaxy = AtomicString("default");
              }
              if (winNucleus == AtomicString("")) {
                winNucleus = AtomicString("default");
              }
              CosmosNode* xobjfortarget = getXobj(galaxy, winNucleus, target);
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

void CosmosWinform::InitWinForm() {
  String strMessageXml = getStr("formxml");
  if (strMessageXml.IsNull() == false && strMessageXml != "") {
    DocumentFragment_ = cosmos_->createDocumentFragment();
    if (DocumentFragment_) {
      ExceptionState exception_state(
          cosmos_->GetIsolate(), v8::ExceptionContext::kAttributeSet, "Element", "outerHTML");

      cosmos_->helperElem_->setInnerHTML(strMessageXml, exception_state);
      DocumentFragment_->appendChild(cosmos_->helperElem_->firstChild());

      if (DocumentFragment_->children()->length()) {
        hostElem_ = DocumentFragment_->children()->item(0);
        m_strAppContents = hostElem_->getAttribute(AtomicString("formdiv"));
        HTMLCollection* list_ = hostElem_->children();
        for (unsigned int i = 0; i < list_->length(); i++) {
          Element* elem = list_->item(i);
          Node* pNode = elem;
          if (pNode->getNodeType() == 1) {
            String name = elem->tagName().LowerASCII();
            if (name == "messagemap" && messageElem_ == nullptr) {
              messageElem_ = elem;
            } else if (name == "referencemap" && refElem_ == nullptr) {
              refElem_ = elem;
              HTMLCollection* list2 = elem->children();
              unsigned int nlength = list2->length();
              if (nlength) {
                bool breferenced = false;
                for (unsigned int j = 0; j < nlength; j++) {
                  Element* e = list2->item(j);
                  Node* pNode2 = e;
                  if (pNode2->getNodeType() == 1) {
                    CosmosNode* grid = getXobj(e);
                    if (grid) {
                      breferenced = true;
                      e->setAttribute(
                          AtomicString("handle"),
                          grid->hostElem_->getAttribute(AtomicString("name")));
                    }
                  }
                }
                if (breferenced) {
                  setStr("msgID", "SET_REFGRIDS_IPC_MSG");
                  setStr("RefInfo", refElem_->outerHTML());
                  m_pRenderframeImpl->SendCosmosMessageEx(session_);
                }
              }
            } else if (name == "eventmap" && eventElem_ == nullptr) {
              eventElem_ = elem;

              HTMLCollection* list = eventElem_->children();
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
                    auto it = m_mapElement.find(strIndex);
                    if (it == m_mapElement.end()) {
                      setStr("msgID", "BIND_NATIVEOBJ_IPC_MSG");
                      setStr("BindObj", name2);
                      setStr("Bindevent", eventname);
                      m_mapElement.insert(strIndex, elemEvent);
                      m_pRenderframeImpl->SendCosmosMessageEx(session_);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  setStr("formxml", "");
}

CosmosWinform* CosmosWinform::activeMDIChild() {
  if (m_pActiveMDIChild) {
    return m_pActiveMDIChild.Get();
  }
  return nullptr;
}

void CosmosWinform::Observe(const String& strCtrlName,
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

void CosmosWinform::Observe(const String& strCtrlName,
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
    m_pRenderframeImpl->m_mapWebRTSession[Cosmos::S2w(callbackid_)] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
    setStr("msgID", "");
  }
}

void CosmosWinform::Observe(const String& strCtrlName,
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

void CosmosWinform::Observe(const String& strCtrlName,
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
    m_pRenderframeImpl->m_mapWebRTSession[Cosmos::S2w(callbackid_)] = this;
    if (callback) {
      mapWebRTEventCallback_.insert(callbackid_, callback);
    }
    m_pRenderframeImpl->SendCosmosMessageEx(session_);
    setStr("msgID", "");
  }
}

void CosmosWinform::ProcessFormMessage(const String& msgID) {
  if (messageElem_ && msgID.IsNull() == false && msgID != "") {
    CosmosNode* xobjfortarget = nullptr;
    HTMLCollection* list =
        messageElem_->getElementsByTagName(AtomicString(msgID.LowerASCII()));
    for (unsigned int i = 0; i < list->length(); i++) {
      HTMLCollection* plist = list->item(i)->children();
      for (unsigned int j = 0; j < plist->length(); j++) {
        Element* elem = plist->item(j);
        AtomicString target = AtomicString("");
        target = elem->getAttribute(AtomicString("target"));
        if (target.IsNull() || target == AtomicString("")) {
        } else {
          AtomicString galaxy = elem->getAttribute(AtomicString("galaxy"));
          AtomicString winNucleus = elem->getAttribute(AtomicString("nucleus"));
          if (galaxy == AtomicString("")) {
            galaxy = AtomicString("default");
          }
          if (winNucleus == AtomicString("")) {
            winNucleus = AtomicString("default");
          }

          xobjfortarget = cosmos_->getXobj(galaxy, winNucleus, target);
          if (xobjfortarget == nullptr) {
            xobjfortarget = getXobj(galaxy, winNucleus, target);
          }
          if (xobjfortarget == nullptr) {
            CosmosWinform* Parentform = mdiParent();
            if (Parentform) {
              xobjfortarget = Parentform->getXobj(galaxy, winNucleus, target);
            }
          }
          if (xobjfortarget == nullptr) {
            long nFormType = getLong("WinFormType");
            if (nFormType == 2) {
              CosmosWinform* childform = activeMDIChild();
              if (childform) {
                xobjfortarget = childform->getXobj(galaxy, winNucleus, target);
              }
            }
          }
        }
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
}
}  // namespace blink
