// OpenGLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OpenGLView.h"
#include "../gl/glut.h"
#include "..\Dlg3DMeasureMatch.h"

// COpenGLView 

IMPLEMENT_DYNCREATE(COpenGLView, CView)

COpenGLView::COpenGLView()
	: m_IsShowErr( false ) 
	, m_IsShowTow( true )
	, m_IsShowStl(true)
	, m_IsShowStd( false )
    , m_IsRotCen( false ) 
	, is_CalcChrom(false)
	, m_fViewAspect( 1.0 )
	, m_BoxMaxSeq( 0 )
{
	m_nViewOpenGL.SetProjectionMode(1);
	m_nViewOpenGL.SetTwoView(false);


	for( int i=0;i<3;++i )
	{
		m_RotCen[i]=0.0;
		m_BoxVec[i]=2.0;
	}
}

COpenGLView::~COpenGLView()
{
}

void COpenGLView::Create2DTextLists()
{
	CFont m_font;
//	GLYPHMETRICSFLOAT agmf[256]; 
	m_font.CreateFont(	-12,                                     // Height Of Font
						0,                                     // Width Of Font
						0,                                     // Angle Of Escapement
						0,                                     // Orientation Angle
						FW_BOLD,                       // Font Weight
						FALSE,                             // Italic
						FALSE,                             // Underline
						FALSE,                             // Strikeout
						ANSI_CHARSET,               // Character Set Identifier
						OUT_TT_PRECIS,             // Output Precision
						CLIP_DEFAULT_PRECIS, // Clipping Precision  裁剪精度
						ANTIALIASED_QUALITY,  // Output Quality 
						FF_DONTCARE | DEFAULT_PITCH, // Family And Pitch
						_T("宋体") );  //T("Arial" 修改
	m_Font.CreateFont(	-12,                                     // Height Of Font
		0,                                     // Width Of Font
		0,                                     // Angle Of Escapement
		0,                                     // Orientation Angle
		FW_BOLD,                       // Font Weight
		FALSE,                             // Italic
		FALSE,                             // Underline
		FALSE,                             // Strikeout
		ANSI_CHARSET,               // Character Set Identifier
		OUT_TT_PRECIS,             // Output Precision
		CLIP_DEFAULT_PRECIS, // Clipping Precision  裁剪精度
		ANTIALIASED_QUALITY,  // Output Quality 
		FF_DONTCARE | DEFAULT_PITCH, // Family And Pitch
		_T("宋体") );  //T("Arial" 修改

	CDC* pDC=GetDC();
	CFont* m_pOldFont = pDC->SelectObject(&m_font);

    // create display lists for glyphs 0 through 255 with 0.1 extrusion 
    // and default deviation. The display list numbering starts at 1000 
    // (it could be any number) 
	m_2DTextList = glGenLists(256);


    // create display lists for glyphs 0 through 255 with 0.1 extrusion 
    // and default deviation. The display list numbering starts at 1000 
    // (it could be any number)
	wglUseFontBitmaps(pDC->GetSafeHdc(), 0, 255, m_2DTextList); 


	pDC->SelectObject(m_pOldFont);
}

BEGIN_MESSAGE_MAP(COpenGLView, CView)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_MOUSEACTIVATE()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// COpenGLView 绘图

void COpenGLView::OnDraw(CDC* /*pDC*/)
{
	m_nViewOpenGL.OnInitRenderOpenGL();
	SetBase();
	tagCVector fBoxCenter,fBoxSize;
	m_nViewOpenGL.GetBox( fBoxCenter,fBoxSize );	
			if( m_IsShowTow ) ShowTow();//Tow点云
		if( m_IsShowStd ) ShowStd();//绘制std点云，操作的时候需要操作两个点云，一个打开，一个导入
		if(m_IsShowStl) ShowStl();
		if(m_IsShowErr) ShowChrom();

	
CDlg3DMeasureMatch *pApp=(CDlg3DMeasureMatch *)AfxGetApp( );

	m_nViewOpenGL.SwapBufferOpenGL();
}


// COpenGLView 诊断

#ifdef _DEBUG
void COpenGLView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void COpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


BOOL COpenGLView::OnEraseBkgnd(CDC* /*pDC*/)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}

// COpenGLView 消息处理程序

void COpenGLView::OnDestroy()
{
	CView::OnDestroy();

	m_nViewOpenGL.OnDestroyOpenGL();	
}

int COpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_nViewOpenGL.OnInitOpenGL(m_hWnd);
	Create2DTextLists();

	return 0;
}

void COpenGLView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	m_nViewOpenGL.OnSizeOpenGL(nType, cx, cy);	

    //CRect Rect;
	//GetClientRect(&m_ViewRect);
	m_fViewAspect=1.0;
	if( cx>0 )
	{
		//m_ViewRect.Height()/m_ViewRect.Width();
		m_fViewAspect=(double)cy/(double)cx;
	}
    
}

void COpenGLView::SetBase()
{
	//背景填充
	glPushMatrix();
	glLoadIdentity();


	double len_x,len_y;

	if( m_fViewAspect>1.0 )
	{
		len_x=m_BoxVec[m_BoxMaxSeq]*1.1;
		len_y=len_x*m_fViewAspect;
	}
	else
	{
		len_y=m_BoxVec[m_BoxMaxSeq]*1.1;
		len_x=len_y/m_fViewAspect;
	}


    glEnable(GL_DEPTH_TEST);
		glBegin(GL_POLYGON);//多边形 背景
			glColor3d(0.1,  0.0 ,  0.4);//r	OpenGLViewSplit/a
			glVertex3d(len_x, len_y, -1990.0);	
			glColor3d(0.1,  0.0 ,  0.4);//g	
			glVertex3d(-len_x, len_y, -1990.0); 
			glColor3d(0.95, 0.95, 0.95);	//b	
			glVertex3d(-len_x, -len_y, -1990.0); 
			glColor3d(0.95, 0.95, 0.95);	//r	
			glVertex3d(len_x, -len_y, -1990.0); 
		glEnd(); 
	glPopMatrix();
		//画左下方的坐标系

	double len_Axis=0.3*m_BoxVec[m_BoxMaxSeq],len_ReAxis=0.2*m_BoxVec[m_BoxMaxSeq];
	tagCVector scale_Vec(m_nViewOpenGL.GetScaling('o'));
	double scale_xVal=( scale_Vec.x>0.8 ? 1.0:(scale_Vec.x+0.0001) );
	double scale_yVal=( scale_Vec.y>0.8 ? 1.0:(scale_Vec.y+0.0001) );
	double scale_zVal=( scale_Vec.z>0.8 ? 1.0:(scale_Vec.z+0.0001) );

	if (!m_IsRotCen)
	{
		glLineWidth(2.0f);
		glBegin(GL_LINES);
		glColor3d(1.0,0.0,0.0);
		glVertex3d(0.0,0.0,0.0);
		glVertex3d(len_Axis/scale_xVal,0.0,0.0);
		glEnd();
		glBegin(GL_LINES);
		glColor3d(0.0,1.0,0.0);
		glVertex3d(0.0,0.0,0.0);
		glVertex3d(0.0,len_Axis/scale_yVal,0.0);
		glEnd();
		glBegin(GL_LINES);
		glColor3d(0.0,0.0,1.0);
		glVertex3d(0.0,0.0,0.0);
		glVertex3d(0.0,0.0,len_Axis/scale_zVal);
		glEnd();
		glLineWidth(1.0f);

		glPointSize(3.0);

		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POINTS);

		glVertex3d(0.0, 0.0, 0.0);

		glEnd();
	}
		

	if( m_IsRotCen )
	{
		glBegin(GL_LINES);
			glColor3d(1.0,0.0,0.0);
			glVertex3d(m_RotCen[0],m_RotCen[1],m_RotCen[2]);
			glVertex3d(m_RotCen[0]+len_ReAxis/scale_xVal,m_RotCen[1],m_RotCen[2]);
		glEnd();

		glBegin(GL_LINES);
			glColor3d(0.0,1.0,0.0);
			glVertex3d(m_RotCen[0],m_RotCen[1],m_RotCen[2]);
			glVertex3d(m_RotCen[0],m_RotCen[1]+len_ReAxis/scale_yVal,m_RotCen[2]);
		glEnd();
		
		glBegin(GL_LINES);
			glColor3d(0.0,0.0,1.0);
			glVertex3d(m_RotCen[0],m_RotCen[1],m_RotCen[2]);
			glVertex3d(m_RotCen[0],m_RotCen[1],m_RotCen[2]+len_ReAxis/scale_zVal);
		glEnd();
		glLineWidth(1.0f);

		glPointSize(3.0);

			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_POINTS);
			
			glVertex3d(m_RotCen[0],m_RotCen[1],m_RotCen[2]);
			
		glEnd();
	}
}

