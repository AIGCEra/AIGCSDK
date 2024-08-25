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

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TANGRAM_EVENT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TANGRAM_EVENT_H_

#include "third_party/blink/renderer/core/dom/events/Event.h"
#include "third_party/blink/renderer/core/dom/element.h"

namespace blink {

  class Element;
  class ScriptState;
  class CosmosXobj;
  class CosmosNode;
  class CosmosGalaxy;
  class CosmosWinform;

  class CORE_EXPORT CosmosEvent : public Event {
    DEFINE_WRAPPERTYPEINFO();

  public:
    static CosmosEvent* Create() { return MakeGarbageCollected<CosmosEvent>(); }
    
    static CosmosEvent* Create(const AtomicString& event_type, CosmosXobj* var);

    static CosmosEvent* Create(const AtomicString& event_type,
      const String& eventId,
      const String& param1,
      const String& param2,
      const String& param3,
      const String& param4,
      const String& param5,
      const int64_t handleSource,
      const int64_t handleTarget,
        CosmosXobj*);

    static CosmosEvent* Create(const AtomicString& event_type,
      const String& eventId,
      const String& param1,
      const int64_t handleSource,
      const String& param3,
      const int64_t handleTarget,
      const String& param5);

    String msgID();
    String eventId();
    void setEventId(const String&);
    String param1();
    void setParam1(const String&);
    String param2();
    void setParam2(const String&);
    String param3();
    void setParam3(const String&);
    String param4();
    void setParam4(const String&);
    String param5();
    void setParam5(const String&);
    CosmosXobj* xobj();
    void setXobj(CosmosXobj*);

    int64_t handleSource();
    void setHandleSource(const int64_t);
    int64_t handleTarget();
    void setHandleTarget(const int64_t);

    int64_t hwnd();
    String name();
    String objtype();
    CosmosNode* grid();
    CosmosWinform* form();
    CosmosGalaxy* galaxy();

    ~CosmosEvent() override;

    CosmosEvent();

    CosmosEvent(const AtomicString& event_type,
      const String& eventId,
      const String& param1,
      const String& param2,
      const String& param3,
      const String& param4,
      const String& param5,
      const int64_t handleSource,
      const int64_t handleTarget,
        CosmosXobj* session);

    void Trace(blink::Visitor*) const override;

  private:
    String eventId_;
    String param1_;
    String param2_;
    String param3_;
    String param4_;
    String param5_;
    int64_t handleSource_;
    int64_t handleTarget_;

    Member<CosmosXobj> session_;
  };

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_PROGRESS_EVENT_H_
