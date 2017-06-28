#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgTransferManualAdvanced 对话框

class CDlgTransferManualAdvanced : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTransferManualAdvanced)

public:
	CDlgTransferManualAdvanced(CProcessCore* pProCore, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransferManualAdvanced();
// 对话框数据
	enum { IDD = IDD_DLG_TRANSFER_M_ADVANCED };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()

public:
	void InitCtrl();
	void SetTransferType(int Type);

private:
	void Release();
	
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedTransferMAOkBtn();
	afx_msg void OnBnClickedTransferMACancelBtn();
	afx_msg void OnNMReleasedcaptureTransferMAPositivepressSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeTransferMAPositivepressEdit();
	afx_msg void OnDeltaposTransferMAPositivepressSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureTransferMANegativepressSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeTransferMANegativepressEdit();
	afx_msg void OnDeltaposTransferMANegativepressSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMReleasedcaptureTransferMAZspeedSlide(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeTransferMAZspeedEdit();
	afx_msg void OnDeltaposTransferMAZspeedSpin(NMHDR *pNMHDR, LRESULT *pResult);


private:
	/*控件变量*/
	CSliderCtrl m_cSldPositiveOrF;
	CEdit m_cEditPositiveOrF;
	CSpinButtonCtrl m_cSpinPositiveOrF;
	CSliderCtrl m_cSldNegativeOrS;
	CEdit m_cEditNegativeOrS;
	CSpinButtonCtrl m_cSpinNegativeOrS;
	CSliderCtrl m_cSldZSpeed;
	CEdit m_cEditZSpeed;
	CSpinButtonCtrl m_cSpinZSpeed;

	int m_iTransferType;     //与外面设定的转印方式关联

	CProcessCore* m_pProCore;
};
