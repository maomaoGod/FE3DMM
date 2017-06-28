// DlgLaserStripSWParamRecord.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgLaserStripSWParamRecord.h"
#include "afxdialogex.h"
#include "DlgLaserStripSubWin.h"


// CDlgLaserStripSWParamRecord 对话框

IMPLEMENT_DYNAMIC(CDlgLaserStripSWParamRecord, CDialog)

CDlgLaserStripSWParamRecord::CDlgLaserStripSWParamRecord(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLaserStripSWParamRecord::IDD, pParent)
{
	m_pDlgLaserStripSubWinMain = (CDlgLaserStripSubWin*)pParent;
	m_strDatabasePath = _T("");
}

CDlgLaserStripSWParamRecord::~CDlgLaserStripSWParamRecord()
{
	Release();
}

void CDlgLaserStripSWParamRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LASERSTRIP_SUB_PR_ScanMode_COMBO, m_comboboxScanMode);
}


BEGIN_MESSAGE_MAP(CDlgLaserStripSWParamRecord, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_CLOSE()
	ON_CBN_SELCHANGE(IDC_LASERSTRIP_SUB_PR_ScanMode_COMBO, &CDlgLaserStripSWParamRecord::OnSelchangeLaserstripSubPRScanModeCombo)
	ON_BN_CLICKED(IDC_LASERSTRIP_SUB_PR_Add_BTN, &CDlgLaserStripSWParamRecord::OnClickedLaserstripSubPrAddBtn)
	ON_BN_CLICKED(IDC_LASERSTRIP_SUB_PR_Delete_BTN, &CDlgLaserStripSWParamRecord::OnBnClickedLaserstripSubPrDeleteBtn)
	ON_BN_CLICKED(IDC_LASERSTRIP_SUB_PR_Apply_BTN, &CDlgLaserStripSWParamRecord::OnBnClickedLaserstripSubPrApplyBtn)
END_MESSAGE_MAP()


// CDlgLaserStripSWParamRecord 消息处理程序


void CDlgLaserStripSWParamRecord::OnCancel()
{
	DestroyWindow();
}


void CDlgLaserStripSWParamRecord::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlgLaserStripSWParamRecord::Cancel()
{
	OnCancel();
}


void CDlgLaserStripSWParamRecord::Release()
{

}


BOOL CDlgLaserStripSWParamRecord::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlgCtrl();
	InitGridListData();

	m_comboboxScanMode.AddString("单行扫描");
	m_comboboxScanMode.AddString("多行扫描");
	m_comboboxScanMode.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgLaserStripSWParamRecord::InitDlgCtrl()
{
	m_bmpBtn[0].SubclassDlgItem(IDC_LASERSTRIP_SUB_PR_Add_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(15);
	m_bmpBtn[0].SetTitle("添加");

	m_bmpBtn[1].SubclassDlgItem(IDC_LASERSTRIP_SUB_PR_Delete_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(15);
	m_bmpBtn[1].SetTitle("删除");

	m_bmpBtn[2].SubclassDlgItem(IDC_LASERSTRIP_SUB_PR_Apply_BTN, this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(15);
	m_bmpBtn[2].SetTitle("应用");
}


BOOL CDlgLaserStripSWParamRecord::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}


HBRUSH CDlgLaserStripSWParamRecord::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgLaserStripSWParamRecord::OnEraseBkgnd(CDC* pDC)
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


void CDlgLaserStripSWParamRecord::OnClose()
{
	if (NULL != m_pDlgLaserStripSubWinMain)
	{
		m_pDlgLaserStripSubWinMain->OnBnClickedLaserstripSPathParamSaveBtn();
	}
}


void CDlgLaserStripSWParamRecord::InitGridListData()
{
	m_strDatabasePath =  m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1) + _T("Storage\\Database.mdb");
	if (!m_adoDatabase.OpenMDB(m_strDatabasePath))
	{
		MessageBox("连接数据库失败！");
		return;
	}

	InitGridListSingleParam();
	InitGridListMultiParam();
	
	GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST)->ShowWindow(SW_HIDE);
}


void CDlgLaserStripSWParamRecord::InitGridListSingleParam()
{
	//初始化单行扫描参数List
	CAdoRecordset recordset;
	if (!recordset.OpenTable("LaserSingleScanParamTable", &m_adoDatabase))
	{
		MessageBox("打开单行扫描参数表失败！");
		return;
	}

	CRect rcGrid;
	GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST)->GetClientRect(&rcGrid);
	m_gridlistSingleParam.Create(rcGrid, GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST), IDC_LASERSTRIP_SUB_PR_SingleParam_LIST);

	//初始化列表各项
	int nFixedColum = 0;
	int nFixedRow = 1;
	int nRowCount = 1;
	int nColumCount = recordset.GetFieldCount();

	m_gridlistSingleParam.SetAutoSizeStyle();
	m_gridlistSingleParam.SetEditable(FALSE);
	m_gridlistSingleParam.SetFixedColumnSelection(FALSE);
	m_gridlistSingleParam.ExpandColumnsToFit(TRUE);

	m_gridlistSingleParam.SetRowCount(nRowCount);
	m_gridlistSingleParam.SetColumnCount(nColumCount);
	m_gridlistSingleParam.SetFixedColumnCount(nFixedColum);
	m_gridlistSingleParam.SetFixedRowCount(nFixedRow);

	CString strItemText = _T("");
	GV_ITEM item;
	item.crBkClr = RGB(200, 255, 255);
	item.nFormat = DT_CENTER|DT_WORDBREAK;
	item.mask = GVIF_TEXT|GVIF_BKCLR|GVIF_FORMAT;
	item.row = 0;

	for (int iColIndex=0; iColIndex<nColumCount; iColIndex++)
	{
		recordset.GetFieldName(iColIndex, strItemText);
		item.col = iColIndex;
		item.strText = strItemText;
		m_gridlistSingleParam.SetItem(&item);

		if (0 == iColIndex)
			m_gridlistSingleParam.SetColumnWidth(iColIndex, 132);
		else
			m_gridlistSingleParam.SetColumnWidth(iColIndex, 80);	
	}

	ShowGridListSingleParam(&recordset);

	recordset.CloseTable();
}


