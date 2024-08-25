/********************************************************************************
 *           Web Runtime for Application - Version 1.0.1.202110220001
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

//
// Cross-referenced type libraries:
//
#include "mso.h"
//

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace VBIDE {

//
// Forward references and typedefs
//

struct __declspec(uuid("0002e157-0000-0000-c000-000000000046"))
/* LIBID */ __VBIDE;
struct __declspec(uuid("0002e158-0000-0000-c000-000000000046"))
/* dual interface */ Application;
enum vbextFileTypes;
struct __declspec(uuid("0002e166-0000-0000-c000-000000000046"))
/* dual interface */ VBE;
enum vbext_WindowType;
enum vbext_WindowState;
struct __declspec(uuid("0002e16b-0000-0000-c000-000000000046"))
/* dual interface */ Window;
struct __declspec(uuid("0002e16a-0000-0000-c000-000000000046"))
/* dual interface */ _Windows_old;
struct __declspec(uuid("f57b7ed0-d8ab-11d1-85df-00c04f98f42c"))
/* dual interface */ _Windows;
struct /* coclass */ Windows;
struct __declspec(uuid("0002e16c-0000-0000-c000-000000000046"))
/* dual interface */ _LinkedWindows;
struct /* coclass */ LinkedWindows;
struct __declspec(uuid("0002e167-0000-0000-c000-000000000046"))
/* dual interface */ Events;
struct __declspec(uuid("0002e113-0000-0000-c000-000000000046"))
/* interface */ _VBProjectsEvents;
struct __declspec(uuid("0002e103-0000-0000-c000-000000000046"))
/* dispinterface */ _dispVBProjectsEvents;
struct __declspec(uuid("0002e115-0000-0000-c000-000000000046"))
/* interface */ _VBComponentsEvents;
struct __declspec(uuid("0002e116-0000-0000-c000-000000000046"))
/* dispinterface */ _dispVBComponentsEvents;
struct __declspec(uuid("0002e11a-0000-0000-c000-000000000046"))
/* interface */ _ReferencesEvents;
struct __declspec(uuid("0002e118-0000-0000-c000-000000000046"))
/* dispinterface */ _dispReferencesEvents;
struct /* coclass */ ReferencesEvents;
struct __declspec(uuid("0002e130-0000-0000-c000-000000000046"))
/* interface */ _CommandBarControlEvents;
struct __declspec(uuid("0002e131-0000-0000-c000-000000000046"))
/* dispinterface */ _dispCommandBarControlEvents;
struct /* coclass */ CommandBarEvents;
struct __declspec(uuid("0002e159-0000-0000-c000-000000000046"))
/* dual interface */ _ProjectTemplate;
struct /* coclass */ ProjectTemplate;
enum vbext_ProjectType;
enum vbext_ProjectProtection;
enum vbext_VBAMode;
struct __declspec(uuid("0002e160-0000-0000-c000-000000000046"))
/* dual interface */ _VBProject_Old;
struct __declspec(uuid("eee00915-e393-11d1-bb03-00c04fb6c4a6"))
/* dual interface */ _VBProject;
struct /* coclass */ VBProject;
struct __declspec(uuid("0002e165-0000-0000-c000-000000000046"))
/* dual interface */ _VBProjects_Old;
struct __declspec(uuid("eee00919-e393-11d1-bb03-00c04fb6c4a6"))
/* dual interface */ _VBProjects;
struct /* coclass */ VBProjects;
struct __declspec(uuid("be39f3d4-1b13-11d0-887f-00a0c90f2744"))
/* dual interface */ SelectedComponents;
enum vbext_ComponentType;
struct __declspec(uuid("0002e161-0000-0000-c000-000000000046"))
/* dual interface */ _Components;
struct /* coclass */ Components;
struct __declspec(uuid("0002e162-0000-0000-c000-000000000046"))
/* dual interface */ _VBComponents_Old;
struct __declspec(uuid("eee0091c-e393-11d1-bb03-00c04fb6c4a6"))
/* dual interface */ _VBComponents;
struct /* coclass */ VBComponents;
struct __declspec(uuid("0002e163-0000-0000-c000-000000000046"))
/* dual interface */ _Component;
struct /* coclass */ Component;
struct __declspec(uuid("0002e164-0000-0000-c000-000000000046"))
/* dual interface */ _VBComponent_Old;
struct __declspec(uuid("eee00921-e393-11d1-bb03-00c04fb6c4a6"))
/* dual interface */ _VBComponent;
struct /* coclass */ VBComponent;
struct __declspec(uuid("0002e18c-0000-0000-c000-000000000046"))
/* dual interface */ Property;
struct __declspec(uuid("0002e188-0000-0000-c000-000000000046"))
/* dual interface */ _Properties;
struct /* coclass */ Properties;
struct __declspec(uuid("da936b62-ac8b-11d1-b6e5-00a0c90f2744"))
/* dual interface */ _AddIns;
struct /* coclass */ Addins;
struct __declspec(uuid("da936b64-ac8b-11d1-b6e5-00a0c90f2744"))
/* dual interface */ AddIn;
enum vbext_ProcKind;
struct __declspec(uuid("0002e16e-0000-0000-c000-000000000046"))
/* dual interface */ _CodeModule;
struct /* coclass */ CodeModule;
struct __declspec(uuid("0002e172-0000-0000-c000-000000000046"))
/* dual interface */ _CodePanes;
struct /* coclass */ CodePanes;
enum vbext_CodePaneview;
struct __declspec(uuid("0002e176-0000-0000-c000-000000000046"))
/* dual interface */ _CodePane;
struct /* coclass */ CodePane;
struct __declspec(uuid("0002e17a-0000-0000-c000-000000000046"))
/* dual interface */ _References;
enum vbext_RefKind;
struct __declspec(uuid("0002e17e-0000-0000-c000-000000000046"))
/* dual interface */ Reference;
struct __declspec(uuid("cdde3804-2064-11cf-867f-00aa005ff34a"))
/* dispinterface */ _dispReferences_Events;
struct /* coclass */ References;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(Application, __uuidof(Application));
_COM_SMARTPTR_TYPEDEF(_VBProjectsEvents, __uuidof(_VBProjectsEvents));
_COM_SMARTPTR_TYPEDEF(_dispVBProjectsEvents, __uuidof(_dispVBProjectsEvents));
_COM_SMARTPTR_TYPEDEF(_VBComponentsEvents, __uuidof(_VBComponentsEvents));
_COM_SMARTPTR_TYPEDEF(_dispVBComponentsEvents, __uuidof(_dispVBComponentsEvents));
_COM_SMARTPTR_TYPEDEF(_ReferencesEvents, __uuidof(_ReferencesEvents));
_COM_SMARTPTR_TYPEDEF(_dispReferencesEvents, __uuidof(_dispReferencesEvents));
_COM_SMARTPTR_TYPEDEF(_CommandBarControlEvents, __uuidof(_CommandBarControlEvents));
_COM_SMARTPTR_TYPEDEF(_dispCommandBarControlEvents, __uuidof(_dispCommandBarControlEvents));
_COM_SMARTPTR_TYPEDEF(_ProjectTemplate, __uuidof(_ProjectTemplate));
_COM_SMARTPTR_TYPEDEF(Events, __uuidof(Events));
_COM_SMARTPTR_TYPEDEF(_Component, __uuidof(_Component));
_COM_SMARTPTR_TYPEDEF(SelectedComponents, __uuidof(SelectedComponents));
_COM_SMARTPTR_TYPEDEF(_dispReferences_Events, __uuidof(_dispReferences_Events));
_COM_SMARTPTR_TYPEDEF(VBE, __uuidof(VBE));
_COM_SMARTPTR_TYPEDEF(Window, __uuidof(Window));
_COM_SMARTPTR_TYPEDEF(_Windows_old, __uuidof(_Windows_old));
_COM_SMARTPTR_TYPEDEF(_LinkedWindows, __uuidof(_LinkedWindows));
_COM_SMARTPTR_TYPEDEF(_VBProject_Old, __uuidof(_VBProject_Old));
_COM_SMARTPTR_TYPEDEF(_VBProject, __uuidof(_VBProject));
_COM_SMARTPTR_TYPEDEF(_VBProjects_Old, __uuidof(_VBProjects_Old));
_COM_SMARTPTR_TYPEDEF(_VBProjects, __uuidof(_VBProjects));
_COM_SMARTPTR_TYPEDEF(_Components, __uuidof(_Components));
_COM_SMARTPTR_TYPEDEF(_VBComponents_Old, __uuidof(_VBComponents_Old));
_COM_SMARTPTR_TYPEDEF(_VBComponents, __uuidof(_VBComponents));
_COM_SMARTPTR_TYPEDEF(_VBComponent_Old, __uuidof(_VBComponent_Old));
_COM_SMARTPTR_TYPEDEF(_VBComponent, __uuidof(_VBComponent));
_COM_SMARTPTR_TYPEDEF(Property, __uuidof(Property));
_COM_SMARTPTR_TYPEDEF(_Properties, __uuidof(_Properties));
_COM_SMARTPTR_TYPEDEF(AddIn, __uuidof(AddIn));
_COM_SMARTPTR_TYPEDEF(_Windows, __uuidof(_Windows));
_COM_SMARTPTR_TYPEDEF(_AddIns, __uuidof(_AddIns));
_COM_SMARTPTR_TYPEDEF(_CodeModule, __uuidof(_CodeModule));
_COM_SMARTPTR_TYPEDEF(_CodePanes, __uuidof(_CodePanes));
_COM_SMARTPTR_TYPEDEF(_CodePane, __uuidof(_CodePane));
_COM_SMARTPTR_TYPEDEF(Reference, __uuidof(Reference));
_COM_SMARTPTR_TYPEDEF(_References, __uuidof(_References));