int COpenGLView::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//return 0;
	return CWnd::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

void COpenGLView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->SetFocus();
	m_nViewOpenGL.OnLButtonDown(nFlags,point);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void COpenGLView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nViewOpenGL.OnLButtonUp(nFlags,point);
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void COpenGLView::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->SetFocus();
	m_nViewOpenGL.OnMButtonDown(nFlags, point);
	Invalidate();

	CView::OnMButtonDown(nFlags, point);
}

void COpenGLView::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nViewOpenGL.OnMButtonUp(nFlags, point);
	Invalidate(FALSE);

	CView::OnMButtonUp(nFlags, point);
}

void COpenGLView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nViewOpenGL.OnMouseMove(nFlags,point);
	Invalidate(FALSE);
	CView::OnMouseMove(nFlags, point);
}

BOOL COpenGLView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nViewOpenGL.OnMouseWheel(nFlags, zDelta, pt);
	Invalidate(FALSE);
	glEnable(GL_NORMALIZE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}

void COpenGLView::ShowStd()
{
	if( m_TowOpt.IsStdEmpty() ) return ;

	const TDSVec3DPtNor &std_PSet( m_TowOpt.CRefStd() );

	glPointSize(2.0);
	TDSVec3DPtNorConIt pn_it;
	glBegin(GL_POINTS);
	for ( pn_it = std_PSet.begin() ; pn_it != std_PSet.end() ; ++pn_it )
	{
			glColor3d(0.8f, 0.8f, 0.8f);		//点的显示颜色
		glVertex3d(pn_it->x() , pn_it->y() ,pn_it->z());
	}
	glEnd();
	
}
void COpenGLView::ShowStl()
{
    const TDSVecFace &stl_PSet(m_TowOpt.CRefStl());
	if(stl_PSet.empty()){return;}
	CDS3DPt temp ;
	TDSVecFaceConIt pn_it;
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	for ( pn_it = stl_PSet.begin() ; pn_it != stl_PSet.end() ; ++pn_it )
	{
		glColor3f(1.0f, 0.0f, 0.0f );
		glNormal3f(pn_it->m_nor.ux(),pn_it->m_nor.uy(),pn_it->m_nor.uz());
		glVertex3f(pn_it->m_pt1.x(),pn_it->m_pt1.y(),pn_it->m_pt1.z());
		glNormal3f(pn_it->m_nor.ux(),pn_it->m_nor.uy(),pn_it->m_nor.uz());
		glVertex3f(pn_it->m_pt2.x(),pn_it->m_pt2.y(),pn_it->m_pt2.z());
		glNormal3f(pn_it->m_nor.ux(),pn_it->m_nor.uy(),pn_it->m_nor.uz());
		glVertex3f(pn_it->m_pt3.x(),pn_it->m_pt3.y(),pn_it->m_pt3.z());
	}
	glEnd();

}
void COpenGLView::ShowTow()
{
	if( m_TowOpt.CRefTow1().empty() ) return ;

	const TDSVec3DPt &tow_SecSet( m_TowOpt.CRefTow1() );

	glPointSize(2.0);
	TDSVec3DPtConIt pn_it;
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f );	
	glPointSize(2.0);
		for ( pn_it = tow_SecSet.begin() ; pn_it != tow_SecSet.end() ; ++pn_it )
		{
			glVertex3d(pn_it->x() , pn_it->y() ,pn_it->z());
		}
	glEnd();
}
void COpenGLView::DrawCNString(const char* str)
{ 
	int len=0, i=0; 
	wchar_t * wstring; 
	HDC hDC=wglGetCurrentDC();
	GLuint list=glGenLists( 1 ); 
	for( i=0; str[i]!='\0'; i++ ) 
	{ 
		if ( IsDBCSLeadByte( str[i] )) 
			i++; 
		len++; 
	} 
	wstring=(wchar_t*)malloc((len+1)*sizeof(wchar_t)); 
	MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len ); 
	wstring[len]=L'\0';
	for( i=0; i<len; i++ ) 
	{ 
		wglUseFontBitmapsW( hDC, wstring[i], 1, list );  
		glCallList( list ); 
	} 
	free( wstring ); 
	glDeleteLists( list, 1 );
}
void COpenGLView::SelectFont(int size, int charset, const char* face) 
{  
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,  
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,  
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);  
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}
//色谱
void COpenGLView::ShowChrom()
{
	//色谱基本数据信息,段数、上限下限值均作为全局变量在类里面已经声明。
	//int m_nCol=13;
	int m_nDec=4; //小数位数
	int nCol = m_nCol;  //颜色段数
	int nColHalf = (nCol-1)/2;
	int decimal = m_nDec;  //小数位数
	double deta, deta1, deta2;  //不同的颜色变化率
	double UpSub, DownSub;  //色谱上、下部分每块间的差值
	double AllRange = m_maxCri - m_minCri;  //色谱的总值域
	double UpEdge = m_maxCri - m_maxNom;  //色谱上部分值域
	double DownEdge = m_minNom - m_minCri;  //色谱下部分值域
	double CentEdge = m_maxNom - m_minNom;  //色谱中间值域
	CString dist;  //储存显示的数字

	deta = 0.8/(double)nColHalf;  //设置不同的颜色变化率
	deta1 = 0.6/(double)nColHalf;
	deta2 = 1/(double)nColHalf;

	UpSub = UpEdge/(double)(nColHalf);  //色谱上部分每块间的差值
	DownSub = DownEdge/(double)(nColHalf);  //色谱下部分每块间的差值

	//色谱显示数据信息
	double width = 3.6;  //色谱显示的宽度为1.8
	double height = 60.0;  //色谱显示的总长度为30

	GLdouble glLeftGap = 1.0;  //设置色谱左边距离左边界距离1.0
	GLdouble glLeft = -50.0+glLeftGap, glTop = 30.0;  //设置色谱左上角坐标15.0
	GLdouble glGapY = width/10;  //色谱每块间的距离
	GLdouble glTextGap = 1.0;  //显示数字距色谱右侧的距离0.5

	double CenSubShape = (CentEdge)/AllRange*height; //中间模块的长度
	double UpSubShape = ((UpEdge/AllRange*height)/nColHalf)-width/10;  //色谱上部分每条的显示长度
	double DownSubShape = ((DownEdge/AllRange*height)/nColHalf)-width/10;//色谱下部分每条的显示长度
	GLdouble glRight = glLeft+width;
	GLdouble glLeftText = glRight+glTextGap;  //数字的显示位置----水平坐标

	float mMatrix[16]={0.0};  //填充矩形的变换矩阵

	/*********************************** 绘制色谱柱状图 *************************************/
	//控制色谱柱状图的小数位数
	CString strDecNum = "%.4f";  //色谱柱状图小数位数

	glPushMatrix();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -5.0f);

	//int nColHalf_1=nColHalf-1;
	//绘制渐变色块（上部分）
	for(double i=0.0; i<nColHalf; i++)
	{
		glBegin(GL_POLYGON);//给出点的顺序不能变！！！！POLYGON填充的多边形
		//OpenGL要求：指定顶点的命令必须包含在glBegin函数之后，  
        //glEnd函数之前（否则指定的顶点将被忽略）。并由glBegin来指明如何使用这些点  
        //GL_POLYGON表示画多边形（由点连接成多边形）
		glColor3f(1, 0+deta*(i+1), 0);  //控制每个色块的颜色
		glVertex2f(glRight, (glTop-UpSubShape*(i+1)-i*glGapY));  //X轴间隔1.8，Y轴间隔0.2
		glColor3f(1, 0+deta*i, 0);
		glVertex2f(glRight,(glTop-(UpSubShape+glGapY)*i));
		glColor3f(1, 0+deta*i, 0);
		glVertex2f(glLeft,(glTop-(UpSubShape+glGapY)*i));
		glColor3f(1, 0+deta*(i+1), 0);  
		glVertex2f(glLeft, (glTop-UpSubShape*(i+1)-i*glGapY));  
		glEnd();
	}
	DrawCNString(" ");
	//添加色块旁的文字（上部分）
	for(double i=0.0; i<(nColHalf); i++)
	{
		SelectFont(12, GB2312_CHARSET, "楷体_GB2312"); 
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(glLeftText, (glTop-(UpSubShape+glGapY)*i));//设置字符起始位置
		dist.Format(strDecNum, m_maxCri-UpSub*i);//使得任何形式转为字符串
		DrawCNString(dist);
	}
	
	//绘制绿色色块（中间部分）                                    
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex2f(glRight,(glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape));
	glColor3f(0, 1, 0);
	glVertex2f(glRight,(glTop-(UpSubShape+glGapY)*(nColHalf)));
	glColor3f(0, 1, 0);
	glVertex2f(glLeft, (glTop-(UpSubShape+glGapY)*(nColHalf)));
	glColor3f(0, 1, 0);
	glVertex2f(glLeft, (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape));
	glEnd();

	
	//添加绿色色块旁的文字（中间部分）  在考虑到部分情况下显示色谱会在中心有一串乱码，将中间部分显示文字代码取消。
	SelectFont(12, GB2312_CHARSET, "楷体_GB2312"); 
	glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(glLeftText, (glTop-(UpSubShape+glGapY)*(nColHalf)));
	dist.Format(strDecNum, m_maxNom);
	DrawCNString(dist);

	glColor3f(0.0f,0.0f,0.0f);
	glRasterPos2f(glLeftText, (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape));
	dist.Format(strDecNum, m_minNom);
	DrawCNString(dist);
	
	for(double i=0.0; i<nColHalf; i++)//绘制渐变色块（下部分）
	{
		glBegin(GL_POLYGON);
		glColor3f(0.6-deta1*(i+1), 1-deta2*(i+1), 1);
		glVertex2f(glRight, (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape-(i+1)*(DownSubShape+glGapY)));

		glColor3f(0.6-deta1*(i), 1-deta2*(i), 1);
		glVertex2f(glRight, (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape-(i+1)*glGapY-DownSubShape*i));

		glColor3f(0.6-deta1*(i), 1-deta2*(i), 1);
		glVertex2f(glLeft, (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape-(i+1)*glGapY-DownSubShape*i));

		glColor3f(0.6-deta1*(i+1), 1-deta2*(i+1), 1);
		glVertex2f(glLeft, (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape-(i+1)*(DownSubShape+glGapY)));
		glEnd();
	}
	//添加色块旁的文字（下部分）
	for(double i=0.0;i<(nColHalf);i++)
	{
		SelectFont(12, GB2312_CHARSET, "楷体_GB2312"); 
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(glLeftText,  (glTop-(UpSubShape+glGapY)*(nColHalf)-CenSubShape-(i+1)*(DownSubShape+glGapY)));
		dist.Format(strDecNum, (m_minNom-DownSub*i-DownSub));
		DrawCNString(dist);
	}
	glPopMatrix();

	/**********************************************/
	if(is_CalcChrom)
	{
		float detaCol, detaUp, detaDown;
		UpEdge = m_maxCri - m_maxNom;
		DownEdge = m_minNom - m_minCri;
		detaUp = UpEdge/(m_nCol/2-1);
		detaDown = DownEdge/(m_nCol/2-1);
		detaCol = (float)2.0/(float)m_nCol;

		if (!(newPtChrom.m_ptColor.empty()))
		{
			vector<CDS3DPtColor>::iterator iter;
			for (iter = newPtChrom.m_ptColor.begin(); iter != newPtChrom.m_ptColor.end(); ++iter)
			{
				float r = 0, g = 0, b = 0;
				//如果位于名义值范围之上
				if ((m_maxNom<iter->m_distErr) && (iter->m_distErr<m_maxCri))
				{
					for(int i=0; i<m_nCol/2; i++)
					{
						if ((m_maxCri-detaUp*(i+1)<iter->m_distErr) && (iter->m_distErr<m_maxCri-detaUp*i))
						{ r = 1;g = detaCol*1;b = 0; }
					}
				}
				//如果位于名义值范围之下
				else if ((m_minCri<iter->m_distErr) && (iter->m_distErr<m_minNom))
				{
					for(int i=0; i<m_nCol/2; i++)
					{
						if ((m_minCri+detaDown*i<iter->m_distErr) && (iter->m_distErr<m_minCri+detaDown*(i+1)))
						{ r = 0.6-detaCol*(i+1);g = 1-detaCol*(i+1);b = 1; }
					}
				}
				//如果位于名义值范围之内
				else if ((m_minNom<iter->m_distErr) && (iter->m_distErr<m_maxNom)) { r = 0;g = 1;b = 0; }
				//如果小于最小临界值
				else if (iter->m_distErr< m_minCri) { r = 0;g = 1;b = 1; }
				//如果大于最大临界值
				else if (iter->m_distErr > m_maxCri) { r = 1;g = 0;b = 0; }
				//存储计算好颜色的点
				iter->r = r;
				iter->g = g;
				iter->b = b;
			}
		}
		is_CalcChrom = FALSE;
	}

    /**********************************************/

	//绘制点云
	vector<CDS3DPtColor>::iterator iter;
	glBegin(GL_POINTS);
	for (iter = newPtChrom.m_ptColor.begin(); iter != newPtChrom.m_ptColor.end(); ++iter)
	{
		if (iter->IsSelected()){glColor3f(0.0 , 1.0, 0.0 );}  //选中点的显示颜色（红色）
		else{glColor3f(iter->r , iter->g, iter->b );}  

		glNormal3f(iter->ux(), iter->ux(), iter->ux());
		glVertex3f(iter->x() , iter->y() ,iter->z());
	}
	glEnd();
}
void COpenGLView::UpdatePCloud( bool is_std )
{
	bool is_box;
	if( is_tow )
	{
		m_TowOpt.GetTowCenPt( m_RotCen );
		is_box=m_TowOpt.GetTowBox( m_BoxVec );
		is_tow=FALSE;
	}
	else if( is_std )
	{
		m_TowOpt.GetStdCenPt( m_RotCen );
		is_box=m_TowOpt.GetStdBox( m_BoxVec );
	}
	else
	{
        m_TowOpt.GetStlCenPt(m_RotCen);
		is_box=m_TowOpt.GetStlBox(m_BoxVec);
	}

	
	m_BoxMaxSeq=0;
	m_BoxVec[0]*=0.5;
	for( int i=1;i<3;++i ) 
	{
		m_BoxVec[i]*=0.5;
		if( m_BoxVec[i]>m_BoxVec[m_BoxMaxSeq] ) m_BoxMaxSeq=i;
	}
 
	m_nViewOpenGL.SetBox( tagCVector( (float)m_RotCen[0], (float)m_RotCen[1], (float)m_RotCen[2] ), 
		tagCVector( (float)m_BoxVec[m_BoxMaxSeq], (float)m_BoxVec[m_BoxMaxSeq], (float)m_BoxVec[m_BoxMaxSeq] ) );

	m_IsRotCen=true;

	Invalidate();
}



