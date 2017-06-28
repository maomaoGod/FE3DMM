// DlgPrintParamAdjust.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgPrintParamAdjust.h"
#include "afxdialogex.h"


// CDlgPrintParamAdjust 对话框

IMPLEMENT_DYNAMIC(CDlgPrintParamAdjust, CDialog)

CDlgPrintParamAdjust::CDlgPrintParamAdjust(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrintParamAdjust::IDD, pParent)
{
	m_pProCore										= pProCore;
	m_bVoltageAirOpen						= false;
	m_bParamDataShow						= false;
	m_bCameraWatchShow					= false;
	m_bForwardOrBackwardFlag		= false;
	m_pDlgPrintParamDataRecord		= NULL;
	m_pDlgPrintParamCameraWatch = NULL;
	m_dDcOffset										= 0.0;
	m_dAcOffset										= 0.0;
	m_dAcFreq										= 0.0;
	m_dAcAmplitude								= 0.0;
	m_dAcRatio										= 0.0;
	m_dAuxiAirPress								= 0.0;
	m_dPumpFlowRate							= 0.0;
	m_dFeedAirFlowRate						= 0.0;

}

CDlgPrintParamAdjust::~CDlgPrintParamAdjust()
{
	Release();
}

void CDlgPrintParamAdjust::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRINT_PA_GB1_GROUP, m_GB1);
	DDX_Control(pDX, IDC_PRINT_PA_GB2_GROUP, m_GB2);
}


BEGIN_MESSAGE_MAP(CDlgPrintParamAdjust, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_PRINT_PA_VoltageAirOpen_BTN, &CDlgPrintParamAdjust::OnBnClickedPrintPaVoltageAirOpenBtn)
	ON_BN_CLICKED(IDC_PRINT_PA_PumpMode_RADIO, &CDlgPrintParamAdjust::OnBnClickedPrintPaPumpmodeRadio)
	ON_BN_CLICKED(IDC_PRINT_PA_FeedAirPressMode_RADIO, &CDlgPrintParamAdjust::OnBnClickedPrintPaFeedAirPressmodeRadio)
	ON_BN_CLICKED(IDC_PRINT_PA_DataRecord_BTN, &CDlgPrintParamAdjust::OnBnClickedPrintPaDataRecordBtn)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(UM_IDM_PRINT_CAMERAWATCH_SHOW, OnUMCameraWatchShow)
	ON_BN_CLICKED(IDC_PRINT_PA_ModeDC_RADIO, &CDlgPrintParamAdjust::OnBnClickedPrintPaDcModeRadio)
	ON_BN_CLICKED(IDC_PRINT_PA_ModeAC_RADIO, &CDlgPrintParamAdjust::OnBnClickedPrintPaAcModeRadio)
	ON_BN_CLICKED(IDC_PRINT_PA_FlowStart_BTN, &CDlgPrintParamAdjust::OnBnClickedPrintPaFlowstartBtn)
	ON_BN_CLICKED(IDC_PRINT_PA_FlowStop_BTN, &CDlgPrintParamAdjust::OnBnClickedPrintPaFlowstopBtn)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PRINT_PA_DutyRatio_SPIN, &CDlgPrintParamAdjust::OnDeltaposPrintPaDutyratioSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PRINT_PA_AuxiAirPress_SPIN, &CDlgPrintParamAdjust::OnDeltaposPrintPaAuxiairpressSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PRINT_PA_Amplitude_SPIN, &CDlgPrintParamAdjust::OnDeltaposPrintPaAmplitudeSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PRINT_PA_Freq_SPIN, &CDlgPrintParamAdjust::OnDeltaposPrintPaFreqSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PRINT_PA_Offset_SPIN, &CDlgPrintParamAdjust::OnDeltaposPrintPaOffsetSpin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_PRINT_PA_FlowSet_SPIN, &CDlgPrintParamAdjust::OnDeltaposPrintPaFlowsetSpin)
	ON_BN_CLICKED(IDC_PRINT_PA_CameraWatch_RADIO, &CDlgPrintParamAdjust::OnBnClickedPrintPaCamerawatchRadio)
END_MESSAGE_MAP()


// CDlgPrintParamAdjust 消息处理程序
void CDlgPrintParamAdjust::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlgPrintParamAdjust::OnCancel()
{
	DestroyWindow();
}


void CDlgPrintParamAdjust::Cancel()
{
	//先子窗口Cancel();
	m_pDlgPrintParamDataRecord->Cancel();
	m_pDlgPrintParamCameraWatch->Cancel();
	OnCancel();
}


void CDlgPrintParamAdjust::Release()
{

}


HBRUSH CDlgPrintParamAdjust::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_STATIC:
		case IDC_PRINT_PA_CameraWatch_RADIO:
		case IDC_PRINT_PA_ModeDC_RADIO:
		case IDC_PRINT_PA_ModeAC_RADIO:
		case IDC_PRINT_PA_PumpMode_RADIO:
		case IDC_PRINT_PA_FeedAirPressMode_RADIO:
		case IDC_PRINT_PA_FlowSet_STATIC:
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlgPrintParamAdjust::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlgPrintParamAdjust::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlgCtrl();
	InitWindowHandle();
