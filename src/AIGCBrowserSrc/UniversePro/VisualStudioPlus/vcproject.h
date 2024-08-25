// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1 (c821d89c).
//
// c:\users\孙辉\documents\visual studio 2017\projects\atlproject2\atlproject2\debug\vcprj3.tlh
//
// C++ source equivalent of Win32 type library E:\tangram\vcprj3.tlb
// compiler-generated file created 08/30/17 at 21:25:33 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace VCProjectEngineLibrary {

//
// Forward references and typedefs
//

struct __declspec(uuid("2fa4aaa3-0285-495e-ac12-8239b65791ea"))
/* LIBID */ __VCProjectEngineLibrary;
struct __declspec(uuid("dbecfca1-1a01-42ad-8158-ca1c3c543adc"))
/* interface */ SVCProjectEngine;
struct __declspec(uuid("0fb57085-958b-45f2-bfac-d8b5cd2b57a8"))
/* dual interface */ IVCProjectEngineEvents;
enum enumSccEvent;
struct __declspec(uuid("e3de0769-1e0a-43b7-8d57-1d4241b822b3"))
/* dual interface */ IVCProjectEngineEvents2;
struct __declspec(uuid("8b558010-3d1f-43ea-af3e-46319fd787eb"))
/* dispinterface */ _dispVCProjectEngineEvents;
struct __declspec(uuid("bc11c64a-17bb-4c0d-8e31-e85ac066a120"))
/* dual interface */ _VCProjectEngineEvents;
struct /* coclass */ VCProjectEngineEvents;
struct /* coclass */ VCProjectEngineObject;
struct __declspec(uuid("54969dd8-23d3-4a77-911c-87e6a3c5c21c"))
/* dual interface */ VCProjectEngine;
struct __declspec(uuid("aa47150b-d212-410c-8a4a-3af30e64670e"))
/* dual interface */ VCToolFile;
struct __declspec(uuid("ef0ef512-4ab7-4eec-91d1-9e5e222eed81"))
/* dual interface */ IVCCollection;
struct __declspec(uuid("622c69b7-5541-4612-89bd-3ddc34f061de"))
/* interface */ IVCProjectBuildService;
enum bldActionTypes;
struct __declspec(uuid("7dd2b83e-a53a-443c-b2eb-ec618bb25f82"))
/* interface */ IVCBuildRequest;
struct __declspec(uuid("9b92c18d-a218-4266-bb37-f9d58c17f07b"))
/* interface */ IVCBuildCompleteCallback;
struct __declspec(uuid("e2a1c8ff-6174-49fa-9476-dc188bd947b5"))
/* dual interface */ VCPlatform;
struct __declspec(uuid("60dddab8-1862-477f-8995-bb83fb33fcda"))
/* dual interface */ VCProjectItem;
struct __declspec(uuid("dbf177f2-06db-4a47-8aad-c8e12bfd6c86"))
/* dual interface */ VCProject;
enum enumFileFormat;
enum enumFrameworkVersion;
struct __declspec(uuid("921dd76b-a230-4028-8dae-7fc88a605676"))
/* dual interface */ VCConfiguration;
enum ConfigurationTypes;
enum useOfMfc;
enum useOfATL;
enum charSet;
enum compileAsManagedOptions;
enum WholeProgramOptimizationTypes;
struct __declspec(uuid("75d6bb37-482d-4cde-9634-ca4c0e8d4153"))
/* dual interface */ VCPropertySheet;
struct __declspec(uuid("41e315a7-2fc2-48a7-8512-90755cd9327e"))
/* dual interface */ VCUserMacro;
enum optManagedIncrementalBuild;
enum BuildWithPropertySheetType;
enum eSqlClrPermissionLevel;
struct __declspec(uuid("6eb8dcb9-f64b-471e-a295-14a41e3c099f"))
/* dual interface */ VCFile;
enum eFileType;
struct __declspec(uuid("78875336-dfd3-4958-8296-e770bc369404"))
/* dual interface */ VCFileConfiguration;
struct __declspec(uuid("89954662-7788-4d23-8508-a73917b2e824"))
/* dual interface */ VCConfiguration2;
struct __declspec(uuid("692ef4e6-8596-4920-9558-66e69b9590dc"))
/* dual interface */ VCReferences;
struct __declspec(uuid("fe124eb0-e13c-4c96-8c15-5b26669d5265"))
/* dual interface */ VCReference;
struct __declspec(uuid("04f61f1d-8cb4-4f98-867a-bb93140bac5b"))
/* dual interface */ VCAssemblyReference;
struct __declspec(uuid("5f6f17fb-dbb8-4456-a153-48e862723a68"))
/* dual interface */ VCProjectReference;
struct __declspec(uuid("a6065869-4807-4485-a625-edc4141f67e2"))
/* dual interface */ VCSharedProjectReference;
struct __declspec(uuid("0881de5a-11db-4cdd-ac10-2d36b5cbb2f1"))
/* dual interface */ VCActiveXReference;
struct __declspec(uuid("feaabf59-80d7-405f-97d5-28a5f0981df2"))
/* dual interface */ VCWinRTReference;
struct __declspec(uuid("e457d993-c6f7-4602-8481-8ef319edfb7f"))
/* dual interface */ VCSdkReference;
struct __declspec(uuid("755e3954-ad2b-48da-a546-da53031db007"))
/* dual interface */ VCForeignReference;
struct __declspec(uuid("2758104b-d976-4367-8c49-a0718731db19"))
/* dual interface */ VCXMLDataGeneratorTool;
struct __declspec(uuid("4b7eb22d-c745-4f7a-95b7-a662d2a25ed4"))
/* dual interface */ VCDebugSettings;
enum TypeOfDebugger;
enum RemoteDebuggerType;
enum eDebuggerTypes;
enum enumMPIAcceptModes;
struct __declspec(uuid("80b63513-3e87-44a5-8e12-4ba7f981153e"))
/* dual interface */ VCCLCompilerTool;
enum warningLevelOption;
enum debugOption;
enum optimizeOption;
enum inlineExpansionOption;
enum favorSizeOrSpeedOption;
enum preprocessOption;
enum cppExceptionHandling;
enum basicRuntimeCheckOption;
enum runtimeLibraryOption;
enum structMemberAlignOption;
enum floatingPointModel;
enum pchOption;
enum asmListingOption;
enum browseInfoOption;
enum callingConventionOption;
enum CompileAsOptions;
enum enhancedInstructionSetType;
enum compilerErrorReportingType;
struct __declspec(uuid("2d745b8b-c934-47bd-ba16-ec0514ae4914"))
/* dual interface */ VCMidlTool;
enum midlWarningLevelOption;
enum midlCharOption;
enum midlTargetEnvironment;
enum midlErrorCheckOption;
enum midlStructMemberAlignOption;
struct __declspec(uuid("6590d9e4-516e-447e-a9d9-a32c15bc562b"))
/* dual interface */ VCLinkerTool;
enum linkProgressOption;
enum linkIncrementalType;
enum subSystemOption;
enum addressAwarenessType;
enum termSvrAwarenessType;
enum driverOption;
enum optRefType;
enum optFoldingType;
enum optWin98Type;
enum LinkTimeCodeGenerationOption;
enum machineTypeOption;
enum eCLRThreadAttribute;
enum eCLRImageType;
enum enumRandomizedBaseAddressBOOL;
enum linkFixedBaseAddress;
enum enumDataExecutionPreventionBOOL;
enum linkAssemblyDebug;
enum linkerErrorReportingType;
enum linkUACExecutionLevel;
struct __declspec(uuid("e202e5ca-684b-4d9a-9485-6a2eee4937b6"))
/* dual interface */ VCResourceCompilerTool;
enum enumResourceLangID;
struct __declspec(uuid("f5b8d246-74c0-4fd7-8522-3ecfd3e08a2d"))
/* dual interface */ VCCustomBuildTool;
struct __declspec(uuid("2cf0e564-48be-4244-a99a-2ecaf22139bb"))
/* dual interface */ VCALinkTool;
struct __declspec(uuid("ac6c847a-a0f3-41d4-bd1e-53739b146dea"))
/* dual interface */ VCManagedResourceCompilerTool;
struct __declspec(uuid("80c80c10-3270-4c8d-9653-fd75aa55e79a"))
/* dual interface */ VCManifestTool;
struct __declspec(uuid("0f297231-6269-41e0-80e1-ed7c483f6560"))
/* dual interface */ VCXDCMakeTool;
struct __declspec(uuid("719a2ede-6e72-43ec-ab20-351e7c358f89"))
/* dual interface */ VCFilter;
enum eWebRefUrlBehavior;
struct __declspec(uuid("4e6ce19b-dcc9-40db-b321-3c6f60f89a6f"))
/* dual interface */ VCPreBuildEventTool;
struct __declspec(uuid("4cb3265a-dd3b-4f1e-bef8-88b68f27118d"))
/* dual interface */ VCPreLinkEventTool;
struct __declspec(uuid("74d00da0-092b-4b51-a4d5-134233aebdf4"))
/* dual interface */ VCPostBuildEventTool;
struct __declspec(uuid("af958e5b-cab8-4aaa-9f6a-fb2fbadecd6e"))
/* dual interface */ VCBscMakeTool;
struct __declspec(uuid("bf75c368-74db-4a28-9fda-3b5b76f8eee9"))
/* dual interface */ VCLibrarianTool;
struct __declspec(uuid("023de234-7e71-4fd3-9d29-f82edfdce51d"))
/* dual interface */ VCNMakeTool;
struct __declspec(uuid("bc0e8841-354b-4880-ae89-f724dce6e45f"))
/* dual interface */ VCFxCopTool;
struct __declspec(uuid("3ac4e69b-a4b0-4996-9eec-063e460b8122"))
/* dual interface */ VCFxCopTool2;
struct __declspec(uuid("e1a22e2b-cf0f-4b23-b25c-81a91b2d0c3b"))
/* interface */ IVCBuildPropertyStorage;
struct __declspec(uuid("e642c68e-b883-4f4f-b946-787a07fb3975"))
/* interface */ IVCRulePropertyStorage;
struct __declspec(uuid("e71d6e86-89d8-4ec7-9517-8475d19737de"))
/* interface */ IVCRulePropertyStorage2;
struct __declspec(uuid("a801c81c-2ee5-4f46-a06e-a318cd228fe5"))
/* interface */ IVCIdentity;
struct __declspec(uuid("d3e42d89-b6cb-47b6-b09f-876f61ac5c27"))
/* interface */ IVCProjectTargetChange;
struct __declspec(uuid("9ffeda85-27ca-46cf-aab7-7c470cecbf29"))
/* interface */ IVCProjectTargetDescription;
struct __declspec(uuid("3b621333-4aad-4d82-b865-80e5ddb2cf1e"))
/* interface */ IVCPropertyStorage;
struct __declspec(uuid("85dd53fe-5534-4acc-a0af-8663c886ff3d"))
/* interface */ IVCBuildRequest2;
enum vcRefType;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(SVCProjectEngine, __uuidof(SVCProjectEngine));
_COM_SMARTPTR_TYPEDEF(IVCProjectEngineEvents, __uuidof(IVCProjectEngineEvents));
_COM_SMARTPTR_TYPEDEF(IVCProjectEngineEvents2, __uuidof(IVCProjectEngineEvents2));
_COM_SMARTPTR_TYPEDEF(_dispVCProjectEngineEvents, __uuidof(_dispVCProjectEngineEvents));
_COM_SMARTPTR_TYPEDEF(_VCProjectEngineEvents, __uuidof(_VCProjectEngineEvents));
_COM_SMARTPTR_TYPEDEF(IVCCollection, __uuidof(IVCCollection));
_COM_SMARTPTR_TYPEDEF(VCToolFile, __uuidof(VCToolFile));
_COM_SMARTPTR_TYPEDEF(IVCBuildCompleteCallback, __uuidof(IVCBuildCompleteCallback));
_COM_SMARTPTR_TYPEDEF(IVCBuildRequest, __uuidof(IVCBuildRequest));
_COM_SMARTPTR_TYPEDEF(IVCProjectBuildService, __uuidof(IVCProjectBuildService));
_COM_SMARTPTR_TYPEDEF(VCProjectEngine, __uuidof(VCProjectEngine));
_COM_SMARTPTR_TYPEDEF(VCPlatform, __uuidof(VCPlatform));
_COM_SMARTPTR_TYPEDEF(VCProjectItem, __uuidof(VCProjectItem));
_COM_SMARTPTR_TYPEDEF(VCFileConfiguration, __uuidof(VCFileConfiguration));
_COM_SMARTPTR_TYPEDEF(VCReferences, __uuidof(VCReferences));
_COM_SMARTPTR_TYPEDEF(VCReference, __uuidof(VCReference));
_COM_SMARTPTR_TYPEDEF(VCAssemblyReference, __uuidof(VCAssemblyReference));
_COM_SMARTPTR_TYPEDEF(VCProjectReference, __uuidof(VCProjectReference));
_COM_SMARTPTR_TYPEDEF(VCSharedProjectReference, __uuidof(VCSharedProjectReference));
_COM_SMARTPTR_TYPEDEF(VCActiveXReference, __uuidof(VCActiveXReference));
_COM_SMARTPTR_TYPEDEF(VCWinRTReference, __uuidof(VCWinRTReference));
_COM_SMARTPTR_TYPEDEF(VCSdkReference, __uuidof(VCSdkReference));
_COM_SMARTPTR_TYPEDEF(VCForeignReference, __uuidof(VCForeignReference));
_COM_SMARTPTR_TYPEDEF(VCXMLDataGeneratorTool, __uuidof(VCXMLDataGeneratorTool));
_COM_SMARTPTR_TYPEDEF(VCDebugSettings, __uuidof(VCDebugSettings));
_COM_SMARTPTR_TYPEDEF(VCCLCompilerTool, __uuidof(VCCLCompilerTool));
_COM_SMARTPTR_TYPEDEF(VCMidlTool, __uuidof(VCMidlTool));
_COM_SMARTPTR_TYPEDEF(VCLinkerTool, __uuidof(VCLinkerTool));
_COM_SMARTPTR_TYPEDEF(VCResourceCompilerTool, __uuidof(VCResourceCompilerTool));
_COM_SMARTPTR_TYPEDEF(VCCustomBuildTool, __uuidof(VCCustomBuildTool));
_COM_SMARTPTR_TYPEDEF(VCALinkTool, __uuidof(VCALinkTool));
_COM_SMARTPTR_TYPEDEF(VCManagedResourceCompilerTool, __uuidof(VCManagedResourceCompilerTool));
_COM_SMARTPTR_TYPEDEF(VCManifestTool, __uuidof(VCManifestTool));
_COM_SMARTPTR_TYPEDEF(VCXDCMakeTool, __uuidof(VCXDCMakeTool));
_COM_SMARTPTR_TYPEDEF(VCFilter, __uuidof(VCFilter));
_COM_SMARTPTR_TYPEDEF(VCPreBuildEventTool, __uuidof(VCPreBuildEventTool));
_COM_SMARTPTR_TYPEDEF(VCPreLinkEventTool, __uuidof(VCPreLinkEventTool));
_COM_SMARTPTR_TYPEDEF(VCPostBuildEventTool, __uuidof(VCPostBuildEventTool));
_COM_SMARTPTR_TYPEDEF(VCBscMakeTool, __uuidof(VCBscMakeTool));
_COM_SMARTPTR_TYPEDEF(VCLibrarianTool, __uuidof(VCLibrarianTool));
_COM_SMARTPTR_TYPEDEF(VCNMakeTool, __uuidof(VCNMakeTool));
_COM_SMARTPTR_TYPEDEF(VCFxCopTool, __uuidof(VCFxCopTool));
_COM_SMARTPTR_TYPEDEF(VCFxCopTool2, __uuidof(VCFxCopTool2));
_COM_SMARTPTR_TYPEDEF(IVCBuildPropertyStorage, __uuidof(IVCBuildPropertyStorage));
_COM_SMARTPTR_TYPEDEF(IVCRulePropertyStorage, __uuidof(IVCRulePropertyStorage));
_COM_SMARTPTR_TYPEDEF(IVCRulePropertyStorage2, __uuidof(IVCRulePropertyStorage2));
_COM_SMARTPTR_TYPEDEF(IVCIdentity, __uuidof(IVCIdentity));
_COM_SMARTPTR_TYPEDEF(IVCProjectTargetChange, __uuidof(IVCProjectTargetChange));
_COM_SMARTPTR_TYPEDEF(IVCProjectTargetDescription, __uuidof(IVCProjectTargetDescription));
_COM_SMARTPTR_TYPEDEF(IVCPropertyStorage, __uuidof(IVCPropertyStorage));
_COM_SMARTPTR_TYPEDEF(VCProject, __uuidof(VCProject));
_COM_SMARTPTR_TYPEDEF(VCConfiguration, __uuidof(VCConfiguration));
_COM_SMARTPTR_TYPEDEF(VCFile, __uuidof(VCFile));
_COM_SMARTPTR_TYPEDEF(VCConfiguration2, __uuidof(VCConfiguration2));
_COM_SMARTPTR_TYPEDEF(IVCBuildRequest2, __uuidof(IVCBuildRequest2));
_COM_SMARTPTR_TYPEDEF(VCPropertySheet, __uuidof(VCPropertySheet));
_COM_SMARTPTR_TYPEDEF(VCUserMacro, __uuidof(VCUserMacro));

//
// Type library items
//

struct __declspec(uuid("dbecfca1-1a01-42ad-8158-ca1c3c543adc"))
SVCProjectEngine : IUnknown
{};

enum enumSccEvent
{
    eProjectInScc = 0,
    ePreDirtyNotification = 1
};

struct __declspec(uuid("0fb57085-958b-45f2-bfac-d8b5cd2b57a8"))
IVCProjectEngineEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ItemAdded (
        IDispatch * Item,
        IDispatch * ItemParent ) = 0;
      virtual HRESULT __stdcall ItemRemoved (
        IDispatch * Item,
        IDispatch * ItemParent ) = 0;
      virtual HRESULT __stdcall ItemRenamed (
        IDispatch * Item,
        IDispatch * ItemParent,
        BSTR OldName ) = 0;
      virtual HRESULT __stdcall ItemMoved (
        IDispatch * Item,
        IDispatch * NewParent,
        IDispatch * OldParent ) = 0;
      virtual HRESULT __stdcall ItemPropertyChange (
        IDispatch * Item,
        IDispatch * Tool,
        long dispid ) = 0;
      virtual HRESULT __stdcall SccEvent (
        IDispatch * Item,
        enum enumSccEvent event,
        /*[out,retval]*/ VARIANT_BOOL * Ret ) = 0;
      virtual HRESULT __stdcall ReportError (
        BSTR ErrMsg,
        HRESULT hr,
        BSTR HelpKeyword ) = 0;
      virtual HRESULT __stdcall ProjectBuildStarted (
        IDispatch * Cfg ) = 0;
      virtual HRESULT __stdcall ProjectBuildFinished (
        IDispatch * Cfg,
        long warnings,
        long errors,
        VARIANT_BOOL Cancelled ) = 0;
      virtual HRESULT __stdcall SolutionLoaded ( ) = 0;
};

struct __declspec(uuid("e3de0769-1e0a-43b7-8d57-1d4241b822b3"))
IVCProjectEngineEvents2 : IVCProjectEngineEvents
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall ItemPropertyChange2 (
        IDispatch * Item,
        BSTR bstrPropertySheet,
        BSTR bstrItemType,
        BSTR bstrPropertyName ) = 0;
};

struct __declspec(uuid("8b558010-3d1f-43ea-af3e-46319fd787eb"))
_dispVCProjectEngineEvents : IDispatch
{};

struct __declspec(uuid("bc11c64a-17bb-4c0d-8e31-e85ac066a120"))
_VCProjectEngineEvents : IDispatch
{};

struct __declspec(uuid("69f077c7-4f70-46a1-bde0-18f8abfaf21e"))
VCProjectEngineEvents;
    // [ default ] interface _VCProjectEngineEvents
    // [ default, source ] dispinterface _dispVCProjectEngineEvents

struct __declspec(uuid("f840d790-af0c-4927-bd62-243899e5c969"))
VCProjectEngineObject;
    // [ default ] interface VCProjectEngine

struct __declspec(uuid("ef0ef512-4ab7-4eec-91d1-9e5e222eed81"))
IVCCollection : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * Enumerator ) = 0;
      virtual HRESULT __stdcall Item (
        VARIANT Index,
        /*[out,retval]*/ IDispatch * * Item ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Val ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
};

struct __declspec(uuid("aa47150b-d212-410c-8a4a-3af30e64670e"))
VCToolFile : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * Path ) = 0;
      virtual HRESULT __stdcall get_CustomBuildRules (
        /*[out,retval]*/ struct IVCCollection * * BuildRules ) = 0;
      virtual HRESULT __stdcall Save (
        /*[in]*/ BSTR Path ) = 0;
      virtual HRESULT __stdcall AddCustomBuildRule (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR CommandLine,
        /*[in]*/ BSTR Outputs,
        /*[in]*/ BSTR FileExtensions,
        /*[out,retval]*/ IDispatch * * CustomBuildRule ) = 0;
      virtual HRESULT __stdcall RemoveCustomBuildRule (
        /*[in]*/ IDispatch * CustomBuildRule ) = 0;
};

enum bldActionTypes
{
    TOB_Build = 0,
    TOB_ReBuild = 1,
    TOB_Clean = 2,
    TOB_Link = 3,
    TOB_PreBuildEvent = 4,
    TOB_PreLinkEvent = 5,
    TOB_PostBuildEvent = 6,
    TOB_Compile = 8,
    TOB_PlatformEvent = 16,
    TOB_Deploy = 17,
    TOB_BuildPDB = 18
};

struct __declspec(uuid("9b92c18d-a218-4266-bb37-f9d58c17f07b"))
IVCBuildCompleteCallback : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall OnBuildCompleted (
        /*[in]*/ unsigned long buildId,
        /*[in]*/ VARIANT_BOOL fSuccessful ) = 0;
};

struct __declspec(uuid("7dd2b83e-a53a-443c-b2eb-ec618bb25f82"))
IVCBuildRequest : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddBuildProperty (
        /*[in]*/ LPWSTR pszName,
        /*[in]*/ LPWSTR pszValue ) = 0;
      virtual HRESULT __stdcall AddBuildTarget (
        LPWSTR pszBuildTarget ) = 0;
      virtual HRESULT __stdcall get_BuildCompletedCallback (
        /*[out,retval]*/ struct IVCBuildCompleteCallback * * ppCB ) = 0;
      virtual HRESULT __stdcall put_BuildCompletedCallback (
        /*[in]*/ struct IVCBuildCompleteCallback * ppCB ) = 0;
      virtual HRESULT __stdcall get_BuildLogFile (
        /*[out,retval]*/ BSTR * pbstrBuildLogFile ) = 0;
      virtual HRESULT __stdcall put_BuildLogFile (
        /*[in]*/ BSTR pbstrBuildLogFile ) = 0;
      virtual HRESULT __stdcall get_OutputWindow (
        /*[out,retval]*/ IUnknown * * ppOutputWindow ) = 0;
      virtual HRESULT __stdcall put_OutputWindow (
        /*[in]*/ IUnknown * ppOutputWindow ) = 0;
};

