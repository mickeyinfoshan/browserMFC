
// bDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "b.h"
#include "bDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CbDlg 对话框




CbDlg::CbDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbDlg::IDD, pParent)
	
	, url(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, a);
	DDX_Control(pDX, IDC_EDIT1, URLBox);
	DDX_Text(pDX, IDC_EDIT1, url);
}

BEGIN_MESSAGE_MAP(CbDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON2, &CbDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CbDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CbDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_BUTTON3, &CbDlg::OnBnClickedForward)
	ON_BN_CLICKED(IDC_BUTTON4, &CbDlg::OnBnClickedRefresh)
END_MESSAGE_MAP()


// CbDlg 消息处理程序

BOOL CbDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon	, FALSE);		// 设置小图标
	MoveWindow(0,0,1024,768);
	GetDlgItem(IDC_EXPLORER1)->MoveWindow(2,40,1018,720);
	// TODO: 在此添加额外的初始化代码
	a.Navigate(_T("http://www.swu.edu.cn"),NULL,NULL,NULL,NULL);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CbDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CbDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}







void CbDlg::OnBnClickedButton2()
{
	a.Navigate((LPCTSTR)url,NULL,NULL,NULL,NULL);
}
BEGIN_EVENTSINK_MAP(CbDlg, CDialogEx)
	ON_EVENT(CbDlg, IDC_EXPLORER1, 251, CbDlg::NewWindow2Explorer1, VTS_PDISPATCH VTS_PBOOL)
END_EVENTSINK_MAP()


void CbDlg::NewWindow2Explorer1(LPDISPATCH* ppDisp, BOOL* Cancel)
{
	CbDlg * newWindow = new CbDlg;
	newWindow->Create(IDD_B_DIALOG);
	newWindow->a.put_RegisterAsBrowser(true);
	*ppDisp = newWindow->a.get_Application();
}


void CbDlg::OnEnChangeEdit1()
{
	UpdateData(true);
}


void CbDlg::OnBnClickedBack()
{
	a.GoBack();
}


void CbDlg::OnBnClickedForward()
{
	a.GoForward();
}


void CbDlg::OnBnClickedRefresh()
{
	a.Refresh();
}
