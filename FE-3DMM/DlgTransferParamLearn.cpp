// DlgTransferParamLearn.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgTransferParamLearn.h"
#include "afxdialogex.h"


// CDlgTransferParamLearn 对话框

IMPLEMENT_DYNAMIC(CDlgTransferParamLearn, CDialog)

CDlgTransferParamLearn::CDlgTransferParamLearn(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
    : CDialog(CDlgTransferParamLearn::IDD, pParent)
    , m_iTransferType(0)
    , m_iPushRodNum(0)
    , m_iRadioVacuum(0)
    , m_iRadioCamera(0)
	, m_bFilmNegOpen(false)
	, m_bFilmPosiOpen(false)
	, m_bRodVacuumOpen(false)
	, m_bPlatVacuumOpen(false)
	, m_bElecStaticOpen(false)
	, m_pProCore(pProCore)
{
}

CDlgTransferParamLearn::~CDlgTransferParamLearn()
{
    Release();
}

void CDlgTransferParamLearn::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_TRANSFER_P_ActiveMode_RADIO, m_iTransferType);
    DDX_Radio(pDX, IDC_TRANSFER_P_PushRod1_RADIO, m_iPushRodNum);
    DDX_Radio(pDX, IDC_TRANSFER_P_VacuumNeg_RADIO, m_iRadioVacuum);
    DDX_Radio(pDX, IDC_TRANSFER_P_CameraTransDown_RADIO, m_iRadioCamera);
    DDX_Control(pDX, IDC_TRANSFER_P_GB1_GROUP, m_GB1);
    DDX_Control(pDX, IDC_TRANSFER_P_GB2_GROUP, m_GB2);
    DDX_Control(pDX, IDC_TRANSFER_P_GB3_GROUP, m_GB3);
    DDX_Control(pDX, IDC_TRANSFER_P_PISize_COMBO, m_cPISizeComBox);
    DDX_Control(pDX, IDC_TRANSFER_P_Pace_SLIDER, m_cSliderPace);
    DDX_Control(pDX, IDC_TRANSFER_P_Vacuum_EDIT, m_cEditVacuum);
    DDX_Control(pDX, IDC_TRANSFER_P_Vacuum_SPIN, m_cSpinVacuum);
    DDX_Control(pDX, IDC_TRANSFER_P_Voltage_SLIDER, m_cSldV);
    DDX_Control(pDX, IDC_TRANSFER_P_Voltage_EDIT, m_cEditV);
    DDX_Control(pDX, IDC_TRANSFER_P_Voltage_SPIN, m_cSpinV);
    DDX_Control(pDX, IDC_TRANSFER_P_Frequency_SLIDER, m_cSldF);
    DDX_Control(pDX, IDC_TRANSFER_P_Frequency_EDIT, m_cEditF);
    DDX_Control(pDX, IDC_TRANSFER_P_Frequency_SPIN, m_cSpinF);
    DDX_Control(pDX, IDC_TRANSFER_P_Pace_EDIT, m_cEditPace);
    DDX_Control(pDX, IDC_TRANSFER_P_Pace_SPIN, m_cSpinPace);
}


BEGIN_MESSAGE_MAP(CDlgTransferParamLearn, CDialog)
    ON_WM_CTLCOLOR()
    ON_WM_ERASEBKGND()
    ON_BN_CLICKED(IDC_TRANSFER_P_Vacuum_Open_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumOpenBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_ElecStatic_Open_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPElecstaticOpenBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_XL_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPXlBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_PickupView_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPPickupviewBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_XR_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPXrBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_ZUP_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPZupBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_ZDOWN_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPZdownBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_PushRodLeft_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPPushrodleftBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_PushRodRight_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPPushrodrightBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_MechArmPick_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPMecharmpickBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_CameraTransDown_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPCameraTransDownRadio)
    ON_BN_CLICKED(IDC_TRANSFER_P_CameraTransUp_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPCameraTransUpRadio)
    ON_BN_CLICKED(IDC_TRANSFER_P_UpView_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPUpviewBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_FourAxleUpView_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPFouraxleupviewBtn)
    ON_EN_CHANGE(IDC_TRANSFER_P_Vacuum_EDIT, &CDlgTransferParamLearn::OnEnChangeTransferPVacuumEdit)
    ON_NOTIFY(UDN_DELTAPOS, IDC_TRANSFER_P_Vacuum_SPIN, &CDlgTransferParamLearn::OnDeltaposTransferPVacuumSpin)
    ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_TRANSFER_P_Voltage_SLIDER, &CDlgTransferParamLearn::OnNMReleasedcaptureTransferPVoltageSlider)
    ON_EN_CHANGE(IDC_TRANSFER_P_Voltage_EDIT, &CDlgTransferParamLearn::OnEnChangeTransferPVoltageEdit)
    ON_NOTIFY(UDN_DELTAPOS, IDC_TRANSFER_P_Voltage_SPIN, &CDlgTransferParamLearn::OnDeltaposTransferPVoltageSpin)
    ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_TRANSFER_P_Frequency_SLIDER, &CDlgTransferParamLearn::OnNMReleasedcaptureTransferPFrequencySlider)
    ON_EN_CHANGE(IDC_TRANSFER_P_Frequency_EDIT, &CDlgTransferParamLearn::OnEnChangeTransferPFrequencyEdit)
    ON_NOTIFY(UDN_DELTAPOS, IDC_TRANSFER_P_Frequency_SPIN, &CDlgTransferParamLearn::OnDeltaposTransferPFrequencySpin)
    ON_BN_CLICKED(IDC_TRANSFER_P_Vacuum_Save_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumSaveBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_ActiveMode_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPActivemodeRadio)
    ON_BN_CLICKED(IDC_TRANSFER_P_PassiveMode_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPPassivemodeRadio)
    ON_BN_CLICKED(IDC_TRANSFER_P_CoordCalib_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPCoordcalibBtn)
    ON_BN_CLICKED(IDC_TRANSFER_P_New_LearnPos_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPNewLearnposBtn)
    ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_TRANSFER_P_Pace_SLIDER, &CDlgTransferParamLearn::OnNMReleasedcaptureTransferPPaceSlider)
    ON_NOTIFY(UDN_DELTAPOS, IDC_TRANSFER_P_Pace_SPIN, &CDlgTransferParamLearn::OnDeltaposTransferPPaceSpin)
	ON_BN_CLICKED(IDC_TRANSFER_P_Vacuum_Close_BTN, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumCloseBtn)
	ON_BN_CLICKED(IDC_TRANSFER_P_VacuumNeg_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumnegRadio)
	ON_BN_CLICKED(IDC_TRANSFER_P_VacuumPosi_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumposiRadio)
	ON_BN_CLICKED(IDC_TRANSFER_P_VacuumRod_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumrodRadio)
	ON_BN_CLICKED(IDC_TRANSFER_P_VacuumPlat_RADIO, &CDlgTransferParamLearn::OnBnClickedTransferPVacuumplatRadio)
	ON_EN_CHANGE(IDC_TRANSFER_P_Pace_EDIT, &CDlgTransferParamLearn::OnEnChangeTransferPPaceEdit)