void CDlgLaserStripSWParamRecord::InitGridListMultiParam()
{
	//初始化多行扫描参数List
	CAdoRecordset recordset;
	if (!recordset.OpenTable("LaserMultiScanParamTable", &m_adoDatabase))
	{
		MessageBox("打开多行扫描参数表失败！");
		return;
	}

	CRect rcGrid;
	GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST)->GetClientRect(&rcGrid);
	m_gridlistMultiParam.Create(rcGrid, GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST), IDC_LASERSTRIP_SUB_PR_MultiParam_LIST);

	//初始化列表各项
	int nFixedColum = 0;
	int nFixedRow = 1;
	int nRowCount = 1;
	int nColumCount = recordset.GetFieldCount();

	m_gridlistMultiParam.SetAutoSizeStyle();
	m_gridlistMultiParam.SetEditable(FALSE);
	m_gridlistMultiParam.SetFixedColumnSelection(FALSE);
	m_gridlistMultiParam.ExpandColumnsToFit(TRUE);

	m_gridlistMultiParam.SetRowCount(nRowCount);
	m_gridlistMultiParam.SetColumnCount(nColumCount);
	m_gridlistMultiParam.SetFixedColumnCount(nFixedColum);
	m_gridlistMultiParam.SetFixedRowCount(nFixedRow);

	CString strItemText = _T("");
	GV_ITEM item;
	item.crBkClr = RGB(200, 255, 255);
	item.nFormat = DT_CENTER|DT_WORDBREAK;
	item.mask = GVIF_TEXT|GVIF_BKCLR|GVIF_FORMAT;
	item.row = 0;

	for (int iColIndex=0; iColIndex<nColumCount; iColIndex++)
	{
		recordset.GetFieldName(iColIndex, strItemText);
		item.col = iColIndex;
		item.strText = strItemText;
		m_gridlistMultiParam.SetItem(&item);

		if (0 == iColIndex)
			m_gridlistMultiParam.SetColumnWidth(iColIndex, 132);
		else
			m_gridlistMultiParam.SetColumnWidth(iColIndex, 80);	
	}

	ShowGridListMultiParam(&recordset);

	recordset.CloseTable();
}


void CDlgLaserStripSWParamRecord::ShowGridListSingleParam(CAdoRecordset* pRecordSet)
{
	if (NULL == pRecordSet || (pRecordSet->IsBOF() && pRecordSet->IsEOF()))
	{
		return;
	}
	else
	{
		pRecordSet->MoveFirst();
	}

	//清空列表行数据
	m_gridlistSingleParam.DeleteNonFixedRows();

	int row = 1;
	GV_ITEM item;
	item.crBkClr = RGB(255, 255, 255);
	item.nFormat = DT_CENTER|DT_VCENTER;
	item.mask = GVIF_TEXT|GVIF_BKCLR|GVIF_FORMAT;

	CString strValue = "";
	int iColCount = pRecordSet->GetFieldCount();
	while (!pRecordSet->IsEOF())
	{
		m_gridlistSingleParam.InsertRow(NULL); //在末尾插入一行

		for (int iColIndex=0; iColIndex<iColCount; iColIndex++)
		{
			item.row = row;
			item.col = iColIndex;
			strValue = pRecordSet->GetFieldValue(iColIndex);
			item.strText = strValue;
			m_gridlistSingleParam.SetItem(&item);
		}	

		++row;
		pRecordSet->MoveNext();
	}

	m_gridlistSingleParam.UpdateData(FALSE);
	m_gridlistSingleParam.Refresh();
}


