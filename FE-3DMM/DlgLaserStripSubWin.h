#pragma once
#include "DlgLaserStripSWScanPath.h"
#include "DlgLaserStripSWParamRecord.h"


// CDlgLaserStripSubWin 对话框
enum ScanMode{EMPTY = 0, SingleROW, MultiROW};
typedef struct st_ParamScan
{
	ScanMode		 scanmode;
	ParamSingleScan  paramSingleScan;
	ParamMultiScan	 paramMultiScan;

	st_ParamScan()
	{
		scanmode = EMPTY;
	}
}ParamScan;


class CDlgLaserStripSubWin : public CDialog
{
	DECLARE_DYNAMIC(CDlgLaserStripSubWin)

public:
	CDlgLaserStripSubWin(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgLaserStripSubWin();

// 对话框数据
	enum { IDD = IDD_DLG_LASERSTRIP_SUBWIN };

	void Cancel();									//销毁窗口及子窗口
	void InitDlgCtrl();
	ParamScan* GetParamScan();		//获取扫描参数指针
	void SetParamInStatic();					//设置扫描参数至Static控件
	CDlgLaserStripSWScanPath* GetDlgLaserStripSWScanPath();  //获取DlgLaserStripSWScanPath对话框指针

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedLaserstripSContiMoveRadio();
	afx_msg void OnBnClickedLaserstripSInterMoveRadio();
	afx_msg void OnDeltaposLaserstripSContiMoveSpeedSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposLaserstripSInterMoveStepSpin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedLaserstripSubwinXLBtn();
	afx_msg void OnClickedLaserstripSubwinXRBtn();
	afx_msg void OnClickedLaserstripSubwinYBBtn();
	afx_msg void OnClickedLaserstripSubwinYFBtn();
	afx_msg void OnClickedLaserstripSFastMoveBtn();
	afx_msg void OnClickedLaserstripSStartStripBtn();
	afx_msg void OnClickedLaserstripSToHomeBtn();
	afx_msg void OnBnClickedLaserstripSScanPathSetBtn();
	afx_msg void OnBnClickedLaserstripSPathParamSaveBtn();
	afx_msg void OnBnClickedLaserstripSLaserConfigBtn();
	afx_msg void OnBnClickedLaserstripSCameraRadio();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();																//释放本窗口中其他new堆内存
	void SetMoveComponentState();							//设置运动控制组件状态
	void ShowBmpInStatic();											//将Bmp显示至Static控件中
	void InitWindowHandle();											//初始化Pic控件显示窗口

private:
	CXPGroupBox					 m_GB1;
	CXPGroupBox					 m_GB2;
	CXPGroupBox					 m_GB3;
	CBmpBtn							m_bmpBtn[10];
	CProcessCore					*m_pProCore;					//主操作类指针
	bool									m_bScanPathSet;				//是否设置扫描路径
	bool									m_bPathParamSave;		//是否保存路径参数
	bool									m_bContinuousMove;	//true连续  false点动
	double								m_dContinMoveSpeed;
	double								m_dInterMoveStep;
	double								m_dFastMoveXPos;
	double								m_dFastMoveYPos;
	ParamScan				 			m_paramscan;					//扫描参数
	HTuple								m_windowHandle_Pic;	//Pic控件关联的Halcon窗口句柄
	Size										m_winSize_Pic;					//Pic窗口大小
	CDlgLaserStripSWScanPath*	 m_pDlgLaserStripSWScanPath;	//扫描路径设置窗口
	CDlgLaserStripSWParamRecord* m_pDlgLaserStripSWParamRecord;	//扫描参数记录窗口
	
	
};
