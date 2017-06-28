// Dlg3DMeasureMatch.cpp : 实现文件
//

#include "stdafx.h"
#include "FE-3DMM.h"
#include "Dlg3DMeasureMatch.h"
#include "afxdialogex.h"
#include <gl\gl.h>
#include <gl\glu.h>
#include "gl\GLAux.h"


// CDlg3DMeasureMatch 对话框

IMPLEMENT_DYNAMIC(CDlg3DMeasureMatch, CDialog)

CDlg3DMeasureMatch::CDlg3DMeasureMatch(CProcessCore* pProCore, CWnd* pParent /*=NULL*/)
	: CDialog(CDlg3DMeasureMatch::IDD, pParent)
{
	m_pProCore = pProCore;
	//  m_sec_number = 0;
	m_sec_number = _T("");
	m_acceptance_down = _T("");
	m_minNom = _T("");
	m_acceptance_up = _T("");
	m_mea_down = _T("");
	m_mea_up = _T("");
	m_mea_dow = _T("");
	m_error_given = _T("");
	m_pass_whether = _T("");
	//  m_rate_actual = _T("");
	m_rate_given = _T("");
	m_rate_actual = 0.0;
}

CDlg3DMeasureMatch::~CDlg3DMeasureMatch()
{
	Release();
}

void CDlg3DMeasureMatch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_3DMEASURE_M_GB1_GROUP, m_GB1);
	DDX_Control(pDX, IDC_3DMEASURE_M_GB2_GROUP, m_GB2);
	DDX_Control(pDX, IDC_3DMEASURE_M_BLENDTIME, m_MatchTimes);
	DDX_Control(pDX, IDC_3DMEASURE_M_BLENDMU, m_AdfMu);
	DDX_Text(pDX, IDC_3DMEASURE_M_DECEMAL, m_sec_number);
	DDX_Text(pDX, IDC_3DMEASURE_M_NMIN, m_acceptance_down);
	DDX_Text(pDX, IDC_3DMEASURE_M_BLENDTIME, m_minNom);
	DDX_Text(pDX, IDC_3DMEASURE_M_NMAX, m_acceptance_up);
	DDX_Text(pDX, IDC_3DMEASURE_M_MMAX, m_mea_up);
	DDX_Text(pDX, IDC_3DMEASURE_M_MMIN, m_mea_dow);
	DDX_Text(pDX, IDC_3DMEASURE_M_ERRORGIVEN, m_error_given);
	DDX_Text(pDX, IDC_3DMEASURE_M_IFPASS, m_pass_whether);
	DDX_Text(pDX, IDC_3DMEASURE_M_ERRORPERCENTGIVEN, m_rate_given);
	DDX_Text(pDX, IDC_3DMEASURE_M_ERRORPERCENTACTUAL, m_rate_actual);
}

