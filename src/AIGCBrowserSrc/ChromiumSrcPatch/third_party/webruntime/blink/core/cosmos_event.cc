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

#include "cosmos_event.h"
#include "cosmos_node.h"
#include "cosmos_winform.h"
#include "cosmos_xobj.h"

namespace blink {

CosmosEvent* CosmosEvent::Create(const AtomicString& event_type,
                                 const String& eventId,
                                 const String& param1,
                                 const String& param2,
                                 const String& param3,
                                 const String& param4,
                                 const String& param5,
                                 const int64_t handleSource,
                                 const int64_t handleTarget,
                                 CosmosXobj* session) {
  return MakeGarbageCollected<CosmosEvent>(event_type, eventId, param1, param2,
                                           param3, param4, param5, handleSource,
                                           handleTarget, session);
}

CosmosEvent* CosmosEvent::Create(const AtomicString& event_type,
                                 const String& eventId,
                                 const String& param1,
                                 const int64_t handleSource,
                                 const String& param3,
                                 const int64_t handleTarget,
                                 const String& param5) {
  return MakeGarbageCollected<CosmosEvent>(event_type, eventId, param1, "",
                                           param3, "", param5, handleSource,
                                           handleTarget, nullptr);
}

CosmosEvent* CosmosEvent::Create(const AtomicString& event_type,
                                 CosmosXobj* session) {
  return MakeGarbageCollected<CosmosEvent>(event_type, "", "", "", "", "", "",
                                           0, 0, session);
}

void CosmosEvent::Trace(blink::Visitor* visitor) const {
  Event::Trace(visitor);
  visitor->Trace(session_);
}

CosmosXobj* CosmosEvent::xobj() {
  return session_;
}

void CosmosEvent::setXobj(CosmosXobj* session) {
  session_ = session;
}

String CosmosEvent::msgID() {
  return session_->getStr("msgID");
}

String CosmosEvent::eventId() {
  return eventId_;
}

int64_t CosmosEvent::handleSource() {
  return handleSource_;
}

void CosmosEvent::setHandleSource(const int64_t handleSource) {
  handleSource_ = handleSource;
}

int64_t CosmosEvent::handleTarget() {
  return handleTarget_;
}

void CosmosEvent::setHandleTarget(const int64_t handleTarget) {
  handleTarget_ = handleTarget;
}

void CosmosEvent::setEventId(const String& eventId) {
  eventId_ = eventId;
}

String CosmosEvent::param1() {
  return param1_;
}

void CosmosEvent::setParam1(const String& param1) {
  param1_ = param1;
}

String CosmosEvent::param2() {
  return param2_;
}

void CosmosEvent::setParam2(const String& param2) {
  param2_ = param2;
}

String CosmosEvent::param3() {
  return param3_;
}

void CosmosEvent::setParam3(const String& param3) {
  param3_ = param3;
}

String CosmosEvent::param4() {
  return param4_;
}

void CosmosEvent::setParam4(const String& param4) {
  param4_ = param4;
}

String CosmosEvent::param5() {
  return param5_;
}

void CosmosEvent::setParam5(const String& param5) {
  param5_ = param5;
}

int64_t CosmosEvent::hwnd() {
  int64_t h = session_->getInt64("xobjhandle");
  if (h == 0)
    h = session_->getInt64("formhandle");
  if (h == 0)
    h = session_->getInt64("hwnd");
  if (h == 0)
    h = session_->getInt64("hWnd");
  return h;
}

String CosmosEvent::name() {
  return session_->name();
}

String CosmosEvent::objtype() {
  return session_->getStr("objtype");
}

CosmosWinform* CosmosEvent::form() {
  if (session_)
    return (CosmosWinform*)session_->form();
  return nullptr;
}

CosmosNode* CosmosEvent::grid() {
  if (session_)
    return (CosmosNode*)session_->grid();
  return nullptr;
}

CosmosGalaxy* CosmosEvent::galaxy() {
  if (session_) {
    CosmosNode* node = (CosmosNode*)session_->grid();
    if (node) {
      return (CosmosGalaxy*)node->parentGalaxy();
    }
  }
  return nullptr;
}

CosmosEvent::CosmosEvent() = default;

CosmosEvent::CosmosEvent(const AtomicString& event_type,
                         const String& eventId,
                         const String& param1,
                         const String& param2,
                         const String& param3,
                         const String& param4,
                         const String& param5,
                         const int64_t handleSource,
                         const int64_t handleTarget,
                         CosmosXobj* session)
    : Event(event_type, Bubbles::kNo, Cancelable::kNo) {
  eventId_ = eventId;
  param1_ = param1;
  param2_ = param2;
  param3_ = param3;
  param4_ = param4;
  param5_ = param5;
  handleSource_ = handleSource;
  handleTarget_ = handleTarget;
  session_ = session;
}

CosmosEvent::~CosmosEvent() = default;

}  // namespace blink
