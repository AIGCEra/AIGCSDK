// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1 (6367f6a8).
//
// c:\users\孙辉\documents\visual studio 2017\projects\atlproject2\atlproject2\debug\vcprj2.tlh
//
// C++ source equivalent of Win32 type library E:\tangram\vcprj2.tlb
// compiler-generated file created 08/30/17 at 21:45:03 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

namespace VCPrivateProjectLibrary {

//
// Forward references and typedefs
//

struct __declspec(uuid("d1094a72-6fa9-4610-b414-ca728d5821f0"))
/* LIBID */ __VCPrivateProjectLibrary;
struct __declspec(uuid("a24dfe34-6f54-4ceb-90e3-ae1e5b65603c"))
/* dual interface */ VCFolder;
struct __declspec(uuid("f2989b37-2228-42ec-8c18-a9dcbca260da"))
/* dual interface */ _VCPlaceHolder;
struct __declspec(uuid("73029e1d-7e8b-468a-a946-f3011b86bce1"))
/* dual interface */ VCPropertyManager;
struct __declspec(uuid("363bffed-cb60-4216-9ee1-2d8990f79177"))
/* dual interface */ VCPropertyManagerToolWindow;
struct __declspec(uuid("289f2fe4-0b73-4851-9434-8bee393582dd"))
/* dual interface */ VCPropertyManagerConfiguration;
struct __declspec(uuid("79a03c6f-704e-4ee1-85a1-f67df4784dcb"))
/* dual interface */ VCPropertyManagerPropertySheet;
struct /* coclass */ FileNodeProps;
struct __declspec(uuid("2d5d650e-3e0d-11d3-9415-00c04f68fb62"))
/* dual interface */ File;
enum eFileType;
struct /* coclass */ FolderNodeProps;
struct __declspec(uuid("2111b8b8-4150-11d3-9416-00c04f68fb62"))
/* dual interface */ Filter;
struct /* coclass */ ProjectNodeProps;
struct __declspec(uuid("2111b8ba-4150-11d3-9416-00c04f68fb62"))
/* dual interface */ _VCProject;
struct /* coclass */ BuildPackage;
struct /* coclass */ VCPropertyManagerPackage;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(VCFolder, __uuidof(VCFolder));
_COM_SMARTPTR_TYPEDEF(_VCPlaceHolder, __uuidof(_VCPlaceHolder));
_COM_SMARTPTR_TYPEDEF(VCPropertyManagerToolWindow, __uuidof(VCPropertyManagerToolWindow));
_COM_SMARTPTR_TYPEDEF(VCPropertyManager, __uuidof(VCPropertyManager));
_COM_SMARTPTR_TYPEDEF(VCPropertyManagerConfiguration, __uuidof(VCPropertyManagerConfiguration));
_COM_SMARTPTR_TYPEDEF(VCPropertyManagerPropertySheet, __uuidof(VCPropertyManagerPropertySheet));
_COM_SMARTPTR_TYPEDEF(File, __uuidof(File));
_COM_SMARTPTR_TYPEDEF(Filter, __uuidof(Filter));
_COM_SMARTPTR_TYPEDEF(_VCProject, __uuidof(_VCProject));

//
// Type library items
//

struct __declspec(uuid("a24dfe34-6f54-4ceb-90e3-ae1e5b65603c"))
VCFolder : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * ppVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR ppVal ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * ppVal ) = 0;
};

struct __declspec(uuid("f2989b37-2228-42ec-8c18-a9dcbca260da"))
_VCPlaceHolder : IDispatch
{};

struct __declspec(uuid("363bffed-cb60-4216-9ee1-2d8990f79177"))
VCPropertyManagerToolWindow : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Show ( ) = 0;
      virtual HRESULT __stdcall Hide ( ) = 0;
      virtual HRESULT __stdcall RefreshItem (
        /*[in]*/ IDispatch * pItem ) = 0;
};

struct __declspec(uuid("73029e1d-7e8b-468a-a946-f3011b86bce1"))
VCPropertyManager : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VCPropertyManagerToolWindow (
        /*[out,retval]*/ struct VCPropertyManagerToolWindow * * ToolWindow ) = 0;
};

