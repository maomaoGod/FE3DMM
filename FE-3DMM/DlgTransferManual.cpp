// DlgTransferManual.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgTransferManual.h"
#include "afxdialogex.h"

using HalconCpp::HObject;
using HalconCpp::HTuple;
// CDlgTransferManual 对话框

IMPLEMENT_DYNAMIC(CDlgTransferManual, CDialog)

//静态成员定义
int CDlgTransferManual::m_NextBtnCount = 0;     
int CDlgTransferManual::m_iClickNum = 0;

CDlgTransferManual::CDlgTransferManual(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTransferManual::IDD, pParent)
	, m_cTransTypeRadio(0)
	, m_cCamNum(0)
{
	m_pProCore = pProCore;
}

CDlgTransferManual::~CDlgTransferManual()
{
	Release();
}

void CDlgTransferManual::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TRANSFER_M_GB1_GROUP, m_GB1);
	DDX_Control(pDX, IDC_TRANSFER_M_GB2_GROUP, m_GB2);
	DDX_Control(pDX, IDC_TRANSFER_M_GB3_GROUP, m_GB3);
	DDX_Control(pDX, IDC_TRANSFER_M_GB4_GROUP, m_GB4);
	DDX_Radio(pDX, IDC_TRANSFER_M_Active_RADIO, m_cTransTypeRadio);
	DDX_Radio(pDX, IDC_TRANSFER_M_CameraTransDown_RADIO, m_cCamNum);
	DDX_Control(pDX, IDC_TRANSFER_M_Object_LIST, m_cListObject);
	//DDX_Text(pDX, IDC_TRANSFER_M_TIPS_STATIC, m_strTips);
}


BEGIN_MESSAGE_MAP(CDlgTransferManual, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_TRANSFER_M_New_BTN, &CDlgTransferManual::OnBnClickedTransferMNewBtn)
	ON_BN_CLICKED(IDC_TRANSFER_M_Advanced_BTN, &CDlgTransferManual::OnBnClickedTransferMAdvancedBtn)
	ON_BN_CLICKED(IDC_TRANSFER_M_Delete_BTN, &CDlgTransferManual::OnBnClickedTransferMDeleteBtn)
	ON_BN_CLICKED(IDC_TRANSFER_M_Start_BTN, &CDlgTransferManual::OnBnClickedTransferMStartBtn)
	ON_BN_CLICKED(IDC_TRANSFER_M_Next_BTN, &CDlgTransferManual::OnBnClickedTransferMNextBtn)
	ON_BN_CLICKED(IDC_TRANSFER_M_StepDebug_BTN, &CDlgTransferManual::OnBnClickedTransferMStepdebugBtn)
	ON_MESSAGE(WM_CHANGETIPS, OnChangeTips)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_TRANSFER_M_CameraTransDown_RADIO, &CDlgTransferManual::OnBnClickedTransferMCameraTransDownRadio)
	ON_BN_CLICKED(IDC_TRANSFER_M_CameraTransUp_RADIO, &CDlgTransferManual::OnBnClickedTransferMCameraTransUpRadio)
END_MESSAGE_MAP()


// CDlgTransferManual 消息处理程序
void CDlgTransferManual::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlgTransferManual::OnCancel()
{
	DestroyWindow();
}


void CDlgTransferManual::Cancel()
{
	m_pProCore->GetProTransfer()->ThreadExit();
	Sleep(500);
	OnCancel();
}


void CDlgTransferManual::Release()
{
	
}


