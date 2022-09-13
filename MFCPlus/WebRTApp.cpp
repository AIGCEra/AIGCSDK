/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202112150001 *
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 *
 * Web Runtime is a new, subversive and Internet Oriented Development Technology
 * for Windows Desktop Software. Its core idea is that, relying on the
 *open-source project of Chromium, developers are allowed to use their familiar
 *software development technology to realize the Main Process of their
 *application system as the Browser Process of Modern Web Browser. Because the
 *Main Process is realized by the developers themselves, the application system
 *developed in this way is completely different from modern web browser. This
 *kind of application will integrate the infrastructure of modern web browser as
 *a part of the system model, the application system contains not only the
 *browser window inherent in the browser, but also other desktop elements
 *oriented to the application, such as WinForms, Java and other mature software
 *elements.
 *
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
 *based on modern javscript/Web technology.
 *
 * Built-in Full-Featured Modern Web Browser Subsystem
 *		Since the main process of the application system is essentially
 *a Browser Process, the application system can naturally create a new browser
 *window. The difference with standard browsers is that we allow the browser
 *window to be a child window of other windows. in sub-window model, we see a
 *brand-new scene: a multi-tab browser sub-window, we think this structure is
 *more suitable for organizing specific applications. Of course, the application
 *system fully supports the creation of an independent browser window as a part
 *of the complete application system, and the browser window serves as a natural
 *extension of the ecological chain to ensure the richness and diversity of the
 *application system content. DOM Plus: Because a large number of mature binary
 *components that conform to industry standards have formed a wealth of software
 *asset accumulation, web runtime allows developers to regard these existing
 *accumulation as new DOM elements and then become a part of web pages, this
 *starting point eventually forms "DOM Plus". DOM plus is a natural extension of
 *standard DOM for desktop applications, similar to the extension from "real
 *number system" to "complex number system" in mathematical theory. Undoubtedly,
 * for the development of mathematics, from "real number system" to "complex
 *number system" is a huge leap, which can be said to be a decisive change in
 *the development of modern mathematics. We hope that the evolution from "DOM"
 *to "DOM plus" will have a similar effect, which is bound to be a huge change
 *from desktop software to Internet desktop software. Different from earlier IE,
 *based on the sandbox mechanism of Modern Web Browser, we let these binary
 *elements run in the Browser Process, completely isolated from the Browser's
 *Renderer Process. This makes full use of the security mechanisms of modern
 * browsers and also takes into account the accumulation of mature software
 *component technologies. Based on such considerations, existing development
 *technologies such as .NET, COM, Java, etc. can be fully applied to Internet
 *software development.
 *
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 * In the Internet era, because the web software model has broken through the
 * limitations of local computers, this makes the software system based on
 * Internet services popular and makes desktop software appear to be dwarfed.
 * With the development of Internet technology, software content service is a
 * key topic that many software infrastructures must face, this topic further
 * highlights the dilemma of the current desktop software structure: on the one
 * hand, a large number of software component assets have been formed, on the
 * other hand, Internet services clearly represent the trend of software
 *development. Therefore, how to properly adapt the desktop software to the
 *development of the contemporary Internet is a very urgent problem and a basic
 *problem that today's desktop software must face. We know that the presentation
 *of web software needs a modern web browser, an indisputable fact is that a
 *desktop Internet web browser is also a desktop software, but because its
 *content relies on Web pages, it is almost recognized as being out of the ranks
 *of desktop software. In the age of the Internet, the difference between the
 *Desktop Software System supported by binary components and the Browser
 *Application Architecture supported by the content of Web pages has become more
 *and more prominent, and it can be said that the two are gradually moving away.
 *How Desktop Software finds its most suitable position has always been an
 *interesting topic, but there has been no proper solution. Although CEF and
 *Electron are very popular, they cannot fundamentally solve the key problem of
 *desktop software connecting to the Internet. Web Runtime tries to consider
 *this issue from a new perspective, due to the needs of Internet content
 *security and rendering, Internet giants have formed a unique Sandbox-Based
 *Multi-Process Architecture for the basic framework of the Web Browser, which
 *makes the browser structure completely different from other desktop software
 *systems in most cases. The Sandbox-Based Multi-Process Architecture indeed
 *solves many problems caused by the Internet, and it also makes the Browser
 *series and traditional desktop software form an increasingly clear difference.
 * We believe that handling this difference is the key to solving the problem of
 *Desktop Software adapting to the Internet. If we take Web Browser as the
 *smallest Desktop Software, for example, let's imagine that we use the basic
 *structure of the Web Browser as the initial structure of other desktop
 *software, what will happen? the problem will become clearer and clearer. We
 * know that in modern browser architecture, the tasks of rendering and
 *displaying web content are completed by the Render Process and GPU Process.
 *The responsibility of the Browser Process seems to be to provide a content
 *"viewport" for Web Content and "auxiliary facilities" around the web content,
 *such as tab strip, toolbar, etc. The key to the difference between Desktop
 *Software and Internet Web Browsers seems to be here. Since Chromium, Mozilla
 *and other such types of projects only focus on the Browser Architecture
 *itself, the restrictions that must be formed around the Browser Architecture
 * also appear in Chromium, for example, because Chromium is a Browser Project,
 *the implementation of the Browser Process is strictly limited to the C++
 *language level due to the project itself, from this we can see that the
 *technical constraints on the browser process are one of the key reason to the
 *huge difference between desktop software and browser software, if this
 *constraint can be broken and developers are allowed to reconstruct the Browser
 *Process while retaining the responsibility of the Browser Process, the
 *situation will be completely different. According to this thinking principle,
 * the problem will be how to use the existing Desktop Software Development
 *Technology to reconstruct the Browser Process of Web Browser Multi-Process
 *Architecture. This consideration seems to be a blind spot in the software
 *industry today, since the vast majority of software teams believe that only
 *the Browser Architecture requires the Process Separation of Browser, Renderer,
 *GPU and others, this has led to a clear difference between the software
 *structure of the browser team and the desktop software team. In order to
 * fundamentally solve the basic problem of desktop software adapting to the
 *Modern Internet, we should unify the core structure of the Browser
 *Infrastructure and the Desktop Software Infrastructure. Recognizing this, the
 *problem will become concise. We just need to consider, what conditions do
 *developers need to build their own browser process? Thanks to Google’s
 *open-source project Chromium, we can compile the Browser Process
 * Infrastructure of modern browsers into a set of dynamic link libraries, based
 *on this, today’s developers are provided with a concise use of their familiar
 *technical framework (such as .Net, Java) to construct their own Browser
 *Process according to their own wishes, therefore a new desktop software
 *construction mode appears.
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
CWebRTImpl* g_pWebRTImpl = nullptr;
CWebRTBrowserFactory* g_pBrowserFactory = nullptr;
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
    if (m_pJVMenv) {
      try {
        OutputDebugString(
            _T("\n\n***************For MFC Developer***************\n")
            _T("***************Exit Eclipse JVM from MFC***************\n\n"));
        m_pJVMenv->CallStaticVoidMethod(systemClass, exitMethod, 0);
        OutputDebugString(
            _T("\n\n***************For MFC Developer***************\n")
            _T("***************end Exit Eclipse JVM from ")
            _T("CLR***************\n\n"));
      } catch (...) {
        OutputDebugString(
            _T("\n\n***************For MFC Developer catch***************\n")
            _T("***************end Exit Eclipse JVM from ")
            _T("MFC***************\n\n"));
      }
      if (m_pJVMenv->ExceptionOccurred()) {
        OutputDebugString(
            _T("\n\n***************For MFC Developer ")
            _T("ExceptionOccurred***************\n")
            _T("***************end Exit Eclipse JVM from ")
            _T("MFC***************\n\n"));
        m_pJVMenv->ExceptionDescribe();
        m_pJVMenv->ExceptionClear();
      }
    }
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
    if (g_pWebRTImpl && g_pWebRTImpl->m_hMainWnd &&
        ::IsWindow(g_pWebRTImpl->m_hMainWnd) == false)
      g_pWebRTImpl->m_hMainWnd = NULL;
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
            if (g_pWebRTImpl->m_bIsDlgApp) {
              if (::IsChild(pApp->m_pMainWnd->m_hWnd, pMsg->hwnd)) {
                // auto it = g_pWebRTImpl->m_mapWebView.find(pMsg->hwnd);
                // if (it != g_pWebRTImpl->m_mapWebView.end())
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
    return NULL;
  }
};