//
// Type library items
//

struct __declspec(uuid("0002e158-0000-0000-c000-000000000046"))
Application : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * lpbstrReturn ) = 0;
};

enum __declspec(uuid("06a03650-2369-11ce-bfdc-08002b2b8cda"))
vbextFileTypes
{
    vbextFileTypeForm = 0,
    vbextFileTypeModule = 1,
    vbextFileTypeClass = 2,
    vbextFileTypeProject = 3,
    vbextFileTypeExe = 4,
    vbextFileTypeFrx = 5,
    vbextFileTypeRes = 6,
    vbextFileTypeUserControl = 7,
    vbextFileTypePropertyPage = 8,
    vbextFileTypeDocObject = 9,
    vbextFileTypeBinary = 10,
    vbextFileTypeGroupProject = 11,
    vbextFileTypeDesigners = 12
};

enum __declspec(uuid("be39f3db-1b13-11d0-887f-00a0c90f2744"))
vbext_WindowType
{
    vbext_wt_CodeWindow = 0,
    vbext_wt_Designer = 1,
    vbext_wt_Browser = 2,
    vbext_wt_Watch = 3,
    vbext_wt_Locals = 4,
    vbext_wt_Immediate = 5,
    vbext_wt_ProjectWindow = 6,
    vbext_wt_PropertyWindow = 7,
    vbext_wt_Find = 8,
    vbext_wt_FindReplace = 9,
    vbext_wt_Toolbox = 10,
    vbext_wt_LinkedWindowFrame = 11,
    vbext_wt_MainWindow = 12,
    vbext_wt_ToolWindow = 15
};

