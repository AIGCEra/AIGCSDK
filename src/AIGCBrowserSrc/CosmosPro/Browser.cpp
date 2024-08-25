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
 
 /********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser;
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
#include "dllmain.h"
#include "Cosmos.h"
#include "CosmosProxy.h"
#include "Browser.h"

using namespace std;
using namespace System;
using namespace System::Windows;
using namespace System::Reflection;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Threading::Tasks;

using System::Runtime::InteropServices::Marshal;

namespace Universe
{
	Wormhole::Wormhole(CSession* pWebRTSession)
	{
		m_pWebRTSession = pWebRTSession;
	}

	void Wormhole::InsertString(String^ key, String^ value)
	{
		if(m_pWebRTSession)
			m_pWebRTSession->InsertString(key, value);
	}

	void Wormhole::InsertLong(String^ key, long value)
	{
		if(m_pWebRTSession)
			m_pWebRTSession->InsertLong(key, value);
	}

	void Wormhole::InsertInt64(String^ key, __int64 value)
	{
		if(m_pWebRTSession)
			m_pWebRTSession->Insertint64(key, value);
	}

	void Wormhole::InsertFloat(String^ key, float value)
	{
		if(m_pWebRTSession)
			m_pWebRTSession->InsertFloat(key, value);
	}

	String^ Wormhole::GetString(String^ key)
	{
		if(m_pWebRTSession)
			return marshal_as<String^>(m_pWebRTSession->GetString(key));
		return L"";
	}

	long Wormhole::GetLong(String^ key)
	{
		if(m_pWebRTSession)
			return m_pWebRTSession->GetLong(key);
		return 0;
	}

	__int64 Wormhole::GetInt64(String^ key)
	{
		if(m_pWebRTSession)
			return m_pWebRTSession->Getint64(key);
		return 0;
	}

	float Wormhole::GetFloat(String^ key)
	{
		if(m_pWebRTSession)
			return m_pWebRTSession->GetFloat(key);
		return 0;
	}

	void Wormhole::SendMessage()
	{
		if (m_pWebRTSession)
			return m_pWebRTSession->SendMessage();
	}

	bool Wormhole::isBindCLRObjToWebPage(Object^ obj, String^ eventName)
	{
		if (obj->GetType()->IsSubclassOf(Control::typeid))
		{
			Control^ ctrl = (Control^)obj;
			String^ strInfo = L"@" + ctrl->Handle.ToString() + eventName->ToLower() + L"@";
			//String^ strInfo = L"@" + ctrl->Name->ToLower() + L"@";
			if (m_strEvents->IndexOf(strInfo) != -1)
			{
				return true;
			}
		}
		return false;
	}

	void Wormhole::AddEventInfo(Object^ obj, String^ eventName)
	{
		if (obj->GetType()->IsSubclassOf(Control::typeid))
		{
			Control^ ctrl = (Control^)obj;
			String^ strInfo = L"@" + ctrl->Handle.ToString() + eventName->ToLower() + L"@";
			//String^ strInfo = L"@" + ctrl->Name->ToLower() + L"@";
			if (m_strEvents->IndexOf(strInfo) == -1)
			{
				m_strEvents += strInfo;
			}
		}
	}

	Browser::Browser(IBrowser* pBrowser)
	{
		m_pWebBrowser = pBrowser;
	}

	void Browser::AddURLs(String^ urls)
	{
		if (m_pWebBrowser)
		{
			m_pWebBrowser->OpenURL(marshal_as<CComBSTR>(urls), BrowserWndOpenDisposition::NEW_FOREGROUND_TAB, CComBSTR(""), CComBSTR(""));
		}
	}

	void Browser::OpenURL(String^ url, Disposition disposition, String^ key, String^ xml)
	{
		CComBSTR bstrUrl = marshal_as<CComBSTR>(url);
		CComBSTR bstrKey = marshal_as<CComBSTR>(key);
		CComBSTR bstrXml = marshal_as<CComBSTR>(xml);
		if (m_pWebBrowser)
		{
			m_pWebBrowser->OpenURL(bstrUrl, (BrowserWndOpenDisposition)disposition, bstrKey, bstrXml);
		}
	}

	WebView::WebView(IWebView* pWebView)
	{
		m_pWebView = pWebView;
	}
	
	IntPtr WebView::Handle::get()
	{
		return (IntPtr)m_hWnd;
	}
	
	Browser^ WebView::Browser::get()
	{
		if (m_pWebView) {
			IBrowser* pBrowser = nullptr;
			m_pWebView->get_WebBrowser(&pBrowser);
			if (pBrowser)
			{
				auto it = theAppProxy.m_mapWebBrowser.find(pBrowser);
				if (it != theAppProxy.m_mapWebBrowser.end())
					return it->second;
			}
		}
		return nullptr;
	}
	
	Xobj^ WebView::ParentXobj::get()
	{
		return theAppProxy._createObject<IXobj, Xobj>(m_pProxy->GetParentXobj());
	}
	
	WinNucleus^ WebView::HostGalaxy::get()
	{
		return theAppProxy._createObject<INucleus, WinNucleus>(m_pProxy->GetNucleus());
	}

	Form^ WebView::CreateForm(String^ strFormKey)
	{
		if (m_pWebView)
		{
			IDispatch* pFormDisp = nullptr;
			pFormDisp = g_pSpaceTelescopeImpl->m_pCLRProxy->CreateWinForm(m_hWnd, marshal_as<CComBSTR>(strFormKey));
			return (Form^)Marshal::GetObjectForIUnknown((IntPtr)pFormDisp);
		}
		return nullptr;
	}
}