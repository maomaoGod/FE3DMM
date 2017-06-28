// DlgTransferParamCoordCalib.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "FE-3DMMDlg.h"
#include "DlgTransferParamCoordCalib.h"
#include "DlgTransfer.h"
#include "afxdialogex.h"


// CDlgTransferParamCoordCalib 对话框

IMPLEMENT_DYNAMIC(CDlgTransferParamCoordCalib, CDialogEx)

int CDlgTransferParamCoordCalib::m_iPressCount = 0;

CDlgTransferParamCoordCalib::CDlgTransferParamCoordCalib(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTransferParamCoordCalib::IDD, pParent)
{
	ASSERT(pProCore);
	m_pProCore = pProCore;
	SetParentWnd();
}

CDlgTransferParamCoordCalib::~CDlgTransferParamCoordCalib()
{
	Release();
}

void CDlgTransferParamCoordCalib::Release()
{

}

void CDlgTransferParamCoordCalib::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTransferParamCoordCalib, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_TRANSFER_P_C_SaveCenter_BTN, &CDlgTransferParamCoordCalib::OnBnClickedTransferPCSavecenterBtn)
	ON_BN_CLICKED(IDC_TRANSFER_P_C_SaveCam_BTN, &CDlgTransferParamCoordCalib::OnBnClickedTransferPCClibBtn)
	ON_BN_CLICKED(IDC_TRANSFER_P_C_CalibPickerCam_BTN, &CDlgTransferParamCoordCalib::OnBnClickedTransferPCCalibpickercamBtn)
END_MESSAGE_MAP()


// CDlgTransferParamCoordCalib 消息处理程序
void CDlgTransferParamCoordCalib::Cancel()
{
	OnCancel();
}

void CDlgTransferParamCoordCalib::OnCancel()
{
	//CWnd* pParent = ((CFE3DMMDlg*)AfxGetMainWnd())->m_pDlgTransfer->m_pDlgTransferParaLearn;
    CWnd* pBtnWnd = (static_cast<CWnd*>(m_pParent))->GetDlgItem(IDC_TRANSFER_P_CoordCalib_BTN);
	pBtnWnd->EnableWindow(TRUE);
	DestroyWindow();
}

void CDlgTransferParamCoordCalib::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();	
	delete this;
}

BOOL CDlgTransferParamCoordCalib::OnEraseBkgnd(CDC* pDC)
{
	CDC MemDC;
	CBitmap Bitmap, *pOldBitmap;
	BITMAP bm;
	Bitmap.LoadBitmap(IDB_BITMAP_BACKGROUND);
	Bitmap.GetObject(sizeof(BITMAP),&bm); 
	MemDC.CreateCompatibleDC(pDC);
	pOldBitmap = (CBitmap*)(MemDC.SelectObject(&Bitmap));

	CRect rcClient;
	GetClientRect(&rcClient);

	pDC->BitBlt(0,0,rcClient.Width(),rcClient.Height(),&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	MemDC.DeleteDC(); 
	return TRUE;
}


HBRUSH CDlgTransferParamCoordCalib::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
			case IDC_STATIC:
			{
				CFont font;
				font.CreatePointFont( 120, _T("宋体") );
				pDC->SetBkMode(TRANSPARENT); 
				pDC->SetTextColor(RGB(0,0,0)); 
				pDC->SelectObject(&font);
				return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
			}
		case IDC_TRANSFER_P_C_NOTE_STATIC:
			{
				CFont font;
				font.CreatePointFont( 120, _T("宋体") );
				pDC->SetBkMode(TRANSPARENT); 
				pDC->SetTextColor(RGB(0,0,0)); 
				pDC->SelectObject(&font);
				return (HBRUSH)GetStockObject(HOLLOW_BRUSH); 
			}
		default: 
			break; 
		} 
	}
	return hbr;
}

void CDlgTransferParamCoordCalib::SetParentWnd()
{
	m_pParent = ((CFE3DMMDlg*)AfxGetMainWnd())->m_pDlgTransfer->m_pDlgTransferParaLearn;
	ASSERT(m_pParent);
}


