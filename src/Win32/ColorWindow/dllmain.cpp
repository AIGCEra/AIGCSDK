// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
#include "dllmain.h"
#include "..\..\AIGCSDK\AIGC.cpp"

class ColorWindowProvider :
	public CWebRTWindowProviderApp
{
public:
	ColorWindowProvider() {
		m_hInst = NULL;
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

private:
	HINSTANCE m_hInst;
	CString m_strColors;
	map<CString, DWORD> m_mapStyle;

	void CreateControls(HWND _hWnd, CString strXml)
	{
		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strXml))
		{
			HWND hWnd = _hWnd;
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
							m_hInst,
							NULL);      // Pointer not needed.
					}
				}
			}
		}
	}

	ATOM RegisterColorWindowClass(CString strColor)
	{
		if (g_pSpaceTelescopeImpl == NULL || ::IsWindow(g_pSpaceTelescopeImpl->m_hMainWnd) == false)
			return NULL;
		if (m_hInst == NULL && g_pSpaceTelescopeImpl->m_hMainWnd)
			m_hInst = (HINSTANCE)GetWindowLongPtr(g_pSpaceTelescopeImpl->m_hMainWnd, GWLP_HINSTANCE);
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
			wcex.lpfnWndProc = ColorWndProc;
			wcex.cbClsExtra = 0;
			wcex.cbWndExtra = 0;
			wcex.hInstance = m_hInst;
			wcex.hIcon = 0;
			wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
			wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(r, g, b));
			wcex.lpszMenuName = NULL;
			wcex.lpszClassName = LPCTSTR(strColor);
			wcex.hIconSm = 0;
			return RegisterClassExW(&wcex);
		}
		return NULL;
	}

	static LRESULT CALLBACK ColorWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_COMMAND:
		{
			int wmId = LOWORD(wParam);
			// Parse the menu selections:
			switch (wmId)
			{
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
					//pWebViewImpl->ObserveViewport(_T(""), _T(""));
				}
			}
			break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		break;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code that uses hdc here...

			RECT rc;
			::GetClientRect(hWnd, &rc);
			SetTextColor(hdc, RGB(255, 170, 128));
			SetBkMode(hdc, TRANSPARENT);
			SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
			LPCTSTR pszText = _T("Color Window @ dll");
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

			if (strWndCls != _T(""))
			{
				RegisterColorWindowClass(strWndCls);
				CString _strIndex = _T(",");
				_strIndex += strWndCls;
				_strIndex += _T("");
				if (m_strColors.Find(_strIndex) != -1) {
					HWND hWnd = CreateWindowW(LPCTSTR(strWndCls), L"", WS_CHILD | WS_VISIBLE,
						CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, hParentWnd, (HMENU)0, m_hInst, nullptr);
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

ColorWindowProvider theProvider;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		if (theProvider.m_hModule == NULL) {
			theProvider.m_hModule = hModule;
			theProvider.WebRTInit(_T(""));
		}
	}
	break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