BEGIN_MESSAGE_MAP(CDlg3DMeasureMatch, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_3DMEASURE_M_Open_Test, &CDlg3DMeasureMatch::OnBnClicked3dmeasureMOpenTest)
	ON_BN_CLICKED(IDC_3DMEASURE_M_Open_Ref, &CDlg3DMeasureMatch::OnBnClicked3dmeasureMOpenRef)
	ON_BN_CLICKED(IDC_3DMEASURE_M_BLEND, &CDlg3DMeasureMatch::OnBnClicked3dmeasureMBlend)
	ON_EN_CHANGE(IDC_3DMEASURE_M_BLENDTIME, &CDlg3DMeasureMatch::OnEnChange3dmeasureMBlendtime)
	ON_EN_CHANGE(IDC_3DMEASURE_M_BLENDMU, &CDlg3DMeasureMatch::OnEnChange3dmeasureMBlendmu)
	ON_BN_CLICKED(IDC_3DMEASURE_M_ONCHROM, &CDlg3DMeasureMatch::OnBnClicked3dmeasureMOnchrom)
	ON_BN_CLICKED(IDC_3DMEASURE_M_OFFCHROM, &CDlg3DMeasureMatch::OnBnClicked3dmeasureMOffchrom)
	
	ON_EN_CHANGE(IDC_3DMEASURE_M_DECEMAL, &CDlg3DMeasureMatch::OnEnChangenumber)
	ON_EN_CHANGE(IDC_3DMEASURE_M_NMIN, &CDlg3DMeasureMatch::OnEnChangedown)
	ON_EN_CHANGE(IDC_3DMEASURE_M_NMAX, &CDlg3DMeasureMatch::OnEnChangeup)
	ON_EN_CHANGE(IDC_3DMEASURE_M_MMAX, &CDlg3DMeasureMatch::OnEnChangeupon)
	ON_EN_CHANGE(IDC_3DMEASURE_M_MMIN, &CDlg3DMeasureMatch::OnEnChangedow)
	ON_EN_CHANGE(IDC_3DMEASURE_M_ERRORGIVEN, &CDlg3DMeasureMatch::OnEnChangegiven)
	ON_EN_CHANGE(IDC_3DMEASURE_M_ERRORPERCENTACTUAL, &CDlg3DMeasureMatch::OnEnChangeactual)
	ON_EN_CHANGE(IDC_3DMEASURE_M_ERRORPERCENTGIVEN, &CDlg3DMeasureMatch::OnEnChangegivenpercent)
	ON_EN_CHANGE(IDC_3DMEASURE_M_IFPASS, &CDlg3DMeasureMatch::OnEnChangewhether)
	ON_BN_CLICKED(IDC_3DMEASURE_M_CONFIRM, &CDlg3DMeasureMatch::OnBnClickedConfirm)
END_MESSAGE_MAP()


// CDlg3DMeasureMatch 消息处理程序
void CDlg3DMeasureMatch::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}


void CDlg3DMeasureMatch::OnCancel()
{
	DestroyWindow();
}


void CDlg3DMeasureMatch::Cancel()
{
	OnCancel();
}


void CDlg3DMeasureMatch::Release()
{

}


BOOL CDlg3DMeasureMatch::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

BOOL CDlg3DMeasureMatch::OnInitDialog()
{
	CDialog::OnInitDialog();

	/////////显示自己定义的View类//////////////
	CWnd *pWnd = GetDlgItem(IDC_3DMEASURE_M_PicShow_STATIC);//获得需要显示的区域
	CRect rectView;
	pWnd->GetWindowRect(rectView);
	pWnd->DestroyWindow();//将原有的控件销毁
	ScreenToClient(rectView);
	//创建、显示视图窗口
	m_viewOpenGL = (COpenGLView *)RUNTIME_CLASS(COpenGLView)->CreateObject();
	m_viewOpenGL->Create(NULL, NULL, WS_BORDER , rectView, this, IDC_3DMEASURE_M_PicShow_STATIC);
	m_viewOpenGL->ShowWindow(SW_SHOW);

	return TRUE;  
}


