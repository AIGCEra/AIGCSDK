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

#pragma once

#include <map>
#include "metahost.h"
#include <ppl.h>
#include <ppltasks.h>
#include <agents.h>
#include <shlobj.h>
#include <atlbase.h>
#include <atlctl.h>
#include <atlstr.h>
#include <msxml2.h>
#include <comdef.h>
#include <ShellScalingApi.h>

#ifdef _AFX
#include <afxcontrolbars.h>     // MFC support for ribbons and control bars
#include <afxcview.h>
#endif

#define WebRTDefault

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

using namespace std;
using namespace ATL;
using namespace concurrency;

#pragma comment(lib, "imagehlp.lib")
#pragma comment(lib,"msxml2.Lib")

namespace CommonUniverse
{
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

	//
	// Forward references and typedefs
	//

	struct __declspec(uuid("19631222-1992-0612-1965-060119820911"))
		/* LIBID */ __Universe;
	struct __declspec(uuid("19631222-1992-0612-1965-060119821002"))
		/* dispinterface */ _IWebRT;
	struct __declspec(uuid("19631222-1992-0612-1965-060119820004"))
		/* interface */ IXobj;
	struct __declspec(uuid("19631222-1992-0612-1965-060119820017"))
		/* dual interface */ IXobjCollection;
	enum XobjType;
	struct __declspec(uuid("19631222-1992-0612-1965-060119820002"))
		/* dual interface */ INuclei;
	struct __declspec(uuid("19631222-1992-0612-1965-060119820003"))
		/* dual interface */ INucleus;
	struct __declspec(uuid("19631222-1992-0612-1965-060120180903"))
		/* dual interface */ IWebView;
	struct __declspec(uuid("19631222-1992-0612-1965-060120180828"))
		/* dual interface */ IBrowser;
	enum BrowserWndOpenDisposition;
	enum GalaxyType;
	struct __declspec(uuid("19631222-1992-0612-1965-060120160928"))
		/* dual interface */ IWebRTEventObj;
	struct /* coclass */ WebRT;
	struct __declspec(uuid("19631222-1992-0612-1965-060119820001"))
		/* dual interface */ IWebRT;
	struct __declspec(uuid("19631222-1992-0612-1965-060120160101"))
		/* dual interface */ IWebRTExtender;
	struct __declspec(uuid("19631222-1992-0612-1965-060119825d34"))
		/* dual interface */ IWorkBenchWindow;
	struct __declspec(uuid("19631222-1992-0612-1965-060120160912"))
		/* dual interface */ IEclipseCtrl;
	struct __declspec(uuid("19631222-1992-0612-1965-0601198231dc"))
		/* dual interface */ IWebRTCtrl;
	struct __declspec(uuid("19631222-1992-0612-1965-060119821001"))
		/* dispinterface */ _IXobjEvents;
	struct __declspec(uuid("19631222-1992-0612-1965-060119821992"))
		/* dispinterface */ _IWebRTObjEvents;
	struct __declspec(uuid("19631222-1992-0612-1965-060120160930"))
		/* dispinterface */ _IWebRTAppEvents;
	struct /* coclass */ WebRTCtrl;
	struct /* coclass */ CosmosExtender;
	struct __declspec(uuid("19631222-1992-0612-1965-060120160918"))
		/* dual interface */ IEclipseExtender;
	struct __declspec(uuid("19631222-1992-0612-1965-060119631222"))
		/* dual interface */ IOfficeExtender;
	struct __declspec(uuid("19631222-1992-0612-1965-060120161001"))
		/* dual interface */ IWebRTAppCtrl;

	//
	// Smart pointer typedef declarations
	//

	_COM_SMARTPTR_TYPEDEF(_IWebRT, __uuidof(_IWebRT));
	_COM_SMARTPTR_TYPEDEF(IWebRTEventObj, __uuidof(IWebRTEventObj));
	_COM_SMARTPTR_TYPEDEF(_IXobjEvents, __uuidof(_IXobjEvents));
	_COM_SMARTPTR_TYPEDEF(_IWebRTObjEvents, __uuidof(_IWebRTObjEvents));
	_COM_SMARTPTR_TYPEDEF(_IWebRTAppEvents, __uuidof(_IWebRTAppEvents));
	_COM_SMARTPTR_TYPEDEF(IXobj, __uuidof(IXobj));
	_COM_SMARTPTR_TYPEDEF(IXobjCollection, __uuidof(IXobjCollection));
	_COM_SMARTPTR_TYPEDEF(IBrowser, __uuidof(IBrowser));
	_COM_SMARTPTR_TYPEDEF(IWebView, __uuidof(IWebView));
	_COM_SMARTPTR_TYPEDEF(INuclei, __uuidof(INuclei));
	_COM_SMARTPTR_TYPEDEF(INucleus, __uuidof(INucleus));
	_COM_SMARTPTR_TYPEDEF(IWebRT, __uuidof(IWebRT));
	_COM_SMARTPTR_TYPEDEF(IWebRTCtrl, __uuidof(IWebRTCtrl));
	_COM_SMARTPTR_TYPEDEF(IWebRTAppCtrl, __uuidof(IWebRTAppCtrl));
	_COM_SMARTPTR_TYPEDEF(IWebRTExtender, __uuidof(IWebRTExtender));
	_COM_SMARTPTR_TYPEDEF(IEclipseExtender, __uuidof(IEclipseExtender));
	_COM_SMARTPTR_TYPEDEF(IOfficeExtender, __uuidof(IOfficeExtender));
	_COM_SMARTPTR_TYPEDEF(IWorkBenchWindow, __uuidof(IWorkBenchWindow));
	_COM_SMARTPTR_TYPEDEF(IEclipseCtrl, __uuidof(IEclipseCtrl));

	//
	// Type library items
	//

	struct __declspec(uuid("19631222-1992-0612-1965-060119821002"))
		_IWebRT : IDispatch
	{};

	enum XobjType
	{
		BlankView = 1,
		ActiveX = 2,
		Grid = 4,
		TabGrid = 8,
		CLRCtrl = 16,
		CLRForm = 32,
		CLRWnd = 64,
		TangramView = 128,
		TangramTreeView = 256,
		TangramListView = 512,
		TabCtrl = 1024,
		TangramWPFCtrl = 2048
	};

	enum BrowserWndOpenDisposition
	{
		UNKNOWN_TAB = 0,
		CURRENT_TAB = 1,
		SINGLETON_TAB = 2,
		NEW_FOREGROUND_TAB = 3,
		NEW_BACKGROUND_TAB = 4,
		NEW_POPUP = 5,
		NEW_WINDOW = 6,
		SAVE_TO_DISK = 7,
		OFF_THE_RECORD = 8,
		IGNORE_ACTION = 9,
		SWITCH_TO_TAB = 10
	};

