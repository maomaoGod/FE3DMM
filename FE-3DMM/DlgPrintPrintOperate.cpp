// DlgPrintPrintControl.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgPrintPrintOperate.h"
#include "afxdialogex.h"


// CDlgPrintPrintOperate 对话框

IMPLEMENT_DYNAMIC(CDlgPrintPrintOperate, CDialog)

enum {TIME_UPDATE_STATE = 0, TIME_PROG_MONITOR};

CDlgPrintPrintOperate::CDlgPrintPrintOperate(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrintPrintOperate::IDD, pParent)
{
	m_pProCore = pProCore;
	m_strUgFileName = _T("");
	m_strUgFilePath = _T("");
	m_dPrintSpeed = 0.0;
}


CDlgPrintPrintOperate::~CDlgPrintPrintOperate()
{
	Release();
}


void CDlgPrintPrintOperate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRINT_PR_GB1_GROUP, m_GB1);
	DDX_Control(pDX, IDC_PRINT_PR_GB2_GROUP, m_GB2);
	DDX_Control(pDX, IDC_PRINT_PR_GB3_GROUP, m_GB3);
	DDX_Control(pDX, IDC_PRINT_PR_Printing_PROGRESS, m_progressPrint);
}


BEGIN_MESSAGE_MAP(CDlgPrintPrintOperate, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_PRINT_PR_LoadUGFile_BTN, &CDlgPrintPrintOperate::OnBnClickedPrintPrLoadUGfileBtn)
	ON_BN_CLICKED(IDC_PRINT_PR_StartPrint_BTN, &CDlgPrintPrintOperate::OnBnClickedPrintPrStartprintBtn)
	ON_BN_CLICKED(IDC_PRINT_PR_StopPrint_BTN, &CDlgPrintPrintOperate::OnBnClickedPrintPrStopprintBtn)
	ON_BN_CLICKED(IDC_PRINT_PR_LinkPrint_BTN, &CDlgPrintPrintOperate::OnBnClickedPrintPrLinkprintBtn)
	ON_BN_CLICKED(IDC_PRINT_PR_PausePrint_BTN, &CDlgPrintPrintOperate::OnBnClickedPrintPrPauseprintBtn)
	ON_BN_CLICKED(IDC_PRINT_PR_ContinuePrint_BTN, &CDlgPrintPrintOperate::OnBnClickedPrintPrContinueprintBtn)
	ON_BN_CLICKED(IDC_PRINT_PR_CameraSlopeWatch_RADIO, &CDlgPrintPrintOperate::OnBnClickedPrintPrCameraslopewatchRadio)
END_MESSAGE_MAP()


// CDlgPrintPrintOperate 消息处理程序
void CDlgPrintPrintOperate::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlgPrintPrintOperate::OnCancel()
{
	DestroyWindow();
}


void CDlgPrintPrintOperate::Cancel()
{
	KillTimer(TIME_UPDATE_STATE);   //关闭定时器
	KillTimer(TIME_PROG_MONITOR);

	OnCancel();
}


void CDlgPrintPrintOperate::Release()
{
	
}


HBRUSH CDlgPrintPrintOperate::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_STATIC:
		case IDC_PRINT_PR_CameraSlopeWatch_RADIO:
		case IDC_PRINT_PR_PrintTrace_RADIO:
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlgPrintPrintOperate::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlgPrintPrintOperate::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlgCtrl();
	InitGridList();
	InitProgress();
	InitWindowHandle();

	GetDlgItem(IDC_PRINT_PR_UgFileName_EDIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_LoadUGFile_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);

	SetTimer(TIME_UPDATE_STATE, 1000, NULL);	//启动数据状态更新定时器
	SetTimer(TIME_PROG_MONITOR, 50, NULL);		//启动监测下载程序定时器

	return TRUE;  
}