void CDlgLaserStripSWParamRecord::ShowGridListMultiParam(CAdoRecordset* pRecordSet)
{
	if (NULL == pRecordSet || (pRecordSet->IsBOF() && pRecordSet->IsEOF()))
	{
		return;
	}
	else
	{
		pRecordSet->MoveFirst();
	}

	//清空列表行数据
	m_gridlistMultiParam.DeleteNonFixedRows();

	int row = 1;
	GV_ITEM item;
	item.crBkClr = RGB(255, 255, 255);
	item.nFormat = DT_CENTER|DT_VCENTER;
	item.mask = GVIF_TEXT|GVIF_BKCLR|GVIF_FORMAT;

	CString strValue = "";
	int iColCount = pRecordSet->GetFieldCount();
	while (!pRecordSet->IsEOF())
	{
		m_gridlistMultiParam.InsertRow(NULL); //在末尾插入一行

		for (int iColIndex=0; iColIndex<iColCount; iColIndex++)
		{
			item.row = row;
			item.col = iColIndex;
			strValue = pRecordSet->GetFieldValue(iColIndex);
			item.strText = strValue;
			m_gridlistMultiParam.SetItem(&item);
		}	

		++row;
		pRecordSet->MoveNext();
	}

	m_gridlistMultiParam.UpdateData(FALSE);
	m_gridlistMultiParam.Refresh();
}


void CDlgLaserStripSWParamRecord::OnSelchangeLaserstripSubPRScanModeCombo()
{
	CString strTemp = _T("");
	m_comboboxScanMode.GetWindowText(strTemp);

	if (strTemp == "单行扫描")
	{
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST)->ShowWindow(SW_HIDE);
	}
	else if (strTemp == "多行扫描")
	{
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST)->ShowWindow(SW_SHOW);
	}
}