	enum GalaxyType
	{
		MDIClientGalaxy = 0,
		MDIChildGalaxy = 1,
		SDIGalaxy = 2,
		CtrlBarGalaxy = 3,
		WinFormMDIClientGalaxy = 4,
		WinFormMDIChildGalaxy = 5,
		WinFormGalaxy = 6,
		EclipseWorkBenchGalaxy = 7,
		EclipseViewGalaxy = 8,
		EclipseSWTGalaxy = 9,
		WinFormControlGalaxy = 10,
		WebPageGalaxy = 11,
		NOGalaxy = 12
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120160928"))
		IWebRTEventObj : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_eventSource(
			/*[out,retval]*/ IDispatch** pVal) = 0;
		virtual HRESULT __stdcall put_eventSource(
			/*[in]*/ IDispatch* pVal) = 0;
		virtual HRESULT __stdcall get_Index(
			/*[out,retval]*/ int* nVal) = 0;
		virtual HRESULT __stdcall put_Index(
			int nVal) = 0;
		virtual HRESULT __stdcall get_EventName(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall put_EventName(
			BSTR pVal) = 0;
		virtual HRESULT __stdcall get_Object(
			int nIndex,
			/*[out,retval]*/ IDispatch** pVal) = 0;
		virtual HRESULT __stdcall put_Object(
			int nIndex,
			IDispatch* pVal) = 0;
		virtual HRESULT __stdcall get_Value(
			int nIndex,
			/*[out,retval]*/ VARIANT* pVal) = 0;
		virtual HRESULT __stdcall put_Value(
			int nIndex,
			VARIANT pVal) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060119990606"))
		WebRT;
	// [ default ] interface IWebRT
	// [ default, source ] dispinterface _IWebRT

	struct __declspec(uuid("19631222-1992-0612-1965-060119821001"))
		_IXobjEvents : IDispatch
	{};

	struct __declspec(uuid("19631222-1992-0612-1965-060119821992"))
		_IWebRTObjEvents : IDispatch
	{};

	struct __declspec(uuid("19631222-1992-0612-1965-060120160930"))
		_IWebRTAppEvents : IDispatch
	{};

	struct __declspec(uuid("19631222-1992-0612-1965-060120071001"))
		WebRTCtrl;
	// [ default ] interface IWebRTCtrl
	// [ default, source ] dispinterface _IWebRTObjEvents

	struct __declspec(uuid("19631222-1992-0612-1965-060100000000"))
		CosmosExtender;
	// [ default ] interface IEclipseCtrl
	// interface IEclipseExtender
	// interface IOfficeExtender
	// interface IWebRTAppCtrl

	struct __declspec(uuid("19631222-1992-0612-1965-060119820004"))
		IXobj : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_ChildNodes(
			/*[out,retval]*/ struct IXobjCollection** ppXobjColletion) = 0;
		virtual HRESULT __stdcall get_Rows(
			/*[out,retval]*/ long* nRows) = 0;
		virtual HRESULT __stdcall get_Cols(
			/*[out,retval]*/ long* nCols) = 0;
		virtual HRESULT __stdcall get_Row(
			/*[out,retval]*/ long* nRow) = 0;
		virtual HRESULT __stdcall get_Col(
			/*[out,retval]*/ long* nCol) = 0;
		virtual HRESULT __stdcall get_XobjType(
			/*[out,retval]*/ enum XobjType* nType) = 0;
		virtual HRESULT __stdcall get_ParentXobj(
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall get_URL(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall put_URL(
			/*[in]*/ BSTR pVal) = 0;
		virtual HRESULT __stdcall get_Nuclei(
			/*[out,retval]*/ struct INuclei** pVal) = 0;
		virtual HRESULT __stdcall get_RootXobj(
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall get_XObject(
			/*[out,retval]*/ VARIANT* pVar) = 0;
		virtual HRESULT __stdcall get_AxPlugIn(
			/*[in]*/ BSTR bstrPlugInName,
			/*[out,retval]*/ IDispatch** pVal) = 0;
		virtual HRESULT __stdcall get_Caption(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall put_Caption(
			/*[in]*/ BSTR pVal) = 0;
		virtual HRESULT __stdcall get_Name(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall put_Name(
			/*[in]*/ BSTR pVal) = 0;
		virtual HRESULT __stdcall get_Objects(
			/*[in]*/ long nType,
			/*[out,retval]*/ struct IXobjCollection** ppXobjColletion) = 0;
		virtual HRESULT __stdcall get_Handle(
			/*[out,retval]*/ __int64* HWND) = 0;
		virtual HRESULT __stdcall get_Attribute(
			/*[in]*/ BSTR bstrKey,
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall put_Attribute(
			/*[in]*/ BSTR bstrKey,
			/*[in]*/ BSTR pVal) = 0;
		virtual HRESULT __stdcall get_Tag(
			/*[out,retval]*/ VARIANT* pVar) = 0;
		virtual HRESULT __stdcall put_Tag(
			/*[in]*/ VARIANT pVar) = 0;
		virtual HRESULT __stdcall get_OuterXml(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_Key(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_WebView(
			/*[out,retval]*/ struct IWebView** pVal) = 0;
		virtual HRESULT __stdcall get_NameAtWindowPage(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_Width(
			/*[out,retval]*/ long* pVal) = 0;
		virtual HRESULT __stdcall get_Height(
			/*[out,retval]*/ long* pVal) = 0;
		virtual HRESULT __stdcall get_WinNucleus(
			/*[out,retval]*/ struct INucleus** pVal) = 0;
		virtual HRESULT __stdcall get_XML(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_Extender(
			/*[out,retval]*/ IDispatch** pVal) = 0;
		virtual HRESULT __stdcall put_Extender(
			/*[in]*/ IDispatch* pVal) = 0;
		virtual HRESULT __stdcall get_DocXml(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_rgbMiddle(
			/*[out,retval]*/ OLE_COLOR* pVal) = 0;
		virtual HRESULT __stdcall put_rgbMiddle(
			/*[in]*/ OLE_COLOR pVal) = 0;
		virtual HRESULT __stdcall get_rgbRightBottom(
			/*[out,retval]*/ OLE_COLOR* pVal) = 0;
		virtual HRESULT __stdcall put_rgbRightBottom(
			/*[in]*/ OLE_COLOR pVal) = 0;
		virtual HRESULT __stdcall get_rgbLeftTop(
			/*[out,retval]*/ OLE_COLOR* pVal) = 0;
		virtual HRESULT __stdcall put_rgbLeftTop(
			/*[in]*/ OLE_COLOR pVal) = 0;
		virtual HRESULT __stdcall get_Hmin(
			/*[out,retval]*/ int* pVal) = 0;
		virtual HRESULT __stdcall put_Hmin(
			/*[in]*/ int pVal) = 0;
		virtual HRESULT __stdcall get_Hmax(
			/*[out,retval]*/ int* pVal) = 0;
		virtual HRESULT __stdcall put_Hmax(
			/*[in]*/ int pVal) = 0;
		virtual HRESULT __stdcall get_Vmin(
			/*[out,retval]*/ int* pVal) = 0;
		virtual HRESULT __stdcall put_Vmin(
			/*[in]*/ int pVal) = 0;
		virtual HRESULT __stdcall get_Vmax(
			/*[out,retval]*/ int* pVal) = 0;
		virtual HRESULT __stdcall put_Vmax(
			/*[in]*/ int pVal) = 0;
		virtual HRESULT __stdcall get_HostXobj(
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall put_HostXobj(
			/*[in]*/ struct IXobj* pVal) = 0;
		virtual HRESULT __stdcall get_ActivePage(
			/*[out,retval]*/ int* pVal) = 0;
		virtual HRESULT __stdcall put_ActivePage(
			/*[in]*/ int pVal) = 0;
		virtual HRESULT __stdcall get_HostGalaxy(
			/*[out,retval]*/ struct INucleus** pVal) = 0;
		virtual HRESULT __stdcall get_OfficeObj(
			/*[out,retval]*/ IDispatch** pVal) = 0;
		virtual HRESULT __stdcall ActiveTabPage(
			struct IXobj* pXobj) = 0;
		virtual HRESULT __stdcall GetXobjs(
			/*[in]*/ BSTR bstrName,
			/*[out]*/ struct IXobj** ppXobj,
			/*[out]*/ struct IXobjCollection** ppXobjs,
			/*[out,retval]*/ long* pCount) = 0;
		virtual HRESULT __stdcall GetXobj(
			/*[in]*/ long nRow,
			/*[in]*/ long nCol,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall GetCtrlByName(
			BSTR bstrName,
			VARIANT_BOOL bFindInChild,
			/*[out,retval]*/ IDispatch** ppCtrlDisp) = 0;
		virtual HRESULT __stdcall SendIPCMessage(
			BSTR bstrTo,
			BSTR bstrPayload,
			BSTR bstrExtra,
			BSTR bstrMsgId,
			/*[out,retval]*/ BSTR* bstrRes) = 0;
		virtual HRESULT __stdcall Observe(
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
		virtual HRESULT __stdcall LoadXML(
			int nType,
			BSTR bstrXml) = 0;
		virtual HRESULT __stdcall ObserveEx(
			int nRow,
			int nCol,
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
		virtual HRESULT __stdcall GetXobjByName(
			/*[in]*/ BSTR bstrName,
			/*[out,retval]*/ struct IXobjCollection** pVal) = 0;
		virtual HRESULT __stdcall GetCtrlValueByName(
			BSTR bstrName,
			VARIANT_BOOL bFindInChild,
			/*[out,retval]*/ BSTR* bstrVal) = 0;
		virtual HRESULT __stdcall SetCtrlValueByName(
			BSTR bstrName,
			VARIANT_BOOL bFindInChild,
			BSTR bstrVal) = 0;
		virtual HRESULT __stdcall NavigateURL(
			BSTR bstrURL,
			IDispatch* dispObjforScript) = 0;
		virtual HRESULT __stdcall GetChildXobjByName(
			/*[in]*/ BSTR bstrName,
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall GetUIScript(
			/*[in]*/ BSTR bstrCtrlName,
			/*[out,retval]*/ BSTR* bstrVal) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060119820017"))
		IXobjCollection : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_XobjCount(
			/*[out,retval]*/ long* pCount) = 0;
		virtual HRESULT __stdcall get_Item(
			/*[in]*/ long iIndex,
			/*[out,retval]*/ struct IXobj** ppTopWindow) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown** ppVal) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120180828"))
		IBrowser : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_RemoteXobj(
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall put_RemoteXobj(
			/*[in]*/ struct IXobj* pVal) = 0;
		virtual HRESULT __stdcall OpenURL(
			BSTR bstrURL,
			enum BrowserWndOpenDisposition nDisposition,
			BSTR bstrKey,
			BSTR bstrXml) = 0;
		virtual HRESULT __stdcall AddURLs(
			BSTR bstrURLs) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120180903"))
		IWebView : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_HostWnd(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall put_HostWnd(
			/*[in]*/ __int64 pVal) = 0;
		virtual HRESULT __stdcall get_WebBrowser(
			/*[out,retval]*/ struct IBrowser** ppWebBrowser) = 0;
		virtual HRESULT __stdcall CreateForm(
			BSTR bstrKey,
			__int64 hParent,
			/*[out,retval]*/ IDispatch** pRetForm) = 0;
		virtual HRESULT __stdcall Observe(
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** pRetXobj) = 0;
		virtual HRESULT __stdcall SendXmlMessage(
			struct IXobj* sender,
			BSTR bstrXml) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060119820002"))
		INuclei : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_WinNucleus(
			/*[in]*/ VARIANT vIndex,
			/*[out,retval]*/ struct INucleus** ppNucleus) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown** ppVal) = 0;
		virtual HRESULT __stdcall get_Count(
			/*[out,retval]*/ long* pCount) = 0;
		virtual HRESULT __stdcall get_NucleiXML(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_Parent(
			/*[out,retval]*/ struct INuclei** pVal) = 0;
		virtual HRESULT __stdcall get_Xobj(
			BSTR bstrNodeName,
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall get_XObject(
			BSTR bstrName,
			/*[out,retval]*/ IDispatch** pVal) = 0;
		virtual HRESULT __stdcall get_NucleusName(
			__int64 hHwnd,
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_Handle(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall get_Width(
			/*[out,retval]*/ long* pVal) = 0;
		virtual HRESULT __stdcall put_Width(
			/*[in]*/ long pVal) = 0;
		virtual HRESULT __stdcall get_Height(
			/*[out,retval]*/ long* pVal) = 0;
		virtual HRESULT __stdcall put_Height(
			/*[in]*/ long pVal) = 0;
		virtual HRESULT __stdcall get_XobjNames(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall CreateNucleus(
			VARIANT ParentObj,
			VARIANT HostWnd,
			BSTR bstrNucleusName,
			/*[out,retval]*/ struct INucleus** pRetGalaxy) = 0;
		virtual HRESULT __stdcall Observe(
			IDispatch* Parent,
			BSTR CtrlName,
			BSTR NucleusName,
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
		virtual HRESULT __stdcall ObserveCtrl(
			VARIANT Ctrl,
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
		virtual HRESULT __stdcall GetXobj(
			BSTR bstrNucleusName,
			BSTR bstrNodeName,
			/*[out,retval]*/ struct IXobj** pRetNode) = 0;
		virtual HRESULT __stdcall GetCtrlInXobj(
			BSTR NodeName,
			BSTR CtrlName,
			/*[out,retval]*/ IDispatch** ppCtrl) = 0;
		virtual HRESULT __stdcall GetNucleusFromCtrl(
			IDispatch* Ctrl,
			/*[out,retval]*/ struct INucleus** ppNucleus) = 0;
		virtual HRESULT __stdcall ObserveNuclei(
			BSTR bstrGalaxys,
			BSTR bstrKey,
			BSTR bstrXml,
			VARIANT_BOOL bSaveToConfigFile) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060119820003"))
		INucleus : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_Xobj(
			/*[in]*/ VARIANT vIndex,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown** ppVal) = 0;
		virtual HRESULT __stdcall get_HWND(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall get_VisibleXobj(
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall get_CurrentNavigateKey(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_Nuclei(
			/*[out,retval]*/ struct INuclei** pVal) = 0;
		virtual HRESULT __stdcall get_HostWebPage(
			/*[out,retval]*/ struct IWebView** ppChromeWebPage) = 0;
		virtual HRESULT __stdcall get_HostBrowser(
			/*[out,retval]*/ struct IBrowser** ppChromeWebBrowser) = 0;
		virtual HRESULT __stdcall get_Count(
			/*[out,retval]*/ long* pCount) = 0;
		virtual HRESULT __stdcall get_RootXobjs(
			/*[out,retval]*/ struct IXobjCollection** ppXobjColletion) = 0;
		virtual HRESULT __stdcall get_GalaxyXML(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall get_GalaxyType(
			/*[out,retval]*/ enum GalaxyType* pVal) = 0;
		virtual HRESULT __stdcall get_Name(
			/*[out,retval]*/ BSTR* pVal) = 0;
		virtual HRESULT __stdcall Detach() = 0;
		virtual HRESULT __stdcall Attach() = 0;
		virtual HRESULT __stdcall ModifyHost(
			__int64 hHostWnd) = 0;
		virtual HRESULT __stdcall Observe(
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
		virtual HRESULT __stdcall GetXml(
			BSTR bstrRootName,
			/*[out,retval]*/ BSTR* bstrRet) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060119820001"))
		IWebRT : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_HostChromeBrowserWnd(
			/*[out,retval]*/ struct IBrowser** ppChromeWebBrowser) = 0;
		virtual HRESULT __stdcall get_AppKeyValue(
			BSTR bstrKey,
			/*[out,retval]*/ VARIANT* pVal) = 0;
		virtual HRESULT __stdcall put_AppKeyValue(
			BSTR bstrKey,
			/*[in]*/ VARIANT pVal) = 0;
		virtual HRESULT __stdcall get_RemoteHelperHWND(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall put_RemoteHelperHWND(
			/*[in]*/ __int64 pVal) = 0;
		virtual HRESULT __stdcall get_RootNodes(
			/*[out,retval]*/ struct IXobjCollection** ppXobjColletion) = 0;
		virtual HRESULT __stdcall get_Extender(
			/*[out,retval]*/ struct IWebRTExtender** pVal) = 0;
		virtual HRESULT __stdcall put_Extender(
			/*[in]*/ struct IWebRTExtender* pVal) = 0;
		virtual HRESULT __stdcall get_CurrentActiveXobj(
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall get_CreatingXobj(
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall get_RemoteCosmos(
			BSTR bstrID,
			/*[out,retval]*/ struct IWebRT** pVal) = 0;
		virtual HRESULT __stdcall NavigateNode(
			struct IXobj* pXobj,
			BSTR bstrBrowserID,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall CreateNucleusGroup(
			__int64 HWND,
			/*[out,retval]*/ struct INuclei** ppNucleusCluster) = 0;
		virtual HRESULT __stdcall CreateOfficeDocument(
			BSTR bstrXml) = 0;
		virtual HRESULT __stdcall CreateCLRObj(
			BSTR bstrObjID,
			/*[out,retval]*/ IDispatch** ppDisp) = 0;
		virtual HRESULT __stdcall CreateApplication(
			BSTR bstrAppID,
			BSTR bstrXml) = 0;
		virtual HRESULT __stdcall GetNucleus(
			__int64 hHostWnd,
			/*[out,retval]*/ struct INucleus** ppNucleus) = 0;
		virtual HRESULT __stdcall GetItemText(
			struct IXobj* pXobj,
			long nCtrlID,
			long nMaxLengeh,
			/*[out,retval]*/ BSTR* bstrRet) = 0;
		virtual HRESULT __stdcall SetItemText(
			struct IXobj* pXobj,
			long nCtrlID,
			BSTR bstrText) = 0;
		virtual HRESULT __stdcall FireCosmosEventObj(
			struct IWebRTEventObj* pWebRTEventObj) = 0;
		virtual HRESULT __stdcall MessageBox(
			__int64 HWND,
			BSTR bstrContext,
			BSTR bstrCaption,
			long nStyle,
			/*[out,retval]*/ int* nRet) = 0;
		virtual HRESULT __stdcall DeletePage(
			__int64 PageHandle) = 0;
		virtual HRESULT __stdcall SetHostFocus() = 0;
		virtual HRESULT __stdcall UpdateXobj(
			struct IXobj* pXobj) = 0;
		virtual HRESULT __stdcall CreateCosmosEventObj(
			/*[out,retval]*/ struct IWebRTEventObj** ppWebRTEventObj) = 0;
		virtual HRESULT __stdcall InitEclipseApp() = 0;
		virtual HRESULT __stdcall CreateOutLookObj(
			BSTR bstrObjType,
			int nType,
			BSTR bstrURL,
			/*[out,retval]*/ IDispatch** ppRetDisp) = 0;
		virtual HRESULT __stdcall ObserveNuclei(
			__int64 HWND,
			BSTR bstrGalaxys,
			BSTR bstrKey,
			BSTR bstrXml,
			VARIANT_BOOL bSaveToConfigFile) = 0;
		virtual HRESULT __stdcall GetCtrlByName(
			IDispatch* pCtrl,
			BSTR bstrName,
			VARIANT_BOOL bFindInChild,
			/*[out,retval]*/ IDispatch** ppCtrlDisp) = 0;
		virtual HRESULT __stdcall GetXobjFromHandle(
			__int64 HWND,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
		virtual HRESULT __stdcall GetCtrlValueByName(
			IDispatch* pCtrl,
			BSTR bstrName,
			VARIANT_BOOL bFindInChild,
			/*[out,retval]*/ BSTR* bstrVal) = 0;
		virtual HRESULT __stdcall SetCtrlValueByName(
			IDispatch* pCtrl,
			BSTR bstrName,
			VARIANT_BOOL bFindInChild,
			BSTR bstrVal) = 0;
		virtual HRESULT __stdcall CreateCosmosCtrl(
			BSTR bstrAppID,
			/*[out,retval]*/ struct IWebRTCtrl** ppRetCtrl) = 0;
		virtual HRESULT __stdcall InitCLRApp(
			BSTR strInitXml,
			/*[out,retval]*/ __int64* llHandle) = 0;
		virtual HRESULT __stdcall DeleteGalaxy(
			struct INucleus* pGalaxy) = 0;
		virtual HRESULT __stdcall GetWindowClientDefaultNode(
			IDispatch* pAddDisp,
			__int64 hParent,
			BSTR bstrWndClaName,
			BSTR bstrGalaxyClusterName,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall CreateBrowser(
			unsigned __int64 hParentWnd,
			BSTR strUrls,
			/*[out,retval]*/ struct IBrowser** ppRet) = 0;
		virtual HRESULT __stdcall NewWorkBench(
			BSTR bstrCosmosDoc,
			/*[out,retval]*/ struct IWorkBenchWindow** ppWorkBenchWindow) = 0;
		virtual HRESULT __stdcall CreateCLRObjRemote(
			BSTR bstrObjID,
			BSTR bstrXmlData,
			__int64 HWND,
			/*[out,retval]*/ IDispatch** ppDisp) = 0;
		virtual HRESULT __stdcall DestroyCtrl(
			__int64 HWND) = 0;
		virtual HRESULT __stdcall GetRemoteHostViewRect(
			__int64 hHostWnd,
			/*[out,retval]*/ BSTR* strData) = 0;
		virtual HRESULT __stdcall CosmosCommand(
			IDispatch* RibbonControl) = 0;
		virtual HRESULT __stdcall CosmosGetImage(
			BSTR strValue,
			/*[out,retval]*/ IPictureDisp** ppdispImage) = 0;
		virtual HRESULT __stdcall CosmosGetVisible(
			IDispatch* RibbonControl,
			/*[out,retval]*/ VARIANT* varVisible) = 0;
		virtual HRESULT __stdcall CosmosOnLoad(
			IDispatch* RibbonControl) = 0;
		virtual HRESULT __stdcall CosmosGetItemCount(
			IDispatch* RibbonControl,
			/*[out,retval]*/ long* nCount) = 0;
		virtual HRESULT __stdcall CosmosGetItemLabel(
			IDispatch* RibbonControl,
			long nIndex,
			/*[out,retval]*/ BSTR* bstrLabel) = 0;
		virtual HRESULT __stdcall CosmosGetItemID(
			IDispatch* RibbonControl,
			long nIndex,
			/*[out,retval]*/ BSTR* bstrID) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-0601198231dc"))
		IWebRTCtrl : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_HWND(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall get_Cosmos(
			/*[out,retval]*/ struct IWebRT** pVal) = 0;
		virtual HRESULT __stdcall get_Tag(
			/*[out,retval]*/ VARIANT* pVal) = 0;
		virtual HRESULT __stdcall put_Tag(
			/*[in]*/ VARIANT pVal) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120161001"))
		IWebRTAppCtrl : IWebRTCtrl
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_AppCtrl(
			/*[in]*/ VARIANT_BOOL _arg1) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120160101"))
		IWebRTExtender : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall Close() = 0;
		virtual HRESULT __stdcall get_ActiveWorkBenchWindow(
			BSTR bstrID,
			/*[out,retval]*/ struct IWorkBenchWindow** pVal) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120160918"))
		IEclipseExtender : IWebRTExtender
	{};

	struct __declspec(uuid("19631222-1992-0612-1965-060119631222"))
		IOfficeExtender : IWebRTExtender
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall AddVBAFormsScript(
			IDispatch* OfficeObject,
			BSTR bstrKey,
			BSTR bstrXml) = 0;
		virtual HRESULT __stdcall InitVBAForm(
			/*[in]*/ IDispatch* newVal,
			/*[in]*/ long nStyle,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall GetNucleusFromVBAForm(
			IDispatch* pForm,
			/*[out,retval]*/ struct INucleus** ppNucleus) = 0;
		virtual HRESULT __stdcall GetActiveTopXobj(
			IDispatch* pForm,
			/*[out,retval]*/ struct IXobj** WndXobj) = 0;
		virtual HRESULT __stdcall GetObjectFromWnd(
			long HWND,
			/*[out,retval]*/ IDispatch** ppObjFromWnd) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060119825d34"))
		IWorkBenchWindow : IDispatch
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall get_Ctrl(
			/*[in]*/ VARIANT vIndex,
			/*[out,retval]*/ struct IEclipseCtrl** ppCtrl) = 0;
		virtual HRESULT __stdcall get__NewEnum(
			/*[out,retval]*/ IUnknown** ppVal) = 0;
		virtual HRESULT __stdcall get_Count(
			/*[out,retval]*/ long* pCount) = 0;
		virtual HRESULT __stdcall get_Handle(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall get_CosmosCtrl(
			__int64 HWND,
			/*[out,retval]*/ struct IEclipseCtrl** pVal) = 0;
		virtual HRESULT __stdcall get_Nuclei(
			/*[out,retval]*/ struct INuclei** pVal) = 0;
		virtual HRESULT __stdcall get_WinNucleus(
			/*[out,retval]*/ struct INucleus** pVal) = 0;
		virtual HRESULT __stdcall Active() = 0;
		virtual HRESULT __stdcall CloseTangramUI() = 0;
		virtual HRESULT __stdcall Observe(
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall ObserveEx(
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall ObserveinView(
			int nIndex,
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppRetXobj) = 0;
	};

	struct __declspec(uuid("19631222-1992-0612-1965-060120160912"))
		IEclipseCtrl : IWebRTCtrl
	{
		//
		// Raw methods provided by interface
		//

		virtual HRESULT __stdcall put_Handle(
			BSTR bstrHandleName,
			/*[in]*/ __int64 _arg2) = 0;
		virtual HRESULT __stdcall get_EclipseViewHandle(
			/*[out,retval]*/ __int64* pVal) = 0;
		virtual HRESULT __stdcall get_Nuclei(
			/*[out,retval]*/ struct INuclei** pVal) = 0;
		virtual HRESULT __stdcall get_WorkBenchWindow(
			/*[out,retval]*/ struct IWorkBenchWindow** pVal) = 0;
		virtual HRESULT __stdcall get_TopNuclei(
			/*[out,retval]*/ struct INuclei** pVal) = 0;
		virtual HRESULT __stdcall get_TopGalaxy(
			/*[out,retval]*/ struct INucleus** pVal) = 0;
		virtual HRESULT __stdcall get_ActiveTopXobj(
			/*[out,retval]*/ struct IXobj** pVal) = 0;
		virtual HRESULT __stdcall get_AppKeyValue(
			BSTR bstrKey,
			/*[out,retval]*/ VARIANT* pVal) = 0;
		virtual HRESULT __stdcall put_AppKeyValue(
			BSTR bstrKey,
			/*[in]*/ VARIANT pVal) = 0;
		virtual HRESULT __stdcall Observe(
			BSTR bstrNucleusName,
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall ObserveEx(
			BSTR bstrNucleusName,
			BSTR bstrKey,
			BSTR bstrXml,
			/*[out,retval]*/ struct IXobj** ppXobj) = 0;
		virtual HRESULT __stdcall InitCtrl(
			BSTR bstrXml) = 0;
	};

	//
	// Named GUID constants initializations
	//

	extern "C" const GUID __declspec(selectany) LIBID_Universe =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x09,0x11} };
	extern "C" const GUID __declspec(selectany) DIID__IWebRT =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x10,0x02} };
	extern "C" const GUID __declspec(selectany) IID_IWebRTEventObj =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x28} };
	extern "C" const GUID __declspec(selectany) CLSID_WebRT =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x99,0x06,0x06} };
	extern "C" const GUID __declspec(selectany) DIID__IXobjEvents =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x10,0x01} };
	extern "C" const GUID __declspec(selectany) DIID__IWebRTObjEvents =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x19,0x92} };
	extern "C" const GUID __declspec(selectany) DIID__IWebRTAppEvents =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x30} };
	extern "C" const GUID __declspec(selectany) CLSID_WebRTCtrl =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x07,0x10,0x01} };
	extern "C" const GUID __declspec(selectany) CLSID_CosmosExtender =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x00,0x00,0x00,0x00} };
	extern "C" const GUID __declspec(selectany) IID_IXobj =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x04} };
	extern "C" const GUID __declspec(selectany) IID_IXobjCollection =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x17} };
	extern "C" const GUID __declspec(selectany) IID_IBrowser =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x18,0x08,0x28} };
	extern "C" const GUID __declspec(selectany) IID_IWebView =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x18,0x09,0x03} };
	extern "C" const GUID __declspec(selectany) IID_INuclei =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x02} };
	extern "C" const GUID __declspec(selectany) IID_INucleus =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x03} };
	extern "C" const GUID __declspec(selectany) IID_IWebRT =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x01} };
	extern "C" const GUID __declspec(selectany) IID_IWebRTCtrl =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x31,0xdc} };
	extern "C" const GUID __declspec(selectany) IID_IWebRTAppCtrl =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x10,0x01} };
	extern "C" const GUID __declspec(selectany) IID_IWebRTExtender =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x01,0x01} };
	extern "C" const GUID __declspec(selectany) IID_IEclipseExtender =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x18} };
	extern "C" const GUID __declspec(selectany) IID_IOfficeExtender =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x63,0x12,0x22} };
	extern "C" const GUID __declspec(selectany) IID_IWorkBenchWindow =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x5d,0x34} };
	extern "C" const GUID __declspec(selectany) IID_IEclipseCtrl =
	{ 0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x12} };
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

	class DpiUtil
	{
	public:
		static void SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiAwarenessContext);

	private:
		static HMODULE GetUser32Module();
		static HMODULE GetShcoreModule();
		static PROCESS_DPI_AWARENESS ProcessDpiAwarenessFromDpiAwarenessContext(
			DPI_AWARENESS_CONTEXT dpiAwarenessContext);
	};

	class CTangramXmlParse
	{
	public:
		CTangramXmlParse* m_pParentParse;
		CTangramXmlParse(void);
		~CTangramXmlParse(void);

		CTangramXmlParse(CComPtr<IXMLDOMNode> _node)
		{
			//m_pUnknown = NULL;
			m_pParentParse = NULL;
			_CTangramXmlParse(_node);
		}
		CTangramXmlParse(CComPtr<IXMLDOMElement> _elem)
		{
			//m_pUnknown = NULL;
			_CTangramXmlParse(_elem);
		}
		CTangramXmlParse(CComPtr<IXMLDOMNodeList> _nlist)
		{
			//m_pUnknown = NULL;
			_CTangramXmlParse(_nlist);
		}

	private:
		void Initialize();

	protected:
		void _CTangramXmlParse(CComPtr<IXMLDOMNode> _node);
		void _CTangramXmlParse(CComPtr<IXMLDOMElement> _elem);
		void _CTangramXmlParse(CComPtr<IXMLDOMNodeList> _nlist);

	protected:
		//CArray<CTangramXmlParse*>  m_aChildElements;
		vector<CTangramXmlParse*>  m_aChildElements;
		CComPtr<IXMLDOMElement> elem;
		CComPtr<IXMLDOMDocument> m_pDoc;
		//CComPtr<IUnknown> m_pUnknown;
		//IUnknown*	m_pUnknown;

	public:
		//CComPtr<IXMLDOMElement> ReturnCurrentElement(){return elem;}
		CComPtr<IXMLDOMElement> GetElement() { return elem; }
		CString name();
		CString xml();
		CString text();
		CString attr(const CString name, CString def) const;

		DWORD attr(const CString name, DWORD def) const;

		bool attrBool(const CString name, bool def = false) const;
		int attrInt(const CString name, int def = 0) const;
		__int64 attrInt64(const CString name, __int64 def = 0) const;
		int GetCount() { return (int)m_aChildElements.size(); }
		bool Reflash();

		CTangramXmlParse* AddNode(CTangramXmlParse* pParse, CString strName);
		CTangramXmlParse* ReplaceNode(CTangramXmlParse* pOldParse, CTangramXmlParse* pNewParse, CString strName);
		CTangramXmlParse* AddNode(CString name);
		BOOL ModifyNode(int nRow, int nCol, CString strName, CString strXml);
		CTangramXmlParse* AddTabNode(CString strName, CString strObjTypeID, CString strObjID, CString strStyle, int nPages);
		CTangramXmlParse* AddSplitterNode(int nRow, int nCol, CString strName, int nWidth, int nHeight);
		HRESULT RemoveNode(CString name);
		HRESULT RemoveNode(int index);
		HRESULT RemoveNode(CTangramXmlParse* pItem);
		HRESULT RemoveSubNodes();
		bool put_attr(CString name, CString value);
		bool put_attr(CString name, int value);
		bool put_attr(CString name, __int64 value);
		bool put_attr(CString name, bool value);
		bool put_text(CString text);

	public:
		CTangramXmlParse* GetChild(CString strName);
		CTangramXmlParse* GetChild(int nIndex);
		CTangramXmlParse& operator[](CString strName);
		CTangramXmlParse& operator[](int nIndex);

		CTangramXmlParse* FindItem(LPCTSTR strItemname);
		CTangramXmlParse* FindItemByName(LPCTSTR strItemname);

		CTangramXmlParse* GetParseByElement(IXMLDOMElement* pEle);
		bool operator==(CTangramXmlParse& nItem);

		CString val() const;

		DWORD vall() const;
		bool LoadXml(CString strXML);
		bool LoadFile(CString strFile);
		bool SaveFile(CString strFile = _T(""));

	private:
		CString	m_strFile;
		bool	m_bCanSave;

	protected:
		void ModifyNameAttrByFix(CString strNameFix);
		CTangramXmlParse* _FindParseByEle(CTangramXmlParse* _pParent, IUnknown* pEle);
		bool Clear();
	};

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
		CMDIChildFormInfo() {}
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
		CWebRTDocProxy* m_pCurDocProxy;
		CWebRTImpl* m_pSpaceTelescopeImpl;

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
			m_bEnableHardwareAcceleration = true;
			m_strAppID = _T("");
			m_strNtpXml = _T("");
			m_strWebRTVer = _T("");
		}

		virtual ~CWebRTImpl() {}

		bool m_bHostMsgLoop;
		bool m_bChromeNeedClosed;
		bool m_bCreatingDevTool;
		bool m_bOMNIBOXPOPUPVISIBLE;
		bool m_b64bitSystem = false;
		bool m_bOfficeApp = false;
		bool m_bEclipse = false;
		bool m_bIsDlgApp = false;
		bool m_bIsNoWebRT = false;
		bool m_bCanClose;
		bool m_bWinFormActived;
		bool m_bEnableProcessFormTabKey;
		bool m_bDeleteNuclei;
		bool m_bIsSupportCrashReporting = false;
		bool m_bIsEclipseInit = false;
		bool m_bIsCreatingWPFCtrl = false;
		bool m_bEnableHardwareAcceleration;

		DWORD m_dwThreadID;
		DWORD m_nAppType;
		HWND m_hFirstView = nullptr;
		HWND m_hActiveWnd;
		HWND m_hEclipseHideWnd;
		HWND m_hMainWnd;
		HWND m_hCosmosWnd;
		HWND m_hFormNodeWnd;
		HWND m_hParent;
		HWND m_hHostBrowserWnd;
		HWND m_hTempBrowserWnd = NULL;
		HWND m_hWaitTabWebPageWnd = NULL;

		HMODULE m_hWebRTProxyModel;

		HICON m_hLargeIcon;
		HICON m_hSmallIcon;

		CString m_strAppID = _T("");
		CString m_strAppKey;
		CString m_strAppName;
		CString m_strExeName;
		CString m_strWebRTVer;
		CString m_strAppPath;
		CString m_strConfigDataFile;
		CString m_strAppDataPath;
		CString m_strCurrentAppID;
		CString m_strProgramFilePath;
		CString m_strAppCommonDocPath;
		CString m_strStartView;
		CString m_strNtpXml;
		CString m_strAppXml;
		CString m_strMainWndXml;
		CString m_strDefaultWorkBenchXml;

		CString m_strConfigFile;

		CString m_strCurrentKey;
		CString m_strWorkBenchStrs;
		CString m_strStartupURL = _T("");
		CString m_strCurrentEclipsePagePath;
		CString m_strDefaultXml;

		CStringA m_strBridgeJavaClass;
		CString m_strStartJarPath;

		CSession* m_pSession;
		IPCMsg* m_pCurrentIPCMsg;
		IWebRTCLRImpl* m_pCLRProxy;
		IUniverseAppProxy* m_pActiveAppProxy;
		IUniverseAppProxy* m_pUniverseAppProxy;
		IUniverseAppProxy* m_pWebRTAppProxy;
		CMDIChildFormInfo* m_pCurMDIChildFormInfo;
		IWebRTExtender* m_pExtender = nullptr;
		IContainer* m_pCreatingWindow = nullptr;
		CWebViewImpl* m_pMainWebPageImpl = nullptr;
		IWebRTDelegate* m_pWebRTDelegate = nullptr;
		CChromeBrowserBase* m_pActiveBrowser = nullptr;
		CWebRTBrowserFactory* m_pBrowserFactory = nullptr;
		CosmosAppMessagePumpForUI* m_pMessagePumpForUI = nullptr;
		OmniboxViewViewsProxy* m_pCreatingOmniboxViewViews = nullptr;
		CChromeRenderFrameHost* m_pCreatingChromeRenderFrameHostBase = nullptr;

		map<HWND, CString> m_mapUIData;
		map<HWND, CString> m_mapCtrlTag;
		map<DWORD, IWebRT*> m_mapRemoteTangramApp;
		map<CString, IDispatch*> m_mapObjDic;
		map<CString, CComVariant> m_mapValInfo;
		map<CString, IWebRT*> m_mapRemoteCosmos;
		map<CString, CString> m_mapDocAppName;
		map<CString, CString> m_mapDocTemplate;
		map<CString, CString> m_mapDocDefaultName;
		map<CString, CString> m_mapJavaNativeInfo;
		map<CString, CString> m_mapCreatingWorkBenchInfo;
		map<CString, HWND> m_mapSingleWndApp;
		map<CString, IUniverseAppProxy*> m_mapWebRTAppProxy;
		map<CString, IWindowProvider*> m_mapWindowProvider;

		map<HWND, IXobj*> m_mapXobj;
		map<HWND, CWebViewImpl*> m_mapWebView;
		map<HWND, HWND> m_mapBrowserForm;
		map<HWND, IBrowser*> m_mapBrowserWnd;
		map<HWND, IWebView*> m_mapFormWebPage;
		map<HWND, IWorkBenchWindow*> m_mapWorkBenchWnd;
		map<HWND, INuclei*> m_mapNuclei;
		map<HWND, WebRTFrameWndInfo*> m_mapWebRTFrameWndInfo;
		map<void*, IUnknown*> m_mapObjects;
		map<IDispatch*, CString> m_mapObjEventDic;

		virtual void Run() {}
		virtual void BrowserAppStart() {}
		virtual INucleus* ConnectNuclei(HWND,
			HWND,
			CString,
			INuclei* pNuclei,
			NucleusInfo*) {
			return nullptr;
		}
		virtual void OnSubBrowserWndCreated(HWND hParent, HWND hBrowser) {}
		virtual void OnRenderProcessCreated(CChromeRenderProcess* pProcess) {}
		virtual void OnDocumentOnLoadCompleted(CChromeRenderFrameHost*,
			HWND hHtmlWnd,
			void*) {}
		virtual void ChromeTabCreated(CChromeTab* pTab) {}
		virtual CString GetProcessPath(const char* _ver, CString process_type) {
			return _T("");
		}
		virtual CString GetSchemeBaseName() { return _T(""); }
		virtual HICON GetAppIcon(int nIndex) { return NULL; }
		virtual CChromeBrowserBase* GetChromeBrowserBase(HWND) { return nullptr; }
		virtual IBrowser* GetHostBrowser(HWND hNodeWnd) { return nullptr; }
		virtual void AttachXobj(void* pXobjEvents) {}
		virtual void WebRTInit() {}
		virtual INuclei* Observe(HWND, CString strName, CString strKey) {
			return nullptr;
		}
		virtual IXobj* ObserveCtrl(__int64 handle, CString name, CString NodeTag) {
			return nullptr;
		}
		virtual bool IsMDIClientNucleusNode(IXobj*) { return false; }
		virtual void InserttoDataMap(int nType, CString strKey, void* pData) {}
		virtual IWebView* GetWebPageFromForm(HWND) { return nullptr; }
		virtual long GetIPCMsgIndex(CString strMsgID) { return 0; }
		virtual CSession* CreateCloudSession(CWebViewImpl*) { return nullptr; }
		virtual CSession* GetCloudSession(IXobj*) { return nullptr; }
		virtual void SetMainWnd(HWND hMain) {}
		virtual IXobj* GetXobj(HWND hWnd) { return nullptr; }
		virtual INucleus* GetNucleus(HWND hWnd) { return nullptr; }
		virtual CWebViewImpl* GetWebPageImpl(HWND hWnd) { return nullptr; }
		virtual CBrowserImpl* GetBrowserImpl(HWND hWnd) { return nullptr; }
		virtual IXobj* ObserveXml(HWND hWnd, CString strKey, CString strXml) {
			return nullptr;
		}
		virtual void SendIPCMsg(HWND hXobj, CString strMsgID) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, CString strVal) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, __int64 llVal) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, long lVal) {}
		virtual void InsertMsgData(HWND hXobj, CString strKey, float fVal) {}
		virtual CString GetMsgStringData(HWND hXobj, CString strKey) {
			return _T("");
		}
		virtual __int64 GetMsgInt64(HWND hXobj, CString strKey) { return 0; }
		virtual long GetMsgLong(HWND hXobj, CString strKey) { return 0; }
		virtual float GetMsgFloat(HWND hXobj, CString strKey) { return 0.0f; }
		virtual bool SetFrameInfo(HWND hWnd,
			HWND hFrame,
			CString strTemplateID,
			void* pDoc,
			void* pDocTemplate) {
			return false;
		}
		virtual CTabStatsTrackerDelegate* SetTabStatsTrackerDelegate() {
			return nullptr;
		}
		virtual void OnNetworkChangeNotify(int ConnectType, __int64 NetworkHandle) {}
		virtual void OnWebRTMessage(HWND hWnd,
			CChromeRenderFrameHost*,
			CommonUniverse::IPCMsg* pIPCInfo) {}
		virtual void OnCLRHostExit() {}
		virtual void ConnectMsgLoop(HWND hMsg) {}
		virtual void OnUpdateParent(HWND hPWnd, HWND hWnd, int DeviceScaleFactor) {}
		virtual void OnNewSurfaceWnd(HWND hWnd, HWND hSurfaceWnd) {}
		virtual void OnExitMainMsgPump() {}
		virtual void OnBatteryChanged() {}
		virtual wstring Json2Xml(wstring strJson, bool bJsonstr) { return L""; }
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
		}

		virtual ~IWebRTDelegate() {}

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
		CBrowserImpl() {}
		virtual ~CBrowserImpl() {}

		bool m_bDestroy = false;
		bool m_bTabChange;
		bool m_bSZMode = false;
		bool m_bInTabChange = false;
		float m_fdevice_scale_factor;
		HWND m_hOldTab;
		HWND m_hBeforeChange = NULL;
		RECT m_OldRect;
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
		CChromeRenderFrameHost() { m_pProxy = nullptr; }

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