// 	InitFlowAdjustCtrlState(theApp.m_bHarvardInitState);
// 	InitVoltageAirAdjustCtrlState(theApp.m_bAglientInitState);

	CheckRadioButton(IDC_PRINT_PA_ModeDC_RADIO, IDC_PRINT_PA_ModeAC_RADIO, IDC_PRINT_PA_ModeDC_RADIO);
	m_enumVolMode = DcMode;
	SetVoltageComponentState(true, false, false, false);

	CheckRadioButton(IDC_PRINT_PA_PumpMode_RADIO, IDC_PRINT_PA_FeedAirPressMode_RADIO, IDC_PRINT_PA_PumpMode_RADIO);
	m_enumFlowAdjPattern = PumpPattern;
	SetFlowComponentState(true, true, true, true, false);

	m_pDlgPrintParamDataRecord = new CDlgPrintParamDataRecord(this);
	ASSERT(m_pDlgPrintParamDataRecord);
	m_pDlgPrintParamDataRecord->Create(IDD_DLG_PRINT_PARAM_DATARECORD);

	m_pDlgPrintParamCameraWatch = new CDlgPrintParamCameraWatch(m_pProCore, this);
	ASSERT(m_pDlgPrintParamCameraWatch);
	m_pDlgPrintParamCameraWatch->Create(IDD_DLG_PRINT_PARAM_CAMERAWATCH);
	
	return TRUE;  
}


