#pragma once
#include "DlgLaserStripSWScanPathSingleRow.h"
#include "DlgLaserStripSWScanPathMultiRow.h"
class CDlgLaserStripSubWin;


// CDlgLaserStripSWScanPath 对话框

class CDlgLaserStripSWScanPath : public CDialog
{
	DECLARE_DYNAMIC(CDlgLaserStripSWScanPath)

public:
	CDlgLaserStripSWScanPath(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLaserStripSWScanPath();

// 对话框数据
	enum { IDD = IDD_DLG_LASERSTRIP_SUB_SCANPATH };

	void Cancel();						//销毁窗口及子窗口
	void ApplyScanParamToPathWin();     //应用扫描参数至路径规划窗口


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedLaserstripSubSpSinglerowRadio();
	afx_msg void OnBnClickedLaserstripSubSpMultirowRadio();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:  
	void Release();			//释放本窗口中其他new堆内存
	void ShowSubDlg(INT singlerow, INT multirow);

private:
	CDlgLaserStripSubWin*					m_pDlgLaserStripSubWinMain;	//主窗口SubWin
	CDlgLaserStripSWScanPathSingleRow*		m_pDlgLaserStripSingleRow;  //单行路径扫描子窗口
	CDlgLaserStripSWScanPathMultiRow*		m_pDlgLaserStripMultiRow;   //多行路径扫描子窗口
	
};
