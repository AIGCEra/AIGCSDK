/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
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
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

#pragma once


#include "Cosmos.h"
#include "universe.h"       // main symbols
#include "TangramBase.h"       // main symbols
using namespace System;
using namespace System::Reflection;
using namespace Universe;

class CXobjCLREvent
{
public:
	CXobjCLREvent();
	virtual ~CXobjCLREvent();

	gcroot<Universe::Xobj^>	m_pXobj;

	void OnDestroy();
	void OnXobjAddInsCreated();
	void OnObserveComplete(IXobj* pXobj);
	void OnDocumentComplete(IDispatch* pDocdisp, BSTR bstrUrl);
	void OnXobjAddInCreated(IDispatch* pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml);
	void OnTabChange(int nActivePage, int nOldPage);
	void OnIPCMessageReceived(BSTR bstrFrom, BSTR bstrTo, BSTR bstrMsgId, BSTR bstrPayload, BSTR bstrExtra);
};
