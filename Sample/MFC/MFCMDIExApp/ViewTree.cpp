
#include "pch.h"
#include "framework.h"
#include "ViewTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree() noexcept
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_MESSAGE(WM_XOBJCREATED, OnWebRTMsg)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CViewTree::OnTvnSelchanged)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree message handlers

LRESULT CViewTree::OnWebRTMsg(WPARAM wParam, LPARAM lParam)
{
	if (lParam == 10000)
	{
		HANDLE hData = ::GetProp(m_hWnd, _T("CosmosData"));
		if (hData)
		{
			CTangramXmlParse* pParse = (CTangramXmlParse*)hData;
			if (pParse)
			{
				int nID = pParse->attrInt(_T("clientid"), 0);
				if (nID == ::GetDlgCtrlID(m_hWnd))
				{
					CString xml = pParse->xml();
				}
			}
		}
	}
	LRESULT lRes = CWnd::DefWindowProc(WM_XOBJCREATED, wParam, lParam);
	return lRes;
}
void CViewTree::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	if (g_pSpaceTelescopeImpl)
	{
		INucleus* pGalaxy = g_pSpaceTelescopeImpl->GetNucleus(m_hWnd);
		if (pGalaxy)
		{
			IXobj* pObj = nullptr;
			pGalaxy->get_VisibleXobj(&pObj);
			if (pObj)
			{
				IWebView* pPage = nullptr;
				pObj->get_WebPage(&pPage);
			}
		}
		CWebViewImpl* pImpl = g_pSpaceTelescopeImpl->GetWebPageImpl(m_hWnd);
		CBrowserImpl* pBrowser = g_pSpaceTelescopeImpl->GetBrowserImpl(m_hWnd);
		HWND hBrowser = nullptr;
		if (pImpl)
		{
			CChromeRenderFrameHost* pChromeRenderFrameHost = pImpl->m_pChromeRenderFrameHost;
			hBrowser = pChromeRenderFrameHost->GetHostBrowserWnd();
		}
		if (pBrowser)
		{
			//pBrowser->m_pBrowser->IsActiveWebContentWnd(pImpl->)
		}
		CString strText = _T("");
		TVITEM pItem = pNMTreeView->itemNew;
		//GetParent()->GetWindowText(strText);
		strText = this->GetItemText(pItem.hItem);
		CString strXml = _T("");
		CString strKey = _T("default");
		CosmosUIItemData* pTreeItemData = (CosmosUIItemData*)pNMTreeView->itemNew.lParam;
		if (pTreeItemData && pTreeItemData->m_strKey != _T(""))
			strKey = strText + _T("_") + pTreeItemData->m_strKey;
		strKey.Replace(_T(" "), _T("_"));
	}
	*pResult = 0;
}

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != nullptr);

	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != nullptr)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}