struct __declspec(uuid("289f2fe4-0b73-4851-9434-8bee393582dd"))
VCPropertyManagerConfiguration : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VCConfiguration (
        /*[out,retval]*/ IDispatch * * ppConfig ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_PlatformName (
        /*[out,retval]*/ BSTR * Platform ) = 0;
};

struct __declspec(uuid("79a03c6f-704e-4ee1-85a1-f67df4784dcb"))
VCPropertyManagerPropertySheet : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_VCPropertySheet (
        /*[out,retval]*/ IDispatch * * ppPropertySheet ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * Name ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall get_PropertySheetFile (
        /*[out,retval]*/ BSTR * File ) = 0;
};

struct __declspec(uuid("2d5d650f-3e0d-11d3-9415-00c04f68fb62"))
FileNodeProps;
    // [ default ] interface File

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

struct __declspec(uuid("2d5d650e-3e0d-11d3-9415-00c04f68fb62"))
File : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_FullPath (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_RelativePath (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_RelativePath (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_DeploymentContent (
        /*[out,retval]*/ VARIANT_BOOL * pVal ) = 0;
      virtual HRESULT __stdcall put_DeploymentContent (
        /*[in]*/ VARIANT_BOOL pVal ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ IDispatch * * ppDisp ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * pvarNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pbstrGuid ) = 0;
      virtual HRESULT __stdcall get_FileType (
        /*[out,retval]*/ enum eFileType * pType ) = 0;
      virtual HRESULT __stdcall put_FileType (
        /*[in]*/ enum eFileType pType ) = 0;
      virtual HRESULT __stdcall get_IncludedInProject (
        /*[out,retval]*/ VARIANT_BOOL * pbIncludedInProject ) = 0;
      virtual HRESULT __stdcall put_IncludedInProject (
        /*[in]*/ VARIANT_BOOL pbIncludedInProject ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pVal ) = 0;
};

struct __declspec(uuid("2111b8b9-4150-11d3-9416-00c04f68fb62"))
FolderNodeProps;
    // [ default ] interface Filter

struct __declspec(uuid("2111b8b8-4150-11d3-9416-00c04f68fb62"))
Filter : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_Filter (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Filter (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ParseFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbParse ) = 0;
      virtual HRESULT __stdcall put_ParseFiles (
        /*[in]*/ VARIANT_BOOL pbParse ) = 0;
      virtual HRESULT __stdcall get_SourceControlFiles (
        /*[out,retval]*/ VARIANT_BOOL * pbSCC ) = 0;
      virtual HRESULT __stdcall put_SourceControlFiles (
        /*[in]*/ VARIANT_BOOL pbSCC ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ IDispatch * * ppDisp ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * pvarNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pbstrGuid ) = 0;
      virtual HRESULT __stdcall get_UniqueIdentifier (
        /*[out,retval]*/ BSTR * Val ) = 0;
      virtual HRESULT __stdcall put_UniqueIdentifier (
        /*[in]*/ BSTR Val ) = 0;
};

struct __declspec(uuid("2111b8bb-4150-11d3-9416-00c04f68fb62"))
ProjectNodeProps;
    // [ default ] interface _VCProject

struct __declspec(uuid("2111b8ba-4150-11d3-9416-00c04f68fb62"))
_VCProject : IDispatch
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pVal ) = 0;
      virtual HRESULT __stdcall get_ProjectFile (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_ProjectDependencies (
        /*[out,retval]*/ BSTR * pVal ) = 0;
      virtual HRESULT __stdcall get_Extender (
        /*[in]*/ BSTR bstrName,
        /*[out,retval]*/ IDispatch * * ppDisp ) = 0;
      virtual HRESULT __stdcall get_ExtenderNames (
        /*[out,retval]*/ VARIANT * pvarNames ) = 0;
      virtual HRESULT __stdcall get_ExtenderCATID (
        /*[out,retval]*/ BSTR * pbstrGuid ) = 0;
      virtual HRESULT __stdcall put_RootNamespace (
        /*[in]*/ BSTR RootNamespace ) = 0;
      virtual HRESULT __stdcall get_RootNamespace (
        /*[out,retval]*/ BSTR * RootNamespace ) = 0;
};

struct __declspec(uuid("f1c25864-3097-11d2-a5c5-00c04f7968b4"))
BuildPackage;
    // [ default ] interface IUnknown

struct __declspec(uuid("3a3e1789-3e35-47b0-8567-d2fb407cc63d"))
VCPropertyManagerPackage;
    // [ default ] interface VCPropertyManager

//
// Named GUID constants initializations
//

extern "C" const GUID __declspec(selectany) LIBID_VCPrivateProjectLibrary =
    {0xd1094a72,0x6fa9,0x4610,{0xb4,0x14,0xca,0x72,0x8d,0x58,0x21,0xf0}};
extern "C" const GUID __declspec(selectany) IID_VCFolder =
    {0xa24dfe34,0x6f54,0x4ceb,{0x90,0xe3,0xae,0x1e,0x5b,0x65,0x60,0x3c}};
extern "C" const GUID __declspec(selectany) IID__VCPlaceHolder =
    {0xf2989b37,0x2228,0x42ec,{0x8c,0x18,0xa9,0xdc,0xbc,0xa2,0x60,0xda}};
extern "C" const GUID __declspec(selectany) IID_VCPropertyManagerToolWindow =
    {0x363bffed,0xcb60,0x4216,{0x9e,0xe1,0x2d,0x89,0x90,0xf7,0x91,0x77}};
extern "C" const GUID __declspec(selectany) IID_VCPropertyManager =
    {0x73029e1d,0x7e8b,0x468a,{0xa9,0x46,0xf3,0x01,0x1b,0x86,0xbc,0xe1}};
extern "C" const GUID __declspec(selectany) IID_VCPropertyManagerConfiguration =
    {0x289f2fe4,0x0b73,0x4851,{0x94,0x34,0x8b,0xee,0x39,0x35,0x82,0xdd}};
extern "C" const GUID __declspec(selectany) IID_VCPropertyManagerPropertySheet =
    {0x79a03c6f,0x704e,0x4ee1,{0x85,0xa1,0xf6,0x7d,0xf4,0x78,0x4d,0xcb}};
extern "C" const GUID __declspec(selectany) CLSID_FileNodeProps =
    {0x2d5d650f,0x3e0d,0x11d3,{0x94,0x15,0x00,0xc0,0x4f,0x68,0xfb,0x62}};
extern "C" const GUID __declspec(selectany) IID_File =
    {0x2d5d650e,0x3e0d,0x11d3,{0x94,0x15,0x00,0xc0,0x4f,0x68,0xfb,0x62}};
extern "C" const GUID __declspec(selectany) CLSID_FolderNodeProps =
    {0x2111b8b9,0x4150,0x11d3,{0x94,0x16,0x00,0xc0,0x4f,0x68,0xfb,0x62}};
extern "C" const GUID __declspec(selectany) IID_Filter =
    {0x2111b8b8,0x4150,0x11d3,{0x94,0x16,0x00,0xc0,0x4f,0x68,0xfb,0x62}};
extern "C" const GUID __declspec(selectany) CLSID_ProjectNodeProps =
    {0x2111b8bb,0x4150,0x11d3,{0x94,0x16,0x00,0xc0,0x4f,0x68,0xfb,0x62}};
extern "C" const GUID __declspec(selectany) IID__VCProject =
    {0x2111b8ba,0x4150,0x11d3,{0x94,0x16,0x00,0xc0,0x4f,0x68,0xfb,0x62}};
extern "C" const GUID __declspec(selectany) CLSID_BuildPackage =
    {0xf1c25864,0x3097,0x11d2,{0xa5,0xc5,0x00,0xc0,0x4f,0x79,0x68,0xb4}};
extern "C" const GUID __declspec(selectany) CLSID_VCPropertyManagerPackage =
    {0x3a3e1789,0x3e35,0x47b0,{0x85,0x67,0xd2,0xfb,0x40,0x7c,0xc6,0x3d}};

} // namespace VCPrivateProjectLibrary

#pragma pack(pop)
