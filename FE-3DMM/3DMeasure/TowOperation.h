

#ifndef _TOWOPERATION_H
#define _TOWOPERATION_H

#include "afxcmn.h"
#include "TowProcess.h"
//#include "..\iCloudOpenGL\OpenGLView.h"
//#include " "
//#include <fstream>
//using std::ifstream;
//using std::ofstream;

#define TowChromFile "TOWCHROM"
#define TowChromFileNum 8

class CTowOpt
{
	////////测量点云
public: 
	//COpenGLView *hdglview;
public:
	//1107
	//void Sethdview(COpenGLView *mviewk){hdglview=mviewk;}
	static void SetMea( const TDSVec23DPt& mea_PSet ); //通过已有数据，设置测量点云

	static void ReadMea(); //读取测量点云
	static void ReadMea( const CString& mea_File ); //读取测量点云

	static void WriteMea(); //输出测量点云
    static void WriteMea( const CString& mea_File ); //输出测量点云到指定的文件
	static inline const TDSVec3DPt& CRefTow1() { return m_TowSet; } //获取标准点云
	static inline const TDSVec23DPt &CRefTow() { return m_TowMea.RefSecSet(); } //获取测量点云
	static const TDSVecFace  &CRefStl(){return in_TriSet;}
	static inline bool IsTowEmpty() { return m_TowMea.IsEmpty(); }
	static TDSVec3DPt GetTow() { return m_TowMea.GetPSet(); } //获取测量点云

	static CDS3DPt GetTowCenPt() { return m_TowCenPt; }
	static void GetTowCenPt( double cen_Pt[3] );
	static CDS3DVec GetTowBox() { return CDS3DVec( m_TowMaxPt-m_TowMinPt ); }
	static bool GetTowBox( double box_Vec[3] );
	static void CalTowCenPt();

private:
	
	static CDS3DPt m_TowCenPt,m_TowMaxPt,m_TowMinPt; //测量点云的中心点
public:
	static TDSVec3DPt m_TowSet; //标准化的点云
	static CTowMea m_TowMea; //铜网测量点云

	///////////标准点云
public:
	//通过已有数据设置标准点云
	static void SetStd( const TDSVec23DPt& vec_StdSet ); 
	//通过文件来设置标准点云
	static void ReadStdFile( const CString& std_File, const CString& file_Ext ); 
	static void ReadStd();  //含打开对话框
	//标准点云的文件打开后缀
	static CString StdOpenExt(); //打开的特定文件

	//保存标准点云
	static void WriteStdFile( CString& path_Name, CString& file_Ext ); 
	static void WriteStd();  //含保存对话框
	//标准点云的文件保存后缀
	static CString StdSaveExt(); //特定的文件保存
	
	//建立标准化的点云
	//static void PoseStd( bool is_mess=true ); 

	//static const TDSVec3DPtNor& CRefStd() { return m_StdSet; }
	//获取标准点云中心点
	static inline CDS3DPt GetStdCenPt() { return m_StdCenPt; }
	static void GetStdCenPt( double cen_Pt[3] );
	//获取包围盒长度
	static inline CDS3DVec GetStdBox() { return CDS3DVec( m_StdMaxPt-m_StdMinPt ); } 
    static bool GetStdBox( double box_Vec[3] );

	static TDSVec3DPtNor GetStd() { return m_StdSet; } //获取标准点云
	static inline const TDSVec3DPtNor& CRefStd() { return m_StdSet; } //获取标准点云
	static inline bool IsStdEmpty() { return m_StdSet.empty()&&m_StdMea.IsEmpty(); } //判断标准点云是否为空
	
public:
	static inline bool IsMea() { m_IsMea&&(!m_IsStd); }
	static void CalStdCenPt();

public:
	static TDSVec3DPtNor m_StdSet; //标准化的点云
	static CTowMea m_StdMea; //通过测量获取的标准点云，需进一步标准化

	static CDS3DPt m_StdCenPt,m_StdMaxPt,m_StdMinPt;
	static bool m_IsStd;
	static bool m_IsNor;
	static bool m_IsMea;
	static CDS3DPt m_StlCenPt,m_StlMaxPt,m_StlMinPt;

	static TDSVecFace in_TriSet;
public:
	static void ReadStl();
	static void ReadStlFile(const CString& stl_File);
	static bool GetStlBox( double box_Vec[3] );
	static void GetStlCenPt( double cen_Pt[3] );
	static inline CDS3DPt GetStlCenPt() { return m_StlCenPt; }
	static inline CDS3DVec GetStlBox() { return CDS3DVec( m_StlMaxPt-m_StlMinPt ); } 

private:
    static void CalStlCenPt();

	//////误差分析
public:
	//当测量点云和标准点云都存在时，执行点云误差对比，用于手工操作，true表示生成拼合相关信息及执行时间
	static void RunBlend( bool is_BldMess=true ); 
	//当存在标准点云时，设置测量点云即可自动执行误差评估，直至生成误差信息，用于自动检测的过程
	static void RunAll( const TDSVec23DPt& vec_PSet ); 
	//当存在标准点云时，读取文件的测量数据，并自动执行误差评估，直至生成误差信息
	static void RunAll( const CString& mea_File ); 
	//生成文件的对话框，获取测量点云的文件名，并自动执行，直至生成误差信息
	static void RunAll(); 
	//建立标准化的点云
	static void PoseStd( bool is_mess=true ); 
	//获取误差信息类
	static const CDSChrom& CRefError() { return m_ErrChrom; } 
	//读取误差信息文件，后缀名统一为"chr"或"CHR"
//	static void ReadError(); 
//	static bool ReadError( const char* chr_File ); 
	//输出误差信息文件，后缀名统一为"chr"或"CHR"
//	static void WriteError();
//	static bool WriteError( const char* chr_File );
//	static CString ErrorExt(); //误差文件的后缀，后缀名统一为"chr"或"CHR"
private:
	static CDSChrom m_ErrChrom; //测量点云的误差信息

public:
	//误差色谱图显示参数
	//static void SetMaxErr();
	static void SetValidErr( const double err_Valid ); //设置有效误差范围 默认为  avg+2*VAR
	static void SetLimitErr( const double err_Limit );//设置极限误差范围  默认为  avg+3*VAR
	static void SetFirTolePerc( const double perc_FirTole ); //设置有效误差容差率 默认为 5%
	static void SetSecTolePerc( const double perc_SecTole ); //设置极限误差容差率  默认为2%
	static void SetSegNum( const int num_Seg ); //设置色谱段数
//	static bool IsEligible(); //铜网是否合格 
//	static void UpdateChrom(); //更新误差色谱图

	//基本参数设定
	//static void SetBldTimes();
	//static void SetBldCoef();

	//static void SetMeaPtNum();
	//static void SetBldPtNum();
};

#endif