enum __declspec(uuid("be39f3dc-1b13-11d0-887f-00a0c90f2744"))
vbext_WindowState
{
    vbext_ws_Normal = 0,
    vbext_ws_Minimize = 1,
    vbext_ws_Maximize = 2
};

//struct __declspec(uuid("0002e185-0000-0000-c000-000000000046"))
//Windows;
//    // [ default ] interface _Windows
//
//struct __declspec(uuid("0002e187-0000-0000-c000-000000000046"))
//LinkedWindows;
    // [ default ] interface _LinkedWindows

struct __declspec(uuid("0002e113-0000-0000-c000-000000000046"))
_VBProjectsEvents : IUnknown
{};

struct __declspec(uuid("0002e103-0000-0000-c000-000000000046"))
_dispVBProjectsEvents : IDispatch
{};

struct __declspec(uuid("0002e115-0000-0000-c000-000000000046"))
_VBComponentsEvents : IUnknown
{};

struct __declspec(uuid("0002e116-0000-0000-c000-000000000046"))
_dispVBComponentsEvents : IDispatch
{};

struct __declspec(uuid("0002e11a-0000-0000-c000-000000000046"))
_ReferencesEvents : IUnknown
{};

struct __declspec(uuid("0002e118-0000-0000-c000-000000000046"))
_dispReferencesEvents : IDispatch
{};

struct __declspec(uuid("0002e119-0000-0000-c000-000000000046"))
ReferencesEvents;
    // [ default ] interface _ReferencesEvents
    // [ default, source ] dispinterface _dispReferencesEvents

struct __declspec(uuid("0002e130-0000-0000-c000-000000000046"))
_CommandBarControlEvents : IUnknown
{};

struct __declspec(uuid("0002e131-0000-0000-c000-000000000046"))
_dispCommandBarControlEvents : IDispatch
{};

struct __declspec(uuid("0002e132-0000-0000-c000-000000000046"))
CommandBarEvents;
    // [ default ] interface _CommandBarControlEvents
    // [ default, source ] dispinterface _dispCommandBarControlEvents

struct __declspec(uuid("0002e159-0000-0000-c000-000000000046"))
_ProjectTemplate : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct Application * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Application * * lppaReturn ) = 0;
};

struct __declspec(uuid("32cdf9e0-1602-11ce-bfdc-08002b2b8cda"))
ProjectTemplate;
    // [ default ] interface _ProjectTemplate

enum __declspec(uuid("ffcf3247-debf-11d1-baff-00c04fb6c4a6"))
vbext_ProjectType
{
    vbext_pt_HostProject = 100,
    vbext_pt_StandAlone = 101
};

enum __declspec(uuid("0002e129-0000-0000-c000-000000000046"))
vbext_ProjectProtection
{
    vbext_pp_none = 0,
    vbext_pp_locked = 1
};

enum __declspec(uuid("be39f3d2-1b13-11d0-887f-00a0c90f2744"))
vbext_VBAMode
{
    vbext_vm_Run = 0,
    vbext_vm_Break = 1,
    vbext_vm_Design = 2
};

struct __declspec(uuid("0002e169-0000-0000-c000-000000000046"))
VBProject;
    // [ default ] interface _VBProject

struct __declspec(uuid("0002e167-0000-0000-c000-000000000046"))
Events : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_ReferencesEvents (
        /*[in]*/ struct _VBProject * VBProject,
        /*[out,retval]*/ struct _ReferencesEvents * * prceNew ) = 0;
      virtual HRESULT __stdcall get_CommandBarEvents (
        /*[in]*/ IDispatch * CommandBarControl,
        /*[out,retval]*/ struct _CommandBarControlEvents * * prceNew ) = 0;
};

struct __declspec(uuid("0002e101-0000-0000-c000-000000000046"))
VBProjects;
    // [ default ] interface _VBProjects

enum __declspec(uuid("be39f3d5-1b13-11d0-887f-00a0c90f2744"))
vbext_ComponentType
{
    vbext_ct_StdModule = 1,
    vbext_ct_ClassModule = 2,
    vbext_ct_MSForm = 3,
    vbext_ct_ActiveXDesigner = 11,
    vbext_ct_Document = 100
};

struct __declspec(uuid("be39f3d6-1b13-11d0-887f-00a0c90f2744"))
Components;
    // [ default ] interface _Components

struct __declspec(uuid("be39f3d7-1b13-11d0-887f-00a0c90f2744"))
VBComponents;
    // [ default ] interface _VBComponents

struct __declspec(uuid("0002e163-0000-0000-c000-000000000046"))
_Component : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct Application * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _Components * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_IsDirty (
        /*[out,retval]*/ VARIANT_BOOL * lpfReturn ) = 0;
      virtual HRESULT __stdcall put_IsDirty (
        /*[in]*/ VARIANT_BOOL lpfReturn ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrReturn ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrReturn ) = 0;
};

struct __declspec(uuid("be39f3d8-1b13-11d0-887f-00a0c90f2744"))
Component;
    // [ default ] interface _Component