END_MESSAGE_MAP()


// CDlgTransferParamLearn 消息处理程序
void CDlgTransferParamLearn::PostNcDestroy()
{
    CDialog::PostNcDestroy();
    delete this;
}


void CDlgTransferParamLearn::OnCancel()
{
    DestroyWindow();
}


void CDlgTransferParamLearn::Cancel()
{
    //m_pDlgCoordCalib->Cancel();
    OnCancel();
}


void CDlgTransferParamLearn::Release()
{

}


HBRUSH CDlgTransferParamLearn::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
    if (nCtlColor == CTLCOLOR_STATIC) 
    { 
        switch(pWnd->GetDlgCtrlID()) 
        {
        case IDC_STATIC:
        case IDC_TRANSFER_P_CameraTransDown_RADIO:
        case IDC_TRANSFER_P_CameraTransUp_RADIO:
        case IDC_TRANSFER_P_ActiveMode_RADIO:
        case IDC_TRANSFER_P_PassiveMode_RADIO:
        case IDC_TRANSFER_P_PushRod1_RADIO:
        case IDC_TRANSFER_P_PushRod2_RADIO:
        case IDC_TRANSFER_P_PushRod3_RADIO:
        case IDC_TRANSFER_P_PushRod4_RADIO:
        case IDC_TRANSFER_P_PushRod5_RADIO:
        case IDC_TRANSFER_P_PushRod6_RADIO:
        case IDC_TRANSFER_P_PushRod7_RADIO:
        case IDC_TRANSFER_P_PushRod8_RADIO:
        case IDC_TRANSFER_P_PushRod9_RADIO:
        case IDC_TRANSFER_P_VacuumPosi_RADIO:
        case IDC_TRANSFER_P_VacuumNeg_RADIO:
		case IDC_TRANSFER_P_VacuumRod_RADIO:
		case IDC_TRANSFER_P_VacuumPlat_RADIO:
            pDC->SetBkMode(TRANSPARENT); 
            pDC->SetTextColor(RGB(0,0,0)); 
            return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
        default: 
            break; 
        } 
    }
    return hbr;
}


BOOL CDlgTransferParamLearn::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlgTransferParamLearn::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO:  在此添加额外的初始化
    InitDlgCtrl();
    InitWindowHandle();	
    return TRUE;  
}

