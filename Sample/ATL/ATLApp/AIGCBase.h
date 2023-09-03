#pragma once

#include <map>
#include "metahost.h"
#include "CommonUniverse.h"
#include "TangramXmlParse.h"
#include <ppl.h>
#include <ppltasks.h>
#include <agents.h>
#include <shlobj.h>
#include <atlctl.h>
#ifdef _AFX
#include <afxcontrolbars.h>     // MFC support for ribbons and control bars
#include <afxcview.h>
#endif
using namespace std;
using namespace ATL;
using namespace concurrency;

#pragma comment(lib, "imagehlp.lib")

namespace CommonUniverse
{
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
