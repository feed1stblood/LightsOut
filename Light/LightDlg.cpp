// LightDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Light.h"
#include "LightDlg.h"
//#include "xxx.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLightDlg �Ի���




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


// CLightDlg ��Ϣ�������

BOOL CLightDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//bmp[0].LoadBitmapW(IDB_BITMAP1);	
	//bmp[1].LoadBitmapW(IDB_BITMAP1);
	CRect rect;
	GetWindowRect(&rect);
	MoveWindow(rect.left,rect.top,300,270);
	GetDlgItem(IDC_SHWCOUNTS)->MoveWindow(40*5+15,40,70,70);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLightDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CLightDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLightDlg::OnHelpAbout()
{
	// TODO: �ڴ���������������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CLightDlg::OnFileExit()
{
	// TODO: �ڴ���������������
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
	m_sSHOWCOUNTS="���ò���:0";
	UpdateData(FALSE);
}

void CLightDlg::OnStartgameNormal()
{
	// TODO: �ڴ���������������
	if(lamps)
		delete lamps;
	GameStarted=TRUE;
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED); 
	lamps=new Lamps2(Length,Height,this);
	lamps->Rinit(1);
	lamps->Draw();
	m_sSHOWCOUNTS="���ò���:0";
	UpdateData(FALSE);
}

void CLightDlg::OnStartgameHard()
{
	// TODO: �ڴ���������������
	if(lamps)
		delete lamps;
	GameStarted=TRUE;
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED); 
	lamps=new Lamps2(Length,Height,this);
	lamps->Rinit(2);
	lamps->Draw();

	m_sSHOWCOUNTS="���ò���:0";
	UpdateData(FALSE);
}



void CLightDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(GameStarted)
	{
		if(point.x>=10&&point.x<=Length*40+10&&point.y>=10&&point.y<=Height*40+10)
			lamps->OnClicked((point.x-10)/40,(point.y-10)/40);
		lamps->Draw();
		if(lamps->IsAllIdentical()!=-1)
		{
			MessageBox(_T("������,������!"),_T("��ϲ"),MB_OK);
			GameStarted=FALSE;
		}
		m_sSHOWCOUNTS.Format(_T("���ò���:%d"),lamps->counts);
		UpdateData(FALSE);
	}
	CDialog::OnLButtonUp(nFlags, point);
}




void CLightDlg::OnHelpHelp()
{
	// TODO: �ڴ���������������
	MessageBox(_T("����һ�������ڵ��Ӵʵ��ϵĿ�������С��Ϸ,\n���ĳ������,�÷��鼰�÷�����Χ�ķ��鶼��ı���ɫ,\n�����з����ڼ��ɻ��ʤ��."),_T("��Ϸ˵��"),MB_OK);
}





void CLightDlg::OnFileModifysize()
{
	// TODO: �ڴ���������������
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
