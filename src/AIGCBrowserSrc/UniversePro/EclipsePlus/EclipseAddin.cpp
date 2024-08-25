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

 //https://github.com/eclipse/rt.equinox.framework/tree/master/features/org.eclipse.equinox.executable.feature

#include "../stdafx.h"
#include "../UniverseApp.h"
#include "../Xobj.h"
#include "../WinNucleus.h"
#include "../GridWnd.h"
#include "EclipseAddin.h"

#include "atlcom.h"

extern jstring newJavaString(JNIEnv *env, _TCHAR * str);

CEclipseExtender::CEclipseExtender()
{
}

CEclipseExtender::~CEclipseExtender()
{
}

STDMETHODIMP CEclipseExtender::Close()
{
	delete this;
	return S_OK;
}

STDMETHODIMP CEclipseExtender::get_ActiveWorkBenchWindow(BSTR bstrID, IWorkBenchWindow** pVal)
{
	CString strID = OLE2T(bstrID);
	strID.Trim();
	if (strID==_T(""))
	{
		if (g_pSpaceTelescope->m_pActiveEclipseWnd)
		{
			*pVal = (IWorkBenchWindow*)g_pSpaceTelescope->m_pActiveEclipseWnd;
			(*pVal)->AddRef();
		}
	}
	else
	{
		IWebRT* pWebRT = nullptr;
		g_pSpaceTelescope->get_RemoteCosmos(bstrID, &pWebRT);
		if (pWebRT)
		{
			IWorkBenchWindow* pRet = nullptr;
			IWebRTExtender* pExtender = nullptr;
			pWebRT->get_Extender(&pExtender);
			if (pExtender)
			{
				CComQIPtr<IEclipseExtender> pEclipse(pExtender);
				if(pEclipse)
					pEclipse->get_ActiveWorkBenchWindow(bstrID, &pRet);
				if (pRet)
				{
					*pVal = pRet;
					(*pVal)->AddRef();
				}
			}
		}
	}

	return S_OK;
}

CEclipseWnd::CEclipseWnd(void)
{
	m_pNucleus = nullptr;
	m_pCurXobj = nullptr;
	m_pHostXobj = nullptr;
	m_strXml = _T("");
	m_strPath = _T("");
	m_strAppProxyID = _T("");
	m_strNodeName = _T("");
	m_strDocKey = _T("");
	m_strFrameID = _T("");
	m_pAppProxy = nullptr;
	m_pNuclei = nullptr;
	g_pSpaceTelescope->m_pActiveEclipseWnd = this;
}

CEclipseWnd::~CEclipseWnd(void) 
{
	if (m_pNuclei)
	{
		HWND hWnd = m_pNuclei->m_hWnd;
		auto it = g_pSpaceTelescope->m_mapNuclei.find(hWnd);
		if (it != g_pSpaceTelescope->m_mapNuclei.end())
		delete m_pNuclei;
	}
	ATLTRACE(_T("delete CEclipseWnd:%x\n"), this);
}

void CEclipseWnd::OnFinalMessage(HWND hWnd)
{
	auto it = g_pSpaceTelescope->m_mapWorkBenchWnd.find(hWnd);
	if (it != g_pSpaceTelescope->m_mapWorkBenchWnd.end())
		g_pSpaceTelescope->m_mapWorkBenchWnd.erase(it);
	if (g_pSpaceTelescope->m_pCLRProxy)
	{
		g_pSpaceTelescope->m_pCLRProxy->ReleaseCosmosObj((IWorkBenchWindow*)this);
	}
	CWindowImpl::OnFinalMessage(hWnd);
	delete this;
}

