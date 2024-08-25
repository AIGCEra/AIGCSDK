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

#include "../stdafx.h"
 //#include <afxMDIFrameWndEx.h>
#include "../UniverseApp.h"
#include "../Xobj.h"
#include "../Wormhole.h"
#include "../WinNucleus.h"
#include "../XobjWnd.h"
#include "../GridWnd.h"
#include "../Markup.h" 
#include "WebPage.h"
#include "BrowserWnd.h"
#include <Psapi.h>

namespace Browser {
	CExtendWnd::CExtendWnd(void)
	{
	}

	void CExtendWnd::OnFinalMessage(HWND hWnd)
	{
		CWindowImpl<CExtendWnd, CWindow>::OnFinalMessage(hWnd);
		delete this;
	}

	LRESULT CExtendWnd::OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		CDC* dc = CDC::FromHandle((HDC)wParam);
		RECT rc;
		::GetClientRect(m_hWnd, &rc);
		dc->FillSolidRect(0, 0, rc.right, rc.bottom, RGB(255, 255, 255));

		//HDC hDC = ::GetDC(m_pHostPage->m_hWnd);
		//CDC* pDC = CDC::FromHandle(hDC);

		//RECT rc;
		//::GetClientRect(m_pHostPage->m_hWnd, &rc);

		////CDC memDC;
		////CBitmap bitmap;
		////memDC.CreateCompatibleDC(pDC);
		////bitmap.CreateCompatibleBitmap(pDC, rc.right, rc.bottom);
		////dc->SelectObject(&bitmap);
		////CDC dcMemory;
		////dcMemory.CreateCompatibleDC(pDC);

		////// Select the bitmap into the in-memory DC
		////CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp);
		//dc->BitBlt(0, 0, rc.right, rc.bottom, pDC, 0, 0, SRCCOPY);

		//CBrush br(&bitmap);
		//RECT rt;
		//GetClientRect(&rt);
		//dc->FillRect(&rt, &br);

		//memDC.DeleteDC();
		//bitmap.DeleteObject();

		//::ReleaseDC(m_pHostPage->m_hWnd, hDC);

		//HDC hDC = ::GetDC(m_pHostPage->m_hWnd);
		//CDC* pDC = CDC::FromHandle(hDC);
		//RECT rc;
		//::GetClientRect(m_pHostPage->m_hWnd, &rc);
		//CDC memDC;
		//CBitmap bitmap;
		//memDC.CreateCompatibleDC(pDC);
		//bitmap.CreateCompatibleBitmap(pDC, rc.right, rc.bottom);
		//memDC.SelectObject(&bitmap);
		//memDC.BitBlt(0, 0, rc.right, rc.bottom, pDC, 0, 0, SRCCOPY);

		//CBrush br(&bitmap);
		//RECT rt;
		//GetClientRect(&rt);
		//dc->FillRect(&rt, &br);

		//memDC.DeleteDC();
		//bitmap.DeleteObject();

