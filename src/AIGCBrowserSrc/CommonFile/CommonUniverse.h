/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202110220001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web
pages,
 *    which are composed of standard DOM elements and binary components
supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet
based
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

#include <ShlObj.h>
#include <atlstr.h>
#include <map>
#include <string>
#include "jniforchrome.h"
#include "universe.h"
#include <Psapi.h>
#include <TlHelp32.h>

#define TANGRAM_CONST_OPENFILE 19920612
#define TANGRAM_CONST_NEWDOC 19631222
#define TANGRAM_CHROME_APP_INIT 20190501

#define IPC_CLR_CONTROL_CREARED 20200220
#define IPC_CLR_CONTROL_CREARED_ID _T("Tangram_CLR_Control_Created")
#define IPC_NODE_CREARED 20200221
#define IPC_NODE_CREARED_ID _T("Cosmos_WndXobj_Created")
#define IPC_NODE_ONMOUSEACTIVATE 20200222
#define IPC_NODE_ONMOUSEACTIVATE_ID _T("Tangram_WndXobj_OnMouseActivate")
#define IPC_MDIWINFORM_ACTIVEMDICHILD 20200224
#define IPC_MDIWINFORM_ACTIVEMDICHILD_ID _T("MdiWinForm_ActiveMdiChild")

#define IPC_HUBBLE_MSG_BASE 20201202
#define IPC_HUBBLE_MSG_BindCLRObject (IPC_HUBBLE_MSG_BASE + 1)
#define IPC_HUBBLE_MSG_FIRE_EVENT (IPC_HUBBLE_MSG_BASE + 2)
#define IPC_HUBBLE_MSG_WINFORM_CREATED (IPC_HUBBLE_MSG_BASE + 3)
#define IPC_HUBBLE_MSG_WINFORM_ONCLOSE (IPC_HUBBLE_MSG_BASE + 4)
#define IPC_HUBBLE_MSG_Tangram_WndXobj_Created (IPC_HUBBLE_MSG_BASE + 5)
#define IPC_HUBBLE_MSG_BIND_NATIVEOBJ_IPC_MSG (IPC_HUBBLE_MSG_BASE + 6)
#define IPC_HUBBLE_MSG_MdiWinForm_ActiveMdiChild (IPC_HUBBLE_MSG_BASE + 7)
#define IPC_HUBBLE_MSG_MdiWinForm_Ready (IPC_HUBBLE_MSG_BASE + 8)
#define IPC_HUBBLE_MSG_MDIFORM_ALLMDICHILDREMOVED (IPC_HUBBLE_MSG_BASE + 9)
#define IPC_HUBBLE_MSG_OPEN_XML_SPLITTER (IPC_HUBBLE_MSG_BASE + 10)

#define APP_WIN32 500
#define APP_BROWSER 1000
#define APP_ECLIPSE 2000
#define APP_BROWSER_ECLIPSE 3000
#define APP_BROWSERAPP 4000

#define APP_WILLCLOSE 2019
#define APP_OTHER 0
#define APP_SDI 1965
#define APP_MDI 1992
#define APP_MDT 1963

#define WM_XOBJCREATED (WM_USER + 0x00004001)
#define WM_OPENDOCUMENT (WM_USER + 0x00004002)
#define WM_SPLITTERREPOSITION (WM_USER + 0x00004003)
#define WM_ECLIPSEWORKBENCHCREATED (WM_USER + 0x00004004)
#define WM_TABCHANGE (WM_USER + 0x00004005)
#define WM_COSMOSMSG (WM_USER + 0x00004006)
#define WM_CLOUDMSGRECEIVED (WM_USER + 0x00004007)
#define WM_OFFICEOBJECTCREATED (WM_USER + 0x00004008)
#define WM_MDICHILDMIN (WM_USER + 0x00004009)
#define WM_HUBBLE_APPQUIT (WM_USER + 0x0000400b)
#define WM_HUBBLE_DATA (WM_USER + 0x0000400c)
#define WM_DOWNLOAD_MSG (WM_USER + 0x0000400d)
#define WM_HUBBLE_NEWOUTLOOKOBJ (WM_USER + 0x0000400e)
#define WM_HUBBLE_ACTIVEINSPECTORPAGE (WM_USER + 0x0000400f)
#define WM_USER_TANGRAMTASK (WM_USER + 0x00004010)
#define WM_SETWNDFOCUSE (WM_USER + 0x00004011)
#define WM_UPLOADFILE (WM_USER + 0x00004012)
#define WM_HUBBLE_DESIGNMSG (WM_USER + 0x00004013)
#define WM_INSERTTREENODE (WM_USER + 0x00004014)
#define WM_REFRESHDATA (WM_USER + 0x00004015)
#define WM_GETSELECTEDNODEINFO (WM_USER + 0x00004016)
#define WM_HUBBLE_DESIGNERCMD (WM_USER + 0x00004017)
#define WM_HUBBLE_GETTREEINFO (WM_USER + 0x00004018)
#define WM_HUBBLE_GETNODE (WM_USER + 0x00004019)
#define WM_HUBBLE_UPDATENODE (WM_USER + 0x0000401a)
#define WM_HUBBLE_SAVE (WM_USER + 0x0000401b)
#define WM_MDICLIENTCREATED (WM_USER + 0x0000401c)
#define WM_TGM_SETACTIVEPAGE (WM_USER + 0x0000401d)
#define WM_TGM_SET_CAPTION (WM_USER + 0x0000401e)
#define WM_GETNODEINFO (WM_USER + 0x0000401f)
#define WM_CREATETABPAGE (WM_USER + 0x00004020)
#define WM_ACTIVETABPAGE (WM_USER + 0x00004021)
#define WM_MODIFYTABPAGE (WM_USER + 0x00004022)
#define WM_ADDTABPAGE (WM_USER + 0x00004023)
#define WM_HUBBLE_ITEMLOAD (WM_USER + 0x00003024)
#define WM_INITOUTLOOK (WM_USER + 0x00004026)

#define WM_QUERYAPPPROXY (WM_USER + 0x00004028)
#define WM_HUBBLE_ACTIVEPAGE (WM_USER + 0x00004029)
#define WM_HUBBLE_SETAPPTITLE (WM_USER + 0x0000402a)
#define WM_LYNCIMWNDCREATED (WM_USER + 0x0000402b)
#define WM_STOPTRACKING (WM_USER + 0x0000402c)
#define WM_HUBBLE_INIT (WM_USER + 0x0000402d)
#define WM_VSSHOWPROPERTYGRID (WM_USER + 0x0000402e)
#define WM_REMOVERESTKEY (WM_USER + 0x0000402f)
#define WM_HUBBLE_GETXML (WM_USER + 0x00004030)
#define WM_CHROMEWEBCLIENTCREATED (WM_USER + 0x00004031)
#define WM_CHROMERENDERERFRAMEHOSTINIT (WM_USER + 0x00004032)
#define WM_CHROMEOPENWINDOWMSG (WM_USER + 0x00004033)
#define WM_BROWSERLAYOUT (WM_USER + 0x00004034)
#define WM_CHROMEMSG (WM_USER + 0x00004035)
#define WM_CHROMEWNDPARENTCHANGED (WM_USER + 0x00004035)
#define WM_DEVICESCALEFACTORCHANGED (WM_USER + 0x00004036)
#define WM_CHROMEDEVTOOLMSG (WM_USER + 0x00004037)
#define WM_BACKGROUNDWEBPROXY_MSG (WM_USER + 0x00004039)
#define WM_CHROMEWNDNODEMSG (WM_USER + 0x00004040)
#define WM_DOCUMENTONLOADCOMPLETED (WM_USER + 0x00004043)
#define WM_DOCUMENTFAILLOADWITHERROR (WM_USER + 0x00004044)
#define WM_CHROMEHELPWND (WM_USER + 0x00004045)
#define WM_CHROMEOMNIBOXPOPUPVISIBLE (WM_USER + 0x00004046)
#define WM_HOSTNODEFORSPLITTERCREATED (WM_USER + 0x00004047)
#define WM_CHROMEOPENURLMSG (WM_USER + 0x00004048)
#define WM_LBUTTONDOWNEX (WM_USER + 0x00004049)
#define WM_WINFORMCREATED (WM_USER + 0x0000404a)
#define WM_CHROMEIPCMSG (WM_USER + 0x00004052)
#define WM_CHROMEAPPINIT (WM_USER + 0x00004053)
#define WM_COSMOSOBSERVED (WM_USER + 0x00004054)

