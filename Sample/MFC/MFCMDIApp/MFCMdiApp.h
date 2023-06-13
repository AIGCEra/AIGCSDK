
// MFCApplication3.h : main header file for the MFCApplication3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCMDIApp:
// See MFCMDIApp.cpp for the implementation of this class
//

class CMFCMDIApp : public CAIGCWinApp
{
public:
	CMFCMDIApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMDIApp theApp;
