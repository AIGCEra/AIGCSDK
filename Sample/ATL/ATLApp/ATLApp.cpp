// ATLApp.cpp : Implementation of WinMain


#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ATLApp_i.h"


using namespace ATL;

class CATLAppModule : public CAIGCModuleT< CATLAppModule >
{
public:
	DECLARE_LIBID(LIBID_ATLAppLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLAPP, "{5a319c27-7415-4304-80ee-4bce0f6759da}")

	//IUniverseAppProxy
	virtual void OnCustomizedMainWindowElement(HWND hMainWnd, CString strXml)
	{
	}
};

CATLAppModule _AtlModule;

//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
	LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

