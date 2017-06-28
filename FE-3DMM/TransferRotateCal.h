#pragma once
#include "TransferMatrix.h"
#include "ParamData.h"

const double MIN =  0.00001;
const int DIS = 25;   //推杆之间的距离（mm）

typedef struct st_Point
{
public:
	double x;
	double y;
	double z;

	st_Point(double a = 0, double b = 0, double c = 0)
		:x(a), y(b), z(c){}
}SurfacePoint;

class CTransferRotateCal
{
public:
	CTransferRotateCal();
	~CTransferRotateCal(void);

	void Rotate();



	/*
	** @input: 输入坐标以工件中心为坐标系，参数1为x坐标，参数2为Y坐标，参数3为旋转的角度（角度制）
	** @output: void
	** @function: 设定贴装位置中心
	*/
	void SetOriginPos(const double&, const double&, const double &);


	/*
	** @input: 坐标
	** @function: 将以工件中心为原点的坐标系，转换到建立方程的坐标系
	*/
	void TransCoordinate(SurfacePoint & p);


	/*
	** @input: void
	** @output: const std::vector<double>&九根推杆的位移
	** @function: 返回九根推杆的位移
	*/
	inline const std::vector<double>& CTransferRotateCal::GetRodDisplacement() const
	{ 
		return m_RodDisplacement; 
	}

	inline double GetRotateAngleA() const {return m_fRotateAngleA;}

	inline double GetRotateAngleB() const {return m_fRotateAngleB;}


private:
	/*
	** @计算指定曲面点的法向量
	*/
	bool CalNormalVector();    


	bool MatrixOne();                    //计算第一种解法的旋转矩阵
	bool MatrixThree();                 //计算第三种解法的旋转矩阵
	bool CalRotateVector();
	bool CalNinePoint();               //计算九个点旋转前的坐标
	bool CalNinePointRotate();   //计算九个点旋转后的坐标
	bool CalRodDisplacement();                  //计算推杆位移



	//private members
private:
	//贴装点的初始位置
	SurfacePoint m_PointCenterOrigin;
	double m_fPosAngleOrigin;

	//贴装点旋转后的位置
	SurfacePoint m_PointCenterPlace;

	double m_fRotateAngleA;         //工件第一次旋转的角度
	double m_fRotateAngleB;          //工件第二次旋转的角度

	std::vector<double> m_Normal;                     //法向矢量
	std::vector<SurfacePoint> m_NinePoint;                    //九个点旋转前的坐标
	std::vector<SurfacePoint> m_NinePointRotate;        //九个点旋转后的坐标
	std::vector<double> m_RodDisplacement;  //推杆位移
	CMatrix m_Matrix;    //旋转矩阵
	
	bool m_bInitFinish;   //是否设定初始值标志量
	CParamData* m_pParamData;
private:
	//拷贝构造函数
	CTransferRotateCal(const CTransferRotateCal&);    //不实现，阻止拷贝
};

