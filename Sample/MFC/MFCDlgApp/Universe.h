// Created by Microsoft (R) C/C++ Compiler Version 14.36.32538.0 (155ad371).
// C++ source equivalent of type library Universe.tlb
// compiler-generated file - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace Universe {

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

      virtual HRESULT __stdcall get_eventSource (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall put_eventSource (
        /*[in]*/ IDispatch * pVal ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ int * nVal ) = 0;
      virtual HRESULT __stdcall put_Index (
        int nVal ) = 0;
      virtual HRESULT __stdcall get_EventName (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_EventName (
        BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Object (
        int nIndex,
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall put_Object (
        int nIndex,
        IDispatch * pVal ) = 0;
      virtual HRESULT __stdcall get_Value (
        int nIndex,
        /*[out,retval]*/ VARIANT * pVal ) = 0;
      virtual HRESULT __stdcall put_Value (
        int nIndex,
        VARIANT pVal ) = 0;
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

      virtual HRESULT __stdcall get_ChildNodes (
        /*[out,retval]*/ struct IXobjCollection * * ppXobjColletion ) = 0;
      virtual HRESULT __stdcall get_Rows (
        /*[out,retval]*/ long * nRows ) = 0;
      virtual HRESULT __stdcall get_Cols (
        /*[out,retval]*/ long * nCols ) = 0;
      virtual HRESULT __stdcall get_Row (
        /*[out,retval]*/ long * nRow ) = 0;
      virtual HRESULT __stdcall get_Col (
        /*[out,retval]*/ long * nCol ) = 0;
      virtual HRESULT __stdcall get_XobjType (
        /*[out,retval]*/ enum XobjType * nType ) = 0;
      virtual HRESULT __stdcall get_ParentXobj (
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_URL (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Nuclei (
        /*[out,retval]*/ struct INuclei * * pVal ) = 0;
      virtual HRESULT __stdcall get_RootXobj (
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall get_XObject (
        /*[out,retval]*/ VARIANT * pVar ) = 0;
      virtual HRESULT __stdcall get_AxPlugIn (
        /*[in]*/ BSTR bstrPlugInName,
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Caption (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Objects (
        /*[in]*/ long nType,
        /*[out,retval]*/ struct IXobjCollection * * ppXobjColletion ) = 0;
      virtual HRESULT __stdcall get_Handle (
        /*[out,retval]*/ __int64 * HWND ) = 0;
      virtual HRESULT __stdcall get_Attribute (
        /*[in]*/ BSTR bstrKey,
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Attribute (
        /*[in]*/ BSTR bstrKey,
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Tag (
        /*[out,retval]*/ VARIANT * pVar ) = 0;
      virtual HRESULT __stdcall put_Tag (
        /*[in]*/ VARIANT pVar ) = 0;
      virtual HRESULT __stdcall get_OuterXml (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Key (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_WebView (
        /*[out,retval]*/ struct IWebView * * pVal ) = 0;
      virtual HRESULT __stdcall get_NameAtWindowPage (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall get_WinNucleus (
        /*[out,retval]*/ struct INucleus * * pVal ) = 0;
      virtual HRESULT __stdcall get_XML (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall put_Extender (
        /*[in]*/ IDispatch * pVal ) = 0;
      virtual HRESULT __stdcall get_DocXml (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_rgbMiddle (
        /*[out,retval]*/ OLE_COLOR * pVal ) = 0;
      virtual HRESULT __stdcall put_rgbMiddle (
        /*[in]*/ OLE_COLOR pVal ) = 0;
      virtual HRESULT __stdcall get_rgbRightBottom (
        /*[out,retval]*/ OLE_COLOR * pVal ) = 0;
      virtual HRESULT __stdcall put_rgbRightBottom (
        /*[in]*/ OLE_COLOR pVal ) = 0;
      virtual HRESULT __stdcall get_rgbLeftTop (
        /*[out,retval]*/ OLE_COLOR * pVal ) = 0;
      virtual HRESULT __stdcall put_rgbLeftTop (
        /*[in]*/ OLE_COLOR pVal ) = 0;
      virtual HRESULT __stdcall get_Hmin (
        /*[out,retval]*/ int * pVal ) = 0;
      virtual HRESULT __stdcall put_Hmin (
        /*[in]*/ int pVal ) = 0;
      virtual HRESULT __stdcall get_Hmax (
        /*[out,retval]*/ int * pVal ) = 0;
      virtual HRESULT __stdcall put_Hmax (
        /*[in]*/ int pVal ) = 0;
      virtual HRESULT __stdcall get_Vmin (
        /*[out,retval]*/ int * pVal ) = 0;
      virtual HRESULT __stdcall put_Vmin (
        /*[in]*/ int pVal ) = 0;
      virtual HRESULT __stdcall get_Vmax (
        /*[out,retval]*/ int * pVal ) = 0;
      virtual HRESULT __stdcall put_Vmax (
        /*[in]*/ int pVal ) = 0;
      virtual HRESULT __stdcall get_HostXobj (
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall put_HostXobj (
        /*[in]*/ struct IXobj * pVal ) = 0;
      virtual HRESULT __stdcall get_ActivePage (
        /*[out,retval]*/ int * pVal ) = 0;
      virtual HRESULT __stdcall put_ActivePage (
        /*[in]*/ int pVal ) = 0;
      virtual HRESULT __stdcall get_HostGalaxy (
        /*[out,retval]*/ struct INucleus * * pVal ) = 0;
      virtual HRESULT __stdcall get_OfficeObj (
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall ActiveTabPage (
        struct IXobj * pXobj ) = 0;
      virtual HRESULT __stdcall GetXobjs (
        /*[in]*/ BSTR bstrName,
        /*[out]*/ struct IXobj * * ppXobj,
        /*[out]*/ struct IXobjCollection * * ppXobjs,
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall GetXobj (
        /*[in]*/ long nRow,
        /*[in]*/ long nCol,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall GetCtrlByName (
        BSTR bstrName,
        VARIANT_BOOL bFindInChild,
        /*[out,retval]*/ IDispatch * * ppCtrlDisp ) = 0;
      virtual HRESULT __stdcall SendIPCMessage (
        BSTR bstrTo,
        BSTR bstrPayload,
        BSTR bstrExtra,
        BSTR bstrMsgId,
        /*[out,retval]*/ BSTR * bstrRes ) = 0;
      virtual HRESULT __stdcall Observe (
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
      virtual HRESULT __stdcall LoadXML (
        int nType,
        BSTR bstrXml ) = 0;
      virtual HRESULT __stdcall ObserveEx (
        int nRow,
        int nCol,
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
      virtual HRESULT __stdcall GetXobjByName (
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ struct IXobjCollection * * pVal ) = 0;
      virtual HRESULT __stdcall GetCtrlValueByName (
        BSTR bstrName,
        VARIANT_BOOL bFindInChild,
        /*[out,retval]*/ BSTR * bstrVal ) = 0;
      virtual HRESULT __stdcall SetCtrlValueByName (
        BSTR bstrName,
        VARIANT_BOOL bFindInChild,
        BSTR bstrVal ) = 0;
      virtual HRESULT __stdcall NavigateURL (
        BSTR bstrURL,
        IDispatch * dispObjforScript ) = 0;
      virtual HRESULT __stdcall GetChildXobjByName (
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall GetUIScript (
        /*[in]*/ BSTR bstrCtrlName,
        /*[out,retval]*/ BSTR * bstrVal ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060119820017"))
IXobjCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_XobjCount (
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ long iIndex,
        /*[out,retval]*/ struct IXobj * * ppTopWindow ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppVal ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060120180828"))
IBrowser : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_RemoteXobj (
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall put_RemoteXobj (
        /*[in]*/ struct IXobj * pVal ) = 0;
      virtual HRESULT __stdcall OpenURL (
        BSTR bstrURL,
        enum BrowserWndOpenDisposition nDisposition,
        BSTR bstrKey,
        BSTR bstrXml ) = 0;
      virtual HRESULT __stdcall AddURLs (
        BSTR bstrURLs ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060120180903"))
IWebView : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_HostWnd (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall put_HostWnd (
        /*[in]*/ __int64 pVal ) = 0;
      virtual HRESULT __stdcall get_WebBrowser (
        /*[out,retval]*/ struct IBrowser * * ppWebBrowser ) = 0;
      virtual HRESULT __stdcall CreateForm (
        BSTR bstrKey,
        __int64 hParent,
        /*[out,retval]*/ IDispatch * * pRetForm ) = 0;
      virtual HRESULT __stdcall Observe (
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * pRetXobj ) = 0;
      virtual HRESULT __stdcall SendXmlMessage (
        struct IXobj * sender,
        BSTR bstrXml ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060119820002"))
INuclei : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_WinNucleus (
        /*[in]*/ VARIANT vIndex,
        /*[out,retval]*/ struct INucleus * * ppNucleus ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppVal ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall get_NucleiXML (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct INuclei * * pVal ) = 0;
      virtual HRESULT __stdcall get_Xobj (
        BSTR bstrNodeName,
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall get_XObject (
        BSTR bstrName,
        /*[out,retval]*/ IDispatch * * pVal ) = 0;
      virtual HRESULT __stdcall get_NucleusName (
        __int64 hHwnd,
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Handle (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long pVal ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long pVal ) = 0;
      virtual HRESULT __stdcall get_XobjNames (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall CreateNucleus (
        VARIANT ParentObj,
        VARIANT HostWnd,
        BSTR bstrNucleusName,
        /*[out,retval]*/ struct INucleus * * pRetGalaxy ) = 0;
      virtual HRESULT __stdcall Observe (
        IDispatch * Parent,
        BSTR CtrlName,
        BSTR NucleusName,
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
      virtual HRESULT __stdcall ObserveCtrl (
        VARIANT Ctrl,
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
      virtual HRESULT __stdcall GetXobj (
        BSTR bstrNucleusName,
        BSTR bstrNodeName,
        /*[out,retval]*/ struct IXobj * * pRetNode ) = 0;
      virtual HRESULT __stdcall GetCtrlInXobj (
        BSTR NodeName,
        BSTR CtrlName,
        /*[out,retval]*/ IDispatch * * ppCtrl ) = 0;
      virtual HRESULT __stdcall GetNucleusFromCtrl (
        IDispatch * Ctrl,
        /*[out,retval]*/ struct INucleus * * ppNucleus ) = 0;
      virtual HRESULT __stdcall ObserveNuclei (
        BSTR bstrGalaxys,
        BSTR bstrKey,
        BSTR bstrXml,
        VARIANT_BOOL bSaveToConfigFile ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060119820003"))
INucleus : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Xobj (
        /*[in]*/ VARIANT vIndex,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppVal ) = 0;
      virtual HRESULT __stdcall get_HWND (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall get_VisibleXobj (
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall get_CurrentNavigateKey (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Nuclei (
        /*[out,retval]*/ struct INuclei * * pVal ) = 0;
      virtual HRESULT __stdcall get_HostWebPage (
        /*[out,retval]*/ struct IWebView * * ppChromeWebPage ) = 0;
      virtual HRESULT __stdcall get_HostBrowser (
        /*[out,retval]*/ struct IBrowser * * ppChromeWebBrowser ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall get_RootXobjs (
        /*[out,retval]*/ struct IXobjCollection * * ppXobjColletion ) = 0;
      virtual HRESULT __stdcall get_GalaxyXML (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_GalaxyType (
        /*[out,retval]*/ enum GalaxyType * pVal ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall Detach ( ) = 0;
      virtual HRESULT __stdcall Attach ( ) = 0;
      virtual HRESULT __stdcall ModifyHost (
        __int64 hHostWnd ) = 0;
      virtual HRESULT __stdcall Observe (
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
      virtual HRESULT __stdcall GetXml (
        BSTR bstrRootName,
        /*[out,retval]*/ BSTR * bstrRet ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060119820001"))
IWebRT : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_HostChromeBrowserWnd (
        /*[out,retval]*/ struct IBrowser * * ppChromeWebBrowser ) = 0;
      virtual HRESULT __stdcall get_AppKeyValue (
        BSTR bstrKey,
        /*[out,retval]*/ VARIANT * pVal ) = 0;
      virtual HRESULT __stdcall put_AppKeyValue (
        BSTR bstrKey,
        /*[in]*/ VARIANT pVal ) = 0;
      virtual HRESULT __stdcall get_RemoteHelperHWND (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall put_RemoteHelperHWND (
        /*[in]*/ __int64 pVal ) = 0;
      virtual HRESULT __stdcall get_RootNodes (
        /*[out,retval]*/ struct IXobjCollection * * ppXobjColletion ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[out,retval]*/ struct IWebRTExtender * * pVal ) = 0;
      virtual HRESULT __stdcall put_Extender (
        /*[in]*/ struct IWebRTExtender * pVal ) = 0;
      virtual HRESULT __stdcall get_CurrentActiveXobj (
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall get_CreatingXobj (
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall get_RemoteCosmos (
        BSTR bstrID,
        /*[out,retval]*/ struct IWebRT * * pVal ) = 0;
      virtual HRESULT __stdcall NavigateNode (
        struct IXobj * pXobj,
        BSTR bstrBrowserID,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall CreateNucleusGroup (
        __int64 HWND,
        /*[out,retval]*/ struct INuclei * * ppNucleusCluster ) = 0;
      virtual HRESULT __stdcall CreateOfficeDocument (
        BSTR bstrXml ) = 0;
      virtual HRESULT __stdcall CreateCLRObj (
        BSTR bstrObjID,
        /*[out,retval]*/ IDispatch * * ppDisp ) = 0;
      virtual HRESULT __stdcall CreateApplication (
        BSTR bstrAppID,
        BSTR bstrXml ) = 0;
      virtual HRESULT __stdcall GetNucleus (
        __int64 hHostWnd,
        /*[out,retval]*/ struct INucleus * * ppNucleus ) = 0;
      virtual HRESULT __stdcall GetItemText (
        struct IXobj * pXobj,
        long nCtrlID,
        long nMaxLengeh,
        /*[out,retval]*/ BSTR * bstrRet ) = 0;
      virtual HRESULT __stdcall SetItemText (
        struct IXobj * pXobj,
        long nCtrlID,
        BSTR bstrText ) = 0;
      virtual HRESULT __stdcall FireCosmosEventObj (
        struct IWebRTEventObj * pWebRTEventObj ) = 0;
      virtual HRESULT __stdcall MessageBox (
        __int64 HWND,
        BSTR bstrContext,
        BSTR bstrCaption,
        long nStyle,
        /*[out,retval]*/ int * nRet ) = 0;
      virtual HRESULT __stdcall DeletePage (
        __int64 PageHandle ) = 0;
      virtual HRESULT __stdcall SetHostFocus ( ) = 0;
      virtual HRESULT __stdcall UpdateXobj (
        struct IXobj * pXobj ) = 0;
      virtual HRESULT __stdcall CreateCosmosEventObj (
        /*[out,retval]*/ struct IWebRTEventObj * * ppWebRTEventObj ) = 0;
      virtual HRESULT __stdcall InitEclipseApp ( ) = 0;
      virtual HRESULT __stdcall CreateOutLookObj (
        BSTR bstrObjType,
        int nType,
        BSTR bstrURL,
        /*[out,retval]*/ IDispatch * * ppRetDisp ) = 0;
      virtual HRESULT __stdcall ObserveNuclei (
        __int64 HWND,
        BSTR bstrGalaxys,
        BSTR bstrKey,
        BSTR bstrXml,
        VARIANT_BOOL bSaveToConfigFile ) = 0;
      virtual HRESULT __stdcall GetCtrlByName (
        IDispatch * pCtrl,
        BSTR bstrName,
        VARIANT_BOOL bFindInChild,
        /*[out,retval]*/ IDispatch * * ppCtrlDisp ) = 0;
      virtual HRESULT __stdcall GetXobjFromHandle (
        __int64 HWND,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
      virtual HRESULT __stdcall GetCtrlValueByName (
        IDispatch * pCtrl,
        BSTR bstrName,
        VARIANT_BOOL bFindInChild,
        /*[out,retval]*/ BSTR * bstrVal ) = 0;
      virtual HRESULT __stdcall SetCtrlValueByName (
        IDispatch * pCtrl,
        BSTR bstrName,
        VARIANT_BOOL bFindInChild,
        BSTR bstrVal ) = 0;
      virtual HRESULT __stdcall CreateCosmosCtrl (
        BSTR bstrAppID,
        /*[out,retval]*/ struct IWebRTCtrl * * ppRetCtrl ) = 0;
      virtual HRESULT __stdcall InitCLRApp (
        BSTR strInitXml,
        /*[out,retval]*/ __int64 * llHandle ) = 0;
      virtual HRESULT __stdcall DeleteGalaxy (
        struct INucleus * pGalaxy ) = 0;
      virtual HRESULT __stdcall GetWindowClientDefaultNode (
        IDispatch * pAddDisp,
        __int64 hParent,
        BSTR bstrWndClaName,
        BSTR bstrGalaxyClusterName,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall CreateBrowser (
        unsigned __int64 hParentWnd,
        BSTR strUrls,
        /*[out,retval]*/ struct IBrowser * * ppRet ) = 0;
      virtual HRESULT __stdcall NewWorkBench (
        BSTR bstrCosmosDoc,
        /*[out,retval]*/ struct IWorkBenchWindow * * ppWorkBenchWindow ) = 0;
      virtual HRESULT __stdcall CreateCLRObjRemote (
        BSTR bstrObjID,
        BSTR bstrXmlData,
        __int64 HWND,
        /*[out,retval]*/ IDispatch * * ppDisp ) = 0;
      virtual HRESULT __stdcall DestroyCtrl (
        __int64 HWND ) = 0;
      virtual HRESULT __stdcall GetRemoteHostViewRect (
        __int64 hHostWnd,
        /*[out,retval]*/ BSTR * strData ) = 0;
      virtual HRESULT __stdcall CosmosCommand (
        IDispatch * RibbonControl ) = 0;
      virtual HRESULT __stdcall CosmosGetImage (
        BSTR strValue,
        /*[out,retval]*/ IPictureDisp * * ppdispImage ) = 0;
      virtual HRESULT __stdcall CosmosGetVisible (
        IDispatch * RibbonControl,
        /*[out,retval]*/ VARIANT * varVisible ) = 0;
      virtual HRESULT __stdcall CosmosOnLoad (
        IDispatch * RibbonControl ) = 0;
      virtual HRESULT __stdcall CosmosGetItemCount (
        IDispatch * RibbonControl,
        /*[out,retval]*/ long * nCount ) = 0;
      virtual HRESULT __stdcall CosmosGetItemLabel (
        IDispatch * RibbonControl,
        long nIndex,
        /*[out,retval]*/ BSTR * bstrLabel ) = 0;
      virtual HRESULT __stdcall CosmosGetItemID (
        IDispatch * RibbonControl,
        long nIndex,
        /*[out,retval]*/ BSTR * bstrID ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-0601198231dc"))
IWebRTCtrl : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_HWND (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall get_Cosmos (
        /*[out,retval]*/ struct IWebRT * * pVal ) = 0;
      virtual HRESULT __stdcall get_Tag (
        /*[out,retval]*/ VARIANT * pVal ) = 0;
      virtual HRESULT __stdcall put_Tag (
        /*[in]*/ VARIANT pVal ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060120161001"))
IWebRTAppCtrl : IWebRTCtrl
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_AppCtrl (
        /*[in]*/ VARIANT_BOOL _arg1 ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060120160101"))
IWebRTExtender : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall get_ActiveWorkBenchWindow (
        BSTR bstrID,
        /*[out,retval]*/ struct IWorkBenchWindow * * pVal ) = 0;
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

      virtual HRESULT __stdcall AddVBAFormsScript (
        IDispatch * OfficeObject,
        BSTR bstrKey,
        BSTR bstrXml ) = 0;
      virtual HRESULT __stdcall InitVBAForm (
        /*[in]*/ IDispatch * newVal,
        /*[in]*/ long nStyle,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall GetNucleusFromVBAForm (
        IDispatch * pForm,
        /*[out,retval]*/ struct INucleus * * ppNucleus ) = 0;
      virtual HRESULT __stdcall GetActiveTopXobj (
        IDispatch * pForm,
        /*[out,retval]*/ struct IXobj * * WndXobj ) = 0;
      virtual HRESULT __stdcall GetObjectFromWnd (
        long HWND,
        /*[out,retval]*/ IDispatch * * ppObjFromWnd ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060119825d34"))
IWorkBenchWindow : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Ctrl (
        /*[in]*/ VARIANT vIndex,
        /*[out,retval]*/ struct IEclipseCtrl * * ppCtrl ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * ppVal ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pCount ) = 0;
      virtual HRESULT __stdcall get_Handle (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall get_CosmosCtrl (
        __int64 HWND,
        /*[out,retval]*/ struct IEclipseCtrl * * pVal ) = 0;
      virtual HRESULT __stdcall get_Nuclei (
        /*[out,retval]*/ struct INuclei * * pVal ) = 0;
      virtual HRESULT __stdcall get_WinNucleus (
        /*[out,retval]*/ struct INucleus * * pVal ) = 0;
      virtual HRESULT __stdcall Active ( ) = 0;
      virtual HRESULT __stdcall CloseTangramUI ( ) = 0;
      virtual HRESULT __stdcall Observe (
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall ObserveEx (
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall ObserveinView (
        int nIndex,
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppRetXobj ) = 0;
};

struct __declspec(uuid("19631222-1992-0612-1965-060120160912"))
IEclipseCtrl : IWebRTCtrl
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_Handle (
        BSTR bstrHandleName,
        /*[in]*/ __int64 _arg2 ) = 0;
      virtual HRESULT __stdcall get_EclipseViewHandle (
        /*[out,retval]*/ __int64 * pVal ) = 0;
      virtual HRESULT __stdcall get_Nuclei (
        /*[out,retval]*/ struct INuclei * * pVal ) = 0;
      virtual HRESULT __stdcall get_WorkBenchWindow (
        /*[out,retval]*/ struct IWorkBenchWindow * * pVal ) = 0;
      virtual HRESULT __stdcall get_TopNuclei (
        /*[out,retval]*/ struct INuclei * * pVal ) = 0;
      virtual HRESULT __stdcall get_TopGalaxy (
        /*[out,retval]*/ struct INucleus * * pVal ) = 0;
      virtual HRESULT __stdcall get_ActiveTopXobj (
        /*[out,retval]*/ struct IXobj * * pVal ) = 0;
      virtual HRESULT __stdcall get_AppKeyValue (
        BSTR bstrKey,
        /*[out,retval]*/ VARIANT * pVal ) = 0;
      virtual HRESULT __stdcall put_AppKeyValue (
        BSTR bstrKey,
        /*[in]*/ VARIANT pVal ) = 0;
      virtual HRESULT __stdcall Observe (
        BSTR bstrNucleusName,
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall ObserveEx (
        BSTR bstrNucleusName,
        BSTR bstrKey,
        BSTR bstrXml,
        /*[out,retval]*/ struct IXobj * * ppXobj ) = 0;
      virtual HRESULT __stdcall InitCtrl (
        BSTR bstrXml ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_Universe =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x09,0x11}};
extern "C" const GUID __declspec(selectany) DIID__IWebRT =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x10,0x02}};
extern "C" const GUID __declspec(selectany) IID_IWebRTEventObj =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x28}};
extern "C" const GUID __declspec(selectany) CLSID_WebRT =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x99,0x06,0x06}};
extern "C" const GUID __declspec(selectany) DIID__IXobjEvents =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x10,0x01}};
extern "C" const GUID __declspec(selectany) DIID__IWebRTObjEvents =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x19,0x92}};
extern "C" const GUID __declspec(selectany) DIID__IWebRTAppEvents =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x30}};
extern "C" const GUID __declspec(selectany) CLSID_WebRTCtrl =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x07,0x10,0x01}};
extern "C" const GUID __declspec(selectany) CLSID_CosmosExtender =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x00,0x00,0x00,0x00}};
extern "C" const GUID __declspec(selectany) IID_IXobj =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x04}};
extern "C" const GUID __declspec(selectany) IID_IXobjCollection =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x17}};
extern "C" const GUID __declspec(selectany) IID_IBrowser =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x18,0x08,0x28}};
extern "C" const GUID __declspec(selectany) IID_IWebView =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x18,0x09,0x03}};
extern "C" const GUID __declspec(selectany) IID_INuclei =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x02}};
extern "C" const GUID __declspec(selectany) IID_INucleus =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x03}};
extern "C" const GUID __declspec(selectany) IID_IWebRT =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x00,0x01}};
extern "C" const GUID __declspec(selectany) IID_IWebRTCtrl =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x31,0xdc}};
extern "C" const GUID __declspec(selectany) IID_IWebRTAppCtrl =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x10,0x01}};
extern "C" const GUID __declspec(selectany) IID_IWebRTExtender =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x01,0x01}};
extern "C" const GUID __declspec(selectany) IID_IEclipseExtender =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x18}};
extern "C" const GUID __declspec(selectany) IID_IOfficeExtender =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x63,0x12,0x22}};
extern "C" const GUID __declspec(selectany) IID_IWorkBenchWindow =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x19,0x82,0x5d,0x34}};
extern "C" const GUID __declspec(selectany) IID_IEclipseCtrl =
    {0x19631222,0x1992,0x0612,{0x19,0x65,0x06,0x01,0x20,0x16,0x09,0x12}};

} // namespace Universe

#pragma pack(pop)