void CDlg3DMeasureMatch::OnBnClicked3dmeasureMOpenTest()
{
	// TODO: 在此添加控件通知处理程序代码
	CString lpszFilter( "Txt Files(*.txt , *TXT)|*.txt|STL Files(*.stl,*.STL)|*.stl||" ); //软件自身格式的文件 lpszFilter参数设置选择文件类型
	CFileDialog dlg(true,CString(".txt"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, lpszFilter,NULL);// 父窗口
	if (dlg.DoModal() != IDOK)
	{return;}
	string err_Str;
	if( m_PtOperator.Read( dlg.GetPathName(), err_Str,m_SetPtTest ) )
	{
		//AfxMessageBox( CString("数据(txt)读取成功!") );
	}
	else
		AfxMessageBox( CString("无法读取数据")+CString(err_Str.c_str()) );
	m_SetPtTest.swap(m_viewOpenGL->RefTowOpt().m_TowSet);
	m_viewOpenGL->RefTowOpt().CalTowCenPt();
	m_viewOpenGL->is_tow = TRUE;
	m_viewOpenGL->UpdatePCloud(true);
}

void CDlg3DMeasureMatch::OnBnClicked3dmeasureMOpenRef()
{
	// TODO: 在此添加控件通知处理程序代码
	m_viewOpenGL->RefTowOpt().ReadStl();
	m_viewOpenGL->is_tow = FALSE;

	vector<CMesh>::iterator iter;
	
	for (iter = m_viewOpenGL->RefTowOpt().in_TriSet.begin(); iter != m_viewOpenGL->RefTowOpt().in_TriSet.end(); ++iter)
	{
		pt.x() = (iter->m_pt1.x() + iter->m_pt2.x() + iter->m_pt3.x())/3;
		pt.y() = (iter->m_pt1.y() + iter->m_pt2.y() + iter->m_pt3.y())/3;
		pt.z() = (iter->m_pt1.z() + iter->m_pt2.z() + iter->m_pt3.z())/3;
		pt.ux() = iter->m_nor.ux();
		pt.uy() = iter->m_nor.uy();
		pt.uz() = iter->m_nor.uz();
        m_viewOpenGL->RefTowOpt().m_StdSet.push_back(pt);
	}

	m_viewOpenGL->UpdatePCloud(false);
}
//匹配
void CDlg3DMeasureMatch::OnBnClicked3dmeasureMBlend()
{
	m_ptMoving.clear();//先清空
	//设置iter这个
	vector<CDS3DPt>::iterator iter;
    for (iter = m_viewOpenGL->RefTowOpt().m_TowSet.begin(); iter != m_viewOpenGL->RefTowOpt().m_TowSet.end(); ++iter)
	{
		pt.x() = iter->x();//	CDS3DPtNor pt;   CDS3DPt pt1;在该.H文件中定义
		pt.y() = iter->y();
		pt.z() = iter->z();
		pt.ux() = 0;
		pt.uy() = 0;
		pt.uz() = 0;
		m_ptMoving.push_back(pt);
	}
	m_ptFixed = m_viewOpenGL->RefTowOpt().m_StdSet;//此时FIXED是标准模型文件？

	CHandleTDM HandleTDM(m_ptMoving, m_ptFixed);//特殊的类，用这两个点云来构造这个对象

	for(int i = 0;i < 4; i++)//对该对象的矩阵操作
	{
		for(int j = 0;j < 4;j++)
		{
			if(i == j)
			{
				HandleTDM.m_blendMatrix[i][j]=1.0f;
			}
			else
			{
				HandleTDM.m_blendMatrix[i][j]=0.0f;
			}
		}
	}

	HandleTDM.SetIterTimes(m_nIterTimes);//匹配次数
	CDSChrom res_Errtemp;//色谱
	HandleTDM.Blend(res_Errtemp);

	CString str;
	str.Format("%f",HandleTDM.m_blendMatrix[0][0]);
	SetDlgItemText(IDC_3DMEASURE_M_R1X,str);
	str.Format("%f",HandleTDM.m_blendMatrix[0][1]);
	SetDlgItemText(IDC_3DMEASURE_M_R1Y,str);
	str.Format("%f",HandleTDM.m_blendMatrix[0][2]);
	SetDlgItemText(IDC_3DMEASURE_M_R1Z,str);
	str.Format("%f",HandleTDM.m_blendMatrix[1][0]);
	SetDlgItemText(IDC_3DMEASURE_M_R2X,str);
	str.Format("%f",HandleTDM.m_blendMatrix[1][1]);
	SetDlgItemText(IDC_3DMEASURE_M_R2Y,str);
	str.Format("%f",HandleTDM.m_blendMatrix[1][2]);
	SetDlgItemText(IDC_3DMEASURE_M_R2Z,str);
	str.Format("%f",HandleTDM.m_blendMatrix[2][0]);
	SetDlgItemText(IDC_3DMEASURE_M_R3X,str);
	str.Format("%f",HandleTDM.m_blendMatrix[2][1]);
	SetDlgItemText(IDC_3DMEASURE_M_R3Y,str);
	str.Format("%f",HandleTDM.m_blendMatrix[2][2]);
	SetDlgItemText(IDC_3DMEASURE_M_R3Z,str);
	str.Format("%f",HandleTDM.m_blendMatrix[0][3]);
	SetDlgItemText(IDC_3DMEASURE_M_TX,str);
	str.Format("%f",HandleTDM.m_blendMatrix[1][3]);
	SetDlgItemText(IDC_3DMEASURE_M_TY,str);
	str.Format("%f",HandleTDM.m_blendMatrix[2][3]);
	SetDlgItemText(IDC_3DMEASURE_M_TZ,str);

	m_ptMoving = HandleTDM.GetMpt();
	vector<CDS3DPtNor>::iterator iter1;
	m_viewOpenGL->RefTowOpt().m_TowSet.clear();


	for (iter1 = m_ptMoving.begin(); iter1 != m_ptMoving.end(); ++iter1)
	{
		pt1.x() = iter1->x();
		pt1.y() = iter1->y();
		pt1.z() = iter1->z();

		m_viewOpenGL->RefTowOpt().m_TowSet.push_back(pt1);
	}
	
	m_viewOpenGL->RefTowOpt().CalTowCenPt();
	m_viewOpenGL->is_tow = TRUE;
	m_viewOpenGL->UpdatePCloud(true);
	
	
	//vector<float> mtDist;
	CHandleTDM HandleADFChrom(m_ptMoving, m_ptFixed);//也是构造对象
	HandleADFChrom.CalDist(mtDist);              //此处ADF

	vector<CDS3DPtNor>::iterator iter2;//遍历moving来赋值
	//迭代器，迭代程序
	vector<float>:: iterator iterDist = mtDist.begin();
	for (iter2 = m_ptMoving.begin();iter2 != m_ptMoving.end(); ++iter2, ++iterDist)
	{
		CDS3DPtColor ptColor;
		ptColor = CDS3DPtColor(*iter2);
		ptColor.r = 0; ptColor.g = 0; ptColor.b = 0;
		ptColor.m_distErr = *iterDist;
		m_viewOpenGL->newPtChrom.m_ptColor.push_back(ptColor);
	}	
	m_viewOpenGL->newPtChrom.CalChromColor();//计算色谱颜色
	m_viewOpenGL->newPtChrom.InitCenter();//

	Invalidate(FALSE);
}

//匹配次数
void CDlg3DMeasureMatch::OnEnChange3dmeasureMBlendtime()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString perc;
	int temp;
	m_MatchTimes.GetWindowText(perc);//m_sliderUniSamPerc.SetPos(temp_percrate);
	temp = atoi(perc);
	m_nIterTimes = temp;//	m_MatchTimeSlider.SetPos((int)temp);
	UpdateData(TRUE); 
}

