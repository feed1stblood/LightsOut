// LightDlg.h : 头文件
//
#include "afxwin.h"
#include "Lamps2.h"
#include "DlgInput.h"
#pragma once


// CLightDlg 对话框
class CLightDlg : public CDialog
{
// 构造
public:
	CLightDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LIGHT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
