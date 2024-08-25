/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
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
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

 // Nuclei.cpp : Implementation of CNuclei

#include "stdafx.h"
#include "Xobj.h"
#include "WinNucleus.h"
#include "UniverseApp.h"
#include "Cosmos.h"

CXobjShareData::CXobjShareData()
{
	m_pOldGalaxy = nullptr;
	m_pOfficeObj = nullptr;
	m_pWebRTParse = nullptr;
	m_pHostClientView = nullptr;
#ifdef _DEBUG
	g_pSpaceTelescope->m_nTangramNodeCommonData++;
#endif	
};

CXobjShareData::~CXobjShareData()
{
	if (m_pWebRTParse)
		delete m_pWebRTParse;
#ifdef _DEBUG
	g_pSpaceTelescope->m_nTangramNodeCommonData--;
#endif	
};

// CNuclei
CNuclei::CNuclei()
{
	m_hWnd = 0;
	m_bPageDataLoaded = false;
	m_bDoc = false;
	m_strXmlHeader = _T("");
	m_strPageFileName = _T("");
	m_strPageFilePath = _T("");
	m_strConfigFileNodeName = _T("tangramdefaultpage");
	m_pBKGalaxy = nullptr;
	m_pParentWinFormWnd = nullptr;
	m_pUniverseAppProxy = nullptr;
	g_pSpaceTelescope->m_pNuclei = this;

#ifdef _DEBUG
	g_pSpaceTelescope->m_nTangram++;
#endif	
}

CNuclei::~CNuclei()
{
#ifdef _DEBUG
	g_pSpaceTelescope->m_nTangram--;
#endif	
	//if(g_pSpaceTelescope->m_nTangram==0)
	//	return;

	m_mapGalaxy.erase(m_mapGalaxy.begin(), m_mapGalaxy.end());
	m_mapXobj.erase(m_mapXobj.begin(), m_mapXobj.end());
	auto it = g_pSpaceTelescope->m_mapNuclei.find(m_hWnd);
	if (it != g_pSpaceTelescope->m_mapNuclei.end())
	{
		g_pSpaceTelescope->m_mapNuclei.erase(it);
	}
	if (g_pSpaceTelescope->m_mapNuclei.size() == 0)
		g_pSpaceTelescope->Close();

	for (auto& it : m_mapNucleiProxy)
	{
		if (it.second->m_bAutoDelete)
			delete it.second;
	}
	m_mapNucleiProxy.clear();
	if (m_mapEventObj.size())
	{
		for (auto& it : m_mapEventObj)
			delete it.second;
		m_mapEventObj.clear();
	}
	if (m_strMapKey.size())
		m_strMapKey.erase(m_strMapKey.begin(), m_strMapKey.end());
}

STDMETHODIMP CNuclei::get_Count(long* pCount)
{
	*pCount = (long)m_mapGalaxy.size();
	return S_OK;
}

STDMETHODIMP CNuclei::get_WinNucleus(VARIANT vIndex, INucleus** ppNucleus)
{
	if (vIndex.vt == VT_I4)
	{
		long lCount = m_mapGalaxy.size();
		int iIndex = vIndex.lVal;
		HWND hWnd = (HWND)iIndex;
		if (::IsWindow(hWnd))
		{
			auto it = m_mapGalaxy.find(hWnd);
			if (it != m_mapGalaxy.end())
			{
				*ppNucleus = it->second;
				return S_OK;
			}
		}
		if (iIndex < 0 || iIndex >= lCount) return E_INVALIDARG;

		auto it = m_mapGalaxy.begin();
		int iPos = 0;
		while (it != m_mapGalaxy.end())
		{
			if (iPos == iIndex)
			{
				*ppNucleus = it->second;
				return S_OK;
			};
			iPos++;
			it++;
		}
		return S_OK;
	}

	if (vIndex.vt == VT_BSTR)
	{
		CString strKey = OLE2T(vIndex.bstrVal);
		auto it = m_mapWnd.find(strKey);
		if (it != m_mapWnd.end())
		{
			auto it2 = m_mapGalaxy.find(it->second);
			if (it2 != m_mapGalaxy.end())
			{
				*ppNucleus = it2->second;
				return S_OK;
			}
		}
		return E_INVALIDARG;
	}

	return S_OK;
}