void COpenGLView::RecoveryPCloud()
{
	tagCVector recipscale_Vec(tagCVector(1.0,1.0,1.0) );  //缩放复原   增加修改
	m_nViewOpenGL.SetScaling('o',recipscale_Vec);

   tagCVector reciptranslate_Vec(tagCVector(0.0,0.0,0.0) );  //平移复原
	m_nViewOpenGL.SetTranslate('o',reciptranslate_Vec);

	tagCVector rotate_Vec(m_nViewOpenGL.GetScaling('o'));  //旋转复原
	tagCVector recip_Rotate_Vec(tagCVector(0.001f,0.001f,0.001f) );
	m_nViewOpenGL.SetRotateCenter('o',recip_Rotate_Vec);
	 GLdouble matrix4[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	m_nViewOpenGL.SetRotate ('o',matrix4);

	Invalidate();
}


void COpenGLView::drawCNString( const char * str )
{ 
	int len=0, i=0; 
	wchar_t * wstring; 
	for( i=0; str[i]!='\0'; i++ ) 
	{ 
		if( IsDBCSLeadByte( str[i] )) 
			i++; 
		len++; 
	} 

	wstring=(wchar_t*)malloc((len+1)*sizeof(wchar_t)); 
	MultiByteToWideChar( CP_ACP
		, MB_PRECOMPOSED, str, -1, wstring, len ); 
	wstring[len]=L'\0';
	GLuint list=glGenLists( 1 );
	CDC* pDC=GetDC();
	for( i=0; i<len; i++ ) 
	{ 
		CFont* m_pOldFont = pDC->SelectObject(&m_Font);
		
		wglUseFontBitmapsW( pDC->GetSafeHdc(), wstring[i], 1, list );
		pDC->SelectObject(m_pOldFont);
		glCallList( list );
		
	} 
	free( wstring ); 
	glDeleteLists( list, 1 ); 
}





