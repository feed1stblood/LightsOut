// LightDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Light.h"
#include "LightDlg.h"
//#include "xxx.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CLightDlg 对话框




CLightDlg::CLightDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLightDlg::IDD, pParent)
	, GameStarted(false),lamps(NULL)
	, m_sSHOWCOUNTS(_T(""))
	, Length(5)
	, Height(5)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHWCOUNTS, m_sSHOWCOUNTS);
}

BEGIN_MESSAGE_MAP(CLightDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP_ABOUT, &CLightDlg::OnHelpAbout)
	ON_COMMAND(ID_FILE_EXIT, &CLightDlg::OnFileExit)
	ON_COMMAND(ID_STARTGAME_EASY, &CLightDlg::OnStartgameEasy)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_STARTGAME_NORMAL, &CLightDlg::OnStartgameNormal)
	ON_COMMAND(ID_STARTGAME_HARD, &CLightDlg::OnStartgameHard)
	ON_COMMAND(ID_HELP_HELP, &CLightDlg::OnHelpHelp)
	ON_COMMAND(ID_FILE_MODIFYSIZE, &CLightDlg::OnFileModifysize)
END_MESSAGE_MAP()


// CLightDlg 消息处理程序

BOOL CLightDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//bmp[0].LoadBitmapW(IDB_BITMAP1);	
	//bmp[1].LoadBitmapW(IDB_BITMAP1);
	CRect rect;
	GetWindowRect(&rect);
	MoveWindow(rect.left,rect.top,300,270);
	GetDlgItem(IDC_SHWCOUNTS)->MoveWindow(40*5+15,40,70,70);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLightDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLightDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CLightDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLightDlg::OnHelpAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CLightDlg::OnFileExit()
{
	// TODO: 在此添加命令处理程序代码
	CDialog::OnOK();
}

void CLightDlg::OnStartgameEasy()
{

	if(lamps)
		delete lamps;
	GameStarted=TRUE;
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED); 
	lamps=new Lamps2(Length,Height,this);
	lamps->Rinit(0);
	lamps->Draw();
	m_sSHOWCOUNTS="已用步骤:0";
	UpdateData(FALSE);
}

void CLightDlg::OnStartgameNormal()
{
	// TODO: 在此添加命令处理程序代码
	if(lamps)
		delete lamps;
	GameStarted=TRUE;
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED); 
	lamps=new Lamps2(Length,Height,this);
	lamps->Rinit(1);
	lamps->Draw();
	m_sSHOWCOUNTS="已用步骤:0";
	UpdateData(FALSE);
}

void CLightDlg::OnStartgameHard()
{
	// TODO: 在此添加命令处理程序代码
	if(lamps)
		delete lamps;
	GameStarted=TRUE;
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED); 
	lamps=new Lamps2(Length,Height,this);
	lamps->Rinit(2);
	lamps->Draw();

	m_sSHOWCOUNTS="已用步骤:0";
	UpdateData(FALSE);
}



void CLightDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(GameStarted)
	{
		if(point.x>=10&&point.x<=Length*40+10&&point.y>=10&&point.y<=Height*40+10)
			lamps->OnClicked((point.x-10)/40,(point.y-10)/40);
		lamps->Draw();
		if(lamps->IsAllIdentical()!=-1)
		{
			MessageBox(_T("真厉害,すごい!"),_T("恭喜"),MB_OK);
			GameStarted=FALSE;
		}
		m_sSHOWCOUNTS.Format(_T("已用步骤:%d"),lamps->counts);
		UpdateData(FALSE);
	}
	CDialog::OnLButtonUp(nFlags, point);
}




void CLightDlg::OnHelpHelp()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("这是一个类似于电子词典上的开窗户的小游戏,\n点击某个方块,该方块及该方块周围的方块都会改变颜色,\n将所有方块变黑即可获得胜利."),_T("游戏说明"),MB_OK);
}





void CLightDlg::OnFileModifysize()
{
	// TODO: 在此添加命令处理程序代码
		CDlgInput input;
	input.m_Length.Format(_T("%d"),Length);
	input.m_Height.Format(_T("%d"),Height);
	if(IDOK==input.DoModal())
	{
		Length=_ttoi(input.m_Length.GetBuffer());
		Height=_ttoi(input.m_Height.GetBuffer());
	}
	CRect Ldlg_rect;
	GetWindowRect(&Ldlg_rect); 
	MoveWindow(Ldlg_rect.left,Ldlg_rect.top,40*Length+100,40*Height+70);
	GetDlgItem(IDC_SHWCOUNTS)->MoveWindow(40*Length+15,40,70,70);
}
