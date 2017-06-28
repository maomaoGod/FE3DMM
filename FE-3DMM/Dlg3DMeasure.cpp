// Dlg3DMeasure.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "Dlg3DMeasure.h"
#include "afxdialogex.h"


// CDlg3DMeasure 对话框

IMPLEMENT_DYNAMIC(CDlg3DMeasure, CDialog)

CDlg3DMeasure::CDlg3DMeasure(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlg3DMeasure::IDD, pParent)
{
	m_pProCore				= pProCore;
	m_pCustomeTab			= NULL;
	m_pDlg3DMeasureScan		= NULL;
	m_pDlg3DMeasureMatch	= NULL;

}

CDlg3DMeasure::~CDlg3DMeasure()
{
	Release();
}

void CDlg3DMeasure::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg3DMeasure, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_NOTIFY(NM_CLICK, IDC_3DMEASURE_TABCTRL, &CDlg3DMeasure::OnCustomeTabChange)
END_MESSAGE_MAP()


// CDlg3DMeasure 消息处理程序


void CDlg3DMeasure::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlg3DMeasure::OnCancel()
{
//	DestroyWindow();
}


void CDlg3DMeasure::Cancel()
{
	//先子窗口Cancel();
	m_pDlg3DMeasureScan->Cancel();
	m_pDlg3DMeasureMatch->Cancel();
	OnCancel();
}


void CDlg3DMeasure::Release()
{
	if (NULL != m_pCustomeTab)
	{
		delete m_pCustomeTab;
		m_pCustomeTab = NULL;
	}
}


HBRUSH CDlg3DMeasure::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_3DMEASURE_TAB_STATIC:
		case IDC_3DMEASURE_SUWIN_STATIC:
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlg3DMeasure::OnEraseBkgnd(CDC* pDC)
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

BOOL CDlg3DMeasure::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitCustomeTab();
	CreateSubWindow();
	ShowSubWindow(0);

	return TRUE;  
}


bool CDlg3DMeasure::InitCustomeTab()
{
	bool bResult = false;
	m_pCustomeTab = new CD2DCustomeTable();
	if (NULL != m_pCustomeTab)
	{
		m_pCustomeTab->InitializeButtonSize(2);
		CRect rect;
		GetDlgItem(IDC_3DMEASURE_TAB_STATIC)->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.top = 0;
		rect.left = 0;
		m_pCustomeTab->Create(this, rect, IDC_3DMEASURE_TABCTRL);

		CStringArray nameArray;
		nameArray.Add(_T("三维扫描 "));
		nameArray.Add(_T("模型匹配"));

		m_pCustomeTab->InitializeButtonName(nameArray);
		m_pCustomeTab->ShowWindow(SW_SHOW);
		bResult = true;
	}

	return bResult;
}

void CDlg3DMeasure::OnCustomeTabChange(NMHDR *pNMHDR,LRESULT * pResult)
{
	TBNOTIFY *pNotify = (TBNOTIFY*)(pNMHDR);
	int nChioce = pNotify->iItem;

	ShowSubWindow(nChioce);
}

void CDlg3DMeasure::CreateSubWindow()
{
	m_pDlg3DMeasureScan = new CDlg3DMeasureScan(m_pProCore);
	ASSERT(m_pDlg3DMeasureScan);
	m_pDlg3DMeasureScan->Create(IDD_DLG_3DMEASURE_SCAN, GetDlgItem(IDC_3DMEASURE_SUWIN_STATIC));

	m_pDlg3DMeasureMatch = new CDlg3DMeasureMatch(m_pProCore);
	ASSERT(m_pDlg3DMeasureMatch);
	m_pDlg3DMeasureMatch->Create(IDD_DLG_3DMEASURE_MATCH, GetDlgItem(IDC_3DMEASURE_SUWIN_STATIC));

	m_listSubWindow.AddTail(m_pDlg3DMeasureScan);
	m_listSubWindow.AddTail(m_pDlg3DMeasureMatch);
}

void CDlg3DMeasure::ShowSubWindow(int iIndex)
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