		//RECT rc;
		//::GetClientRect(m_hWnd, &rc);
		//dc->FillSolidRect(0, 0, rc.right, rc.bottom, RGB(255, 255, 255));
		return true;
	}

	CWebView::CWebView() {
		m_bReloadModel = false;
		m_pWebWnd = nullptr;
		m_pBrowser = nullptr;
		m_pDevToolWnd = nullptr;
		m_pBindWinForm = nullptr;
		m_pAppProxy = nullptr;
		m_bDevToolWnd = false;
		m_strCurKey = _T("");
		m_strCurXml = _T("");
		m_strDocXml = _T("");
		m_strAdditionalUrls = _T("");
		//m_pParentXobj = nullptr;
		m_strMainWndXml = _T("");
		m_strAppProxyID = _T("");
		m_strPageName = _T("");
		m_strLoadingURLs = _T("");
		//m_pBindXobj = nullptr;
		m_pNuclei = nullptr;
		m_pNucleus = nullptr;
		m_hWebHostWnd = m_hExtendWnd = m_hChildWnd = NULL;
		if (m_pChromeRenderFrameHost)
			m_pChromeRenderFrameHost->m_pProxy = this;
		m_mapFormsInfo.clear();
	}

	CWebView::~CWebView() {
		for (auto& it : m_mapChildFormsInfo)
		{
			delete it.second;
		}
	}

	LRESULT CWebView::OnMouseActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		if (m_pChromeRenderFrameHost)//&&::GetWindowLongPtr(m_pChromeRenderFrameHost->GetHostBrowserWnd(), GWL_STYLE) & WS_CHILD)
		{
			g_pSpaceTelescope->m_pActiveHtmlWnd = this;
			g_pSpaceTelescope->m_pNucleus = nullptr;
			g_pSpaceTelescope->m_bWinFormActived = false;
			g_pSpaceTelescope->m_hActiveWnd = nullptr;
			LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
			::PostMessage(m_hWnd, WM_COSMOSMSG, 20190331, 1);
			return lRes;
		}
		else
			g_pSpaceTelescope->m_pActiveHtmlWnd = nullptr;
		return DefWindowProc(uMsg, wParam, lParam);
	}

	LRESULT CWebView::OnWebRTMsg(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL&) {
		switch (wParam)
		{
		case 20230708:
		{
			HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
			HWND hPPWnd = ::GetParent(hBrowser);
			CTangramXmlParse* pParse = (CTangramXmlParse*)wParam;
			//pParse = pParse->GetChild(_T("client"));
			IXobj* pClientObj = g_pSpaceTelescope->ObserveXml(hPPWnd, pParse->attr(_T("id"), _T("default")), pParse->xml());
		}
		break;
		case 20220816:
			OnNTPLoaded();
			break;
		case 20190331:
		{
			if (m_pChromeRenderFrameHost)
			{
				if (lParam)
				{
					g_pSpaceTelescope->m_pActiveHtmlWnd = this;
					g_pSpaceTelescope->m_pNucleus = nullptr;
					g_pSpaceTelescope->m_bWinFormActived = false;
					g_pSpaceTelescope->m_hActiveWnd = nullptr;
					g_pSpaceTelescope->m_pActiveXobj = nullptr;
					::SetFocus(m_hWnd);
				}
				else
				{
					g_pSpaceTelescope->m_pActiveHtmlWnd = nullptr;
					::SendMessage(m_hWnd, WM_KILLFOCUS, (WPARAM)m_hWnd, 0);
				}
				m_pChromeRenderFrameHost->SetFocus((bool)lParam);
			}
		}
		break;
		case 20210411:
		{
			CBrowser* pWebBrowser = nullptr;
			HWND hPWnd = ::GetParent(m_hWnd);
			auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hPWnd);
			if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
			{
				pWebBrowser = (CBrowser*)it->second;
				if (lParam)
				{
					g_pSpaceTelescope->m_nWaitTabCounts = 0;
					g_pSpaceTelescope->m_hWaitTabWebPageWnd = NULL;
					m_strLoadingURLs = _T("");
					theApp.m_bAppStarting = false;
					//pWebBrowser->m_bSZMode = false;
					m_bCanShow = true;
					::SendMessage(hPWnd, WM_BROWSERLAYOUT, 0, pWebBrowser->m_pMDIParent ? 7 : 1);
					if (pWebBrowser->m_pParentXobj)
					{
						RECT rc;
						pWebBrowser->m_pParentXobj->m_pHostWnd->GetClientRect(&rc);
						if (m_pChromeRenderFrameHost)
						{
							::SetWindowPos(m_pChromeRenderFrameHost->GetHostBrowserWnd(), HWND_TOP, -12, -6, rc.right + 24, rc.bottom + 18, SWP_SHOWWINDOW | SWP_NOACTIVATE | SWP_NOREDRAW);
							CWormhole* pSession = pWebBrowser->m_pParentXobj->m_pWormhole;
							if (pSession)
							{
								pSession->InsertString(_T("msgID"), L"WebRuntimeOnInitApplication");
								pSession->SendMessage();
							}
						}
						::PostMessage(pWebBrowser->m_hWnd, WM_BROWSERLAYOUT, 1, 7);
					}
					break;
				}
				if (m_strLoadingURLs != _T(""))
				{
					pWebBrowser->m_bSZMode = true;
					m_bCanShow = false;
					pWebBrowser->m_bInTabChange = true;
					theApp.m_bAppStarting = true;
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(m_strLoadingURLs))
					{
						CString strUrls = _T("");
						int nCount = m_Parse.GetCount();
						for (int i = 0; i < nCount; i++)
						{
							CString strURL = m_Parse.GetChild(i)->attr(_T("url"), _T(""));
							int nPos2 = strURL.Find(_T(":"));
							if (nPos2 != -1)
							{
								CString strURLHeader = strURL.Left(nPos2);
								if (strURLHeader.CompareNoCase(_T("host")) == 0)
								{
									strURL = g_pSpaceTelescope->m_strAppPath + strURL.Mid(nPos2 + 1);
								}
							}
							if (strURL != _T(""))
							{
								strUrls += strURL;
								if (i < nCount - 1)
									strUrls += _T("|");
							}
						}
						if (strUrls != _T(""))
						{
							g_pSpaceTelescope->m_nWaitTabCounts = nCount;
							g_pSpaceTelescope->m_hWaitTabWebPageWnd = m_hWnd;
							CString strDisposition = _T("");
							strDisposition.Format(_T("%d"), NEW_BACKGROUND_TAB);
							if (m_pChromeRenderFrameHost)
							{
								IPCMsg msg;
								msg.m_strId = L"ADD_URL";
								msg.m_strParam1 = strUrls;
								msg.m_strParam2 = strDisposition;
								m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
							}
						}
						if (m_pChromeRenderFrameHost && pWebBrowser->m_pParentXobj)
						{
							CWormhole* pSession = pWebBrowser->m_pParentXobj->m_pWormhole;
							if (pSession)
							{
								pSession->InsertString(_T("msgID"), L"WebRuntimeOnInitApplication");
								pSession->SendMessage();
							}
						}
					}
				}
			}
		}
		break;
		case 20201109:
		{
			if (lParam)
			{
				if (::IsWindow(m_hExtendWnd))
				{
					if (::IsChild(m_hWnd, m_hExtendWnd))
					{
						::SetParent(m_hExtendWnd, ::GetParent(m_hWnd));
						::ShowWindow(m_hExtendWnd, SW_SHOW);
					}
				}
			}
			else
			{
				::SetParent(m_hExtendWnd, m_hWnd);
				::ShowWindow(m_hExtendWnd, SW_HIDE);
			}
		}
		break;
		case 20200429:
		{
			CSession* pSession = (CSession*)lParam;
			pSession->SendMessage();
		}
		break;
		case 20200310:
		{
			CXobj* pXobj = (CXobj*)lParam;
			if (pXobj && pXobj->m_pWormhole == nullptr)
			{
				pXobj->m_pWormhole = (CWormhole*)((CWebRTImpl*)g_pSpaceTelescope)->CreateCloudSession(this);
				if (pXobj->m_pXobjShareData->m_pNucleus->m_pWormhole == nullptr)
				{
					pXobj->m_pXobjShareData->m_pNucleus->m_pWormhole = pXobj->m_pWormhole;
				}
				CWormhole* pSession = pXobj->m_pWormhole;
				if (pSession)
				{
					CCloudWinForm* pForm = nullptr;
					CBrowser* _pBrowser = nullptr;
					HWND hBrowserWnd = m_pChromeRenderFrameHost->GetHostBrowserWnd();
					auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowserWnd);
					if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
					{
						_pBrowser = (CBrowser*)it->second;
						HWND hXobj = ::GetParent(hBrowserWnd);
						IXobj* pXobj = nullptr;
						g_pSpaceTelescope->GetXobjFromHandle((__int64)hXobj, &pXobj);
						if (pXobj)
						{
							_pBrowser->m_pParentXobj = (CXobj*)pXobj;
							if (_pBrowser->m_pParentXobj && _pBrowser->m_pParentXobj->m_pXobjShareData->m_pNucleus->m_pParentWinForm)
							{
								pForm = _pBrowser->m_pParentXobj->m_pXobjShareData->m_pNucleus->m_pParentWinForm;
							}
						}
					}
					pSession->InsertString(_T("msgID"), IPC_NODE_CREARED_ID);
					CString strDocType = pXobj->m_pXobjShareData->m_pNucleus->m_strDocTemplateID;
					if (strDocType == _T(""))
					{
						strDocType = g_pSpaceTelescope->m_pUniverseAppProxy->QueryDocType(pXobj->m_pHostWnd->m_hWnd);
						pXobj->m_pXobjShareData->m_pNucleus->m_strDocTemplateID = strDocType;
					}
					pSession->InsertString(_T("DocTypeID"), strDocType);
					pSession->InsertLong(_T("autodelete"), 0);
					pSession->InsertLong(_T("gridtype"), pXobj->m_nViewType);
					pSession->InsertLong(_T("rows"), pXobj->m_nRows);
					pSession->InsertLong(_T("cols"), pXobj->m_nCols);
					pSession->InsertLong(_T("row"), pXobj->m_nRow);
					pSession->InsertLong(_T("col"), pXobj->m_nCol);
					pSession->InsertString(_T("objtype"), pXobj->m_strObjTypeID);
					if (pXobj->m_strCosmosXml != _T(""))
					{
						pSession->InsertString(_T("formxml"), pXobj->m_strCosmosXml);
					}
					pSession->InsertString(_T("gridxml"), pXobj->m_pHostParse->xml());
					pSession->InsertString(_T("name@page"), pXobj->m_strName);
					pSession->Insertint64(_T("xobjhandle"), (__int64)pXobj->m_pHostWnd->m_hWnd);
					pSession->Insertint64(_T("xobj"), (__int64)(IXobj*)pXobj);
					pSession->Insertint64(_T("Galaxyhandle"), (__int64)pXobj->m_pXobjShareData->m_pNucleus->m_hWnd);
					if (pXobj->m_pXobjShareData->m_pNucleus->m_strNucleusName == _T("default"))
					{
						CString strName = pXobj->m_pRootObj->m_pHostParse->attr(_T("galaxy"), _T(""));
						if (strName != _T(""))
							pXobj->m_pXobjShareData->m_pNucleus->m_strNucleusName = strName;
					}
					pSession->InsertString(_T("galaxy"), pXobj->m_pXobjShareData->m_pNucleus->m_strNucleusName);
					pSession->InsertString(TGM_NUCLEUS, pXobj->m_pRootObj->m_strKey);
					pSession->Insertint64(_T("rootgridhandle"), (__int64)pXobj->m_pRootObj->m_pHostWnd->m_hWnd);
					pSession->Insertint64(_T("domhandle"), (__int64)pXobj->m_pWormhole);
					if (pXobj->m_pXobjShareData->m_pHostClientView)
						pSession->Insertint64(_T("nucleushandle"), (__int64)pXobj->m_pXobjShareData->m_pHostClientView->m_hWnd);
					pSession->InsertString(_T("objID"), _T("wndnode"));
					switch (pXobj->m_nViewType)
					{
					case Grid:
					{
						CGridWnd* pWnd = (CGridWnd*)pXobj->m_pHostWnd;
						for (int i = 0; i < pXobj->m_nRows; i++)
						{
							for (int j = 0; j < pXobj->m_nCols; j++)
							{
								int nIndex = j + i * pXobj->m_nRows;
								CString strIndex = _T("");
								strIndex.Format(_T("%d"), nIndex);
								pSession->Insertint64(strIndex, (__int64)::GetDlgItem(pWnd->m_hWnd, pWnd->IdFromRowCol(i, j)));
							}
						}
					}
					break;
					case TabGrid:
					{
						for (auto& it : pXobj->m_vChildNodes)
						{
							CString strIndex = _T("");
							strIndex.Format(_T("%d"), it->m_nCol);
							pSession->Insertint64(strIndex, (__int64)it->m_pHostWnd->m_hWnd);
						}
					}
					break;
					default:
						break;
					}
					if (pXobj->m_pParentObj)
					{
						pSession->Insertint64(_T("parenthandle"), (__int64)pXobj->m_pParentObj->m_pHostWnd->m_hWnd);
					}

					CCloudWinForm* pMDIPForm = nullptr;
					bool bMDIChild = false;
					{
						pXobj->m_pRootObj->m_pXobjShareData->m_pNucleus->GetWinForm(pXobj->m_pRootObj->m_pXobjShareData->m_pNucleus->m_hWnd);
						if (pXobj->m_pRootObj->m_pParentWinFormWnd)
						{
							pXobj->m_pParentWinFormWnd = pXobj->m_pRootObj->m_pParentWinFormWnd;
							{
								HWND hPWnd = pXobj->m_pRootObj->m_pParentWinFormWnd->m_hWnd;
								if ((::GetWindowLong(hPWnd, GWL_EXSTYLE) & WS_EX_MDICHILD))
								{
									bMDIChild = true;
									hPWnd = ::GetParent(::GetParent(hPWnd));
									pMDIPForm = (CCloudWinForm*)::SendMessage(hPWnd, WM_HUBBLE_DATA, 0, 20190214);
								}
							}
						}
					}

					if (pXobj->m_pParentWinFormWnd)
					{
						pSession->Insertint64(_T("parentFormHandle"), (__int64)pXobj->m_pParentWinFormWnd->m_hWnd);
					}
					else if (pForm != nullptr)
					{
						pXobj->m_pParentWinFormWnd = pForm;
						pSession->Insertint64(_T("parentFormHandle"), (__int64)pForm->m_hWnd);
					}
					if (bMDIChild && pMDIPForm)
					{
						pSession->Insertint64(_T("parentMDIFormHandle"), (__int64)pMDIPForm->m_hWnd);
						INucleus* pGalaxy = nullptr;
						CWebRTImpl* _pWebRTImpl = static_cast<CWebRTImpl*>(g_pSpaceTelescope);
						auto it = _pWebRTImpl->m_mapNuclei.find(pMDIPForm->m_hWnd);
						if (it != _pWebRTImpl->m_mapNuclei.end())
						{
							it->second->get_WinNucleus(CComVariant(L"mdiclient"), &pGalaxy);
							if (pGalaxy)
							{
								IXobj* _pXobj = nullptr;
								pGalaxy->get_VisibleXobj(&_pXobj);
								__int64 nHandle = 0;
								if (_pXobj)
								{
									_pXobj->get_Handle(&nHandle);
									pSession->Insertint64(_T("BindMdiXobjHandle"), nHandle);
									if (pXobj->m_pParentWinFormWnd)
									{
										pXobj->m_pParentWinFormWnd->m_pBindMDIXobj = (CXobj*)_pXobj;
									}
								}
								if (m_pNucleus && m_pNucleus->m_pWorkXobj && pXobj->m_pParentWinFormWnd)
								{
									CString strKey = pXobj->m_pParentWinFormWnd->m_strKey;
									auto it = m_pNucleus->m_mapXobj.find(strKey);// 
									if (it != m_pNucleus->m_mapXobj.end())
									{
										it->second->get_Handle(&nHandle);
										if (nHandle)
											pSession->Insertint64(_T("mdiwebbindgridhandle"), nHandle);
										if (pXobj->m_pParentWinFormWnd)
										{
											pXobj->m_pParentWinFormWnd->m_pWebBindMDIXobj = it->second;
										}
									}
								}
							}
						}
					}
					if (pXobj->m_pDisp)
					{
						pXobj->m_pWormhole->Insertint64(_T("objectdisp"), (__int64)pXobj->m_pDisp);
						if (g_pSpaceTelescope->m_pCLRProxy)
						{
							g_pSpaceTelescope->m_pCLRProxy->ConnectXobjToWebPage(pXobj, true);
						}
					}

					CCloudWinForm* pIsForm = (CCloudWinForm*)::SendMessage(pXobj->m_pHostWnd->m_hWnd, WM_HUBBLE_DATA, 0, 20190214);
					if (pIsForm)
					{
						pSession->InsertLong(_T("nodeisform"), 1);
					}
					m_pChromeRenderFrameHost->SendCosmosMessage(pSession->m_pSession);

					if (pIsForm)
					{
						if (pIsForm->m_bMdiForm || pIsForm->m_hMDIClient)
							pSession->InsertLong(_T("WinFormType"), 1);
						else
							pSession->InsertLong(_T("WinFormType"), 0);

						CString strFormName = pXobj->m_pHostParse->attr(_T("formname"), _T(""));
						if (strFormName == _T(""))
						{
							//strFormName = marshal_as<CString>(thisForm->Name);
						}
						pSession->InsertString(_T("formname"), strFormName);
						pSession->InsertString(_T("tagName"), pXobj->m_pHostParse->name());
						//pWebRTSession->Insertint64(_T("formhandle"), thisForm->Handle.ToInt64());
						CString strFormID = pXobj->m_pHostParse->attr(_T("id"), _T(""));
						if (strFormID != _T(""))
						{
							pSession->InsertString(_T("id"), strFormID);
						}
						strFormID = pXobj->m_pHostParse->attr(_T("objid"), _T(""));
						pSession->InsertString(_T("objid"), strFormID);

						pSession->Insertint64(_T("formhandle"), (__int64)pIsForm->m_hWnd);
						pSession->InsertString(_T("msgID"), _T("WINFORM_CREATED"));
						//pSession->SendMessage();
						m_pChromeRenderFrameHost->SendCosmosMessage(pSession->m_pSession);
					}
				}
			}
		}
		break;
		case 20200311:
		{
			if (m_pNucleus && m_pNucleus->m_pWorkXobj)
			{
				if (m_pNucleus->m_pWorkXobj->m_pWormhole)
				{
					m_pNucleus->m_pWorkXobj->m_pWormhole->InsertString(_T("msgID"), _T("TANGRAMAPP_READY"));
					m_pNucleus->m_pWorkXobj->m_pWormhole->SendMessage();
				}
			}
		}
		break;
		case 20200131:
		{
			if (m_pChromeRenderFrameHost)
			{
				OutputDebugString(_T("------------------WebRT Begin ShowWebPage------------------------\n"));
				HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
				::SetParent(m_hExtendWnd, hBrowser);
				m_pChromeRenderFrameHost->ShowWebPage(true);
				//::SendMessage(hBrowser, WM_BROWSERLAYOUT, 0, 4);
				OutputDebugString(_T("------------------WebRT End ShowWebPage------------------------\n"));
			}
		}
		break;
		case 20200221:
		{
			IPCMsg* pMsg = (IPCMsg*)lParam;
			if (pMsg && m_pChromeRenderFrameHost)
			{
				m_pChromeRenderFrameHost->SendCosmosMessage(pMsg);
				g_pSpaceTelescope->m_pCurrentIPCMsg = nullptr;
			}
		}
		break;
		case 20200213:
		{
			HWND hWnd = (HWND)lParam;
			if (::IsWindow(hWnd))
			{
				CCloudWinForm* pWnd = (CCloudWinForm*)::SendMessage(hWnd, WM_HUBBLE_DATA, 0, 20190214);
				if (pWnd)
				{
					m_mapSubWinForm[hWnd] = pWnd;
				}
			}
		}
		break;
		case 19820911:
		{
			Show(_T(""));
		}
		break;
		case 20190115:
		{
			if (g_pSpaceTelescope->m_mapCreatingWorkBenchInfo.size())
			{
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, 0, 20191114);
			}
		}
		break;
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	void CWebView::ParentChanged(CBrowser* pParent, HWND hNewPWnd)
	{
		if (g_pSpaceTelescope->m_bChromeNeedClosed == false && hNewPWnd) {
			::GetClassName(hNewPWnd, g_pSpaceTelescope->m_szBuffer, 256);
			CString strName = g_pSpaceTelescope->m_szBuffer;
			if (strName.Find(_T("Chrome_WidgetWin_0")) == 0)
			{
				if (m_hExtendWnd)
				{
					::SetParent(m_hExtendWnd, m_hWnd);
					::ShowWindow(m_hExtendWnd, SW_HIDE);
				}
			}
			else
			{
				if (m_hExtendWnd)
				{
					::SetParent(m_hExtendWnd, hNewPWnd);
					::ShowWindow(m_hExtendWnd, SW_SHOW);
				}
				HWND hNewPWnd2 = ::GetParent(m_hWnd);
				bool bNewParent = false;
				if (hNewPWnd != hNewPWnd2)
				{
					hNewPWnd = hNewPWnd2;
					bNewParent = true;
				}
				CBrowser* pChromeBrowserWnd = pParent;
				//auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hNewPWnd);
				if (pChromeBrowserWnd)
				{
					pChromeBrowserWnd->m_bSZMode = true;
					g_pSpaceTelescope->m_pActiveBrowser = pChromeBrowserWnd->m_pBrowser;
					if (pChromeBrowserWnd && m_hExtendWnd) {
						if (::IsWindowVisible(m_hWnd)) {
							pChromeBrowserWnd->m_pVisibleWebView = this;
							if (bNewParent)
							{
								g_pSpaceTelescope->m_pActiveBrowser->m_pProxy = pChromeBrowserWnd;
								::PostMessageW(hNewPWnd, WM_BROWSERLAYOUT, 0, 7);
							}
							else
							{
								if (pChromeBrowserWnd->m_bInTabChange)
								{
									::SendMessageW(pChromeBrowserWnd->m_hWnd, WM_BROWSERLAYOUT, 0, 1000);
								}
							}
						}
					}
					if (pChromeBrowserWnd->m_pVisibleWebView && m_bDevToolWnd && pChromeBrowserWnd->m_pVisibleWebView->m_bDevToolWnd == false)
					{
						if (pChromeBrowserWnd->m_pVisibleWebView->m_pDevToolWnd == nullptr)
						{
							pChromeBrowserWnd->m_pVisibleWebView->m_pDevToolWnd = this;
							::ShowWindow(m_hWnd, SW_SHOW);
						}
					}
					bool bChangeParent = false;
					for (auto it : m_mapAttachedForm)
					{
						it.second->m_pBrowser = pChromeBrowserWnd;
						bChangeParent = true;
					}
					if (bChangeParent)
						::PostMessage(pChromeBrowserWnd->m_hWnd, WM_BROWSERLAYOUT, 0, 7);
				}
			}
		}
	}

	LRESULT CWebView::OnDestroy(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL& /*bHandled*/) {
		if (m_hExtendWnd)
		{
			::DestroyWindow(m_hExtendWnd);
		}

		if (g_pSpaceTelescope->m_pCLRProxy)
			g_pSpaceTelescope->m_pCLRProxy->OnWebPageCreated(m_hWnd, (CWebViewImpl*)this, (IWebView*)this, 1);

		m_hExtendWnd = nullptr;

		if (m_bDevToolWnd) {
			if (m_pWebWnd) {
				m_pWebWnd->m_pDevToolWnd = nullptr;
			}
		}
		if (m_mapSubWinForm.size())
		{
			for (auto& it : m_mapSubWinForm)
			{
				::DestroyWindow(it.first);
			}
			m_mapSubWinForm.erase(m_mapSubWinForm.begin(), m_mapSubWinForm.end());
		}
		if (m_mapWinForm.size())
		{
			auto it = m_mapWinForm.find(g_pSpaceTelescope->m_hMainWnd);
			if (it != m_mapWinForm.end())
			{
				m_mapWinForm.erase(it);
			}
			while (m_mapWinForm.size())
			{
				auto it = m_mapWinForm.begin();
				CCloudWinForm* pForm = it->second;
				if (pForm->m_bMainForm == false)
				{
					if (::IsChild(pForm->m_hWnd, m_hWnd) || ::IsWindow(pForm->m_hWnd) == false)
					{
						m_mapWinForm.erase(it);
					}
					else
					{
						::DestroyWindow(pForm->m_hWnd);
					}
				}
				else
				{
					pForm->m_pOwnerHtmlWnd = nullptr;
					m_mapWinForm.erase(it);
				}
				if (m_mapWinForm.size() == 0)
					break;
			}
			m_mapWinForm.erase(m_mapWinForm.begin(), m_mapWinForm.end());
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CWebView::OnShowWindow(UINT uMsg,
		WPARAM wParam,
		LPARAM lParam,
		BOOL&) {
		if (g_pSpaceTelescope->m_bChromeNeedClosed == false && ::IsWindow(m_hExtendWnd))
		{
			if (wParam) {
				CBrowser* pBrowserWnd = nullptr;
				HWND hPWnd = ::GetParent(m_hWnd);
				if (!m_bDevToolWnd)
				{
					auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hPWnd);
					if (it != g_pSpaceTelescope->m_mapBrowserWnd.end()) {
						pBrowserWnd = (CBrowser*)it->second;
						pBrowserWnd->m_pVisibleWebView = this;
					}
				}
				::ShowWindow(m_hExtendWnd, SW_SHOW);
				::SetParent(m_hExtendWnd, hPWnd);
				if (pBrowserWnd)
				{
					if (::GetParent(hPWnd) == nullptr)
					{
						pBrowserWnd->BrowserLayout();
						::PostMessage(hPWnd, WM_BROWSERLAYOUT, 0, 2);
					}
					else
					{
						if (pBrowserWnd->m_pParentXobj)
						{
							CNucleus* pGalaxy = pBrowserWnd->m_pParentXobj->m_pXobjShareData->m_pNucleus;
							WebRTFrameWndInfo* pInfo = pGalaxy->m_pWebRTFrameWndInfo;
							CCloudMDIFrame* pMainParent = nullptr;
							CXobj* pMDIClientObj = pBrowserWnd->m_pParentXobj->GetVisibleChildByName(_T("hostclient"));
							if (pInfo)
							{
								switch (pInfo->m_nFrameType)
								{
								case 2:
								{
									pMainParent = pBrowserWnd->m_pParentXobj->m_pXobjShareData->m_pNucleus->m_pMDIParent;
									auto it = g_pSpaceTelescope->m_mapMDIParent.find(::GetParent(pInfo->m_hClient));
									if (it != g_pSpaceTelescope->m_mapMDIParent.end())
									{
										pMainParent = it->second;
										if (pMDIClientObj)
										{
											g_pSpaceTelescope->ModifyBindingXobj(pMainParent->m_pMDINucleus, pMDIClientObj);
										}
										pBrowserWnd->m_pBrowser->LayoutBrowser();
										::PostMessage(pMainParent->m_hMDIClient, WM_COSMOSMSG, 0, 20180115);
									}
								}
								break;
								case 1:
									break;
								}
							}
							if (pMDIClientObj)
							{
								CNucleus* pNucleus = nullptr;
								if (pGalaxy->m_pParentMDIWinForm && pGalaxy->m_pParentMDIWinForm->m_pClientGalaxy)
								{
									pNucleus = pGalaxy->m_pParentMDIWinForm->m_pClientGalaxy;
								}
								else
								{
									pNucleus = pBrowserWnd->m_pParentXobj->m_pRootObj->m_pXobjShareData->m_pNucleus;
								}
								g_pSpaceTelescope->ModifyBindingXobj(pNucleus, pMDIClientObj);
							}
							if (pGalaxy->m_nGalaxyType != GalaxyType::CtrlBarGalaxy && pGalaxy->m_pWebViewWnd)
							{
								HWND hWnd = ::GetParent(pGalaxy->m_pWebViewWnd->m_hWnd);
								if (pMainParent == nullptr || pMainParent->m_bCreateNewDoc == false)
								{
									if (pBrowserWnd->m_pParentXobj->m_pParentWinFormWnd)
									{
										pGalaxy->m_pParentWinForm = pBrowserWnd->m_pParentXobj->m_pParentWinFormWnd;
										if (pGalaxy->m_pParentWinForm->m_bMdiForm)
											pGalaxy->m_pParentMDIWinForm = pGalaxy->m_pParentWinForm;
										CNucleus* pClientGalaxy = (CNucleus*)g_pSpaceTelescope->GetNucleus(pGalaxy->m_pParentWinForm->m_hMDIClient);
										if (pClientGalaxy && pGalaxy->m_pParentMDIWinForm)
										{
											pGalaxy->m_pParentMDIWinForm->m_pClientGalaxy = pClientGalaxy;
										}
									}
								}
								HWND hClient = NULL;
								if (pGalaxy->m_pParentMDIWinForm)
								{
									hClient = pGalaxy->m_pParentMDIWinForm->m_hMDIClient;
								}
								else
								{
									if (pGalaxy->m_pMDIParent)
										hClient = pGalaxy->m_pMDIParent->m_hMDIClient;
								}
								if (hClient)
									::PostMessage(hClient, WM_COSMOSMSG, 3, 20180115);
							}
							//20230308:
							::PostMessage(pBrowserWnd->m_hWnd, WM_BROWSERLAYOUT, 1, 7);
						}
					}
					for (auto it : m_mapAttachedForm)
					{
						if (::IsWindowVisible(it.first))
						{
							::PostMessage(it.second->m_hMDIClient, WM_COSMOSMSG, 0, 20180115);
							it.second->OnShowAllChild();
						}
					}
				}
			}
			else
			{
				::SetParent(m_hExtendWnd, m_hWnd);
			}
		}
		LRESULT lRes = DefWindowProc(uMsg, wParam, lParam);
		return lRes;
	}

	void CWebView::OnFinalMessage(HWND hWnd) {
		CBrowser* pPWnd = nullptr;
		auto it2 = g_pSpaceTelescope->m_mapBrowserWnd.find(::GetParent(hWnd));
		if (it2 != g_pSpaceTelescope->m_mapBrowserWnd.end())
		{
			pPWnd = (CBrowser*)it2->second;
			if (pPWnd->m_pVisibleWebView == this)
				pPWnd->m_pVisibleWebView = nullptr;
			auto it3 = pPWnd->m_mapChildPage.find(hWnd);
			if (it3 != pPWnd->m_mapChildPage.end())
			{
				pPWnd->m_mapChildPage.erase(it3);
			}
		}
		auto it = g_pSpaceTelescope->m_mapWebView.find(hWnd);
		if (it != g_pSpaceTelescope->m_mapWebView.end())
		{
			g_pSpaceTelescope->m_mapWebView.erase(it);
		}
		if (g_pSpaceTelescope->m_pActiveHtmlWnd == this)
			g_pSpaceTelescope->m_pActiveHtmlWnd = nullptr;
		CWindowImpl::OnFinalMessage(hWnd);
		delete this;
	}

	void CWebView::Show(CString strID2)
	{
		LONG_PTR data = 0;
		if (::IsWindow(m_hChildWnd))
			data = ::GetWindowLongPtr(m_hChildWnd, GWLP_USERDATA);

		if (data == 0 && g_pSpaceTelescope->m_pUniverseAppProxy)
		{
			if (::IsChild(m_hExtendWnd, m_hChildWnd))
			{
				auto it = g_pSpaceTelescope->m_mapNuclei.find(m_hExtendWnd);
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

				//m_strAppProxyID = _T("");
				//if (m_strAppProxyID != _T(""))
				//{
				//	m_pAppProxy = nullptr;
				//	auto it = g_pSpaceTelescope->m_mapWebRTAppProxy.find(m_strAppProxyID.MakeLower());
				//	if (it != g_pSpaceTelescope->m_mapWebRTAppProxy.end())
				//		m_pAppProxy = it->second;
				//	else
				//	{
				//		CString strPath = g_pSpaceTelescope->m_strAppPath;
				//		HMODULE hHandle = nullptr;
				//		CString strAppName = _T("");
				//		int nPos = m_strAppProxyID.Find(_T("."));
				//		if (nPos != -1)
				//			strAppName = m_strAppProxyID.Left(nPos);
				//		CString strdll = strPath + m_strAppProxyID + _T("\\") + strAppName + _T(".dll");
				//		if (::PathFileExists(strdll))
				//			hHandle = ::LoadLibrary(strdll);
				//		if (hHandle)
				//		{
				//			it = g_pSpaceTelescope->m_mapWebRTAppProxy.find(m_strAppProxyID.MakeLower());
				//			if (it != g_pSpaceTelescope->m_mapWebRTAppProxy.end())
				//			{
				//				m_pAppProxy = it->second;
				//			}
				//		}
				//	}
				//	if (m_pAppProxy)
				//	{
				//		g_pSpaceTelescope->m_pActiveAppProxy = m_pAppProxy;
				//		m_pAppProxy->m_hCreatingView = m_hChildWnd;
				//		::SetWindowText(m_hChildWnd, g_pSpaceTelescope->m_strAppKey);
				//	}
				//}
				//else
				{
					INucleus* pGalaxy = nullptr;
					m_pNuclei->CreateNucleus(CComVariant(0), CComVariant((LONGLONG)m_hChildWnd), CComBSTR(L"default"), &pGalaxy);
					if (pGalaxy)
					{
						m_pNucleus = (CNucleus*)pGalaxy;
						//m_pNuclei->m_mapNeedSaveGalaxy[m_hChildWnd] = m_pNucleus;
						IXobj* pXobj = nullptr;
						pGalaxy->Observe(CComBSTR("default"), CComBSTR(L""), &pXobj);
					}
				}
			}
		}
	}

	void CWebView::SendChromeIPCMessage(CString strId, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5)
	{
		if (m_pChromeRenderFrameHost != nullptr)
		{
			IPCMsg pIPCInfo;
			pIPCInfo.m_strId = strId;
			pIPCInfo.m_strParam1 = strParam1;
			pIPCInfo.m_strParam2 = strParam2;
			pIPCInfo.m_strParam3 = strParam3;
			pIPCInfo.m_strParam4 = strParam4;
			pIPCInfo.m_strParam5 = strParam5;
			m_pChromeRenderFrameHost->SendCosmosMessage(&pIPCInfo);
		}
		g_pSpaceTelescope->m_pCurrentIPCMsg = nullptr;
	}

	CChromeBrowserBase* CWebView::GetChromeBrowserBase(HWND hHostWnd)
	{
		return nullptr;
	}

	void CWebView::ObserveViewport(CString strName, CString strXML)
	{
		HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
		HWND hPPWnd = ::GetParent(hBrowser);
		CCloudMDTFrame* pMDTWnd = nullptr;
		CCloudMDIFrame* pMDIWnd = nullptr;
		CBrowser* pBrowserWnd = nullptr;
		auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
		if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
		{
			pBrowserWnd = (CBrowser*)it->second;

			if (pBrowserWnd->m_pBrowser->GetActiveWebContentWnd() != m_hWnd)
				::ShowWindow(m_hWnd, SW_HIDE);
			if (pBrowserWnd->m_pWebRTFrameWndInfo == nullptr)
			{
				WebRTInfo* pInfo = (WebRTInfo*)::GetProp(hPPWnd, _T("WebRTInfo"));
				if (pInfo)
				{
					pBrowserWnd->m_pParentXobj = (CXobj*)pInfo->m_pXobj;
				}
				if (pBrowserWnd->m_pParentXobj == nullptr) {
					pBrowserWnd->m_pParentXobj = (CXobj*)g_pSpaceTelescope->GetXobj(hPPWnd);
				}
				if (pBrowserWnd->m_pParentXobj) {
					HWND hPWnd = pBrowserWnd->m_pParentXobj->m_pXobjShareData->m_pNucleus->m_hWnd;
					hPWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(DocView, hPWnd);
					if (hPWnd)
					{
						pBrowserWnd->m_pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(hPWnd, _T("WebRTFrameWndInfo"));;
						switch (pBrowserWnd->m_pWebRTFrameWndInfo->m_nFrameType)
						{
						case 1:
						{
							auto it = g_pSpaceTelescope->m_mapMDTWindow.find(hPWnd);
							if (it != g_pSpaceTelescope->m_mapMDTWindow.end())
							{
								pMDTWnd = it->second;
								pMDTWnd->m_pBrowser = pBrowserWnd;
							}
						}
						break;
						case 2:
						{
							auto it = g_pSpaceTelescope->m_mapMDIParent.find(hPWnd);
							if (it != g_pSpaceTelescope->m_mapMDIParent.end())
							{
								it->second->m_pHostBrowser = pBrowserWnd;
								pMDIWnd = it->second;
							}
						}
						break;
						}
					}
				}
			}
		}
		if (m_pWebRTFrameWndInfo == nullptr && pBrowserWnd)
		{
			m_pWebRTFrameWndInfo = pBrowserWnd->m_pWebRTFrameWndInfo;
		}
		if (m_strAdditionalUrls == _T(""))
		{
			CTangramXmlParse m_Parse;
			if (m_Parse.LoadXml(strXML))
			{
				CTangramXmlParse* pUrlsParse = m_Parse.GetChild(_T("urls"));
				if (pUrlsParse)
				{
					m_strLoadingURLs = pUrlsParse->xml();

					if (m_strLoadingURLs != _T(""))
					{
						pBrowserWnd->m_bSZMode = true;
						m_bCanShow = false;
						pBrowserWnd->m_bInTabChange = true;
						//CString strUrls = _T("");
						int nCount = pUrlsParse->GetCount();
						for (int i = 0; i < nCount; i++)
						{
							CString strURL = pUrlsParse->GetChild(i)->attr(_T("url"), _T(""));
							int nPos2 = strURL.Find(_T(":"));
							if (nPos2 != -1)
							{
								CString strURLHeader = strURL.Left(nPos2);
								if (strURLHeader.CompareNoCase(_T("host")) == 0)
								{
									strURL = g_pSpaceTelescope->m_strAppPath + strURL.Mid(nPos2 + 1);
								}
							}
							if (strURL != _T(""))
							{
								m_strAdditionalUrls += strURL;
								if (i < nCount - 1)
									m_strAdditionalUrls += _T("|");
							}
						}
						if (g_pSpaceTelescope->m_nNativeAppType == 20 || g_pSpaceTelescope->m_nNativeAppType == 30) {
							//auto t = create_task([this]()
							//	{
							//		while (1)
							//		{
							//			Sleep(500);
							//			break;
							//		}
							//		return;
							//	});
							Sleep(500);
							::PostMessage(m_hWnd, WM_COSMOSMSG, 20210411, 0);
						}
						else if (m_strAdditionalUrls != _T(""))
						{
							g_pSpaceTelescope->m_nWaitTabCounts = nCount;
							g_pSpaceTelescope->m_hWaitTabWebPageWnd = m_hWnd;
							CString strDisposition = _T("");
							strDisposition.Format(_T("%d"), NEW_BACKGROUND_TAB);
							if (m_pChromeRenderFrameHost)
							{
								IPCMsg msg;
								msg.m_strId = L"ADD_URL";
								msg.m_strParam1 = m_strAdditionalUrls;
								msg.m_strParam2 = strDisposition;
								m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
							}
							::PostMessage(m_hWnd, WM_COSMOSMSG, 20210411, 1);
							m_strLoadingURLs = _T("");
						}
					}
				}
			}
		}
		if (m_pRemoteCosmos)
		{
			CString strInfo = _T("");
			strInfo.Format(_T("loaddocument2viewport:%I64d"), hPPWnd);
			CString strData = strName;
			strData += _T("|");
			strData += strXML;
			m_pRemoteCosmos->put_AppKeyValue(CComBSTR(strInfo), CComVariant(strData));
		}
		if (m_hExtendWnd == nullptr)
		{
			HWND hParent = NULL;
			if (::IsWindowVisible(m_hWnd))
				hParent = ::GetParent(m_hWnd);
			else
				hParent = m_hWnd;

			m_hExtendWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, hParent, NULL, theApp.m_hInstance, NULL);
			m_hChildWnd = ::CreateWindowEx(NULL, _T("Chrome Extended Window Class"), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 0, 0, m_hExtendWnd, (HMENU)1, theApp.m_hInstance, NULL);
			CExtendWnd* pExtendWnd = new CExtendWnd();
			pExtendWnd->m_pHostPage = this;
			pExtendWnd->SubclassWindow(m_hChildWnd);
			::SetWindowLongPtr(m_hExtendWnd, GWLP_USERDATA, (LONG_PTR)m_hChildWnd);
			::SetWindowLongPtr(m_hChildWnd, GWLP_USERDATA, (LONG_PTR)this);
		}
		if (m_hExtendWnd)
		{
			if (m_pNucleus == nullptr) {
				CNuclei* pNuclei = nullptr;
				auto it = g_pSpaceTelescope->m_mapNuclei.find(m_hExtendWnd);
				if (it != g_pSpaceTelescope->m_mapNuclei.end())
					pNuclei = (CNuclei*)it->second;
				else
				{
					pNuclei = new CComObject<CNuclei>();
					pNuclei->m_hWnd = m_hExtendWnd;
					g_pSpaceTelescope->m_mapNuclei[m_hExtendWnd] = pNuclei;

					for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
					{
						CNucleiProxy* pProxy = it.second->OnNucleiCreated(pNuclei);
						if (pProxy)
							pNuclei->m_mapNucleiProxy[it.second] = pProxy;
					}
				}
				if (pNuclei) {
					INucleus* pGalaxy = nullptr;
					pNuclei->CreateNucleus(CComVariant((__int64)0), CComVariant((__int64)m_hChildWnd), CComBSTR("nativeui"), &pGalaxy);
					if (pGalaxy)
					{
						m_pNucleus = (CNucleus*)pGalaxy;
						m_pNucleus->m_pWebViewWnd = this;
					}
				}
			}
			if (m_pNucleus)
			{
				if (pMDIWnd && m_pNucleus->m_pMDIParent == nullptr)
					m_pNucleus->m_pMDIParent = pMDIWnd;
				IXobj* pXobj = nullptr;
				CComBSTR bstrKey(strName);
				m_pNucleus->m_pWebViewWnd = this;
				m_pNucleus->Observe(bstrKey, CComBSTR(strXML), &pXobj);
				if (pXobj)
				{
					m_strCurKey = strName;
					m_hWebHostWnd = NULL;
					if (m_pNucleus->m_pBindingXobj)
					{
						m_hWebHostWnd = m_pNucleus->m_pBindingXobj->m_pHostWnd->m_hWnd;
					}
					CTangramXmlParse* pParse = ((CXobj*)pXobj)->m_pHostParse->m_pParentParse->m_pParentParse;
					CString str = _T("");
					if (pParse)
					{
						pParse = pParse->GetChild(_T("doctemplate"));
						if (pParse) {
							//::PostMessage(m_hWnd, WM_COSMOSMSG, 20230708, (LPARAM)pParse->m_pParentParse);
						}
					}
					if (pMDTWnd && pMDTWnd->m_bCreateNewMDTDoc)
					{
						::PostMessage(pMDTWnd->m_hWnd, WM_COSMOSMSG, 0, 20210328);
						return;
					}
				}
			}
		}

		g_pSpaceTelescope->m_mapSizingBrowser[hBrowser] = pBrowserWnd;
		if (hPPWnd == nullptr)
			pBrowserWnd->BrowserLayout();
		::PostMessage(hBrowser, WM_BROWSERLAYOUT, 0, 7);
	}

	void CWebView::HandleChromeIPCMessage(CString strId, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5)
	{
		if (strId.CompareNoCase(_T("RENDER_ELEMENT")) == 0)
		{
			CustomizedDOMElement(strParam1, strParam2);
		}
		else if (strId.CompareNoCase(_T("RELOADWEBPAGE")) == 0)
		{
			HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
			HWND hPPWnd = ::GetParent(hBrowser);
			if (hPPWnd == NULL && ::IsWindow(m_hExtendWnd) && m_pNucleus) {
				//m_bReloadModel = true;
				IXobj* pXobj = nullptr;
				m_pNucleus->Observe(CComBSTR("__default__key__for__chrome__"), CComBSTR(g_pSpaceTelescope->m_strDefaultXml), &pXobj);
				::SendMessage(hBrowser, WM_BROWSERLAYOUT, 0, 4);
				::SetParent(m_hExtendWnd, m_hWnd);
				::SetWindowPos(m_hExtendWnd, HWND_BOTTOM, 0, 0, 0, 0, SWP_SHOWWINDOW);
				//::PostMessage(m_hExtendWnd, WM_DESTROY, 0, 0);
				::DestroyWindow(m_hExtendWnd);
				m_hExtendWnd = NULL;
				m_pNucleus = nullptr;
				if (m_mapSubWinForm.size())
				{
					for (auto& it : m_mapSubWinForm)
					{
						::DestroyWindow(it.first);
					}
					m_mapSubWinForm.erase(m_mapSubWinForm.begin(), m_mapSubWinForm.end());
				}
				if (m_mapWinForm.size())
				{
					auto it = m_mapWinForm.find(g_pSpaceTelescope->m_hMainWnd);
					if (it != m_mapWinForm.end())
					{
						m_mapWinForm.erase(it);
					}
					while (m_mapWinForm.size())
					{
						auto it = m_mapWinForm.begin();
						CCloudWinForm* pForm = it->second;
						if (pForm->m_bMainForm == false)
						{
							if (::IsChild(pForm->m_hWnd, m_hWnd) || ::IsWindow(pForm->m_hWnd) == false)
							{
								m_mapWinForm.erase(it);
							}
							else
							{
								::DestroyWindow(pForm->m_hWnd);
							}
						}
						else
						{
							pForm->m_pOwnerHtmlWnd = nullptr;
							m_mapWinForm.erase(it);
						}
						if (m_mapWinForm.size() == 0)
							break;
					}
					m_mapWinForm.erase(m_mapWinForm.begin(), m_mapWinForm.end());
				}
			}
		}
		else if (strId.CompareNoCase(_T("AGGREGATED_MESSAGE")) == 0)
		{
			//HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
			//HWND hPPWnd = ::GetParent(hBrowser);
			//if (hPPWnd == NULL && ::IsWindow(m_hExtendWnd) && m_pNucleus) {
			//	m_bReloadModel = true;
			//}
			if (strParam2 == _T("1"))
				g_pSpaceTelescope->m_bCommercialEdition = true;
			else
				g_pSpaceTelescope->m_bCommercialEdition = false;
			HandleAggregatedMessage(strParam1, strParam2);
			if (g_pSpaceTelescope->m_pHostHtmlWnd == nullptr && g_pSpaceTelescope->m_strAppXml != _T(""))
			{
				if (g_pSpaceTelescope->m_pUniverseAppProxy)
					g_pSpaceTelescope->m_pUniverseAppProxy->OnWebAppData(this, g_pSpaceTelescope->m_strAppXml);
				g_pSpaceTelescope->m_pHostHtmlWnd = this;

				CTangramXmlParse m_Parse;
				if (m_Parse.LoadXml(g_pSpaceTelescope->m_strAppXml))
				{
					g_pSpaceTelescope->m_strAppName = m_Parse.attr(_T("appname"), _T("The Universe System"));
					m_strPageName = m_Parse.attr(_T("pagename"), _T("default"));
					CString _strCorlor = m_Parse.attr(_T("browserbkcorlor"), _T(""));
					if (!_strCorlor.IsEmpty())
					{
						int r, g, b;
						_stscanf_s(_strCorlor, _T("RGB(%d,%d,%d)"), &r, &g, &b);
						g_pSpaceTelescope->m_BrowserBKCorlor = RGB(r, g, b);
					}
					CTangramXmlParse* pParse = nullptr;
					pParse = m_Parse.GetChild(_T("modules"));
					if (pParse)
					{
						int nCount = pParse->GetCount();
						LONGLONG hHandle = 0;
						for (int i = 0; i < nCount; i++)
						{
							CTangramXmlParse* pCLRApp = pParse->GetChild(i);
							BSTR bstrAppXML = pCLRApp->xml().AllocSysString();
							g_pSpaceTelescope->InitCLRApp(bstrAppXML, &hHandle);
							::SysFreeString(bstrAppXML);
						}
					}

					pParse = m_Parse.GetChild(_T("ntp"));
					if (pParse)
						g_pSpaceTelescope->m_strNtpXml = m_Parse[_T("ntp")].xml();
					pParse = m_Parse.GetChild(_T("doctemplate"));
					if (pParse)
					{
						int nCount = pParse->GetCount();
						if (nCount)
						{
							for (int i = 0; i < nCount; i++)
							{
								CTangramXmlParse* pChild = pParse->GetChild(i);
								CString strName = pChild->name();
								CString strDefaultName = pChild->attr(_T("defaultname"), strName);
								CString strAppName = pChild->attr(_T("appname"), strName);
								g_pSpaceTelescope->m_mapDocAppName[strName] = strAppName;
								g_pSpaceTelescope->m_mapDocTemplate[strName] = pChild->xml();
								g_pSpaceTelescope->m_mapDocDefaultName[strName] = strDefaultName;
							}
							//20240315 modify:
							::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)g_pSpaceTelescope->m_hFirstView, 20210111);
						}
					}
					pParse = m_Parse.GetChild(_T("defaultworkbench"));
					if (pParse)
						g_pSpaceTelescope->m_strDefaultWorkBenchXml = m_Parse[_T("defaultworkbench")].xml();

					g_pSpaceTelescope->m_pMainWebPageImpl = this;
					pParse = m_Parse.GetChild(_T("urls"));
					if (pParse)
					{
						CString strUrls = _T("");
						int nCount = pParse->GetCount();
						for (int i = 0; i < nCount; i++)
						{
							CString strURL = pParse->GetChild(i)->attr(_T("url"), _T(""));
							int nPos2 = strURL.Find(_T(":"));
							if (nPos2 != -1)
							{
								CString strURLHeader = strURL.Left(nPos2);
								if (strURLHeader.CompareNoCase(_T("host")) == 0)
								{
									strURL = g_pSpaceTelescope->m_strAppPath + strURL.Mid(nPos2 + 1);
								}
							}
							if (strURL != _T(""))
							{
								strUrls += strURL;
								if (i < nCount - 1)
									strUrls += _T("|");
							}
						}
						if (strUrls != _T(""))
						{
							CString strDisposition = _T("");
							strDisposition.Format(_T("%d"), NEW_BACKGROUND_TAB);
							if (m_pChromeRenderFrameHost)
							{
								IPCMsg msg;
								msg.m_strId = L"ADD_URL";
								msg.m_strParam1 = strUrls;
								msg.m_strParam2 = strDisposition;
								m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
							}
						}
					}
				}

				//::MessageBox(NULL, m_strMainWndXml, L"", MB_OK);
				//::MessageBox(NULL, g_pSpaceTelescope->m_strAppXml, L"", MB_OK);
				CustomizedMainWindowElement(m_strMainWndXml);
			}
			if (m_strDocXml != _T(""))
			{
				CustomizedDocElement(m_strDocXml);
			}
		}
		else if (/*g_pSpaceTelescope->m_bCommercialEdition && */strId.CompareNoCase(_T("NTP_Msg")) == 0)
		{
			if (m_pChromeRenderFrameHost)
			{
				auto t = create_task([this]()
					{
						while (1)
						{
							Sleep(500);
							::PostMessage(m_hWnd, WM_COSMOSMSG, 20220816, 0);
							break;
						}
						return;
					});
			}
		}
		else if (strId.CompareNoCase(_T("TANGRAM_UI_MESSAGE")) == 0)
		{
			CString strKey = strParam1;
			int nPos = strKey.Find(_T(":"));
			if (nPos != -1)
			{
				CString strAppID = strKey.Left(nPos);
				strKey = strKey.Mid(nPos + 1);
				if (strKey != _T("")) {
					if (strAppID.CompareNoCase(_T("officeapp")) == 0)
					{
						g_pSpaceTelescope->CreateApplication(CComBSTR(strKey), CComBSTR(strParam3));
					}
					else if (strAppID.CompareNoCase(_T("WinApp")) == 0)
					{
						HWND g_hProcessWnd = NULL;
						CString g_strConfigPath = _T("");
						TCHAR m_szBuffer[MAX_PATH] = { 0 };
						memset(m_szBuffer, 0, sizeof(m_szBuffer));
						::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
						CString strWinAppProxy = CString(m_szBuffer);
						int nPos = strWinAppProxy.ReverseFind('\\');
						strWinAppProxy = strWinAppProxy.Left(nPos + 1) + _T("WebRTHelper.dll");

						CTangramXmlParse m_Parse;
						if (m_Parse.LoadXml(strKey))
						{
							CString strModel = m_Parse.attr(_T("runmodel"), _T(""));
							WebRTRunModel _mode = (WebRTRunModel)(_wtoi(strModel) % 4);
							if (_mode != WebRTRunModel::RunNormal) {
								CString strProcessPath = _T("");
								strProcessPath = m_Parse.attr(_T("apppath"), _T(""));
								if (strProcessPath == _T(""))
									return;
								CString strExeName = _T("");
								int nPos = -1;
								nPos = strProcessPath.ReverseFind('\\');
								if (nPos != -1)
								{
									strExeName = strProcessPath.Mid(nPos + 1);
								}
								else {
									strExeName = strProcessPath;
								}
								nPos = strExeName.ReverseFind('.');
								strExeName = strExeName.Left(nPos);
								strProcessPath.MakeLower();
								strProcessPath.Replace(_T("/"), _T("\\"));
								bool bRunOnly = m_Parse.attrBool(_T("runonly"), false);
								int nDelaySecond = m_Parse.attrInt(_T("delaytime"), 500);
								int nDelaySecond2 = m_Parse.attrInt(_T("delaytime2"), 1000);
								HANDLE hProcess = NULL;
								if (!bRunOnly) {
									auto itCfg = g_pSpaceTelescope->m_mapProcessConfig.find(strProcessPath);
									if (itCfg != g_pSpaceTelescope->m_mapProcessConfig.end())
										g_strConfigPath = itCfg->second;
									else {
										CString strConfigFile = _T("");
										CString strProductName = m_Parse.attr(_T("productname"), _T(""));
										if (strProductName == _T(""))
											strProductName = strExeName;
										CString strCompanyPathName = m_Parse.attr(_T("companypathname"), _T(""));
										if (strCompanyPathName == _T(""))
											strCompanyPathName = strExeName + _T(" team");
										strProductName.MakeLower();
										strCompanyPathName.MakeLower();

										HRESULT hr = SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, m_szBuffer);
										strConfigFile = m_szBuffer;
										strConfigFile += _T("\\");
										strConfigFile.Replace(_T("\\\\"), _T("\\"));
										strConfigFile += _T("TangramData\\");
										strConfigFile += strExeName;
										strConfigFile += _T("\\");
										strConfigFile.MakeLower();
										if (!::PathIsDirectory(strConfigFile))
											CreateDirectory(strConfigFile, NULL);
										CString strAppKey = g_pSpaceTelescope->ComputeHash(strConfigFile + _T("@") + strCompanyPathName + _T("@") + strProductName);
										strConfigFile += strAppKey;
										strConfigFile += _T("\\");
										if (!::PathIsDirectory(strConfigFile))
											CreateDirectory(strConfigFile, NULL);
										strConfigFile += strExeName;
										strConfigFile += _T(".tangram");
										g_pSpaceTelescope->m_mapProcessConfig[strProcessPath] = strConfigFile;
										g_strConfigPath = strConfigFile;
										if (!::PathFileExists(g_strConfigPath)) {
											m_Parse.SaveFile(g_strConfigPath);
										}
									}

									HWND hCosmosWnd = NULL;
									CTangramXmlParse _CfgXmlParse;
									if (::PathFileExists(g_strConfigPath)) {
										if (_CfgXmlParse.LoadFile(g_strConfigPath)) {
											hCosmosWnd = (HWND)_CfgXmlParse.attrInt64(_T("cosmoswindowhandle"), 0);
											DWORD g_dwMainThreadID = (DWORD)_CfgXmlParse.attrInt64(_T("mainThreadID"), 0);
											if (::IsWindow(hCosmosWnd)) {
												DWORD dwProcessID = 0;
												GetWindowThreadProcessId(hCosmosWnd, &dwProcessID);
												hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID);
												GetProcessImageFileNameW(hProcess, m_szBuffer, MAX_PATH);
												CString _strProcessPath = m_szBuffer;
												CString _strExeName = _T("");
												nPos = _strProcessPath.ReverseFind('\\');
												if (nPos != -1)
												{
													_strExeName = _strProcessPath.Mid(nPos + 1);
												}
												else {
													_strExeName = _strProcessPath;
												}
												nPos = _strExeName.ReverseFind('.');
												_strExeName = _strExeName.Left(nPos);

												if (_strExeName.CompareNoCase(strExeName) == 0) {
													auto it = g_pSpaceTelescope->m_mapProcessBindInfo.find(g_strConfigPath);
													if (it == g_pSpaceTelescope->m_mapProcessBindInfo.end())
													{
														g_hProcessWnd = CreateWindowEx(0, _T("WebRT Process Info"), g_strConfigPath, WS_CHILD | WS_CAPTION, 0, 0, 0, 0, g_pSpaceTelescope->m_hCosmosWnd, NULL, NULL, NULL);
														if (::IsWindow(g_hProcessWnd)) {
															::SetWindowLongPtr(g_hProcessWnd, GWLP_USERDATA, (LONG_PTR)hProcess);
															g_pSpaceTelescope->m_mapProcessBindInfo[g_strConfigPath] = g_hProcessWnd;
														}
													}
												}
												else
													hProcess = NULL;
											}
											else {
												_CfgXmlParse.put_attr(_T("cosmoswindowhandle"), _T(""));
												auto it = g_pSpaceTelescope->m_mapProcessBindInfo.find(g_strConfigPath);
												if (it != g_pSpaceTelescope->m_mapProcessBindInfo.end()) {
													g_pSpaceTelescope->m_mapProcessBindInfo.erase(it);
												}
											}
										}
									}
									auto it = g_pSpaceTelescope->m_mapProcessBindInfo.find(g_strConfigPath);
									if (it != g_pSpaceTelescope->m_mapProcessBindInfo.end())
									{
										g_hProcessWnd = it->second;
										hProcess = (HANDLE)::GetWindowLongPtr(g_hProcessWnd, GWLP_USERDATA);
									}
								}
								if (hProcess == NULL) {
									CString strExplorer = _T("EXPLORER.EXE");
									if (g_pSpaceTelescope->m_hWebRTToken == NULL) {
										if (!g_pSpaceTelescope->GetTokenByName(g_pSpaceTelescope->m_hWebRTToken, strExplorer.GetBuffer()))
										{
											return;
										}
										strExplorer.ReleaseBuffer();
									}
									HANDLE hTokenDup = NULL;
									bool bRet = DuplicateTokenEx(g_pSpaceTelescope->m_hWebRTToken, TOKEN_ALL_ACCESS, NULL, SecurityIdentification, TokenPrimary, &hTokenDup);
									STARTUPINFO startupInfo{};
									SECURITY_ATTRIBUTES saProcess{}, saThread{};
									PROCESS_INFORMATION process_info{};
									ZeroMemory(&startupInfo, sizeof(STARTUPINFO));
									ZeroMemory(&saThread, sizeof(SECURITY_ATTRIBUTES));
									ZeroMemory(&saProcess, sizeof(SECURITY_ATTRIBUTES));
									ZeroMemory(&process_info, sizeof(PROCESS_INFORMATION));
									CString strID = _T("WinSta0\\Default");
									startupInfo.lpDesktop = strID.GetBuffer();
									strID.ReleaseBuffer();
									startupInfo.cb = sizeof(STARTUPINFO);
									startupInfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_FORCEONFEEDBACK /*|STARTF_USEPOSITION*/;
									startupInfo.wShowWindow = SW_SHOWNORMAL;
									saProcess.nLength = sizeof(saProcess);
									saProcess.lpSecurityDescriptor = NULL;
									saProcess.bInheritHandle = true;
									saThread.nLength = sizeof(saThread);
									saThread.lpSecurityDescriptor = NULL;
									saThread.bInheritHandle = false;
									DWORD deCreateFlag = NORMAL_PRIORITY_CLASS;
									bool bResult = CreateProcessAsUser(hTokenDup, strProcessPath, NULL, &saProcess,
										&saThread, TRUE, deCreateFlag, NULL, NULL, &startupInfo, &process_info);

									if (!bResult) {
										if (!::PathFileExists(strProcessPath))
										{
											HRESULT hr = SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer);
											CString strCmd = m_szBuffer;
											strCmd += _T("\\") + strProcessPath;
											if (!::PathFileExists(strCmd)) {
												hr = SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, m_szBuffer);
												strCmd = m_szBuffer;
												strCmd += _T("\\") + strProcessPath;
											}
											if (!::PathFileExists(strCmd)) {
												int nPos = strProcessPath.ReverseFind('\\');
												if (nPos != -1)
												{
													strCmd = strCmd.Mid(nPos + 1);
												}
												::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
												CString strPathFile = m_szBuffer;
												nPos = strPathFile.ReverseFind('\\');
												strCmd = strPathFile.Left(nPos + 1) + strProcessPath;
											}
											if (::PathFileExists(strCmd)) {
												strProcessPath = strCmd;
											}
											else
												return;
										}
										bResult = CreateProcessAsUser(hTokenDup, strProcessPath, NULL, &saProcess,
											&saThread, FALSE, deCreateFlag, NULL, NULL, &startupInfo, &process_info);
										if (hTokenDup)
											CloseHandle(hTokenDup);
										if (!bResult)
											bResult = CreateProcess(strProcessPath, NULL, &saProcess,
												&saThread, FALSE, deCreateFlag, NULL, NULL, &startupInfo, &process_info);
									}
									//if (bRunOnly || _mode == WebRTRunModel::WebRTModel) {
									//	return;
									//}
									if (bResult)
									{
										if (g_pSpaceTelescope->IsWow64(process_info.hProcess) == FALSE)
										{
											CString strInitWebPage = _T("");
											CString strCosmosFilePath = _T("");
											strProcessPath.Replace(_T("/"), _T("\\"));
											nPos = strProcessPath.ReverseFind('\\');
											if (nPos != -1)
											{
												strCosmosFilePath = strProcessPath.Left(nPos + 1) + _T("cosmos.dll");
												nPos = strProcessPath.ReverseFind('.');
												strInitWebPage = strProcessPath.Left(nPos + 1) + _T("app.html");
											}
											if (::PathFileExists(strInitWebPage) && ::PathFileExists(strCosmosFilePath))
											{
												g_hProcessWnd = CreateWindowEx(0, _T("WebRT Process Info"), g_strConfigPath, WS_CHILD | WS_CAPTION, 0, 0, 0, 0, g_pSpaceTelescope->m_hCosmosWnd, NULL, NULL, NULL);
												HANDLE mainThread = process_info.hThread;
												DWORD mainThreadID = process_info.dwThreadId;
												m_Parse.put_attr(_T("mainThreadID"), (_int64)mainThreadID);
												::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
												CString strWebRTPath = m_szBuffer;
												m_Parse.put_attr(_T("webrtpath"), strWebRTPath);
												m_Parse.put_attr(_T("processinfownd"), (__int64)g_hProcessWnd);
												m_Parse.SaveFile(g_strConfigPath);
												//mt.exe -nologo -manifest  d:\AIGCAssistant\AIGCSDK\aigc.manifest -outputresource:D:\AIGCAssistant\WinFormsApp1.exe
												//mt.exe -nologo -manifest  d:\AIGCAssistant\AIGCSDK\aigc.manifest -updateresource:D:\AIGCAssistant\WinFormsMDIApp.exe
												::SetWindowLongPtr(g_hProcessWnd, GWLP_USERDATA, (LONG_PTR)process_info.hProcess);
												if (g_pSpaceTelescope->m_pWebRTMainDllLoader) {
													ProcessData _Data;
													ZeroMemory(&_Data, sizeof(ProcessData));
													_Data.m_hWnd = NULL;
													_Data.dwThreadID = process_info.dwThreadId;
													_Data.dwProcessID = process_info.dwProcessId;
													while (::IsWindow(_Data.m_hWnd) == false) {
														Sleep(500);
														EnumWindows(CUniverse::EnumProcessWindowsProc, (LPARAM)&_Data);
													}
													ProcessInfo* pProcessInfo = new ProcessInfo;
													pProcessInfo->processHandle = process_info.hProcess;
													pProcessInfo->processID = process_info.dwProcessId;
													pProcessInfo->threadID = process_info.dwThreadId;
													pProcessInfo->hWnd = _Data.m_hWnd;
													pProcessInfo->processProxyPath = strWinAppProxy;
													pProcessInfo->nDelaySecond = nDelaySecond;
													pProcessInfo->nDelaySecond2 = nDelaySecond2;
													::PostAppMessage(g_pSpaceTelescopeImpl->m_dwThreadID, WM_COSMOSMSG, (WPARAM)pProcessInfo, 20240327);
												}
												return;
											}
										}
									}
									else
									{
										bResult = GetLastError();
									}
								}
								else {
									//20240226 Very important:
									//Sleep(nDelaySecond2);
									if (g_pSpaceTelescope->m_pWebRTMainDllLoader) {
										g_pSpaceTelescope->m_pWebRTMainDllLoader->ExtendWinApp(hProcess, strWinAppProxy, nDelaySecond, nDelaySecond2);
									}
								}
							}
						}
					}
				}
				return;
			}
			// Param1: Frame Name, Param2: HWND, Param3: XML, Param4: BindWebObj Name
			HWND hWndSource = (HWND)_wtoi(LPCTSTR(strParam2));
			if (::IsWindow(hWndSource))
			{
				auto it = m_mapWinForm.find(hWndSource);
				if (it != m_mapWinForm.end())
				{
					ObserveViewport(strParam1, strParam3);
					return;
				}
				LRESULT lRes = ::SendMessage(hWndSource, WM_HUBBLE_DATA, 0, 20190214);
				if (lRes)
				{
					ObserveViewport(strParam2, strParam3);
					return;
				}
			}
			ObserveViewport(strParam1, strParam3);
		}
		else if (strId.CompareNoCase(_T("Client_UI_MESSAGE")) == 0)
		{
			HWND hMainWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(MainWnd, NULL);
			if (hMainWnd)
			{
				CTangramXmlParse xmlParse;
				if (xmlParse.LoadFile(strParam3))
				{
					WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
					HANDLE hHandle = ::GetProp(hMainWnd, _T("WebRTFrameWndInfo"));
					if (hHandle)
					{
						pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
						pWebRTFrameWndInfo->m_pWebView = this;
						pWebRTFrameWndInfo->m_strData = m_strMainWndXml;
						CTangramXmlParse* pParse = xmlParse.GetChild(_T("mainframe"));
						if (pParse)
						{
							CTangramXmlParse* pParseClient = pParse->GetChild(_T("client"));
							if (pParseClient)
							{
								HWND hClient = pWebRTFrameWndInfo->m_hClient; //0315
								CString strXml = pParseClient->xml();
								INuclei* pCluster = nullptr;
								if (pCluster == nullptr)
								{
									g_pSpaceTelescope->CreateNucleusGroup((__int64)::GetParent(hClient), &pCluster);
								}
								if (pCluster)
								{
									INucleus* pGalaxy = nullptr;
									CString strKey = _T("client");
									pCluster->CreateNucleus(CComVariant((__int64)::GetParent(hClient)), CComVariant((__int64)hClient), CComBSTR(strKey), &pGalaxy);
									if (pGalaxy)
									{
										CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
										_pGalaxy->m_pWebViewWnd = this;
										IXobj* pXobj = nullptr;
										_pGalaxy->Observe(CComBSTR(strParam1), CComBSTR(strXml), &pXobj);
									}
								}
							}
							pParse = pParse->GetChild(_T("controlbars"));
							if (pParse)
							{
								int nCount = pParse->GetCount();
								for (int i = 0; i < nCount; i++)
								{
									CTangramXmlParse* pParse2 = pParse->GetChild(i);
									int nBarID = pParse2->attrInt(_T("ctrlbarid"), 0);
									if (nBarID)
									{
										auto it = pWebRTFrameWndInfo->m_mapCtrlBarWnd.find(nBarID);
										if (it != pWebRTFrameWndInfo->m_mapCtrlBarWnd.end())
										{
											HWND hWnd = it->second;
											int nID = pParse2->attrInt(_T("clientid"), 0);
											CString strCaption = pParse2->attr(_T("caption"), _T(""));
											HWND hClient = ::GetDlgItem(hWnd, nID);
											if (hClient)
											{
												CString strXml = pParse2->xml();
												INuclei* pCluster = nullptr;
												if (pCluster == nullptr)
												{
													g_pSpaceTelescope->CreateNucleusGroup((__int64)hWnd, &pCluster);
												}
												if (pCluster)
												{
													if (strCaption != _T(""))
														::SetWindowText(::GetParent(hClient), strCaption);
													INucleus* pGalaxy = nullptr;
													CString strKey = _T("");
													strKey.Format(_T("ControlBar_%d"), nBarID);
													pCluster->CreateNucleus(CComVariant((__int64)::GetParent(hClient)), CComVariant((__int64)hClient), CComBSTR(strKey), &pGalaxy);
													if (pGalaxy)
													{
														CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
														_pGalaxy->m_pWebViewWnd = this;
														IXobj* pXobj = nullptr;
														_pGalaxy->Observe(CComBSTR(strParam1), CComBSTR(strXml), &pXobj);
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
			}
		}
		else
		{
			if (g_pSpaceTelescope->m_pUniverseAppProxy)
				g_pSpaceTelescope->m_pUniverseAppProxy->OnIPCMsg((CWebViewImpl*)this, strId, strParam1, strParam2, strParam3, strParam4, strParam5); // TODO: Missing parameters
			HWND hPPWnd = ::GetParent(::GetParent(m_hWnd));
			if (m_pRemoteCosmos)
			{
				CString strMsg = _T("");
				CString strMsgID = _T("");
				strMsg.Format(_T("%s@IPCMessage@%s@IPCMessage@%s@IPCMessage@%s@IPCMessage@%s@IPCMessage@%s"), strId, strParam1, strParam2, strParam3, strParam4, strParam5);
				strMsgID.Format(_T("HandleChromeIPCMessage:%I64d"), hPPWnd);
				m_pRemoteCosmos->put_AppKeyValue(CComBSTR(strMsgID), CComVariant(strMsg));
			}
		}
	}

	void CWebView::HandleAggregatedMessage(CString strParam1, CString strParam2)
	{
		int nTokenPos = 0;
		CString strToken = strParam1.Tokenize(_T("$$$"), nTokenPos);
		while (!strToken.IsEmpty())
		{
			// Process a single message.
			HandleSingleMessage(strToken);
			strToken = strParam1.Tokenize(_T("$$$"), nTokenPos);
		}
	}

	CString CWebView::FindToken(CString pszContent, CString pszDelimiter, int& nStart)
	{
		if (nStart == -1) {
			return _T("");
		}
		int nNextDelimiter = pszContent.Find(pszDelimiter, nStart);
		if (nNextDelimiter == -1)
		{
			CString pszToken = pszContent.Mid(nStart);
			nStart = -1;
			return pszToken;
		}
		else
		{
			int nCount = nNextDelimiter - nStart;
			CString pszToken = pszContent.Mid(nStart, nCount);
			nStart = nNextDelimiter + pszDelimiter.GetLength();
			if (nStart >= pszContent.GetLength()) {
				nStart = -1;
			}
			return pszToken;
		}
	}

	void CWebView::HandleSingleMessage(CString strParam)
	{
		int nStart = 0;
		CString strId = FindToken(strParam, _T("%%%"), nStart);
		CString strParam1 = FindToken(strParam, _T("%%%"), nStart);
		CString strParam2 = FindToken(strParam, _T("%%%"), nStart);
		CString strParam3 = FindToken(strParam, _T("%%%"), nStart);
		CString strParam4 = FindToken(strParam, _T("%%%"), nStart);
		CString strParam5 = FindToken(strParam, _T("%%%"), nStart);
		HandleChromeIPCMessage(strId, strParam1, strParam2, strParam3, strParam4, strParam5);
	}

	void CWebView::CustomizedDOMElement(CString strRuleName, CString strHTML)
	{
		if (strRuleName.CompareNoCase(_T("application")) == 0)
		{
			if (g_pSpaceTelescope->m_strAppXml == _T(""))
			{
				g_pSpaceTelescope->m_strAppXml = strHTML;
			}
			CTangramXmlParse m_Parse;
			if (m_Parse.LoadXml(strHTML))
			{
				m_strPageName = m_Parse.attr(_T("pagename"), _T("default"));
				if (g_pSpaceTelescope->m_bIsClrCoreApp == false)
					g_pSpaceTelescope->m_bIsClrCoreApp = m_Parse.attrBool(_T("dotnetapp"), false);
				CString CorePath = g_pSpaceTelescope->m_strProgramFilePath;
				CorePath += _T("\\dotnet\\shared\\Microsoft.NETCore.App\\");
				if (g_pSpaceTelescope->m_bIsClrCoreApp && ::PathIsDirectory(CorePath)) {
					g_pSpaceTelescope->m_strMiniClrCoreVer = m_Parse.attr(_T("minidotnetver"), _T("6.0.0.0"));
				}
				else {
					g_pSpaceTelescope->m_bIsClrCoreApp = false;
				}
			}
		}
		else if (strRuleName.CompareNoCase(_T("mainWindow")) == 0)
		{
			if (m_strMainWndXml == _T(""))
				m_strMainWndXml = strHTML;
		}
		else if (strRuleName.CompareNoCase(_T("WebPages")) == 0 || strRuleName.CompareNoCase(_T("TabGroup")) == 0)
		{
			CreateTabGroup(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("cloudWinform")) == 0)
		{
			CreateCloudForm(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("MDTDocTemplate")) == 0)
		{
			ProcessMDTDocTemplate(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("gridTemplate")) == 0)
		{
			CustomizedNodeDetailsElement(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("object")) == 0)
		{
			CustomizedObjectElement(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("data")) == 0)
		{
			CustomizedDataElement(strHTML);
		}
		else if (strRuleName.CompareNoCase(_T("NativeUI")) == 0)
		{
			m_strDocXml = strHTML;
		}
		else if (strRuleName.CompareNoCase(_T("extra")) == 0)
		{
			CustomizedExtraElement(strHTML);
		}
		else
		{
			g_pSpaceTelescope->m_pUniverseAppProxy->CustomizedDOMElement(m_hWnd, strRuleName, strHTML);
		}
	}

	void CWebView::CustomizedMainWindowElement(CString strHTML)
	{
		CBrowser* pBrowserWnd = nullptr;
		CCloudMDIFrame* pMdiParent = nullptr;
		if (m_pChromeRenderFrameHost)
		{
			HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
			auto itBrowser = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
			if (itBrowser != g_pSpaceTelescope->m_mapBrowserWnd.end())
			{
				pBrowserWnd = (CBrowser*)itBrowser->second;
				pBrowserWnd->m_bHostBrowser = true;
				::PostMessage(pBrowserWnd->m_hWnd, WM_COSMOSMSG, 20230331, 0);
			}
		}
		CTangramXmlParse xmlParse;
		if (xmlParse.LoadXml(strHTML))
		{
			CTangramXmlParse* urlsParse = xmlParse.GetChild(_T("urls"));
			CString strObjID = xmlParse.attr(_T("objid"), _T(""));
			IDispatch* pDisp = nullptr;
			int nPos = strObjID.Find(_T(","));
			if (strObjID != _T("") && nPos != -1)
			{
				if (g_pSpaceTelescope->m_pCLRProxy == nullptr)
					g_pSpaceTelescope->LoadCLR();
				if (g_pSpaceTelescope->m_pCLRProxy)
				{
					pBrowserWnd->m_bSZMode = true;
					m_bCanShow = false;					IWebView* pChromeWebPage = (IWebView*)this;
					xmlParse.put_attr(_T("webpage"), (__int64)pChromeWebPage);
					xmlParse.put_attr(_T("webpagehandle"), (__int64)m_hWnd);
					CWebViewImpl* pChromeRenderFrameHostProxyBase = (CWebViewImpl*)this;
					xmlParse.put_attr(_T("renderframehostproxy"), (__int64)pChromeRenderFrameHostProxyBase);
					xmlParse.put_attr(_T("IsMainCosmosWnd"), (__int64)1);
					g_pSpaceTelescope->m_nWaitTabCounts = 1;
					pDisp = g_pSpaceTelescope->m_pCLRProxy->CreateCLRObj(xmlParse.xml());
					if (pDisp) {
						HWND hwnd = g_pSpaceTelescope->m_pCLRProxy->GetCtrlHandle(pDisp);
						if (hwnd) {
							g_pSpaceTelescope->m_hMainWnd = hwnd;
							::SetParent(g_pSpaceTelescope->m_hCosmosWnd, hwnd);
						}
					}
					if (pBrowserWnd->m_pParentXobj)
					{
						if (pBrowserWnd->m_pParentXobj->m_pParentWinFormWnd)
						{
							pBrowserWnd->m_pParentXobj->m_pParentWinFormWnd->m_pBrowser = pBrowserWnd;
						}
					}
				}
			}
			if (pDisp == nullptr)
			{
				bool bRet = false;
				HWND hMainWnd = g_pSpaceTelescope->m_pUniverseAppProxy->QueryWndInfo(MainWnd, NULL);
				if (hMainWnd) {
					g_pSpaceTelescope->m_hMainWnd = hMainWnd;
					::SetParent(g_pSpaceTelescope->m_hCosmosWnd, hMainWnd);
				}
				else
					hMainWnd = g_pSpaceTelescope->m_pUniverseAppProxy->m_hMainWnd;
				WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
				auto it1 = g_pSpaceTelescope->m_mapMDIParent.find(hMainWnd);
				if (it1 != g_pSpaceTelescope->m_mapMDIParent.end())
				{
					pMdiParent = it1->second;
					bRet = true;
				}
				else
				{
					pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(hMainWnd, _T("WebRTFrameWndInfo"));
					if (pWebRTFrameWndInfo && pWebRTFrameWndInfo->m_nFrameType <= 1)
						bRet = true;
				}

				if (bRet)
				{
					theApp.m_bAppStarting = true;
					if (urlsParse) {
						m_strLoadingURLs = urlsParse->xml();
					}

					if (m_strLoadingURLs != _T(""))
					{
						pBrowserWnd->m_bSZMode = true;
						m_bCanShow = false;
						pBrowserWnd->m_bInTabChange = true;
						CString strUrls = _T("");
						int nCount = urlsParse->GetCount();
						for (int i = 0; i < nCount; i++)
						{
							CString strURL = urlsParse->GetChild(i)->attr(_T("url"), _T(""));
							int nPos2 = strURL.Find(_T(":"));
							if (nPos2 != -1)
							{
								CString strURLHeader = strURL.Left(nPos2);
								if (strURLHeader.CompareNoCase(_T("host")) == 0)
								{
									strURL = g_pSpaceTelescope->m_strAppPath + strURL.Mid(nPos2 + 1);
								}
							}
							if (strURL != _T(""))
							{
								strUrls += strURL;
								if (i < nCount - 1)
									strUrls += _T("|");
							}
						}
						if (strUrls != _T(""))
						{
							g_pSpaceTelescope->m_nWaitTabCounts = nCount;
							g_pSpaceTelescope->m_hWaitTabWebPageWnd = m_hWnd;
							CString strDisposition = _T("");
							strDisposition.Format(_T("%d"), NEW_BACKGROUND_TAB);
							if (m_pChromeRenderFrameHost)
							{
								IPCMsg msg;
								msg.m_strId = L"ADD_URL";
								msg.m_strParam1 = strUrls;
								msg.m_strParam2 = strDisposition;
								m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
							}
						}
						if (m_pChromeRenderFrameHost && pBrowserWnd->m_pParentXobj)
						{
							CWormhole* pSession = pBrowserWnd->m_pParentXobj->m_pWormhole;
							if (pSession)
							{
								pSession->InsertString(_T("msgID"), L"WebRuntimeOnInitApplication");
								pSession->SendMessage();
							}
						}
					}
					m_strLoadingURLs = _T("");
				}
				if (pMdiParent)
				{
					if (hMainWnd)
					{
						INuclei* pCluster = nullptr;
						WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
						HANDLE hHandle = ::GetProp(hMainWnd, _T("WebRTFrameWndInfo"));
						if (hHandle)
						{
							pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
							pWebRTFrameWndInfo->m_pWebView = this;
							m_pWebRTFrameWndInfo = pWebRTFrameWndInfo;
							CCloudMDIChild* pChild = nullptr;
							pBrowserWnd->m_pWebRTFrameWndInfo = m_pWebRTFrameWndInfo;
							pBrowserWnd->m_pMDIParent = pMdiParent;
							pMdiParent->m_pHostBrowser = pBrowserWnd;
							pMdiParent->m_pWebRTFrameWndInfo = pWebRTFrameWndInfo;
							CTangramXmlParse* pParse = xmlParse.GetChild(_T("doctemplate"));
							if (pParse)
							{
								int nCount = pParse->GetCount();
								if (nCount)
								{
									for (int i = 0; i < nCount; i++)
									{
										CTangramXmlParse* pChild = pParse->GetChild(i);
										CString strName = pChild->name();
										CString strDefaultName = pChild->attr(_T("defaultname"), strName);
										CString strAppName = pChild->attr(_T("appname"), strName);
										pMdiParent->m_mapDocAppName[strName] = strAppName;
										pMdiParent->m_mapDocTemplate[strName] = pChild->xml();
										pMdiParent->m_mapDocDefaultName[strName] = strDefaultName;
									}
									if (pMdiParent->m_mapMDIChild.size())
									{
										pChild = pMdiParent->m_mapMDIChild.begin()->second;
									}
								}
							}

							RECT rc;
							::GetClientRect(pWebRTFrameWndInfo->m_hClient, &rc);
							::SetWindowPos(pBrowserWnd->m_hWnd, nullptr, 0, 0, rc.right, rc.bottom, SWP_DRAWFRAME);
							pWebRTFrameWndInfo->m_strData = m_strMainWndXml;

							CString strWndXml = _T("");
							CString strTemplateID = _T("");
							CString strMainClient = _T("");
							if (g_pSpaceTelescope->m_pUniverseAppProxy->m_nShellCmd == CCommandLineInfo::FileNothing)
							{
								strTemplateID = _T("mainclient");
							}
							else
							{
								if (pChild)
								{
									strTemplateID = pChild->m_strDocTemplateKey;
								}
								if (strTemplateID == _T(""))
									strTemplateID = xmlParse.attr(_T("initdocid"), _T("default"));
								if (pMdiParent)
								{
									auto itDoc = pMdiParent->m_mapDocTemplate.find(_T("mainclient"));
									if (itDoc != pMdiParent->m_mapDocTemplate.end())
										strMainClient = itDoc->second;
								}
							}
							CString strTemplate = _T("");
							auto itDoc = pMdiParent->m_mapDocTemplate.find(strTemplateID);
							if (itDoc != pMdiParent->m_mapDocTemplate.end())
							{
								strTemplate = itDoc->second;
								if (strTemplate != _T(""))
								{
									CTangramXmlParse m_DocParse, m_DocParse2;
									CString strWebPage = _T("");
									bool bNeedClientInfo = false;
									if (strMainClient != _T(""))
										bNeedClientInfo = m_DocParse2.LoadXml(strMainClient);
									if (m_DocParse.LoadXml(strTemplate))
									{
										CTangramXmlParse* pParse = m_DocParse.GetChild(_T("hostpage"));
										if (pParse)
										{
											strWebPage = pParse->xml();
											if (bNeedClientInfo)
											{
												CTangramXmlParse* pParse = m_DocParse2.GetChild(_T("hostpage"));
												pMdiParent->m_mapClientCtrlBarData[_T("hostpage")] = pParse->xml();;
											}
											ObserveViewport(strTemplateID, strWebPage);
										}
										CString strCaption = xmlParse.attr(_T("caption"), _T(""));
										if (strCaption != _T("") && pMdiParent->m_mapDocAppName.size())
										{
											auto it2 = pMdiParent->m_mapDocAppName.find(strTemplateID);
											g_pSpaceTelescope->m_pUniverseAppProxy->SetFrameCaption(hMainWnd, strCaption, it2->second);
										}
										CTangramXmlParse* pParseClient = nullptr;
										if (pWebRTFrameWndInfo->m_nFrameType == 2)
											pParseClient = m_DocParse.GetChild(_T("mdiclient"));
										else
											pParseClient = m_DocParse.GetChild(_T("client"));
										if (pParseClient)
										{
											HWND hClient = pWebRTFrameWndInfo->m_hClient;
											if (pWebRTFrameWndInfo->m_nFrameType != 2)
											{
												CTangramXmlParse* pClient = m_DocParse.GetChild(_T("framescript"));
												if (pClient) {
													if (g_pSpaceTelescope->m_pUniverseAppProxy) {
														//g_pSpaceTelescope->m_pUniverseAppProxy->GetFrameClientHandle(pWebRTFrameWndInfo->m_pHostWnd->)
													}
												}
											}
											CString strXml = pParseClient->xml();
											if (bNeedClientInfo)
											{
												CTangramXmlParse* pParse = m_DocParse2.GetChild(_T("mdiclient"));
												pMdiParent->m_mapClientCtrlBarData[_T("client")] = pParse->xml();;
											}
											if (pCluster == nullptr)
											{
												g_pSpaceTelescope->CreateNucleusGroup((__int64)::GetParent(hClient), &pCluster);
											}
											if (pCluster)
											{
												INucleus* pGalaxy = nullptr;//0315
												CString strKey = _T("client");
												pCluster->CreateNucleus(CComVariant((__int64)::GetParent(hClient)), CComVariant((__int64)hClient), CComBSTR(strKey), &pGalaxy);
												if (pGalaxy)
												{
													CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
													pWebRTFrameWndInfo->m_mapCtrlBarNucleus[10000] = _pGalaxy;
													_pGalaxy->m_pWebViewWnd = this;
													if (pWebRTFrameWndInfo->m_nFrameType == 2)
													{
														IXobj* pXobj = nullptr;
														_pGalaxy->Observe(CComBSTR(strTemplateID), CComBSTR(strXml), &pXobj);
													}
												}
											}
										}
										pParse = m_DocParse.GetChild(_T("controlbars"));
										CTangramXmlParse* pParseControlBars = nullptr;
										if (bNeedClientInfo)
										{
											pParseControlBars = m_DocParse2.GetChild(_T("controlbars"));
										}
										if (pParse)
										{
											int nCount = pParse->GetCount();
											for (int i = 0; i < nCount; i++)
											{
												CTangramXmlParse* pParse2 = pParse->GetChild(i);
												CTangramXmlParse* pCtrlBarParse2 = nullptr;
												if (pParseControlBars)
													pCtrlBarParse2 = pParseControlBars->GetChild(i);
												int nBarID = pParse2->attrInt(_T("ctrlbarid"), 0);
												if (nBarID)
												{
													auto it = m_pWebRTFrameWndInfo->m_mapCtrlBarWnd.find(nBarID);
													if (it != m_pWebRTFrameWndInfo->m_mapCtrlBarWnd.end())
													{
														HWND hWnd = it->second;
														int nID = pParse2->attrInt(_T("clientid"), 0);
														HWND hClient = ::GetDlgItem(hWnd, nID);
														if (hClient)
														{
															CString strXml = pParse2->xml();
															if (pCluster)
															{
																INucleus* pGalaxy = nullptr;
																CString strKey = _T("");
																strKey.Format(_T("ControlBar_%d"), nBarID);
																if (bNeedClientInfo && pCtrlBarParse2)
																{
																	pMdiParent->m_mapClientCtrlBarData[strKey.MakeLower()] = pCtrlBarParse2->xml();;
																}

																pCluster->CreateNucleus(CComVariant((__int64)::GetParent(hClient)), CComVariant((__int64)hClient), CComBSTR(strKey), &pGalaxy);
																if (pGalaxy)
																{
																	CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
																	m_pWebRTFrameWndInfo->m_mapCtrlBarNucleus[nBarID] = _pGalaxy;
																	_pGalaxy->m_pWebViewWnd = this;
																	IXobj* pXobj = nullptr;
																	_pGalaxy->Observe(CComBSTR(strTemplateID), CComBSTR(strXml), &pXobj);
																}
																CString strCaption = pParse2->attr(_T("caption"), _T(""));
																if (strCaption != _T(""))
																	::SetWindowText(::GetParent(hClient), strCaption);
															}
														}
													}
												}

											}
										}
										if (pMdiParent && pChild && pChild->m_pMDIChildNucleus == nullptr)
										{
											::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)pChild->m_hMDIChildClient, 20210110);
										}
										if (pBrowserWnd->m_pClientGalaxy == nullptr)
										{
											if (m_pWebRTFrameWndInfo)
											{
												HWND hClient = m_pWebRTFrameWndInfo->m_hClient;
												INucleus* pGalaxy = nullptr;
												g_pSpaceTelescope->GetNucleus((__int64)hClient, &pGalaxy);
												if (pGalaxy)
												{
													pBrowserWnd->m_pClientGalaxy = (CNucleus*)pGalaxy;
												}
											}
										}
										if (g_pSpaceTelescope->m_pUniverseAppProxy->m_nShellCmd != CCommandLineInfo::FileNothing)
										{
										}
										else
											theApp.m_bAppStarting = false;
									}
								}
							}
						}
					}
				}
				else if (g_pSpaceTelescope->m_pMainWnd || g_pSpaceTelescope->m_bIsDlgApp)
				{
					CTangramXmlParse* pDlgItemsXmlParse = NULL;
					pDlgItemsXmlParse = xmlParse.GetChild(_T("dlgitems"));
					if (pDlgItemsXmlParse == nullptr)
						pDlgItemsXmlParse = xmlParse.GetChild(_T("ctrlitems"));
					if (pDlgItemsXmlParse)
					{
						CNuclei* m_pNuclei = nullptr;
						int nCount = pDlgItemsXmlParse->GetCount();
						for (int i = 0; i < nCount; i++)
						{
							CTangramXmlParse* pChild = pDlgItemsXmlParse->GetChild(i);
							int nID = pChild->attrInt(_T("ctrlid"), 0);
							HWND hDlgItem = ::GetDlgItem(g_pSpaceTelescope->m_hMainWnd, nID);
							if (::IsWindow(hDlgItem) == false)
								hDlgItem = ::GetDlgItem(g_pSpaceTelescope->m_hMainWnd, AFX_IDW_PANE_FIRST);
							if (::IsWindow(hDlgItem))
							{
								CString strName = pChild->name().MakeLower();
								if (m_pNuclei == nullptr)
								{
									m_pNuclei = new CComObject<CNuclei>();
									m_pNuclei->m_hWnd = g_pSpaceTelescope->m_hMainWnd;
									g_pSpaceTelescope->m_mapNuclei[g_pSpaceTelescope->m_hMainWnd] = m_pNuclei;

									for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
									{
										CNucleiProxy* pWebRTProxy = it.second->OnNucleiCreated(m_pNuclei);
										if (pWebRTProxy)
											m_pNuclei->m_mapNucleiProxy[it.second] = pWebRTProxy;
									}
								}
								INucleus* pGalaxy = nullptr;
								m_pNuclei->CreateNucleus(CComVariant((LONGLONG)g_pSpaceTelescope->m_hMainWnd), CComVariant((LONGLONG)hDlgItem), CComBSTR(L"default"), &pGalaxy);
								if (pGalaxy)
								{
									CNucleus* m_pNucleus = (CNucleus*)pGalaxy;
									CString strKey = _T("default");
									IXobj* pXobj = nullptr;
									pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pChild->xml()), &pXobj);
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
				else
				{
					if (pWebRTFrameWndInfo == NULL)
					{
						if (g_pSpaceTelescope->m_pUniverseAppProxy->m_hMainWnd) {
							g_pSpaceTelescope->m_hMainWnd = g_pSpaceTelescope->m_pUniverseAppProxy->m_hMainWnd;
							::SetParent(g_pSpaceTelescope->m_hCosmosWnd, g_pSpaceTelescope->m_hMainWnd);
						}
						CTangramXmlParse* pCtrlItemsXmlParse = xmlParse.GetChild(_T("ctrlitems"));
						if (pCtrlItemsXmlParse == NULL)
							pCtrlItemsXmlParse = xmlParse.GetChild(_T("dlgitems"));
						if (pCtrlItemsXmlParse)
						{
							CNuclei* m_pNuclei = nullptr;
							int nCount = pCtrlItemsXmlParse->GetCount();
							for (int i = 0; i < nCount; i++)
							{
								CTangramXmlParse* pChild = pCtrlItemsXmlParse->GetChild(i);
								CString strName = pChild->name().MakeLower();
								if (strName == _T("mainclient"))
								{
									CString strXml = pChild->xml();
									g_pSpaceTelescope->m_pUniverseAppProxy->OnCustomizedMainWindowElement(g_pSpaceTelescope->m_hMainWnd, strXml);
								}
								int nID = pChild->attrInt(_T("ctrlid"), 0);
								HWND hDlgItem = ::GetDlgItem(g_pSpaceTelescope->m_hMainWnd, nID);
								if (::IsWindow(hDlgItem))
								{
									if (m_pNuclei == nullptr)
									{
										m_pNuclei = new CComObject<CNuclei>();
										m_pNuclei->m_hWnd = g_pSpaceTelescope->m_hMainWnd;
										g_pSpaceTelescope->m_mapNuclei[g_pSpaceTelescope->m_hMainWnd] = m_pNuclei;

										for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
										{
											CNucleiProxy* pWebRTProxy = it.second->OnNucleiCreated(m_pNuclei);
											if (pWebRTProxy)
												m_pNuclei->m_mapNucleiProxy[it.second] = pWebRTProxy;
										}
									}
									INucleus* pGalaxy = nullptr;
									m_pNuclei->CreateNucleus(CComVariant((LONGLONG)g_pSpaceTelescope->m_hMainWnd), CComVariant((LONGLONG)hDlgItem), CComBSTR(L"default"), &pGalaxy);
									if (pGalaxy)
									{
										CNucleus* m_pNucleus = (CNucleus*)pGalaxy;
										CString strKey = _T("default");
										IXobj* pXobj = nullptr;
										pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pChild->xml()), &pXobj);
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
					else
					{
						CString strExt = xmlParse.attr(_T("ext"), _T(""));
						CString strDocID = xmlParse.attr(_T("docid"), _T("default"));
						g_pSpaceTelescope->m_pUniverseAppProxy->OpenDocFile(_T(""), strExt, strDocID);
					}
				}
				if (bRet)
				{
					if (urlsParse)
						::PostMessage(m_hWnd, WM_COSMOSMSG, 20210411, 1);
					else
					{
						::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)m_hWnd, 20210418);
					}
					return;
				}
			}
			if (urlsParse)
			{
				theApp.m_bAppStarting = true;
				m_strLoadingURLs = urlsParse->xml();
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)m_hWnd, 20210411);
			}
			else
			{
				::PostAppMessage(::GetCurrentThreadId(), WM_COSMOSMSG, (WPARAM)m_hWnd, 20210418);
			}
		}
	}

	void CWebView::CreateCloudForm(CString strHTML)
	{
		CTangramXmlParse xmlParse;
		if (xmlParse.LoadXml(strHTML))
		{
			CTangramXmlParse* pMdiChildXmlParse = xmlParse.GetChild(_T("mdichild"));
			if (pMdiChildXmlParse)
			{
				int nCount = pMdiChildXmlParse->GetCount();
				if (nCount)
				{
					CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
					g_pSpaceTelescope->m_pCurMDIChildFormInfo = pInfo;
					for (int i = 0; i < nCount; i++)
					{
						CString strName = pMdiChildXmlParse->GetChild(i)->name().MakeLower();
						CWebViewImpl* pChromeRenderFrameHostProxyBase = (CWebViewImpl*)this;
						pMdiChildXmlParse->GetChild(i)->put_attr(_T("renderframehostproxy"), (__int64)pChromeRenderFrameHostProxyBase);
						IWebView* pChromeWebPage = (IWebView*)this;
						pMdiChildXmlParse->GetChild(i)->put_attr(_T("webpage"), (__int64)pChromeWebPage);
						pMdiChildXmlParse->GetChild(i)->put_attr(_T("webpagehandle"), (__int64)m_hWnd);
						pMdiChildXmlParse->GetChild(i)->put_attr(_T("mdichild"), true);
						pInfo->m_mapFormsInfo[strName] = pMdiChildXmlParse->GetChild(i)->xml();
					}
				}
			}
			if (g_pSpaceTelescope->m_pCLRProxy == nullptr)
				g_pSpaceTelescope->LoadCLR();
			if (g_pSpaceTelescope->m_pCLRProxy)
			{
				CWebViewImpl* pProxyBase = (CWebViewImpl*)this;
				xmlParse.put_attr(_T("renderframehostproxy"), (__int64)pProxyBase);
				IWebView* pChromeWebPage = (IWebView*)this;
				xmlParse.put_attr(_T("webpage"), (__int64)pChromeWebPage);
				xmlParse.put_attr(_T("webpagehandle"), (__int64)m_hWnd);
				IDispatch* pDisp = g_pSpaceTelescope->m_pCLRProxy->CreateCLRObj(xmlParse.xml());
			}
		}
	}

	void CWebView::ProcessMDTDocTemplate(CString strHTML)
	{
		if (g_pSpaceTelescope->m_pCreatingFrameWnd) {
			CTangramXmlParse xmlParse;
			if (xmlParse.LoadXml(strHTML))
			{
				CCloudMDTFrame* pFrameWnd = g_pSpaceTelescope->m_pCreatingFrameWnd;
				g_pSpaceTelescope->m_pCreatingFrameWnd = nullptr;
				HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
				CBrowser* pBrowser = NULL;
				auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
				if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
				{
					pBrowser = (CBrowser*)it->second;
				}
				CNuclei* pNuclei = nullptr;
				WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(pFrameWnd->m_hWnd, _T("WebRTFrameWndInfo"));
				INucleus* pGalaxy = nullptr;
				IXobj* _pXobj = nullptr;
				int nViewSize = pFrameWnd->m_mapView.size();
				CString strKey = xmlParse.attr(_T("docid"), _T("default"));
				CTangramXmlParse* pClients = xmlParse.GetChild(_T("clients"));
				if (pClients == nullptr) {
					CTangramXmlParse* pClient = xmlParse.GetChild(_T("client"));
					int nClientIndex = xmlParse.attrInt(_T("clientid"));
					if (nViewSize > 0)
						nClientIndex = nClientIndex % nViewSize;
					pNuclei = new CComObject<CNuclei>();
					pNuclei->m_hWnd = pFrameWnd->m_hWnd;
					g_pSpaceTelescope->m_mapNuclei[pFrameWnd->m_hWnd] = pNuclei;

					for (auto& it2 : g_pSpaceTelescope->m_mapWebRTAppProxy)
					{
						CNucleiProxy* pWebRTProxy = it2.second->OnNucleiCreated(pNuclei);
						if (pWebRTProxy)
							pNuclei->m_mapNucleiProxy[it2.second] = pWebRTProxy;
					}
					if (pClient)
					{
						__int64 nClientHandle = (__int64)pFrameWnd->m_hMDTClient;
						if (nClientIndex) {
							auto it = pFrameWnd->m_mapView.find(nClientIndex);
							if (it != pFrameWnd->m_mapView.end())
								nClientHandle = (__int64)it->second;
						}
						pNuclei->CreateNucleus(CComVariant((__int64)pFrameWnd->m_hWnd), CComVariant(nClientHandle), CComBSTR(""), &pGalaxy);
						if (pGalaxy)
						{
							CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
							_pGalaxy->m_strDocTemplateID = strKey;
							_pGalaxy->m_pWebViewWnd = this;
							if (pBrowser)
								_pGalaxy->m_pHostWebBrowserWnd = pBrowser;
							pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pClient->xml()), &_pXobj);
							if (_pXobj) {
								CTangramXmlParse* pCtrlItemsXmlParse = pClient->GetChild(_T("ctrlitems"));
								if (pCtrlItemsXmlParse)
								{
									int nCount = pCtrlItemsXmlParse->GetCount();
									for (int i = 0; i < nCount; i++)
									{
										CTangramXmlParse* pChild = pCtrlItemsXmlParse->GetChild(i);
										//CString strName = pChild->name().MakeLower();
										int nID = pChild->attrInt(_T("ctrlid"), 0);
										HWND hDlgItem = ::GetDlgItem((HWND)nClientHandle, nID);
										if (::IsWindow(hDlgItem))
										{
											INucleus* pGalaxy = g_pSpaceTelescope->GetNucleus(hDlgItem);
											if (pGalaxy == NULL) {
												pNuclei->CreateNucleus(CComVariant((LONGLONG)nClientHandle), CComVariant((LONGLONG)hDlgItem), CComBSTR(L"default"), &pGalaxy);
												if (pGalaxy)
												{
													IXobj* pXobj = nullptr;
													pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pChild->xml()), &pXobj);
												}
											}
										}
									}
								}
							}
						}
					}
				}
				else
				{
					int nCount = pClients->GetCount();
					if (nCount) {
						for (int i = 0; i < nCount; i++) {
							CTangramXmlParse* pChildClient = pClients->GetChild(i);
							int nViewID = pChildClient->attrInt(_T("clientid"));
							if (nViewSize > 0)
								nViewID = nViewID % nViewSize;
							auto it = pFrameWnd->m_mapView.find(nViewID);
							if (it != pFrameWnd->m_mapView.end())
							{
								__int64 nClientHandle = (__int64)it->second;

								INucleus* pGalaxy = g_pSpaceTelescope->GetNucleus(it->second);
								if (pGalaxy == NULL) {
									pNuclei->CreateNucleus(CComVariant((__int64)pFrameWnd->m_hWnd), CComVariant(nClientHandle), CComBSTR(""), &pGalaxy);
									if (pGalaxy)
									{
										CNucleus* _pGalaxy = (CNucleus*)pGalaxy;
										_pGalaxy->m_strDocTemplateID = strKey;
										_pGalaxy->m_pWebViewWnd = this;
										if (pBrowser)
											_pGalaxy->m_pHostWebBrowserWnd = pBrowser;
										pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pChildClient->xml()), &_pXobj);
										if (_pXobj) {
											CTangramXmlParse* pCtrlItemsXmlParse = pChildClient->GetChild(_T("ctrlitems"));
											if (pCtrlItemsXmlParse)
											{
												int nCount = pCtrlItemsXmlParse->GetCount();
												for (int i = 0; i < nCount; i++)
												{
													CTangramXmlParse* pChild = pCtrlItemsXmlParse->GetChild(i);
													//CString strName = pChild->name().MakeLower();
													int nID = pChild->attrInt(_T("ctrlid"), 0);
													HWND hDlgItem = ::GetDlgItem(it->second, nID);
													if (::IsWindow(hDlgItem))
													{
														INucleus* pGalaxy = g_pSpaceTelescope->GetNucleus(hDlgItem);
														if (pGalaxy == NULL) {
															pNuclei->CreateNucleus(CComVariant((LONGLONG)it->second), CComVariant((LONGLONG)hDlgItem), CComBSTR(L"default"), &pGalaxy);
															if (pGalaxy)
															{
																IXobj* pXobj = nullptr;
																pGalaxy->Observe(CComBSTR(strKey), CComBSTR(pChild->xml()), &pXobj);
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
					}
				}
			}
		}
	}

	void CWebView::CreateTabGroup(CString strHTML)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strHTML))
		{
			CString strUrls = _T("");
			int nCount = m_Parse.GetCount();
			if (nCount > 0)
			{
				for (int i = 0; i < nCount; i++)
				{
					CString strUrl = m_Parse.GetChild(i)->attr(_T("url"), _T("chrome://newtab"));
					int nPos2 = strUrl.Find(_T(":"));
					if (nPos2 != -1)
					{
						CString strURLHeader = strUrl.Left(nPos2);
						if (strURLHeader.CompareNoCase(_T("host")) == 0)
						{
							strUrl = g_pSpaceTelescope->m_strAppPath + strUrl.Mid(nPos2 + 1);
						}
					}
					strUrls = strUrls + strUrl + _T("|");
				}
			}
			else
			{
				strUrls = _T("chrome://newtab|");
			}

			HWND hBrowser = g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(NULL, strUrls);
			bool bTopMost = m_Parse.attrBool(_T("topmost"));
			if (bTopMost)
			{
				::PostAppMessage(g_pSpaceTelescope->m_dwThreadID, WM_COSMOSMSG, (WPARAM)hBrowser, 20240603);
			}
		}
	}

	void CWebView::CustomizedNodeDetailsElement(CString strHTML)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strHTML))
		{
			CString strType = m_Parse.attr(_T("type"), _T(""));
			CString strUiKey = m_Parse.attr(_T("uikey"), _T("")).MakeLower();
			if (strUiKey != _T(""))
			{
				if (strType.CompareNoCase(_T("winform")) == 0)
				{
					m_mapFormsInfo[strUiKey] = m_Parse.xml();
				}
			}
		}
	}

	void CWebView::CustomizedObjectElement(CString strHTML)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strHTML))
		{
			CString strType = m_Parse.attr(_T("type"), _T(""));
			if (strType.CompareNoCase(_T("winform")) == 0)
			{
				CString strStartup = _T("");
				CTangramXmlParse* pChild3 = m_Parse.GetChild(_T("mdichild"));
				CString strID = m_Parse.attr(_T("uikey"), _T("")).MakeLower();
				CString strName = m_Parse.name();
				if (strID != _T(""))
				{
					m_mapFormsInfo[strID] = m_Parse.xml();
				}
				if (m_Parse.attrBool(_T("showstartup")))
				{
					strStartup = strID;
				}
				if (pChild3)
				{
					int nCount = pChild3->GetCount();
					if (nCount)
					{
						CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
						g_pSpaceTelescope->m_pCurMDIChildFormInfo = pInfo;
						for (int i = 0; i < nCount; i++)
						{
							CString strName = pChild3->GetChild(i)->name().MakeLower();
							CWebViewImpl* pChromeRenderFrameHostProxyBase = (CWebViewImpl*)this;
							pChild3->GetChild(i)->put_attr(_T("renderframehostproxy"), (__int64)pChromeRenderFrameHostProxyBase);
							IWebView* pChromeWebPage = (IWebView*)this;
							pChild3->GetChild(i)->put_attr(_T("webpage"), (__int64)pChromeWebPage);
							pChild3->GetChild(i)->put_attr(_T("webpagehandle"), (__int64)m_hWnd);
							pChild3->GetChild(i)->put_attr(_T("mdichild"), true);
							pInfo->m_mapFormsInfo[strName] = pChild3->GetChild(i)->xml();
						}
					}
				}
				if (strStartup != _T(""))
				{
					CString strID = strStartup.MakeLower();
					if (g_pSpaceTelescope->m_pCLRProxy == nullptr)
						g_pSpaceTelescope->LoadCLR();
					if (g_pSpaceTelescope->m_pCLRProxy)
					{
						auto it = m_mapFormsInfo.find(strID);
						if (it != m_mapFormsInfo.end())
						{
							auto it2 = m_mapChildFormsInfo.find(strID);
							if (it2 != m_mapChildFormsInfo.end())
								g_pSpaceTelescope->m_pCurMDIChildFormInfo = it2->second;
							IDispatch* pDisp = g_pSpaceTelescope->m_pCLRProxy->CreateCLRObj(it->second);
							HWND hwnd = g_pSpaceTelescope->m_pCLRProxy->GetCtrlHandle(pDisp);
							if (hwnd)
							{
								CCloudWinForm* pForm = (CCloudWinForm*)::SendMessage(hwnd, WM_HUBBLE_DATA, 0, 20190214);
								if (pForm)
								{
									HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
									auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
									if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
									{
										pForm->m_pOwnerHtmlWnd = this;
										pForm->m_pBrowser = (CBrowser*)it->second;
									}
								}
							}
						}
					}
				}
			}
			if (strType.CompareNoCase(_T("workbench")) == 0)
			{
				bool bSkip = false;
				if (::IsChild(g_pSpaceTelescope->m_hHostBrowserWnd, m_hWnd))
				{
					if (g_pSpaceTelescope->m_nAppType != APP_ECLIPSE && g_pSpaceTelescope->m_nAppType != APP_BROWSER_ECLIPSE)
					{
						bSkip = true;
					}
				}
				if (bSkip == false)
				{
					CString strStartup = _T("");
					CString strID = m_Parse.attr(_T("workbenchkey"), _T(""));
					CString strName = m_Parse.name();
					if (strID != _T(""))
					{
						g_pSpaceTelescope->m_mapCreatingWorkBenchInfo[strID] = m_mapWorkBenchInfo[strID] = m_Parse.xml();
					}
					if (m_Parse.attrBool(_T("showstartup")))
					{
						strStartup = strID;
					}
					if (strStartup != _T(""))
					{
						CString strID = strStartup;
						g_pSpaceTelescope->m_strWorkBenchStrs = strID;
						g_pSpaceTelescope->m_strWorkBenchStrs += _T("|");
						g_pSpaceTelescope->m_nAppType = APP_BROWSER_ECLIPSE;
					}
				}
			}
			else if (strType.CompareNoCase(_T("browser")) == 0)
			{
				CString strUrls = _T("");
				int nCount = m_Parse.GetCount();
				for (int i = 0; i < nCount; i++)
				{
					CString strUrl = m_Parse.GetChild(i)->attr(_T("url"), _T(""));
					int nPos2 = strUrl.Find(_T(":"));
					if (nPos2 != -1)
					{
						CString strURLHeader = strUrl.Left(nPos2);
						if (strURLHeader.CompareNoCase(_T("host")) == 0)
						{
							strUrl = g_pSpaceTelescope->m_strAppPath + strUrl.Mid(nPos2 + 1);
						}
					}
					strUrls = strUrls + strUrl + _T("|");
				}
				g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(NULL, strUrls);
			}
		}
	}

	void CWebView::CustomizedExtraElement(CString strHTML)
	{
		CMarkup rootXML;
		if (rootXML.SetDoc(strHTML) && rootXML.FindElem())
		{
			CString strTarget = rootXML.GetAttrib(_T("target"));
			if (strTarget.CompareNoCase(_T("ntp")) == 0)
			{
				g_pSpaceTelescope->m_strNtpXml = strHTML;
			}
		}
	}

	void CWebView::CustomizedDataElement(CString strHTML)
	{
		CMarkup rootXML;
		if (rootXML.SetDoc(strHTML) && rootXML.FindElem())
		{
			CString strKey = rootXML.GetAttrib(_T("key"));
			g_pSpaceTelescope->m_mapValInfo[strKey] = CComVariant(strHTML);
		}
	}

	void CWebView::CustomizedDocElement(CString strHTML)
	{
		CMarkup rootXML;
		if (rootXML.SetDoc(strHTML) && rootXML.FindElem())
		{
			CString strName = rootXML.GetAttrib(_T("name"));
			if (strName == _T(""))
			{
				strName = _T("__NATIVE_UI_DEFAULT__");
			}
			ObserveViewport(strName, strHTML);
			::PostMessage(m_hWnd, WM_COSMOSMSG, 20200311, 0);
		}
	}

	void CWebView::OnNTPLoaded()
	{
		if (g_pSpaceTelescope->m_strNtpXml != _T(""))
			ObserveViewport(_T("__NTP_DEFAULT__"), g_pSpaceTelescope->m_strNtpXml);
	}

	void CWebView::OnWinFormCreated(HWND hwnd)
	{
		if (hwnd)
		{
			CCloudWinForm* pWnd = nullptr;
			LRESULT l = ::SendMessage(hwnd, WM_HUBBLE_DATA, 0, 20190214);
			if (l == 0)
			{
				pWnd = new CCloudWinForm();
				g_pSpaceTelescope->m_hFormNodeWnd = (HWND)hwnd;
				pWnd->SubclassWindow(hwnd);
			}
			else
				pWnd = (CCloudWinForm*)l;
			HWND hBrowser = m_pChromeRenderFrameHost->GetHostBrowserWnd();
			auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowser);
			if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
			{
				pWnd->m_pOwnerHtmlWnd = this;
				pWnd->m_pBrowser = (CBrowser*)it->second;
			}
			g_pSpaceTelescope->m_mapFormWebPage[hwnd] = this;
			m_mapWinForm[hwnd] = pWnd;
			::PostMessage(g_pSpaceTelescope->m_hFormNodeWnd, WM_WINFORMCREATED, 0, 0);
		}
	}

	void CWebView::OnCloudMsgReceived(CSession* pSession)
	{
		CString strMsgID = pSession->GetString(L"msgID");
		IXobj* pXobj = (IXobj*)pSession->Getint64(_T("xobj"));
		CXobj* pObj = nullptr;
		if (pXobj)
		{
			pObj = (CXobj*)pXobj;
			if (pObj->m_pWormhole == nullptr)
				pObj->m_pWormhole = (CWormhole*)pSession;
			if (pObj->m_pWebView == nullptr)
				pObj->m_pWebView = this;
			if (pObj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd == nullptr)
				pObj->m_pXobjShareData->m_pNucleus->m_pWebViewWnd = this;
		}
		if (pObj)
		{
			::SendMessage(pObj->m_pXobjShareData->m_pNucleus->m_hWnd, WM_CLOUDMSGRECEIVED, (WPARAM)pObj, (LPARAM)pSession);
			::SendMessage(pObj->m_pHostWnd->m_hWnd, WM_CLOUDMSGRECEIVED, (WPARAM)pObj, (LPARAM)pSession);
		}
		if (strMsgID == _T("CREATE_WINFORM"))
		{
			CString strFormXml = pSession->GetString(_T("formXml"));
			pSession->InsertString(_T("formXml"), _T(""));
			// formType: 0, normal form; 1 subform; 2: dlgform
			long formType = pSession->GetLong(_T("formType"));
			CTangramXmlParse xmlParse;
			if (xmlParse.LoadXml(strFormXml))
			{
				CTangramXmlParse* pMdiChildXmlParse = xmlParse.GetChild(_T("mdichild"));
				if (pMdiChildXmlParse)
				{
					int nCount = pMdiChildXmlParse->GetCount();
					if (nCount)
					{
						CMDIChildFormInfo* pInfo = new CMDIChildFormInfo();
						g_pSpaceTelescope->m_pCurMDIChildFormInfo = pInfo;
						for (int i = 0; i < nCount; i++)
						{
							CString strName = pMdiChildXmlParse->GetChild(i)->name().MakeLower();
							CWebViewImpl* pChromeRenderFrameHostProxyBase = (CWebViewImpl*)this;
							pMdiChildXmlParse->GetChild(i)->put_attr(_T("renderframehostproxy"), (__int64)pChromeRenderFrameHostProxyBase);
							IWebView* pChromeWebPage = (IWebView*)this;
							pMdiChildXmlParse->GetChild(i)->put_attr(_T("webpage"), (__int64)pChromeWebPage);
							pMdiChildXmlParse->GetChild(i)->put_attr(_T("webpagehandle"), (__int64)m_hWnd);
							pMdiChildXmlParse->GetChild(i)->put_attr(_T("mdichild"), true);
							pInfo->m_mapFormsInfo[strName] = pMdiChildXmlParse->GetChild(i)->xml();
						}
					}
				}
				if (g_pSpaceTelescope->m_pCLRProxy == nullptr)
					g_pSpaceTelescope->LoadCLR();
				if (g_pSpaceTelescope->m_pCLRProxy)
				{
					CWebViewImpl* pProxyBase = (CWebViewImpl*)this;
					xmlParse.put_attr(_T("renderframehostproxy"), (__int64)pProxyBase);
					xmlParse.put_attr(_T("addsubform"), (int)1);
					xmlParse.put_attr(_T("ipcsession"), (__int64)pSession);
					pSession->Insertint64(_T("domhandle"), (__int64)pSession);
					pSession->InsertLong(_T("autodelete"), 0);
					IWebView* pChromeWebPage = (IWebView*)this;
					xmlParse.put_attr(_T("webpage"), (__int64)pChromeWebPage);
					xmlParse.put_attr(_T("webpagehandle"), (__int64)m_hWnd);
					if (formType == 2)
					{
						xmlParse.put_attr(_T("model"), 1);
					}
					pSession->m_pOwner = this;
					IDispatch* pDisp = g_pSpaceTelescope->m_pCLRProxy->CreateCLRObj(xmlParse.xml());
				}
			}
		}
		else if (strMsgID == _T("OPEN_URL"))
		{
			CString strPath = g_pSpaceTelescope->m_strAppPath;
			CString strUrl = pSession->GetString(_T("openurl"));
			long nPos = pSession->GetLong(_T("BrowserWndOpenDisposition"));
			int _nPos = strUrl.Find(_T("host:"));
			if (nPos == 2 && _nPos != -1)
				strUrl.Replace(_T("host:"), strPath);
			else
			{
				strUrl.Replace(_T("host:"), strPath);
				strUrl += _T("|");
				strUrl.Replace(_T("||"), _T("|"));
			}
			if (m_pChromeRenderFrameHost)
			{
				if (nPos > 0x000a || nPos == 0)
				{
					switch (nPos)
					{
					case 200:
					case 1965:
					{
						HWND hWnd = ::CreateWindow(L"Cosmos Xobj Class", NULL, /*WS_OVERLAPPED |*/ WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 200, 200, g_pSpaceTelescope->m_hCosmosWnd, 0, AfxGetInstanceHandle(), NULL);
						g_pSpaceTelescope->m_hTempBrowserWnd = g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(hWnd, strUrl);
						::SetWindowPos(g_pSpaceTelescope->m_hTempBrowserWnd, HWND_BOTTOM, 0, 0, ::GetSystemMetrics(SM_CXSCREEN), 100, SWP_NOACTIVATE);// | SWP_HIDEWINDOW);
						if (nPos == 1965)
							g_pSpaceTelescope->m_mapBrowserForm[g_pSpaceTelescope->m_hTempBrowserWnd] = (HWND)pSession->Getint64(_T("InitFormHandle"));;
					}
					break;
					default:
						g_pSpaceTelescope->m_pBrowserFactory->CreateBrowser(0, strUrl);
						break;
					}
				}
				else
				{
					IPCMsg msg;
					msg.m_strId = L"OPEN_URL";
					msg.m_strParam1 = strUrl;
					CString strDisposition = _T("");
					strDisposition.Format(_T("%d"), nPos);
					msg.m_strParam2 = strDisposition;
					m_pChromeRenderFrameHost->SendCosmosMessage(&msg);
				}
			}
		}
		else if (strMsgID == _T("OPEN_XML"))
		{
			CString strKey = pSession->GetString(_T("openkey"));
			CString strXml = pSession->GetString(_T("openxml"));
			if (pXobj)
			{
				IXobj* _pXobj = nullptr;
				if (pObj->m_pParentObj == nullptr && pObj->m_strID == TGM_NUCLEUS && pObj->m_pWebView == this)
				{
					ObserveViewport(strKey, strXml);
					_pXobj = m_pNucleus->m_pWorkXobj;
				}
				else
					pXobj->Observe(CComBSTR(strKey), CComBSTR(strXml), &_pXobj);
				if (_pXobj)
				{
					__int64 nHandle = 0;
					_pXobj->get_Handle(&nHandle);
					pSession->Insertint64(_T("openxmlreturnhandle"), nHandle);
					::PostMessage(m_hWnd, WM_COSMOSMSG, 20200429, (LPARAM)pSession);
				}
			}
		}
		else if (strMsgID == _T("OPEN_XML_SPLITTER"))
		{
			CString strKey = pSession->GetString(_T("openkey"));
			CString strXml = pSession->GetString(_T("openxml"));
			int nCol = pSession->GetLong(_T("opencol"));
			int nRow = pSession->GetLong(_T("openrow"));
			if (pXobj)
			{
				IXobj* _pXobj = nullptr;
				pXobj->ObserveEx(nRow, nCol, CComBSTR(strKey), CComBSTR(strXml), &_pXobj);
				if (_pXobj)
				{
					__int64 nHandle = 0;
					_pXobj->get_Handle(&nHandle);
					pSession->Insertint64(_T("openxmlreturnhandle"), nHandle);
					::PostMessage(m_hWnd, WM_COSMOSMSG, 20200429, (LPARAM)pSession);
				}
			}
		}
		else if (strMsgID == _T("OPEN_XML_CTRL"))
		{
			//CString strName = pSession->GetString(_T("ctrlName"));
			//CString strKey = pSession->GetString(_T("openkey"));
			//CString strXml = pSession->GetString(_T("openxml"));
		}
		else if (strMsgID == _T("SET_REFGRIDS_IPC_MSG"))
		{
			CString strXml = pSession->GetString(_T("RefInfo"));
			((CXobj*)pXobj)->m_strXmlRefXobjInfo = strXml;
		}
	}

	STDMETHODIMP CWebView::get_HostWnd(LONGLONG* Val)
	{
		*Val = (LONGLONG)m_hWebHostWnd;
		return S_OK;
	}

	STDMETHODIMP CWebView::put_HostWnd(LONGLONG newVal)
	{
		HWND hWnd = (HWND)newVal;
		if (::IsWindow(hWnd))
			m_hWebHostWnd = hWnd;
		return S_OK;
	}

	STDMETHODIMP CWebView::get_WebBrowser(IBrowser** ppVal)
	{
		if (m_pBrowser == nullptr) {
			HWND hBrowserWnd = m_pChromeRenderFrameHost->GetHostBrowserWnd();
			auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(hBrowserWnd);
			if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
			{
				m_pBrowser = (CBrowser*)it->second;
			}
		}
		*ppVal = m_pBrowser;
		return S_OK;
	}

	STDMETHODIMP CWebView::Observe(BSTR bstrKey, BSTR bstrXml, IXobj** pRetXobj)
	{
		if (m_pNucleus == nullptr) {
			CNuclei* pNuclei = nullptr;
			auto it = g_pSpaceTelescope->m_mapNuclei.find(m_hExtendWnd);
			if (it != g_pSpaceTelescope->m_mapNuclei.end())
				pNuclei = (CNuclei*)it->second;
			else
			{
				pNuclei = new CComObject<CNuclei>();
				pNuclei->m_hWnd = m_hExtendWnd;
				g_pSpaceTelescope->m_mapNuclei[m_hExtendWnd] = pNuclei;

				for (auto& it : g_pSpaceTelescope->m_mapWebRTAppProxy)
				{
					CNucleiProxy* pProxy = it.second->OnNucleiCreated(pNuclei);
					if (pProxy)
						pNuclei->m_mapNucleiProxy[it.second] = pProxy;
				}
			}
			if (pNuclei) {
				INucleus* pGalaxy = nullptr;
				pNuclei->CreateNucleus(CComVariant((__int64)0), CComVariant((__int64)m_hChildWnd), CComBSTR("default"), &pGalaxy);
				if (pGalaxy)
				{
					m_pNucleus = (CNucleus*)pGalaxy;
					m_pNucleus->m_pWebViewWnd = this;
				}
			}
		}
		if (m_pNucleus)
		{
			CString strNewKey = OLE2T(bstrKey);
			if (m_strCurKey != strNewKey)
				m_pNucleus->Observe(bstrKey, bstrXml, pRetXobj);
			else
			{
				*pRetXobj = m_pNucleus->m_pWorkXobj;
				return S_OK;
			}
			if (*pRetXobj)
			{
				m_strCurKey = strNewKey;
				m_hWebHostWnd = NULL;
				if (m_pNucleus->m_pBindingXobj)
				{
					m_hWebHostWnd = m_pNucleus->m_pBindingXobj->m_pHostWnd->m_hWnd;
				}
			}
		}
		CBrowser* pBrowserWnd = nullptr;
		auto it = g_pSpaceTelescope->m_mapBrowserWnd.find(::GetParent(m_hWnd));
		if (it != g_pSpaceTelescope->m_mapBrowserWnd.end())
		{
			pBrowserWnd = (CBrowser*)it->second;
			if (pBrowserWnd->m_pBrowser->GetActiveWebContentWnd() != m_hWnd)
				::ShowWindow(m_hWnd, SW_HIDE);
		}
		return S_OK;
	}

	STDMETHODIMP CWebView::SendXmlMessage(IXobj* sender, BSTR bstrXml)
	{
		CXobj* pXobj = (CXobj*)sender;
		if (pXobj)
		{
			CTangramXmlParse m_Parse;
			if (m_Parse.LoadXml(OLE2T(bstrXml)))
			{
				CTangramXmlParse* pChild = m_Parse.GetChild(_T("webpage"));
				if (pChild)
				{
					CString strMsgID = m_Parse.attr(_T("msgID"), _T(""));
					int nCount = pChild->GetCount();
					if (nCount)
					{
						for (int i = 0; i < nCount; i++)
						{
							CString strName = pChild->GetChild(i)->name();
							auto it = pXobj->m_pRootObj->m_mapChildXobj.find(strName);
							if (it != pXobj->m_pRootObj->m_mapChildXobj.end())
							{
								CXobj* pTarget = it->second;
								if (pTarget)
								{
									if (pXobj->m_pWormhole == nullptr)
									{
										pXobj->m_pWormhole = (CWormhole*)((CWebRTImpl*)g_pSpaceTelescope)->CreateCloudSession(this);
										CWormhole* pSession = pXobj->m_pWormhole;
										if (pSession)
										{
											pSession->InsertString(_T("msgID"), strMsgID);
											pSession->InsertLong(_T("autodelete"), 0);
											pSession->InsertLong(_T("gridtype"), pXobj->m_nViewType);
											pSession->InsertLong(_T("rows"), pXobj->m_nRows);
											pSession->InsertLong(_T("cols"), pXobj->m_nCols);
											pSession->InsertLong(_T("row"), pXobj->m_nRow);
											pSession->InsertLong(_T("col"), pXobj->m_nCol);
											pSession->InsertString(_T("objtype"), pXobj->m_strObjTypeID);
											pSession->InsertString(_T("name@page"), pXobj->m_strName);
											pSession->Insertint64(_T("xobjhandle"), (__int64)pXobj->m_pHostWnd->m_hWnd);
											pSession->Insertint64(_T("xobj"), (__int64)(IXobj*)pXobj);
											pSession->Insertint64(_T("Galaxyhandle"), (__int64)pXobj->m_pXobjShareData->m_pNucleus->m_hWnd);
											pSession->InsertString(_T("galaxy"), pXobj->m_pXobjShareData->m_pNucleus->m_strNucleusName);
											pSession->InsertString(TGM_NUCLEUS, pXobj->m_pRootObj->m_strKey);
											pSession->Insertint64(_T("rootgridhandle"), (__int64)pXobj->m_pRootObj->m_pHostWnd->m_hWnd);
											pSession->Insertint64(_T("domhandle"), (__int64)pXobj->m_pWormhole);
											pSession->InsertString(_T("objID"), _T("wndnode"));
											switch (pXobj->m_nViewType)
											{
											case Grid:
											{
												CGridWnd* pWnd = (CGridWnd*)pXobj->m_pHostWnd;
												for (int i = 0; i < pXobj->m_nRows; i++)
												{
													for (int j = 0; j < pXobj->m_nCols; j++)
													{
														int nIndex = j + i * pXobj->m_nRows;
														CString strIndex = _T("");
														strIndex.Format(_T("%d"), nIndex);
														pSession->Insertint64(strIndex, (__int64)::GetDlgItem(pWnd->m_hWnd, pWnd->IdFromRowCol(i, j)));
													}
												}
											}
											break;
											case TabGrid:
											{
												for (auto& it : pXobj->m_vChildNodes)
												{
													CString strIndex = _T("");
													strIndex.Format(_T("%d"), it->m_nCol);
													pSession->Insertint64(strIndex, (__int64)it->m_pHostWnd->m_hWnd);
												}
											}
											break;
											default:
												break;
											}
											if (pXobj->m_pParentObj)
											{
												pSession->Insertint64(_T("parenthandle"), (__int64)pXobj->m_pParentObj->m_pHostWnd->m_hWnd);
											}
											if (pXobj->m_pParentWinFormWnd)
											{
												pSession->Insertint64(_T("parentFormHandle"), (__int64)pXobj->m_pParentWinFormWnd->m_hWnd);
											}
											if (pXobj->m_pDisp)
											{
												pXobj->m_pWormhole->Insertint64(_T("objectdisp"), (__int64)pXobj->m_pDisp);
												if (g_pSpaceTelescope->m_pCLRProxy)
												{
													g_pSpaceTelescope->m_pCLRProxy->ConnectXobjToWebPage(pXobj, true);
												}
											}
											pXobj->m_pWormhole->InsertString(_T("msgData"), pChild->GetChild(i)->xml());
											m_pChromeRenderFrameHost->SendCosmosMessage(pSession->m_pSession);
										}
									}
									else
									{
										pXobj->m_pWormhole->InsertString(_T("msgID"), strMsgID);
										pXobj->m_pWormhole->InsertString(_T("msgData"), pChild->GetChild(i)->xml());
										m_pChromeRenderFrameHost->SendCosmosMessage(pXobj->m_pWormhole->m_pSession);
									}
								}
							}
						}
					}
				}
			}
		}
		return S_FALSE;
	}

	STDMETHODIMP CWebView::CreateForm(BSTR bstrKey, LONGLONG hParent, IDispatch** pRetForm)
	{
		if (g_pSpaceTelescope->m_pCLRProxy == nullptr)
			g_pSpaceTelescope->LoadCLR();
		if (hParent == 0)
			hParent = (__int64)m_hWnd;
		CString strKey = OLE2T(bstrKey);
		auto it = this->m_mapFormsInfo.find(strKey.MakeLower());
		if (it != m_mapFormsInfo.end())
		{
			*pRetForm = g_pSpaceTelescope->m_pCLRProxy->CreateWinForm((HWND)hParent, CComBSTR(it->second));
		}
		return S_OK;
	}
}  // namespace Browser
