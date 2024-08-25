// Created by Microsoft (R) C/C++ Compiler Version 14.00.23026.0 (08715b27).
//
// c:\users\sunhui2\documents\visual studio 2015\projects\atlproject1\atlproject1\debug\devshell.tlh
//
// C++ source equivalent of Win32 type library D:\devshell.tlb
// compiler-generated file created 11/01/15 at 10:25:52 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Forward references and typedefs
//

struct __declspec(uuid("b3cf8e20-19b6-11cf-8e4d-00aa004254c4"))
/* LIBID */ __DSSharedObjects;
enum DsWindowState;
enum DsArrangeStyle;
enum DsButtonType;
enum DsSaveChanges;
enum DsSaveStatus;
struct __declspec(uuid("fb7fdae1-89b8-11cf-9be8-00a0c90a632c"))
/* dual interface */ IGenericDocument;
struct __declspec(uuid("fd20fc80-a9d2-11cf-9c13-00a0c90a632c"))
/* dual interface */ IGenericWindow;
struct __declspec(uuid("8ca5a960-fc7d-11cf-927d-00a0c9138c45"))
/* dual interface */ IGenericProject;
struct __declspec(uuid("ec1d73a1-8cc4-11cf-9be9-00a0c90a632c"))
/* dual interface */ IApplication;
struct __declspec(uuid("9fd2df20-190d-11cf-8e4d-00aa004254c4"))
/* dispinterface */ IDispApplication;
struct __declspec(uuid("8ea3f900-4a9f-11cf-8e4e-00aa004254c4"))
/* dual interface */ IApplicationEvents;
struct __declspec(uuid("ae166b02-a9a0-11cf-ad07-00a0c9034965"))
/* dispinterface */ IDispApplicationEvents;
struct /* coclass */ Application;
struct __declspec(uuid("fb7fdae3-89b8-11cf-9be8-00a0c90a632c"))
/* dual interface */ IDocuments;
struct __declspec(uuid("e9eb1ae1-89a8-11cf-9be8-00a0c90a632c"))
/* dispinterface */ IDispDocuments;
struct /* coclass */ Documents;
struct __declspec(uuid("3928f551-96e6-11cf-9c00-00a0c90a632c"))
/* dual interface */ IWindows;
struct __declspec(uuid("5774d191-96e1-11cf-9c00-00a0c90a632c"))
/* dispinterface */ IDispWindows;
struct /* coclass */ Windows;
struct __declspec(uuid("13bf7741-a7e8-11cf-ad07-00a0c9034965"))
/* dual interface */ IProjects;
struct __declspec(uuid("dfac7c40-a810-11cf-ad07-00a0c9034965"))
/* dispinterface */ IDispProjects;
struct /* coclass */ Projects;
struct __declspec(uuid("e1870221-933a-11cf-9bf9-00a0c90a632c"))
/* dispinterface */ IDispGenericDocument;
struct /* coclass */ Document;
struct __declspec(uuid("e1870223-933a-11cf-9bf9-00a0c90a632c"))
/* dispinterface */ IDispGenericWindow;
struct /* coclass */ Window;
struct __declspec(uuid("520bec60-31e8-11d0-b17f-00a0c91bc8ed"))
/* dispinterface */ IDispGenericProject;
struct /* coclass */ Project;
struct __declspec(uuid("c0002f81-ae2e-11cf-ad07-00a0c9034965"))
/* interface */ IDSAddIn;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(IGenericDocument, __uuidof(IGenericDocument));
_COM_SMARTPTR_TYPEDEF(IGenericWindow, __uuidof(IGenericWindow));
_COM_SMARTPTR_TYPEDEF(IGenericProject, __uuidof(IGenericProject));
_COM_SMARTPTR_TYPEDEF(IApplication, __uuidof(IApplication));
_COM_SMARTPTR_TYPEDEF(IDispApplication, __uuidof(IDispApplication));
_COM_SMARTPTR_TYPEDEF(IApplicationEvents, __uuidof(IApplicationEvents));
_COM_SMARTPTR_TYPEDEF(IDispApplicationEvents, __uuidof(IDispApplicationEvents));
_COM_SMARTPTR_TYPEDEF(IDocuments, __uuidof(IDocuments));
_COM_SMARTPTR_TYPEDEF(IDispDocuments, __uuidof(IDispDocuments));
_COM_SMARTPTR_TYPEDEF(IWindows, __uuidof(IWindows));
_COM_SMARTPTR_TYPEDEF(IDispWindows, __uuidof(IDispWindows));
_COM_SMARTPTR_TYPEDEF(IProjects, __uuidof(IProjects));
_COM_SMARTPTR_TYPEDEF(IDispProjects, __uuidof(IDispProjects));
_COM_SMARTPTR_TYPEDEF(IDispGenericDocument, __uuidof(IDispGenericDocument));
_COM_SMARTPTR_TYPEDEF(IDispGenericWindow, __uuidof(IDispGenericWindow));
_COM_SMARTPTR_TYPEDEF(IDispGenericProject, __uuidof(IDispGenericProject));
_COM_SMARTPTR_TYPEDEF(IDSAddIn, __uuidof(IDSAddIn));

