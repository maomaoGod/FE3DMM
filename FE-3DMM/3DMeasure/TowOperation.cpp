#include "stdafx.h"
#include "math.h"
#include "TowOperation.h"
#include "TowSimp.h"
#include "TowBlend.h"
#include <fstream>
#include "../gl/GLUT.H"

CTowMea CTowOpt::m_TowMea;
TDSVec3DPt CTowOpt::m_TowSet;
TDSVec3DPtNor CTowOpt::m_StdSet;
bool CTowOpt::m_IsStd(false);
bool CTowOpt::m_IsNor(false);
CTowMea CTowOpt::m_StdMea;
bool CTowOpt::m_IsMea(false);
TDSVecFace CTowOpt::in_TriSet;
//CArray<STLVector,STLVector> CTowOpt::VertexArray;//静态变量除了定义以外还需要在CPP文件下声明

CDS3DPt CTowOpt::m_StdCenPt(0.0,0.0,0.0);
CDS3DPt CTowOpt::m_StdMaxPt(0.0,0.0,0.0);
CDS3DPt CTowOpt::m_StdMinPt(0.0,0.0,0.0);

CDS3DPt CTowOpt::m_TowCenPt(0.0,0.0,0.0);
CDS3DPt CTowOpt::m_TowMaxPt(0.0,0.0,0.0);
CDS3DPt CTowOpt::m_TowMinPt(0.0,0.0,0.0);

CDS3DPt CTowOpt::m_StlCenPt(0.0,0.0,0.0);
CDS3DPt CTowOpt::m_StlMaxPt(0.0,0.0,0.0);
CDS3DPt CTowOpt::m_StlMinPt(0.0,0.0,0.0);
CDSChrom CTowOpt::m_ErrChrom;

void CTowOpt::SetMea( const TDSVec23DPt& mea_PSet )
{
	m_TowMea.SetPSet( mea_PSet );
	m_TowMea.GetBox( m_TowCenPt, m_TowMinPt, m_TowMaxPt ); //获取中心点
}

void CTowOpt::GetTowCenPt( double cen_Pt[3] ) 
{ 
	for( int i=0;i<3;++i ) 
		cen_Pt[i]=m_TowCenPt.xyz(i); 
}

bool CTowOpt::GetTowBox( double box_Vec[3] )
{
	double sum_sq=0.0;
	for( int i=0;i<3;++i ) 
	{
		box_Vec[i]=m_TowMaxPt.xyz(i)-m_TowMinPt.xyz(i); //分别求的xyz的最大值减去最小值的值
		sum_sq+=box_Vec[i]*box_Vec[i];//各个差值的平方相加得到立方体的体积
	}

	if(sum_sq>1.0e-8)
		return true;
	else
	{
		for( int i=0;i<3;++i ) 
			box_Vec[i]=1.0; 

		return false;
	}
}

void CTowOpt::ReadMea()
{
	CString lpszFilter( "Txt Files(*.txt , *TXT)|*.txt|STL Files(*.stl,*.STL)|*.stl||" ); //软件自身格式的文件 lpszFilter参数设置选择文件类型
	CFileDialog dlg(true,// Open TRUE为打开文件对话框；FALSE为保存文件对话框
		CString(".txt"),// 如果值为null，则为缺省扩展名
		NULL,// 缺省文件名
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, // 选项 对话框风格，一般为OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 即隐藏只读选项和覆盖已有文件前提示。
		lpszFilter,// 文件过滤器/*lpszFilter：文件筛选类型，它指明可供选择的文件类型和相应的扩展名。参数格式如：
//"Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|All Files (*.*)|*.*||";文件类型说明和扩展名间用 | 分隔，
//同种类型文件的扩展名间可以用 ; 分割，每种文件类型间用 | 分隔，末尾用 || 指明。*/
		NULL);// 父窗口

	if (dlg.DoModal() != IDOK)//弹出对话框并点击OK键.点击了打开确定操作
	{
		return;
	}
	string err_Str;
	if( m_TowMea.Read( dlg.GetPathName(), err_Str ) )
	{
		m_TowMea.GetBox( m_TowCenPt, m_TowMinPt, m_TowMaxPt );
		//AfxMessageBox( CString("数据(TOW)读取成功!") );
	}
	else
		AfxMessageBox( CString("无法读取数据")+CString(err_Str.c_str()) );
}