void CDlgPrintPrintOperate::InitDlgCtrl()
{
	m_GB1.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);

	m_GB2.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);

	m_GB3.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);


	m_bmpBtn[0].SubclassDlgItem(IDC_PRINT_PR_LoadUGFile_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(15);
	m_bmpBtn[0].SetTitle("加载UG文件");

	m_bmpBtn[1].SubclassDlgItem(IDC_PRINT_PR_StartPrint_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(15);
	m_bmpBtn[1].SetTitle("开始");

	m_bmpBtn[2].SubclassDlgItem(IDC_PRINT_PR_StopPrint_BTN, this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(15);
	m_bmpBtn[2].SetTitle("停止");

	m_bmpBtn[3].SubclassDlgItem(IDC_PRINT_PR_LinkPrint_BTN, this);
	m_bmpBtn[3].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[3].SetFont(15);
	m_bmpBtn[3].SetTitle("连线打印");

	m_bmpBtn[4].SubclassDlgItem(IDC_PRINT_PR_PausePrint_BTN, this);
	m_bmpBtn[4].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[4].SetFont(15);
	m_bmpBtn[4].SetTitle("暂停");

	m_bmpBtn[5].SubclassDlgItem(IDC_PRINT_PR_ContinuePrint_BTN, this);
	m_bmpBtn[5].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[5].SetFont(15);
	m_bmpBtn[5].SetTitle("继续");
}


void CDlgPrintPrintOperate::InitGridList()
{
	CRect rcGridList;
	GetDlgItem(IDC_PRINT_PR_StateShow_LIST)->GetClientRect(&rcGridList);
	m_gridListState.Create(rcGridList, GetDlgItem(IDC_PRINT_PR_StateShow_LIST), IDC_PRINT_PR_StateShow_LIST);

	int iFixedCol = 0;
	int iFixedRow = 0;
	int iColNum = 6;
	int iRowNum = 4;

	m_gridListState.SetEditable(FALSE);
	m_gridListState.EnableSelection(FALSE);
	m_gridListState.SetAutoSizeStyle();

	m_gridListState.SetColumnCount(iColNum);
	m_gridListState.SetRowCount(iRowNum);
	m_gridListState.SetFixedColumnCount(iFixedCol);
	m_gridListState.SetFixedRowCount(iFixedRow);

	int col = 0;
	CString strList = _T("");
	GV_ITEM item;
	item.crBkClr = RGB(200, 255, 255);
	item.nFormat = DT_CENTER|DT_WORDBREAK;
	item.mask = GVIF_TEXT|GVIF_BKCLR|GVIF_FORMAT;

	strList.Format(_T("启动时间"));
	item.strText = strList;
	item.row = 0;
	item.col = col;
	m_gridListState.SetItem(&item);

	strList.Format(_T("当前时间"));
	item.strText = strList;
	item.row = 2;
	item.col = col;
	m_gridListState.SetItem(&item);


	++col;
	strList.Format(_T("流量泵流量"));
	item.strText = strList;
	item.row = 0;
	item.col = col;
	m_gridListState.SetItem(&item);

	strList.Format(_T("电压峰值"));
	item.strText = strList;
	item.row = 2;
	item.col = col;
	m_gridListState.SetItem(&item);

	++col;
	strList.Format(_T("打印起点X"));
	item.strText = strList;
	item.row = 0;
	item.col = col;
	m_gridListState.SetItem(&item);

	strList.Format(_T("打印起点Y"));
	item.strText = strList;
	item.row = 2;
	item.col = col;
	m_gridListState.SetItem(&item);

	++col;
	strList.Format(_T("X位置"));
	item.strText = strList;
	item.row = 0;
	item.col = col;
	m_gridListState.SetItem(&item);

	strList.Format(_T("Y位置"));
	item.strText = strList;
	item.row = 2;
	item.col = col;
	m_gridListState.SetItem(&item);

	++col;
	strList.Format(_T("X速度"));
	item.strText = strList;
	item.row = 0;
	item.col = col;
	m_gridListState.SetItem(&item);

	strList.Format(_T("Y速度"));
	item.strText = strList;
	item.row = 2;
	item.col = col;
	m_gridListState.SetItem(&item);

	++col;
	strList.Format(_T("X电机状态"));
	item.strText = strList;
	item.row = 0;
	item.col = col;
	m_gridListState.SetItem(&item);

	strList.Format(_T("Y电机状态"));
	item.strText = strList;
	item.row = 2;
	item.col = col;
	m_gridListState.SetItem(&item);

	int iListWid = rcGridList.Width() - 5;
	int iListHei = rcGridList.Height() - 5;
	for (int i=0; i<m_gridListState.GetColumnCount(); i++ )
	{
		m_gridListState.SetColumnWidth(i, iListWid/m_gridListState.GetColumnCount());
	}

	for (int j=0; j<m_gridListState.GetRowCount(); j++)
	{
		m_gridListState.SetRowHeight(j, iListHei/m_gridListState.GetRowCount());
	}

	m_gridListState.UpdateData(FALSE);
}


void CDlgPrintPrintOperate::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nIDEvent)
	{
	case TIME_UPDATE_STATE:
		UpdateGridList();
		break;

	case TIME_PROG_MONITOR:
		if (NULL != m_pProCore)
		{
			m_pProCore->GetProPrint()->MonitorProg();
		}
		break;

	default:
		break;
	}

	CDialog::OnTimer(nIDEvent);
}


void CDlgPrintPrintOperate::UpdateGridList()
{
	//使用定时器，隔一段时间更新一次
}