//
// Type library items
//

enum DsWindowState
{
    dsWindowStateMaximized = 1,
    dsWindowStateMinimized = 2,
    dsWindowStateNormal = 3
};

enum DsArrangeStyle
{
    dsMinimize = 1,
    dsTileHorizontal = 2,
    dsTileVertical = 3,
    dsCascade = 4
};

enum DsButtonType
{
    dsGlyph = 1,
    dsText = 2
};

enum DsSaveChanges
{
    dsSaveChangesYes = 1,
    dsSaveChangesNo = 2,
    dsSaveChangesPrompt = 3
};

enum DsSaveStatus
{
    dsSaveSucceeded = 1,
    dsSaveCanceled = 2
};

struct __declspec(uuid("fb7fdae1-89b8-11cf-9be8-00a0c90a632c"))
IGenericDocument : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pName ) = 0;
      virtual HRESULT __stdcall get_FullName (
        /*[out,retval]*/ BSTR * pName ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppApplication ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * pPath ) = 0;
      virtual HRESULT __stdcall get_Saved (
        /*[out,retval]*/ VARIANT_BOOL * pSaved ) = 0;
      virtual HRESULT __stdcall get_ActiveWindow (
        /*[out,retval]*/ IDispatch * * ppWindow ) = 0;
      virtual HRESULT __stdcall get_ReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pReadOnly ) = 0;
      virtual HRESULT __stdcall put_ReadOnly (
        /*[in]*/ VARIANT_BOOL pReadOnly ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ BSTR * pType ) = 0;
      virtual HRESULT __stdcall get_Windows (
        /*[out,retval]*/ IDispatch * * ppWindows ) = 0;
      virtual HRESULT __stdcall put_Active (
        /*[in]*/ VARIANT_BOOL pbActive ) = 0;
      virtual HRESULT __stdcall get_Active (
        /*[out,retval]*/ VARIANT_BOOL * pbActive ) = 0;
      virtual HRESULT __stdcall NewWindow (
        /*[out,retval]*/ IDispatch * * ppWindow ) = 0;
      virtual HRESULT __stdcall Save (
        /*[in]*/ VARIANT vFilename,
        /*[in]*/ VARIANT vBoolPrompt,
        /*[out,retval]*/ enum DsSaveStatus * pSaved ) = 0;
      virtual HRESULT __stdcall Undo (
        /*[out,retval]*/ VARIANT_BOOL * pSuccess ) = 0;
      virtual HRESULT __stdcall Redo (
        /*[out,retval]*/ VARIANT_BOOL * pSuccess ) = 0;
      virtual HRESULT __stdcall PrintOut (
        /*[out,retval]*/ VARIANT_BOOL * pSuccess ) = 0;
      virtual HRESULT __stdcall Close (
        /*[in]*/ VARIANT vSaveChanges,
        /*[out,retval]*/ enum DsSaveStatus * pSaved ) = 0;
      virtual HRESULT __stdcall Reserved1 ( ) = 0;
      virtual HRESULT __stdcall Reserved2 ( ) = 0;
      virtual HRESULT __stdcall Reserved3 ( ) = 0;
      virtual HRESULT __stdcall Reserved4 ( ) = 0;
      virtual HRESULT __stdcall Reserved5 ( ) = 0;
      virtual HRESULT __stdcall Reserved6 ( ) = 0;
      virtual HRESULT __stdcall Reserved7 ( ) = 0;
      virtual HRESULT __stdcall Reserved8 ( ) = 0;
      virtual HRESULT __stdcall Reserved9 ( ) = 0;
      virtual HRESULT __stdcall Reserved10 ( ) = 0;
};

