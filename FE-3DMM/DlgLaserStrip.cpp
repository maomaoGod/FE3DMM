// DlgLaserStrip.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgLaserStrip.h"
#include "afxdialogex.h"


// CDlgLaserStrip 对话框

IMPLEMENT_DYNAMIC(CDlgLaserStrip, CDialog)

CDlgLaserStrip::CDlgLaserStrip(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLaserStrip::IDD, pParent)
{
	m_pProCore				= pProCore;
	m_pCustomeTab			= NULL;
	m_pDlgLaserStripSubwin	= NULL;

}

CDlgLaserStrip::~CDlgLaserStrip()
{
	Release();
}

void CDlgLaserStrip::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLaserStrip, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_CLICK, IDC_LASERSTRIP_TABCTRL, &CDlgLaserStrip::OnCustomeTabChange)
END_MESSAGE_MAP()


// CDlgLaserStrip 消息处理程序


void CDlgLaserStrip::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlgLaserStrip::OnCancel()
{
	DestroyWindow();
}


void CDlgLaserStrip::Cancel()
{
	//先子窗口Cancel();
	m_pDlgLaserStripSubwin->Cancel();
	OnCancel();
}


void CDlgLaserStrip::Release()
{
	if (NULL != m_pCustomeTab)
	{
		delete m_pCustomeTab;
		m_pCustomeTab = NULL;
	}
}


HBRUSH CDlgLaserStrip::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_LASERSTRIP_TAB_STATIC:
		case IDC_LASERSTRIP_SUWIN_STATIC:
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlgLaserStrip::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlgLaserStrip::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitCustomeTab();
	CreateSubWindow();
	ShowSubWindow(0);

	return TRUE;  
}

bool CDlgLaserStrip::InitCustomeTab()
{
	bool bResult = false;
	m_pCustomeTab = new CD2DCustomeTable();
	if (NULL != m_pCustomeTab)
	{
		m_pCustomeTab->InitializeButtonSize(1);
		CRect rect;
		GetDlgItem(IDC_LASERSTRIP_TAB_STATIC)->GetWindowRect(&rect);
		ScreenToClient(&rect);
		rect.top = 0;
		rect.left = 0;
		m_pCustomeTab->Create(this, rect, IDC_LASERSTRIP_TABCTRL);

		CStringArray nameArray;
		nameArray.Add(_T("激光剥离操作"));

		m_pCustomeTab->InitializeButtonName(nameArray);
		m_pCustomeTab->ShowWindow(SW_SHOW);
		bResult = true;
	}

	return bResult;
}

void CDlgLaserStrip::OnCustomeTabChange(NMHDR *pNMHDR,LRESULT * pResult)
{
	TBNOTIFY *pNotify = (TBNOTIFY*)(pNMHDR);
	int nChioce = pNotify->iItem;

	ShowSubWindow(nChioce);
}

void CDlgLaserStrip::CreateSubWindow()
{
	m_pDlgLaserStripSubwin = new CDlgLaserStripSubWin(m_pProCore);
	ASSERT(m_pDlgLaserStripSubwin);
	m_pDlgLaserStripSubwin->Create(IDD_DLG_LASERSTRIP_SUBWIN, GetDlgItem(IDC_LASERSTRIP_SUWIN_STATIC));

	m_listSubWindow.AddTail(m_pDlgLaserStripSubwin);
}

void CDlgLaserStrip::ShowSubWindow(int iIndex)
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


BOOL CDlgLaserStrip::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}