HBRUSH CDlgTransferManual::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		CFont font;
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_TRANSFER_M_TIPS_STATIC:			
			font.CreatePointFont( 120, "宋体");
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			pDC->SelectObject(&font);
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 

		case IDC_STATIC:
		case IDC_TRANSFER_M_CameraTransDown_RADIO:
		case IDC_TRANSFER_M_CameraTransUp_RADIO:
		case IDC_TRANSFER_M_Active_RADIO:
		case IDC_TRANSFER_M_Passivity_RADIO:		
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlgTransferManual::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlgTransferManual::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitDlgCtrl();
	InitWindowHandle();	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDlgTransferManual::InitDlgCtrl()
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

	m_GB4.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);

	m_bmpBtn[0].SubclassDlgItem(IDC_TRANSFER_M_New_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(16);
	m_bmpBtn[0].SetTitle("新建");

	m_bmpBtn[1].SubclassDlgItem(IDC_TRANSFER_M_Delete_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(16);
	m_bmpBtn[1].SetTitle("删除");

	m_bmpBtn[2].SubclassDlgItem(IDC_TRANSFER_M_Advanced_BTN , this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(16);
	m_bmpBtn[2].SetTitle("高级设置");

	m_bmpBtn[3].SubclassDlgItem(IDC_TRANSFER_M_Start_BTN, this);
	m_bmpBtn[3].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[3].SetFont(16);
	m_bmpBtn[3].SetTitle("开始");

	m_bmpBtn[4].SubclassDlgItem(IDC_TRANSFER_M_Stop_BTN, this);
	m_bmpBtn[4].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[4].SetFont(16);
	m_bmpBtn[4].SetTitle("停止");

	m_bmpBtn[5].SubclassDlgItem(IDC_TRANSFER_M_PAUSE_BTN, this);
	m_bmpBtn[5].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[5].SetFont(16);
	m_bmpBtn[5].SetTitle("暂停");

	m_bmpBtn[6].SubclassDlgItem(IDC_TRANSFER_M_Next_BTN, this);
	m_bmpBtn[6].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[6].SetFont(16);
	m_bmpBtn[6].SetTitle("下一步");

	m_bmpBtn[7].SubclassDlgItem(IDC_TRANSFER_M_StepDebug_BTN, this);
	m_bmpBtn[7].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[7].SetFont(16);
	m_bmpBtn[7].SetTitle("单步运行");

	m_bmpBtn[8].SubclassDlgItem(IDC_TRANSFER_M_Fix_BTN, this);
	m_bmpBtn[8].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[8].SetFont(16);
	m_bmpBtn[8].SetTitle("修改");

	//初始化列表控件
	m_cListObject.ModifyStyle(NULL,LVS_REPORT);
	m_cListObject.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_MULTIWORKAREAS);

	m_cListObject.SetHeaderBKColor(0x00,0xB2,0xEE, 3);
	LV_COLUMN lvColumn;
	lvColumn.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|WS_CHILD|WS_BORDER|WS_GROUP|LVS_REPORT/*|LVS_EDITLABELS*/;
	lvColumn.fmt = LVCFMT_CENTER;

	CRect rect;
	m_cListObject.GetWindowRect(&rect);
	int nWidth = rect.Width()/2;

	m_cListObject.InsertColumn(0, "对象名称", LVCFMT_CENTER);
	m_cListObject.InsertColumn(1, "创建时间", LVCFMT_CENTER);

	m_cListObject.SetColumnWidth(0, (int)(nWidth*1.17));
	m_cListObject.SetColumnWidth(1, (int)(nWidth*0.84));

	//初始化编辑框控件
	SetDlgItemText(IDC_TRANSFER_M_PositionX_EDIT, "0");
	SetDlgItemText(IDC_TRANSFER_M_PositionY_EDIT, "0");
	SetDlgItemText(IDC_TRANSFER_M_PositionAngle_EDIT, "0");
	SetDlgItemText(IDC_TRANSFER_M_Angle_EDIT, "0");
	SetDlgItemText(IDC_TRANSFER_M_YOffset_EDIT, "0");
	SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, "0");

	UpdateList();

	//控件使能
	GetDlgItem(IDC_TRANSFER_M_PAUSE_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_TRANSFER_M_Stop_BTN)->EnableWindow(FALSE);
	GetDlgItem(IDC_TRANSFER_M_Next_BTN)->EnableWindow(FALSE);

	//提示框初始化
	m_strTips = "请先设置参数然后点击开始进行试验！";
	SetDlgItemText(IDC_TRANSFER_M_TIPS_STATIC, m_strTips);
}

void CDlgTransferManual::InitWindowHandle()
{
	SetCheck("~father");
	Hlong hlWnd;
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_TRANSFER_M_Image_STATIC);
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

void CDlgTransferManual::UpdateList()
{
	//清空list
	m_cListObject.DeleteAllItems();
	ASSERT(m_cListObject.GetItemCount() == 0);
	//遍历一遍文件夹，把文件加载进去
	int iItem = 0;
	CString strDebugPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1);
	CString strFilePath = strDebugPath + "Storage\\Config\\TransferObject\\";	
	CString strTemp = strFilePath + "*.*";   
	CString lpFileName("");             //全路径名，包含文件名
	CString strFileName("");            //文件名，不包含路径
	char strValue[256];
	CFileFind FileFind;
	BOOL bFind = FileFind.FindFile(strTemp);
	while (bFind)
	{
		//查找下一个文件
		bFind = FileFind.FindNextFile();
		//判断是否为文件夹
		if(FileFind.IsDots())
			continue;
		strFileName = FileFind.GetFileName();
		m_cListObject.InsertItem(iItem,_T(""));
		m_cListObject.SetItemText(iItem, 0, strFileName);
		CString lpAppName = "Transfer_Object_File";
		lpFileName = strFilePath + strFileName;
		GetPrivateProfileString(lpAppName, "CreatedTime", "READ_FAIL", strValue, 256, lpFileName);
		m_cListObject.SetItemText(iItem, 1, (CString)strValue);
		iItem++;
	}
}