struct __declspec(uuid("fd20fc80-a9d2-11cf-9c13-00a0c90a632c"))
IGenericWindow : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * pbstrCaption ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ BSTR * pbstrCaption ) = 0;
      virtual HRESULT __stdcall put_Active (
        /*[in]*/ VARIANT_BOOL pbActive ) = 0;
      virtual HRESULT __stdcall get_Active (
        /*[out,retval]*/ VARIANT_BOOL * pbActive ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ long plVal ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ long * plVal ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ long plVal ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ long * plVal ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long plVal ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * plVal ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long plVal ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * plVal ) = 0;
      virtual HRESULT __stdcall get_Index (
        /*[out,retval]*/ long * plVal ) = 0;
      virtual HRESULT __stdcall get_Next (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Previous (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
      virtual HRESULT __stdcall put_WindowState (
        /*[in]*/ enum DsWindowState plVal ) = 0;
      virtual HRESULT __stdcall get_WindowState (
        /*[out,retval]*/ enum DsWindowState * plVal ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
      virtual HRESULT __stdcall Close (
        /*[in]*/ VARIANT boolSaveChanges,
        /*[out,retval]*/ enum DsSaveStatus * pSaved ) = 0;
      virtual HRESULT __stdcall Reserved1 ( ) = 0;
      virtual HRESULT __stdcall Reserved2 ( ) = 0;
      virtual HRESULT __stdcall Reserved3 ( ) = 0;
      virtual HRESULT __stdcall Reserved4 ( ) = 0;
      virtual HRESULT __stdcall Reserved5 ( ) = 0;
      virtual HRESULT __stdcall Reserved6 ( ) = 0;
      virtual HRESULT __stdcall Reserved7 ( ) = 0;
      virtual HRESULT __stdcall Reserved8 ( ) = 0;
      virtual HRESULT __stdcall Reserved9 ( ) = 0;
      virtual HRESULT __stdcall Reserved10 ( ) = 0;
};

struct __declspec(uuid("8ca5a960-fc7d-11cf-927d-00a0c9138c45"))
IGenericProject : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_FullName (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * Application ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ BSTR * pType ) = 0;
      virtual HRESULT __stdcall Reserved1 ( ) = 0;
      virtual HRESULT __stdcall Reserved2 ( ) = 0;
      virtual HRESULT __stdcall Reserved3 ( ) = 0;
      virtual HRESULT __stdcall Reserved4 ( ) = 0;
      virtual HRESULT __stdcall Reserved5 ( ) = 0;
      virtual HRESULT __stdcall Reserved6 ( ) = 0;
      virtual HRESULT __stdcall Reserved7 ( ) = 0;
      virtual HRESULT __stdcall Reserved8 ( ) = 0;
      virtual HRESULT __stdcall Reserved9 ( ) = 0;
      virtual HRESULT __stdcall Reserved10 ( ) = 0;
};
    const LPSTR dsApplication = (char*) "Application";
    const LPSTR dsDLL = (char*) "DLL";
    const LPSTR dsConsoleApp = (char*) "Console Application";
    const LPSTR dsStaticLib = (char*) "Static Library";
    const LPSTR dsUtility = (char*) "Utility";
    const LPSTR dsMakefile = (char*) "Makefile";
    const LPSTR dsFortran1 = (char*) "QuickWin Application";
    const LPSTR dsFortran2 = (char*) "Standard Graphics Application";

struct __declspec(uuid("ec1d73a1-8cc4-11cf-9be9-00a0c90a632c"))
IApplication : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * Height ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long Height ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * Width ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long Width ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ long * Top ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ long Top ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ long * Left ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ long Left ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall get_TextEditor (
        /*[out,retval]*/ IDispatch * * TextEditor ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * Version ) = 0;
      virtual HRESULT __stdcall get_Path (
        /*[out,retval]*/ BSTR * Path ) = 0;
      virtual HRESULT __stdcall get_CurrentDirectory (
        /*[out,retval]*/ BSTR * CurrentDirectory ) = 0;
      virtual HRESULT __stdcall put_CurrentDirectory (
        /*[in]*/ BSTR CurrentDirectory ) = 0;
      virtual HRESULT __stdcall get_FullName (
        /*[out,retval]*/ BSTR * FullName ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * Application ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get_ActiveDocument (
        /*[out,retval]*/ IDispatch * * ActiveDocument ) = 0;
      virtual HRESULT __stdcall get_Windows (
        /*[out,retval]*/ IDispatch * * Windows ) = 0;
      virtual HRESULT __stdcall get_Documents (
        /*[out,retval]*/ IDispatch * * Documents ) = 0;
      virtual HRESULT __stdcall get_ActiveWindow (
        /*[out,retval]*/ IDispatch * * ActiveWindow ) = 0;
      virtual HRESULT __stdcall get_WindowState (
        /*[out,retval]*/ enum DsWindowState * WindowState ) = 0;
      virtual HRESULT __stdcall put_WindowState (
        /*[in]*/ enum DsWindowState WindowState ) = 0;
      virtual HRESULT __stdcall get_Debugger (
        /*[out,retval]*/ IDispatch * * ppDebugger ) = 0;
      virtual HRESULT __stdcall get_Projects (
        /*[out,retval]*/ IDispatch * * Projects ) = 0;
      virtual HRESULT __stdcall get_ActiveConfiguration (
        /*[out,retval]*/ IDispatch * * ActiveConfiguration ) = 0;
      virtual HRESULT __stdcall put_ActiveConfiguration (
        /*[in]*/ IDispatch * ActiveConfiguration ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ VARIANT_BOOL * Visible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ VARIANT_BOOL Visible ) = 0;
      virtual HRESULT __stdcall get_ActiveProject (
        /*[out,retval]*/ IDispatch * * ActiveProject ) = 0;
      virtual HRESULT __stdcall put_ActiveProject (
        /*[in]*/ IDispatch * ActiveProject ) = 0;
      virtual HRESULT __stdcall put_Active (
        /*[in]*/ VARIANT_BOOL pbActive ) = 0;
      virtual HRESULT __stdcall get_Active (
        /*[out,retval]*/ VARIANT_BOOL * pbActive ) = 0;
      virtual HRESULT __stdcall GetPackageExtension (
        /*[in]*/ BSTR szExtensionName,
        /*[out,retval]*/ IDispatch * * pExt ) = 0;
      virtual HRESULT __stdcall Quit ( ) = 0;
      virtual HRESULT __stdcall PrintToOutputWindow (
        /*[in]*/ BSTR Message ) = 0;
      virtual HRESULT __stdcall ExecuteCommand (
        /*[in]*/ BSTR szCommandName ) = 0;
      virtual HRESULT __stdcall AddCommandBarButton (
        /*[in]*/ long nButtonType,
        /*[in]*/ BSTR szCmdName,
        /*[in]*/ long dwCookie ) = 0;
      virtual HRESULT __stdcall AddKeyBinding (
        /*[in]*/ BSTR szKey,
        /*[in]*/ BSTR szCommandName,
        /*[in]*/ BSTR szEditor ) = 0;
      virtual HRESULT __stdcall Build (
        /*[in]*/ VARIANT Configuration = vtMissing ) = 0;
      virtual HRESULT __stdcall RebuildAll (
        /*[in]*/ VARIANT Configuration = vtMissing ) = 0;
      virtual HRESULT __stdcall ExecuteConfiguration (
        /*[in]*/ VARIANT Reserved = vtMissing ) = 0;
      virtual HRESULT __stdcall SetAddInInfo (
        /*[in]*/ long nInstanceHandle,
        /*[in]*/ IDispatch * pCmdDispatch,
        /*[in]*/ long nIDBitmapResourceMedium,
        /*[in]*/ long nIDBitmapResourceLarge,
        /*[in]*/ long dwCookie ) = 0;
      virtual HRESULT __stdcall AddCommand (
        /*[in]*/ BSTR szCmdName,
        /*[in]*/ BSTR szMethodName,
        /*[in]*/ long nBitmapOffset,
        /*[in]*/ long dwCookie,
        /*[out,retval]*/ VARIANT_BOOL * pbResult ) = 0;
      virtual HRESULT __stdcall EnableModeless (
        /*[in]*/ VARIANT_BOOL bEnable ) = 0;
      virtual HRESULT __stdcall Clean (
        /*[in]*/ VARIANT Configuration = vtMissing ) = 0;
      virtual HRESULT __stdcall get_Errors (
        /*[out,retval]*/ long * Errors ) = 0;
      virtual HRESULT __stdcall get_Warnings (
        /*[out,retval]*/ long * Warnings ) = 0;
      virtual HRESULT __stdcall AddProject (
        /*[in]*/ BSTR szName,
        /*[in]*/ BSTR szPath,
        /*[in]*/ BSTR szType,
        /*[in]*/ VARIANT bAddDefaultFolders ) = 0;
};

struct __declspec(uuid("9fd2df20-190d-11cf-8e4d-00aa004254c4"))
IDispApplication : IDispatch
{};

struct __declspec(uuid("8ea3f900-4a9f-11cf-8e4e-00aa004254c4"))
IApplicationEvents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall BeforeBuildStart ( ) = 0;
      virtual HRESULT __stdcall BuildFinish (
        /*[in]*/ long nNumErrors,
        /*[in]*/ long nNumWarnings ) = 0;
      virtual HRESULT __stdcall BeforeApplicationShutDown ( ) = 0;
      virtual HRESULT __stdcall DocumentOpen (
        /*[in]*/ IDispatch * theDocument ) = 0;
      virtual HRESULT __stdcall BeforeDocumentClose (
        /*[in]*/ IDispatch * theDocument ) = 0;
      virtual HRESULT __stdcall DocumentSave (
        /*[in]*/ IDispatch * theDocument ) = 0;
      virtual HRESULT __stdcall NewDocument (
        /*[in]*/ IDispatch * theDocument ) = 0;
      virtual HRESULT __stdcall WindowActivate (
        /*[in]*/ IDispatch * theWindow ) = 0;
      virtual HRESULT __stdcall WindowDeactivate (
        /*[in]*/ IDispatch * theWindow ) = 0;
      virtual HRESULT __stdcall WorkspaceOpen ( ) = 0;
      virtual HRESULT __stdcall WorkspaceClose ( ) = 0;
      virtual HRESULT __stdcall NewWorkspace ( ) = 0;
};

