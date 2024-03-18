// dllmain.h : Declaration of module class.

class CTangramApp : 
	public CComponentApp
{
public:
	CTangramApp();
	virtual ~CTangramApp();

	BOOL InitInstance();

	// IHubbleWindowProvider Methods:
	virtual HWND Create(HWND hParentWnd, IXobj* pNode);
	virtual CString GetNames();
	virtual CString GetTags(CString strName);
};

extern CTangramApp theApp;
