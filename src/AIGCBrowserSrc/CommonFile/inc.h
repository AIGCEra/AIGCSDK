#pragma once

#define DECLARE_DYNCREATE_ATL(class_name) \
	DECLARE_DYNCREATE(class_name) 


#define IMPLEMENT_DYNCREATE_ATL(class_name, base_class_name) \
	CObject* PASCAL class_name::CreateObject() \
		{ CComObject<class_name>* pObj = NULL; \
		pObj = new CComObject<class_name>; \
		pObj->InternalAddRef(); \
		return pObj; } \
		IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, 0xFFFF, \
		class_name::CreateObject,NULL)

#define DECLARE_SERIAL_ATL(class_name) \
	_DECLARE_DYNAMIC(class_name) \
	static CObject* PASCAL CreateObject();\
	AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb);

#define IMPLEMENT_SERIAL_ATL(class_name, base_class_name, wSchema) \
	CObject* PASCAL class_name::CreateObject() \
		{ CComObject<class_name>* pObj = NULL; \
		HRESULT hr = CComObject<class_name>::CreateInstance(&pObj); \
		if (FAILED(hr)) { AfxThrowOleException(hr); } \
		pObj->InternalAddRef(); \
		return pObj; } \
		_IMPLEMENT_RUNTIMECLASS(class_name, base_class_name, wSchema, \
		class_name::CreateObject) \
		AFX_CLASSINIT _init_##class_name(RUNTIME_CLASS(class_name)); \
		CArchive& AFXAPI operator>>(CArchive& ar, class_name* &pOb) \
		{ pOb = (class_name*) ar.ReadObject(RUNTIME_CLASS(class_name)); \
		return ar; } 


#define m_dwRef					m_dwRefAtl
#define m_pOuterUnknown			m_pOuterUnknownAtl
#define InternalQueryInterface	InternalQueryInterfaceAtl
#define InternalAddRef			InternalAddRefAtl
#define InternalRelease			InternalReleaseAtl
