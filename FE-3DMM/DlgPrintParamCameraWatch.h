#pragma once
class CDlgPrintParamAdjust;

// CDlgPrintParamCameraWatch 对话框

class CDlgPrintParamCameraWatch : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrintParamCameraWatch)

public:
	CDlgPrintParamCameraWatch(CProcessCore* pProCore = NULL, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPrintParamCameraWatch();

// 对话框数据
	enum { IDD = IDD_DLG_PRINT_PARAM_CAMERAWATCH };

	void Cancel();				//销毁窗口及子窗口

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnCancel();
	virtual void PostNcDestroy();

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPrintPaCameraFilenameBtn();
	afx_msg void OnBnClickedPrintPaCameraPhotoBtn();
	afx_msg void OnBnClickedPrintPaCameraVideoBtn();
	afx_msg void OnBnClickedPrintPaCameraTickmarkBtn();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	void Release();			//释放本窗口中其他new堆内存
	void InitDlgCtrl();


private:
	CDlgPrintParamAdjust*		m_pDlgParamMain;				//参数调节窗口
	CBmpBtn								m_bmpBtn[4];
	CProcessCore						*m_pProCore;						//主操作类指针
	CImageShowStatic				m_staticPicShow;
	bool										m_bDrawTickMark;				//是否画刻度
	bool										m_bWriteVideo;					//是否写视频
	CString									m_strFileName;					//图片或视频文件的名称
	CString									m_strStorePath;					//文件存储路径
	CString									m_strPhotoAllPath;				//照片文件全路径
	CString									m_strVideoAllPath;				//视频文件全路径
	VideoWriter							m_videoWriter;					//写视频
	CImageOperate					m_imageoperate;				//图像操作
};