void CDlgTransferManual::OnBnClickedTransferMNewBtn()
{
	CDlgTransferManualNew dlg(m_pProCore);
	// TODO: 在此添加控件通知处理程序代码
	if (IDOK == dlg.DoModal())
	{
		//更新列表控件
		UpdateList();
	}
}


void CDlgTransferManual::OnBnClickedTransferMDeleteBtn()
{
	int Item = GetSelProduct();
	if(0 > GetSelProduct())
	{
		MessageBox("未选择任何文件!",_T("提示"),MB_ICONWARNING+MB_OK);
		return;
	}
	int	iRet = MessageBox("确认删除该文件？\n点击“确定”按钮确认删除，文件删除后无法恢复。","Warning",MB_ICONWARNING+MB_OKCANCEL);
	if( iRet == IDOK)
	{
		//执行删除操作
		CString strDebugPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1);
		CString strFilePath = strDebugPath + "Config\\TransferObject\\";	
		CString strFileName = strFilePath + m_cListObject.GetItemText(Item,0);
		DeleteFileA(strFileName);
		m_cListObject.DeleteAllItems();
		UpdateList();
	}
	else
		return;
}


int CDlgTransferManual::GetSelProduct()
{
	CString str;
	for(int i=0; i<m_cListObject.GetItemCount(); i++)
	{
		if( m_cListObject.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED )
		{
			return i;
		}
	}	
	return -1;
}


void CDlgTransferManual::OnBnClickedTransferMAdvancedBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgTransferManualAdvanced dlg(m_pProCore);
	dlg.DoModal();
}



void CDlgTransferManual::OnBnClickedTransferMStartBtn()
{
	UpdateData(TRUE);

	//根据选着的类型对象选择加载的参数文件
	if (m_cListObject.GetSelectedCount() < 1)
	{
		MessageBox("请选择一个需要转印的对象！", "提示", IDOK | MB_ICONERROR );
		return;
	}
	else if (m_cListObject.GetSelectedCount() > 1)
	{
		MessageBox("选择的对象超过一个\n请重新确认选择！", "提示", IDOK | MB_ICONERROR );
		return;
	}

	int Item = GetSelProduct();
	CString strObjectName = m_cListObject.GetItemText(Item, 0);

	//判断尺寸类型
	CString strSize = strObjectName.Left(strObjectName.Find("_"));
	if (_T("6mm X 6mm") == strSize)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferSize = SIZE66;
	}
	else if (_T("5mm X 5mm") == strSize)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferSize = SIZE55;
	}
	else if (_T("4mm X 4mm") == strSize)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferSize = SIZE44;
	}
	else if (_T("3mm X 3mm") == strSize)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferSize = SIZE33;
	}
	else if (_T("2mm X 2mm") == strSize)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferSize = SIZE22;
	}
	else if (_T("1mm X 1mm") == strSize)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferSize = SIZE11;
	}

	//判断转印类型
	if (m_cTransTypeRadio == 0)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferType = INITIATIVE;
	}
	else if (m_cTransTypeRadio == 1)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferType = PASSITIVITY;
	}
	else
	{
		MessageBox("请选择转印方式", "提示", MB_ICONERROR);
	}
	
	//读取剩余控件数据
	ReadCtrlValue();
	
    //控件使能
	GetDlgItem(IDC_TRANSFER_M_Start_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_TRANSFER_M_PAUSE_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_TRANSFER_M_Stop_BTN)->EnableWindow(TRUE);
	GetDlgItem(IDC_TRANSFER_M_Next_BTN)->EnableWindow(TRUE);

	m_NextBtnCount = 0;
	//启动
	m_pProCore->GetProTransfer()->Run();
}

