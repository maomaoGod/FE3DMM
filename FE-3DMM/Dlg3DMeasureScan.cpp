// Dlg3DMeasureScan.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "Dlg3DMeasureScan.h"
#include "afxdialogex.h"


// CDlg3DMeasureScan 对话框
ISD_LaserCOMPtr oLaserCom = NULL;
int NumofProbes = 0;
IMPLEMENT_DYNAMIC(CDlg3DMeasureScan, CDialog)

CDlg3DMeasureScan::CDlg3DMeasureScan(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlg3DMeasureScan::IDD, pParent)
{
	m_pProCore = pProCore;
}

CDlg3DMeasureScan::~CDlg3DMeasureScan()
{
	Release();
}

void CDlg3DMeasureScan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_3DMEASURE_S_GB1_GROUP, m_GB1);
	DDX_Control(pDX, IDC_3DMEASURE_S_LensMaxDis_COMBOX, m_cbLens);
	DDX_Control(pDX, IDC_3DMEASURE_S_LensDis_SLIDER, m_sliderPower);
	DDX_Control(pDX, IDC_3DMEASURE_S_ProbeType_COMBOX, m_CBProbeType);
	DDX_Text(pDX, IDC_3DMEASURE_S_LensDis_EDIT, m_sSliderPower);
	DDX_Text(pDX, IDC_3DMEASURE_S_LensMinDis_EDIT, m_sDisMin);
	DDX_Text(pDX, IDC_3DMEASURE_S_LensMaxDis_EDIT, m_sDisMax);
	DDX_Text(pDX, IDC_3DMEASURE_S_PointDis_EDIT, m_sDistance);
	DDX_Text(pDX, IDC_3DMEASURE_S_PointSNR_EDIT, m_sSNR);
//	DDX_Text(pDX, IDC_3DMEASURE_S_PointFreq_EDIT, m_Freq);
//	DDX_Text(pDX, IDC_3DMEASURE_S_PointQuality_EDIT, m_sQuality);

}


BEGIN_MESSAGE_MAP(CDlg3DMeasureScan, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_HSCROLL()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_3DMEASURE_S_Connect_BTN, &CDlg3DMeasureScan::OnBnClicked3dmeasureSConnectBtn)
	ON_BN_CLICKED(IDC_3DMEASURE_S_Start_BTN, &CDlg3DMeasureScan::OnBnClicked3dmeasureSStartBtn)
	ON_BN_CLICKED(IDC_3DMEASURE_S_Stop_BTN, &CDlg3DMeasureScan::OnBnClicked3dmeasureSStopBtn)
	ON_CBN_SELCHANGE(IDC_3DMEASURE_S_LensMaxDis_COMBOX, &CDlg3DMeasureScan::OnCbnSelchange3dmeasureSLensmaxdisCombox)
//	ON_EN_CHANGE(IDC_3DMEASURE_S_PointFreq_EDIT, &CDlg3DMeasureScan::OnEnChange3dmeasureSPointfreqEdit)
END_MESSAGE_MAP()


// CDlg3DMeasureScan 消息处理程序
void CDlg3DMeasureScan::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlg3DMeasureScan::OnCancel()
{
//	DestroyWindow();
}


void CDlg3DMeasureScan::Cancel()
{
	OnCancel();
}


void CDlg3DMeasureScan::Release()
{

}


HBRUSH CDlg3DMeasureScan::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
		case IDC_STATIC:
			pDC->SetBkMode(TRANSPARENT); 
			pDC->SetTextColor(RGB(0,0,0)); 
			return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
		default: 
			break; 
		} 
	}
	return hbr;
}


BOOL CDlg3DMeasureScan::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlg3DMeasureScan::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlgCtrl();
	CoInitialize(NULL);

	oLaserCom.CreateInstance(__uuidof(SD_LaserCOM));



	m_CBProbeType.SetCurSel(1);
	m_sliderPower.SetRange(0, 63, TRUE);
	m_sliderPower.SetPos(20);
	return TRUE;  
}


