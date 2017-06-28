
// FE-3DMM.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "FE-3DMMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFE3DMMApp

BEGIN_MESSAGE_MAP(CFE3DMMApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CFE3DMMApp 构造

CFE3DMMApp::CFE3DMMApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
	m_pInitWorkThread	= NULL;
	m_pInitUIThread		= NULL;
	m_bAglientInitState = false;
	m_bHarvardInitState = false;
	m_bWinMainBegin		= false;
	m_bAppExit			= false;
}


// 唯一的一个 CFE3DMMApp 对象

CFE3DMMApp theApp;


// CFE3DMMApp 初始化

BOOL CFE3DMMApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	//获得.exe路径
	char cExePath[MAX_PATH];
	GetModuleFileName(NULL, cExePath, MAX_PATH);
	m_gAppExePath.Format("%s", cExePath);

	//设备初始化////////////////////jsb先注释，后面调试放开
// 	m_pInitUIThread = (CInitializeThread*)AfxBeginThread(RUNTIME_CLASS(CInitializeThread));
// 	ASSERT(m_pInitUIThread);
// 	m_pInitWorkThread = AfxBeginThread(InitThreadFunc, this);
// 	ASSERT(m_pInitWorkThread);
// 
// 	while(!m_bWinMainBegin)
// 	{
// 		if (m_bAppExit)
// 		{
// 			return FALSE;
// 		}	
// 	}
	////////////////////////////////

	CFE3DMMDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}


HHOOK hHook;
LRESULT __stdcall CBTHookProc(long nCode, WPARAM wParam, LPARAM lParam)
{
	if(nCode == HCBT_ACTIVATE)
	{
		SetDlgItemText((HWND)wParam,IDOK,_T("&忽略并继续"));
		SetDlgItemText((HWND)wParam,IDCANCEL,_T("&退出"));
		UnhookWindowsHookEx(hHook);
	}

	return 0;
}

UINT CFE3DMMApp::InitThreadFunc(LPVOID pVoid)
{
	CFE3DMMApp* pThis = (CFE3DMMApp*)pVoid;			
	
	LONG nNum = 0;
	bool bInitState = true;    //初始化状态(当前设备初始化成功或忽略不成功，才能继续初始化)

	//创建初始化界面
	pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 0, (LPARAM)nNum);

	//初始化控制卡
	nNum = 20;
	//Sleep(100);


	//初始化函数发生器
	if (bInitState)
	{
// 		nNum = 60;
// 		if (TRUE == pThis->m_JetAglientFunc.Connect())
// 		{
// 			pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 2, (LPARAM)nNum);
// 			pThis->m_bAglientInitState = true;
// 		}
// 		else
// 		{
// 			hHook = SetWindowsHookEx(WH_CBT, (HOOKPROC)CBTHookProc, NULL, GetCurrentThreadId());
// 			int nResult = MessageBox(NULL, _T("初始化函数发生器失败！"), _T("函数发生器Error"), MB_OKCANCEL|MB_SYSTEMMODAL);
// 			if (IDCANCEL == nResult)
// 			{
// 				//退出
// 				pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 5, (LPARAM)nNum);
// 				Sleep(300);
// 				pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 6, (LPARAM)nNum);
// 				bInitState = false;
// 			}
// 			else if (IDOK == nResult)
// 			{
// 				//忽略并继续
// 				pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 2, (LPARAM)nNum);
// 			}
// 			pThis->m_bAglientInitState = false;
// 		}
// 		Sleep(500);
	}

	//初始化精密流量泵
	if (bInitState)
	{
// 		nNum = 100;
// 		int nPort = 7;
// 		if (pThis->m_JetHarvardPump.Init(nPort))
// 		{
// 			pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 3, (LPARAM)nNum);
// 			pThis->m_bHarvardInitState = true;
// 		}
// 		else
// 		{
// 			hHook = SetWindowsHookEx(WH_CBT, (HOOKPROC)CBTHookProc, NULL, GetCurrentThreadId());
// 			int nResult = MessageBox(NULL, _T("初始化精密流量泵失败！"), _T("精密流量泵Error"), MB_OKCANCEL|MB_SYSTEMMODAL);
// 			if (IDCANCEL == nResult)
// 			{
// 				//退出
// 				pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 5, (LPARAM)nNum);
// 				Sleep(300);
// 				pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 6, (LPARAM)nNum);
// 				bInitState = false;
// 			}
// 			else if (IDOK == nResult)
// 			{
// 				//忽略并继续
// 				pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 3, (LPARAM)nNum);
// 			}
// 			pThis->m_bHarvardInitState = false;
// 		}
//		Sleep(500);
	}

	if (bInitState)
	{
		pThis->m_pInitUIThread->PostThreadMessage(UM_INITIALIZE, 4, (LPARAM)nNum);
	}

	return 0;
}