void CTowOpt::ReadMea( const CString& mea_File )
{
	string err_Str;
	if( m_TowMea.Read( mea_File, err_Str ) )
	{
		m_TowMea.GetBox( m_TowCenPt, m_TowMinPt, m_TowMaxPt );
		//AfxMessageBox( CString("铜网测量数据(TOW)读取成功!") );
	}
	else
		AfxMessageBox( CString("无法读取铜网测量数据")+CString(err_Str.c_str()) );
}

void CTowOpt::WriteMea()
{
	CString lpszFilter( "Tow Files(*.tow , *TOW)|*.tow||" ); //软件自身格式的文件
	CFileDialog dlg(false,CString(".tow"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);

	if ( dlg.DoModal() != IDOK )
	{
		return;
	}

	CString mea_File( dlg.GetPathName() );
	if( m_TowMea.Write( mea_File ) )
		AfxMessageBox( mea_File+CString(": 测量数据输出成功!") );
	else
        AfxMessageBox( mea_File+CString("无法输出测量数据!") );
}

void CTowOpt::WriteMea( const CString& mea_File )
{
	if( m_TowMea.Write( mea_File ) ) ;
		//AfxMessageBox( mea_File+CString(": 测量数据输出成功!") );
	else
        AfxMessageBox( mea_File+CString("无法输出测量数据!") );
}

void CTowOpt::GetStdCenPt( double cen_Pt[3] ) 
{ 
	for( int i=0;i<3;++i ) 
		cen_Pt[i]=m_StdCenPt.xyz(i); 
}
void CTowOpt::GetStlCenPt(double cen_Pt[3])
{
    for(int i=0;i<3;++i)
		cen_Pt[i]=m_StlCenPt.xyz(i);
}
bool CTowOpt::GetStdBox( double box_Vec[3] )
{
	double sum_sq=0.0;
	for( int i=0;i<3;++i ) 
	{
		box_Vec[i]=m_StdMaxPt.xyz(i)-m_StdMinPt.xyz(i); 
		sum_sq+=box_Vec[i]*box_Vec[i];
	}

	if(sum_sq>1.0e-8)
		return true;
	else
	{
		for( int i=0;i<3;++i ) 
			box_Vec[i]=1.0; 

		return false;
	}
}
bool CTowOpt::GetStlBox( double box_Vec[3] )
{
	double sum_sq=0.0;
	for( int i=0;i<3;++i ) 
	{
		box_Vec[i]=m_StlMaxPt.xyz(i)-m_StlMinPt.xyz(i); 
		sum_sq+=box_Vec[i]*box_Vec[i];
	}

	if(sum_sq>1.0e-8)
		return true;
	else
	{
		for( int i=0;i<3;++i ) 
			box_Vec[i]=1.0; 

		return false;
	}
}

void CTowOpt::ReadStdFile( const CString& std_File, const CString& file_Ext )
{
	CString file_ExtLow( file_Ext );
	file_ExtLow.MakeLower();

	string err_Str;
	bool is_read;
	m_IsMea=false;
	TDSVec3DPtNor std_Set;
	if( TowFileOrigin==file_ExtLow )
	{
		is_read=m_StdMea.Read( std_File, err_Str, std_Set );
			//m_StdMea.GetCenPt( m_StdCenPt );if( ) 
		m_IsMea=true;
		m_IsNor=false;
		//CTowFile::OpenTowFile( , m_StdSet );
	}
	else 
	{
		if( TowFileStd==file_ExtLow )
		{
			is_read=CTowFile::OpenGeneralFile( std_File, m_IsNor, std_Set );
			//m_IsStd=true;
		}
		else
		{
			is_read=CTowFile::OpenGeneralFile( std_File, m_IsNor, std_Set );
			//判断点云是否含有法矢
		}

		m_IsMea=false;
		if( is_read ) m_StdMea.clear();
	}

	m_IsStd=false;

	if( is_read ) 
	{
		std_Set.swap( m_StdSet );
		CalStdCenPt();
		//AfxMessageBox( CString("标准数据读取成功!") );
	}
	else AfxMessageBox( CString( err_Str.c_str() ) );
}

void CTowOpt::ReadStd()
{
	CString lpszFilter( "TXT Files(*.txt , *TXT)|*.txt|" ); //软件自身标准格式的文件

	lpszFilter += "All Files(*.*)|*.*||";
	CFileDialog dlg(true,CString(".txt"),NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);

	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	ReadStdFile( dlg.GetPathName(), dlg.GetFileExt() );
}

CString CTowOpt::StdOpenExt()
{
	CString lpszFilter( "Tow Std Files(*.tsd , *TSD)|*.tsd|" ); //软件自身标准格式的文件
	lpszFilter += "Tow Mea Files(*.tow , *TOW)|*.tow|";
	lpszFilter += "ASCII Files(*.asc , *ASC)|*.asc|Text Files(*.txt , *TXT)|*.txt|Dat Files(*.dat , *DAT)|*.dat|Vertex Files(*.vtx , *VTX)|*.vtx|";
	lpszFilter += "All Files(*.*)|*.*||";

	return lpszFilter;
}

void CTowOpt::SetStd( const TDSVec23DPt& vec_StdSet )
{
	m_StdMea.SetPSet( vec_StdSet );
	m_IsStd=false;
	m_IsNor=false;
}


void CTowOpt::WriteStd()
{
	CString lpszFilter,lpszDefExt;
	if( m_IsNor ) 
	{
		lpszFilter+= "Tow Std Files(*.tsd , *TSD)|*.tsd|"; //软件自身格式的文件
		lpszDefExt+=".tsd";
	}
	else 
	{
		if( m_IsMea ) 
		{
			lpszFilter+= "Tow Mea Files(*.tow , *TOW)|*.tow||";
			if( lpszDefExt.IsEmpty() ) lpszDefExt+=".tow";
		}
		else 
		{
			lpszFilter+= "Asc Files(*.asc , *ASC)|*.asc||";
			if( lpszDefExt.IsEmpty() ) lpszDefExt+=".asc";
		}
	}
	
		

	CFileDialog dlg(false,lpszFilter,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpszFilter,NULL);

	if ( dlg.DoModal() != IDOK )
	{
		return;
	}

	WriteStdFile( dlg.GetPathName(), dlg.GetFileExt() );
}

void CTowOpt::WriteStdFile( CString& path_Name, CString& file_Ext )
{
	bool is_write=false; 
	CString file_Ext2(file_Ext);
	if( TowFileOrigin==file_Ext2.MakeLower() )
		is_write=m_TowMea.Write( path_Name );
	else
	{
		if( m_IsNor ) is_write=CTowFile::SaveTowStdFile( path_Name, m_StdSet );
		else is_write=CTowFile::SaveGeneralFile( path_Name, false, m_StdSet );
	}

	if( is_write );
		//AfxMessageBox( path_Name+CString(": 成功保存标准化点云!") );
	else
		AfxMessageBox( path_Name+CString(": 无法保存标准化点云，请确保文件可用!") );
}

CString CTowOpt::StdSaveExt()
{
	CString lpszFilter;
	if( m_IsNor ) 
	{
		lpszFilter+= "Tow Std Files(*.tsd , *TSD)|*.tsd|"; //软件自身格式的文件
	}
	else 
	{
		if( m_IsMea ) 
			lpszFilter+= "Tow Mea Files(*.tow , *TOW)|*.tow||";
		else 
			lpszFilter+= "Asc Files(*.asc , *ASC)|*.asc||";
	}

	return lpszFilter;
}
void CTowOpt::CalTowCenPt() //求取包围盒及中心点
{
	if( m_TowSet.empty() ) return;

	//中心点初始化为零点
	m_TowCenPt.setx(0.0);
	m_TowCenPt.sety(0.0);
	m_TowCenPt.setz(0.0);

	TDSVec3DPtIt pn_it=m_TowSet.begin();
	m_TowMaxPt=(*pn_it);
	m_TowMinPt=(*pn_it);
	double tmp_Val;
	for( ;pn_it!=m_TowSet.end();++pn_it )
	{
		m_TowCenPt+=(CDS3DPt)(*pn_it);

		if( (tmp_Val=pn_it->x())<m_TowMinPt.x() ) m_TowMinPt.setx( tmp_Val );
		else if( tmp_Val>m_TowMaxPt.x() ) m_TowMaxPt.setx( tmp_Val );

		if( (tmp_Val=pn_it->y())<m_TowMinPt.y() ) m_TowMinPt.sety( tmp_Val );
		else if( tmp_Val>m_TowMaxPt.y() ) m_TowMaxPt.sety( tmp_Val );

		if( (tmp_Val=pn_it->z())<m_TowMinPt.z() ) m_TowMinPt.setz( tmp_Val );
		else if( tmp_Val>m_TowMaxPt.z() ) m_TowMaxPt.setz( tmp_Val );
	}

	m_TowCenPt*=(double)(1.0/m_TowSet.size()); //平均得到中心点
}

void CTowOpt::CalStdCenPt() //求取包围盒及中心点
{
	if( m_StdSet.empty() ) return;

	//中心点初始化为零点
	m_StdCenPt.setx(0.0);
	m_StdCenPt.sety(0.0);
	m_StdCenPt.setz(0.0);
	
	TDSVec3DPtNorIt pn_it=m_StdSet.begin();
	m_StdMaxPt=(*pn_it);
	m_StdMinPt=(*pn_it);
	double tmp_Val;
	for( ;pn_it!=m_StdSet.end();++pn_it )
	{
		m_StdCenPt+=(CDS3DPt)(*pn_it);

		if( (tmp_Val=pn_it->x())<m_StdMinPt.x() ) m_StdMinPt.setx( tmp_Val );
		else if( tmp_Val>m_StdMaxPt.x() ) m_StdMaxPt.setx( tmp_Val );

		if( (tmp_Val=pn_it->y())<m_StdMinPt.y() ) m_StdMinPt.sety( tmp_Val );
		else if( tmp_Val>m_StdMaxPt.y() ) m_StdMaxPt.sety( tmp_Val );

		if( (tmp_Val=pn_it->z())<m_StdMinPt.z() ) m_StdMinPt.setz( tmp_Val );
		else if( tmp_Val>m_StdMaxPt.z() ) m_StdMaxPt.setz( tmp_Val );
	}

	m_StdCenPt*=(double)(1.0/m_StdSet.size()); //平均得到中心点
}

void CTowOpt::CalStlCenPt()
{
	//if( m_StlSet.empty() ) return;

	//中心点初始化为零点
	m_StlCenPt.setx(0.0);
	m_StlCenPt.sety(0.0);
	m_StlCenPt.setz(0.0);

	TDSVecFaceConIt pn_it=in_TriSet.begin();
	m_StlMinPt=pn_it->m_pt1;
	m_StlMaxPt=pn_it->m_pt1;
    double tmp_Val;
	int i;
	for( ;pn_it!=in_TriSet.end();++pn_it )
	{
		CDS3DPt tmpCenPt=pn_it->m_pt1;
        m_StlCenPt+=tmpCenPt;
        tmpCenPt=pn_it->m_pt2;
		m_StlCenPt+=tmpCenPt;
		tmpCenPt=pn_it->m_pt3;
		m_StlCenPt+=tmpCenPt;
		if( (tmp_Val=pn_it->m_pt1.x())<m_StlMinPt.x() ) m_StlMinPt.setx( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.x() ) m_StlMaxPt.setx( tmp_Val );

		if( (tmp_Val=pn_it->m_pt1.y())<m_StlMinPt.y() ) m_StlMinPt.sety( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.y() ) m_StlMaxPt.sety( tmp_Val );

		if( (tmp_Val=pn_it->m_pt1.z())<m_StlMinPt.z() ) m_StlMinPt.setz( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.z() ) m_StlMaxPt.setz( tmp_Val );

		if( (tmp_Val=pn_it->m_pt2.x())<m_StlMinPt.x() ) m_StlMinPt.setx( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.x() ) m_StlMaxPt.setx( tmp_Val );

		if( (tmp_Val=pn_it->m_pt2.y())<m_StlMinPt.y() ) m_StlMinPt.sety( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.y() ) m_StlMaxPt.sety( tmp_Val );

		if( (tmp_Val=pn_it->m_pt2.z())<m_StlMinPt.z() ) m_StlMinPt.setz( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.z() ) m_StlMaxPt.setz( tmp_Val );

		if( (tmp_Val=pn_it->m_pt3.x())<m_StlMinPt.x() ) m_StlMinPt.setx( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.x() ) m_StlMaxPt.setx( tmp_Val );

		if( (tmp_Val=pn_it->m_pt3.y())<m_StlMinPt.y() ) m_StlMinPt.sety( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.y() ) m_StlMaxPt.sety( tmp_Val );

		if( (tmp_Val=pn_it->m_pt3.z())<m_StlMinPt.z() ) m_StlMinPt.setz( tmp_Val );
		else if( tmp_Val>m_StlMaxPt.z() ) m_StlMaxPt.setz( tmp_Val );
	}

	m_StlCenPt*=(double)(1.0/(in_TriSet.size()*3)); //平均得到中心点
}
void CTowOpt::ReadStl()
{
   	CString lpszFilter( "STL Files(*.stl,*.STL)|*.stl||" ); //软件自身格式的文件 lpszFilter参数设置选择文件类型
	CFileDialog dlg(true,// Open TRUE为打开文件对话框；FALSE为保存文件对话框
		CString(".stl"),// 如果值为null，则为缺省扩展名
		NULL,// 缺省文件名
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT, // 选项 对话框风格，一般为OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 即隐藏只读选项和覆盖已有文件前提示。
		lpszFilter,// 文件过滤器/*lpszFilter：文件筛选类型，它指明可供选择的文件类型和相应的扩展名。参数格式如：
//"Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|All Files (*.*)|*.*||";文件类型说明和扩展名间用 | 分隔，
//同种类型文件的扩展名间可以用 ; 分割，每种文件类型间用 | 分隔，末尾用 || 指明。*/
		NULL);// 父窗口

	if (dlg.DoModal() != IDOK)//弹出对话框并点击OK键.点击了打开确定操作
	{
		return;
	}
	ReadStlFile(dlg.GetPathName());//可以成功返回stl文件路径
}
void CTowOpt::ReadStlFile(const CString& stl_File)
{
	float normx,normy,normz,vetx,vety,vetz;//norm:三角面片法向量的3个分量值  vet:三角面片三个顶点
	FILE* file;
	if ((file = fopen (stl_File, "r")) == NULL) return;
	//返回值：文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在errno 中。
	//参数path字符串包含欲打开的文件路径及文件名，参数mode字符串则代表着流形态。r 以只读方式打开文件，该文件必须存在。
	char str[80];
	char temp1[20],temp2[20],temp3[20];
	CMesh Sgl_TriFace;
	CDS3DPt tempPt;
	CDS3DVec tempVec;
	while(fscanf(file,"%s",str)==1)/*FILE *stream：文件指针；  fscanf返回的是实际读取的数据个数，出错或者到结尾时才返回EOF。
                                                  char *format：格式字符串；EOF的值是-1
                                                  [argument...]：输入列表。fscanf(fp, %s ,str)!=EOF这句的意思就是用fscanf读fp指向的文件，要读的内容是一个
												  字符串%s,把字符串读到str指向的空间里，如果读成功，fscanf返回成功读取的字符的个数，如果失败，返回EOF。
                                                  */
	{ 
		if(strncmp(str,"normal",6)==0)/*函数原型 int strncmp(char *str1, char *str2, int maxlen);
此函数用来比较字符串str1和str2的前maxlen个字符。如果前maxlen字节完全相等，返回值就=0；在前maxlen字节比较过程中，如果出现str1[n]与str2[n]不等，则
返回（str1[n]-str2[n]）这里strncmp(str1, str2, strlen(str1))==0，就是判断字符串str2是否以字符串str1开头，如果是，该表达式为真，否则为假*/
		{   
			fscanf (file,"%f%f%f",&normx,&normy,&normz);
			tempVec=CDS3DVec(normx,normy,normz);
			Sgl_TriFace.m_nor=tempVec;
			//读取法矢量数据, 滤过三个字符串后就是面
			//片的第一个顶点数据
			fscanf(file,"%s%s%s",temp1,temp2,temp3);
			fscanf(file,"%f%f%f",&(vetx),&(vety),&(vetz));
			tempPt=CDS3DPt(vetx,vety,vetz);
			Sgl_TriFace.m_pt1=tempPt;
			fscanf(file,"%s",str);   
			if(strncmp(str,"vertex",6)==0)
			//fscanf(file,"%s%s",temp1,temp2);
			{	vetx =0;
                vety =0;
                vetz =0;
			fscanf (file,"%f%f%f",&(vetx),&
				(vety),&(vetz));
			tempPt=CDS3DPt(vetx,vety,vetz);
			Sgl_TriFace.m_pt2=tempPt;
			}
			fscanf(file,"%s",str);
			if(strncmp(str,"vertex",6)==0)
				//fscanf(file,"%s%s",temp1,temp2);
			{	vetx =0;
            vety =0;
            vetz =0;
			fscanf (file,"%f%f%f",& (vetx),&
				(vety),&(vetz));
			tempPt=CDS3DPt(vetx,vety,vetz);
			Sgl_TriFace.m_pt3=tempPt;
			}
			fscanf(file,"%s%s%s",temp1,temp2,temp3);
			in_TriSet.push_back(Sgl_TriFace);
		}
		memset(str,0,sizeof(char)*80);/*void *memset(void *s, int ch, size_t n);
									  函数解释：将s中前n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
                                 memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法*/
		
	}
	CalStlCenPt();
	fclose(file);
	
}

void CTowOpt::PoseStd( bool is_mess )
{
	if( m_IsMea )
	{
		m_StdMea.StdTow( int(TowStdMaxNum*1.1), m_StdSet );
		m_IsNor=true;
	}
	else
	{
		if( m_StdSet.size()>(TowStdMaxNum)*1.1 ) //若点云超过点数，则进行精简
		{
			TowSimpUniform simp_Unif( m_StdSet );
			simp_Unif.SimpUniSam_Number( TowStdMaxNum, m_StdSet );
		}
		if( !m_IsNor )
		{
			CTowTop tow_Top( m_StdSet ); //构建标准点云的法矢
			m_IsNor=true;
		}
	}

	//CTowTop top_Tow( m_StdSet );

	CalStdCenPt();
	m_IsStd=true;
	if( is_mess ) AfxMessageBox( CString("点云成功标准化!") );
}

void CTowOpt::RunBlend( bool is_BldMess )
{
	//先判断是否输入测量点云
	if( m_TowSet.empty() )
	{
		AfxMessageBox( _T("先输入测量模型!") );
		return ;
	}

	if( !m_IsStd )
	{
		if( m_StdMea.IsEmpty()&&m_StdSet.empty() )
		{
			AfxMessageBox( _T("先输入标准模板!") );
			return ;
		}
		else 
			PoseStd(false);
	}

	LONGLONG   tBegin,tEnd; 
	LONGLONG   persecond; 
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&persecond));//询问系统一秒钟的频率 
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&tBegin));
	
	//先对测量点云进行预处理
	TDSVec3DPt movpt1=m_TowMea.GetPSet();
	m_TowMea.PreTow( int(m_StdSet.size()/TowStdMeaRatio) );
	TDSVec3DPt movpt=m_TowMea.GetPSet();
   TDSVec3DPtNor fixpt=m_StdSet;

	//CTowBlend *tow_Bld;
	if( !m_IsNor ) //tow_Bld=&( CTowADF( m_TowMea.GetPSet(), m_StdSet ) );
	{
		CTowADF tow_Adf( m_TowMea.GetPSet(), m_StdSet );
        tow_Adf.Blend( m_ErrChrom );
	}
	else //tow_Bld=&( CTowICP( m_TowMea.GetPSet(), m_StdSet ) );
	{
        CTowICP tow_Icp( m_TowMea.GetPSet(), m_StdSet );
        tow_Icp.Blend( m_ErrChrom );

	}
	m_ErrChrom.SetFlag( true );
	
	//tow_Bld->Blend( m_ErrChrom );

	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&tEnd)); 
	double   tTime = static_cast<double>(tEnd - tBegin) / static_cast<double>(persecond); 

	//显示拼合时间
	if( is_BldMess )
	{
		CString strTime;
		strTime.Format(CString("%f 秒"), tTime);
	}
}

void CTowOpt::RunAll( const TDSVec23DPt& vec_PSet )
{
	m_TowMea.SetPSet( vec_PSet );
	RunBlend( false );
}

void CTowOpt::RunAll( const CString& mea_File )
{
	ReadMea( mea_File );
    RunBlend( false );
}

void CTowOpt::RunAll()
{
	ReadMea();
    RunBlend( false );
}

void CTowOpt::SetValidErr( const double err_Valid ) //设置有效误差范围
{
}

void CTowOpt::SetSegNum( const int num_Seg ) //设置色谱段数
{
}


void CTowOpt::SetLimitErr( const double err_Limit )//设置极限误差范围  增加修改
{
}
void CTowOpt::SetFirTolePerc( const double perc_FirTole ) //设置有效误差容差率
{

}
void CTowOpt::SetSecTolePerc( const double perc_SecTole ) //设置极限误差容差率
{

}