struct __declspec(uuid("622c69b7-5541-4612-89bd-3ddc34f061de"))
IVCProjectBuildService : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetTargetForBuildType (
        /*[in]*/ enum bldActionTypes action,
        /*[out,retval]*/ BSTR * pbstrTarget ) = 0;
      virtual HRESULT __stdcall CreateVCBuildRequest (
        /*[out,retval]*/ struct IVCBuildRequest * * ppRequest ) = 0;
      virtual HRESULT __stdcall get_CanStartBuild (
        /*[out,retval]*/ VARIANT_BOOL * pfCanStart ) = 0;
      virtual HRESULT __stdcall StartBuildTarget (
        /*[in]*/ struct IVCBuildRequest * request,
        /*[out]*/ unsigned long * pdwBuildId ) = 0;
      virtual HRESULT __stdcall Cancel (
        /*[in]*/ unsigned long buildId,
        /*[in]*/ VARIANT_BOOL fSync ) = 0;
      virtual HRESULT __stdcall IsBuildUpToDate (
        /*[in]*/ LPWSTR pszConfiguration,
        /*[in]*/ LPWSTR pszPlatform,
        /*[in]*/ LPWSTR pszLastBuildStateFile,
        /*[in]*/ LPWSTR pszLastUnsuccessfulBuildFile,
        /*[in]*/ LPWSTR pszCurrentEvaluationFingerprint,
        /*[in]*/ LPWSTR pszExcludePaths,
        /*[in]*/ LPWSTR pszTrackerLogDirectory,
        /*[in]*/ SAFEARRAY * rgAdditionalInputFiles,
        /*[in]*/ IUnknown * pOutputWindow,
        /*[out,retval]*/ VARIANT_BOOL * pfUpToDate ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
};

struct __declspec(uuid("54969dd8-23d3-4a77-911c-87e6a3c5c21c"))
VCProjectEngine : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_BuildLogging (
        /*[out,retval]*/ VARIANT_BOOL * Log ) = 0;
      virtual HRESULT __stdcall put_BuildLogging (
        /*[in]*/ VARIANT_BOOL Log ) = 0;
      virtual HRESULT __stdcall get_BuildTiming (
        /*[out,retval]*/ VARIANT_BOOL * Time ) = 0;
      virtual HRESULT __stdcall put_BuildTiming (
        /*[in]*/ VARIANT_BOOL Time ) = 0;
      virtual HRESULT __stdcall get_PerformanceLogging (
        /*[out,retval]*/ VARIANT_BOOL * Time ) = 0;
      virtual HRESULT __stdcall put_PerformanceLogging (
        /*[in]*/ VARIANT_BOOL Time ) = 0;
      virtual HRESULT __stdcall IsSystemInclude (
        /*[in]*/ BSTR Include,
        /*[out,retval]*/ VARIANT_BOOL * IsSystem ) = 0;
      virtual HRESULT __stdcall get_Events (
        /*[out,retval]*/ IDispatch * * ProjectEngineEvents ) = 0;
      virtual HRESULT __stdcall get_Platforms (
        /*[out,retval]*/ IDispatch * * Platforms ) = 0;
      virtual HRESULT __stdcall get_Projects (
        /*[out,retval]*/ IDispatch * * Projects ) = 0;
      virtual HRESULT __stdcall CreateProject (
        /*[in]*/ BSTR projectName,
        /*[out,retval]*/ IDispatch * * project ) = 0;
      virtual HRESULT __stdcall LoadProject (
        /*[in]*/ BSTR projectName,
        /*[out,retval]*/ IDispatch * * project ) = 0;
      virtual HRESULT __stdcall RemoveProject (
        /*[in]*/ IDispatch * project ) = 0;
      virtual HRESULT __stdcall get_PropertySheets (
        /*[out,retval]*/ IDispatch * * PropertySheets ) = 0;
      virtual HRESULT __stdcall LoadPropertySheet (
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ IDispatch * * PropertySheet ) = 0;
      virtual HRESULT __stdcall CreatePropertySheet (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ IDispatch * * PropertySheet ) = 0;
      virtual HRESULT __stdcall RemovePropertySheet (
        /*[in]*/ IDispatch * PropertySheet ) = 0;
      virtual HRESULT __stdcall Evaluate (
        /*[in]*/ BSTR In,
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall get_ShowEnvironmentInBuildLog (
        /*[out,retval]*/ VARIANT_BOOL * showEnvironment ) = 0;
      virtual HRESULT __stdcall put_ShowEnvironmentInBuildLog (
        /*[in]*/ VARIANT_BOOL showEnvironment ) = 0;
      virtual HRESULT __stdcall AddFakeProps (
        /*[in]*/ long idStart,
        /*[in]*/ long idEnd,
        /*[in]*/ long idOffset ) = 0;
      virtual HRESULT __stdcall get_ToolFileSearchPaths (
        /*[out,retval]*/ BSTR * SearchPaths ) = 0;
      virtual HRESULT __stdcall put_ToolFileSearchPaths (
        /*[in]*/ BSTR SearchPaths ) = 0;
      virtual HRESULT __stdcall get_ToolFiles (
        /*[out,retval]*/ IDispatch * * ToolFiles ) = 0;
      virtual HRESULT __stdcall LoadToolFile (
        /*[in]*/ BSTR File,
        /*[out,retval]*/ struct VCToolFile * * ToolFile ) = 0;
      virtual HRESULT __stdcall CreateToolFile (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ struct VCToolFile * * ToolFile ) = 0;
      virtual HRESULT __stdcall get_ValidateSchemas (
        /*[out,retval]*/ VARIANT_BOOL * Validate ) = 0;
      virtual HRESULT __stdcall put_ValidateSchemas (
        /*[in]*/ VARIANT_BOOL Validate ) = 0;
      virtual HRESULT __stdcall WaitForMultipleHandles (
        /*[in]*/ unsigned long timeout,
        /*[in]*/ SAFEARRAY * saHandles,
        /*[out,retval]*/ int * piSignaled ) = 0;
      virtual HRESULT __stdcall GetVCProjectBuildService (
        /*[in]*/ LPWSTR pszProjectFullPath,
        /*[in]*/ LPWSTR pszProjectUniqueName,
        /*[in]*/ GUID * guidProject,
        /*[in]*/ IUnknown * pHierarchy,
        /*[out,retval]*/ struct IVCProjectBuildService * * ppService ) = 0;
};

