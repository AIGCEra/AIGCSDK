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

// TangramTreeView.cpp : Implementation of CTangramTreeView

#include "stdafx.h"
#include "TangramHtmlTreeWnd.h"
#include "TangramTreeView.h"


// CTangramTreeView
CTangramTreeView::CTangramTreeView()
{
	m_pWebRTHtmlTreeWnd = NULL;
}


STDMETHODIMP CTangramTreeView::put_TangramTreeViewCallBack(BSTR bstrKey, IWebRTTreeViewCallBack* newVal)
{
	CString strKey = OLE2T(bstrKey);
	strKey.Trim();
	strKey.MakeLower();
	auto it = m_mapWebRTTreeViewCallBack.find(strKey);
	if(it==m_mapWebRTTreeViewCallBack.end())
	{
		m_mapWebRTTreeViewCallBack[strKey] = newVal;
		newVal->AddRef();
	}

	return S_OK;
}

void CTangramTreeView::FinalRelease()
{
	for(auto it : m_mapWebRTTreeViewCallBack)
	{
		it.second->Release();
	}
	m_mapWebRTTreeViewCallBack.erase(m_mapWebRTTreeViewCallBack.begin(),m_mapWebRTTreeViewCallBack.end());
}

STDMETHODIMP CTangramTreeView::AddTreeNode(long hItem, BSTR bstrXml)
{
	if(m_pWebRTHtmlTreeWnd)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadXml(OLE2T(bstrXml)))
		{
			int nCount = 0;
			if((HTREEITEM)hItem)
			{
				HTREEITEM hChild = m_pWebRTHtmlTreeWnd->GetChildItem((HTREEITEM)hItem);
				CTangramXHtmlTreeNode *pXTCD = m_pWebRTHtmlTreeWnd->GetItemDataStruct((HTREEITEM)hChild);
				if(pXTCD->m_bWaitingFor)
					m_pWebRTHtmlTreeWnd->DeleteItem(hChild);
			}
				
			CTangramXHtmlTreeNode *pXTCD = m_pWebRTHtmlTreeWnd->GetItemDataStruct((HTREEITEM)hItem);
			if(pXTCD)
				pXTCD->m_strTangramXML = _T("");

			m_pWebRTHtmlTreeWnd->LoadXml(&m_Parse,(HTREEITEM)hItem,nCount);
			m_pWebRTHtmlTreeWnd->Expand((HTREEITEM)hItem,TVE_EXPAND);
		}
	}

	return S_OK;
}

STDMETHODIMP CTangramTreeView::InsertNode(BSTR bstrXml, long* hItem)
{
	if(m_pWebRTHtmlTreeWnd)
	{
		CTangramXmlParse m_Parse;
		if(m_Parse.LoadXml(OLE2T(bstrXml)))
		{
			int nCount = 0;
			HTREEITEM _hItem = m_pWebRTHtmlTreeWnd->InsertXmlItem(&m_Parse,0);
			* hItem = (long)_hItem;
		}
	}
	return S_OK;
}

STDMETHODIMP CTangramTreeView::get_FirstRoot(long* pVal)
{
	if(m_pWebRTHtmlTreeWnd&&m_pWebRTHtmlTreeWnd->m_hFirstRoot)
	{
		* pVal = (long)m_pWebRTHtmlTreeWnd->m_hFirstRoot;
	}

	return S_OK;
}