void CDlgPrintParamAdjust::InitDlgCtrl()
{
	m_GB1.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);

	m_GB2.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);

	m_bmpBtn[0].SubclassDlgItem(IDC_PRINT_PA_VoltageAirOpen_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(15);
	m_bmpBtn[0].SetTitle("开启");

	m_bmpBtn[1].SubclassDlgItem(IDC_PRINT_PA_FlowForward_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(15);
	m_bmpBtn[1].SetTitle("快进");

	m_bmpBtn[2].SubclassDlgItem(IDC_PRINT_PA_FlowBackward_BTN, this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(15);
	m_bmpBtn[2].SetTitle("快退");

	m_bmpBtn[3].SubclassDlgItem(IDC_PRINT_PA_FlowStart_BTN, this);
	m_bmpBtn[3].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[3].SetFont(15);
	m_bmpBtn[3].SetTitle("启动射流");

	m_bmpBtn[4].SubclassDlgItem(IDC_PRINT_PA_FlowStop_BTN, this);
	m_bmpBtn[4].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[4].SetFont(15);
	m_bmpBtn[4].SetTitle("停止射流");

	m_bmpBtn[5].SubclassDlgItem(IDC_PRINT_PA_DataRecord_BTN, this);
	m_bmpBtn[5].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[5].SetFont(15);
	m_bmpBtn[5].SetTitle("数据记录>>");
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaVoltageAirOpenBtn()
{
	if (!m_bVoltageAirOpen)
	{
		m_bVoltageAirOpen = true;
		m_bmpBtn[0].SetTitle("关闭");

		if (m_enumVolMode == DcMode)
		{
		// 	theApp.m_JetAglientFunc.SetDCMode();
		// 	theApp.m_JetAglientFunc.SetOffset(m_dDcOffset);
		}
		else if (m_enumVolMode == AcMode)
		{
		// 	theApp.m_JetAglientFunc.SetACMode();
		// 	theApp.m_JetAglientFunc.SetOffset(m_dAcOffset);
		// 	theApp.m_JetAglientFunc.SetAmplitude(m_dAcAmplitude);
		// 	theApp.m_JetAglientFunc.SetFrequency(m_dAcFreq);
		//  ::PostMessage(theApp.m_pMainWnd->m_hWnd,WM_FREQ_CHANGED,0,LPARAM(m_dAcFreq));
		// 	theApp.m_JetAglientFunc.SetRatio(m_dAcRatio);
		//	::PostMessageA((theApp.m_pMainWnd->m_hWnd, WM_SET_OUTPUT, 0, 1);
		}
// 		theApp.m_JetAglientFunc.SetOutput(TRUE);
		//此处添加辅助气压打开
	}
	else
	{
		m_bVoltageAirOpen = false;
		m_bmpBtn[0].SetTitle("打开");

// 		theApp.m_JetAglientFunc.SetOutput(FALSE);
		//此处添加辅助气压关闭

// 		if (m_enumVolMode == AcMode)
// 		{
// 			::PostMessage((theApp.m_pMainWnd->m_hWnd, WM_SET_OUTPUT, 0, 0);
// 		}
		
	}

	//刷新按钮
	CRect rc;
	GetDlgItem(IDC_PRINT_PA_VoltageAirOpen_BTN)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	RedrawWindow(&rc);
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaPumpmodeRadio()
{
	m_enumFlowAdjPattern = PumpPattern;

	CString strTemp = _T("");
	strTemp.Format(_T("%.4f"), m_dPumpFlowRate);
	GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->SetWindowText(strTemp);

	//theApp.m_JetHarvardPump.SetInfuseRate((int)m_dPumpFlowRate);
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaFeedAirPressmodeRadio()
{
	m_enumFlowAdjPattern = FeedAirPressPattern;

	CString strTemp = _T("");
	strTemp.Format(_T("%.4f"), m_dFeedAirFlowRate);
	GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->SetWindowText(strTemp);

	//此处添加气压值设置
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaDataRecordBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_bParamDataShow)
	{
		m_bParamDataShow = true;
		m_bmpBtn[5].SetTitle("数据记录<<");
		
		CRect rcMain, rcSub;
		GetDlgItem(IDC_PRINT_PA_GB1_GROUP)->GetWindowRect(&rcMain);
		m_pDlgPrintParamDataRecord->GetWindowRect(&rcSub);	
		m_pDlgPrintParamDataRecord->MoveWindow(rcMain.left, rcMain.bottom-rcSub.Height(), rcSub.Width(), rcSub.Height());
		m_pDlgPrintParamDataRecord->ShowWindow(SW_SHOW);
	}
	else
	{
		m_bParamDataShow = false;
		m_bmpBtn[5].SetTitle("数据记录>>");
	
		m_pDlgPrintParamDataRecord->ShowWindow(SW_HIDE);
	}

	//刷新按钮
	CRect rc;
	GetDlgItem(IDC_PRINT_PA_DataRecord_BTN)->GetWindowRect(&rc);
	ScreenToClient(&rc);
	RedrawWindow(&rc);
}


void CDlgPrintParamAdjust::OnRButtonDown(UINT nFlags, CPoint point)
{
	CRect rect;
	GetDlgItem(IDC_PRINT_PA_GB1_GROUP)->GetWindowRect(&rect);
	ClientToScreen(&point); 
	if (rect.PtInRect(point))
	{
		//动态创建弹出菜单
		CMenu menu;
		menu.CreatePopupMenu();  
		if (!m_bCameraWatchShow)
		{
			menu.AppendMenuA(MF_BYCOMMAND|MF_STRING, UM_IDM_PRINT_CAMERAWATCH_SHOW, _T("独立显示")); 
		}
		else
		{
			menu.AppendMenuA(MF_BYCOMMAND|MF_STRING, UM_IDM_PRINT_CAMERAWATCH_SHOW, _T("隐藏")); 
		}

		menu.TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this); //加载弹出菜单
	}
	
	CDialog::OnRButtonDown(nFlags, point);
}


void CDlgPrintParamAdjust::OnUMCameraWatchShow()
{
	if (!m_bCameraWatchShow)
	{
		m_bCameraWatchShow = true;

		CRect rcMain, rcSub;
		GetDlgItem(IDC_PRINT_PA_GB1_GROUP)->GetWindowRect(&rcMain);
		m_pDlgPrintParamCameraWatch->GetWindowRect(&rcSub);	
		m_pDlgPrintParamCameraWatch->MoveWindow(rcMain.left, rcMain.top, rcSub.Width(), rcSub.Height());
		m_pDlgPrintParamCameraWatch->ShowWindow(SW_SHOW);
		m_pDlgPrintParamCameraWatch->SetTimer(1,50,NULL);   //开启墨滴观测相机采集显示定时器
	}
	else
	{
		m_bCameraWatchShow = false;
		m_pDlgPrintParamCameraWatch->ShowWindow(SW_HIDE);
		m_pDlgPrintParamCameraWatch->KillTimer(1);   //关闭墨滴观测相机采集显示定时器
	}
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaDcModeRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	m_enumVolMode = DcMode;

	SetVoltageComponentState(true, false, false, false);

	CString strTemp = _T("");
	strTemp.Format(_T("%.2f"), m_dDcOffset);
	GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->SetWindowText(strTemp);
	
// 	theApp.m_JetAglientFunc.SetDCMode();
// 	theApp.m_JetAglientFunc.SetOffset(m_dDcOffset);
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaAcModeRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	m_enumVolMode = AcMode;

	SetVoltageComponentState(true, true, true, true);

	CString strTemp = _T("");
	strTemp.Format(_T("%.2f"), m_dAcOffset);
	GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->SetWindowText(strTemp);
	strTemp.Format(_T("%.2f"), m_dAcAmplitude);
	GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT)->SetWindowText(strTemp);
	strTemp.Format(_T("%.2f"), m_dAcFreq);
	GetDlgItem(IDC_PRINT_PA_Freq_EDIT)->SetWindowText(strTemp);
	strTemp.Format(_T("%.2f"), m_dAcRatio);
	GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT)->SetWindowText(strTemp);

// 	theApp.m_JetAglientFunc.SetACMode();
// 	theApp.m_JetAglientFunc.SetOffset(m_dAcOffset);
// 	theApp.m_JetAglientFunc.SetAmplitude(m_dAcAmplitude);
// 	theApp.m_JetAglientFunc.SetFrequency(m_dAcFreq);
//  ::PostMessage(theApp.m_pMainWnd->m_hWnd,WM_FREQ_CHANGED,0,LPARAM(m_dAcFreq));
// 	theApp.m_JetAglientFunc.SetRatio(m_dAcRatio);
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaFlowstartBtn()
{
	if (m_enumFlowAdjPattern == PumpPattern)
	{
// 		if (theApp.m_JetHarvardPump.m_comm.IsOpen())
// 		{
// 			CString strTemp = _T("");
// 			GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->GetWindowText(strTemp);
// 			m_dPumpFlowRate = _ttof(strTemp);
// 
// 			theApp.m_JetHarvardPump.SetInfuseRate(static_cast<int>(m_dPumpFlowRate));
// 			theApp.m_JetHarvardPump.Run();
// 		}
	}
	else if (m_enumFlowAdjPattern == FeedAirPressPattern)
	{
		//此处添加进给气压打开 m_dFeedAirFlowRate
	}

	SetFlowComponentState(false, false, false, false, true);
}


void CDlgPrintParamAdjust::OnBnClickedPrintPaFlowstopBtn()
{
	// TODO: 在此添加控件通知处理程序代码

// 	theApp.m_JetHarvardPump.Stop();
// 	theApp.m_AirPress.Stop();

	SetFlowComponentState(true, true, true, true, false);
}


void CDlgPrintParamAdjust::OnDeltaposPrintPaAmplitudeSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp = _T("");
	double dEditValue = 0.0;
	GetDlgItemText(IDC_PRINT_PA_Amplitude_EDIT, strTemp);
	dEditValue = _ttof(strTemp);
	dEditValue -= (double)pNMUpDown->iDelta * 0.1f;
	if(dEditValue < 0.0)
		dEditValue = 0.0;
	if(dEditValue > 5000.0)
		dEditValue = 5000.0;
	strTemp.Format(_T("%.2f"), dEditValue);
	SetDlgItemText(IDC_PRINT_PA_Amplitude_EDIT, strTemp);

	m_dAcAmplitude = dEditValue;
// 	theApp.m_JetAglientFunc.SetAmplitude(m_dAcAmplitude);

	*pResult = 0;
}


void CDlgPrintParamAdjust::OnDeltaposPrintPaFreqSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp = _T("");
	double dEditValue = 0.0;
	GetDlgItemText(IDC_PRINT_PA_Freq_EDIT, strTemp);
	dEditValue = _ttof(strTemp);
	dEditValue -= (double)pNMUpDown->iDelta * 0.1f;
	if(dEditValue < 0.0)
		dEditValue = 0.0;
	if(dEditValue > 10000.0)
		dEditValue = 10000.0;
	strTemp.Format(_T("%.2f"), dEditValue);
	SetDlgItemText(IDC_PRINT_PA_Freq_EDIT, strTemp);

	m_dAcFreq = dEditValue;
// 	theApp.m_JetAglientFunc.SetFrequency(m_dAcFreq);
//  ::PostMessage(theApp.m_pMainWnd->m_hWnd,WM_FREQ_CHANGED,0,LPARAM(m_dAcFreq));

	*pResult = 0;
}


