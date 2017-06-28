#pragma once


// CDlgInitialize 对话框

class CDlgInitialize : public CDialog
{
	DECLARE_DYNAMIC(CDlgInitialize)

public:
	CDlgInitialize(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgInitialize();

// 对话框数据
	enum { IDD = IDD_DLG_INITIALIZE };

	void Cancel();				//销毁窗口及子窗口
	void InitFinish();			//初始化完成
	void InitExit();			//初始化退出

public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
	virtual void OnCancel();

private:
	void Release();				//释放本窗口中其他new堆内存
	void InitProgress();
	void InitEdit();


public:
	CGradientProgressCtrl	m_progressInit;
	CCustomEdit				m_editInit;
	
};
