
// bDlg.h : ͷ�ļ�
//

#pragma once
#include "explorer1.h"
#include "afxwin.h"


// CbDlg �Ի���
class CbDlg : public CDialogEx
{
// ����
public:
	CbDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_B_DIALOG };

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