void CDlgPrintParamAdjust::OnDeltaposPrintPaOffsetSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp = _T("");
	double dEditValue = 0.0;
	GetDlgItemText(IDC_PRINT_PA_Offset_EDIT, strTemp);
	dEditValue = _ttof(strTemp);
	dEditValue -= (double)pNMUpDown->iDelta * 0.1f;
	if(dEditValue < 0.0)
		dEditValue = 0.0;
	if(dEditValue > 3000.0)
		dEditValue = 3000.0;
	strTemp.Format(_T("%.2f"), dEditValue);
	SetDlgItemText(IDC_PRINT_PA_Offset_EDIT, strTemp);

	if (m_enumVolMode == AcMode)
	{
		m_dAcOffset = dEditValue;
	// 	theApp.m_JetAglientFunc.SetOffset(m_dAcOffset);
	}
	else if (m_enumVolMode == DcMode)
	{
		m_dDcOffset = dEditValue;
	// 	theApp.m_JetAglientFunc.SetOffset(m_dDcOffset);
	}

	*pResult = 0;
}


void CDlgPrintParamAdjust::OnDeltaposPrintPaDutyratioSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp = _T("");
	double dEditValue = 0.0;
	GetDlgItemText(IDC_PRINT_PA_DutyRatio_EDIT, strTemp);
	dEditValue = _ttof(strTemp);
	dEditValue -= (double)pNMUpDown->iDelta * 0.1f;
	if(dEditValue < 0.0)
		dEditValue = 0.0;
	if(dEditValue > 100.0)
		dEditValue = 100.0;
	strTemp.Format(_T("%.2f"), dEditValue);
	SetDlgItemText(IDC_PRINT_PA_DutyRatio_EDIT, strTemp);

	m_dAcRatio = dEditValue;
//	theApp.m_JetAglientFunc.SetRatio(m_dAcRatio);
	
	*pResult = 0;
}


void CDlgPrintParamAdjust::OnDeltaposPrintPaAuxiairpressSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp = _T("");
	double dEditValue = 0.0;
	GetDlgItemText(IDC_PRINT_PA_AuxiAirPress_EDIT, strTemp);
	dEditValue = _ttof(strTemp);
	dEditValue -= (double)pNMUpDown->iDelta * 0.1f;
	if(dEditValue < 0.0)
		dEditValue = 0.0;
	if(dEditValue > 5000.0)
		dEditValue = 5000.0;
	strTemp.Format(_T("%.2f"), dEditValue);
	SetDlgItemText(IDC_PRINT_PA_AuxiAirPress_EDIT, strTemp);

	m_dAuxiAirPress = dEditValue;
	//此处增加辅助气压值设置

	*pResult = 0;
}