void CDlg3DMeasureScan::InitDlgCtrl()
{
	m_GB1.SetXPGroupStyle(CXPGroupBox::XPGB_WINDOW)
		.SetFontBold(TRUE)
		.SetFontSize(16)
		.SetAlignment(SS_CENTER);

	m_bmpBtn[0].SubclassDlgItem(IDC_3DMEASURE_S_Connect_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(16);
	m_bmpBtn[0].SetTitle("连接测头");

	m_bmpBtn[1].SubclassDlgItem(IDC_3DMEASURE_S_Start_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(16);
	m_bmpBtn[1].SetTitle("开始测量");

	m_bmpBtn[2].SubclassDlgItem(IDC_3DMEASURE_S_Stop_BTN, this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(16);
	m_bmpBtn[2].SetTitle("停止测量");
}

void CDlg3DMeasureScan::OnBnClicked3dmeasureSConnectBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	//定义要显示的数据
	byte Res = 0;

	unsigned short port = 0;
	byte bRes = 0;
	long SN = 0;

	int nCurSel = 1;
	oLaserCom->SetProbeType(nCurSel,&bRes);//选择将要用哪个probe
	oLaserCom->ProbeDetect(&port);//检测连接到系统的probe数量，为其注册IP
	NumofProbes = port;

	for (int i = 0; i < NumofProbes; i++)
	{
		oLaserCom->SetActiveProbe(i, &bRes);//设置活动probe的索引
		oLaserCom->ProbeGetHeadSN(&SN);//获取probe的序列号
		CString sSN;
		sSN.Format("%ld",SN);
//		m_CBProbes.AddString(sSN);

		oLaserCom->ProbeInit(i, &Res);
		if (Res == 0)
		{
			//MessageBox.Show("Can't initialize Probe", "Probe Laser COM", MessageBoxButtons.OK, MessageBoxIcon.Error);
			oLaserCom->ProbeTerminate();//如果想换活动Probe,则终止当前的probe
		}

	}
	int val = m_sliderPower.GetPos();

	oLaserCom->ProbeSetPower(2, val, &Res);//设置激光强度

	unsigned short power = 0;
	oLaserCom->ProbeGetPower(2, &power);//返回实际激光强度值
//	GetDlgItem(IDC_3DMEASURE_S_LensDis_SLIDER)->SetWindowText(pp);
	m_sSliderPower.Format("%ld",power); 
	UpdateData(FALSE);
//	m_CBProbes.SetCurSel(0);
	OnChangeProbes();
	OnChangeLens();

}


void CDlg3DMeasureScan::OnBnClicked3dmeasureSStartBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	//SD_LaserCOMLib.PrbMeasurementInt Meas = new PrbMeasurementInt();
	byte Res = 0;
	timer1 = SetTimer(1,100,0);
	for (int t = 0; t < NumofProbes; t++)
	{
		oLaserCom->SetActiveProbe(t, &Res);
		oLaserCom->ProbeBeginReadMeasurementStream(10,(TPrbMode)0,0, &Res);//转换到测量模式
	}


//	timer1 = SetTimer(1,100,0);


}


void CDlg3DMeasureScan::OnBnClicked3dmeasureSStopBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(timer1);
}
void CDlg3DMeasureScan::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == (CScrollBar *) &m_sliderPower)
	{
		int val = m_sliderPower.GetPos();

		byte Res = 0;
		oLaserCom->ProbeSetPower(2, val, &Res);//设置激光强度

		unsigned short power = 0;
		oLaserCom->ProbeGetPower(2, &power);//返回实际激光强度值

		m_sSliderPower.Format("%ld",power); 
		UpdateData(FALSE);
	}
	else
	{
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}

void CDlg3DMeasureScan::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	IPrbMeasurementIntPtr Meas = NULL;  

	if (nIDEvent == timer1)
	{
		byte Res = 0;

		for (int t = 0; t < NumofProbes; t++)
		{
			oLaserCom->SetActiveProbe(t, &Res);
			oLaserCom->ProbeGetMeasurementStream(&Meas, &Res);//

			if (Res != 0)
			{
				float f = 0;
				Meas->Distance(&f);
				m_sDistance.Format("%f",f);
				long SNR = 0, Total = 0;
				Meas->Snr(&SNR);
				SNR = SNR * 100 / 1024;
				m_sSNR.Format("%ld",SNR);                
// 				Meas->Total(&Total);
// 				m_sQuality.Format("%ld",Total);
			}
		}
	}
	else if (nIDEvent == timer2)
	{
		byte Res = 0;

		oLaserCom->ProbeReadMeasurement(&Meas, &Res);//显示一副图像，并可以换扫描仪参数
		if (Res != 0)
		{
			float f = 0;
			Meas->Distance(&f);
			m_sDistance.Format("%f",f);
			long SNR = 0, Total = 0;
			Meas->Snr(&SNR);
			SNR = SNR * 100 / 1024;
			m_sSNR.Format("%ld",SNR);
// 			Meas->Total(&Total);
// 			m_sQuality.Format("%ld",Total);
		}
	}

	UpdateData(FALSE);

	CDialog::OnTimer(nIDEvent);
}

void CDlg3DMeasureScan::OnCbnSelchange3dmeasureSLensmaxdisCombox()
{
	// TODO: 在此添加控件通知处理程序代码
	OnChangeLens();
}
void CDlg3DMeasureScan::OnChangeProbes()
{
	unsigned short power = 0;

    byte res = 0;
    oLaserCom->SetActiveProbe(30745, &res);
    //Fill in Lens Dialog

    oLaserCom->ProbeGetPower(2, &power);

    byte Cnt = 0;
    oLaserCom->ProbeGetLensCount(&Cnt);//返回扫描仪已经校准好的镜头数量
    IPrbLensIntPtr Lens = NULL;
	Lens.CreateInstance(__uuidof(PrbLensInt));
    long Val = 0;
	CString sdis; 
    for (byte ii = 1; ii <= Cnt; ii++)
    {
        oLaserCom->ProbeGetLens(ii, &Lens, &res);//更新镜头参数
		if (res == 1)
		{
			Lens->FocalDistance(&Val);//镜头到发射激光束焦点的距离
			sdis.Format("%ld",Val);
			m_cbLens.AddString(sdis);
		}

    }
    oLaserCom->ProbeGetActiveLensIndex(&Cnt);//当前镜头的数据
	m_cbLens.SetCurSel(Cnt-1);


	UpdateData(FALSE);
}
void CDlg3DMeasureScan::OnChangeLens()
{
	byte Res = 0;
	byte idx = (byte)(m_cbLens.GetCurSel() + 1);
	oLaserCom->ProbeSetActiveLensIndex(idx, &Res);//配置扫描仪来校准变化后的距离参数
	IPrbLensIntPtr Lens = NULL;
	Lens.CreateInstance(__uuidof(PrbLensInt));
	oLaserCom->ProbeGetLens(idx, &Lens, &Res);
	float val =0;
	Lens->DistanceMin(&val);
	m_sDisMin.Format("%f",val);
	Lens->DistanceMax(&val);
	m_sDisMax.Format("%f",val);

	UpdateData(FALSE);
}