struct __declspec(uuid("be39f3d4-1b13-11d0-887f-00a0c90f2744"))
SelectedComponents : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ int index,
        /*[out,retval]*/ struct _Component * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct Application * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _VBProject * * lppptReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
};

struct __declspec(uuid("be39f3da-1b13-11d0-887f-00a0c90f2744"))
VBComponent;
    // [ default ] interface _VBComponent

//struct __declspec(uuid("0002e18b-0000-0000-c000-000000000046"))
//Properties;
//    // [ default ] interface _Properties

struct __declspec(uuid("da936b63-ac8b-11d1-b6e5-00a0c90f2744"))
Addins;
    // [ default ] interface _AddIns

enum vbext_ProcKind
{
    vbext_pk_Proc = 0,
    vbext_pk_Let = 1,
    vbext_pk_Set = 2,
    vbext_pk_Get = 3
};

struct __declspec(uuid("0002e170-0000-0000-c000-000000000046"))
CodeModule;
    // [ default ] interface _CodeModule

struct __declspec(uuid("0002e174-0000-0000-c000-000000000046"))
CodePanes;
    // [ default ] interface _CodePanes

enum vbext_CodePaneview
{
    vbext_cv_ProcedureView = 0,
    vbext_cv_FullModuleView = 1
};

struct __declspec(uuid("0002e178-0000-0000-c000-000000000046"))
CodePane;
    // [ default ] interface _CodePane

enum vbext_RefKind
{
    vbext_rk_TypeLib = 0,
    vbext_rk_Project = 1
};

struct __declspec(uuid("cdde3804-2064-11cf-867f-00aa005ff34a"))
_dispReferences_Events : IDispatch
{};

struct __declspec(uuid("0002e17c-0000-0000-c000-000000000046"))
References;
    // [ default ] interface _References
    // [ default, source ] dispinterface _dispReferences_Events

struct __declspec(uuid("0002e166-0000-0000-c000-000000000046"))
VBE : Application
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VBProjects (
        /*[out,retval]*/ struct _VBProjects * * lppptReturn ) = 0;
      virtual HRESULT __stdcall get_CommandBars (
        /*[out,retval]*/ struct Office::_CommandBars * * ppcbs ) = 0;
      virtual HRESULT __stdcall get_CodePanes (
        /*[out,retval]*/ struct _CodePanes * * ppCodePanes ) = 0;
      virtual HRESULT __stdcall get_Windows (
        /*[out,retval]*/ struct _Windows * * ppwnsVBWindows ) = 0;
      virtual HRESULT __stdcall get_Events (
        /*[out,retval]*/ struct Events * * ppevtEvents ) = 0;
      virtual HRESULT __stdcall get_ActiveVBProject (
        /*[out,retval]*/ struct _VBProject * * lppptReturn ) = 0;
      virtual HRESULT __stdcall putref_ActiveVBProject (
        /*[in]*/ struct _VBProject * lppptReturn ) = 0;
      virtual HRESULT __stdcall get_SelectedVBComponent (
        /*[out,retval]*/ struct _VBComponent * * lppscReturn ) = 0;
      virtual HRESULT __stdcall get_MainWindow (
        /*[out,retval]*/ struct Window * * ppwin ) = 0;
      virtual HRESULT __stdcall get_ActiveWindow (
        /*[out,retval]*/ struct Window * * ppwinActive ) = 0;
      virtual HRESULT __stdcall get_ActiveCodePane (
        /*[out,retval]*/ struct _CodePane * * ppCodePane ) = 0;
      virtual HRESULT __stdcall putref_ActiveCodePane (
        /*[in]*/ struct _CodePane * ppCodePane ) = 0;
      virtual HRESULT __stdcall get_Addins (
        /*[out,retval]*/ struct _AddIns * * lpppAddIns ) = 0;
};

struct __declspec(uuid("0002e16b-0000-0000-c000-000000000046"))
Window : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _Windows * * lppaReturn ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall get_Caption (
        /*[out,retval]*/ BSTR * pbstrTitle ) = 0;
      virtual HRESULT __stdcall get_Visible (
        /*[out,retval]*/ VARIANT_BOOL * pfVisible ) = 0;
      virtual HRESULT __stdcall put_Visible (
        /*[in]*/ VARIANT_BOOL pfVisible ) = 0;
      virtual HRESULT __stdcall get_Left (
        /*[out,retval]*/ long * plLeft ) = 0;
      virtual HRESULT __stdcall put_Left (
        /*[in]*/ long plLeft ) = 0;
      virtual HRESULT __stdcall get_Top (
        /*[out,retval]*/ long * plTop ) = 0;
      virtual HRESULT __stdcall put_Top (
        /*[in]*/ long plTop ) = 0;
      virtual HRESULT __stdcall get_Width (
        /*[out,retval]*/ long * plWidth ) = 0;
      virtual HRESULT __stdcall put_Width (
        /*[in]*/ long plWidth ) = 0;
      virtual HRESULT __stdcall get_Height (
        /*[out,retval]*/ long * plHeight ) = 0;
      virtual HRESULT __stdcall put_Height (
        /*[in]*/ long plHeight ) = 0;
      virtual HRESULT __stdcall get_WindowState (
        /*[out,retval]*/ enum vbext_WindowState * plWindowState ) = 0;
      virtual HRESULT __stdcall put_WindowState (
        /*[in]*/ enum vbext_WindowState plWindowState ) = 0;
      virtual HRESULT __stdcall SetFocus ( ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum vbext_WindowType * pKind ) = 0;
      virtual HRESULT __stdcall SetKind (
        /*[in]*/ enum vbext_WindowType eKind ) = 0;
      virtual HRESULT __stdcall get_LinkedWindows (
        /*[out,retval]*/ struct _LinkedWindows * * ppwnsCollection ) = 0;
      virtual HRESULT __stdcall get_LinkedWindowFrame (
        /*[out,retval]*/ struct Window * * ppwinFrame ) = 0;
      virtual HRESULT __stdcall Detach ( ) = 0;
      virtual HRESULT __stdcall Attach (
        /*[in]*/ long lWindowHandle ) = 0;
      virtual HRESULT __stdcall get_HWnd (
        /*[out,retval]*/ long * plWindowHandle ) = 0;
};

