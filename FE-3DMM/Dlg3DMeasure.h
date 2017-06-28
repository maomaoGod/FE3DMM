#pragma once
#include "Dlg3DMeasureScan.h"
#include "Dlg3DMeasureMatch.h"

// CDlg3DMeasure 对话框

class CDlg3DMeasure : public CDialog
{
	DECLARE_DYNAMIC(CDlg3DMeasure)

public:
	CDlg3DMeasure(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg3DMeasure();

// 对话框数据
	enum { IDD = IDD_DLG_3DMEASURE };

	void Cancel();				//销毁窗口及子窗口

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnCustomeTabChange(NMHDR *pNMHDR, LRESULT * pResult);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();				//释放本窗口中其他new堆内存
	bool InitCustomeTab();
	void CreateSubWindow();
	void ShowSubWindow(int iIndex);

public:
	CD2DCustomeTable		*m_pCustomeTab;
	CDlg3DMeasureScan		*m_pDlg3DMeasureScan;
	CDlg3DMeasureMatch		*m_pDlg3DMeasureMatch;

private:
	CList<CDialog *, CDialog* > m_listSubWindow;

	CProcessCore			*m_pProCore;	//主操作类指针
};
