// DlgPrintParamData.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "DlgPrintParamDataRecord.h"
#include "afxdialogex.h"
#include "DlgPrintParamAdjust.h"


// CDlgPrintParamDataRecord 对话框

IMPLEMENT_DYNAMIC(CDlgPrintParamDataRecord, CDialog)

CDlgPrintParamDataRecord::CDlgPrintParamDataRecord(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrintParamDataRecord::IDD, pParent)
{
	m_pDlgParamMain = (CDlgPrintParamAdjust*)pParent;
	m_strDatabasePath = _T("");
}

CDlgPrintParamDataRecord::~CDlgPrintParamDataRecord()
{
	Release();
}

void CDlgPrintParamDataRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPrintParamDataRecord, CDialog)
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_PRINT_PA_DATA_Apply_BTN, &CDlgPrintParamDataRecord::OnBnClickedPrintPaDataApplyBtn)
	ON_BN_CLICKED(IDC_PRINT_PA_DATA_Add_BTN, &CDlgPrintParamDataRecord::OnBnClickedPrintPaDataAddBtn)
	ON_BN_CLICKED(IDC_PRINT_PA_DATA_Modify_BTN, &CDlgPrintParamDataRecord::OnBnClickedPrintPaDataModifyBtn)
	ON_BN_CLICKED(IDC_PRINT_PA_DATA_Delete_BTN, &CDlgPrintParamDataRecord::OnBnClickedPrintPaDataDeleteBtn)
END_MESSAGE_MAP()


// CDlgPrintParamDataRecord 消息处理程序


void CDlgPrintParamDataRecord::OnCancel()
{
	DestroyWindow();
}


void CDlgPrintParamDataRecord::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlgPrintParamDataRecord::Cancel()
{
	OnCancel();
}


void CDlgPrintParamDataRecord::Release()
{

}


HBRUSH CDlgPrintParamDataRecord::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CDlgPrintParamDataRecord::OnEraseBkgnd(CDC* pDC)
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


BOOL CDlgPrintParamDataRecord::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlgCtrl();
	InitGridListData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDlgPrintParamDataRecord::InitDlgCtrl()
{
	m_bmpBtn[0].SubclassDlgItem(IDC_PRINT_PA_DATA_Apply_BTN, this);
	m_bmpBtn[0].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[0].SetFont(15);
	m_bmpBtn[0].SetTitle("应用");

	m_bmpBtn[1].SubclassDlgItem(IDC_PRINT_PA_DATA_Add_BTN, this);
	m_bmpBtn[1].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[1].SetFont(15);
	m_bmpBtn[1].SetTitle("增加");

	m_bmpBtn[2].SubclassDlgItem(IDC_PRINT_PA_DATA_Modify_BTN, this);
	m_bmpBtn[2].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[2].SetFont(15);
	m_bmpBtn[2].SetTitle("修改");

	m_bmpBtn[3].SubclassDlgItem(IDC_PRINT_PA_DATA_Delete_BTN, this);
	m_bmpBtn[3].LoadBitmaps(IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK,IDB_BITMAP_BTN,IDB_BITMAP_BTNCLK);
	m_bmpBtn[3].SetFont(15);
	m_bmpBtn[3].SetTitle("删除");
}


void CDlgPrintParamDataRecord::OnClose()
{
	if (NULL != m_pDlgParamMain)
	{
		m_pDlgParamMain->OnBnClickedPrintPaDataRecordBtn();
	}	
}


void CDlgPrintParamDataRecord::InitGridListData()
{
	m_strDatabasePath =  m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1) + _T("Storage\\Database.mdb");
	if (!m_adoDatabase.OpenMDB(m_strDatabasePath))
	{
		MessageBox("连接数据库失败！");
		return;
	}

	CAdoRecordset recordset;
	if (!recordset.OpenTable("PrintParamTable", &m_adoDatabase))
	{
		MessageBox("打开参数数据表失败！");
		return;
	}

	CRect rcGrid;
	GetDlgItem(IDC_PRINT_PA_DATA_LIST)->GetClientRect(&rcGrid);
	m_gridlistData.Create(rcGrid, GetDlgItem(IDC_PRINT_PA_DATA_LIST), IDC_PRINT_PA_DATA_LIST);

	//初始化列表各项
	int nFixedColum = 1;
	int nFixedRow = 1;
	int nRowCount = 1;
	int nColumCount = recordset.GetFieldCount();

	m_gridlistData.SetAutoSizeStyle();
	m_gridlistData.SetEditable(TRUE);
	m_gridlistData.SetFixedColumnSelection(FALSE);
	m_gridlistData.ExpandColumnsToFit(TRUE);

	m_gridlistData.SetRowCount(nRowCount);
	m_gridlistData.SetColumnCount(nColumCount);
	m_gridlistData.SetFixedColumnCount(nFixedColum);
	m_gridlistData.SetFixedRowCount(nFixedRow);

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
		m_gridlistData.SetItem(&item);

		if (0 == iColIndex)
			m_gridlistData.SetColumnWidth(iColIndex, 132);
		else
			m_gridlistData.SetColumnWidth(iColIndex, 80);	
	}

	ShowGridListData(&recordset);

	recordset.CloseTable();
}


