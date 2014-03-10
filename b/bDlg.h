
// bDlg.h : 头文件
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// CbDlg 对话框
class CbDlg : public CDialogEx
{
// 构造
public:
	CbDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_B_DIALOG };

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
	
	CExplorer1 a;
	afx_msg void OnBnClickedButton2();
	DECLARE_EVENTSINK_MAP()
	void NewWindow2Explorer1(LPDISPATCH* ppDisp, BOOL* Cancel);
	
	CEdit URLBox;
	CString url;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedBack();
	afx_msg void OnBnClickedForward();
	afx_msg void OnBnClickedRefresh();
};
