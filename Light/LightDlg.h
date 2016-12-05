// LightDlg.h : ͷ�ļ�
//
#include "afxwin.h"
#include "Lamps2.h"
#include "DlgInput.h"
#pragma once


// CLightDlg �Ի���
class CLightDlg : public CDialog
{
// ����
public:
	CLightDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LIGHT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileStartgame();
	afx_msg void OnHelpAbout();
	afx_msg void OnFileExit();
	afx_msg void OnStartgameEasy();
	afx_msg void OnStartgameNormal();
	afx_msg void OnStartgameHard();
	afx_msg void OnHelpHelp();
	afx_msg void OnFileModifysize();
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
private:
	CString m_sSHOWCOUNTS;


private:
	bool GameStarted;
	int Length;
	int Height;
	Lamps2 *lamps;
};