void CDlgTransferManual::ReadCtrlValue()
{
	UpdateData(TRUE);
	char PosX[256], PosY[256], PosAngle[256];
	char * StopString;
	memset(PosX, 0, 256);
	memset(PosY, 0, 256);
	memset(PosAngle, 0, 256);
	GetDlgItemText(IDC_TRANSFER_M_A_PositivePress_EDIT, PosX, 256);
	GetDlgItemText(IDC_TRANSFER_M_A_NegativePress_EDIT, PosY, 256);
	GetDlgItemText(IDC_TRANSFER_M_A_ZSpeed_EDIT, PosAngle, 256);

	if (strcmp(PosX, "") == 0 || strcmp(PosY, "") == 0 || strcmp(PosAngle, "") == 0)
	{
		MessageBox("请输入数值", "提示", MB_OK);
		return;
	}

	double fPosX = strtod(PosX, &StopString);
	if (strcmp(StopString, "\0") != 0)
	{
		MessageBox("输入数据有误，请重新输入", "提示", MB_OK);
		return;
	}

	double fPosY = strtod(PosY, &StopString);
	if (strcmp(StopString, "\0") != 0)
	{
		MessageBox("输入数据有误，请重新输入", "提示", MB_OK);
		return;
	}

	double fPosAngle = strtod(PosAngle, &StopString);
	if (strcmp(StopString, "\0") != 0)
	{
		MessageBox("输入数据有误，请重新输入", "提示", MB_OK);
		return;
	}

	m_pProCore->GetParamData()->GetParamTransfer()->iPlacePos.fPosX = fPosX;
	m_pProCore->GetParamData()->GetParamTransfer()->iPlacePos.fPosY = fPosY;
	m_pProCore->GetParamData()->GetParamTransfer()->iPlacePos.fPosA = fPosAngle;

	if (0 == m_cTransTypeRadio)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferType = INITIATIVE;
	} 
	else if (1 == m_cTransTypeRadio)
	{
		m_pProCore->GetParamData()->GetParamTransfer()->TransferType = PASSITIVITY;
	}
	else
	{
		MessageBox("请选择转印方式！", "提示", MB_OK | MB_ICONERROR);
	}
}


void CDlgTransferManual::OnBnClickedTransferMNextBtn()
{
	// 点击的次数加1
	++m_NextBtnCount;
	switch(m_NextBtnCount)
	{
	case 1:
		//m_pProCore->GetProTransfer()->m_BeAdjustAngle = true;
		break;
	default:
		break;
	}
}


LRESULT CDlgTransferManual::OnChangeTips(WPARAM wParam, LPARAM lParam)
{
	//下一步还没有被按下过，角度调整完毕标志还未置1
	if (0 == m_NextBtnCount && wParam == 1)
	{		
		m_strTips.Format("%f", m_pProCore->GetParamData()->GetParamTransfer()->fAngleOffsetPick);
		SetDlgItemText(IDC_TRANSFER_M_Angle_EDIT, m_strTips);
		m_strTips = "角度偏差值为：" + m_strTips;
		m_strTips = "\n请转动手动滑台纠正角度误差";		
	} 
	else if(1 == m_NextBtnCount && wParam == 2)
	{
		m_strTips.Format("%f", m_pProCore->GetParamData()->GetParamTransfer()->fYOffsetPick);
		SetDlgItemText(IDC_TRANSFER_M_YOffset_EDIT, m_strTips);
		m_strTips = "Y轴方向偏差值为：" + m_strTips;
		m_strTips = "\n请转动手动滑台纠正角度误差";
	}
	else if (3 == wParam)
	{
		m_strTips = "转印相机定位完成";
	}

	RefreshStatic();

	CWnd* pTmpWnd = GetDlgItem(IDC_TRANSFER_M_TIPS_STATIC);
	ASSERT(pTmpWnd);

	pTmpWnd->SetWindowText(m_strTips);
	return TRUE;

	return 0;
}



void CDlgTransferManual::OnBnClickedTransferMStepdebugBtn()
{
	StepRun();
}


/*
** @name: StepRun
** @Function: 主动变形情况下单步运行函数
** @Input: NULL
** @Output: NULL
*/
void CDlgTransferManual::StepRun()
{	
	if (m_cTransTypeRadio == 0)
	{
		PositiveStepRun();
	}
	else if(m_cTransTypeRadio == 1)
	{
		//NegtiveStepRun();
	}
	else
	{		
		/*NULL*/
	}
}