STDMETHODIMP CNuclei::get__NewEnum(IUnknown** ppVal)
{
	typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT>>
		CComEnumVariant;

	CComObject<CComEnumVariant>* pe = 0;
	HRESULT hr = pe->CreateInstance(&pe);

	if (SUCCEEDED(hr))
	{
		pe->AddRef();
		long nLen = (long)m_mapGalaxy.size();
		VARIANT* rgvar = new VARIANT[nLen];
		ZeroMemory(rgvar, sizeof(VARIANT) * nLen);
		VARIANT* pItem = rgvar;
		for (auto& it : m_mapGalaxy)
		{
			IUnknown* pDisp = nullptr;
			CNucleus* pObj = it.second;
			hr = pObj->QueryInterface(IID_IUnknown, (void**)&pDisp);
			pItem->vt = VT_UNKNOWN;
			pItem->punkVal = pDisp;
			if (pItem->punkVal != nullptr)
				pItem->punkVal->AddRef();
			pItem++;
			pDisp->Release();
		}

		hr = pe->Init(rgvar, &rgvar[nLen], 0, AtlFlagTakeOwnership);
		if (SUCCEEDED(hr))
			hr = pe->QueryInterface(IID_IUnknown, (void**)ppVal);
		pe->Release();
	}
	return S_OK;
}