void CDlgPrintParamAdjust::OnDeltaposPrintPaFlowsetSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString strTemp = _T("");
	double dEditValue = 0.0;
	GetDlgItemText(IDC_PRINT_PA_FlowSet_EDIT, strTemp);
	dEditValue = _ttof(strTemp);
	dEditValue -= (double)pNMUpDown->iDelta * 0.1f;
	if(dEditValue < 10.0)
		dEditValue = 10.0;
	if(dEditValue > 8000.0)
		dEditValue = 8000.0;
	strTemp.Format(_T("%.4f"), dEditValue);
	SetDlgItemText(IDC_PRINT_PA_FlowSet_EDIT, strTemp);

	if (m_enumFlowAdjPattern == PumpPattern)
	{
		m_dPumpFlowRate = dEditValue;
		//theApp.m_JetHarvardPump.SetInfuseRate((int)m_dPumpFlowRate);
	}
	else if (m_enumFlowAdjPattern == FeedAirPressPattern)
	{
		m_dFeedAirFlowRate = dEditValue;
		//此处添加进给气压值设置
	}

	*pResult = 0;
}


BOOL CDlgPrintParamAdjust::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		CString strTemp = _T("");
		double dEditValue = 0.0;

		if (GetFocus() == GetDlgItem(IDC_PRINT_PA_Offset_EDIT))
		{
			GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);
			if(dEditValue < 0.0)
				dEditValue = 0.0;
			else if (dEditValue > 3000.0)
				dEditValue = 3000.0;
			strTemp.Format(_T("%.2f"), dEditValue);
			GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->SetWindowText(strTemp);

			if (m_enumVolMode == AcMode)
			{
				m_dAcOffset = dEditValue;
			}
			else if (m_enumVolMode == DcMode)
			{
				m_dDcOffset = dEditValue;
			}

		// 	theApp.m_JetAglientFunc.SetOffset(dEditValue);			
		}

		if (GetFocus() == GetDlgItem(IDC_PRINT_PA_Freq_EDIT))
		{
			GetDlgItem(IDC_PRINT_PA_Freq_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);
			if(dEditValue < 0.0)
				dEditValue = 0.0;	
			else if (dEditValue > 10000.0)
				dEditValue = 10000.0;
			strTemp.Format(_T("%.2f"), dEditValue);
			GetDlgItem(IDC_PRINT_PA_Freq_EDIT)->SetWindowText(strTemp);

			m_dAcFreq = dEditValue;
		// 	theApp.m_JetAglientFunc.SetFrequency(m_dAcFreq);
		//	::PostMessageA(theApp.m_pMainWnd->m_hWnd,WM_FREQ_CHANGED,0,LPARAM(m_dAcFreq));
		}

		if (GetFocus() == GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT))
		{
			GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);
			if (dEditValue < 0.0)
				dEditValue = 0.0;
			else if (dEditValue > 5000.0)
				dEditValue = 5000.0;
			strTemp.Format(_T("%.2f"), dEditValue);
			GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT)->SetWindowText(strTemp);
	
			m_dAcAmplitude = dEditValue;
		// 	theApp.m_JetAglientFunc.SetAmplitude(m_dAcAmplitude);
		}

		if (GetFocus() == GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT))
		{
			GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);
			if (dEditValue < 0.0)
				dEditValue = 0.0;
			else if (dEditValue > 100.0)
				dEditValue = 100.0;
			strTemp.Format(_T("%.2f"), dEditValue);
			GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT)->SetWindowText(strTemp);
			
			m_dAcRatio = dEditValue;
		// 	theApp.m_JetAglientFunc.SetRatio(m_dAcRatio);
		}

		if (GetFocus() == GetDlgItem(IDC_PRINT_PA_AuxiAirPress_EDIT))
		{
			GetDlgItem(IDC_PRINT_PA_AuxiAirPress_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);
			if (dEditValue < 0.00)
				dEditValue = 0.0;
			else if (dEditValue > 5000.0)
				dEditValue = 5000.0;
			strTemp.Format(_T("%.2f"), dEditValue);
			GetDlgItem(IDC_PRINT_PA_AuxiAirPress_EDIT)->SetWindowText(strTemp);
			
			m_dAuxiAirPress = dEditValue;
			//此处添加气压值设置
		}

		if (GetFocus() == GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT))
		{
			GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->GetWindowText(strTemp);
			dEditValue = _ttof(strTemp);
			if(dEditValue < 10.0)
				dEditValue = 10.0;
			else if (dEditValue > 8000.0)
				dEditValue = 8000.0;		
			strTemp.Format(_T("%.4f"), dEditValue);
			GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->SetWindowText(strTemp);

			if (m_enumFlowAdjPattern == PumpPattern)
			{
				m_dPumpFlowRate = dEditValue;
				//theApp.m_JetHarvardPump.SetInfuseRate((int)m_dPumpFlowRate);
			}
			else if (m_enumFlowAdjPattern == FeedAirPressPattern)
			{
				m_dFeedAirFlowRate = dEditValue;
				//此处添加进给气压值设置
			}
		}

		return TRUE;
	}
	
	if (WM_LBUTTONDBLCLK == pMsg->message)
	{
		return TRUE;
	}

	if (WM_LBUTTONDOWN == pMsg->message)
	{
		CWnd* pWnd = WindowFromPoint(pMsg->pt);
		if (pWnd == GetDlgItem(IDC_PRINT_PA_FlowForward_BTN))
		{
			if (m_enumFlowAdjPattern == PumpPattern)
			{
// 				m_dPumpFlowRate = theApp.m_JetHarvardPump.GetInfuseRate();
// 				theApp.m_JetHarvardPump.SetMaxInfuseRate();
// 				theApp.m_JetHarvardPump.Run();
			}
			else if (m_enumFlowAdjPattern == FeedAirPressPattern)
			{
				//此处添加进给气压调节快进
			}
			SetFlowComponentState(true, true, false, false, false);
			m_bForwardOrBackwardFlag = true;
		}

		if (pWnd == GetDlgItem(IDC_PRINT_PA_FlowBackward_BTN))
		{
			if (m_enumFlowAdjPattern == PumpPattern)
			{
// 				m_dPumpFlowRate = theApp.m_JetHarvardPump.GetWithdrawRate();
// 				theApp.m_JetHarvardPump.SetMaxWithdrawRate();
// 				theApp.m_JetHarvardPump.RunBack();
			}
			else if (m_enumFlowAdjPattern == FeedAirPressPattern)
			{
				//此处添加进给气压调节快退
			}
			SetFlowComponentState(true, false, true, false, false);
			m_bForwardOrBackwardFlag = true;
		}
	}

	if (WM_LBUTTONUP == pMsg->message)
	{
		CWnd* pWnd = WindowFromPoint(pMsg->pt);
		if (pWnd == GetDlgItem(IDC_PRINT_PA_FlowForward_BTN) || pWnd == GetDlgItem(IDC_PRINT_PA_FlowBackward_BTN))
		{
			if (m_enumFlowAdjPattern == PumpPattern)
			{
// 				theApp.m_JetHarvardPump.Stop();
// 				theApp.m_JetHarvardPump.SetInfuseRate(static_cast<int>(m_dPumpFlowRate));
			}
			else if (m_enumFlowAdjPattern == FeedAirPressPattern)
			{
				//此处添加进给气压调节停止
			}		
			SetFlowComponentState(true, true, true, true, false);
			m_bForwardOrBackwardFlag = false;
		}
	}
	
	if (WM_MOUSEMOVE == pMsg->message)
	{
		CWnd* pWnd = WindowFromPoint(pMsg->pt);
		if (pWnd != GetDlgItem(IDC_PRINT_PA_FlowForward_BTN) && pWnd != GetDlgItem(IDC_PRINT_PA_FlowBackward_BTN))
		{
			if (m_bForwardOrBackwardFlag)
			{
				if (m_enumFlowAdjPattern == PumpPattern)
				{
// 					theApp.m_JetHarvardPump.Stop();
// 					theApp.m_JetHarvardPump.SetInfuseRate(static_cast<int>(m_dPumpFlowRate));
				}
				else if (m_enumFlowAdjPattern == FeedAirPressPattern)
				{
					//此处添加进给气压调节停止
				}		
				SetFlowComponentState(true, true, true, true, false);
				m_bForwardOrBackwardFlag = false;		
			}
		}
	}

	//以下是单选按钮操作
	if (WM_LBUTTONDOWN == pMsg->message || WM_LBUTTONDBLCLK == pMsg->message)
	{
		if (pMsg->hwnd == GetDlgItem(IDC_PRINT_PA_ModeDC_RADIO)->GetSafeHwnd())
		{
			CRect winRect;
			HDC hdc;
			TEXTMETRIC tm;
			GetDlgItem(IDC_PRINT_PA_ModeDC_RADIO)->GetWindowRect(&winRect);
			hdc = GetDlgItem(IDC_PRINT_PA_ModeDC_RADIO)->GetDC()->GetSafeHdc();  
			GetTextMetrics(hdc, &tm);
			int iOffSetX = tm.tmHeight*2/3;
			int iOffSetY = (winRect.Height() - (tm.tmHeight - tm.tmInternalLeading)) / 2;

			CPoint pt = pMsg->pt;
			if (pt.x < winRect.left || pt.x > winRect.left + iOffSetX ||
				pt.y < winRect.top + iOffSetY || pt.y > winRect.bottom - iOffSetY)
			{
				return TRUE;
			}
		}

		if (pMsg->hwnd == GetDlgItem(IDC_PRINT_PA_ModeAC_RADIO)->GetSafeHwnd())
		{
			CRect winRect;
			HDC hdc;
			TEXTMETRIC tm;
			GetDlgItem(IDC_PRINT_PA_ModeAC_RADIO)->GetWindowRect(&winRect);
			hdc = GetDlgItem(IDC_PRINT_PA_ModeAC_RADIO)->GetDC()->GetSafeHdc();  
			GetTextMetrics(hdc, &tm);
			int iOffSetX = tm.tmHeight*2/3;
			int iOffSetY = (winRect.Height() - (tm.tmHeight - tm.tmInternalLeading)) / 2;

			CPoint pt = pMsg->pt;
			if (pt.x < winRect.left || pt.x > winRect.left + iOffSetX ||
				pt.y < winRect.top + iOffSetY || pt.y > winRect.bottom - iOffSetY)
			{
				return TRUE;
			}
		}

		if (pMsg->hwnd == GetDlgItem(IDC_PRINT_PA_PumpMode_RADIO)->GetSafeHwnd())
		{
			CRect winRect;
			HDC hdc;
			TEXTMETRIC tm;
			GetDlgItem(IDC_PRINT_PA_PumpMode_RADIO)->GetWindowRect(&winRect);
			hdc = GetDlgItem(IDC_PRINT_PA_PumpMode_RADIO)->GetDC()->GetSafeHdc();  
			GetTextMetrics(hdc, &tm);
			int iOffSetX = tm.tmHeight*2/3;
			int iOffSetY = (winRect.Height() - (tm.tmHeight - tm.tmInternalLeading)) / 2;

			CPoint pt = pMsg->pt;
			if (pt.x < winRect.left || pt.x > winRect.left + iOffSetX ||
				pt.y < winRect.top + iOffSetY || pt.y > winRect.bottom - iOffSetY)
			{
				return TRUE;
			}
		}

		if (pMsg->hwnd == GetDlgItem(IDC_PRINT_PA_FeedAirPressMode_RADIO)->GetSafeHwnd())
		{
			CRect winRect;
			HDC hdc;
			TEXTMETRIC tm;
			GetDlgItem(IDC_PRINT_PA_FeedAirPressMode_RADIO)->GetWindowRect(&winRect);
			hdc = GetDlgItem(IDC_PRINT_PA_FeedAirPressMode_RADIO)->GetDC()->GetSafeHdc();  
			GetTextMetrics(hdc, &tm);
			int iOffSetX = tm.tmHeight*2/3;
			int iOffSetY = (winRect.Height() - (tm.tmHeight - tm.tmInternalLeading)) / 2;

			CPoint pt = pMsg->pt;
			if (pt.x < winRect.left || pt.x > winRect.left + iOffSetX ||
				pt.y < winRect.top + iOffSetY || pt.y > winRect.bottom - iOffSetY)
			{
				return TRUE;
			}
		}
	}
			
	return CDialog::PreTranslateMessage(pMsg);
}