CWebRTProxy theAppProxy;

CWebRTApp::CWebRTApp() {
  g_pAppBase = this;
  m_strProviderID = _T("");
  m_nShellCmd = CCommandLineInfo::FileNew;
}

CWebRTApp::~CWebRTApp() {
  TRACE(_T("\n**********************delete CWebRTApp**********************\n"));
  if (m_pWebRTImpl) {
    m_pWebRTImpl->InserttoDataMap(0, m_strProviderID, nullptr);
    m_pWebRTImpl->InserttoDataMap(1, m_strProviderID, nullptr);
  }
  CMFCVisualManager* pCMFCVisualManager = CMFCVisualManager::GetInstance();
  if (pCMFCVisualManager) {
    TRACE(
        _T("\n**********************delete ")
        _T("CMFCVisualManager**********************\n"));
    delete pCMFCVisualManager;
  }
}

BOOL CWebRTApp::InitApplication() {
  if (WebRTInit(_T("")) ? CWinApp::InitApplication() : false)
    return ProcessAppType(m_bCrashReporting);
  else
    return false;
}

HWND CWebRTApp::GetActivePopupMenu(HWND hWnd) {
  // CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
  // if (pActivePopupMenu)
  //{
  //	ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
  //	return pActivePopupMenu->m_hWnd;
  // }
  return nullptr;
}

