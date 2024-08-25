/********************************************************************************
 *           Web Runtime for Application - Version 1.0.0.202203120001
 ********************************************************************************
 * Copyright (C) 2002-2021 by Tangram Team.   All Rights Reserved.
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
// Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
 *
 * CONTACT INFORMATION:
 * mailto:tangramteam@outlook.com or mailto:sunhuizlz@yeah.net
 * https://www.webruntime.com
 *
 *******************************************************************************/

 // dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "dllmain.h"
#include "CosmosEvents.cpp"
#include <shellapi.h>
#include <shlobj.h>

CSpaceTelescope::CSpaceTelescope()
{
	ATLTRACE(_T("Loading CSpaceTelescope :%p\n"), this);
	m_pWebRT = nullptr;
	m_dwThreadID = ::GetCurrentThreadId();

	TCHAR m_szBuffer[MAX_PATH];
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
	CString path = m_szBuffer;
	m_strAppPath = path;
	int nPos = m_strAppPath.ReverseFind('\\');
	m_strAppPath = m_strAppPath.Left(nPos + 1);
	m_bHostApp = false;
	nPos = path.ReverseFind('.');
	path = path.Left(nPos + 1);

	m_bNativeApp =
		(::PathFileExists(path + _T("app.html")) == false) &&
		(::PathFileExists(path + _T("html")) == false);
}

CSpaceTelescope::~CSpaceTelescope()
{
	CString strInfo = _T("");
	strInfo.Format(_T("------------------Begin Release CSpaceTelescope: %p from Cosmos.dll ------------------------\n"), this);
	OutputDebugString(strInfo);
	if (g_pSpaceTelescopeImpl)
		g_pSpaceTelescopeImpl->OnCLRHostExit();
	strInfo.Format(_T("------------------End Release CSpaceTelescope: %p from Cosmos.dll ------------------------\n"), this);
	OutputDebugString(strInfo);
}

int CalculateByteMD5(BYTE* pBuffer, int BufferSize, CString& MD5)
{
	HCRYPTPROV hProv = NULL;
	DWORD dw = 0;
	// Acquire a cryptographic provider context handle.
	if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0))
	{
		HCRYPTHASH hHash;
		// Create the hash object.
		if (CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
		{
			// Compute the cryptographic hash of the buffer.
			if (CryptHashData(hHash, pBuffer, BufferSize, 0))
			{
				DWORD dwCount = 16;
				unsigned char digest[16];
				CryptGetHashParam(hHash, HP_HASHVAL, digest, &dwCount, 0);

				if (hHash)
					CryptDestroyHash(hHash);

				// Release the provider handle.
				if (hProv)
					CryptReleaseContext(hProv, 0);

				unsigned char b;
				char c;
				char* Value = new char[1024];
				int k = 0;
				for (int i = 0; i < 16; i++)
				{
					b = digest[i];
					for (int j = 4; j >= 0; j -= 4)
					{
						c = ((char)(b >> j) & 0x0F);
						if (c < 10) c += '0';
						else c = ('a' + (c - 10));
						Value[k] = c;
						k++;
					}
				}
				Value[k] = '\0';
				MD5 = CString(Value);
				delete Value;
			}
		}
	}
	else
	{
		dw = GetLastError();
		if (dw == NTE_BAD_KEYSET)
		{
			if (CryptAcquireContext(
				&hProv,
				NULL,
				NULL,
				PROV_RSA_FULL,
				CRYPT_NEWKEYSET))
			{
				_tprintf(TEXT("CryptAcquireContext succeeded.\n"));
			}
			else
			{
				_tprintf(TEXT("CryptAcquireContext falied.\n"));
			}
		}
	}

	return 1;
}

CString ComputeHash(CString source)
{
	std::string strSrc = (LPCSTR)CW2A(source, CP_UTF8);
	int nSrcLen = strSrc.length();
	CString strRet = _T("");
	CalculateByteMD5((BYTE*)strSrc.c_str(), nSrcLen, strRet);
	return strRet;
}