struct __declspec(uuid("ae166b02-a9a0-11cf-ad07-00a0c9034965"))
IDispApplicationEvents : IDispatch
{};

struct __declspec(uuid("fb7fdae2-89b8-11cf-9be8-00a0c90a632c"))
Application;
    // dispinterface IDispApplication
    // [ default ] interface IApplication
    // [ source ] interface IApplicationEvents
    // [ default, source ] dispinterface IDispApplicationEvents

struct __declspec(uuid("fb7fdae3-89b8-11cf-9be8-00a0c90a632c"))
IDocuments : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppApplication ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * Item ) = 0;
      virtual HRESULT __stdcall SaveAll (
        /*[in]*/ VARIANT vtBoolPrompt,
        /*[out,retval]*/ enum DsSaveStatus * pSaved ) = 0;
      virtual HRESULT __stdcall CloseAll (
        /*[in]*/ VARIANT vtSaveChanges,
        /*[out,retval]*/ enum DsSaveStatus * pSaved ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ BSTR docType,
        /*[in]*/ VARIANT vtReserved,
        /*[out,retval]*/ IDispatch * * ppDocument ) = 0;
      virtual HRESULT __stdcall Open (
        /*[in]*/ BSTR filename,
        /*[in]*/ VARIANT vtDocType,
        /*[in]*/ VARIANT vtBoolReadOnly,
        /*[out,retval]*/ IDispatch * * ppDocument ) = 0;
};