void CDlgTransferParamLearn::InitDlgCtrl()
{
    //初始化组合框
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

    //初始化按钮控件
    m_bmpBtn[0].SubclassDlgItem(IDC_TRANSFER_P_ZUP_BTN, this);
    m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_YF,IDB_BITMAP_YFCLK,IDB_BITMAP_YF,IDB_BITMAP_YFCLK);

    m_bmpBtn[1].SubclassDlgItem(IDC_TRANSFER_P_ZDOWN_BTN, this);
    m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_YB,IDB_BITMAP_YBCLK,IDB_BITMAP_YB,IDB_BITMAP_YBCLK);

    m_bmpBtn[2].SubclassDlgItem(IDC_TRANSFER_P_XL_BTN, this);
    m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_XL,IDB_BITMAP_XLCLK,IDB_BITMAP_XL,IDB_BITMAP_XLCLK);

    m_bmpBtn[3].SubclassDlgItem(IDC_TRANSFER_P_XR_BTN, this);
    m_bmpBtn[3].LoadBitmaps(IDB_BITMAP_XR,IDB_BITMAP_XRCLK,IDB_BITMAP_XR,IDB_BITMAP_XRCLK);

    m_bmpBtn[4].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_XL_BTN, this);
    m_bmpBtn[4].LoadBitmaps(IDB_BITMAP_XL,IDB_BITMAP_XLCLK,IDB_BITMAP_XL,IDB_BITMAP_XLCLK);

    m_bmpBtn[5].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_XR_BTN, this);
    m_bmpBtn[5].LoadBitmaps(IDB_BITMAP_XR,IDB_BITMAP_XRCLK,IDB_BITMAP_XR,IDB_BITMAP_XRCLK);

    m_bmpBtn[6].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_YL_BTN, this);
    m_bmpBtn[6].LoadBitmaps(IDB_BITMAP_XL,IDB_BITMAP_XLCLK,IDB_BITMAP_XL,IDB_BITMAP_XLCLK);

    m_bmpBtn[7].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_YR_BTN, this);
    m_bmpBtn[7].LoadBitmaps(IDB_BITMAP_XR,IDB_BITMAP_XRCLK,IDB_BITMAP_XR,IDB_BITMAP_XRCLK);

    m_bmpBtn[8].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_AFL_BTN, this);
    m_bmpBtn[8].LoadBitmaps(IDB_BITMAP_XL,IDB_BITMAP_XLCLK,IDB_BITMAP_XL,IDB_BITMAP_XLCLK);

    m_bmpBtn[9].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_AFR_BTN, this);
    m_bmpBtn[9].LoadBitmaps(IDB_BITMAP_XR,IDB_BITMAP_XRCLK,IDB_BITMAP_XR,IDB_BITMAP_XRCLK);

    m_bmpBtn[10].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_BTL_BTN, this);
    m_bmpBtn[10].LoadBitmaps(IDB_BITMAP_XL,IDB_BITMAP_XLCLK,IDB_BITMAP_XL,IDB_BITMAP_XLCLK);

    m_bmpBtn[11].SubclassDlgItem(IDC_TRANSFER_P_FourAxle_BTR_BTN, this);
    m_bmpBtn[11].LoadBitmaps(IDB_BITMAP_XR,IDB_BITMAP_XRCLK,IDB_BITMAP_XR,IDB_BITMAP_XRCLK);

    m_bmpBtn[12].SubclassDlgItem(IDC_TRANSFER_P_PushRodLeft_BTN, this);
    m_bmpBtn[12].LoadBitmaps(IDB_BITMAP_XL,IDB_BITMAP_XLCLK,IDB_BITMAP_XL,IDB_BITMAP_XLCLK);

    m_bmpBtn[13].SubclassDlgItem(IDC_TRANSFER_P_PushRodRight_BTN, this);
    m_bmpBtn[13].LoadBitmaps(IDB_BITMAP_XR,IDB_BITMAP_XRCLK,IDB_BITMAP_XR,IDB_BITMAP_XRCLK);

    m_bmpBtn[14].SubclassDlgItem(IDC_TRANSFER_P_New_LearnPos_BTN, this);
    m_bmpBtn[14].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[14].SetFont(15);
    m_bmpBtn[14].SetTitle("新建");

    m_bmpBtn[15].SubclassDlgItem(IDC_TRANSFER_P_Del_LearnPos_BTN, this);
    m_bmpBtn[15].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[15].SetFont(15);
    m_bmpBtn[15].SetTitle("删除");

    m_bmpBtn[16].SubclassDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN, this);
    m_bmpBtn[16].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[16].SetFont(15);
    m_bmpBtn[16].SetTitle("开");

    m_bmpBtn[17].SubclassDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN, this);
    m_bmpBtn[17].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[17].SetFont(15);
    m_bmpBtn[17].SetTitle("保存");

    m_bmpBtn[18].SubclassDlgItem(IDC_TRANSFER_P_ElecStatic_Open_BTN, this);
    m_bmpBtn[18].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[18].SetFont(15);
    m_bmpBtn[18].SetTitle("开启");

    m_bmpBtn[19].SubclassDlgItem(IDC_TRANSFER_P_ElecStatic_Save_BTN, this);
    m_bmpBtn[19].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[19].SetFont(15);
    m_bmpBtn[19].SetTitle("保存");

    m_bmpBtn[20].SubclassDlgItem(IDC_TRANSFER_P_PickupView_BTN, this);
    m_bmpBtn[20].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[20].SetFont(15);
    m_bmpBtn[20].SetTitle("拾取前观测位置");

    m_bmpBtn[21].SubclassDlgItem(IDC_TRANSFER_P_MechArmPick_BTN, this);
    m_bmpBtn[21].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[21].SetFont(15);
    m_bmpBtn[21].SetTitle("机械手拾取高度");

    m_bmpBtn[22].SubclassDlgItem(IDC_TRANSFER_P_CoordCalib_BTN, this);
    m_bmpBtn[22].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[22].SetFont(15);
    m_bmpBtn[22].SetTitle("坐标标定");

    m_bmpBtn[23].SubclassDlgItem(IDC_TRANSFER_P_UpView_BTN, this);
    m_bmpBtn[23].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[23].SetFont(15);
    m_bmpBtn[23].SetTitle("上视观测XZ位置");


    m_bmpBtn[24].SubclassDlgItem(IDC_TRANSFER_P_FourAxleUpView_BTN, this);
    m_bmpBtn[24].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[24].SetFont(15);
    m_bmpBtn[24].SetTitle("上视观测四轴位置");
    

    m_bmpBtn[25].SubclassDlgItem(IDC_TRANSFER_P_Step_BTN, this);
    m_bmpBtn[25].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[25].SetFont(15);
    m_bmpBtn[25].SetTitle("单步调试运行");

    m_bmpBtn[26].SubclassDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN, this);
    m_bmpBtn[26].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
    m_bmpBtn[26].SetFont(15);
    m_bmpBtn[26].SetTitle("关");

    //组合框控件初始化
    m_cPISizeComBox.AddString("3mm X 3mm");
    m_cPISizeComBox.AddString("4mm X 4mm");
    m_cPISizeComBox.AddString("5mm X 5mm");
    m_cPISizeComBox.AddString("6mm X 6mm");
    m_cPISizeComBox.SetCurSel(3);

    //初始化步距滑块
    m_cSliderPace.SetRange(0,500,TRUE);
    m_cSliderPace.SetPos(50);
    m_cSliderPace.SetTicFreq(5);
    m_cSpinPace.SetBuddy(&m_cEditPace);
    m_cSpinPace.SetRange(0, 500);
    m_cSpinPace.SetPos(50);
    m_cEditPace.SetWindowTextA("50");

    m_cSpinVacuum.SetBuddy(&m_cEditVacuum);
    m_cSpinVacuum.SetRange(0,500);
    m_cSpinVacuum.SetPos(0);
    m_cEditVacuum.SetWindowTextA("50");

    m_cSldV.SetRange(0,500,TRUE);
    m_cSldV.SetPos(0);
    m_cSldV.SetTicFreq(5);
    m_cSpinV.SetBuddy(&m_cEditV);
    m_cSpinV.SetRange(0,500);
    m_cSpinV.SetPos(0);
    m_cEditV.SetWindowTextA("50");

    m_cSldF.SetRange(0,500,TRUE);
    m_cSldF.SetPos(0);
    m_cSldF.SetTicFreq(5);
    m_cSpinF.SetBuddy(&m_cEditF);
    m_cSpinF.SetRange(0,500);
    m_cSpinF.SetPos(0);
    m_cEditF.SetWindowTextA("50");

    GetDlgItem(IDC_TRANSFER_P_Voltage_SLIDER)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Voltage_EDIT)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Voltage_SPIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_SLIDER)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_EDIT)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_SPIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_ElecStatic_Open_BTN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_New_LearnPos_BTN)->EnableWindow(FALSE);
}