//MU值
void CDlg3DMeasureMatch::OnEnChange3dmeasureMBlendmu()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString temp;
	m_AdfMu.GetWindowText(temp);
	m_Mu = atof(temp);
}

//色谱
void CDlg3DMeasureMatch::OnBnClicked3dmeasureMOnchrom()
{
	// TODO: 在此添加控件通知处理程序代码
	m_viewOpenGL->SetShowErrSym(TRUE);
	m_viewOpenGL->SetShowStdSym(FALSE);
	m_viewOpenGL->SetShowTowSym(FALSE);
	m_viewOpenGL->SetShowStlSy(FALSE);
	m_viewOpenGL->is_CalcChrom = TRUE;
	Invalidate(FALSE);
}


void CDlg3DMeasureMatch::OnBnClicked3dmeasureMOffchrom()
{
	// TODO: 在此添加控件通知处理程序代码
	m_viewOpenGL->SetShowErrSym(false);
	m_viewOpenGL->SetShowStdSym(true);
	m_viewOpenGL->SetShowTowSym(true);
	m_viewOpenGL->SetShowStlSy(true);
	Invalidate(FALSE);
}




//控制色谱的段数,均使用value的Cstring变量，再变为int
void CDlg3DMeasureMatch::OnEnChangenumber()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);   
    CString   buf   =   m_sec_number;  
	//CString buf;//为输入的字符串

	int temp;

	temp = atoi(buf);
	m_viewOpenGL->m_nCol = temp;
	
	//COpenGLView
}
//合格值上限,应为double类型
void CDlg3DMeasureMatch::OnEnChangedown()
{

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);   
    CString   buf   =   m_acceptance_down;  
	//CString buf;//为输入的字符串

	double temp;

	temp = atof(buf);
	m_viewOpenGL->m_minNom = temp;
}
//合格值下限
void CDlg3DMeasureMatch::OnEnChangeup()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);   
    CString   buf   =   m_acceptance_up;  
	//CString buf;//为输入的字符串

	double temp;

	 temp= atof(buf);
	m_viewOpenGL->m_maxNom = temp;
}
//上限范围
void CDlg3DMeasureMatch::OnEnChangeupon()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);   
    CString   buf   =   m_mea_up;  
	//CString buf;//为输入的字符串

	double temp;

	temp = atof(buf);
	m_viewOpenGL->m_maxCri = temp;
}
//下限范围
void CDlg3DMeasureMatch::OnEnChangedow()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
		UpdateData(TRUE);   
    CString   buf   =   m_mea_dow;  
	//CString buf;//为输入的字符串

	double temp;

	temp = atof(buf);
	m_viewOpenGL->m_minCri = temp;
}