struct __declspec(uuid("e9eb1ae1-89a8-11cf-9be8-00a0c90a632c"))
IDispDocuments : IDispatch
{};

struct __declspec(uuid("e9eb1ae2-89a8-11cf-9be8-00a0c90a632c"))
Documents;
    // dispinterface IDispDocuments
    // [ default ] interface IDocuments

struct __declspec(uuid("3928f551-96e6-11cf-9c00-00a0c90a632c"))
IWindows : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * ppApplication ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * ppParent ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ IDispatch * * Item ) = 0;
      virtual HRESULT __stdcall Arrange (
        /*[in]*/ VARIANT vtArrangeStyle ) = 0;
      virtual HRESULT __stdcall CloseAll (
        /*[in]*/ VARIANT vtSaveChanges,
        /*[out,retval]*/ enum DsSaveStatus * pSaved ) = 0;
};

struct __declspec(uuid("5774d191-96e1-11cf-9c00-00a0c90a632c"))
IDispWindows : IDispatch
{};

struct __declspec(uuid("5774d192-96e1-11cf-9c00-00a0c90a632c"))
Windows;
    // dispinterface IDispWindows
    // [ default ] interface IWindows

struct __declspec(uuid("13bf7741-a7e8-11cf-ad07-00a0c9034965"))
IProjects : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ IDispatch * * Application ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * Parent ) = 0;
      virtual HRESULT __stdcall get__NewEnum (
        /*[out,retval]*/ IUnknown * * _NewEnum ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT Index,
        /*[out,retval]*/ struct IGenericProject * * Item ) = 0;
};