STDMETHODIMP CNuclei::CreateNucleus(VARIANT ParentObj, VARIANT HostWnd, BSTR bstrNucleusName, INucleus** pRetFrame)
{
	HWND h = 0;
	CString strNucleusName = OLE2T(bstrNucleusName);
	BSTR bstrName = strNucleusName.MakeLower().AllocSysString();
	if (ParentObj.vt == VT_DISPATCH && HostWnd.vt == VT_BSTR)
	{
		if (g_pSpaceTelescope->m_pCLRProxy)
		{
			IDispatch* pDisp = nullptr;
			pDisp = g_pSpaceTelescope->m_pCLRProxy->GetCtrlByName(ParentObj.pdispVal, HostWnd.bstrVal, true);
			if (pDisp)
			{
				h = g_pSpaceTelescope->m_pCLRProxy->GetCtrlHandle(pDisp);
				if (h)
				{
					HRESULT hr = CreateNucleus(CComVariant(0), CComVariant((long)h), bstrName, pRetFrame);
					::SysFreeString(bstrName);
					return hr;
				}
			}
		}
		::SysFreeString(bstrName);
		return S_FALSE;
	}
	if (HostWnd.vt == VT_DISPATCH)
	{
		if (g_pSpaceTelescope->m_pCLRProxy)
		{
			h = g_pSpaceTelescope->m_pCLRProxy->IsNucleus(HostWnd.pdispVal);
			if (h)
			{
				CString strName = strNucleusName;
				if (strName == _T(""))
				{
					::SysFreeString(bstrName);
					bstrNucleusName = g_pSpaceTelescope->m_pCLRProxy->GetCtrlName(HostWnd.pdispVal);
					strName = OLE2T(bstrNucleusName);
					if (strName == _T(""))
						bstrNucleusName = CComBSTR(L"Default");

					strNucleusName = OLE2T(bstrNucleusName);
					auto it = m_mapWnd.find(strNucleusName);
					if (it != m_mapWnd.end())
					{
						int i = 0;
						CString s = _T("");
						s.Format(_T("%s%d"), strNucleusName, i);
						auto it = m_mapWnd.find(s);
						while (it != m_mapWnd.end())
						{
							i++;
							s.Format(_T("%s%d"), strNucleusName, i);
							it = m_mapWnd.find(s);
							if (it == m_mapWnd.end())
								break;
						}
						strNucleusName = s;
					}

				}
				auto it = m_mapGalaxy.find((HWND)h);
				if (it == m_mapGalaxy.end())
					return CreateNucleus(CComVariant(0), CComVariant((long)h), CComBSTR(strNucleusName.MakeLower()), pRetFrame);
				else
					*pRetFrame = it->second;
			}
		}
	}
	else if (HostWnd.vt == VT_I2 || HostWnd.vt == VT_I4 || HostWnd.vt == VT_I8)
	{
		BOOL bIsMDI = FALSE;
		HWND _hWnd = NULL;
		if (HostWnd.vt == VT_I4)
			_hWnd = (HWND)HostWnd.lVal;
		if (HostWnd.vt == VT_I8)
			_hWnd = (HWND)HostWnd.llVal;
		if (_hWnd == 0)
		{
			_hWnd = ::FindWindowEx(m_hWnd, NULL, _T("MDIClient"), NULL);
			if (_hWnd == NULL)
				_hWnd = ::GetWindow(m_hWnd, GW_CHILD);
			else
				bIsMDI = TRUE;
		}
		if (_hWnd && ::IsWindow(_hWnd))
		{
			auto it = m_mapGalaxy.find(_hWnd);
			if (it == m_mapGalaxy.end())
			{
				HWND hPWnd = ::GetParent(_hWnd);
				DWORD dwID = ::GetWindowThreadProcessId(_hWnd, NULL);
				CommonThreadInfo* pThreadInfo = g_pSpaceTelescope->GetThreadInfo(dwID);

				CNucleus* _pGalaxy = new CComObject<CNucleus>();
				CString strName = strNucleusName;
				if (strName == _T(""))
					strName = _T("default");
				strName.MakeLower();
				_pGalaxy->m_strNucleusName = strName;
				if (strName.CompareNoCase(_T("System.Windows.Forms.MdiClient")) == 0)
				{
					_pGalaxy->m_nGalaxyType = WinFormMDIClientGalaxy;
					_pGalaxy->m_strDocTemplateID = _T("System.Windows.Forms.MdiClient");
				}
				else if (bIsMDI)
				{
					_pGalaxy->m_nGalaxyType = MDIClientGalaxy;
					_pGalaxy->m_strDocTemplateID = _T("MDIClient");
				}
				::GetClassName(hPWnd, g_pSpaceTelescope->m_szBuffer, MAX_PATH);
				CString strClassName = g_pSpaceTelescope->m_szBuffer;
				if (strClassName.Find(_T("Afx:ControlBar:")) == 0)
				{
					_pGalaxy->m_nGalaxyType = CtrlBarGalaxy;
					_pGalaxy->m_strDocTemplateID = _T("ControlBar");
					CWnd* pWnd = CWnd::FromHandlePermanent(hPWnd);
					if (pWnd == nullptr)
					{
						CWebRTWnd* _pWnd = new CWebRTWnd();
						_pWnd->SubclassWindow(hPWnd);
						//_pWnd->ModifyStyle(0, WS_CLIPCHILDREN|WS_CLIPSIBLINGS);
						_pWnd->m_hClient = _hWnd;
					}
				}
				else if (strClassName.Find(_T("Chrome Extended Window Class")) == 0)
				{
					_pGalaxy->m_nGalaxyType = GalaxyType::WebPageGalaxy;
					_pGalaxy->m_strDocTemplateID = _T("WebPage");
					HWND _hPWnd = ::GetParent(hPWnd);
					auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(_hPWnd);
					if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
					{
						CBrowser* pBrowser = (CBrowser*)it->second;
						if (pBrowser->m_pParentXobj)
							_pGalaxy->m_pWebRTFrameWndInfo = pBrowser->m_pParentXobj->m_pXobjShareData->m_pNucleus->m_pWebRTFrameWndInfo;
					}
				}
				else if (strClassName.Find(_T("MDIClient")) == 0)
				{
					_pGalaxy->m_nGalaxyType = MDIClientGalaxy;
					_pGalaxy->m_strDocTemplateID = _T("MDIClient");
				}
				CCloudMDIFrame* pMDIParent = nullptr;
				HWND hTopParent = ::GetAncestor(hPWnd, GA_ROOT);
				auto it2 = g_pSpaceTelescope->m_mapMDIParent.find(hTopParent);
				if (it2 != g_pSpaceTelescope->m_mapMDIParent.end())
				{
					pMDIParent = it2->second;
					if (!::IsChild(pMDIParent->m_hMDIClient, _hWnd))
					{
						_pGalaxy->m_pMDIParent = pMDIParent;
						_pGalaxy->m_pWebRTFrameWndInfo = pMDIParent->m_pWebRTFrameWndInfo;
					}
					if (pMDIParent->m_hMDIClient == _hWnd)
					{
						_pGalaxy->m_pWebRTFrameWndInfo = pMDIParent->m_pWebRTFrameWndInfo;
						pMDIParent->m_pMDINucleus = _pGalaxy;
					}
				}
				else if (g_pSpaceTelescope->m_pCLRProxy)
				{
					__int64 nMDIClient = 100;
					HWND hForm = g_pSpaceTelescope->m_pCLRProxy->GetWinForm(_hWnd, nMDIClient);
					if (::IsWindow(hForm))
					{
						CCloudWinForm* pForm = (CCloudWinForm*)::SendMessage(hForm, WM_HUBBLE_DATA, 0, 20190214);
						if (pForm)
						{
							_pGalaxy->m_pParentWinForm = pForm;
							if (nMDIClient >= 1)
							{
								if (nMDIClient == 1)
								{
									_pGalaxy->m_pParentMDIWinForm = _pGalaxy->m_pParentWinForm;
									pForm->m_bMdiForm = true;
									pForm->m_hMDIClient = _hWnd;
								}
								else
								{
									_pGalaxy->m_pParentMDIWinForm = (CCloudWinForm*)::SendMessage(hTopParent, WM_HUBBLE_DATA, 0, 20190214);
									if (::IsWindow((HWND)nMDIClient))
										_pGalaxy->m_pParentMDIWinForm->m_hMDIClient = (HWND)nMDIClient;
								}
							}
							else if (pForm->m_bMdiForm)
								_pGalaxy->m_pParentMDIWinForm = _pGalaxy->m_pParentWinForm;
							else
								_pGalaxy->m_pParentMDIWinForm = nullptr;;
						}
					}
				}
				_pGalaxy->m_pNuclei = this;
				_pGalaxy->m_hHostWnd = _hWnd;
				pThreadInfo->m_mapGalaxy[_hWnd] = _pGalaxy;
				m_mapGalaxy[_hWnd] = _pGalaxy;
				m_mapWnd[strName] = _hWnd;

				for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
				{
					CNucleusProxy* pGalaxyProxy = it.second->OnNucleusCreated(_pGalaxy);
					if (pGalaxyProxy)
					{
						_pGalaxy->m_mapGalaxyProxy[it.second] = pGalaxyProxy;
					}
				}

				*pRetFrame = _pGalaxy;
			}
			else
				*pRetFrame = it->second;
		}
	}

	return S_OK;
}

