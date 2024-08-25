/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001           *
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
 *
 * Web Runtime is a new, subversive and Internet Oriented Development Technology
 * for Windows Desktop Software. Its core idea is that, relying on the open-source
 * project of Chromium, developers are allowed to use their familiar software
 * development technology to realize the Main Process of their application system
 * as the Browser Process of Modern Web Browser. Because the Main Process is realized
 * by the developers themselves, the application system developed in this way is
 * completely different from modern web browser. This kind of application will
 * integrate the infrastructure of modern web browser as a part of the system model,
 * the application system contains not only the browser window inherent in the browser,
 * but also other desktop elements oriented to the application, such as WinForms, Java
 * and other mature software elements.
 *
 * There are Three Key Features of Webruntime:
 * 1. Built-in Modern Web Browser: Independent Browser Window and Browser Window
 *    as sub windows of other windows are supported in the application process;
 * 2. DOM Plus: DOMPlus is a natural extension of the standard DOM system.
 *    It allows the application system to support a kind of generalized web pages,
 *    which are composed of standard DOM elements and binary components supported
 *    by the application system;
 * 3. JavaScript for Application: Similar to VBA in MS office, JavaScript will
 *    become a built-in programmable language in the application system, so that
 *    the application system can be expanded and developed for the Internet based
 *    on modern javscript/Web technology.
 *
 * Built-in Full-Featured Modern Web Browser Subsystem
 *		Since the main process of the application system is essentially a Browser
 * Process, the application system can naturally create a new browser window. The
 * difference with standard browsers is that we allow the browser window to be a child
 * window of other windows. in sub-window model, we see a brand-new scene: a multi-tab
 * browser sub-window, we think this structure is more suitable for organizing specific
 * applications. Of course, the application system fully supports the creation of an
 * independent browser window as a part of the complete application system, and the browser
 * window serves as a natural extension of the ecological chain to ensure the richness
 * and diversity of the application system content.
 * DOM Plus:
 *		Because a large number of mature binary components that conform to industry
 * standards have formed a wealth of software asset accumulation, web runtime allows
 * developers to regard these existing accumulation as new DOM elements and then become
 * a part of web pages, this starting point eventually forms "DOM Plus". DOM plus is a
 * natural extension of standard DOM for desktop applications, similar to the extension
 * from "real number system" to "complex number system" in mathematical theory. Undoubtedly,
 * for the development of mathematics, from "real number system" to "complex number system"
 * is a huge leap, which can be said to be a decisive change in the development of modern
 * mathematics. We hope that the evolution from "DOM" to "DOM plus" will have a similar
 * effect, which is bound to be a huge change from desktop software to Internet desktop software.
 *		Different from earlier IE, based on the sandbox mechanism of Modern Web Browser,
 * we let these binary elements run in the Browser Process, completely isolated from the
 * Browser's Renderer Process. This makes full use of the security mechanisms of modern
 * browsers and also takes into account the accumulation of mature software component
 * technologies. Based on such considerations, existing development technologies such as
 * .NET, COM, Java, etc. can be fully applied to Internet software development.
 *
 * Use of this source code is governed by a BSD-style license that
 * can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *******************************************************************************/

 // Universe.h : DLL

#pragma once

namespace Browser
{
	class CBrowser;
	class CWebView;
}

using namespace Browser;

typedef HRESULT(__stdcall* CosmosCLRCreateInstance)(REFCLSID clsid, REFIID riid, LPVOID* ppInterface);

static bool g_bRecturnPressed = false;

class CHelperWnd :
	public CWindowImpl<CHelperWnd, CWindow>
{
public:
	CHelperWnd(void)
	{
		m_strID = _T("");
	};

	~CHelperWnd(void) {};

	CString m_strID;
	DECLARE_WND_CLASS(_T("Tangram Helper Window Class"))
	BEGIN_MSG_MAP(CHelperWnd)
	END_MSG_MAP()
	void OnFinalMessage(HWND hWnd);
};

class CUniverse :
	public CWinApp, 
	public CAtlDllModuleT<CUniverse>
{
public:
	CUniverse();
	~CUniverse();

	bool				m_bHostCLR;
	bool				m_bAppStarting = false;

	CString				m_strCosmosVer;
	CString				GetFileVer();

	int					Run();
	void				SetHook(DWORD ThreadID);
	wstring				json_to_xml(wstring& jsonStr);

	static LRESULT CALLBACK CBTProc(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK ForegroundIdleProc(int nCode, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK CosmosMsgWndProc(_In_ HWND hWnd, UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam);
	static LRESULT CALLBACK CosmosExtendedWndProc(_In_ HWND hWnd, UINT msg, _In_ WPARAM wParam, _In_ LPARAM lParam);

	static BOOL CALLBACK EnumProcessWindowsProc(HWND hWnd, LPARAM lParam)
	{
		if (!::IsWindowVisible(hWnd))return TRUE;
		ProcessData* pProcessData = (ProcessData*)lParam;
		DWORD dwProcessID = 0, dwThreadID = 0;
		dwThreadID = ::GetWindowThreadProcessId(hWnd, &dwProcessID);
		if (dwProcessID == pProcessData->dwProcessID && dwThreadID == pProcessData->dwThreadID) {
			pProcessData->m_hWnd = hWnd;
			return FALSE;
		}
		return TRUE;
	}

	DECLARE_LIBID(LIBID_Universe)

private:
	int ExitInstance();
	BOOL InitInstance();

	static LRESULT CALLBACK GetMessageProc(int nCode, WPARAM wParam, LPARAM lParam);
};

extern CUniverse theApp;
extern CSpaceTelescope* g_pSpaceTelescope;