int CWebRTApp::Run() {
  return CWinThread::Run();
}

CString CWebRTApp::GetNames() {
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

CString CWebRTApp::GetTags(CString strName) {
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

HWND CWebRTApp::Create(HWND hParentWnd, IXobj* pXobj) {
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

bool CWebRTApp::WebRTInit(CString strID) {
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
  HMODULE hModule = ::LoadLibrary(strTangramDll);
  if (hModule) {
    if (m_strContainer != _T("")) {
      m_strContainer = _T(",") + m_strContainer + _T(",");
      m_strContainer.Replace(_T(",,"), _T(","));
    }
    GetWebRTImpl _pWebRTImplFunction;
    _pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
    g_pWebRTImpl = m_pWebRTImpl = _pWebRTImplFunction(&g_pWebRT);

    if (!afxContextIsDLL) {
      m_strProviderID += _T("host");
      m_strProviderID.MakeLower();

      m_pWebRTImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
      g_pWebRTImpl->InserttoDataMap(0, m_strProviderID,
                                    static_cast<IUniverseAppProxy*>(this));
      g_pWebRTImpl->InserttoDataMap(1, m_strProviderID,
                                    static_cast<IWebRTWindowProvider*>(this));
      if (g_pWebRTImpl->m_nAppType != APP_BROWSER &&
          g_pWebRTImpl->m_nAppType != APP_BROWSER_ECLIPSE)
        ::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
                         (WPARAM)m_pWebRTImpl->m_pWebRTDelegate,
                         g_pWebRTImpl->m_nAppType);
      m_pWebRTImpl->m_pUniverseAppProxy = this;
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
        g_pWebRTImpl->InserttoDataMap(0, m_strProviderID,
                                      static_cast<IUniverseAppProxy*>(this));
        g_pWebRTImpl->InserttoDataMap(1, m_strProviderID,
                                      static_cast<IWebRTWindowProvider*>(this));
      }
      m_pWebRTImpl->m_pUniverseAppProxy = this;
    }
  }
  return true;
}

CString CWebRTApp::QueryDocType(HWND hWnd) {
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

CString CWebRTApp::QueryWndClassName(HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  if (pWnd) {
    CRuntimeClass* pClassInfo = pWnd->GetRuntimeClass();
    if (pClassInfo) {
      return CString(pClassInfo->m_lpszClassName);
    }
  }
  return _T("");
}

HWND CWebRTApp::GetFrameWnd(HWND hWnd, int& nType) {
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

HWND CWebRTApp::QueryWndInfo(QueryType nType, HWND hWnd) {
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
            bool bRet = g_pWebRTImpl->SetFrameInfo(hWnd, hRetFrame, strInfo,
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
      if (g_pWebRTImpl->m_hMainWnd) {
        m_pMainWnd = nullptr;
      }
    } break;
    default:
      break;
  }
  return NULL;
}

bool CWebRTApp::SetFrameCaption(HWND hWnd,
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
                                                    g_pWebRTImpl->m_strAppName);
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

CString CWebRTApp::QueryParentInfo(HWND hPWnd, void* lpInfo) {
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

void CWebRTApp::OpenDocFile(CString strFileName,
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

void CWebRTApp::OnIPCMsg(CWebPageImpl* pWebPageImpl,
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

CXobjProxy* CWebRTApp::OnXobjInit(IXobj* pNewNode) {
  CComBSTR bstrName("");
  pNewNode->get_Name(&bstrName);
  CComBSTR bstrName2("");
  pNewNode->get_NameAtWindowPage(&bstrName2);
  return nullptr;
}

CNucleusProxy* CWebRTApp::OnNucleusCreated(INucleus* pNewFrame) {
  __int64 h = 0;
  pNewFrame->get_HWND(&h);
  CComBSTR bstrName("");
  pNewFrame->get_Name(&bstrName);
  return nullptr;
}

CNucleiProxy* CWebRTApp::OnNucleiCreated(INuclei* pNuclei) {
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
bool CWebRTApp::InitApp() {
  if (m_bBuiltInBrowser)
    return false;
  if (ProcessAppType(m_bCrashReporting) == false)
    return false;
  return true;
}

CString CWebRTApp::GetDocTemplateID(CDocument* pDoc) {
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

bool CWebRTApp::ProcessAppType(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32)
    return true;
  if (m_pWebRTImpl) {
    switch (m_pWebRTImpl->m_nAppType) {
      case APP_WIN32:
        return true;
        break;
      case APP_BROWSER:
      case APP_BROWSER_ECLIPSE: {
        if (m_pWebRTImpl->m_nAppType == APP_BROWSER_ECLIPSE) {
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
        m_pWebRTImpl->m_hMainWnd = NULL;
        HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
        if (hModule == nullptr)
          hModule = ::LoadLibrary(L"webrt.dll");
        if (hModule == nullptr) {
          TCHAR m_szBuffer[MAX_PATH];
          if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
                              m_szBuffer) == S_OK) {
            CString strChromeRTFilePath = CString(m_szBuffer);
            strChromeRTFilePath += _T("\\WebRT\\webrt.dll");
            if (::PathFileExists(strChromeRTFilePath)) {
              hModule = ::LoadLibrary(strChromeRTFilePath);
            }
          }
          if (hModule == nullptr)
            hModule = ::LoadLibrary(L"webrt.dll");
        }
        if (hModule) {
          typedef int(__stdcall * _InitApp)(bool bSupportCrashReporting, void*);
          _InitApp _pInitAppFunction;
          _pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
          if (_pInitAppFunction != NULL) {
            m_bBuiltInBrowser = true;
            _pInitAppFunction(bCrashReporting, m_pWebRTImpl->m_pWebRTDelegate);
            return false;
          }
        }
      } break;
      case APP_ECLIPSE:
        if (g_pWebRT && !m_pWebRTImpl->m_bIsEclipseInit) {
          g_pWebRT->InitEclipseApp();
          return false;
        }
        break;
    }
  }
  return true;
}

BOOL CWebRTApp::IsBrowserModel(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32 == false) {
    HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
    if (hModule == nullptr)
      hModule = ::LoadLibrary(L"webrt.dll");
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

CWebRTAppEx::CWebRTAppEx() {
  g_pAppBase = this;
  m_strProviderID = _T("");
  m_nShellCmd = CCommandLineInfo::FileNew;
}

CWebRTAppEx::~CWebRTAppEx() {
  if (m_pWebRTImpl) {
    m_pWebRTImpl->InserttoDataMap(0, m_strProviderID, nullptr);
    m_pWebRTImpl->InserttoDataMap(1, m_strProviderID, nullptr);
  }
}

BOOL CWebRTAppEx::InitApplication() {
  if (WebRTInit(_T("")) ? CWinAppEx::InitApplication() : false)
    return ProcessAppType(m_bCrashReporting);
  else
    return false;
}

HWND CWebRTAppEx::GetActivePopupMenu(HWND hWnd) {
  CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
  if (pActivePopupMenu) {
    ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
    return pActivePopupMenu->m_hWnd;
  }
  return nullptr;
}

int CWebRTAppEx::Run() {
  return CWinThread::Run();
}

CString CWebRTAppEx::GetNames() {
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

CString CWebRTAppEx::GetTags(CString strName) {
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

HWND CWebRTAppEx::Create(HWND hParentWnd, IXobj* pXobj) {
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

bool CWebRTAppEx::WebRTInit(CString strID) {
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
  HMODULE hModule = ::LoadLibrary(strTangramDll);
  if (hModule) {
    if (m_strContainer != _T("")) {
      m_strContainer = _T(",") + m_strContainer + _T(",");
      m_strContainer.Replace(_T(",,"), _T(","));
    }
    GetWebRTImpl _pWebRTImplFunction;
    _pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
    g_pWebRTImpl = m_pWebRTImpl = _pWebRTImplFunction(&g_pWebRT);

    if (!afxContextIsDLL) {
      m_strProviderID += _T("host");
      m_strProviderID.MakeLower();

      m_pWebRTImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
      g_pWebRTImpl->InserttoDataMap(0, m_strProviderID,
                                    static_cast<IUniverseAppProxy*>(this));
      g_pWebRTImpl->InserttoDataMap(1, m_strProviderID,
                                    static_cast<IWebRTWindowProvider*>(this));
      if (g_pWebRTImpl->m_nAppType != APP_BROWSER &&
          g_pWebRTImpl->m_nAppType != APP_BROWSER_ECLIPSE)
        ::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
                         (WPARAM)m_pWebRTImpl->m_pWebRTDelegate,
                         g_pWebRTImpl->m_nAppType);
      m_pWebRTImpl->m_pUniverseAppProxy = this;
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
        g_pWebRTImpl->InserttoDataMap(0, m_strProviderID,
                                      static_cast<IUniverseAppProxy*>(this));
        g_pWebRTImpl->InserttoDataMap(1, m_strProviderID,
                                      static_cast<IWebRTWindowProvider*>(this));
      }
      m_pWebRTImpl->m_pUniverseAppProxy = this;
    }
  }
  return true;
}

CString CWebRTAppEx::QueryDocType(HWND hWnd) {
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

CString CWebRTAppEx::QueryWndClassName(HWND hWnd) {
  CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
  if (pWnd) {
    CRuntimeClass* pClassInfo = pWnd->GetRuntimeClass();
    if (pClassInfo) {
      return CString(pClassInfo->m_lpszClassName);
    }
  }
  return _T("");
}

HWND CWebRTAppEx::GetFrameWnd(HWND hWnd, int& nType) {
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

HWND CWebRTAppEx::QueryWndInfo(QueryType nType, HWND hWnd) {
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
      //					g_pWebRTImpl->m_hMainWnd =
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
            bool bRet = g_pWebRTImpl->SetFrameInfo(hWnd, hRetFrame, strInfo,
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
      if (g_pWebRTImpl->m_hMainWnd) {
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

bool CWebRTAppEx::SetFrameCaption(HWND hWnd,
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
                                                    g_pWebRTImpl->m_strAppName);
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

CString CWebRTAppEx::QueryParentInfo(HWND hPWnd, void* lpInfo) {
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

void CWebRTAppEx::OpenDocFile(CString strFileName,
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

void CWebRTAppEx::OnIPCMsg(CWebPageImpl* pWebPageImpl,
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

CXobjProxy* CWebRTAppEx::OnXobjInit(IXobj* pNewNode) {
  CComBSTR bstrName("");
  pNewNode->get_Name(&bstrName);
  CComBSTR bstrName2("");
  pNewNode->get_NameAtWindowPage(&bstrName2);
  return nullptr;
}

CNucleusProxy* CWebRTAppEx::OnNucleusCreated(INucleus* pNewFrame) {
  __int64 h = 0;
  pNewFrame->get_HWND(&h);
  CComBSTR bstrName("");
  pNewFrame->get_Name(&bstrName);
  return nullptr;
}

CNucleiProxy* CWebRTAppEx::OnNucleiCreated(INuclei* pNuclei) {
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
bool CWebRTAppEx::InitApp() {
  if (m_bBuiltInBrowser)
    return false;
  if (ProcessAppType(m_bCrashReporting) == false)
    return false;
  return true;
}

CString CWebRTAppEx::GetDocTemplateID(CDocument* pDoc) {
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

bool CWebRTAppEx::ProcessAppType(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32)
    return true;
  if (m_pWebRTImpl) {
    switch (m_pWebRTImpl->m_nAppType) {
      case APP_WIN32:
        return true;
        break;
      case APP_BROWSER:
      case APP_BROWSER_ECLIPSE: {
        if (m_pWebRTImpl->m_nAppType == APP_BROWSER_ECLIPSE) {
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
        m_pWebRTImpl->m_hMainWnd = NULL;
        HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
        if (hModule == nullptr)
          hModule = ::LoadLibrary(L"webrt.dll");
        if (hModule) {
          typedef int(__stdcall * _InitApp)(bool bSupportCrashReporting, void*);
          _InitApp _pInitAppFunction;
          _pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
          if (_pInitAppFunction != NULL) {
            m_bBuiltInBrowser = true;
            _pInitAppFunction(bCrashReporting, m_pWebRTImpl->m_pWebRTDelegate);
            return false;
          }
        }
      } break;
      case APP_ECLIPSE:
        if (g_pWebRT && !m_pWebRTImpl->m_bIsEclipseInit) {
          g_pWebRT->InitEclipseApp();
          return false;
        }
        break;
    }
  }
  return true;
}

BOOL CWebRTAppEx::IsBrowserModel(bool bCrashReporting) {
  BOOL bWin32 =
      (::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
      (::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
  if (bWin32 == false) {
    HMODULE hModule = ::GetModuleHandle(L"webrt.dll");
    if (hModule == nullptr)
      hModule = ::LoadLibrary(L"webrt.dll");
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
