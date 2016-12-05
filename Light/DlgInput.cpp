// DlgInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Light.h"
#include "DlgInput.h"


// CDlgInput �Ի���

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


// CDlgInput ��Ϣ�������

void CDlgInput::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	int Length=_ttoi(m_Length.GetBuffer());
	int Height=_ttoi(m_Height.GetBuffer());
	if(Length<3||Length>15||Height<3||Height>15)
	{
		MessageBox(_T("���Ϳ������2��15֮��"),_T("��ʾ"),MB_OK);
		return;
	}
	OnOK();
}
