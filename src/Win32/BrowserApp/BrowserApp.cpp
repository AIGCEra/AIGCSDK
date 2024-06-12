// BrowserApp.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "BrowserApp.h"
#include "..\..\AIGCSDK\AIGC.cpp"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


class CBrowserApp :
	public CAIGCApp
{
public:
	CBrowserApp() {
		m_hMainClientWnd = NULL;
		m_strColors = _T("");

		/*
		 * Button Control Styles
		 */
		m_mapStyle[_T("BS_PUSHBUTTON")] = 0x00000000L;
		m_mapStyle[_T("BS_DEFPUSHBUTTON")] = 0x00000001L;
		m_mapStyle[_T("BS_CHECKBOX")] = 0x00000002L;
		m_mapStyle[_T("BS_AUTOCHECKBOX")] = 0x00000003L;
		m_mapStyle[_T("BS_RADIOBUTTON")] = 0x00000004L;
		m_mapStyle[_T("BS_3STATE")] = 0x00000005L;
		m_mapStyle[_T("BS_AUTO3STATE")] = 0x00000006L;
		m_mapStyle[_T("BS_GROUPBOX")] = 0x00000007L;
		m_mapStyle[_T("BS_USERBUTTON")] = 0x00000008L;
		m_mapStyle[_T("BS_AUTORADIOBUTTON")] = 0x00000009L;
		m_mapStyle[_T("BS_PUSHBOX")] = 0x0000000AL;
		m_mapStyle[_T("BS_OWNERDRAW")] = 0x0000000BL;
		m_mapStyle[_T("BS_TYPEMASK")] = 0x0000000FL;
		m_mapStyle[_T("BS_LEFTTEXT")] = 0x00000020L;
		m_mapStyle[_T("BS_TEXT")] = 0x00000000L;
		m_mapStyle[_T("BS_ICON")] = 0x00000040L;
		m_mapStyle[_T("BS_BITMAP")] = 0x00000080L;
		m_mapStyle[_T("BS_LEFT")] = 0x00000100L;
		m_mapStyle[_T("BS_RIGHT")] = 0x00000200L;
		m_mapStyle[_T("BS_CENTER")] = 0x00000300L;
		m_mapStyle[_T("BS_TOP")] = 0x00000400L;
		m_mapStyle[_T("BS_BOTTOM")] = 0x00000800L;
		m_mapStyle[_T("BS_VCENTER")] = 0x00000C00L;
		m_mapStyle[_T("BS_PUSHLIKE")] = 0x00001000L;
		m_mapStyle[_T("BS_MULTILINE")] = 0x00002000L;
		m_mapStyle[_T("BS_NOTIFY")] = 0x00004000L;
		m_mapStyle[_T("BS_FLAT")] = 0x00008000L;
		m_mapStyle[_T("BS_RIGHTBUTTON")] = BS_LEFTTEXT;

		/*
		 * Edit Control Styles
		 */
		m_mapStyle[_T("ES_LEFT")] = 0x0000L;
		m_mapStyle[_T("ES_CENTER")] = 0x0001L;
		m_mapStyle[_T("ES_RIGHT")] = 0x0002L;
		m_mapStyle[_T("ES_MULTILINE")] = 0x0004L;
		m_mapStyle[_T("ES_UPPERCASE")] = 0x0008L;
		m_mapStyle[_T("ES_LOWERCASE")] = 0x0010L;
		m_mapStyle[_T("ES_PASSWORD")] = 0x0020L;
		m_mapStyle[_T("ES_AUTOVSCROLL")] = 0x0040L;
		m_mapStyle[_T("ES_AUTOHSCROLL")] = 0x0080L;
		m_mapStyle[_T("ES_NOHIDESEL")] = 0x0100L;
		m_mapStyle[_T("ES_OEMCONVERT")] = 0x0400L;
		m_mapStyle[_T("ES_READONLY")] = 0x0800L;
		m_mapStyle[_T("ES_WANTRETURN")] = 0x1000L;
		m_mapStyle[_T("ES_NUMBER")] = 0x2000L;
	}

	HWND m_hMainClientWnd;

	void CreateControls(HWND _hWnd, CString strXml)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strXml))
		{
			HWND hWnd = _hWnd;
			CString strName = m_Parse.name();
			if (strName == _T("mainclient"))
			{
				CString strWndCls = m_Parse.attr(_T("winbkcolor"), _T("RGB(128,255,255)"));
				int nID = m_Parse.attrInt(_T("ctrlid"), 0);
				RegisterColorWindowClass(strWndCls);
				RECT rc;
				::GetClientRect(g_pSpaceTelescopeImpl->m_hMainWnd, &rc);
				m_hMainClientWnd = CreateWindowW(LPCTSTR(strWndCls), szTitle, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
					CW_USEDEFAULT, 0, rc.right, rc.bottom, g_pSpaceTelescopeImpl->m_hMainWnd, (HMENU)nID, hInst, nullptr);
				hWnd = m_hMainClientWnd;

			}
			CTangramXmlParse* xmlCtrls = m_Parse.GetChild(_T("controls"));
			if (xmlCtrls)
			{
				int nCount = xmlCtrls->GetCount();
				for (int i = 0; i < nCount; i++)
				{
					CTangramXmlParse* xmlCtrl = xmlCtrls->GetChild(i);
					CString strRect = xmlCtrl->attr(_T("client"), _T("rect(0,0,0,0)"));
					xmlCtrl = xmlCtrls->GetChild(i);
					int x = 0;
					int y = 0;
					int w = 0;
					int h = 0;
					if (!strRect.IsEmpty())
					{
						_stscanf_s(strRect, _T("rect(%d,%d,%d,%d)"), &x, &y, &w, &h);
					}
					if (w * h)
					{
						int nCtrlID = xmlCtrl->attrInt(_T("ctrlid"), 0);
						CString strText = xmlCtrl->attr(_T("text"), _T(""));
						CString strWndCls = xmlCtrl->attr(_T("type"), _T("BUTTON"));
						CString strWndStyle = xmlCtrl->attr(_T("style"), _T("BS_DEFPUSHBUTTON"));
						DWORD dwStyle = WS_TABSTOP | WS_VISIBLE | WS_CHILD;
						if (strWndStyle != _T("")) {
							int nPos = strWndStyle.Find(_T("|"));
							if (nPos == -1)
							{
								auto it = m_mapStyle.find(strWndStyle);
								if (it != m_mapStyle.end())
								{
									dwStyle |= it->second;
								}
							}
							while (nPos != -1)
							{
								CString strStyle = strWndStyle.Left(nPos);
								strWndStyle = strWndStyle.Mid(nPos + 1);
								auto it = m_mapStyle.find(strStyle);
								if (it != m_mapStyle.end())
								{
									dwStyle |= it->second;
								}
								nPos = strWndStyle.Find(_T("|"));
								if (nPos == -1) {
									auto it = m_mapStyle.find(strWndStyle);
									if (it != m_mapStyle.end())
									{
										dwStyle |= it->second;
									}
								}
							}
						}
						HWND hwndCtrl = CreateWindow(
							LPCTSTR(strWndCls),  // Predefined class by RegisterColorWindowClass; 
							LPCTSTR(strText),      // control text 
							dwStyle,  // Styles 
							x,         // x position 
							y,         // y position 
							w,        // control width
							h,        // control height
							hWnd,     // Parent window
							(HMENU)nCtrlID,       // No menu.
							(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
							NULL);      // Pointer not needed.
					}
				}
			}
		}
	}

	ATOM RegisterColorWindowClass(CString strColor)
	{
		if (strColor.Find(_T("RGB(")) == -1)
			return NULL;
		CString _strIndex = _T(",");
		_strIndex += strColor;
		if (m_strColors.Find(_strIndex) == -1) {
			m_strColors += _strIndex;
			int r = 0;
			int g = 0;
			int b = 0;
			if (!strColor.IsEmpty()) {
				_stscanf_s(strColor, _T("RGB(%d,%d,%d)"), &r, &g, &b);
			}
			WNDCLASSEXW wcex;
			wcex.cbSize = sizeof(WNDCLASSEX);
			wcex.style = CS_HREDRAW | CS_VREDRAW;
			wcex.lpfnWndProc = WndProc;
			wcex.cbClsExtra = 0;
			wcex.cbWndExtra = 0;
			wcex.hInstance = hInst;
			wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_BROWSERAPP));
			wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
			wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(r, g, b));
			wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_BROWSERAPP);
			wcex.lpszClassName = LPCTSTR(strColor);
			wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
			return RegisterClassExW(&wcex);
		}
		return NULL;
	}

