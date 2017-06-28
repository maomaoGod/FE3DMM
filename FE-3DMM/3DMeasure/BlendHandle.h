/***************************************************************** 
** 文件名称: BlendHandle.h
** 版本说明: 由iCloud3D V1.0 升级为 iCloud3D-2015
** 使用说明: 有关匹配的算法函数
** 创 建 人: 吴谋虎、李启东
** 创建时间: 2012年11月29日
** 修 改 人: 谢核、李豪
** 修改时间: 2015年10月15日
******************************************************************/


#include "DataStructure.h"
#include "KDtree.h"

#define BlendNum 15
#define BlendADF 0.05
#define iMAX 10


class dll_API CBlendHandle
{
public:
	CBlendHandle();
	CBlendHandle(const TDSVec3DPtNor& mov_PSet, const TDSVec3DPtNor& fix_PSetN);
	~CBlendHandle();

	virtual void Blend(CDSChrom& res_Err) = 0;

	//用于将连个点云的中心坐标平移到一起
	void MovePCloud(TDSVec3DPtNor& ptMoving, TDSVec3DPtNor& ptFixed);
	void MovePCloud();
	void KdtreeSearch();
	void KdtreeSearch2(vector<CDS3DPtNor>& mM, vector<CDS3DPtNor>& mF, vector<CDS3DPtNor>& mNear);
	void CreateKdtree(kdtree *ptree, int *data);
	void SearchNearest(kdtree *ptree);
	void MatrixCross(float x1[3], float x2[3], float y[3]);
	void InverseMatrix6(long float A[6][6], int n, long float B[6][6]);
	void InverseMatrix62(long double A[6][6], int n, long double B[6][6]);
	void InverseMatrix42(double A[4][4], int n, double B[4][4]);
	void InverseMatrix4(float A[4][4], int n, float B[4][4]);
	void CalDist(vector<float> &mVDist);  //添加10.15
	void CalculateBlendMatrix(float blendMatrix[4][4], const float RTMatrix[4][4]);
	void CalculateBlendMatrix1(float blendMatrix[4][4], const float RTMatrix[4][4]);
	void Inverse1(float *matrix1[], float *matrix2[], int n, float d);
	float Determinant1(float* matrix[], int n);
	float AlCo1(float* matrix[], int jie, int row, int column);
	float Cofactor1(float* matrix[], int jie, int row, int column);
	void Empty1(float *matrix[], int row, int column);
	void FitPlane(vector<vector<float>> &mVPt, vector<float> &mk);
	void CHe();

	float m_blendMatrix[4][4];

protected:
	TDSVec3DPtNor m_ptMoving;	//移动点集
	TDSVec3DPtNor m_ptFixed;	//固定点集
	TDSVec3DPtNor m_ptNearest;	//移动点集在固定点集中对应的最近点

public:
	static void SetIterTimes(const int iter_Times) { m_nIterTimes = iter_Times; }
	static int GetIterTimes() { return m_nIterTimes; }
	TDSVec3DPtNor GetMpt() {return m_ptMoving;}

protected:
	static int m_nIterTimes;
};


/**************************************************************************************************/
/****************************************               *******************************************/
/****************************************      ADF      *******************************************/
/****************************************               *******************************************/
/**************************************************************************************************/
class dll_API CHandleADF : public CBlendHandle
{
public:
	CHandleADF();
	CHandleADF(const TDSVec3DPtNor& mov_PSet, const TDSVec3DPtNor& fix_PSetN);
	~CHandleADF();

	virtual void Blend(CDSChrom& res_Err);
	void Blend2(CDSChrom& res_Err);
	void DoADF();
	void DoADF2();
	void TDM(vector<CDS3DPtNor> & mM, vector<CDS3DPtNor>& mF, float R[3][3], float T[3]);//匹配
	void AdjustVec(float Val[9],float Vec[9],float Vecnew[3][3]);//调整法矢方向
	void PCA();//主成分分析

public:
	static void SetAdfCoef(const float coef_Adf) { Adfmu = coef_Adf; }
	static float GetAdfCoef() { return Adfmu; }

protected:
	static float Adfmu;  //拼合系数
// 	map<int, vector<CDS3DPtNor>> m_mapStorePCloud;  //用于当前执行操作的各种点云
// 	int m_nMapIndex;	//记录操作次数
};


/**************************************************************************************************/
/****************************************               *******************************************/
/****************************************      ICP      *******************************************/
/****************************************               *******************************************/
/**************************************************************************************************/
class dll_API CHandleICP : public CBlendHandle
{
public:
	CHandleICP();
	CHandleICP( const TDSVec3DPtNor& mov_PSet, const TDSVec3DPtNor& fix_PSetN );
	~CHandleICP();

	virtual void Blend( CDSChrom& res_Err );

	void DoICP();
};


/**************************************************************************************************/
/****************************************               *******************************************/
/****************************************      TDM      *******************************************/
/****************************************               *******************************************/
/**************************************************************************************************/
class dll_API CHandleTDM : public CBlendHandle
{
public:
	CHandleTDM();
	CHandleTDM(const TDSVec3DPtNor& mov_PSet, const TDSVec3DPtNor& fix_PSetN);
	~CHandleTDM();

	virtual void Blend(CDSChrom& res_Err);

	BOOL m_flgevery;
	BOOL m_flgblendend;
	BOOL m_fenduan;
	vector<float> mdist;
	vector<float> Vection;
	vector<float> y_MaxMin;
	
	void Blend2();//匹配
	void BlendEnd(CDSChrom& res_Err);//匹配
	void DoTDM();//匹配
	void TDM(vector<CDS3DPtNor> & mM, vector<CDS3DPtNor>& mF, float R[3][3], float T[3]);//匹配
	void TDM1(vector<CDS3DPtNor> & mM, vector<CDS3DPtNor>& mF, double R[3][3], double T[3]);
	void CalCalV();
	void DelIso(double Perc);//删除孤立点
	void DelIsoAbs(double mAbs);//删除孤立点
	void AdjustVec(float Val[9],float Vec[9],float Vecnew[3][3]);//调整法矢方向
	void PCA();//主成分分析
};