/*
** @name: StepRunEnableCtrl
** @Function: 单步运行情况下，使能控件
** @Input: bool变量，true表示使能使用，false表示使不能使用
** @Output: NULL
*/
void CDlgTransferManual::StepRunEnableCtrl(bool bEnable)
{
	GetDlgItem(IDC_TRANSFER_M_Start_BTN)->EnableWindow(bEnable);
	
	GetDlgItem(IDC_TRANSFER_M_Active_RADIO)->EnableWindow(bEnable);

	GetDlgItem(IDC_TRANSFER_M_Passivity_RADIO)->EnableWindow(bEnable);
}


/*
** @name: PositiveStepRun
** @Function: 主动变形情况下单步运行函数
** @Input: NULL
** @Output: NULL
*/
void CDlgTransferManual::PositiveStepRun()
{
	++m_iClickNum;

	switch (m_iClickNum)
	{
	case STEP1:
		{
			StepRunEnableCtrl(false);

			/* 修改单步调试按钮名称 */
			m_bmpBtn[7].SetTitle("下一步");
			CRect rc;
			GetDlgItem(IDC_TRANSFER_M_StepDebug_BTN)->GetWindowRect(&rc);
			ScreenToClient(&rc);
			RedrawWindow(&rc);


			/* 开始单步调试运行，电机回零*/
			PositiveStep1();
			SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("1"));
			break;
		}


	case STEP2:
		/* 电机运动到转印相机采图位置*/
		PositiveStep2();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("2"));
		break;

	case STEP3:
		/* 开始相机采图，实时反馈，调整角度*/
		PositiveStep3();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("3"));
		break;

	case STEP4:
		/* 结束角度调整， 开始Y方向定位*/
		PositiveStep4();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("4"));
		break;

	case STEP5:
		/* 结束Y方向调整，采图定位X方向后机械手移动到PI上方*/
		PositiveStep5();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("5"));
		break;

	case STEP6:
		/* Z轴电机向下运动 */
		PositiveStep6();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("6"));
		break;

	case STEP7:
		/* 开启真空吸附，达到指定值后，Z轴向上运动 */
		PositiveStep7();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("7"));
		break;

	case STEP8:
		/* 推杆变形， 四轴运动到采图位置 */
		PositiveStep8();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("8"));
		break;

	case STEP9:
		/* 上视定位，四轴调整到贴装姿态 */
		PositiveStep9();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("9"));
		break;

	case STEP10:
		/* 转印Z轴向下运动到贴装位置 */
		PositiveStep10();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("10"));
		break;

	case STEP11:
		/* 关闭吸附，开始吹气,达到指定值后关闭吹气， Z轴上移 */
		PositiveStep11();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("11"));
		break;

	case STEP12:
		/* 关闭吸附，开始吹气,达到指定值后关闭吹气， Z轴上移 */
		PositiveStep12();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("12"));
		break;

	case STEP13:
		/* 关闭吸附，开始吹气,达到指定值后关闭吹气， Z轴上移 */
		PositiveStep13();
		SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("13"));
		break;

	case STEP14:
		{
			/* 回零 */
			PositiveStep14();

			m_bmpBtn[7].SetTitle("开始单步调试");
			CRect rc;
			GetDlgItem(IDC_TRANSFER_M_StepDebug_BTN)->GetWindowRect(&rc);
			ScreenToClient(&rc);
			RedrawWindow(&rc);

			StepRunEnableCtrl(true);

			SetDlgItemText(IDC_TRANSFER_M_StepNum_EDIT, _T("0"));
			break;
		}

	default:
		break;
	}

	if (m_iClickNum == STEP14)
	{
		m_iClickNum = 0;
	}
}


BOOL CDlgTransferManual::PositiveStep1()
{

#ifndef FE_DEBUG_OFFLINE

	//设置运行模式，让操作类执行对应的代码
	m_pProCore->GetProTransfer()->SetRunMode(STEP);
	//电机回零
	//GoHome();
	//加载相机模板
	m_pProCore->GetProTransfer()->LoadModel();
	//初始化
	m_pProCore->GetProTransfer()->StepRunInit();
	//开启支撑平台真空
	m_pProCore->GetProTransfer()->GetIoPickPlatform()->On();
#endif

	//更新提示框
	UpDateTips(TO_TRANSCAM_VIEW);

	return TRUE;
}