void CDlgTransferParamLearn::InitWindowHandle()
{
	SetCheck("~father");
	Hlong hlWnd;
	CStatic* pWnd = (CStatic*)GetDlgItem(IDC_TRANSFER_P_PicShow_STATIC);
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



void CDlgTransferParamLearn::OnBnClickedTransferPVacuumOpenBtn()
{
	UpdateData(TRUE);
	switch(m_iRadioVacuum)
	{
	case FILMNEGETIVE:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoVacAttach()->On();
#endif
		
		m_bFilmNegOpen = true;		
		break;

	case FILEPOSITIVE:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoVacBlow()->On();
#endif
		
		m_bFilmPosiOpen = true;
		break;

	case RODVACUUM:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoRodAttach()->On();
#endif
		
		m_bRodVacuumOpen = true;
		break;

	case PLATVACUUM:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoPickPlatform()->On();
#endif
		
		m_bPlatVacuumOpen = true;
		break;

	default:
		break;
	}
	m_bmpBtn[16].EnableWindow(FALSE);
	m_bmpBtn[26].EnableWindow(TRUE);


    //刷新按钮
    //CRect rc;
    //GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->GetWindowRect(&rc);
    //ScreenToClient(&rc);
    //RedrawWindow(&rc);
}

void CDlgTransferParamLearn::OnBnClickedTransferPVacuumCloseBtn()
{
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	switch(m_iRadioVacuum)
	{
	case FILMNEGETIVE:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoVacAttach()->On();
#endif

		m_bFilmNegOpen = false;		
		break;

	case FILEPOSITIVE:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoVacBlow()->On();
#endif

		m_bFilmPosiOpen = false;
		break;

	case RODVACUUM:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoRodAttach()->On();
#endif

		m_bRodVacuumOpen = false;
		break;

	case PLATVACUUM:

#ifndef FE_DEBUG_OFFLINE
		m_pProCore->GetProTransfer()->GetIoPickPlatform()->On();
#endif

		m_bPlatVacuumOpen = false;
		break;

	default:
		break;
	}
	m_bmpBtn[16].EnableWindow(TRUE);
	m_bmpBtn[26].EnableWindow(FALSE);
}

void CDlgTransferParamLearn::OnBnClickedTransferPVacuumnegRadio()
{
	if (m_bFilmNegOpen)
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(TRUE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN)->EnableWindow(TRUE);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Open_BTN);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Close_BTN);
}


void CDlgTransferParamLearn::OnBnClickedTransferPVacuumposiRadio()
{
	if (m_bFilmPosiOpen)
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(TRUE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN)->EnableWindow(TRUE);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Open_BTN);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Close_BTN);
}

void CDlgTransferParamLearn::OnBnClickedTransferPVacuumrodRadio()
{
	if (m_bRodVacuumOpen)
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(TRUE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN)->EnableWindow(FALSE);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Open_BTN);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Close_BTN);
}


void CDlgTransferParamLearn::OnBnClickedTransferPVacuumplatRadio()
{
	if (m_bPlatVacuumOpen)
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(FALSE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(TRUE);
		GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(FALSE);
	}
	GetDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN)->EnableWindow(FALSE);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Open_BTN);
	RefreshLocalRegion(IDC_TRANSFER_P_Vacuum_Close_BTN);
}

void CDlgTransferParamLearn::OnBnClickedTransferPElecstaticOpenBtn()
{
    if (!m_bElecStaticOpen)
    {
        m_bElecStaticOpen = true;
        m_bmpBtn[18].SetTitle("关闭");
    }
    else
    {
        m_bElecStaticOpen = false;
        m_bmpBtn[18].SetTitle("开启");
    }

    //刷新按钮
    CRect rc;
    GetDlgItem(IDC_TRANSFER_P_ElecStatic_Open_BTN)->GetWindowRect(&rc);
    ScreenToClient(&rc);
    RedrawWindow(&rc);
}