struct __declspec(uuid("0002e16a-0000-0000-c000-000000000046"))
_Windows_old : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Application * * lppptReturn ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct Window * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
};

struct __declspec(uuid("0002e16c-0000-0000-c000-000000000046"))
_LinkedWindows : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct Window * * ppptReturn ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct Window * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ struct Window * Window ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ struct Window * Window ) = 0;
};

struct __declspec(uuid("0002e160-0000-0000-c000-000000000046"))
_VBProject_Old : _ProjectTemplate
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_HelpFile (
        /*[out,retval]*/ BSTR * lpbstrHelpFile ) = 0;
      virtual HRESULT __stdcall put_HelpFile (
        /*[in]*/ BSTR lpbstrHelpFile ) = 0;
      virtual HRESULT __stdcall get_HelpContextID (
        /*[out,retval]*/ long * lpdwContextID ) = 0;
      virtual HRESULT __stdcall put_HelpContextID (
        /*[in]*/ long lpdwContextID ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * lpbstrDescription ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR lpbstrDescription ) = 0;
      virtual HRESULT __stdcall get_Mode (
        /*[out,retval]*/ enum vbext_VBAMode * lpVbaMode ) = 0;
      virtual HRESULT __stdcall get_References (
        /*[out,retval]*/ struct _References * * lppReferences ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * lpbstrName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR lpbstrName ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _VBProjects * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Protection (
        /*[out,retval]*/ enum vbext_ProjectProtection * lpProtection ) = 0;
      virtual HRESULT __stdcall get_Saved (
        /*[out,retval]*/ VARIANT_BOOL * lpfReturn ) = 0;
      virtual HRESULT __stdcall get_VBComponents (
        /*[out,retval]*/ struct _VBComponents * * lppcReturn ) = 0;
};

struct __declspec(uuid("eee00915-e393-11d1-bb03-00c04fb6c4a6"))
_VBProject : _VBProject_Old
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall SaveAs (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall MakeCompiledFile ( ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum vbext_ProjectType * lpkind ) = 0;
      virtual HRESULT __stdcall get_FileName (
        /*[out,retval]*/ BSTR * lpbstrReturn ) = 0;
      virtual HRESULT __stdcall get_BuildFileName (
        /*[out,retval]*/ BSTR * lpbstrBldFName ) = 0;
      virtual HRESULT __stdcall put_BuildFileName (
        /*[in]*/ BSTR lpbstrBldFName ) = 0;
};

struct __declspec(uuid("0002e165-0000-0000-c000-000000000046"))
_VBProjects_Old : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct _VBProject * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
};

struct __declspec(uuid("eee00919-e393-11d1-bb03-00c04fb6c4a6"))
_VBProjects : _VBProjects_Old
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Add (
        /*[in]*/ enum vbext_ProjectType Type,
        /*[out,retval]*/ struct _VBProject * * lppcReturn ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ struct _VBProject * lpc ) = 0;
      virtual HRESULT __stdcall Open (
        /*[in]*/ BSTR bstrPath,
        /*[out,retval]*/ struct _VBProject * * lpc ) = 0;
};

struct __declspec(uuid("0002e161-0000-0000-c000-000000000046"))
_Components : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct _Component * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct Application * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _VBProject * * lppptReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ struct _Component * Component ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum vbext_ComponentType ComponentType,
        /*[out,retval]*/ struct _Component * * lppComponent ) = 0;
      virtual HRESULT __stdcall Import (
        /*[in]*/ BSTR FileName,
        /*[out,retval]*/ struct _Component * * lppComponent ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
};

struct __declspec(uuid("0002e162-0000-0000-c000-000000000046"))
_VBComponents_Old : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct _VBComponent * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _VBProject * * lppptReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ struct _VBComponent * VBComponent ) = 0;
      virtual HRESULT __stdcall Add (
        /*[in]*/ enum vbext_ComponentType ComponentType,
        /*[out,retval]*/ struct _VBComponent * * lppComponent ) = 0;
      virtual HRESULT __stdcall Import (
        /*[in]*/ BSTR FileName,
        /*[out,retval]*/ struct _VBComponent * * lppComponent ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
};

struct __declspec(uuid("eee0091c-e393-11d1-bb03-00c04fb6c4a6"))
_VBComponents : _VBComponents_Old
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall AddCustom (
        /*[in]*/ BSTR ProgId,
        /*[out,retval]*/ struct _VBComponent * * lppComponent ) = 0;
      virtual HRESULT __stdcall AddMTDesigner (
        /*[in]*/ long index,
        /*[out,retval]*/ struct _VBComponent * * lppComponent ) = 0;
};