STDMETHODIMP CNuclei::GetNucleusFromCtrl(IDispatch* CtrlObj, INucleus** ppNucleus)
{
	if (g_pSpaceTelescope->m_pCLRProxy)
	{
		HWND h = g_pSpaceTelescope->m_pCLRProxy->IsNucleus(CtrlObj);
		if (h)
		{
			auto it = m_mapGalaxy.find(h);
			if (it != m_mapGalaxy.end())
				*ppNucleus = it->second;
		}
	}

	return S_OK;
}

STDMETHODIMP CNuclei::GetXobj(BSTR bstrNucleusName, BSTR bstrNodeName, IXobj** pRetNode)
{
	CString strKey = OLE2T(bstrNucleusName);
	CString strName = OLE2T(bstrNodeName);
	if (strKey == _T("") || strName == _T(""))
		return S_FALSE;
	auto it = m_mapWnd.find(strKey);
	if (it != m_mapWnd.end())
	{
		HWND hWnd = it->second;
		if (::IsWindow(hWnd))
		{
			auto it = m_mapGalaxy.find(hWnd);
			if (it != m_mapGalaxy.end())
			{
				CNucleus* pGalaxy = it->second;
				strName = strName.MakeLower();
				auto it2 = pGalaxy->m_mapXobj.find(strName);
				if (it2 != pGalaxy->m_mapXobj.end())
					*pRetNode = (IXobj*)it2->second;
				else
				{
					it2 = m_mapXobj.find(strName);
					if (it2 != m_mapXobj.end())
						*pRetNode = (IXobj*)it2->second;
				}
			}
		}
	}

	return S_OK;
}

STDMETHODIMP CNuclei::get_NucleusName(LONGLONG hHwnd, BSTR* pVal)
{
	HWND _hWnd = (HWND)hHwnd;
	if (_hWnd)
	{
		auto it = m_mapGalaxy.find(_hWnd);
		if (it != m_mapGalaxy.end())
			*pVal = it->second->m_strNucleusName.AllocSysString();
	}

	return S_OK;
}

void CNuclei::BeforeDestory()
{
	Fire_Destroy();

	for (auto& it : m_mapGalaxy)
		it.second->Destroy();

	if (g_pSpaceTelescope->m_pCLRProxy)
	{
		g_pSpaceTelescope->m_pCLRProxy->ReleaseCosmosObj((INuclei*)this);
	}
}

STDMETHODIMP CNuclei::get_Xobj(BSTR bstrNodeName, IXobj** pVal)
{
	CString strName = OLE2T(bstrNodeName);
	if (strName == _T(""))
		return S_OK;
	auto it2 = m_mapXobj.find(strName);
	if (it2 == m_mapXobj.end())
		return S_OK;

	if (it2->second)
		*pVal = it2->second;

	return S_OK;
}