void CEclipseWnd::CreatePage(BOOL bSaveToConfigFile)
{
	if (m_pNuclei == nullptr)
	{
		INuclei* pNuclei = nullptr;
		g_pSpaceTelescope->CreateNucleusGroup((LONGLONG)m_hWnd, &pNuclei);
		if (pNuclei == nullptr)
			return;
		m_pNuclei = (CNuclei*)pNuclei;
		HMENU hMenu = ::GetMenu(m_hWnd);
		if (hMenu)
		{
			MENUITEMINFO mii;
			mii.fMask = MIIM_STRING;
			mii.cbSize = sizeof(MENUITEMINFO);
			int nCount = ::GetMenuItemCount(hMenu);
			for (int i = nCount - 1; i >0; i--)
			{
				mii.cch = 256;
				mii.fType = MFT_STRING;
				mii.dwTypeData = g_pSpaceTelescope->m_szBuffer;
				GetMenuItemInfo(hMenu, i, true, &mii);
				CString str = mii.dwTypeData;
				if (str == _T("&Window"))
				{
					HMENU hSubMenu = ::GetSubMenu(hMenu, i);
					int nCount = ::GetMenuItemCount(hSubMenu);
					for (int i = 0; i<nCount; i++)
					{
						mii.fMask = MIIM_STRING | MIIM_ID;
						mii.cch = 256;
						mii.dwTypeData = g_pSpaceTelescope->m_szBuffer;
						GetMenuItemInfo(hSubMenu, i, true, &mii);
						str = mii.dwTypeData;
						if (str == _T("&New Window"))
						{
							m_nNewWinCmdID = mii.wID;
							break;
						}
					}
					break;
				}
			}
		}
		if (::IsWindowVisible(m_hWnd))
		{
			m_strDocKey = g_pSpaceTelescope->m_strCurrentEclipsePagePath;
			g_pSpaceTelescope->m_strCurrentEclipsePagePath = _T("");
			Show(m_strDocKey);
			auto it2 = g_pSpaceTelescope->m_mapValInfo.find(_T("newmdtframe"));
			if (it2 != g_pSpaceTelescope->m_mapValInfo.end())
			{
				m_strFrameID = OLE2T(it2->second.bstrVal);
				g_pSpaceTelescope->m_mapValInfo.erase(it2);
			}
		}
	}
}

