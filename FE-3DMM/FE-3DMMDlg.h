
// FE-3DMMDlg.h : 头文件
//

#pragma once
#include "FE-3DMM.h"
#include "DlgLaserStrip.h"
#include "Dlg3DMeasure.h"
#include "DlgTransfer.h"
#include "DlgPrint.h"

#define TIMER_ERROR_STATUS 0xFF          //报警定时器
#define TIMER_IMAGE_SHOW   0xFF+1		//图像显示定时器

// CFE3DMMDlg 对话框
class CFE3DMMDlg : public CDialogEx
{
// 构造
public:
	CFE3DMMDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FE3DMM_DIALOG };

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedMain3dmeasureBtn();
	afx_msg void OnBnClickedMainUgBtn();
	afx_msg void OnBnClickedMainLaserstripBtn();
	afx_msg void OnBnClickedMainTransferBtn();
	afx_msg void OnBnClickedMainPrintBtn();
	afx_msg void OnBnClickedMainExitBtn();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);


// 实现
protected:
	HICON m_hIcon;

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void Release();														//释放本窗口中其他new堆内存
	void InitButton();
	void InitErrorStatusEdit();									//初始化报警显示Edit
	void CreateSubDialog();
	void ShowSubDialog(INT measure=SW_HIDE, INT laserstrip=SW_HIDE, INT tranfer=SW_HIDE, INT print=SW_HIDE);
	void ShowUgWnd();											//显示UG窗口
	void CloseUgWnd();											//关闭UG窗口
	void RefreshErrorStatus();									//更新报警状态
	void RefreshImageShow();									//更新图像显示

public:
	CDlgLaserStrip			*m_pDlgLaserStrip;
	CDlg3DMeasure		*m_pDlg3DMeasure;
	CDlgTransfer				*m_pDlgTransfer;
	CDlgPrint					*m_pDlgPrint;

private:
	CBmpBtn					m_bmpBtn[7];
	CProcessCore			*m_pProCore;					//主操作类指针
	CReadOnlyEdit			m_editErrorStatus;			//报警显示Edit
	CString						m_strErrorStatus;				//报警内容

};
