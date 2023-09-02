
// MFCApplication4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCDlgApp:
// See MFCApplication4.cpp for the implementation of this class
//

class CMFCDlgApp : public CWinApp
{
public:
	CMFCDlgApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCDlgApp theApp;