#define GUID_Compatibility_Vista	_T("{e2011457-1546-43c5-a5fe-008deee3d3f0}")
#define GUID_Compatibility_Win7		_T("{35138b9a-5d96-4fbd-8e2d-a2440225f93a}")
#define GUID_Compatibility_Win8		_T("{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}")
#define GUID_Compatibility_Win81	_T("{1f676c76-80e1-4239-95bb-83d0f6d0da78}")
#define GUID_Compatibility_Win10	_T("{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}")

#define TANGRAM_OBJECT_ENTRY_AUTO(clsid, class)                             \
  __declspec(selectany) ATL::_ATL_OBJMAP_CACHE __objCache__##class = {NULL, \
                                                                      0};   \
  const ATL::_ATL_OBJMAP_ENTRY_EX __objMap_##class = {                      \
      &clsid,                                                               \
      class ::UpdateRegistry,                                               \
      class ::_ClassFactoryCreatorClass::CreateInstance,                    \
      class ::CreateInstance,                                               \
      &__objCache__##class,                                                 \
      class ::GetObjectDescription,                                         \
      class ::GetCategoryMap,                                               \
      class ::ObjectMain};                                                  \
  extern "C" __declspec(allocate("ATL$__m")) __declspec(selectany)          \
      const ATL::_ATL_OBJMAP_ENTRY_EX* const __pobjMap_##class              \
      = &__objMap_##class;                                                  \
  OBJECT_ENTRY_PRAGMA(class)

#define OBJECT_ENTRY_AUTO_EX(clsid, class)                                  \
  __declspec(selectany) ATL::_ATL_OBJMAP_CACHE __objCache__##class = {NULL, \
                                                                      0};   \
  const ATL::_ATL_OBJMAP_ENTRY_EX __objMap_##class = {                      \
      &clsid,                                                               \
      class ::UpdateRegistry,                                               \
      class ::_ClassFactoryCreatorClass::CreateInstance,                    \
      class ::CreateInstance,                                               \
      &__objCache__##class,                                                 \
      class ::GetObjectDescription,                                         \
      class ::GetCategoryMap,                                               \
      class ::ObjectMain};                                                  \
  extern "C" __declspec(allocate("ATL$__m")) __declspec(selectany)          \
      const ATL::_ATL_OBJMAP_ENTRY_EX* const __pobjMap_##class              \
      = &__objMap_##class;                                                  \
  OBJECT_ENTRY_PRAGMA(class)

#define TGM_NAME _T("name")
#define TGM_CAPTION _T("caption")
#define TGM_GRID_TYPE _T("gridtype")
#define TGM_OBJ_ID _T("objid")
#define TGM_HEIGHT _T("height")
#define TGM_WIDTH _T("width")
#define TGM_STYLE _T("style")
#define TGM_ACTIVE_PAGE _T("activepage")
#define TGM_TAG _T("tag")
#define TGM_XOBJ _T("xobj")
#define TGM_NUCLEUS _T("nucleus")

#define TGM_ROWS _T("rows")
#define TGM_COLS _T("cols")

#define TGM_SETTING_HEAD _T("#$^&TANGRAM")
#define TGM_SETTING_FOMRAT _T("#$^&TANGRAM[%ld][%ld]")

#define TGM_S_EXCEL_INPUT 1

namespace CommonUniverse {
	using namespace std;
	using namespace ATL;

	class CChromeTab;
	class CWebRTImpl;
	class IContainer;
	class CChromeTabProxy;
	class CSession;
	class IWebRTDelegate;
	class CChromeBrowserBase;
	class CBrowserImpl;
	class CChromeRenderProcess;
	class CChromeWebContentBase;
	class CWebRTMainDllLoader;
	class OmniboxViewViewsProxy;
	class CWebRTBrowserFactory;
	class CChromeRenderProcessProxy;
	class CChromeWebContentProxyBase;
	class CChromeRenderFrameHost;
	class CChromeChildProcessHostImpl;
	class CWebViewImpl;
	class IWindowProvider;
	class CTabStatsTrackerDelegate;
	class CosmosAppMessagePumpForUI;
	class CChromeBookmarkTabHelper;
	class CChromeBookmarkTabHelperDelegate;
	class CChromeChildProcessHostImplProxy;

	class IWebRTCLRImpl;
	class IUniverseAppProxy;

	extern CWebRTImpl* g_pSpaceTelescopeImpl;

	enum class BrowserTabChangeType {
		// Everything changed.
		All,
		// Only the loading state changed.
		LoadingOnly,
	};

	enum class CosmosCloseState {
		StartClose,
		FinalBrowserClose,
		ProcessQuit,
	};

	typedef enum WebRTRunModel {
		WebRTModel = 0x00000000,
		RunNormal = 0x00000001,
		RunFromBrowser = 0x00000002,
		RunFromBrowserAsWinApp = 0x00000003,
	} WebRTRunModel;

	typedef enum QueryType {
		MainWnd = 0x00000000,
		CanClose = 0x00000001,
		DocView = 0x00000002,
		OtherType = 0x00000003,
		QueryDestroy = 0x00000004,
		CanAddView = 0x00000005,
		ObserveComplete = 0x00000006,
		RecalcLayout = 0x00000007,
		RecalcCtrlBarLayout = 0x00000008,
		SetMainWndNULL = 0x00000009,
		WinApp = 0x0000000a
	} QueryType;

	typedef enum NucleusParentType {
		MFCFrame = 0x00000000,
		MFCMDIFrame = 0x00000001,
		MFCMDIChild = 0x00000002,
		WinForm = 0x00000003,
		MDIWinForm = 0x00000004,
		MdiChildForm = 0x00000005,
		Other = 0x00000006
	} NucleusParentType;

	typedef struct IPCMsg {
		CString m_strId = _T("");
		CString m_strParam1 = _T("");
		CString m_strParam2 = _T("");
		CString m_strParam3 = _T("");
		CString m_strParam4 = _T("");
		CString m_strParam5 = _T("");
		long m_nHandleFrom = 0;
		long m_nHandleTo = 0;
	} IPCMsg;