void CDlgPrintPrintOperate::InitProgress()
{
	m_progressPrint.SetRange(0, 100);
	m_progressPrint.SetPos(1);
	m_progressPrint.ShowPercent(true);
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrLoadUGfileBtn()
{
	CFileDialog OpenDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY|OFN_EXPLORER, _T("TXT File(*.txt)|*.txt|All Files(*.*)|*.*||"), NULL);
	OpenDlg.m_ofn.lpstrTitle = _T("Open UG File");
	if (OpenDlg.DoModal() == IDOK)
	{
		m_strUgFilePath = OpenDlg.GetFolderPath();
		m_strUgFileName = OpenDlg.GetFileName();
		GetDlgItem(IDC_PRINT_PR_UgFileName_EDIT)->SetWindowText(m_strUgFileName);
		
		if (NULL != m_pProCore)
		{
			m_pProCore->GetProPrint()->OpenGCodeFile(m_strUgFilePath + "\\" + m_strUgFileName);
		}

		GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(TRUE);
		GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(TRUE);
		GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);
	}
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrStartprintBtn()
{
	//并开启定时器，获取基代码打印行位置，并根据打印行数估计进度条的位置（和轨迹图像上打印进度）
	if (NULL != m_pProCore)
	{
		m_pProCore->GetProPrint()->m_bIsLinesPrint = false;
		m_pProCore->GetProPrint()->StartPrint();
	}
	
	GetDlgItem(IDC_PRINT_PR_LoadUGFile_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrStopprintBtn()
{
	if (NULL != m_pProCore)
	{
		m_pProCore->GetProPrint()->StopPrint();
	}

	GetDlgItem(IDC_PRINT_PR_LoadUGFile_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrLinkprintBtn()
{
	if (NULL != m_pProCore)
	{
		m_pProCore->GetProPrint()->m_bIsLinesPrint = true;
		m_pProCore->GetProPrint()->StartPrint();
	}
	
	GetDlgItem(IDC_PRINT_PR_LoadUGFile_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrPauseprintBtn()
{
	if (NULL != m_pProCore)
	{
		m_pProCore->GetProPrint()->PausePrint();
	}

	GetDlgItem(IDC_PRINT_PR_LoadUGFile_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(TRUE);
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrContinueprintBtn()
{
	if (NULL != m_pProCore)
	{
		m_pProCore->GetProPrint()->ContinuePrint();
	}

	GetDlgItem(IDC_PRINT_PR_LoadUGFile_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StartPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_StopPrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_LinkPrint_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PRINT_PR_PausePrint_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PRINT_PR_ContinuePrint_BTN)->EnableWindow(FALSE);
}


BOOL CDlgPrintPrintOperate::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		if (GetFocus() == GetDlgItem(IDC_PRINT_PR_PrintSpeed_EDIT))
		{
			CString strTemp = _T("");
			double dEditValue = 0.0;
			GetDlgItem(IDC_PRINT_PR_PrintSpeed_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);

			if (dEditValue <= 0.0)
			{
				dEditValue = 0.0;
				strTemp.Format(_T("%.4f"), dEditValue);
				GetDlgItem(IDC_PRINT_PR_PrintSpeed_EDIT)->SetWindowText(strTemp);
			}
			else if (dEditValue >= 350.0)
			{
				dEditValue = 350.0;
				strTemp.Format(_T("%.4f"), dEditValue);
				GetDlgItem(IDC_PRINT_PR_PrintSpeed_EDIT)->SetWindowText(strTemp);
			}

			m_dPrintSpeed = dEditValue;
		}

		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}


void CDlgPrintPrintOperate::InitWindowHandle()
{
	SetCheck("~father");
	Hlong hlWnd;
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_PRINT_PR_PicShow_STATIC);
	hlWnd = (Hlong)(pWnd ->GetSafeHwnd());
	CRect rc; 
	pWnd->GetClientRect(&rc);
	m_winSize_Pic.width = rc.Width();
	m_winSize_Pic.height = rc.Height();

	OpenWindow(0, 0, rc.Width(), rc.Height(), hlWnd, "", "", &m_windowHandle_Pic);
	SetPart(m_windowHandle_Pic, 0, 0, rc.Height()-1, rc.Width()-1);
	SetColor(m_windowHandle_Pic, "yellow");
	SetWindowAttr("background_color", "black");
	SetCheck("father");
}


void CDlgPrintPrintOperate::OnBnClickedPrintPrCameraslopewatchRadio()
{
	if (NULL == m_pProCore) return;
	m_pProCore->SwitchCamera(PRINT_ASKANT);
	m_pProCore->SetShowInfo(PRINT_ASKANT, m_windowHandle_Pic, m_winSize_Pic);
}