//给定的误差，以下函数的变量均在MATCH.h文件中定义
void CDlg3DMeasureMatch::OnEnChangegiven()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);   
    CString   buf   =   m_error_given;  //等号后面是设定的VALUE值，CSTRING类型
	//CString buf;//为输入的字符串

	double temp;

	temp = atof(buf);//剩下的就是给定的误差怎么处理的问题
	given_error = temp;
}

//由误差得出的百分比，行使的是输出显示功能
void CDlg3DMeasureMatch::OnEnChangeactual()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	 
    // str.Format("%s\n",context);  
    // str.Format("%d",fplength);  //此处format是转化为字符串并无意义

     //定义的double类型数据变量m_rate_actual已经在确认按钮处计算完毕，应该直接显示就可以了
  
     //更新显示  m_rate_actual的内容
}

//给定的预期百分比，读取功能
void CDlg3DMeasureMatch::OnEnChangegivenpercent()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);   
    CString   buf   =   m_rate_given;  //等号后面是设定的VALUE值，CSTRING类型
	//CString buf;//为输入的字符串

	double temp;

	temp = atof(buf);//剩下的就是给定的误差怎么处理的问题
	rate_given_1 = temp;
}

//显示达标与否
void CDlg3DMeasureMatch::OnEnChangewhether()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	/*if(pass_whether_f==true)
	{
		m_pass_whether="合格";
	}
	else
	{
		m_pass_whether="不合格";
	}
	UpdateData(FALSE);
	*/
}

//button确认，进行百分比匹配的运算，计算在该误差范围下应该有多少百分比。
void CDlg3DMeasureMatch::OnBnClickedConfirm()
{
	// TODO: 在此添加控件通知处理程序代码
	vector<CDS3DPtNor>::iterator iter3;
	vector<float>:: iterator iterDist1 = mtDist.begin();
	long int num=0; //合格数
	long int sum=0;//总数
	for (iter3 = m_ptMoving.begin();iter3 != m_ptMoving.end(); ++iter3, ++iterDist1)
	{
		if(*iterDist1>=0)
		{
			if(*iterDist1 <= given_error)
			{  
				num=num+1;sum=sum+1;
			}
			else
			{
				sum=sum+1;
			}
		}
		else
		{
			if(*iterDist1 >= -1*given_error)
			{  
				num=num+1;sum=sum+1;
			}
			else
			{
				sum=sum+1;
			}
		}

			
	}	
	m_rate_actual=(double)num/(double)sum*100.0;//实际的是合格百分比
	CString str;
	str.Format("%f",m_rate_actual);
	SetDlgItemText(IDC_3DMEASURE_M_ERRORPERCENTACTUAL,str);
	//GetDlgItem(rate_actual)->SetWindowText(m_rate_actual);
	//比较两个百分比，确定是否合格
	if(m_rate_actual>=rate_given_1)
	{
		pass_whether_f=true;//合格
	}
	else
	{
		pass_whether_f=false;
	}
	//编辑框显示文字不用在那个编辑框中

	if(pass_whether_f==true)
	{
		GetDlgItem(IDC_3DMEASURE_M_IFPASS)->SetWindowText("OK!");
	}
	else
	{
		GetDlgItem(IDC_3DMEASURE_M_IFPASS)->SetWindowText("NO!");
	}
	
}