BOOL CDlgTransferManual::PositiveStep2()
{
#ifndef FE_DEBUG_OFFLINE

	//运动到采图位置
	double fPosition;

	//X电机运动到采图位置
	fPosition = m_pProCore->GetParamData()->GetParamTransfer()->fXPosPickCamera;
	m_pProCore->GetProTransfer()->GetMotorTransferX()->MoveTo(fPosition);

	//Z轴电机运动到采图位置
	fPosition = m_pProCore->GetParamData()->GetParamTransfer()->fZPosPickCamera;
	m_pProCore->GetProTransfer()->GetMotorTransferZ()->MoveTo(fPosition);

	//加定时器查询是否到达学习位置
#endif

	UpDateTips(ANGLE_LOCA);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep3()
{
#ifndef FE_DEBUG_OFFLINE

	//控制转印X和Z电机不使能
	m_pProCore->GetProTransfer()->EnableTransMotor(false);

	//从转印相机抓图，进行实时角度定位
	m_pProCore->GetProTransfer()->StartAngleAdjust();

#endif
	UpDateTips(POSY_LOCA);
	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep4()
{

#ifndef FE_DEBUG_OFFLINE

	//结束角度调整的循环
	m_pProCore->GetProTransfer()->EndAngleAdjust();

	//开始采图，进行实时Y方向定位
	m_pProCore->GetProTransfer()->StartYAdjust();

#endif

	UpDateTips(TO_PICK_POS);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep5()
{

#ifndef FE_DEBUG_OFFLINE

	//使能电机
	m_pProCore->GetProTransfer()->EnableTransMotor(true);

	//结束Y方向调整
	m_pProCore->GetProTransfer()->EndYAdjust();

	//退出调整线程
	m_pProCore->GetProTransfer()->ExitStepAdjustThread();

	//开始采图，X方向定位
	m_pProCore->GetProTransfer()->PickPosXLocation();

	Sleep(100);

	//移动X轴电机到PI上方
	double fDis = m_pProCore->GetParamData()->GetParamTransfer()->fDisPickerCamX;
	double fOffset = m_pProCore->GetParamData()->GetParamTransfer()->fXOffsetPick;
	double des =  fDis + fOffset;
	m_pProCore->GetProTransfer()->GetMotorTransferX()->MoveTo(des);

#endif

	UpDateTips(PICK);

	return TRUE;
}

BOOL CDlgTransferManual::PositiveStep6()
{
#ifndef FE_DEBUG_OFFLINE

	//移动Z轴电机到拾取位置
	double des = m_pProCore->GetParamData()->GetParamTransfer()->fZPosPickPicker;
	m_pProCore->GetProTransfer()->GetMotorTransferZ()->MoveTo(des);

#endif

	UpDateTips(SUCTION);

	return TRUE;
}

BOOL CDlgTransferManual::PositiveStep7()
{
#ifndef FE_DEBUG_OFFLINE

	//开启九个轴真空吸附
	m_pProCore->GetProTransfer()->GetIoRodAttach()->On();
	//开启膜真空吸附
	m_pProCore->GetProTransfer()->GetIoVacAttach()->On();

	//开定时器查询，是否到达指定气压值，然后关闭膜真空开关，或者延时，然后升起Z轴，后面调试再完善
	//SetTimer(1, 10, NULL);
#endif
	
	UpDateTips(ROD_RUN);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep8()
{
#ifndef FE_DEBUG_OFFLINE

	//计算旋转信息
	m_pProCore->GetProTransfer()->CalRotateInfo();

	//推杆运动
	double fDis 

	fDis= m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod11;
	m_pProCore->GetProTransfer()->GetMotorRod11()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod12;
	m_pProCore->GetProTransfer()->GetMotorRod12()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod13;
	m_pProCore->GetProTransfer()->GetMotorRod13()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod21;
	m_pProCore->GetProTransfer()->GetMotorRod21()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod22;
	m_pProCore->GetProTransfer()->GetMotorRod22()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod23;
	m_pProCore->GetProTransfer()->GetMotorRod23()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod31;
	m_pProCore->GetProTransfer()->GetMotorRod31()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod32;
	m_pProCore->GetProTransfer()->GetMotorRod32()->MoveTo(fDis);

	fDis = m_pProCore->GetParamData()->GetParamTransfer()->RodStransform.fRod33;
	m_pProCore->GetProTransfer()->GetMotorRod33()->MoveTo(fDis);	

#endif

	UpDateTips(TO_UPCAM_VIEW);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep9()
{
#ifndef FE_DEBUG_OFFLINE

	//X、Z轴运动到下视相机采图位置
	double des(0.0);
	des = m_pProCore->GetParamData()->GetParamTransfer()->fXPosPlaceCamera;
	m_pProCore->GetProTransfer()->GetMotorTransferX()->MoveTo(des);
	des = m_pProCore->GetParamData()->GetParamTransfer()->fZPosPlaceCamera;
	m_pProCore->GetProTransfer()->GetMotorTransferZ()->MoveTo(des);

	//四轴运动到下视采图位置
	des = m_pProCore->GetParamData()->GetParamTransfer()->fXPosViewFourAxle;
	m_pProCore->GetProTransfer()->GetMotorFourX()->MoveTo(des);
	des = m_pProCore->GetParamData()->GetParamTransfer()->fYPosViewFourAxle;
	m_pProCore->GetProTransfer()->GetMotorFourY()->MoveTo(des);

	
#endif

	UpDateTips(PLACE_LOCA);

	return TRUE;
}



BOOL CDlgTransferManual::PositiveStep10()
{
#ifndef FE_DEBUG_OFFLINE
	
	//上视相机抓一张图
	CVisionPart* pCamera;
	pCamera = m_pProCore->GetProTransfer()->GetCameraUp();
	pCamera->SingleGrab();
	pCamera->Match();

	//向上运动
	double des = m_pProCore->GetParamData()->GetParamTransfer()->fZPosAfterSurfaceLoc;
	m_pProCore->GetProTransfer()->GetMotorTransferZ()->MoveTo(des);

#endif

	UpDateTips(SURFACE_ROTATE);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep11()
{
#ifndef FE_DEBUG_OFFLINE

	//四轴的XY走到贴装的位置
	double des;
	des = m_pProCore->GetParamData()->GetParamTransfer()->fXPosPlaceFourAxle + 
		       m_pProCore->GetParamData()->GetParamTransfer()->fXOffsetPlace;

	m_pProCore->GetProTransfer()->GetMotorFourX()->MoveTo(des);

	des = m_pProCore->GetParamData()->GetParamTransfer()->fYPosPlaceFourAxle + 
		       m_pProCore->GetParamData()->GetParamTransfer()->fYOffsetPlace;

	m_pProCore->GetProTransfer()->GetMotorFourY()->MoveTo(des);

	//调整角度偏差
	des = m_pProCore->GetParamData()->GetParamTransfer()->fAngleOffsetPlace;

	m_pProCore->GetProTransfer()->GetMotorFourAngleC()->MoveTo(des);

	//曲面旋转
	des = m_pProCore->GetParamData()->GetParamTransfer()->fAPosPlaceFourAxle;
	m_pProCore->GetProTransfer()->GetMotorFourAngleA()->MoveTo(des);

	des = m_pProCore->GetParamData()->GetParamTransfer()->fBPosPlaceFourAxle;
	m_pProCore->GetProTransfer()->GetMotorFourAngleB()->MoveTo(des);

#endif

	UpDateTips(PLACE);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep12()
{
#ifndef FE_DEBUG_OFFLINE

	//机械手向下运动到贴装位置
	double des = m_pProCore->GetParamData()->GetParamTransfer()->fZPosPlacePicker;
	m_pProCore->GetProTransfer()->GetMotorTransferZ()->MoveTo(des);
#endif

	UpDateTips(BLOW);

	return TRUE;
}


BOOL CDlgTransferManual::PositiveStep13()
{
#ifndef FE_DEBUG_OFFLINE

	//关闭真空吸附，开启吹气
	m_pProCore->GetProTransfer()->GetIoVacAttach()->Off();
	Sleep(100);

	m_pProCore->GetProTransfer()->GetIoVacBlow()->On();

	//定时查询压力
	SetTimer(1, 10, NULL);
#endif

	UpDateTips(END);

	return TRUE;
}

BOOL CDlgTransferManual::PositiveStep14()
{
#ifndef FE_DEBUG_OFFLINE

	//关闭平台真空
	m_pProCore->GetProTransfer()->GetIoPickPlatform()->Off();
	GoHome();

#endif
    
    UpDateTips(INIT);

	return TRUE;
}

/*
** @name: GoHome
** @Function: 转印模块电机回零
** @Input: NULL
** @Output: NULL
*/
BOOL CDlgTransferManual::GoHome()
{
	return TRUE;
}


/***************************************************************** 
** 函数名称: UpDateTips
** 输入参数: 标记量
** 输出:	     BOOL
** 函数功能: 单步调试时，在提示窗口显示相应的提示信息
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
BOOL CDlgTransferManual::UpDateTips(int num)
{
	m_strTips = _T("");
	switch (num)
	{
	case GO_HOME:
		m_strTips = _T("电机回零中...");
		break;
		
	case TO_TRANSCAM_VIEW:
		m_strTips = _T("提示：等待回零结束后，单击下一步，使转印相机运动到采图位置");
		break;

	case ANGLE_LOCA:
		m_strTips = _T("提示：点击运动停止后，单击下一步，调节手动平台调整角度误差小于0.1");
		break;

	case POSY_LOCA:
		m_strTips = _T("提示：角度调整完成后，单击下一步，调整Y方向手动滑台使误差小于0.1后点击下一步");
		break;

	case TO_PICK_POS:
		m_strTips = _T("提示：Y方向调整结束后，单击下一步，机械手运动到PI上方准备拾取");
		break;

	case PICK:
		m_strTips = _T("提示：电机运动停止后，单击下一步，Z轴机械手运动到拾取位置");
		break;

	case SUCTION:
		m_strTips = _T("提示：电机运动停止后，单击下一步，开启真空吸附");
		break;
		
	case ROD_RUN:
		m_strTips = _T("提示：Z轴上升到安全高度后，单击下一步，九轴开始变形");
		break;

	case TO_UPCAM_VIEW:
		m_strTips = _T("提示：电机运动停止后，单击下一步，运动到上视相机采图位置，机械手变形成曲面状态");
		break;

	case PLACE_LOCA:
		m_strTips = _T("提示：运动停止后，单击下一步开始贴装定位");
		break;

	case TO_PLACE_POSE:
		m_strTips = _T("提示：电机运动停止后，单击下一步，四轴运动到贴装位姿");
		break;

	case SURFACE_ROTATE:
		m_strTips = _T("提示：电机停止后，单击下一步开始曲面旋转");
		break;

	case PLACE:
		m_strTips = _T("提示：电机运动停止后，单击下一步，Z轴电机运动到贴装点");
		break;

	case BLOW:
		m_strTips = _T("提示：电机运动停止后，单击下一步，关闭真空吸附，开启吹气");
		break;

	case END:
		m_strTips = _T("提示：单步调试结束，电机回到零位");
		break;

	case INIT:
		m_strTips = _T("请先设置参数然后点击开始进行试验");
		break;

	default:
		break;
	}

	//设置为透明后，需要局部刷新再设置内容
	RefreshStatic();

	CWnd* pTmpWnd = GetDlgItem(IDC_TRANSFER_M_TIPS_STATIC);
	ASSERT(pTmpWnd);
	
	pTmpWnd->SetWindowText(m_strTips);
	return TRUE;

	return FALSE;
}


/***************************************************************** 
** 函数名称: RefreshStatic
** 输入参数: 无
** 输出:	     无
** 函数功能: 窗口局部刷新
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
void CDlgTransferManual::RefreshStatic()
{
	if ((CStatic*)GetDlgItem(IDC_TRANSFER_M_TIPS_STATIC)->GetSafeHwnd())  //判断窗口是否被销毁
	{
		CStatic * pWnd = ((CStatic*)GetDlgItem(IDC_TRANSFER_M_TIPS_STATIC));
		ASSERT(pWnd); //判断指针是否为空
		CRect Rect;
		pWnd ->GetWindowRect(&Rect);
		ScreenToClient(&Rect);
		InvalidateRect(&Rect);
	}
}


/***************************************************************** 
** 函数名称: OnTimer
** 输入参数: nIDEvent，定时器号
** 输出:	     无
** 函数功能: 定时查询真空是否达到指定值
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
void CDlgTransferManual::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nIDEvent)
	{
	case 0:
		//如果达到指定值，则使Z轴电机上移，关闭定时器
		
		break;

	case 1:
		//如果达到指定值，则使Z轴电机上移，关闭定时器

		break;
	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}


void CDlgTransferManual::OnBnClickedTransferMCameraTransDownRadio()
{
	m_pProCore->SwitchCamera(TRANS_DOWN);
	m_pProCore->SetShowInfo(TRANS_DOWN, m_windowHandle_Pic, m_winSize_Pic);
}


void CDlgTransferManual::OnBnClickedTransferMCameraTransUpRadio()
{
	m_pProCore->SwitchCamera(TRANS_UP);
	m_pProCore->SetShowInfo(TRANS_UP, m_windowHandle_Pic, m_winSize_Pic);
}