#ifdef _AFX
	class CAIGCWinApp :
		public CWinApp,
		public IUniverseAppProxy,
		public IWindowProvider {
	public:
		CAIGCWinApp();
		virtual ~CAIGCWinApp();
		CString GetDocTemplateID(CDocument* pDoc);

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);

	private:
		bool m_bBuiltInBrowser = false;
		bool m_bCrashReporting = false;
		bool m_bNoDefaultMainWnd = false;
		map<CView*, CDocument*> m_mapViewDoc;
		BOOL IsBrowserModel(bool bCrashReporting);
		bool ProcessAppType(bool bCrashReporting);
		virtual int Run();
		virtual BOOL InitApplication();
		virtual HWND GetActivePopupMenu(HWND hWnd);

		//IUniverseAppProxy:
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {};
		virtual void OnObserveComplete(HWND hContentLoaderWnd, CString strUrl, IXobj* pRootNode) {};
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode);
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewFrame);
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewContentLoaderManager);
		virtual void OnIPCMsg(CWebViewImpl* pWebViewImpl, CString strType, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5);
		virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML) {};
		virtual void OpenDocFile(CString strFileName, CString strExt, CString strCreatingDOCID);
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd);
		virtual CString QueryWndClassName(HWND hWnd);
		virtual CString QueryDocType(HWND hWnd);
		virtual bool EclipseAppInit() { return false; };
		virtual bool SetFrameCaption(HWND hWnd, CString strCaption, CString strAppName);
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo);
		virtual HWND GetFrameWnd(HWND hWnd, int& nType);

		//IWindowProvider:
		virtual CString GetNames();
		virtual CString GetTags(CString strName);
		virtual HWND Create(HWND hParentWnd, IXobj* pGrid);
	};

	class CComponentApp :
		public CWinApp,
		public IWindowProvider
	{
	public:
		CComponentApp();
		virtual ~CComponentApp();
		bool WebRTInit(CString strID);
		virtual BOOL InitInstance();
		virtual int ExitInstance();
	private:
		virtual CString GetNames();
		virtual CString GetTags(CString strName);
		virtual HWND Create(HWND hParentWnd, IXobj* pGrid);
	};

	class CAIGCWinAppEx :
		public CWinAppEx,
		public IUniverseAppProxy,
		public IWindowProvider {
	public:
		CAIGCWinAppEx();
		virtual ~CAIGCWinAppEx();
		CString GetDocTemplateID(CDocument* pDoc);

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);

	private:
		bool m_bBuiltInBrowser = false;
		bool m_bCrashReporting = false;
		bool m_bNoDefaultMainWnd = false;
		map<CView*, CDocument*> m_mapViewDoc;
		BOOL IsBrowserModel(bool bCrashReporting);
		bool ProcessAppType(bool bCrashReporting);
		virtual int Run();
		virtual BOOL InitApplication();
		virtual HWND GetActivePopupMenu(HWND hWnd);

		//IUniverseAppProxy:
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {};
		virtual void OnObserveComplete(HWND hContentLoaderWnd, CString strUrl, IXobj* pRootNode) {};
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode);
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewFrame);
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewContentLoaderManager);
		virtual void OnIPCMsg(CWebViewImpl* pWebViewImpl, CString strType, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5);
		virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML) {};
		virtual void OpenDocFile(CString strFileName, CString strExt, CString strCreatingDOCID);
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd);
		virtual CString QueryWndClassName(HWND hWnd);
		virtual CString QueryDocType(HWND hWnd);
		virtual bool EclipseAppInit() { return false; };
		virtual bool SetFrameCaption(HWND hWnd, CString strCaption, CString strAppName);
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo);
		virtual HWND GetFrameWnd(HWND hWnd, int& nType);

		//IWindowProvider:
		//virtual bool WebRTInit(CString strID);
		virtual CString GetNames();
		virtual CString GetTags(CString strName);
		virtual HWND Create(HWND hParentWnd, IXobj* pGrid);
	};

	class CWebRTMDIFrame :
		public CMDIFrameWndEx,
		public CNucleiProxy
	{
	public:
		CWebRTMDIFrame() {};
		virtual ~CWebRTMDIFrame() {};

		DECLARE_DYNCREATE(CWebRTMDIFrame)

		virtual BOOL OnShowPopupMenu(CMFCPopupMenu* /*pMenuPopup*/);
		//virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
		virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	protected:
		DECLARE_MESSAGE_MAP()

	private:
		bool bAdjustClient = false;

		void AdjustClientArea();
		void OnTabChange(IXobj* sender, LONG ActivePage, LONG OldPage);
		void OnClrControlCreated(IXobj* Node, IDispatch* Ctrl, CString CtrlName, HWND CtrlHandle);
		void OnEvent(IDispatch* sender, IDispatch* EventArg) {};
		void OnControlNotify(IXobj* sender, LONG NotifyCode, LONG CtrlID, HWND CtrlHandle, CString CtrlClassName) {};
		void OnHubbleEvent(IWebRTEventObj* NotifyObj) {};
	};