STDMETHODIMP CNuclei::get_XObject(BSTR bstrName, IDispatch** pVal)
{
	CString strName = OLE2T(bstrName);
	if (strName == _T(""))
		return S_OK;
	auto it2 = m_mapXobj.find(strName);
	if (it2 == m_mapXobj.end())
		return S_OK;
	if (it2->second->m_pDisp)
	{
		*pVal = it2->second->m_pDisp;
		(*pVal)->AddRef();
	}
	return S_OK;
}

STDMETHODIMP CNuclei::get_Width(long* pVal)
{
	if (m_hWnd)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		*pVal = rc.right - rc.left;
	}

	return S_OK;
}

STDMETHODIMP CNuclei::put_Width(long newVal)
{
	if (m_hWnd && newVal)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		rc.right = rc.left + newVal;
		::SetWindowPos(m_hWnd, NULL, rc.left, rc.top, newVal, rc.bottom - rc.top, SWP_NOACTIVATE | SWP_NOREDRAW);
	}

	return S_OK;
}

STDMETHODIMP CNuclei::get_Height(long* pVal)
{
	if (m_hWnd)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		*pVal = rc.bottom - rc.top;
	}
	return S_OK;
}

STDMETHODIMP CNuclei::put_Height(long newVal)
{
	if (m_hWnd && newVal)
	{
		RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		rc.right = rc.left + newVal;
		::SetWindowPos(m_hWnd, NULL, rc.left, rc.top, rc.right - rc.left, newVal, SWP_NOACTIVATE | SWP_NOREDRAW);
	}
	return S_OK;
}

STDMETHODIMP CNuclei::get_XobjNames(BSTR* pVal)
{
	CString strNames = _T("");
	for (auto& it : m_mapXobj)
	{
		strNames += it.first;
		strNames += _T(",");
	}
	int nPos = strNames.ReverseFind(',');
	strNames = strNames.Left(nPos);
	*pVal = strNames.AllocSysString();
	return S_OK;
}

STDMETHODIMP CNuclei::get_Parent(INuclei** pVal)
{
	HWND hWnd = ::GetParent(m_hWnd);
	if (hWnd == NULL)
		return S_OK;

	auto it = g_pSpaceTelescope->m_mapNuclei.find(hWnd);
	while (it == g_pSpaceTelescope->m_mapNuclei.end())
	{
		hWnd = ::GetParent(hWnd);
		if (hWnd == NULL)
			return S_OK;
		it = g_pSpaceTelescope->m_mapNuclei.find(hWnd);
		if (it != g_pSpaceTelescope->m_mapNuclei.end())
		{
			*pVal = it->second;
			return S_OK;
		}
	}
	return S_OK;
}

STDMETHODIMP CNuclei::get_Handle(LONGLONG* pVal)
{
	if (m_hWnd)
		*pVal = (LONGLONG)m_hWnd;
	return S_OK;
}

STDMETHODIMP CNuclei::GetCtrlInXobj(BSTR NodeName, BSTR CtrlName, IDispatch** ppCtrl)
{
	CString strName = OLE2T(NodeName);
	if (strName == _T(""))
		return S_OK;
	auto it2 = m_mapXobj.find(strName);
	if (it2 == m_mapXobj.end())
		return S_OK;

	CXobj* pXobj = it2->second;
	if (pXobj)
		pXobj->GetCtrlByName(CtrlName, true, ppCtrl);

	return S_OK;
}

STDMETHODIMP CNuclei::Observe(IDispatch* Parent, BSTR CtrlName, BSTR NucleusName, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj)
{
	if (g_pSpaceTelescope->m_pCLRProxy)
	{
		IDispatch* pDisp = nullptr;
		pDisp = g_pSpaceTelescope->m_pCLRProxy->GetCtrlByName(Parent, CtrlName, true);
		if (pDisp)
		{
			HWND h = 0;
			h = g_pSpaceTelescope->m_pCLRProxy->IsNucleus(pDisp);
			if (h)
			{
				CString strNucleusName = OLE2T(NucleusName);
				CString strKey = OLE2T(bstrKey);
				if (strNucleusName == _T(""))
					NucleusName = CtrlName;
				if (strKey == _T(""))
					bstrKey = CComBSTR(L"Default");
				auto it = m_mapGalaxy.find((HWND)h);
				if (it == m_mapGalaxy.end())
				{
					INucleus* pGalaxy = nullptr;
					CreateNucleus(CComVariant(0), CComVariant((long)h), NucleusName, &pGalaxy);
					return pGalaxy->Observe(bstrKey, bstrXml, ppRetXobj);
				}
				else
				{
					return it->second->Observe(bstrKey, bstrXml, ppRetXobj);
				}
			}
		}
	}
	return S_OK;
}