void CDlgTransferParamLearn::OnBnClickedTransferPXlBtn()
{
    // TODO: 在此添加控件通知处理程序代码
    CCtrlMotor *motor = m_pProCore->GetProTransfer()->GetMotorTransferX();
    motor->Move((-5000)*m_iPace);   
}

void CDlgTransferParamLearn::OnBnClickedTransferPXrBtn()
{
    CCtrlMotor *motor = m_pProCore->GetProTransfer()->GetMotorTransferX();
    motor->Move(5000*m_iPace);   
}


void CDlgTransferParamLearn::OnBnClickedTransferPZupBtn()
{
    CCtrlMotor *motor = m_pProCore->GetProTransfer()->GetMotorTransferZ();
    motor->Move((-5000)*m_iPace);   
}


void CDlgTransferParamLearn::OnBnClickedTransferPZdownBtn()
{
    int nPos = m_cSliderPace.GetPos();
    CCtrlMotor *motor = m_pProCore->GetProTransfer()->GetMotorTransferZ();
    motor->Move(5000*m_iPace);    
}



void CDlgTransferParamLearn::OnBnClickedTransferPPushrodleftBtn()
{
    CCtrlMotor* RunMotor;
    switch (m_iPushRodNum)
    {
    case -1:
        AfxMessageBox("请选择要运行的直线推杆！");
        break;
    case 0:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod11();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 1:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod12();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 2:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod13();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 3:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod21();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 4:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod22();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 5:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod23();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 6:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod31();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 7:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod32();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    case 8:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod33();
        RunMotor->Move(-(5000*m_iPace));   
        break;
    }
}


void CDlgTransferParamLearn::OnBnClickedTransferPPushrodrightBtn()
{
    CCtrlMotor* RunMotor;
    switch (m_iPushRodNum)
    {
    case -1:
        AfxMessageBox("请选择要运行的直线推杆！");
        break;
    case 0:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod11();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 1:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod12();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 2:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod13();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 3:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod21();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 4:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod22();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 5:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod23();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 6:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod31();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 7:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod32();
        RunMotor->Move(5000*m_iPace);   
        break;
    case 8:
        RunMotor = m_pProCore->GetProTransfer()->GetMotorRod33();
        RunMotor->Move(5000*m_iPace);   
        break;
    }
}


void CDlgTransferParamLearn::OnBnClickedTransferPCameraTransDownRadio()
{
	m_pProCore->SwitchCamera(TRANS_DOWN);
	m_pProCore->SetShowInfo(TRANS_DOWN, m_windowHandle_Pic, m_winSize_Pic);
}


void CDlgTransferParamLearn::OnBnClickedTransferPCameraTransUpRadio()
{
	m_pProCore->SwitchCamera(TRANS_UP);
	m_pProCore->SetShowInfo(TRANS_UP, m_windowHandle_Pic, m_winSize_Pic);
}



void CDlgTransferParamLearn::OnBnClickedTransferPPickupviewBtn()
{
    ParamTransfer* ParaTransfer = m_pProCore->GetParamData()->GetParamTransfer();
#ifndef FE_DEBUG_OFFLINE
    // 获取转印观测时X轴和Z轴位置
    double fXPos = m_pProCore->GetProTransfer()->GetMotorTransferX()->GetMotorPostion();
    Sleep(5);
    double fZPos = m_pProCore->GetProTransfer()->GetMotorTransferZ()->GetMotorPostion();
    Sleep(5);
    //将获取的值赋值给参数
    ParaTransfer->fXPosPickCamera = fXPos;
    ParaTransfer->fZPosPickCamera = fZPos;
#else
    ParaTransfer->fXPosPickCamera = 1000;
    ParaTransfer->fZPosPickCamera = 1000;
#endif
    //将参数保存，根据PI尺寸和转移方式
    int type, size;
    switch(m_iTransferType)
    {
    case 0:
        type = INITIATIVE;
        break;
    case 1:
        type = PASSITIVITY;
        break;
    default:
        break;
    }
    int iSel;
    iSel = m_cPISizeComBox.GetCurSel();
    CString strSize;
    m_cPISizeComBox.GetLBText(iSel, strSize); 
    if (strSize == "6mm X 6mm")
    {
        size = SIZE66;
    } 
    else if(strSize == "5mm X 5mm")
    {
        size = SIZE55;
    }
    else if(strSize == "4mm X 4mm")
    {
        size = SIZE44;
    }
    else if(strSize == "3mm X 3mm")
    {
        size = SIZE33;
    }
    m_pProCore->GetParamData()->SaveTransferPa(type, size);
}


void CDlgTransferParamLearn::OnBnClickedTransferPMecharmpickBtn()
{
    // 获取转印拾取时Z轴位置
    float fZPos = m_pProCore->GetProTransfer()->GetMotorTransferZ()->GetMotorPostion();
    Sleep(5);
    //将获取的值赋值给参数
    ParamTransfer* ParaTransfer = m_pProCore->GetParamData()->GetParamTransfer();
    ParaTransfer->fZPosPickCamera = fZPos;
    //将参数保存，根据PI尺寸和转移方式
    int type, size;
    switch(m_iTransferType)
    {
    case 0:
        type = INITIATIVE;
        break;
    case 1:
        type = PASSITIVITY;
        break;
    default:
        break;
    }
    int iSel;
    iSel = m_cPISizeComBox.GetCurSel();
    CString strSize;
    m_cPISizeComBox.GetLBText(iSel, strSize); 
    if (strSize == "6mm X 6mm")
    {
        size = SIZE66;
    } 
    else if(strSize == "5mm X 5mm")
    {
        size = SIZE55;
    }
    else if(strSize == "4mm X 4mm")
    {
        size = SIZE44;
    }
    else if(strSize == "3mm X 3mm")
    {
        size = SIZE33;
    }
    m_pProCore->GetParamData()->SaveTransferPa(type, size);
}