//CString CSpaceTelescope::BuildConfigDataFile(CString strExeName, CString strProductName, CString strCompanyPathName)
//{
//	TCHAR m_szBuffer[MAX_PATH];
//	HRESULT hr = SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, m_szBuffer);
//	CString _strProductName = strProductName;
//	CString _strCompanyPathName = strCompanyPathName;
//	_strProductName.MakeLower();
//	_strCompanyPathName.MakeLower();
//	CString _strAppKey = _T("");
//	CString _strAppDataPath = _T("");
//	CString _strConfigDataFile = _T("");
//	_strAppDataPath = m_szBuffer;
//	_strAppDataPath += _T("\\");
//	_strAppDataPath.Replace(_T("\\\\"), _T("\\"));
//	_strAppDataPath += _T("TangramData\\");
//	_strAppDataPath += strExeName;
//	_strAppDataPath += _T("\\");
//	_strAppDataPath.MakeLower();
//	if (!::PathIsDirectory(_strAppDataPath))
//		CreateDirectory(_strAppDataPath, NULL);
//	_strAppKey = ComputeHash(_strAppDataPath + _T("@") + _strCompanyPathName + _T("@") + _strProductName);
//	_strAppDataPath += _strAppKey;
//	_strAppDataPath += _T("\\");
//	if (!::PathIsDirectory(_strAppDataPath))
//		CreateDirectory(_strAppDataPath, NULL);
//	_strConfigDataFile = _strAppDataPath;
//	_strConfigDataFile += strExeName;
//	_strConfigDataFile += _T(".tangram");
//	return _strConfigDataFile;
//}

void CSpaceTelescope::InitWebRTApp(bool bCrashReporting)
{
	if (m_bNativeApp || m_bBrowserModeInit)
		return;
	HMODULE hModule = NULL;
	if (g_pSpaceTelescopeImpl->m_hWebRTProxyModel == NULL) {
		TCHAR m_szBuffer[MAX_PATH];
		::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
		CString strAIGCAgentPath = m_szBuffer;
		int nPos = strAIGCAgentPath.ReverseFind('\\');
		strAIGCAgentPath = strAIGCAgentPath.Left(nPos + 1) + _T("AIGCAgent.dll");
		hModule = g_pSpaceTelescopeImpl->m_hWebRTProxyModel = ::LoadLibrary(strAIGCAgentPath);
	}
	else
		hModule = g_pSpaceTelescopeImpl->m_hWebRTProxyModel;
	if (hModule) {
		typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting);
		_InitApp _pInitAppFunction;
		_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
		if (_pInitAppFunction != NULL) {
			m_bBrowserModeInit = true;
			_pInitAppFunction(bCrashReporting);
		}
	}
}