struct __declspec(uuid("0002e164-0000-0000-c000-000000000046"))
_VBComponent_Old : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Saved (
        /*[out,retval]*/ VARIANT_BOOL * lpfReturn ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrReturn ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrReturn ) = 0;
      virtual HRESULT __stdcall get_Designer (
        /*[out,retval]*/ IDispatch * * ppDispatch ) = 0;
      virtual HRESULT __stdcall get_CodeModule (
        /*[out,retval]*/ struct _CodeModule * * ppVbaModule ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum vbext_ComponentType * pKind ) = 0;
      virtual HRESULT __stdcall Export (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _VBComponents * * lppcReturn ) = 0;
      virtual HRESULT __stdcall get_HasOpenDesigner (
        /*[out,retval]*/ VARIANT_BOOL * lpfReturn ) = 0;
      virtual HRESULT __stdcall get_Properties (
        /*[out,retval]*/ struct _Properties * * lpppReturn ) = 0;
      virtual HRESULT __stdcall DesignerWindow (
        /*[out,retval]*/ struct Window * * lppcReturn ) = 0;
      virtual HRESULT __stdcall Activate ( ) = 0;
};

struct __declspec(uuid("eee00921-e393-11d1-bb03-00c04fb6c4a6"))
_VBComponent : _VBComponent_Old
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_DesignerID (
        /*[out,retval]*/ BSTR * pbstrReturn ) = 0;
};

struct __declspec(uuid("0002e18c-0000-0000-c000-000000000046"))
Property : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Value (
        /*[out,retval]*/ VARIANT * lppvReturn ) = 0;
      virtual HRESULT __stdcall put_Value (
        /*[in]*/ VARIANT lppvReturn ) = 0;
      virtual HRESULT __stdcall get_IndexedValue (
        /*[in]*/ VARIANT Index1,
        /*[in]*/ VARIANT Index2,
        /*[in]*/ VARIANT Index3,
        /*[in]*/ VARIANT Index4,
        /*[out,retval]*/ VARIANT * lppvReturn ) = 0;
      virtual HRESULT __stdcall put_IndexedValue (
        /*[in]*/ VARIANT Index1,
        /*[in]*/ VARIANT Index2,
        /*[in]*/ VARIANT Index3 = vtMissing,
        /*[in]*/ VARIANT Index4 = vtMissing,
        /*[in]*/ VARIANT lppvReturn = vtMissing ) = 0;
      virtual HRESULT __stdcall get_NumIndices (
        /*[out,retval]*/ short * lpiRetVal ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct Application * * lpaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _Properties * * lpppReturn ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * lpbstrReturn ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lpaReturn ) = 0;
      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _Properties * * lpppReturn ) = 0;
      virtual HRESULT __stdcall get_Object (
        /*[out,retval]*/ IUnknown * * lppunk ) = 0;
      virtual HRESULT __stdcall putref_Object (
        /*[in]*/ IUnknown * lppunk ) = 0;
};

struct __declspec(uuid("0002e188-0000-0000-c000-000000000046"))
_Properties : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct Property * * lplppReturn ) = 0;
      virtual HRESULT __stdcall get_Application (
        /*[out,retval]*/ struct Application * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * lppidReturn ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
};

struct __declspec(uuid("da936b64-ac8b-11d1-b6e5-00a0c90f2744"))
AddIn : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * lpbstr ) = 0;
      virtual HRESULT __stdcall put_Description (
        /*[in]*/ BSTR lpbstr ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppVBE ) = 0;
      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _AddIns * * lppaddins ) = 0;
      virtual HRESULT __stdcall get_ProgId (
        /*[out,retval]*/ BSTR * lpbstr ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * lpbstr ) = 0;
      virtual HRESULT __stdcall get_Connect (
        /*[out,retval]*/ VARIANT_BOOL * lpfConnect ) = 0;
      virtual HRESULT __stdcall put_Connect (
        /*[in]*/ VARIANT_BOOL lpfConnect ) = 0;
      virtual HRESULT __stdcall get_Object (
        /*[out,retval]*/ IDispatch * * lppdisp ) = 0;
      virtual HRESULT __stdcall put_Object (
        /*[in]*/ IDispatch * lppdisp ) = 0;
};

struct __declspec(uuid("f57b7ed0-d8ab-11d1-85df-00c04f98f42c"))
_Windows : _Windows_old
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall CreateToolWindow (
        /*[in]*/ struct AddIn * AddInInst,
        /*[in]*/ BSTR ProgId,
        /*[in]*/ BSTR Caption,
        /*[in]*/ BSTR GuidPosition,
        /*[in,out]*/ IDispatch * * DocObj,
        /*[out,retval]*/ struct Window * * lppcReturn ) = 0;
};

struct __declspec(uuid("da936b62-ac8b-11d1-b6e5-00a0c90f2744"))
_AddIns : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct AddIn * * lppaddin ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppVBA ) = 0;
      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ IDispatch * * lppVBA ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * lplReturn ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * lppiuReturn ) = 0;
      virtual HRESULT __stdcall Update ( ) = 0;
};