void CDlgTransferParamLearn::OnBnClickedTransferPUpviewBtn()
{
    // 获取转印观测时X轴和Z轴位置
    float fXPos = m_pProCore->GetProTransfer()->GetMotorTransferX()->GetMotorPostion();
    Sleep(5);
    double fZPos = m_pProCore->GetProTransfer()->GetMotorTransferZ()->GetMotorPostion();
    Sleep(5);
    //将获取的值赋值给参数
    ParamTransfer* ParaTransfer = m_pProCore->GetParamData()->GetParamTransfer();
    ParaTransfer->fXPosPlaceCamera = fXPos;
    ParaTransfer->fZPosPlaceCamera = fZPos;
    //将参数保存，根据PI尺寸和转移方式
    int type, size;
    switch(m_iTransferType)
    {
    case 0:
        type = INITIATIVE;
        break;
    case 1:
        type = PASSITIVITY;
        break;
    default:
        break;
    }
    int iSel;
    iSel = m_cPISizeComBox.GetCurSel();
    CString strSize;
    m_cPISizeComBox.GetLBText(iSel, strSize); 
    if (strSize == "6mm X 6mm")
    {
        size = SIZE66;
    } 
    else if(strSize == "5mm X 5mm")
    {
        size = SIZE55;
    }
    else if(strSize == "4mm X 4mm")
    {
        size = SIZE44;
    }
    else if(strSize == "3mm X 3mm")
    {
        size = SIZE33;
    }
    m_pProCore->GetParamData()->SaveTransferPa(type, size);
}


void CDlgTransferParamLearn::OnBnClickedTransferPFouraxleupviewBtn()
{
    double fXPos = m_pProCore->GetProTransfer()->GetMotorFourX()->GetMotorPostion();
    Sleep(5);
    double fYPos = m_pProCore->GetProTransfer()->GetMotorFourY()->GetMotorPostion();
    Sleep(5);
    double fAPos = m_pProCore->GetProTransfer()->GetMotorFourAngleA()->GetMotorPostion();
    Sleep(5);
    double fBPos = m_pProCore->GetProTransfer()->GetMotorFourAngleB()->GetMotorPostion();
    Sleep(5);
    double fCPos = m_pProCore->GetProTransfer()->GetMotorFourAngleC()->GetMotorPostion();
    Sleep(5);

    ParamTransfer* ParaTransfer = m_pProCore->GetParamData()->GetParamTransfer();
    ParaTransfer->fXPosViewFourAxle = fXPos;
    ParaTransfer->fYPosViewFourAxle = fYPos;
    ParaTransfer->fAPosPlaceFourAxle = fAPos;   //旋转轴到底是几个？？？

    //将参数保存，根据PI尺寸和转移方式
    int type, size;
    switch(m_iTransferType)
    {
    case 0:
        type = INITIATIVE;
        break;
    case 1:
        type = PASSITIVITY;
        break;
    default:
        break;
    }
    int iSel;
    iSel = m_cPISizeComBox.GetCurSel();
    CString strSize;
    m_cPISizeComBox.GetLBText(iSel, strSize); 
    if (strSize == "6mm X 6mm")
    {
        size = SIZE66;
    } 
    else if(strSize == "5mm X 5mm")
    {
        size = SIZE55;
    }
    else if(strSize == "4mm X 4mm")
    {
        size = SIZE44;
    }
    else if(strSize == "3mm X 3mm")
    {
        size = SIZE33;
    }
    m_pProCore->GetParamData()->SaveTransferPa(type, size);
}


void CDlgTransferParamLearn::OnNMReleasedcaptureTransferPPaceSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
    int iPos = m_cSliderPace.GetPos();
    m_cSliderPace.SetPos(iPos);
    CString str;
    str.Format(_T("%d"),iPos);
    m_cEditPace.SetWindowText(str);
    m_iPace = iPos;
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
}


void CDlgTransferParamLearn::OnDeltaposTransferPPaceSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    CString strTmp;
    int val;
    if(pNMUpDown->iDelta >0)                    //如果点击的是Spin中的往上按钮  ,1
    {
        m_cEditPace.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) + 1;
        m_cSpinPace.SetPos(val);
        m_cSliderPace.SetPos(val);		
        CString str;
        str.Format(_T("%d"),val);
        m_cEditPace.SetWindowTextA(str);
    }
    else if(pNMUpDown->iDelta <0)    //如果点击的是Spin中往下按钮,  -1
    {
        m_cEditPace.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) - 1;
        m_cSpinPace.SetPos(val);
        m_cSliderPace.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditPace.SetWindowTextA(str);
    }
    m_iPace = val;
    *pResult = 0;
}