void CDlgPrintParamAdjust::InitFlowAdjustCtrlState(bool bEnabled)
{
	GetDlgItem(IDC_PRINT_PA_PumpMode_RADIO)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_FeedAirPressMode_RADIO)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_FlowSet_SPIN)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_FlowForward_BTN)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_FlowBackward_BTN)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_FlowStart_BTN)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_FlowStop_BTN)->EnableWindow(bEnabled);
}


void CDlgPrintParamAdjust::InitVoltageAirAdjustCtrlState(bool bEnabled)
{
	GetDlgItem(IDC_PRINT_PA_ModeDC_RADIO)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_ModeAC_RADIO)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_Offset_SPIN)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_Amplitude_SPIN)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_Freq_EDIT)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_Freq_SPIN)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_DutyRatio_SPIN)->EnableWindow(bEnabled);
	GetDlgItem(IDC_PRINT_PA_AuxiAirPress_EDIT)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_AuxiAirPress_SPIN)->EnableWindow(bEnabled);	
	GetDlgItem(IDC_PRINT_PA_VoltageAirOpen_BTN)->EnableWindow(bEnabled);
}


void CDlgPrintParamAdjust::SetFlowComponentState(bool bEdit,bool bForward,bool bBackward,bool bStart,bool bStop)
{
	GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->EnableWindow(bEdit);
	GetDlgItem(IDC_PRINT_PA_FlowForward_BTN)->EnableWindow(bForward);
	GetDlgItem(IDC_PRINT_PA_FlowBackward_BTN)->EnableWindow(bBackward);
	GetDlgItem(IDC_PRINT_PA_FlowStart_BTN)->EnableWindow(bStart);
	GetDlgItem(IDC_PRINT_PA_FlowStop_BTN)->EnableWindow(bStop);
}


