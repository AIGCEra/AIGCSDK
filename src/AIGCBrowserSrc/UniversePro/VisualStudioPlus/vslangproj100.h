

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __vslangproj100_h__
#define __vslangproj100_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __VBProjectProperties6_FWD_DEFINED__
#define __VBProjectProperties6_FWD_DEFINED__
typedef interface VBProjectProperties6 VBProjectProperties6;

#endif 	/* __VBProjectProperties6_FWD_DEFINED__ */


#ifndef __VBProjectConfigurationProperties5_FWD_DEFINED__
#define __VBProjectConfigurationProperties5_FWD_DEFINED__
typedef interface VBProjectConfigurationProperties5 VBProjectConfigurationProperties5;

#endif 	/* __VBProjectConfigurationProperties5_FWD_DEFINED__ */


#ifndef __CSharpProjectProperties6_FWD_DEFINED__
#define __CSharpProjectProperties6_FWD_DEFINED__
typedef interface CSharpProjectProperties6 CSharpProjectProperties6;

#endif 	/* __CSharpProjectProperties6_FWD_DEFINED__ */


#ifndef __CSharpProjectConfigurationProperties5_FWD_DEFINED__
#define __CSharpProjectConfigurationProperties5_FWD_DEFINED__
typedef interface CSharpProjectConfigurationProperties5 CSharpProjectConfigurationProperties5;

#endif 	/* __CSharpProjectConfigurationProperties5_FWD_DEFINED__ */


#ifndef __Reference4_FWD_DEFINED__
#define __Reference4_FWD_DEFINED__
typedef interface Reference4 Reference4;

#endif 	/* __Reference4_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vslangproj100_0000_0000 */
/* [local] */ 

#define VSLANGPROJ100_VER_MAJ   10
#define VSLANGPROJ100_VER_MIN    0


extern RPC_IF_HANDLE __MIDL_itf_vslangproj100_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vslangproj100_0000_0000_v0_0_s_ifspec;


#ifndef __VSLangProj100_LIBRARY_DEFINED__
#define __VSLangProj100_LIBRARY_DEFINED__

/* library VSLangProj100 */
/* [version][helpstring][uuid] */ 


enum VsProjPropId100
    {
        VBPROJPROPID_TargetFrameworkMoniker	= 12202,
        VBPROJPROPID_CodeAnalysisRuleSet	= 15212,
        VBPROJPROPID_CodeAnalysisRuleSetDirectories	= 15213,
        VBPROJPROPID_CodeAnalysisIgnoreBuiltInRuleSets	= 15214,
        VBPROJPROPID_CodeAnalysisRuleDirectories	= 15215,
        VBPROJPROPID_CodeAnalysisIgnoreBuiltInRules	= 15216,
        VBPROJPROPID_CodeAnalysisFailOnMissingRules	= 15217
    } ;

enum VsProjReferencePropId100
    {
        DISPID_Reference_EmbedInteropTypes	= 127
    } ;

enum VBProjPropId100
    {
        VBPROJPROPID_LanguageVersion	= 16101
    } ;

EXTERN_C const IID LIBID_VSLangProj100;

#ifndef __VBProjectProperties6_INTERFACE_DEFINED__
#define __VBProjectProperties6_INTERFACE_DEFINED__