void CDlgPrintParamDataRecord::ShowGridListData(CAdoRecordset* pRecordSet)
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
	m_gridlistData.DeleteNonFixedRows();

	int row = 1;
	GV_ITEM item;
	item.crBkClr = RGB(255, 255, 255);
	item.nFormat = DT_CENTER|DT_VCENTER;
	item.mask = GVIF_TEXT|GVIF_BKCLR|GVIF_FORMAT|GVIF_STATE;

	CString strValue = "";
	int iColCount = pRecordSet->GetFieldCount();
	while (!pRecordSet->IsEOF())
	{
		m_gridlistData.InsertRow(NULL); //在末尾插入一行

		for (int iColIndex=0; iColIndex<iColCount; iColIndex++)
		{
			if (row%2 == 0)
			{
				item.crBkClr = RGB(255, 255, 255);
			}
			else
			{
				item.crBkClr = RGB(210, 210, 210);
			}

			if (iColIndex==1 || iColIndex==2)
			{
				item.nState = GVIS_MODIFIED;
			}
			else
			{
				item.nState = GVIS_READONLY;
			}

			item.row = row;
			item.col = iColIndex;
			strValue = pRecordSet->GetFieldValue(iColIndex);
			item.strText = strValue;
			m_gridlistData.SetItem(&item);
		}	

		++row;
		pRecordSet->MoveNext();
	}

	m_gridlistData.UpdateData(FALSE);
	m_gridlistData.Refresh();
}


void CDlgPrintParamDataRecord::OnBnClickedPrintPaDataApplyBtn()
{
	int nRowIndex = m_gridlistData.GetFocusCell().row;
	int nColCount = m_gridlistData.GetColumnCount();

	if (nRowIndex <= 0) return;

	CString strItemText = _T("");
	for (int nColIndex=3; nColIndex<nColCount; nColIndex++)
	{
		strItemText = m_gridlistData.GetItemText(nRowIndex, nColIndex);
		switch(nColIndex)
		{
		case 3: //电压模式
			if (strItemText == _T("方波"))
			{
				m_PrintParamTable.enumVolMode = AcMode;
			}
			else if (strItemText == _T("直流"))
			{
				m_PrintParamTable.enumVolMode = DcMode;
			}
			break;

		case 4: //直流偏置
			m_PrintParamTable.dDcOffset = _ttof(strItemText);
			break;

		case 5: //交流偏置
			m_PrintParamTable.dAcOffset = _ttof(strItemText);
			break;
			
		case 6: //交流频率
			m_PrintParamTable.dAcFreq = _ttof(strItemText);
			break;
			
		case 7: //交流幅值
			m_PrintParamTable.dAcAmplitude = _ttof(strItemText);
			break;
	
		case 8: //交流占空比
			m_PrintParamTable.dAcRatio = _ttof(strItemText);
			break;
	
		case 9: //辅助气压值
			m_PrintParamTable.dAuxiAirPress = _ttof(strItemText);
			break;
	
		case 10: //流量调节方式
			if (strItemText == _T("流量泵"))
			{
				m_PrintParamTable.enumFlowAdjPattern = PumpPattern;
			}
			else if (strItemText == _T("进给气压"))
			{
				m_PrintParamTable.enumFlowAdjPattern = FeedAirPressPattern;
			}
			break;

		case 11: //流量泵流量
			m_PrintParamTable.dPumpFlowRate = _ttof(strItemText);
			break;

		case 12: //进给气压流量
			m_PrintParamTable.dFeedAirFlowRate = _ttof(strItemText);
			break;

		default:
			break;
		}
	}

	if (NULL != m_pDlgParamMain)
	{
		m_pDlgParamMain->ApplyPrintParamTable();
		m_pDlgParamMain->UpdateData(FALSE);
	}	
}