void CDlgPrintParamAdjust::SetVoltageComponentState(bool bOffset,bool bAmplitude,bool bFreq,bool bDutyRatio)
{
	GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->EnableWindow(bOffset);
	GetDlgItem(IDC_PRINT_PA_Offset_SPIN)->EnableWindow(bOffset);
	GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT)->EnableWindow(bAmplitude);
	GetDlgItem(IDC_PRINT_PA_Amplitude_SPIN)->EnableWindow(bAmplitude);
	GetDlgItem(IDC_PRINT_PA_Freq_EDIT)->EnableWindow(bFreq);
	GetDlgItem(IDC_PRINT_PA_Freq_SPIN)->EnableWindow(bFreq);
	GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT)->EnableWindow(bDutyRatio);
	GetDlgItem(IDC_PRINT_PA_DutyRatio_SPIN)->EnableWindow(bDutyRatio);
}


void CDlgPrintParamAdjust::AddPrintParamTable()
{
	if (m_enumVolMode == AcMode)
	{
		m_pDlgPrintParamDataRecord->m_PrintParamTable.enumVolMode = AcMode;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcOffset = m_dAcOffset;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcAmplitude = m_dAcAmplitude;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcFreq = m_dAcFreq;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcRatio = m_dAcRatio;
	}
	else if (m_enumVolMode == DcMode)
	{
		m_pDlgPrintParamDataRecord->m_PrintParamTable.enumVolMode = DcMode;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dDcOffset = m_dDcOffset;
	}

	m_pDlgPrintParamDataRecord->m_PrintParamTable.dAuxiAirPress = m_dAuxiAirPress;

	if (m_enumFlowAdjPattern == PumpPattern)
	{
		m_pDlgPrintParamDataRecord->m_PrintParamTable.enumFlowAdjPattern = PumpPattern;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dPumpFlowRate = m_dPumpFlowRate;
	}
	else if (m_enumFlowAdjPattern = FeedAirPressPattern)
	{
		m_pDlgPrintParamDataRecord->m_PrintParamTable.enumFlowAdjPattern = FeedAirPressPattern;
		m_pDlgPrintParamDataRecord->m_PrintParamTable.dFeedAirFlowRate = m_dFeedAirFlowRate;
	}
}