struct __declspec(uuid("0002e16e-0000-0000-c000-000000000046"))
_CodeModule : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _VBComponent * * retval ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * retval ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pbstrName ) = 0;
      virtual HRESULT __stdcall AddFromString (
        /*[in]*/ BSTR String ) = 0;
      virtual HRESULT __stdcall AddFromFile (
        /*[in]*/ BSTR FileName ) = 0;
      virtual HRESULT __stdcall get_Lines (
        /*[in]*/ long StartLine,
        /*[in]*/ long Count,
        /*[out,retval]*/ BSTR * String ) = 0;
      virtual HRESULT __stdcall get_CountOfLines (
        /*[out,retval]*/ long * CountOfLines ) = 0;
      virtual HRESULT __stdcall InsertLines (
        /*[in]*/ long Line,
        /*[in]*/ BSTR String ) = 0;
      virtual HRESULT __stdcall DeleteLines (
        /*[in]*/ long StartLine,
        /*[in]*/ long Count ) = 0;
      virtual HRESULT __stdcall ReplaceLine (
        /*[in]*/ long Line,
        /*[in]*/ BSTR String ) = 0;
      virtual HRESULT __stdcall get_ProcStartLine (
        /*[in]*/ BSTR ProcName,
        /*[in]*/ enum vbext_ProcKind ProcKind,
        /*[out,retval]*/ long * ProcStartLine ) = 0;
      virtual HRESULT __stdcall get_ProcCountLines (
        /*[in]*/ BSTR ProcName,
        /*[in]*/ enum vbext_ProcKind ProcKind,
        /*[out,retval]*/ long * ProcCountLines ) = 0;
      virtual HRESULT __stdcall get_ProcBodyLine (
        /*[in]*/ BSTR ProcName,
        /*[in]*/ enum vbext_ProcKind ProcKind,
        /*[out,retval]*/ long * ProcBodyLine ) = 0;
      virtual HRESULT __stdcall get_ProcOfLine (
        /*[in]*/ long Line,
        /*[out]*/ enum vbext_ProcKind * ProcKind,
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_CountOfDeclarationLines (
        /*[out,retval]*/ long * pDeclCountOfLines ) = 0;
      virtual HRESULT __stdcall CreateEventProc (
        /*[in]*/ BSTR EventName,
        /*[in]*/ BSTR ObjectName,
        /*[out,retval]*/ long * Line ) = 0;
      virtual HRESULT __stdcall Find (
        /*[in]*/ BSTR Target,
        /*[in,out]*/ long * StartLine,
        /*[in,out]*/ long * StartColumn,
        /*[in,out]*/ long * EndLine,
        /*[in,out]*/ long * EndColumn,
        /*[in]*/ VARIANT_BOOL WholeWord,
        /*[in]*/ VARIANT_BOOL MatchCase,
        /*[in]*/ VARIANT_BOOL PatternSearch,
        /*[out,retval]*/ VARIANT_BOOL * pfFound ) = 0;
      virtual HRESULT __stdcall get_CodePane (
        /*[out,retval]*/ struct _CodePane * * CodePane ) = 0;
};

struct __declspec(uuid("0002e172-0000-0000-c000-000000000046"))
_CodePanes : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct VBE * * retval ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * retval ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct _CodePane * * CodePane ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * ppenum ) = 0;
      virtual HRESULT __stdcall get_Current (
        /*[out,retval]*/ struct _CodePane * * CodePane ) = 0;
      virtual HRESULT __stdcall put_Current (
        /*[in]*/ struct _CodePane * CodePane ) = 0;
};

struct __declspec(uuid("0002e176-0000-0000-c000-000000000046"))
_CodePane : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _CodePanes * * retval ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * retval ) = 0;
      virtual HRESULT __stdcall get_Window (
        /*[out,retval]*/ struct Window * * retval ) = 0;
      virtual HRESULT __stdcall GetSelection (
        /*[out]*/ long * StartLine,
        /*[out]*/ long * StartColumn,
        /*[out]*/ long * EndLine,
        /*[out]*/ long * EndColumn ) = 0;
      virtual HRESULT __stdcall SetSelection (
        /*[in]*/ long StartLine,
        /*[in]*/ long StartColumn,
        /*[in]*/ long EndLine,
        /*[in]*/ long EndColumn ) = 0;
      virtual HRESULT __stdcall get_TopLine (
        /*[out,retval]*/ long * TopLine ) = 0;
      virtual HRESULT __stdcall put_TopLine (
        /*[in]*/ long TopLine ) = 0;
      virtual HRESULT __stdcall get_CountOfVisibleLines (
        /*[out,retval]*/ long * CountOfVisibleLines ) = 0;
      virtual HRESULT __stdcall get_CodeModule (
        /*[out,retval]*/ struct _CodeModule * * CodeModule ) = 0;
      virtual HRESULT __stdcall Show ( ) = 0;
      virtual HRESULT __stdcall get_CodePaneView (
        /*[out,retval]*/ enum vbext_CodePaneview * pCodePaneview ) = 0;
};

struct __declspec(uuid("0002e17e-0000-0000-c000-000000000046"))
Reference : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Collection (
        /*[out,retval]*/ struct _References * * retval ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * lppaReturn ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
      virtual HRESULT __stdcall get_Guid (
        /*[out,retval]*/ BSTR * pbstrGuid ) = 0;
      virtual HRESULT __stdcall get_Major (
        /*[out,retval]*/ long * pMajor ) = 0;
      virtual HRESULT __stdcall get_Minor (
        /*[out,retval]*/ long * pMinor ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * pbstrLocation ) = 0;
      virtual HRESULT __stdcall get_BuiltIn (
        /*[out,retval]*/ VARIANT_BOOL * pfIsDefault ) = 0;
      virtual HRESULT __stdcall get_IsBroken (
        /*[out,retval]*/ VARIANT_BOOL * pfIsBroken ) = 0;
      virtual HRESULT __stdcall get_Type (
        /*[out,retval]*/ enum vbext_RefKind * pKind ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pbstrName ) = 0;
};