void CDlgLaserStripSWParamRecord::AddGridListSingleParam()
{
	CAdoRecordset recordset;
	if (!recordset.OpenTable("LaserSingleScanParamTable", &m_adoDatabase))
	{
		MessageBox("打开单行扫描参数表失败！");
		return;
	}

	recordset.AddNew();    //增加一行

	CTime time;
	CString strTime = _T("");
	time = CTime::GetCurrentTime();
	strTime = time.Format(_T("%Y/%m/%d-%H/%M/%S"));
	recordset.SetFieldValue(0, strTime);

	CString strTemp = _T("");
	strTemp.Format(_T("%.2f"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramSingleScan.dScanLen);
	recordset.SetFieldValue(1, strTemp);
	strTemp.Format(_T("%.2f"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramSingleScan.dScanSpeed);
	recordset.SetFieldValue(2, strTemp);
	strTemp.Format(_T("%d"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramSingleScan.nScanNum);
	recordset.SetFieldValue(3, strTemp);

	recordset.Update();

	ShowGridListSingleParam(&recordset);
	recordset.CloseTable();
}


void CDlgLaserStripSWParamRecord::AddGridListMultiParam()
{
	CAdoRecordset recordset;
	if (!recordset.OpenTable("LaserMultiScanParamTable", &m_adoDatabase))
	{
		MessageBox("打开多行扫描参数表失败！");
		return;
	}

	recordset.AddNew();    //增加一行

	CTime time;
	CString strTime = _T("");
	time = CTime::GetCurrentTime();
	strTime = time.Format(_T("%Y/%m/%d-%H/%M/%S"));
	recordset.SetFieldValue(0, strTime);

	CString strTemp = _T("");
	strTemp.Format(_T("%.2f"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dScanLen);
	recordset.SetFieldValue(1, strTemp);
	strTemp.Format(_T("%.2f"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dScanSpace);
	recordset.SetFieldValue(2, strTemp);
	strTemp.Format(_T("%.2f"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dScanSpeed);
	recordset.SetFieldValue(3, strTemp);
	strTemp.Format(_T("%.2f"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dTransRowSpeed);
	recordset.SetFieldValue(4, strTemp);
	strTemp.Format(_T("%d"), m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.nScanNum);
	recordset.SetFieldValue(5, strTemp);

	recordset.Update();

	ShowGridListMultiParam(&recordset);
	recordset.CloseTable();
}


void CDlgLaserStripSWParamRecord::OnClickedLaserstripSubPrAddBtn()
{
	if (NULL == m_pDlgLaserStripSubWinMain) return;
	
	ParamScan* pScanParam = NULL;
	pScanParam = m_pDlgLaserStripSubWinMain->GetParamScan();
	if (NULL == pScanParam)	return;
	
	if (pScanParam->scanmode == SingleROW)
	{
		AddGridListSingleParam();
		m_comboboxScanMode.SetCurSel(0);
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST)->ShowWindow(SW_HIDE);
	}
	else if (pScanParam->scanmode == MultiROW)
	{
		AddGridListMultiParam();
		m_comboboxScanMode.SetCurSel(1);
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_SingleParam_LIST)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_LASERSTRIP_SUB_PR_MultiParam_LIST)->ShowWindow(SW_SHOW);
	}	
}


void CDlgLaserStripSWParamRecord::OnBnClickedLaserstripSubPrDeleteBtn()
{
	CString strTemp = _T("");
	m_comboboxScanMode.GetWindowText(strTemp);

	if (strTemp == "单行扫描")
	{
		CAdoRecordset recordset;
		if (!recordset.OpenTable("LaserSingleScanParamTable", &m_adoDatabase))
		{
			MessageBox("打开单行扫描参数表失败！");
			return;
		}

		int nRowIndex = m_gridlistSingleParam.GetFocusCell().row;
		if (nRowIndex > 0)
		{
			recordset.Move(nRowIndex-1);   //列表中第1行对应数据库中第0行
			recordset.Delete();
			recordset.Update();
			ShowGridListSingleParam(&recordset);
		}	
		recordset.CloseTable();
	}
	else if (strTemp == "多行扫描")
	{
		CAdoRecordset recordset;
		if (!recordset.OpenTable("LaserMultiScanParamTable", &m_adoDatabase))
		{
			MessageBox("打开多行扫描参数表失败！");
			return;
		}

		int nRowIndex = m_gridlistMultiParam.GetFocusCell().row;
		if (nRowIndex > 0)
		{
			recordset.Move(nRowIndex-1);   //列表中第1行对应数据库中第0行
			recordset.Delete();
			recordset.Update();
			ShowGridListMultiParam(&recordset);
		}	
		recordset.CloseTable();
	}
}


void CDlgLaserStripSWParamRecord::ApplyGridListSingleParam()
{
	int nColCount = m_gridlistSingleParam.GetColumnCount();
	int nRowIndex = m_gridlistSingleParam.GetFocusCell().row;
	if (nRowIndex <= 0) return;

	m_pDlgLaserStripSubWinMain->GetParamScan()->scanmode = SingleROW;
	CString strItemText = _T("");
	for (int nColIndex=1; nColIndex<nColCount; nColIndex++)
	{
		strItemText = m_gridlistSingleParam.GetItemText(nRowIndex, nColIndex);
		switch(nColIndex)
		{
		case 1:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramSingleScan.dScanLen = _ttof(strItemText);
			break;
		case 2:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramSingleScan.dScanSpeed = _ttof(strItemText);
			break;
		case 3:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramSingleScan.nScanNum = _ttoi(strItemText);
			break;
		default:
			break;
		}
	}

	m_pDlgLaserStripSubWinMain->SetParamInStatic();
}


void CDlgLaserStripSWParamRecord::ApplyGridListMultiParam()
{
	int nColCount = m_gridlistMultiParam.GetColumnCount();
	int nRowIndex = m_gridlistMultiParam.GetFocusCell().row;
	if (nRowIndex <= 0) return;

	m_pDlgLaserStripSubWinMain->GetParamScan()->scanmode = MultiROW;
	CString strItemText = _T("");
	for (int nColIndex=1; nColIndex<nColCount; nColIndex++)
	{
		strItemText = m_gridlistMultiParam.GetItemText(nRowIndex, nColIndex);
		switch(nColIndex)
		{
		case 1:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dScanLen = _ttof(strItemText);
			break;
		case 2:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dScanSpace = _ttof(strItemText);
			break;
		case 3:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dScanSpeed = _ttof(strItemText);
			break;
		case 4:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.dTransRowSpeed = _ttof(strItemText);
			break;
		case 5:
			m_pDlgLaserStripSubWinMain->GetParamScan()->paramMultiScan.nScanNum = _ttoi(strItemText);
			break;
		default:
			break;
		}
	}

	m_pDlgLaserStripSubWinMain->SetParamInStatic();
}


void CDlgLaserStripSWParamRecord::OnBnClickedLaserstripSubPrApplyBtn()
{
	if (NULL == m_pDlgLaserStripSubWinMain) return;

	CString strTemp = _T("");
	m_comboboxScanMode.GetWindowText(strTemp);

	if (strTemp == "单行扫描")
	{
		ApplyGridListSingleParam();
	}
	else if (strTemp == "多行扫描")
	{
		ApplyGridListMultiParam();
	}

	if (NULL != m_pDlgLaserStripSubWinMain->GetDlgLaserStripSWScanPath())
		m_pDlgLaserStripSubWinMain->GetDlgLaserStripSWScanPath()->ApplyScanParamToPathWin(); 
}


