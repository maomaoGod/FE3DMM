#pragma once
#include "DlgPrintMotionLinkLearn.h"

// CDlgPrintMotionControl 对话框

class CDlgPrintMotionControl : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrintMotionControl)

public:
	CDlgPrintMotionControl(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrintMotionControl();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT_MOTION };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedPrintMContinuMoveRadio();
	afx_msg void OnBnClickedPrintMInterMoveRadio();
	afx_msg void OnBnClickedPrintMXpositiveBtn();
	afx_msg void OnBnClickedPrintMXnegativeBtn();
	afx_msg void OnBnClickedPrintMYpositiveBtn();
	afx_msg void OnBnClickedPrintMYnegativeBtn();
	afx_msg void OnDeltaposPrintMContinuMoveSpeedSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposPrintMInterMoveStepSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedPrintMLinklearnBtn();
	afx_msg void OnBnClickedPrintMCameralocateRadio();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();
	
private:
	void Release();														//释放本窗口中其他new堆内存
	void InitSimulatePanel();										//初始化运动模拟面板
	void SetMoveComponentState();					//设置运动控制组件状态
	void InitWindowHandle();									//初始化Pic控件显示窗口

public:
	CDlgPrintMotionLinkLearn* m_pDlgPrintMotionLinkLearn;  	//连线学习Dlg

private:
	CXPGroupBox				m_GB1;
	CXPGroupBox				m_GB2;
	CXPGroupBox				m_GB3;
	CBmpBtn						m_bmpBtn[7];
	CPanelWnd					m_panelwnd;
	CProcessCore				*m_pProCore;											//主操作类指针
	bool								m_bContinuousMove;							//true连续  false点动
	double							m_dContinMoveSpeed;
	double							m_dInterMoveStep;
	bool								m_bLinkLearn;											//是否进行连线学习
	HTuple							m_windowHandle_Pic;							//Pic控件关联的Halcon窗口句柄
	Size									m_winSize_Pic;											//Pic窗口大小
};
