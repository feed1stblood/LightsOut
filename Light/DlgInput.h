#pragma once


// CDlgInput �Ի���

class CDlgInput : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput)

public:
	CDlgInput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgInput();

// �Ի�������
	enum { IDD = IDD_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Length;
public:
	CString m_Height;
public:
	afx_msg void OnBnClickedOk();
};