void CDlgPrintParamAdjust::ApplyPrintParamTable()
{
	//获得参数
	if (m_pDlgPrintParamDataRecord->m_PrintParamTable.enumVolMode == AcMode)
	{
		m_dAcOffset = m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcOffset;
		m_dAcAmplitude = m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcAmplitude;
		m_dAcFreq = m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcFreq;
		m_dAcRatio = m_pDlgPrintParamDataRecord->m_PrintParamTable.dAcRatio;
	}
	else if (m_pDlgPrintParamDataRecord->m_PrintParamTable.enumVolMode == DcMode)
	{
		m_dDcOffset = m_pDlgPrintParamDataRecord->m_PrintParamTable.dDcOffset;
	}

	m_dAuxiAirPress = m_pDlgPrintParamDataRecord->m_PrintParamTable.dAuxiAirPress;

	if (m_pDlgPrintParamDataRecord->m_PrintParamTable.enumFlowAdjPattern == PumpPattern)
	{
		m_dPumpFlowRate = m_pDlgPrintParamDataRecord->m_PrintParamTable.dPumpFlowRate;
	}
	else if (m_pDlgPrintParamDataRecord->m_PrintParamTable.enumFlowAdjPattern == FeedAirPressPattern)
	{
		m_dFeedAirFlowRate = m_pDlgPrintParamDataRecord->m_PrintParamTable.dFeedAirFlowRate;
	}

	//控件显示
	CString strTemp = _T("");
	if (m_enumVolMode == AcMode)
	{
		strTemp.Format(_T("%.2f"), m_dAcOffset);
		GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->SetWindowText(strTemp);
		strTemp.Format(_T("%.2f"), m_dAcAmplitude);
		GetDlgItem(IDC_PRINT_PA_Amplitude_EDIT)->SetWindowText(strTemp);
		strTemp.Format(_T("%.2f"), m_dAcFreq);
		GetDlgItem(IDC_PRINT_PA_Freq_EDIT)->SetWindowText(strTemp);
		strTemp.Format(_T("%.2f"), m_dAcRatio);
		GetDlgItem(IDC_PRINT_PA_DutyRatio_EDIT)->SetWindowText(strTemp);
	// 	theApp.m_JetAglientFunc.SetOffset(m_dAcOffset);
	// 	theApp.m_JetAglientFunc.SetAmplitude(m_dAcAmplitude);
	// 	theApp.m_JetAglientFunc.SetFrequency(m_dAcFreq);
	//  ::PostMessage(theApp.m_pMainWnd->m_hWnd,WM_FREQ_CHANGED,0,LPARAM(m_dAcFreq));
	// 	theApp.m_JetAglientFunc.SetRatio(m_dAcRatio);
	}
	else if (m_enumVolMode == DcMode)
	{
		strTemp.Format(_T("%.2f"), m_dDcOffset);
		GetDlgItem(IDC_PRINT_PA_Offset_EDIT)->SetWindowText(strTemp);
	// 	theApp.m_JetAglientFunc.SetDCMode();
	// 	theApp.m_JetAglientFunc.SetOffset(m_dDcOffset);
	}

	strTemp.Format(_T("%.2f"), m_dAuxiAirPress);
	GetDlgItem(IDC_PRINT_PA_AuxiAirPress_EDIT)->SetWindowText(strTemp);
	//此处添加辅助气压值调节

	if (m_enumFlowAdjPattern == PumpPattern)
	{
		strTemp.Format(_T("%.4f"), m_dPumpFlowRate);
		GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->SetWindowText(strTemp);
		//theApp.m_JetHarvardPump.SetInfuseRate((int)m_dPumpFlowRate);
	}
	else if (m_enumFlowAdjPattern == FeedAirPressPattern)
	{
		strTemp.Format(_T("%.4f"), m_dFeedAirFlowRate);
		GetDlgItem(IDC_PRINT_PA_FlowSet_EDIT)->SetWindowText(strTemp);
		//此处添加进给气压值调节
	}
}


void CDlgPrintParamAdjust::InitWindowHandle()
{
	SetCheck("~father");
	Hlong hlWnd;
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_PRINT_PA_PicShow_STATIC);
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


void CDlgPrintParamAdjust::OnBnClickedPrintPaCamerawatchRadio()
{
	if (NULL == m_pProCore) return;
	m_pProCore->SwitchCamera(PRINT_HORIZONTAL);
	m_pProCore->SetShowInfo(PRINT_HORIZONTAL, m_windowHandle_Pic, m_winSize_Pic);
}