private:
	CString m_strColors;
	map<CString, DWORD> m_mapStyle;

	//IUniverseAppProxy
	virtual void OnCustomizedMainWindowElement(HWND hMainWnd, CString strXml)
	{
		CreateControls(NULL, strXml);
	}

	//IWindowProvider:
	virtual HWND Create(HWND hParentWnd, IXobj* pXobj)
	{
		USES_CONVERSION;
		BSTR bstrTag = ::SysAllocString(L"");

		pXobj->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T("")) {
			BSTR bstrColor = ::SysAllocString(L"");
			pXobj->get_Attribute(CComBSTR("winbkcolor"), &bstrColor);
			CString strWndCls = OLE2T(bstrColor);
			::SysFreeString(bstrColor);

			if (strWndCls == _T(""))
			{
				return CreateWindowW(szWindowClass, L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
					CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, hParentWnd, (HMENU)0, hInst, nullptr);
			}
			else {
				RegisterColorWindowClass(strWndCls);
				CString _strIndex = _T(",");
				_strIndex += strWndCls;
				_strIndex += _T("");
				if (m_strColors.Find(_strIndex) != -1) {
					HWND hWnd = CreateWindowW(LPCTSTR(strWndCls), L"", WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
						CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, hParentWnd, (HMENU)0, hInst, nullptr);
					if (::IsWindow(hWnd))
					{
						CComBSTR bstrXml("");
						pXobj->get_XML(&bstrXml);
						CString strXml = OLE2T(bstrXml);
						CreateControls(hWnd, strXml);
					}
					return hWnd;
				}
			}
		}
		return NULL;
	};
};