void CDlgTransferParamLearn::OnEnChangeTransferPVacuumEdit()
{
    // TODO:  在此添加控件通知处理程序代码
    CString strTmp;
    int val;

    try
    {
        m_cEditVacuum.GetWindowTextA(strTmp);
        TRACE("enter OnEnChangeEditZ , get str in m_cEditZSpeed\n");
    }
    catch (CException* e)
    {
        throw (e);
        TRACE("test empty str of OnEnChangeEditZ in m_cEditZSpeed\n");
    }

    bool bEmptyOfString;
    bEmptyOfString = strTmp.IsEmpty();

    if(bEmptyOfString) val=0;
    else val =  (int)_tstof(strTmp);

    if ( val > 500 || val < 0 )
    {
        if (val > 0)
        {
            val = 500;
            CString str;
            str.Format(_T("%d"), val);
            m_cEditVacuum.SetWindowText(str);
        }
        else
        {
            val = 0;
            CString str;
            str.Format(_T("%d"), val);
            m_cEditVacuum.SetWindowText(str);
        }
        //AfxMessageBox(_T("请输入一个介于0到500之间的数！"));
    }
    m_cSpinVacuum.SetPos(val);
}


void CDlgTransferParamLearn::OnDeltaposTransferPVacuumSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    CString strTmp;
    int val;
    if(pNMUpDown->iDelta >0)                    //如果点击的是Spin中的往上按钮  ,1
    {
        m_cEditVacuum.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) + 1;
        m_cSpinVacuum.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditVacuum.SetWindowTextA(str);
    }
    else if(pNMUpDown->iDelta <0)    //如果点击的是Spin中往下按钮,  -1
    {
        m_cEditVacuum.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) - 1;
        m_cSpinVacuum.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditVacuum.SetWindowTextA(str);
    }
    *pResult = 0;
}


void CDlgTransferParamLearn::OnNMReleasedcaptureTransferPVoltageSlider(NMHDR *pNMHDR, LRESULT *pResult)
{
    int iPos = m_cSldV.GetPos();
    m_cSldV.SetPos(iPos);
    CString str;
    str.Format(_T("%d"),iPos);
    m_cEditV.SetWindowText(str);
    *pResult = 0;
}


void CDlgTransferParamLearn::OnEnChangeTransferPVoltageEdit()
{
    // TODO:  在此添加控件通知处理程序代码
    CString strTmp;
    int val;

    try
    {
        m_cEditV.GetWindowTextA(strTmp);
        TRACE("enter OnEnChangeEditZ , get str in m_cEditZSpeed\n");
    }
    catch (CException* e)
    {
        throw (e);
        TRACE("test empty str of OnEnChangeEditZ in m_cEditZSpeed\n");
    }

    bool bEmptyOfString;
    bEmptyOfString = strTmp.IsEmpty();

    if(bEmptyOfString) val=0;
    else val =  (int)_tstof(strTmp);

    if ( val > 500 || val < 0 )
    {
        if (val > 0)
        {
            val = 500;
            CString str;
            str.Format(_T("%d"), val);
            m_cEditVacuum.SetWindowText(str);
        }
        else
        {
            val = 0;
            CString str;
            str.Format(_T("%d"), val);
            m_cEditVacuum.SetWindowText(str);
        }
        //AfxMessageBox(_T("请输入一个介于0到500之间的数！"));
    }
    m_cSldV.SetPos(val);
    m_cSpinV.SetPos(val);
}


void CDlgTransferParamLearn::OnDeltaposTransferPVoltageSpin(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    CString strTmp;
    int val;
    if(pNMUpDown->iDelta >0)                    //如果点击的是Spin中的往上按钮  ,1
    {
        m_cEditV.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) + 1;
        m_cSpinV.SetPos(val);
        m_cSldV.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditV.SetWindowTextA(str);
    }
    else if(pNMUpDown->iDelta <0)    //如果点击的是Spin中往下按钮,  -1
    {
        m_cEditV.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) - 1;
        m_cSpinV.SetPos(val);
        m_cSldV.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditV.SetWindowTextA(str);
    }
    *pResult = 0;
}


void CDlgTransferParamLearn::OnNMReleasedcaptureTransferPFrequencySlider(NMHDR *pNMHDR, LRESULT *pResult)
{
    int iPos = m_cSldF.GetPos();
    m_cSldF.SetPos(iPos);
    CString str;
    str.Format(_T("%d"),iPos);
    m_cEditF.SetWindowText(str);
    *pResult = 0;
}


void CDlgTransferParamLearn::OnEnChangeTransferPFrequencyEdit()
{
    CString strTmp;
    int val;

    try
    {
        m_cEditF.GetWindowTextA(strTmp);
        TRACE("enter OnEnChangeEditZ , get str in m_cEditZSpeed\n");
    }
    catch (CException* e)
    {
        throw (e);
        TRACE("test empty str of OnEnChangeEditZ in m_cEditZSpeed\n");
    }

    bool bEmptyOfString;
    bEmptyOfString = strTmp.IsEmpty();

    if(bEmptyOfString) val=0;
    else val =  (int)_tstof(strTmp);

    if ( val > 500 || val < 0 )
    {
        if (val > 0)
        {
            val = 500;
            CString str;
            str.Format(_T("%d"), val);
            m_cEditF.SetWindowText(str);
        }
        else
        {
            val = 0;
            CString str;
            str.Format(_T("%d"), val);
            m_cEditF.SetWindowText(str);
        }
        //AfxMessageBox(_T("请输入一个介于0到500之间的数！"));
    }
    m_cSldF.SetPos(val);
    m_cSpinF.SetPos(val);
}


void CDlgTransferParamLearn::OnDeltaposTransferPFrequencySpin(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    CString strTmp;
    int val;
    if(pNMUpDown->iDelta >0)                    //如果点击的是Spin中的往上按钮  ,1
    {
        m_cEditF.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) + 1;
        m_cSpinF.SetPos(val);
        m_cSldF.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditF.SetWindowTextA(str);
    }
    else if(pNMUpDown->iDelta <0)    //如果点击的是Spin中往下按钮,  -1
    {
        m_cEditF.GetWindowTextA(strTmp);
        val =  (int)_tstof(strTmp) - 1;
        m_cSpinF.SetPos(val);
        m_cSldF.SetPos(val);
        CString str;
        str.Format(_T("%d"),val);
        m_cEditF.SetWindowTextA(str);
    }
    *pResult = 0;
}