STDMETHODIMP CNuclei::ObserveCtrl(VARIANT MdiForm, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj)
{
	HWND h = 0;
	bool bMDI = false;
	if (MdiForm.vt == VT_DISPATCH)
	{
		if (g_pSpaceTelescope->m_pCLRProxy)
		{
			h = g_pSpaceTelescope->m_pCLRProxy->GetMDIClientHandle(MdiForm.pdispVal);
			if (h)
				bMDI = true;
			else
			{
				h = g_pSpaceTelescope->m_pCLRProxy->IsNucleus(MdiForm.pdispVal);
				if (h)
				{
					CComBSTR bstrName(L"");
					bstrName = g_pSpaceTelescope->m_pCLRProxy->GetCtrlName(MdiForm.pdispVal);
					CString strKey = OLE2T(bstrKey);
					if (strKey == _T(""))
						bstrKey = CComBSTR(L"Default");
					INucleus* pGalaxy = nullptr;
					map<HWND, CNucleus*>::iterator it = m_mapGalaxy.find((HWND)h);
					if (it == m_mapGalaxy.end())
					{
						CreateNucleus(CComVariant(0), CComVariant((long)h), bstrName, &pGalaxy);
						return pGalaxy->Observe(bstrKey, bstrXml, ppRetXobj);
					}
					else
					{
						return it->second->Observe(bstrKey, bstrXml, ppRetXobj);
					}
				}
			}
		}
	}
	else if (MdiForm.vt == VT_I4 || MdiForm.vt == VT_I8)
	{
		HWND hWnd = NULL;
		if (MdiForm.vt == VT_I4)
		{
			if (MdiForm.lVal == 0)
			{
				hWnd = ::FindWindowEx(m_hWnd, NULL, _T("MDIClient"), NULL);
				if (hWnd)
				{
					bMDI = true;
				}
				else
				{
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);
				}
			}
			else
			{
				hWnd = (HWND)MdiForm.lVal;
				if (::IsWindow(hWnd) == false)
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);
			}
		}
		if (MdiForm.vt == VT_I8)
		{
			if (MdiForm.llVal == 0)
			{
				hWnd = ::FindWindowEx(m_hWnd, NULL, _T("MDIClient"), NULL);
				if (hWnd)
				{
					bMDI = true;
				}
				else
				{
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);
				}
			}
			else
			{
				hWnd = (HWND)MdiForm.llVal;
				if (::IsWindow(hWnd) == false)
					hWnd = ::GetWindow(m_hWnd, GW_CHILD);

			}
		}
		h = hWnd;
	}
	if (h)
	{
		CString strKey = OLE2T(bstrKey);
		if (strKey == _T(""))
			bstrKey = CComBSTR(L"Default");
		INucleus* pGalaxy = nullptr;
		if (bMDI)
		{
			HRESULT hr = CreateNucleus(CComVariant(0), CComVariant((long)h), CComBSTR(L"TangramMDIClientGalaxy"), &pGalaxy);
			if (pGalaxy)
			{
				return pGalaxy->Observe(bstrKey, bstrXml, ppRetXobj);
			}
		}
		else
		{
			CString strKey = OLE2T(bstrKey);
			if (strKey == _T(""))
				bstrKey = CComBSTR(L"Default");

			INucleus* pGalaxy = nullptr;
			auto it = m_mapGalaxy.find((HWND)h);
			if (it == m_mapGalaxy.end())
			{
				TCHAR szBuffer[MAX_PATH];
				::GetWindowText((HWND)h, szBuffer, MAX_PATH);
				CString strText = szBuffer;
				if (strText == _T(""))
				{
					CString s = _T("");
					s.Format(_T("Frame_%p"), h);
					strText = s;
				}
				CreateNucleus(CComVariant(0), CComVariant((long)h), CComBSTR(strText), &pGalaxy);
				return pGalaxy->Observe(bstrKey, bstrXml, ppRetXobj);
			}
			else
			{
				return it->second->Observe(bstrKey, bstrXml, ppRetXobj);
			}
		}
	}

	return S_OK;
}