struct __declspec(uuid("dfac7c40-a810-11cf-ad07-00a0c9034965"))
IDispProjects : IDispatch
{};

struct __declspec(uuid("dfac7c41-a810-11cf-ad07-00a0c9034965"))
Projects;
    // [ default ] interface IProjects
    // dispinterface IDispProjects

struct __declspec(uuid("e1870221-933a-11cf-9bf9-00a0c90a632c"))
IDispGenericDocument : IDispatch
{};

struct __declspec(uuid("e1870222-933a-11cf-9bf9-00a0c90a632c"))
Document;
    // dispinterface IDispGenericDocument
    // [ default ] interface IGenericDocument

struct __declspec(uuid("e1870223-933a-11cf-9bf9-00a0c90a632c"))
IDispGenericWindow : IDispatch
{};

struct __declspec(uuid("e1870224-933a-11cf-9bf9-00a0c90a632c"))
Window;
    // dispinterface IDispGenericWindow
    // [ default ] interface IGenericWindow

struct __declspec(uuid("520bec60-31e8-11d0-b17f-00a0c91bc8ed"))
IDispGenericProject : IDispatch
{};

struct __declspec(uuid("520bec61-31e8-11d0-b17f-00a0c91bc8ed"))
Project;
    // dispinterface IDispGenericProject
    // [ default ] interface IGenericProject

