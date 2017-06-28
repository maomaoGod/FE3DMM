#pragma once
#include "afxwin.h"


// CDlgTransferVisionTrain 对话框

class CDlgTransferVisionTrain : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransferVisionTrain)

public:
	CDlgTransferVisionTrain(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransferVisionTrain();

// 对话框数据
	enum { IDD = IDD_DLG_TRANSFER_VISION };
	enum {NCC = 0, SHAPE};
	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();
	
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedTransferVCameraTransUpRadio();
	afx_msg void OnBnClickedTransferVCameraTransDownRadio();
	afx_msg void OnBnClickedTransferVCameraliveCheck();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();				//释放本窗口中其他new堆内存
	void SetTransCameraType(const CameraType camtype);  //设置转印相机的类型
	void UpdateModelList();
	void InitHalconWindow();

private:
	CXPGroupBox						m_GB1;
	CXPGroupBox						m_GB2;
	CXPGroupBox						m_GB3;
	CBmpBtn								m_bmpBtn[4];
	CComboBox                         m_cComBoxObject;
	CProcessCore						*m_pProCore;						//主操作类指针
	CImageShowStatic				m_staticPicShow;
	CameraType							m_cameratypeTrans;			//转印相机的类型
	CImageOperate					m_imgoperTransUp;			//转印上视图像操作
	CImageOperate					m_imgoperTransDown;		//转印下视图像操作
	HTuple                                   m_hvModelWindow;          //显示模板图像窗口
	HObject                                 m_hoImageModel;
	CListCtrlCl                              m_cModelList;
	int                                            m_iTransferType; 
	int                                            m_iMatchType;
public:
	afx_msg void OnBnClickedTransferVInitiativeRadio();
	afx_msg void OnBnClickedTransferVPassivityRadio();
	afx_msg void OnBnClickedTransferVCalibrateBtn();
	afx_msg void OnBnClickedTransferVMakemodelBtn();
	afx_msg void OnBnClickedTransferVModeldelBtn();
	afx_msg void OnNMClickTransferVModelList(NMHDR *pNMHDR, LRESULT *pResult);
};