HRESULT CNuclei::Fire_GalaxyClusterLoaded(IDispatch* sender, BSTR url)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[2];
		avarParams[1] = sender;
		avarParams[1].vt = VT_DISPATCH;
		avarParams[0] = url;
		avarParams[0].vt = VT_BSTR;

		DISPPARAMS params = { avarParams, NULL, 2, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();

			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection.p);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnNucleiLoaded(sender, OLE2T(url));
	}
	return hr;
}

HRESULT CNuclei::Fire_NodeCreated(IXobj* pXobjCreated)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pXobjCreated;
		avarParams[0].vt = VT_DISPATCH;

		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnXobjCreated(pXobjCreated);
	}
	return hr;
}

HRESULT CNuclei::Fire_AddInCreated(IXobj* pRootXobj, IDispatch* pAddIn, BSTR bstrID, BSTR bstrAddInXml)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = pRootXobj;
		avarParams[3].vt = VT_DISPATCH;
		avarParams[2] = pAddIn;
		avarParams[2].vt = VT_DISPATCH;
		avarParams[1] = bstrID;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = bstrAddInXml;
		avarParams[0].vt = VT_BSTR;

		DISPPARAMS params = { avarParams, NULL, 4, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnAddInCreated(pRootXobj, pAddIn, OLE2T(bstrID), OLE2T(bstrAddInXml));
	}
	return hr;
}

HRESULT CNuclei::Fire_BeforeOpenXml(BSTR bstrXml, LONGLONG hWnd)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[2];
		avarParams[1] = bstrXml;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = hWnd;
		avarParams[0].vt = VT_I8;

		DISPPARAMS params = { avarParams, NULL, 2, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnBeforeOpenXml(OLE2T(bstrXml), (HWND)hWnd);
	}
	return hr;
}

HRESULT CNuclei::Fire_OpenXmlComplete(BSTR bstrXml, LONGLONG hWnd, IXobj* pRetRootNode)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[3];
		avarParams[2] = bstrXml;
		avarParams[2].vt = VT_BSTR;
		avarParams[1] = hWnd;
		avarParams[1].vt = VT_I8;
		avarParams[0] = pRetRootNode;
		avarParams[0].vt = VT_DISPATCH;

		DISPPARAMS params = { avarParams, NULL, 3, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnOpenXmlComplete(OLE2T(bstrXml), (HWND)hWnd, pRetRootNode);
	}
	return hr;
}

HRESULT CNuclei::Fire_Destroy()
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		DISPPARAMS params = { NULL, NULL, 0, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnDestroy();
	}
	return hr;
}

HRESULT CNuclei::Fire_NodeMouseActivate(IXobj* pActiveNode)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pActiveNode;
		avarParams[0].vt = VT_DISPATCH;
		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			CComPtr<IUnknown> punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();

			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection.p);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(7, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnNodeMouseActivate(pActiveNode);
	}
	return hr;
}

HRESULT CNuclei::Fire_ClrControlCreated(IXobj* Node, IDispatch* Ctrl, BSTR CtrlName, LONGLONG CtrlHandle)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = Node;
		avarParams[3].vt = VT_DISPATCH;
		avarParams[2] = Ctrl;
		avarParams[2].vt = VT_DISPATCH;
		avarParams[1] = CtrlName;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = CtrlHandle;
		avarParams[0].vt = VT_I8;
		DISPPARAMS params = { avarParams, NULL, 4, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();

			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(8, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnClrControlCreated(Node, Ctrl, OLE2T(CtrlName), (HWND)CtrlHandle);
	}
	return hr;
}

HRESULT CNuclei::Fire_IPCMsg(INucleus* pSender, BSTR bstrType, BSTR bstrContent, BSTR bstrFeature)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[4];
		avarParams[3] = pSender;
		avarParams[3].vt = VT_DISPATCH;
		avarParams[2] = bstrType;
		avarParams[2].vt = VT_BSTR;
		avarParams[1] = bstrContent;
		avarParams[1].vt = VT_BSTR;
		avarParams[0] = bstrFeature;
		avarParams[0].vt = VT_BSTR;
		DISPPARAMS params = { avarParams, NULL, 4, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();

			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);

			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(13, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	return hr;
}