CString CSpaceTelescope::GetLibPathFromAssemblyQualifiedName(CString strAssemblyQualifiedName)
{
	BOOL bLocalAssembly = false;
	strAssemblyQualifiedName.MakeLower();
	CString strPath = _T("");
	CString strLib = _T("");
	CString strObjName = _T("");
	CString strVersion = _T("");
	CString strPublickeytoken = _T("");
	int nPos = strAssemblyQualifiedName.Find(_T("publickeytoken"));
	if (nPos == -1)
	{
		bLocalAssembly = true;
		nPos = strAssemblyQualifiedName.Find(_T(","));
		if (nPos != -1)
		{
			strObjName = strAssemblyQualifiedName.Left(nPos);
			strLib = strAssemblyQualifiedName.Mid(nPos + 1);
			strLib.Trim();
			strObjName.Trim();
			if (strLib == _T("Cosmos"))// || strLib == _T("tangram"))
			{
				return strObjName + _T("|") + strLib + _T("|");
			}
			else {
				HMODULE hModule1 = ::GetModuleHandle(L"tangramwizard.dll");
				if (hModule1)
				{

				}
				HMODULE hModule = ::GetModuleHandle(L"devenv.exe");
				if (hModule)
				{
					TCHAR szPath[MAX_PATH] = { 0 };
					::GetModuleFileName(hModule, szPath, MAX_PATH);
					strLib = szPath;
					nPos = strLib.ReverseFind('\\');
					strLib = strLib.Left(nPos + 1);
					strLib += _T("PublicAssemblies\\tangramwizard");
					return strObjName + _T("|") + strLib + _T("|");
				}
			}
		}
	}
	else
	{
		strPublickeytoken = strAssemblyQualifiedName.Mid(nPos + 15);
		if (strPublickeytoken == _T("null"))
		{
			bLocalAssembly = true;
			nPos = strAssemblyQualifiedName.Find(_T("version"));
			if (nPos != -1)
			{
				strLib = strAssemblyQualifiedName.Left(nPos);
				nPos = strLib.ReverseFind(',');
				strLib = strLib.Left(nPos);
				nPos = strLib.Find(',');
				strObjName = strLib.Left(nPos);
				strLib = strLib.Mid(nPos + 1);
				strLib.Trim();
			}
		}
		else
		{
			nPos = strAssemblyQualifiedName.Find(_T("version"));
			if (nPos != -1)
			{
				strVersion = strAssemblyQualifiedName.Mid(nPos + 8);
				strLib = strAssemblyQualifiedName.Left(nPos);
				nPos = strLib.ReverseFind(',');
				strLib = strLib.Left(nPos);
				nPos = strVersion.Find(',');
				strVersion = strVersion.Left(nPos);
				nPos = strLib.Find(',');
				strObjName = strLib.Left(nPos);
				strLib = strLib.Mid(nPos + 1);
				strLib.Trim();
				TCHAR m_szBuffer[MAX_PATH];
				HRESULT hr = SHGetFolderPath(NULL, CSIDL_WINDOWS, NULL, 0, m_szBuffer);
				strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_MSIL\\%s\\v4.0_%s__%s\\%s.dll"), m_szBuffer, strLib, strVersion, strPublickeytoken, strLib);
				if (::PathFileExists(strPath))
					return strObjName + _T("|") + strLib + _T("|") + strPath;
				else
				{
#ifdef _WIN64
					strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_%d\\%s\\v4.0_%s__%s\\%s.dll"), m_szBuffer, 64, strLib, strVersion, strPublickeytoken, strLib);
#else
					strPath.Format(_T("%s\\Microsoft.NET\\assembly\\GAC_%d\\%s\\v4.0_%s__%s\\%s.dll"), m_szBuffer, 32, strLib, strVersion, strPublickeytoken, strLib);
#endif
					if (::PathFileExists(strPath))
						return strObjName + _T("|") + strLib + _T("|") + strPath;
				}
			}
		}
	}
	if (strLib != _T(""))
	{
		if (strLib.CompareNoCase(g_pSpaceTelescopeImpl->m_strExeName) == 0)
		{
			strPath = m_strAppPath + strLib + _T(".exe");
		}
		else
		{
			if (g_pSpaceTelescopeImpl->m_bOfficeApp)
			{
				if (m_strOfficeComponentPath == _T(""))
				{
					TCHAR m_szBuffer[MAX_PATH];
					if (SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, 0, m_szBuffer) == S_OK) {
						m_strOfficeComponentPath = CString(m_szBuffer);
						m_strOfficeComponentPath += _T("\\tangram\\");
						m_strOfficeComponentPath += g_pSpaceTelescopeImpl->m_strExeName;
						m_strOfficeComponentPath += _T("\\");
					}
				}
				strPath = m_strOfficeComponentPath + strLib + _T(".dll");
			}
			else
			{
				strPath = m_strAppPath + strLib + _T(".dll");
			}
		}
		if (::PathFileExists(strPath))
			return strObjName + _T("|") + strLib + _T("|") + strPath;
		else
		{
			HANDLE hFind; // file handle
			WIN32_FIND_DATA FindFileData;

			hFind = FindFirstFile(m_strAppPath + _T("*.*"), &FindFileData); // find the first file
			if (hFind == INVALID_HANDLE_VALUE)
			{
				return _T("");
			}

			bool bSearch = true;
			while (bSearch) // until we finds an entry
			{
				if (FindNextFile(hFind, &FindFileData))
				{
					// Don't care about . and ..
					//if(IsDots(FindFileData.cFileName))
					if ((_tcscmp(FindFileData.cFileName, _T(".")) == 0) ||
						(_tcscmp(FindFileData.cFileName, _T("..")) == 0))
						continue;

					// We have found a directory
					if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
					{
						CString strPath = m_strAppPath + FindFileData.cFileName + _T("\\");
						CString strPath2 = strPath + strLib + _T(".dll");
						if (::PathFileExists(strPath2))
							return strObjName + _T("|") + strLib + _T("|") + strPath2;
						CString strRet = _GetLibPathFromAssemblyQualifiedName(strPath, strLib + _T(".dll"));
						if (strRet != _T(""))
							return strObjName + _T("|") + strLib + _T("|") + strRet;
					}

				}//FindNextFile
				else
				{
					if (GetLastError() == ERROR_NO_MORE_FILES) // no more files there
						bSearch = false;
					else {
						// some error occured, close the handle and return false
						FindClose(hFind);
						return _T("");
					}
				}
			}//while

			// Find .shared directory
			CString strSharedPath = g_pSpaceTelescopeImpl->m_strAppDataPath;// OLE2T(pVal.bstrVal);
			hFind = FindFirstFile(strSharedPath + _T(".shared\\*.*"), &FindFileData); // find the first file
			if (hFind == INVALID_HANDLE_VALUE)
			{
				return _T("");
			}

			bSearch = true;
			while (bSearch) // until we finds an entry
			{
				if (FindNextFile(hFind, &FindFileData))
				{
					// Don't care about . and ..
					//if(IsDots(FindFileData.cFileName))
					if ((_tcscmp(FindFileData.cFileName, _T(".")) == 0) ||
						(_tcscmp(FindFileData.cFileName, _T("..")) == 0))
						continue;

					// We have found a directory
					if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
					{
						CString strPath = m_strAppPath + FindFileData.cFileName + _T("\\");
						CString strPath2 = strPath + strLib + _T(".dll");
						if (::PathFileExists(strPath2))
							return strObjName + _T("|") + strLib + _T("|") + strPath2;
						CString strRet = _GetLibPathFromAssemblyQualifiedName(strPath, strLib + _T(".dll"));
						if (strRet != _T(""))
							return strObjName + _T("|") + strLib + _T("|") + strRet;
					}

				}//FindNextFile
				else
				{
					if (GetLastError() == ERROR_NO_MORE_FILES) // no more files there
						bSearch = false;
					else {
						// some error occured, close the handle and return false
						FindClose(hFind);
						return _T("");
					}
				}
			}//while

			// End Find .shared directory

			FindClose(hFind); // closing file handle
		}
	}

	return _T("");
}

