#pragma once
#include "COpenGL.h"
//#include "..\iCloudCuM\DataStructure.h"
#include "TowOperation.h"

// COpenGLView 视图
//#define tagColor
//class CTowOpt;
#define  OpenGLViewSplit 3.0

class COpenGLView : public CView
{
	DECLARE_DYNCREATE(COpenGLView)

public:
	COpenGLView();           // 动态创建所使用的受保护的构造函数
	virtual ~COpenGLView();
	BOOL is_tow;
	BOOL is_CalcChrom;
	//CTowOpt GetTowOpt() const { return m_TowOpt; }
	void DrawCNString(const char *str);  //绘制文字
	void SelectFont(int size, int charset, const char *face);
	CTowOpt &RefTowOpt() { return m_TowOpt; }
	const CTowOpt &RefTowOpt() const { return m_TowOpt; }
	
	//更新视图，当用户修改参数等需要调用该函数更新视图，否则不予更新
	void UpdateView() { Invalidate(); }
	//更新点云，true更新标准点云或误差色谱图，false更新测量点云
	void UpdatePCloud(bool is_std ); 
	//复原测量点云、标准点云显示初始位置
	void RecoveryPCloud(  );
    //设置误差显示的标志，读取误差文件chr或执行拼合后设置为true，
	//若显示测量铜网或标准铜网则设置为false
   void SetShowErrSym( bool is_err=true )   //增加修改
	{ m_IsShowErr=is_err;
	} 
	//是否显示铜网点云
	void SetShowTowSym( bool is_tow=true ) { m_IsShowTow=is_tow; }
	//是否显示标准点云
	void SetShowStdSym( bool is_std=true ) { m_IsShowStd=is_std; }
    //是否显示stl文件
	void SetShowStlSy(bool is_stl=true){m_IsShowStl=is_stl;}
	//判断当前视图是否显示误差
	bool IsShowErr() const { return m_IsShowErr; }
	//判断当前视图是否显示铜网点云
	bool IsShowTow() const { return m_IsShowTow; }
	//判断当前视图是否显示标准点云
	bool IsShowStd() const { return m_IsShowStd; }
    //判断当前视图是否显示stl文件
	bool IsShowStl() const { return m_IsShowStl; }

public:
	CFont m_Font;
	CDSChrom newPtChrom;
	int m_nCol;
	double m_maxCri;double m_maxNom;double m_minNom;double m_minCri;
		//int m_nCol=13;只有静态常量整型数据成员才可以在类中初始化,所以应该在构造函数中赋值
	//int m_maxCri=2;int m_maxNom=0.3;int m_minNom=-0.3;int m_minCri=-2;
private:
	bool ShowError( bool is_showerr=true );
	void ShowStd();
	void ShowTow();
	void ShowStl();
	void ShowChrom();
	void drawCNString( const char * str ); 
private:
    COpenGL m_nViewOpenGL;
	CTowOpt m_TowOpt;

	void Create2DTextLists();

	GLuint m_2DTextList;
	bool m_IsShowErr;
	bool m_IsShowTow; //是否显示测量点云
	bool m_IsShowStd; //是否显示标准点云
	bool m_IsShowStl;

	//视图的相关控制
	bool m_IsRotCen;
	double m_RotCen[3],m_BoxVec[3];
	int m_BoxMaxSeq;
	
    double m_fViewAspect;


public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void SetBase();
public:
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


