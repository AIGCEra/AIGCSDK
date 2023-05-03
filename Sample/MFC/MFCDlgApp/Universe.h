

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\CommonFile\Universe.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Universe_h__
#define __Universe_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWebRTExtender_FWD_DEFINED__
#define __IWebRTExtender_FWD_DEFINED__
typedef interface IWebRTExtender IWebRTExtender;

#endif 	/* __IWebRTExtender_FWD_DEFINED__ */


#ifndef __IEclipseExtender_FWD_DEFINED__
#define __IEclipseExtender_FWD_DEFINED__
typedef interface IEclipseExtender IEclipseExtender;

#endif 	/* __IEclipseExtender_FWD_DEFINED__ */


#ifndef __IOfficeExtender_FWD_DEFINED__
#define __IOfficeExtender_FWD_DEFINED__
typedef interface IOfficeExtender IOfficeExtender;

#endif 	/* __IOfficeExtender_FWD_DEFINED__ */


#ifndef __IWebRTTreeNode_FWD_DEFINED__
#define __IWebRTTreeNode_FWD_DEFINED__
typedef interface IWebRTTreeNode IWebRTTreeNode;

#endif 	/* __IWebRTTreeNode_FWD_DEFINED__ */


#ifndef __IWebRTTreeViewCallBack_FWD_DEFINED__
#define __IWebRTTreeViewCallBack_FWD_DEFINED__
typedef interface IWebRTTreeViewCallBack IWebRTTreeViewCallBack;

#endif 	/* __IWebRTTreeViewCallBack_FWD_DEFINED__ */


#ifndef __IWebRTTreeView_FWD_DEFINED__
#define __IWebRTTreeView_FWD_DEFINED__
typedef interface IWebRTTreeView IWebRTTreeView;

#endif 	/* __IWebRTTreeView_FWD_DEFINED__ */


#ifndef __IWebRTEventObj_FWD_DEFINED__
#define __IWebRTEventObj_FWD_DEFINED__
typedef interface IWebRTEventObj IWebRTEventObj;

#endif 	/* __IWebRTEventObj_FWD_DEFINED__ */


#ifndef __IXobj_FWD_DEFINED__
#define __IXobj_FWD_DEFINED__
typedef interface IXobj IXobj;

#endif 	/* __IXobj_FWD_DEFINED__ */


#ifndef __IAppExtender_FWD_DEFINED__
#define __IAppExtender_FWD_DEFINED__
typedef interface IAppExtender IAppExtender;

#endif 	/* __IAppExtender_FWD_DEFINED__ */


#ifndef __IWebRT_FWD_DEFINED__
#define __IWebRT_FWD_DEFINED__
typedef interface IWebRT IWebRT;

#endif 	/* __IWebRT_FWD_DEFINED__ */


#ifndef __INucleus_FWD_DEFINED__
#define __INucleus_FWD_DEFINED__
typedef interface INucleus INucleus;

#endif 	/* __INucleus_FWD_DEFINED__ */


#ifndef __IXobjCollection_FWD_DEFINED__
#define __IXobjCollection_FWD_DEFINED__
typedef interface IXobjCollection IXobjCollection;

#endif 	/* __IXobjCollection_FWD_DEFINED__ */


#ifndef __INuclei_FWD_DEFINED__
#define __INuclei_FWD_DEFINED__
typedef interface INuclei INuclei;

#endif 	/* __INuclei_FWD_DEFINED__ */


#ifndef __IWorkBenchWindow_FWD_DEFINED__
#define __IWorkBenchWindow_FWD_DEFINED__
typedef interface IWorkBenchWindow IWorkBenchWindow;

#endif 	/* __IWorkBenchWindow_FWD_DEFINED__ */


#ifndef __IBrowser_FWD_DEFINED__
#define __IBrowser_FWD_DEFINED__
typedef interface IBrowser IBrowser;

#endif 	/* __IBrowser_FWD_DEFINED__ */


#ifndef __IWebPage_FWD_DEFINED__
#define __IWebPage_FWD_DEFINED__
typedef interface IWebPage IWebPage;

#endif 	/* __IWebPage_FWD_DEFINED__ */


#ifndef __IOfficeObject_FWD_DEFINED__
#define __IOfficeObject_FWD_DEFINED__
typedef interface IOfficeObject IOfficeObject;

#endif 	/* __IOfficeObject_FWD_DEFINED__ */


#ifndef __IWebRTCtrl_FWD_DEFINED__
#define __IWebRTCtrl_FWD_DEFINED__
typedef interface IWebRTCtrl IWebRTCtrl;

#endif 	/* __IWebRTCtrl_FWD_DEFINED__ */


#ifndef __IWebRTAppCtrl_FWD_DEFINED__
#define __IWebRTAppCtrl_FWD_DEFINED__
typedef interface IWebRTAppCtrl IWebRTAppCtrl;

#endif 	/* __IWebRTAppCtrl_FWD_DEFINED__ */


#ifndef __IEclipseCtrl_FWD_DEFINED__
#define __IEclipseCtrl_FWD_DEFINED__
typedef interface IEclipseCtrl IEclipseCtrl;

#endif 	/* __IEclipseCtrl_FWD_DEFINED__ */


#ifndef ___IWebRT_FWD_DEFINED__
#define ___IWebRT_FWD_DEFINED__
typedef interface _IWebRT _IWebRT;

#endif 	/* ___IWebRT_FWD_DEFINED__ */


#ifndef __Cosmos_FWD_DEFINED__
#define __Cosmos_FWD_DEFINED__

#ifdef __cplusplus
typedef class Cosmos Cosmos;
#else
typedef struct Cosmos Cosmos;
#endif /* __cplusplus */

#endif 	/* __Cosmos_FWD_DEFINED__ */


#ifndef ___IXobjEvents_FWD_DEFINED__
#define ___IXobjEvents_FWD_DEFINED__
typedef interface _IXobjEvents _IXobjEvents;

#endif 	/* ___IXobjEvents_FWD_DEFINED__ */


#ifndef ___IWebRTObjEvents_FWD_DEFINED__
#define ___IWebRTObjEvents_FWD_DEFINED__
typedef interface _IWebRTObjEvents _IWebRTObjEvents;

#endif 	/* ___IWebRTObjEvents_FWD_DEFINED__ */


#ifndef ___IWebRTAppEvents_FWD_DEFINED__
#define ___IWebRTAppEvents_FWD_DEFINED__
typedef interface _IWebRTAppEvents _IWebRTAppEvents;

#endif 	/* ___IWebRTAppEvents_FWD_DEFINED__ */


#ifndef __CosmosCtrl_FWD_DEFINED__
#define __CosmosCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CosmosCtrl CosmosCtrl;
#else
typedef struct CosmosCtrl CosmosCtrl;
#endif /* __cplusplus */

#endif 	/* __CosmosCtrl_FWD_DEFINED__ */


#ifndef __CosmosExtender_FWD_DEFINED__
#define __CosmosExtender_FWD_DEFINED__

#ifdef __cplusplus
typedef class CosmosExtender CosmosExtender;
#else
typedef struct CosmosExtender CosmosExtender;
#endif /* __cplusplus */

#endif 	/* __CosmosExtender_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Universe_0000_0000 */
/* [local] */ 












typedef /* [helpstring] */ 
enum BrowserWndOpenDisposition
    {
        UNKNOWN	= 0,
        CURRENT_TAB	= 0x1,
        SINGLETON_TAB	= 0x2,
        NEW_FOREGROUND_TAB	= 0x3,
        NEW_BACKGROUND_TAB	= 0x4,
        NEW_POPUP	= 0x5,
        NEW_WINDOW	= 0x6,
        SAVE_TO_DISK	= 0x7,
        OFF_THE_RECORD	= 0x8,
        IGNORE_ACTION	= 0x9,
        SWITCH_TO_TAB	= 0xa
    } 	BrowserWndOpenDisposition;

typedef /* [helpstring] */ 
enum GalaxyType
    {
        MDIClientGalaxy	= 0,
        MDIChildGalaxy	= 0x1,
        SDIGalaxy	= 0x2,
        CtrlBarGalaxy	= 0x3,
        WinFormMDIClientGalaxy	= 0x4,
        WinFormMDIChildGalaxy	= 0x5,
        WinFormGalaxy	= 0x6,
        EclipseWorkBenchGalaxy	= 0x7,
        EclipseViewGalaxy	= 0x8,
        EclipseSWTGalaxy	= 0x9,
        WinFormControlGalaxy	= 0xa,
        WebPageGalaxy	= 0xb,
        NOGalaxy	= 0xc
    } 	GalaxyType;

typedef /* [helpstring] */ 
enum ObjEventType
    {
        TangramNode	= 0,
        CosmosDocEvent	= 0x1,
        TangramNodeAllChildNode	= 0x2,
        CosmosDocAllGalaxyAllChildNode	= 0x3,
        CosmosDocAllGalaxyAllTopXobj	= 0x4,
        TangramGalaxyAllTopXobjAllChildNode	= 0x5,
        TangramGalaxyAllTopXobj	= 0x6,
        GalaxyClusterAllGalaxyAllTopXobjAllChildNode	= 0x7,
        GalaxyClusterAllGalaxyAllTopXobj	= 0x8,
        GalaxyClusterCtrlBarGalaxyAllTopXobjAllChildNode	= 0x9,
        GalaxyClusterCtrlBarGalaxyAllTopXobj	= 0xa,
        GalaxyClusterNotCtrlBarGalaxyAllTopXobjAllChildNode	= 0xb,
        GalaxyClusterNotCtrlBarGalaxyAllTopXobj	= 0xc,
        CosmosDocAllCtrlBarGalaxyAllChildNode	= 0xd,
        CosmosDocAllCtrlBarGalaxy	= 0xe
    } 	ObjEventType;

typedef /* [helpstring] */ 
enum XobjType
    {
        BlankView	= 0x1,
        ActiveX	= 0x2,
        Grid	= 0x4,
        TabGrid	= 0x8,
        CLRCtrl	= 0x10,
        CLRForm	= 0x20,
        CLRWnd	= 0x40,
        TangramView	= 0x80,
        TangramTreeView	= 0x100,
        TangramListView	= 0x200,
        TabCtrl	= 0x400,
        TangramWPFCtrl	= 0x800
    } 	XobjType;



extern RPC_IF_HANDLE __MIDL_itf_Universe_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Universe_0000_0000_v0_0_s_ifspec;

#ifndef __IWebRTExtender_INTERFACE_DEFINED__
#define __IWebRTExtender_INTERFACE_DEFINED__

/* interface IWebRTExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160101")
    IWebRTExtender : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveWorkBenchWindow( 
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWebRTExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            IWebRTExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        END_INTERFACE
    } IWebRTExtenderVtbl;

    interface IWebRTExtender
    {
        CONST_VTBL struct IWebRTExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRTExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IWebRTExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTExtender_INTERFACE_DEFINED__ */


#ifndef __IEclipseExtender_INTERFACE_DEFINED__
#define __IEclipseExtender_INTERFACE_DEFINED__

/* interface IEclipseExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEclipseExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160918")
    IEclipseExtender : public IWebRTExtender
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IEclipseExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEclipseExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEclipseExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEclipseExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEclipseExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEclipseExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEclipseExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEclipseExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IEclipseExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            IEclipseExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        END_INTERFACE
    } IEclipseExtenderVtbl;

    interface IEclipseExtender
    {
        CONST_VTBL struct IEclipseExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEclipseExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEclipseExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEclipseExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEclipseExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEclipseExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEclipseExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEclipseExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEclipseExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IEclipseExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEclipseExtender_INTERFACE_DEFINED__ */


#ifndef __IOfficeExtender_INTERFACE_DEFINED__
#define __IOfficeExtender_INTERFACE_DEFINED__