CString CSpaceTelescope::_GetLibPathFromAssemblyQualifiedName(CString strDir, CString strLibName)
{
	CString strPath = strDir + strLibName;
	if (::PathFileExists(strPath))
		return strPath;
	HANDLE hFind; // file handle
	WIN32_FIND_DATA FindFileData;

	hFind = FindFirstFile(strDir + _T("*.*"), &FindFileData); // find the first file
	if (hFind == INVALID_HANDLE_VALUE)
	{
		return _T("");
	}

	bool bSearch = true;
	while (bSearch) // until we finds an entry
	{
		if (FindNextFile(hFind, &FindFileData))
		{
			// Don't care about . and ..
			//if(IsDots(FindFileData.cFileName))
			if ((_tcscmp(FindFileData.cFileName, _T(".")) == 0) ||
				(_tcscmp(FindFileData.cFileName, _T("..")) == 0))
				continue;

			// We have found a directory
			if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				CString strPath = strDir + FindFileData.cFileName + _T("\\");
				CString strRet = _GetLibPathFromAssemblyQualifiedName(strPath, strLibName);
				if (strRet != _T(""))
					return strRet;
			}

		}//FindNextFile
		else
		{
			if (GetLastError() == ERROR_NO_MORE_FILES) // no more files there
				bSearch = false;
			else {
				// some error occured, close the handle and return false
				FindClose(hFind);
				return _T("");
			}
		}
	}//while

	FindClose(hFind); // closing file handle
	return _T("");
}

CWebRTXobjEvent::CWebRTXobjEvent()
{
	m_pXobj = nullptr;
	m_pXobjCLREvent = nullptr;
}

CWebRTXobjEvent::~CWebRTXobjEvent()
{
	if (m_pXobjCLREvent)
	{
		//LONGLONG nValue = (LONGLONG)m_pXobj;
		DispEventUnadvise(m_pXobj);
	}
}

using namespace ATL;
