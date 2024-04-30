#include "AIGC.h"
#include <wincrypt.h>
#include <iostream>
#include <fstream>
#include <sstream>

IWebRT* g_pWebRT = nullptr;

namespace CommonUniverse {
	typedef IWebRT* (__stdcall* GetWebRT)();
	typedef CWebRTImpl* (__stdcall* GetWebRTImpl)(IWebRT**);
	typedef bool(__stdcall* _IsBrowserModel)(bool bSupportCrashReporting, void*);

	HHOOK	g_hCBTHook = NULL;

	_IsBrowserModel FuncIsBrowserModel;
	CWebRTImpl* g_pSpaceTelescopeImpl = nullptr;

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

	CString BuildConfigDataFile(CString strExeName, CString strProductName, CString strCompanyPathName)
	{
		TCHAR m_szBuffer[MAX_PATH];
		HRESULT hr = SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, m_szBuffer);
		CString _strProductName = strProductName;
		CString _strCompanyPathName = strCompanyPathName;
		_strProductName.MakeLower();
		_strCompanyPathName.MakeLower();
		CString _strAppKey = _T("");
		CString _strAppDataPath = _T("");
		CString _strConfigDataFile = _T("");
		_strAppDataPath = m_szBuffer;
		_strAppDataPath += _T("\\");
		_strAppDataPath.Replace(_T("\\\\"), _T("\\"));
		_strAppDataPath += _T("TangramData\\");
		_strAppDataPath += strExeName;
		_strAppDataPath += _T("\\");
		_strAppDataPath.MakeLower();
		if (!::PathIsDirectory(_strAppDataPath))
			CreateDirectory(_strAppDataPath, NULL);
		_strAppKey = ComputeHash(_strAppDataPath + _T("@") + _strCompanyPathName + _T("@") + _strProductName);
		_strAppDataPath += _strAppKey;
		_strAppDataPath += _T("\\");
		if (!::PathIsDirectory(_strAppDataPath))
			CreateDirectory(_strAppDataPath, NULL);
		_strConfigDataFile = _strAppDataPath;
		_strConfigDataFile += strExeName;
		_strConfigDataFile += _T(".tangram");
		return _strConfigDataFile;
	}

	CString g_strChromeRTFilePath = _T("");
	CString g_strUniverseFilePath = _T("");

	static void GetWebRTInfo() {
		CString g_strCfgDataFile = BuildConfigDataFile(_T("aigcbrowser"), _T("aigcbrowser"), _T("Tangram Team"));
		if (::PathFileExists(g_strCfgDataFile))
		{
			CString strData = _T("");
			wifstream fin(g_strCfgDataFile, wifstream::binary);
			std::wstringstream stream;
			stream << fin.rdbuf();
			strData = stream.str().c_str();
			fin.close();
			int nPos = strData.Find(_T("Universe"));
			if (nPos != -1) {
				CString strTemp = strData.Mid(nPos + 8);
				nPos = strTemp.Find(_T(".dll"));
				strTemp = strTemp.Left(nPos + 4);
				nPos = strTemp.Find(_T(":"));
				g_strUniverseFilePath = strTemp.Mid(nPos - 1);
				if (::PathFileExists(g_strUniverseFilePath) == false)
					g_strUniverseFilePath = _T("");
			}
			nPos = strData.Find(_T("AIGCAgent"));
			if (nPos != -1) {
				CString strTemp = strData.Mid(nPos + 9);
				nPos = strTemp.Find(_T(".dll"));
				strTemp = strTemp.Left(nPos + 4);
				nPos = strTemp.Find(_T(":"));
				g_strChromeRTFilePath = strTemp.Mid(nPos - 1);
				if (::PathFileExists(g_strChromeRTFilePath) == false)
					g_strChromeRTFilePath = _T("");
			}
		}
	}

	void DpiUtil::SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiAwarenessContext)
	{
		// Call the latest DPI awareness function possible
		static auto SetProcessDpiAwarenessContextFunc = []() {
			return reinterpret_cast<decltype(&::SetProcessDpiAwarenessContext)>(
				::GetProcAddress(GetUser32Module(), "SetProcessDpiAwarenessContext"));
			}();
			if (SetProcessDpiAwarenessContextFunc)
			{
				// Windows 10 1703+: SetProcessDpiAwarenessContext
				SetProcessDpiAwarenessContextFunc(dpiAwarenessContext);
			}
			else
			{
				static auto SetProcessDpiAwarenessFunc = []() {
					return reinterpret_cast<decltype(&::SetProcessDpiAwareness)>(
						::GetProcAddress(GetShcoreModule(), "SetProcessDpiAwareness"));
					}();
					if (SetProcessDpiAwarenessFunc)
					{
						// Windows 8.1+: SetProcessDpiAwareness
						SetProcessDpiAwarenessFunc(
							ProcessDpiAwarenessFromDpiAwarenessContext(dpiAwarenessContext));
					}
					else if (dpiAwarenessContext != DPI_AWARENESS_CONTEXT_UNAWARE)
					{
						// Windows 7+: SetProcessDPIAware
						::SetProcessDPIAware();
					}
			}
	}

	HMODULE DpiUtil::GetUser32Module()
	{
		static HMODULE user32Module = nullptr;
		if (user32Module == nullptr)
		{
			user32Module = LoadLibraryA("User32.dll");
		}
		return user32Module;
	}

	HMODULE DpiUtil::GetShcoreModule()
	{
		static HMODULE shcoreModule = nullptr;
		if (shcoreModule == nullptr)
		{
			shcoreModule = LoadLibraryA("Shcore.dll");
		}
		return shcoreModule;
	}

	PROCESS_DPI_AWARENESS DpiUtil::ProcessDpiAwarenessFromDpiAwarenessContext(
		DPI_AWARENESS_CONTEXT dpiAwarenessContext)
	{
		if (dpiAwarenessContext == DPI_AWARENESS_CONTEXT_UNAWARE ||
			dpiAwarenessContext == DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED)
		{
			return PROCESS_DPI_UNAWARE;
		}
		if (dpiAwarenessContext == DPI_AWARENESS_CONTEXT_SYSTEM_AWARE)
		{
			return PROCESS_SYSTEM_DPI_AWARE;
		}
		if (dpiAwarenessContext == DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE ||
			dpiAwarenessContext == DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2)
		{
			return PROCESS_PER_MONITOR_DPI_AWARE;
		}
		// All DPI awarenes contexts should be covered above.
		//FAIL_FAST();
		return PROCESS_DPI_UNAWARE;
	}

	CTangramXmlParse::CTangramXmlParse(void)
	{
		Initialize();
		elem = NULL;
		m_pParentParse = NULL;
	}

	CTangramXmlParse::~CTangramXmlParse(void)
	{
		Clear();
		//if (m_pUnknown) 
		//{
		//	m_pUnknown->Release();
		//	m_pUnknown = NULL;
		//}
		elem = NULL;
	}


	void CTangramXmlParse::_CTangramXmlParse(CComPtr<IXMLDOMElement> _elem)
	{
		Initialize();
		elem = _elem;
		//m_pUnknown = NULL;
		//elem->QueryInterface(IID_IUnknown,(void**)&m_pUnknown);

		CComPtr<IXMLDOMNodeList> pList = NULL;
		if (_elem->get_childNodes(&pList) == S_OK)
		{
			_CTangramXmlParse(pList);
		}
	}

	void CTangramXmlParse::_CTangramXmlParse(CComPtr<IXMLDOMNode> _node)
	{
		CComPtr<IXMLDOMElement> pElem = NULL;
		if (_node->QueryInterface<IXMLDOMElement>(&pElem) == S_OK)
		{
			_CTangramXmlParse(pElem);
		}
	}

	void CTangramXmlParse::ModifyNameAttrByFix(CString strNameFix)
	{
		if (strNameFix != _T(""))
		{
			CComVariant var;
			CComBSTR bstrAttrName(L"id");
			CComBSTR bstrNAME(L"Name");
			HRESULT hr = elem->getAttribute(bstrNAME, &var);
			CString strNAME = OLE2T(var.bstrVal);
			hr = elem->getAttribute(bstrAttrName, &var);
			if (var.vt == VT_BSTR)
			{
				CString strName = OLE2T(var.bstrVal);
				CComBSTR bstrName = CComBSTR(strNameFix);
				CString _strName = OLE2T(var.bstrVal);
				if (_strName == _T(""))
					bstrName += strNAME;
				else
					bstrName += var.bstrVal;
				var.bstrVal = bstrName;
				hr = elem->setAttribute(bstrAttrName, var);
			}
			if (hr != S_OK)
			{
				::VariantClear(&var);
				CString _strName = strNameFix + strNAME;
				var.vt = VT_BSTR;
				var.bstrVal = _strName.AllocSysString();
				hr = elem->setAttribute(bstrAttrName, var);
			}
			::VariantClear(&var);
			//::SysFreeString(bstrAttrName);
			int nCount = GetCount();
			for (int i = 0; i < nCount; i++)
			{
				GetChild(i)->ModifyNameAttrByFix(strNameFix);
			}
		}
	}

	CTangramXmlParse* CTangramXmlParse::AddNode(CTangramXmlParse* pParse, CString strNameFix)
	{
		if (pParse)
		{
			if (strNameFix != _T(""))
			{
				pParse->ModifyNameAttrByFix(strNameFix);
			}
			CComPtr<IXMLDOMElement> pElem = pParse->GetElement();
			CComPtr<IXMLDOMDocument> pDoc;
			elem->get_ownerDocument(&pDoc);
			if (pDoc)
			{
				CComPtr<IXMLDOMNode> pNode;
				HRESULT hr = elem->appendChild(pElem, &pNode);
				if (hr == S_OK)
				{
					CTangramXmlParse* pWebRTXmlParse = new CTangramXmlParse(pNode);
					m_aChildElements.push_back(pWebRTXmlParse);
					return pWebRTXmlParse;
				}
			}
		}
		return NULL;
	}

	CTangramXmlParse* CTangramXmlParse::AddTabNode(CString strName, CString strObjTypeID, CString strObjID, CString strStyle, int nPages)
	{
		strName.Trim();
		if (strName == _T(""))
			return NULL;
		strObjTypeID.Trim().MakeLower();
		strStyle.Trim().MakeLower();
		if (strObjTypeID == _T(""))
			strObjTypeID = _T("tabbedwnd");
		if (strObjTypeID == _T("tabbedwnd"))
		{
			if (strStyle == _T(""))
				strStyle = _T("19");
		}
		CTangramXmlParse* pNode = AddNode(_T("xobj"));
		pNode->put_attr(_T("gridtype"), strObjID);
		pNode->put_attr(_T("id"), strName);
		pNode->put_attr(_T("objid"), strObjTypeID);
		pNode->put_attr(_T("tabstyle"), strStyle);
		if (nPages)
		{
			CString strVal = _T("");
			for (int i = 0; i < nPages; i++)
			{
				CTangramXmlParse* _pNode = pNode->AddNode(_T("xobj"));
				strVal.Format(_T("%s_Page%d"), strName, i);
				_pNode->put_attr(_T("id"), strVal);
				_pNode->put_attr(_T("caption"), strVal);
			}
		}
		return pNode;
	}

	CTangramXmlParse* CTangramXmlParse::AddSplitterNode(int nRows, int nCols, CString strName, int nWidth, int nHeight)
	{
		strName.Trim();
		if (strName == _T(""))
			return NULL;
		nRows = nRows % 16;
		nCols = nCols % 16;
		if (nWidth * nHeight && nRows * nCols > 1)
		{
			CTangramXmlParse* pNode = AddNode(_T("xobj"));
			int _nWidth = nWidth / nCols;
			int _nHeight = nHeight / nRows;
			CString strRows = _T("");
			CString strCols = _T("");
			if (pNode)
			{
				pNode->put_attr(_T("gridtype"), CString(_T("xobj")));
				pNode->put_attr(_T("id"), strName);
				CString strVal = _T("");
				strVal.Format(_T("%d"), nRows);
				pNode->put_attr(_T("rows"), strVal);
				strVal.Format(_T("%d"), nCols);
				pNode->put_attr(_T("cols"), strVal);
				strVal.Format(_T("%d,"), _nWidth);
				CString	strVal2 = _T("");
				CString	strVal3 = _T("");
				strVal2.Format(_T("%d,"), _nHeight);
				for (int i = 0; i < nCols; i++)
				{
					if (i < nCols - 1)
					{
						strRows += strVal;
					}
					for (int j = 0; j < nRows; j++)
					{
						if (i == 0 && j < nRows - 1)
						{
							strCols += strVal2;
						}
						CTangramXmlParse* _pNode = pNode->AddNode(_T("xobj"));
						strVal3.Format(_T("%s_View%02d%02d"), strName, i, j);
						_pNode->put_attr(_T("id"), strVal3);
					}
				}
				pNode->put_attr(_T("width"), strRows);
				pNode->put_attr(_T("height"), strCols);
				return pNode;
			}
		}

		return NULL;
	}

	BOOL CTangramXmlParse::ModifyNode(int nRow, int nCol, CString strName, CString strXml)
	{
		int nIndex = 0;
		CString strID = this->attr(_T("gridtype"), _T(""));
		if (strID == _T(""))
			return FALSE;
		int nCount = GetCount();
		if (nCount == 0)
			return FALSE;
		nRow = nRow % 16;
		nCol = nCol % 16;
		int nRows = attrInt(_T("rows"), 0);
		int nCols = attrInt(_T("cols"), 0);
		if (nRow >= nRows || nCol > nCols)
			return FALSE;

		nIndex = nRow * nCols + nCol;
		CTangramXmlParse* pChild = GetChild(nIndex);

		CTangramXmlParse m_Parse;
		if (m_Parse.LoadXml(strXml) || m_Parse.LoadFile(strXml))
		{
			CTangramXmlParse* pWindow = m_Parse.GetChild(TGM_NUCLEUS);
			if (pWindow)
			{
				CTangramXmlParse* pNode = pWindow->GetChild(_T("xobj"));
				if (pNode)
				{
					if (ReplaceNode(pChild, pNode, strName))
						return TRUE;
				}
			}
		}
		return FALSE;
	}

	CTangramXmlParse* CTangramXmlParse::ReplaceNode(CTangramXmlParse* pOldParse, CTangramXmlParse* pNewParse, CString strNameFix)
	{
		int nCount = GetCount();
		for (int i = 0; i < nCount; i++)
		{
			CTangramXmlParse* pChild = GetChild(i);
			if (pChild == pOldParse)
			{
				if (strNameFix != _T(""))
				{
					pNewParse->ModifyNameAttrByFix(strNameFix);
				}
				CString strCapOld = pOldParse->attr(_T("caption"), _T(""));
				CComPtr<IXMLDOMElement> pElem = pOldParse->GetElement();
				CComPtr<IXMLDOMElement> pNewElem = pNewParse->GetElement();
				CComPtr<IXMLDOMNode> pOutNode;
				HRESULT hr = elem->replaceChild(pNewElem, pElem, &pOutNode);
				CComPtr<IXMLDOMNodeList> pList = NULL;
				if (elem->get_childNodes(&pList) == S_OK)
				{
					CComPtr<IXMLDOMNode> pNode;
					pList->get_item(i, &pNode);
					CComPtr<IXMLDOMElement> pElem = NULL;
					if (pNode->QueryInterface<IXMLDOMElement>(&pElem) == S_OK)
					{
						CTangramXmlParse* pOldChild = pChild;
						pChild = new CTangramXmlParse(pElem);
						pChild->m_pParentParse = this;
						m_aChildElements[i] = pChild;
						delete pOldChild;
						CString strCap = pChild->attr(_T("caption"), _T(""));
						if (strCap == _T("") && strCapOld != _T(""))
							pChild->put_attr(_T("caption"), strCapOld);
						return pChild;
					}
				}
				break;
			}
		}
		return NULL;
	}

	void CTangramXmlParse::_CTangramXmlParse(CComPtr<IXMLDOMNodeList> _nlist)
	{
		long nLen = 0;
		_nlist->get_length(&nLen);
		for (long i = 0; i < nLen; i++)
		{
			CComPtr<IXMLDOMNode> pNode = NULL;
			CComPtr<IXMLDOMElement> pElem = NULL;
			if (_nlist->get_item(i, &pNode) == S_OK)
			{
				if (pNode->QueryInterface<IXMLDOMElement>(&pElem) == S_OK)
				{
					//m_aChildElements.Add(new CTangramXmlParse(pElem));
					CTangramXmlParse* pChild = new CTangramXmlParse(pElem);
					pChild->m_pParentParse = this;
					m_aChildElements.push_back(pChild);
				}
			}
		}
	}

	CTangramXmlParse* CTangramXmlParse::GetChild(int nIndex)
	{
		if (nIndex < 0 || nIndex >= GetCount())
			return NULL;
		return m_aChildElements[nIndex];
	}

	CTangramXmlParse* CTangramXmlParse::GetChild(CString strName)
	{
		for (int i = 0; i < GetCount(); i++)
		{
			if (m_aChildElements[i]->name().CompareNoCase(strName) == 0)
				return m_aChildElements[i];
		}
		return NULL;
	}

	CTangramXmlParse& CTangramXmlParse::operator[](CString strName)
	{
		CTangramXmlParse* pXml = GetChild(strName);
		if (pXml != NULL) return *pXml;
		//ASSERT(FALSE);//don't have the node.
		return *this;
	}

	CTangramXmlParse& CTangramXmlParse::operator[](int nIndex)
	{
		CTangramXmlParse* pXml = GetChild(nIndex);
		if (pXml != NULL) return *pXml;
		//ASSERT(FALSE);//index is overflow
		return *this;
	}

	CTangramXmlParse* CTangramXmlParse::FindItem(LPCTSTR strItemname)
	{
		CTangramXmlParse* pItem = NULL;

		//if (name().CompareNoCase(strItemname) == 0)
		//{
		//	pItem = this;
		//}

		if (pItem == NULL)
		{
			for (int i = 0; i < GetCount(); i++)
			{
				CTangramXmlParse* pI = GetChild(i);
				if (pI->name().CompareNoCase(strItemname) == 0)
				{
					pItem = pI;
					break;
				}
			}
		}

		if (pItem == NULL)
		{
			for (int i = 0; i < GetCount(); i++)
			{
				CTangramXmlParse* pX = GetChild(i)->FindItem(strItemname);

				if (pX != NULL)
				{
					pItem = pX;
					break;
				}
			}
		}
		return pItem;
	}

	CTangramXmlParse* CTangramXmlParse::FindItemByName(LPCTSTR strItemname)
	{
		CTangramXmlParse* pItem = NULL;

		//if (name().CompareNoCase(strItemname) == 0)
		//{
		//	pItem = this;
		//}

		if (pItem == NULL)
		{
			for (int i = 0; i < GetCount(); i++)
			{
				CTangramXmlParse* pI = GetChild(i);
				CString strName = pI->attr(_T("id"), _T(""));
				if (strName.CompareNoCase(strItemname) == 0)
				{
					pItem = pI;
					break;
				}
			}
		}

		if (pItem == NULL)
		{
			for (int i = 0; i < GetCount(); i++)
			{
				CTangramXmlParse* pX = GetChild(i)->FindItemByName(strItemname);

				if (pX != NULL)
				{
					pItem = pX;
					break;
				}
			}
		}
		return pItem;
	}

	bool CTangramXmlParse::operator==(CTangramXmlParse& nItem)
	{
		IUnknown* pUn1 = NULL;
		elem->QueryInterface(IID_IUnknown, (void**)&pUn1);

		IUnknown* pUn2 = NULL;
		nItem.elem->QueryInterface(IID_IUnknown, (void**)&pUn2);

		bool bRet = (pUn2 == pUn1);

		pUn1->Release();
		pUn2->Release();

		return bRet;
	}

	void CTangramXmlParse::Initialize()
	{
		m_strFile = _T("");
		m_bCanSave = false;
	}

	CTangramXmlParse* CTangramXmlParse::_FindParseByEle(CTangramXmlParse* _pParent, IUnknown* pEle)
	{
		IUnknown* pUn1 = NULL;
		_pParent->elem->QueryInterface(IID_IUnknown, (void**)&pUn1);
		if (pUn1 == pEle)
		{
			pUn1->Release();
			return _pParent;
		}
		pUn1->Release();

		int c = (int)_pParent->GetCount();

		for (int i = 0; i < c; i++)
		{
			CTangramXmlParse* pValue = _FindParseByEle(_pParent->m_aChildElements[i], pEle);
			if (pValue != NULL) return pValue;
		}
		return NULL;
	}



	CTangramXmlParse* CTangramXmlParse::GetParseByElement(IXMLDOMElement* pEle)
	{
		if (elem == NULL) return NULL;
		CTangramXmlParse* pParse = NULL;
		IUnknown* pUnk = NULL;

		if (pEle->QueryInterface(IID_IUnknown, (void**)&pUnk) == S_OK)
		{
			pParse = _FindParseByEle(this, pUnk);
			pUnk->Release();
		}
		return pParse;
	}

	CTangramXmlParse* CTangramXmlParse::AddNode(CString name)
	{
		CComPtr<IXMLDOMDocument> pDoc = NULL;
		CComPtr<IXMLDOMElement> pElement = NULL;
		if (elem->get_ownerDocument(&pDoc) == S_OK)
		{
			pDoc->createElement(CComBSTR(name), &pElement);
			if (pElement != NULL)
			{
				if (elem->appendChild(pElement, NULL) == S_OK)
				{
					CTangramXmlParse* pWebRTXmlParse = new CTangramXmlParse(pElement);
					m_aChildElements.push_back(pWebRTXmlParse);
					return pWebRTXmlParse;
				}
			}
		}
		return NULL;
	}

	HRESULT CTangramXmlParse::RemoveNode(CString name)
	{
		CTangramXmlParse* pNode = GetChild(name);
		return RemoveNode(pNode);
	}

	HRESULT CTangramXmlParse::RemoveNode(CTangramXmlParse* pNode)
	{
		if (pNode == NULL) return E_FAIL;

		HRESULT hr = elem->removeChild(pNode->elem, NULL);
		if (hr == S_OK)
		{
			//for(int i = 0; i<GetCount(); i++)
			//{
			//	if (m_aChildElements[i] == pNode)
			//	{
			//		m_aChildElements.RemoveAt(i);
			//		//m_aChildElements.erase(m_aChildElements.at(i));
			//		delete pNode;
			//		break;
			//	}
			//}

			vector<CTangramXmlParse*>::iterator it;
			//for(int i = 0; i<GetCount(); i++)
			for (it = m_aChildElements.begin(); it != m_aChildElements.end(); it++)
			{
				if (*it == pNode)
				{
					//m_aChildElements.RemoveAt(i);
					m_aChildElements.erase(it);
					delete pNode;
					break;
				}
			}
		}
		return hr;
	}

	HRESULT CTangramXmlParse::RemoveNode(int index)
	{
		if (index >= GetCount()) return -1;
		CTangramXmlParse* pNode = m_aChildElements[index];
		return RemoveNode(pNode);
	}

	HRESULT CTangramXmlParse::RemoveSubNodes()
	{
		for (int i = GetCount(); i >= 0; i--)
			RemoveNode(i);
		return S_OK;
	}

	bool CTangramXmlParse::put_text(CString text)
	{
		CComPtr<IXMLDOMNodeList> pSubNodeList;
		elem->get_childNodes(&pSubNodeList);
		long sublen;
		bool bFound = false;
		pSubNodeList->get_length(&sublen);
		for (long j = 0; j < sublen; j++)
		{
			CComPtr<IXMLDOMNode> pChildNode = NULL;
			if (pSubNodeList->get_item(j, &pChildNode) == S_OK)
			{
				BSTR subname = NULL;
				pChildNode->get_nodeName(&subname);
				if (wcscmp(subname, L"#text") == 0)
				{
					pChildNode->put_text(CComBSTR(text));
					bFound = true;
					break;
				}
			}
		}
		if (!bFound) elem->put_text(CComBSTR(text));
		return true;
	}

	bool CTangramXmlParse::put_attr(CString name, CString value)
	{
		return (elem->setAttribute(CComBSTR(name), CComVariant(CComBSTR(value))) == S_OK);
	}

	bool CTangramXmlParse::put_attr(CString name, int value)
	{
		CString strInfo;
		strInfo.Format(_T("%d"), value);
		return put_attr(name, strInfo);
	}

	bool CTangramXmlParse::put_attr(CString name, __int64 value)
	{
		CString strInfo;
		strInfo.Format(_T("%I64d"), value);
		return put_attr(name, strInfo);
	}

	bool CTangramXmlParse::put_attr(CString name, bool value)
	{
		CString strInfo = _T("false");
		if (value) strInfo = _T("true");
		return put_attr(name, strInfo);
	}

	CString CTangramXmlParse::name()
	{
		if (!elem) return _T("");
		CComBSTR bn;
		elem->get_tagName(&bn);
		return CString(bn);
	}

	CString CTangramXmlParse::xml()
	{
		if (!elem) return _T("");
		CComBSTR bn;
		elem->get_xml(&bn);
		return CString(bn);
	}

	CString CTangramXmlParse::text()
	{
		if (!elem) return _T("");
		CComPtr<IXMLDOMNodeList> pList = NULL;
		if (elem->get_childNodes(&pList) == S_OK)
		{
			long nLen = 0;
			pList->get_length(&nLen);
			for (long i = 0; i < nLen; i++)
			{
				CComPtr<IXMLDOMNode> pNode = NULL;
				if (pList->get_item(i, &pNode) == S_OK)
				{
					BSTR name = NULL;
					pNode->get_nodeName(&name);
					if (CString(name).CompareNoCase(_T("#text")) == 0)
					{
						BSTR value = NULL;
						pNode->get_text(&value);
						return CString(value);
					}
				}
			}
		}
		return _T("");
	}

	CString CTangramXmlParse::attr(const CString name, CString def) const
	{
		if (!elem) return _T("");
		CComBSTR bname(name);
		CComVariant val(VT_EMPTY);
		elem->getAttribute(bname, &val);

		if (val.vt == VT_BSTR)
		{
			CString strRet = OLE2T(val.bstrVal);
			if (strRet != _T(""))
				return strRet;
		}
		return def;
	}

	DWORD CTangramXmlParse::attr(const CString name, DWORD def) const
	{
		if (!elem) return 0;
		CComBSTR bname(name);
		CComVariant vall(VT_EMPTY);
		elem->getAttribute(bname, &vall);
		if (vall.vt == VT_BSTR)
		{
			//DWORD rr = DWORD();
			CString s = _T("");
			s += vall.bstrVal;
			DWORD rr = _ttoi(s);
			return rr;
		}
		return def;
	}

	//HKEY CTangramXmlParse::attr(const CString name) const
	//{
	//	if(!elem) return 0;
	//}

	bool CTangramXmlParse::attrBool(const CString name, bool def) const
	{
		CString a = attr(name, _T(""));
		if (a.CompareNoCase(_T("true")) == 0) return true;
		else if (a.CompareNoCase(_T("false")) == 0) return false;
		else return def;
	}

	int CTangramXmlParse::attrInt(const CString name, int def) const
	{
		CString str = attr(name, _T(""));
		if (str.IsEmpty()) return def;
		return _ttoi(str);
	}

	__int64 CTangramXmlParse::attrInt64(const CString name, __int64 def) const
	{
		CString str = attr(name, _T(""));
		if (str.IsEmpty()) return def;
		return _ttoi64(str);
	}

	CString CTangramXmlParse::val() const
	{
		USES_CONVERSION;
		if (!elem) return _T("");
		CComVariant val(VT_EMPTY);
		elem->get_nodeTypedValue(&val);
		if (val.vt == VT_BSTR) return OLE2T(val.bstrVal);
		return _T("");
	}

	//新增
	DWORD CTangramXmlParse::vall() const
	{
		USES_CONVERSION;
		if (!elem) return 0;
		CComVariant val(VT_EMPTY);
		elem->get_nodeTypedValue(&val);
		if (val.vt == VT_I8 || val.vt == VT_I4) return DWORD(val.lVal);
		return 0;
	}

	bool CTangramXmlParse::LoadXml(CString strXML)
	{
		//HRESULT hr = CoInitialize(NULL);
		if (m_pDoc != NULL) m_pDoc.Release();
		if (CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&m_pDoc) == S_OK)
		{
			VARIANT_BOOL vb;
			if ((m_pDoc->load(CComVariant(strXML), &vb) != S_OK) || !vb)
			{
				m_pDoc->loadXML(CComBSTR(strXML), &vb);
			}
			if (!vb)
			{
				return false;
			}
			CComPtr<IXMLDOMElement> pEle;
			if (m_pDoc->get_documentElement(&pEle) == S_OK)
			{
				Clear();
				_CTangramXmlParse(pEle);
				return true;
			}
		}
		return false;
	}

	bool CTangramXmlParse::LoadFile(CString strFile)
	{
		//HRESULT hr = CoInitializeEx(NULL,0);
		if (m_pDoc != NULL) m_pDoc.Release();
		if (CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER, IID_IXMLDOMDocument, (void**)&m_pDoc) == S_OK)
		{
			CComVariant file(strFile);
			VARIANT_BOOL vb;
			if (m_pDoc->load(file, &vb) == S_OK)
			{
				if (!vb)
				{
					return false;
				}
				CComPtr<IXMLDOMElement> pEle;
				if (m_pDoc->get_documentElement(&pEle) == S_OK)
				{
					Clear();
					_CTangramXmlParse(pEle);

					m_bCanSave = true;
					m_strFile = strFile;

					return true;
				}
			}
		}
		return false;
	}
	bool CTangramXmlParse::SaveFile(CString strFile)
	{
		if (m_pDoc == NULL)
		{
			elem->get_ownerDocument(&m_pDoc);
		}

		if (strFile.Compare(_T("")) == 0)
		{
			if (m_bCanSave)
			{
				strFile = m_strFile;
			}
		}

		CComVariant var(strFile);
		return (m_pDoc->save(var) == S_OK);
	}

	bool CTangramXmlParse::Reflash()
	{
		Clear();
		if (elem)
			_CTangramXmlParse(elem);
		return true;
	}

	bool CTangramXmlParse::Clear()
	{
		for (int i = 0; i < GetCount(); i++)
		{
			delete m_aChildElements[i];
		}
		//m_aChildElements.RemoveAll();
		m_aChildElements.clear();
		return true;
	}