/* interface VBProjectProperties6 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_VBProjectProperties6;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7d84f860-7e2a-42c4-9a70-455b8238dd66")
    VBProjectProperties6 : public VBProjectProperties4
    {
    public:
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_TargetFrameworkMoniker( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrTargetFrameworkMoniker) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propput] */ HRESULT STDMETHODCALLTYPE put_TargetFrameworkMoniker( 
            /* [in] */ __RPC__in BSTR bstrTargetFrameworkMoniker) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LanguageVersion( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrLanguageVersion) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LanguageVersion( 
            /* [in] */ __RPC__in BSTR LanguageVersion) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct VBProjectProperties6Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **ppvObj,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in VBProjectProperties6 * This,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *pctinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **pptinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ __RPC__deref_in_opt signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__out signed long *rgdispid,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ __RPC__in struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ __RPC__out VARIANT *pvarResult,
            /* [out][idldescattr] */ __RPC__out struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *puArgErr,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___project )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartupObject )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartupObject )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOutputType *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOutputType noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RootNamespace )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RootNamespace )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFile )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFile )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyContainerName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyContainerName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyMode )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOriginatorKeyMode *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyMode )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOriginatorKeyMode noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DelaySign )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DelaySign )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServer )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServerVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ServerExtensionsVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinkRepair )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinkRepair )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OfflineURL )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileSharePath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileSharePath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveFileSharePath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebAccessMethod )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjWebAccessMethod *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WebAccessMethod )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjWebAccessMethod noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWebAccessMethod )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjWebAccessMethod *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultClientScript )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjScriptLanguage *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultClientScript )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjScriptLanguage noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTargetSchema )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjTargetSchema *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTargetSchema )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjTargetSchema noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHTMLPageLayout )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjHTMLPageLayout *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHTMLPageLayout )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjHTMLPageLayout noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveConfigurationSettings )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt ProjectConfigurationProperties **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR ExtenderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationIcon )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationIcon )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionStrict )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOptionStrict *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionStrict )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOptionStrict noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ReferencePath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ReferencePath )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AbsoluteProjectDirectory )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionExplicit )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOptionExplicit *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionExplicit )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOptionExplicit noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionCompare )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjCompare *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionCompare )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjCompare noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjProjectType *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultNamespace )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultNamespace )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PreBuildEvent )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PreBuildEvent )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PostBuildEvent )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PostBuildEvent )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RunPostBuildEvent )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjRunPostBuildEvent *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RunPostBuildEvent )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjRunPostBuildEvent noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AspnetVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Product )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Product )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Copyright )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Trademark )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Trademark )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjAssemblyType *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjAssemblyType noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TypeComplianceDiagnostics )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TypeComplianceDiagnostics )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Win32ResourceFile )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Win32ResourceFile )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyProviderName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyProviderName )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFileType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFileType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyFileVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyFileVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_GenerateManifests )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_GenerateManifests )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSecurityDebugging )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSecurityDebugging )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSecurityZoneURL )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSecurityZoneURL )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Publish )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ComVisible )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ComVisible )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyGuid )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyGuid )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NeutralResourcesLanguage )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NeutralResourcesLanguage )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SignAssembly )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SignAssembly )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SignManifests )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SignManifests )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TargetZone )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TargetZone )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExcludedPermissions )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ExcludedPermissions )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestCertificateThumbprint )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ManifestCertificateThumbprint )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestKeyFile )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ManifestKeyFile )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestTimestampUrl )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ManifestTimestampUrl )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_MyApplication )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_MyType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_MyType )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TargetFramework )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TargetFramework )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationManifest )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationManifest )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionInfer )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOptionInfer *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionInfer )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOptionInfer noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetFrameworkMoniker )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrTargetFrameworkMoniker);
        
        /* [helpstring][id][nonbrowsable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TargetFrameworkMoniker )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in] */ __RPC__in BSTR bstrTargetFrameworkMoniker);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrLanguageVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LanguageVersion )( 
            __RPC__in VBProjectProperties6 * This,
            /* [in] */ __RPC__in BSTR LanguageVersion);
        
        END_INTERFACE
    } VBProjectProperties6Vtbl;

    interface VBProjectProperties6
    {
        CONST_VTBL struct VBProjectProperties6Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define VBProjectProperties6_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define VBProjectProperties6_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define VBProjectProperties6_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define VBProjectProperties6_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define VBProjectProperties6_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define VBProjectProperties6_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define VBProjectProperties6_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define VBProjectProperties6_get___id(This,retval)	\
    ( (This)->lpVtbl -> get___id(This,retval) ) 

#define VBProjectProperties6_get___project(This,retval)	\
    ( (This)->lpVtbl -> get___project(This,retval) ) 

#define VBProjectProperties6_get_StartupObject(This,retval)	\
    ( (This)->lpVtbl -> get_StartupObject(This,retval) ) 

#define VBProjectProperties6_put_StartupObject(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartupObject(This,noname,retval) ) 

#define VBProjectProperties6_get_OutputType(This,retval)	\
    ( (This)->lpVtbl -> get_OutputType(This,retval) ) 

#define VBProjectProperties6_put_OutputType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OutputType(This,noname,retval) ) 

#define VBProjectProperties6_get_RootNamespace(This,retval)	\
    ( (This)->lpVtbl -> get_RootNamespace(This,retval) ) 

#define VBProjectProperties6_put_RootNamespace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RootNamespace(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyName(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyName(This,retval) ) 

#define VBProjectProperties6_put_AssemblyName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyName(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyOriginatorKeyFile(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyOriginatorKeyFile(This,retval) ) 

#define VBProjectProperties6_put_AssemblyOriginatorKeyFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyOriginatorKeyFile(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyKeyContainerName(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyKeyContainerName(This,retval) ) 

#define VBProjectProperties6_put_AssemblyKeyContainerName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyKeyContainerName(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyOriginatorKeyMode(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyOriginatorKeyMode(This,retval) ) 

#define VBProjectProperties6_put_AssemblyOriginatorKeyMode(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyOriginatorKeyMode(This,noname,retval) ) 

#define VBProjectProperties6_get_DelaySign(This,retval)	\
    ( (This)->lpVtbl -> get_DelaySign(This,retval) ) 

#define VBProjectProperties6_put_DelaySign(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DelaySign(This,noname,retval) ) 

#define VBProjectProperties6_get_WebServer(This,retval)	\
    ( (This)->lpVtbl -> get_WebServer(This,retval) ) 

#define VBProjectProperties6_get_WebServerVersion(This,retval)	\
    ( (This)->lpVtbl -> get_WebServerVersion(This,retval) ) 

#define VBProjectProperties6_get_ServerExtensionsVersion(This,retval)	\
    ( (This)->lpVtbl -> get_ServerExtensionsVersion(This,retval) ) 

#define VBProjectProperties6_get_LinkRepair(This,retval)	\
    ( (This)->lpVtbl -> get_LinkRepair(This,retval) ) 

#define VBProjectProperties6_put_LinkRepair(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinkRepair(This,noname,retval) ) 

#define VBProjectProperties6_get_OfflineURL(This,retval)	\
    ( (This)->lpVtbl -> get_OfflineURL(This,retval) ) 

#define VBProjectProperties6_get_FileSharePath(This,retval)	\
    ( (This)->lpVtbl -> get_FileSharePath(This,retval) ) 

#define VBProjectProperties6_put_FileSharePath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_FileSharePath(This,noname,retval) ) 

#define VBProjectProperties6_get_ActiveFileSharePath(This,retval)	\
    ( (This)->lpVtbl -> get_ActiveFileSharePath(This,retval) ) 

#define VBProjectProperties6_get_WebAccessMethod(This,retval)	\
    ( (This)->lpVtbl -> get_WebAccessMethod(This,retval) ) 

#define VBProjectProperties6_put_WebAccessMethod(This,noname,retval)	\
    ( (This)->lpVtbl -> put_WebAccessMethod(This,noname,retval) ) 

#define VBProjectProperties6_get_ActiveWebAccessMethod(This,retval)	\
    ( (This)->lpVtbl -> get_ActiveWebAccessMethod(This,retval) ) 

#define VBProjectProperties6_get_DefaultClientScript(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultClientScript(This,retval) ) 

#define VBProjectProperties6_put_DefaultClientScript(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultClientScript(This,noname,retval) ) 

#define VBProjectProperties6_get_DefaultTargetSchema(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultTargetSchema(This,retval) ) 

#define VBProjectProperties6_put_DefaultTargetSchema(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultTargetSchema(This,noname,retval) ) 

#define VBProjectProperties6_get_DefaultHTMLPageLayout(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultHTMLPageLayout(This,retval) ) 

#define VBProjectProperties6_put_DefaultHTMLPageLayout(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultHTMLPageLayout(This,noname,retval) ) 

#define VBProjectProperties6_get_FileName(This,retval)	\
    ( (This)->lpVtbl -> get_FileName(This,retval) ) 

#define VBProjectProperties6_put_FileName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_FileName(This,noname,retval) ) 

#define VBProjectProperties6_get_FullPath(This,retval)	\
    ( (This)->lpVtbl -> get_FullPath(This,retval) ) 

#define VBProjectProperties6_get_LocalPath(This,retval)	\
    ( (This)->lpVtbl -> get_LocalPath(This,retval) ) 

#define VBProjectProperties6_get_URL(This,retval)	\
    ( (This)->lpVtbl -> get_URL(This,retval) ) 

#define VBProjectProperties6_get_ActiveConfigurationSettings(This,retval)	\
    ( (This)->lpVtbl -> get_ActiveConfigurationSettings(This,retval) ) 

#define VBProjectProperties6_get_Extender(This,ExtenderName,retval)	\
    ( (This)->lpVtbl -> get_Extender(This,ExtenderName,retval) ) 

#define VBProjectProperties6_get_ExtenderNames(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderNames(This,retval) ) 

#define VBProjectProperties6_get_ExtenderCATID(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderCATID(This,retval) ) 

#define VBProjectProperties6_get_ApplicationIcon(This,retval)	\
    ( (This)->lpVtbl -> get_ApplicationIcon(This,retval) ) 

#define VBProjectProperties6_put_ApplicationIcon(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ApplicationIcon(This,noname,retval) ) 

#define VBProjectProperties6_get_OptionStrict(This,retval)	\
    ( (This)->lpVtbl -> get_OptionStrict(This,retval) ) 

#define VBProjectProperties6_put_OptionStrict(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionStrict(This,noname,retval) ) 

#define VBProjectProperties6_get_ReferencePath(This,retval)	\
    ( (This)->lpVtbl -> get_ReferencePath(This,retval) ) 

#define VBProjectProperties6_put_ReferencePath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ReferencePath(This,noname,retval) ) 

#define VBProjectProperties6_get_OutputFileName(This,retval)	\
    ( (This)->lpVtbl -> get_OutputFileName(This,retval) ) 

#define VBProjectProperties6_get_AbsoluteProjectDirectory(This,retval)	\
    ( (This)->lpVtbl -> get_AbsoluteProjectDirectory(This,retval) ) 

#define VBProjectProperties6_get_OptionExplicit(This,retval)	\
    ( (This)->lpVtbl -> get_OptionExplicit(This,retval) ) 

#define VBProjectProperties6_put_OptionExplicit(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionExplicit(This,noname,retval) ) 

#define VBProjectProperties6_get_OptionCompare(This,retval)	\
    ( (This)->lpVtbl -> get_OptionCompare(This,retval) ) 

#define VBProjectProperties6_put_OptionCompare(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionCompare(This,noname,retval) ) 

#define VBProjectProperties6_get_ProjectType(This,retval)	\
    ( (This)->lpVtbl -> get_ProjectType(This,retval) ) 

#define VBProjectProperties6_get_DefaultNamespace(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultNamespace(This,retval) ) 

#define VBProjectProperties6_put_DefaultNamespace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultNamespace(This,noname,retval) ) 

#define VBProjectProperties6_get_PreBuildEvent(This,retval)	\
    ( (This)->lpVtbl -> get_PreBuildEvent(This,retval) ) 

#define VBProjectProperties6_put_PreBuildEvent(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PreBuildEvent(This,noname,retval) ) 

#define VBProjectProperties6_get_PostBuildEvent(This,retval)	\
    ( (This)->lpVtbl -> get_PostBuildEvent(This,retval) ) 

#define VBProjectProperties6_put_PostBuildEvent(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PostBuildEvent(This,noname,retval) ) 

#define VBProjectProperties6_get_RunPostBuildEvent(This,retval)	\
    ( (This)->lpVtbl -> get_RunPostBuildEvent(This,retval) ) 

#define VBProjectProperties6_put_RunPostBuildEvent(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RunPostBuildEvent(This,noname,retval) ) 

#define VBProjectProperties6_get_AspnetVersion(This,retval)	\
    ( (This)->lpVtbl -> get_AspnetVersion(This,retval) ) 

#define VBProjectProperties6_get_Title(This,retval)	\
    ( (This)->lpVtbl -> get_Title(This,retval) ) 

#define VBProjectProperties6_put_Title(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Title(This,noname,retval) ) 

#define VBProjectProperties6_get_Description(This,retval)	\
    ( (This)->lpVtbl -> get_Description(This,retval) ) 

#define VBProjectProperties6_put_Description(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Description(This,noname,retval) ) 

#define VBProjectProperties6_get_Company(This,retval)	\
    ( (This)->lpVtbl -> get_Company(This,retval) ) 

#define VBProjectProperties6_put_Company(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Company(This,noname,retval) ) 

#define VBProjectProperties6_get_Product(This,retval)	\
    ( (This)->lpVtbl -> get_Product(This,retval) ) 

#define VBProjectProperties6_put_Product(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Product(This,noname,retval) ) 

#define VBProjectProperties6_get_Copyright(This,retval)	\
    ( (This)->lpVtbl -> get_Copyright(This,retval) ) 

#define VBProjectProperties6_put_Copyright(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Copyright(This,noname,retval) ) 

#define VBProjectProperties6_get_Trademark(This,retval)	\
    ( (This)->lpVtbl -> get_Trademark(This,retval) ) 

#define VBProjectProperties6_put_Trademark(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Trademark(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyType(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyType(This,retval) ) 

#define VBProjectProperties6_put_AssemblyType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyType(This,noname,retval) ) 

#define VBProjectProperties6_get_TypeComplianceDiagnostics(This,retval)	\
    ( (This)->lpVtbl -> get_TypeComplianceDiagnostics(This,retval) ) 

#define VBProjectProperties6_put_TypeComplianceDiagnostics(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TypeComplianceDiagnostics(This,noname,retval) ) 

#define VBProjectProperties6_get_Win32ResourceFile(This,retval)	\
    ( (This)->lpVtbl -> get_Win32ResourceFile(This,retval) ) 

#define VBProjectProperties6_put_Win32ResourceFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Win32ResourceFile(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyKeyProviderName(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyKeyProviderName(This,retval) ) 

#define VBProjectProperties6_put_AssemblyKeyProviderName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyKeyProviderName(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyOriginatorKeyFileType(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyOriginatorKeyFileType(This,retval) ) 

#define VBProjectProperties6_put_AssemblyOriginatorKeyFileType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyOriginatorKeyFileType(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyVersion(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyVersion(This,retval) ) 

#define VBProjectProperties6_put_AssemblyVersion(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyVersion(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyFileVersion(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyFileVersion(This,retval) ) 

#define VBProjectProperties6_put_AssemblyFileVersion(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyFileVersion(This,noname,retval) ) 

#define VBProjectProperties6_get_GenerateManifests(This,retval)	\
    ( (This)->lpVtbl -> get_GenerateManifests(This,retval) ) 

#define VBProjectProperties6_put_GenerateManifests(This,noname,retval)	\
    ( (This)->lpVtbl -> put_GenerateManifests(This,noname,retval) ) 

#define VBProjectProperties6_get_EnableSecurityDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableSecurityDebugging(This,retval) ) 

#define VBProjectProperties6_put_EnableSecurityDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableSecurityDebugging(This,noname,retval) ) 

#define VBProjectProperties6_get_DebugSecurityZoneURL(This,retval)	\
    ( (This)->lpVtbl -> get_DebugSecurityZoneURL(This,retval) ) 

#define VBProjectProperties6_put_DebugSecurityZoneURL(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DebugSecurityZoneURL(This,noname,retval) ) 

#define VBProjectProperties6_get_Publish(This,retval)	\
    ( (This)->lpVtbl -> get_Publish(This,retval) ) 

#define VBProjectProperties6_get_ComVisible(This,retval)	\
    ( (This)->lpVtbl -> get_ComVisible(This,retval) ) 

#define VBProjectProperties6_put_ComVisible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ComVisible(This,noname,retval) ) 

#define VBProjectProperties6_get_AssemblyGuid(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyGuid(This,retval) ) 

#define VBProjectProperties6_put_AssemblyGuid(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyGuid(This,noname,retval) ) 

#define VBProjectProperties6_get_NeutralResourcesLanguage(This,retval)	\
    ( (This)->lpVtbl -> get_NeutralResourcesLanguage(This,retval) ) 

#define VBProjectProperties6_put_NeutralResourcesLanguage(This,noname,retval)	\
    ( (This)->lpVtbl -> put_NeutralResourcesLanguage(This,noname,retval) ) 

#define VBProjectProperties6_get_SignAssembly(This,retval)	\
    ( (This)->lpVtbl -> get_SignAssembly(This,retval) ) 

#define VBProjectProperties6_put_SignAssembly(This,noname,retval)	\
    ( (This)->lpVtbl -> put_SignAssembly(This,noname,retval) ) 

#define VBProjectProperties6_get_SignManifests(This,retval)	\
    ( (This)->lpVtbl -> get_SignManifests(This,retval) ) 

#define VBProjectProperties6_put_SignManifests(This,noname,retval)	\
    ( (This)->lpVtbl -> put_SignManifests(This,noname,retval) ) 

#define VBProjectProperties6_get_TargetZone(This,retval)	\
    ( (This)->lpVtbl -> get_TargetZone(This,retval) ) 

#define VBProjectProperties6_put_TargetZone(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TargetZone(This,noname,retval) ) 

#define VBProjectProperties6_get_ExcludedPermissions(This,retval)	\
    ( (This)->lpVtbl -> get_ExcludedPermissions(This,retval) ) 

#define VBProjectProperties6_put_ExcludedPermissions(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ExcludedPermissions(This,noname,retval) ) 

#define VBProjectProperties6_get_ManifestCertificateThumbprint(This,retval)	\
    ( (This)->lpVtbl -> get_ManifestCertificateThumbprint(This,retval) ) 

#define VBProjectProperties6_put_ManifestCertificateThumbprint(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ManifestCertificateThumbprint(This,noname,retval) ) 

#define VBProjectProperties6_get_ManifestKeyFile(This,retval)	\
    ( (This)->lpVtbl -> get_ManifestKeyFile(This,retval) ) 

#define VBProjectProperties6_put_ManifestKeyFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ManifestKeyFile(This,noname,retval) ) 

#define VBProjectProperties6_get_ManifestTimestampUrl(This,retval)	\
    ( (This)->lpVtbl -> get_ManifestTimestampUrl(This,retval) ) 

#define VBProjectProperties6_put_ManifestTimestampUrl(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ManifestTimestampUrl(This,noname,retval) ) 

#define VBProjectProperties6_get_MyApplication(This,retval)	\
    ( (This)->lpVtbl -> get_MyApplication(This,retval) ) 

#define VBProjectProperties6_get_MyType(This,retval)	\
    ( (This)->lpVtbl -> get_MyType(This,retval) ) 

#define VBProjectProperties6_put_MyType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_MyType(This,noname,retval) ) 

#define VBProjectProperties6_get_TargetFramework(This,retval)	\
    ( (This)->lpVtbl -> get_TargetFramework(This,retval) ) 

#define VBProjectProperties6_put_TargetFramework(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TargetFramework(This,noname,retval) ) 

#define VBProjectProperties6_get_ApplicationManifest(This,retval)	\
    ( (This)->lpVtbl -> get_ApplicationManifest(This,retval) ) 

#define VBProjectProperties6_put_ApplicationManifest(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ApplicationManifest(This,noname,retval) ) 

#define VBProjectProperties6_get_OptionInfer(This,retval)	\
    ( (This)->lpVtbl -> get_OptionInfer(This,retval) ) 

#define VBProjectProperties6_put_OptionInfer(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionInfer(This,noname,retval) ) 


#define VBProjectProperties6_get_TargetFrameworkMoniker(This,pbstrTargetFrameworkMoniker)	\
    ( (This)->lpVtbl -> get_TargetFrameworkMoniker(This,pbstrTargetFrameworkMoniker) ) 

#define VBProjectProperties6_put_TargetFrameworkMoniker(This,bstrTargetFrameworkMoniker)	\
    ( (This)->lpVtbl -> put_TargetFrameworkMoniker(This,bstrTargetFrameworkMoniker) ) 

#define VBProjectProperties6_get_LanguageVersion(This,pbstrLanguageVersion)	\
    ( (This)->lpVtbl -> get_LanguageVersion(This,pbstrLanguageVersion) ) 

#define VBProjectProperties6_put_LanguageVersion(This,LanguageVersion)	\
    ( (This)->lpVtbl -> put_LanguageVersion(This,LanguageVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE VBProjectProperties6_get_TargetFrameworkMoniker_Proxy( 
    __RPC__in VBProjectProperties6 * This,
    /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrTargetFrameworkMoniker);


void __RPC_STUB VBProjectProperties6_get_TargetFrameworkMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][nonbrowsable][propput] */ HRESULT STDMETHODCALLTYPE VBProjectProperties6_put_TargetFrameworkMoniker_Proxy( 
    __RPC__in VBProjectProperties6 * This,
    /* [in] */ __RPC__in BSTR bstrTargetFrameworkMoniker);


void __RPC_STUB VBProjectProperties6_put_TargetFrameworkMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE VBProjectProperties6_get_LanguageVersion_Proxy( 
    __RPC__in VBProjectProperties6 * This,
    /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrLanguageVersion);


void __RPC_STUB VBProjectProperties6_get_LanguageVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE VBProjectProperties6_put_LanguageVersion_Proxy( 
    __RPC__in VBProjectProperties6 * This,
    /* [in] */ __RPC__in BSTR LanguageVersion);


void __RPC_STUB VBProjectProperties6_put_LanguageVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __VBProjectProperties6_INTERFACE_DEFINED__ */


#ifndef __VBProjectConfigurationProperties5_INTERFACE_DEFINED__
#define __VBProjectConfigurationProperties5_INTERFACE_DEFINED__

/* interface VBProjectConfigurationProperties5 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_VBProjectConfigurationProperties5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08624013-5567-494a-afe9-a4d1499e50b9")
    VBProjectConfigurationProperties5 : public VBProjectConfigurationProperties4
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisRuleSet( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSet) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisRuleSet( 
            /* [in] */ __RPC__in BSTR bstrRuleSet) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisRuleSetDirectories( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSetDirectories) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisRuleSetDirectories( 
            /* [in] */ __RPC__in BSTR bstrRuleSetDirectories) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisIgnoreBuiltInRuleSets( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRuleSets) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisIgnoreBuiltInRuleSets( 
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRuleSets) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisRuleDirectories( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleDirectories) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisRuleDirectories( 
            /* [in] */ __RPC__in BSTR bstrRuleDirectories) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisIgnoreBuiltInRules( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRules) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisIgnoreBuiltInRules( 
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRules) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisFailOnMissingRules( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbFailOnMissingRules) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisFailOnMissingRules( 
            /* [in] */ VARIANT_BOOL FailOnMissingRules) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct VBProjectConfigurationProperties5Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **ppvObj,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *pctinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **pptinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ __RPC__deref_in_opt signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__out signed long *rgdispid,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ __RPC__in struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ __RPC__out VARIANT *pvarResult,
            /* [out][idldescattr] */ __RPC__out struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *puArgErr,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSymbols )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSymbols )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineDebug )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineDebug )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineTrace )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineTrace )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPath )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPath )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IntermediatePath )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IntermediatePath )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineConstants )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineConstants )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveIntegerChecks )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveIntegerChecks )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BaseAddress )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_BaseAddress )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AllowUnsafeBlocks )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AllowUnsafeBlocks )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CheckForOverflowUnderflow )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CheckForOverflowUnderflow )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentationFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentationFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Optimize )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Optimize )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalBuild )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalBuild )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartProgram )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartProgram )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWorkingDirectory )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWorkingDirectory )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartURL )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartURL )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartPage )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartPage )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartArguments )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartArguments )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithIE )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithIE )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPXDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPXDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableUnmanagedDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableUnmanagedDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartAction )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out enum prjStartAction *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartAction )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ enum prjStartAction noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR ExtenderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WarningLevel )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out enum prjWarningLevel *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WarningLevel )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ enum prjWarningLevel noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatWarningsAsErrors )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatWarningsAsErrors )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSQLServerDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSQLServerDebugging )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileAlignment )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileAlignment )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterForComInterop )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterForComInterop )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigurationOverrideFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ConfigurationOverrideFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugEnabled )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugEnabled )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugMachine )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugMachine )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoWarn )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoWarn )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoStdLib )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoStdLib )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugInfo )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugInfo )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformTarget )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlatformTarget )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSpecificWarningsAsErrors )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSpecificWarningsAsErrors )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RunCodeAnalysis )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RunCodeAnalysis )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisLogFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisLogFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleAssemblies )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleAssemblies )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisInputAssembly )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisInputAssembly )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRules )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRules )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisSpellCheckLanguages )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisSpellCheckLanguages )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisUseTypeNameInSuppression )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisUseTypeNameInSuppression )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisModuleSuppressionsFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisModuleSuppressionsFile )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_UseVSHostingProcess )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_UseVSHostingProcess )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_GenerateSerializationAssemblies )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out enum sgenGenerationOption *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_GenerateSerializationAssemblies )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ enum sgenGenerationOption noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisIgnoreGeneratedCode )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisIgnoreGeneratedCode )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisOverrideRuleVisibilities )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisOverrideRuleVisibilities )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisDictionaries )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisDictionaries )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisCulture )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisCulture )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleSet )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSet);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleSet )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in] */ __RPC__in BSTR bstrRuleSet);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleSetDirectories )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSetDirectories);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleSetDirectories )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in] */ __RPC__in BSTR bstrRuleSetDirectories);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisIgnoreBuiltInRuleSets )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRuleSets);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisIgnoreBuiltInRuleSets )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRuleSets);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleDirectories )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleDirectories);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleDirectories )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in] */ __RPC__in BSTR bstrRuleDirectories);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisIgnoreBuiltInRules )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRules);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisIgnoreBuiltInRules )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRules);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisFailOnMissingRules )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbFailOnMissingRules);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisFailOnMissingRules )( 
            __RPC__in VBProjectConfigurationProperties5 * This,
            /* [in] */ VARIANT_BOOL FailOnMissingRules);
        
        END_INTERFACE
    } VBProjectConfigurationProperties5Vtbl;

    interface VBProjectConfigurationProperties5
    {
        CONST_VTBL struct VBProjectConfigurationProperties5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define VBProjectConfigurationProperties5_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define VBProjectConfigurationProperties5_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define VBProjectConfigurationProperties5_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define VBProjectConfigurationProperties5_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define VBProjectConfigurationProperties5_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define VBProjectConfigurationProperties5_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define VBProjectConfigurationProperties5_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define VBProjectConfigurationProperties5_get___id(This,retval)	\
    ( (This)->lpVtbl -> get___id(This,retval) ) 

#define VBProjectConfigurationProperties5_get_DebugSymbols(This,retval)	\
    ( (This)->lpVtbl -> get_DebugSymbols(This,retval) ) 

#define VBProjectConfigurationProperties5_put_DebugSymbols(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DebugSymbols(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_DefineDebug(This,retval)	\
    ( (This)->lpVtbl -> get_DefineDebug(This,retval) ) 

#define VBProjectConfigurationProperties5_put_DefineDebug(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefineDebug(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_DefineTrace(This,retval)	\
    ( (This)->lpVtbl -> get_DefineTrace(This,retval) ) 

#define VBProjectConfigurationProperties5_put_DefineTrace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefineTrace(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_OutputPath(This,retval)	\
    ( (This)->lpVtbl -> get_OutputPath(This,retval) ) 

#define VBProjectConfigurationProperties5_put_OutputPath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OutputPath(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_IntermediatePath(This,retval)	\
    ( (This)->lpVtbl -> get_IntermediatePath(This,retval) ) 

#define VBProjectConfigurationProperties5_put_IntermediatePath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_IntermediatePath(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_DefineConstants(This,retval)	\
    ( (This)->lpVtbl -> get_DefineConstants(This,retval) ) 

#define VBProjectConfigurationProperties5_put_DefineConstants(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefineConstants(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_RemoveIntegerChecks(This,retval)	\
    ( (This)->lpVtbl -> get_RemoveIntegerChecks(This,retval) ) 

#define VBProjectConfigurationProperties5_put_RemoveIntegerChecks(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RemoveIntegerChecks(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_BaseAddress(This,retval)	\
    ( (This)->lpVtbl -> get_BaseAddress(This,retval) ) 

#define VBProjectConfigurationProperties5_put_BaseAddress(This,noname,retval)	\
    ( (This)->lpVtbl -> put_BaseAddress(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_AllowUnsafeBlocks(This,retval)	\
    ( (This)->lpVtbl -> get_AllowUnsafeBlocks(This,retval) ) 

#define VBProjectConfigurationProperties5_put_AllowUnsafeBlocks(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AllowUnsafeBlocks(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CheckForOverflowUnderflow(This,retval)	\
    ( (This)->lpVtbl -> get_CheckForOverflowUnderflow(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CheckForOverflowUnderflow(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CheckForOverflowUnderflow(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_DocumentationFile(This,retval)	\
    ( (This)->lpVtbl -> get_DocumentationFile(This,retval) ) 

#define VBProjectConfigurationProperties5_put_DocumentationFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DocumentationFile(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_Optimize(This,retval)	\
    ( (This)->lpVtbl -> get_Optimize(This,retval) ) 

#define VBProjectConfigurationProperties5_put_Optimize(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Optimize(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_IncrementalBuild(This,retval)	\
    ( (This)->lpVtbl -> get_IncrementalBuild(This,retval) ) 

#define VBProjectConfigurationProperties5_put_IncrementalBuild(This,noname,retval)	\
    ( (This)->lpVtbl -> put_IncrementalBuild(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartProgram(This,retval)	\
    ( (This)->lpVtbl -> get_StartProgram(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartProgram(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartProgram(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartWorkingDirectory(This,retval)	\
    ( (This)->lpVtbl -> get_StartWorkingDirectory(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartWorkingDirectory(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartWorkingDirectory(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartURL(This,retval)	\
    ( (This)->lpVtbl -> get_StartURL(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartURL(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartURL(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartPage(This,retval)	\
    ( (This)->lpVtbl -> get_StartPage(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartPage(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartPage(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartArguments(This,retval)	\
    ( (This)->lpVtbl -> get_StartArguments(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartArguments(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartArguments(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartWithIE(This,retval)	\
    ( (This)->lpVtbl -> get_StartWithIE(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartWithIE(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartWithIE(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_EnableASPDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableASPDebugging(This,retval) ) 

#define VBProjectConfigurationProperties5_put_EnableASPDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableASPDebugging(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_EnableASPXDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableASPXDebugging(This,retval) ) 

#define VBProjectConfigurationProperties5_put_EnableASPXDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableASPXDebugging(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_EnableUnmanagedDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableUnmanagedDebugging(This,retval) ) 

#define VBProjectConfigurationProperties5_put_EnableUnmanagedDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableUnmanagedDebugging(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_StartAction(This,retval)	\
    ( (This)->lpVtbl -> get_StartAction(This,retval) ) 

#define VBProjectConfigurationProperties5_put_StartAction(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartAction(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_Extender(This,ExtenderName,retval)	\
    ( (This)->lpVtbl -> get_Extender(This,ExtenderName,retval) ) 

#define VBProjectConfigurationProperties5_get_ExtenderNames(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderNames(This,retval) ) 

#define VBProjectConfigurationProperties5_get_ExtenderCATID(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderCATID(This,retval) ) 

#define VBProjectConfigurationProperties5_get_WarningLevel(This,retval)	\
    ( (This)->lpVtbl -> get_WarningLevel(This,retval) ) 

#define VBProjectConfigurationProperties5_put_WarningLevel(This,noname,retval)	\
    ( (This)->lpVtbl -> put_WarningLevel(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_TreatWarningsAsErrors(This,retval)	\
    ( (This)->lpVtbl -> get_TreatWarningsAsErrors(This,retval) ) 

#define VBProjectConfigurationProperties5_put_TreatWarningsAsErrors(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TreatWarningsAsErrors(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_EnableSQLServerDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableSQLServerDebugging(This,retval) ) 

#define VBProjectConfigurationProperties5_put_EnableSQLServerDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableSQLServerDebugging(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_FileAlignment(This,retval)	\
    ( (This)->lpVtbl -> get_FileAlignment(This,retval) ) 

#define VBProjectConfigurationProperties5_put_FileAlignment(This,noname,retval)	\
    ( (This)->lpVtbl -> put_FileAlignment(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_RegisterForComInterop(This,retval)	\
    ( (This)->lpVtbl -> get_RegisterForComInterop(This,retval) ) 

#define VBProjectConfigurationProperties5_put_RegisterForComInterop(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RegisterForComInterop(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_ConfigurationOverrideFile(This,retval)	\
    ( (This)->lpVtbl -> get_ConfigurationOverrideFile(This,retval) ) 

#define VBProjectConfigurationProperties5_put_ConfigurationOverrideFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ConfigurationOverrideFile(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_RemoteDebugEnabled(This,retval)	\
    ( (This)->lpVtbl -> get_RemoteDebugEnabled(This,retval) ) 

#define VBProjectConfigurationProperties5_put_RemoteDebugEnabled(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RemoteDebugEnabled(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_RemoteDebugMachine(This,retval)	\
    ( (This)->lpVtbl -> get_RemoteDebugMachine(This,retval) ) 

#define VBProjectConfigurationProperties5_put_RemoteDebugMachine(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RemoteDebugMachine(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_NoWarn(This,retval)	\
    ( (This)->lpVtbl -> get_NoWarn(This,retval) ) 

#define VBProjectConfigurationProperties5_put_NoWarn(This,noname,retval)	\
    ( (This)->lpVtbl -> put_NoWarn(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_NoStdLib(This,retval)	\
    ( (This)->lpVtbl -> get_NoStdLib(This,retval) ) 

#define VBProjectConfigurationProperties5_put_NoStdLib(This,noname,retval)	\
    ( (This)->lpVtbl -> put_NoStdLib(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_DebugInfo(This,retval)	\
    ( (This)->lpVtbl -> get_DebugInfo(This,retval) ) 

#define VBProjectConfigurationProperties5_put_DebugInfo(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DebugInfo(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_PlatformTarget(This,retval)	\
    ( (This)->lpVtbl -> get_PlatformTarget(This,retval) ) 

#define VBProjectConfigurationProperties5_put_PlatformTarget(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlatformTarget(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_TreatSpecificWarningsAsErrors(This,retval)	\
    ( (This)->lpVtbl -> get_TreatSpecificWarningsAsErrors(This,retval) ) 

#define VBProjectConfigurationProperties5_put_TreatSpecificWarningsAsErrors(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TreatSpecificWarningsAsErrors(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_RunCodeAnalysis(This,retval)	\
    ( (This)->lpVtbl -> get_RunCodeAnalysis(This,retval) ) 

#define VBProjectConfigurationProperties5_put_RunCodeAnalysis(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RunCodeAnalysis(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisLogFile(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisLogFile(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisLogFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisLogFile(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisRuleAssemblies(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleAssemblies(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisRuleAssemblies(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleAssemblies(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisInputAssembly(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisInputAssembly(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisInputAssembly(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisInputAssembly(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisRules(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRules(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisRules(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRules(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisSpellCheckLanguages(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisSpellCheckLanguages(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisSpellCheckLanguages(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisSpellCheckLanguages(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisUseTypeNameInSuppression(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisUseTypeNameInSuppression(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisUseTypeNameInSuppression(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisUseTypeNameInSuppression(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisModuleSuppressionsFile(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisModuleSuppressionsFile(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisModuleSuppressionsFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisModuleSuppressionsFile(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_UseVSHostingProcess(This,retval)	\
    ( (This)->lpVtbl -> get_UseVSHostingProcess(This,retval) ) 

#define VBProjectConfigurationProperties5_put_UseVSHostingProcess(This,noname,retval)	\
    ( (This)->lpVtbl -> put_UseVSHostingProcess(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_GenerateSerializationAssemblies(This,retval)	\
    ( (This)->lpVtbl -> get_GenerateSerializationAssemblies(This,retval) ) 

#define VBProjectConfigurationProperties5_put_GenerateSerializationAssemblies(This,noname,retval)	\
    ( (This)->lpVtbl -> put_GenerateSerializationAssemblies(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisIgnoreGeneratedCode(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisIgnoreGeneratedCode(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisIgnoreGeneratedCode(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisIgnoreGeneratedCode(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisOverrideRuleVisibilities(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisOverrideRuleVisibilities(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisOverrideRuleVisibilities(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisOverrideRuleVisibilities(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisDictionaries(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisDictionaries(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisDictionaries(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisDictionaries(This,noname,retval) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisCulture(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisCulture(This,retval) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisCulture(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisCulture(This,noname,retval) ) 


#define VBProjectConfigurationProperties5_get_CodeAnalysisRuleSet(This,pbstrRuleSet)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleSet(This,pbstrRuleSet) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisRuleSet(This,bstrRuleSet)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleSet(This,bstrRuleSet) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisRuleSetDirectories(This,pbstrRuleSetDirectories)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleSetDirectories(This,pbstrRuleSetDirectories) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisRuleSetDirectories(This,bstrRuleSetDirectories)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleSetDirectories(This,bstrRuleSetDirectories) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisIgnoreBuiltInRuleSets(This,pbIgnoreBuiltInRuleSets)	\
    ( (This)->lpVtbl -> get_CodeAnalysisIgnoreBuiltInRuleSets(This,pbIgnoreBuiltInRuleSets) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisIgnoreBuiltInRuleSets(This,IgnoreBuiltInRuleSets)	\
    ( (This)->lpVtbl -> put_CodeAnalysisIgnoreBuiltInRuleSets(This,IgnoreBuiltInRuleSets) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisRuleDirectories(This,pbstrRuleDirectories)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleDirectories(This,pbstrRuleDirectories) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisRuleDirectories(This,bstrRuleDirectories)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleDirectories(This,bstrRuleDirectories) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisIgnoreBuiltInRules(This,pbIgnoreBuiltInRules)	\
    ( (This)->lpVtbl -> get_CodeAnalysisIgnoreBuiltInRules(This,pbIgnoreBuiltInRules) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisIgnoreBuiltInRules(This,IgnoreBuiltInRules)	\
    ( (This)->lpVtbl -> put_CodeAnalysisIgnoreBuiltInRules(This,IgnoreBuiltInRules) ) 

#define VBProjectConfigurationProperties5_get_CodeAnalysisFailOnMissingRules(This,pbFailOnMissingRules)	\
    ( (This)->lpVtbl -> get_CodeAnalysisFailOnMissingRules(This,pbFailOnMissingRules) ) 

#define VBProjectConfigurationProperties5_put_CodeAnalysisFailOnMissingRules(This,FailOnMissingRules)	\
    ( (This)->lpVtbl -> put_CodeAnalysisFailOnMissingRules(This,FailOnMissingRules) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __VBProjectConfigurationProperties5_INTERFACE_DEFINED__ */


#ifndef __CSharpProjectProperties6_INTERFACE_DEFINED__
#define __CSharpProjectProperties6_INTERFACE_DEFINED__

/* interface CSharpProjectProperties6 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_CSharpProjectProperties6;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("531d3661-c9ce-4618-bdb4-466a4e4072c9")
    CSharpProjectProperties6 : public CSharpProjectProperties4
    {
    public:
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_TargetFrameworkMoniker( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrTargetFrameworkMoniker) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propput] */ HRESULT STDMETHODCALLTYPE put_TargetFrameworkMoniker( 
            /* [in] */ __RPC__in BSTR bstrTargetFrameworkMoniker) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct CSharpProjectProperties6Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **ppvObj,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *pctinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **pptinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ __RPC__deref_in_opt signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__out signed long *rgdispid,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ __RPC__in struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ __RPC__out VARIANT *pvarResult,
            /* [out][idldescattr] */ __RPC__out struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *puArgErr,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___project )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt IUnknown **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartupObject )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartupObject )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOutputType *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOutputType noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RootNamespace )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RootNamespace )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFile )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFile )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyContainerName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyContainerName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyMode )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOriginatorKeyMode *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyMode )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOriginatorKeyMode noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DelaySign )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DelaySign )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServer )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServerVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ServerExtensionsVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinkRepair )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinkRepair )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OfflineURL )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileSharePath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileSharePath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveFileSharePath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebAccessMethod )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjWebAccessMethod *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WebAccessMethod )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjWebAccessMethod noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWebAccessMethod )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjWebAccessMethod *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultClientScript )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjScriptLanguage *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultClientScript )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjScriptLanguage noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTargetSchema )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjTargetSchema *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTargetSchema )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjTargetSchema noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHTMLPageLayout )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjHTMLPageLayout *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHTMLPageLayout )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjHTMLPageLayout noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveConfigurationSettings )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt ProjectConfigurationProperties **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR ExtenderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationIcon )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationIcon )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionStrict )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOptionStrict *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionStrict )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOptionStrict noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ReferencePath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ReferencePath )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AbsoluteProjectDirectory )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionExplicit )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjOptionExplicit *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionExplicit )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjOptionExplicit noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionCompare )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjCompare *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionCompare )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjCompare noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjProjectType *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultNamespace )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultNamespace )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PreBuildEvent )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PreBuildEvent )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PostBuildEvent )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PostBuildEvent )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RunPostBuildEvent )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjRunPostBuildEvent *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RunPostBuildEvent )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjRunPostBuildEvent noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AspnetVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Product )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Product )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Copyright )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Trademark )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Trademark )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out enum prjAssemblyType *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ enum prjAssemblyType noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TypeComplianceDiagnostics )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TypeComplianceDiagnostics )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Win32ResourceFile )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Win32ResourceFile )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyProviderName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyProviderName )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFileType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFileType )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyFileVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyFileVersion )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_GenerateManifests )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_GenerateManifests )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSecurityDebugging )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSecurityDebugging )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSecurityZoneURL )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSecurityZoneURL )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Publish )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ComVisible )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ComVisible )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyGuid )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyGuid )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NeutralResourcesLanguage )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NeutralResourcesLanguage )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SignAssembly )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SignAssembly )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SignManifests )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SignManifests )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TargetZone )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TargetZone )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExcludedPermissions )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ExcludedPermissions )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestCertificateThumbprint )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ManifestCertificateThumbprint )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestKeyFile )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ManifestKeyFile )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ManifestTimestampUrl )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ManifestTimestampUrl )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TargetFramework )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TargetFramework )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationManifest )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationManifest )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetFrameworkMoniker )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrTargetFrameworkMoniker);
        
        /* [helpstring][id][nonbrowsable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TargetFrameworkMoniker )( 
            __RPC__in CSharpProjectProperties6 * This,
            /* [in] */ __RPC__in BSTR bstrTargetFrameworkMoniker);
        
        END_INTERFACE
    } CSharpProjectProperties6Vtbl;

    interface CSharpProjectProperties6
    {
        CONST_VTBL struct CSharpProjectProperties6Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CSharpProjectProperties6_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define CSharpProjectProperties6_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define CSharpProjectProperties6_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define CSharpProjectProperties6_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define CSharpProjectProperties6_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define CSharpProjectProperties6_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define CSharpProjectProperties6_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define CSharpProjectProperties6_get___id(This,retval)	\
    ( (This)->lpVtbl -> get___id(This,retval) ) 

#define CSharpProjectProperties6_get___project(This,retval)	\
    ( (This)->lpVtbl -> get___project(This,retval) ) 

#define CSharpProjectProperties6_get_StartupObject(This,retval)	\
    ( (This)->lpVtbl -> get_StartupObject(This,retval) ) 

#define CSharpProjectProperties6_put_StartupObject(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartupObject(This,noname,retval) ) 

#define CSharpProjectProperties6_get_OutputType(This,retval)	\
    ( (This)->lpVtbl -> get_OutputType(This,retval) ) 

#define CSharpProjectProperties6_put_OutputType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OutputType(This,noname,retval) ) 

#define CSharpProjectProperties6_get_RootNamespace(This,retval)	\
    ( (This)->lpVtbl -> get_RootNamespace(This,retval) ) 

#define CSharpProjectProperties6_put_RootNamespace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RootNamespace(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyName(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyName(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyName(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyOriginatorKeyFile(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyOriginatorKeyFile(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyOriginatorKeyFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyOriginatorKeyFile(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyKeyContainerName(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyKeyContainerName(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyKeyContainerName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyKeyContainerName(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyOriginatorKeyMode(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyOriginatorKeyMode(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyOriginatorKeyMode(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyOriginatorKeyMode(This,noname,retval) ) 

#define CSharpProjectProperties6_get_DelaySign(This,retval)	\
    ( (This)->lpVtbl -> get_DelaySign(This,retval) ) 

#define CSharpProjectProperties6_put_DelaySign(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DelaySign(This,noname,retval) ) 

#define CSharpProjectProperties6_get_WebServer(This,retval)	\
    ( (This)->lpVtbl -> get_WebServer(This,retval) ) 

#define CSharpProjectProperties6_get_WebServerVersion(This,retval)	\
    ( (This)->lpVtbl -> get_WebServerVersion(This,retval) ) 

#define CSharpProjectProperties6_get_ServerExtensionsVersion(This,retval)	\
    ( (This)->lpVtbl -> get_ServerExtensionsVersion(This,retval) ) 

#define CSharpProjectProperties6_get_LinkRepair(This,retval)	\
    ( (This)->lpVtbl -> get_LinkRepair(This,retval) ) 

#define CSharpProjectProperties6_put_LinkRepair(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LinkRepair(This,noname,retval) ) 

#define CSharpProjectProperties6_get_OfflineURL(This,retval)	\
    ( (This)->lpVtbl -> get_OfflineURL(This,retval) ) 

#define CSharpProjectProperties6_get_FileSharePath(This,retval)	\
    ( (This)->lpVtbl -> get_FileSharePath(This,retval) ) 

#define CSharpProjectProperties6_put_FileSharePath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_FileSharePath(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ActiveFileSharePath(This,retval)	\
    ( (This)->lpVtbl -> get_ActiveFileSharePath(This,retval) ) 

#define CSharpProjectProperties6_get_WebAccessMethod(This,retval)	\
    ( (This)->lpVtbl -> get_WebAccessMethod(This,retval) ) 

#define CSharpProjectProperties6_put_WebAccessMethod(This,noname,retval)	\
    ( (This)->lpVtbl -> put_WebAccessMethod(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ActiveWebAccessMethod(This,retval)	\
    ( (This)->lpVtbl -> get_ActiveWebAccessMethod(This,retval) ) 

#define CSharpProjectProperties6_get_DefaultClientScript(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultClientScript(This,retval) ) 

#define CSharpProjectProperties6_put_DefaultClientScript(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultClientScript(This,noname,retval) ) 

#define CSharpProjectProperties6_get_DefaultTargetSchema(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultTargetSchema(This,retval) ) 

#define CSharpProjectProperties6_put_DefaultTargetSchema(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultTargetSchema(This,noname,retval) ) 

#define CSharpProjectProperties6_get_DefaultHTMLPageLayout(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultHTMLPageLayout(This,retval) ) 

#define CSharpProjectProperties6_put_DefaultHTMLPageLayout(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultHTMLPageLayout(This,noname,retval) ) 

#define CSharpProjectProperties6_get_FileName(This,retval)	\
    ( (This)->lpVtbl -> get_FileName(This,retval) ) 

#define CSharpProjectProperties6_put_FileName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_FileName(This,noname,retval) ) 

#define CSharpProjectProperties6_get_FullPath(This,retval)	\
    ( (This)->lpVtbl -> get_FullPath(This,retval) ) 

#define CSharpProjectProperties6_get_LocalPath(This,retval)	\
    ( (This)->lpVtbl -> get_LocalPath(This,retval) ) 

#define CSharpProjectProperties6_get_URL(This,retval)	\
    ( (This)->lpVtbl -> get_URL(This,retval) ) 

#define CSharpProjectProperties6_get_ActiveConfigurationSettings(This,retval)	\
    ( (This)->lpVtbl -> get_ActiveConfigurationSettings(This,retval) ) 

#define CSharpProjectProperties6_get_Extender(This,ExtenderName,retval)	\
    ( (This)->lpVtbl -> get_Extender(This,ExtenderName,retval) ) 

#define CSharpProjectProperties6_get_ExtenderNames(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderNames(This,retval) ) 

#define CSharpProjectProperties6_get_ExtenderCATID(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderCATID(This,retval) ) 

#define CSharpProjectProperties6_get_ApplicationIcon(This,retval)	\
    ( (This)->lpVtbl -> get_ApplicationIcon(This,retval) ) 

#define CSharpProjectProperties6_put_ApplicationIcon(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ApplicationIcon(This,noname,retval) ) 

#define CSharpProjectProperties6_get_OptionStrict(This,retval)	\
    ( (This)->lpVtbl -> get_OptionStrict(This,retval) ) 

#define CSharpProjectProperties6_put_OptionStrict(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionStrict(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ReferencePath(This,retval)	\
    ( (This)->lpVtbl -> get_ReferencePath(This,retval) ) 

#define CSharpProjectProperties6_put_ReferencePath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ReferencePath(This,noname,retval) ) 

#define CSharpProjectProperties6_get_OutputFileName(This,retval)	\
    ( (This)->lpVtbl -> get_OutputFileName(This,retval) ) 

#define CSharpProjectProperties6_get_AbsoluteProjectDirectory(This,retval)	\
    ( (This)->lpVtbl -> get_AbsoluteProjectDirectory(This,retval) ) 

#define CSharpProjectProperties6_get_OptionExplicit(This,retval)	\
    ( (This)->lpVtbl -> get_OptionExplicit(This,retval) ) 

#define CSharpProjectProperties6_put_OptionExplicit(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionExplicit(This,noname,retval) ) 

#define CSharpProjectProperties6_get_OptionCompare(This,retval)	\
    ( (This)->lpVtbl -> get_OptionCompare(This,retval) ) 

#define CSharpProjectProperties6_put_OptionCompare(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OptionCompare(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ProjectType(This,retval)	\
    ( (This)->lpVtbl -> get_ProjectType(This,retval) ) 

#define CSharpProjectProperties6_get_DefaultNamespace(This,retval)	\
    ( (This)->lpVtbl -> get_DefaultNamespace(This,retval) ) 

#define CSharpProjectProperties6_put_DefaultNamespace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefaultNamespace(This,noname,retval) ) 

#define CSharpProjectProperties6_get_PreBuildEvent(This,retval)	\
    ( (This)->lpVtbl -> get_PreBuildEvent(This,retval) ) 

#define CSharpProjectProperties6_put_PreBuildEvent(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PreBuildEvent(This,noname,retval) ) 

#define CSharpProjectProperties6_get_PostBuildEvent(This,retval)	\
    ( (This)->lpVtbl -> get_PostBuildEvent(This,retval) ) 

#define CSharpProjectProperties6_put_PostBuildEvent(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PostBuildEvent(This,noname,retval) ) 

#define CSharpProjectProperties6_get_RunPostBuildEvent(This,retval)	\
    ( (This)->lpVtbl -> get_RunPostBuildEvent(This,retval) ) 

#define CSharpProjectProperties6_put_RunPostBuildEvent(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RunPostBuildEvent(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AspnetVersion(This,retval)	\
    ( (This)->lpVtbl -> get_AspnetVersion(This,retval) ) 

#define CSharpProjectProperties6_get_Title(This,retval)	\
    ( (This)->lpVtbl -> get_Title(This,retval) ) 

#define CSharpProjectProperties6_put_Title(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Title(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Description(This,retval)	\
    ( (This)->lpVtbl -> get_Description(This,retval) ) 

#define CSharpProjectProperties6_put_Description(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Description(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Company(This,retval)	\
    ( (This)->lpVtbl -> get_Company(This,retval) ) 

#define CSharpProjectProperties6_put_Company(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Company(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Product(This,retval)	\
    ( (This)->lpVtbl -> get_Product(This,retval) ) 

#define CSharpProjectProperties6_put_Product(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Product(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Copyright(This,retval)	\
    ( (This)->lpVtbl -> get_Copyright(This,retval) ) 

#define CSharpProjectProperties6_put_Copyright(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Copyright(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Trademark(This,retval)	\
    ( (This)->lpVtbl -> get_Trademark(This,retval) ) 

#define CSharpProjectProperties6_put_Trademark(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Trademark(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyType(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyType(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyType(This,noname,retval) ) 

#define CSharpProjectProperties6_get_TypeComplianceDiagnostics(This,retval)	\
    ( (This)->lpVtbl -> get_TypeComplianceDiagnostics(This,retval) ) 

#define CSharpProjectProperties6_put_TypeComplianceDiagnostics(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TypeComplianceDiagnostics(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Win32ResourceFile(This,retval)	\
    ( (This)->lpVtbl -> get_Win32ResourceFile(This,retval) ) 

#define CSharpProjectProperties6_put_Win32ResourceFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Win32ResourceFile(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyKeyProviderName(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyKeyProviderName(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyKeyProviderName(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyKeyProviderName(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyOriginatorKeyFileType(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyOriginatorKeyFileType(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyOriginatorKeyFileType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyOriginatorKeyFileType(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyVersion(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyVersion(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyVersion(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyVersion(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyFileVersion(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyFileVersion(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyFileVersion(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyFileVersion(This,noname,retval) ) 

#define CSharpProjectProperties6_get_GenerateManifests(This,retval)	\
    ( (This)->lpVtbl -> get_GenerateManifests(This,retval) ) 

#define CSharpProjectProperties6_put_GenerateManifests(This,noname,retval)	\
    ( (This)->lpVtbl -> put_GenerateManifests(This,noname,retval) ) 

#define CSharpProjectProperties6_get_EnableSecurityDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableSecurityDebugging(This,retval) ) 

#define CSharpProjectProperties6_put_EnableSecurityDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableSecurityDebugging(This,noname,retval) ) 

#define CSharpProjectProperties6_get_DebugSecurityZoneURL(This,retval)	\
    ( (This)->lpVtbl -> get_DebugSecurityZoneURL(This,retval) ) 

#define CSharpProjectProperties6_put_DebugSecurityZoneURL(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DebugSecurityZoneURL(This,noname,retval) ) 

#define CSharpProjectProperties6_get_Publish(This,retval)	\
    ( (This)->lpVtbl -> get_Publish(This,retval) ) 

#define CSharpProjectProperties6_get_ComVisible(This,retval)	\
    ( (This)->lpVtbl -> get_ComVisible(This,retval) ) 

#define CSharpProjectProperties6_put_ComVisible(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ComVisible(This,noname,retval) ) 

#define CSharpProjectProperties6_get_AssemblyGuid(This,retval)	\
    ( (This)->lpVtbl -> get_AssemblyGuid(This,retval) ) 

#define CSharpProjectProperties6_put_AssemblyGuid(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AssemblyGuid(This,noname,retval) ) 

#define CSharpProjectProperties6_get_NeutralResourcesLanguage(This,retval)	\
    ( (This)->lpVtbl -> get_NeutralResourcesLanguage(This,retval) ) 

#define CSharpProjectProperties6_put_NeutralResourcesLanguage(This,noname,retval)	\
    ( (This)->lpVtbl -> put_NeutralResourcesLanguage(This,noname,retval) ) 

#define CSharpProjectProperties6_get_SignAssembly(This,retval)	\
    ( (This)->lpVtbl -> get_SignAssembly(This,retval) ) 

#define CSharpProjectProperties6_put_SignAssembly(This,noname,retval)	\
    ( (This)->lpVtbl -> put_SignAssembly(This,noname,retval) ) 

#define CSharpProjectProperties6_get_SignManifests(This,retval)	\
    ( (This)->lpVtbl -> get_SignManifests(This,retval) ) 

#define CSharpProjectProperties6_put_SignManifests(This,noname,retval)	\
    ( (This)->lpVtbl -> put_SignManifests(This,noname,retval) ) 

#define CSharpProjectProperties6_get_TargetZone(This,retval)	\
    ( (This)->lpVtbl -> get_TargetZone(This,retval) ) 

#define CSharpProjectProperties6_put_TargetZone(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TargetZone(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ExcludedPermissions(This,retval)	\
    ( (This)->lpVtbl -> get_ExcludedPermissions(This,retval) ) 

#define CSharpProjectProperties6_put_ExcludedPermissions(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ExcludedPermissions(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ManifestCertificateThumbprint(This,retval)	\
    ( (This)->lpVtbl -> get_ManifestCertificateThumbprint(This,retval) ) 

#define CSharpProjectProperties6_put_ManifestCertificateThumbprint(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ManifestCertificateThumbprint(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ManifestKeyFile(This,retval)	\
    ( (This)->lpVtbl -> get_ManifestKeyFile(This,retval) ) 

#define CSharpProjectProperties6_put_ManifestKeyFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ManifestKeyFile(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ManifestTimestampUrl(This,retval)	\
    ( (This)->lpVtbl -> get_ManifestTimestampUrl(This,retval) ) 

#define CSharpProjectProperties6_put_ManifestTimestampUrl(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ManifestTimestampUrl(This,noname,retval) ) 

#define CSharpProjectProperties6_get_TargetFramework(This,retval)	\
    ( (This)->lpVtbl -> get_TargetFramework(This,retval) ) 

#define CSharpProjectProperties6_put_TargetFramework(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TargetFramework(This,noname,retval) ) 

#define CSharpProjectProperties6_get_ApplicationManifest(This,retval)	\
    ( (This)->lpVtbl -> get_ApplicationManifest(This,retval) ) 

#define CSharpProjectProperties6_put_ApplicationManifest(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ApplicationManifest(This,noname,retval) ) 


#define CSharpProjectProperties6_get_TargetFrameworkMoniker(This,pbstrTargetFrameworkMoniker)	\
    ( (This)->lpVtbl -> get_TargetFrameworkMoniker(This,pbstrTargetFrameworkMoniker) ) 

#define CSharpProjectProperties6_put_TargetFrameworkMoniker(This,bstrTargetFrameworkMoniker)	\
    ( (This)->lpVtbl -> put_TargetFrameworkMoniker(This,bstrTargetFrameworkMoniker) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE CSharpProjectProperties6_get_TargetFrameworkMoniker_Proxy( 
    __RPC__in CSharpProjectProperties6 * This,
    /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrTargetFrameworkMoniker);


void __RPC_STUB CSharpProjectProperties6_get_TargetFrameworkMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][nonbrowsable][propput] */ HRESULT STDMETHODCALLTYPE CSharpProjectProperties6_put_TargetFrameworkMoniker_Proxy( 
    __RPC__in CSharpProjectProperties6 * This,
    /* [in] */ __RPC__in BSTR bstrTargetFrameworkMoniker);


void __RPC_STUB CSharpProjectProperties6_put_TargetFrameworkMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __CSharpProjectProperties6_INTERFACE_DEFINED__ */


#ifndef __CSharpProjectConfigurationProperties5_INTERFACE_DEFINED__
#define __CSharpProjectConfigurationProperties5_INTERFACE_DEFINED__

/* interface CSharpProjectConfigurationProperties5 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_CSharpProjectConfigurationProperties5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c379af13-6c05-4a91-a3bf-4c61999174b4")
    CSharpProjectConfigurationProperties5 : public CSharpProjectConfigurationProperties4
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisRuleSet( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSet) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisRuleSet( 
            /* [in] */ __RPC__in BSTR bstrRuleSet) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisRuleSetDirectories( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSetDirectories) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisRuleSetDirectories( 
            /* [in] */ __RPC__in BSTR bstrRuleSetDirectories) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisIgnoreBuiltInRuleSets( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRuleSets) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisIgnoreBuiltInRuleSets( 
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRuleSets) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisRuleDirectories( 
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleDirectories) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisRuleDirectories( 
            /* [in] */ __RPC__in BSTR bstrRuleDirectories) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisIgnoreBuiltInRules( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRules) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisIgnoreBuiltInRules( 
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRules) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodeAnalysisFailOnMissingRules( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbFailOnMissingRules) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodeAnalysisFailOnMissingRules( 
            /* [in] */ VARIANT_BOOL FailOnMissingRules) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct CSharpProjectConfigurationProperties5Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **ppvObj,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *pctinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **pptinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ __RPC__deref_in_opt signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__out signed long *rgdispid,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ __RPC__in struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ __RPC__out VARIANT *pvarResult,
            /* [out][idldescattr] */ __RPC__out struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *puArgErr,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSymbols )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSymbols )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineDebug )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineDebug )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineTrace )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineTrace )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPath )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPath )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IntermediatePath )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IntermediatePath )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineConstants )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineConstants )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveIntegerChecks )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveIntegerChecks )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BaseAddress )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_BaseAddress )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AllowUnsafeBlocks )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AllowUnsafeBlocks )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CheckForOverflowUnderflow )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CheckForOverflowUnderflow )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentationFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentationFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Optimize )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Optimize )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalBuild )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalBuild )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartProgram )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartProgram )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWorkingDirectory )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWorkingDirectory )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartURL )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartURL )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartPage )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartPage )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartArguments )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartArguments )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithIE )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithIE )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPXDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPXDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableUnmanagedDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableUnmanagedDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartAction )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out enum prjStartAction *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartAction )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ enum prjStartAction noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR ExtenderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WarningLevel )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out enum prjWarningLevel *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WarningLevel )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ enum prjWarningLevel noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatWarningsAsErrors )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatWarningsAsErrors )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSQLServerDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSQLServerDebugging )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileAlignment )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileAlignment )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterForComInterop )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterForComInterop )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigurationOverrideFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ConfigurationOverrideFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugEnabled )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugEnabled )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugMachine )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugMachine )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoWarn )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoWarn )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoStdLib )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoStdLib )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugInfo )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugInfo )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformTarget )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PlatformTarget )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSpecificWarningsAsErrors )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSpecificWarningsAsErrors )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RunCodeAnalysis )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RunCodeAnalysis )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisLogFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisLogFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleAssemblies )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleAssemblies )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisInputAssembly )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisInputAssembly )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRules )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRules )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisSpellCheckLanguages )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisSpellCheckLanguages )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisUseTypeNameInSuppression )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisUseTypeNameInSuppression )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisModuleSuppressionsFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisModuleSuppressionsFile )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_UseVSHostingProcess )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_UseVSHostingProcess )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_GenerateSerializationAssemblies )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out enum sgenGenerationOption *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_GenerateSerializationAssemblies )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ enum sgenGenerationOption noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageVersion )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LanguageVersion )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorReport )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ErrorReport )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisIgnoreGeneratedCode )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisIgnoreGeneratedCode )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisOverrideRuleVisibilities )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisOverrideRuleVisibilities )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisDictionaries )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisDictionaries )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisCulture )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisCulture )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleSet )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSet);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleSet )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in] */ __RPC__in BSTR bstrRuleSet);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleSetDirectories )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleSetDirectories);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleSetDirectories )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in] */ __RPC__in BSTR bstrRuleSetDirectories);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisIgnoreBuiltInRuleSets )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRuleSets);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisIgnoreBuiltInRuleSets )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRuleSets);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisRuleDirectories )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *pbstrRuleDirectories);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisRuleDirectories )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in] */ __RPC__in BSTR bstrRuleDirectories);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisIgnoreBuiltInRules )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbIgnoreBuiltInRules);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisIgnoreBuiltInRules )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in] */ VARIANT_BOOL IgnoreBuiltInRules);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodeAnalysisFailOnMissingRules )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbFailOnMissingRules);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodeAnalysisFailOnMissingRules )( 
            __RPC__in CSharpProjectConfigurationProperties5 * This,
            /* [in] */ VARIANT_BOOL FailOnMissingRules);
        
        END_INTERFACE
    } CSharpProjectConfigurationProperties5Vtbl;

    interface CSharpProjectConfigurationProperties5
    {
        CONST_VTBL struct CSharpProjectConfigurationProperties5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CSharpProjectConfigurationProperties5_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define CSharpProjectConfigurationProperties5_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define CSharpProjectConfigurationProperties5_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define CSharpProjectConfigurationProperties5_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define CSharpProjectConfigurationProperties5_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define CSharpProjectConfigurationProperties5_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define CSharpProjectConfigurationProperties5_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define CSharpProjectConfigurationProperties5_get___id(This,retval)	\
    ( (This)->lpVtbl -> get___id(This,retval) ) 

#define CSharpProjectConfigurationProperties5_get_DebugSymbols(This,retval)	\
    ( (This)->lpVtbl -> get_DebugSymbols(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_DebugSymbols(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DebugSymbols(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_DefineDebug(This,retval)	\
    ( (This)->lpVtbl -> get_DefineDebug(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_DefineDebug(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefineDebug(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_DefineTrace(This,retval)	\
    ( (This)->lpVtbl -> get_DefineTrace(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_DefineTrace(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefineTrace(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_OutputPath(This,retval)	\
    ( (This)->lpVtbl -> get_OutputPath(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_OutputPath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_OutputPath(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_IntermediatePath(This,retval)	\
    ( (This)->lpVtbl -> get_IntermediatePath(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_IntermediatePath(This,noname,retval)	\
    ( (This)->lpVtbl -> put_IntermediatePath(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_DefineConstants(This,retval)	\
    ( (This)->lpVtbl -> get_DefineConstants(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_DefineConstants(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DefineConstants(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_RemoveIntegerChecks(This,retval)	\
    ( (This)->lpVtbl -> get_RemoveIntegerChecks(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_RemoveIntegerChecks(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RemoveIntegerChecks(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_BaseAddress(This,retval)	\
    ( (This)->lpVtbl -> get_BaseAddress(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_BaseAddress(This,noname,retval)	\
    ( (This)->lpVtbl -> put_BaseAddress(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_AllowUnsafeBlocks(This,retval)	\
    ( (This)->lpVtbl -> get_AllowUnsafeBlocks(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_AllowUnsafeBlocks(This,noname,retval)	\
    ( (This)->lpVtbl -> put_AllowUnsafeBlocks(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CheckForOverflowUnderflow(This,retval)	\
    ( (This)->lpVtbl -> get_CheckForOverflowUnderflow(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CheckForOverflowUnderflow(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CheckForOverflowUnderflow(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_DocumentationFile(This,retval)	\
    ( (This)->lpVtbl -> get_DocumentationFile(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_DocumentationFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DocumentationFile(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_Optimize(This,retval)	\
    ( (This)->lpVtbl -> get_Optimize(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_Optimize(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Optimize(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_IncrementalBuild(This,retval)	\
    ( (This)->lpVtbl -> get_IncrementalBuild(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_IncrementalBuild(This,noname,retval)	\
    ( (This)->lpVtbl -> put_IncrementalBuild(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartProgram(This,retval)	\
    ( (This)->lpVtbl -> get_StartProgram(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartProgram(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartProgram(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartWorkingDirectory(This,retval)	\
    ( (This)->lpVtbl -> get_StartWorkingDirectory(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartWorkingDirectory(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartWorkingDirectory(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartURL(This,retval)	\
    ( (This)->lpVtbl -> get_StartURL(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartURL(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartURL(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartPage(This,retval)	\
    ( (This)->lpVtbl -> get_StartPage(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartPage(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartPage(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartArguments(This,retval)	\
    ( (This)->lpVtbl -> get_StartArguments(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartArguments(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartArguments(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartWithIE(This,retval)	\
    ( (This)->lpVtbl -> get_StartWithIE(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartWithIE(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartWithIE(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_EnableASPDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableASPDebugging(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_EnableASPDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableASPDebugging(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_EnableASPXDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableASPXDebugging(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_EnableASPXDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableASPXDebugging(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_EnableUnmanagedDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableUnmanagedDebugging(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_EnableUnmanagedDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableUnmanagedDebugging(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_StartAction(This,retval)	\
    ( (This)->lpVtbl -> get_StartAction(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_StartAction(This,noname,retval)	\
    ( (This)->lpVtbl -> put_StartAction(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_Extender(This,ExtenderName,retval)	\
    ( (This)->lpVtbl -> get_Extender(This,ExtenderName,retval) ) 

#define CSharpProjectConfigurationProperties5_get_ExtenderNames(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderNames(This,retval) ) 

#define CSharpProjectConfigurationProperties5_get_ExtenderCATID(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderCATID(This,retval) ) 

#define CSharpProjectConfigurationProperties5_get_WarningLevel(This,retval)	\
    ( (This)->lpVtbl -> get_WarningLevel(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_WarningLevel(This,noname,retval)	\
    ( (This)->lpVtbl -> put_WarningLevel(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_TreatWarningsAsErrors(This,retval)	\
    ( (This)->lpVtbl -> get_TreatWarningsAsErrors(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_TreatWarningsAsErrors(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TreatWarningsAsErrors(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_EnableSQLServerDebugging(This,retval)	\
    ( (This)->lpVtbl -> get_EnableSQLServerDebugging(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_EnableSQLServerDebugging(This,noname,retval)	\
    ( (This)->lpVtbl -> put_EnableSQLServerDebugging(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_FileAlignment(This,retval)	\
    ( (This)->lpVtbl -> get_FileAlignment(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_FileAlignment(This,noname,retval)	\
    ( (This)->lpVtbl -> put_FileAlignment(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_RegisterForComInterop(This,retval)	\
    ( (This)->lpVtbl -> get_RegisterForComInterop(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_RegisterForComInterop(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RegisterForComInterop(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_ConfigurationOverrideFile(This,retval)	\
    ( (This)->lpVtbl -> get_ConfigurationOverrideFile(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_ConfigurationOverrideFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ConfigurationOverrideFile(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_RemoteDebugEnabled(This,retval)	\
    ( (This)->lpVtbl -> get_RemoteDebugEnabled(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_RemoteDebugEnabled(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RemoteDebugEnabled(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_RemoteDebugMachine(This,retval)	\
    ( (This)->lpVtbl -> get_RemoteDebugMachine(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_RemoteDebugMachine(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RemoteDebugMachine(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_NoWarn(This,retval)	\
    ( (This)->lpVtbl -> get_NoWarn(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_NoWarn(This,noname,retval)	\
    ( (This)->lpVtbl -> put_NoWarn(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_NoStdLib(This,retval)	\
    ( (This)->lpVtbl -> get_NoStdLib(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_NoStdLib(This,noname,retval)	\
    ( (This)->lpVtbl -> put_NoStdLib(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_DebugInfo(This,retval)	\
    ( (This)->lpVtbl -> get_DebugInfo(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_DebugInfo(This,noname,retval)	\
    ( (This)->lpVtbl -> put_DebugInfo(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_PlatformTarget(This,retval)	\
    ( (This)->lpVtbl -> get_PlatformTarget(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_PlatformTarget(This,noname,retval)	\
    ( (This)->lpVtbl -> put_PlatformTarget(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_TreatSpecificWarningsAsErrors(This,retval)	\
    ( (This)->lpVtbl -> get_TreatSpecificWarningsAsErrors(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_TreatSpecificWarningsAsErrors(This,noname,retval)	\
    ( (This)->lpVtbl -> put_TreatSpecificWarningsAsErrors(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_RunCodeAnalysis(This,retval)	\
    ( (This)->lpVtbl -> get_RunCodeAnalysis(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_RunCodeAnalysis(This,noname,retval)	\
    ( (This)->lpVtbl -> put_RunCodeAnalysis(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisLogFile(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisLogFile(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisLogFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisLogFile(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisRuleAssemblies(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleAssemblies(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisRuleAssemblies(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleAssemblies(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisInputAssembly(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisInputAssembly(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisInputAssembly(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisInputAssembly(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisRules(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRules(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisRules(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRules(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisSpellCheckLanguages(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisSpellCheckLanguages(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisSpellCheckLanguages(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisSpellCheckLanguages(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisUseTypeNameInSuppression(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisUseTypeNameInSuppression(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisUseTypeNameInSuppression(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisUseTypeNameInSuppression(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisModuleSuppressionsFile(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisModuleSuppressionsFile(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisModuleSuppressionsFile(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisModuleSuppressionsFile(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_UseVSHostingProcess(This,retval)	\
    ( (This)->lpVtbl -> get_UseVSHostingProcess(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_UseVSHostingProcess(This,noname,retval)	\
    ( (This)->lpVtbl -> put_UseVSHostingProcess(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_GenerateSerializationAssemblies(This,retval)	\
    ( (This)->lpVtbl -> get_GenerateSerializationAssemblies(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_GenerateSerializationAssemblies(This,noname,retval)	\
    ( (This)->lpVtbl -> put_GenerateSerializationAssemblies(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_LanguageVersion(This,retval)	\
    ( (This)->lpVtbl -> get_LanguageVersion(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_LanguageVersion(This,noname,retval)	\
    ( (This)->lpVtbl -> put_LanguageVersion(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_ErrorReport(This,retval)	\
    ( (This)->lpVtbl -> get_ErrorReport(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_ErrorReport(This,noname,retval)	\
    ( (This)->lpVtbl -> put_ErrorReport(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisIgnoreGeneratedCode(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisIgnoreGeneratedCode(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisIgnoreGeneratedCode(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisIgnoreGeneratedCode(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisOverrideRuleVisibilities(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisOverrideRuleVisibilities(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisOverrideRuleVisibilities(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisOverrideRuleVisibilities(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisDictionaries(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisDictionaries(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisDictionaries(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisDictionaries(This,noname,retval) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisCulture(This,retval)	\
    ( (This)->lpVtbl -> get_CodeAnalysisCulture(This,retval) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisCulture(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CodeAnalysisCulture(This,noname,retval) ) 


#define CSharpProjectConfigurationProperties5_get_CodeAnalysisRuleSet(This,pbstrRuleSet)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleSet(This,pbstrRuleSet) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisRuleSet(This,bstrRuleSet)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleSet(This,bstrRuleSet) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisRuleSetDirectories(This,pbstrRuleSetDirectories)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleSetDirectories(This,pbstrRuleSetDirectories) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisRuleSetDirectories(This,bstrRuleSetDirectories)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleSetDirectories(This,bstrRuleSetDirectories) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisIgnoreBuiltInRuleSets(This,pbIgnoreBuiltInRuleSets)	\
    ( (This)->lpVtbl -> get_CodeAnalysisIgnoreBuiltInRuleSets(This,pbIgnoreBuiltInRuleSets) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisIgnoreBuiltInRuleSets(This,IgnoreBuiltInRuleSets)	\
    ( (This)->lpVtbl -> put_CodeAnalysisIgnoreBuiltInRuleSets(This,IgnoreBuiltInRuleSets) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisRuleDirectories(This,pbstrRuleDirectories)	\
    ( (This)->lpVtbl -> get_CodeAnalysisRuleDirectories(This,pbstrRuleDirectories) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisRuleDirectories(This,bstrRuleDirectories)	\
    ( (This)->lpVtbl -> put_CodeAnalysisRuleDirectories(This,bstrRuleDirectories) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisIgnoreBuiltInRules(This,pbIgnoreBuiltInRules)	\
    ( (This)->lpVtbl -> get_CodeAnalysisIgnoreBuiltInRules(This,pbIgnoreBuiltInRules) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisIgnoreBuiltInRules(This,IgnoreBuiltInRules)	\
    ( (This)->lpVtbl -> put_CodeAnalysisIgnoreBuiltInRules(This,IgnoreBuiltInRules) ) 

#define CSharpProjectConfigurationProperties5_get_CodeAnalysisFailOnMissingRules(This,pbFailOnMissingRules)	\
    ( (This)->lpVtbl -> get_CodeAnalysisFailOnMissingRules(This,pbFailOnMissingRules) ) 

#define CSharpProjectConfigurationProperties5_put_CodeAnalysisFailOnMissingRules(This,FailOnMissingRules)	\
    ( (This)->lpVtbl -> put_CodeAnalysisFailOnMissingRules(This,FailOnMissingRules) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __CSharpProjectConfigurationProperties5_INTERFACE_DEFINED__ */


#ifndef __Reference4_INTERFACE_DEFINED__
#define __Reference4_INTERFACE_DEFINED__

/* interface Reference4 */
/* [uuid][object][oleautomation][dual] */ 


EXTERN_C const IID IID_Reference4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f71b6036-80f1-4f08-bc59-b5d92865f629")
    Reference4 : public Reference3
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EmbedInteropTypes( 
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbEmbedInteropTypes) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EmbedInteropTypes( 
            /* [in] */ VARIANT_BOOL bEmbedInteropTypes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct Reference4Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **ppvObj,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            __RPC__in Reference4 * This,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *pctinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__deref_out_opt void **pptinfo,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ __RPC__deref_in_opt signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ __RPC__out signed long *rgdispid,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ __RPC__in struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ __RPC__in struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ __RPC__out VARIANT *pvarResult,
            /* [out][idldescattr] */ __RPC__out struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ __RPC__out unsigned UINT *puArgErr,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DTE )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Collection )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt References **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ContainingProject )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt Project **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out enum prjReferenceType *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Identity )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Culture )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_MajorVersion )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_MinorVersion )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RevisionNumber )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BuildNumber )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StrongName )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SourceProject )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt Project **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CopyLocal )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CopyLocal )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ __RPC__in BSTR ExtenderName,
            /* [retval][out] */ __RPC__deref_out_opt IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PublicKeyToken )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RuntimeVersion )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SpecificVersion )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SpecificVersion )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SubType )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SubType )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Isolated )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Isolated )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Aliases )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__deref_out_opt BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Aliases )( 
            __RPC__in Reference4 * This,
            /* [in][idldescattr] */ __RPC__in BSTR noname,
            /* [retval][out] */ __RPC__out void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RefType )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out unsigned long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AutoReferenced )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Resolved )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out BOOLEAN *retval);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EmbedInteropTypes )( 
            __RPC__in Reference4 * This,
            /* [retval][out] */ __RPC__out VARIANT_BOOL *pbEmbedInteropTypes);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EmbedInteropTypes )( 
            __RPC__in Reference4 * This,
            /* [in] */ VARIANT_BOOL bEmbedInteropTypes);
        
        END_INTERFACE
    } Reference4Vtbl;

    interface Reference4
    {
        CONST_VTBL struct Reference4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Reference4_QueryInterface(This,riid,ppvObj,retval)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval) ) 

#define Reference4_AddRef(This,retval)	\
    ( (This)->lpVtbl -> AddRef(This,retval) ) 

#define Reference4_Release(This,retval)	\
    ( (This)->lpVtbl -> Release(This,retval) ) 

#define Reference4_GetTypeInfoCount(This,pctinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval) ) 

#define Reference4_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval) ) 

#define Reference4_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval) ) 

#define Reference4_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    ( (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval) ) 

#define Reference4_get_DTE(This,retval)	\
    ( (This)->lpVtbl -> get_DTE(This,retval) ) 

#define Reference4_get_Collection(This,retval)	\
    ( (This)->lpVtbl -> get_Collection(This,retval) ) 

#define Reference4_get_ContainingProject(This,retval)	\
    ( (This)->lpVtbl -> get_ContainingProject(This,retval) ) 

#define Reference4_Remove(This,retval)	\
    ( (This)->lpVtbl -> Remove(This,retval) ) 

#define Reference4_get_Name(This,retval)	\
    ( (This)->lpVtbl -> get_Name(This,retval) ) 

#define Reference4_get_Type(This,retval)	\
    ( (This)->lpVtbl -> get_Type(This,retval) ) 

#define Reference4_get_Identity(This,retval)	\
    ( (This)->lpVtbl -> get_Identity(This,retval) ) 

#define Reference4_get_Path(This,retval)	\
    ( (This)->lpVtbl -> get_Path(This,retval) ) 

#define Reference4_get_Description(This,retval)	\
    ( (This)->lpVtbl -> get_Description(This,retval) ) 

#define Reference4_get_Culture(This,retval)	\
    ( (This)->lpVtbl -> get_Culture(This,retval) ) 

#define Reference4_get_MajorVersion(This,retval)	\
    ( (This)->lpVtbl -> get_MajorVersion(This,retval) ) 

#define Reference4_get_MinorVersion(This,retval)	\
    ( (This)->lpVtbl -> get_MinorVersion(This,retval) ) 

#define Reference4_get_RevisionNumber(This,retval)	\
    ( (This)->lpVtbl -> get_RevisionNumber(This,retval) ) 

#define Reference4_get_BuildNumber(This,retval)	\
    ( (This)->lpVtbl -> get_BuildNumber(This,retval) ) 

#define Reference4_get_StrongName(This,retval)	\
    ( (This)->lpVtbl -> get_StrongName(This,retval) ) 

#define Reference4_get_SourceProject(This,retval)	\
    ( (This)->lpVtbl -> get_SourceProject(This,retval) ) 

#define Reference4_get_CopyLocal(This,retval)	\
    ( (This)->lpVtbl -> get_CopyLocal(This,retval) ) 

#define Reference4_put_CopyLocal(This,noname,retval)	\
    ( (This)->lpVtbl -> put_CopyLocal(This,noname,retval) ) 

#define Reference4_get_Extender(This,ExtenderName,retval)	\
    ( (This)->lpVtbl -> get_Extender(This,ExtenderName,retval) ) 

#define Reference4_get_ExtenderNames(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderNames(This,retval) ) 

#define Reference4_get_ExtenderCATID(This,retval)	\
    ( (This)->lpVtbl -> get_ExtenderCATID(This,retval) ) 

#define Reference4_get_PublicKeyToken(This,retval)	\
    ( (This)->lpVtbl -> get_PublicKeyToken(This,retval) ) 

#define Reference4_get_Version(This,retval)	\
    ( (This)->lpVtbl -> get_Version(This,retval) ) 

#define Reference4_get_RuntimeVersion(This,retval)	\
    ( (This)->lpVtbl -> get_RuntimeVersion(This,retval) ) 

#define Reference4_get_SpecificVersion(This,retval)	\
    ( (This)->lpVtbl -> get_SpecificVersion(This,retval) ) 

#define Reference4_put_SpecificVersion(This,noname,retval)	\
    ( (This)->lpVtbl -> put_SpecificVersion(This,noname,retval) ) 

#define Reference4_get_SubType(This,retval)	\
    ( (This)->lpVtbl -> get_SubType(This,retval) ) 

#define Reference4_put_SubType(This,noname,retval)	\
    ( (This)->lpVtbl -> put_SubType(This,noname,retval) ) 

#define Reference4_get_Isolated(This,retval)	\
    ( (This)->lpVtbl -> get_Isolated(This,retval) ) 

#define Reference4_put_Isolated(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Isolated(This,noname,retval) ) 

#define Reference4_get_Aliases(This,retval)	\
    ( (This)->lpVtbl -> get_Aliases(This,retval) ) 

#define Reference4_put_Aliases(This,noname,retval)	\
    ( (This)->lpVtbl -> put_Aliases(This,noname,retval) ) 

#define Reference4_get_RefType(This,retval)	\
    ( (This)->lpVtbl -> get_RefType(This,retval) ) 

#define Reference4_get_AutoReferenced(This,retval)	\
    ( (This)->lpVtbl -> get_AutoReferenced(This,retval) ) 

#define Reference4_get_Resolved(This,retval)	\
    ( (This)->lpVtbl -> get_Resolved(This,retval) ) 


#define Reference4_get_EmbedInteropTypes(This,pbEmbedInteropTypes)	\
    ( (This)->lpVtbl -> get_EmbedInteropTypes(This,pbEmbedInteropTypes) ) 

#define Reference4_put_EmbedInteropTypes(This,bEmbedInteropTypes)	\
    ( (This)->lpVtbl -> put_EmbedInteropTypes(This,bEmbedInteropTypes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __Reference4_INTERFACE_DEFINED__ */

#endif /* __VSLangProj100_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


