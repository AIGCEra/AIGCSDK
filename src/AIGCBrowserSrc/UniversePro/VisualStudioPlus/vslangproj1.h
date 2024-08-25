// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1 (52a83b60).
//
// c:\users\孙辉\documents\visual studio 2017\projects\atlproject2\atlproject2\debug\vslangproj.tlh
//
// C++ source equivalent of Win32 type library C:\Program Files (x86)\Common Files\Microsoft Shared\MSEnv\vslangproj.olb
// compiler-generated file created 08/30/17 at 22:01:13 - DO NOT EDIT!

//
// Cross-referenced type libraries:
//
#include "dte80.h"
//

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace VSLangProj {

//
// Forward references and typedefs
//

struct __declspec(uuid("49a1950e-3e35-4595-8cb9-920c64c44d67"))
/* LIBID */ __VSLangProj;
enum prjStartAction;
enum prjOutputType;
enum prjScriptLanguage;
enum prjTargetSchema;
enum prjHTMLPageLayout;
enum prjOriginatorKeyMode;
enum prjWebAccessMethod;
enum prjWarningLevel;
enum prjProjectType;
enum prjBuildAction;
enum prjCompare;
enum prjOptionExplicit;
enum prjOptionStrict;
enum webrefUrlBehavior;
struct __declspec(uuid("3cdaa65d-1e9d-11d3-b202-00c04f79cacb"))
/* dual interface */ ProjectConfigurationProperties;
struct __declspec(uuid("3cdaa65e-1e9d-11d3-b202-00c04f79cacb"))
/* dual interface */ ProjectProperties;
struct __declspec(uuid("516bd64e-51c0-11d3-85cf-00c04f6123b3"))
/* dual interface */ FileProperties;
struct __declspec(uuid("8e4aa768-51e1-11d3-85cf-00c04f6123b3"))
/* dual interface */ FolderProperties;
enum prjReferenceType;
struct __declspec(uuid("35d6fb50-35b6-4c81-b91c-3930b0d95386"))
/* dual interface */ Reference;
struct __declspec(uuid("b8758ee4-0553-4bc9-8432-440449d35c14"))
/* dual interface */ References;
struct __declspec(uuid("1cf40c9e-d548-4b45-ad0f-3d7843f62bbb"))
/* dual interface */ _ReferencesEvents;
struct __declspec(uuid("287eb27c-0f8b-4d2d-8e82-a9ca50b6766e"))
/* dispinterface */ _dispReferencesEvents;
struct /* coclass */ ReferencesEvents;
struct __declspec(uuid("c711e2b7-3c58-4c37-9359-705208a890ae"))
/* dual interface */ BuildManager;
struct __declspec(uuid("5f4aae42-bc94-401d-9213-b8a8b9e553de"))
/* dual interface */ _BuildManagerEvents;
struct __declspec(uuid("828914f7-1d81-4f5c-83ce-37819d7ee759"))
/* dispinterface */ _dispBuildManagerEvents;
struct /* coclass */ BuildManagerEvents;
struct __declspec(uuid("642789f9-210d-4574-96fd-5a653451e216"))
/* dual interface */ Imports;
struct __declspec(uuid("037ad859-7a75-4cf3-8a38-83d6e045fee3"))
/* dual interface */ _ImportsEvents;
struct __declspec(uuid("40806cea-abab-4887-a356-d8869c28a6e6"))
/* dispinterface */ _dispImportsEvents;
struct /* coclass */ ImportsEvents;
struct __declspec(uuid("f8b92546-f1a2-4066-92f6-fdf2e691a50c"))
/* dual interface */ VSProjectEvents;
enum prjCopyProjectOption;
enum prjExecCommand;
struct __declspec(uuid("2cfb826f-f6bf-480d-a546-95a0381cc411"))
/* dual interface */ VSProject;
struct __declspec(uuid("89ff44c6-979d-49b6-af56-ec9509001de4"))
/* dual interface */ VSProjectItem;
enum tagWebPrjAuthoringAccess;
struct __declspec(uuid("8fa8d496-caf1-40b3-bc58-5fc877fefea7"))
/* dual interface */ WebSettings;
typedef enum tagWebPrjAuthoringAccess webPrjAuthoringAccess;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(ProjectConfigurationProperties, __uuidof(ProjectConfigurationProperties));
_COM_SMARTPTR_TYPEDEF(ProjectProperties, __uuidof(ProjectProperties));
_COM_SMARTPTR_TYPEDEF(FileProperties, __uuidof(FileProperties));
_COM_SMARTPTR_TYPEDEF(FolderProperties, __uuidof(FolderProperties));
_COM_SMARTPTR_TYPEDEF(_ReferencesEvents, __uuidof(_ReferencesEvents));
_COM_SMARTPTR_TYPEDEF(_dispReferencesEvents, __uuidof(_dispReferencesEvents));
_COM_SMARTPTR_TYPEDEF(BuildManager, __uuidof(BuildManager));
_COM_SMARTPTR_TYPEDEF(_BuildManagerEvents, __uuidof(_BuildManagerEvents));
_COM_SMARTPTR_TYPEDEF(_dispBuildManagerEvents, __uuidof(_dispBuildManagerEvents));
_COM_SMARTPTR_TYPEDEF(Imports, __uuidof(Imports));
_COM_SMARTPTR_TYPEDEF(_ImportsEvents, __uuidof(_ImportsEvents));
_COM_SMARTPTR_TYPEDEF(_dispImportsEvents, __uuidof(_dispImportsEvents));
_COM_SMARTPTR_TYPEDEF(VSProjectEvents, __uuidof(VSProjectEvents));
_COM_SMARTPTR_TYPEDEF(VSProjectItem, __uuidof(VSProjectItem));
_COM_SMARTPTR_TYPEDEF(WebSettings, __uuidof(WebSettings));
_COM_SMARTPTR_TYPEDEF(Reference, __uuidof(Reference));
_COM_SMARTPTR_TYPEDEF(References, __uuidof(References));
_COM_SMARTPTR_TYPEDEF(VSProject, __uuidof(VSProject));

//
// Type library items
//
    const LPSTR prjKindVBProject = (char*) "{F184B08F-C81C-45F6-A57F-5ABD9991F28F}";
    const LPSTR prjKindCSharpProject = (char*) "{FAE04EC0-301F-11D3-BF4B-00C04F79EFBC}";
    const LPSTR prjKindVSAProject = (char*) "{13B7A3EE-4614-11D3-9BC7-00C04F79DE25}";
    const LPSTR prjKindVenusProject = (char*) "{E24C65DC-7377-472b-9ABA-BC803B73C61A}";
    const LPSTR prjCATIDProject = (char*) "{610D4614-D0D5-11D2-8599-006097C68E81}";
    const LPSTR prjCATIDProjectItem = (char*) "{610D4615-D0D5-11D2-8599-006097C68E81}";
    const LPSTR prjCATIDVBProjectBrowseObject = (char*) "{E0FDC879-C32A-4751-A3D3-0B3824BD575F}";
    const LPSTR prjCATIDCSharpProjectBrowseObject = (char*) "{4EF9F003-DE95-4d60-96B0-212979F2A857}";
    const LPSTR prjCATIDVBProjectConfigBrowseObject = (char*) "{67F8DD11-14EB-489b-87F0-F01C52AF3870}";
    const LPSTR prjCATIDCSharpProjectConfigBrowseObject = (char*) "{A12CE10A-227F-4963-ADB6-3A43388513CA}";
    const LPSTR prjCATIDVBFileBrowseObject = (char*) "{EA5BD05D-3C72-40A5-95A0-28A2773311CA}";
    const LPSTR prjCATIDCSharpFileBrowseObject = (char*) "{8D58E6AF-ED4E-48B0-8C7B-C74EF0735451}";
    const LPSTR prjCATIDVSAFileBrowseObject = (char*) "{AC2912B2-50ED-4E62-8DFF-429B4B88FC9E}";
    const LPSTR prjCATIDVBFolderBrowseObject = (char*) "{932DC619-2EAA-4192-B7E6-3D15AD31DF49}";
    const LPSTR prjCATIDCSharpFolderBrowseObject = (char*) "{914FE278-054A-45DB-BF9E-5F22484CC84C}";
    const LPSTR prjCATIDVSAFolderBrowseObject = (char*) "{79231B36-6213-481D-AA7D-0F931E8F2CF9}";
    const LPSTR prjCATIDVBReferenceBrowseObject = (char*) "{2289B812-8191-4e81-B7B3-174045AB0CB5}";
    const LPSTR prjCATIDCSharpReferenceBrowseObject = (char*) "{2F0FA3B8-C855-4a4e-95A5-CB45C67D6C27}";
    const LPSTR prjCATIDVSAReferenceBrowseObject = (char*) "{4E018D0E-1143-47d6-A139-68D01E39BF5F}";
    const LPSTR prjCATIDVBConfig = (char*) "{5A30A635-0BA6-468f-A1C6-952DA61DB00B}";
    const LPSTR prjCATIDCSharpConfig = (char*) "{89FB23F7-E591-4a2f-8E0F-64C0522FCF77}";
    const LPSTR prjCATIDVSAConfig = (char*) "{1AA19227-163B-42fd-87CC-F5E78DABF52B}";

enum __declspec(uuid("504876a3-4b7d-4932-b1d7-e91129d4aebf"))
prjStartAction
{
    prjStartActionProject = 0,
    prjStartActionProgram = 1,
    prjStartActionURL = 2,
    prjStartActionNone = 3
};

enum __declspec(uuid("fb309311-8f09-41e7-8347-68f5a079592d"))
prjOutputType
{
    prjOutputTypeWinExe = 0,
    prjOutputTypeExe = 1,
    prjOutputTypeLibrary = 2
};

enum __declspec(uuid("d760c0e8-311e-45eb-b06c-033f8cc1e5ec"))
prjScriptLanguage
{
    prjScriptLanguageJScript = 0,
    prjScriptLanguageVBScript = 1
};

enum __declspec(uuid("b743460b-b3a1-40dc-9a0c-19eccb63650e"))
prjTargetSchema
{
    prjTargetSchemaIE32Nav30 = 0,
    prjTargetSchemaIE50 = 1,
    prjTargetSchemaNav40 = 2
};

enum __declspec(uuid("8821c6db-40b9-4584-b3f1-28336b36a23d"))
prjHTMLPageLayout
{
    prjHTMLPageLayoutFlow = 0,
    prjHTMLPageLayoutGrid = 1
};

enum __declspec(uuid("02720598-3e01-4721-adaf-e2937bd6c645"))
prjOriginatorKeyMode
{
    prjOriginatorKeyModeNone = 0,
    prjOriginatorKeyModeFile = 1,
    prjOriginatorKeyModeContainer = 2
};

enum __declspec(uuid("88a4c7d7-2587-4cc3-adac-993896b5d094"))
prjWebAccessMethod
{
    prjWebAccessMethodFileShare = 0,
    prjWebAccessMethodFrontPage = 1
};

enum __declspec(uuid("31dddf62-1891-4870-8df5-00d9028826df"))
prjWarningLevel
{
    prjWarningLevel0 = 0,
    prjWarningLevel1 = 1,
    prjWarningLevel2 = 2,
    prjWarningLevel3 = 3,
    prjWarningLevel4 = 4
};

enum __declspec(uuid("5b50016f-f7cc-4687-a1da-3f234f7620ee"))
prjProjectType
{
    prjProjectTypeLocal = 0,
    prjProjectTypeWeb = 1
};

enum __declspec(uuid("d399129c-23cc-4301-81b0-5a60dc52e67d"))
prjBuildAction
{
    prjBuildActionNone = 0,
    prjBuildActionCompile = 1,
    prjBuildActionContent = 2,
    prjBuildActionEmbeddedResource = 3
};

enum __declspec(uuid("ebda8dd4-e450-452a-9ff5-7970904dea7f"))
prjCompare
{
    prjCompareBinary = 0,
    prjCompareText = 1
};

enum __declspec(uuid("95dcfabc-145d-498d-a454-47f33d47139c"))
prjOptionExplicit
{
    prjOptionExplicitOff = 0,
    prjOptionExplicitOn = 1
};

enum __declspec(uuid("ce6aa0fd-6ccd-4601-a730-fa75219862c3"))
prjOptionStrict
{
    prjOptionStrictOff = 0,
    prjOptionStrictOn = 1
};

enum __declspec(uuid("1fe01ddf-c760-4307-8a40-0d023aeaff07"))
webrefUrlBehavior
{
    webrefUrlBehaviorStatic = 0,
    webrefUrlBehaviorDynamic = 1
};

struct __declspec(uuid("3cdaa65d-1e9d-11d3-b202-00c04f79cacb"))
ProjectConfigurationProperties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get___id (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_DebugSymbols (
        /*[out,retval]*/ VARIANT_BOOL * pbGenerate ) = 0;
      virtual HRESULT __stdcall put_DebugSymbols (
        /*[in]*/ VARIANT_BOOL pbGenerate ) = 0;
      virtual HRESULT __stdcall get_DefineDebug (
        /*[out,retval]*/ VARIANT_BOOL * pbDefineDebug ) = 0;
      virtual HRESULT __stdcall put_DefineDebug (
        /*[in]*/ VARIANT_BOOL pbDefineDebug ) = 0;
      virtual HRESULT __stdcall get_DefineTrace (
        /*[out,retval]*/ VARIANT_BOOL * pbDefineTrace ) = 0;
      virtual HRESULT __stdcall put_DefineTrace (
        /*[in]*/ VARIANT_BOOL pbDefineTrace ) = 0;
      virtual HRESULT __stdcall get_OutputPath (
        /*[out,retval]*/ BSTR * pbstrOutputPath ) = 0;
      virtual HRESULT __stdcall put_OutputPath (
        /*[in]*/ BSTR pbstrOutputPath ) = 0;
      virtual HRESULT __stdcall get_IntermediatePath (
        /*[out,retval]*/ BSTR * pbstrIntermediatePath ) = 0;
      virtual HRESULT __stdcall put_IntermediatePath (
        /*[in]*/ BSTR pbstrIntermediatePath ) = 0;
      virtual HRESULT __stdcall get_DefineConstants (
        /*[out,retval]*/ BSTR * pbstrDefineConstants ) = 0;
      virtual HRESULT __stdcall put_DefineConstants (
        /*[in]*/ BSTR pbstrDefineConstants ) = 0;
      virtual HRESULT __stdcall get_RemoveIntegerChecks (
        /*[out,retval]*/ VARIANT_BOOL * pbRemoveIntegerChecks ) = 0;
      virtual HRESULT __stdcall put_RemoveIntegerChecks (
        /*[in]*/ VARIANT_BOOL pbRemoveIntegerChecks ) = 0;
      virtual HRESULT __stdcall get_BaseAddress (
        /*[out,retval]*/ unsigned long * pdwBaseAddress ) = 0;
      virtual HRESULT __stdcall put_BaseAddress (
        /*[in]*/ unsigned long pdwBaseAddress ) = 0;
      virtual HRESULT __stdcall get_AllowUnsafeBlocks (
        /*[out,retval]*/ VARIANT_BOOL * pbUnsafe ) = 0;
      virtual HRESULT __stdcall put_AllowUnsafeBlocks (
        /*[in]*/ VARIANT_BOOL pbUnsafe ) = 0;
      virtual HRESULT __stdcall get_CheckForOverflowUnderflow (
        /*[out,retval]*/ VARIANT_BOOL * pbCheckForOverflowUnderflow ) = 0;
      virtual HRESULT __stdcall put_CheckForOverflowUnderflow (
        /*[in]*/ VARIANT_BOOL pbCheckForOverflowUnderflow ) = 0;
      virtual HRESULT __stdcall get_DocumentationFile (
        /*[out,retval]*/ BSTR * pbstrDocumentationFile ) = 0;
      virtual HRESULT __stdcall put_DocumentationFile (
        /*[in]*/ BSTR pbstrDocumentationFile ) = 0;
      virtual HRESULT __stdcall get_Optimize (
        /*[out,retval]*/ VARIANT_BOOL * pbOptimize ) = 0;
      virtual HRESULT __stdcall put_Optimize (
        /*[in]*/ VARIANT_BOOL pbOptimize ) = 0;
      virtual HRESULT __stdcall get_IncrementalBuild (
        /*[out,retval]*/ VARIANT_BOOL * pbIncrementalBuild ) = 0;
      virtual HRESULT __stdcall put_IncrementalBuild (
        /*[in]*/ VARIANT_BOOL pbIncrementalBuild ) = 0;
      virtual HRESULT __stdcall get_StartProgram (
        /*[out,retval]*/ BSTR * pbstrStartProgram ) = 0;
      virtual HRESULT __stdcall put_StartProgram (
        /*[in]*/ BSTR pbstrStartProgram ) = 0;
      virtual HRESULT __stdcall get_StartWorkingDirectory (
        /*[out,retval]*/ BSTR * pbstrStartWorkingDirectory ) = 0;
      virtual HRESULT __stdcall put_StartWorkingDirectory (
        /*[in]*/ BSTR pbstrStartWorkingDirectory ) = 0;
      virtual HRESULT __stdcall get_StartURL (
        /*[out,retval]*/ BSTR * pbstrStartURL ) = 0;
      virtual HRESULT __stdcall put_StartURL (
        /*[in]*/ BSTR pbstrStartURL ) = 0;
      virtual HRESULT __stdcall get_StartPage (
        /*[out,retval]*/ BSTR * pbstrStartPage ) = 0;
      virtual HRESULT __stdcall put_StartPage (
        /*[in]*/ BSTR pbstrStartPage ) = 0;
      virtual HRESULT __stdcall get_StartArguments (
        /*[out,retval]*/ BSTR * pbstrStartArguments ) = 0;
      virtual HRESULT __stdcall put_StartArguments (
        /*[in]*/ BSTR pbstrStartArguments ) = 0;
      virtual HRESULT __stdcall get_StartWithIE (
        /*[out,retval]*/ VARIANT_BOOL * pbStartWithIE ) = 0;
      virtual HRESULT __stdcall put_StartWithIE (
        /*[in]*/ VARIANT_BOOL pbStartWithIE ) = 0;
      virtual HRESULT __stdcall get_EnableASPDebugging (
        /*[out,retval]*/ VARIANT_BOOL * pbEnableASPDebugging ) = 0;
      virtual HRESULT __stdcall put_EnableASPDebugging (
        /*[in]*/ VARIANT_BOOL pbEnableASPDebugging ) = 0;
      virtual HRESULT __stdcall get_EnableASPXDebugging (
        /*[out,retval]*/ VARIANT_BOOL * pbEnableASPXDebugging ) = 0;
      virtual HRESULT __stdcall put_EnableASPXDebugging (
        /*[in]*/ VARIANT_BOOL pbEnableASPXDebugging ) = 0;
      virtual HRESULT __stdcall get_EnableUnmanagedDebugging (
        /*[out,retval]*/ VARIANT_BOOL * pbEnableUnmanagedDebugging ) = 0;
      virtual HRESULT __stdcall put_EnableUnmanagedDebugging (
        /*[in]*/ VARIANT_BOOL pbEnableUnmanagedDebugging ) = 0;
      virtual HRESULT __stdcall get_StartAction (
        /*[out,retval]*/ enum prjStartAction * pdebugStartMode ) = 0;
      virtual HRESULT __stdcall put_StartAction (
        /*[in]*/ enum prjStartAction pdebugStartMode ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR ExtenderName,
        /*[out,retval]*/ IDispatch * * Extender ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * ExtenderNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pRetval ) = 0;
      virtual HRESULT __stdcall get_WarningLevel (
        /*[out,retval]*/ enum prjWarningLevel * pWarningLeve ) = 0;
      virtual HRESULT __stdcall put_WarningLevel (
        /*[in]*/ enum prjWarningLevel pWarningLeve ) = 0;
      virtual HRESULT __stdcall get_TreatWarningsAsErrors (
        /*[out,retval]*/ VARIANT_BOOL * pWarningAsError ) = 0;
      virtual HRESULT __stdcall put_TreatWarningsAsErrors (
        /*[in]*/ VARIANT_BOOL pWarningAsError ) = 0;
      virtual HRESULT __stdcall get_EnableSQLServerDebugging (
        /*[out,retval]*/ VARIANT_BOOL * pbEnableSQLServerDebugging ) = 0;
      virtual HRESULT __stdcall put_EnableSQLServerDebugging (
        /*[in]*/ VARIANT_BOOL pbEnableSQLServerDebugging ) = 0;
      virtual HRESULT __stdcall get_FileAlignment (
        /*[out,retval]*/ unsigned long * pdwFileAlignment ) = 0;
      virtual HRESULT __stdcall put_FileAlignment (
        /*[in]*/ unsigned long pdwFileAlignment ) = 0;
      virtual HRESULT __stdcall get_RegisterForComInterop (
        /*[out,retval]*/ VARIANT_BOOL * pVal ) = 0;
      virtual HRESULT __stdcall put_RegisterForComInterop (
        /*[in]*/ VARIANT_BOOL pVal ) = 0;
      virtual HRESULT __stdcall get_ConfigurationOverrideFile (
        /*[out,retval]*/ BSTR * pbstrConfigFile ) = 0;
      virtual HRESULT __stdcall put_ConfigurationOverrideFile (
        /*[in]*/ BSTR pbstrConfigFile ) = 0;
      virtual HRESULT __stdcall get_RemoteDebugEnabled (
        /*[out,retval]*/ VARIANT_BOOL * pbEnableRemoteLaunch ) = 0;
      virtual HRESULT __stdcall put_RemoteDebugEnabled (
        /*[in]*/ VARIANT_BOOL pbEnableRemoteLaunch ) = 0;
      virtual HRESULT __stdcall get_RemoteDebugMachine (
        /*[out,retval]*/ BSTR * pbstrRemoteLaunchMach ) = 0;
      virtual HRESULT __stdcall put_RemoteDebugMachine (
        /*[in]*/ BSTR pbstrRemoteLaunchMach ) = 0;
};

struct __declspec(uuid("3cdaa65e-1e9d-11d3-b202-00c04f79cacb"))
ProjectProperties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get___id (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get___project (
        /*[out,retval]*/ IUnknown * * ppUnk ) = 0;
      virtual HRESULT __stdcall get_StartupObject (
        /*[out,retval]*/ BSTR * pbstrStartupObject ) = 0;
      virtual HRESULT __stdcall put_StartupObject (
        /*[in]*/ BSTR pbstrStartupObject ) = 0;
      virtual HRESULT __stdcall get_OutputType (
        /*[out,retval]*/ enum prjOutputType * pOutputType ) = 0;
      virtual HRESULT __stdcall put_OutputType (
        /*[in]*/ enum prjOutputType pOutputType ) = 0;
      virtual HRESULT __stdcall get_RootNamespace (
        /*[out,retval]*/ BSTR * pbstrRootNamespace ) = 0;
      virtual HRESULT __stdcall put_RootNamespace (
        /*[in]*/ BSTR pbstrRootNamespace ) = 0;
      virtual HRESULT __stdcall get_AssemblyName (
        /*[out,retval]*/ BSTR * pbstrAssemblyName ) = 0;
      virtual HRESULT __stdcall put_AssemblyName (
        /*[in]*/ BSTR pbstrAssemblyName ) = 0;
      virtual HRESULT __stdcall get_AssemblyOriginatorKeyFile (
        /*[out,retval]*/ BSTR * pbstrOriginatorKeyFile ) = 0;
      virtual HRESULT __stdcall put_AssemblyOriginatorKeyFile (
        /*[in]*/ BSTR pbstrOriginatorKeyFile ) = 0;
      virtual HRESULT __stdcall get_AssemblyKeyContainerName (
        /*[out,retval]*/ BSTR * pbstrKeyContainerName ) = 0;
      virtual HRESULT __stdcall put_AssemblyKeyContainerName (
        /*[in]*/ BSTR pbstrKeyContainerName ) = 0;
      virtual HRESULT __stdcall get_AssemblyOriginatorKeyMode (
        /*[out,retval]*/ enum prjOriginatorKeyMode * pOriginatorKeyMode ) = 0;
      virtual HRESULT __stdcall put_AssemblyOriginatorKeyMode (
        /*[in]*/ enum prjOriginatorKeyMode pOriginatorKeyMode ) = 0;
      virtual HRESULT __stdcall get_DelaySign (
        /*[out,retval]*/ VARIANT_BOOL * pbDelaySign ) = 0;
      virtual HRESULT __stdcall put_DelaySign (
        /*[in]*/ VARIANT_BOOL pbDelaySign ) = 0;
      virtual HRESULT __stdcall get_WebServer (
        /*[out,retval]*/ BSTR * pbstrWebServer ) = 0;
      virtual HRESULT __stdcall get_WebServerVersion (
        /*[out,retval]*/ BSTR * pbstrWebServerVersion ) = 0;
      virtual HRESULT __stdcall get_ServerExtensionsVersion (
        /*[out,retval]*/ BSTR * pbstrServerExtensionsVersion ) = 0;
      virtual HRESULT __stdcall get_LinkRepair (
        /*[out,retval]*/ VARIANT_BOOL * pLinkRepair ) = 0;
      virtual HRESULT __stdcall put_LinkRepair (
        /*[in]*/ VARIANT_BOOL pLinkRepair ) = 0;
      virtual HRESULT __stdcall get_OfflineURL (
        /*[out,retval]*/ BSTR * pbstrOfflineURL ) = 0;
      virtual HRESULT __stdcall get_FileSharePath (
        /*[out,retval]*/ BSTR * pbstrFileSharePath ) = 0;
      virtual HRESULT __stdcall put_FileSharePath (
        /*[in]*/ BSTR pbstrFileSharePath ) = 0;
      virtual HRESULT __stdcall get_ActiveFileSharePath (
        /*[out,retval]*/ BSTR * pbstrFileSharePath ) = 0;
      virtual HRESULT __stdcall get_WebAccessMethod (
        /*[out,retval]*/ enum prjWebAccessMethod * pWebAccessMethod ) = 0;
      virtual HRESULT __stdcall put_WebAccessMethod (
        /*[in]*/ enum prjWebAccessMethod pWebAccessMethod ) = 0;
      virtual HRESULT __stdcall get_ActiveWebAccessMethod (
        /*[out,retval]*/ enum prjWebAccessMethod * pActiveWebAccessMethod ) = 0;
      virtual HRESULT __stdcall get_DefaultClientScript (
        /*[out,retval]*/ enum prjScriptLanguage * pScriptLanguage ) = 0;
      virtual HRESULT __stdcall put_DefaultClientScript (
        /*[in]*/ enum prjScriptLanguage pScriptLanguage ) = 0;
      virtual HRESULT __stdcall get_DefaultTargetSchema (
        /*[out,retval]*/ enum prjTargetSchema * pTargetSchema ) = 0;
      virtual HRESULT __stdcall put_DefaultTargetSchema (
        /*[in]*/ enum prjTargetSchema pTargetSchema ) = 0;
      virtual HRESULT __stdcall get_DefaultHTMLPageLayout (
        /*[out,retval]*/ enum prjHTMLPageLayout * pHTMLPageLayout ) = 0;
      virtual HRESULT __stdcall put_DefaultHTMLPageLayout (
        /*[in]*/ enum prjHTMLPageLayout pHTMLPageLayout ) = 0;
      virtual HRESULT __stdcall get_FileName (
        /*[out,retval]*/ BSTR * pbstrFileName ) = 0;
      virtual HRESULT __stdcall put_FileName (
        /*[in]*/ BSTR pbstrFileName ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * pbstrFullPath ) = 0;
      virtual HRESULT __stdcall get_LocalPath (
        /*[out,retval]*/ BSTR * pbstrLocalPath ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * pbstrURL ) = 0;
      virtual HRESULT __stdcall get_ActiveConfigurationSettings (
        /*[out,retval]*/ struct ProjectConfigurationProperties * * ppVBProjConfigProps ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR ExtenderName,
        /*[out,retval]*/ IDispatch * * Extender ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * ExtenderNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pRetval ) = 0;
      virtual HRESULT __stdcall get_ApplicationIcon (
        /*[out,retval]*/ BSTR * pbstrApplicationIcon ) = 0;
      virtual HRESULT __stdcall put_ApplicationIcon (
        /*[in]*/ BSTR pbstrApplicationIcon ) = 0;
      virtual HRESULT __stdcall get_OptionStrict (
        /*[out,retval]*/ enum prjOptionStrict * pOptionStrict ) = 0;
      virtual HRESULT __stdcall put_OptionStrict (
        /*[in]*/ enum prjOptionStrict pOptionStrict ) = 0;
      virtual HRESULT __stdcall get_ReferencePath (
        /*[out,retval]*/ BSTR * pbstrReferencePath ) = 0;
      virtual HRESULT __stdcall put_ReferencePath (
        /*[in]*/ BSTR pbstrReferencePath ) = 0;
      virtual HRESULT __stdcall get_OutputFileName (
        /*[out,retval]*/ BSTR * pbstrOutputFileName ) = 0;
      virtual HRESULT __stdcall get_AbsoluteProjectDirectory (
        /*[out,retval]*/ BSTR * pbstrDir ) = 0;
      virtual HRESULT __stdcall get_OptionExplicit (
        /*[out,retval]*/ enum prjOptionExplicit * pOptionExplicit ) = 0;
      virtual HRESULT __stdcall put_OptionExplicit (
        /*[in]*/ enum prjOptionExplicit pOptionExplicit ) = 0;
      virtual HRESULT __stdcall get_OptionCompare (
        /*[out,retval]*/ enum prjCompare * pOptionCompare ) = 0;
      virtual HRESULT __stdcall put_OptionCompare (
        /*[in]*/ enum prjCompare pOptionCompare ) = 0;
      virtual HRESULT __stdcall get_ProjectType (
        /*[out,retval]*/ enum prjProjectType * pProjectType ) = 0;
      virtual HRESULT __stdcall get_DefaultNamespace (
        /*[out,retval]*/ BSTR * pbstrRootNamespace ) = 0;
      virtual HRESULT __stdcall put_DefaultNamespace (
        /*[in]*/ BSTR pbstrRootNamespace ) = 0;
};

struct __declspec(uuid("516bd64e-51c0-11d3-85cf-00c04f6123b3"))
FileProperties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get___id (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_FileName (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall put_FileName (
        /*[in]*/ BSTR pbstrName ) = 0;
      virtual HRESULT __stdcall get_Extension (
        /*[out,retval]*/ BSTR * pbstrExtension ) = 0;
      virtual HRESULT __stdcall get_Filesize (
        /*[out,retval]*/ unsigned long * pdwSize ) = 0;
      virtual HRESULT __stdcall get_LocalPath (
        /*[out,retval]*/ BSTR * pbstrLocalPath ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * pbstrFullPath ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * pbstrURL ) = 0;
      virtual HRESULT __stdcall get_HTMLTitle (
        /*[out,retval]*/ BSTR * pbstrTitle ) = 0;
      virtual HRESULT __stdcall get_Author (
        /*[out,retval]*/ BSTR * pbstrTitle ) = 0;
      virtual HRESULT __stdcall get_DateCreated (
        /*[out,retval]*/ BSTR * pbstrDateCreated ) = 0;
      virtual HRESULT __stdcall get_DateModified (
        /*[out,retval]*/ BSTR * pbstrDateCreated ) = 0;
      virtual HRESULT __stdcall get_ModifiedBy (
        /*[out,retval]*/ BSTR * pbstrDateCreated ) = 0;
      virtual HRESULT __stdcall get_SubType (
        /*[out,retval]*/ BSTR * pbstrSubType ) = 0;
      virtual HRESULT __stdcall put_SubType (
        /*[in]*/ BSTR pbstrSubType ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR ExtenderName,
        /*[out,retval]*/ IDispatch * * Extender ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * ExtenderNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pRetval ) = 0;
      virtual HRESULT __stdcall get_BuildAction (
        /*[out,retval]*/ enum prjBuildAction * pbuildAction ) = 0;
      virtual HRESULT __stdcall put_BuildAction (
        /*[in]*/ enum prjBuildAction pbuildAction ) = 0;
      virtual HRESULT __stdcall get_CustomTool (
        /*[out,retval]*/ BSTR * pbstrCustomTool ) = 0;
      virtual HRESULT __stdcall put_CustomTool (
        /*[in]*/ BSTR pbstrCustomTool ) = 0;
      virtual HRESULT __stdcall get_CustomToolNamespace (
        /*[out,retval]*/ BSTR * pbstrCustomToolNamespace ) = 0;
      virtual HRESULT __stdcall put_CustomToolNamespace (
        /*[in]*/ BSTR pbstrCustomToolNamespace ) = 0;
      virtual HRESULT __stdcall get_CustomToolOutput (
        /*[out,retval]*/ BSTR * pbstrCustomToolOutput ) = 0;
      virtual HRESULT __stdcall get_IsCustomToolOutput (
        /*[out,retval]*/ VARIANT_BOOL * pbIsCustomToolOutput ) = 0;
      virtual HRESULT __stdcall get_IsDependentFile (
        /*[out,retval]*/ VARIANT_BOOL * pbIsDepedentFile ) = 0;
      virtual HRESULT __stdcall get_IsLink (
        /*[out,retval]*/ VARIANT_BOOL * pbIsLinkFile ) = 0;
      virtual HRESULT __stdcall get_IsDesignTimeBuildInput (
        /*[out,retval]*/ VARIANT_BOOL * pbIsDesignTimeBuildInput ) = 0;
};

struct __declspec(uuid("8e4aa768-51e1-11d3-85cf-00c04f6123b3"))
FolderProperties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get___id (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_FileName (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall put_FileName (
        /*[in]*/ BSTR pbstrName ) = 0;
      virtual HRESULT __stdcall get_LocalPath (
        /*[out,retval]*/ BSTR * pbstrLocalPath ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * pbstrFullPath ) = 0;
      virtual HRESULT __stdcall get_URL (
        /*[out,retval]*/ BSTR * pbstrURL ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR ExtenderName,
        /*[out,retval]*/ IDispatch * * Extender ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * ExtenderNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pRetval ) = 0;
      virtual HRESULT __stdcall get_WebReference (
        /*[out,retval]*/ BSTR * pbstrWebReferenceUrl ) = 0;
      virtual HRESULT __stdcall put_WebReference (
        /*[in]*/ BSTR pbstrWebReferenceUrl ) = 0;
      virtual HRESULT __stdcall get_DefaultNamespace (
        /*[out,retval]*/ BSTR * pbstrNamespace ) = 0;
      virtual HRESULT __stdcall get_UrlBehavior (
        /*[out,retval]*/ enum webrefUrlBehavior * pUrlBehavior ) = 0;
      virtual HRESULT __stdcall put_UrlBehavior (
        /*[in]*/ enum webrefUrlBehavior pUrlBehavior ) = 0;
};

enum __declspec(uuid("b21668ef-29f1-425d-85d7-118cb838c362"))
prjReferenceType
{
    prjReferenceTypeAssembly = 0,
    prjReferenceTypeActiveX = 1
};

struct __declspec(uuid("1cf40c9e-d548-4b45-ad0f-3d7843f62bbb"))
_ReferencesEvents : IDispatch
{};

struct __declspec(uuid("287eb27c-0f8b-4d2d-8e82-a9ca50b6766e"))
_dispReferencesEvents : IDispatch
{};

struct __declspec(uuid("1cdb29fe-33b7-4392-9742-d9415d3408fe"))
ReferencesEvents;
    // [ default ] interface _ReferencesEvents
    // [ default, source ] dispinterface _dispReferencesEvents

struct __declspec(uuid("c711e2b7-3c58-4c37-9359-705208a890ae"))
BuildManager : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DTE (
        /*[out,retval]*/ struct EnvDTE::_DTE * * ppDTE ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_ContainingProject (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall get_DesignTimeOutputMonikers (
        /*[out,retval]*/ VARIANT * pvarMonikers ) = 0;
      virtual HRESULT __stdcall BuildDesignTimeOutput (
        /*[in]*/ BSTR bstrOutputMoniker,
        /*[out,retval]*/ BSTR * pbstrXMLFormat ) = 0;
};

struct __declspec(uuid("5f4aae42-bc94-401d-9213-b8a8b9e553de"))
_BuildManagerEvents : IDispatch
{};

struct __declspec(uuid("828914f7-1d81-4f5c-83ce-37819d7ee759"))
_dispBuildManagerEvents : IDispatch
{};

struct __declspec(uuid("66923b02-677b-4920-a319-f8925a0ba8a8"))
BuildManagerEvents;
    // [ default ] interface _BuildManagerEvents
    // [ default, source ] dispinterface _dispBuildManagerEvents

struct __declspec(uuid("642789f9-210d-4574-96fd-5a653451e216"))
Imports : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DTE (
        /*[out,retval]*/ struct EnvDTE::_DTE * * ppDTE ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_ContainingProject (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ long lIndex,
        /*[out,retval]*/ BSTR * pbstrImport ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR bstrImport ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ VARIANT index ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * ppiuReturn ) = 0;
};

struct __declspec(uuid("037ad859-7a75-4cf3-8a38-83d6e045fee3"))
_ImportsEvents : IDispatch
{};

struct __declspec(uuid("40806cea-abab-4887-a356-d8869c28a6e6"))
_dispImportsEvents : IDispatch
{};

struct __declspec(uuid("ac779606-837c-444f-b8fa-a69805b59976"))
ImportsEvents;
    // [ default ] interface _ImportsEvents
    // [ default, source ] dispinterface _dispImportsEvents

struct __declspec(uuid("f8b92546-f1a2-4066-92f6-fdf2e691a50c"))
VSProjectEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ReferencesEvents (
        /*[out,retval]*/ struct _ReferencesEvents * * ppRefsEvents ) = 0;
      virtual HRESULT __stdcall get_BuildManagerEvents (
        /*[out,retval]*/ struct _BuildManagerEvents * * ppBuildMgrEvents ) = 0;
      virtual HRESULT __stdcall get_ImportsEvents (
        /*[out,retval]*/ struct _ImportsEvents * * ppImportsEvents ) = 0;
};

enum __declspec(uuid("5de9f309-e701-44d1-8068-1860738c0084"))
prjCopyProjectOption
{
    prjRunFiles = 0,
    prjProjectFiles = 1,
    prjAllFiles = 2
};

enum __declspec(uuid("f111445e-a9ed-4d12-9a0e-738f5f995f10"))
prjExecCommand
{
    prjExecCommandHandleInvalidStartupObject = 0
};

struct __declspec(uuid("89ff44c6-979d-49b6-af56-ec9509001de4"))
VSProjectItem : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DTE (
        /*[out,retval]*/ struct EnvDTE::_DTE * * ppDTE ) = 0;
      virtual HRESULT __stdcall get_ProjectItem (
        /*[out,retval]*/ struct EnvDTE::ProjectItem * * ppProjectItem ) = 0;
      virtual HRESULT __stdcall get_ContainingProject (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall RunCustomTool ( ) = 0;
};

enum tagWebPrjAuthoringAccess
{
    webPrjAuthoringAccess_FileShare = 1,
    webPrjAuthoringAccess_FrontPage = 2
};

struct __declspec(uuid("8fa8d496-caf1-40b3-bc58-5fc877fefea7"))
WebSettings : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AuthoringAccess (
        /*[out,retval]*/ webPrjAuthoringAccess * pAccessMethod ) = 0;
      virtual HRESULT __stdcall put_AuthoringAccess (
        /*[in]*/ webPrjAuthoringAccess pAccessMethod ) = 0;
      virtual HRESULT __stdcall get_RepairLinks (
        /*[out,retval]*/ VARIANT_BOOL * pbRepairLinks ) = 0;
      virtual HRESULT __stdcall put_RepairLinks (
        /*[in]*/ VARIANT_BOOL pbRepairLinks ) = 0;
      virtual HRESULT __stdcall get_WebProjectCacheDirectory (
        /*[out,retval]*/ BSTR * pbstrDirectory ) = 0;
      virtual HRESULT __stdcall put_WebProjectCacheDirectory (
        /*[in]*/ BSTR pbstrDirectory ) = 0;
      virtual HRESULT __stdcall SetDefaultWebProjectCacheDirectory ( ) = 0;
};

struct __declspec(uuid("35d6fb50-35b6-4c81-b91c-3930b0d95386"))
Reference : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DTE (
        /*[out,retval]*/ struct EnvDTE::_DTE * * ppDTE ) = 0;
      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct References * * ppProjectReferences ) = 0;
      virtual HRESULT __stdcall get_ContainingProject (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall Remove ( ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum prjReferenceType * pType ) = 0;
      virtual HRESULT __stdcall get_Identity (
        /*[out,retval]*/ BSTR * pbstrIdentity ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * pbstrPath ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstrDesc ) = 0;
      virtual HRESULT __stdcall get_Culture (
        /*[out,retval]*/ BSTR * pbstrCulture ) = 0;
      virtual HRESULT __stdcall get_MajorVersion (
        /*[out,retval]*/ long * plMajorVer ) = 0;
      virtual HRESULT __stdcall get_MinorVersion (
        /*[out,retval]*/ long * plMinorVer ) = 0;
      virtual HRESULT __stdcall get_RevisionNumber (
        /*[out,retval]*/ long * plRevNo ) = 0;
      virtual HRESULT __stdcall get_BuildNumber (
        /*[out,retval]*/ long * plBuildNo ) = 0;
      virtual HRESULT __stdcall get_StrongName (
        /*[out,retval]*/ VARIANT_BOOL * pfStrongName ) = 0;
      virtual HRESULT __stdcall get_SourceProject (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall get_CopyLocal (
        /*[out,retval]*/ VARIANT_BOOL * pbCopyLocal ) = 0;
      virtual HRESULT __stdcall put_CopyLocal (
        /*[in]*/ VARIANT_BOOL pbCopyLocal ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR ExtenderName,
        /*[out,retval]*/ IDispatch * * Extender ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * ExtenderNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pRetval ) = 0;
      virtual HRESULT __stdcall get_PublicKeyToken (
        /*[out,retval]*/ BSTR * pbstrPublicKeyToken ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * pbstrVersion ) = 0;
};

struct __declspec(uuid("b8758ee4-0553-4bc9-8432-440449d35c14"))
References : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DTE (
        /*[out,retval]*/ struct EnvDTE::_DTE * * ppDTE ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppdispParent ) = 0;
      virtual HRESULT __stdcall get_ContainingProject (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * plCount ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct Reference * * ppProjectReference ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * ppiuReturn ) = 0;
      virtual HRESULT __stdcall Find (
        /*[in]*/ BSTR bstrIdentity,
        /*[out,retval]*/ struct Reference * * ppProjectReference ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR bstrPath,
        /*[out,retval]*/ struct Reference * * ppProjectReference ) = 0;
      virtual HRESULT __stdcall AddActiveX (
        /*[in]*/ BSTR bstrTypeLibGuid,
        /*[in]*/ long lMajorVer,
        /*[in]*/ long lMinorVer,
        /*[in]*/ long lLocaleId,
        /*[in]*/ BSTR bstrWrapperTool,
        /*[out,retval]*/ struct Reference * * ppProjectReference ) = 0;
      virtual HRESULT __stdcall AddProject (
        /*[in]*/ struct EnvDTE::Project * pProject,
        /*[out,retval]*/ struct Reference * * ppProjectReference ) = 0;
};

struct __declspec(uuid("2cfb826f-f6bf-480d-a546-95a0381cc411"))
VSProject : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_References (
        /*[out,retval]*/ struct References * * ppRefs ) = 0;
      virtual HRESULT __stdcall get_BuildManager (
        /*[out,retval]*/ struct BuildManager * * ppBuildMgr ) = 0;
      virtual HRESULT __stdcall get_DTE (
        /*[out,retval]*/ struct EnvDTE::_DTE * * ppDTE ) = 0;
      virtual HRESULT __stdcall get_Project (
        /*[out,retval]*/ struct EnvDTE::Project * * ppProject ) = 0;
      virtual HRESULT __stdcall CreateWebReferencesFolder (
        /*[out,retval]*/ struct EnvDTE::ProjectItem * * ppProjectItem ) = 0;
      virtual HRESULT __stdcall get_WebReferencesFolder (
        /*[out,retval]*/ struct EnvDTE::ProjectItem * * ppProjectItem ) = 0;
      virtual HRESULT __stdcall AddWebReference (
        /*[in]*/ BSTR bstrUrl,
        /*[out,retval]*/ struct EnvDTE::ProjectItem * * ppProjectItem ) = 0;
      virtual HRESULT __stdcall get_TemplatePath (
        /*[out,retval]*/ BSTR * pbstrTemplatePath ) = 0;
      virtual HRESULT __stdcall Refresh ( ) = 0;
      virtual HRESULT __stdcall get_WorkOffline (
        /*[out,retval]*/ VARIANT_BOOL * pbWorkOffline ) = 0;
      virtual HRESULT __stdcall put_WorkOffline (
        /*[in]*/ VARIANT_BOOL pbWorkOffline ) = 0;
      virtual HRESULT __stdcall get_Imports (
        /*[out,retval]*/ struct Imports * * ppImports ) = 0;
      virtual HRESULT __stdcall get_Events (
        /*[out,retval]*/ struct VSProjectEvents * * ppEvents ) = 0;
      virtual HRESULT __stdcall CopyProject (
        /*[in]*/ BSTR bstrDestFolder,
        /*[in]*/ BSTR bstrDestUNCPath,
        /*[in]*/ enum prjCopyProjectOption copyProjectOption,
        /*[in]*/ BSTR bstrUsername,
        /*[in]*/ BSTR bstrPassword ) = 0;
      virtual HRESULT __stdcall Exec (
        /*[in]*/ enum prjExecCommand command,
        long bSuppressUI,
        /*[in]*/ VARIANT varIn,
        /*[out]*/ VARIANT * pVarOut ) = 0;
      virtual HRESULT __stdcall GenerateKeyPairFiles (
        /*[in]*/ BSTR strPublicPrivateFile,
        /*[in]*/ BSTR strPublicOnlyFile ) = 0;
      virtual HRESULT __stdcall GetUniqueFilename (
        /*[in]*/ IDispatch * pDispatch,
        /*[in]*/ BSTR bstrRoot,
        /*[in]*/ BSTR bstrDesiredExt,
        /*[out,retval]*/ BSTR * pbstrFileName ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_VSLangProj =
    {0x49a1950e,0x3e35,0x4595,{0x8c,0xb9,0x92,0x0c,0x64,0xc4,0x4d,0x67}};
extern "C" const GUID __declspec(selectany) IID_ProjectConfigurationProperties =
    {0x3cdaa65d,0x1e9d,0x11d3,{0xb2,0x02,0x00,0xc0,0x4f,0x79,0xca,0xcb}};
extern "C" const GUID __declspec(selectany) IID_ProjectProperties =
    {0x3cdaa65e,0x1e9d,0x11d3,{0xb2,0x02,0x00,0xc0,0x4f,0x79,0xca,0xcb}};
extern "C" const GUID __declspec(selectany) IID_FileProperties =
    {0x516bd64e,0x51c0,0x11d3,{0x85,0xcf,0x00,0xc0,0x4f,0x61,0x23,0xb3}};
extern "C" const GUID __declspec(selectany) IID_FolderProperties =
    {0x8e4aa768,0x51e1,0x11d3,{0x85,0xcf,0x00,0xc0,0x4f,0x61,0x23,0xb3}};
extern "C" const GUID __declspec(selectany) IID__ReferencesEvents =
    {0x1cf40c9e,0xd548,0x4b45,{0xad,0x0f,0x3d,0x78,0x43,0xf6,0x2b,0xbb}};
extern "C" const GUID __declspec(selectany) DIID__dispReferencesEvents =
    {0x287eb27c,0x0f8b,0x4d2d,{0x8e,0x82,0xa9,0xca,0x50,0xb6,0x76,0x6e}};
extern "C" const GUID __declspec(selectany) CLSID_ReferencesEvents =
    {0x1cdb29fe,0x33b7,0x4392,{0x97,0x42,0xd9,0x41,0x5d,0x34,0x08,0xfe}};
extern "C" const GUID __declspec(selectany) IID_BuildManager =
    {0xc711e2b7,0x3c58,0x4c37,{0x93,0x59,0x70,0x52,0x08,0xa8,0x90,0xae}};
extern "C" const GUID __declspec(selectany) IID__BuildManagerEvents =
    {0x5f4aae42,0xbc94,0x401d,{0x92,0x13,0xb8,0xa8,0xb9,0xe5,0x53,0xde}};
extern "C" const GUID __declspec(selectany) DIID__dispBuildManagerEvents =
    {0x828914f7,0x1d81,0x4f5c,{0x83,0xce,0x37,0x81,0x9d,0x7e,0xe7,0x59}};
extern "C" const GUID __declspec(selectany) CLSID_BuildManagerEvents =
    {0x66923b02,0x677b,0x4920,{0xa3,0x19,0xf8,0x92,0x5a,0x0b,0xa8,0xa8}};
extern "C" const GUID __declspec(selectany) IID_Imports =
    {0x642789f9,0x210d,0x4574,{0x96,0xfd,0x5a,0x65,0x34,0x51,0xe2,0x16}};
extern "C" const GUID __declspec(selectany) IID__ImportsEvents =
    {0x037ad859,0x7a75,0x4cf3,{0x8a,0x38,0x83,0xd6,0xe0,0x45,0xfe,0xe3}};
extern "C" const GUID __declspec(selectany) DIID__dispImportsEvents =
    {0x40806cea,0xabab,0x4887,{0xa3,0x56,0xd8,0x86,0x9c,0x28,0xa6,0xe6}};
extern "C" const GUID __declspec(selectany) CLSID_ImportsEvents =
    {0xac779606,0x837c,0x444f,{0xb8,0xfa,0xa6,0x98,0x05,0xb5,0x99,0x76}};
extern "C" const GUID __declspec(selectany) IID_VSProjectEvents =
    {0xf8b92546,0xf1a2,0x4066,{0x92,0xf6,0xfd,0xf2,0xe6,0x91,0xa5,0x0c}};
extern "C" const GUID __declspec(selectany) IID_VSProjectItem =
    {0x89ff44c6,0x979d,0x49b6,{0xaf,0x56,0xec,0x95,0x09,0x00,0x1d,0xe4}};
extern "C" const GUID __declspec(selectany) IID_WebSettings =
    {0x8fa8d496,0xcaf1,0x40b3,{0xbc,0x58,0x5f,0xc8,0x77,0xfe,0xfe,0xa7}};
extern "C" const GUID __declspec(selectany) IID_Reference =
    {0x35d6fb50,0x35b6,0x4c81,{0xb9,0x1c,0x39,0x30,0xb0,0xd9,0x53,0x86}};
extern "C" const GUID __declspec(selectany) IID_References =
    {0xb8758ee4,0x0553,0x4bc9,{0x84,0x32,0x44,0x04,0x49,0xd3,0x5c,0x14}};
extern "C" const GUID __declspec(selectany) IID_VSProject =
    {0x2cfb826f,0xf6bf,0x480d,{0xa5,0x46,0x95,0xa0,0x38,0x1c,0xc4,0x11}};

} // namespace VSLangProj

#pragma pack(pop)
