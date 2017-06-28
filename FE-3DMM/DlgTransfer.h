#pragma once
#include "DlgTransferAuto.h"
#include "DlgTransferManual.h"
#include "DlgTransferParamLearn.h"
#include "DlgTransferVisionTrain.h"

// CDlgTransfer 对话框

class CDlgTransfer : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransfer)

public:
	CDlgTransfer(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransfer();

// 对话框数据
	enum { IDD = IDD_DLG_TRANSFER };

	void Cancel();				//销毁窗口及子窗口

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	afx_msg void OnCustomeTabChange(NMHDR *pNMHDR, LRESULT * pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

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
	CD2DCustomeTable				*m_pCustomeTab;
	CDlgTransferAuto					*m_pDlgTransferAuto;
	CDlgTransferManual				*m_pDlgTransferManual;
	CDlgTransferParamLearn		*m_pDlgTransferParaLearn;
	CDlgTransferVisionTrain			*m_pDlgTransferVisTrain;

private:
	CList<CDialog *, CDialog* >	m_listSubWindow;
	CProcessCore							*m_pProCore;	//主操作类指针
};
