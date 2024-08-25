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

#include "stdafx.h"
#include "GridCLREvent.h"

using namespace System::Runtime::InteropServices;

CXobjCLREvent::CXobjCLREvent()
{
}


CXobjCLREvent::~CXobjCLREvent()
{
	//delete m_pXobj;
}

void CXobjCLREvent::OnObserveComplete(IXobj* pXobj)
{
	m_pXobj->Fire_ObserveComplete(m_pXobj);
}

void CXobjCLREvent::OnDocumentComplete(IDispatch* pDocdisp, BSTR bstrUrl)
{
	Object^ pObj = reinterpret_cast<Object^>(Marshal::GetObjectForIUnknown((System::IntPtr)(pDocdisp)));
	m_pXobj->Fire_OnDocumentComplete(m_pXobj, pObj, marshal_as<String^>(bstrUrl));
}

void CXobjCLREvent::OnDestroy()
{
	if (m_pXobj->m_pHostObj)
	{
		Universe::Xobj^ pXobj = nullptr;
		if (Universe::WebRT::m_pFrameworkElementDic->TryGetValue(m_pXobj->m_pHostObj, pXobj))
		{
			Universe::WebRT::m_pFrameworkElementDic->Remove(m_pXobj->m_pHostObj);
		}
	}
	m_pXobj->Fire_OnDestroy(m_pXobj);
}

void CXobjCLREvent::OnXobjAddInCreated(IDispatch* pAddIndisp, BSTR bstrAddInID, BSTR bstrAddInXml)
{
	Object^ pAddinObj = reinterpret_cast<Object^>(Marshal::GetObjectForIUnknown((System::IntPtr)(pAddIndisp)));
	m_pXobj->Fire_XobjAddInCreated(m_pXobj, pAddinObj, marshal_as<String^>(bstrAddInID), marshal_as<String^>(bstrAddInXml));
}

void CXobjCLREvent::OnXobjAddInsCreated()
{
	m_pXobj->Fire_XobjAddInsCreated(m_pXobj);
}

void CXobjCLREvent::OnTabChange(int nActivePage, int nOldPage)
{
	Universe::Xobj^ pActiveXobj = m_pXobj->GetXobj(0, nActivePage);
	Universe::Xobj^ pOldXobj = m_pXobj->GetXobj(0, nOldPage);
	m_pXobj->Fire_OnTabChange(pActiveXobj, pOldXobj);
}

void CXobjCLREvent::OnIPCMessageReceived(BSTR bstrFrom, BSTR bstrTo, BSTR bstrMsgId, BSTR bstrPayload, BSTR bstrExtra)
{
	m_pXobj->Fire_OnIPCMessageReceived(marshal_as<String^>(bstrFrom), marshal_as<String^>(bstrTo), marshal_as<String^>(bstrMsgId), marshal_as<String^>(bstrPayload), marshal_as<String^>(bstrExtra));
}