STDMETHODIMP CEclipseWnd::get_Count(long* pCount)
{
	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_Ctrl(VARIANT vIndex, IEclipseCtrl **ppCtrl)
{
	return S_OK;
}

STDMETHODIMP CEclipseWnd::CloseTangramUI()
{
	if (m_pNucleus)
	{
		HWND _hWnd = ::CreateWindowEx(NULL, _T("Cosmos Xobj Class"), L"", WS_CHILD, 0, 0, 0, 0, g_pSpaceTelescope->m_hCosmosWnd, NULL, AfxGetInstanceHandle(), NULL);
		HWND _hChildWnd = ::CreateWindowEx(NULL, _T("Cosmos Xobj Class"), L"", WS_CHILD, 0, 0, 0, 0, (HWND)_hWnd, NULL, AfxGetInstanceHandle(), NULL);
		if (::IsWindow(m_hWnd))
		{
			m_pNucleus->ModifyHost((LONGLONG)_hChildWnd);
			::DestroyWindow(_hWnd);
		}
		m_pNucleus = nullptr;
		delete m_pNuclei;
		m_pNuclei = nullptr;
	}

	return S_OK;
}

STDMETHODIMP CEclipseWnd::get__NewEnum(IUnknown** ppVal)
{
	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_Handle(LONGLONG* pVal)
{
	*pVal = (LONGLONG)m_hClient;
	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_Nuclei(INuclei** pVal)
{
	if (m_pNuclei)
		*pVal = m_pNuclei;

	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_WinNucleus(INucleus** pVal)
{
	if (m_pNucleus)
		*pVal = m_pNucleus;
	return S_OK;
}

STDMETHODIMP CEclipseWnd::Observe(BSTR bstrKey, BSTR bstrXml, IXobj** ppXobj)
{
	CString strKey = OLE2T(bstrKey);
	strKey.Trim();
	HRESULT hr = S_FALSE;
	if (m_hClient == NULL)
		return S_FALSE;
	if (m_pNuclei == nullptr)
	{
		INuclei* pNuclei = nullptr;
		g_pSpaceTelescope->CreateNucleusGroup((LONGLONG)m_hWnd, &pNuclei);
		if (pNuclei == nullptr)
			return S_FALSE;
		m_pNuclei = (CNuclei*)pNuclei;
		if (m_pNucleus == nullptr)
		{
			INucleus* pGalaxy = nullptr;
			m_pNuclei->CreateNucleus(CComVariant(0), CComVariant((LONGLONG)m_hClient), CComBSTR(L"default"), &pGalaxy);
			if (pGalaxy == nullptr)
			{
				delete m_pNuclei;
				m_pNuclei = nullptr;
			}
			m_pNucleus = (CNucleus*)pGalaxy;
		}
	}
	else
	{
		m_pNucleus = (CNucleus*)::SendMessage(m_hClient, WM_HUBBLE_DATA, 0, 1992);
		if (m_pNucleus == nullptr)
		{
			auto it = m_pNuclei->m_mapGalaxy.find(m_hClient);
			if (it != m_pNuclei->m_mapGalaxy.end())
				m_pNucleus = it->second;
			else
			{
				INucleus* pGalaxy = nullptr;
				m_pNuclei->CreateNucleus(CComVariant(0), CComVariant((LONGLONG)m_hClient), CComBSTR(L"default"), &pGalaxy);
				if (pGalaxy == nullptr)
				{
					delete m_pNuclei;
					m_pNuclei = nullptr;
				}
				m_pNucleus = (CNucleus*)pGalaxy;
			}
		}
	}
	if (m_pNucleus)
	{
		hr = m_pNucleus->Observe(bstrKey, bstrXml, ppXobj);
		if (*ppXobj)
		{
			m_pCurXobj = (CXobj*)*ppXobj;
		}
	}
	return hr;
} 

STDMETHODIMP CEclipseWnd::ObserveEx(BSTR bstrKey, BSTR bstrXml, IXobj** ppXobj)
{
	HRESULT hr = Observe(bstrKey, bstrXml, ppXobj);
	if (*ppXobj)
	{
		m_pCurXobj = (CXobj*)*ppXobj;
	}
	return hr;
} 

STDMETHODIMP CEclipseWnd::ObserveinView(int nIndex, BSTR bstrKey, BSTR bstrXml, IXobj** ppRetXobj)
{
	IEclipseCtrl* pCtrl = nullptr;
	get_Ctrl(CComVariant((int)nIndex), &pCtrl);
	if (pCtrl)
	{
		IXobj* pXobj = nullptr;
		return pCtrl->Observe(CComBSTR(L"EclipseView"), bstrKey, bstrXml, ppRetXobj);
	}

	return S_OK;
}

STDMETHODIMP CEclipseWnd::Active()
{
	SetFocus();

	return S_OK;
}

STDMETHODIMP CEclipseWnd::get_CosmosCtrl(LONGLONG hWnd, IEclipseCtrl** pVal)
{
	return S_OK;
}

void CEclipseWnd::Show(CString strID)
{
	LONG_PTR data = 0;
	if(::IsWindow(m_hClient))
		data = ::GetWindowLongPtr(m_hClient, GWLP_USERDATA);
	if (g_pSpaceTelescope->m_bIsEclipseInit == false)
		g_pSpaceTelescope->m_bIsEclipseInit = true;
	if (data==0&&g_pSpaceTelescope->m_pUniverseAppProxy)
	{
		m_strPath = strID;
		if (::IsChild(m_hWnd, m_hClient))
		{
			m_strAppProxyID = _T("");
			auto it = g_pSpaceTelescope->m_mapNuclei.find(m_hWnd);
			if (m_pNuclei == nullptr)
			{
				if (it != g_pSpaceTelescope->m_mapNuclei.end())
					m_pNuclei = (CNuclei*)it->second;
				else
				{
					m_pNuclei = new CComObject<CNuclei>();
					m_pNuclei->m_hWnd = m_hWnd;
					g_pSpaceTelescope->m_mapNuclei[m_hWnd] = m_pNuclei;

					for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
					{
						CNucleiProxy* pWebRTProxy = it.second->OnNucleiCreated(m_pNuclei);
						if (pWebRTProxy)
							m_pNuclei->m_mapNucleiProxy[it.second] = pWebRTProxy;
					}
				}
			}

			if (m_strPath == _T("")||::PathFileExists(m_strPath)==false)
			{
				auto it = g_pSpaceTelescope->m_mapCreatingWorkBenchInfo.find(strID);
				if (it != g_pSpaceTelescope->m_mapCreatingWorkBenchInfo.end())
				{
					m_strDocKey = m_strXml = it->second;
					g_pSpaceTelescope->m_mapCreatingWorkBenchInfo.erase(it);
				}
				else
					m_strDocKey = m_strXml = m_strPath = g_pSpaceTelescope->m_strDefaultWorkBenchXml;
			}
			else
			{
				m_strDocKey = m_strXml = m_strPath;
				CTangramXmlParse m_Parse;
				if (m_Parse.LoadFile(m_strDocKey))
				{
					m_strAppProxyID = m_Parse.attr(_T("styleproxyid"), _T(""));
				}
			}
			if (m_strAppProxyID != _T(""))
			{
				m_pAppProxy = nullptr;
				auto it = g_pSpaceTelescope->m_mapWebRTAppProxy.find(m_strAppProxyID.MakeLower());
				if (it != g_pSpaceTelescope->m_mapWebRTAppProxy.end())
					m_pAppProxy = it->second;
				else
				{
					CString strPath = g_pSpaceTelescope->m_strAppPath;
					HMODULE hHandle = nullptr;
					CString strAppName = _T("");
					int nPos = m_strAppProxyID.Find(_T("."));
					if (nPos != -1)
						strAppName = m_strAppProxyID.Left(nPos);
					CString strdll = strPath + m_strAppProxyID + _T("\\") + strAppName + _T(".dll");
					if (::PathFileExists(strdll))
						hHandle = ::LoadLibrary(strdll);
					if (hHandle)
					{
						it = g_pSpaceTelescope->m_mapWebRTAppProxy.find(m_strAppProxyID.MakeLower());
						if (it != g_pSpaceTelescope->m_mapWebRTAppProxy.end())
						{
							m_pAppProxy = it->second;
						}
					}
				}
				if (m_pAppProxy)
				{
					g_pSpaceTelescope->m_pActiveAppProxy = m_pAppProxy;
					m_pAppProxy->m_hCreatingView = m_hClient;
					::SetWindowText(m_hClient, g_pSpaceTelescope->m_strAppKey);
					::SetWindowLongPtr(m_hClient, GWLP_USERDATA, (LONG_PTR)1);
				}
			}
			else if(strID !=_T(""))
			{
				INucleus* pGalaxy = nullptr;
				m_pNuclei->CreateNucleus(CComVariant(0), CComVariant((LONGLONG)m_hClient), CComBSTR(L"default"), &pGalaxy);
				if (pGalaxy)
				{
					m_pNucleus = (CNucleus*)pGalaxy;
					//m_pNuclei->m_mapNeedSaveGalaxy[m_hClient] = m_pNucleus;
					CString strKey = _T("default");
					if (m_strDocKey == _T(""))
					{
						m_strDocKey = m_strXml = m_strPath = g_pSpaceTelescope->m_strAppDataPath + _T("default.workbench");
					}
					else
					{
						strKey = strID;
						if (g_pSpaceTelescope->m_nAppType == APP_ECLIPSE)
							m_strDocKey = g_pSpaceTelescope->m_strStartupURL;
					}

					IXobj* pXobj = nullptr;
					pGalaxy->Observe(CComBSTR(strKey), CComBSTR(m_strDocKey), &pXobj);
					if (pXobj == nullptr)
					{
						delete m_pNucleus;
						m_pNucleus = nullptr;
						m_pNuclei = nullptr;
					}
				}
			}
		}
	}
}

LRESULT CEclipseWnd::OnShowWindow(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	if (g_pSpaceTelescope->m_strWorkBenchStrs != _T(""))
	{
		int nPos = g_pSpaceTelescope->m_strWorkBenchStrs.Find(_T("|"));
		m_strDocKey = g_pSpaceTelescope->m_strWorkBenchStrs.Left(nPos);
		g_pSpaceTelescope->m_strWorkBenchStrs = g_pSpaceTelescope->m_strWorkBenchStrs.Mid(nPos + 1);
	}

	if (g_pSpaceTelescope->m_strCurrentEclipsePagePath != _T(""))
	{
		m_strDocKey = g_pSpaceTelescope->m_strCurrentEclipsePagePath;
		g_pSpaceTelescope->m_strCurrentEclipsePagePath = _T("");
	}
	if (::IsWindow(m_hClient)/*&& m_strDocKey!=_T("")*/)
	{
		Show(m_strDocKey);
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	if (wParam == m_nNewWinCmdID)
	{
		if (g_pSpaceTelescope->m_strCurrentEclipsePagePath == _T(""))
		{
			CComBSTR bstrTemplate(L"");
			g_pSpaceTelescope->m_strCurrentEclipsePagePath = OLE2T(bstrTemplate);
		}
		if (g_pSpaceTelescope->m_strCurrentEclipsePagePath == _T("")&& m_pNucleus)
		{
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnWebRTGetXml(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL&)
{
	CString strNucleusName = (LPCTSTR)wParam;
	CString currentKey = (LPCTSTR)lParam;
	CString strIndex = strNucleusName + L"_" + currentKey;
	CTangramXmlParse parse;
	if (parse.LoadXml(m_strXml) || parse.LoadFile(m_strXml))
	{
		CTangramXmlParse* pParse = parse.GetChild(strNucleusName);
		if (pParse)
		{
			CTangramXmlParse* pParse2 = pParse->GetChild(currentKey);
			if (pParse2)
			{
				auto it = g_pSpaceTelescope->m_mapValInfo.find(strIndex);
				if (it != g_pSpaceTelescope->m_mapValInfo.end())
				{
					g_pSpaceTelescope->m_mapValInfo.erase(it);
				}
				g_pSpaceTelescope->m_mapValInfo[strIndex] = CComVariant(pParse2->xml());
				return 1;
			}
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnWebRTMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	switch (wParam)
	{
	case 1963:
		{
			return ::SendMessage(::GetParent(m_hClient), WM_QUERYAPPPROXY, wParam, 0);
		}
		break;
	case 20190305:
		{
			return (LRESULT)this;
		}
		break;
	case 19820911:
		{
			if (lParam == 0)
			{
				::PostMessage(m_hWnd, WM_COSMOSMSG, 19820911, 1);
			}
			if (lParam == 1)
			{
				CNucleus* pGalaxy = (CNucleus*)::SendMessage(m_hClient, WM_HUBBLE_DATA, 0, 1992);
				if (pGalaxy)
				{
					pGalaxy->m_nGalaxyType = EclipseWorkBenchGalaxy;
					pGalaxy->m_pWorkBenchFrame = this;
				}
				else
				{
					if (g_pSpaceTelescope->m_strWorkBenchStrs != _T(""))
					{
						int nPos = g_pSpaceTelescope->m_strWorkBenchStrs.Find(_T("|"));
						m_strDocKey = g_pSpaceTelescope->m_strWorkBenchStrs.Left(nPos);
						g_pSpaceTelescope->m_strWorkBenchStrs = g_pSpaceTelescope->m_strWorkBenchStrs.Mid(nPos + 1);
					}
					if (g_pSpaceTelescope->m_strCurrentEclipsePagePath != _T(""))
					{
						m_strDocKey = g_pSpaceTelescope->m_strCurrentEclipsePagePath;
						g_pSpaceTelescope->m_strCurrentEclipsePagePath = _T("");
					}
					LONG_PTR data = 0;
					if (::IsWindow(m_hClient)/*&& m_strDocKey!=_T("")*/)
					{
						data = ::GetWindowLongPtr(m_hClient, GWLP_USERDATA);
						if (data == 0)
						{
							Show(m_strDocKey);
							break;
						}
					}
				}
			}
		}
		break;
	}

	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	m_strPath = g_pSpaceTelescope->m_strAppDataPath + _T("default.workbench");
	if (m_strPath != _T(""))
	{
		LRESULT lRes = ::SendMessage(::GetParent(m_hClient),WM_QUERYAPPPROXY,0,19631222);
		if (lRes == 0)
		{
			CTangramXmlParse m_Parse;
			if (m_pNuclei)
			{
				m_strXml = _T("<eclipseplus>");
				for (auto& it : m_pNuclei->m_mapGalaxy)
				{
					CNucleus* pGalaxy = it.second;
					for (auto& it2 :pGalaxy->m_mapXobj)
					{
						CXobj* pWndXobj = (CXobj*)it2.second;
						if (pWndXobj)
						{
							if (pWndXobj->m_pWindow)
							{
								if (pWndXobj->m_nActivePage > 0)
								{
									CString strVal = _T("");
									strVal.Format(_T("%d"), pWndXobj->m_nActivePage);
									pWndXobj->m_pHostParse->put_attr(_T("activepage"), strVal);
								}
								pWndXobj->m_pWindow->Save();
							}
							if (pWndXobj->m_nViewType == Grid)
							{
								((CGridWnd*)pWndXobj->m_pHostWnd)->Save();
							}
							g_pSpaceTelescope->UpdateXobj(pWndXobj);
							for (auto& it2 :pWndXobj->m_vChildNodes)
							{
								g_pSpaceTelescope->UpdateXobj(it2);
							}
						}
					}
				}
				//for (auto& it : m_pNuclei->m_mapNeedSaveGalaxy)
				//{
				//	CNucleus* pGalaxy = it.second;
				//	auto it2 = pGalaxy->m_mapXobj.find(_T("default"));
				//	if (it2 != pGalaxy->m_mapXobj.end())
				//	{
				//		CXobj* _pXobj = (CXobj*)it2->second;
				//		if (pGalaxy->m_strNucleusName.Find(_T("@")) == -1)
				//		{
				//			CString strXml = _pXobj->m_pXobjShareData->m_pWebRTParse->xml();
				//			strXml.Replace(_T("/><"), _T("/>\r\n<"));
				//			strXml.Replace(_T("/>"), _T("></xobj>"));
				//			CString s = _T("");
				//			s.Format(_T("<%s>%s</%s>"), pGalaxy->m_strNucleusName, strXml, pGalaxy->m_strNucleusName);
				//			m_strXml += s;
				//		}
				//	}
				//}
				m_strXml += _T("</eclipseplus>");
			}
			bool bSave = false;
			if (m_Parse.LoadXml(m_strXml))
			{
				if (m_pAppProxy)
				{
					m_Parse.put_attr(_T("styleproxyid"), m_strAppProxyID);
				}
				bSave = m_Parse.SaveFile(m_strPath);
			}
		}
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}

LRESULT CEclipseWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	CTangramXmlParse xmlParse;
	if (xmlParse.LoadFile(g_pSpaceTelescope->m_strConfigDataFile))
	{
		CTangramXmlParse* pParse = xmlParse.GetChild(_T("openedworkbench"));
		if (pParse == nullptr)
		{
			pParse = xmlParse.AddNode(_T("openedworkbench"));
		}
		if (pParse)
		{
			CString strWorkBenchStrs = m_strDocKey + _T("|");
			strWorkBenchStrs += pParse->text();
			pParse->put_text(strWorkBenchStrs);
			xmlParse.SaveFile(g_pSpaceTelescope->m_strConfigDataFile);
		}
	}
	if (g_pSpaceTelescope->m_pActiveEclipseWnd == this)
		g_pSpaceTelescope->m_pActiveEclipseWnd = nullptr;
	auto it = g_pSpaceTelescope->m_mapWorkBenchWnd.find(m_hWnd);
	if (it != g_pSpaceTelescope->m_mapWorkBenchWnd.end())
	{
		g_pSpaceTelescope->m_mapWorkBenchWnd.erase(it);
	}
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	if (g_pSpaceTelescope->m_mapWorkBenchWnd.size() == 0)
	{
		if (::GetModuleHandle(L"chrome_elf.dll"))
		{
			if (g_pSpaceTelescope)
			{
				if (g_pSpaceTelescope->m_mapBrowserWnd.size())
				{
					g_pSpaceTelescope->m_bChromeNeedClosed = true;
					auto it = g_pSpaceTelescope->m_mapBrowserWnd.begin();
					((CBrowser*)it->second)->SendMessageW(WM_CLOSE, 0, 0);
				}
			}
		}
		if (::IsWindow(g_pSpaceTelescope->m_hCosmosWnd))
			::DestroyWindow(g_pSpaceTelescope->m_hCosmosWnd);
	}
	return lRes;
}

LRESULT CEclipseWnd::OnActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
	if (LOWORD(wParam) != WA_INACTIVE)
	{
		g_pSpaceTelescope->m_pActiveEclipseWnd = this;
		g_pSpaceTelescope->m_pActiveAppProxy = m_pAppProxy;
	}
	return lRes;
}

LRESULT CEclipseWnd::OnQueryAppProxy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& )
{
	LRESULT lRes = ::SendMessage(::GetParent(m_hClient), uMsg, wParam, 19631992);
	if (lRes)
	{
		if (m_pAppProxy==nullptr)
			m_pAppProxy = (IUniverseAppProxy*)lRes;

		return lRes;
	}
	
	lRes = DefWindowProc(uMsg, wParam, lParam);
	return lRes;
}