#else
	class CAIGCApp :
		public IUniverseAppProxy,
		public IWindowProvider {
	public:
		CAIGCApp();
		virtual ~CAIGCApp();

		CString m_strExeName;

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);

		virtual BOOL InitApplication();
	private:
		bool m_bBuiltInBrowser = false;
		bool m_bCrashReporting = false;
		bool m_bNoDefaultMainWnd = false;
		BOOL IsBrowserModel(bool bCrashReporting);
		bool ProcessAppType(bool bCrashReporting);
		virtual HWND GetActivePopupMenu(HWND hWnd) { return NULL; };

		//IUniverseAppProxy:
		virtual void OnWebRTEvent(IWebRTEventObj* NotifyObj) {};
		virtual void OnObserveComplete(HWND hContentLoaderWnd, CString strUrl, IXobj* pRootNode) {};
		virtual CXobjProxy* OnXobjInit(IXobj* pNewNode);
		virtual CNucleusProxy* OnNucleusCreated(INucleus* pNewFrame);
		virtual CNucleiProxy* OnNucleiCreated(INuclei* pNewContentLoaderManager);
		virtual void OnIPCMsg(CWebViewImpl* pWebViewImpl, CString strType, CString strParam1, CString strParam2, CString strParam3, CString strParam4, CString strParam5) {};
		virtual void CustomizedDOMElement(HWND hWnd, CString strRuleName, CString strHTML) {};
		virtual void OpenDocFile(CString strFileName, CString strExt, CString strCreatingDOCID) {};
		virtual HWND QueryWndInfo(QueryType nType, HWND hWnd) { return NULL; };
		virtual CString QueryWndClassName(HWND hWnd) { return _T(""); };
		virtual CString QueryDocType(HWND hWnd) { return _T(""); };
		virtual bool EclipseAppInit() { return false; };
		virtual bool SetFrameCaption(HWND hWnd, CString strCaption, CString strAppName) { return false; };
		virtual CString QueryParentInfo(HWND hPWnd, void* lpInfo) { return _T(""); };
		virtual HWND GetFrameWnd(HWND hWnd, int& nType) { return NULL; };

		//IWindowProvider:
		virtual CString GetNames() { return _T(""); };
		virtual CString GetTags(CString strName) { return _T(""); };
		virtual HWND Create(HWND hParentWnd, IXobj* pXobj) { return NULL; };
		virtual IDispatch* CreateCtrl(CString strCtrlID) { return NULL; }
	};

	class CAIGCAppEx :
		public CAIGCApp
	{
	public:
		CAIGCAppEx();
		virtual ~CAIGCAppEx();

	private:
		static LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam);
		virtual bool WebRTInit(CString strID);
	};

	class CWebRTWindowProviderApp :
		public IWindowProvider {
	public:
		CWebRTWindowProviderApp();
		virtual ~CWebRTWindowProviderApp();

		HINSTANCE m_hModule;

		//IWindowProvider:
		virtual bool WebRTInit(CString strID);
	private:
		//IWindowProvider:
		virtual HWND Create(HWND hParentWnd, IXobj* pXobj) { return NULL; };
	};

	template <class T>
	class ATL_NO_VTABLE CAIGCModuleT :
		public CAIGCApp,
		public CAtlExeModuleT<T>
	{
	public:
		virtual HRESULT PreMessageLoop(int nShowCmd) {
			if (InitApplication()) {
				__super::PreMessageLoop(nShowCmd);
				return S_OK;
			}
			return S_FALSE;
		}
	};
#endif
};

using namespace CommonUniverse;
extern IWebRT* g_pWebRT;

#ifdef WebRTDefault

#ifndef CMDIFrameWndEx
#ifndef _WINDLL
#define CWinApp CAIGCWinApp
#else
#define CWinApp CComponentApp
#endif // !_WINDLL

#define CWinAppEx CAIGCWinAppEx
#define CMDIFrameWndEx CWebRTMDIFrame
#endif // !CMDIFrameWndEx

#ifndef CAtlExeModuleT
#define CAtlExeModuleT CAIGCModuleT
#endif // !CAtlExeModuleT

#endif // WebRTDefault

