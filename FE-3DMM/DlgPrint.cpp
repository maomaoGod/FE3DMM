// DlgPrint.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgPrint.h"
#include "afxdialogex.h"


// CDlgPrint 对话框

IMPLEMENT_DYNAMIC(CDlgPrint, CDialog)

CDlgPrint::CDlgPrint(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrint::IDD, pParent)
{
	m_pProCore								= pProCore;
	m_pCustomeTab						= NULL;
	m_pDlgPrintParamAdjust		= NULL;
	m_pDlgPrintMotionControl	= NULL;
	m_pDlgPrintPrintOperate		= NULL;
}

CDlgPrint::~CDlgPrint()
{
	Release();
}

void CDlgPrint::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPrint, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_NOTIFY(NM_CLICK, IDC_PRINT_TABCTRL, &CDlgPrint::OnCustomeTabChange)
END_MESSAGE_MAP()


// CDlgPrint 消息处理程序


void CDlgPrint::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}

void CDlgPrint::OnCancel()
{
	DestroyWindow();
}


void CDlgPrint::Cancel()
{
	//先退出打印线程
	if (NULL != m_pProCore)
	{
		m_pProCore->GetProPrint()->ExitPrintThread();
	}

	Sleep(500);    //等待线程退出

	//关闭子窗口Cancel();
	m_pDlgPrintParamAdjust->Cancel();
	m_pDlgPrintMotionControl->Cancel();
	m_pDlgPrintPrintOperate->Cancel();

	OnCancel();
}


void CDlgPrint::Release()
{
	if (NULL != m_pCustomeTab)
	{
		delete m_pCustomeTab;
		m_pCustomeTab = NULL;
	}
}


HBRUSH CDlgPrint::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_PRINT_TAB_STATIC:
		case IDC_PRINT_SUWIN_STATIC:
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlgPrint::OnEraseBkgnd(CDC* pDC)
{
	CDC MemDC; 
	//CBitmap对象
	CBitmap Bitmap,*pOldBitmap; 
	//BITMAP句柄
	BITMAP bm; 
	//加载位图
	Bitmap.LoadBitmap(IDB_BITMAP_SUBDLG_BG); 
	//将位图资源与句柄绑定
	Bitmap.GetObject(sizeof(BITMAP),&bm); 
	//创建与内存兼容的DC
	MemDC.CreateCompatibleDC(pDC); 
	//替换原位图
	pOldBitmap=(CBitmap*)(MemDC.SelectObject(&Bitmap)); 

	//获取绘制的区域
	CRect rcClient;
	GetClientRect(&rcClient); 

	//绘制到客户区
	pDC->BitBlt(0,0,rcClient.Width(),rcClient.Height(),&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC(); 
	return TRUE;
}


BOOL CDlgPrint::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitCustomeTab();
	CreateSubWindow();
	ShowSubWindow(0);

	return TRUE;
}


bool CDlgPrint::InitCustomeTab()
{
	bool bResult = false;
	m_pCustomeTab = new CD2DCustomeTable();
	if (NULL != m_pCustomeTab)
	{
		m_pCustomeTab->InitializeButtonSize(3);
		CRect rect;
		GetDlgItem(IDC_PRINT_TAB_STATIC)->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.top = 0;
		rect.left = 0;
		m_pCustomeTab->Create(this, rect, IDC_PRINT_TABCTRL);

		CStringArray nameArray;
		nameArray.Add(_T("运动控制"));
		nameArray.Add(_T("参数调节"));
		nameArray.Add(_T("打印操作"));

		m_pCustomeTab->InitializeButtonName(nameArray);
		m_pCustomeTab->ShowWindow(SW_SHOW);
		bResult = true;
	}

	return bResult;
}


void CDlgPrint::OnCustomeTabChange(NMHDR *pNMHDR,LRESULT * pResult)
{
	TBNOTIFY *pNotify = (TBNOTIFY*)(pNMHDR);
	int nChioce = pNotify->iItem;

	ShowSubWindow(nChioce);
}


void CDlgPrint::CreateSubWindow()
{
	m_pDlgPrintMotionControl = new CDlgPrintMotionControl(m_pProCore);
	ASSERT(m_pDlgPrintMotionControl);
	m_pDlgPrintMotionControl->Create(IDD_DLG_PRINT_MOTION, GetDlgItem(IDC_PRINT_SUWIN_STATIC));

	m_pDlgPrintParamAdjust = new CDlgPrintParamAdjust(m_pProCore);
	ASSERT(m_pDlgPrintParamAdjust);
	m_pDlgPrintParamAdjust->Create(IDD_DLG_PRINT_PARAM, GetDlgItem(IDC_PRINT_SUWIN_STATIC));

	m_pDlgPrintPrintOperate = new CDlgPrintPrintOperate(m_pProCore);
	ASSERT(m_pDlgPrintPrintOperate);
	m_pDlgPrintPrintOperate->Create(IDD_DLG_PRINT_PRINTING, GetDlgItem(IDC_PRINT_SUWIN_STATIC));

	m_listSubWindow.AddTail(m_pDlgPrintMotionControl);
	m_listSubWindow.AddTail(m_pDlgPrintParamAdjust);
	m_listSubWindow.AddTail(m_pDlgPrintPrintOperate);
}

void CDlgPrint::ShowSubWindow(int iIndex)
{
	int iCount = m_listSubWindow.GetSize();
	if (!m_listSubWindow.IsEmpty())
	{
		for (int i = 0; i < iCount; i++)
		{
			POSITION pos = m_listSubWindow.FindIndex(i);
			CDialog *pDlgTemp = m_listSubWindow.GetAt(pos);

			if (i == iIndex)
				pDlgTemp->ShowWindow(SW_SHOW);
			else
				pDlgTemp->ShowWindow(SW_HIDE);		
		}
	}
}

BOOL CDlgPrint::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}