void CDlgTransferParamLearn::OnBnClickedTransferPVacuumSaveBtn()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CDlgTransferParamLearn::OnBnClickedTransferPActivemodeRadio()
{
    GetDlgItem(IDC_TRANSFER_P_Vacuum_EDIT)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_SPIN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_VacuumNeg_RADIO)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_VacuumPosi_RADIO)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_VacuumRod_RADIO)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_VacuumPlat_RADIO)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_EDIT)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_SPIN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(TRUE);

    GetDlgItem(IDC_TRANSFER_P_Voltage_SLIDER)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Voltage_EDIT)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Voltage_SPIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_SLIDER)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_EDIT)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_SPIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_ElecStatic_Open_BTN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_New_LearnPos_BTN)->EnableWindow(FALSE);

	RefreshLocalRegion(IDC_TRANSFER_P_VacuumNeg_RADIO);
	RefreshLocalRegion(IDC_TRANSFER_P_VacuumPosi_RADIO);
	RefreshLocalRegion(IDC_TRANSFER_P_VacuumRod_RADIO);
	RefreshLocalRegion(IDC_TRANSFER_P_VacuumPlat_RADIO);
}


void CDlgTransferParamLearn::OnBnClickedTransferPPassivemodeRadio()
{
    GetDlgItem(IDC_TRANSFER_P_Voltage_SLIDER)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Voltage_EDIT)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Voltage_SPIN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_SLIDER)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_EDIT)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_Frequency_SPIN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_ElecStatic_Open_BTN)->EnableWindow(TRUE);
    GetDlgItem(IDC_TRANSFER_P_New_LearnPos_BTN)->EnableWindow(TRUE);

    GetDlgItem(IDC_TRANSFER_P_Vacuum_EDIT)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_SPIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_VacuumNeg_RADIO)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_VacuumPosi_RADIO)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_VacuumRod_RADIO)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_VacuumPlat_RADIO)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_EDIT)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_SPIN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_Save_BTN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_Open_BTN)->EnableWindow(FALSE);
    GetDlgItem(IDC_TRANSFER_P_Vacuum_Close_BTN)->EnableWindow(FALSE);
}


void CDlgTransferParamLearn::OnBnClickedTransferPCoordcalibBtn()
{
    m_bmpBtn[22].EnableWindow(FALSE);
    m_pDlgCoordCalib = new CDlgTransferParamCoordCalib(m_pProCore);
    ASSERT(m_pDlgCoordCalib);
    m_pDlgCoordCalib->Create(IDD_DLG_TRANSFER_P_COORDCALIB, this);
    CRect rect, rectPop;
    CWnd* MainWnd = (CWnd*)AfxGetApp()->m_pMainWnd;
    ASSERT(MainWnd);
    if (::GetWindowRect(MainWnd->m_hWnd, rect))
    {
        if (::GetWindowRect(m_pDlgCoordCalib->m_hWnd, rectPop))
        {
            m_pDlgCoordCalib->SetWindowPos(&wndNoTopMost, rect.right + 10, rect.top, rectPop.Width(), rect.Height(), SWP_SHOWWINDOW );
            m_pDlgCoordCalib->ShowWindow(TRUE);
        }
    }
}


void CDlgTransferParamLearn::OnBnClickedTransferPNewLearnposBtn()
{
    // TODO: 在此添加控件通知处理程序代码
}


void CDlgTransferParamLearn::RefreshLocalRegion(const int & ID)
{
	if ((CStatic*)GetDlgItem(ID)->GetSafeHwnd())  //判断窗口是否被销毁
	{
		CStatic * pWnd = ((CStatic*)GetDlgItem(ID));
		ASSERT(pWnd); //判断指针是否为空
		CRect Rect;
		pWnd ->GetWindowRect(&Rect);
		ScreenToClient(&Rect);
		InvalidateRect(&Rect);
	}
}


BOOL CDlgTransferParamLearn::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CDialog::PreTranslateMessage(pMsg);
}


void CDlgTransferParamLearn::OnEnChangeTransferPPaceEdit()
{
	// TODO:  在此添加控件通知处理程序代码
		CString strTmp;
		int val;

		try
		{
			m_cEditPace.GetWindowTextA(strTmp);
			TRACE("enter OnEnChangeEditZ , get str in m_cEditZSpeed\n");
		}
		catch (CException* e)
		{
			throw (e);
			TRACE("test empty str of OnEnChangeEditZ in m_cEditZSpeed\n");
		}

		bool bEmptyOfString;
		bEmptyOfString = strTmp.IsEmpty();

		if(bEmptyOfString) val=0;
		else val =  (int)_tstof(strTmp);

		if ( val > 500 || val < 0 )
		{
			if (val > 0)
			{
				val = 500;
				CString str;
				str.Format(_T("%d"), val);
				m_cEditPace.SetWindowText(str);
			}
			else
			{
				val = 0;
				CString str;
				str.Format(_T("%d"), val);
				m_cEditPace.SetWindowText(str);
			}
			//AfxMessageBox(_T("请输入一个介于0到500之间的数！"));
		}
		m_iPace = val;
		m_cSliderPace.SetPos(val);
		m_cSpinPace.SetPos(val);
}
