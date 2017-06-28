#pragma once
//#include "afxcmn.h"
#include "DataStructure.h"


class /*DS_API_EXPORT*/ TowSimpInterData
{
public:
	bool SimpEnterYes;
	bool SimpCancelNo;
	int  SimpNumber;
	TDSVec3DPtNor SimpData;
};

class /*DS_API_EXPORT*/ TowSimpCovEigData
{
public:
	double EigVal;
	CDS3DPt EigVec;
	TowSimpCovEigData(double val,CDS3DPt vec)
	{
		EigVal=val;
		EigVec=vec;
	}
};

class /*DS_API_EXPORT*/ TowSimpBase
{
protected:
	// 用于精简的点云的最大坐标值
	CDS3DPt PCloud_MaxXYZ;
	// 用于精简的点云的最小坐标值
	CDS3DPt PCloud_MinXYZ;
	// 用于精简的点云的最小包围盒各边边长
	CDS3DPt PCloud_LXYZ;
public:
	// 待精简的点云
	TDSVec3DPtNor SimpPCloud;
	// 传当前点云CurrentPCloud的数据，用于各种数据精简
	//int SimpOperNum;
protected:
	double DotP3D(const CDS3DPt &p3d1,const CDS3DPt &p3d2);
public:
	TowSimpBase(void);
	TowSimpBase( const TDSVec3DPtNor& in_PCloud );
    TowSimpBase( const TDSVec3DPtNor& in_PCloud, 
		         const CDS3DPt box_MaxPt, const CDS3DPt box_MinPt );
	TowSimpBase(bool SimpInfoJud);
public:
	~TowSimpBase(void);
public:
	void InfOfPSet(const TDSVec3DPt& PSet, CDS3DPt& Max_XYZ, CDS3DPt& Min_XYZ);
	void InfOfPSetNor( const TDSVec3DPtNor& PSet, CDS3DPt& Max_XYZ, CDS3DPt& Min_XYZ );
	bool SimpCreIndexPCloud(double SampleSpace,map<int,TDSVec3DPtNor>& SimpIndexPCloud);
public:
	// 基于间距的均匀采样
	bool SimpUniform_Spacce(double SampleSpace,TDSVec3DPtNor& temp_SimpPCloud);
	// 基于点数的均匀采样
	bool SimpUniform_Number(int SampleNum, TDSVec3DPtNor& temp_SimpPCloud);
public:
	CDS3DPtNor MinPToPSetCenter(const TDSVec3DPtNor PointSet);

	void GetXYZAxisData(const TDSVec3DPtNor& PointSet, TDSVecDou& XData_PSet, TDSVecDou& YData_PSet, TDSVecDou& ZData_PSet);
	
public:
	void GetCenterOfPSet(const TDSVec3DPtNor& PointSet, CDS3DPt& CenterPSet);
	void GetPSetSubCenter(const TDSVec3DPtNor& PointSet, vector<CDS3DPt>& PointSetSubCen);//vector<double> &SqureDistToCen);
public:
	void LeastSquareFit(const vector<CDS3DPt>& PointSetSubCen, vector<TowSimpCovEigData>& EigValAndVec);
	void OCTXYZSpi(const TDSVec3DPtNor& PSet, map<int,TDSVec3DPtNor>& OCTPSet);
	
	
public:
};


/****************************均匀采样类声明内容****************************/

class/* DS_API_EXPORT*/ TowSimpUniform:public TowSimpBase
{
public:
	TowSimpUniform();
	TowSimpUniform( const TDSVec3DPtNor& in_PCloud );
	TowSimpUniform( const TDSVec3DPtNor& in_PCloud, 
		            const CDS3DPt box_MaxPt, const CDS3DPt box_MinPt );
	~TowSimpUniform();

	void GridIndexPSet( const double SampleSpace, const TDSVec3DPtNor& PSet, map<int,TDSVec3DPtNor>& IndexPSet );
	bool SimpUniSamBySpacce( const double SampleSpace,TDSVec3DPtNor& temp_SimpPCloud );

	//基于间距的均匀采样	
	bool SimpUniSam_Space( const double SampleSpace,TDSVec3DPtNor& NewPCloud );//基于间距的采样函数
	//基于点数的均匀采样	
	void CreIndexPSet( const double SampleSpace, vector<int>& IndexOfPSet );//为用于精简的点云创建栅格索引号
	int  GridNum( const vector<int>& Grid_P );//统计栅格总数	
	void GetSpacForNum( const int SamNum, double& SamSpac, vector<int>& IndexOfPSet );//依采样点数，获取合适采样间距
	bool SimpUniSam_Number( const int SamNum, TDSVec3DPtNor& NewPCloud );//基于点数的采样函数

};
/****************************均匀采样类声明结束****************************/

/****************************随机采样类声明内容****************************/
class /*DS_API_EXPORT*/ TowSimpRandom:public TowSimpBase
{
public:
	void RanNumForm(const int CurAllNum, const int CurRanNum, vector<int>& vec_KeepSeq);
	void RanSpiPSet(const TDSVec3DPtNor& PSet, map<int,TDSVec3DPtNor>& map_SpiPSet);
	void RanSamByNum(const int CurRanNum, const TDSVec3DPtNor& PSet, TDSVec3DPtNor& SamPSet);
public:
	bool SimpRanSam(int RanNum, TDSVec3DPtNor& temp_SimpPCloud);
};
/****************************随机采样类声明结束****************************/

/****************************层次聚类类声明内容****************************/
class/* DS_API_EXPORT*/ TowSimpClusBSP
{
public:
	int pointnum;
	bool fullsym;
	double surfvar;
	TowSimpClusBSP *BSPLeft;
    TowSimpClusBSP *BSPRight;
};

class /*DS_API_EXPORT*/ TowSimpCluster:public TowSimpBase
{
private:
	int NumThr;
	double VarThr;
	TDSVec3DPtNor BSPPCloud;
public:
    TowSimpCluster();
	~TowSimpCluster();
public:
	void BSPLSFInfo(const TDSVec3DPt& PointSetSubCen, CDS3DPt &VecOfMaxEigVal, double &SurfVar, bool varsym=false);
	void BSPLRSpi(const TDSVec3DPtNor& PSet, const TDSVec3DPt& PSetSubCen, const CDS3DPt &SpiDirec,TDSVec3DPtNor& LeftPSet, TDSVec3DPtNor& RightPSet);
	void BSPCreate(const TDSVec3DPtNor& PSet,TowSimpClusBSP *BSP);
	void BSPCreate(const TDSVec3DPtNor& PSet);
	void BSPCreateByNum(const int thr_num, const TDSVec3DPtNor& PSet, map<int,TDSVec3DPtNor>& map_SpiPSet);
	void BSPCreateByVar(const TDSVec3DPtNor& PSet);
	void BSPCreateByVar(const double thr_var, const map<int,TDSVec3DPtNor>& map_SpiPSet, TDSVec3DPtNor& ClusPCloud);
	bool SimpHieClus(const int numthr, const double varthr, TDSVec3DPtNor& ClusPCloud);
};
/****************************层次聚类类声明结束****************************/

/****************************曲率采样类声明内容****************************/
class /*DS_API_EXPORT*/ TowSimpCurvature:public TowSimpBase
{
public:

};
/****************************曲率采样类声明结束****************************/