struct __declspec(uuid("c0002f81-ae2e-11cf-ad07-00a0c9034965"))
IDSAddIn : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall OnConnection (
        /*[in]*/ struct IApplication * pApp,
        /*[in]*/ VARIANT_BOOL bFirstTime,
        /*[in]*/ long dwCookie,
        /*[out,retval]*/ VARIANT_BOOL * OnConnection ) = 0;
      virtual HRESULT __stdcall OnDisconnection (
        /*[in]*/ VARIANT_BOOL bLastTime ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_DSSharedObjects =
    {0xb3cf8e20,0x19b6,0x11cf,{0x8e,0x4d,0x00,0xaa,0x00,0x42,0x54,0xc4}};
extern "C" const GUID __declspec(selectany) IID_IGenericDocument =
    {0xfb7fdae1,0x89b8,0x11cf,{0x9b,0xe8,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) IID_IGenericWindow =
    {0xfd20fc80,0xa9d2,0x11cf,{0x9c,0x13,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) IID_IGenericProject =
    {0x8ca5a960,0xfc7d,0x11cf,{0x92,0x7d,0x00,0xa0,0xc9,0x13,0x8c,0x45}};
extern "C" const GUID __declspec(selectany) IID_IApplication =
    {0xec1d73a1,0x8cc4,0x11cf,{0x9b,0xe9,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) DIID_IDispApplication =
    {0x9fd2df20,0x190d,0x11cf,{0x8e,0x4d,0x00,0xaa,0x00,0x42,0x54,0xc4}};
extern "C" const GUID __declspec(selectany) IID_IApplicationEvents =
    {0x8ea3f900,0x4a9f,0x11cf,{0x8e,0x4e,0x00,0xaa,0x00,0x42,0x54,0xc4}};
extern "C" const GUID __declspec(selectany) DIID_IDispApplicationEvents =
    {0xae166b02,0xa9a0,0x11cf,{0xad,0x07,0x00,0xa0,0xc9,0x03,0x49,0x65}};
extern "C" const GUID __declspec(selectany) CLSID_Application =
    {0xfb7fdae2,0x89b8,0x11cf,{0x9b,0xe8,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) IID_IDocuments =
    {0xfb7fdae3,0x89b8,0x11cf,{0x9b,0xe8,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) DIID_IDispDocuments =
    {0xe9eb1ae1,0x89a8,0x11cf,{0x9b,0xe8,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) CLSID_Documents =
    {0xe9eb1ae2,0x89a8,0x11cf,{0x9b,0xe8,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) IID_IWindows =
    {0x3928f551,0x96e6,0x11cf,{0x9c,0x00,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) DIID_IDispWindows =
    {0x5774d191,0x96e1,0x11cf,{0x9c,0x00,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) CLSID_Windows =
    {0x5774d192,0x96e1,0x11cf,{0x9c,0x00,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) IID_IProjects =
    {0x13bf7741,0xa7e8,0x11cf,{0xad,0x07,0x00,0xa0,0xc9,0x03,0x49,0x65}};
extern "C" const GUID __declspec(selectany) DIID_IDispProjects =
    {0xdfac7c40,0xa810,0x11cf,{0xad,0x07,0x00,0xa0,0xc9,0x03,0x49,0x65}};
extern "C" const GUID __declspec(selectany) CLSID_Projects =
    {0xdfac7c41,0xa810,0x11cf,{0xad,0x07,0x00,0xa0,0xc9,0x03,0x49,0x65}};
extern "C" const GUID __declspec(selectany) DIID_IDispGenericDocument =
    {0xe1870221,0x933a,0x11cf,{0x9b,0xf9,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) CLSID_Document =
    {0xe1870222,0x933a,0x11cf,{0x9b,0xf9,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) DIID_IDispGenericWindow =
    {0xe1870223,0x933a,0x11cf,{0x9b,0xf9,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) CLSID_Window =
    {0xe1870224,0x933a,0x11cf,{0x9b,0xf9,0x00,0xa0,0xc9,0x0a,0x63,0x2c}};
extern "C" const GUID __declspec(selectany) DIID_IDispGenericProject =
    {0x520bec60,0x31e8,0x11d0,{0xb1,0x7f,0x00,0xa0,0xc9,0x1b,0xc8,0xed}};
extern "C" const GUID __declspec(selectany) CLSID_Project =
    {0x520bec61,0x31e8,0x11d0,{0xb1,0x7f,0x00,0xa0,0xc9,0x1b,0xc8,0xed}};
extern "C" const GUID __declspec(selectany) IID_IDSAddIn =
    {0xc0002f81,0xae2e,0x11cf,{0xad,0x07,0x00,0xa0,0xc9,0x03,0x49,0x65}};

#pragma pack(pop)
