/********************************************************************************
 *           AIGC for Desktop Application - Version 1.0.0.202203120001
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

#include "WebRTApp.h"
#include "TangramXmlParse.cpp"

IWebRT* g_pWebRT = nullptr;

namespace CommonUniverse {
typedef IWebRT*(__stdcall* GetWebRT)();
typedef CWebRTImpl*(__stdcall* GetWebRTImpl)(IWebRT**);
typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*);
_IsBrowserModel FuncIsBrowserModel;
CWinApp* g_pAppBase = nullptr;
CWebRTImpl* g_pSpaceTelescopeImpl = nullptr;
class CTangramHelperWnd : public CWnd {
 public:
  CTangramHelperWnd() {}
  virtual ~CTangramHelperWnd() {}
  void PostNcDestroy() {
    CWnd::PostNcDestroy();
    delete this;
  }

 protected:
  DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CTangramHelperWnd, CWnd)
END_MESSAGE_MAP()

class CWebRTProxy : public IWebRTDelegate {
 public:
  CWebRTProxy(){};
  virtual ~CWebRTProxy() {
  }

  // IWebRTDelegate:
  virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) {
    _AFX_THREAD_STATE* pState = AfxGetThreadState();
    while (bIdle &&
           !::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE)) {
      if (!AfxGetApp()->OnIdle(lCount++))
        bIdle = FALSE;  // assume "no idle" state
    }
    return true;
  }

  virtual bool DoIdleWork() {
    if (g_pSpaceTelescopeImpl && g_pSpaceTelescopeImpl->m_hMainWnd &&
        ::IsWindow(g_pSpaceTelescopeImpl->m_hMainWnd) == false)
      g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
    return false;
  }

  virtual bool IsAppIdleMessage() {
    _AFX_THREAD_STATE* pState = AfxGetThreadState();
    if (AfxGetApp()->IsIdleMessage(&(pState->m_msgCur))) {
      return true;
    }
    return false;
  }

  virtual void ProcessMsg(MSG* msg) {
    if (msg->message != WM_KICKIDLE) {
      ::TranslateMessage(msg);
      ::DispatchMessage(msg);
    }
  }

  virtual void ForegroundIdleProc() {
    // send WM_IDLEUPDATECMDUI to the main window
    CWnd* pMainWnd = AfxGetApp()->m_pMainWnd;
    if (pMainWnd != NULL && pMainWnd->m_hWnd != NULL &&
        pMainWnd->IsWindowVisible()) {
      AfxCallWndProc(pMainWnd, pMainWnd->m_hWnd, WM_IDLEUPDATECMDUI,
                     (WPARAM)TRUE, 0);
      pMainWnd->SendMessageToDescendants(WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0,
                                         TRUE, TRUE);
    }
  }

  virtual bool OnUniversePreTranslateMessage(MSG* pMsg) {
    // if (pMsg->message == WM_CHAR || pMsg->hwnd == nullptr)
    //	return TRUE;
    HWND hwnd = pMsg->hwnd;
    CWinApp* pApp = AfxGetApp();
    CWnd* pWnd = CWnd::FromHandlePermanent(hwnd);
    if (pWnd) {
      if (CMFCPopupMenu::GetActiveMenu() &&
          !::IsWindow(CMFCPopupMenu::GetActiveMenu()->m_hWnd)) {
        return true;
      }
      // if (::GetAncestor(hwnd, GA_ROOTOWNER) ==
      // ::GetAncestor(pApp->m_pMainWnd->m_hWnd, GA_ROOTOWNER))
      //	AFXSetTopLevelFrame((CFrameWnd*)pApp->m_pMainWnd);
      if (pMsg->message == WM_LBUTTONDOWN) {
        if (pApp->m_pMainWnd)
          pApp->m_pMainWnd->PreTranslateMessage(pMsg);
        return true;
      }
      // if (pMsg->wParam==VK_TAB&&IsDialogMessage(pMsg->hwnd, pMsg))
      //{
      //	::DispatchMessage(pMsg);
      //	TranslateMessage(pMsg);
      // }
      return pWnd->PreTranslateMessage(pMsg);
    } else {
      switch (pMsg->message) {
        case WM_NCLBUTTONDOWN:
        case WM_NCRBUTTONDOWN:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
          // case WM_POINTERDOWN:
          // case WM_POINTERUP:
        case WM_SETWNDFOCUSE:
          if (pApp->m_pMainWnd) {
            if (g_pSpaceTelescopeImpl->m_bIsDlgApp) {
              if (::IsChild(pApp->m_pMainWnd->m_hWnd, pMsg->hwnd)) {
                // auto it = g_pSpaceTelescopeImpl->m_mapWebView.find(pMsg->hwnd);
                // if (it != g_pSpaceTelescopeImpl->m_mapWebView.end())
                { return false; }
              }
            }
            pApp->m_pMainWnd->PreTranslateMessage(pMsg);
            return true;
          }
          break;
        case WM_KEYDOWN: {
          if (pApp->m_pMainWnd) {
            if (pMsg->wParam == VK_TAB && IsDialogMessage(pMsg->hwnd, pMsg)) {
              CWnd* pWnd = CWnd::FromHandlePermanent(::GetParent(pMsg->hwnd));
              if (pWnd)
                return pWnd->PreTranslateMessage(pMsg);
            }
            pApp->m_pMainWnd->PreTranslateMessage(pMsg);
            return true;
          }
        } break;
      }
      return TRUE;
    }
    return pApp->PreTranslateMessage(pMsg);
  }

  virtual HICON GetAppIcon(int nIndex) {
    if (g_pAppBase->m_pMainWnd) {
      switch (nIndex) {
        case 0:
          return reinterpret_cast<HICON>(
              GetClassLongPtr(g_pAppBase->m_pMainWnd->m_hWnd, GCLP_HICON));
          break;
        case 1:
          return reinterpret_cast<HICON>(
              GetClassLongPtr(g_pAppBase->m_pMainWnd->m_hWnd, GCLP_HICONSM));
          break;
      }
    }
    else
    {
        TCHAR m_szBuffer[MAX_PATH];
        ::GetModuleFileName(GetModuleHandle(NULL), m_szBuffer, MAX_PATH);
        SHFILEINFOW info;
        if (SHGetFileInfoW(m_szBuffer,
            FILE_ATTRIBUTE_NORMAL,
            &info,
            sizeof(info),
            SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
        {
            return info.hIcon;
        }
    }
    return NULL;
  }
};

CWebRTProxy theAppProxy;

CAIGCWinApp::CAIGCWinApp() {
  g_pAppBase = this;
  m_strProviderID = _T("");
  m_nShellCmd = CCommandLineInfo::FileNew;
}

CAIGCWinApp::~CAIGCWinApp() {
  TRACE(_T("\n**********************delete CAIGCWinApp**********************\n"));
  if (m_pSpaceTelescopeImpl) {
    m_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
    m_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
  }
  CMFCVisualManager* pCMFCVisualManager = CMFCVisualManager::GetInstance();
  if (pCMFCVisualManager) {
    TRACE(
        _T("\n**********************delete ")
        _T("CMFCVisualManager**********************\n"));
    delete pCMFCVisualManager;
  }
}

BOOL CAIGCWinApp::InitApplication() {
  if (WebRTInit(_T("")) ? CWinApp::InitApplication() : false)
    return ProcessAppType(m_bCrashReporting);
  else
    return false;
}

HWND CAIGCWinApp::GetActivePopupMenu(HWND hWnd) {
  // CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
  // if (pActivePopupMenu)
  //{
  //	ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
  //	return pActivePopupMenu->m_hWnd;
  // }
  return nullptr;
}

int CAIGCWinApp::Run() {
  return CWinThread::Run();
}

CString CAIGCWinApp::GetNames() {
  CString strNames = _T("tabctrl,");
  if (m_mapDOMObj.size()) {
    for (auto it = m_mapDOMObj.begin(); it != m_mapDOMObj.end(); it++) {
      strNames += it->first;
      strNames += _T(",");
    }
    return strNames.MakeLower();
  }
  return strNames.MakeLower();
}

CString CAIGCWinApp::GetTags(CString strName) {
  CString strNameBase = _T("0,1,2,3,4,5,6,7,");
  strName.Trim().MakeLower();
  if (strName != _T("")) {
    auto it = m_mapDOMObjStyle.find(strName);
    if (it != m_mapDOMObjStyle.end()) {
      strNameBase += it->second;
      strNameBase += _T(",");
      return strNameBase;
    }
  }
  return strNameBase;
}

HWND CAIGCWinApp::Create(HWND hParentWnd, IXobj* pXobj) {
  CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
  if (pParent == nullptr) {
    pParent = new CTangramHelperWnd();
    if (!pParent->SubclassWindow(hParentWnd)) {
      TRACE(_T("\n**********************Error**********************\n"));
      return NULL;
    }
  }
  USES_CONVERSION;
  BSTR bstrTag = ::SysAllocString(L"");

  pXobj->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
  CString m_strTag = OLE2T(bstrTag);
  ::SysFreeString(bstrTag);
  m_strTag.Trim().MakeLower();
  if (m_strTag != _T("")) {
    auto it = m_mapDOMObj.find(m_strTag);
    if (it != m_mapDOMObj.end()) {
      CRuntimeClass* pCls = (CRuntimeClass*)it->second;
      CWnd* pWnd = (CWnd*)pCls->CreateObject();
      if (pWnd) {
        if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView))) {
          AfxSetResourceHandle(AfxGetApp()->m_hInstance);
        }
        if (pWnd->Create(nullptr, _T(""), WS_CHILD | WS_VISIBLE,
                         CRect(0, 0, 0, 0), pParent, 0, nullptr)) {
          ::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, (WPARAM)pXobj, 20191031);
          if (pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
            CView* pView = static_cast<CView*>(pWnd);
            CFrameWnd* pFrame = pView->GetParentFrame();
            WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
            if (pFrame) {
              pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
                  pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
              if (pWebRTFrameWndInfo) {
                HWND hView = pWebRTFrameWndInfo->m_hClient;
                CWnd* pHostView = CWnd::FromHandlePermanent(hView);
                if (pHostView->IsKindOf(RUNTIME_CLASS(CView))) {
                  CView* _pView = (CView*)pHostView;
                  CDocument* pDoc = _pView->GetDocument();
                  if (pDoc) {
                    m_mapViewDoc[pView] = pDoc;
                    pWebRTFrameWndInfo->m_pDoc = pDoc;
                    pWebRTFrameWndInfo->m_hClient = hView;
                    pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
                  }
                }
              }
            }
          }
          return pWnd->m_hWnd;
        }
      }
    }
  }
  return NULL;
}

bool CAIGCWinApp::WebRTInit(CString strID) {
  if (!afxContextIsDLL) {
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);
    m_nShellCmd = cmdInfo.m_nShellCommand;
    switch (m_nShellCmd) {
      case CCommandLineInfo::AppRegister:
      case CCommandLineInfo::AppUnregister:
        return true;
      default:
        break;
    }
    if (IsBrowserModel(false)) {
      m_bBuiltInBrowser = true;
      return false;
    }
  }
  HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
  if (hModule == nullptr)
      hModule = ::LoadLibrary(L"AIGCAgent.dll");
  if (hModule == nullptr) {
      TCHAR m_szBuffer[MAX_PATH];
      if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
          m_szBuffer) == S_OK) {
          CString strChromeRTFilePath = CString(m_szBuffer);
          strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
          if (::PathFileExists(strChromeRTFilePath)) {
              hModule = ::LoadLibrary(strChromeRTFilePath);
          }
      }
      if (hModule == nullptr)
          hModule = ::LoadLibrary(L"AIGCAgent.dll");
  }
  HMODULE hModule2 = hModule;
  if (hModule) {
      BOOL isBrowserModel = false;
      FuncIsBrowserModel =
          (_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
      if (FuncIsBrowserModel != NULL) {
          isBrowserModel = FuncIsBrowserModel(false, this);
          if (isBrowserModel)
              return false;
      }
  }

  TCHAR m_szBuffer[MAX_PATH];
  TCHAR szDriver[MAX_PATH] = {0};
  TCHAR szDir[MAX_PATH] = {0};
  TCHAR szExt[MAX_PATH] = {0};
  TCHAR szFile2[MAX_PATH] = {0};
  ::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
  _tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
  CString strTangramDll = szDriver;
  strTangramDll += szDir;
  strTangramDll += _T("universe.dll");
  hModule = ::LoadLibrary(strTangramDll);
  if (hModule) {
    if (m_strContainer != _T("")) {
      m_strContainer = _T(",") + m_strContainer + _T(",");
      m_strContainer.Replace(_T(",,"), _T(","));
    }
    GetWebRTImpl _pWebRTImplFunction;
    _pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
    g_pSpaceTelescopeImpl = m_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
    g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hModule2;
    if (!afxContextIsDLL) {
      m_strProviderID += _T("host");
      m_strProviderID.MakeLower();

      m_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
      g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
                                    static_cast<IUniverseAppProxy*>(this));
      g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
                                    static_cast<IWindowProvider*>(this));
      if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
          g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
        ::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
                         (WPARAM)m_pSpaceTelescopeImpl->m_pWebRTDelegate,
                         g_pSpaceTelescopeImpl->m_nAppType);
      m_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
    } else {
      strID.Trim();
      if (strID == _T(""))
        strID = _T("component");
      if (m_strProviderID == _T("")) {
        CString strName = AfxGetApp()->m_pszAppName;
        if (strName.CompareNoCase(_T("cosmoshelper")) == 0)
          m_strProviderID = _T("host");
        else
          m_strProviderID = strName + _T(".") + strID;
      }
      if (m_strProviderID != _T("")) {
        m_strProviderID.MakeLower();
        g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
                                      static_cast<IUniverseAppProxy*>(this));
        g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
                                      static_cast<IWindowProvider*>(this));
      }
      m_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
    }
  }
  return true;
}

CString CAIGCWinApp::QueryDocType(HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandle(hWnd);
  CFrameWnd* pFrame = pWnd->GetParentFrame();
  if (pFrame) {
    CString strType =
        (LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
    if (strType == _T("") && pFrame == m_pMainWnd &&
        pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
      strType = _T("mdiframe");
    }
    if (strType == _T("") && pFrame == m_pMainWnd &&
        pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd))) {
      strType = _T("miniframe");
    }
    return strType;
  }
  return _T("");
}

CString CAIGCWinApp::QueryWndClassName(HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  if (pWnd) {
    CRuntimeClass* pClassInfo = pWnd->GetRuntimeClass();
    if (pClassInfo) {
      return CString(pClassInfo->m_lpszClassName);
    }
  }
  return _T("");
}

HWND CAIGCWinApp::GetFrameWnd(HWND hWnd, int& nType) {
  CWnd* pWnd = CWnd::FromHandle(hWnd);
  if (pWnd) {
    CFrameWnd* pFrame = pWnd->GetParentFrame();
    if (pFrame) {
      if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
        nType = 1;
      else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
        nType = 2;
      else if (pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd)))
        nType = 4;
      else
        nType = 3;
      return pFrame->m_hWnd;
    }
  }
  return NULL;
}

HWND CAIGCWinApp::QueryWndInfo(QueryType nType, HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  switch (nType) {
    case MainWnd:
      if (m_pMainWnd) {
        pWnd = m_pMainWnd;
        if (pWnd) {
          WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
          HANDLE hHandle = ::GetProp(pWnd->m_hWnd, _T("WebRTFrameWndInfo"));
          if (hHandle) {
            pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
            if (pWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
              pWebRTFrameWndInfo->m_nFrameType = 2;
            else {
              POSITION nPos = GetFirstDocTemplatePosition();
              while (nPos) {
                CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
                POSITION pos = pTemplate->GetFirstDocPosition();
                while (pos != NULL) {
                  CDocument* pDoc = pTemplate->GetNextDoc(pos);
                  POSITION pos2 = pDoc->GetFirstViewPosition();
                  while (pos2 != NULL) {
                    CView* pView = pDoc->GetNextView(pos2);
                    ASSERT_VALID(pView);
                    CFrameWnd* pFrame = pView->GetParentFrame();
                    if (m_pMainWnd == pFrame) {
                      if (pTemplate->IsKindOf(
                              RUNTIME_CLASS(CMultiDocTemplate))) {
                        if (!pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
                          pWebRTFrameWndInfo->m_nFrameType = 1;
                        return pWnd->m_hWnd;
                      }
                      break;
                    }
                  }
                }
              }
            }
          }
        }
        return m_pMainWnd->m_hWnd;
      }
      break;
    case CanClose: {
      if (pWnd) {
        if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
          CFrameWnd* _pFrame = (CFrameWnd*)pWnd;
          POSITION nPos = GetFirstDocTemplatePosition();
          while (nPos) {
            CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
            POSITION pos = pTemplate->GetFirstDocPosition();
            while (pos != NULL) {
              CDocument* pDoc = pTemplate->GetNextDoc(pos);
              POSITION pos2 = pDoc->GetFirstViewPosition();
              while (pos2 != NULL) {
                CView* pView = pDoc->GetNextView(pos2);
                ASSERT_VALID(pView);
                CFrameWnd* pFrame = pView->GetParentFrame();
                if (_pFrame == pFrame) {
                  if (pDoc->CanCloseFrame(pFrame)) {
                    return pFrame->m_hWnd;
                  } else
                    return NULL;
                }
              }
            }
          }
        }
      }
      return NULL;
    } break;
    case DocView: {
      if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
        CView* pView = static_cast<CView*>(pWnd);
        WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
        CDocument* pDoc = pView->GetDocument();
        if (pDoc) {
          HWND hRetFrame = NULL;
          CDocTemplate* pTemplate = pDoc->GetDocTemplate();
          CFrameWnd* pFrame = pView->GetParentFrame();
          if (pFrame) {
            hRetFrame = pFrame->m_hWnd;
            CString strInfo = m_strCreatingDOCID;
            if (strInfo == _T(""))
              strInfo = _T("default");
            CRuntimeClass* pClsInfo = pView->GetRuntimeClass();
            CString strName = CString(pClsInfo->m_lpszClassName);
            auto it = m_mapDOMObj.find(strName);
            if (it == m_mapDOMObj.end())
              m_mapDOMObj[strName] = pClsInfo;
            bool bRet = g_pSpaceTelescopeImpl->SetFrameInfo(hWnd, hRetFrame, strInfo,
                                                   pDoc, pTemplate);
            if (pWnd->IsKindOf(RUNTIME_CLASS(CScrollView)) &&
                ::GetParent(hWnd) == hRetFrame)
              ((CScrollView*)pWnd)->ResizeParentToFit();
            pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
                hRetFrame, _T("WebRTFrameWndInfo"));
            if (pWebRTFrameWndInfo == nullptr) {
              __int64 nType = 0;
              if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
                nType = 2;
              else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
                nType = 3;
              else if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
                nType = 1;
              ::SetProp(hRetFrame, _T("CosmosFrameWndType"), (HANDLE)nType);
            } else {
              pWebRTFrameWndInfo->m_hClient = hWnd;
              if (pWebRTFrameWndInfo->m_pDoc == nullptr && pDoc) {
                pWebRTFrameWndInfo->m_pDoc = pDoc;
                pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
              }
              if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
                pWebRTFrameWndInfo->m_nFrameType = 2;
              else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd))) {
                pWebRTFrameWndInfo->m_nFrameType = 3;
              } else if (pTemplate->IsKindOf(
                             RUNTIME_CLASS(CMultiDocTemplate))) {
                pWebRTFrameWndInfo->m_nFrameType = 1;
              } else if (pFrame->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
                pWebRTFrameWndInfo->m_nFrameType = 4;
            }
          }
          return hRetFrame;
        }
      }
    } break;
    case QueryDestroy: {
      if (::GetParent(hWnd) == NULL)  // && m_pMainWnd && m_pMainWnd != pWnd)
      {
        m_pMainWnd = pWnd;
        return pWnd->m_hWnd;
      }
    } break;
    case ObserveComplete: {
      for (auto& it : m_mapViewDoc) {
        it.second->AddView(it.first);
      }
      m_mapViewDoc.erase(m_mapViewDoc.begin(), m_mapViewDoc.end());
    } break;
    case RecalcLayout: {
      CWnd* pWnd = CWnd::FromHandle(hWnd);
      CFrameWnd* pFrame = pWnd->GetParentFrame();
      if (pFrame) {
        pFrame->RecalcLayout();
        return pFrame->m_hWnd;
      } else {
        pWnd = CWnd::FromHandlePermanent(hWnd);
        if (pWnd && pWnd->IsFrameWnd()) {
          pFrame = (CFrameWnd*)pWnd;
          pFrame->RecalcLayout();
          return pFrame->m_hWnd;
        }
      }
    } break;
    case SetMainWndNULL: {
      if (g_pSpaceTelescopeImpl->m_hMainWnd) {
        m_pMainWnd = nullptr;
      }
    } break;
    default:
      break;
  }
  return NULL;
}

bool CAIGCWinApp::SetFrameCaption(HWND hWnd,
                                CString strCaption,
                                CString strAppName) {
  if (strCaption == _T("") || !::IsWindow(hWnd))
    return false;
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  CFrameWnd* pFrame = nullptr;
  if (pWnd) {
    if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
      pFrame = (CFrameWnd*)pWnd;
    } else {
      pFrame = pWnd->GetParentFrame();
    }
    if (pFrame) {
      WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
          pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
      if (pWebRTFrameWndInfo) {
        CDocument* pDoc = (CDocument*)pWebRTFrameWndInfo->m_pDoc;
        if (pDoc) {
          CString strPath = pDoc->GetPathName();
          if (strPath == _T("")) {
            CString strTitle = pDoc->GetTitle();
            CDocTemplate* pTemplate =
                (CDocTemplate*)pWebRTFrameWndInfo->m_pDocTemplate;
            CString name = _T("");
            pTemplate->GetDocString(name, CDocTemplate::docName);
            strTitle.Replace(name, strCaption);
            pDoc->SetTitle(strTitle);
            switch (pWebRTFrameWndInfo->m_nFrameType) {
              case 1:
              case 4:
                ::SetWindowText(pFrame->m_hWnd, strTitle + _T(" - ") +
                                                    strAppName + _T(" - ") +
                                                    g_pSpaceTelescopeImpl->m_strAppName);
                break;
              default:
                ::SetWindowText(pFrame->m_hWnd, strTitle);
                break;
            }
          }
          return true;
        }
      }
    }
  } else {
    pWnd = CWnd::FromHandle(hWnd);
    if (pWnd)
      pFrame = pWnd->GetParentFrame();
  }
  if (pFrame) {
    CString strText = _T("");
    pFrame->GetWindowText(strText);
    CString strTitle = pFrame->GetTitle();
    int nPos = strText.ReverseFind('-');
    if (nPos != -1) {
      CString s1 = strText.Left(nPos + 1);
      s1 += _T(" ");
      s1 += strCaption;
      ::SetWindowText(pFrame->m_hWnd, s1);
      pFrame->SetTitle(strCaption);
      return true;
    } else {
      pFrame->SetTitle(strCaption);
      ::SetWindowText(pFrame->m_hWnd, strCaption);
    }
    return true;
  }

  return false;
}

CString CAIGCWinApp::QueryParentInfo(HWND hPWnd, void* lpInfo) {
  CWnd* pParent = CWnd::FromHandlePermanent(hPWnd);
  if (pParent) {
    CFrameWnd* pParentFrame = nullptr;
    if (pParent->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
      if (pParent->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
        return _T("");
      pParentFrame = (CFrameWnd*)pParent;
    } else
      pParentFrame = pParent->GetParentFrame();
    if (pParentFrame) {
      CCreateContext* pContext = (CCreateContext*)lpInfo;
      CDocument* pDoc = pContext->m_pCurrentDoc;
      CDocTemplate* pTemplate =
          pDoc->GetDocTemplate();  // pContext->m_pNewDocTemplate;
      CString strExt = _T("");
      pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
      strExt.MakeLower();
      if (strExt == _T(""))
        strExt = _T("default");
      return strExt;
    }
  }
  return _T("");
}

void CAIGCWinApp::OpenDocFile(CString strFileName,
                            CString strExt,
                            CString strCreatingDOCID) {
  POSITION nPos = GetFirstDocTemplatePosition();
  while (nPos) {
    CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
    if (strExt == _T("")) {
      if (pTemplate) {
        m_strCreatingDOCID = strCreatingDOCID;
        if (m_bNoDefaultMainWnd)
          pTemplate->OpenDocumentFile(NULL);
        return;
      }
    }
    CString _strExt = _T("");
    pTemplate->GetDocString(_strExt, CDocTemplate::filterExt);
    _strExt.MakeLower();
    if (_strExt == _T(""))
      _strExt = _T("default");
    if (strExt != _T("") && strExt.CompareNoCase(strExt) == 0) {
      m_strCreatingDOCID = strCreatingDOCID;
      pTemplate->OpenDocumentFile(strFileName == _T("") ? NULL
                                                        : LPCTSTR(strFileName));
      return;
    }
  }
}

void CAIGCWinApp::OnIPCMsg(CWebPageImpl* pWebPageImpl,
                         CString strType,
                         CString strParam1,
                         CString strParam2,
                         CString strParam3,
                         CString strParam4,
                         CString strParam5) {
  if (strType.CompareNoCase(_T("COSMOS_CREATE_DOC")) == 0) {
    int nCount = 0;
    m_strCreatingDOCID = _T("");
    CDocTemplate* pTemplate = nullptr;
    POSITION nPos = GetFirstDocTemplatePosition();
    while (nPos) {
      nCount++;
      pTemplate = GetNextDocTemplate(nPos);
      CString strExt = _T("");
      pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
      strExt.MakeLower();
      if (strExt == _T(""))
        strExt = _T("default");
      if (strExt != _T("") && strExt.CompareNoCase(strParam1) == 0) {
        m_strCreatingDOCID = strParam2;
        pTemplate->OpenDocumentFile(nullptr);
        return;
      }
    }
    if (pTemplate && m_strCreatingDOCID == _T("") &&
        nCount == 1)  // && strParam1.CompareNoCase(_T(".abc")) == 0)
    {
      m_strCreatingDOCID = strParam2;
      pTemplate->OpenDocumentFile(nullptr);
      return;
    }
  }
}

CXobjProxy* CAIGCWinApp::OnXobjInit(IXobj* pNewNode) {
  CComBSTR bstrName("");
  pNewNode->get_Name(&bstrName);
  CComBSTR bstrName2("");
  pNewNode->get_NameAtWindowPage(&bstrName2);
  return nullptr;
}

CNucleusProxy* CAIGCWinApp::OnNucleusCreated(INucleus* pNewFrame) {
  __int64 h = 0;
  pNewFrame->get_HWND(&h);
  CComBSTR bstrName("");
  pNewFrame->get_Name(&bstrName);
  return nullptr;
}

CNucleiProxy* CAIGCWinApp::OnNucleiCreated(INuclei* pNuclei) {
  CNucleiProxy* pNucleiProxy = nullptr;
  __int64 h = 0;
  pNuclei->get_Handle(&h);
  if (h) {
    CWnd* pWnd = CWnd::FromHandlePermanent((HWND)h);
    if (pWnd == NULL)
      return NULL;
    // if (pWnd->IsKindOf(RUNTIME_CLASS(CWebRTMDIFrame)))
    //{
    //	pNucleiProxy = (CNucleiProxy*)(CWebRTMDIFrame*)pWnd;
    // }
    if (pNucleiProxy)
      pNucleiProxy->m_bAutoDelete = false;
  }
  return pNucleiProxy;
}

CString CAIGCWinApp::GetDocTemplateID(CDocument* pDoc) {
  if (pDoc) {
    POSITION nPos = pDoc->GetFirstViewPosition();
    if (nPos != NULL) {
      CView* pView = pDoc->GetNextView(nPos);
      ASSERT_VALID(pView);
      CFrameWnd* pFrame = pView->GetParentFrame();
      CString s =
          (LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
      return s;
    }
  }
  return _T("");
}

bool CAIGCWinApp::ProcessAppType(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32)
    return true;
  if (m_pSpaceTelescopeImpl) {
    switch (m_pSpaceTelescopeImpl->m_nAppType) {
      case APP_WIN32:
        return true;
        break;
      case APP_BROWSER:
      case APP_BROWSER_ECLIPSE: {
        if (m_pSpaceTelescopeImpl->m_nAppType == APP_BROWSER_ECLIPSE) {
#ifdef _AFXDLL
#ifdef _DEBUG
          ::MessageBox(NULL,
                       _T("Chrome-Eclipse Model is not support MFC Share Dll"),
                       _T("Warnning"), MB_OK);
#endif
          TRACE(
              _T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support ")
              _T("MFC Share Dll********\r\n\r\n"));
#endif
        }
        m_pSpaceTelescopeImpl->m_hMainWnd = NULL;
        HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
        if (hModule == nullptr)
          hModule = ::LoadLibrary(L"AIGCAgent.dll");
        if (hModule == nullptr) {
          TCHAR m_szBuffer[MAX_PATH];
          if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
                              m_szBuffer) == S_OK) {
            CString strChromeRTFilePath = CString(m_szBuffer);
            strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
            if (::PathFileExists(strChromeRTFilePath)) {
              hModule = ::LoadLibrary(strChromeRTFilePath);
            }
          }
          if (hModule == nullptr)
            hModule = ::LoadLibrary(L"AIGCAgent.dll");
        }
        if (hModule) {
          typedef int(__stdcall * _InitApp)(bool bSupportCrashReporting, void*);
          _InitApp _pInitAppFunction;
          _pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
          if (_pInitAppFunction != NULL) {
            m_bBuiltInBrowser = true;
            _pInitAppFunction(bCrashReporting, m_pSpaceTelescopeImpl->m_pWebRTDelegate);
            return false;
          }
        }
      } break;
      case APP_ECLIPSE:
        if (g_pWebRT && !m_pSpaceTelescopeImpl->m_bIsEclipseInit) {
          g_pWebRT->InitEclipseApp();
          return false;
        }
        break;
    }
  }
  return true;
}

BOOL CAIGCWinApp::IsBrowserModel(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32 == false) {
    HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
    if (hModule == nullptr)
      hModule = ::LoadLibrary(L"AIGCAgent.dll");
    if (hModule) {
      m_bCrashReporting = bCrashReporting;
      FuncIsBrowserModel =
          (_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
      if (FuncIsBrowserModel != NULL) {
        return FuncIsBrowserModel(bCrashReporting, this);
      }
    }
  }

  return false;
};

CComponentApp::CComponentApp()
{
    g_pAppBase = this;
}

CComponentApp::~CComponentApp()
{
}

bool CComponentApp::WebRTInit(CString strID)
{
    HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));;
    if (hModule)
    {
        if (m_strContainer != _T(""))
        {
            m_strContainer = _T(",") + m_strContainer + _T(",");
            m_strContainer.Replace(_T(",,"), _T(","));
        }
        GetWebRTImpl _pHubbleImplFunction;
        _pHubbleImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
        g_pSpaceTelescopeImpl = _pHubbleImplFunction(&g_pWebRT);
        if (g_pSpaceTelescopeImpl->m_nAppType == APP_BROWSER_ECLIPSE)
        {
#ifdef _AFXDLL
#ifdef _DEBUG
            ::MessageBox(NULL, _T("Chrome-Eclipse Model is not support MFC Share Dll"), _T("Warnning"), MB_OK);
#endif 
            TRACE(_T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support MFC Share Dll********\r\n\r\n"));
#endif
        }
        strID.Trim();
        if (strID == _T(""))
            strID = _T("views");
        if (m_strProviderID == _T(""))
        {
            CString strName = g_pAppBase->m_pszAppName;
            m_strProviderID = strName + _T(".") + strID;
        }
        if (m_strProviderID != _T(""))
        {
            m_strProviderID.MakeLower();
            g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, static_cast<IWindowProvider*>(this));
        }
    }
    return true;
}

CString CComponentApp::GetNames()
{
    if (m_mapDOMObj.size())
    {
        CString strNames = _T("");
        for (auto it = m_mapDOMObj.begin(); it != m_mapDOMObj.end(); it++)
        {
            strNames += it->first;
            strNames += _T(",");
        }
        return strNames.MakeLower();
    }
    return _T("");
}

CString CComponentApp::GetTags(CString strName)
{
    strName.Trim().MakeLower();
    if (strName != _T(""))
    {
        auto it = m_mapDOMObjStyle.find(strName);
        if (it != m_mapDOMObjStyle.end())
        {
            return it->second;
        }
    }
    return _T("");
}

BOOL CComponentApp::InitInstance()
{
    WebRTInit(_T(""));
    return CWinApp::InitInstance();
}

int CComponentApp::ExitInstance()
{
    return CWinApp::ExitInstance();
}

HWND CComponentApp::Create(HWND hParentWnd, IXobj* pGrid)
{
    CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
    if (pParent == nullptr)
    {
        pParent = new CTangramHelperWnd();
        if (!pParent->SubclassWindow(hParentWnd))
        {
            TRACE(_T("\n**********************Error**********************\n"));
            return NULL;
        }
    }
    USES_CONVERSION;
    BSTR bstrTag = ::SysAllocString(L"");
    pGrid->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
    CString m_strTag = OLE2T(bstrTag);
    ::SysFreeString(bstrTag);
    m_strTag.Trim().MakeLower();
    if (m_strTag != _T(""))
    {
        auto it = m_mapDOMObj.find(m_strTag);
        if (it != m_mapDOMObj.end())
        {
            CRuntimeClass* pCls = (CRuntimeClass*)it->second;
            CWnd* pWnd = (CWnd*)pCls->CreateObject();
            if (pWnd)
            {
                if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView)))
                {
                    AfxSetResourceHandle(CWinApp::m_hInstance);
                }
                pGrid->get_Attribute(CComBSTR("style"), &bstrTag);
                CString strStyle = OLE2T(bstrTag);
                strStyle.Trim();
                if (strStyle == _T(""))
                {
                    ::SysFreeString(bstrTag);
                    pGrid->get_Attribute(CComBSTR("tabstyle"), &bstrTag);
                    strStyle = OLE2T(bstrTag);
                    ::SysFreeString(bstrTag);
                    strStyle.Trim();
                }
                if (pWnd->Create(nullptr, strStyle, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), pParent, 0, nullptr))
                {
                    ::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, (WPARAM)pGrid, 20191031);
                    pGrid->get_Attribute(CComBSTR("activepage"), &bstrTag);
                    long nCount = 0;
                    pGrid->get_Cols(&nCount);
                    CString m_strTag = OLE2T(bstrTag);
                    ::SysFreeString(bstrTag);
                    int nActivePage = _wtoi(m_strTag);
                    if (nCount)
                        nActivePage = nActivePage % nCount;
                    ::PostMessage(pWnd->m_hWnd, WM_TABCHANGE, nActivePage, 0);
                    return pWnd->m_hWnd;
                }
            }
        }
    }
    return NULL;
}

CAIGCWinAppEx::CAIGCWinAppEx() {
  g_pAppBase = this;
  m_strProviderID = _T("");
  m_nShellCmd = CCommandLineInfo::FileNew;
}

CAIGCWinAppEx::~CAIGCWinAppEx() {
  if (m_pSpaceTelescopeImpl) {
    m_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
    m_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
  }
}

BOOL CAIGCWinAppEx::InitApplication() {
  if (WebRTInit(_T("")) ? CWinAppEx::InitApplication() : false)
    return ProcessAppType(m_bCrashReporting);
  else
    return false;
}

HWND CAIGCWinAppEx::GetActivePopupMenu(HWND hWnd) {
  CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
  if (pActivePopupMenu) {
    ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
    return pActivePopupMenu->m_hWnd;
  }
  return nullptr;
}

int CAIGCWinAppEx::Run() {
  return CWinThread::Run();
}

CString CAIGCWinAppEx::GetNames() {
  CString strNames = _T("tabctrl,");
  if (m_mapDOMObj.size()) {
    for (auto it = m_mapDOMObj.begin(); it != m_mapDOMObj.end(); it++) {
      strNames += it->first;
      strNames += _T(",");
    }
    return strNames.MakeLower();
  }
  return strNames.MakeLower();
}

CString CAIGCWinAppEx::GetTags(CString strName) {
  CString strNameBase = _T("0,1,2,3,4,5,6,7,");
  strName.Trim().MakeLower();
  if (strName != _T("")) {
    auto it = m_mapDOMObjStyle.find(strName);
    if (it != m_mapDOMObjStyle.end()) {
      strNameBase += it->second;
      strNameBase += _T(",");
      return strNameBase;
    }
  }
  return strNameBase;
}

HWND CAIGCWinAppEx::Create(HWND hParentWnd, IXobj* pXobj) {
  CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
  if (pParent == nullptr) {
    pParent = new CTangramHelperWnd();
    if (!pParent->SubclassWindow(hParentWnd)) {
      TRACE(_T("\n**********************Error**********************\n"));
      return NULL;
    }
  }
  USES_CONVERSION;
  BSTR bstrTag = ::SysAllocString(L"");

  pXobj->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
  CString m_strTag = OLE2T(bstrTag);
  ::SysFreeString(bstrTag);
  m_strTag.Trim().MakeLower();
  if (m_strTag != _T("")) {
    auto it = m_mapDOMObj.find(m_strTag);
    if (it != m_mapDOMObj.end()) {
      CRuntimeClass* pCls = (CRuntimeClass*)it->second;
      CWnd* pWnd = (CWnd*)pCls->CreateObject();
      if (pWnd) {
        if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView))) {
          AfxSetResourceHandle(AfxGetApp()->m_hInstance);
        }
        if (pWnd->Create(nullptr, _T(""), WS_CHILD | WS_VISIBLE,
                         CRect(0, 0, 0, 0), pParent, 0, nullptr)) {
          ::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, (WPARAM)pXobj, 20191031);
          if (pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
            CView* pView = static_cast<CView*>(pWnd);
            CFrameWnd* pFrame = pView->GetParentFrame();
            WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
            if (pFrame) {
              pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
                  pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
              if (pWebRTFrameWndInfo) {
                HWND hView = pWebRTFrameWndInfo->m_hClient;
                CWnd* pHostView = CWnd::FromHandlePermanent(hView);
                if (pHostView->IsKindOf(RUNTIME_CLASS(CView))) {
                  CView* _pView = (CView*)pHostView;
                  CDocument* pDoc = _pView->GetDocument();
                  if (pDoc) {
                    m_mapViewDoc[pView] = pDoc;
                    pWebRTFrameWndInfo->m_pDoc = pDoc;
                    pWebRTFrameWndInfo->m_hClient = hView;
                    pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
                  }
                }
              }
            }
          }
          return pWnd->m_hWnd;
        }
      }
    }
  }
  return NULL;
}

bool CAIGCWinAppEx::WebRTInit(CString strID) {
  if (!afxContextIsDLL) {
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);
    m_nShellCmd = cmdInfo.m_nShellCommand;
    switch (m_nShellCmd) {
      case CCommandLineInfo::AppRegister:
      case CCommandLineInfo::AppUnregister:
        return true;
      default:
        break;
    }
    if (IsBrowserModel(false)) {
      m_bBuiltInBrowser = true;
      return false;
    }
  }
  HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
  if (hModule == nullptr)
      hModule = ::LoadLibrary(L"AIGCAgent.dll");
  if (hModule == nullptr) {
      TCHAR m_szBuffer[MAX_PATH];
      if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
          m_szBuffer) == S_OK) {
          CString strChromeRTFilePath = CString(m_szBuffer);
          strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
          if (::PathFileExists(strChromeRTFilePath)) {
              hModule = ::LoadLibrary(strChromeRTFilePath);
          }
      }
      if (hModule == nullptr)
          hModule = ::LoadLibrary(L"AIGCAgent.dll");
  }
  HMODULE hModule2 = hModule;
  if (hModule) {
      BOOL isBrowserModel = false;
      FuncIsBrowserModel =
          (_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
      if (FuncIsBrowserModel != NULL) {
          isBrowserModel = FuncIsBrowserModel(false, this);
          if (isBrowserModel)
              return false;
      }
  }
  TCHAR m_szBuffer[MAX_PATH];
  TCHAR szDriver[MAX_PATH] = {0};
  TCHAR szDir[MAX_PATH] = {0};
  TCHAR szExt[MAX_PATH] = {0};
  TCHAR szFile2[MAX_PATH] = {0};
  ::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
  _tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
  CString strTangramDll = szDriver;
  strTangramDll += szDir;
  strTangramDll += _T("universe.dll");
  hModule = ::LoadLibrary(strTangramDll);
  if (hModule) {
    if (m_strContainer != _T("")) {
      m_strContainer = _T(",") + m_strContainer + _T(",");
      m_strContainer.Replace(_T(",,"), _T(","));
    }
    GetWebRTImpl _pWebRTImplFunction;
    _pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
    g_pSpaceTelescopeImpl = m_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
    g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hModule2;

    if (!afxContextIsDLL) {
      m_strProviderID += _T("host");
      m_strProviderID.MakeLower();

      m_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
      g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
                                    static_cast<IUniverseAppProxy*>(this));
      g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
                                    static_cast<IWindowProvider*>(this));
      if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
          g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
        ::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
                         (WPARAM)m_pSpaceTelescopeImpl->m_pWebRTDelegate,
                         g_pSpaceTelescopeImpl->m_nAppType);
      m_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
    } else {
      strID.Trim();
      if (strID == _T(""))
        strID = _T("component");
      if (m_strProviderID == _T("")) {
        CString strName = AfxGetApp()->m_pszAppName;
        m_strProviderID = strName + _T(".") + strID;
      }
      if (m_strProviderID != _T("")) {
        m_strProviderID.MakeLower();
        g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
                                      static_cast<IUniverseAppProxy*>(this));
        g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
                                      static_cast<IWindowProvider*>(this));
      }
      m_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
    }
  }
  return true;
}

CString CAIGCWinAppEx::QueryDocType(HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandle(hWnd);
  CFrameWnd* pFrame = pWnd->GetParentFrame();
  if (pFrame) {
    CString strType =
        (LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
    if (strType == _T("") && pFrame == m_pMainWnd &&
        pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
      strType = _T("mdiframe");
    }
    if (strType == _T("") && pFrame == m_pMainWnd &&
        pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd))) {
      strType = _T("miniframe");
    }
    return strType;
  }
  return _T("");
}

CString CAIGCWinAppEx::QueryWndClassName(HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  if (pWnd) {
    CRuntimeClass* pClassInfo = pWnd->GetRuntimeClass();
    if (pClassInfo) {
      return CString(pClassInfo->m_lpszClassName);
    }
  }
  return _T("");
}

HWND CAIGCWinAppEx::GetFrameWnd(HWND hWnd, int& nType) {
  CWnd* pWnd = CWnd::FromHandle(hWnd);
  if (pWnd) {
    CFrameWnd* pFrame = pWnd->GetParentFrame();
    if (pFrame) {
      if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
        nType = 1;
      else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
        nType = 2;
      else if (pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd)))
        nType = 4;
      else
        nType = 3;
      return pFrame->m_hWnd;
    }
  }
  return NULL;
}

HWND CAIGCWinAppEx::QueryWndInfo(QueryType nType, HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  if (pWnd) {
    if (pWnd->IsKindOf(RUNTIME_CLASS(CMDIClientAreaWnd))) {
      BOOL bMDIClient = true;
      if (nType == RecalcLayout) {
        CFrameWnd* pFrame = pWnd->GetParentFrame();
        if (pFrame) {
          pFrame->RecalcLayout();
        }
      }
      return ::GetParent(hWnd);
    }
    // if (pWnd->IsKindOf(RUNTIME_CLASS(CDockablePane)))
    //{
    //	if (nType == RecalcCtrlBarLayout)
    //	{
    //		CDockablePane* pDockablePane = (CDockablePane*)pWnd;
    //		if (pDockablePane)
    //		{
    //			if (pDockablePane->IsFloating())
    //			{
    //				pDockablePane->RecalcLayout();
    //				pDockablePane->GetParentMiniFrame(true)->RedrawAll();
    //			}
    //			if (pDockablePane->IsDocked())
    //			{
    //				pDockablePane->GetParentFrame()->RecalcLayout();
    //			}
    //		}
    //	}
    //	return ::GetParent(hWnd);
    // }
  }
  switch (nType) {
    case MainWnd:
      if (m_pMainWnd) {
        pWnd = m_pMainWnd;
        if (pWnd) {
          WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
          HANDLE hHandle = ::GetProp(pWnd->m_hWnd, _T("WebRTFrameWndInfo"));
          if (hHandle) {
            pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
            if (pWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
              pWebRTFrameWndInfo->m_nFrameType = 2;
            else {
              POSITION nPos = GetFirstDocTemplatePosition();
              while (nPos) {
                CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
                POSITION pos = pTemplate->GetFirstDocPosition();
                while (pos != NULL) {
                  CDocument* pDoc = pTemplate->GetNextDoc(pos);
                  POSITION pos2 = pDoc->GetFirstViewPosition();
                  while (pos2 != NULL) {
                    CView* pView = pDoc->GetNextView(pos2);
                    ASSERT_VALID(pView);
                    CFrameWnd* pFrame = pView->GetParentFrame();
                    if (m_pMainWnd == pFrame) {
                      if (pTemplate->IsKindOf(
                              RUNTIME_CLASS(CMultiDocTemplate))) {
                        if (!pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
                          pWebRTFrameWndInfo->m_nFrameType = 1;
                        return pWnd->m_hWnd;
                      }
                      break;
                    }
                  }
                }
              }
            }
          }
        }
        return m_pMainWnd->m_hWnd;
      }
      break;
    case CanClose: {
      if (pWnd) {
        if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
          CFrameWnd* _pFrame = (CFrameWnd*)pWnd;
          POSITION nPos = GetFirstDocTemplatePosition();
          while (nPos) {
            CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
            POSITION pos = pTemplate->GetFirstDocPosition();
            while (pos != NULL) {
              CDocument* pDoc = pTemplate->GetNextDoc(pos);
              POSITION pos2 = pDoc->GetFirstViewPosition();
              while (pos2 != NULL) {
                CView* pView = pDoc->GetNextView(pos2);
                ASSERT_VALID(pView);
                CFrameWnd* pFrame = pView->GetParentFrame();
                if (_pFrame == pFrame) {
                  if (pDoc->CanCloseFrame(pFrame)) {
                    return pFrame->m_hWnd;
                  } else
                    return NULL;
                }
              }
            }
          }
        }
      }
      // if (pWnd)// && pWnd == m_pMainWnd)
      //{
      //	POSITION nPos = GetFirstDocTemplatePosition();
      //	while (nPos)
      //	{
      //		CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
      //		POSITION pos = pTemplate->GetFirstDocPosition();
      //		while (pos != NULL)
      //		{
      //			CDocument* pDoc = pTemplate->GetNextDoc(pos);
      //			POSITION pos2 = pDoc->GetFirstViewPosition();
      //			while (pos2 != NULL)
      //			{
      //				CView* pView = pDoc->GetNextView(pos2);
      //				ASSERT_VALID(pView);
      //				CFrameWnd* pFrame =
      // pView->GetParentFrame(); 				if (m_pMainWnd !=
      // pFrame)
      //				{
      //					//pDoc->CanCloseFrame(pFrame);
      //					m_pMainWnd = pFrame;
      //					g_pSpaceTelescopeImpl->m_hMainWnd =
      // m_pMainWnd->m_hWnd; 					return
      // pFrame->m_hWnd;
      //				}
      //			}
      //		}
      //	}
      // }
      return NULL;
    } break;
    case DocView: {
      if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
        CView* pView = static_cast<CView*>(pWnd);
        WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
        CDocument* pDoc = pView->GetDocument();
        if (pDoc) {
          HWND hRetFrame = NULL;
          CDocTemplate* pTemplate = pDoc->GetDocTemplate();
          CFrameWnd* pFrame = pView->GetParentFrame();
          if (pFrame) {
            hRetFrame = pFrame->m_hWnd;
            CString strInfo = m_strCreatingDOCID;
            if (strInfo == _T(""))
              strInfo = _T("default");
            CRuntimeClass* pClsInfo = pView->GetRuntimeClass();
            CString strName = CString(pClsInfo->m_lpszClassName);
            auto it = m_mapDOMObj.find(strName);
            if (it == m_mapDOMObj.end())
              m_mapDOMObj[strName] = pClsInfo;
            bool bRet = g_pSpaceTelescopeImpl->SetFrameInfo(hWnd, hRetFrame, strInfo,
                                                   pDoc, pTemplate);
            if (pWnd->IsKindOf(RUNTIME_CLASS(CFormView)) &&
                ::GetParent(hWnd) == hRetFrame)
              ((CFormView*)pWnd)->ResizeParentToFit();

            pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
                hRetFrame, _T("WebRTFrameWndInfo"));
            if (pWebRTFrameWndInfo == nullptr) {
              __int64 nType = 0;
              if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
                nType = 2;
              else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
                nType = 3;
              else if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
                nType = 1;
              ::SetProp(hRetFrame, _T("CosmosFrameWndType"), (HANDLE)nType);
            } else {
              pWebRTFrameWndInfo->m_hClient = hWnd;
              if (pWebRTFrameWndInfo->m_pDoc == nullptr && pDoc) {
                pWebRTFrameWndInfo->m_pDoc = pDoc;
                pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
              }
              if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
                pWebRTFrameWndInfo->m_nFrameType = 2;
              else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd))) {
                pWebRTFrameWndInfo->m_nFrameType = 3;
              } else if (pTemplate->IsKindOf(
                             RUNTIME_CLASS(CMultiDocTemplate))) {
                pWebRTFrameWndInfo->m_nFrameType = 1;
              } else if (pFrame->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
                pWebRTFrameWndInfo->m_nFrameType = 4;
            }
          }
          return hRetFrame;
        }
      }
    } break;
    case QueryDestroy: {
      if (::GetParent(hWnd) == NULL)  // && m_pMainWnd && m_pMainWnd != pWnd)
      {
        m_pMainWnd = pWnd;
        return pWnd->m_hWnd;
      }
    } break;
    case ObserveComplete: {
      for (auto& it : m_mapViewDoc) {
        it.second->AddView(it.first);
      }
      m_mapViewDoc.erase(m_mapViewDoc.begin(), m_mapViewDoc.end());
    } break;
    case RecalcLayout: {
      CWnd* pWnd = CWnd::FromHandle(hWnd);
      CFrameWnd* pFrame = pWnd->GetParentFrame();
      if (pFrame) {
        pFrame->RecalcLayout();
        return pFrame->m_hWnd;
      } else {
        pWnd = CWnd::FromHandlePermanent(hWnd);
        if (pWnd && pWnd->IsFrameWnd()) {
          pFrame = (CFrameWnd*)pWnd;
          pFrame->RecalcLayout();
          return pFrame->m_hWnd;
        }
      }
    } break;
    case SetMainWndNULL: {
      if (g_pSpaceTelescopeImpl->m_hMainWnd) {
        m_pMainWnd = nullptr;
      }
    } break;
    default:
      if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CMDIClientAreaWnd))) {
        BOOL bMDIClient = true;
        return ::GetParent(hWnd);
      }
      break;
  }
  return NULL;
}

bool CAIGCWinAppEx::SetFrameCaption(HWND hWnd,
                                  CString strCaption,
                                  CString strAppName) {
  if (strCaption == _T("") || !::IsWindow(hWnd))
    return false;
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  CFrameWnd* pFrame = nullptr;
  if (pWnd) {
    if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
      pFrame = (CFrameWnd*)pWnd;
    } else {
      pFrame = pWnd->GetParentFrame();
    }
    if (pFrame) {
      WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
          pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
      if (pWebRTFrameWndInfo) {
        CDocument* pDoc = (CDocument*)pWebRTFrameWndInfo->m_pDoc;
        if (pDoc) {
          CString strPath = pDoc->GetPathName();
          if (strPath == _T("")) {
            CString strTitle = pDoc->GetTitle();
            CDocTemplate* pTemplate =
                (CDocTemplate*)pWebRTFrameWndInfo->m_pDocTemplate;
            CString name = _T("");
            pTemplate->GetDocString(name, CDocTemplate::docName);
            strTitle.Replace(name, strCaption);
            pDoc->SetTitle(strTitle);
            switch (pWebRTFrameWndInfo->m_nFrameType) {
              case 1:
              case 4:
                ::SetWindowText(pFrame->m_hWnd, strTitle + _T(" - ") +
                                                    strAppName + _T(" - ") +
                                                    g_pSpaceTelescopeImpl->m_strAppName);
                break;
              default:
                ::SetWindowText(pFrame->m_hWnd, strTitle);
                break;
            }
          }
          return true;
        }
      }
    }
  } else {
    pWnd = CWnd::FromHandle(hWnd);
    if (pWnd)
      pFrame = pWnd->GetParentFrame();
  }
  if (pFrame) {
    CString strText = _T("");
    pFrame->GetWindowText(strText);
    CString strTitle = pFrame->GetTitle();
    int nPos = strText.ReverseFind('-');
    if (nPos != -1) {
      CString s1 = strText.Left(nPos + 1);
      s1 += _T(" ");
      s1 += strCaption;
      ::SetWindowText(pFrame->m_hWnd, s1);
      pFrame->SetTitle(strCaption);
      return true;
    } else {
      pFrame->SetTitle(strCaption);
      ::SetWindowText(pFrame->m_hWnd, strCaption);
    }
    return true;
  }

  return false;
}

CString CAIGCWinAppEx::QueryParentInfo(HWND hPWnd, void* lpInfo) {
  CWnd* pParent = CWnd::FromHandlePermanent(hPWnd);
  if (pParent) {
    CFrameWnd* pParentFrame = nullptr;
    if (pParent->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
      if (pParent->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
        return _T("");
      pParentFrame = (CFrameWnd*)pParent;
    } else
      pParentFrame = pParent->GetParentFrame();
    if (pParentFrame) {
      CCreateContext* pContext = (CCreateContext*)lpInfo;
      CDocument* pDoc = pContext->m_pCurrentDoc;
      CDocTemplate* pTemplate = pContext->m_pNewDocTemplate;
      CString strExt = _T("");
      pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
      strExt.MakeLower();
      if (strExt == _T(""))
        strExt = _T("default");
      return strExt;
    }
  }
  return _T("");
}

void CAIGCWinAppEx::OpenDocFile(CString strFileName,
                              CString strExt,
                              CString strCreatingDOCID) {
  POSITION nPos = GetFirstDocTemplatePosition();
  while (nPos) {
    CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
    if (strExt == _T("")) {
      if (pTemplate) {
        m_strCreatingDOCID = strCreatingDOCID;
        if (m_bNoDefaultMainWnd)
          pTemplate->OpenDocumentFile(NULL);
        return;
      }
    }
    CString _strExt = _T("");
    pTemplate->GetDocString(_strExt, CDocTemplate::filterExt);
    _strExt.MakeLower();
    if (_strExt == _T(""))
      _strExt = _T("default");
    if (strExt != _T("") && strExt.CompareNoCase(strExt) == 0) {
      m_strCreatingDOCID = strCreatingDOCID;
      pTemplate->OpenDocumentFile(strFileName == _T("") ? NULL
                                                        : LPCTSTR(strFileName));
      return;
    }
  }
}

void CAIGCWinAppEx::OnIPCMsg(CWebPageImpl* pWebPageImpl,
                           CString strType,
                           CString strParam1,
                           CString strParam2,
                           CString strParam3,
                           CString strParam4,
                           CString strParam5) {
  if (strType.CompareNoCase(_T("COSMOS_CREATE_DOC")) == 0) {
    int nCount = 0;
    m_strCreatingDOCID = _T("");
    CDocTemplate* pTemplate = nullptr;
    POSITION nPos = GetFirstDocTemplatePosition();
    while (nPos) {
      nCount++;
      pTemplate = GetNextDocTemplate(nPos);
      CString strExt = _T("");
      pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
      strExt.MakeLower();
      if (strExt == _T(""))
        strExt = _T("default");
      if (strExt != _T("") && strExt.CompareNoCase(strParam1) == 0) {
        m_strCreatingDOCID = strParam2;
        pTemplate->OpenDocumentFile(nullptr);
        return;
      }
    }
    if (pTemplate && m_strCreatingDOCID == _T("") &&
        nCount == 1)  //&& strParam1.CompareNoCase(_T(".abc")) == 0)
    {
      m_strCreatingDOCID = strParam2;
      pTemplate->OpenDocumentFile(nullptr);
      return;
    }
  }
}

CXobjProxy* CAIGCWinAppEx::OnXobjInit(IXobj* pNewNode) {
  CComBSTR bstrName("");
  pNewNode->get_Name(&bstrName);
  CComBSTR bstrName2("");
  pNewNode->get_NameAtWindowPage(&bstrName2);
  return nullptr;
}

CNucleusProxy* CAIGCWinAppEx::OnNucleusCreated(INucleus* pNewFrame) {
  __int64 h = 0;
  pNewFrame->get_HWND(&h);
  CComBSTR bstrName("");
  pNewFrame->get_Name(&bstrName);
  return nullptr;
}

CNucleiProxy* CAIGCWinAppEx::OnNucleiCreated(INuclei* pNuclei) {
  CNucleiProxy* pNucleiProxy = nullptr;
  __int64 h = 0;
  pNuclei->get_Handle(&h);
  if (h) {
    CWnd* pWnd = CWnd::FromHandlePermanent((HWND)h);
    if (pWnd == NULL)
      return NULL;
    if (pWnd->IsKindOf(RUNTIME_CLASS(CWebRTMDIFrame))) {
      pNucleiProxy = (CNucleiProxy*)(CWebRTMDIFrame*)pWnd;
    }
    if (pNucleiProxy)
      pNucleiProxy->m_bAutoDelete = false;
  }
  return pNucleiProxy;
}

CString CAIGCWinAppEx::GetDocTemplateID(CDocument* pDoc) {
  if (pDoc) {
    POSITION nPos = pDoc->GetFirstViewPosition();
    if (nPos != NULL) {
      CView* pView = pDoc->GetNextView(nPos);
      ASSERT_VALID(pView);
      CFrameWnd* pFrame = pView->GetParentFrame();
      CString s =
          (LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
      return s;
    }
  }
  return _T("");
}

bool CAIGCWinAppEx::ProcessAppType(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32)
    return true;
  if (m_pSpaceTelescopeImpl) {
    switch (m_pSpaceTelescopeImpl->m_nAppType) {
      case APP_WIN32:
        return true;
        break;
      case APP_BROWSER:
      case APP_BROWSER_ECLIPSE: {
        if (m_pSpaceTelescopeImpl->m_nAppType == APP_BROWSER_ECLIPSE) {
#ifdef _AFXDLL
#ifdef _DEBUG
          ::MessageBox(NULL,
                       _T("Chrome-Eclipse Model is not support MFC Share Dll"),
                       _T("Warnning"), MB_OK);
#endif
          TRACE(
              _T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support ")
              _T("MFC Share Dll********\r\n\r\n"));
#endif
        }
        m_pSpaceTelescopeImpl->m_hMainWnd = NULL;
        HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
        if (hModule == nullptr)
          hModule = ::LoadLibrary(L"AIGCAgent.dll");
        if (hModule) {
          typedef int(__stdcall * _InitApp)(bool bSupportCrashReporting, void*);
          _InitApp _pInitAppFunction;
          _pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
          if (_pInitAppFunction != NULL) {
            m_bBuiltInBrowser = true;
            _pInitAppFunction(bCrashReporting, m_pSpaceTelescopeImpl->m_pWebRTDelegate);
            return false;
          }
        }
      } break;
      case APP_ECLIPSE:
        if (g_pWebRT && !m_pSpaceTelescopeImpl->m_bIsEclipseInit) {
          g_pWebRT->InitEclipseApp();
          return false;
        }
        break;
    }
  }
  return true;
}

BOOL CAIGCWinAppEx::IsBrowserModel(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32 == false) {
    HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
    if (hModule == nullptr)
      hModule = ::LoadLibrary(L"AIGCAgent.dll");
    if (hModule) {
      m_bCrashReporting = bCrashReporting;
      FuncIsBrowserModel =
          (_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
      if (FuncIsBrowserModel != NULL) {
        return FuncIsBrowserModel(bCrashReporting, this);
      }
    }
  }

  return false;
};

IMPLEMENT_DYNCREATE(CWebRTMDIFrame, CMDIFrameWndEx)

BEGIN_MESSAGE_MAP(CWebRTMDIFrame, CMDIFrameWndEx)
END_MESSAGE_MAP()

// BOOL CWebRTMDIFrame::OnCommand(WPARAM wParam, LPARAM lParam)
//{
//	HWND hWndCtrl = (HWND)lParam;
//	UINT nID = LOWORD(wParam);
//	CFrameWnd* pFrameWnd = this;
//	ENSURE_VALID(pFrameWnd);
//	if (pFrameWnd->m_bHelpMode && hWndCtrl == NULL &&
//		nID != ID_HELP && nID != ID_DEFAULT_HELP && nID !=
// ID_CONTEXT_HELP)
//	{
//		// route as help
//		if (!SendMessage(WM_COMMANDHELP, 0, HID_BASE_COMMAND + nID))
//			SendMessage(WM_COMMAND, ID_DEFAULT_HELP);
//		return TRUE;
//	}

//	// route as normal command
//	return CMDIFrameWndEx::OnCommand(wParam, lParam);
//}

LRESULT CWebRTMDIFrame::WindowProc(UINT message, WPARAM wp, LPARAM lp) {
  switch (message) {
    case WM_NCACTIVATE: {
      CMFCRibbonBar* pBar = GetRibbonBar();
      if (pBar && ::IsWindow(pBar->m_hWnd) == NULL)
        return CMDIFrameWnd::WindowProc(message, wp, lp);
      return CMDIFrameWndEx::WindowProc(message, wp, lp);
    } break;
    case WM_QUERYAPPPROXY: {
      if (lp) {
        switch (lp) {
          case 20210214: {
            if (bAdjustClient) {
              bAdjustClient = false;
              CRect rc = m_dockManager.GetClientAreaBounds();
              ::SendMessage(m_hWndMDIClient, WM_QUERYAPPPROXY,
                            (WPARAM)(LPRECT)rc, 19651965);
              m_wndClientArea.CalcWindowRectForMDITabbedGroups(rc, 0);
            }
          } break;
          case 20210215: {
            bAdjustClient = false;
            CRect rc = m_dockManager.GetClientAreaBounds();
            ::SendMessage(m_hWndMDIClient, WM_QUERYAPPPROXY, (WPARAM)(LPRECT)rc,
                          19651965);
            m_wndClientArea.CalcWindowRectForMDITabbedGroups(rc, 0);
          } break;
          case 19651965:
            RecalcLayout();
            break;
          case 19631992:
            AfxGetApp()->m_pMainWnd = this;
            break;
          case 19921989:
            if (wp) {
              LPRECT lpRC = (LPRECT)wp;
              *lpRC = m_dockManager.GetClientAreaBounds();
              return lp;
            }
            break;
        }
      }
      return CMDIFrameWndEx::WindowProc(message, wp, lp);
    } break;
  }
  return CMDIFrameWndEx::WindowProc(message, wp, lp);
}

void CWebRTMDIFrame::AdjustClientArea() {
  if (bAdjustClient == false) {
    bAdjustClient = true;
    ::PostMessage(m_hWnd, WM_QUERYAPPPROXY, 0, 20210214);
  }
  CMDIFrameWndEx::AdjustClientArea();
}

void CWebRTMDIFrame::OnTabChange(IXobj* sender, LONG ActivePage, LONG OldPage) {
  __int64 h = 0;
  sender->get_Handle(&h);
  IXobj* pActiveNode = nullptr;
  sender->GetXobj(0, ActivePage, &pActiveNode);
  CComBSTR bstrName("");
  pActiveNode->get_Name(&bstrName);
  CComBSTR bstrName2("");
  pActiveNode->get_NameAtWindowPage(&bstrName2);
}

void CWebRTMDIFrame::OnClrControlCreated(IXobj* Node,
                                         IDispatch* Ctrl,
                                         CString CtrlName,
                                         HWND CtrlHandle) {
  CComBSTR bstrName("");
  Node->get_Name(&bstrName);
  CComBSTR bstrName2("");
  Node->get_NameAtWindowPage(&bstrName2);
}

BOOL CWebRTMDIFrame::OnShowPopupMenu(CMFCPopupMenu* pMenuPopup) {
  if (pMenuPopup == nullptr || ::IsWindow(pMenuPopup->m_hWnd) == false)
    return false;
  return CMDIFrameWndEx::OnShowPopupMenu(pMenuPopup);
}
}  // namespace CommonUniverse
