// InitializeThread.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "InitializeThread.h"


// CInitializeThread

IMPLEMENT_DYNCREATE(CInitializeThread, CWinThread)

CInitializeThread::CInitializeThread()
{
	m_pDlgInitialize = NULL;
}

CInitializeThread::~CInitializeThread()
{
}

BOOL CInitializeThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int CInitializeThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CInitializeThread, CWinThread)
	ON_THREAD_MESSAGE(UM_INITIALIZE, &CInitializeThread::OnUIThreadMessage)
END_MESSAGE_MAP()


// CInitializeThread 消息处理程序

void CInitializeThread::OnUIThreadMessage(WPARAM wParam,LPARAM lParam)
{
	UINT nSelect = wParam;

	switch(nSelect)
	{
	case 0:
		CreateInitDialog();
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->m_editInit.SetWindowText(_T("控制卡正在初始化..."));
			CButton* pBtn = (CButton*)(m_pDlgInitialize->GetDlgItem(IDC_INIT_ControlCard_CHECK));
			pBtn->SetCheck(1);
		}
		break;
		
	case 1:
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->m_editInit.SetWindowText(_T("函数发生器正在初始化..."));
			m_pDlgInitialize->m_progressInit.SetPos(lParam);
			CButton* pBtn = (CButton*)(m_pDlgInitialize->GetDlgItem(IDC_INIT_AglientFunc_CHECK));
			pBtn->SetCheck(1);
		}
		break;

	case 2:
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->m_editInit.SetWindowText(_T("精密流量泵正在初始化..."));
			m_pDlgInitialize->m_progressInit.SetPos(lParam);
			CButton* pBtn = (CButton*)(m_pDlgInitialize->GetDlgItem(IDC_INIT_HarvardPump_CHECK));
			pBtn->SetCheck(1);
		}
		break;

	case 3:
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->m_editInit.SetWindowText(_T("设备初始化完成！"));
			m_pDlgInitialize->m_progressInit.SetPos(lParam);
		}
		break;

	case 4:
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->InitFinish();
		}
		break;

	case 5:
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->m_editInit.SetWindowText(_T("设备初始化失败，正在退出..."));
		}
		break;
	case 6:
		if (NULL != m_pDlgInitialize)
		{
			m_pDlgInitialize->InitExit();
		}
		break;

	default:
		break;
	}
}
	
BOOL CInitializeThread::CreateInitDialog()
{
	if (NULL != m_pDlgInitialize)
	{
		return FALSE;
	}

	m_pDlgInitialize = new CDlgInitialize();
	ASSERT(m_pDlgInitialize);
	m_pDlgInitialize->Create(IDD_DLG_INITIALIZE);
	m_pDlgInitialize->CenterWindow();
	m_pDlgInitialize->ShowWindow(SW_SHOWNORMAL);

	return TRUE;
}