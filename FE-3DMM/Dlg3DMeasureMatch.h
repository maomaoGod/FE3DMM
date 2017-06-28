#pragma once
#include ".\3DMeasure\DataStructure.h"
#include ".\3DMeasure\iCloud3D_Operator.h"
#include ".\3DMeasure\BlendHandle.h"
#include ".\3DMeasure\Calculate.h"
#include ".\3DMeasure\OpenGLView.h"
#include ".\3DMeasure\COpenGL.h"
#include "resource.h"

// CDlg3DMeasureMatch 对话框

class CDlg3DMeasureMatch : public CDialog
{
	DECLARE_DYNAMIC(CDlg3DMeasureMatch)

public:
	CDlg3DMeasureMatch(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg3DMeasureMatch();

// 对话框数据
	enum { IDD = IDD_DLG_3DMEASURE_MATCH };

	void Cancel();				//销毁窗口及子窗口
//	void InitDlgCtrl();

public:
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	virtual BOOL OnInitDialog();
public:
	iCloudOperator m_PtOperator;
	TDSVec3DPt m_SetPtTest;
	CDS3DPtNor pt;
	CDS3DPt pt1;
	CEdit m_MatchTimes;
	CEdit m_AdfMu;
	int m_nIterTimes;
	float m_Mu;
	CDSChrom res_Errtemp;
	CHandleADF HandleADF;
	vector<CDS3DPtNor> m_ptMoving;	//移动点集
	vector<CDS3DPtNor> m_ptFixed;	//固定点集

	vector<float> mtDist;//修改添加的3/18
	double given_error;//用户给定的误差
	double rate_given_1;//用户给定的百分比
	bool pass_whether_f;//误差是否通过

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	COpenGLView *m_viewOpenGL;
	virtual void PostNcDestroy();
	virtual void OnCancel();
	
private:
	void Release();				//释放本窗口中其他new堆内存


private:
	CXPGroupBox			m_GB1;
	CXPGroupBox			m_GB2;
	CProcessCore		*m_pProCore;	//主操作类指针
public:
	afx_msg void OnBnClicked3dmeasureMOpenTest();
	afx_msg void OnBnClicked3dmeasureMOpenRef();
	afx_msg void OnBnClicked3dmeasureMBlend();
	afx_msg void OnEnChange3dmeasureMBlendtime();
	afx_msg void OnEnChange3dmeasureMBlendmu();
	afx_msg void OnBnClicked3dmeasureMOnchrom();
	afx_msg void OnBnClicked3dmeasureMOffchrom();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangenumber();
	afx_msg void OnEnChangedown();
	afx_msg void OnEnChangeup();
	afx_msg void OnEnChangeupon();
	afx_msg void OnEnChangedow();
	afx_msg void OnEnChangegiven();
	afx_msg void OnEnChangeactual();
	afx_msg void OnEnChangegivenpercent();
	afx_msg void OnEnChangewhether();
	afx_msg void OnBnClickedConfirm();
	CString m_sec_number;
	CString m_acceptance_down;
	CString m_minNom;
	CString m_acceptance_up;
	CString m_mea_down;
	CString m_mea_up;
	CString m_mea_dow;
	CString m_error_given;
	CString m_pass_whether;
	CString m_rate_given;
	double m_rate_actual;
};