struct __declspec(uuid("e2a1c8ff-6174-49fa-9476-dc188bd947b5"))
VCPlatform : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ExecutableDirectories (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall put_ExecutableDirectories (
        /*[in]*/ BSTR Dir ) = 0;
      virtual HRESULT __stdcall get_IncludeDirectories (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall put_IncludeDirectories (
        /*[in]*/ BSTR Dir ) = 0;
      virtual HRESULT __stdcall get_ReferenceDirectories (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall put_ReferenceDirectories (
        /*[in]*/ BSTR Dir ) = 0;
      virtual HRESULT __stdcall get_LibraryDirectories (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall put_LibraryDirectories (
        /*[in]*/ BSTR Dir ) = 0;
      virtual HRESULT __stdcall get_SourceDirectories (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall put_SourceDirectories (
        /*[in]*/ BSTR Dir ) = 0;
      virtual HRESULT __stdcall get_ExcludeDirectories (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall put_ExcludeDirectories (
        /*[in]*/ BSTR Dir ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall get_Tools (
        /*[out,retval]*/ IDispatch * * Dir ) = 0;
      virtual HRESULT __stdcall MatchName (
        /*[in]*/ BSTR NameToMatch,
        /*[in]*/ VARIANT_BOOL FullOnly,
        /*[out,retval]*/ VARIANT_BOOL * IsMatch ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall Evaluate (
        /*[in]*/ BSTR In,
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall get_DefaultDirectory (
        /*[out,retval]*/ BSTR * Dir ) = 0;
      virtual HRESULT __stdcall CommitChanges ( ) = 0;
      virtual HRESULT __stdcall GetToolNameForKeyword (
        /*[in]*/ BSTR keyword,
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_DeploymentTool (
        /*[out,retval]*/ IDispatch * * Tool ) = 0;
      virtual HRESULT __stdcall get_DebuggerTool (
        /*[out,retval]*/ IDispatch * * Tool ) = 0;
      virtual HRESULT __stdcall get_GeneralPageTool (
        /*[out,retval]*/ IDispatch * * Page ) = 0;
      virtual HRESULT __stdcall get_NumberOfPlatformMacros (
        /*[out,retval]*/ long * numMacros ) = 0;
      virtual HRESULT __stdcall get_PlatformMacro (
        /*[in]*/ long Index,
        /*[out,retval]*/ BSTR * macroName ) = 0;
      virtual HRESULT __stdcall GetMacroValue (
        /*[in]*/ BSTR In,
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall get_DisableAlternateDebuggers (
        /*[out,retval]*/ VARIANT_BOOL * Val ) = 0;
      virtual HRESULT __stdcall get_ExecutableExtensions (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall get_DumpfileExtensions (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall IsExecutable (
        /*[in]*/ BSTR Path,
        /*[out,retval]*/ VARIANT_BOOL * Ret ) = 0;
      virtual HRESULT __stdcall IsDumpfile (
        /*[in]*/ BSTR Path,
        /*[out,retval]*/ VARIANT_BOOL * Ret ) = 0;
};

struct __declspec(uuid("60dddab8-1862-477f-8995-bb83fb33fcda"))
VCProjectItem : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall MatchName (
        /*[in]*/ BSTR NameToMatch,
        /*[in]*/ VARIANT_BOOL FullOnly,
        /*[out,retval]*/ VARIANT_BOOL * IsMatch ) = 0;
      virtual HRESULT __stdcall get_project (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_ItemName (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall get_Kind (
        /*[out,retval]*/ BSTR * Kind ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
};

enum enumFileFormat
{
    eANSI = 0,
    eUTF8 = 1,
    eUnicode = 2
};

enum enumFrameworkVersion
{
    eFrameworkVersionUnknown = 0,
    eFrameworkVersion20 = 131072,
    eFrameworkVersion30 = 196608,
    eFrameworkVersion35 = 196613,
    eFrameworkVersion40 = 262144,
    eFrameworkVersion45 = 262149,
    eFrameworkVersion451 = 262405,
    eFrameworkVersion452 = 262661,
    eFrameworkVersion46 = 262150,
    eFrameworkVersion461 = 262406,
    eFrameworkVersion462 = 262662,
    eFrameworkVersionLatest = 262662,
    eFrameworkVersionDefault = 262144
};

enum ConfigurationTypes
{
    typeUnknown = 0,
    typeApplication = 1,
    typeDynamicLibrary = 2,
    typeStaticLibrary = 4,
    typeGeneric = 10
};

enum useOfMfc
{
    useMfcStdWin = 0,
    useMfcStatic = 1,
    useMfcDynamic = 2
};

enum useOfATL
{
    useATLNotSet = 0,
    useATLStatic = 1,
    useATLDynamic = 2
};

enum charSet
{
    charSetNotSet = 0,
    charSetUnicode = 1,
    charSetMBCS = 2
};

enum compileAsManagedOptions
{
    managedNotSet = 0,
    managedAssembly = 1,
    managedAssemblyPure = 2,
    managedAssemblySafe = 3,
    managedAssemblyOldSyntax = 4
};

enum WholeProgramOptimizationTypes
{
    WholeProgramOptimizationNone = 0,
    WholeProgramOptimizationLinkTimeCodeGen = 1,
    WholeProgramOptimizationPGOInstrument = 2,
    WholeProgramOptimizationPGOOptimize = 3,
    WholeProgramOptimizationPGOUpdate = 4
};

enum optManagedIncrementalBuild
{
    optManagedIncrementalBuildNo = 0,
    optManagedIncrementalBuildYes = 1
};

enum BuildWithPropertySheetType
{
    BuildWithPropertySheetTypeBuild = 0,
    BuildWithPropertySheetTypeRebuild = 1,
    BuildWithPropertySheetTypeLink = 2,
    BuildWithPropertySheetTypeClean = 3
};

enum eSqlClrPermissionLevel
{
    eSafe = 0,
    eExternal = 1,
    eUnsafe = 2
};

enum eFileType
{
    eFileTypeDefault = -1,
    eFileTypeCppCode = 0,
    eFileTypeCppClass = 1,
    eFileTypeCppHeader = 2,
    eFileTypeCppForm = 3,
    eFileTypeCppControl = 4,
    eFileTypeText = 5,
    eFileTypeDEF = 6,
    eFileTypeIDL = 7,
    eFileTypeMakefile = 8,
    eFileTypeRGS = 9,
    eFileTypeRC = 10,
    eFileTypeRES = 11,
    eFileTypeXSD = 12,
    eFileTypeXML = 13,
    eFileTypeHTML = 14,
    eFileTypeCSS = 15,
    eFileTypeBMP = 16,
    eFileTypeICO = 17,
    eFileTypeResx = 18,
    eFileTypeScript = 19,
    eFileTypeBSC = 20,
    eFileTypeXSX = 21,
    eFileTypeCppWebService = 22,
    eFileTypeAsax = 23,
    eFileTypeAspPage = 24,
    eFileTypeDocument = 25,
    eFileTypeDiscomap = 26,
    eFileTypeCSharpFile = 28,
    eFileTypeClassDiagram = 29,
    eFileTypeMHT = 30,
    eFileTypePropertySheet = 31,
    eFileTypeCUR = 32,
    eFileTypeManifest = 33,
    eFileTypeRDLC = 34,
    eFileTypeFilters = 35,
    eFileTypeReference = 36
};

struct __declspec(uuid("78875336-dfd3-4958-8296-e770bc369404"))
VCFileConfiguration : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall get_Tool (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall put_Tool (
        /*[in]*/ IDispatch * Val ) = 0;
      virtual HRESULT __stdcall get_ExcludedFromBuild (
        /*[out,retval]*/ VARIANT_BOOL * ExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall put_ExcludedFromBuild (
        /*[in]*/ VARIANT_BOOL ExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall MatchName (
        /*[in]*/ BSTR bstrNameToMatch,
        /*[in]*/ VARIANT_BOOL FullOnly,
        /*[out,retval]*/ VARIANT_BOOL * Match ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_File (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall Evaluate (
        /*[in]*/ BSTR bstrIn,
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ProjectConfiguration (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall Compile (
        /*[in]*/ VARIANT_BOOL forceBuild,
        /*[in]*/ VARIANT_BOOL waitOnBuild ) = 0;
      virtual HRESULT __stdcall get_OutputUpToDate (
        /*[out,retval]*/ VARIANT_BOOL * UpToDate ) = 0;
};

struct __declspec(uuid("692ef4e6-8596-4920-9558-66e69b9590dc"))
VCReferences : VCProjectItem
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddAssemblyReference (
        /*[in]*/ BSTR bstrRef,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddActiveXReference (
        /*[in]*/ BSTR typeLibGuid,
        /*[in]*/ long majorVersion,
        /*[in]*/ long minorVersion,
        /*[in]*/ long localeID,
        /*[in]*/ BSTR wrapper,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddProjectReference (
        /*[in]*/ IDispatch * proj,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddWinRTReference (
        /*[in]*/ BSTR bstrRef,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddSdkReference (
        /*[in]*/ BSTR bstrsdkIdentity,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall CanAddAssemblyReference (
        /*[in]*/ BSTR bstrRef,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddActiveXReference (
        /*[in]*/ BSTR typeLibGuid,
        /*[in]*/ long majorVersion,
        /*[in]*/ long minorVersion,
        /*[in]*/ long localeID,
        /*[in]*/ BSTR wrapper,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddProjectReference (
        /*[in]*/ IDispatch * proj,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddWinRTReference (
        /*[in]*/ BSTR bstrRef,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddSdkReference (
        /*[in]*/ BSTR bstrsdkIdentity,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall RemoveReference (
        /*[in]*/ IDispatch * Reference ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * Enumerator ) = 0;
      virtual HRESULT __stdcall Item (
        VARIANT Index,
        /*[out,retval]*/ IDispatch * * Item ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get_References (
        /*[out,retval]*/ IDispatch * * Refs ) = 0;
      virtual HRESULT __stdcall AddAssemblyReferenceWithStrongName (
        /*[in]*/ BSTR bstrRef,
        /*[in]*/ BSTR bstrAssemblyName,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall CanAddAssemblyReferenceWithStrongName (
        /*[in]*/ BSTR bstrRef,
        /*[in]*/ BSTR bstrAssemblyName,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall AddProjectReferenceByIdentifier (
        /*[in]*/ BSTR Identifier,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall CanAddProjectReferenceByIdentifier (
        /*[in]*/ BSTR Identifier,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall AddReferenceToFile (
        /*[in]*/ BSTR Path,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall CanAddReferenceToFile (
        /*[in]*/ BSTR Path,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall AddAssemblyReferenceWithStrongNameEx (
        /*[in]*/ BSTR bstrRef,
        /*[in]*/ BSTR bstrAssemblyName,
        /*[out]*/ VARIANT_BOOL * created,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddActiveXReferenceEx (
        /*[in]*/ BSTR typeLibGuid,
        /*[in]*/ long majorVersion,
        /*[in]*/ long minorVersion,
        /*[in]*/ long localeID,
        /*[in]*/ BSTR wrapper,
        /*[out]*/ VARIANT_BOOL * created,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddProjectReferenceByIdentifierEx (
        /*[in]*/ BSTR Identifier,
        /*[out]*/ VARIANT_BOOL * created,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall AddReferenceToFileEx (
        /*[in]*/ BSTR Path,
        /*[out]*/ VARIANT_BOOL * created,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall GetReferencesOfType (
        /*[in]*/ unsigned long dwType,
        /*[out,retval]*/ struct IVCCollection * * ppRefs ) = 0;
      virtual HRESULT __stdcall AddSharedProjectReference (
        /*[in]*/ BSTR Path,
        /*[out]*/ VARIANT_BOOL * created,
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
};

struct __declspec(uuid("fe124eb0-e13c-4c96-8c15-5b26669d5265"))
VCReference : VCProjectItem
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Identity (
        /*[out,retval]*/ BSTR * Identity ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Description ) = 0;
      virtual HRESULT __stdcall get_Label (
        /*[out,retval]*/ BSTR * Label ) = 0;
      virtual HRESULT __stdcall get_CopyLocal (
        /*[out,retval]*/ VARIANT_BOOL * CopyLocal ) = 0;
      virtual HRESULT __stdcall put_CopyLocal (
        /*[in]*/ VARIANT_BOOL CopyLocal ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * FullPath ) = 0;
      virtual HRESULT __stdcall get_Culture (
        /*[out,retval]*/ BSTR * Culture ) = 0;
      virtual HRESULT __stdcall get_majorVersion (
        /*[out,retval]*/ long * majorVersion ) = 0;
      virtual HRESULT __stdcall get_minorVersion (
        /*[out,retval]*/ long * minorVersion ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * Version ) = 0;
      virtual HRESULT __stdcall get_StrongName (
        /*[out,retval]*/ VARIANT_BOOL * StrongName ) = 0;
      virtual HRESULT __stdcall get_PublicKeyToken (
        /*[out,retval]*/ BSTR * PublicKeyToken ) = 0;
      virtual HRESULT __stdcall get_BuildNumber (
        /*[out,retval]*/ long * BuildNumber ) = 0;
      virtual HRESULT __stdcall get_RevisionNumber (
        /*[out,retval]*/ long * RevisionNumber ) = 0;
      virtual HRESULT __stdcall Remove ( ) = 0;
      virtual HRESULT __stdcall get_Reference (
        /*[out,retval]*/ IDispatch * * Reference ) = 0;
      virtual HRESULT __stdcall get_UseInBuild (
        /*[out,retval]*/ VARIANT_BOOL * UseInBuild ) = 0;
      virtual HRESULT __stdcall put_UseInBuild (
        /*[in]*/ VARIANT_BOOL UseInBuild ) = 0;
      virtual HRESULT __stdcall get_VCReferences (
        /*[out,retval]*/ IDispatch * * References ) = 0;
      virtual HRESULT __stdcall get_AssemblyName (
        /*[out,retval]*/ BSTR * AssemblyName ) = 0;
      virtual HRESULT __stdcall get_SubType (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_SubType (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_UseDependenciesInBuild (
        /*[out,retval]*/ VARIANT_BOOL * UseDependenciesInBuild ) = 0;
      virtual HRESULT __stdcall put_UseDependenciesInBuild (
        /*[in]*/ VARIANT_BOOL UseDependenciesInBuild ) = 0;
      virtual HRESULT __stdcall get_CopyLocalDependencies (
        /*[out,retval]*/ VARIANT_BOOL * CopyLocalDependencies ) = 0;
      virtual HRESULT __stdcall put_CopyLocalDependencies (
        /*[in]*/ VARIANT_BOOL CopyLocalDependencies ) = 0;
      virtual HRESULT __stdcall get_CopyLocalSatelliteAssemblies (
        /*[out,retval]*/ VARIANT_BOOL * CopyLocalSatellites ) = 0;
      virtual HRESULT __stdcall put_CopyLocalSatelliteAssemblies (
        /*[in]*/ VARIANT_BOOL CopyLocalSatellites ) = 0;
      virtual HRESULT __stdcall get_MinFrameworkVersion (
        /*[out,retval]*/ enum enumFrameworkVersion * MinFrameworkVersion ) = 0;
      virtual HRESULT __stdcall get_VCReferenceType (
        /*[out,retval]*/ unsigned long * pType ) = 0;
};

struct __declspec(uuid("04f61f1d-8cb4-4f98-867a-bb93140bac5b"))
VCAssemblyReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_RelativePath (
        /*[out,retval]*/ BSTR * Val ) = 0;
};

struct __declspec(uuid("5f6f17fb-dbb8-4456-a153-48e862723a68"))
VCProjectReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ReferencedProject (
        /*[out,retval]*/ IDispatch * * ReferencedProject ) = 0;
      virtual HRESULT __stdcall get_ReferencedProjectIdentifier (
        /*[out,retval]*/ BSTR * referencedProjectID ) = 0;
      virtual HRESULT __stdcall get_IsProjectLoaded (
        /*[out,retval]*/ VARIANT_BOOL * IsLoaded ) = 0;
      virtual HRESULT __stdcall get_LinkLibraryDependency (
        /*[out,retval]*/ VARIANT_BOOL * LinkLibraryDependency ) = 0;
      virtual HRESULT __stdcall put_LinkLibraryDependency (
        /*[in]*/ VARIANT_BOOL LinkLibraryDependency ) = 0;
      virtual HRESULT __stdcall get_UseLibraryDependencyInputs (
        /*[out,retval]*/ VARIANT_BOOL * UseLibraryDependencyInputs ) = 0;
      virtual HRESULT __stdcall put_UseLibraryDependencyInputs (
        /*[in]*/ VARIANT_BOOL UseLibraryDependencyInputs ) = 0;
};

struct __declspec(uuid("a6065869-4807-4485-a625-edc4141f67e2"))
VCSharedProjectReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ReferencedProject (
        /*[out,retval]*/ IDispatch * * ReferencedProject ) = 0;
      virtual HRESULT __stdcall get_ReferencedProjectIdentifier (
        /*[out,retval]*/ BSTR * referencedProjectID ) = 0;
};

struct __declspec(uuid("0881de5a-11db-4cdd-ac10-2d36b5cbb2f1"))
VCActiveXReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ControlGUID (
        /*[out,retval]*/ BSTR * refGUID ) = 0;
      virtual HRESULT __stdcall get_ControlVersion (
        /*[out,retval]*/ BSTR * refVersion ) = 0;
      virtual HRESULT __stdcall get_ControlLocale (
        /*[out,retval]*/ long * refLocale ) = 0;
      virtual HRESULT __stdcall get_WrapperTool (
        /*[out,retval]*/ BSTR * wrapper ) = 0;
      virtual HRESULT __stdcall put_WrapperTool (
        /*[in]*/ BSTR wrapper ) = 0;
      virtual HRESULT __stdcall get_ControlFullPath (
        /*[out,retval]*/ BSTR * controlPath ) = 0;
      virtual HRESULT __stdcall get_TypeLibraryName (
        /*[out,retval]*/ BSTR * typelibName ) = 0;
      virtual HRESULT __stdcall get_WrapperSuccessfullyGenerated (
        /*[out,retval]*/ VARIANT_BOOL * Successful ) = 0;
      virtual HRESULT __stdcall get_GenerationErrorMessage (
        /*[out,retval]*/ BSTR * ErrorMessage ) = 0;
};

struct __declspec(uuid("feaabf59-80d7-405f-97d5-28a5f0981df2"))
VCWinRTReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_RelativePath (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall get_sdkIdentity (
        /*[out,retval]*/ BSTR * Val ) = 0;
};

struct __declspec(uuid("e457d993-c6f7-4602-8481-8ef319edfb7f"))
VCSdkReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ExpandedReferences (
        /*[out,retval]*/ SAFEARRAY * * pRetVal ) = 0;
};

struct __declspec(uuid("755e3954-ad2b-48da-a546-da53031db007"))
VCForeignReference : VCReference
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ForeignReference (
        /*[out,retval]*/ IDispatch * * ppVal ) = 0;
};

struct __declspec(uuid("2758104b-d976-4367-8c49-a0718731db19"))
VCXMLDataGeneratorTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_Output (
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall put_Output (
        /*[in]*/ BSTR Out ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * suppress ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL suppress ) = 0;
      virtual HRESULT __stdcall get_Namespace (
        /*[out,retval]*/ BSTR * Namespace ) = 0;
      virtual HRESULT __stdcall put_Namespace (
        /*[in]*/ BSTR Namespace ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

enum TypeOfDebugger
{
    DbgNativeOnly = 0,
    DbgManagedOnly = 1,
    DbgMixed = 2,
    DbgAuto = 3,
    DbgScript = 4
};

enum RemoteDebuggerType
{
    DbgRemote = 1,
    DbgRemoteTCPIP = 2
};

enum eDebuggerTypes
{
    eLocalDebugger = 0,
    eRemoteDebugger = 1,
    eWebSvcDebugger = 2,
    eClusterDebugger = 3,
    eWebBrowserDebugger = 4,
    eDebuggerTypeLast = 5
};

enum enumMPIAcceptModes
{
    eMPIAcceptSubnets = 0,
    eMPIAcceptSpecific = 1,
    eMPIAcceptAny = 2
};

struct __declspec(uuid("4b7eb22d-c745-4f7a-95b7-a662d2a25ed4"))
VCDebugSettings : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Command (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_Command (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_CommandArguments (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_CommandArguments (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_WorkingDirectory (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_WorkingDirectory (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_Attach (
        /*[out,retval]*/ VARIANT_BOOL * Val ) = 0;
      virtual HRESULT __stdcall put_Attach (
        /*[in]*/ VARIANT_BOOL Val ) = 0;
      virtual HRESULT __stdcall get_PDBPath (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_PDBPath (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_DebuggerType (
        /*[out,retval]*/ enum TypeOfDebugger * Val ) = 0;
      virtual HRESULT __stdcall put_DebuggerType (
        /*[in]*/ enum TypeOfDebugger Val ) = 0;
      virtual HRESULT __stdcall get_Environment (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_Environment (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_EnvironmentMerge (
        /*[out,retval]*/ VARIANT_BOOL * Val ) = 0;
      virtual HRESULT __stdcall put_EnvironmentMerge (
        /*[in]*/ VARIANT_BOOL Val ) = 0;
      virtual HRESULT __stdcall get_SQLDebugging (
        /*[out,retval]*/ VARIANT_BOOL * Val ) = 0;
      virtual HRESULT __stdcall put_SQLDebugging (
        /*[in]*/ VARIANT_BOOL Val ) = 0;
      virtual HRESULT __stdcall get_HttpUrl (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_HttpUrl (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_Remote (
        /*[out,retval]*/ enum RemoteDebuggerType * Val ) = 0;
      virtual HRESULT __stdcall put_Remote (
        /*[in]*/ enum RemoteDebuggerType Val ) = 0;
      virtual HRESULT __stdcall get_RemoteMachine (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_RemoteMachine (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_RemoteCommand (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_RemoteCommand (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_DebuggerFlavor (
        /*[out,retval]*/ enum eDebuggerTypes * Val ) = 0;
      virtual HRESULT __stdcall put_DebuggerFlavor (
        /*[in]*/ enum eDebuggerTypes Val ) = 0;
      virtual HRESULT __stdcall get_MPIRunCommand (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_MPIRunCommand (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_MPIRunArguments (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_MPIRunArguments (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_MPIRunWorkingDirectory (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_MPIRunWorkingDirectory (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_ApplicationCommand (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_ApplicationCommand (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_ApplicationArguments (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_ApplicationArguments (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_ShimCommand (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_ShimCommand (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_MPIAcceptMode (
        /*[out,retval]*/ enum enumMPIAcceptModes * Val ) = 0;
      virtual HRESULT __stdcall put_MPIAcceptMode (
        /*[in]*/ enum enumMPIAcceptModes Val ) = 0;
      virtual HRESULT __stdcall get_MPIAcceptFilter (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_MPIAcceptFilter (
        /*[in]*/ BSTR Val ) = 0;
};

enum warningLevelOption
{
    warningLevel_0 = 0,
    warningLevel_1 = 1,
    warningLevel_2 = 2,
    warningLevel_3 = 3,
    warningLevel_4 = 4
};

enum debugOption
{
    debugDisabled = 0,
    debugOldStyleInfo = 1,
    debugEnabled = 3,
    debugEditAndContinue = 4
};

enum optimizeOption
{
    optimizeDisabled = 0,
    optimizeMinSpace = 1,
    optimizeMaxSpeed = 2,
    optimizeFull = 3,
    optimizeCustom = 4
};

enum inlineExpansionOption
{
    expandDisable = 0,
    expandOnlyInline = 1,
    expandAnySuitable = 2
};

enum favorSizeOrSpeedOption
{
    favorNone = 0,
    favorSpeed = 1,
    favorSize = 2
};

enum preprocessOption
{
    preprocessNo = 0,
    preprocessYes = 1,
    preprocessNoLineNumbers = 2
};

enum cppExceptionHandling
{
    cppExceptionHandlingNo = 0,
    cppExceptionHandlingYes = 1,
    cppExceptionHandlingYesWithSEH = 2
};

enum basicRuntimeCheckOption
{
    runtimeBasicCheckNone = 0,
    runtimeCheckStackFrame = 1,
    runtimeCheckUninitVariables = 2,
    runtimeBasicCheckAll = 3
};

enum runtimeLibraryOption
{
    rtMultiThreaded = 0,
    rtMultiThreadedDebug = 1,
    rtMultiThreadedDLL = 2,
    rtMultiThreadedDebugDLL = 3
};

enum structMemberAlignOption
{
    alignNotSet = 0,
    alignSingleByte = 1,
    alignTwoBytes = 2,
    alignFourBytes = 3,
    alignEightBytes = 4,
    alignSixteenBytes = 5
};

enum floatingPointModel
{
    FloatingPointPrecise = 0,
    FloatingPointStrict = 1,
    FloatingPointFast = 2
};

enum pchOption
{
    pchNone = 0,
    pchCreateUsingSpecific = 1,
    pchUseUsingSpecific = 2
};

enum asmListingOption
{
    asmListingNone = 0,
    asmListingAssemblyOnly = 1,
    asmListingAsmMachineSrc = 2,
    asmListingAsmMachine = 3,
    asmListingAsmSrc = 4
};

enum browseInfoOption
{
    brInfoNone = 0,
    brAllInfo = 1,
    brNoLocalSymbols = 2
};

enum callingConventionOption
{
    callConventionCDecl = 0,
    callConventionFastCall = 1,
    callConventionStdCall = 2
};

enum CompileAsOptions
{
    compileAsDefault = 0,
    compileAsC = 1,
    compileAsCPlusPlus = 2
};

enum enhancedInstructionSetType
{
    enhancedInstructionSetTypeNotSet = 0,
    enhancedInstructionSetTypeSIMD = 1,
    enhancedInstructionSetTypeSIMD2 = 2
};

enum compilerErrorReportingType
{
    compilerErrorReportingDefault = 0,
    compilerErrorReportingPrompt = 1,
    compilerErrorReportingQueue = 2
};

struct __declspec(uuid("80b63513-3e87-44a5-8e12-4ba7f981153e"))
VCCLCompilerTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_WarningLevel (
        /*[out,retval]*/ enum warningLevelOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_WarningLevel (
        /*[in]*/ enum warningLevelOption optSetting ) = 0;
      virtual HRESULT __stdcall get_WarnAsError (
        /*[out,retval]*/ VARIANT_BOOL * WarnAsError ) = 0;
      virtual HRESULT __stdcall put_WarnAsError (
        /*[in]*/ VARIANT_BOOL WarnAsError ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_Detect64BitPortabilityProblems (
        /*[out,retval]*/ VARIANT_BOOL * DetectPortabilityProblems ) = 0;
      virtual HRESULT __stdcall put_Detect64BitPortabilityProblems (
        /*[in]*/ VARIANT_BOOL DetectPortabilityProblems ) = 0;
      virtual HRESULT __stdcall get_DebugInformationFormat (
        /*[out,retval]*/ enum debugOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_DebugInformationFormat (
        /*[in]*/ enum debugOption optSetting ) = 0;
      virtual HRESULT __stdcall get_CompileAsManaged (
        /*[out,retval]*/ enum compileAsManagedOptions * optSetting ) = 0;
      virtual HRESULT __stdcall put_CompileAsManaged (
        /*[in]*/ enum compileAsManagedOptions optSetting ) = 0;
      virtual HRESULT __stdcall get_AdditionalIncludeDirectories (
        /*[out,retval]*/ BSTR * IncludePath ) = 0;
      virtual HRESULT __stdcall put_AdditionalIncludeDirectories (
        /*[in]*/ BSTR IncludePath ) = 0;
      virtual HRESULT __stdcall get_AdditionalUsingDirectories (
        /*[out,retval]*/ BSTR * IncludePath ) = 0;
      virtual HRESULT __stdcall put_AdditionalUsingDirectories (
        /*[in]*/ BSTR IncludePath ) = 0;
      virtual HRESULT __stdcall get_Optimization (
        /*[out,retval]*/ enum optimizeOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_Optimization (
        /*[in]*/ enum optimizeOption optSetting ) = 0;
      virtual HRESULT __stdcall get_InlineFunctionExpansion (
        /*[out,retval]*/ enum inlineExpansionOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_InlineFunctionExpansion (
        /*[in]*/ enum inlineExpansionOption optSetting ) = 0;
      virtual HRESULT __stdcall get_EnableIntrinsicFunctions (
        /*[out,retval]*/ VARIANT_BOOL * enableIntrinsic ) = 0;
      virtual HRESULT __stdcall put_EnableIntrinsicFunctions (
        /*[in]*/ VARIANT_BOOL enableIntrinsic ) = 0;
      virtual HRESULT __stdcall get_FavorSizeOrSpeed (
        /*[out,retval]*/ enum favorSizeOrSpeedOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_FavorSizeOrSpeed (
        /*[in]*/ enum favorSizeOrSpeedOption optSetting ) = 0;
      virtual HRESULT __stdcall get_OmitFramePointers (
        /*[out,retval]*/ VARIANT_BOOL * optSetting ) = 0;
      virtual HRESULT __stdcall put_OmitFramePointers (
        /*[in]*/ VARIANT_BOOL optSetting ) = 0;
      virtual HRESULT __stdcall get_EnableFiberSafeOptimizations (
        /*[out,retval]*/ VARIANT_BOOL * enable ) = 0;
      virtual HRESULT __stdcall put_EnableFiberSafeOptimizations (
        /*[in]*/ VARIANT_BOOL enable ) = 0;
      virtual HRESULT __stdcall get_WholeProgramOptimization (
        /*[out,retval]*/ VARIANT_BOOL * wholeProgOp ) = 0;
      virtual HRESULT __stdcall put_WholeProgramOptimization (
        /*[in]*/ VARIANT_BOOL wholeProgOp ) = 0;
      virtual HRESULT __stdcall get_PreprocessorDefinitions (
        /*[out,retval]*/ BSTR * Defines ) = 0;
      virtual HRESULT __stdcall put_PreprocessorDefinitions (
        /*[in]*/ BSTR Defines ) = 0;
      virtual HRESULT __stdcall get_IgnoreStandardIncludePath (
        /*[out,retval]*/ VARIANT_BOOL * bIgnoreInclPath ) = 0;
      virtual HRESULT __stdcall put_IgnoreStandardIncludePath (
        /*[in]*/ VARIANT_BOOL bIgnoreInclPath ) = 0;
      virtual HRESULT __stdcall get_GeneratePreprocessedFile (
        /*[out,retval]*/ enum preprocessOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_GeneratePreprocessedFile (
        /*[in]*/ enum preprocessOption optSetting ) = 0;
      virtual HRESULT __stdcall get_KeepComments (
        /*[out,retval]*/ VARIANT_BOOL * bkeepComments ) = 0;
      virtual HRESULT __stdcall put_KeepComments (
        /*[in]*/ VARIANT_BOOL bkeepComments ) = 0;
      virtual HRESULT __stdcall get_StringPooling (
        /*[out,retval]*/ VARIANT_BOOL * optSetting ) = 0;
      virtual HRESULT __stdcall put_StringPooling (
        /*[in]*/ VARIANT_BOOL optSetting ) = 0;
      virtual HRESULT __stdcall get_MinimalRebuild (
        /*[out,retval]*/ VARIANT_BOOL * MinimalRebuild ) = 0;
      virtual HRESULT __stdcall put_MinimalRebuild (
        /*[in]*/ VARIANT_BOOL MinimalRebuild ) = 0;
      virtual HRESULT __stdcall get_ExceptionHandling (
        /*[out,retval]*/ enum cppExceptionHandling * optSetting ) = 0;
      virtual HRESULT __stdcall put_ExceptionHandling (
        /*[in]*/ enum cppExceptionHandling optSetting ) = 0;
      virtual HRESULT __stdcall get_BasicRuntimeChecks (
        /*[out,retval]*/ enum basicRuntimeCheckOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_BasicRuntimeChecks (
        /*[in]*/ enum basicRuntimeCheckOption optSetting ) = 0;
      virtual HRESULT __stdcall get_SmallerTypeCheck (
        /*[out,retval]*/ VARIANT_BOOL * smallerType ) = 0;
      virtual HRESULT __stdcall put_SmallerTypeCheck (
        /*[in]*/ VARIANT_BOOL smallerType ) = 0;
      virtual HRESULT __stdcall get_RuntimeLibrary (
        /*[out,retval]*/ enum runtimeLibraryOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_RuntimeLibrary (
        /*[in]*/ enum runtimeLibraryOption optSetting ) = 0;
      virtual HRESULT __stdcall get_StructMemberAlignment (
        /*[out,retval]*/ enum structMemberAlignOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_StructMemberAlignment (
        /*[in]*/ enum structMemberAlignOption optSetting ) = 0;
      virtual HRESULT __stdcall get_BufferSecurityCheck (
        /*[out,retval]*/ VARIANT_BOOL * Secure ) = 0;
      virtual HRESULT __stdcall put_BufferSecurityCheck (
        /*[in]*/ VARIANT_BOOL Secure ) = 0;
      virtual HRESULT __stdcall get_EnableFunctionLevelLinking (
        /*[out,retval]*/ VARIANT_BOOL * enable ) = 0;
      virtual HRESULT __stdcall put_EnableFunctionLevelLinking (
        /*[in]*/ VARIANT_BOOL enable ) = 0;
      virtual HRESULT __stdcall get_floatingPointModel (
        /*[out,retval]*/ enum floatingPointModel * fp ) = 0;
      virtual HRESULT __stdcall put_floatingPointModel (
        /*[in]*/ enum floatingPointModel fp ) = 0;
      virtual HRESULT __stdcall get_FloatingPointExceptions (
        /*[out,retval]*/ VARIANT_BOOL * enable ) = 0;
      virtual HRESULT __stdcall put_FloatingPointExceptions (
        /*[in]*/ VARIANT_BOOL enable ) = 0;
      virtual HRESULT __stdcall get_DisableLanguageExtensions (
        /*[out,retval]*/ VARIANT_BOOL * DisableExtensions ) = 0;
      virtual HRESULT __stdcall put_DisableLanguageExtensions (
        /*[in]*/ VARIANT_BOOL DisableExtensions ) = 0;
      virtual HRESULT __stdcall get_DefaultCharIsUnsigned (
        /*[out,retval]*/ VARIANT_BOOL * IsUnsigned ) = 0;
      virtual HRESULT __stdcall put_DefaultCharIsUnsigned (
        /*[in]*/ VARIANT_BOOL IsUnsigned ) = 0;
      virtual HRESULT __stdcall get_TreatWChar_tAsBuiltInType (
        /*[out,retval]*/ VARIANT_BOOL * BuiltInType ) = 0;
      virtual HRESULT __stdcall put_TreatWChar_tAsBuiltInType (
        /*[in]*/ VARIANT_BOOL BuiltInType ) = 0;
      virtual HRESULT __stdcall get_ForceConformanceInForLoopScope (
        /*[out,retval]*/ VARIANT_BOOL * conform ) = 0;
      virtual HRESULT __stdcall put_ForceConformanceInForLoopScope (
        /*[in]*/ VARIANT_BOOL conform ) = 0;
      virtual HRESULT __stdcall get_RuntimeTypeInfo (
        /*[out,retval]*/ VARIANT_BOOL * RTTI ) = 0;
      virtual HRESULT __stdcall put_RuntimeTypeInfo (
        /*[in]*/ VARIANT_BOOL RTTI ) = 0;
      virtual HRESULT __stdcall get_OpenMP (
        /*[out,retval]*/ VARIANT_BOOL * OpenMP ) = 0;
      virtual HRESULT __stdcall put_OpenMP (
        /*[in]*/ VARIANT_BOOL OpenMP ) = 0;
      virtual HRESULT __stdcall get_UsePrecompiledHeader (
        /*[out,retval]*/ enum pchOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_UsePrecompiledHeader (
        /*[in]*/ enum pchOption optSetting ) = 0;
      virtual HRESULT __stdcall get_PrecompiledHeaderThrough (
        /*[out,retval]*/ BSTR * File ) = 0;
      virtual HRESULT __stdcall put_PrecompiledHeaderThrough (
        /*[in]*/ BSTR File ) = 0;
      virtual HRESULT __stdcall get_PrecompiledHeaderFile (
        /*[out,retval]*/ BSTR * PCH ) = 0;
      virtual HRESULT __stdcall put_PrecompiledHeaderFile (
        /*[in]*/ BSTR PCH ) = 0;
      virtual HRESULT __stdcall get_ExpandAttributedSource (
        /*[out,retval]*/ VARIANT_BOOL * bExpandAttributedSource ) = 0;
      virtual HRESULT __stdcall put_ExpandAttributedSource (
        /*[in]*/ VARIANT_BOOL bExpandAttributedSource ) = 0;
      virtual HRESULT __stdcall get_AssemblerOutput (
        /*[out,retval]*/ enum asmListingOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_AssemblerOutput (
        /*[in]*/ enum asmListingOption optSetting ) = 0;
      virtual HRESULT __stdcall get_AssemblerListingLocation (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_AssemblerListingLocation (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_ObjectFile (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_ObjectFile (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_ProgramDataBaseFileName (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_ProgramDataBaseFileName (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_BrowseInformation (
        /*[out,retval]*/ enum browseInfoOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_BrowseInformation (
        /*[in]*/ enum browseInfoOption optSetting ) = 0;
      virtual HRESULT __stdcall get_BrowseInformationFile (
        /*[out,retval]*/ BSTR * File ) = 0;
      virtual HRESULT __stdcall put_BrowseInformationFile (
        /*[in]*/ BSTR File ) = 0;
      virtual HRESULT __stdcall get_CallingConvention (
        /*[out,retval]*/ enum callingConventionOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_CallingConvention (
        /*[in]*/ enum callingConventionOption optSetting ) = 0;
      virtual HRESULT __stdcall get_CompileAs (
        /*[out,retval]*/ enum CompileAsOptions * CompileAs ) = 0;
      virtual HRESULT __stdcall put_CompileAs (
        /*[in]*/ enum CompileAsOptions CompileAs ) = 0;
      virtual HRESULT __stdcall get_DisableSpecificWarnings (
        /*[out,retval]*/ BSTR * warnings ) = 0;
      virtual HRESULT __stdcall put_DisableSpecificWarnings (
        /*[in]*/ BSTR warnings ) = 0;
      virtual HRESULT __stdcall get_ForcedIncludeFiles (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_ForcedIncludeFiles (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_ForcedUsingFiles (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_ForcedUsingFiles (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_ShowIncludes (
        /*[out,retval]*/ VARIANT_BOOL * ShowInc ) = 0;
      virtual HRESULT __stdcall put_ShowIncludes (
        /*[in]*/ VARIANT_BOOL ShowInc ) = 0;
      virtual HRESULT __stdcall get_UndefinePreprocessorDefinitions (
        /*[out,retval]*/ BSTR * Undefines ) = 0;
      virtual HRESULT __stdcall put_UndefinePreprocessorDefinitions (
        /*[in]*/ BSTR Undefines ) = 0;
      virtual HRESULT __stdcall get_UndefineAllPreprocessorDefinitions (
        /*[out,retval]*/ VARIANT_BOOL * undefinePredefinedMacros ) = 0;
      virtual HRESULT __stdcall put_UndefineAllPreprocessorDefinitions (
        /*[in]*/ VARIANT_BOOL undefinePredefinedMacros ) = 0;
      virtual HRESULT __stdcall get_EnablePREfast (
        /*[out,retval]*/ VARIANT_BOOL * pbEnablePREfast ) = 0;
      virtual HRESULT __stdcall put_EnablePREfast (
        /*[in]*/ VARIANT_BOOL pbEnablePREfast ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_FullIncludePath (
        /*[out,retval]*/ BSTR * FullIncludePath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_CompileOnly (
        /*[out,retval]*/ VARIANT_BOOL * CompileOnly ) = 0;
      virtual HRESULT __stdcall put_CompileOnly (
        /*[in]*/ VARIANT_BOOL CompileOnly ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_EnableEnhancedInstructionSet (
        /*[out,retval]*/ enum enhancedInstructionSetType * setType ) = 0;
      virtual HRESULT __stdcall put_EnableEnhancedInstructionSet (
        /*[in]*/ enum enhancedInstructionSetType setType ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
      virtual HRESULT __stdcall get_UseUnicodeResponseFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall put_UseUnicodeResponseFiles (
        /*[in]*/ VARIANT_BOOL pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall get_GenerateXMLDocumentationFiles (
        /*[out,retval]*/ VARIANT_BOOL * GenerateDocumentationFiles ) = 0;
      virtual HRESULT __stdcall put_GenerateXMLDocumentationFiles (
        /*[in]*/ VARIANT_BOOL GenerateDocumentationFiles ) = 0;
      virtual HRESULT __stdcall get_XMLDocumentationFileName (
        /*[out,retval]*/ BSTR * DocumentFile ) = 0;
      virtual HRESULT __stdcall put_XMLDocumentationFileName (
        /*[in]*/ BSTR DocumentFile ) = 0;
      virtual HRESULT __stdcall get_UseFullPaths (
        /*[out,retval]*/ VARIANT_BOOL * UseFullPaths ) = 0;
      virtual HRESULT __stdcall put_UseFullPaths (
        /*[in]*/ VARIANT_BOOL UseFullPaths ) = 0;
      virtual HRESULT __stdcall get_OmitDefaultLibName (
        /*[out,retval]*/ VARIANT_BOOL * omit ) = 0;
      virtual HRESULT __stdcall put_OmitDefaultLibName (
        /*[in]*/ VARIANT_BOOL omit ) = 0;
      virtual HRESULT __stdcall get_ErrorReporting (
        /*[out,retval]*/ enum compilerErrorReportingType * type ) = 0;
      virtual HRESULT __stdcall put_ErrorReporting (
        /*[in]*/ enum compilerErrorReportingType type ) = 0;
};

enum midlWarningLevelOption
{
    midlWarningLevel_0 = 0,
    midlWarningLevel_1 = 1,
    midlWarningLevel_2 = 2,
    midlWarningLevel_3 = 3,
    midlWarningLevel_4 = 4
};

enum midlCharOption
{
    midlCharUnsigned = 0,
    midlCharSigned = 1,
    midlCharAscii7 = 2
};

enum midlTargetEnvironment
{
    midlTargetNotSet = 0,
    midlTargetWin32 = 1,
    midlTargetIA64 = 2,
    midlTargetAMD64 = 3
};

enum midlErrorCheckOption
{
    midlEnableCustom = 0,
    midlDisableAll = 1,
    midlEnableAll = 2
};

enum midlStructMemberAlignOption
{
    midlAlignNotSet = 0,
    midlAlignSingleByte = 1,
    midlAlignTwoBytes = 2,
    midlAlignFourBytes = 3,
    midlAlignEightBytes = 4
};

struct __declspec(uuid("2d745b8b-c934-47bd-ba16-ec0514ae4914"))
VCMidlTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_PreprocessorDefinitions (
        /*[out,retval]*/ BSTR * Defines ) = 0;
      virtual HRESULT __stdcall put_PreprocessorDefinitions (
        /*[in]*/ BSTR Defines ) = 0;
      virtual HRESULT __stdcall get_AdditionalIncludeDirectories (
        /*[out,retval]*/ BSTR * IncludePath ) = 0;
      virtual HRESULT __stdcall put_AdditionalIncludeDirectories (
        /*[in]*/ BSTR IncludePath ) = 0;
      virtual HRESULT __stdcall get_IgnoreStandardIncludePath (
        /*[out,retval]*/ VARIANT_BOOL * Ignore ) = 0;
      virtual HRESULT __stdcall put_IgnoreStandardIncludePath (
        /*[in]*/ VARIANT_BOOL Ignore ) = 0;
      virtual HRESULT __stdcall get_MkTypLibCompatible (
        /*[out,retval]*/ VARIANT_BOOL * Compatible ) = 0;
      virtual HRESULT __stdcall put_MkTypLibCompatible (
        /*[in]*/ VARIANT_BOOL Compatible ) = 0;
      virtual HRESULT __stdcall get_WarningLevel (
        /*[out,retval]*/ enum midlWarningLevelOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_WarningLevel (
        /*[in]*/ enum midlWarningLevelOption optSetting ) = 0;
      virtual HRESULT __stdcall get_WarnAsError (
        /*[out,retval]*/ VARIANT_BOOL * WarnAsError ) = 0;
      virtual HRESULT __stdcall put_WarnAsError (
        /*[in]*/ VARIANT_BOOL WarnAsError ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_DefaultCharType (
        /*[out,retval]*/ enum midlCharOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_DefaultCharType (
        /*[in]*/ enum midlCharOption optSetting ) = 0;
      virtual HRESULT __stdcall get_TargetEnvironment (
        /*[out,retval]*/ enum midlTargetEnvironment * optSetting ) = 0;
      virtual HRESULT __stdcall put_TargetEnvironment (
        /*[in]*/ enum midlTargetEnvironment optSetting ) = 0;
      virtual HRESULT __stdcall get_GenerateStublessProxies (
        /*[out,retval]*/ VARIANT_BOOL * optSetting ) = 0;
      virtual HRESULT __stdcall put_GenerateStublessProxies (
        /*[in]*/ VARIANT_BOOL optSetting ) = 0;
      virtual HRESULT __stdcall get_OutputDirectory (
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall put_OutputDirectory (
        /*[in]*/ BSTR Out ) = 0;
      virtual HRESULT __stdcall get_HeaderFileName (
        /*[out,retval]*/ BSTR * HeaderFile ) = 0;
      virtual HRESULT __stdcall put_HeaderFileName (
        /*[in]*/ BSTR HeaderFile ) = 0;
      virtual HRESULT __stdcall get_DLLDataFileName (
        /*[out,retval]*/ BSTR * DLLData ) = 0;
      virtual HRESULT __stdcall put_DLLDataFileName (
        /*[in]*/ BSTR DLLData ) = 0;
      virtual HRESULT __stdcall get_InterfaceIdentifierFileName (
        /*[out,retval]*/ BSTR * IID ) = 0;
      virtual HRESULT __stdcall put_InterfaceIdentifierFileName (
        /*[in]*/ BSTR IID ) = 0;
      virtual HRESULT __stdcall get_ProxyFileName (
        /*[out,retval]*/ BSTR * ProxyFile ) = 0;
      virtual HRESULT __stdcall put_ProxyFileName (
        /*[in]*/ BSTR ProxyFile ) = 0;
      virtual HRESULT __stdcall get_GenerateTypeLibrary (
        /*[out,retval]*/ VARIANT_BOOL * optSetting ) = 0;
      virtual HRESULT __stdcall put_GenerateTypeLibrary (
        /*[in]*/ VARIANT_BOOL optSetting ) = 0;
      virtual HRESULT __stdcall get_TypeLibraryName (
        /*[out,retval]*/ BSTR * TLBFile ) = 0;
      virtual HRESULT __stdcall put_TypeLibraryName (
        /*[in]*/ BSTR TLBFile ) = 0;
      virtual HRESULT __stdcall get_EnableErrorChecks (
        /*[out,retval]*/ enum midlErrorCheckOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_EnableErrorChecks (
        /*[in]*/ enum midlErrorCheckOption optSetting ) = 0;
      virtual HRESULT __stdcall get_ErrorCheckAllocations (
        /*[out,retval]*/ VARIANT_BOOL * errorCheck ) = 0;
      virtual HRESULT __stdcall put_ErrorCheckAllocations (
        /*[in]*/ VARIANT_BOOL errorCheck ) = 0;
      virtual HRESULT __stdcall get_ErrorCheckBounds (
        /*[out,retval]*/ VARIANT_BOOL * errorCheck ) = 0;
      virtual HRESULT __stdcall put_ErrorCheckBounds (
        /*[in]*/ VARIANT_BOOL errorCheck ) = 0;
      virtual HRESULT __stdcall get_ErrorCheckEnumRange (
        /*[out,retval]*/ VARIANT_BOOL * errorCheck ) = 0;
      virtual HRESULT __stdcall put_ErrorCheckEnumRange (
        /*[in]*/ VARIANT_BOOL errorCheck ) = 0;
      virtual HRESULT __stdcall get_ErrorCheckRefPointers (
        /*[out,retval]*/ VARIANT_BOOL * errorCheck ) = 0;
      virtual HRESULT __stdcall put_ErrorCheckRefPointers (
        /*[in]*/ VARIANT_BOOL errorCheck ) = 0;
      virtual HRESULT __stdcall get_ErrorCheckStubData (
        /*[out,retval]*/ VARIANT_BOOL * errorCheck ) = 0;
      virtual HRESULT __stdcall put_ErrorCheckStubData (
        /*[in]*/ VARIANT_BOOL errorCheck ) = 0;
      virtual HRESULT __stdcall get_ValidateParameters (
        /*[out,retval]*/ VARIANT_BOOL * Validate ) = 0;
      virtual HRESULT __stdcall put_ValidateParameters (
        /*[in]*/ VARIANT_BOOL Validate ) = 0;
      virtual HRESULT __stdcall get_RedirectOutputAndErrors (
        /*[out,retval]*/ BSTR * Output ) = 0;
      virtual HRESULT __stdcall put_RedirectOutputAndErrors (
        /*[in]*/ BSTR Output ) = 0;
      virtual HRESULT __stdcall get_StructMemberAlignment (
        /*[out,retval]*/ enum midlStructMemberAlignOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_StructMemberAlignment (
        /*[in]*/ enum midlStructMemberAlignOption optSetting ) = 0;
      virtual HRESULT __stdcall get_CPreprocessOptions (
        /*[out,retval]*/ BSTR * Opt ) = 0;
      virtual HRESULT __stdcall put_CPreprocessOptions (
        /*[in]*/ BSTR Opt ) = 0;
      virtual HRESULT __stdcall get_UndefinePreprocessorDefinitions (
        /*[out,retval]*/ BSTR * Undefines ) = 0;
      virtual HRESULT __stdcall put_UndefinePreprocessorDefinitions (
        /*[in]*/ BSTR Undefines ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_FullIncludePath (
        /*[out,retval]*/ BSTR * FullIncludePath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

enum linkProgressOption
{
    linkProgressNotSet = 0,
    linkProgressAll = 1,
    linkProgressLibs = 2
};

enum linkIncrementalType
{
    linkIncrementalDefault = 0,
    linkIncrementalNo = 1,
    linkIncrementalYes = 2
};

enum subSystemOption
{
    subSystemNotSet = 0,
    subSystemConsole = 1,
    subSystemWindows = 2,
    subSystemNative = 3,
    subSystemEFIApplication = 4,
    subSystemEFIBootService = 5,
    subSystemEFIROM = 6,
    subSystemEFIRuntime = 7,
    subSystemWindowsCE = 8,
    subSystemPosix = 9
};

enum addressAwarenessType
{
    addrAwareDefault = 0,
    addrAwareNoLarge = 1,
    addrAwareLarge = 2
};

enum termSvrAwarenessType
{
    termSvrAwareDefault = 0,
    termSvrAwareNo = 1,
    termSvrAwareYes = 2
};

enum driverOption
{
    driverDefault = 0,
    driver = 1,
    driverUpOnly = 2,
    driverWDM = 3
};

enum optRefType
{
    optReferencesDefault = 0,
    optNoReferences = 1,
    optReferences = 2
};

enum optFoldingType
{
    optFoldingDefault = 0,
    optNoFolding = 1,
    optFolding = 2
};

enum optWin98Type
{
    optWin98Default = 0,
    optWin98No = 1,
    optWin98Yes = 2
};

enum LinkTimeCodeGenerationOption
{
    LinkTimeCodeGenerationOptionDefault = 0,
    LinkTimeCodeGenerationOptionUse = 1,
    LinkTimeCodeGenerationOptionInstrument = 2,
    LinkTimeCodeGenerationOptionOptimize = 3,
    LinkTimeCodeGenerationOptionUpdate = 4
};

enum machineTypeOption
{
    machineNotSet = 0,
    machineX86 = 1,
    machineAM33 = 2,
    machineARM = 3,
    machineEBC = 4,
    machineIA64 = 5,
    machineM32R = 6,
    machineMIPS = 7,
    machineMIPS16 = 8,
    machineMIPSFPU = 9,
    machineMIPSFPU16 = 10,
    machineMIPSR41XX = 11,
    machineSH3 = 12,
    machineSH3DSP = 13,
    machineSH4 = 14,
    machineSH5 = 15,
    machineTHUMB = 16,
    machineAMD64 = 17
};

enum eCLRThreadAttribute
{
    CLRThreadAttributeNone = 0,
    CLRThreadAttributeMTA = 1,
    CLRThreadAttributeSTA = 2
};

enum eCLRImageType
{
    CLRImageTypeDefault = 0,
    CLRImageTypeIJW = 1,
    CLRImageTypePure = 2,
    CLRImageTypeSafe = 3
};

enum enumRandomizedBaseAddressBOOL
{
    RandomizedBaseAddressDefault = 0,
    RandomizedBaseAddressNo = 1,
    RandomizedBaseAddressYes = 2
};

enum linkFixedBaseAddress
{
    linkFixedBaseAddressDefault = 0,
    linkFixedBaseAddressNo = 1,
    linkFixedBaseAddressYes = 2
};

enum enumDataExecutionPreventionBOOL
{
    DataExecutionPreventionDefault = 0,
    DataExecutionPreventionNo = 1,
    DataExecutionPreventionYes = 2
};

enum linkAssemblyDebug
{
    linkAssemblyDebugDefault = 0,
    linkAssemblyDebugFull = 1,
    linkAssemblyDebugDisable = 2
};

enum linkerErrorReportingType
{
    linkerErrorReportingDefault = 0,
    linkerErrorReportingPrompt = 1,
    linkerErrorReportingQueue = 2
};

enum linkUACExecutionLevel
{
    linkUACExecutionLevelAsInvoker = 0,
    linkUACExecutionLevelHighestAvailable = 1,
    linkUACExecutionLevelRequireAdministrator = 2
};

struct __declspec(uuid("6590d9e4-516e-447e-a9d9-a32c15bc562b"))
VCLinkerTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_OutputFile (
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall put_OutputFile (
        /*[in]*/ BSTR Out ) = 0;
      virtual HRESULT __stdcall get_ShowProgress (
        /*[out,retval]*/ enum linkProgressOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_ShowProgress (
        /*[in]*/ enum linkProgressOption optSetting ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * Version ) = 0;
      virtual HRESULT __stdcall put_Version (
        /*[in]*/ BSTR Version ) = 0;
      virtual HRESULT __stdcall get_LinkIncremental (
        /*[out,retval]*/ enum linkIncrementalType * optSetting ) = 0;
      virtual HRESULT __stdcall put_LinkIncremental (
        /*[in]*/ enum linkIncrementalType optSetting ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_IgnoreImportLibrary (
        /*[out,retval]*/ VARIANT_BOOL * IgnoreImportLib ) = 0;
      virtual HRESULT __stdcall put_IgnoreImportLibrary (
        /*[in]*/ VARIANT_BOOL IgnoreImportLib ) = 0;
      virtual HRESULT __stdcall get_RegisterOutput (
        /*[out,retval]*/ VARIANT_BOOL * doRegister ) = 0;
      virtual HRESULT __stdcall put_RegisterOutput (
        /*[in]*/ VARIANT_BOOL doRegister ) = 0;
      virtual HRESULT __stdcall get_PerUserRedirection (
        /*[out,retval]*/ VARIANT_BOOL * pbPerUserRedirection ) = 0;
      virtual HRESULT __stdcall put_PerUserRedirection (
        /*[in]*/ VARIANT_BOOL pbPerUserRedirection ) = 0;
      virtual HRESULT __stdcall get_AdditionalLibraryDirectories (
        /*[out,retval]*/ BSTR * LibPath ) = 0;
      virtual HRESULT __stdcall put_AdditionalLibraryDirectories (
        /*[in]*/ BSTR LibPath ) = 0;
      virtual HRESULT __stdcall get_LinkDLL (
        /*[out,retval]*/ VARIANT_BOOL * buildDLL ) = 0;
      virtual HRESULT __stdcall put_LinkDLL (
        /*[in]*/ VARIANT_BOOL buildDLL ) = 0;
      virtual HRESULT __stdcall get_AdditionalDependencies (
        /*[out,retval]*/ BSTR * Dependencies ) = 0;
      virtual HRESULT __stdcall put_AdditionalDependencies (
        /*[in]*/ BSTR Dependencies ) = 0;
      virtual HRESULT __stdcall get_IgnoreAllDefaultLibraries (
        /*[out,retval]*/ VARIANT_BOOL * NoDefaults ) = 0;
      virtual HRESULT __stdcall put_IgnoreAllDefaultLibraries (
        /*[in]*/ VARIANT_BOOL NoDefaults ) = 0;
      virtual HRESULT __stdcall get_IgnoreDefaultLibraryNames (
        /*[out,retval]*/ BSTR * Lib ) = 0;
      virtual HRESULT __stdcall put_IgnoreDefaultLibraryNames (
        /*[in]*/ BSTR Lib ) = 0;
      virtual HRESULT __stdcall get_ModuleDefinitionFile (
        /*[out,retval]*/ BSTR * DefFile ) = 0;
      virtual HRESULT __stdcall put_ModuleDefinitionFile (
        /*[in]*/ BSTR DefFile ) = 0;
      virtual HRESULT __stdcall get_AddModuleNamesToAssembly (
        /*[out,retval]*/ BSTR * moduleName ) = 0;
      virtual HRESULT __stdcall put_AddModuleNamesToAssembly (
        /*[in]*/ BSTR moduleName ) = 0;
      virtual HRESULT __stdcall get_EmbedManagedResourceFile (
        /*[out,retval]*/ BSTR * Res ) = 0;
      virtual HRESULT __stdcall put_EmbedManagedResourceFile (
        /*[in]*/ BSTR Res ) = 0;
      virtual HRESULT __stdcall get_ForceSymbolReferences (
        /*[out,retval]*/ BSTR * Symbol ) = 0;
      virtual HRESULT __stdcall put_ForceSymbolReferences (
        /*[in]*/ BSTR Symbol ) = 0;
      virtual HRESULT __stdcall get_DelayLoadDLLs (
        /*[out,retval]*/ BSTR * DLLName ) = 0;
      virtual HRESULT __stdcall put_DelayLoadDLLs (
        /*[in]*/ BSTR DLLName ) = 0;
      virtual HRESULT __stdcall get_MidlCommandFile (
        /*[out,retval]*/ BSTR * MidlCmdFile ) = 0;
      virtual HRESULT __stdcall put_MidlCommandFile (
        /*[in]*/ BSTR MidlCmdFile ) = 0;
      virtual HRESULT __stdcall get_IgnoreEmbeddedIDL (
        /*[out,retval]*/ VARIANT_BOOL * IgnoreIDL ) = 0;
      virtual HRESULT __stdcall put_IgnoreEmbeddedIDL (
        /*[in]*/ VARIANT_BOOL IgnoreIDL ) = 0;
      virtual HRESULT __stdcall get_MergedIDLBaseFileName (
        /*[out,retval]*/ BSTR * IDLFile ) = 0;
      virtual HRESULT __stdcall put_MergedIDLBaseFileName (
        /*[in]*/ BSTR IDLFile ) = 0;
      virtual HRESULT __stdcall get_TypeLibraryFile (
        /*[out,retval]*/ BSTR * TLBFile ) = 0;
      virtual HRESULT __stdcall put_TypeLibraryFile (
        /*[in]*/ BSTR TLBFile ) = 0;
      virtual HRESULT __stdcall get_TypeLibraryResourceID (
        /*[out,retval]*/ long * ResourceID ) = 0;
      virtual HRESULT __stdcall put_TypeLibraryResourceID (
        /*[in]*/ long ResourceID ) = 0;
      virtual HRESULT __stdcall get_GenerateDebugInformation (
        /*[out,retval]*/ VARIANT_BOOL * genDebug ) = 0;
      virtual HRESULT __stdcall put_GenerateDebugInformation (
        /*[in]*/ VARIANT_BOOL genDebug ) = 0;
      virtual HRESULT __stdcall get_ProgramDatabaseFile (
        /*[out,retval]*/ BSTR * File ) = 0;
      virtual HRESULT __stdcall put_ProgramDatabaseFile (
        /*[in]*/ BSTR File ) = 0;
      virtual HRESULT __stdcall get_StripPrivateSymbols (
        /*[out,retval]*/ BSTR * StrippedPDB ) = 0;
      virtual HRESULT __stdcall put_StripPrivateSymbols (
        /*[in]*/ BSTR StrippedPDB ) = 0;
      virtual HRESULT __stdcall get_GenerateMapFile (
        /*[out,retval]*/ VARIANT_BOOL * Map ) = 0;
      virtual HRESULT __stdcall put_GenerateMapFile (
        /*[in]*/ VARIANT_BOOL Map ) = 0;
      virtual HRESULT __stdcall get_MapFileName (
        /*[out,retval]*/ BSTR * MapFile ) = 0;
      virtual HRESULT __stdcall put_MapFileName (
        /*[in]*/ BSTR MapFile ) = 0;
      virtual HRESULT __stdcall get_MapExports (
        /*[out,retval]*/ VARIANT_BOOL * Exports ) = 0;
      virtual HRESULT __stdcall put_MapExports (
        /*[in]*/ VARIANT_BOOL Exports ) = 0;
      virtual HRESULT __stdcall get_SubSystem (
        /*[out,retval]*/ enum subSystemOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_SubSystem (
        /*[in]*/ enum subSystemOption optSetting ) = 0;
      virtual HRESULT __stdcall get_HeapReserveSize (
        /*[out,retval]*/ long * ReserveSize ) = 0;
      virtual HRESULT __stdcall put_HeapReserveSize (
        /*[in]*/ long ReserveSize ) = 0;
      virtual HRESULT __stdcall get_HeapCommitSize (
        /*[out,retval]*/ long * CommitSize ) = 0;
      virtual HRESULT __stdcall put_HeapCommitSize (
        /*[in]*/ long CommitSize ) = 0;
      virtual HRESULT __stdcall get_StackReserveSize (
        /*[out,retval]*/ long * ReserveSize ) = 0;
      virtual HRESULT __stdcall put_StackReserveSize (
        /*[in]*/ long ReserveSize ) = 0;
      virtual HRESULT __stdcall get_StackCommitSize (
        /*[out,retval]*/ long * CommitSize ) = 0;
      virtual HRESULT __stdcall put_StackCommitSize (
        /*[in]*/ long CommitSize ) = 0;
      virtual HRESULT __stdcall get_LargeAddressAware (
        /*[out,retval]*/ enum addressAwarenessType * optSetting ) = 0;
      virtual HRESULT __stdcall put_LargeAddressAware (
        /*[in]*/ enum addressAwarenessType optSetting ) = 0;
      virtual HRESULT __stdcall get_TerminalServerAware (
        /*[out,retval]*/ enum termSvrAwarenessType * optSetting ) = 0;
      virtual HRESULT __stdcall put_TerminalServerAware (
        /*[in]*/ enum termSvrAwarenessType optSetting ) = 0;
      virtual HRESULT __stdcall get_SwapRunFromCD (
        /*[out,retval]*/ VARIANT_BOOL * Run ) = 0;
      virtual HRESULT __stdcall put_SwapRunFromCD (
        /*[in]*/ VARIANT_BOOL Run ) = 0;
      virtual HRESULT __stdcall get_SwapRunFromNet (
        /*[out,retval]*/ VARIANT_BOOL * Run ) = 0;
      virtual HRESULT __stdcall put_SwapRunFromNet (
        /*[in]*/ VARIANT_BOOL Run ) = 0;
      virtual HRESULT __stdcall get_driver (
        /*[out,retval]*/ enum driverOption * pDriver ) = 0;
      virtual HRESULT __stdcall put_driver (
        /*[in]*/ enum driverOption pDriver ) = 0;
      virtual HRESULT __stdcall get_OptimizeReferences (
        /*[out,retval]*/ enum optRefType * optSetting ) = 0;
      virtual HRESULT __stdcall put_OptimizeReferences (
        /*[in]*/ enum optRefType optSetting ) = 0;
      virtual HRESULT __stdcall get_EnableCOMDATFolding (
        /*[out,retval]*/ enum optFoldingType * optSetting ) = 0;
      virtual HRESULT __stdcall put_EnableCOMDATFolding (
        /*[in]*/ enum optFoldingType optSetting ) = 0;
      virtual HRESULT __stdcall get_OptimizeForWindows98 (
        /*[out,retval]*/ enum optWin98Type * optSetting ) = 0;
      virtual HRESULT __stdcall put_OptimizeForWindows98 (
        /*[in]*/ enum optWin98Type optSetting ) = 0;
      virtual HRESULT __stdcall get_FunctionOrder (
        /*[out,retval]*/ BSTR * Order ) = 0;
      virtual HRESULT __stdcall put_FunctionOrder (
        /*[in]*/ BSTR Order ) = 0;
      virtual HRESULT __stdcall get_LinkTimeCodeGeneration (
        /*[out,retval]*/ enum LinkTimeCodeGenerationOption * CodeGen ) = 0;
      virtual HRESULT __stdcall put_LinkTimeCodeGeneration (
        /*[in]*/ enum LinkTimeCodeGenerationOption CodeGen ) = 0;
      virtual HRESULT __stdcall get_EntryPointSymbol (
        /*[out,retval]*/ BSTR * Entry ) = 0;
      virtual HRESULT __stdcall put_EntryPointSymbol (
        /*[in]*/ BSTR Entry ) = 0;
      virtual HRESULT __stdcall get_ResourceOnlyDLL (
        /*[out,retval]*/ VARIANT_BOOL * NoEntry ) = 0;
      virtual HRESULT __stdcall put_ResourceOnlyDLL (
        /*[in]*/ VARIANT_BOOL NoEntry ) = 0;
      virtual HRESULT __stdcall get_SetChecksum (
        /*[out,retval]*/ VARIANT_BOOL * Release ) = 0;
      virtual HRESULT __stdcall put_SetChecksum (
        /*[in]*/ VARIANT_BOOL Release ) = 0;
      virtual HRESULT __stdcall get_BaseAddress (
        /*[out,retval]*/ BSTR * Address ) = 0;
      virtual HRESULT __stdcall put_BaseAddress (
        /*[in]*/ BSTR Address ) = 0;
      virtual HRESULT __stdcall get_TurnOffAssemblyGeneration (
        /*[out,retval]*/ VARIANT_BOOL * noAssembly ) = 0;
      virtual HRESULT __stdcall put_TurnOffAssemblyGeneration (
        /*[in]*/ VARIANT_BOOL noAssembly ) = 0;
      virtual HRESULT __stdcall get_SupportUnloadOfDelayLoadedDLL (
        /*[out,retval]*/ VARIANT_BOOL * supportUnload ) = 0;
      virtual HRESULT __stdcall put_SupportUnloadOfDelayLoadedDLL (
        /*[in]*/ VARIANT_BOOL supportUnload ) = 0;
      virtual HRESULT __stdcall get_ImportLibrary (
        /*[out,retval]*/ BSTR * ImportLib ) = 0;
      virtual HRESULT __stdcall put_ImportLibrary (
        /*[in]*/ BSTR ImportLib ) = 0;
      virtual HRESULT __stdcall get_MergeSections (
        /*[out,retval]*/ BSTR * Merge ) = 0;
      virtual HRESULT __stdcall put_MergeSections (
        /*[in]*/ BSTR Merge ) = 0;
      virtual HRESULT __stdcall get_TargetMachine (
        /*[out,retval]*/ enum machineTypeOption * optSetting ) = 0;
      virtual HRESULT __stdcall put_TargetMachine (
        /*[in]*/ enum machineTypeOption optSetting ) = 0;
      virtual HRESULT __stdcall get_Profile (
        /*[out,retval]*/ VARIANT_BOOL * Profile ) = 0;
      virtual HRESULT __stdcall put_Profile (
        /*[in]*/ VARIANT_BOOL Profile ) = 0;
      virtual HRESULT __stdcall get_CLRThreadAttribute (
        /*[out,retval]*/ enum eCLRThreadAttribute * ta ) = 0;
      virtual HRESULT __stdcall put_CLRThreadAttribute (
        /*[in]*/ enum eCLRThreadAttribute ta ) = 0;
      virtual HRESULT __stdcall get_CLRImageType (
        /*[out,retval]*/ enum eCLRImageType * ta ) = 0;
      virtual HRESULT __stdcall put_CLRImageType (
        /*[in]*/ enum eCLRImageType ta ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR PropName,
        /*[in]*/ long PropID,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_RandomizedBaseAddress (
        /*[out,retval]*/ enum enumRandomizedBaseAddressBOOL * pbRandomizedBaseAddress ) = 0;
      virtual HRESULT __stdcall put_RandomizedBaseAddress (
        /*[in]*/ enum enumRandomizedBaseAddressBOOL pbRandomizedBaseAddress ) = 0;
      virtual HRESULT __stdcall get_FixedBaseAddress (
        /*[out,retval]*/ enum linkFixedBaseAddress * Fixed ) = 0;
      virtual HRESULT __stdcall put_FixedBaseAddress (
        /*[in]*/ enum linkFixedBaseAddress Fixed ) = 0;
      virtual HRESULT __stdcall get_DataExecutionPrevention (
        /*[out,retval]*/ enum enumDataExecutionPreventionBOOL * pbDataExecutionPrevention ) = 0;
      virtual HRESULT __stdcall put_DataExecutionPrevention (
        /*[in]*/ enum enumDataExecutionPreventionBOOL pbDataExecutionPrevention ) = 0;
      virtual HRESULT __stdcall get_AssemblyDebug (
        /*[out,retval]*/ enum linkAssemblyDebug * AssemblyDebug ) = 0;
      virtual HRESULT __stdcall put_AssemblyDebug (
        /*[in]*/ enum linkAssemblyDebug AssemblyDebug ) = 0;
      virtual HRESULT __stdcall get_AssemblyLinkResource (
        /*[out,retval]*/ BSTR * AssemblyLinkResource ) = 0;
      virtual HRESULT __stdcall put_AssemblyLinkResource (
        /*[in]*/ BSTR AssemblyLinkResource ) = 0;
      virtual HRESULT __stdcall get_LinkLibraryDependencies (
        /*[out,retval]*/ VARIANT_BOOL * LinkLibraryDependencies ) = 0;
      virtual HRESULT __stdcall put_LinkLibraryDependencies (
        /*[in]*/ VARIANT_BOOL LinkLibraryDependencies ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
      virtual HRESULT __stdcall put_KeyFile (
        /*[in]*/ BSTR KeyFile ) = 0;
      virtual HRESULT __stdcall get_KeyFile (
        /*[out,retval]*/ BSTR * KeyFile ) = 0;
      virtual HRESULT __stdcall put_KeyContainer (
        /*[in]*/ BSTR KeyContainer ) = 0;
      virtual HRESULT __stdcall get_KeyContainer (
        /*[out,retval]*/ BSTR * KeyContainer ) = 0;
      virtual HRESULT __stdcall put_DelaySign (
        /*[in]*/ VARIANT_BOOL DelaySign ) = 0;
      virtual HRESULT __stdcall get_DelaySign (
        /*[out,retval]*/ VARIANT_BOOL * DelaySign ) = 0;
      virtual HRESULT __stdcall get_UseUnicodeResponseFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall put_UseUnicodeResponseFiles (
        /*[in]*/ VARIANT_BOOL pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall get_ProfileGuidedDatabase (
        /*[out,retval]*/ BSTR * pbstrDatabaseFile ) = 0;
      virtual HRESULT __stdcall put_ProfileGuidedDatabase (
        /*[in]*/ BSTR pbstrDatabaseFile ) = 0;
      virtual HRESULT __stdcall get_GenerateManifest (
        /*[out,retval]*/ VARIANT_BOOL * GenerateManifest ) = 0;
      virtual HRESULT __stdcall put_GenerateManifest (
        /*[in]*/ VARIANT_BOOL GenerateManifest ) = 0;
      virtual HRESULT __stdcall get_ManifestFile (
        /*[out,retval]*/ BSTR * ManifestFile ) = 0;
      virtual HRESULT __stdcall put_ManifestFile (
        /*[in]*/ BSTR ManifestFile ) = 0;
      virtual HRESULT __stdcall get_AdditionalManifestDependencies (
        /*[out,retval]*/ BSTR * Dependencies ) = 0;
      virtual HRESULT __stdcall put_AdditionalManifestDependencies (
        /*[in]*/ BSTR Dependencies ) = 0;
      virtual HRESULT __stdcall get_AllowIsolation (
        /*[out,retval]*/ VARIANT_BOOL * AllowIsolation ) = 0;
      virtual HRESULT __stdcall put_AllowIsolation (
        /*[in]*/ VARIANT_BOOL AllowIsolation ) = 0;
      virtual HRESULT __stdcall get_ErrorReporting (
        /*[out,retval]*/ enum linkerErrorReportingType * type ) = 0;
      virtual HRESULT __stdcall put_ErrorReporting (
        /*[in]*/ enum linkerErrorReportingType type ) = 0;
      virtual HRESULT __stdcall get_UseLibraryDependencyInputs (
        /*[out,retval]*/ VARIANT_BOOL * UseLibraryDependencyInputs ) = 0;
      virtual HRESULT __stdcall put_UseLibraryDependencyInputs (
        /*[in]*/ VARIANT_BOOL UseLibraryDependencyInputs ) = 0;
      virtual HRESULT __stdcall get_CLRUnmanagedCodeCheck (
        /*[out,retval]*/ VARIANT_BOOL * bVal ) = 0;
      virtual HRESULT __stdcall put_CLRUnmanagedCodeCheck (
        /*[in]*/ VARIANT_BOOL bVal ) = 0;
      virtual HRESULT __stdcall get_EnableUAC (
        /*[out,retval]*/ VARIANT_BOOL * EnableUAC ) = 0;
      virtual HRESULT __stdcall put_EnableUAC (
        /*[in]*/ VARIANT_BOOL EnableUAC ) = 0;
      virtual HRESULT __stdcall get_UACExecutionLevel (
        /*[out,retval]*/ enum linkUACExecutionLevel * UACExecutionLevel ) = 0;
      virtual HRESULT __stdcall put_UACExecutionLevel (
        /*[in]*/ enum linkUACExecutionLevel UACExecutionLevel ) = 0;
      virtual HRESULT __stdcall get_UACUIAccess (
        /*[out,retval]*/ VARIANT_BOOL * UACUIAccess ) = 0;
      virtual HRESULT __stdcall put_UACUIAccess (
        /*[in]*/ VARIANT_BOOL UACUIAccess ) = 0;
};

enum enumResourceLangID
{
    rcUseDefault = 0,
    rcAfrikaans = 1078,
    rcAlbanian = 1052,
    rcArabicSaudi = 1025,
    rcArabicIraq = 2049,
    rcArabicEgypt = 3073,
    rcArabicLibya = 4097,
    rcArabicAlgeria = 5121,
    rcArabicMorocco = 6145,
    rcArabicTunisia = 7169,
    rcArabicOman = 8193,
    rcArabicYemen = 9217,
    rcArabicSyria = 10241,
    rcArabicJordan = 11265,
    rcArabicLebanon = 12289,
    rcArabicKuwait = 13313,
    rcArabicUnitedArabEmirates = 14337,
    rcArabicBahrain = 15361,
    rcArabicQatar = 16385,
    rcBasque = 1069,
    rcBulgarian = 1026,
    rcBelarusian = 1059,
    rcCatalan = 1027,
    rcChineseTaiwan = 1028,
    rcChinesePRC = 2052,
    rcChineseHongKong = 3076,
    rcChineseSingapore = 4100,
    rcCroatian = 1050,
    rcCzech = 1029,
    rcDanish = 1030,
    rcDutchStandard = 1043,
    rcDutchBelgium = 2067,
    rcEnglishUS = 1033,
    rcEnglishBritain = 2057,
    rcEnglishAustralia = 3081,
    rcEnglishCanada = 4105,
    rcEnglishNewZealand = 5129,
    rcEnglishIreland = 6153,
    rcEnglishSouthAfrica = 7177,
    rcEnglishJamaica = 8201,
    rcEnglishCarribean = 9225,
    rcEstonian = 1061,
    rcPersian = 1065,
    rcFinnish = 1035,
    rcFrenchStandard = 1036,
    rcFrenchBelgium = 2060,
    rcFrenchCanada = 3084,
    rcFrenchSwitzerland = 4108,
    rcFrenchLuxembourg = 5132,
    rcGermanStandard = 1031,
    rcGermanSwitzerland = 2055,
    rcGermanAustria = 3079,
    rcGermanLuxembourg = 4103,
    rcGermanLichtenstein = 5127,
    rcGreek = 1032,
    rcHebrew = 1037,
    rcHungarian = 1038,
    rcIcelandic = 1039,
    rcIndonesian = 1057,
    rcItalianStandard = 1040,
    rcItalianSwitzerland = 2064,
    rcJapanese = 1041,
    rcKorean = 1042,
    rcLatvian = 1062,
    rcLithuanian = 1063,
    rcNorwegianBokmal = 1044,
    rcNorwegianNynorsk = 2068,
    rcPolish = 1045,
    rcPortugueseBrazilian = 1046,
    rcPortugueseStandard = 2070,
    rcRomanian = 1048,
    rcRussian = 1049,
    rcSlovak = 1051,
    rcSpanishTraditional = 1034,
    rcSpanishMexico = 2058,
    rcSpanishModern = 3082,
    rcSpanishGuatemala = 4106,
    rcSpanishCostaRica = 5130,
    rcSpanishPanama = 6154,
    rcSpanishDominicanRepublic = 7178,
    rcSpanishVenezuela = 8202,
    rcSpanishColombia = 9226,
    rcSpanishPeru = 10250,
    rcSpanishArgentina = 11274,
    rcSpanishEcuador = 12298,
    rcSpanishChile = 13322,
    rcSpanishUruguay = 14346,
    rcSpanishParaguay = 15370,
    rcSpanishBolivia = 16394,
    rcSwedish = 1053,
    rcThai = 1054,
    rcTurkish = 1055,
    rcUkrainian = 1058,
    rcSerbian = 2074,
    rcUrdu = 1056
};

struct __declspec(uuid("e202e5ca-684b-4d9a-9485-6a2eee4937b6"))
VCResourceCompilerTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * AdditionalOptions ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR AdditionalOptions ) = 0;
      virtual HRESULT __stdcall get_PreprocessorDefinitions (
        /*[out,retval]*/ BSTR * Defines ) = 0;
      virtual HRESULT __stdcall put_PreprocessorDefinitions (
        /*[in]*/ BSTR Defines ) = 0;
      virtual HRESULT __stdcall get_Culture (
        /*[out,retval]*/ enum enumResourceLangID * LangID ) = 0;
      virtual HRESULT __stdcall put_Culture (
        /*[in]*/ enum enumResourceLangID LangID ) = 0;
      virtual HRESULT __stdcall get_AdditionalIncludeDirectories (
        /*[out,retval]*/ BSTR * IncludePath ) = 0;
      virtual HRESULT __stdcall put_AdditionalIncludeDirectories (
        /*[in]*/ BSTR IncludePath ) = 0;
      virtual HRESULT __stdcall get_IgnoreStandardIncludePath (
        /*[out,retval]*/ VARIANT_BOOL * IgnoreInclPath ) = 0;
      virtual HRESULT __stdcall put_IgnoreStandardIncludePath (
        /*[in]*/ VARIANT_BOOL IgnoreInclPath ) = 0;
      virtual HRESULT __stdcall get_ShowProgress (
        /*[out,retval]*/ VARIANT_BOOL * ShowProgress ) = 0;
      virtual HRESULT __stdcall put_ShowProgress (
        /*[in]*/ VARIANT_BOOL ShowProgress ) = 0;
      virtual HRESULT __stdcall get_ResourceOutputFileName (
        /*[out,retval]*/ BSTR * ResFile ) = 0;
      virtual HRESULT __stdcall put_ResourceOutputFileName (
        /*[in]*/ BSTR ResFile ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_FullIncludePath (
        /*[out,retval]*/ BSTR * FullIncludePath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("f5b8d246-74c0-4fd7-8522-3ecfd3e08a2d"))
VCCustomBuildTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_CommandLine (
        /*[out,retval]*/ BSTR * cmdLine ) = 0;
      virtual HRESULT __stdcall put_CommandLine (
        /*[in]*/ BSTR cmdLine ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * Desc ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR Desc ) = 0;
      virtual HRESULT __stdcall get_Outputs (
        /*[out,retval]*/ BSTR * Outputs ) = 0;
      virtual HRESULT __stdcall put_Outputs (
        /*[in]*/ BSTR Outputs ) = 0;
      virtual HRESULT __stdcall get_AdditionalDependencies (
        /*[out,retval]*/ BSTR * Dependencies ) = 0;
      virtual HRESULT __stdcall put_AdditionalDependencies (
        /*[in]*/ BSTR Dependencies ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("2cf0e564-48be-4244-a99a-2ecaf22139bb"))
VCALinkTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_OutputBaseFileName (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("ac6c847a-a0f3-41d4-bd1e-53739b146dea"))
VCManagedResourceCompilerTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ResourceFileName (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall put_ResourceFileName (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_OutputFileName (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall get_DefaultLocalizedResources (
        /*[out,retval]*/ VARIANT_BOOL * defaultResources ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("80c80c10-3270-4c8d-9653-fd75aa55e79a"))
VCManifestTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_VerboseOutput (
        /*[out,retval]*/ VARIANT_BOOL * VerboseOutput ) = 0;
      virtual HRESULT __stdcall put_VerboseOutput (
        /*[in]*/ VARIANT_BOOL VerboseOutput ) = 0;
      virtual HRESULT __stdcall get_GenerateCatalogFiles (
        /*[out,retval]*/ VARIANT_BOOL * GenerateCatalogs ) = 0;
      virtual HRESULT __stdcall put_GenerateCatalogFiles (
        /*[in]*/ VARIANT_BOOL GenerateCatalogs ) = 0;
      virtual HRESULT __stdcall get_OutputManifestFile (
        /*[out,retval]*/ BSTR * OutputFile ) = 0;
      virtual HRESULT __stdcall put_OutputManifestFile (
        /*[in]*/ BSTR OutputFile ) = 0;
      virtual HRESULT __stdcall get_UpdateFileHashes (
        /*[out,retval]*/ VARIANT_BOOL * UpdateHashes ) = 0;
      virtual HRESULT __stdcall put_UpdateFileHashes (
        /*[in]*/ VARIANT_BOOL UpdateHashes ) = 0;
      virtual HRESULT __stdcall get_UpdateFileHashesSearchPath (
        /*[out,retval]*/ BSTR * UpdateHashesSearchPath ) = 0;
      virtual HRESULT __stdcall put_UpdateFileHashesSearchPath (
        /*[in]*/ BSTR UpdateHashesSearchPath ) = 0;
      virtual HRESULT __stdcall get_AssemblyIdentity (
        /*[out,retval]*/ BSTR * Identity ) = 0;
      virtual HRESULT __stdcall put_AssemblyIdentity (
        /*[in]*/ BSTR Identity ) = 0;
      virtual HRESULT __stdcall get_ReplacementsFile (
        /*[out,retval]*/ BSTR * Replacements ) = 0;
      virtual HRESULT __stdcall put_ReplacementsFile (
        /*[in]*/ BSTR Replacements ) = 0;
      virtual HRESULT __stdcall get_TypeLibraryFile (
        /*[out,retval]*/ BSTR * TypeLibrary ) = 0;
      virtual HRESULT __stdcall put_TypeLibraryFile (
        /*[in]*/ BSTR TypeLibrary ) = 0;
      virtual HRESULT __stdcall get_RegistrarScriptFile (
        /*[out,retval]*/ BSTR * RegScript ) = 0;
      virtual HRESULT __stdcall put_RegistrarScriptFile (
        /*[in]*/ BSTR RegScript ) = 0;
      virtual HRESULT __stdcall get_AdditionalManifestFiles (
        /*[out,retval]*/ BSTR * AdditionalManifests ) = 0;
      virtual HRESULT __stdcall put_AdditionalManifestFiles (
        /*[in]*/ BSTR AdditionalManifests ) = 0;
      virtual HRESULT __stdcall get_InputResourceManifests (
        /*[out,retval]*/ BSTR * InputManifests ) = 0;
      virtual HRESULT __stdcall put_InputResourceManifests (
        /*[in]*/ BSTR InputManifests ) = 0;
      virtual HRESULT __stdcall get_EmbedManifest (
        /*[out,retval]*/ VARIANT_BOOL * EmbedManifest ) = 0;
      virtual HRESULT __stdcall put_EmbedManifest (
        /*[in]*/ VARIANT_BOOL EmbedManifest ) = 0;
      virtual HRESULT __stdcall get_DependencyInformationFile (
        /*[out,retval]*/ BSTR * DependencyFile ) = 0;
      virtual HRESULT __stdcall put_DependencyInformationFile (
        /*[in]*/ BSTR DependencyFile ) = 0;
      virtual HRESULT __stdcall get_ComponentFileName (
        /*[out,retval]*/ BSTR * ComponentFileName ) = 0;
      virtual HRESULT __stdcall put_ComponentFileName (
        /*[in]*/ BSTR ComponentFileName ) = 0;
      virtual HRESULT __stdcall get_ManifestResourceFile (
        /*[out,retval]*/ BSTR * ManifestResourceFile ) = 0;
      virtual HRESULT __stdcall put_ManifestResourceFile (
        /*[in]*/ BSTR ManifestResourceFile ) = 0;
      virtual HRESULT __stdcall get_UseUnicodeResponseFiles (
        /*[out,retval]*/ VARIANT_BOOL * UseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall put_UseUnicodeResponseFiles (
        /*[in]*/ VARIANT_BOOL UseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall get_UseFAT32Workaround (
        /*[out,retval]*/ VARIANT_BOOL * UseWorkaround ) = 0;
      virtual HRESULT __stdcall put_UseFAT32Workaround (
        /*[in]*/ VARIANT_BOOL UseWorkaround ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("0f297231-6269-41e0-80e1-ed7c483f6560"))
VCXDCMakeTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_ValidateIntelliSense (
        /*[out,retval]*/ VARIANT_BOOL * Validate ) = 0;
      virtual HRESULT __stdcall put_ValidateIntelliSense (
        /*[in]*/ VARIANT_BOOL Validate ) = 0;
      virtual HRESULT __stdcall get_AdditionalDocumentFiles (
        /*[out,retval]*/ BSTR * AdditionalFiles ) = 0;
      virtual HRESULT __stdcall put_AdditionalDocumentFiles (
        /*[in]*/ BSTR AdditionalFiles ) = 0;
      virtual HRESULT __stdcall get_OutputDocumentFile (
        /*[out,retval]*/ BSTR * OutputFile ) = 0;
      virtual HRESULT __stdcall put_OutputDocumentFile (
        /*[in]*/ BSTR OutputFile ) = 0;
      virtual HRESULT __stdcall get_DocumentLibraryDependencies (
        /*[out,retval]*/ VARIANT_BOOL * DocDependencies ) = 0;
      virtual HRESULT __stdcall put_DocumentLibraryDependencies (
        /*[in]*/ VARIANT_BOOL DocDependencies ) = 0;
      virtual HRESULT __stdcall get_UseUnicodeResponseFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall put_UseUnicodeResponseFiles (
        /*[in]*/ VARIANT_BOOL pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

enum eWebRefUrlBehavior
{
    eStaticUrl = 0,
    eDynamicUrl = 1
};

struct __declspec(uuid("719a2ede-6e72-43ec-ab20-351e7c358f89"))
VCFilter : VCProjectItem
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_UniqueIdentifier (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_UniqueIdentifier (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_CanonicalName (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall Remove ( ) = 0;
      virtual HRESULT __stdcall get_Filter (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_Filter (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_Filters (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_Files (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddFilter (
        BSTR bstrName,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall CanAddFilter (
        /*[in]*/ BSTR Filter,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall AddFile (
        BSTR bstrPath,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall CanAddFile (
        /*[in]*/ BSTR bstrFile,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall RemoveFile (
        /*[in]*/ IDispatch * File ) = 0;
      virtual HRESULT __stdcall RemoveFilter (
        /*[in]*/ IDispatch * Filter ) = 0;
      virtual HRESULT __stdcall get_Items (
        /*[out,retval]*/ IDispatch * * Items ) = 0;
      virtual HRESULT __stdcall get_ParseFiles (
        /*[out,retval]*/ VARIANT_BOOL * Parse ) = 0;
      virtual HRESULT __stdcall put_ParseFiles (
        /*[in]*/ VARIANT_BOOL Parse ) = 0;
      virtual HRESULT __stdcall get_SourceControlFiles (
        /*[out,retval]*/ VARIANT_BOOL * SCC ) = 0;
      virtual HRESULT __stdcall put_SourceControlFiles (
        /*[in]*/ VARIANT_BOOL SCC ) = 0;
      virtual HRESULT __stdcall AddWebReference (
        /*[in]*/ BSTR bstrUrl,
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ IDispatch * * File ) = 0;
      virtual HRESULT __stdcall Move (
        /*[in]*/ IDispatch * Parent ) = 0;
      virtual HRESULT __stdcall CanMove (
        /*[in]*/ IDispatch * Parent,
        /*[out,retval]*/ VARIANT_BOOL * CanMove ) = 0;
      virtual HRESULT __stdcall get_Object (
        /*[out,retval]*/ IDispatch * * vsObject ) = 0;
      virtual HRESULT __stdcall get_WebReference (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_UrlBehavior (
        /*[out,retval]*/ enum eWebRefUrlBehavior * pVal ) = 0;
};

struct __declspec(uuid("4e6ce19b-dcc9-40db-b321-3c6f60f89a6f"))
VCPreBuildEventTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_CommandLine (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_CommandLine (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ExcludedFromBuild (
        /*[out,retval]*/ VARIANT_BOOL * bExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall put_ExcludedFromBuild (
        /*[in]*/ VARIANT_BOOL bExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("4cb3265a-dd3b-4f1e-bef8-88b68f27118d"))
VCPreLinkEventTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_CommandLine (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_CommandLine (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ExcludedFromBuild (
        /*[out,retval]*/ VARIANT_BOOL * bExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall put_ExcludedFromBuild (
        /*[in]*/ VARIANT_BOOL bExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("74d00da0-092b-4b51-a4d5-134233aebdf4"))
VCPostBuildEventTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_CommandLine (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_CommandLine (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ExcludedFromBuild (
        /*[out,retval]*/ VARIANT_BOOL * bExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall put_ExcludedFromBuild (
        /*[in]*/ VARIANT_BOOL bExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("af958e5b-cab8-4aaa-9f6a-fb2fbadecd6e"))
VCBscMakeTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_OutputFile (
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall put_OutputFile (
        /*[in]*/ BSTR Out ) = 0;
      virtual HRESULT __stdcall get_DEPRECATED1 (
        /*[out,retval]*/ VARIANT_BOOL * Run ) = 0;
      virtual HRESULT __stdcall put_DEPRECATED1 (
        /*[in]*/ VARIANT_BOOL Run ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("bf75c368-74db-4a28-9fda-3b5b76f8eee9"))
VCLibrarianTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AdditionalOptions (
        /*[out,retval]*/ BSTR * options ) = 0;
      virtual HRESULT __stdcall put_AdditionalOptions (
        /*[in]*/ BSTR options ) = 0;
      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_OutputFile (
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall put_OutputFile (
        /*[in]*/ BSTR Out ) = 0;
      virtual HRESULT __stdcall get_AdditionalDependencies (
        /*[out,retval]*/ BSTR * Dependencies ) = 0;
      virtual HRESULT __stdcall put_AdditionalDependencies (
        /*[in]*/ BSTR Dependencies ) = 0;
      virtual HRESULT __stdcall get_AdditionalLibraryDirectories (
        /*[out,retval]*/ BSTR * LibPath ) = 0;
      virtual HRESULT __stdcall put_AdditionalLibraryDirectories (
        /*[in]*/ BSTR LibPath ) = 0;
      virtual HRESULT __stdcall get_SuppressStartupBanner (
        /*[out,retval]*/ VARIANT_BOOL * NoLogo ) = 0;
      virtual HRESULT __stdcall put_SuppressStartupBanner (
        /*[in]*/ VARIANT_BOOL NoLogo ) = 0;
      virtual HRESULT __stdcall get_ModuleDefinitionFile (
        /*[out,retval]*/ BSTR * DefFile ) = 0;
      virtual HRESULT __stdcall put_ModuleDefinitionFile (
        /*[in]*/ BSTR DefFile ) = 0;
      virtual HRESULT __stdcall get_IgnoreAllDefaultLibraries (
        /*[out,retval]*/ VARIANT_BOOL * NoDefault ) = 0;
      virtual HRESULT __stdcall put_IgnoreAllDefaultLibraries (
        /*[in]*/ VARIANT_BOOL NoDefault ) = 0;
      virtual HRESULT __stdcall get_IgnoreDefaultLibraryNames (
        /*[out,retval]*/ BSTR * Lib ) = 0;
      virtual HRESULT __stdcall put_IgnoreDefaultLibraryNames (
        /*[in]*/ BSTR Lib ) = 0;
      virtual HRESULT __stdcall get_ExportNamedFunctions (
        /*[out,retval]*/ BSTR * Symbols ) = 0;
      virtual HRESULT __stdcall put_ExportNamedFunctions (
        /*[in]*/ BSTR Symbols ) = 0;
      virtual HRESULT __stdcall get_ForceSymbolReferences (
        /*[out,retval]*/ BSTR * Symbol ) = 0;
      virtual HRESULT __stdcall put_ForceSymbolReferences (
        /*[in]*/ BSTR Symbol ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_PropertyOption (
        /*[in]*/ BSTR Prop,
        /*[in]*/ long dispidProp,
        /*[out,retval]*/ BSTR * propVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
      virtual HRESULT __stdcall get_UseUnicodeResponseFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall put_UseUnicodeResponseFiles (
        /*[in]*/ VARIANT_BOOL pbUseUnicodeRSP ) = 0;
      virtual HRESULT __stdcall get_LinkTimeCodeGeneration (
        /*[out,retval]*/ VARIANT_BOOL * CodeGen ) = 0;
      virtual HRESULT __stdcall put_LinkTimeCodeGeneration (
        /*[in]*/ VARIANT_BOOL CodeGen ) = 0;
      virtual HRESULT __stdcall get_Inputs (
        /*[out,retval]*/ BSTR * Inputs ) = 0;
      virtual HRESULT __stdcall get_LinkLibraryDependencies (
        /*[out,retval]*/ VARIANT_BOOL * LinkLibraryDependencies ) = 0;
      virtual HRESULT __stdcall put_LinkLibraryDependencies (
        /*[in]*/ VARIANT_BOOL LinkLibraryDependencies ) = 0;
};

struct __declspec(uuid("023de234-7e71-4fd3-9d29-f82edfdce51d"))
VCNMakeTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_BuildCommandLine (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_BuildCommandLine (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ReBuildCommandLine (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_ReBuildCommandLine (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_CleanCommandLine (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_CleanCommandLine (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Output (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Output (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_PreprocessorDefinitions (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_PreprocessorDefinitions (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_IncludeSearchPath (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_IncludeSearchPath (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ForcedIncludes (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_ForcedIncludes (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_AssemblySearchPath (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_AssemblySearchPath (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ForcedUsingAssemblies (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_ForcedUsingAssemblies (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_CompileAsManaged (
        /*[out,retval]*/ enum compileAsManagedOptions * optSetting ) = 0;
      virtual HRESULT __stdcall put_CompileAsManaged (
        /*[in]*/ enum compileAsManagedOptions optSetting ) = 0;
};

struct __declspec(uuid("bc0e8841-354b-4880-ae89-f724dce6e45f"))
VCFxCopTool : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_InputAssemblyFileName (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall put_InputAssemblyFileName (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_Rules (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall put_Rules (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_RuleAssemblies (
        /*[out,retval]*/ BSTR * RuleAssemblies ) = 0;
      virtual HRESULT __stdcall put_RuleAssemblies (
        /*[in]*/ BSTR RuleAssemblies ) = 0;
      virtual HRESULT __stdcall get_OutputFile (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall put_OutputFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_EnableFxCop (
        /*[out,retval]*/ VARIANT_BOOL * pbExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall put_EnableFxCop (
        /*[in]*/ VARIANT_BOOL pbExcludedFromBuild ) = 0;
      virtual HRESULT __stdcall get_IgnoreGeneratedCode (
        /*[out,retval]*/ VARIANT_BOOL * pbIgnoreGeneratedCode ) = 0;
      virtual HRESULT __stdcall put_IgnoreGeneratedCode (
        /*[in]*/ VARIANT_BOOL pbIgnoreGeneratedCode ) = 0;
      virtual HRESULT __stdcall get_FxCopUseTypeNameInSuppression (
        /*[out,retval]*/ VARIANT_BOOL * pbFxCopUseTypeNameInSuppression ) = 0;
      virtual HRESULT __stdcall put_FxCopUseTypeNameInSuppression (
        /*[in]*/ VARIANT_BOOL pbFxCopUseTypeNameInSuppression ) = 0;
      virtual HRESULT __stdcall get_FxCopModuleSuppressionsFile (
        /*[out,retval]*/ BSTR * FileName ) = 0;
      virtual HRESULT __stdcall put_FxCopModuleSuppressionsFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_OverrideRuleVisibilities (
        /*[out,retval]*/ VARIANT_BOOL * pbOverrideRuleVisibilities ) = 0;
      virtual HRESULT __stdcall put_OverrideRuleVisibilities (
        /*[in]*/ VARIANT_BOOL pbOverrideRuleVisibilities ) = 0;
      virtual HRESULT __stdcall get_Culture (
        /*[out,retval]*/ BSTR * Culture ) = 0;
      virtual HRESULT __stdcall put_Culture (
        /*[in]*/ BSTR Culture ) = 0;
      virtual HRESULT __stdcall get_Dictionaries (
        /*[out,retval]*/ BSTR * Dictionaries ) = 0;
      virtual HRESULT __stdcall put_Dictionaries (
        /*[in]*/ BSTR Dictionaries ) = 0;
      virtual HRESULT __stdcall get_toolName (
        /*[out,retval]*/ BSTR * toolName ) = 0;
      virtual HRESULT __stdcall get_ToolKind (
        /*[out,retval]*/ BSTR * ToolKind ) = 0;
      virtual HRESULT __stdcall get_ToolPath (
        /*[out,retval]*/ BSTR * ToolPath ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_ExecutionBucket (
        /*[out,retval]*/ long * pVal ) = 0;
      virtual HRESULT __stdcall put_ExecutionBucket (
        /*[in]*/ long pVal ) = 0;
};

struct __declspec(uuid("3ac4e69b-a4b0-4996-9eec-063e460b8122"))
VCFxCopTool2 : VCFxCopTool
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_RuleSet (
        /*[out,retval]*/ BSTR * pbstrRuleSet ) = 0;
      virtual HRESULT __stdcall put_RuleSet (
        /*[in]*/ BSTR pbstrRuleSet ) = 0;
      virtual HRESULT __stdcall get_RuleSetDirectories (
        /*[out,retval]*/ BSTR * pbstrRuleSetDirectories ) = 0;
      virtual HRESULT __stdcall put_RuleSetDirectories (
        /*[in]*/ BSTR pbstrRuleSetDirectories ) = 0;
      virtual HRESULT __stdcall get_IgnoreBuiltInRuleSets (
        /*[out,retval]*/ VARIANT_BOOL * pbIgnoreBuiltInRuleSets ) = 0;
      virtual HRESULT __stdcall put_IgnoreBuiltInRuleSets (
        /*[in]*/ VARIANT_BOOL pbIgnoreBuiltInRuleSets ) = 0;
      virtual HRESULT __stdcall get_RuleDirectories (
        /*[out,retval]*/ BSTR * pbstrRuleDirectories ) = 0;
      virtual HRESULT __stdcall put_RuleDirectories (
        /*[in]*/ BSTR pbstrRuleDirectories ) = 0;
      virtual HRESULT __stdcall get_IgnoreBuiltInRules (
        /*[out,retval]*/ VARIANT_BOOL * pbIgnoreBuiltInRules ) = 0;
      virtual HRESULT __stdcall put_IgnoreBuiltInRules (
        /*[in]*/ VARIANT_BOOL pbIgnoreBuiltInRules ) = 0;
      virtual HRESULT __stdcall get_FailOnMissingRules (
        /*[out,retval]*/ VARIANT_BOOL * pbFailOnMissingRules ) = 0;
      virtual HRESULT __stdcall put_FailOnMissingRules (
        /*[in]*/ VARIANT_BOOL pbFailOnMissingRules ) = 0;
};

struct __declspec(uuid("e1a22e2b-cf0f-4b23-b25c-81a91b2d0c3b"))
IVCBuildPropertyStorage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetPropertyValue (
        /*[in]*/ BSTR pszPropName,
        /*[in]*/ BSTR pszConfigName,
        /*[in]*/ BSTR storage,
        /*[out,retval]*/ BSTR * pbstrPropValue ) = 0;
      virtual HRESULT __stdcall SetPropertyValue (
        /*[in]*/ BSTR pszPropName,
        /*[in]*/ BSTR pszConfigName,
        /*[in]*/ BSTR storage,
        /*[in]*/ BSTR pszPropValue ) = 0;
      virtual HRESULT __stdcall RemoveProperty (
        /*[in]*/ BSTR pszPropName,
        /*[in]*/ BSTR pszConfigName,
        /*[in]*/ BSTR storage ) = 0;
};

struct __declspec(uuid("e642c68e-b883-4f4f-b946-787a07fb3975"))
IVCRulePropertyStorage : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetEvaluatedPropertyValue (
        /*[in]*/ BSTR bstrPropertyName,
        /*[out,retval]*/ BSTR * pbstrEvaluatedPropertyValue ) = 0;
      virtual HRESULT __stdcall GetUnevaluatedPropertyValue (
        /*[in]*/ BSTR bstrPropertyName,
        /*[out,retval]*/ BSTR * pbstrUnevaluatedPropertyValue ) = 0;
      virtual HRESULT __stdcall SetPropertyValue (
        /*[in]*/ BSTR bstrPropertyName,
        /*[in]*/ BSTR bstrUnevaluatedPropertyValue ) = 0;
      virtual HRESULT __stdcall DeleteProperty (
        /*[in]*/ BSTR bstrPropertyName ) = 0;
};

struct __declspec(uuid("e71d6e86-89d8-4ec7-9517-8475d19737de"))
IVCRulePropertyStorage2 : IVCRulePropertyStorage
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * ruleName ) = 0;
};

struct __declspec(uuid("a801c81c-2ee5-4f46-a06e-a318cd228fe5"))
IVCIdentity : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall MatchIndex (
        /*[in]*/ IUnknown * pVal,
        /*[out,retval]*/ VARIANT_BOOL * result ) = 0;
};

struct __declspec(uuid("d3e42d89-b6cb-47b6-b09f-876f61ac5c27"))
IVCProjectTargetChange : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ApplicationType (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_ApplicationTypeRevision (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_Toolset (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
      virtual HRESULT __stdcall get_DisplayName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
};

struct __declspec(uuid("9ffeda85-27ca-46cf-aab7-7c470cecbf29"))
IVCProjectTargetDescription : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ShortDisplayName (
        /*[out,retval]*/ BSTR * pbstrVal ) = 0;
};

struct __declspec(uuid("3b621333-4aad-4d82-b865-80e5ddb2cf1e"))
IVCPropertyStorage : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetEvaluatedPropertyValue (
        /*[in]*/ BSTR bstrRuleName,
        /*[in]*/ BSTR bstrPropertyName,
        /*[out,retval]*/ BSTR * pbstrEvaluatedPropertyValue ) = 0;
      virtual HRESULT __stdcall GetEvaluatedPropertyValues (
        /*[in]*/ SAFEARRAY * bstrRuleNames,
        /*[in]*/ SAFEARRAY * bstrPropertyNames,
        /*[out,retval]*/ SAFEARRAY * * pbstrEvaluatedPropertyValues ) = 0;
      virtual HRESULT __stdcall GetRuleNames (
        /*[out,retval]*/ SAFEARRAY * * prgNames ) = 0;
      virtual HRESULT __stdcall GetRule (
        /*[in]*/ LPWSTR pszRuleName,
        /*[out,retval]*/ struct IVCRulePropertyStorage * * ppRule ) = 0;
};

enum vcRefType
{
    VCRT_ASSEMBLY = 1,
    VCRT_COM = 2,
    VCRT_PROJECT = 4,
    VCRT_WINRT = 8,
    VCRT_SDK = 16,
    VCRT_SHARED_PROJECT = 32,
    VCRT_FOREIGN_REFERENCE = 64,
    VCRT_ALL = -1
};

struct __declspec(uuid("dbf177f2-06db-4a47-8aad-c8e12bfd6c86"))
VCProject : VCProjectItem
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_ProjectDirectory (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall get_ProjectFile (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_ProjectFile (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_Platforms (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddPlatform (
        /*[in]*/ BSTR PlatformName ) = 0;
      virtual HRESULT __stdcall RemovePlatform (
        /*[in]*/ IDispatch * Platform ) = 0;
      virtual HRESULT __stdcall get_Configurations (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddConfiguration (
        BSTR ConfigurationName ) = 0;
      virtual HRESULT __stdcall RemoveConfiguration (
        IDispatch * Config ) = 0;
      virtual HRESULT __stdcall get_Files (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall CanAddFile (
        /*[in]*/ BSTR File,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall AddFile (
        BSTR bstrPath,
        /*[out,retval]*/ IDispatch * * Disp ) = 0;
      virtual HRESULT __stdcall RemoveFile (
        /*[in]*/ IDispatch * File ) = 0;
      virtual HRESULT __stdcall get_Filters (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall CanAddFilter (
        /*[in]*/ BSTR Filter,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall AddFilter (
        BSTR bstrFilterName,
        /*[out,retval]*/ IDispatch * * Disp ) = 0;
      virtual HRESULT __stdcall RemoveFilter (
        /*[in]*/ IDispatch * Filter ) = 0;
      virtual HRESULT __stdcall get_Items (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddWebReference (
        /*[in]*/ BSTR URL,
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ IDispatch * * File ) = 0;
      virtual HRESULT __stdcall Save ( ) = 0;
      virtual HRESULT __stdcall get_IsDirty (
        /*[out,retval]*/ VARIANT_BOOL * Val ) = 0;
      virtual HRESULT __stdcall get_FileFormat (
        /*[out,retval]*/ enum enumFileFormat * FileType ) = 0;
      virtual HRESULT __stdcall put_FileFormat (
        /*[in]*/ enum enumFileFormat FileType ) = 0;
      virtual HRESULT __stdcall get_FileEncoding (
        /*[out,retval]*/ BSTR * encoding ) = 0;
      virtual HRESULT __stdcall put_FileEncoding (
        /*[in]*/ BSTR encoding ) = 0;
      virtual HRESULT __stdcall SaveProjectOptions (
        /*[in]*/ IUnknown * StreamUnk ) = 0;
      virtual HRESULT __stdcall LoadProjectOptions (
        /*[in]*/ IUnknown * StreamUnk ) = 0;
      virtual HRESULT __stdcall get_SccProjectName (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_SccProjectName (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_SccAuxPath (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_SccAuxPath (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_SccLocalPath (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_SccLocalPath (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_SccProvider (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_SccProvider (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_keyword (
        /*[out,retval]*/ BSTR * keyword ) = 0;
      virtual HRESULT __stdcall put_keyword (
        /*[in]*/ BSTR keyword ) = 0;
      virtual HRESULT __stdcall put_OwnerKey (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_OwnerKey (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_ProjectGUID (
        /*[in]*/ BSTR guid ) = 0;
      virtual HRESULT __stdcall get_ProjectGUID (
        /*[out,retval]*/ BSTR * guid ) = 0;
      virtual HRESULT __stdcall AddAssemblyReference (
        /*[in]*/ BSTR Path,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddActiveXReference (
        /*[in]*/ BSTR typeLibGuid,
        /*[in]*/ long majorVersion,
        /*[in]*/ long minorVersion,
        /*[in]*/ long localeID,
        /*[in]*/ BSTR wrapper,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddProjectReference (
        /*[in]*/ IDispatch * proj,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddWinRTReference (
        /*[in]*/ BSTR Path,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall AddSdkReference (
        /*[in]*/ BSTR sdkIdentity,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall CanAddAssemblyReference (
        /*[in]*/ BSTR bstrRef,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddActiveXReference (
        /*[in]*/ BSTR typeLibGuid,
        /*[in]*/ long majorVersion,
        /*[in]*/ long minorVersion,
        /*[in]*/ long localeID,
        /*[in]*/ BSTR wrapper,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddProjectReference (
        /*[in]*/ IDispatch * proj,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddWinRTReference (
        /*[in]*/ BSTR bstrRef,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall CanAddSdkReference (
        /*[in]*/ BSTR bstrsdkIdentity,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall RemoveReference (
        /*[in]*/ IDispatch * pDispRef ) = 0;
      virtual HRESULT __stdcall get_VCReferences (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_References (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_ReferencesConsumableByDesigners (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_GetAllowedReferencesTypes (
        /*[out,retval]*/ unsigned long * dwAllowedRefTypes ) = 0;
      virtual HRESULT __stdcall put_RootNamespace (
        /*[in]*/ BSTR guid ) = 0;
      virtual HRESULT __stdcall get_RootNamespace (
        /*[out,retval]*/ BSTR * guid ) = 0;
      virtual HRESULT __stdcall get_Object (
        /*[out,retval]*/ IDispatch * * vsObject ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out]*/ long * major,
        /*[out]*/ long * minor ) = 0;
      virtual HRESULT __stdcall get_ShowAllFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbShowAllFiles ) = 0;
      virtual HRESULT __stdcall put_ShowAllFiles (
        /*[in]*/ VARIANT_BOOL pbShowAllFiles ) = 0;
      virtual HRESULT __stdcall AddToolFile (
        /*[in]*/ struct VCToolFile * ToolFile ) = 0;
      virtual HRESULT __stdcall RemoveToolFile (
        /*[in]*/ struct VCToolFile * ToolFile ) = 0;
      virtual HRESULT __stdcall get_ToolFiles (
        /*[out,retval]*/ struct IVCCollection * * ToolFiles ) = 0;
      virtual HRESULT __stdcall put_ManagedDBConnection (
        /*[in]*/ BSTR con ) = 0;
      virtual HRESULT __stdcall get_ManagedDBConnection (
        /*[out,retval]*/ BSTR * con ) = 0;
      virtual HRESULT __stdcall put_ManagedDBProvider (
        /*[in]*/ BSTR con ) = 0;
      virtual HRESULT __stdcall get_ManagedDBProvider (
        /*[out,retval]*/ BSTR * con ) = 0;
      virtual HRESULT __stdcall MakeManagedDBConnection (
        /*[in]*/ VARIANT_BOOL forceNew ) = 0;
      virtual HRESULT __stdcall get_AssemblyReferenceSearchPaths (
        /*[out,retval]*/ BSTR * Paths ) = 0;
      virtual HRESULT __stdcall put_AssemblyReferenceSearchPaths (
        /*[in]*/ BSTR Paths ) = 0;
      virtual HRESULT __stdcall LoadUserFile ( ) = 0;
      virtual HRESULT __stdcall SaveUserFile ( ) = 0;
      virtual HRESULT __stdcall IncludeHeaderFile (
        /*[in]*/ BSTR HeaderFile,
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall put_TargetFrameworkVersion (
        /*[in]*/ enum enumFrameworkVersion TargetFrameworkVersion ) = 0;
      virtual HRESULT __stdcall get_TargetFrameworkVersion (
        /*[out,retval]*/ enum enumFrameworkVersion * TargetFrameworkVersion ) = 0;
      virtual HRESULT __stdcall ContainsFileEndingWith (
        /*[in]*/ BSTR EndingWith,
        /*[out,retval]*/ VARIANT_BOOL * doesContain ) = 0;
      virtual HRESULT __stdcall ContainsFileWithItemType (
        /*[in]*/ BSTR ItemType,
        /*[out,retval]*/ VARIANT_BOOL * doesContain ) = 0;
      virtual HRESULT __stdcall GetFilesEndingWith (
        /*[in]*/ BSTR EndingWith,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall GetFilesWithItemType (
        /*[in]*/ BSTR ItemType,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_TargetFrameworkMoniker (
        /*[out,retval]*/ BSTR * pbstrTargetFrameworkMoniker ) = 0;
      virtual HRESULT __stdcall AddRuleDefinition (
        /*[in]*/ BSTR bstrRuleFilePath,
        /*[in]*/ BSTR bstrContext,
        /*[in]*/ VARIANT_BOOL bPersistInProject,
        /*[out,retval]*/ VARIANT_BOOL * bCreated ) = 0;
      virtual HRESULT __stdcall RemoveRuleDefinition (
        /*[in]*/ BSTR bstrRuleFilePath,
        /*[out,retval]*/ VARIANT_BOOL * bRemoved ) = 0;
      virtual HRESULT __stdcall GetVCService (
        /*[in]*/ GUID * guid,
        /*[out,retval]*/ IUnknown * * ppService ) = 0;
      virtual HRESULT __stdcall get_SupportedPlatformNames (
        /*[out,retval]*/ BSTR * pbstrPlatformNames ) = 0;
      virtual HRESULT __stdcall get_ActiveConfiguration (
        /*[out,retval]*/ struct VCConfiguration * * Val ) = 0;
      virtual HRESULT __stdcall FindFile (
        /*[in]*/ LPWSTR pszFileName,
        /*[out,retval]*/ struct VCFile * * Val ) = 0;
      virtual HRESULT __stdcall get_Capabilities (
        /*[out,retval]*/ BSTR * pbstrCapabilities ) = 0;
      virtual HRESULT __stdcall IsCapabilityPresent (
        /*[in]*/ BSTR bstrCapability,
        /*[out,retval]*/ VARIANT_BOOL * bCapabilityPresent ) = 0;
      virtual HRESULT __stdcall get_LatestTargetPlatformVersion (
        /*[out,retval]*/ BSTR * pbstrTargetPlatformVersion ) = 0;
};

struct __declspec(uuid("921dd76b-a230-4028-8dae-7fc88a605676"))
VCConfiguration : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * cfgName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR cfgName ) = 0;
      virtual HRESULT __stdcall get_Platform (
        /*[out,retval]*/ IDispatch * * assocPlatform ) = 0;
      virtual HRESULT __stdcall get_OutputDirectory (
        /*[out,retval]*/ BSTR * outDir ) = 0;
      virtual HRESULT __stdcall put_OutputDirectory (
        /*[in]*/ BSTR outDir ) = 0;
      virtual HRESULT __stdcall get_IntermediateDirectory (
        /*[out,retval]*/ BSTR * intDir ) = 0;
      virtual HRESULT __stdcall put_IntermediateDirectory (
        /*[in]*/ BSTR intDir ) = 0;
      virtual HRESULT __stdcall Delete ( ) = 0;
      virtual HRESULT __stdcall Build ( ) = 0;
      virtual HRESULT __stdcall Rebuild ( ) = 0;
      virtual HRESULT __stdcall Clean ( ) = 0;
      virtual HRESULT __stdcall get_DebugSettings (
        /*[out,retval]*/ IDispatch * * DbgSettings ) = 0;
      virtual HRESULT __stdcall get_PrimaryOutput (
        /*[out,retval]*/ BSTR * primaryOut ) = 0;
      virtual HRESULT __stdcall get_ImportLibrary (
        /*[out,retval]*/ BSTR * ImportLib ) = 0;
      virtual HRESULT __stdcall get_ProgramDatabase (
        /*[out,retval]*/ BSTR * PDB ) = 0;
      virtual HRESULT __stdcall get_project (
        /*[out,retval]*/ IDispatch * * proj ) = 0;
      virtual HRESULT __stdcall MatchName (
        /*[in]*/ BSTR NameToMatch,
        /*[in]*/ VARIANT_BOOL FullOnly,
        /*[out,retval]*/ VARIANT_BOOL * IsMatch ) = 0;
      virtual HRESULT __stdcall get_Tools (
        /*[out,retval]*/ IDispatch * * toolList ) = 0;
      virtual HRESULT __stdcall get_FileTools (
        /*[out,retval]*/ struct IVCCollection * * fileToolList ) = 0;
      virtual HRESULT __stdcall get_ConfigurationName (
        /*[out,retval]*/ BSTR * cfgName ) = 0;
      virtual HRESULT __stdcall put_ConfigurationName (
        /*[in]*/ BSTR cfgName ) = 0;
      virtual HRESULT __stdcall get_UpToDate (
        /*[out,retval]*/ VARIANT_BOOL * IsUpToDate ) = 0;
      virtual HRESULT __stdcall get_ConfigurationType (
        /*[out,retval]*/ enum ConfigurationTypes * ConfigType ) = 0;
      virtual HRESULT __stdcall put_ConfigurationType (
        /*[in]*/ enum ConfigurationTypes ConfigType ) = 0;
      virtual HRESULT __stdcall CopyTo (
        IDispatch * Config ) = 0;
      virtual HRESULT __stdcall get_InheritedPropertySheets (
        /*[out,retval]*/ BSTR * PropertySheets ) = 0;
      virtual HRESULT __stdcall put_InheritedPropertySheets (
        /*[in]*/ BSTR PropertySheets ) = 0;
      virtual HRESULT __stdcall get_DEPRECATED1 (
        /*[out,retval]*/ VARIANT_BOOL * Bsc ) = 0;
      virtual HRESULT __stdcall put_DEPRECATED1 (
        /*[in]*/ VARIANT_BOOL Bsc ) = 0;
      virtual HRESULT __stdcall get_useOfMfc (
        /*[out,retval]*/ enum useOfMfc * useMfc ) = 0;
      virtual HRESULT __stdcall put_useOfMfc (
        /*[in]*/ enum useOfMfc useMfc ) = 0;
      virtual HRESULT __stdcall get_useOfATL (
        /*[out,retval]*/ enum useOfATL * useATL ) = 0;
      virtual HRESULT __stdcall put_useOfATL (
        /*[in]*/ enum useOfATL useATL ) = 0;
      virtual HRESULT __stdcall get_ATLMinimizesCRunTimeLibraryUsage (
        /*[out,retval]*/ VARIANT_BOOL * UseCRT ) = 0;
      virtual HRESULT __stdcall put_ATLMinimizesCRunTimeLibraryUsage (
        /*[in]*/ VARIANT_BOOL UseCRT ) = 0;
      virtual HRESULT __stdcall get_CharacterSet (
        /*[out,retval]*/ enum charSet * optSetting ) = 0;
      virtual HRESULT __stdcall put_CharacterSet (
        /*[in]*/ enum charSet optSetting ) = 0;
      virtual HRESULT __stdcall get_ManagedExtensions (
        /*[out,retval]*/ enum compileAsManagedOptions * Managed ) = 0;
      virtual HRESULT __stdcall put_ManagedExtensions (
        /*[in]*/ enum compileAsManagedOptions Managed ) = 0;
      virtual HRESULT __stdcall get_DeleteExtensionsOnClean (
        /*[out,retval]*/ BSTR * ExtList ) = 0;
      virtual HRESULT __stdcall put_DeleteExtensionsOnClean (
        /*[in]*/ BSTR ExtList ) = 0;
      virtual HRESULT __stdcall get_WholeProgramOptimization (
        /*[out,retval]*/ enum WholeProgramOptimizationTypes * Optimize ) = 0;
      virtual HRESULT __stdcall put_WholeProgramOptimization (
        /*[in]*/ enum WholeProgramOptimizationTypes Optimize ) = 0;
      virtual HRESULT __stdcall get_RegisterOutput (
        /*[out,retval]*/ VARIANT_BOOL * doRegister ) = 0;
      virtual HRESULT __stdcall get_PerUserRedirection (
        /*[out,retval]*/ VARIANT_BOOL * doPerUserRedirection ) = 0;
      virtual HRESULT __stdcall Evaluate (
        /*[in]*/ BSTR In,
        /*[out,retval]*/ BSTR * Out ) = 0;
      virtual HRESULT __stdcall get_PropertySheets (
        /*[out,retval]*/ IDispatch * * PropertySheets ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_SatelliteDLLs (
        /*[out,retval]*/ BSTR * satellites ) = 0;
      virtual HRESULT __stdcall StopBuild ( ) = 0;
      virtual HRESULT __stdcall WaitForBuild ( ) = 0;
      virtual HRESULT __stdcall get_ExcludeBuckets (
        /*[out,retval]*/ BSTR * Buckets ) = 0;
      virtual HRESULT __stdcall put_ExcludeBuckets (
        /*[in]*/ BSTR Buckets ) = 0;
      virtual HRESULT __stdcall get_BuildLogFile (
        /*[out,retval]*/ BSTR * pbstrBuildLogFile ) = 0;
      virtual HRESULT __stdcall put_BuildLogFile (
        /*[in]*/ BSTR pbstrBuildLogFile ) = 0;
      virtual HRESULT __stdcall ClearToolProperty (
        /*[in]*/ IDispatch * pTool,
        /*[in]*/ BSTR bstrPropertyName ) = 0;
      virtual HRESULT __stdcall Deploy ( ) = 0;
      virtual HRESULT __stdcall BuildWithPropertySheet (
        /*[in]*/ struct VCPropertySheet * pPropertySheet,
        /*[in]*/ enum BuildWithPropertySheetType buildType ) = 0;
      virtual HRESULT __stdcall BuildWithPropertySheetPath (
        /*[in]*/ BSTR propertySheetPath,
        /*[in]*/ enum BuildWithPropertySheetType buildType ) = 0;
      virtual HRESULT __stdcall get_SqlDeploySource (
        /*[out,retval]*/ VARIANT_BOOL * bDeploySrc ) = 0;
      virtual HRESULT __stdcall put_SqlDeploySource (
        /*[in]*/ VARIANT_BOOL bDeploySrc ) = 0;
      virtual HRESULT __stdcall get_SqlDebugScript (
        /*[out,retval]*/ BSTR * debugScript ) = 0;
      virtual HRESULT __stdcall put_SqlDebugScript (
        /*[in]*/ BSTR debugScript ) = 0;
      virtual HRESULT __stdcall get_SqlPreDeployScript (
        /*[out,retval]*/ BSTR * preDeployScript ) = 0;
      virtual HRESULT __stdcall put_SqlPreDeployScript (
        /*[in]*/ BSTR preDeployScript ) = 0;
      virtual HRESULT __stdcall get_SqlPostDeployScript (
        /*[out,retval]*/ BSTR * postDeployScript ) = 0;
      virtual HRESULT __stdcall put_SqlPostDeployScript (
        /*[in]*/ BSTR postDeployScript ) = 0;
      virtual HRESULT __stdcall get_SqlPermissionLevel (
        /*[out,retval]*/ enum eSqlClrPermissionLevel * permission ) = 0;
      virtual HRESULT __stdcall put_SqlPermissionLevel (
        /*[in]*/ enum eSqlClrPermissionLevel permission ) = 0;
      virtual HRESULT __stdcall get_IntrinsicPropertySheets (
        /*[out,retval]*/ BSTR * PropertySheets ) = 0;
      virtual HRESULT __stdcall put_IntrinsicPropertySheets (
        /*[in]*/ BSTR PropertySheets ) = 0;
      virtual HRESULT __stdcall get_DeploymentTool (
        /*[out,retval]*/ IDispatch * * deployTool ) = 0;
      virtual HRESULT __stdcall get_SqlAssemblyOwner (
        /*[out,retval]*/ BSTR * owner ) = 0;
      virtual HRESULT __stdcall put_SqlAssemblyOwner (
        /*[in]*/ BSTR owner ) = 0;
      virtual HRESULT __stdcall Relink ( ) = 0;
      virtual HRESULT __stdcall get_EnableManagedIncrementalBuild (
        /*[out,retval]*/ enum optManagedIncrementalBuild * EnableMIB ) = 0;
      virtual HRESULT __stdcall put_EnableManagedIncrementalBuild (
        /*[in]*/ enum optManagedIncrementalBuild EnableMIB ) = 0;
      virtual HRESULT __stdcall get_Rules (
        /*[out,retval]*/ struct IVCCollection * * listRules ) = 0;
      virtual HRESULT __stdcall AddPropertySheet (
        /*[in]*/ LPWSTR FileName,
        /*[out,retval]*/ struct VCPropertySheet * * ppPropertySheet ) = 0;
      virtual HRESULT __stdcall RemovePropertySheet (
        /*[in]*/ struct VCPropertySheet * pPropertySheet,
        /*[out,retval]*/ VARIANT_BOOL * pbFound ) = 0;
      virtual HRESULT __stdcall MovePropertySheet (
        /*[in]*/ struct VCPropertySheet * pPropertySheet,
        /*[in]*/ VARIANT_BOOL bMoveImportLaterInEvaluation ) = 0;
      virtual HRESULT __stdcall IsBuildActionSupported (
        /*[in]*/ enum bldActionTypes bldType,
        /*[out,retval]*/ VARIANT_BOOL * pfBuildActionSupported ) = 0;
      virtual HRESULT __stdcall BuildWithProperty (
        /*[in]*/ enum bldActionTypes bldType,
        /*[in]*/ BSTR bstrPropertyName,
        /*[in]*/ BSTR bstrPropertyValue,
        /*[in]*/ struct IVCBuildCompleteCallback * callback ) = 0;
      virtual HRESULT __stdcall BuildAndCallback (
        /*[in]*/ enum bldActionTypes buildType,
        /*[in]*/ struct IVCBuildCompleteCallback * callback ) = 0;
      virtual HRESULT __stdcall GetEvaluatedPropertyValue (
        /*[in]*/ BSTR bstrPropertyName,
        /*[out,retval]*/ BSTR * pbstrEvaluatedPropertyValue ) = 0;
      virtual HRESULT __stdcall GetUnevaluatedPropertyValue (
        /*[in]*/ BSTR bstrPropertyName,
        /*[out,retval]*/ BSTR * pbstrUnevaluatedPropertyValue ) = 0;
      virtual HRESULT __stdcall GetVCService (
        /*[in]*/ GUID * guid,
        /*[out,retval]*/ IUnknown * * ppService ) = 0;
      virtual HRESULT __stdcall IsUpToDate (
        /*[in]*/ IUnknown * logger,
        /*[out,retval]*/ VARIANT_BOOL * IsUpToDate ) = 0;
      virtual HRESULT __stdcall CollectIntelliSenseInfo (
        /*[out,retval]*/ IUnknown * * ppIIntelliSenseInfo ) = 0;
};

struct __declspec(uuid("6eb8dcb9-f64b-471e-a295-14a41e3c099f"))
VCFile : VCProjectItem
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall Remove ( ) = 0;
      virtual HRESULT __stdcall get_RelativePath (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_RelativePath (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall get_FileConfigurations (
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall get_DeploymentContent (
        /*[out,retval]*/ VARIANT_BOOL * Val ) = 0;
      virtual HRESULT __stdcall put_DeploymentContent (
        /*[in]*/ VARIANT_BOOL Val ) = 0;
      virtual HRESULT __stdcall get_Extension (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall Move (
        /*[in]*/ IDispatch * Parent ) = 0;
      virtual HRESULT __stdcall CanMove (
        /*[in]*/ IDispatch * Parent,
        /*[out,retval]*/ VARIANT_BOOL * CanMove ) = 0;
      virtual HRESULT __stdcall get_FileType (
        /*[out,retval]*/ enum eFileType * pType ) = 0;
      virtual HRESULT __stdcall put_FileType (
        /*[in]*/ enum eFileType pType ) = 0;
      virtual HRESULT __stdcall get_Items (
        /*[out,retval]*/ IDispatch * * Items ) = 0;
      virtual HRESULT __stdcall AddFile (
        BSTR bstrPath,
        /*[out,retval]*/ IDispatch * * Val ) = 0;
      virtual HRESULT __stdcall CanAddFile (
        /*[in]*/ BSTR bstrFile,
        /*[out,retval]*/ VARIANT_BOOL * canAdd ) = 0;
      virtual HRESULT __stdcall RemoveFile (
        /*[in]*/ IDispatch * File ) = 0;
      virtual HRESULT __stdcall get_CustomTool (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_CustomTool (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_SubType (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_SubType (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall get_Object (
        /*[out,retval]*/ IDispatch * * vsObject ) = 0;
      virtual HRESULT __stdcall get_UnexpandedRelativePath (
        /*[out,retval]*/ BSTR * bstrRelPath ) = 0;
      virtual HRESULT __stdcall get_ItemType (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_ItemType (
        /*[in]*/ BSTR Val ) = 0;
      virtual HRESULT __stdcall GetFileConfigurationForProjectConfiguration (
        /*[in]*/ struct VCConfiguration * pProjCfg,
        /*[out,retval]*/ struct VCFileConfiguration * * ppFileCfg ) = 0;
      virtual HRESULT __stdcall get_ContentType (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_ContentType (
        /*[in]*/ BSTR Val ) = 0;
};

struct __declspec(uuid("89954662-7788-4d23-8508-a73917b2e824"))
VCConfiguration2 : VCConfiguration
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_EvaluationId (
        /*[out,retval]*/ __int64 * hash ) = 0;
      virtual HRESULT __stdcall get_AllImports (
        /*[out,retval]*/ SAFEARRAY * * psaImports ) = 0;
};

struct __declspec(uuid("85dd53fe-5534-4acc-a0af-8663c886ff3d"))
IVCBuildRequest2 : IVCBuildRequest
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Configuration (
        /*[out,retval]*/ struct VCConfiguration * * ppConfig ) = 0;
      virtual HRESULT __stdcall put_Configuration (
        /*[in]*/ struct VCConfiguration * ppConfig ) = 0;
};

struct __declspec(uuid("75d6bb37-482d-4cde-9634-ca4c0e8d4153"))
VCPropertySheet : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * styleName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR styleName ) = 0;
      virtual HRESULT __stdcall MatchName (
        /*[in]*/ BSTR NameToMatch,
        /*[in]*/ VARIANT_BOOL FullOnly,
        /*[out,retval]*/ VARIANT_BOOL * IsMatch ) = 0;
      virtual HRESULT __stdcall get_PropertySheetName (
        /*[out,retval]*/ BSTR * PropertySheetName ) = 0;
      virtual HRESULT __stdcall put_PropertySheetName (
        /*[in]*/ BSTR PropertySheetName ) = 0;
      virtual HRESULT __stdcall get_PropertySheetFile (
        /*[out,retval]*/ BSTR * File ) = 0;
      virtual HRESULT __stdcall put_PropertySheetFile (
        /*[in]*/ BSTR File ) = 0;
      virtual HRESULT __stdcall get_Tools (
        /*[out,retval]*/ IDispatch * * Tools ) = 0;
      virtual HRESULT __stdcall get_FileTools (
        /*[out,retval]*/ struct IVCCollection * * fileToolList ) = 0;
      virtual HRESULT __stdcall get_IsDirty (
        /*[out,retval]*/ VARIANT_BOOL * dirty ) = 0;
      virtual HRESULT __stdcall get_PropertySheets (
        /*[out,retval]*/ IDispatch * * PropertySheets ) = 0;
      virtual HRESULT __stdcall get_IntermediateDirectory (
        /*[out,retval]*/ BSTR * intDir ) = 0;
      virtual HRESULT __stdcall put_IntermediateDirectory (
        /*[in]*/ BSTR intDir ) = 0;
      virtual HRESULT __stdcall get_OutputDirectory (
        /*[out,retval]*/ BSTR * outDir ) = 0;
      virtual HRESULT __stdcall put_OutputDirectory (
        /*[in]*/ BSTR outDir ) = 0;
      virtual HRESULT __stdcall get_InheritedPropertySheets (
        /*[out,retval]*/ BSTR * PropertySheetNames ) = 0;
      virtual HRESULT __stdcall put_InheritedPropertySheets (
        /*[in]*/ BSTR PropertySheetNames ) = 0;
      virtual HRESULT __stdcall get_DEPRECATED1 (
        /*[out,retval]*/ VARIANT_BOOL * Bsc ) = 0;
      virtual HRESULT __stdcall put_DEPRECATED1 (
        /*[in]*/ VARIANT_BOOL Bsc ) = 0;
      virtual HRESULT __stdcall get_useOfMfc (
        /*[out,retval]*/ enum useOfMfc * useMfc ) = 0;
      virtual HRESULT __stdcall put_useOfMfc (
        /*[in]*/ enum useOfMfc useMfc ) = 0;
      virtual HRESULT __stdcall get_useOfATL (
        /*[out,retval]*/ enum useOfATL * useATL ) = 0;
      virtual HRESULT __stdcall put_useOfATL (
        /*[in]*/ enum useOfATL useATL ) = 0;
      virtual HRESULT __stdcall get_ATLMinimizesCRunTimeLibraryUsage (
        /*[out,retval]*/ VARIANT_BOOL * UseCRT ) = 0;
      virtual HRESULT __stdcall put_ATLMinimizesCRunTimeLibraryUsage (
        /*[in]*/ VARIANT_BOOL UseCRT ) = 0;
      virtual HRESULT __stdcall get_CharacterSet (
        /*[out,retval]*/ enum charSet * optSetting ) = 0;
      virtual HRESULT __stdcall put_CharacterSet (
        /*[in]*/ enum charSet optSetting ) = 0;
      virtual HRESULT __stdcall get_ManagedExtensions (
        /*[out,retval]*/ enum compileAsManagedOptions * Managed ) = 0;
      virtual HRESULT __stdcall put_ManagedExtensions (
        /*[in]*/ enum compileAsManagedOptions Managed ) = 0;
      virtual HRESULT __stdcall get_DeleteExtensionsOnClean (
        /*[out,retval]*/ BSTR * ExtList ) = 0;
      virtual HRESULT __stdcall put_DeleteExtensionsOnClean (
        /*[in]*/ BSTR ExtList ) = 0;
      virtual HRESULT __stdcall get_WholeProgramOptimization (
        /*[out,retval]*/ VARIANT_BOOL * Optimize ) = 0;
      virtual HRESULT __stdcall put_WholeProgramOptimization (
        /*[in]*/ VARIANT_BOOL Optimize ) = 0;
      virtual HRESULT __stdcall get_VCProjectEngine (
        /*[out,retval]*/ IDispatch * * ProjectEngine ) = 0;
      virtual HRESULT __stdcall get_PropertySheetDirectory (
        /*[out,retval]*/ BSTR * PropertySheetDirectory ) = 0;
      virtual HRESULT __stdcall get_BuildLogFile (
        /*[out,retval]*/ BSTR * pbstrBuildLogFile ) = 0;
      virtual HRESULT __stdcall put_BuildLogFile (
        /*[in]*/ BSTR pbstrBuildLogFile ) = 0;
      virtual HRESULT __stdcall get_FileFormat (
        /*[out,retval]*/ enum enumFileFormat * FileType ) = 0;
      virtual HRESULT __stdcall put_FileFormat (
        /*[in]*/ enum enumFileFormat FileType ) = 0;
      virtual HRESULT __stdcall get_FileEncoding (
        /*[out,retval]*/ BSTR * encoding ) = 0;
      virtual HRESULT __stdcall put_FileEncoding (
        /*[in]*/ BSTR encoding ) = 0;
      virtual HRESULT __stdcall get_ConfigurationType (
        /*[out,retval]*/ enum ConfigurationTypes * ConfigType ) = 0;
      virtual HRESULT __stdcall put_ConfigurationType (
        /*[in]*/ enum ConfigurationTypes ConfigType ) = 0;
      virtual HRESULT __stdcall ClearToolProperty (
        /*[in]*/ IDispatch * pTool,
        /*[in]*/ BSTR bstrPropertyName ) = 0;
      virtual HRESULT __stdcall Save ( ) = 0;
      virtual HRESULT __stdcall get_UserMacros (
        /*[out,retval]*/ struct IVCCollection * * UserMacros ) = 0;
      virtual HRESULT __stdcall AddUserMacro (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR Value,
        /*[out,retval]*/ struct VCUserMacro * * UserMacro ) = 0;
      virtual HRESULT __stdcall RemoveUserMacro (
        /*[in]*/ struct VCUserMacro * UserMacro ) = 0;
      virtual HRESULT __stdcall RemoveAllUserMacros ( ) = 0;
      virtual HRESULT __stdcall get_EnableManagedIncrementalBuild (
        /*[out,retval]*/ enum optManagedIncrementalBuild * EnableMIB ) = 0;
      virtual HRESULT __stdcall put_EnableManagedIncrementalBuild (
        /*[in]*/ enum optManagedIncrementalBuild EnableMIB ) = 0;
      virtual HRESULT __stdcall get_Rules (
        /*[out,retval]*/ struct IVCCollection * * listRules ) = 0;
      virtual HRESULT __stdcall AddPropertySheet (
        /*[in]*/ LPWSTR FileName,
        /*[out,retval]*/ struct VCPropertySheet * * ppPropertySheet ) = 0;
      virtual HRESULT __stdcall RemovePropertySheet (
        /*[in]*/ struct VCPropertySheet * pPropertySheet,
        /*[out,retval]*/ VARIANT_BOOL * pbFound ) = 0;
      virtual HRESULT __stdcall MovePropertySheet (
        /*[in]*/ struct VCPropertySheet * pPropertySheet,
        /*[in]*/ VARIANT_BOOL bMoveImportLaterInEvaluation ) = 0;
      virtual HRESULT __stdcall get_IsSystemPropertySheet (
        /*[out,retval]*/ VARIANT_BOOL * pfIsSystemPropertySheet ) = 0;
};

struct __declspec(uuid("41e315a7-2fc2-48a7-8512-90755cd9327e"))
VCUserMacro : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * variableName ) = 0;
      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ BSTR * variableValue ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ BSTR variableValue ) = 0;
      virtual HRESULT __stdcall get_InheritsFromParent (
        /*[out,retval]*/ VARIANT_BOOL * variableType ) = 0;
      virtual HRESULT __stdcall put_InheritsFromParent (
        /*[in]*/ VARIANT_BOOL variableType ) = 0;
      virtual HRESULT __stdcall get_Delimiter (
        /*[out,retval]*/ BSTR * variableDelimiter ) = 0;
      virtual HRESULT __stdcall put_Delimiter (
        /*[in]*/ BSTR variableDelimiter ) = 0;
      virtual HRESULT __stdcall get_PerformEnvironmentSet (
        /*[out,retval]*/ VARIANT_BOOL * pbSetInEnvironment ) = 0;
      virtual HRESULT __stdcall put_PerformEnvironmentSet (
        /*[in]*/ VARIANT_BOOL pbSetInEnvironment ) = 0;
      virtual HRESULT __stdcall get_PropertySheet (
        /*[out,retval]*/ struct VCPropertySheet * * ppPropertySheet ) = 0;
      virtual HRESULT __stdcall MatchName (
        /*[in]*/ BSTR NameToMatch,
        /*[in]*/ VARIANT_BOOL FullOnly,
        /*[out,retval]*/ VARIANT_BOOL * IsMatch ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_VCProjectEngineLibrary =
    {0x2fa4aaa3,0x0285,0x495e,{0xac,0x12,0x82,0x39,0xb6,0x57,0x91,0xea}};
extern "C" const GUID __declspec(selectany) IID_SVCProjectEngine =
    {0xdbecfca1,0x1a01,0x42ad,{0x81,0x58,0xca,0x1c,0x3c,0x54,0x3a,0xdc}};
extern "C" const GUID __declspec(selectany) IID_IVCProjectEngineEvents =
    {0x0fb57085,0x958b,0x45f2,{0xbf,0xac,0xd8,0xb5,0xcd,0x2b,0x57,0xa8}};
extern "C" const GUID __declspec(selectany) IID_IVCProjectEngineEvents2 =
    {0xe3de0769,0x1e0a,0x43b7,{0x8d,0x57,0x1d,0x42,0x41,0xb8,0x22,0xb3}};
extern "C" const GUID __declspec(selectany) DIID__dispVCProjectEngineEvents =
    {0x8b558010,0x3d1f,0x43ea,{0xaf,0x3e,0x46,0x31,0x9f,0xd7,0x87,0xeb}};
extern "C" const GUID __declspec(selectany) IID__VCProjectEngineEvents =
    {0xbc11c64a,0x17bb,0x4c0d,{0x8e,0x31,0xe8,0x5a,0xc0,0x66,0xa1,0x20}};
extern "C" const GUID __declspec(selectany) CLSID_VCProjectEngineEvents =
    {0x69f077c7,0x4f70,0x46a1,{0xbd,0xe0,0x18,0xf8,0xab,0xfa,0xf2,0x1e}};
extern "C" const GUID __declspec(selectany) CLSID_VCProjectEngineObject =
    {0xf840d790,0xaf0c,0x4927,{0xbd,0x62,0x24,0x38,0x99,0xe5,0xc9,0x69}};
extern "C" const GUID __declspec(selectany) IID_IVCCollection =
    {0xef0ef512,0x4ab7,0x4eec,{0x91,0xd1,0x9e,0x5e,0x22,0x2e,0xed,0x81}};
extern "C" const GUID __declspec(selectany) IID_VCToolFile =
    {0xaa47150b,0xd212,0x410c,{0x8a,0x4a,0x3a,0xf3,0x0e,0x64,0x67,0x0e}};
extern "C" const GUID __declspec(selectany) IID_IVCBuildCompleteCallback =
    {0x9b92c18d,0xa218,0x4266,{0xbb,0x37,0xf9,0xd5,0x8c,0x17,0xf0,0x7b}};
extern "C" const GUID __declspec(selectany) IID_IVCBuildRequest =
    {0x7dd2b83e,0xa53a,0x443c,{0xb2,0xeb,0xec,0x61,0x8b,0xb2,0x5f,0x82}};
extern "C" const GUID __declspec(selectany) IID_IVCProjectBuildService =
    {0x622c69b7,0x5541,0x4612,{0x89,0xbd,0x3d,0xdc,0x34,0xf0,0x61,0xde}};
extern "C" const GUID __declspec(selectany) IID_VCProjectEngine =
    {0x54969dd8,0x23d3,0x4a77,{0x91,0x1c,0x87,0xe6,0xa3,0xc5,0xc2,0x1c}};
extern "C" const GUID __declspec(selectany) IID_VCPlatform =
    {0xe2a1c8ff,0x6174,0x49fa,{0x94,0x76,0xdc,0x18,0x8b,0xd9,0x47,0xb5}};
extern "C" const GUID __declspec(selectany) IID_VCProjectItem =
    {0x60dddab8,0x1862,0x477f,{0x89,0x95,0xbb,0x83,0xfb,0x33,0xfc,0xda}};
extern "C" const GUID __declspec(selectany) IID_VCFileConfiguration =
    {0x78875336,0xdfd3,0x4958,{0x82,0x96,0xe7,0x70,0xbc,0x36,0x94,0x04}};
extern "C" const GUID __declspec(selectany) IID_VCReferences =
    {0x692ef4e6,0x8596,0x4920,{0x95,0x58,0x66,0xe6,0x9b,0x95,0x90,0xdc}};
extern "C" const GUID __declspec(selectany) IID_VCReference =
    {0xfe124eb0,0xe13c,0x4c96,{0x8c,0x15,0x5b,0x26,0x66,0x9d,0x52,0x65}};
extern "C" const GUID __declspec(selectany) IID_VCAssemblyReference =
    {0x04f61f1d,0x8cb4,0x4f98,{0x86,0x7a,0xbb,0x93,0x14,0x0b,0xac,0x5b}};
extern "C" const GUID __declspec(selectany) IID_VCProjectReference =
    {0x5f6f17fb,0xdbb8,0x4456,{0xa1,0x53,0x48,0xe8,0x62,0x72,0x3a,0x68}};
extern "C" const GUID __declspec(selectany) IID_VCSharedProjectReference =
    {0xa6065869,0x4807,0x4485,{0xa6,0x25,0xed,0xc4,0x14,0x1f,0x67,0xe2}};
extern "C" const GUID __declspec(selectany) IID_VCActiveXReference =
    {0x0881de5a,0x11db,0x4cdd,{0xac,0x10,0x2d,0x36,0xb5,0xcb,0xb2,0xf1}};
extern "C" const GUID __declspec(selectany) IID_VCWinRTReference =
    {0xfeaabf59,0x80d7,0x405f,{0x97,0xd5,0x28,0xa5,0xf0,0x98,0x1d,0xf2}};
extern "C" const GUID __declspec(selectany) IID_VCSdkReference =
    {0xe457d993,0xc6f7,0x4602,{0x84,0x81,0x8e,0xf3,0x19,0xed,0xfb,0x7f}};
extern "C" const GUID __declspec(selectany) IID_VCForeignReference =
    {0x755e3954,0xad2b,0x48da,{0xa5,0x46,0xda,0x53,0x03,0x1d,0xb0,0x07}};
extern "C" const GUID __declspec(selectany) IID_VCXMLDataGeneratorTool =
    {0x2758104b,0xd976,0x4367,{0x8c,0x49,0xa0,0x71,0x87,0x31,0xdb,0x19}};
extern "C" const GUID __declspec(selectany) IID_VCDebugSettings =
    {0x4b7eb22d,0xc745,0x4f7a,{0x95,0xb7,0xa6,0x62,0xd2,0xa2,0x5e,0xd4}};
extern "C" const GUID __declspec(selectany) IID_VCCLCompilerTool =
    {0x80b63513,0x3e87,0x44a5,{0x8e,0x12,0x4b,0xa7,0xf9,0x81,0x15,0x3e}};
extern "C" const GUID __declspec(selectany) IID_VCMidlTool =
    {0x2d745b8b,0xc934,0x47bd,{0xba,0x16,0xec,0x05,0x14,0xae,0x49,0x14}};
extern "C" const GUID __declspec(selectany) IID_VCLinkerTool =
    {0x6590d9e4,0x516e,0x447e,{0xa9,0xd9,0xa3,0x2c,0x15,0xbc,0x56,0x2b}};
extern "C" const GUID __declspec(selectany) IID_VCResourceCompilerTool =
    {0xe202e5ca,0x684b,0x4d9a,{0x94,0x85,0x6a,0x2e,0xee,0x49,0x37,0xb6}};
extern "C" const GUID __declspec(selectany) IID_VCCustomBuildTool =
    {0xf5b8d246,0x74c0,0x4fd7,{0x85,0x22,0x3e,0xcf,0xd3,0xe0,0x8a,0x2d}};
extern "C" const GUID __declspec(selectany) IID_VCALinkTool =
    {0x2cf0e564,0x48be,0x4244,{0xa9,0x9a,0x2e,0xca,0xf2,0x21,0x39,0xbb}};
extern "C" const GUID __declspec(selectany) IID_VCManagedResourceCompilerTool =
    {0xac6c847a,0xa0f3,0x41d4,{0xbd,0x1e,0x53,0x73,0x9b,0x14,0x6d,0xea}};
extern "C" const GUID __declspec(selectany) IID_VCManifestTool =
    {0x80c80c10,0x3270,0x4c8d,{0x96,0x53,0xfd,0x75,0xaa,0x55,0xe7,0x9a}};
extern "C" const GUID __declspec(selectany) IID_VCXDCMakeTool =
    {0x0f297231,0x6269,0x41e0,{0x80,0xe1,0xed,0x7c,0x48,0x3f,0x65,0x60}};
extern "C" const GUID __declspec(selectany) IID_VCFilter =
    {0x719a2ede,0x6e72,0x43ec,{0xab,0x20,0x35,0x1e,0x7c,0x35,0x8f,0x89}};
extern "C" const GUID __declspec(selectany) IID_VCPreBuildEventTool =
    {0x4e6ce19b,0xdcc9,0x40db,{0xb3,0x21,0x3c,0x6f,0x60,0xf8,0x9a,0x6f}};
extern "C" const GUID __declspec(selectany) IID_VCPreLinkEventTool =
    {0x4cb3265a,0xdd3b,0x4f1e,{0xbe,0xf8,0x88,0xb6,0x8f,0x27,0x11,0x8d}};
extern "C" const GUID __declspec(selectany) IID_VCPostBuildEventTool =
    {0x74d00da0,0x092b,0x4b51,{0xa4,0xd5,0x13,0x42,0x33,0xae,0xbd,0xf4}};
extern "C" const GUID __declspec(selectany) IID_VCBscMakeTool =
    {0xaf958e5b,0xcab8,0x4aaa,{0x9f,0x6a,0xfb,0x2f,0xba,0xde,0xcd,0x6e}};
extern "C" const GUID __declspec(selectany) IID_VCLibrarianTool =
    {0xbf75c368,0x74db,0x4a28,{0x9f,0xda,0x3b,0x5b,0x76,0xf8,0xee,0xe9}};
extern "C" const GUID __declspec(selectany) IID_VCNMakeTool =
    {0x023de234,0x7e71,0x4fd3,{0x9d,0x29,0xf8,0x2e,0xdf,0xdc,0xe5,0x1d}};
extern "C" const GUID __declspec(selectany) IID_VCFxCopTool =
    {0xbc0e8841,0x354b,0x4880,{0xae,0x89,0xf7,0x24,0xdc,0xe6,0xe4,0x5f}};
extern "C" const GUID __declspec(selectany) IID_VCFxCopTool2 =
    {0x3ac4e69b,0xa4b0,0x4996,{0x9e,0xec,0x06,0x3e,0x46,0x0b,0x81,0x22}};
extern "C" const GUID __declspec(selectany) IID_IVCBuildPropertyStorage =
    {0xe1a22e2b,0xcf0f,0x4b23,{0xb2,0x5c,0x81,0xa9,0x1b,0x2d,0x0c,0x3b}};
extern "C" const GUID __declspec(selectany) IID_IVCRulePropertyStorage =
    {0xe642c68e,0xb883,0x4f4f,{0xb9,0x46,0x78,0x7a,0x07,0xfb,0x39,0x75}};
extern "C" const GUID __declspec(selectany) IID_IVCRulePropertyStorage2 =
    {0xe71d6e86,0x89d8,0x4ec7,{0x95,0x17,0x84,0x75,0xd1,0x97,0x37,0xde}};
extern "C" const GUID __declspec(selectany) IID_IVCIdentity =
    {0xa801c81c,0x2ee5,0x4f46,{0xa0,0x6e,0xa3,0x18,0xcd,0x22,0x8f,0xe5}};
extern "C" const GUID __declspec(selectany) IID_IVCProjectTargetChange =
    {0xd3e42d89,0xb6cb,0x47b6,{0xb0,0x9f,0x87,0x6f,0x61,0xac,0x5c,0x27}};
extern "C" const GUID __declspec(selectany) IID_IVCProjectTargetDescription =
    {0x9ffeda85,0x27ca,0x46cf,{0xaa,0xb7,0x7c,0x47,0x0c,0xec,0xbf,0x29}};
extern "C" const GUID __declspec(selectany) IID_IVCPropertyStorage =
    {0x3b621333,0x4aad,0x4d82,{0xb8,0x65,0x80,0xe5,0xdd,0xb2,0xcf,0x1e}};
extern "C" const GUID __declspec(selectany) IID_VCProject =
    {0xdbf177f2,0x06db,0x4a47,{0x8a,0xad,0xc8,0xe1,0x2b,0xfd,0x6c,0x86}};
extern "C" const GUID __declspec(selectany) IID_VCConfiguration =
    {0x921dd76b,0xa230,0x4028,{0x8d,0xae,0x7f,0xc8,0x8a,0x60,0x56,0x76}};
extern "C" const GUID __declspec(selectany) IID_VCFile =
    {0x6eb8dcb9,0xf64b,0x471e,{0xa2,0x95,0x14,0xa4,0x1e,0x3c,0x09,0x9f}};
extern "C" const GUID __declspec(selectany) IID_VCConfiguration2 =
    {0x89954662,0x7788,0x4d23,{0x85,0x08,0xa7,0x39,0x17,0xb2,0xe8,0x24}};
extern "C" const GUID __declspec(selectany) IID_IVCBuildRequest2 =
    {0x85dd53fe,0x5534,0x4acc,{0xa0,0xaf,0x86,0x63,0xc8,0x86,0xff,0x3d}};
extern "C" const GUID __declspec(selectany) IID_VCPropertySheet =
    {0x75d6bb37,0x482d,0x4cde,{0x96,0x34,0xca,0x4c,0x0e,0x8d,0x41,0x53}};
extern "C" const GUID __declspec(selectany) IID_VCUserMacro =
    {0x41e315a7,0x2fc2,0x48a7,{0x85,0x12,0x90,0x75,0x5c,0xd9,0x32,0x7e}};

} // namespace VCProjectEngineLibrary

#pragma pack(pop)