struct __declspec(uuid("0002e17a-0000-0000-c000-000000000046"))
_References : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Parent (
        /*[out,retval]*/ struct _VBProject * * retval ) = 0;
      virtual HRESULT __stdcall get_VBE (
        /*[out,retval]*/ struct VBE * * retval ) = 0;
      virtual HRESULT __stdcall Item (
        /*[in]*/ VARIANT index,
        /*[out,retval]*/ struct Reference * * Reference ) = 0;
      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * Count ) = 0;
      virtual HRESULT __stdcall _NewEnum (
        /*[out,retval]*/ IUnknown * * ppenum ) = 0;
      virtual HRESULT __stdcall AddFromGuid (
        /*[in]*/ BSTR Guid,
        /*[in]*/ long Major,
        /*[in]*/ long Minor,
        /*[out,retval]*/ struct Reference * * Reference ) = 0;
      virtual HRESULT __stdcall AddFromFile (
        /*[in]*/ BSTR FileName,
        /*[out,retval]*/ struct Reference * * Reference ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ struct Reference * Reference ) = 0;
};

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_VBIDE =
    {0x0002e157,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Application =
    {0x0002e158,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_Windows =
    {0x0002e185,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_LinkedWindows =
    {0x0002e187,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBProjectsEvents =
    {0x0002e113,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__dispVBProjectsEvents =
    {0x0002e103,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBComponentsEvents =
    {0x0002e115,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__dispVBComponentsEvents =
    {0x0002e116,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__ReferencesEvents =
    {0x0002e11a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__dispReferencesEvents =
    {0x0002e118,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_ReferencesEvents =
    {0x0002e119,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CommandBarControlEvents =
    {0x0002e130,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__dispCommandBarControlEvents =
    {0x0002e131,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CommandBarEvents =
    {0x0002e132,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__ProjectTemplate =
    {0x0002e159,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_ProjectTemplate =
    {0x32cdf9e0,0x1602,0x11ce,{0xbf,0xdc,0x08,0x00,0x2b,0x2b,0x8c,0xda}};
extern "C" const GUID __declspec(selectany) CLSID_VBProject =
    {0x0002e169,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Events =
    {0x0002e167,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_VBProjects =
    {0x0002e101,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_Components =
    {0xbe39f3d6,0x1b13,0x11d0,{0x88,0x7f,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_VBComponents =
    {0xbe39f3d7,0x1b13,0x11d0,{0x88,0x7f,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) IID__Component =
    {0x0002e163,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_Component =
    {0xbe39f3d8,0x1b13,0x11d0,{0x88,0x7f,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) IID_SelectedComponents =
    {0xbe39f3d4,0x1b13,0x11d0,{0x88,0x7f,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_VBComponent =
    {0xbe39f3da,0x1b13,0x11d0,{0x88,0x7f,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_Properties =
    {0x0002e18b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_Addins =
    {0xda936b63,0xac8b,0x11d1,{0xb6,0xe5,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) CLSID_CodeModule =
    {0x0002e170,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CodePanes =
    {0x0002e174,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) CLSID_CodePane =
    {0x0002e178,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) DIID__dispReferences_Events =
    {0xcdde3804,0x2064,0x11cf,{0x86,0x7f,0x00,0xaa,0x00,0x5f,0xf3,0x4a}};
extern "C" const GUID __declspec(selectany) CLSID_References =
    {0x0002e17c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_VBE =
    {0x0002e166,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Window =
    {0x0002e16b,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__Windows_old =
    {0x0002e16a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__LinkedWindows =
    {0x0002e16c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBProject_Old =
    {0x0002e160,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBProject =
    {0xeee00915,0xe393,0x11d1,{0xbb,0x03,0x00,0xc0,0x4f,0xb6,0xc4,0xa6}};
extern "C" const GUID __declspec(selectany) IID__VBProjects_Old =
    {0x0002e165,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBProjects =
    {0xeee00919,0xe393,0x11d1,{0xbb,0x03,0x00,0xc0,0x4f,0xb6,0xc4,0xa6}};
extern "C" const GUID __declspec(selectany) IID__Components =
    {0x0002e161,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBComponents_Old =
    {0x0002e162,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBComponents =
    {0xeee0091c,0xe393,0x11d1,{0xbb,0x03,0x00,0xc0,0x4f,0xb6,0xc4,0xa6}};
extern "C" const GUID __declspec(selectany) IID__VBComponent_Old =
    {0x0002e164,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__VBComponent =
    {0xeee00921,0xe393,0x11d1,{0xbb,0x03,0x00,0xc0,0x4f,0xb6,0xc4,0xa6}};
extern "C" const GUID __declspec(selectany) IID_Property =
    {0x0002e18c,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__Properties =
    {0x0002e188,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_AddIn =
    {0xda936b64,0xac8b,0x11d1,{0xb6,0xe5,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) IID__Windows =
    {0xf57b7ed0,0xd8ab,0x11d1,{0x85,0xdf,0x00,0xc0,0x4f,0x98,0xf4,0x2c}};
extern "C" const GUID __declspec(selectany) IID__AddIns =
    {0xda936b62,0xac8b,0x11d1,{0xb6,0xe5,0x00,0xa0,0xc9,0x0f,0x27,0x44}};
extern "C" const GUID __declspec(selectany) IID__CodeModule =
    {0x0002e16e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CodePanes =
    {0x0002e172,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__CodePane =
    {0x0002e176,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID_Reference =
    {0x0002e17e,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
extern "C" const GUID __declspec(selectany) IID__References =
    {0x0002e17a,0x0000,0x0000,{0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

} // namespace VBIDE

#pragma pack(pop)