BOOL CDlgTransferParamCoordCalib::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitCtrl();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgTransferParamCoordCalib::InitCtrl()
{
	m_bmpBtn[0].SubclassDlgItem(IDC_TRANSFER_P_C_SaveCenter_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(15);
	m_bmpBtn[0].SetTitle("保存机械手中心");

	m_bmpBtn[1].SubclassDlgItem(IDC_TRANSFER_P_C_SaveCam_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(15);
	m_bmpBtn[1].SetTitle("保存相机位置");
	m_bmpBtn[1].EnableWindow(FALSE);

	m_bmpBtn[2].SubclassDlgItem(IDC_TRANSFER_P_C_CalibPickerCam_BTN, this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(15);
	m_bmpBtn[2].SetTitle("完成标定");
	m_bmpBtn[2].EnableWindow(FALSE);

	m_bmpBtn[3].SubclassDlgItem(IDC_TRANSFER_P_C_SaveX_BTN, this);
	m_bmpBtn[3].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[3].SetFont(15);
	m_bmpBtn[3].SetTitle("保存X方向值");

	m_bmpBtn[4].SubclassDlgItem(IDC_TRANSFER_P_C_SaveY_BTN, this);
	m_bmpBtn[4].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[4].SetFont(15);
	m_bmpBtn[4].SetTitle("保存Y方向值");

	m_bmpBtn[5].SubclassDlgItem(IDC_TRANSFER_P_C_SaveZ_BTN, this);
	m_bmpBtn[5].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[5].SetFont(15);
	m_bmpBtn[5].SetTitle("保存Z方向值");
}


void CDlgTransferParamCoordCalib::OnBnClickedTransferPCSavecenterBtn()
{
	// TODO: 在此添加控件通知处理程序代码
#ifndef FE_DEBUG_OFFLINE
	CCtrlMotor *pMotorX;
	pMotorX = m_pProCore->GetProTransfer()->GetMotorTransferX();
	ASSERT(pMotorX);
	m_fTransferPickPosX = pMotorX->GetMotorPostion();
#endif
	MessageBox(_T("保存成功"), _T("提示"), MB_OK);
	m_bmpBtn[1].EnableWindow(TRUE);
}


void CDlgTransferParamCoordCalib::OnBnClickedTransferPCClibBtn()
{
	//获取采图时电机的位置
	CCtrlMotor *pMotorX;
	pMotorX = m_pProCore->GetProTransfer()->GetMotorTransferX();
	ASSERT(pMotorX);
	m_fTransCamPosX = pMotorX->GetMotorPostion();

	//转印下视相机采集一张图像
	PylonCamera  * TransCam = m_pProCore->GetCameraTransDown();
		
	//定位圆心位置与相机中心的偏距
	double fOffsetX, fOffsetY;   
	//机械手中心与相机中心偏距
	double fDisPickCamX, fDisPickCamY;
	
	if (LocateCircle(TransCam->GetSingleLocal(), fOffsetX, fOffsetY))
	{
		fDisPickCamX = (m_fTransCamPosX - m_fTransferPickPosX) + fOffsetX;
		fDisPickCamY = fOffsetY;

		PickCamOffset tempOffset;
		tempOffset.fOffsetX = fDisPickCamX;
		tempOffset.fOffsetY = fDisPickCamY;
		m_vecOffset.push_back(tempOffset);

		MessageBox(_T("保存成功"), _T("提示"), MB_OK);

		if ( ++m_iPressCount == 3)
		{
			m_bmpBtn[2].EnableWindow(TRUE);
		}
	}
}


void CDlgTransferParamCoordCalib::OnBnClickedTransferPCCalibpickercamBtn()
{
	double sumX = 0.0, sumY = 0.0;
	std::vector<PickCamOffset>::iterator beg = m_vecOffset.begin();
	for (; beg != m_vecOffset.end(); ++beg)
	{
		sumX += (*beg).fOffsetX;
		sumY += (*beg).fOffsetY;
	}
	m_fOffsetX = sumX / m_vecOffset.size();
	m_fOffsetY = sumY / m_vecOffset.size();
	//保存结果
	m_pProCore->GetParamData()->GetParamTransfer()->fDisPickerCamX = m_fOffsetX;
	m_pProCore->GetParamData()->GetParamTransfer()->fDisPickerCamY = m_fOffsetY;
	m_iPressCount = 0;
	m_bmpBtn[2].EnableWindow(FALSE);
}


BOOL CDlgTransferParamCoordCalib::LocateCircle(const HObject* hoImage, const double &fOffsetX, const double&fOffsetY)
{
	return TRUE;
}