	typedef struct _ProcessData
	{
		HWND m_hWnd = 0;
		DWORD dwProcessID = 0;
		DWORD dwThreadID = 0;
	}ProcessData;

	typedef struct ProcessInfo {
		int nDelaySecond = 0;
		int nDelaySecond2 = 0;
		bool bCompatibilityWin10 = false;
		DWORD processID = 0;
		DWORD threadID = 0;
		HWND hWnd = NULL;
		HWND hCosmosWnd = NULL;
		HANDLE processHandle = NULL;
		CString processProxyPath = _T("");
		CString processConfigPath = _T("");
		CString processConfigDataPath = _T("");
	} ProcessInfo;

	typedef struct WebRTInfo {
		HWND m_hCtrlHandle = nullptr;
		HWND m_pParentForm = nullptr;
		HWND m_pMDIParent = nullptr;
		CString m_strName = _T("");
		CString m_strNodeName = _T("");
		CString m_strXobjXml = _T("");
		CString m_strSessionID = _T("");
		CString m_strTag = _T("");
		IXobj* m_pXobj = nullptr;
		INucleus* m_pNucleus = nullptr;
		INuclei* m_pNuclei = nullptr;
	} WebRTInfo;

	typedef struct NucleusInfo {
		HWND m_hCtrlHandle;
		IDispatch* m_pDisp;
		IDispatch* m_pParentDisp;
		CString m_strCtrlName;
		CString m_strNucleusName;
		CString m_strXobjXml;
		CString m_strParentCtrlName;
	} NucleusInfo;

	typedef struct DocTemplateInfo {
		bool bDll;
		int nResID;
		CString strProxyName;
		CString strProxyID;
		CString strFileTypeID;
		CString strExt;
		CString strfilterName;
	} DocTemplateInfo;

	typedef struct WebRTFrameWndInfo {
		bool bControlBarProessed = false;
		NucleusParentType m_nType = Other;
		int m_nFrameType = 0;  // 0:SDI;1:MDT;2:MDI;3:MDIChild
		HWND m_hClient = NULL;
		bool m_bSZMode = false;
		CString m_strData = _T("");
		CString m_strDocTemplateID = _T("");
		IWebView* m_pWebView = nullptr;
		void* m_pDoc = nullptr;
		void* m_pHostWnd = nullptr;
		void* m_pDocTemplate = nullptr;
		map<DWORD, HWND> m_mapCtrlBarWnd;
		map<DWORD, INucleus*> m_mapCtrlBarNucleus;
	} WebRTFrameWndInfo;

	typedef struct CtrlInfo {
		HWND m_hWnd;
		CString m_strName;
		INuclei* m_pNuclei;
		IXobj* m_pXobj;
		IDispatch* m_pCtrlDisp;
	} CtrlInfo;

	typedef struct IPCSession {
	public:
		std::map<std::wstring, std::wstring> m_mapString;
		std::map<std::wstring, long> m_mapLong;
		std::map<std::wstring, __int64> m_mapint64;
		std::map<std::wstring, float> m_mapFloat;
	} IPCSession;

	class CSession {
	public:
		CSession() {}
		virtual ~CSession() {}

		CWebViewImpl* m_pOwner;

		virtual void InsertString(CString key, CString value) {}
		virtual void InsertLong(CString key, long value) {}
		virtual void Insertint64(CString key, __int64 value) {}
		virtual void InsertFloat(CString key, float value) {}
		virtual CString GetString(CString key) { return _T(""); }
		virtual long GetLong(CString key) { return 0; }
		virtual __int64 Getint64(CString key) { return 0; }
		virtual float GetFloat(CString key) { return 0; }
		virtual void SendMessage() {}
		virtual void addEventListener(CString ListenerName) {}
		virtual void removeEventListener(CString ListenerName) {}
	};

	class CCommonFunction {
	public:
		template <class T>
		static BOOL ClearObject(T* pObject) {
			BOOL bRet = FALSE;
			if (pObject != NULL) {
				ULONG dw = pObject->Release();
				while (dw > 0)
					dw = pObject->Release();
				bRet = TRUE;
			}
			return bRet;
		}
	};

	class CosmosUIItemData {
	public:
		CosmosUIItemData() {}
		~CosmosUIItemData() {}
		LPARAM lParam = 0;
		CString m_strType = _T("treectrl");
		CString m_strKey = _T("");
		CString m_strData = _T("");
		CosmosUIItemData* m_pParent = nullptr;
		void* m_hParentItem = nullptr;
		map<CString, CosmosUIItemData*> m_mapChild;
	};

	class CMDIChildFormInfo {
	public:
		CMDIChildFormInfo() {
		}
		~CMDIChildFormInfo() {
			m_mapFormsInfo.erase(m_mapFormsInfo.begin(), m_mapFormsInfo.end());
		}
		map<CString, CString> m_mapFormsInfo;
	};

	typedef CWebRTImpl* (__stdcall* GetWebRTImplFunction)(IWebRT** ppWebRT);

	class CWPFObj {
	public:
		CWPFObj() {
			m_pDisp = nullptr;
			m_hwndWPF = nullptr;
		}
		~CWPFObj() {}
		HWND m_hwndWPF;
		IDispatch* m_pDisp;
		map<CString, IDispatch*> m_mapWPFObj;
		virtual BOOL IsVisible() { return false; }
		virtual void InvalidateVisual() {}
		virtual void ShowVisual(BOOL bShow) {}
		virtual void Focusable(BOOL bFocus) {}
	};

	class CXobjProxy {
	public:
		CXobjProxy() {}
		virtual ~CXobjProxy() {}

		bool m_bAutoDelete;

		virtual void OnObserveComplete() {}
		virtual void OnDestroy() {}
		virtual void OnXobjAddInCreated(IDispatch* pAddIndisp,
			CString bstrAddInID,
			CString bstrAddInXml) {}
		virtual void OnXobjAddInsCreated() {}
		virtual void OnXobjDocumentComplete(IDispatch* ExtenderDisp,
			CString bstrURL) {}
		virtual void OnControlNotify(IXobj* sender,
			LONG NotifyCode,
			LONG CtrlID,
			HWND CtrlHandle,
			CString CtrlClassName) {}
		virtual void OnTabChange(LONG ActivePage, LONG OldPage) {}
		virtual void OnWebRTDocEvent(IWebRTEventObj* pEventObj) {}
	};

	class CNucleiProxy {
	public:
		CNucleiProxy() {}
		virtual ~CNucleiProxy() {}

		bool m_bAutoDelete;

		virtual void OnNucleiLoaded(IDispatch* sender, CString url) {}
		virtual void OnXobjCreated(IXobj* pXobjCreated) {}
		virtual void OnAddInCreated(IXobj* pRootXobj,
			IDispatch* pAddIn,
			CString bstrID,
			CString bstrAddInXml) {}
		virtual void OnBeforeOpenXml(CString bstrXml, HWND hWnd) {}
		virtual void OnOpenXmlComplete(CString bstrXml,
			HWND hWnd,
			IXobj* pRetRootNode) {}
		virtual void OnDestroy() {}
		virtual void OnNodeMouseActivate(IXobj* pActiveNode) {}
		virtual void OnClrControlCreated(IXobj* Node,
			IDispatch* Ctrl,
			CString CtrlName,
			HWND CtrlHandle) {}
		virtual void OnTabChange(IXobj* sender, LONG ActivePage, LONG OldPage) {}
		virtual void OnEvent(IDispatch* sender, IDispatch* EventArg) {}
		virtual void OnControlNotify(IXobj* sender,
			LONG NotifyCode,
			LONG CtrlID,
			HWND CtrlHandle,
			CString CtrlClassName) {}
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {}
	};

