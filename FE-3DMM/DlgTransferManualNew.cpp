// DlgTransferManualNew.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgTransferManualNew.h"
#include "afxdialogex.h"


// CDlgTransferManualNew 对话框

IMPLEMENT_DYNAMIC(CDlgTransferManualNew, CDialogEx)

CDlgTransferManualNew::CDlgTransferManualNew(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgTransferManualNew::IDD, pParent)
{
	m_pProCore = pProCore;
}

CDlgTransferManualNew::~CDlgTransferManualNew()
{
	Release();
}



void CDlgTransferManualNew::Release()
{

}

void CDlgTransferManualNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TRANSFER_M_N_PISize_COMBO, m_cComBoxPISize);
}


BEGIN_MESSAGE_MAP(CDlgTransferManualNew, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_TRANSFER_M_N_Ok_BTN, &CDlgTransferManualNew::OnBnClickedTransferMNOkBtn)
	ON_BN_CLICKED(IDC_TRANSFER_M_N_Cancel_BTN, &CDlgTransferManualNew::OnBnClickedTransferMNCancelBtn)
END_MESSAGE_MAP()



BOOL CDlgTransferManualNew::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitCtrl();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


// CDlgTransferManualNew 消息处理程序
HBRUSH CDlgTransferManualNew::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) 
	{ 
		switch(pWnd->GetDlgCtrlID()) 
		{
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


BOOL CDlgTransferManualNew::OnEraseBkgnd(CDC* pDC)
{
	CDC MemDC; 
	//CBitmap对象
	CBitmap Bitmap,*pOldBitmap; 
	//BITMAP句柄
	BITMAP bm; 
	//加载位图
	Bitmap.LoadBitmap(IDB_BITMAP_BACKGROUND); 
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


void CDlgTransferManualNew::InitCtrl()
{
	m_cComBoxPISize.AddString("3mm X 3mm");
	m_cComBoxPISize.AddString("4mm X 4mm");
	m_cComBoxPISize.AddString("5mm X 5mm");
	m_cComBoxPISize.AddString("6mm X 6mm");

	m_cComBoxPISize.SetCurSel(3);
}


void CDlgTransferManualNew::OnBnClickedTransferMNOkBtn()
{
	UpdateData(TRUE);                    //控件中的值更新到关联变量
	char XEdit[256], YEdit[256];
	char * StopString;
	memset(XEdit, 0, 256);
	memset(XEdit, 0, 256);
	GetDlgItemText(IDC_TRANSFER_M_N_X_EDIT, XEdit, 256);
	GetDlgItemText(IDC_TRANSFER_M_N_Y_EDIT, YEdit, 256);

	if (strcmp(XEdit, "") == 0 || strcmp(YEdit, "") == 0)
	{
		MessageBox("请输入数值", "提示", NULL);
		return;
	}
	
	double fXToCenter = strtod(XEdit, &StopString);
	if (strcmp(StopString, "\0") != 0)
	{
		MessageBox("输入数据有误，请重新输入", "提示", NULL);
		return;
	}

	double fYToCenter = strtod(YEdit, &StopString);
	if (strcmp(StopString, "\0") != 0)
	{
		MessageBox("输入数据有误，请重新输入", "提示", NULL);
		return;
	}

	// 将设定的参数传给系统参数
	int iSel;
	iSel = m_cComBoxPISize.GetCurSel();
	CString strSize;
	m_cComBoxPISize.GetLBText(iSel, strSize); 
	if (strSize == "6mm X 6mm")
	{
		m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.iSize = SIZE66;
	} 
	else if(strSize == "5mm X 5mm")
	{
		m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.iSize = SIZE55;
	}
	else if(strSize == "4mm X 4mm")
	{
		m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.iSize = SIZE44;
	}
	else if(strSize == "3mm X 3mm")
	{
		m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.iSize = SIZE33;
	}
	
	m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.fXToCenter = fXToCenter;
	m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.fYToCenter = fYToCenter;


	//获取时间
	CString  strFullTime("");
	CTime strTime = CTime::GetCurrentTime();	//获得系统时间
	strFullTime = strTime.Format("%Y/%m/%d" /*%H:%M:%S*/);

	CString strFileName = strSize + "_" + (CString)XEdit + "_" + (CString)YEdit;

	/*判断文件是否已近存在*/
	if (FileExist(strFileName))
	{
		MessageBox("对象已经存在！", "提示", NULL);
		return;
	}
	
	//保存一个文件
	CString lpAppName = "Transfer_Object_File";
	CString strValue;
	CString strDebugPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1);
	CString lpFileName = strDebugPath + "Storage\\Config\\TransferObject\\" + strFileName;	

	WritePrivateProfileString(lpAppName, "CreatedTime", strFullTime, lpFileName);

	strValue.Format("%d", m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.iSize);
	WritePrivateProfileString(lpAppName, "iPlaceObject", strValue, lpFileName);

	strValue.Format("%.5f", m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.fXToCenter);
	WritePrivateProfileString(lpAppName, "iPlaceObject", strValue, lpFileName);

	strValue.Format("%.5f", m_pProCore->GetParamData()->GetParamTransfer()->iPlaceObject.fYToCenter);
	WritePrivateProfileString(lpAppName, "iPlaceObject", strValue, lpFileName);
	CDlgTransferManualNew::OnOK();
}


BOOL CDlgTransferManualNew::FileExist(const CString FileName) const
{
	//遍历查找一遍，是否存在该文件
	CString strDebugPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1);
	CString strFilePath = strDebugPath + "Storage\\Config\\TransferObject\\";	
	CString strTemp = strFilePath + "*.*";   
	CFileFind FileFind;
	BOOL bFind = FileFind.FindFile(strTemp);
	while (bFind)
	{
		//查找下一个文件
		bFind = FileFind.FindNextFile();
		//判断是否为文件夹
		if(FileFind.IsDots())
			continue;
		if (FileName == FileFind.GetFileName())
		{
			return TRUE;
		}
	}
	return FALSE;
}

void CDlgTransferManualNew::OnBnClickedTransferMNCancelBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgTransferManualNew::OnCancel();
}



