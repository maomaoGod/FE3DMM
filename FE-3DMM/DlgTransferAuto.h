#pragma once


// CDlgTransferAuto 对话框

class CDlgTransferAuto : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransferAuto)

public:
	CDlgTransferAuto(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransferAuto();

// 对话框数据
	enum { IDD = IDD_DLG_TRANSFER_AUTO };

	void Cancel();				//销毁窗口及子窗口
	void InitDlgCtrl();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedTransferACameraTransUpRadio();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();																		//释放本窗口中其他new堆内存
	void InitWindowHandle();													//初始化Pic控件显示窗口

private:
	CXPGroupBox					m_GB1;
	CXPGroupBox					m_GB2;
	CXPGroupBox					m_GB3;
	CBmpBtn							m_bmpBtn[4];
	CProcessCore					*m_pProCore;							//主操作类指针
	HTuple								m_windowHandle_Pic;			//Pic控件关联的Halcon窗口句柄
	Size										m_winSize_Pic;							//Pic窗口大小
};