	class CNucleusProxy {
	public:
		CNucleusProxy() {}
		virtual ~CNucleusProxy() {}

		bool m_bAutoDelete;
		virtual void OnExtend(IXobj* pRetNode, CString bstrKey, CString bstrXml) {}
	};

	class CWebRTDocProxy {
	public:
		CWebRTDocProxy() {}
		virtual ~CWebRTDocProxy() {
			m_bDocLoaded = false;
			m_bCanDestroyFrame = true;
			m_strCosmosData = _T("");
		}

		BOOL m_bDocLoaded;
		BOOL m_bCanDestroyFrame;
		CString m_strTangramID;
		CString m_strAppProxyID;
		CString m_strAppName;
		CString m_strMainFrameID;
		CString m_strDocID;
		CString m_strCosmosData;

		virtual void CosmosDocEvent(IWebRTEventObj* pEventObj) {}
	};

	class IUniverseAppProxy {
	public:
		IUniverseAppProxy() {
			m_bWebRTInit = TRUE;
			m_bAutoDelete = TRUE;
			m_hMainWnd = nullptr;
			m_hClosingFrame = m_hCreatingView = nullptr;
			m_pvoid = nullptr;
			m_pCurDocProxy = nullptr;
			m_pMDIClientAreaWnd = nullptr;
			m_strProxyName = _T("");
			m_strProxyID = _T("");
			m_strClosingFrameID = _T("");
			m_strCreatingFrameTitle = _T("");

			m_bCreatingNewFrame = FALSE;

			m_nFrameIndex = 0;
			m_strAppKey = _T("");
			m_strCreatingDOCID = _T("");
		}

		virtual ~IUniverseAppProxy() {}

		int m_nShellCmd = -1;
		int m_nFrameIndex;
		BOOL m_bWebRTInit;
		BOOL m_bAutoDelete;
		BOOL m_bCreatingNewFrame;
		HWND m_hMainWnd;
		HWND m_hCreatingView;
		HWND m_hClosingFrame;
		LPCTSTR m_strProxyName;
		LPCTSTR m_strProxyID;
		LPCTSTR m_strCreatingFrameTitle;
		LPCTSTR m_strClosingFrameID;

		CString m_strAppKey;
		CString m_strCreatingDOCID = _T("");
		CString m_strStartOpenFile = _T("");

		void* m_pvoid;
		void* m_pMDIClientAreaWnd = NULL;
		CWebRTDocProxy* m_pCurDocProxy;

		RECT m_ClientRect;

		virtual BOOL InitWebRT(void* pVoid) { return TRUE; }
		virtual BOOL CosmosSaveAllModified() { return TRUE; }