#ifdef _AFX
	CWinApp* g_pAppBase = nullptr;

	class CTangramHelperWnd : public CWnd {
	public:
		CTangramHelperWnd() {}
		virtual ~CTangramHelperWnd() {}
		void PostNcDestroy() {
			CWnd::PostNcDestroy();
			delete this;
		}

	protected:
		DECLARE_MESSAGE_MAP()
	};
	BEGIN_MESSAGE_MAP(CTangramHelperWnd, CWnd)
	END_MESSAGE_MAP()

	static LRESULT WebRTCBTProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		LRESULT hr = CallNextHookEx(g_hCBTHook, nCode, wParam, lParam);
		HWND hWnd = (HWND)wParam;
		if (nCode == HCBT_CREATEWND) {
			CBT_CREATEWND* pCreateWnd = (CBT_CREATEWND*)lParam;
			TCHAR m_szBuffer[MAX_PATH];
			::GetClassName(hWnd, m_szBuffer, MAX_PATH);
			CString strClassName = m_szBuffer;
			if (strClassName == _T("Tangram Message Window Class")) {
				CWinApp* pApp = AfxGetApp();
				IUniverseAppProxy* pAppProxy = NULL;
				if (pApp && pApp->m_pMainWnd) {
					if (UnhookWindowsHookEx(g_hCBTHook)) {
						if (pApp->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWndEx)) || pApp->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx))) {
							pAppProxy = static_cast<IUniverseAppProxy*>((CAIGCWinAppEx*)pApp);
						}
						else {
							pAppProxy = static_cast<IUniverseAppProxy*>((CAIGCWinApp*)pApp);
						}
						pAppProxy->m_hMainWnd = pApp->m_pMainWnd->m_hWnd;
						::SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pAppProxy);
					}
				}
			}
		}
		return hr;
	}

	class CWebRTProxy : public IWebRTDelegate {
	public:
		CWebRTProxy() {};
		virtual ~CWebRTProxy() {
		}

		// IWebRTDelegate:
		virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) {
			_AFX_THREAD_STATE* pState = AfxGetThreadState();
			while (bIdle &&
				!::PeekMessage(&(pState->m_msgCur), NULL, NULL, NULL, PM_NOREMOVE)) {
				if (!AfxGetApp()->OnIdle(lCount++))
					bIdle = FALSE;  // assume "no idle" state
			}
			return true;
		}

		virtual bool DoIdleWork() {
			if (g_pSpaceTelescopeImpl && g_pSpaceTelescopeImpl->m_hMainWnd &&
				::IsWindow(g_pSpaceTelescopeImpl->m_hMainWnd) == false)
				g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
			return false;
		}

		virtual bool IsAppIdleMessage() {
			_AFX_THREAD_STATE* pState = AfxGetThreadState();
			if (AfxGetApp()->IsIdleMessage(&(pState->m_msgCur))) {
				return true;
			}
			return false;
		}

		virtual void ProcessMsg(MSG* msg) {
			if (msg->message != WM_KICKIDLE) {
				::TranslateMessage(msg);
				::DispatchMessage(msg);
			}
		}

		virtual void ForegroundIdleProc() {
			// send WM_IDLEUPDATECMDUI to the main window
			CWnd* pMainWnd = AfxGetApp()->m_pMainWnd;
			if (pMainWnd != NULL && pMainWnd->m_hWnd != NULL &&
				pMainWnd->IsWindowVisible()) {
				AfxCallWndProc(pMainWnd, pMainWnd->m_hWnd, WM_IDLEUPDATECMDUI,
					(WPARAM)TRUE, 0);
				pMainWnd->SendMessageToDescendants(WM_IDLEUPDATECMDUI, (WPARAM)TRUE, 0,
					TRUE, TRUE);
			}
		}

		virtual bool OnUniversePreTranslateMessage(MSG* pMsg) {
			// if (pMsg->message == WM_CHAR || pMsg->hwnd == nullptr)
			//	return TRUE;
			HWND hwnd = pMsg->hwnd;
			CWinApp* pApp = AfxGetApp();
			CWnd* pWnd = CWnd::FromHandlePermanent(hwnd);
			if (pWnd) {
				if (CMFCPopupMenu::GetActiveMenu() &&
					!::IsWindow(CMFCPopupMenu::GetActiveMenu()->m_hWnd)) {
					return true;
				}
				// if (::GetAncestor(hwnd, GA_ROOTOWNER) ==
				// ::GetAncestor(pApp->m_pMainWnd->m_hWnd, GA_ROOTOWNER))
				//	AFXSetTopLevelFrame((CFrameWnd*)pApp->m_pMainWnd);
				if (pMsg->message == WM_LBUTTONDOWN) {
					if (pApp->m_pMainWnd)
						pApp->m_pMainWnd->PreTranslateMessage(pMsg);
					return true;
				}
				// if (pMsg->wParam==VK_TAB&&IsDialogMessage(pMsg->hwnd, pMsg))
				//{
				//	::DispatchMessage(pMsg);
				//	TranslateMessage(pMsg);
				// }
				return pWnd->PreTranslateMessage(pMsg);
			}
			else {
				switch (pMsg->message) {
				case WM_NCLBUTTONDOWN:
				case WM_NCRBUTTONDOWN:
				case WM_LBUTTONDOWN:
				case WM_RBUTTONDOWN:
				case WM_LBUTTONUP:
					// case WM_POINTERDOWN:
					// case WM_POINTERUP:
				case WM_SETWNDFOCUSE:
					if (pApp->m_pMainWnd) {
						if (g_pSpaceTelescopeImpl->m_bIsDlgApp) {
							if (::IsChild(pApp->m_pMainWnd->m_hWnd, pMsg->hwnd)) {
								// auto it = g_pSpaceTelescopeImpl->m_mapWebView.find(pMsg->hwnd);
								// if (it != g_pSpaceTelescopeImpl->m_mapWebView.end())
								{ return false; }
							}
						}
						pApp->m_pMainWnd->PreTranslateMessage(pMsg);
						return true;
					}
					break;
				case WM_KEYDOWN: {
					if (pApp->m_pMainWnd) {
						if (pMsg->wParam == VK_TAB && IsDialogMessage(pMsg->hwnd, pMsg)) {
							CWnd* pWnd = CWnd::FromHandlePermanent(::GetParent(pMsg->hwnd));
							if (pWnd)
								return pWnd->PreTranslateMessage(pMsg);
						}
						pApp->m_pMainWnd->PreTranslateMessage(pMsg);
						return true;
					}
				} break;
				}
				return TRUE;
			}
			return pApp->PreTranslateMessage(pMsg);
		}

		virtual HICON GetAppIcon(int nIndex) {
			if (g_pAppBase->m_pMainWnd) {
				switch (nIndex) {
				case 0:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pAppBase->m_pMainWnd->m_hWnd, GCLP_HICON));
					break;
				case 1:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pAppBase->m_pMainWnd->m_hWnd, GCLP_HICONSM));
					break;
				}
			}
			else
			{
				TCHAR m_szBuffer[MAX_PATH];
				::GetModuleFileName(GetModuleHandle(NULL), m_szBuffer, MAX_PATH);
				SHFILEINFOW info;
				if (SHGetFileInfoW(m_szBuffer,
					FILE_ATTRIBUTE_NORMAL,
					&info,
					sizeof(info),
					SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
				{
					return info.hIcon;
				}
			}
			return NULL;
		}
	};

	CWebRTProxy theAppProxy;

	CAIGCWinApp::CAIGCWinApp() {
		g_pAppBase = this;
		m_strProviderID = _T("");
		m_nShellCmd = CCommandLineInfo::FileNew;
	}

	CAIGCWinApp::~CAIGCWinApp() {
		TRACE(_T("\n**********************delete CAIGCWinApp**********************\n"));
		if (g_pSpaceTelescopeImpl) {
			g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
		CMFCVisualManager* pCMFCVisualManager = CMFCVisualManager::GetInstance();
		if (pCMFCVisualManager) {
			TRACE(
				_T("\n**********************delete ")
				_T("CMFCVisualManager**********************\n"));
			delete pCMFCVisualManager;
		}
	}

	BOOL CAIGCWinApp::InitApplication() {
		if (WebRTInit(_T("")) ? CWinApp::InitApplication() : false)
			return ProcessAppType(m_bCrashReporting);
		else
			return false;
	}

	HWND CAIGCWinApp::GetActivePopupMenu(HWND hWnd) {
		// CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
		// if (pActivePopupMenu)
		//{
		//	ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
		//	return pActivePopupMenu->m_hWnd;
		// }
		return nullptr;
	}

	int CAIGCWinApp::Run() {
		return CWinThread::Run();
	}

	CString CAIGCWinApp::GetNames() {
		CString strNames = _T("tabctrl,");
		if (m_mapDOMObj.size()) {
			for (auto it = m_mapDOMObj.begin(); it != m_mapDOMObj.end(); it++) {
				strNames += it->first;
				strNames += _T(",");
			}
			return strNames.MakeLower();
		}
		return strNames.MakeLower();
	}

	CString CAIGCWinApp::GetTags(CString strName) {
		CString strNameBase = _T("0,1,2,3,4,5,6,7,");
		strName.Trim().MakeLower();
		if (strName != _T("")) {
			auto it = m_mapDOMObjStyle.find(strName);
			if (it != m_mapDOMObjStyle.end()) {
				strNameBase += it->second;
				strNameBase += _T(",");
				return strNameBase;
			}
		}
		return strNameBase;
	}

	HWND CAIGCWinApp::Create(HWND hParentWnd, IXobj* pXobj) {
		CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
		if (pParent == nullptr) {
			pParent = new CTangramHelperWnd();
			if (!pParent->SubclassWindow(hParentWnd)) {
				TRACE(_T("\n**********************Error**********************\n"));
				return NULL;
			}
		}
		USES_CONVERSION;
		BSTR bstrTag = ::SysAllocString(L"");

		pXobj->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T("")) {
			auto it = m_mapDOMObj.find(m_strTag);
			if (it != m_mapDOMObj.end()) {
				CRuntimeClass* pCls = (CRuntimeClass*)it->second;
				CWnd* pWnd = (CWnd*)pCls->CreateObject();
				if (pWnd) {
					if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView))) {
						AfxSetResourceHandle(AfxGetApp()->m_hInstance);
					}
					if (pWnd->Create(nullptr, _T(""), WS_CHILD | WS_VISIBLE,
						CRect(0, 0, 0, 0), pParent, 0, nullptr)) {
						::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, (WPARAM)pXobj, 20191031);
						if (pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
							CView* pView = static_cast<CView*>(pWnd);
							CFrameWnd* pFrame = pView->GetParentFrame();
							WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
							if (pFrame) {
								pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
									pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
								if (pWebRTFrameWndInfo) {
									HWND hView = pWebRTFrameWndInfo->m_hClient;
									CWnd* pHostView = CWnd::FromHandlePermanent(hView);
									if (pHostView->IsKindOf(RUNTIME_CLASS(CView))) {
										CView* _pView = (CView*)pHostView;
										CDocument* pDoc = _pView->GetDocument();
										if (pDoc) {
											m_mapViewDoc[pView] = pDoc;
											pWebRTFrameWndInfo->m_pDoc = pDoc;
											pWebRTFrameWndInfo->m_hClient = hView;
											pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
										}
									}
								}
							}
						}
						return pWnd->m_hWnd;
					}
				}
			}
		}
		return NULL;
	}

	bool CAIGCWinApp::WebRTInit(CString strID) {
		if (!afxContextIsDLL) {
			CCommandLineInfo cmdInfo;
			ParseCommandLine(cmdInfo);
			m_nShellCmd = cmdInfo.m_nShellCommand;
			switch (m_nShellCmd) {
			case CCommandLineInfo::AppRegister:
			case CCommandLineInfo::AppUnregister:
				return true;
			default:
				break;
			}
			DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
			DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
			GetWebRTInfo();
			if (IsBrowserModel(false)) {
				m_bBuiltInBrowser = true;
				return false;
			}
		}

		HMODULE hAIGCAgentModule = NULL;
		if (::PathFileExists(g_strChromeRTFilePath))
			hAIGCAgentModule = ::LoadLibrary(g_strChromeRTFilePath);
		else
			hAIGCAgentModule = ::LoadLibrary(L"AIGCAgent.dll");
		if (hAIGCAgentModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
				m_szBuffer) == S_OK) {
				g_strChromeRTFilePath = CString(m_szBuffer);
				g_strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
				if (::PathFileExists(g_strChromeRTFilePath)) {
					hAIGCAgentModule = ::LoadLibrary(g_strChromeRTFilePath);
				}
			}
		}
		TCHAR m_szBuffer[MAX_PATH];
		TCHAR szDriver[MAX_PATH] = { 0 };
		TCHAR szDir[MAX_PATH] = { 0 };
		TCHAR szExt[MAX_PATH] = { 0 };
		TCHAR szFile2[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
		_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
		CString strTangramDll = szDriver;
		strTangramDll += szDir;
		strTangramDll += _T("universe.dll");
		HMODULE hUniverseModule = ::LoadLibrary(strTangramDll);
		if (hUniverseModule == NULL && g_strUniverseFilePath != _T(""))
			hUniverseModule = ::LoadLibrary(g_strUniverseFilePath);
		if (hUniverseModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hUniverseModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
			g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hAIGCAgentModule;

			if (!afxContextIsDLL) {
				m_strProviderID += _T("host");
				m_strProviderID.MakeLower();

				g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
				g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
					static_cast<IUniverseAppProxy*>(this));
				g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
					static_cast<IWindowProvider*>(this));
				if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
					g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
					::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
						(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
						g_pSpaceTelescopeImpl->m_nAppType);
				g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			}
			else {
				strID.Trim();
				if (strID == _T(""))
					strID = _T("component");
				if (m_strProviderID == _T("")) {
					CString strName = AfxGetApp()->m_pszAppName;
					m_strProviderID = strName + _T(".") + strID;
				}
				if (m_strProviderID != _T("")) {
					m_strProviderID.MakeLower();
					g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
						static_cast<IUniverseAppProxy*>(this));
					g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
						static_cast<IWindowProvider*>(this));
				}
				g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			}
		}
		if (hUniverseModule == NULL || hAIGCAgentModule == NULL) {
			g_hCBTHook = SetWindowsHookEx(WH_CBT, WebRTCBTProc, NULL, ::GetCurrentThreadId());
		}
		return true;
	}

	CString CAIGCWinApp::QueryDocType(HWND hWnd) {
		CWnd* pWnd = CWnd::FromHandle(hWnd);
		CFrameWnd* pFrame = pWnd->GetParentFrame();
		if (pFrame) {
			CString strType =
				(LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
			if (strType == _T("") && pFrame == m_pMainWnd &&
				pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
				strType = _T("mdiframe");
			}
			if (strType == _T("") && pFrame == m_pMainWnd &&
				pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd))) {
				strType = _T("miniframe");
			}
			return strType;
		}
		return _T("");
	}

	CString CAIGCWinApp::QueryWndClassName(HWND hWnd) {
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		if (pWnd) {
			CRuntimeClass* pClassInfo = pWnd->GetRuntimeClass();
			if (pClassInfo) {
				return CString(pClassInfo->m_lpszClassName);
			}
		}
		return _T("");
	}

	HWND CAIGCWinApp::GetFrameWnd(HWND hWnd, int& nType) {
		CWnd* pWnd = CWnd::FromHandle(hWnd);
		if (pWnd) {
			CFrameWnd* pFrame = pWnd->GetParentFrame();
			if (pFrame) {
				if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
					nType = 1;
				else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
					nType = 2;
				else if (pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd)))
					nType = 4;
				else
					nType = 3;
				return pFrame->m_hWnd;
			}
		}
		return NULL;
	}

	HWND CAIGCWinApp::QueryWndInfo(QueryType nType, HWND hWnd) {
		if (hWnd == NULL && m_pMainWnd) {
			if (g_pSpaceTelescopeImpl == NULL) {
				HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
				if (hModule) {
					GetWebRTImpl _pWebRTImplFunction;
					_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
					g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
				}
			}
			if (m_hMainWnd == NULL) {
				m_hMainWnd = m_pMainWnd->m_hWnd;
				CCommandLineInfo cmdInfo;
				ParseCommandLine(cmdInfo);
				m_nShellCmd = cmdInfo.m_nShellCommand;
				if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
					WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
					HANDLE hHandle = ::GetProp(m_pMainWnd->m_hWnd, _T("WebRTFrameWndInfo"));
					if (hHandle == 0)
					{
						pWebRTFrameWndInfo = g_pSpaceTelescopeImpl->InsertWebRTFrameWndInfo(m_hMainWnd);
						hHandle = pWebRTFrameWndInfo;
					}
					else
					{
						pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
					}

					if (pWebRTFrameWndInfo) {
						if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
						{
							POSITION nPos = GetFirstDocTemplatePosition();
							while (nPos) {
								CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
								POSITION pos = pTemplate->GetFirstDocPosition();
								while (pos != NULL) {
									CDocument* pDoc = pTemplate->GetNextDoc(pos);
									POSITION pos2 = pDoc->GetFirstViewPosition();
									while (pos2 != NULL) {
										CView* pView = pDoc->GetNextView(pos2);
										ASSERT_VALID(pView);
										if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
											if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate))) {
												pWebRTFrameWndInfo->m_nFrameType = 2;
											}
										}
										else
										{
											CFrameWnd* pFrame = pView->GetParentFrame();
											if (m_pMainWnd == pFrame) {
												g_pSpaceTelescopeImpl->m_hFirstView = pView->m_hWnd;
												if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
													pWebRTFrameWndInfo->m_nFrameType = 1;
												else
													pWebRTFrameWndInfo->m_nFrameType = 4;
											}
										}
									}
								}
							}
							CFrameWnd* pFrame = (CFrameWnd*)m_pMainWnd;
							if (pFrame) {
								if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
									pWebRTFrameWndInfo->m_nFrameType = 2;
									pWebRTFrameWndInfo->m_hClient = ((CMDIFrameWnd*)pFrame)->m_hWndMDIClient;
									POSITION nPos = GetFirstDocTemplatePosition();
									while (nPos) {
										CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
										POSITION pos = pTemplate->GetFirstDocPosition();
										CDocument* pDoc = pTemplate->GetNextDoc(pos);
										POSITION pos2 = pDoc->GetFirstViewPosition();
										while (pos2 != NULL) {
											CView* pView = pDoc->GetNextView(pos2);
											ASSERT_VALID(pView);
											g_pSpaceTelescopeImpl->AttachMDIChild(m_hMainWnd, pView->GetParentFrame()->m_hWnd, pView->m_hWnd);
										}
									}
								}
								else {
									if (pWebRTFrameWndInfo->m_pDoc == NULL) {
										CDocument* m_pDoc = pFrame->GetActiveDocument();
										if (m_pDoc) {
											pWebRTFrameWndInfo->m_hClient = pFrame->GetActiveView()->m_hWnd;
											pWebRTFrameWndInfo->m_pDoc = m_pDoc;
											CDocTemplate* pTemplate = m_pDoc->GetDocTemplate();
											pWebRTFrameWndInfo->m_pDocTemplate = pTemplate;
											pWebRTFrameWndInfo->m_nFrameType = pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)) ? 1 : 4;
										}
									}
								}
							}
						}
					}
				}
			}
			return m_hMainWnd;
		}
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		switch (nType) {
		case MainWnd:
			if (m_pMainWnd) {
				pWnd = m_pMainWnd;
				if (pWnd) {
					WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
					HANDLE hHandle = ::GetProp(pWnd->m_hWnd, _T("WebRTFrameWndInfo"));
					if (hHandle) {
						pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
						if (pWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
							pWebRTFrameWndInfo->m_nFrameType = 2;
						else {
							POSITION nPos = GetFirstDocTemplatePosition();
							while (nPos) {
								CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
								POSITION pos = pTemplate->GetFirstDocPosition();
								while (pos != NULL) {
									CDocument* pDoc = pTemplate->GetNextDoc(pos);
									POSITION pos2 = pDoc->GetFirstViewPosition();
									while (pos2 != NULL) {
										CView* pView = pDoc->GetNextView(pos2);
										ASSERT_VALID(pView);
										CFrameWnd* pFrame = pView->GetParentFrame();
										if (m_pMainWnd == pFrame) {
											if (pTemplate->IsKindOf(
												RUNTIME_CLASS(CMultiDocTemplate))) {
												if (!pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
													pWebRTFrameWndInfo->m_nFrameType = 1;
												return pWnd->m_hWnd;
											}
											break;
										}
									}
								}
							}
						}
					}
				}
				return m_pMainWnd->m_hWnd;
			}
			break;
		case CanClose: {
			if (pWnd) {
				if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
					CFrameWnd* _pFrame = (CFrameWnd*)pWnd;
					POSITION nPos = GetFirstDocTemplatePosition();
					while (nPos) {
						CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
						POSITION pos = pTemplate->GetFirstDocPosition();
						while (pos != NULL) {
							CDocument* pDoc = pTemplate->GetNextDoc(pos);
							POSITION pos2 = pDoc->GetFirstViewPosition();
							while (pos2 != NULL) {
								CView* pView = pDoc->GetNextView(pos2);
								ASSERT_VALID(pView);
								CFrameWnd* pFrame = pView->GetParentFrame();
								if (_pFrame == pFrame) {
									if (pDoc->CanCloseFrame(pFrame)) {
										return pFrame->m_hWnd;
									}
									else
										return NULL;
								}
							}
						}
					}
				}
			}
			return NULL;
		} break;
		case DocView: {
			if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
				CView* pView = static_cast<CView*>(pWnd);
				WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
				CDocument* pDoc = pView->GetDocument();
				if (pDoc) {
					HWND hRetFrame = NULL;
					CDocTemplate* pTemplate = pDoc->GetDocTemplate();
					CFrameWnd* pFrame = pView->GetParentFrame();
					if (pFrame) {
						hRetFrame = pFrame->m_hWnd;
						CString strInfo = m_strCreatingDOCID;
						if (strInfo == _T(""))
							strInfo = _T("default");
						CRuntimeClass* pClsInfo = pView->GetRuntimeClass();
						CString strName = CString(pClsInfo->m_lpszClassName);
						auto it = m_mapDOMObj.find(strName);
						if (it == m_mapDOMObj.end())
							m_mapDOMObj[strName] = pClsInfo;
						bool bRet = g_pSpaceTelescopeImpl->SetFrameInfo(hWnd, hRetFrame, strInfo,
							pDoc, pTemplate);
						//if (pWnd->IsKindOf(RUNTIME_CLASS(CScrollView)) &&
						//    ::GetParent(hWnd) == hRetFrame)
						//  ((CScrollView*)pWnd)->ResizeParentToFit();
						pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
							hRetFrame, _T("WebRTFrameWndInfo"));
						if (pWebRTFrameWndInfo == nullptr) {
							__int64 nType = 0;
							if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
								nType = 2;
							else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
								nType = 3;
							else if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
								nType = 1;
							::SetProp(hRetFrame, _T("CosmosFrameWndType"), (HANDLE)nType);
						}
						else {
							pWebRTFrameWndInfo->m_hClient = hWnd;
							if (pWebRTFrameWndInfo->m_pDoc == nullptr && pDoc) {
								pWebRTFrameWndInfo->m_pDoc = pDoc;
								pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
							}
							if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
								pWebRTFrameWndInfo->m_nFrameType = 2;
							else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd))) {
								pWebRTFrameWndInfo->m_nFrameType = 3;
							}
							else if (pTemplate->IsKindOf(
								RUNTIME_CLASS(CMultiDocTemplate))) {
								pWebRTFrameWndInfo->m_nFrameType = 1;
							}
							else if (pFrame->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
								pWebRTFrameWndInfo->m_nFrameType = 4;
						}
					}
					return hRetFrame;
				}
			}
		} break;
		case QueryDestroy: {
			if (::IsWindow(hWnd))
			{
				m_pMainWnd = pWnd;
				return pWnd->m_hWnd;
			}
		} break;
		case ObserveComplete: {
			for (auto& it : m_mapViewDoc) {
				it.second->AddView(it.first);
			}
			m_mapViewDoc.erase(m_mapViewDoc.begin(), m_mapViewDoc.end());
		} break;
		case RecalcLayout: {
			CWnd* pWnd = CWnd::FromHandle(hWnd);
			CFrameWnd* pFrame = pWnd->GetParentFrame();
			if (pFrame) {
				pFrame->RecalcLayout();
				return pFrame->m_hWnd;
			}
			else {
				pWnd = CWnd::FromHandlePermanent(hWnd);
				if (pWnd && pWnd->IsFrameWnd()) {
					pFrame = (CFrameWnd*)pWnd;
					pFrame->RecalcLayout();
					return pFrame->m_hWnd;
				}
			}
		} break;
		case SetMainWndNULL: {
			if (g_pSpaceTelescopeImpl->m_hMainWnd) {
				m_pMainWnd = nullptr;
			}
		} break;
		default:
			break;
		}
		return NULL;
	}

	bool CAIGCWinApp::SetFrameCaption(HWND hWnd,
		CString strCaption,
		CString strAppName) {
		if (strCaption == _T("") || !::IsWindow(hWnd))
			return false;
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		CFrameWnd* pFrame = nullptr;
		if (pWnd) {
			if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
				pFrame = (CFrameWnd*)pWnd;
			}
			else {
				pFrame = pWnd->GetParentFrame();
			}
			if (pFrame) {
				WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
					pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
				if (pWebRTFrameWndInfo) {
					CDocument* pDoc = (CDocument*)pWebRTFrameWndInfo->m_pDoc;
					if (pDoc) {
						CString strPath = pDoc->GetPathName();
						if (strPath == _T("")) {
							CString strTitle = pDoc->GetTitle();
							CDocTemplate* pTemplate =
								(CDocTemplate*)pWebRTFrameWndInfo->m_pDocTemplate;
							CString name = _T("");
							pTemplate->GetDocString(name, CDocTemplate::docName);
							strTitle.Replace(name, strCaption);
							pDoc->SetTitle(strTitle);
							switch (pWebRTFrameWndInfo->m_nFrameType) {
							case 1:
							case 4:
								::SetWindowText(pFrame->m_hWnd, strTitle + _T(" - ") +
									strAppName + _T(" - ") +
									g_pSpaceTelescopeImpl->m_strAppName);
								break;
							default:
								::SetWindowText(pFrame->m_hWnd, strTitle);
								break;
							}
						}
						return true;
					}
				}
			}
		}
		else {
			pWnd = CWnd::FromHandle(hWnd);
			if (pWnd)
				pFrame = pWnd->GetParentFrame();
		}
		if (pFrame) {
			CString strText = _T("");
			pFrame->GetWindowText(strText);
			CString strTitle = pFrame->GetTitle();
			int nPos = strText.ReverseFind('-');
			if (nPos != -1) {
				CString s1 = strText.Left(nPos + 1);
				s1 += _T(" ");
				s1 += strCaption;
				::SetWindowText(pFrame->m_hWnd, s1);
				pFrame->SetTitle(strCaption);
				return true;
			}
			else {
				pFrame->SetTitle(strCaption);
				::SetWindowText(pFrame->m_hWnd, strCaption);
			}
			return true;
		}

		return false;
	}

	CString CAIGCWinApp::QueryParentInfo(HWND hPWnd, void* lpInfo) {
		CWnd* pParent = CWnd::FromHandlePermanent(hPWnd);
		if (pParent) {
			CFrameWnd* pParentFrame = nullptr;
			if (pParent->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
				if (pParent->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
					return _T("");
				pParentFrame = (CFrameWnd*)pParent;
			}
			else
				pParentFrame = pParent->GetParentFrame();
			if (pParentFrame) {
				CCreateContext* pContext = (CCreateContext*)lpInfo;
				CDocument* pDoc = pContext->m_pCurrentDoc;
				CDocTemplate* pTemplate =
					pDoc->GetDocTemplate();  // pContext->m_pNewDocTemplate;
				CString strExt = _T("");
				pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
				strExt.MakeLower();
				if (strExt == _T(""))
					strExt = _T("default");
				return strExt;
			}
		}
		return _T("");
	}

	void CAIGCWinApp::OpenDocFile(CString strFileName,
		CString strExt,
		CString strCreatingDOCID) {
		POSITION nPos = GetFirstDocTemplatePosition();
		while (nPos) {
			CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
			if (strExt == _T("")) {
				if (pTemplate) {
					m_strCreatingDOCID = strCreatingDOCID;
					if (m_bNoDefaultMainWnd)
						pTemplate->OpenDocumentFile(NULL);
					return;
				}
			}
			CString _strExt = _T("");
			pTemplate->GetDocString(_strExt, CDocTemplate::filterExt);
			_strExt.MakeLower();
			if (_strExt == _T(""))
				_strExt = _T("default");
			if (strExt != _T("") && strExt.CompareNoCase(strExt) == 0) {
				m_strCreatingDOCID = strCreatingDOCID;
				pTemplate->OpenDocumentFile(strFileName == _T("") ? NULL
					: LPCTSTR(strFileName));
				return;
			}
		}
	}

	BOOL CAIGCWinApp::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
	{
		BOOL bCmdProcess = (nCode == 0 && pExtra == NULL && pHandlerInfo == NULL && g_pSpaceTelescopeImpl && ::IsWindow(g_pSpaceTelescopeImpl->m_hCosmosWnd));
		if (bCmdProcess)
		{
			//HWND hActiveWnd = ::GetActiveWindow();
			bCmdProcess = true;
			::SendMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, 0, 20240409);
			switch (nID) {
			case ID_FILE_OPEN:
			case ID_FILE_NEW:
			case ID_FILE_NEW_FRAME:
				AfxSetResourceHandle(m_hInstance);
				break;
			default:
				break;
			}
		}

		BOOL bRet = CWinApp::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
		if (bCmdProcess)
		{
			::PostMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, 1, 20240409);
		}
		return bRet;
	}

	void CAIGCWinApp::OnIPCMsg(CWebViewImpl* pWebViewImpl,
		CString strType,
		CString strParam1,
		CString strParam2,
		CString strParam3,
		CString strParam4,
		CString strParam5) {
		if (strType.CompareNoCase(_T("COSMOS_CREATE_DOC")) == 0) {
			AfxSetResourceHandle(m_hInstance);
			int nCount = 0;
			m_strCreatingDOCID = _T("");
			CDocTemplate* pTemplate = nullptr;
			POSITION nPos = GetFirstDocTemplatePosition();
			while (nPos) {
				nCount++;
				pTemplate = GetNextDocTemplate(nPos);
				CString strExt = _T("");
				pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
				strExt.MakeLower();
				if (strExt == _T(""))
					strExt = _T("default");
				if (strExt != _T("") && strExt.CompareNoCase(strParam1) == 0) {
					m_strCreatingDOCID = strParam2;
					pTemplate->OpenDocumentFile(nullptr);
					return;
				}
			}
			if (pTemplate && m_strCreatingDOCID == _T("") &&
				nCount == 1)  // && strParam1.CompareNoCase(_T(".abc")) == 0)
			{
				m_strCreatingDOCID = strParam2;
				pTemplate->OpenDocumentFile(nullptr);
				return;
			}
		}
	}

	CXobjProxy* CAIGCWinApp::OnXobjInit(IXobj* pNewNode) {
		CComBSTR bstrName("");
		pNewNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pNewNode->get_NameAtWindowPage(&bstrName2);
		return nullptr;
	}

	CNucleusProxy* CAIGCWinApp::OnNucleusCreated(INucleus* pNewFrame) {
		__int64 h = 0;
		pNewFrame->get_HWND(&h);
		CComBSTR bstrName("");
		pNewFrame->get_Name(&bstrName);
		return nullptr;
	}

	CNucleiProxy* CAIGCWinApp::OnNucleiCreated(INuclei* pNuclei) {
		CNucleiProxy* pNucleiProxy = nullptr;
		__int64 h = 0;
		pNuclei->get_Handle(&h);
		if (h) {
			CWnd* pWnd = CWnd::FromHandlePermanent((HWND)h);
			if (pWnd == NULL)
				return NULL;
			if (pNucleiProxy)
				pNucleiProxy->m_bAutoDelete = false;
		}
		return pNucleiProxy;
	}

	CString CAIGCWinApp::GetDocTemplateID(CDocument* pDoc) {
		if (pDoc) {
			POSITION nPos = pDoc->GetFirstViewPosition();
			if (nPos != NULL) {
				CView* pView = pDoc->GetNextView(nPos);
				ASSERT_VALID(pView);
				CFrameWnd* pFrame = pView->GetParentFrame();
				CString s =
					(LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
				return s;
			}
		}
		return _T("");
	}

	bool CAIGCWinApp::AttachWebRT() {
		HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
		if (hModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
		}
		if (g_pSpaceTelescopeImpl)
		{
			HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hModule == nullptr) {
				TCHAR m_szBuffer[MAX_PATH];
				CString _strAIGCAgentPath = _T("");
				::GetModuleFileName(::GetModuleHandle(_T("universe.dll")), m_szBuffer, MAX_PATH);
				_strAIGCAgentPath = CString(m_szBuffer);
				int nPos = _strAIGCAgentPath.ReverseFind('\\');
				_strAIGCAgentPath = _strAIGCAgentPath.Left(nPos + 1) + _T("AIGCAgent.dll");
				if (::PathFileExists(_strAIGCAgentPath)) {
					g_pSpaceTelescopeImpl->m_hWebRTProxyModel = ::LoadLibrary(_strAIGCAgentPath);
					{
						if (!afxContextIsDLL) {
							DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
							DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
						}
						if (m_strContainer != _T("")) {
							m_strContainer = _T(",") + m_strContainer + _T(",");
							m_strContainer.Replace(_T(",,"), _T(","));
						}

						if (g_pSpaceTelescopeImpl->m_pWebRTDelegate == NULL) {
							m_strProviderID += _T("host");
							m_strProviderID.MakeLower();

							g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
							g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
								static_cast<IUniverseAppProxy*>(this));
							g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
								static_cast<IWindowProvider*>(this));
							if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CDialog))) {
								::SendMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, (WPARAM)m_pMainWnd->m_hWnd, 20240416);
								::PostMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, 0, 20240220);
								return true;
							}
							if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
								g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
								::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
									(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
									g_pSpaceTelescopeImpl->m_nAppType);
							g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
							m_bBuiltInBrowser = true;

							CCommandLineInfo cmdInfo;
							ParseCommandLine(cmdInfo);
							m_nShellCmd = cmdInfo.m_nShellCommand;
							if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
								WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
								HANDLE hHandle = ::GetProp(m_pMainWnd->m_hWnd, _T("WebRTFrameWndInfo"));
								if (hHandle == 0)
								{
									pWebRTFrameWndInfo = g_pSpaceTelescopeImpl->InsertWebRTFrameWndInfo(m_hMainWnd);
									hHandle = pWebRTFrameWndInfo;
								}
								else
								{
									pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
								}

								if (pWebRTFrameWndInfo) {
									if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
									{
										POSITION nPos = GetFirstDocTemplatePosition();
										while (nPos) {
											CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
											POSITION pos = pTemplate->GetFirstDocPosition();
											while (pos != NULL) {
												CDocument* pDoc = pTemplate->GetNextDoc(pos);
												POSITION pos2 = pDoc->GetFirstViewPosition();
												while (pos2 != NULL) {
													CView* pView = pDoc->GetNextView(pos2);
													ASSERT_VALID(pView);
													if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
														if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate))) {
															pWebRTFrameWndInfo->m_nFrameType = 2;
														}
													}
													else
													{
														CFrameWnd* pFrame = pView->GetParentFrame();
														if (m_pMainWnd == pFrame) {
															g_pSpaceTelescopeImpl->m_hFirstView = pView->m_hWnd;
															if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
																pWebRTFrameWndInfo->m_nFrameType = 1;
															else
																pWebRTFrameWndInfo->m_nFrameType = 4;
														}
													}
												}
											}
										}
										CFrameWnd* pFrame = (CFrameWnd*)m_pMainWnd;
										if (pFrame) {
											if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
												pWebRTFrameWndInfo->m_nFrameType = 2;
												pWebRTFrameWndInfo->m_hClient = ((CMDIFrameWnd*)pFrame)->m_hWndMDIClient;
												POSITION nPos = GetFirstDocTemplatePosition();
												while (nPos) {
													CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
													POSITION pos = pTemplate->GetFirstDocPosition();
													CDocument* pDoc = pTemplate->GetNextDoc(pos);
													POSITION pos2 = pDoc->GetFirstViewPosition();
													while (pos2 != NULL) {
														CView* pView = pDoc->GetNextView(pos2);
														ASSERT_VALID(pView);
														g_pSpaceTelescopeImpl->AttachMDIChild(m_hMainWnd, pView->GetParentFrame()->m_hWnd, pView->m_hWnd);
													}
												}
											}
											else {
												if (pWebRTFrameWndInfo->m_pDoc == NULL) {
													CDocument* m_pDoc = pFrame->GetActiveDocument();
													if (m_pDoc) {
														pWebRTFrameWndInfo->m_hClient = pFrame->GetActiveView()->m_hWnd;
														pWebRTFrameWndInfo->m_pDoc = m_pDoc;
														CDocTemplate* pTemplate = m_pDoc->GetDocTemplate();
														pWebRTFrameWndInfo->m_pDocTemplate = pTemplate;
														pWebRTFrameWndInfo->m_nFrameType = pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)) ? 1 : 4;
													}
												}
											}
										}
									}
								}
							}
							//else if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CDialog)))
							//{
							//	::SendMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, (WPARAM)m_pMainWnd->m_hWnd, 20240416);
							//}
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	bool CAIGCWinApp::ProcessAppType(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
			(::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
		if (bWin32)
			return true;
		if (g_pSpaceTelescopeImpl) {
			switch (g_pSpaceTelescopeImpl->m_nAppType) {
			case APP_WIN32:
				return true;
				break;
			case APP_BROWSER:
			case APP_BROWSER_ECLIPSE: {
				if (g_pSpaceTelescopeImpl->m_nAppType == APP_BROWSER_ECLIPSE) {
#ifdef _AFXDLL
#ifdef _DEBUG
					::MessageBox(NULL,
						_T("Chrome-Eclipse Model is not support MFC Share Dll"),
						_T("Warnning"), MB_OK);
#endif
					TRACE(
						_T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support ")
						_T("MFC Share Dll********\r\n\r\n"));
#endif
				}
				g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
				HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
				if (hModule == nullptr)
					hModule = ::LoadLibrary(L"AIGCAgent.dll");
				if (hModule == nullptr) {
					TCHAR m_szBuffer[MAX_PATH];
					if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
						m_szBuffer) == S_OK) {
						CString strChromeRTFilePath = CString(m_szBuffer);
						strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
						if (::PathFileExists(strChromeRTFilePath)) {
							hModule = ::LoadLibrary(strChromeRTFilePath);
						}
					}
					if (hModule == nullptr)
						hModule = ::LoadLibrary(L"AIGCAgent.dll");
				}
				if (hModule) {
					typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
					_InitApp _pInitAppFunction;
					_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
					if (_pInitAppFunction != NULL) {
						m_bBuiltInBrowser = true;
						_pInitAppFunction(bCrashReporting, g_pSpaceTelescopeImpl->m_pWebRTDelegate);
						return false;
					}
				}
			} break;
			case APP_ECLIPSE:
				if (g_pWebRT && !g_pSpaceTelescopeImpl->m_bIsEclipseInit) {
					g_pWebRT->InitEclipseApp();
					return false;
				}
				break;
			}
		}
		return true;
	}

	BOOL CAIGCWinApp::IsBrowserModel(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
			(::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
		if (bWin32 == false) {
			HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hModule == nullptr)
				hModule = ::LoadLibrary(g_strChromeRTFilePath);
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"AIGCAgent.dll");
			if (hModule) {
				m_bCrashReporting = bCrashReporting;
				FuncIsBrowserModel =
					(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
				if (FuncIsBrowserModel != NULL) {
					return FuncIsBrowserModel(bCrashReporting, this);
				}
			}
		}

		return false;
	};

	CComponentApp::CComponentApp()
	{
		g_pAppBase = this;
	}

	CComponentApp::~CComponentApp()
	{
	}

	bool CComponentApp::WebRTInit(CString strID)
	{
		HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));;
		if (hModule)
		{
			if (m_strContainer != _T(""))
			{
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pHubbleImplFunction;
			_pHubbleImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pHubbleImplFunction(&g_pWebRT);
			if (g_pSpaceTelescopeImpl->m_nAppType == APP_BROWSER_ECLIPSE)
			{
#ifdef _AFXDLL
#ifdef _DEBUG
				::MessageBox(NULL, _T("Chrome-Eclipse Model is not support MFC Share Dll"), _T("Warnning"), MB_OK);
#endif 
				TRACE(_T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support MFC Share Dll********\r\n\r\n"));
#endif
			}
			m_strProviderID = g_pAppBase->m_pszAppName;
			m_strProviderID.MakeLower();
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, static_cast<IWindowProvider*>(this));
		}
		return true;
	}

	CString CComponentApp::GetNames()
	{
		if (m_mapDOMObj.size())
		{
			CString strNames = _T("");
			for (auto it = m_mapDOMObj.begin(); it != m_mapDOMObj.end(); it++)
			{
				strNames += it->first;
				strNames += _T(",");
			}
			return strNames.MakeLower();
		}
		return _T("");
	}

	CString CComponentApp::GetTags(CString strName)
	{
		strName.Trim().MakeLower();
		if (strName != _T(""))
		{
			auto it = m_mapDOMObjStyle.find(strName);
			if (it != m_mapDOMObjStyle.end())
			{
				return it->second;
			}
		}
		return _T("");
	}

	BOOL CComponentApp::InitInstance()
	{
		WebRTInit(_T(""));
		return CWinApp::InitInstance();
	}

	int CComponentApp::ExitInstance()
	{
		return CWinApp::ExitInstance();
	}

	HWND CComponentApp::Create(HWND hParentWnd, IXobj* pGrid)
	{
		CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
		if (pParent == nullptr)
		{
			pParent = new CTangramHelperWnd();
			if (!pParent->SubclassWindow(hParentWnd))
			{
				TRACE(_T("\n**********************Error**********************\n"));
				return NULL;
			}
		}
		USES_CONVERSION;
		BSTR bstrTag = ::SysAllocString(L"");
		pGrid->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T(""))
		{
			auto it = m_mapDOMObj.find(m_strTag);
			if (it != m_mapDOMObj.end())
			{
				CRuntimeClass* pCls = (CRuntimeClass*)it->second;
				CWnd* pWnd = (CWnd*)pCls->CreateObject();
				if (pWnd)
				{
					if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView)))
					{
						AfxSetResourceHandle(CWinApp::m_hInstance);
					}
					pGrid->get_Attribute(CComBSTR("style"), &bstrTag);
					CString strStyle = OLE2T(bstrTag);
					strStyle.Trim();
					if (strStyle == _T(""))
					{
						::SysFreeString(bstrTag);
						pGrid->get_Attribute(CComBSTR("tabstyle"), &bstrTag);
						strStyle = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						strStyle.Trim();
					}
					if (pWnd->Create(nullptr, strStyle, WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), pParent, 0, nullptr))
					{
						::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, (WPARAM)pGrid, 20191031);
						pGrid->get_Attribute(CComBSTR("activepage"), &bstrTag);
						long nCount = 0;
						pGrid->get_Cols(&nCount);
						CString m_strTag = OLE2T(bstrTag);
						::SysFreeString(bstrTag);
						int nActivePage = _wtoi(m_strTag);
						if (nCount)
							nActivePage = nActivePage % nCount;
						::PostMessage(pWnd->m_hWnd, WM_TABCHANGE, nActivePage, 0);
						return pWnd->m_hWnd;
					}
				}
			}
		}
		return NULL;
	}

	CAIGCWinAppEx::CAIGCWinAppEx() {
		g_pAppBase = this;
		m_strProviderID = _T("");
		m_nShellCmd = CCommandLineInfo::FileNew;
	}

	CAIGCWinAppEx::~CAIGCWinAppEx() {
		if (g_pSpaceTelescopeImpl) {
			g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	BOOL CAIGCWinAppEx::InitApplication() {
		if (WebRTInit(_T("")) ? CWinAppEx::InitApplication() : false)
			return ProcessAppType(m_bCrashReporting);
		else
			return false;
	}

	HWND CAIGCWinAppEx::GetActivePopupMenu(HWND hWnd) {
		CMFCPopupMenu* pActivePopupMenu = CMFCPopupMenu::GetSafeActivePopupMenu();
		if (pActivePopupMenu) {
			ATLTRACE(_T("pActivePopupMenu:%x\n"), pActivePopupMenu->m_hWnd);
			return pActivePopupMenu->m_hWnd;
		}
		return nullptr;
	}

	int CAIGCWinAppEx::Run() {
		return CWinThread::Run();
	}

	CString CAIGCWinAppEx::GetNames() {
		CString strNames = _T("tabctrl,");
		if (m_mapDOMObj.size()) {
			for (auto it = m_mapDOMObj.begin(); it != m_mapDOMObj.end(); it++) {
				strNames += it->first;
				strNames += _T(",");
			}
			return strNames.MakeLower();
		}
		return strNames.MakeLower();
	}

	CString CAIGCWinAppEx::GetTags(CString strName) {
		CString strNameBase = _T("0,1,2,3,4,5,6,7,");
		strName.Trim().MakeLower();
		if (strName != _T("")) {
			auto it = m_mapDOMObjStyle.find(strName);
			if (it != m_mapDOMObjStyle.end()) {
				strNameBase += it->second;
				strNameBase += _T(",");
				return strNameBase;
			}
		}
		return strNameBase;
	}

	HWND CAIGCWinAppEx::Create(HWND hParentWnd, IXobj* pXobj) {
		CWnd* pParent = CWnd::FromHandlePermanent(hParentWnd);
		if (pParent == nullptr) {
			pParent = new CTangramHelperWnd();
			if (!pParent->SubclassWindow(hParentWnd)) {
				TRACE(_T("\n**********************Error**********************\n"));
				return NULL;
			}
		}
		USES_CONVERSION;
		BSTR bstrTag = ::SysAllocString(L"");

		pXobj->get_Attribute(CComBSTR("xobjtype"), &bstrTag);
		CString m_strTag = OLE2T(bstrTag);
		::SysFreeString(bstrTag);
		m_strTag.Trim().MakeLower();
		if (m_strTag != _T("")) {
			auto it = m_mapDOMObj.find(m_strTag);
			if (it != m_mapDOMObj.end()) {
				CRuntimeClass* pCls = (CRuntimeClass*)it->second;
				CWnd* pWnd = (CWnd*)pCls->CreateObject();
				if (pWnd) {
					if (pCls->IsDerivedFrom(RUNTIME_CLASS(CFormView))) {
						AfxSetResourceHandle(AfxGetApp()->m_hInstance);
					}
					if (pWnd->Create(nullptr, _T(""), WS_CHILD | WS_VISIBLE,
						CRect(0, 0, 0, 0), pParent, 0, nullptr)) {
						::PostMessage(pWnd->m_hWnd, WM_COSMOSMSG, (WPARAM)pXobj, 20191031);
						if (pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
							CView* pView = static_cast<CView*>(pWnd);
							CFrameWnd* pFrame = pView->GetParentFrame();
							WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
							if (pFrame) {
								pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
									pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
								if (pWebRTFrameWndInfo) {
									HWND hView = pWebRTFrameWndInfo->m_hClient;
									CWnd* pHostView = CWnd::FromHandlePermanent(hView);
									if (pHostView->IsKindOf(RUNTIME_CLASS(CView))) {
										CView* _pView = (CView*)pHostView;
										CDocument* pDoc = _pView->GetDocument();
										if (pDoc) {
											m_mapViewDoc[pView] = pDoc;
											pWebRTFrameWndInfo->m_pDoc = pDoc;
											pWebRTFrameWndInfo->m_hClient = hView;
											pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
										}
									}
								}
							}
						}
						return pWnd->m_hWnd;
					}
				}
			}
		}
		return NULL;
	}

	bool CAIGCWinAppEx::WebRTInit(CString strID) {
		if (!afxContextIsDLL) {
			CCommandLineInfo cmdInfo;
			ParseCommandLine(cmdInfo);
			m_nShellCmd = cmdInfo.m_nShellCommand;
			switch (m_nShellCmd) {
			case CCommandLineInfo::AppRegister:
			case CCommandLineInfo::AppUnregister:
				return true;
			default:
				break;
			}
			DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
			DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
			GetWebRTInfo();
			if (IsBrowserModel(false)) {
				m_bBuiltInBrowser = true;
				return false;
			}
		}
		HMODULE hAIGCAgentModule = NULL;
		if (::PathFileExists(g_strChromeRTFilePath))
			hAIGCAgentModule = ::LoadLibrary(g_strChromeRTFilePath);
		else
			hAIGCAgentModule = ::LoadLibrary(L"AIGCAgent.dll");
		if (hAIGCAgentModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
				m_szBuffer) == S_OK) {
				g_strChromeRTFilePath = CString(m_szBuffer);
				g_strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
				if (::PathFileExists(g_strChromeRTFilePath)) {
					hAIGCAgentModule = ::LoadLibrary(g_strChromeRTFilePath);
				}
			}
		}
		TCHAR m_szBuffer[MAX_PATH];
		TCHAR szDriver[MAX_PATH] = { 0 };
		TCHAR szDir[MAX_PATH] = { 0 };
		TCHAR szExt[MAX_PATH] = { 0 };
		TCHAR szFile2[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
		_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
		CString strTangramDll = szDriver;
		strTangramDll += szDir;
		strTangramDll += _T("universe.dll");
		HMODULE hUniverseModule = ::LoadLibrary(strTangramDll);
		if (hUniverseModule == NULL && g_strUniverseFilePath != _T(""))
			hUniverseModule = ::LoadLibrary(g_strUniverseFilePath);
		if (hUniverseModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hUniverseModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
			g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hAIGCAgentModule;

			if (!afxContextIsDLL) {
				m_strProviderID += _T("host");
				m_strProviderID.MakeLower();

				g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
				g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
					static_cast<IUniverseAppProxy*>(this));
				g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
					static_cast<IWindowProvider*>(this));
				if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
					g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
					::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
						(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
						g_pSpaceTelescopeImpl->m_nAppType);
				g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			}
			else {
				strID.Trim();
				if (strID == _T(""))
					strID = _T("component");
				if (m_strProviderID == _T("")) {
					CString strName = AfxGetApp()->m_pszAppName;
					m_strProviderID = strName + _T(".") + strID;
				}
				if (m_strProviderID != _T("")) {
					m_strProviderID.MakeLower();
					g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
						static_cast<IUniverseAppProxy*>(this));
					g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
						static_cast<IWindowProvider*>(this));
				}
				g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			}
		}
		if (hUniverseModule == NULL || hAIGCAgentModule == NULL) {
			g_hCBTHook = SetWindowsHookEx(WH_CBT, WebRTCBTProc, NULL, ::GetCurrentThreadId());
		}
		return true;
	}

	CString CAIGCWinAppEx::QueryDocType(HWND hWnd) {
		CWnd* pWnd = CWnd::FromHandle(hWnd);
		CFrameWnd* pFrame = pWnd->GetParentFrame();
		if (pFrame) {
			CString strType =
				(LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
			if (strType == _T("") && pFrame == m_pMainWnd &&
				pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
				strType = _T("mdiframe");
			}
			if (strType == _T("") && pFrame == m_pMainWnd &&
				pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd))) {
				strType = _T("miniframe");
			}
			return strType;
		}
		return _T("");
	}

	CString CAIGCWinAppEx::QueryWndClassName(HWND hWnd) {
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		if (pWnd) {
			CRuntimeClass* pClassInfo = pWnd->GetRuntimeClass();
			if (pClassInfo) {
				return CString(pClassInfo->m_lpszClassName);
			}
		}
		return _T("");
	}

	HWND CAIGCWinAppEx::GetFrameWnd(HWND hWnd, int& nType) {
		CWnd* pWnd = CWnd::FromHandle(hWnd);
		if (pWnd) {
			CFrameWnd* pFrame = pWnd->GetParentFrame();
			if (pFrame) {
				if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
					nType = 1;
				else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
					nType = 2;
				else if (pFrame->IsKindOf(RUNTIME_CLASS(CMiniFrameWnd)))
					nType = 4;
				else
					nType = 3;
				return pFrame->m_hWnd;
			}
		}
		return NULL;
	}

	void CAIGCWinAppEx::AttachCDockablePane(CDockablePane* pDockablePane, WebRTFrameWndInfo* pWebRTFrameWndInfo)
	{
		if (pDockablePane->IsKindOf(RUNTIME_CLASS(CTabbedPane)))
		{
			CTabbedPane* pTabbedPane = (CTabbedPane*)pDockablePane;
			POSITION pos = NULL;
			CObList _list;
			pTabbedPane->GetPaneList(_list);
			for (pos = _list.GetHeadPosition(); pos != NULL;) {
				CBasePane* _pBar = (CBasePane*)_list.GetNext(pos);
				if (_pBar->IsKindOf(RUNTIME_CLASS(CTabbedPane)))
				{
					CDockablePane* pDockablePane = (CDockablePane*)_pBar;
					AttachCDockablePane(pDockablePane, pWebRTFrameWndInfo);
				}
				else
					g_pSpaceTelescopeImpl->AttachControlBar(pWebRTFrameWndInfo, _pBar->m_hWnd);
			}
		}
	}

	HWND CAIGCWinAppEx::QueryWndInfo(QueryType nType, HWND hWnd) {
		if (hWnd == NULL && m_pMainWnd) {
			if (g_pSpaceTelescopeImpl == NULL) {
				HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
				if (hModule) {
					GetWebRTImpl _pWebRTImplFunction;
					_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
					g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
				}
			}
			if (m_pDockingManager == NULL) {
				m_hMainWnd = m_pMainWnd->m_hWnd;
				CCommandLineInfo cmdInfo;
				ParseCommandLine(cmdInfo);
				m_nShellCmd = cmdInfo.m_nShellCommand;
				if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
					WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
					HANDLE hHandle = ::GetProp(m_pMainWnd->m_hWnd, _T("WebRTFrameWndInfo"));
					if (hHandle == 0)
					{
						pWebRTFrameWndInfo = g_pSpaceTelescopeImpl->InsertWebRTFrameWndInfo(m_hMainWnd);
						hHandle = pWebRTFrameWndInfo;
					}
					else
					{
						pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;

					}
					m_pDockingManager = GetDockingManager(m_pMainWnd);
					if (m_pDockingManager) {
						if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
							CMDIFrameWnd* pMDIFrame = (CMDIFrameWnd*)m_pMainWnd;
							m_pMDIClientAreaWnd = CWnd::FromHandlePermanent(pMDIFrame->m_hWndMDIClient);
							m_pvoid = m_pMDIClientAreaWnd;
						}
						POSITION pos = NULL;
						CObList list;
						m_pDockingManager->GetPaneList(list, TRUE);
						for (pos = list.GetHeadPosition(); pos != NULL;)
						{
							CBasePane* pBar = (CBasePane*)list.GetNext(pos);
							ASSERT_VALID(pBar);
							if (pBar->IsKindOf(RUNTIME_CLASS(CDockablePane)))
							{
								CDockablePane* pDockablePane = (CDockablePane*)pBar;

								if (pBar->IsKindOf(RUNTIME_CLASS(CTabbedPane)))
									AttachCDockablePane(pDockablePane, pWebRTFrameWndInfo);
								else
									g_pSpaceTelescopeImpl->AttachControlBar(pWebRTFrameWndInfo, pBar->m_hWnd);
							}
						}
					}

					if (pWebRTFrameWndInfo) {
						if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
						{
							POSITION nPos = GetFirstDocTemplatePosition();
							while (nPos) {
								CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
								POSITION pos = pTemplate->GetFirstDocPosition();
								while (pos != NULL) {
									CDocument* pDoc = pTemplate->GetNextDoc(pos);
									POSITION pos2 = pDoc->GetFirstViewPosition();
									while (pos2 != NULL) {
										CView* pView = pDoc->GetNextView(pos2);
										ASSERT_VALID(pView);
										if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
											if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate))) {
												pWebRTFrameWndInfo->m_nFrameType = 2;
											}
										}
										else
										{
											CFrameWnd* pFrame = pView->GetParentFrame();
											if (m_pMainWnd == pFrame) {
												g_pSpaceTelescopeImpl->m_hFirstView = pView->m_hWnd;
												if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
													pWebRTFrameWndInfo->m_nFrameType = 1;
												else
													pWebRTFrameWndInfo->m_nFrameType = 4;
											}
										}
									}
								}
							}
							CFrameWnd* pFrame = (CFrameWnd*)m_pMainWnd;
							if (pFrame) {
								if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
									pWebRTFrameWndInfo->m_nFrameType = 2;
									pWebRTFrameWndInfo->m_hClient = ((CMDIFrameWnd*)pFrame)->m_hWndMDIClient;
									POSITION nPos = GetFirstDocTemplatePosition();
									while (nPos) {
										CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
										POSITION pos = pTemplate->GetFirstDocPosition();
										CDocument* pDoc = pTemplate->GetNextDoc(pos);
										POSITION pos2 = pDoc->GetFirstViewPosition();
										while (pos2 != NULL) {
											CView* pView = pDoc->GetNextView(pos2);
											ASSERT_VALID(pView);
											g_pSpaceTelescopeImpl->AttachMDIChild(m_hMainWnd, pView->GetParentFrame()->m_hWnd, pView->m_hWnd);
										}
									}
								}
								else {
									if (pWebRTFrameWndInfo->m_pDoc == NULL) {
										CDocument* m_pDoc = pFrame->GetActiveDocument();
										if (m_pDoc) {
											pWebRTFrameWndInfo->m_hClient = pFrame->GetActiveView()->m_hWnd;
											pWebRTFrameWndInfo->m_pDoc = m_pDoc;
											CDocTemplate* pTemplate = m_pDoc->GetDocTemplate();
											pWebRTFrameWndInfo->m_pDocTemplate = pTemplate;
											pWebRTFrameWndInfo->m_nFrameType = pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)) ? 1 : 4;
										}
									}
								}
							}
						}
					}
				}
			}
			return m_hMainWnd;
		}
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		switch (nType) {
		case MainWnd:
			if (m_pMainWnd) {
				if (m_hMainWnd == NULL)
					m_hMainWnd = g_pSpaceTelescopeImpl->m_hMainWnd;
				if (!m_pDockingManager) {
					m_pDockingManager = GetDockingManager(m_pMainWnd);
					if (m_pDockingManager) {
						if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
							CMDIFrameWnd* pMDIFrame = (CMDIFrameWnd*)m_pMainWnd;
							m_pMDIClientAreaWnd = CWnd::FromHandlePermanent(pMDIFrame->m_hWndMDIClient);
						}
					}
				}
				WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
				HANDLE hHandle = ::GetProp(m_pMainWnd->m_hWnd, _T("WebRTFrameWndInfo"));
				if (hHandle) {
					pWebRTFrameWndInfo = (WebRTFrameWndInfo*)hHandle;
					if (m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd))) {
						pWebRTFrameWndInfo->m_nFrameType = 2;
					}
					else {
						POSITION nPos = GetFirstDocTemplatePosition();
						while (nPos) {
							CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
							POSITION pos = pTemplate->GetFirstDocPosition();
							while (pos != NULL) {
								CDocument* pDoc = pTemplate->GetNextDoc(pos);
								POSITION pos2 = pDoc->GetFirstViewPosition();
								while (pos2 != NULL) {
									CView* pView = pDoc->GetNextView(pos2);
									ASSERT_VALID(pView);
									CFrameWnd* pFrame = pView->GetParentFrame();
									if (m_pMainWnd == pFrame) {
										if (pTemplate->IsKindOf(
											RUNTIME_CLASS(CMultiDocTemplate))) {
											if (!pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
												pWebRTFrameWndInfo->m_nFrameType = 1;
											return m_pMainWnd->m_hWnd;
										}
										break;
									}
								}
							}
						}
					}
				}
				return m_pMainWnd->m_hWnd;
			}
			break;
		case CanClose: {
			if (pWnd) {
				if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
					CFrameWnd* _pFrame = (CFrameWnd*)pWnd;
					POSITION nPos = GetFirstDocTemplatePosition();
					while (nPos) {
						CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
						POSITION pos = pTemplate->GetFirstDocPosition();
						while (pos != NULL) {
							CDocument* pDoc = pTemplate->GetNextDoc(pos);
							POSITION pos2 = pDoc->GetFirstViewPosition();
							while (pos2 != NULL) {
								CView* pView = pDoc->GetNextView(pos2);
								ASSERT_VALID(pView);
								CFrameWnd* pFrame = pView->GetParentFrame();
								if (_pFrame == pFrame) {
									if (pDoc->CanCloseFrame(pFrame)) {
										return pFrame->m_hWnd;
									}
									else
										return NULL;
								}
							}
						}
					}
				}
			}
			// if (pWnd)// && pWnd == m_pMainWnd)
			//{
			//	POSITION nPos = GetFirstDocTemplatePosition();
			//	while (nPos)
			//	{
			//		CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
			//		POSITION pos = pTemplate->GetFirstDocPosition();
			//		while (pos != NULL)
			//		{
			//			CDocument* pDoc = pTemplate->GetNextDoc(pos);
			//			POSITION pos2 = pDoc->GetFirstViewPosition();
			//			while (pos2 != NULL)
			//			{
			//				CView* pView = pDoc->GetNextView(pos2);
			//				ASSERT_VALID(pView);
			//				CFrameWnd* pFrame =
			// pView->GetParentFrame(); 				if (m_pMainWnd !=
			// pFrame)
			//				{
			//					//pDoc->CanCloseFrame(pFrame);
			//					m_pMainWnd = pFrame;
			//					g_pSpaceTelescopeImpl->m_hMainWnd =
			// m_pMainWnd->m_hWnd; 					return
			// pFrame->m_hWnd;
			//				}
			//			}
			//		}
			//	}
			// }
			return NULL;
		} break;
		case DocView: {
			if (pWnd && pWnd->IsKindOf(RUNTIME_CLASS(CView))) {
				CView* pView = static_cast<CView*>(pWnd);
				WebRTFrameWndInfo* pWebRTFrameWndInfo = nullptr;
				CDocument* pDoc = pView->GetDocument();
				if (pDoc) {
					HWND hRetFrame = NULL;
					CDocTemplate* pTemplate = pDoc->GetDocTemplate();
					CFrameWnd* pFrame = pView->GetParentFrame();
					if (pFrame) {
						hRetFrame = pFrame->m_hWnd;
						CString strInfo = m_strCreatingDOCID;
						if (strInfo == _T(""))
							strInfo = _T("default");
						CRuntimeClass* pClsInfo = pView->GetRuntimeClass();
						CString strName = CString(pClsInfo->m_lpszClassName);
						auto it = m_mapDOMObj.find(strName);
						if (it == m_mapDOMObj.end())
							m_mapDOMObj[strName] = pClsInfo;
						bool bRet = g_pSpaceTelescopeImpl->SetFrameInfo(hWnd, hRetFrame, strInfo,
							pDoc, pTemplate);
						//if (pWnd->IsKindOf(RUNTIME_CLASS(CFormView)) &&
						//    ::GetParent(hWnd) == hRetFrame)
						//  ((CFormView*)pWnd)->ResizeParentToFit();

						pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
							hRetFrame, _T("WebRTFrameWndInfo"));
						if (pWebRTFrameWndInfo == nullptr) {
							__int64 nType = 0;
							if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
								nType = 2;
							else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd)))
								nType = 3;
							else if (pTemplate->IsKindOf(RUNTIME_CLASS(CMultiDocTemplate)))
								nType = 1;
							::SetProp(hRetFrame, _T("CosmosFrameWndType"), (HANDLE)nType);
						}
						else {
							pWebRTFrameWndInfo->m_hClient = hWnd;
							if (pWebRTFrameWndInfo->m_pDoc == nullptr && pDoc) {
								pWebRTFrameWndInfo->m_pDoc = pDoc;
								pWebRTFrameWndInfo->m_pDocTemplate = pDoc->GetDocTemplate();
							}
							if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
								pWebRTFrameWndInfo->m_nFrameType = 2;
							else if (pFrame->IsKindOf(RUNTIME_CLASS(CMDIChildWnd))) {
								pWebRTFrameWndInfo->m_nFrameType = 3;
							}
							else if (pTemplate->IsKindOf(
								RUNTIME_CLASS(CMultiDocTemplate))) {
								pWebRTFrameWndInfo->m_nFrameType = 1;
							}
							else if (pFrame->IsKindOf(RUNTIME_CLASS(CFrameWnd)))
								pWebRTFrameWndInfo->m_nFrameType = 4;
						}
					}
					return hRetFrame;
				}
			}
		} break;
		case QueryDestroy: {
			if (::IsWindow(hWnd))
			{
				m_pMainWnd = pWnd;
				return pWnd->m_hWnd;
			}
		} break;
		case ObserveComplete: {
			for (auto& it : m_mapViewDoc) {
				it.second->AddView(it.first);
			}
			m_mapViewDoc.erase(m_mapViewDoc.begin(), m_mapViewDoc.end());
		} break;
		case RecalcLayout: {
			CFrameWnd* pFrame = pWnd->GetParentFrame();
			if (pFrame) {
				pFrame->RecalcLayout();
				return pFrame->m_hWnd;
			}
			else {
				pWnd = CWnd::FromHandlePermanent(hWnd);
				if (pWnd && pWnd->IsFrameWnd()) {
					pFrame = (CFrameWnd*)pWnd;
					pFrame->RecalcLayout();
					return pFrame->m_hWnd;
				}
			}
		} break;
		case SetMainWndNULL: {
			if (g_pSpaceTelescopeImpl->m_hMainWnd) {
				m_pMainWnd = nullptr;
			}
		} break;
		}
		return NULL;
	}

	bool CAIGCWinAppEx::SetFrameCaption(HWND hWnd,
		CString strCaption,
		CString strAppName) {
		if (strCaption == _T("") || !::IsWindow(hWnd))
			return false;
		CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
		CFrameWnd* pFrame = nullptr;
		if (pWnd) {
			if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
				pFrame = (CFrameWnd*)pWnd;
			}
			else {
				pFrame = pWnd->GetParentFrame();
			}
			if (pFrame) {
				WebRTFrameWndInfo* pWebRTFrameWndInfo = (WebRTFrameWndInfo*)::GetProp(
					pFrame->m_hWnd, _T("WebRTFrameWndInfo"));
				if (pWebRTFrameWndInfo) {
					CDocument* pDoc = (CDocument*)pWebRTFrameWndInfo->m_pDoc;
					if (pDoc) {
						CString strPath = pDoc->GetPathName();
						if (strPath == _T("")) {
							CString strTitle = pDoc->GetTitle();
							CDocTemplate* pTemplate =
								(CDocTemplate*)pWebRTFrameWndInfo->m_pDocTemplate;
							CString name = _T("");
							pTemplate->GetDocString(name, CDocTemplate::docName);
							strTitle.Replace(name, strCaption);
							pDoc->SetTitle(strTitle);
							switch (pWebRTFrameWndInfo->m_nFrameType) {
							case 1:
							case 4:
								::SetWindowText(pFrame->m_hWnd, strTitle + _T(" - ") +
									strAppName + _T(" - ") +
									g_pSpaceTelescopeImpl->m_strAppName);
								break;
							default:
								::SetWindowText(pFrame->m_hWnd, strTitle);
								break;
							}
						}
						return true;
					}
				}
			}
		}
		else {
			pWnd = CWnd::FromHandle(hWnd);
			if (pWnd)
				pFrame = pWnd->GetParentFrame();
		}
		if (pFrame) {
			CString strText = _T("");
			pFrame->GetWindowText(strText);
			CString strTitle = pFrame->GetTitle();
			int nPos = strText.ReverseFind('-');
			if (nPos != -1) {
				CString s1 = strText.Left(nPos + 1);
				s1 += _T(" ");
				s1 += strCaption;
				::SetWindowText(pFrame->m_hWnd, s1);
				pFrame->SetTitle(strCaption);
				return true;
			}
			else {
				pFrame->SetTitle(strCaption);
				::SetWindowText(pFrame->m_hWnd, strCaption);
			}
			return true;
		}

		return false;
	}

	CString CAIGCWinAppEx::QueryParentInfo(HWND hPWnd, void* lpInfo) {
		CWnd* pParent = CWnd::FromHandlePermanent(hPWnd);
		if (pParent) {
			CFrameWnd* pParentFrame = nullptr;
			if (pParent->IsKindOf(RUNTIME_CLASS(CFrameWnd))) {
				if (pParent->IsKindOf(RUNTIME_CLASS(CMDIFrameWnd)))
					return _T("");
				pParentFrame = (CFrameWnd*)pParent;
			}
			else
				pParentFrame = pParent->GetParentFrame();
			if (pParentFrame) {
				CCreateContext* pContext = (CCreateContext*)lpInfo;
				CDocument* pDoc = pContext->m_pCurrentDoc;
				CDocTemplate* pTemplate = pContext->m_pNewDocTemplate;
				CString strExt = _T("");
				pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
				strExt.MakeLower();
				if (strExt == _T(""))
					strExt = _T("default");
				return strExt;
			}
		}
		return _T("");
	}

	void CAIGCWinAppEx::OpenDocFile(CString strFileName,
		CString strExt,
		CString strCreatingDOCID) {
		POSITION nPos = GetFirstDocTemplatePosition();
		while (nPos) {
			CDocTemplate* pTemplate = GetNextDocTemplate(nPos);
			if (strExt == _T("")) {
				if (pTemplate) {
					m_strCreatingDOCID = strCreatingDOCID;
					if (m_bNoDefaultMainWnd)
						pTemplate->OpenDocumentFile(NULL);
					return;
				}
			}
			CString _strExt = _T("");
			pTemplate->GetDocString(_strExt, CDocTemplate::filterExt);
			_strExt.MakeLower();
			if (_strExt == _T(""))
				_strExt = _T("default");
			if (strExt != _T("") && strExt.CompareNoCase(strExt) == 0) {
				m_strCreatingDOCID = strCreatingDOCID;
				pTemplate->OpenDocumentFile(strFileName == _T("") ? NULL
					: LPCTSTR(strFileName));
				return;
			}
		}
	}

	BOOL CAIGCWinAppEx::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
	{
		BOOL bCmdProcess = (nCode == 0 && pExtra == NULL && pHandlerInfo == NULL && g_pSpaceTelescopeImpl && ::IsWindow(g_pSpaceTelescopeImpl->m_hCosmosWnd));
		if (bCmdProcess)
		{
			//HWND hActiveWnd = ::GetActiveWindow();
			bCmdProcess = true;
			::SendMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, 0, 20240409);
			switch (nID) {
			case ID_FILE_OPEN:
			case ID_FILE_NEW:
			case ID_FILE_NEW_FRAME:
				AfxSetResourceHandle(m_hInstance);
				break;
			default:
				break;
			}
		}

		BOOL bRet = CWinAppEx::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
		if (bCmdProcess)
		{
			::PostMessage(g_pSpaceTelescopeImpl->m_hCosmosWnd, WM_COSMOSMSG, 1, 20240409);
		}
		return bRet;
	}

	void CAIGCWinAppEx::OnIPCMsg(CWebViewImpl* pWebViewImpl,
		CString strType,
		CString strParam1,
		CString strParam2,
		CString strParam3,
		CString strParam4,
		CString strParam5) {
		if (strType.CompareNoCase(_T("COSMOS_CREATE_DOC")) == 0) {
			AfxSetResourceHandle(m_hInstance);
			int nCount = 0;
			m_strCreatingDOCID = _T("");
			CDocTemplate* pTemplate = nullptr;
			POSITION nPos = GetFirstDocTemplatePosition();
			while (nPos) {
				nCount++;
				pTemplate = GetNextDocTemplate(nPos);
				CString strExt = _T("");
				pTemplate->GetDocString(strExt, CDocTemplate::filterExt);
				strExt.MakeLower();
				if (strExt == _T(""))
					strExt = _T("default");
				if (strExt != _T("") && strExt.CompareNoCase(strParam1) == 0) {
					m_strCreatingDOCID = strParam2;
					pTemplate->OpenDocumentFile(nullptr);
					return;
				}
			}
			if (pTemplate && m_strCreatingDOCID == _T("") &&
				nCount == 1)  //&& strParam1.CompareNoCase(_T(".abc")) == 0)
			{
				m_strCreatingDOCID = strParam2;
				pTemplate->OpenDocumentFile(nullptr);
				return;
			}
		}
	}

	CXobjProxy* CAIGCWinAppEx::OnXobjInit(IXobj* pNewNode) {
		CComBSTR bstrName("");
		pNewNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pNewNode->get_NameAtWindowPage(&bstrName2);
		return nullptr;
	}

	CNucleusProxy* CAIGCWinAppEx::OnNucleusCreated(INucleus* pNewFrame) {
		__int64 h = 0;
		pNewFrame->get_HWND(&h);
		CComBSTR bstrName("");
		pNewFrame->get_Name(&bstrName);
		return nullptr;
	}

	CNucleiProxy* CAIGCWinAppEx::OnNucleiCreated(INuclei* pNuclei) {
		CNucleiProxy* pNucleiProxy = nullptr;
		__int64 h = 0;
		pNuclei->get_Handle(&h);
		if (h) {
			CWnd* pWnd = CWnd::FromHandlePermanent((HWND)h);
			if (pWnd == NULL)
				return NULL;
			//if (pWnd->IsKindOf(RUNTIME_CLASS(CWebRTMDIFrame))) {
			//	pNucleiProxy = (CNucleiProxy*)(CWebRTMDIFrame*)pWnd;
			//}
			if (pNucleiProxy)
				pNucleiProxy->m_bAutoDelete = false;
		}
		return pNucleiProxy;
	}

	CString CAIGCWinAppEx::GetDocTemplateID(CDocument* pDoc) {
		if (pDoc) {
			POSITION nPos = pDoc->GetFirstViewPosition();
			if (nPos != NULL) {
				CView* pView = pDoc->GetNextView(nPos);
				ASSERT_VALID(pView);
				CFrameWnd* pFrame = pView->GetParentFrame();
				CString s =
					(LPCTSTR)::SendMessage(pFrame->m_hWnd, WM_COSMOSMSG, 0, 10000);
				return s;
			}
		}
		return _T("");
	}

	bool CAIGCWinAppEx::AttachWebRT() {
		HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
		if (hModule) {
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
		}
		if (g_pSpaceTelescopeImpl)
		{
			HMODULE hAIGCAgentModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hAIGCAgentModule == nullptr) {
				TCHAR m_szBuffer[MAX_PATH];
				CString _strAIGCAgentPath = _T("");
				::GetModuleFileName(hModule, m_szBuffer, MAX_PATH);
				_strAIGCAgentPath = CString(m_szBuffer);
				int nPos = _strAIGCAgentPath.ReverseFind('\\');
				_strAIGCAgentPath = _strAIGCAgentPath.Left(nPos + 1) + _T("AIGCAgent.dll");
				if (::PathFileExists(_strAIGCAgentPath)) {
					g_pSpaceTelescopeImpl->m_hWebRTProxyModel = ::LoadLibrary(_strAIGCAgentPath);
					{
						DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
						DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
						g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
						if (m_strContainer != _T("")) {
							m_strContainer = _T(",") + m_strContainer + _T(",");
							m_strContainer.Replace(_T(",,"), _T(","));
						}
						m_strProviderID += _T("host");
						m_strProviderID.MakeLower();

						g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
							static_cast<IUniverseAppProxy*>(this));
						g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
							static_cast<IWindowProvider*>(this));
						if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
							g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
							::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
								(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
								g_pSpaceTelescopeImpl->m_nAppType);
						g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
						m_bBuiltInBrowser = true;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool CAIGCWinAppEx::ProcessAppType(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
			(::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
		if (bWin32)
			return true;
		if (g_pSpaceTelescopeImpl) {
			switch (g_pSpaceTelescopeImpl->m_nAppType) {
			case APP_WIN32:
				return true;
				break;
			case APP_BROWSER:
			case APP_BROWSER_ECLIPSE: {
				if (g_pSpaceTelescopeImpl->m_nAppType == APP_BROWSER_ECLIPSE) {
#ifdef _AFXDLL
#ifdef _DEBUG
					::MessageBox(NULL,
						_T("Chrome-Eclipse Model is not support MFC Share Dll"),
						_T("Warnning"), MB_OK);
#endif
					TRACE(
						_T("\r\n\r\n********Chrome-Eclipse-CLR Mix-Model is not support ")
						_T("MFC Share Dll********\r\n\r\n"));
#endif
				}
				g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
				HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
				if (hModule == nullptr)
					hModule = ::LoadLibrary(L"AIGCAgent.dll");
				if (hModule) {
					typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
					_InitApp _pInitAppFunction;
					_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp2");
					if (_pInitAppFunction != NULL) {
						m_bBuiltInBrowser = true;
						_pInitAppFunction(bCrashReporting, g_pSpaceTelescopeImpl->m_pWebRTDelegate);
						return false;
					}
				}
			} break;
			case APP_ECLIPSE:
				if (g_pWebRT && !g_pSpaceTelescopeImpl->m_bIsEclipseInit) {
					g_pWebRT->InitEclipseApp();
					return false;
				}
				break;
			}
		}
		return true;
	}

	BOOL CAIGCWinAppEx::IsBrowserModel(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(CString(m_pszExeName) + _T(".app.html")) == false) &&
			(::PathFileExists(CString(m_pszExeName) + _T(".html")) == false);
		if (bWin32 == false) {
			HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hModule == nullptr)
				hModule = ::LoadLibrary(g_strChromeRTFilePath);
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"AIGCAgent.dll");
			if (hModule) {
				m_bCrashReporting = bCrashReporting;
				FuncIsBrowserModel =
					(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
				if (FuncIsBrowserModel != NULL) {
					return FuncIsBrowserModel(bCrashReporting, this);
				}
			}
		}

		return false;
	};

	HWND CAIGCWinAppEx::GetDockablePane(HWND hFrame, int nID) {
		CWnd* pWnd = CWnd::FromHandlePermanent(hFrame);
		if (pWnd) {
			if (pWnd->IsKindOf(RUNTIME_CLASS(CFrameWndEx))) {
				CFrameWndEx* pFrame = (CFrameWndEx*)pWnd;
				CBasePane* pPane = pFrame->GetPane(nID);
				if (pPane)
					return pPane->m_hWnd;
			}
			if (pWnd->IsKindOf(RUNTIME_CLASS(CMDIFrameWndEx))) {
				CMDIFrameWndEx* pFrame = (CMDIFrameWndEx*)pWnd;
				CBasePane* pPane = pFrame->GetPane(nID);
				if (pPane)
					return pPane->m_hWnd;
			}
		}
		return NULL;
	}

	RECT CAIGCWinAppEx::GetClientAreaBounds()
	{
		if (m_pDockingManager)
			return m_pDockingManager->GetClientAreaBounds();
		return CRect(0, 0, 0, 0);
	}

	void CAIGCWinAppEx::CalcWindowRectForMDITabbedGroups(LPRECT rc)
	{
		if (m_pMDIClientAreaWnd)
			((CMDIClientAreaWnd*)m_pMDIClientAreaWnd)->CalcWindowRectForMDITabbedGroups(rc, 0);
	}
#else
	CAIGCApp* g_pAIGCApp = nullptr;
	static LRESULT WebRTCBTProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		LRESULT hr = CallNextHookEx(g_hCBTHook, nCode, wParam, lParam);
		HWND hWnd = (HWND)wParam;
		if (nCode == HCBT_CREATEWND) {
			CBT_CREATEWND* pCreateWnd = (CBT_CREATEWND*)lParam;
			TCHAR m_szBuffer[MAX_PATH];
			::GetClassName(hWnd, m_szBuffer, MAX_PATH);
			CString strClassName = m_szBuffer;
			if (strClassName == _T("Tangram Message Window Class")) {
				if (UnhookWindowsHookEx(g_hCBTHook)) {
					IUniverseAppProxy* pAppProxy = static_cast<IUniverseAppProxy*>(g_pAIGCApp);
					//pAppProxy->m_hMainWnd = pApp->m_pMainWnd->m_hWnd;
					::SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pAppProxy);
				}
			}
		}
		return hr;
	}

	class CWebRTProxy : public IWebRTDelegate {
	public:
		CWebRTProxy() {};
		virtual ~CWebRTProxy() {}

		// IWebRTDelegate:
		virtual bool OnAppIdle(BOOL& bIdle, LONG lCount) {
			return true;
		}

		virtual bool DoIdleWork() {
			if (g_pSpaceTelescopeImpl && g_pSpaceTelescopeImpl->m_hMainWnd &&
				::IsWindow(g_pSpaceTelescopeImpl->m_hMainWnd) == false)
				g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
			return false;
		}

		virtual bool IsAppIdleMessage() {
			return false;
		}

		virtual void ProcessMsg(MSG* msg) {
			::TranslateMessage(msg);
			::DispatchMessage(msg);
		}

		virtual void ForegroundIdleProc() {
		}

		virtual bool OnUniversePreTranslateMessage(MSG* pMsg) {
			return TRUE;
		}

		virtual HICON GetAppIcon(int nIndex)
		{
			if (g_pSpaceTelescopeImpl->m_hMainWnd) {
				switch (nIndex) {
				case 0:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pSpaceTelescopeImpl->m_hMainWnd, GCLP_HICON));
					break;
				case 1:
					return reinterpret_cast<HICON>(
						GetClassLongPtr(g_pSpaceTelescopeImpl->m_hMainWnd, GCLP_HICONSM));
					break;
				}
			}
			else
			{
				TCHAR m_szBuffer[MAX_PATH];
				::GetModuleFileName(GetModuleHandle(NULL), m_szBuffer, MAX_PATH);
				SHFILEINFOW info;
				if (SHGetFileInfoW(m_szBuffer,
					FILE_ATTRIBUTE_NORMAL,
					&info,
					sizeof(info),
					SHGFI_SYSICONINDEX | SHGFI_ICON | SHGFI_USEFILEATTRIBUTES))
				{
					return info.hIcon;
				}
			}
			return NULL;
		}
	};

	CWebRTProxy theAppProxy;

	CAIGCApp::CAIGCApp() {
		m_strExeName = _T("");
		m_strProviderID = _T("");
		g_pAIGCApp = this;
	}

	CAIGCApp::~CAIGCApp() {
		if (g_pSpaceTelescopeImpl) {
			g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID, nullptr);
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	bool CAIGCApp::WebRTInit(CString strID) {
		GetWebRTInfo();
		DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
		DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
		HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
		if (hModule == nullptr)
			hModule = ::LoadLibrary(g_strChromeRTFilePath);
		if (hModule == nullptr)
			hModule = ::LoadLibrary(L"AIGCAgent.dll");
		if (hModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
				m_szBuffer) == S_OK) {
				CString strChromeRTFilePath = CString(m_szBuffer);
				strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
				if (::PathFileExists(strChromeRTFilePath)) {
					hModule = ::LoadLibrary(strChromeRTFilePath);
				}
			}
		}
		if (hModule) {
			BOOL isBrowserModel = false;
			FuncIsBrowserModel =
				(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
			if (FuncIsBrowserModel != NULL) {
				isBrowserModel = FuncIsBrowserModel(false, this);
				if (isBrowserModel) {
					return false;
				}
			}
		}

		TCHAR m_szBuffer[MAX_PATH];
		TCHAR szDriver[MAX_PATH] = { 0 };
		TCHAR szDir[MAX_PATH] = { 0 };
		TCHAR szExt[MAX_PATH] = { 0 };
		TCHAR szFile2[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
		_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
		CString strTangramDll = szDriver;
		m_strExeName = szFile2;
		strTangramDll += szDir;
		strTangramDll += _T("universe.dll");
		HMODULE hModule2 = hModule;
		hModule = ::LoadLibrary(strTangramDll);
		if (hModule == NULL && g_strUniverseFilePath != _T(""))
			hModule = ::LoadLibrary(g_strUniverseFilePath);
		if (hModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
			g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hModule2;

			m_strProviderID += _T("host");
			m_strProviderID.MakeLower();

			g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
			g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
				static_cast<IUniverseAppProxy*>(this));
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
				static_cast<IWindowProvider*>(this));
			if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
				g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
				::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
					(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
					g_pSpaceTelescopeImpl->m_nAppType);
		}
		if (hModule == NULL || hModule2 == NULL) {
			g_hCBTHook = SetWindowsHookEx(WH_CBT, WebRTCBTProc, NULL, ::GetCurrentThreadId());
		}
		return true;
	}

	CXobjProxy* CAIGCApp::OnXobjInit(IXobj* pNewNode) {
		CComBSTR bstrName("");
		pNewNode->get_Name(&bstrName);
		CComBSTR bstrName2("");
		pNewNode->get_NameAtWindowPage(&bstrName2);
		return nullptr;
	}

	CNucleusProxy* CAIGCApp::OnNucleusCreated(INucleus* pNewFrame) {
		__int64 h = 0;
		pNewFrame->get_HWND(&h);
		CComBSTR bstrName("");
		pNewFrame->get_Name(&bstrName);
		return nullptr;
	}

	CNucleiProxy* CAIGCApp::OnNucleiCreated(INuclei* pNuclei) {
		CNucleiProxy* pNucleiProxy = nullptr;
		__int64 h = 0;
		pNuclei->get_Handle(&h);
		if (h) {
			if (pNucleiProxy)
				pNucleiProxy->m_bAutoDelete = false;
		}
		return pNucleiProxy;
	}

	HWND CAIGCApp::QueryWndInfo(QueryType nType, HWND hWnd)
	{
		if (nType == MainWnd && ::IsWindow(m_hMainWnd) && hWnd == NULL)
			return m_hMainWnd;
		return NULL;
	};

	bool CAIGCApp::AttachWebRT() {
		HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
		if (hModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
		}
		if (g_pSpaceTelescopeImpl)
		{
			HMODULE hAgentModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hAgentModule == nullptr) {
				TCHAR m_szBuffer[MAX_PATH];
				CString _strAIGCAgentPath = _T("");
				::GetModuleFileName(hModule, m_szBuffer, MAX_PATH);
				_strAIGCAgentPath = CString(m_szBuffer);
				int nPos = _strAIGCAgentPath.ReverseFind('\\');
				_strAIGCAgentPath = _strAIGCAgentPath.Left(nPos + 1) + _T("AIGCAgent.dll");
				if (::PathFileExists(_strAIGCAgentPath)) {
					hAgentModule = g_pSpaceTelescopeImpl->m_hWebRTProxyModel = ::LoadLibrary(_strAIGCAgentPath);
					if (g_pSpaceTelescopeImpl->m_pWebRTDelegate == NULL) {
						m_strProviderID += _T("host");
						m_strProviderID.MakeLower();

						g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
						g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
							static_cast<IUniverseAppProxy*>(this));
						g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
							static_cast<IWindowProvider*>(this));
						if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
							g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
							::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
								(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
								g_pSpaceTelescopeImpl->m_nAppType);
						g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
						m_bBuiltInBrowser = true;
						if (hAgentModule) {
							typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
							_InitApp _pInitAppFunction;
							_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
							if (_pInitAppFunction != NULL) {
								m_bBuiltInBrowser = true;
								_pInitAppFunction(false, g_pSpaceTelescopeImpl->m_pWebRTDelegate);
								return true;
							}
						}

						//HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
						//if (hModule) {
						//	typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
						//	_InitApp _pInitAppFunction;
						//	_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
						//	if (_pInitAppFunction != NULL) {
						//		m_bBuiltInBrowser = true;
						//		_pInitAppFunction(false, g_pSpaceTelescopeImpl->m_pWebRTDelegate);
						//		return true;
						//	}
						//}
						return true;
					}
				}
			}
		}
		return false;
	}

	BOOL CAIGCApp::InitApplication() {
		if (WebRTInit(_T("")))
			return ProcessAppType(m_bCrashReporting);
		else
			return false;
	}

	bool CAIGCApp::ProcessAppType(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(m_strExeName + _T(".app.html")) == false) &&
			(::PathFileExists(m_strExeName + _T(".html")) == false);
		if (bWin32)
			return true;
		if (g_pSpaceTelescopeImpl) {
			switch (g_pSpaceTelescopeImpl->m_nAppType) {
			case APP_WIN32:
				return true;
				break;
			case APP_BROWSER:
			case APP_BROWSER_ECLIPSE: {
				g_pSpaceTelescopeImpl->m_hMainWnd = NULL;
				HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
				if (hModule == nullptr)
					hModule = ::LoadLibrary(L"AIGCAgent.dll");
				if (hModule == nullptr) {
					TCHAR m_szBuffer[MAX_PATH];
					if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
						m_szBuffer) == S_OK) {
						CString strChromeRTFilePath = CString(m_szBuffer);
						strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
						if (::PathFileExists(strChromeRTFilePath)) {
							hModule = ::LoadLibrary(strChromeRTFilePath);
						}
					}
					if (hModule == nullptr)
						hModule = ::LoadLibrary(L"AIGCAgent.dll");
				}
				if (hModule) {
					typedef int(__stdcall* _InitApp)(bool bSupportCrashReporting, void*);
					_InitApp _pInitAppFunction;
					_pInitAppFunction = (_InitApp)GetProcAddress(hModule, "InitApp");
					if (_pInitAppFunction != NULL) {
						m_bBuiltInBrowser = true;
						_pInitAppFunction(bCrashReporting, g_pSpaceTelescopeImpl->m_pWebRTDelegate);
						return true;
					}
				}
			} break;
			case APP_ECLIPSE:
				if (g_pWebRT && !g_pSpaceTelescopeImpl->m_bIsEclipseInit) {
					g_pWebRT->InitEclipseApp();
					return false;
				}
				break;
			}
		}
		return true;
	}

	BOOL CAIGCApp::IsBrowserModel(bool bCrashReporting) {
		BOOL bWin32 =
			(::PathFileExists(m_strExeName + _T(".app.html")) == false) &&
			(::PathFileExists(m_strExeName + _T(".html")) == false);
		if (bWin32 == false) {
			HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
			if (hModule == nullptr)
				hModule = ::LoadLibrary(g_strChromeRTFilePath);
			if (hModule == nullptr)
				hModule = ::LoadLibrary(L"AIGCAgent.dll");
			if (hModule) {
				m_bCrashReporting = bCrashReporting;
				FuncIsBrowserModel =
					(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
				if (FuncIsBrowserModel != NULL) {
					return FuncIsBrowserModel(bCrashReporting, this);
				}
			}
		}

		return false;
	};

	CAIGCAppEx::CAIGCAppEx() {
		m_bWebRTInit = InitApplication();
	}

	CAIGCAppEx::~CAIGCAppEx() {
		if (g_hCBTHook) {
			::UnhookWindowsHookEx(g_hCBTHook);
		}
	}

	LRESULT CAIGCAppEx::CBTProc(int nCode, WPARAM wParam, LPARAM lParam)
	{
		LRESULT hr = CallNextHookEx(g_hCBTHook, nCode, wParam, lParam);
		HWND hWnd = (HWND)wParam;
		if (nCode == HCBT_CREATEWND) {
			return 1000;
		}
		return hr;
	}

	bool CAIGCAppEx::WebRTInit(CString strID) {
		GetWebRTInfo();
		DPI_AWARENESS_CONTEXT dpiAwarenessContext = DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2;
		DpiUtil::SetProcessDpiAwarenessContext(dpiAwarenessContext);
		HMODULE hModule = ::GetModuleHandle(L"AIGCAgent.dll");
		if (hModule == nullptr)
			hModule = ::LoadLibrary(g_strChromeRTFilePath);
		if (hModule == nullptr)
			hModule = ::LoadLibrary(L"AIGCAgent.dll");
		if (hModule == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			if (SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0,
				m_szBuffer) == S_OK) {
				CString strChromeRTFilePath = CString(m_szBuffer);
				strChromeRTFilePath += _T("\\AIGCAssistant\\AIGCAgent.dll");
				if (::PathFileExists(strChromeRTFilePath)) {
					hModule = ::LoadLibrary(strChromeRTFilePath);
				}
			}
		}
		if (hModule) {
			BOOL isBrowserModel = false;
			FuncIsBrowserModel =
				(_IsBrowserModel)GetProcAddress(hModule, "IsBrowserModel");
			if (FuncIsBrowserModel != NULL) {
				isBrowserModel = FuncIsBrowserModel(false, this);
				if (isBrowserModel) {
					g_hCBTHook = SetWindowsHookEx(WH_CBT, CBTProc, NULL, ::GetCurrentThreadId());
					return false;
				}
			}
		}

		TCHAR m_szBuffer[MAX_PATH];
		TCHAR szDriver[MAX_PATH] = { 0 };
		TCHAR szDir[MAX_PATH] = { 0 };
		TCHAR szExt[MAX_PATH] = { 0 };
		TCHAR szFile2[MAX_PATH] = { 0 };
		::GetModuleFileName(NULL, m_szBuffer, MAX_PATH);
		_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
		CString strTangramDll = szDriver;
		m_strExeName = szFile2;
		strTangramDll += szDir;
		strTangramDll += _T("universe.dll");
		HMODULE hModule2 = hModule;
		hModule = ::LoadLibrary(strTangramDll);
		if (hModule == nullptr && g_strUniverseFilePath != _T(""))
			hModule = ::LoadLibrary(g_strUniverseFilePath);
		if (hModule) {
			if (m_strContainer != _T("")) {
				m_strContainer = _T(",") + m_strContainer + _T(",");
				m_strContainer.Replace(_T(",,"), _T(","));
			}
			GetWebRTImpl _pWebRTImplFunction;
			_pWebRTImplFunction = (GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
			g_pSpaceTelescopeImpl = _pWebRTImplFunction(&g_pWebRT);
			g_pSpaceTelescopeImpl->m_hWebRTProxyModel = hModule2;

			m_strProviderID += _T("host");
			m_strProviderID.MakeLower();

			g_pSpaceTelescopeImpl->m_pUniverseAppProxy = this;
			g_pSpaceTelescopeImpl->m_pWebRTDelegate = (IWebRTDelegate*)&theAppProxy;
			g_pSpaceTelescopeImpl->InserttoDataMap(0, m_strProviderID,
				static_cast<IUniverseAppProxy*>(this));
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID,
				static_cast<IWindowProvider*>(this));
			if (g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER &&
				g_pSpaceTelescopeImpl->m_nAppType != APP_BROWSER_ECLIPSE)
				::PostAppMessage(::GetCurrentThreadId(), WM_CHROMEAPPINIT,
					(WPARAM)g_pSpaceTelescopeImpl->m_pWebRTDelegate,
					g_pSpaceTelescopeImpl->m_nAppType);
		}
		return true;
	};

	CWebRTWindowProviderApp::CWebRTWindowProviderApp() {
		m_hModule = NULL;
		m_strProviderID = _T("");
	}

	CWebRTWindowProviderApp::~CWebRTWindowProviderApp() {
		if (g_pSpaceTelescopeImpl) {
			g_pSpaceTelescopeImpl->InserttoDataMap(1, m_strProviderID, nullptr);
		}
	}

	bool CWebRTWindowProviderApp::WebRTInit(CString strID) {
		if (g_pSpaceTelescopeImpl == nullptr) {
			TCHAR m_szBuffer[MAX_PATH];
			TCHAR szDriver[MAX_PATH] = { 0 };
			TCHAR szDir[MAX_PATH] = { 0 };
			TCHAR szExt[MAX_PATH] = { 0 };
			TCHAR szFile2[MAX_PATH] = { 0 };
			::GetModuleFileName(m_hModule, m_szBuffer, MAX_PATH);
			_tsplitpath_s(m_szBuffer, szDriver, szDir, szFile2, szExt);
			m_strProviderID = szFile2;
			HMODULE hModule = ::GetModuleHandle(_T("universe.dll"));
			if (hModule) {
				typedef CWebRTImpl* (__stdcall* GetWebRTImpl)(IWebRT**);
				GetWebRTImpl _pWebRTFunction;
				_pWebRTFunction =
					(GetWebRTImpl)GetProcAddress(hModule, "GetWebRTImpl");
				IWebRT* pWebRT = nullptr;
				g_pSpaceTelescopeImpl = _pWebRTFunction(&pWebRT);
				m_strProviderID.MakeLower();
				g_pSpaceTelescopeImpl->InserttoDataMap(
					1, m_strProviderID, static_cast<IWindowProvider*>(this));
				return true;
			}
		}
		return false;
	}
#endif
}  // namespace CommonUniverse