CBrowserApp theApp;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
		// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_BROWSERAPP, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BROWSERAPP));
	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BROWSERAPP));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(128, 128, 256));// (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_BROWSERAPP);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	if (!theApp.InitApplication())
		return false;
	HWND hWnd = theApp.m_hMainWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case 1963: //for NTP
		{
			IBrowser* pBrowser = g_pSpaceTelescopeImpl->GetHostBrowser(hWnd);
			if (pBrowser)
			{
				pBrowser->OpenURL(CComBSTR("http://www.github.com/tangramdev"), BrowserWndOpenDisposition::CURRENT_TAB, CComBSTR(""), CComBSTR(""));
			}
		}
		break;
		case 1965: //for NTP
		{
			CWebViewImpl* pWebViewImpl = g_pSpaceTelescopeImpl->GetWebPageImpl(hWnd);
			if (pWebViewImpl)
			{
				CString strXml = _T("");
				IXobj* pXobj = g_pSpaceTelescopeImpl->GetXobj(hWnd);
				if (pXobj) {
					CComBSTR bstrXml("");
					pXobj->get_XML(&bstrXml);
					strXml = OLE2T(bstrXml);
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CTangramXmlParse* pChild = m_Parse.GetChild(_T("urls"));
						if (pChild)
							g_pSpaceTelescopeImpl->m_pBrowserFactory->CreateBrowser(NULL, pChild->xml());
					}
				}
			}
		}
		break;
		case 1992:
		{
			CWebViewImpl* pWebViewImpl = g_pSpaceTelescopeImpl->GetWebPageImpl(hWnd);
			if (pWebViewImpl)
			{
				CString strXml = _T("");
				IXobj* pXobj = g_pSpaceTelescopeImpl->GetXobj(hWnd);
				if (pXobj) {
					CComBSTR bstrXml("");
					pXobj->get_XML(&bstrXml);
					strXml = OLE2T(bstrXml);
					CTangramXmlParse m_Parse;
					if (m_Parse.LoadXml(strXml))
					{
						CTangramXmlParse* pChild = m_Parse.GetChild(_T("dynwindow"));
						if (pChild) {
							IXobj* pRetObj = nullptr;
							pXobj->Observe(CComBSTR(pChild->name()), CComBSTR(pChild->xml()), &pRetObj);
						}
					}
				}
			}
		}
		break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_SIZE:
	{
		if (g_pSpaceTelescopeImpl &&
			hWnd == g_pSpaceTelescopeImpl->m_hMainWnd &&
			::IsWindow(theApp.m_hMainClientWnd))
		{
			RECT rc;
			::GetClientRect(hWnd, &rc);
			::SetWindowPos(theApp.m_hMainClientWnd, HWND_BOTTOM, 0, 0, rc.right, rc.bottom, SWP_NOREDRAW | SWP_NOACTIVATE);
		}
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...

		RECT rc;
		::GetClientRect(hWnd, &rc);
		SetTextColor(hdc, RGB(255, 170, 0));
		SetBkMode(hdc, TRANSPARENT);
		SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
		LPCTSTR pszText = _T("Color Window");
		TextOut(hdc,
			(rc.left + rc.right) / 2,
			(rc.top + rc.bottom) / 2,
			pszText,
			lstrlen(pszText));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