/* interface IOfficeExtender */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOfficeExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119631222")
    IOfficeExtender : public IWebRTExtender
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddVBAFormsScript( 
            IDispatch *OfficeObject,
            BSTR bstrKey,
            BSTR bstrXml) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitVBAForm( 
            /* [in] */ IDispatch *newVal,
            /* [in] */ long nStyle,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNucleusFromVBAForm( 
            IDispatch *pForm,
            /* [retval][out] */ INucleus **ppNucleus) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActiveTopXobj( 
            IDispatch *pForm,
            /* [retval][out] */ IXobj **WndXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetObjectFromWnd( 
            LONG hWnd,
            /* [retval][out] */ IDispatch **ppObjFromWnd) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOfficeExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfficeExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfficeExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfficeExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOfficeExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOfficeExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOfficeExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOfficeExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IOfficeExtender * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWorkBenchWindow )( 
            IOfficeExtender * This,
            BSTR bstrID,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddVBAFormsScript )( 
            IOfficeExtender * This,
            IDispatch *OfficeObject,
            BSTR bstrKey,
            BSTR bstrXml);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitVBAForm )( 
            IOfficeExtender * This,
            /* [in] */ IDispatch *newVal,
            /* [in] */ long nStyle,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNucleusFromVBAForm )( 
            IOfficeExtender * This,
            IDispatch *pForm,
            /* [retval][out] */ INucleus **ppNucleus);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActiveTopXobj )( 
            IOfficeExtender * This,
            IDispatch *pForm,
            /* [retval][out] */ IXobj **WndXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetObjectFromWnd )( 
            IOfficeExtender * This,
            LONG hWnd,
            /* [retval][out] */ IDispatch **ppObjFromWnd);
        
        END_INTERFACE
    } IOfficeExtenderVtbl;

    interface IOfficeExtender
    {
        CONST_VTBL struct IOfficeExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfficeExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfficeExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfficeExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfficeExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOfficeExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOfficeExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOfficeExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOfficeExtender_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IOfficeExtender_get_ActiveWorkBenchWindow(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_ActiveWorkBenchWindow(This,bstrID,pVal) ) 


#define IOfficeExtender_AddVBAFormsScript(This,OfficeObject,bstrKey,bstrXml)	\
    ( (This)->lpVtbl -> AddVBAFormsScript(This,OfficeObject,bstrKey,bstrXml) ) 

#define IOfficeExtender_InitVBAForm(This,newVal,nStyle,bstrXml,ppXobj)	\
    ( (This)->lpVtbl -> InitVBAForm(This,newVal,nStyle,bstrXml,ppXobj) ) 

#define IOfficeExtender_GetNucleusFromVBAForm(This,pForm,ppNucleus)	\
    ( (This)->lpVtbl -> GetNucleusFromVBAForm(This,pForm,ppNucleus) ) 

#define IOfficeExtender_GetActiveTopXobj(This,pForm,WndXobj)	\
    ( (This)->lpVtbl -> GetActiveTopXobj(This,pForm,WndXobj) ) 

#define IOfficeExtender_GetObjectFromWnd(This,hWnd,ppObjFromWnd)	\
    ( (This)->lpVtbl -> GetObjectFromWnd(This,hWnd,ppObjFromWnd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfficeExtender_INTERFACE_DEFINED__ */


#ifndef __IWebRTTreeNode_INTERFACE_DEFINED__
#define __IWebRTTreeNode_INTERFACE_DEFINED__

/* interface IWebRTTreeNode */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTTreeNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-06011982C951")
    IWebRTTreeNode : public IDispatch
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTTreeNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTTreeNode * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTTreeNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTTreeNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTTreeNode * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTTreeNode * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTTreeNode * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTTreeNode * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IWebRTTreeNodeVtbl;

    interface IWebRTTreeNode
    {
        CONST_VTBL struct IWebRTTreeNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTTreeNode_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTTreeNode_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTTreeNode_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTTreeNode_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTTreeNode_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTTreeNode_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTTreeNode_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTTreeNode_INTERFACE_DEFINED__ */


#ifndef __IWebRTTreeViewCallBack_INTERFACE_DEFINED__
#define __IWebRTTreeViewCallBack_INTERFACE_DEFINED__

/* interface IWebRTTreeViewCallBack */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTTreeViewCallBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198283A6")
    IWebRTTreeViewCallBack : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WndXobj( 
            IXobj *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pages( 
            long *retVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnInitTreeView( 
            IWebRTTreeView *pTangramTreeView,
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnClick( 
            BSTR bstrXml,
            BSTR bstrXmlData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnInit( 
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnNewPage( 
            int nNewPage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosAction( 
            BSTR bstrXml,
            /* [retval][out] */ BSTR *bstrRetXml) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTTreeViewCallBackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTTreeViewCallBack * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTTreeViewCallBack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTTreeViewCallBack * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTTreeViewCallBack * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTTreeViewCallBack * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTTreeViewCallBack * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTTreeViewCallBack * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WndXobj )( 
            IWebRTTreeViewCallBack * This,
            IXobj *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pages )( 
            IWebRTTreeViewCallBack * This,
            long *retVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnInitTreeView )( 
            IWebRTTreeViewCallBack * This,
            IWebRTTreeView *pTangramTreeView,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnClick )( 
            IWebRTTreeViewCallBack * This,
            BSTR bstrXml,
            BSTR bstrXmlData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnInit )( 
            IWebRTTreeViewCallBack * This,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OnNewPage )( 
            IWebRTTreeViewCallBack * This,
            int nNewPage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosAction )( 
            IWebRTTreeViewCallBack * This,
            BSTR bstrXml,
            /* [retval][out] */ BSTR *bstrRetXml);
        
        END_INTERFACE
    } IWebRTTreeViewCallBackVtbl;

    interface IWebRTTreeViewCallBack
    {
        CONST_VTBL struct IWebRTTreeViewCallBackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTTreeViewCallBack_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTTreeViewCallBack_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTTreeViewCallBack_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTTreeViewCallBack_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTTreeViewCallBack_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTTreeViewCallBack_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTTreeViewCallBack_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRTTreeViewCallBack_put_WndXobj(This,newVal)	\
    ( (This)->lpVtbl -> put_WndXobj(This,newVal) ) 

#define IWebRTTreeViewCallBack_get_Pages(This,retVal)	\
    ( (This)->lpVtbl -> get_Pages(This,retVal) ) 

#define IWebRTTreeViewCallBack_OnInitTreeView(This,pTangramTreeView,bstrXml)	\
    ( (This)->lpVtbl -> OnInitTreeView(This,pTangramTreeView,bstrXml) ) 

#define IWebRTTreeViewCallBack_OnClick(This,bstrXml,bstrXmlData)	\
    ( (This)->lpVtbl -> OnClick(This,bstrXml,bstrXmlData) ) 

#define IWebRTTreeViewCallBack_OnInit(This,bstrXml)	\
    ( (This)->lpVtbl -> OnInit(This,bstrXml) ) 

#define IWebRTTreeViewCallBack_OnNewPage(This,nNewPage)	\
    ( (This)->lpVtbl -> OnNewPage(This,nNewPage) ) 

#define IWebRTTreeViewCallBack_CosmosAction(This,bstrXml,bstrRetXml)	\
    ( (This)->lpVtbl -> CosmosAction(This,bstrXml,bstrRetXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTTreeViewCallBack_INTERFACE_DEFINED__ */


#ifndef __IWebRTTreeView_INTERFACE_DEFINED__
#define __IWebRTTreeView_INTERFACE_DEFINED__

/* interface IWebRTTreeView */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTTreeView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198283A5")
    IWebRTTreeView : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TangramTreeViewCallBack( 
            BSTR bstrKey,
            /* [in] */ IWebRTTreeViewCallBack *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FirstRoot( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTreeNode( 
            long hItem,
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertNode( 
            BSTR bstrXml,
            /* [retval][out] */ long *hItem) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTTreeViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTTreeView * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTTreeView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTTreeView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTTreeView * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTTreeView * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTTreeView * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTTreeView * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TangramTreeViewCallBack )( 
            IWebRTTreeView * This,
            BSTR bstrKey,
            /* [in] */ IWebRTTreeViewCallBack *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FirstRoot )( 
            IWebRTTreeView * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTreeNode )( 
            IWebRTTreeView * This,
            long hItem,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertNode )( 
            IWebRTTreeView * This,
            BSTR bstrXml,
            /* [retval][out] */ long *hItem);
        
        END_INTERFACE
    } IWebRTTreeViewVtbl;

    interface IWebRTTreeView
    {
        CONST_VTBL struct IWebRTTreeViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTTreeView_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTTreeView_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTTreeView_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTTreeView_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTTreeView_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTTreeView_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTTreeView_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRTTreeView_put_TangramTreeViewCallBack(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_TangramTreeViewCallBack(This,bstrKey,newVal) ) 

#define IWebRTTreeView_get_FirstRoot(This,pVal)	\
    ( (This)->lpVtbl -> get_FirstRoot(This,pVal) ) 

#define IWebRTTreeView_AddTreeNode(This,hItem,bstrXml)	\
    ( (This)->lpVtbl -> AddTreeNode(This,hItem,bstrXml) ) 

#define IWebRTTreeView_InsertNode(This,bstrXml,hItem)	\
    ( (This)->lpVtbl -> InsertNode(This,bstrXml,hItem) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTTreeView_INTERFACE_DEFINED__ */


#ifndef __IWebRTEventObj_INTERFACE_DEFINED__
#define __IWebRTEventObj_INTERFACE_DEFINED__

/* interface IWebRTEventObj */
/* [unique][helpstring][nonextensible][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTEventObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160928")
    IWebRTEventObj : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_eventSource( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_eventSource( 
            /* [in] */ IDispatch *eventSource) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ int *nVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Index( 
            int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EventName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EventName( 
            BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Object( 
            int nIndex,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Object( 
            int nIndex,
            IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            int nIndex,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            int nIndex,
            VARIANT newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTEventObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTEventObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTEventObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTEventObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTEventObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTEventObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTEventObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTEventObj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_eventSource )( 
            IWebRTEventObj * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_eventSource )( 
            IWebRTEventObj * This,
            /* [in] */ IDispatch *eventSource);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IWebRTEventObj * This,
            /* [retval][out] */ int *nVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Index )( 
            IWebRTEventObj * This,
            int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventName )( 
            IWebRTEventObj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventName )( 
            IWebRTEventObj * This,
            BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Object )( 
            IWebRTEventObj * This,
            int nIndex,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Object )( 
            IWebRTEventObj * This,
            int nIndex,
            IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IWebRTEventObj * This,
            int nIndex,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IWebRTEventObj * This,
            int nIndex,
            VARIANT newVal);
        
        END_INTERFACE
    } IWebRTEventObjVtbl;

    interface IWebRTEventObj
    {
        CONST_VTBL struct IWebRTEventObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTEventObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTEventObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTEventObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTEventObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTEventObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTEventObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTEventObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRTEventObj_get_eventSource(This,pVal)	\
    ( (This)->lpVtbl -> get_eventSource(This,pVal) ) 

#define IWebRTEventObj_put_eventSource(This,eventSource)	\
    ( (This)->lpVtbl -> put_eventSource(This,eventSource) ) 

#define IWebRTEventObj_get_Index(This,nVal)	\
    ( (This)->lpVtbl -> get_Index(This,nVal) ) 

#define IWebRTEventObj_put_Index(This,newVal)	\
    ( (This)->lpVtbl -> put_Index(This,newVal) ) 

#define IWebRTEventObj_get_EventName(This,pVal)	\
    ( (This)->lpVtbl -> get_EventName(This,pVal) ) 

#define IWebRTEventObj_put_EventName(This,newVal)	\
    ( (This)->lpVtbl -> put_EventName(This,newVal) ) 

#define IWebRTEventObj_get_Object(This,nIndex,pVal)	\
    ( (This)->lpVtbl -> get_Object(This,nIndex,pVal) ) 

#define IWebRTEventObj_put_Object(This,nIndex,newVal)	\
    ( (This)->lpVtbl -> put_Object(This,nIndex,newVal) ) 

#define IWebRTEventObj_get_Value(This,nIndex,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,nIndex,pVal) ) 

#define IWebRTEventObj_put_Value(This,nIndex,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,nIndex,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTEventObj_INTERFACE_DEFINED__ */


#ifndef __IXobj_INTERFACE_DEFINED__
#define __IXobj_INTERFACE_DEFINED__

/* interface IXobj */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IXobj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820004")
    IXobj : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ChildNodes( 
            /* [retval][out] */ IXobjCollection **ppXobjColletion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rows( 
            /* [retval][out] */ long *nRows) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cols( 
            /* [retval][out] */ long *nCols) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Row( 
            /* [retval][out] */ long *nRow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Col( 
            /* [retval][out] */ long *nCol) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XobjType( 
            /* [retval][out] */ XobjType *nType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentXobj( 
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_URL( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_URL( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Nuclei( 
            /* [retval][out] */ INuclei **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootXobj( 
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XObject( 
            /* [retval][out] */ VARIANT *pVar) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AxPlugIn( 
            /* [in] */ BSTR bstrPlugInName,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR bstrCaption) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Objects( 
            /* [in] */ long nType,
            /* [retval][out] */ IXobjCollection **ppXobjColletion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ LONGLONG *hWnd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attribute( 
            /* [in] */ BSTR bstrKey,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Attribute( 
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Tag( 
            /* [retval][out] */ VARIANT *pVar) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Tag( 
            /* [in] */ VARIANT vVar) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OuterXml( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Key( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WebPage( 
            /* [retval][out] */ IWebPage **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NameAtWindowPage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WinNucleus( 
            /* [retval][out] */ INucleus **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Extender( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Extender( 
            /* [in] */ IDispatch *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DocXml( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rgbMiddle( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rgbMiddle( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rgbRightBottom( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rgbRightBottom( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rgbLeftTop( 
            /* [retval][out] */ OLE_COLOR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rgbLeftTop( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Hmin( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Hmin( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Hmax( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Hmax( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Vmin( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Vmin( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Vmax( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Vmax( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostXobj( 
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_HostXobj( 
            /* [in] */ IXobj *newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActivePage( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ActivePage( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostGalaxy( 
            /* [retval][out] */ INucleus **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OfficeObj( 
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE ActiveTabPage( 
            IXobj *pXobj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXobjs( 
            /* [in] */ BSTR bstrName,
            /* [out] */ IXobj **ppXobj,
            /* [out] */ IXobjCollection **ppXobjs,
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXobj( 
            /* [in] */ long nRow,
            /* [in] */ long nCol,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlByName( 
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SendIPCMessage( 
            BSTR bstrTo,
            BSTR bstrPayload,
            BSTR bstrExtra,
            BSTR bstrMsgId,
            /* [retval][out] */ BSTR *bstrRes) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadXML( 
            int nType,
            BSTR bstrXML) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveEx( 
            int nRow,
            int nCol,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetXobjByName( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IXobjCollection **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlValueByName( 
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCtrlValueByName( 
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NavigateURL( 
            BSTR bstrURL,
            IDispatch *dispObjforScript) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetChildXobjByName( 
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetUIScript( 
            /* [in] */ BSTR bstrCtrlName,
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXobjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXobj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXobj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXobj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXobj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXobj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXobj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXobj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChildNodes )( 
            IXobj * This,
            /* [retval][out] */ IXobjCollection **ppXobjColletion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rows )( 
            IXobj * This,
            /* [retval][out] */ long *nRows);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cols )( 
            IXobj * This,
            /* [retval][out] */ long *nCols);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Row )( 
            IXobj * This,
            /* [retval][out] */ long *nRow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Col )( 
            IXobj * This,
            /* [retval][out] */ long *nCol);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XobjType )( 
            IXobj * This,
            /* [retval][out] */ XobjType *nType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentXobj )( 
            IXobj * This,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_URL )( 
            IXobj * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Nuclei )( 
            IXobj * This,
            /* [retval][out] */ INuclei **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootXobj )( 
            IXobj * This,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XObject )( 
            IXobj * This,
            /* [retval][out] */ VARIANT *pVar);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxPlugIn )( 
            IXobj * This,
            /* [in] */ BSTR bstrPlugInName,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Caption )( 
            IXobj * This,
            /* [in] */ BSTR bstrCaption);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IXobj * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Objects )( 
            IXobj * This,
            /* [in] */ long nType,
            /* [retval][out] */ IXobjCollection **ppXobjColletion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IXobj * This,
            /* [retval][out] */ LONGLONG *hWnd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attribute )( 
            IXobj * This,
            /* [in] */ BSTR bstrKey,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Attribute )( 
            IXobj * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ BSTR bstrVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tag )( 
            IXobj * This,
            /* [retval][out] */ VARIANT *pVar);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tag )( 
            IXobj * This,
            /* [in] */ VARIANT vVar);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OuterXml )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Key )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WebPage )( 
            IXobj * This,
            /* [retval][out] */ IWebPage **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NameAtWindowPage )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IXobj * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IXobj * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WinNucleus )( 
            IXobj * This,
            /* [retval][out] */ INucleus **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XML )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            IXobj * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Extender )( 
            IXobj * This,
            /* [in] */ IDispatch *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocXml )( 
            IXobj * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rgbMiddle )( 
            IXobj * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rgbMiddle )( 
            IXobj * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rgbRightBottom )( 
            IXobj * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rgbRightBottom )( 
            IXobj * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rgbLeftTop )( 
            IXobj * This,
            /* [retval][out] */ OLE_COLOR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rgbLeftTop )( 
            IXobj * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hmin )( 
            IXobj * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hmin )( 
            IXobj * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Hmax )( 
            IXobj * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Hmax )( 
            IXobj * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Vmin )( 
            IXobj * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Vmin )( 
            IXobj * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Vmax )( 
            IXobj * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Vmax )( 
            IXobj * This,
            /* [in] */ int newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostXobj )( 
            IXobj * This,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostXobj )( 
            IXobj * This,
            /* [in] */ IXobj *newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActivePage )( 
            IXobj * This,
            /* [retval][out] */ int *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActivePage )( 
            IXobj * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostGalaxy )( 
            IXobj * This,
            /* [retval][out] */ INucleus **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfficeObj )( 
            IXobj * This,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *ActiveTabPage )( 
            IXobj * This,
            IXobj *pXobj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXobjs )( 
            IXobj * This,
            /* [in] */ BSTR bstrName,
            /* [out] */ IXobj **ppXobj,
            /* [out] */ IXobjCollection **ppXobjs,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXobj )( 
            IXobj * This,
            /* [in] */ long nRow,
            /* [in] */ long nCol,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlByName )( 
            IXobj * This,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SendIPCMessage )( 
            IXobj * This,
            BSTR bstrTo,
            BSTR bstrPayload,
            BSTR bstrExtra,
            BSTR bstrMsgId,
            /* [retval][out] */ BSTR *bstrRes);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            IXobj * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadXML )( 
            IXobj * This,
            int nType,
            BSTR bstrXML);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveEx )( 
            IXobj * This,
            int nRow,
            int nCol,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetXobjByName )( 
            IXobj * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IXobjCollection **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlValueByName )( 
            IXobj * This,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCtrlValueByName )( 
            IXobj * This,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NavigateURL )( 
            IXobj * This,
            BSTR bstrURL,
            IDispatch *dispObjforScript);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetChildXobjByName )( 
            IXobj * This,
            /* [in] */ BSTR bstrName,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetUIScript )( 
            IXobj * This,
            /* [in] */ BSTR bstrCtrlName,
            /* [retval][out] */ BSTR *bstrVal);
        
        END_INTERFACE
    } IXobjVtbl;

    interface IXobj
    {
        CONST_VTBL struct IXobjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXobj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXobj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXobj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXobj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IXobj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IXobj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IXobj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IXobj_get_ChildNodes(This,ppXobjColletion)	\
    ( (This)->lpVtbl -> get_ChildNodes(This,ppXobjColletion) ) 

#define IXobj_get_Rows(This,nRows)	\
    ( (This)->lpVtbl -> get_Rows(This,nRows) ) 

#define IXobj_get_Cols(This,nCols)	\
    ( (This)->lpVtbl -> get_Cols(This,nCols) ) 

#define IXobj_get_Row(This,nRow)	\
    ( (This)->lpVtbl -> get_Row(This,nRow) ) 

#define IXobj_get_Col(This,nCol)	\
    ( (This)->lpVtbl -> get_Col(This,nCol) ) 

#define IXobj_get_XobjType(This,nType)	\
    ( (This)->lpVtbl -> get_XobjType(This,nType) ) 

#define IXobj_get_ParentXobj(This,ppXobj)	\
    ( (This)->lpVtbl -> get_ParentXobj(This,ppXobj) ) 

#define IXobj_get_URL(This,pVal)	\
    ( (This)->lpVtbl -> get_URL(This,pVal) ) 

#define IXobj_put_URL(This,newVal)	\
    ( (This)->lpVtbl -> put_URL(This,newVal) ) 

#define IXobj_get_Nuclei(This,pVal)	\
    ( (This)->lpVtbl -> get_Nuclei(This,pVal) ) 

#define IXobj_get_RootXobj(This,ppXobj)	\
    ( (This)->lpVtbl -> get_RootXobj(This,ppXobj) ) 

#define IXobj_get_XObject(This,pVar)	\
    ( (This)->lpVtbl -> get_XObject(This,pVar) ) 

#define IXobj_get_AxPlugIn(This,bstrPlugInName,pVal)	\
    ( (This)->lpVtbl -> get_AxPlugIn(This,bstrPlugInName,pVal) ) 

#define IXobj_get_Caption(This,pVal)	\
    ( (This)->lpVtbl -> get_Caption(This,pVal) ) 

#define IXobj_put_Caption(This,bstrCaption)	\
    ( (This)->lpVtbl -> put_Caption(This,bstrCaption) ) 

#define IXobj_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IXobj_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IXobj_get_Objects(This,nType,ppXobjColletion)	\
    ( (This)->lpVtbl -> get_Objects(This,nType,ppXobjColletion) ) 

#define IXobj_get_Handle(This,hWnd)	\
    ( (This)->lpVtbl -> get_Handle(This,hWnd) ) 

#define IXobj_get_Attribute(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_Attribute(This,bstrKey,pVal) ) 

#define IXobj_put_Attribute(This,bstrKey,bstrVal)	\
    ( (This)->lpVtbl -> put_Attribute(This,bstrKey,bstrVal) ) 

#define IXobj_get_Tag(This,pVar)	\
    ( (This)->lpVtbl -> get_Tag(This,pVar) ) 

#define IXobj_put_Tag(This,vVar)	\
    ( (This)->lpVtbl -> put_Tag(This,vVar) ) 

#define IXobj_get_OuterXml(This,pVal)	\
    ( (This)->lpVtbl -> get_OuterXml(This,pVal) ) 

#define IXobj_get_Key(This,pVal)	\
    ( (This)->lpVtbl -> get_Key(This,pVal) ) 

#define IXobj_get_WebPage(This,pVal)	\
    ( (This)->lpVtbl -> get_WebPage(This,pVal) ) 

#define IXobj_get_NameAtWindowPage(This,pVal)	\
    ( (This)->lpVtbl -> get_NameAtWindowPage(This,pVal) ) 

#define IXobj_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IXobj_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IXobj_get_WinNucleus(This,pVal)	\
    ( (This)->lpVtbl -> get_WinNucleus(This,pVal) ) 

#define IXobj_get_XML(This,pVal)	\
    ( (This)->lpVtbl -> get_XML(This,pVal) ) 

#define IXobj_get_Extender(This,pVal)	\
    ( (This)->lpVtbl -> get_Extender(This,pVal) ) 

#define IXobj_put_Extender(This,newVal)	\
    ( (This)->lpVtbl -> put_Extender(This,newVal) ) 

#define IXobj_get_DocXml(This,pVal)	\
    ( (This)->lpVtbl -> get_DocXml(This,pVal) ) 

#define IXobj_get_rgbMiddle(This,pVal)	\
    ( (This)->lpVtbl -> get_rgbMiddle(This,pVal) ) 

#define IXobj_put_rgbMiddle(This,newVal)	\
    ( (This)->lpVtbl -> put_rgbMiddle(This,newVal) ) 

#define IXobj_get_rgbRightBottom(This,pVal)	\
    ( (This)->lpVtbl -> get_rgbRightBottom(This,pVal) ) 

#define IXobj_put_rgbRightBottom(This,newVal)	\
    ( (This)->lpVtbl -> put_rgbRightBottom(This,newVal) ) 

#define IXobj_get_rgbLeftTop(This,pVal)	\
    ( (This)->lpVtbl -> get_rgbLeftTop(This,pVal) ) 

#define IXobj_put_rgbLeftTop(This,newVal)	\
    ( (This)->lpVtbl -> put_rgbLeftTop(This,newVal) ) 

#define IXobj_get_Hmin(This,pVal)	\
    ( (This)->lpVtbl -> get_Hmin(This,pVal) ) 

#define IXobj_put_Hmin(This,newVal)	\
    ( (This)->lpVtbl -> put_Hmin(This,newVal) ) 

#define IXobj_get_Hmax(This,pVal)	\
    ( (This)->lpVtbl -> get_Hmax(This,pVal) ) 

#define IXobj_put_Hmax(This,newVal)	\
    ( (This)->lpVtbl -> put_Hmax(This,newVal) ) 

#define IXobj_get_Vmin(This,pVal)	\
    ( (This)->lpVtbl -> get_Vmin(This,pVal) ) 

#define IXobj_put_Vmin(This,newVal)	\
    ( (This)->lpVtbl -> put_Vmin(This,newVal) ) 

#define IXobj_get_Vmax(This,pVal)	\
    ( (This)->lpVtbl -> get_Vmax(This,pVal) ) 

#define IXobj_put_Vmax(This,newVal)	\
    ( (This)->lpVtbl -> put_Vmax(This,newVal) ) 

#define IXobj_get_HostXobj(This,pVal)	\
    ( (This)->lpVtbl -> get_HostXobj(This,pVal) ) 

#define IXobj_put_HostXobj(This,newVal)	\
    ( (This)->lpVtbl -> put_HostXobj(This,newVal) ) 

#define IXobj_get_ActivePage(This,pVal)	\
    ( (This)->lpVtbl -> get_ActivePage(This,pVal) ) 

#define IXobj_put_ActivePage(This,newVal)	\
    ( (This)->lpVtbl -> put_ActivePage(This,newVal) ) 

#define IXobj_get_HostGalaxy(This,pVal)	\
    ( (This)->lpVtbl -> get_HostGalaxy(This,pVal) ) 

#define IXobj_get_OfficeObj(This,pVal)	\
    ( (This)->lpVtbl -> get_OfficeObj(This,pVal) ) 

#define IXobj_ActiveTabPage(This,pXobj)	\
    ( (This)->lpVtbl -> ActiveTabPage(This,pXobj) ) 

#define IXobj_GetXobjs(This,bstrName,ppXobj,ppXobjs,pCount)	\
    ( (This)->lpVtbl -> GetXobjs(This,bstrName,ppXobj,ppXobjs,pCount) ) 

#define IXobj_GetXobj(This,nRow,nCol,ppXobj)	\
    ( (This)->lpVtbl -> GetXobj(This,nRow,nCol,ppXobj) ) 

#define IXobj_GetCtrlByName(This,bstrName,bFindInChild,ppCtrlDisp)	\
    ( (This)->lpVtbl -> GetCtrlByName(This,bstrName,bFindInChild,ppCtrlDisp) ) 

#define IXobj_SendIPCMessage(This,bstrTo,bstrPayload,bstrExtra,bstrMsgId,bstrRes)	\
    ( (This)->lpVtbl -> SendIPCMessage(This,bstrTo,bstrPayload,bstrExtra,bstrMsgId,bstrRes) ) 

#define IXobj_Observe(This,bstrKey,bstrXml,ppRetXobj)	\
    ( (This)->lpVtbl -> Observe(This,bstrKey,bstrXml,ppRetXobj) ) 

#define IXobj_LoadXML(This,nType,bstrXML)	\
    ( (This)->lpVtbl -> LoadXML(This,nType,bstrXML) ) 

#define IXobj_ObserveEx(This,nRow,nCol,bstrKey,bstrXml,ppRetXobj)	\
    ( (This)->lpVtbl -> ObserveEx(This,nRow,nCol,bstrKey,bstrXml,ppRetXobj) ) 

#define IXobj_GetXobjByName(This,bstrName,pVal)	\
    ( (This)->lpVtbl -> GetXobjByName(This,bstrName,pVal) ) 

#define IXobj_GetCtrlValueByName(This,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> GetCtrlValueByName(This,bstrName,bFindInChild,bstrVal) ) 

#define IXobj_SetCtrlValueByName(This,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> SetCtrlValueByName(This,bstrName,bFindInChild,bstrVal) ) 

#define IXobj_NavigateURL(This,bstrURL,dispObjforScript)	\
    ( (This)->lpVtbl -> NavigateURL(This,bstrURL,dispObjforScript) ) 

#define IXobj_GetChildXobjByName(This,bstrName,pVal)	\
    ( (This)->lpVtbl -> GetChildXobjByName(This,bstrName,pVal) ) 

#define IXobj_GetUIScript(This,bstrCtrlName,bstrVal)	\
    ( (This)->lpVtbl -> GetUIScript(This,bstrCtrlName,bstrVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXobj_INTERFACE_DEFINED__ */


#ifndef __IAppExtender_INTERFACE_DEFINED__
#define __IAppExtender_INTERFACE_DEFINED__

/* interface IAppExtender */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IAppExtender;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119822007")
    IAppExtender : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProcessNotify( 
            /* [in] */ BSTR bstrXmlNotify) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAppExtenderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAppExtender * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAppExtender * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAppExtender * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAppExtender * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAppExtender * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAppExtender * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAppExtender * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProcessNotify )( 
            IAppExtender * This,
            /* [in] */ BSTR bstrXmlNotify);
        
        END_INTERFACE
    } IAppExtenderVtbl;

    interface IAppExtender
    {
        CONST_VTBL struct IAppExtenderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAppExtender_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAppExtender_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAppExtender_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAppExtender_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAppExtender_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAppExtender_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAppExtender_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAppExtender_ProcessNotify(This,bstrXmlNotify)	\
    ( (This)->lpVtbl -> ProcessNotify(This,bstrXmlNotify) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAppExtender_INTERFACE_DEFINED__ */


#ifndef __IWebRT_INTERFACE_DEFINED__
#define __IWebRT_INTERFACE_DEFINED__

/* interface IWebRT */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820001")
    IWebRT : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostChromeBrowserWnd( 
            /* [retval][out] */ IBrowser **ppChromeWebBrowser) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppKeyValue( 
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AppKeyValue( 
            BSTR bstrKey,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteHelperHWND( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoteHelperHWND( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootNodes( 
            /* [retval][out] */ IXobjCollection **ppXobjColletion) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Extender( 
            /* [retval][out] */ IWebRTExtender **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Extender( 
            /* [in] */ IWebRTExtender *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentActiveXobj( 
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreatingXobj( 
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteCosmos( 
            BSTR bstrID,
            /* [retval][out] */ IWebRT **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NavigateNode( 
            IXobj *pXobj,
            BSTR bstrBrowserID,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateNucleusGroup( 
            LONGLONG hWnd,
            /* [retval][out] */ INuclei **ppNucleusCluster) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateOfficeDocument( 
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateCLRObj( 
            BSTR bstrObjID,
            /* [retval][out] */ IDispatch **ppDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateApplication( 
            BSTR bstrAppID,
            BSTR bstrXml) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNucleus( 
            LONGLONG hHostWnd,
            /* [retval][out] */ INucleus **ppNucleus) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItemText( 
            IXobj *pXobj,
            long nCtrlID,
            LONG nMaxLengeh,
            /* [retval][out] */ BSTR *bstrRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItemText( 
            IXobj *pXobj,
            long nCtrlID,
            BSTR bstrText) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FireCosmosEventObj( 
            IWebRTEventObj *pWebRTEventObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MessageBox( 
            LONGLONG hWnd,
            BSTR bstrContext,
            BSTR bstrCaption,
            long nStyle,
            /* [retval][out] */ int *nRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeletePage( 
            LONGLONG PageHandle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetHostFocus( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UpdateXobj( 
            IXobj *pXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateCosmosEventObj( 
            /* [retval][out] */ IWebRTEventObj **ppWebRTEventObj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitEclipseApp( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateOutLookObj( 
            BSTR bstrObjType,
            int nType,
            BSTR bstrURL,
            /* [retval][out] */ IDispatch **ppRetDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveNuclei( 
            LONGLONG hWnd,
            BSTR bstrGalaxys,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlByName( 
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetXobjFromHandle( 
            LONGLONG hWnd,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlValueByName( 
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCtrlValueByName( 
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CreateCosmosCtrl( 
            BSTR bstrAppID,
            /* [retval][out] */ IWebRTCtrl **ppRetCtrl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitCLRApp( 
            BSTR strInitXml,
            /* [retval][out] */ LONGLONG *llHandle) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteGalaxy( 
            INucleus *pGalaxy) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetWindowClientDefaultNode( 
            IDispatch *pAddDisp,
            LONGLONG hParent,
            BSTR bstrWndClaName,
            BSTR bstrGalaxyClusterName,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateBrowser( 
            ULONGLONG hParentWnd,
            BSTR strUrls,
            /* [retval][out] */ IBrowser **ppRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NewWorkBench( 
            BSTR bstrCosmosDoc,
            /* [retval][out] */ IWorkBenchWindow **ppWorkBenchWindow) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateCLRObjRemote( 
            BSTR bstrObjID,
            BSTR bstrXmlData,
            LONGLONG hWnd,
            /* [retval][out] */ IDispatch **ppDisp) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DestroyCtrl( 
            LONGLONG hWnd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRemoteHostViewRect( 
            LONGLONG hHostWnd,
            /* [retval][out] */ BSTR *strData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosCommand( 
            IDispatch *RibbonControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosGetImage( 
            BSTR strValue,
            /* [retval][out] */ IPictureDisp **ppdispImage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosGetVisible( 
            IDispatch *RibbonControl,
            /* [retval][out] */ VARIANT *varVisible) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosOnLoad( 
            IDispatch *RibbonControl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosGetItemCount( 
            IDispatch *RibbonControl,
            /* [retval][out] */ long *nCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosGetItemLabel( 
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrLabel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CosmosGetItemID( 
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRT * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRT * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRT * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRT * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRT * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostChromeBrowserWnd )( 
            IWebRT * This,
            /* [retval][out] */ IBrowser **ppChromeWebBrowser);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AppKeyValue )( 
            IWebRT * This,
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppKeyValue )( 
            IWebRT * This,
            BSTR bstrKey,
            /* [in] */ VARIANT newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteHelperHWND )( 
            IWebRT * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteHelperHWND )( 
            IWebRT * This,
            /* [in] */ LONGLONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootNodes )( 
            IWebRT * This,
            /* [retval][out] */ IXobjCollection **ppXobjColletion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            IWebRT * This,
            /* [retval][out] */ IWebRTExtender **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Extender )( 
            IWebRT * This,
            /* [in] */ IWebRTExtender *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentActiveXobj )( 
            IWebRT * This,
            /* [retval][out] */ IXobj **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreatingXobj )( 
            IWebRT * This,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteCosmos )( 
            IWebRT * This,
            BSTR bstrID,
            /* [retval][out] */ IWebRT **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NavigateNode )( 
            IWebRT * This,
            IXobj *pXobj,
            BSTR bstrBrowserID,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateNucleusGroup )( 
            IWebRT * This,
            LONGLONG hWnd,
            /* [retval][out] */ INuclei **ppNucleusCluster);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateOfficeDocument )( 
            IWebRT * This,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateCLRObj )( 
            IWebRT * This,
            BSTR bstrObjID,
            /* [retval][out] */ IDispatch **ppDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateApplication )( 
            IWebRT * This,
            BSTR bstrAppID,
            BSTR bstrXml);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNucleus )( 
            IWebRT * This,
            LONGLONG hHostWnd,
            /* [retval][out] */ INucleus **ppNucleus);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItemText )( 
            IWebRT * This,
            IXobj *pXobj,
            long nCtrlID,
            LONG nMaxLengeh,
            /* [retval][out] */ BSTR *bstrRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItemText )( 
            IWebRT * This,
            IXobj *pXobj,
            long nCtrlID,
            BSTR bstrText);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FireCosmosEventObj )( 
            IWebRT * This,
            IWebRTEventObj *pWebRTEventObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MessageBox )( 
            IWebRT * This,
            LONGLONG hWnd,
            BSTR bstrContext,
            BSTR bstrCaption,
            long nStyle,
            /* [retval][out] */ int *nRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeletePage )( 
            IWebRT * This,
            LONGLONG PageHandle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetHostFocus )( 
            IWebRT * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UpdateXobj )( 
            IWebRT * This,
            IXobj *pXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateCosmosEventObj )( 
            IWebRT * This,
            /* [retval][out] */ IWebRTEventObj **ppWebRTEventObj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitEclipseApp )( 
            IWebRT * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateOutLookObj )( 
            IWebRT * This,
            BSTR bstrObjType,
            int nType,
            BSTR bstrURL,
            /* [retval][out] */ IDispatch **ppRetDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveNuclei )( 
            IWebRT * This,
            LONGLONG hWnd,
            BSTR bstrGalaxys,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlByName )( 
            IWebRT * This,
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ IDispatch **ppCtrlDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetXobjFromHandle )( 
            IWebRT * This,
            LONGLONG hWnd,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlValueByName )( 
            IWebRT * This,
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            /* [retval][out] */ BSTR *bstrVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCtrlValueByName )( 
            IWebRT * This,
            IDispatch *pCtrl,
            BSTR bstrName,
            VARIANT_BOOL bFindInChild,
            BSTR bstrVal);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CreateCosmosCtrl )( 
            IWebRT * This,
            BSTR bstrAppID,
            /* [retval][out] */ IWebRTCtrl **ppRetCtrl);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitCLRApp )( 
            IWebRT * This,
            BSTR strInitXml,
            /* [retval][out] */ LONGLONG *llHandle);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteGalaxy )( 
            IWebRT * This,
            INucleus *pGalaxy);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetWindowClientDefaultNode )( 
            IWebRT * This,
            IDispatch *pAddDisp,
            LONGLONG hParent,
            BSTR bstrWndClaName,
            BSTR bstrGalaxyClusterName,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateBrowser )( 
            IWebRT * This,
            ULONGLONG hParentWnd,
            BSTR strUrls,
            /* [retval][out] */ IBrowser **ppRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NewWorkBench )( 
            IWebRT * This,
            BSTR bstrCosmosDoc,
            /* [retval][out] */ IWorkBenchWindow **ppWorkBenchWindow);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateCLRObjRemote )( 
            IWebRT * This,
            BSTR bstrObjID,
            BSTR bstrXmlData,
            LONGLONG hWnd,
            /* [retval][out] */ IDispatch **ppDisp);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DestroyCtrl )( 
            IWebRT * This,
            LONGLONG hWnd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteHostViewRect )( 
            IWebRT * This,
            LONGLONG hHostWnd,
            /* [retval][out] */ BSTR *strData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosCommand )( 
            IWebRT * This,
            IDispatch *RibbonControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosGetImage )( 
            IWebRT * This,
            BSTR strValue,
            /* [retval][out] */ IPictureDisp **ppdispImage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosGetVisible )( 
            IWebRT * This,
            IDispatch *RibbonControl,
            /* [retval][out] */ VARIANT *varVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosOnLoad )( 
            IWebRT * This,
            IDispatch *RibbonControl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosGetItemCount )( 
            IWebRT * This,
            IDispatch *RibbonControl,
            /* [retval][out] */ long *nCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosGetItemLabel )( 
            IWebRT * This,
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrLabel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CosmosGetItemID )( 
            IWebRT * This,
            IDispatch *RibbonControl,
            long nIndex,
            /* [retval][out] */ BSTR *bstrID);
        
        END_INTERFACE
    } IWebRTVtbl;

    interface IWebRT
    {
        CONST_VTBL struct IWebRTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRT_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRT_get_HostChromeBrowserWnd(This,ppChromeWebBrowser)	\
    ( (This)->lpVtbl -> get_HostChromeBrowserWnd(This,ppChromeWebBrowser) ) 

#define IWebRT_get_AppKeyValue(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_AppKeyValue(This,bstrKey,pVal) ) 

#define IWebRT_put_AppKeyValue(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_AppKeyValue(This,bstrKey,newVal) ) 

#define IWebRT_get_RemoteHelperHWND(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoteHelperHWND(This,pVal) ) 

#define IWebRT_put_RemoteHelperHWND(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoteHelperHWND(This,newVal) ) 

#define IWebRT_get_RootNodes(This,ppXobjColletion)	\
    ( (This)->lpVtbl -> get_RootNodes(This,ppXobjColletion) ) 

#define IWebRT_get_Extender(This,pVal)	\
    ( (This)->lpVtbl -> get_Extender(This,pVal) ) 

#define IWebRT_put_Extender(This,newVal)	\
    ( (This)->lpVtbl -> put_Extender(This,newVal) ) 

#define IWebRT_get_CurrentActiveXobj(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentActiveXobj(This,pVal) ) 

#define IWebRT_get_CreatingXobj(This,pVal)	\
    ( (This)->lpVtbl -> get_CreatingXobj(This,pVal) ) 

#define IWebRT_get_RemoteCosmos(This,bstrID,pVal)	\
    ( (This)->lpVtbl -> get_RemoteCosmos(This,bstrID,pVal) ) 

#define IWebRT_NavigateNode(This,pXobj,bstrBrowserID,bstrXml,pVal)	\
    ( (This)->lpVtbl -> NavigateNode(This,pXobj,bstrBrowserID,bstrXml,pVal) ) 

#define IWebRT_CreateNucleusGroup(This,hWnd,ppNucleusCluster)	\
    ( (This)->lpVtbl -> CreateNucleusGroup(This,hWnd,ppNucleusCluster) ) 

#define IWebRT_CreateOfficeDocument(This,bstrXml)	\
    ( (This)->lpVtbl -> CreateOfficeDocument(This,bstrXml) ) 

#define IWebRT_CreateCLRObj(This,bstrObjID,ppDisp)	\
    ( (This)->lpVtbl -> CreateCLRObj(This,bstrObjID,ppDisp) ) 

#define IWebRT_CreateApplication(This,bstrAppID,bstrXml)	\
    ( (This)->lpVtbl -> CreateApplication(This,bstrAppID,bstrXml) ) 

#define IWebRT_GetNucleus(This,hHostWnd,ppNucleus)	\
    ( (This)->lpVtbl -> GetNucleus(This,hHostWnd,ppNucleus) ) 

#define IWebRT_GetItemText(This,pXobj,nCtrlID,nMaxLengeh,bstrRet)	\
    ( (This)->lpVtbl -> GetItemText(This,pXobj,nCtrlID,nMaxLengeh,bstrRet) ) 

#define IWebRT_SetItemText(This,pXobj,nCtrlID,bstrText)	\
    ( (This)->lpVtbl -> SetItemText(This,pXobj,nCtrlID,bstrText) ) 

#define IWebRT_FireCosmosEventObj(This,pWebRTEventObj)	\
    ( (This)->lpVtbl -> FireCosmosEventObj(This,pWebRTEventObj) ) 

#define IWebRT_MessageBox(This,hWnd,bstrContext,bstrCaption,nStyle,nRet)	\
    ( (This)->lpVtbl -> MessageBox(This,hWnd,bstrContext,bstrCaption,nStyle,nRet) ) 

#define IWebRT_DeletePage(This,PageHandle)	\
    ( (This)->lpVtbl -> DeletePage(This,PageHandle) ) 

#define IWebRT_SetHostFocus(This)	\
    ( (This)->lpVtbl -> SetHostFocus(This) ) 

#define IWebRT_UpdateXobj(This,pXobj)	\
    ( (This)->lpVtbl -> UpdateXobj(This,pXobj) ) 

#define IWebRT_CreateCosmosEventObj(This,ppWebRTEventObj)	\
    ( (This)->lpVtbl -> CreateCosmosEventObj(This,ppWebRTEventObj) ) 

#define IWebRT_InitEclipseApp(This)	\
    ( (This)->lpVtbl -> InitEclipseApp(This) ) 

#define IWebRT_CreateOutLookObj(This,bstrObjType,nType,bstrURL,ppRetDisp)	\
    ( (This)->lpVtbl -> CreateOutLookObj(This,bstrObjType,nType,bstrURL,ppRetDisp) ) 

#define IWebRT_ObserveNuclei(This,hWnd,bstrGalaxys,bstrKey,bstrXml,bSaveToConfigFile)	\
    ( (This)->lpVtbl -> ObserveNuclei(This,hWnd,bstrGalaxys,bstrKey,bstrXml,bSaveToConfigFile) ) 

#define IWebRT_GetCtrlByName(This,pCtrl,bstrName,bFindInChild,ppCtrlDisp)	\
    ( (This)->lpVtbl -> GetCtrlByName(This,pCtrl,bstrName,bFindInChild,ppCtrlDisp) ) 

#define IWebRT_GetXobjFromHandle(This,hWnd,ppRetXobj)	\
    ( (This)->lpVtbl -> GetXobjFromHandle(This,hWnd,ppRetXobj) ) 

#define IWebRT_GetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> GetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal) ) 

#define IWebRT_SetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal)	\
    ( (This)->lpVtbl -> SetCtrlValueByName(This,pCtrl,bstrName,bFindInChild,bstrVal) ) 

#define IWebRT_CreateCosmosCtrl(This,bstrAppID,ppRetCtrl)	\
    ( (This)->lpVtbl -> CreateCosmosCtrl(This,bstrAppID,ppRetCtrl) ) 

#define IWebRT_InitCLRApp(This,strInitXml,llHandle)	\
    ( (This)->lpVtbl -> InitCLRApp(This,strInitXml,llHandle) ) 

#define IWebRT_DeleteGalaxy(This,pGalaxy)	\
    ( (This)->lpVtbl -> DeleteGalaxy(This,pGalaxy) ) 

#define IWebRT_GetWindowClientDefaultNode(This,pAddDisp,hParent,bstrWndClaName,bstrGalaxyClusterName,ppXobj)	\
    ( (This)->lpVtbl -> GetWindowClientDefaultNode(This,pAddDisp,hParent,bstrWndClaName,bstrGalaxyClusterName,ppXobj) ) 

#define IWebRT_CreateBrowser(This,hParentWnd,strUrls,ppRet)	\
    ( (This)->lpVtbl -> CreateBrowser(This,hParentWnd,strUrls,ppRet) ) 

#define IWebRT_NewWorkBench(This,bstrCosmosDoc,ppWorkBenchWindow)	\
    ( (This)->lpVtbl -> NewWorkBench(This,bstrCosmosDoc,ppWorkBenchWindow) ) 

#define IWebRT_CreateCLRObjRemote(This,bstrObjID,bstrXmlData,hWnd,ppDisp)	\
    ( (This)->lpVtbl -> CreateCLRObjRemote(This,bstrObjID,bstrXmlData,hWnd,ppDisp) ) 

#define IWebRT_DestroyCtrl(This,hWnd)	\
    ( (This)->lpVtbl -> DestroyCtrl(This,hWnd) ) 

#define IWebRT_GetRemoteHostViewRect(This,hHostWnd,strData)	\
    ( (This)->lpVtbl -> GetRemoteHostViewRect(This,hHostWnd,strData) ) 

#define IWebRT_CosmosCommand(This,RibbonControl)	\
    ( (This)->lpVtbl -> CosmosCommand(This,RibbonControl) ) 

#define IWebRT_CosmosGetImage(This,strValue,ppdispImage)	\
    ( (This)->lpVtbl -> CosmosGetImage(This,strValue,ppdispImage) ) 

#define IWebRT_CosmosGetVisible(This,RibbonControl,varVisible)	\
    ( (This)->lpVtbl -> CosmosGetVisible(This,RibbonControl,varVisible) ) 

#define IWebRT_CosmosOnLoad(This,RibbonControl)	\
    ( (This)->lpVtbl -> CosmosOnLoad(This,RibbonControl) ) 

#define IWebRT_CosmosGetItemCount(This,RibbonControl,nCount)	\
    ( (This)->lpVtbl -> CosmosGetItemCount(This,RibbonControl,nCount) ) 

#define IWebRT_CosmosGetItemLabel(This,RibbonControl,nIndex,bstrLabel)	\
    ( (This)->lpVtbl -> CosmosGetItemLabel(This,RibbonControl,nIndex,bstrLabel) ) 

#define IWebRT_CosmosGetItemID(This,RibbonControl,nIndex,bstrID)	\
    ( (This)->lpVtbl -> CosmosGetItemID(This,RibbonControl,nIndex,bstrID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRT_INTERFACE_DEFINED__ */


#ifndef __INucleus_INTERFACE_DEFINED__
#define __INucleus_INTERFACE_DEFINED__

/* interface INucleus */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INucleus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820003")
    INucleus : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Xobj( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VisibleXobj( 
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentNavigateKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Nuclei( 
            /* [retval][out] */ INuclei **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostWebPage( 
            /* [retval][out] */ IWebPage **ppChromeWebPage) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostBrowser( 
            /* [retval][out] */ IBrowser **ppChromeWebBrowser) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RootXobjs( 
            /* [retval][out] */ IXobjCollection **ppXobjColletion) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_GalaxyXML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_GalaxyType( 
            /* [retval][out] */ GalaxyType *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Detach( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ModifyHost( 
            LONGLONG hHostWnd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetXml( 
            BSTR bstrRootName,
            /* [retval][out] */ BSTR *bstrRet) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INucleusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INucleus * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INucleus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INucleus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INucleus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INucleus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INucleus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INucleus * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Xobj )( 
            INucleus * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INucleus * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            INucleus * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VisibleXobj )( 
            INucleus * This,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentNavigateKey )( 
            INucleus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Nuclei )( 
            INucleus * This,
            /* [retval][out] */ INuclei **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostWebPage )( 
            INucleus * This,
            /* [retval][out] */ IWebPage **ppChromeWebPage);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostBrowser )( 
            INucleus * This,
            /* [retval][out] */ IBrowser **ppChromeWebBrowser);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INucleus * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RootXobjs )( 
            INucleus * This,
            /* [retval][out] */ IXobjCollection **ppXobjColletion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GalaxyXML )( 
            INucleus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GalaxyType )( 
            INucleus * This,
            /* [retval][out] */ GalaxyType *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            INucleus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Detach )( 
            INucleus * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            INucleus * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ModifyHost )( 
            INucleus * This,
            LONGLONG hHostWnd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            INucleus * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetXml )( 
            INucleus * This,
            BSTR bstrRootName,
            /* [retval][out] */ BSTR *bstrRet);
        
        END_INTERFACE
    } INucleusVtbl;

    interface INucleus
    {
        CONST_VTBL struct INucleusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INucleus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INucleus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INucleus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INucleus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INucleus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INucleus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INucleus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INucleus_get_Xobj(This,vIndex,ppXobj)	\
    ( (This)->lpVtbl -> get_Xobj(This,vIndex,ppXobj) ) 

#define INucleus_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define INucleus_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define INucleus_get_VisibleXobj(This,pVal)	\
    ( (This)->lpVtbl -> get_VisibleXobj(This,pVal) ) 

#define INucleus_get_CurrentNavigateKey(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentNavigateKey(This,pVal) ) 

#define INucleus_get_Nuclei(This,pVal)	\
    ( (This)->lpVtbl -> get_Nuclei(This,pVal) ) 

#define INucleus_get_HostWebPage(This,ppChromeWebPage)	\
    ( (This)->lpVtbl -> get_HostWebPage(This,ppChromeWebPage) ) 

#define INucleus_get_HostBrowser(This,ppChromeWebBrowser)	\
    ( (This)->lpVtbl -> get_HostBrowser(This,ppChromeWebBrowser) ) 

#define INucleus_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define INucleus_get_RootXobjs(This,ppXobjColletion)	\
    ( (This)->lpVtbl -> get_RootXobjs(This,ppXobjColletion) ) 

#define INucleus_get_GalaxyXML(This,pVal)	\
    ( (This)->lpVtbl -> get_GalaxyXML(This,pVal) ) 

#define INucleus_get_GalaxyType(This,pVal)	\
    ( (This)->lpVtbl -> get_GalaxyType(This,pVal) ) 

#define INucleus_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define INucleus_Detach(This)	\
    ( (This)->lpVtbl -> Detach(This) ) 

#define INucleus_Attach(This)	\
    ( (This)->lpVtbl -> Attach(This) ) 

#define INucleus_ModifyHost(This,hHostWnd)	\
    ( (This)->lpVtbl -> ModifyHost(This,hHostWnd) ) 

#define INucleus_Observe(This,bstrKey,bstrXml,ppRetXobj)	\
    ( (This)->lpVtbl -> Observe(This,bstrKey,bstrXml,ppRetXobj) ) 

#define INucleus_GetXml(This,bstrRootName,bstrRet)	\
    ( (This)->lpVtbl -> GetXml(This,bstrRootName,bstrRet) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INucleus_INTERFACE_DEFINED__ */


#ifndef __IXobjCollection_INTERFACE_DEFINED__
#define __IXobjCollection_INTERFACE_DEFINED__

/* interface IXobjCollection */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXobjCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820017")
    IXobjCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_XobjCount( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long iIndex,
            /* [retval][out] */ IXobj **ppTopWindow) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IXobjCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXobjCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXobjCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXobjCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXobjCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXobjCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXobjCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXobjCollection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XobjCount )( 
            IXobjCollection * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IXobjCollection * This,
            /* [in] */ long iIndex,
            /* [retval][out] */ IXobj **ppTopWindow);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IXobjCollection * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        END_INTERFACE
    } IXobjCollectionVtbl;

    interface IXobjCollection
    {
        CONST_VTBL struct IXobjCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXobjCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IXobjCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IXobjCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IXobjCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IXobjCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IXobjCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IXobjCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IXobjCollection_get_XobjCount(This,pCount)	\
    ( (This)->lpVtbl -> get_XobjCount(This,pCount) ) 

#define IXobjCollection_get_Item(This,iIndex,ppTopWindow)	\
    ( (This)->lpVtbl -> get_Item(This,iIndex,ppTopWindow) ) 

#define IXobjCollection_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IXobjCollection_INTERFACE_DEFINED__ */


#ifndef __INuclei_INTERFACE_DEFINED__
#define __INuclei_INTERFACE_DEFINED__

/* interface INuclei */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INuclei;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119820002")
    INuclei : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WinNucleus( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ INucleus **ppNucleus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NucleiXML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ INuclei **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Xobj( 
            BSTR bstrNodeName,
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_XObject( 
            BSTR bstrName,
            /* [retval][out] */ IDispatch **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NucleusName( 
            LONGLONG hHwnd,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_XobjNames( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateNucleus( 
            VARIANT ParentObj,
            VARIANT HostWnd,
            BSTR bstrNucleusName,
            /* [retval][out] */ INucleus **pRetGalaxy) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            IDispatch *Parent,
            BSTR CtrlName,
            BSTR NucleusName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveCtrl( 
            VARIANT Ctrl,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetXobj( 
            BSTR bstrNucleusName,
            BSTR bstrNodeName,
            /* [retval][out] */ IXobj **pRetNode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCtrlInXobj( 
            BSTR NodeName,
            BSTR CtrlName,
            /* [retval][out] */ IDispatch **ppCtrl) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNucleusFromCtrl( 
            IDispatch *ctrl,
            /* [retval][out] */ INucleus **ppNucleus) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveNuclei( 
            BSTR bstrGalaxys,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INucleiVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INuclei * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INuclei * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INuclei * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INuclei * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INuclei * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INuclei * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INuclei * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WinNucleus )( 
            INuclei * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ INucleus **ppNucleus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            INuclei * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            INuclei * This,
            /* [retval][out] */ long *pCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NucleiXML )( 
            INuclei * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            INuclei * This,
            /* [retval][out] */ INuclei **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Xobj )( 
            INuclei * This,
            BSTR bstrNodeName,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XObject )( 
            INuclei * This,
            BSTR bstrName,
            /* [retval][out] */ IDispatch **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NucleusName )( 
            INuclei * This,
            LONGLONG hHwnd,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            INuclei * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            INuclei * This,
            /* [retval][out] */ long *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            INuclei * This,
            /* [in] */ long newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            INuclei * This,
            /* [retval][out] */ long *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            INuclei * This,
            /* [in] */ long newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XobjNames )( 
            INuclei * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateNucleus )( 
            INuclei * This,
            VARIANT ParentObj,
            VARIANT HostWnd,
            BSTR bstrNucleusName,
            /* [retval][out] */ INucleus **pRetGalaxy);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            INuclei * This,
            IDispatch *Parent,
            BSTR CtrlName,
            BSTR NucleusName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveCtrl )( 
            INuclei * This,
            VARIANT Ctrl,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetXobj )( 
            INuclei * This,
            BSTR bstrNucleusName,
            BSTR bstrNodeName,
            /* [retval][out] */ IXobj **pRetNode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCtrlInXobj )( 
            INuclei * This,
            BSTR NodeName,
            BSTR CtrlName,
            /* [retval][out] */ IDispatch **ppCtrl);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNucleusFromCtrl )( 
            INuclei * This,
            IDispatch *ctrl,
            /* [retval][out] */ INucleus **ppNucleus);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveNuclei )( 
            INuclei * This,
            BSTR bstrGalaxys,
            BSTR bstrKey,
            BSTR bstrXml,
            VARIANT_BOOL bSaveToConfigFile);
        
        END_INTERFACE
    } INucleiVtbl;

    interface INuclei
    {
        CONST_VTBL struct INucleiVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INuclei_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INuclei_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INuclei_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INuclei_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INuclei_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INuclei_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INuclei_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INuclei_get_WinNucleus(This,vIndex,ppNucleus)	\
    ( (This)->lpVtbl -> get_WinNucleus(This,vIndex,ppNucleus) ) 

#define INuclei_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define INuclei_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define INuclei_get_NucleiXML(This,pVal)	\
    ( (This)->lpVtbl -> get_NucleiXML(This,pVal) ) 

#define INuclei_get_Parent(This,pVal)	\
    ( (This)->lpVtbl -> get_Parent(This,pVal) ) 

#define INuclei_get_Xobj(This,bstrNodeName,pVal)	\
    ( (This)->lpVtbl -> get_Xobj(This,bstrNodeName,pVal) ) 

#define INuclei_get_XObject(This,bstrName,pVal)	\
    ( (This)->lpVtbl -> get_XObject(This,bstrName,pVal) ) 

#define INuclei_get_NucleusName(This,hHwnd,pVal)	\
    ( (This)->lpVtbl -> get_NucleusName(This,hHwnd,pVal) ) 

#define INuclei_get_Handle(This,pVal)	\
    ( (This)->lpVtbl -> get_Handle(This,pVal) ) 

#define INuclei_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define INuclei_put_Width(This,newVal)	\
    ( (This)->lpVtbl -> put_Width(This,newVal) ) 

#define INuclei_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define INuclei_put_Height(This,newVal)	\
    ( (This)->lpVtbl -> put_Height(This,newVal) ) 

#define INuclei_get_XobjNames(This,pVal)	\
    ( (This)->lpVtbl -> get_XobjNames(This,pVal) ) 

#define INuclei_CreateNucleus(This,ParentObj,HostWnd,bstrNucleusName,pRetGalaxy)	\
    ( (This)->lpVtbl -> CreateNucleus(This,ParentObj,HostWnd,bstrNucleusName,pRetGalaxy) ) 

#define INuclei_Observe(This,Parent,CtrlName,NucleusName,bstrKey,bstrXml,ppRetXobj)	\
    ( (This)->lpVtbl -> Observe(This,Parent,CtrlName,NucleusName,bstrKey,bstrXml,ppRetXobj) ) 

#define INuclei_ObserveCtrl(This,Ctrl,bstrKey,bstrXml,ppRetXobj)	\
    ( (This)->lpVtbl -> ObserveCtrl(This,Ctrl,bstrKey,bstrXml,ppRetXobj) ) 

#define INuclei_GetXobj(This,bstrNucleusName,bstrNodeName,pRetNode)	\
    ( (This)->lpVtbl -> GetXobj(This,bstrNucleusName,bstrNodeName,pRetNode) ) 

#define INuclei_GetCtrlInXobj(This,NodeName,CtrlName,ppCtrl)	\
    ( (This)->lpVtbl -> GetCtrlInXobj(This,NodeName,CtrlName,ppCtrl) ) 

#define INuclei_GetNucleusFromCtrl(This,ctrl,ppNucleus)	\
    ( (This)->lpVtbl -> GetNucleusFromCtrl(This,ctrl,ppNucleus) ) 

#define INuclei_ObserveNuclei(This,bstrGalaxys,bstrKey,bstrXml,bSaveToConfigFile)	\
    ( (This)->lpVtbl -> ObserveNuclei(This,bstrGalaxys,bstrKey,bstrXml,bSaveToConfigFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INuclei_INTERFACE_DEFINED__ */


#ifndef __IWorkBenchWindow_INTERFACE_DEFINED__
#define __IWorkBenchWindow_INTERFACE_DEFINED__

/* interface IWorkBenchWindow */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWorkBenchWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119825D34")
    IWorkBenchWindow : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Ctrl( 
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IEclipseCtrl **ppCtrl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Handle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CosmosCtrl( 
            LONGLONG hWnd,
            /* [retval][out] */ IEclipseCtrl **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Nuclei( 
            /* [retval][out] */ INuclei **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_WinNucleus( 
            /* [retval][out] */ INucleus **pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Active( void) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CloseTangramUI( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveEx( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveinView( 
            int nIndex,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWorkBenchWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWorkBenchWindow * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWorkBenchWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWorkBenchWindow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWorkBenchWindow * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWorkBenchWindow * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWorkBenchWindow * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWorkBenchWindow * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Ctrl )( 
            IWorkBenchWindow * This,
            /* [in] */ VARIANT vIndex,
            /* [retval][out] */ IEclipseCtrl **ppCtrl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ IUnknown **ppVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ long *pCount);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CosmosCtrl )( 
            IWorkBenchWindow * This,
            LONGLONG hWnd,
            /* [retval][out] */ IEclipseCtrl **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Nuclei )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ INuclei **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WinNucleus )( 
            IWorkBenchWindow * This,
            /* [retval][out] */ INucleus **pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Active )( 
            IWorkBenchWindow * This);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CloseTangramUI )( 
            IWorkBenchWindow * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            IWorkBenchWindow * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveEx )( 
            IWorkBenchWindow * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveinView )( 
            IWorkBenchWindow * This,
            int nIndex,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppRetXobj);
        
        END_INTERFACE
    } IWorkBenchWindowVtbl;

    interface IWorkBenchWindow
    {
        CONST_VTBL struct IWorkBenchWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWorkBenchWindow_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWorkBenchWindow_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWorkBenchWindow_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWorkBenchWindow_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWorkBenchWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWorkBenchWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWorkBenchWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWorkBenchWindow_get_Ctrl(This,vIndex,ppCtrl)	\
    ( (This)->lpVtbl -> get_Ctrl(This,vIndex,ppCtrl) ) 

#define IWorkBenchWindow_get__NewEnum(This,ppVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,ppVal) ) 

#define IWorkBenchWindow_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IWorkBenchWindow_get_Handle(This,pVal)	\
    ( (This)->lpVtbl -> get_Handle(This,pVal) ) 

#define IWorkBenchWindow_get_CosmosCtrl(This,hWnd,pVal)	\
    ( (This)->lpVtbl -> get_CosmosCtrl(This,hWnd,pVal) ) 

#define IWorkBenchWindow_get_Nuclei(This,pVal)	\
    ( (This)->lpVtbl -> get_Nuclei(This,pVal) ) 

#define IWorkBenchWindow_get_WinNucleus(This,pVal)	\
    ( (This)->lpVtbl -> get_WinNucleus(This,pVal) ) 

#define IWorkBenchWindow_Active(This)	\
    ( (This)->lpVtbl -> Active(This) ) 

#define IWorkBenchWindow_CloseTangramUI(This)	\
    ( (This)->lpVtbl -> CloseTangramUI(This) ) 

#define IWorkBenchWindow_Observe(This,bstrKey,bstrXml,ppXobj)	\
    ( (This)->lpVtbl -> Observe(This,bstrKey,bstrXml,ppXobj) ) 

#define IWorkBenchWindow_ObserveEx(This,bstrKey,bstrXml,ppXobj)	\
    ( (This)->lpVtbl -> ObserveEx(This,bstrKey,bstrXml,ppXobj) ) 

#define IWorkBenchWindow_ObserveinView(This,nIndex,bstrKey,bstrXml,ppRetXobj)	\
    ( (This)->lpVtbl -> ObserveinView(This,nIndex,bstrKey,bstrXml,ppRetXobj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWorkBenchWindow_INTERFACE_DEFINED__ */


#ifndef __IBrowser_INTERFACE_DEFINED__
#define __IBrowser_INTERFACE_DEFINED__

/* interface IBrowser */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBrowser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120180828")
    IBrowser : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteXobj( 
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoteXobj( 
            /* [in] */ IXobj *newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenURL( 
            BSTR bstrURL,
            BrowserWndOpenDisposition nDisposition,
            BSTR bstrKey,
            BSTR bstrXml) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddURLs( 
            BSTR bstrURLs) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBrowser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBrowser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBrowser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBrowser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBrowser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBrowser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBrowser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteXobj )( 
            IBrowser * This,
            /* [retval][out] */ IXobj **pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteXobj )( 
            IBrowser * This,
            /* [in] */ IXobj *newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenURL )( 
            IBrowser * This,
            BSTR bstrURL,
            BrowserWndOpenDisposition nDisposition,
            BSTR bstrKey,
            BSTR bstrXml);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddURLs )( 
            IBrowser * This,
            BSTR bstrURLs);
        
        END_INTERFACE
    } IBrowserVtbl;

    interface IBrowser
    {
        CONST_VTBL struct IBrowserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBrowser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBrowser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBrowser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBrowser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBrowser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBrowser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBrowser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBrowser_get_RemoteXobj(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoteXobj(This,pVal) ) 

#define IBrowser_put_RemoteXobj(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoteXobj(This,newVal) ) 

#define IBrowser_OpenURL(This,bstrURL,nDisposition,bstrKey,bstrXml)	\
    ( (This)->lpVtbl -> OpenURL(This,bstrURL,nDisposition,bstrKey,bstrXml) ) 

#define IBrowser_AddURLs(This,bstrURLs)	\
    ( (This)->lpVtbl -> AddURLs(This,bstrURLs) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBrowser_INTERFACE_DEFINED__ */


#ifndef __IWebPage_INTERFACE_DEFINED__
#define __IWebPage_INTERFACE_DEFINED__

/* interface IWebPage */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebPage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120180903")
    IWebPage : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HostWnd( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_HostWnd( 
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateForm( 
            BSTR bstrKey,
            LONGLONG hParent,
            /* [retval][out] */ IDispatch **pRetForm) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **pRetXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SendXmlMessage( 
            IXobj *sender,
            BSTR bstrXml) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebPageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebPage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebPage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebPage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebPage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebPage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebPage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebPage * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostWnd )( 
            IWebPage * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostWnd )( 
            IWebPage * This,
            /* [in] */ LONGLONG newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateForm )( 
            IWebPage * This,
            BSTR bstrKey,
            LONGLONG hParent,
            /* [retval][out] */ IDispatch **pRetForm);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            IWebPage * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **pRetXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SendXmlMessage )( 
            IWebPage * This,
            IXobj *sender,
            BSTR bstrXml);
        
        END_INTERFACE
    } IWebPageVtbl;

    interface IWebPage
    {
        CONST_VTBL struct IWebPageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebPage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebPage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebPage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebPage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebPage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebPage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebPage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebPage_get_HostWnd(This,pVal)	\
    ( (This)->lpVtbl -> get_HostWnd(This,pVal) ) 

#define IWebPage_put_HostWnd(This,newVal)	\
    ( (This)->lpVtbl -> put_HostWnd(This,newVal) ) 

#define IWebPage_CreateForm(This,bstrKey,hParent,pRetForm)	\
    ( (This)->lpVtbl -> CreateForm(This,bstrKey,hParent,pRetForm) ) 

#define IWebPage_Observe(This,bstrKey,bstrXml,pRetXobj)	\
    ( (This)->lpVtbl -> Observe(This,bstrKey,bstrXml,pRetXobj) ) 

#define IWebPage_SendXmlMessage(This,sender,bstrXml)	\
    ( (This)->lpVtbl -> SendXmlMessage(This,sender,bstrXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebPage_INTERFACE_DEFINED__ */


#ifndef __IOfficeObject_INTERFACE_DEFINED__
#define __IOfficeObject_INTERFACE_DEFINED__

/* interface IOfficeObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOfficeObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060119650606")
    IOfficeObject : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Show( 
            VARIANT_BOOL bShow) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnloadCosmos( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOfficeObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOfficeObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOfficeObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOfficeObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOfficeObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOfficeObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOfficeObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOfficeObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Show )( 
            IOfficeObject * This,
            VARIANT_BOOL bShow);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            IOfficeObject * This,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnloadCosmos )( 
            IOfficeObject * This);
        
        END_INTERFACE
    } IOfficeObjectVtbl;

    interface IOfficeObject
    {
        CONST_VTBL struct IOfficeObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOfficeObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOfficeObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOfficeObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOfficeObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOfficeObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOfficeObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOfficeObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOfficeObject_Show(This,bShow)	\
    ( (This)->lpVtbl -> Show(This,bShow) ) 

#define IOfficeObject_Observe(This,bstrKey,bstrXml,ppXobj)	\
    ( (This)->lpVtbl -> Observe(This,bstrKey,bstrXml,ppXobj) ) 

#define IOfficeObject_UnloadCosmos(This)	\
    ( (This)->lpVtbl -> UnloadCosmos(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOfficeObject_INTERFACE_DEFINED__ */


#ifndef __IWebRTCtrl_INTERFACE_DEFINED__
#define __IWebRTCtrl_INTERFACE_DEFINED__

/* interface IWebRTCtrl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-0601198231DC")
    IWebRTCtrl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Cosmos( 
            /* [retval][out] */ IWebRT **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_tag( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_tag( 
            /* [in] */ VARIANT newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTCtrl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IWebRTCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cosmos )( 
            IWebRTCtrl * This,
            /* [retval][out] */ IWebRT **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            IWebRTCtrl * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            IWebRTCtrl * This,
            /* [in] */ VARIANT newVal);
        
        END_INTERFACE
    } IWebRTCtrlVtbl;

    interface IWebRTCtrl
    {
        CONST_VTBL struct IWebRTCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRTCtrl_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define IWebRTCtrl_get_Cosmos(This,pVal)	\
    ( (This)->lpVtbl -> get_Cosmos(This,pVal) ) 

#define IWebRTCtrl_get_tag(This,pVal)	\
    ( (This)->lpVtbl -> get_tag(This,pVal) ) 

#define IWebRTCtrl_put_tag(This,newVal)	\
    ( (This)->lpVtbl -> put_tag(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTCtrl_INTERFACE_DEFINED__ */


#ifndef __IWebRTAppCtrl_INTERFACE_DEFINED__
#define __IWebRTAppCtrl_INTERFACE_DEFINED__

/* interface IWebRTAppCtrl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWebRTAppCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120161001")
    IWebRTAppCtrl : public IWebRTCtrl
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AppCtrl( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IWebRTAppCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebRTAppCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebRTAppCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebRTAppCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWebRTAppCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWebRTAppCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWebRTAppCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWebRTAppCtrl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IWebRTAppCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cosmos )( 
            IWebRTAppCtrl * This,
            /* [retval][out] */ IWebRT **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            IWebRTAppCtrl * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            IWebRTAppCtrl * This,
            /* [in] */ VARIANT newVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppCtrl )( 
            IWebRTAppCtrl * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IWebRTAppCtrlVtbl;

    interface IWebRTAppCtrl
    {
        CONST_VTBL struct IWebRTAppCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebRTAppCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWebRTAppCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWebRTAppCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWebRTAppCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWebRTAppCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWebRTAppCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWebRTAppCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWebRTAppCtrl_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define IWebRTAppCtrl_get_Cosmos(This,pVal)	\
    ( (This)->lpVtbl -> get_Cosmos(This,pVal) ) 

#define IWebRTAppCtrl_get_tag(This,pVal)	\
    ( (This)->lpVtbl -> get_tag(This,pVal) ) 

#define IWebRTAppCtrl_put_tag(This,newVal)	\
    ( (This)->lpVtbl -> put_tag(This,newVal) ) 


#define IWebRTAppCtrl_put_AppCtrl(This,newVal)	\
    ( (This)->lpVtbl -> put_AppCtrl(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWebRTAppCtrl_INTERFACE_DEFINED__ */


#ifndef __IEclipseCtrl_INTERFACE_DEFINED__
#define __IEclipseCtrl_INTERFACE_DEFINED__

/* interface IEclipseCtrl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEclipseCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("19631222-1992-0612-1965-060120160912")
    IEclipseCtrl : public IWebRTCtrl
    {
    public:
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Handle( 
            BSTR bstrHandleName,
            /* [in] */ LONGLONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EclipseViewHandle( 
            /* [retval][out] */ LONGLONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Nuclei( 
            /* [retval][out] */ INuclei **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_WorkBenchWindow( 
            /* [retval][out] */ IWorkBenchWindow **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopNuclei( 
            /* [retval][out] */ INuclei **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TopGalaxy( 
            /* [retval][out] */ INucleus **pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveTopXobj( 
            /* [retval][out] */ IXobj **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AppKeyValue( 
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AppKeyValue( 
            BSTR bstrKey,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Observe( 
            BSTR bstrNucleusName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObserveEx( 
            BSTR bstrNucleusName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitCtrl( 
            BSTR bstrXml) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEclipseCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEclipseCtrl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEclipseCtrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEclipseCtrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEclipseCtrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEclipseCtrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEclipseCtrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEclipseCtrl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IEclipseCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cosmos )( 
            IEclipseCtrl * This,
            /* [retval][out] */ IWebRT **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_tag )( 
            IEclipseCtrl * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_tag )( 
            IEclipseCtrl * This,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Handle )( 
            IEclipseCtrl * This,
            BSTR bstrHandleName,
            /* [in] */ LONGLONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EclipseViewHandle )( 
            IEclipseCtrl * This,
            /* [retval][out] */ LONGLONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Nuclei )( 
            IEclipseCtrl * This,
            /* [retval][out] */ INuclei **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WorkBenchWindow )( 
            IEclipseCtrl * This,
            /* [retval][out] */ IWorkBenchWindow **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopNuclei )( 
            IEclipseCtrl * This,
            /* [retval][out] */ INuclei **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TopGalaxy )( 
            IEclipseCtrl * This,
            /* [retval][out] */ INucleus **pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveTopXobj )( 
            IEclipseCtrl * This,
            /* [retval][out] */ IXobj **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AppKeyValue )( 
            IEclipseCtrl * This,
            BSTR bstrKey,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AppKeyValue )( 
            IEclipseCtrl * This,
            BSTR bstrKey,
            /* [in] */ VARIANT newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Observe )( 
            IEclipseCtrl * This,
            BSTR bstrNucleusName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObserveEx )( 
            IEclipseCtrl * This,
            BSTR bstrNucleusName,
            BSTR bstrKey,
            BSTR bstrXml,
            /* [retval][out] */ IXobj **ppXobj);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitCtrl )( 
            IEclipseCtrl * This,
            BSTR bstrXml);
        
        END_INTERFACE
    } IEclipseCtrlVtbl;

    interface IEclipseCtrl
    {
        CONST_VTBL struct IEclipseCtrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEclipseCtrl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEclipseCtrl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEclipseCtrl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEclipseCtrl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEclipseCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEclipseCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEclipseCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEclipseCtrl_get_HWND(This,pVal)	\
    ( (This)->lpVtbl -> get_HWND(This,pVal) ) 

#define IEclipseCtrl_get_Cosmos(This,pVal)	\
    ( (This)->lpVtbl -> get_Cosmos(This,pVal) ) 

#define IEclipseCtrl_get_tag(This,pVal)	\
    ( (This)->lpVtbl -> get_tag(This,pVal) ) 

#define IEclipseCtrl_put_tag(This,newVal)	\
    ( (This)->lpVtbl -> put_tag(This,newVal) ) 


#define IEclipseCtrl_put_Handle(This,bstrHandleName,newVal)	\
    ( (This)->lpVtbl -> put_Handle(This,bstrHandleName,newVal) ) 

#define IEclipseCtrl_get_EclipseViewHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_EclipseViewHandle(This,pVal) ) 

#define IEclipseCtrl_get_Nuclei(This,pVal)	\
    ( (This)->lpVtbl -> get_Nuclei(This,pVal) ) 

#define IEclipseCtrl_get_WorkBenchWindow(This,pVal)	\
    ( (This)->lpVtbl -> get_WorkBenchWindow(This,pVal) ) 

#define IEclipseCtrl_get_TopNuclei(This,pVal)	\
    ( (This)->lpVtbl -> get_TopNuclei(This,pVal) ) 

#define IEclipseCtrl_get_TopGalaxy(This,pVal)	\
    ( (This)->lpVtbl -> get_TopGalaxy(This,pVal) ) 

#define IEclipseCtrl_get_ActiveTopXobj(This,pVal)	\
    ( (This)->lpVtbl -> get_ActiveTopXobj(This,pVal) ) 

#define IEclipseCtrl_get_AppKeyValue(This,bstrKey,pVal)	\
    ( (This)->lpVtbl -> get_AppKeyValue(This,bstrKey,pVal) ) 

#define IEclipseCtrl_put_AppKeyValue(This,bstrKey,newVal)	\
    ( (This)->lpVtbl -> put_AppKeyValue(This,bstrKey,newVal) ) 

#define IEclipseCtrl_Observe(This,bstrNucleusName,bstrKey,bstrXml,ppXobj)	\
    ( (This)->lpVtbl -> Observe(This,bstrNucleusName,bstrKey,bstrXml,ppXobj) ) 

#define IEclipseCtrl_ObserveEx(This,bstrNucleusName,bstrKey,bstrXml,ppXobj)	\
    ( (This)->lpVtbl -> ObserveEx(This,bstrNucleusName,bstrKey,bstrXml,ppXobj) ) 

#define IEclipseCtrl_InitCtrl(This,bstrXml)	\
    ( (This)->lpVtbl -> InitCtrl(This,bstrXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEclipseCtrl_INTERFACE_DEFINED__ */



#ifndef __Universe_LIBRARY_DEFINED__
#define __Universe_LIBRARY_DEFINED__

/* library Universe */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_Universe;

#ifndef ___IWebRT_DISPINTERFACE_DEFINED__
#define ___IWebRT_DISPINTERFACE_DEFINED__

/* dispinterface _IWebRT */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IWebRT;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060119821002")
    _IWebRT : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IWebRTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IWebRT * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IWebRT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IWebRT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IWebRT * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IWebRT * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IWebRT * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IWebRT * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IWebRTVtbl;

    interface _IWebRT
    {
        CONST_VTBL struct _IWebRTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IWebRT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IWebRT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IWebRT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IWebRT_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IWebRT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IWebRT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IWebRT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IWebRT_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Cosmos;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060119990606")
Cosmos;
#endif

#ifndef ___IXobjEvents_DISPINTERFACE_DEFINED__
#define ___IXobjEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IXobjEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IXobjEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060119821001")
    _IXobjEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IXobjEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IXobjEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IXobjEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IXobjEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IXobjEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IXobjEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IXobjEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IXobjEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IXobjEventsVtbl;

    interface _IXobjEvents
    {
        CONST_VTBL struct _IXobjEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IXobjEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IXobjEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IXobjEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IXobjEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IXobjEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IXobjEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IXobjEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IXobjEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___IWebRTObjEvents_DISPINTERFACE_DEFINED__
#define ___IWebRTObjEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IWebRTObjEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IWebRTObjEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060119821992")
    _IWebRTObjEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IWebRTObjEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IWebRTObjEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IWebRTObjEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IWebRTObjEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IWebRTObjEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IWebRTObjEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IWebRTObjEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IWebRTObjEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IWebRTObjEventsVtbl;

    interface _IWebRTObjEvents
    {
        CONST_VTBL struct _IWebRTObjEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IWebRTObjEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IWebRTObjEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IWebRTObjEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IWebRTObjEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IWebRTObjEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IWebRTObjEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IWebRTObjEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IWebRTObjEvents_DISPINTERFACE_DEFINED__ */


#ifndef ___IWebRTAppEvents_DISPINTERFACE_DEFINED__
#define ___IWebRTAppEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IWebRTAppEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IWebRTAppEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19631222-1992-0612-1965-060120160930")
    _IWebRTAppEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IWebRTAppEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IWebRTAppEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IWebRTAppEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IWebRTAppEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IWebRTAppEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IWebRTAppEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IWebRTAppEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IWebRTAppEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IWebRTAppEventsVtbl;

    interface _IWebRTAppEvents
    {
        CONST_VTBL struct _IWebRTAppEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IWebRTAppEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IWebRTAppEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IWebRTAppEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IWebRTAppEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IWebRTAppEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IWebRTAppEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IWebRTAppEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IWebRTAppEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WebRTCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060120071001")
CosmosCtrl;
#endif

EXTERN_C const CLSID CLSID_CosmosExtender;

#ifdef __cplusplus

class DECLSPEC_UUID("19631222-1992-0612-1965-060100000000")
CosmosExtender;
#endif
#endif /* __Universe_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


