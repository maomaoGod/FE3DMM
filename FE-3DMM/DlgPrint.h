#pragma once
#include "DlgPrintMotionControl.h"
#include "DlgPrintParamAdjust.h"
#include "DlgPrintPrintOperate.h"

// CDlgPrint 对话框

class CDlgPrint : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrint)

public:
	CDlgPrint(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrint();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT };

	void Cancel();				//销毁窗口及子窗口

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnCustomeTabChange(NMHDR *pNMHDR, LRESULT * pResult);


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();


private:
	void Release();				//释放本窗口中其他new堆内存
	bool InitCustomeTab();
	void CreateSubWindow();
	void ShowSubWindow(int iIndex);

public:
	CD2DCustomeTable		*m_pCustomeTab;
	CDlgPrintParamAdjust	*m_pDlgPrintParamAdjust;
	CDlgPrintMotionControl	*m_pDlgPrintMotionControl;
	CDlgPrintPrintOperate	*m_pDlgPrintPrintOperate;

private:
	CList<CDialog *, CDialog* > m_listSubWindow;

	CProcessCore			*m_pProCore;	//主操作类指针
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
