// DlgInput.cpp : 实现文件
//

#include "stdafx.h"
#include "Light.h"
#include "DlgInput.h"


// CDlgInput 对话框

IMPLEMENT_DYNAMIC(CDlgInput, CDialog)

CDlgInput::CDlgInput(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput::IDD, pParent)
	, m_Length(_T(""))
	, m_Height(_T(""))
{

}

CDlgInput::~CDlgInput()
{
}

void CDlgInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_LENGTH, m_Length);
	DDV_MaxChars(pDX, m_Length, 2);
	DDX_Text(pDX, IDC_EDIT_Height, m_Height);
}


BEGIN_MESSAGE_MAP(CDlgInput, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgInput::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput 消息处理程序

void CDlgInput::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int Length=_ttoi(m_Length.GetBuffer());
	int Height=_ttoi(m_Height.GetBuffer());
	if(Length<3||Length>15||Height<3||Height>15)
	{
		MessageBox(_T("长和宽必须在2～15之间"),_T("提示"),MB_OK);
		return;
	}
	OnOK();
}