		virtual void OnActiveMainFrame(HWND) {}
		virtual int OnDestroyMainFrame(CString strID,
			int nMainFrameCount,
			int nWndType) {
			return -1;
		}
		virtual LRESULT OnForegroundIdleProc() { return 0; }
		virtual BOOL UniversePreTranslateMessage(MSG* pMsg) { return false; }
		virtual bool EclipseAppInit() { return false; }
		virtual bool SetFrameCaption(HWND hWnd,
			CString strCaption,
			CString strAppName) {
			return false;
		}
		virtual void OnWebRTClose(CosmosCloseState state) {}
		virtual void OnObserveComplete(HWND hWnd, CString bstrUrl, IXobj* pRootXobj) {
		}
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {}
		virtual void MouseMoveProxy(HWND hWnd) {}
		virtual void OpenDocFile(CString strFileName,
			CString strExt,
			CString strCreatingDOCID) {}
		virtual HWND GetActivePopupMenu(HWND) { return NULL; }
		virtual HRESULT CreateCosmosCtrl(void* pv, REFIID riid, LPVOID* ppv) {
			return S_OK;
		}
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode) { return nullptr; }
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewNucleus) {
			return nullptr;
		}
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewNucleus) {
			return nullptr;
		}
		virtual HWND InitWebRTApp() { return NULL; }
		virtual void OnWebAppData(CWebViewImpl*, CString strXml) {}
		virtual HWND OnWinFormCreated(CWebViewImpl*, CString strXml) { return NULL; }
		virtual CWebViewImpl* OnNewWebPage(CBrowserImpl*, CString strXml) {
			return NULL;
		}
		virtual void OnIPCMsg(CWebViewImpl* pWebViewImpl,
			CString strType,
			CString strParam1,
			CString strParam2,
			CString strParam3,
			CString strParam4,
			CString strParam5) {}
		virtual void CustomizedDOMElement(HWND hWnd,
			CString strRuleName,
			CString strHTML) {}
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd) { return NULL; }
		virtual CString QueryDocType(HWND hWnd) { return _T(""); }
		virtual CString QueryWndClassName(HWND hWnd) { return _T(""); }
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo) { return _T(""); }
		virtual HWND GetFrameWnd(HWND hWnd, int& nType) { return NULL; }
		virtual void OnCustomizedMainWindowElement(HWND hMainWnd, CString strXml) {}
		virtual HWND GetDockablePane(HWND hFrame, int nID) { return NULL; }
		virtual HWND GetFrameClientHandle(HWND hFrame, CString strScript) { return NULL; }
		virtual RECT GetClientAreaBounds() { return RECT{ 0, 0, 0, 0 }; }
		virtual void CalcWindowRectForMDITabbedGroups(LPRECT rc) {}
		virtual bool AttachWebRT() { return false; }
	};

	class ITabClientAreaProxy {
	public:
		ITabClientAreaProxy() {}
		virtual ~ITabClientAreaProxy() {}
		virtual RECT GetClientAreaBounds() { return RECT{ 0, 0, 0, 0 }; }
		virtual void CalcWindowRectForMDITabbedGroups(LPRECT rc) {}
	};

	class IWinAppProxyImpl {
	public:
		IWinAppProxyImpl() {}
		virtual ~IWinAppProxyImpl() {}
		virtual DWORD ExecCmd(CString cmd, CString strInfo, bool setCurrentDirectory) { return 0; }
	};

	class IWebRTCLRImpl {
	public:
		IWebRTCLRImpl() {}

		CString m_strCurrentWinFormTemplate;

		virtual IDispatch* CreateCLRObj(CString bstrObjID) { return nullptr; }
		virtual IDispatch* CreateCLRObjRemote(CString bstrObjID,
			CString strXmlData,
			HWND hHostWnd) {
			return nullptr;
		}
		virtual HRESULT ProcessCtrlMsg(HWND hCtrl, bool bShiftKey) { return 0; }
		virtual BOOL ProcessFormMsg(HWND hFormWnd, LPMSG lpMsg, int nMouseButton) {
			return false;
		}
		virtual IDispatch* CreateObject(BSTR bstrObjID,
			HWND hParent,
			IXobj* pHostNode,
			CWebViewImpl*,
			IWebView*) {
			return nullptr;
		}
		virtual int IsWinForm(HWND hWnd) { return 0; }
		virtual HWND GetParentWinForm(HWND hWnd) { return nullptr; }
		virtual HWND GetWinForm(HWND hWnd, __int64& nMDIParent) { return nullptr; }
		virtual IDispatch* GetCLRControl(IDispatch* CtrlDisp, BSTR bstrNames) {
			return nullptr;
		}
		virtual BSTR GetCtrlName(IDispatch* pCtrl) { return CComBSTR(""); }
		virtual IDispatch* GetCtrlFromHandle(HWND hWnd) { return nullptr; }
		virtual HWND GetMDIClientHandle(IDispatch* pMDICtrl) { return NULL; }
		virtual IDispatch* GetCtrlByName(IDispatch* CtrlDisp,
			BSTR bstrName,
			bool bFindInChild) {
			return nullptr;
		}
		virtual HWND GetCtrlHandle(IDispatch* pCtrl) { return NULL; }
		virtual BSTR GetCtrlType(IDispatch* pCtrl) { return CComBSTR(""); }
		virtual HWND IsNucleus(IDispatch* ctrl) { return NULL; }
		virtual void CosmosAction(BSTR bstrXml, void*) {}
		virtual BSTR GetCtrlValueByName(IDispatch* CtrlDisp,
			BSTR bstrName,
			bool bFindInChild) {
			return CComBSTR("");
		}
		virtual void SetCtrlValueByName(IDispatch* CtrlDisp,
			BSTR bstrName,
			bool bFindInChild,
			BSTR strVal) {}
		virtual void ReleaseCosmosObj(IDispatch*) {}
		virtual void WindowCreated(LPCTSTR strClassName,
			LPCTSTR strName,
			HWND hPWnd,
			HWND hWnd) {}
		virtual void WindowDestroy(HWND hWnd) {}
		virtual CWPFObj* CreateWPFControl(IXobj* pXobj, HWND hPWnd, UINT nID) {
			return nullptr;
		}
		virtual HRESULT NavigateURL(IXobj* pXobj,
			CString strURL,
			IDispatch* dispObjforScript) {
			return S_FALSE;
		}
		virtual void OnCLRHostExit() {}
		virtual void OnDestroyChromeBrowser(IBrowser*) {}
		virtual void SetObjectProperty(IDispatch* pObj,
			BSTR bstrPropertyName,
			BSTR bstrPropertyValue) {}
		virtual void* Extend(CString strKey, CString strData, CString strFeatures) {
			return nullptr;
		}
		virtual HICON GetAppIcon(int nIndex) { return NULL; }
		virtual IDispatch* CreateWinForm(HWND hParent, BSTR strXML) {
			return nullptr;
		}
		virtual void OnWebPageCreated(HWND,
			CWebViewImpl*,
			IWebView* pChromeWebContent,
			int nState) {}
		virtual bool PreWindowPosChanging(HWND hWnd, WINDOWPOS* lpwndpos, int nType) {
			return false;
		}
		virtual void OnCloudMsgReceived(CSession*) {}
		virtual void ConnectXobjToWebPage(IXobj*, bool) {}
		virtual void ProcessFormWorkState(HWND hForm, int nState) {}
		virtual int GetCLRObjType(CString bstrObjID) { return 1000; }
		virtual void ResetMenuStripState(HWND hForm) {}
	};

	class CWebRTImpl {
	public:
		CWebRTImpl() {
			m_bIsNoWebRT = false;
			m_bHostMsgLoop = false;
			m_hParent = NULL;
			m_hWebRTProxyModel = nullptr;
			m_hSmallIcon = nullptr;
			m_hLargeIcon = nullptr;
			m_hFormNodeWnd = nullptr;
			m_hMainWnd = nullptr;
			m_hCosmosWnd = nullptr;
			m_pCLRProxy = nullptr;
			m_pSession = nullptr;
			m_pActiveAppProxy = nullptr;
			m_pWebRTAppProxy = nullptr;
			m_pUniverseAppProxy = nullptr;
			m_pCurMDIChildFormInfo = nullptr;
			m_strAppID = _T("");
			m_strNtpXml = _T("");
			m_strWebRTVer = _T("");
		}

		virtual ~CWebRTImpl() {}

		bool m_bHostMsgLoop = false;
		bool m_bChromeNeedClosed = false;
		bool m_bCreatingDevTool = false;
		bool m_bOMNIBOXPOPUPVISIBLE = false;
		bool m_b64bitSystem = false;
		bool m_bOfficeApp = false;
		bool m_bEclipse = false;
		bool m_bIsDlgApp = false;
		bool m_bIsNoWebRT = false;
		bool m_bCanClose = false;
		bool m_bWinFormActived = false;
		bool m_bEnableProcessFormTabKey = false;
		bool m_bDeleteNuclei = false;
		bool m_bIsSupportCrashReporting = false;
		bool m_bIsEclipseInit = false;
		bool m_bIsCreatingWPFCtrl = false;

		DWORD m_dwThreadID = 0;
		DWORD m_nAppType = 0;
		HWND m_hFirstView = nullptr;
		HWND m_hActiveWnd = NULL;
		HWND m_hEclipseHideWnd = NULL;
		HWND m_hMainWnd = NULL;
		HWND m_hCosmosWnd = NULL;
		HWND m_hFormNodeWnd = NULL;
		HWND m_hParent = NULL;
		HWND m_hHostBrowserWnd = NULL;
		HWND m_hTempBrowserWnd = NULL;
		HWND m_hWaitTabWebPageWnd = NULL;

		HMODULE m_hWebRTProxyModel = NULL;

		HICON m_hLargeIcon = NULL;
		HICON m_hSmallIcon = NULL;

		CString m_strAppID = _T("");
		CString m_strAppKey = _T("");
		CString m_strAppName = _T("");
		CString m_strExeName = _T("");
		CString m_strWebRTVer = _T("");
		CString m_strAppPath = _T("");
		CString m_strConfigDataFile = _T("");
		CString m_strAppDataPath = _T("");
		CString m_strCurrentAppID = _T("");
		CString m_strProgramFilePath = _T("");
		CString m_strAppCommonDocPath = _T("");
		CString m_strStartView = _T("");
		CString m_strNtpXml = _T("");
		CString m_strAppXml = _T("");
		CString m_strCosmosDllMD5 = _T("");
		CString m_strUniverseDllMD5 = _T("");
		CString m_strMainWndXml = _T("");
		CString m_strDefaultWorkBenchXml = _T("");

		CString m_strConfigFile = _T("");

		CString m_strCurrentKey = _T("");
		CString m_strWorkBenchStrs = _T("");
		CString m_strStartupURL = _T("");
		CString m_strCurrentEclipsePagePath = _T("");
		CString m_strDefaultXml = _T("");

		CStringA m_strBridgeJavaClass = "";
		CString m_strStartJarPath = _T("");

		CSession* m_pSession = NULL;
		IPCMsg* m_pCurrentIPCMsg = NULL;
		IWebRTCLRImpl* m_pCLRProxy = NULL;
		IUniverseAppProxy* m_pActiveAppProxy = NULL;
		IUniverseAppProxy* m_pUniverseAppProxy = NULL;
		IUniverseAppProxy* m_pWebRTAppProxy = NULL;
		CMDIChildFormInfo* m_pCurMDIChildFormInfo = NULL;
		IWebRTExtender* m_pExtender = nullptr;
		IContainer* m_pCreatingWindow = nullptr;
		CWebViewImpl* m_pMainWebPageImpl = nullptr;
		IWebRTDelegate* m_pWebRTDelegate = nullptr;
		CChromeBrowserBase* m_pActiveBrowser = nullptr;
		IWinAppProxyImpl* m_pWinAppProxyImpl = nullptr;
		CWebRTBrowserFactory* m_pBrowserFactory = nullptr;
		CWebRTMainDllLoader* m_pWebRTMainDllLoader = nullptr;
		CosmosAppMessagePumpForUI* m_pMessagePumpForUI = nullptr;
		OmniboxViewViewsProxy* m_pCreatingOmniboxViewViews = nullptr;
		CChromeRenderFrameHost* m_pCreatingChromeRenderFrameHostBase = nullptr;

		map<HWND, CString>						m_mapUIData;
		map<HWND, CString>						m_mapCtrlTag;
		map<DWORD, IWebRT*>						m_mapRemoteTangramApp;
		map<CString, IDispatch*>				m_mapObjDic;
		map<CString, CComVariant>				m_mapValInfo;
		map<CString, IWebRT*>					m_mapRemoteCosmos;
		map<CString, CString>					m_mapDocAppName;
		map<CString, CString>					m_mapDocTemplate;
		map<CString, CString>					m_mapDocDefaultName;
		map<CString, CString>					m_mapJavaNativeInfo;
		map<CString, CString>					m_mapCreatingWorkBenchInfo;
		map<CString, HWND>						m_mapSingleWndApp;
		map<CString, IUniverseAppProxy*>		m_mapWebRTAppProxy;
		map<CString, IWindowProvider*>			m_mapWindowProvider;

		map<HWND, IXobj*>						m_mapXobj;
		map<HWND, CWebViewImpl*>				m_mapWebView;
		map<HWND, HWND>							m_mapBrowserForm;
		map<HWND, IBrowser*>					m_mapBrowserWnd;
		map<HWND, IWebView*>					m_mapFormWebPage;
		map<HWND, IWorkBenchWindow*>			m_mapWorkBenchWnd;
		map<HWND, INuclei*>						m_mapNuclei;
		map<HWND, WebRTFrameWndInfo*>			m_mapWebRTFrameWndInfo;
		map<void*, IUnknown*>					m_mapObjects;
		map<IDispatch*, CString>				m_mapObjEventDic;
		//map<DWORD, LPPROCESSENTRY32>			m_mapProcessInfo;
		map<DWORD, DWORD>						m_mapProcessInfo2;
		map<CString, HWND>						m_mapProcessBindInfo;
		map<CString, CString>					m_mapProcessConfig;

		virtual void Run() {}
		virtual void BrowserAppStart() {}
		virtual void WebRTInit() {}
		virtual void OnCLRHostExit() {}
		virtual void OnBatteryChanged() {}
		virtual void OnExitMainMsgPump() {}
		virtual void SetMainWnd(HWND hMain) {}
		virtual void ConnectMsgLoop(HWND hMsg) {}
		virtual void AttachXobj(void* pXobjEvents) {}
		virtual void ChromeTabCreated(CChromeTab* pTab) {}
		virtual void SendIPCMsg(HWND hXobj, CString strMsgID) {}
		virtual void OnNewSurfaceWnd(HWND hWnd, HWND hSurfaceWnd) {}
		virtual void OnSubBrowserWndCreated(HWND hParent, HWND hBrowser) {}
		virtual void OnRenderProcessCreated(CChromeRenderProcess* pProcess) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, long lVal) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, float fVal) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, __int64 llVal) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, CString strVal) {}
		virtual void InserttoDataMap(int nType, CString strKey, void* pData) {}
		virtual void AttachControlBar(WebRTFrameWndInfo* pInfo, HWND hCtrlBar) { }
		virtual void OnUpdateParent(HWND hPWnd, HWND hWnd, int DeviceScaleFactor) {}
		virtual void AttachMDIChild(HWND hFrame, HWND hMDIChild, HWND hChildClient) { }
		virtual void OnNetworkChangeNotify(int ConnectType, __int64 NetworkHandle) {}
		virtual void OnDocumentOnLoadCompleted(CChromeRenderFrameHost*, HWND hHtmlWnd, void*) {}
		virtual void OnWebRTMessage(HWND hWnd, CChromeRenderFrameHost*, CommonUniverse::IPCMsg* pIPCInfo) {}
		virtual CString GetFileMD5(CString strSRC) { return _T(""); }
		virtual CString GetProcessPath(const char* _ver, CString process_type) { return _T(""); }
		virtual CString GetSchemeBaseName() { return _T(""); }
		virtual CString GetMsgStringData(HWND hXobj, CString strKey) { return _T(""); }
		virtual CString BuildConfigDataFile(CString strExeName, CString strProductName, CString strCompanyPathName) { return _T(""); }
		virtual wstring Json2Xml(wstring strJson, bool bJsonstr) { return L""; }
		virtual bool IsMDIClientNucleusNode(IXobj*) { return false; }
		virtual bool GetEnableHardwareAcceleration() { return false; }
		virtual bool SetFrameInfo(HWND hWnd, HWND hFrame, CString strTemplateID, void* pDoc, void* pDocTemplate) { return false; }
		virtual long GetIPCMsgIndex(CString strMsgID) { return 0; }
		virtual long GetMsgLong(HWND hXobj, CString strKey) { return 0; }
		virtual float GetMsgFloat(HWND hXobj, CString strKey) { return 0.0f; }
		virtual __int64 GetMsgInt64(HWND hXobj, CString strKey) { return 0; }
		virtual HICON GetAppIcon(int nIndex) { return NULL; }
		virtual HWND GetMainWnd(int nChildID, CString strAppProxy) { return NULL; }
		virtual IXobj* ObserveCtrl(__int64 handle, CString name, CString NodeTag) { return nullptr; }
		virtual IXobj* GetXobj(HWND hWnd) { return nullptr; }
		virtual IXobj* ObserveXml(HWND hWnd, CString strKey, CString strXml) { return nullptr; }
		virtual INucleus* ConnectNuclei(HWND, HWND, CString, INuclei* pNuclei, NucleusInfo*) { return nullptr; }
		virtual INucleus* GetNucleus(HWND hWnd) { return nullptr; }
		virtual INuclei* Observe(HWND, CString strName, CString strKey) { return nullptr; }
		virtual IWebView* GetWebPageFromForm(HWND) { return nullptr; }
		virtual IBrowser* GetHostBrowser(HWND hNodeWnd) { return nullptr; }
		virtual CChromeBrowserBase* GetChromeBrowserBase(HWND) { return nullptr; }
		virtual CSession* CreateCloudSession(CWebViewImpl*) { return nullptr; }
		virtual CSession* GetCloudSession(IXobj*) { return nullptr; }
		virtual CWebViewImpl* GetWebPageImpl(HWND hWnd) { return nullptr; }
		virtual CBrowserImpl* GetBrowserImpl(HWND hWnd) { return nullptr; }
		virtual CTabStatsTrackerDelegate* SetTabStatsTrackerDelegate() { return nullptr; }
		virtual WebRTFrameWndInfo* InsertWebRTFrameWndInfo(HWND hWnd) { return NULL; }
	};

	class IWindowProvider {
	public:
		IWindowProvider() {}
		virtual ~IWindowProvider() {
			if (::GetModuleHandle(L"universe") != NULL && g_pSpaceTelescopeImpl) {
				g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
			}
		}

		CString m_strProviderID = _T("");
		CString m_strContainer = _T("");
		map<CString, CString> m_mapDOMObjStyle;
		map<CString, void*> m_mapDOMObj;

		virtual bool WebRTInit(CString strID) {
			strID.MakeLower().Trim();
			if (strID != _T("") && g_pSpaceTelescopeImpl == nullptr) {
				m_strProviderID = strID;
				HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
				if (hModule) {
					typedef CWebRTImpl* (__stdcall* GetWebRTImpl)(IWebRT**);
					GetWebRTImpl _pWebRTFunction;
					_pWebRTFunction =
						(GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
					IWebRT* pWebRT = nullptr;
					g_pSpaceTelescopeImpl = _pWebRTFunction(&pWebRT);
					m_strProviderID.MakeLower();
					g_pSpaceTelescopeImpl->InserttoDataMap(
						1, m_strProviderID, static_cast<IWindowProvider*>(this));
					return true;
				}
			}
			return false;
		}

		virtual CString GetNames() { return _T(""); }
		virtual CString GetTags(CString strName) { return _T(""); }
		virtual HWND Create(HWND hParentWnd, IXobj* pXobj) { return NULL; }
		virtual IDispatch* CreateCtrl(CString strCtrlID) { return NULL; }
	};

	class IContainer {
	public:
		IContainer() {
			if (g_pSpaceTelescopeImpl)
				g_pSpaceTelescopeImpl->m_pCreatingWindow = this;
		}

		virtual ~IContainer() {}

		virtual void Save() {}
	};

	class IWebRTDelegate {
	public:
		IWebRTDelegate() {
			m_pJVM = nullptr;
			m_pJVMenv = nullptr;
			systemClass = nullptr;
			exitMethod = nullptr;
			loadMethod = nullptr;
		}

		virtual ~IWebRTDelegate() {}

		JavaVM* m_pJVM;
		JNIEnv* m_pJVMenv;
		jclass systemClass;
		jmethodID exitMethod;
		jmethodID loadMethod;

		virtual bool DoIdleWork() { return false; }
		virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) { return false; }
		virtual bool IsAppIdleMessage() { return false; }
		virtual bool OnUniversePreTranslateMessage(MSG* pMsg) { return false; }
		virtual void ProcessMsg(MSG* msg) {}
		virtual void ForegroundIdleProc() {}
		virtual HICON GetAppIcon(int nIndex) { return NULL; }
	};

	class CWebRTMainDllLoader {
	public:
		CWebRTMainDllLoader() {}
		virtual ~CWebRTMainDllLoader() {}
		virtual void LaunchEx(CWebRTImpl*) {}
		virtual bool ExtendWinApp(HANDLE hProcess, CString strPath, int nDelaySecond, int nDelaySecond2) { return false; }
	};

	class CWebRTBrowserFactory {
	public:
		CWebRTBrowserFactory() {}
		virtual ~CWebRTBrowserFactory() {}

		virtual HWND CreateBrowser(HWND hParent, CString strXml) { return NULL; }
	};

	class CTabStatsTrackerImpl {
	public:
		CTabStatsTrackerImpl() { m_pTabStatsTrackerDelegate = nullptr; }
		virtual ~CTabStatsTrackerImpl() {}

		CTabStatsTrackerDelegate* m_pTabStatsTrackerDelegate;

		virtual void OnInit() {}
	};

	class CTabStatsTrackerDelegate {
	public:
		CTabStatsTrackerDelegate() {}
		virtual ~CTabStatsTrackerDelegate() {}

		virtual void Resume() {}
		virtual void HeartbeatEvent() {}
		virtual void InitialOrInsertedTab(HWND hWebView, HWND hBrowser) {}
		virtual void WebContentsDestroyed(HWND hWebView, HWND hBrowser) {}
		virtual void OnTabChangedAt(HWND hWebView,
			HWND hBrowser,
			int nIndex,
			BrowserTabChangeType type,
			void* content) {}
		virtual void BrowserAdded(CChromeBrowserBase* browser, HWND hBrowser) {}
		virtual void BrowserRemoved(CChromeBrowserBase* browser, HWND hBrowser) {}
	};

	class CChromeChildProcessHostImpl {
	public:
		CChromeChildProcessHostImpl() { m_pChildProcessHostProxy = nullptr; }
		virtual ~CChromeChildProcessHostImpl() {}

		CChromeChildProcessHostImplProxy* m_pChildProcessHostProxy;
	};

	class CChromeChildProcessHostImplProxy {
	public:
		CChromeChildProcessHostImplProxy() {}

		virtual ~CChromeChildProcessHostImplProxy() {}

		virtual void OnRenderProcessCreated() {}
	};

	class CChromeRenderProcess {
	public:
		CChromeRenderProcess() { m_pRenderProcessProxy = nullptr; }
		virtual ~CChromeRenderProcess() {}

		CChromeRenderProcessProxy* m_pRenderProcessProxy;
	};

	class CChromeRenderProcessProxy {
	public:
		CChromeRenderProcessProxy() {}

		virtual ~CChromeRenderProcessProxy() {}

		virtual CString ProcessPath() { return _T(""); }
		virtual void OnRenderProcessCreated() {}
	};

	class CChromeTab {
	public:
		CChromeTab() {
			m_pTabProxy = nullptr;
			HMODULE hModule = ::GetModuleHandle(L"universe.dll");
			if (hModule != nullptr) {
				GetWebRTImplFunction GetWebRTImplFunction =
					(CommonUniverse::GetWebRTImplFunction)GetProcAddress(
						hModule, "GetWebRTImpl");
				if (GetWebRTImplFunction != NULL) {
					IWebRT* pWebRT = nullptr;
					CWebRTImpl* _pImpl = GetWebRTImplFunction(&pWebRT);
					if (_pImpl) {
						_pImpl->ChromeTabCreated(this);
					}
				}
			}
		}
		virtual ~CChromeTab() {}

		CChromeTabProxy* m_pTabProxy;
	};

	class CChromeTabProxy {
	public:
		CChromeTabProxy() { m_pTab = nullptr; }
		virtual ~CChromeTabProxy() {}
		CChromeTab* m_pTab;
	};

	class CChromeTabHoverCardEventSnifferImpl {
	public:
		CChromeTabHoverCardEventSnifferImpl() {
			m_hWnd = nullptr;
			m_bMainDlgTabHoverCardEvent = false;
		}
		virtual ~CChromeTabHoverCardEventSnifferImpl() {}
		bool m_bMainDlgTabHoverCardEvent;
		HWND m_hWnd;
	};

	class OmniboxViewViewsProxy {
	public:
		OmniboxViewViewsProxy() {
			HMODULE hModule = ::GetModuleHandle(L"universe.dll");
			if (hModule != nullptr) {
				GetWebRTImplFunction GetWebRTImplFunction =
					(CommonUniverse::GetWebRTImplFunction)GetProcAddress(
						hModule, "GetWebRTImpl");
				if (GetWebRTImplFunction != NULL) {
					IWebRT* pWebRT = nullptr;
					CWebRTImpl* _pImpl = GetWebRTImplFunction(&pWebRT);
					if (_pImpl) {
						_pImpl->m_pCreatingOmniboxViewViews = this;
					}
				}
			}
		}
		virtual ~OmniboxViewViewsProxy() {}

		virtual void Blur() = 0;
		virtual bool IsFocused() = 0;
	};

	class CChromeBrowserBase {
	public:
		CChromeBrowserBase() {
			HMODULE hModule = ::GetModuleHandle(L"universe.dll");
			if (hModule != nullptr) {
				GetWebRTImplFunction GetWebRTImplFunction =
					(CommonUniverse::GetWebRTImplFunction)GetProcAddress(
						hModule, "GetWebRTImpl");
				if (GetWebRTImplFunction != NULL) {
					IWebRT* pWebRT = nullptr;
					CWebRTImpl* _pImpl = GetWebRTImplFunction(&pWebRT);
					if (_pImpl) {
						m_pProxy = nullptr;
						_pImpl->m_pActiveBrowser = this;
					}
				}
			}
		}
		virtual ~CChromeBrowserBase() {}

		CBrowserImpl* m_pProxy;

		virtual int GetType() { return -1; }
		virtual void* GetBrowser() { return nullptr; }
		virtual void LayoutBrowser() {}
		virtual void OpenURL(std::wstring strURL,
			BrowserWndOpenDisposition nPos,
			void* pVoid) {}
		virtual HWND GetActiveWebContentWnd() { return NULL; }
		virtual bool IsActiveWebContentWnd(HWND hWebWnd) { return false; }
	};

	class CBrowserImpl {
	public:
		CBrowserImpl() {
			m_strBKColor = _T("");
			m_hDrawWnd = 0;
		}
		virtual ~CBrowserImpl() {}

		bool m_bDestroy = false;
		bool m_bTabChange;
		bool m_bSZMode = false;
		bool m_bInTabChange = false;
		float m_fdevice_scale_factor;
		HWND m_hOldTab;
		HWND m_hDrawWnd;
		HWND m_hBeforeChange = NULL;
		RECT m_OldRect;
		CString m_strBKColor;
		CChromeBrowserBase* m_pBrowser;
		OmniboxViewViewsProxy* m_pOmniboxViewViews;

		virtual void UpdateContentRect(HWND hWebContent,
			RECT& rc,
			int nTopFix,
			float dwDeviceScaleFactor) {}
		virtual void BeforeActiveChromeTab(HWND hOldWnd) {}
		virtual void ActiveChromeTab(HWND hActive, HWND hOldWnd) {}
		virtual void EndActiveChromeTab(HWND hActive) {}
		virtual void BrowserLayoutImpl() {}
		virtual CString GetXobjAttr(CString attrName) { return _T(""); }
	};

	class CChromeWebContentBase {
	public:
		CChromeWebContentBase() { m_pProxy = nullptr; }

		virtual ~CChromeWebContentBase() {}

		CChromeWebContentProxyBase* m_pProxy;

		virtual CChromeRenderFrameHost* GetMainRenderFrameHost() { return nullptr; }
	};

	class CChromeWebContentProxyBase {
	public:
		CChromeWebContentProxyBase() { m_pWebContent = nullptr; }

		virtual ~CChromeWebContentProxyBase() {}

		CChromeWebContentBase* m_pWebContent;
	};

	class CChromeRenderFrameHost {
	public:
		CChromeRenderFrameHost() {
			m_pProxy = nullptr;
		}

		virtual ~CChromeRenderFrameHost() {
			for (auto& it : m_mapWebRTSession) {
				delete it.second;
			}
			m_mapWebRTSession.erase(m_mapWebRTSession.begin(),
				m_mapWebRTSession.end());
		}

		CWebViewImpl* m_pProxy;
		map<CString, IPCSession*> m_mapWebRTSession;
		virtual void SetFocus(bool bFocus) {}
		virtual void ShowWebPage(bool bShow) {}
		virtual void SendCosmosMessage(IPCMsg*) {}
		virtual void SendCosmosMessage(IPCSession* var) {}
		virtual HWND GetHostBrowserWnd() { return NULL; }
		virtual IPCSession* GetIPCSession() { return nullptr; }
		virtual void InsertString(IPCSession*, CString key, CString value) {}
		virtual void InsertLong(IPCSession*, CString key, long value) {}
		virtual void Insertint64(IPCSession*, CString key, __int64 value) {}
		virtual void InsertFloat(IPCSession*, CString key, float value) {}
		virtual CString GetString(IPCSession*, CString key) { return _T(""); }
		virtual long GetLong(IPCSession*, CString key) { return 0; }
		virtual __int64 Getint64(IPCSession*, CString key) { return 0; }
		virtual float GetFloat(IPCSession*, CString key) { return 0; }
		virtual CString GetRenderFrameURL(int nType) { return _T(""); }
		virtual bool ExtendWinApp(HANDLE hProcess, CString strPath, int nDelaySecond, int nDelaySecond2) { return false; }
	};

	class CWebViewImpl {
	public:
		CWebViewImpl() {
			m_pSession = nullptr;
			m_pRemoteCosmos = nullptr;
			m_pChromeRenderFrameHost = g_pSpaceTelescopeImpl->m_pCreatingChromeRenderFrameHostBase;
			g_pSpaceTelescopeImpl->m_pCreatingChromeRenderFrameHostBase = nullptr;
		}

		virtual ~CWebViewImpl() {}
		CSession* m_pSession = nullptr;
		IWebRT* m_pRemoteCosmos = nullptr;
		CChromeRenderFrameHost* m_pChromeRenderFrameHost;
		virtual void SendChromeIPCMessage(CString strId,
			CString strParam1,
			CString strParam2,
			CString strParam3,
			CString strParam4,
			CString strParam5) = 0;
		virtual CChromeBrowserBase* GetChromeBrowserBase(HWND) { return nullptr; }
		virtual void OnWinFormCreated(HWND) {}
		virtual IXobj* GetParentXobj() { return nullptr; }
		virtual INucleus* GetNucleus() { return nullptr; }
		virtual void OnCloudMsgReceived(CSession*) {}
		virtual void ObserveViewport(CString strName, CString strXML) {}
	};

	class CChromeRendererFrameBase {
	public:
		CChromeRendererFrameBase() {}

		virtual ~CChromeRendererFrameBase() {}
	};

	class CosmosAppMessagePumpForUI {
	public:
		CosmosAppMessagePumpForUI() {
			bIdle = TRUE;
			lIdleCount = 0;
		}

		virtual ~CosmosAppMessagePumpForUI() {}
		virtual void OnAppIdle() {}
		virtual int OnProcessNextWindowsMessage(LPMSG lpMsg) { return -1; }
		bool m_bStartRun = false;
		BOOL bIdle = TRUE;
		LONG lIdleCount = 0;
		bool more_work_is_plausible = false;
	};

}  // namespace CommonUniverse