HRESULT CNuclei::Fire_TabChange(IXobj* sender, LONG ActivePage, LONG OldPage)
{
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[3];
		avarParams[2] = sender;
		avarParams[2].vt = VT_DISPATCH;
		avarParams[1] = ActivePage;
		avarParams[1].vt = VT_I4;
		avarParams[0] = OldPage;
		avarParams[0].vt = VT_I4;
		DISPPARAMS params = { avarParams, NULL, 3, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(9, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}

	for (auto &it : m_mapNucleiProxy)
	{
		it.second->OnTabChange(sender, ActivePage, OldPage);
	}
	return hr;
}

HRESULT CNuclei::Fire_CosmosEvent(IWebRTEventObj* pEventObj)
{
	CWebRTEvent* pEvent = (CWebRTEvent*)pEventObj;
	m_mapEventObj[(__int64)pEvent] = pEvent;
	HRESULT hr = S_OK;
	int cConnections = m_vec.GetSize();
	if (cConnections)
	{
		CComVariant avarParams[1];
		avarParams[0] = pEventObj;
		avarParams[0].vt = VT_DISPATCH;
		DISPPARAMS params = { avarParams, NULL, 1, 0 };
		for (int iConnection = 0; iConnection < cConnections; iConnection++)
		{
			g_pSpaceTelescope->Lock();
			IUnknown* punkConnection = m_vec.GetAt(iConnection);
			g_pSpaceTelescope->Unlock();
			IDispatch* pConnection = static_cast<IDispatch*>(punkConnection);
			if (pConnection)
			{
				CComVariant varResult;
				hr = pConnection->Invoke(12, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &params, &varResult, NULL, NULL);
			}
		}
	}
	return hr;
}

STDMETHODIMP CNuclei::get_NucleiXML(BSTR* pVal)
{
	//CString strData = m_strXmlHeader;
	//if (strData == _T(""))
	//	strData = _T("<tangramdefaultpage>");
	//CString strIndex = _T("@");
	//for (auto& it : m_mapGalaxy)
	//{
	//	CComBSTR bstrXml(L"");
	//	strIndex += it.second->m_strNucleusName;
	//	strIndex += _T("@");
	//	it.second->get_GalaxyXML(&bstrXml);
	//	strData += OLE2T(bstrXml);
	//}
	//map<CString, CString> m_mapTemp;
	//for (auto& it : m_strMapKey)
	//{
	//	CString strKey = it.first;
	//	int nPos = strKey.Find(_T("@"));
	//	if (nPos != -1)
	//	{
	//		strKey = strKey.Mid(nPos);
	//		nPos = strKey.ReverseFind('@');
	//		if (nPos != -1)
	//		{
	//			strKey = strKey.Left(nPos + 1);
	//			if (strIndex.Find(strKey) == -1)
	//			{
	//				strKey.Replace(_T("@"), _T(""));
	//				auto it2 = m_mapTemp.find(strKey);
	//				if (strKey != _T(""))
	//				{
	//					if (it2 == m_mapTemp.end())
	//					{
	//						m_mapTemp[strKey] = it.second;
	//					}
	//					else
	//					{
	//						m_mapTemp[strKey] = it2->second + it.second;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	//for (auto& it : m_mapTemp)
	//{
	//	CString strXml = _T("");
	//	strXml.Format(_T("<%s>%s</%s>"), it.first, it.second, it.first);
	//	strData += strXml;
	//}
	//if (m_strXmlBottom != _T(""))
	//	strData += m_strXmlBottom;
	//else
	//	strData += _T("</tangramdefaultpage>");
	//*pVal = CComBSTR(strData);
	return S_OK;
}

STDMETHODIMP CNuclei::ObserveNuclei(BSTR bstrGalaxys, BSTR bstrKey, BSTR bstrXml, VARIANT_BOOL bSaveToConfigFile)
{
	CString strGalaxys = OLE2T(bstrGalaxys);
	CString strKey = OLE2T(bstrKey);
	CString strXml = OLE2T(bstrXml);
	if (strGalaxys == _T(""))
	{
		for (auto &it : m_mapGalaxy)
		{
			if (it.second != m_pBKGalaxy)
			{
				IXobj* pXobj = nullptr;
				it.second->Observe(bstrKey, bstrXml, &pXobj);
			}
		}
	}
	else
	{
		strGalaxys = _T(",") + strGalaxys;
		for (auto& it : m_mapGalaxy)
		{
			CString strName = _T(",") + it.second->m_strNucleusName + _T(",");
			if (strGalaxys.Find(strName) != -1)
			{
				IXobj* pXobj = nullptr;
				it.second->Observe(bstrKey, bstrXml, &pXobj);
			}
		}
	}

	return S_OK;
}