void CDlgPrintParamDataRecord::OnBnClickedPrintPaDataAddBtn()
{
	if (NULL == m_pDlgParamMain) return;

	m_pDlgParamMain->AddPrintParamTable();   //添加打印参数

	CAdoRecordset recordset;
	if (!recordset.OpenTable("PrintParamTable", &m_adoDatabase))
	{
		MessageBox("打开参数数据表失败！");
		return;
	}

	recordset.AddNew();    //增加一行

	CTime time;
	CString strTime = _T("");
	time = CTime::GetCurrentTime();
	strTime = time.Format(_T("%Y/%m/%d-%H/%M/%S"));

	recordset.SetFieldValue(0, strTime);
	recordset.SetFieldValue(1, "");
	recordset.SetFieldValue(2, "");
	CString strTemp = _T("");
	if (m_PrintParamTable.enumVolMode == AcMode)
	{
		strTemp = _T("方波");
		recordset.SetFieldValue(3, strTemp);
		recordset.SetFieldValue(4, "");
		strTemp.Format(_T("%.2f"), m_PrintParamTable.dAcOffset);
		recordset.SetFieldValue(5, strTemp);
		strTemp.Format(_T("%.2f"), m_PrintParamTable.dAcFreq);
		recordset.SetFieldValue(6, strTemp);
		strTemp.Format(_T("%.2f"), m_PrintParamTable.dAcAmplitude);
		recordset.SetFieldValue(7, strTemp);
		strTemp.Format(_T("%.2f"), m_PrintParamTable.dAcRatio);
		recordset.SetFieldValue(8, strTemp);	
	}
	if (m_PrintParamTable.enumVolMode == DcMode)
	{
		strTemp = _T("直流");
		recordset.SetFieldValue(3, strTemp);
		strTemp.Format(_T("%.2f"), m_PrintParamTable.dDcOffset);
		recordset.SetFieldValue(4, strTemp);
		recordset.SetFieldValue(5, "");
		recordset.SetFieldValue(6, "");
		recordset.SetFieldValue(7, "");
		recordset.SetFieldValue(8, "");	
	}
	
	strTemp.Format(_T("%.2f"), m_PrintParamTable.dAuxiAirPress);
	recordset.SetFieldValue(9, strTemp);

	if (m_PrintParamTable.enumFlowAdjPattern == PumpPattern)
	{
		strTemp = _T("流量泵");
		recordset.SetFieldValue(10, strTemp);
		strTemp.Format(_T("%.4f"), m_PrintParamTable.dPumpFlowRate);
		recordset.SetFieldValue(11, strTemp);
		recordset.SetFieldValue(12, "");
	}
	else if (m_PrintParamTable.enumFlowAdjPattern == FeedAirPressPattern)
	{
		strTemp = _T("进给气压");
		recordset.SetFieldValue(10, strTemp);	
		recordset.SetFieldValue(11, "");
		strTemp.Format(_T("%.4f"), m_PrintParamTable.dFeedAirFlowRate);
		recordset.SetFieldValue(12, strTemp);
	}
	
	recordset.Update();

	ShowGridListData(&recordset);
	recordset.CloseTable();
}


void CDlgPrintParamDataRecord::OnBnClickedPrintPaDataModifyBtn()
{
	CAdoRecordset recordset;
	if (!recordset.OpenTable("PrintParamTable", &m_adoDatabase))
	{
		MessageBox("打开参数数据表失败！");
		return;
	}

	int nRowIndex = m_gridlistData.GetFocusCell().row;
	int nColCount = m_gridlistData.GetColumnCount();

	if (nRowIndex>0)
	{
		recordset.Move(nRowIndex-1);     //列表中第1行对应数据库中第0行
		CString strItemText = _T("");
		for (int j=0; j<nColCount; j++)
		{
			strItemText = m_gridlistData.GetItemText(nRowIndex, j);
			recordset.SetFieldValue(j, strItemText);
			recordset.Update();
		}
		ShowGridListData(&recordset);
	}
	recordset.CloseTable();
}


void CDlgPrintParamDataRecord::OnBnClickedPrintPaDataDeleteBtn()
{
	CAdoRecordset recordset;
	if (!recordset.OpenTable("PrintParamTable", &m_adoDatabase))
	{
		MessageBox("打开参数数据表失败！");
		return;
	}

	int nRowIndex = m_gridlistData.GetFocusCell().row;
	if (nRowIndex > 0)
	{
		recordset.Move(nRowIndex-1);   //列表中第1行对应数据库中第0行
		recordset.Delete();
		recordset.Update();
		ShowGridListData(&recordset);
	}	
	recordset.CloseTable();
}


BOOL CDlgPrintParamDataRecord::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (WM_KEYDOWN == pMsg->message && VK_RETURN == pMsg->wParam)
	{
		return TRUE;
	}

	return CDialog::PreTranslateMessage(pMsg);
}
