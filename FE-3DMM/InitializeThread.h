#pragma once
#include "DlgInitialize.h"


// CInitializeThread

class CInitializeThread : public CWinThread
{
	DECLARE_DYNCREATE(CInitializeThread)

protected:
	CInitializeThread();           // 动态创建所使用的受保护的构造函数
	virtual ~CInitializeThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnUIThreadMessage(WPARAM wParam,LPARAM lParam);    //用户界面线程消息响应函数

private:
	BOOL CreateInitDialog();

private:
	CDlgInitialize*  m_pDlgInitialize;
};


