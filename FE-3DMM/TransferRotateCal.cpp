#include "StdAfx.h"
#include "TransferRotateCal.h"
#include <math.h>

CTransferRotateCal::CTransferRotateCal()
	:m_NinePoint(9)
	,m_NinePointRotate(9)
	,m_RodDisplacement(9)
	,m_bInitFinish(false)
{
}


CTransferRotateCal::~CTransferRotateCal(void)
{
}

CTransferRotateCal::CTransferRotateCal(const CTransferRotateCal& Rotate)
{

}

void CTransferRotateCal::Rotate()
{
	assert(m_bInitFinish);
	CalNormalVector();
	MatrixThree();
	CalNinePoint();
	CalNinePointRotate();
	CalRodDisplacement();
}


/***************************************************************** 
** 函数名称: SetOriginPos
** 输入参数: 输入坐标以工件中心为坐标系，参数1为x坐标，参数2为Y坐标，参数3为旋转的角度（角度制）
** 输出参数: void
** 函数功能: 设定贴装位置（中心位置）
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
void CTransferRotateCal::SetOriginPos(const double& x, const double& y, const double& angle)
{
	m_bInitFinish = true;
	m_PointCenterOrigin.x = x;
	m_PointCenterOrigin.y = y;
	
	//将角度化为弧度制
	m_fPosAngleOrigin = angle / 180 * M_PI;
}



/***************************************************************** 
** 函数名称: TransCoordinate
** 输入参数: Point点
** 输出参数: void
** 函数功能: 将一个点从中心坐标转换到函数坐标系
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
void CTransferRotateCal::TransCoordinate(SurfacePoint & p)
{
	p.x += p.x + 275;
	p.y += p.y + 200;
}


/***************************************************************** 
** 函数名称: CalNormalVector
** 输入参数: void
** 输出参数: bool
** 函数功能: 通过曲面方程（z=23.09 * cos(x/40) * cos(y/40)）计算点的法向矢量
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::CalNormalVector()
{
	double param1 = (m_PointCenterOrigin.x + 275) * 0.025;
	double param2 = (m_PointCenterOrigin.y + 200) * 0.025;
	//计算对应曲面x,y位置z的值
	m_PointCenterOrigin.z = 23.09 * cos(param1) * cos(param2);

	double NormalX, NormalY, NormalZ;
	double a , b, c;
	//指定点的法向矢量
	a = 0.5775 * sin(param1) * cos(param2);
	b = 0.5775 * cos(param1) * sin(param2);
	c = 1;
	//将法向矢量单位化
	NormalX = a / sqrt(a * a + b * b + c * c);
	NormalY = b / sqrt(a * a + b * b + c * c);
	NormalZ = c / sqrt(a * a + b * b + c * c);
	m_Normal.push_back(NormalX);
	m_Normal.push_back(NormalY);
	m_Normal.push_back(NormalZ);

	return true;
}


/***************************************************************** 
** 函数名称: MatrixOne
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 计算旋转角度，采用第一种方法进行旋转，计算其旋转矩阵，先绕Z转，再绕X转，最后再绕Z转相反的角度
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::MatrixOne()
{
	CMatrix Rza(4, 4), Rxb(4, 4), Rz_a(4, 4);
	CMatrix result;
	double sina, cosa, sinb, cosb;
	sina = m_Normal[0] / sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1]);
	cosa = m_Normal[1] / sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1]);
	sinb = sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1]) / sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]);
	cosb = m_Normal[2] / sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]);
	//计算角度值
	m_fRotateAngleA = (asin(sina) / M_PI) * 180;
	m_fRotateAngleB = (asin(sinb) / M_PI) * 180;
	//给矩阵赋值
	Rza[0][0] = cosa;
	Rza[0][1] = sina;
	Rza[0][2] = 0;
	Rza[0][3] = 0;

	Rza[1][0] = -sina;
	Rza[1][1] = cosa;
	Rza[1][2] = 0;
	Rza[1][3] = 0;

	Rza[2][0] = 0;
	Rza[2][1] = 0;
	Rza[2][2] = 1;
	Rza[2][3] = 0;

	Rza[3][0] = 0;
	Rza[3][1] = 0;
	Rza[3][2] = 0;
	Rza[3][3] = 1;

	/*****************************************************************/
	Rxb[0][0] = 1;
	Rxb[0][1] = 0;
	Rxb[0][2] = 0;
	Rxb[0][3] = 0;

	Rxb[1][0] = 0;
	Rxb[1][1] = cosb;
	Rxb[1][2] = sinb;
	Rxb[1][3] = 0;

	Rxb[2][0] = 0;
	Rxb[2][1] = -sinb;
	Rxb[2][2] = cosb;
	Rxb[2][3] = 0;

	Rxb[3][0] = 0;
	Rxb[3][1] = 0;
	Rxb[3][2] = 0;
	Rxb[3][3] = 1;
	/************************************************************************/
	Rz_a[0][0] = cosa;
	Rz_a[0][1] = -sina;
	Rz_a[0][2] = 0;
	Rz_a[0][3] = 0;

	Rz_a[1][0] = sina;
	Rz_a[1][1] = cosa;
	Rz_a[1][2] = 0;
	Rz_a[1][3] = 0;

	Rz_a[2][0] = 0;
	Rz_a[2][1] = 0;
	Rz_a[2][2] = 1;
	Rz_a[2][3] = 0;

	Rz_a[3][0] = 0;
	Rz_a[3][1] = 0;
	Rz_a[3][2] = 0;
	Rz_a[3][3] = 1;

	//计算矩阵
	result = Rza * Rxb;
	m_Matrix = result;
	return true;
}

/***************************************************************** 
** 函数名称: MatrixThree
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 采用第三种方法进行旋转，计算其旋转矩阵，先绕X转，再绕Y转
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::MatrixThree()
{
	CMatrix Rxa(4, 4), Ryb(4, 4);
	CMatrix result;
	double sina, cosa, sinb, cosb;
	sina = m_Normal[1] / sqrt(m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]);
	cosa = m_Normal[2] / sqrt(m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]);
	cosb = sqrt(m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]) / sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]);
	sinb = m_Normal[0] / sqrt(m_Normal[0] * m_Normal[0] + m_Normal[1] * m_Normal[1] + m_Normal[2] * m_Normal[2]);
	//计算角度值
	m_fRotateAngleA = (asin(sina) / M_PI) * 180;
	m_fRotateAngleB = (asin(sinb) / M_PI) * 180;
	//给矩阵赋值
	Rxa[0][0] = 1;
	Rxa[0][1] = 0;
	Rxa[0][2] = 0;
	Rxa[0][3] = 0;

	Rxa[1][0] = 0;
	Rxa[1][1] = cosa;
	Rxa[1][2] = sina;
	Rxa[1][3] = 0;

	Rxa[2][0] = 0;
	Rxa[2][1] = -sina;
	Rxa[2][2] = cosa;
	Rxa[2][3] = 0;

	Rxa[3][0] = 0;
	Rxa[3][1] = 0;
	Rxa[3][2] = 0;
	Rxa[3][3] = 1;

	/*****************************************************************/
	Ryb[0][0] = cosb;
	Ryb[0][1] = 0;
	Ryb[0][2] = sinb;
	Ryb[0][3] = 0;

	Ryb[1][0] = 0;
	Ryb[1][1] = 1;
	Ryb[1][2] = 0;
	Ryb[1][3] = 0;

	Ryb[2][0] = -sinb;
	Ryb[2][1] = 0;
	Ryb[2][2] = cosb;
	Ryb[2][3] = 0;

	Ryb[3][0] = 0;
	Ryb[3][1] = 0;
	Ryb[3][2] = 0;
	Ryb[3][3] = 1;


	//计算矩阵
	result = Rxa*Ryb;
	m_Matrix = result;
	return true;
}

/***************************************************************** 
** 函数名称: CalRotateVector
** 输入参数: 无
** 输出参数: bool值，是否成功
** 函数功能: 计算旋转后的矢量，得到机械手中心旋转后的位置
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::CalRotateVector()
{
	CMatrix vec(1, 4);
	vec[0][0] = m_Normal[0];
	vec[0][1] = m_Normal[1];
	vec[0][2] = m_Normal[2];
	vec[0][3] = 1;
	CMatrix RotateVec(4, 1);
	RotateVec = vec * m_Matrix;
	//确认值的正确性
	if (abs(RotateVec[0][0]) < MIN && abs(RotateVec[0][1]) < MIN && abs(RotateVec[0][2] - 1.0) < MIN)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/***************************************************************** 
** 函数名称: CalNinePoint
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 计算旋转前九个点坐标
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::CalNinePoint()
{
	SurfacePoint TmpPoint;
	/*点11*/
	TmpPoint.x = m_PointCenterOrigin.x - sqrt(2.0) * DIS * sin(M_PI / 4 + m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y + sqrt(2.0) * DIS * cos(M_PI / 4 + m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点12*/
	TmpPoint.x = m_PointCenterOrigin.x - DIS * sin(m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y + DIS * cos(m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点13*/
	TmpPoint.x = m_PointCenterOrigin.x + sqrt(2.0) * DIS * sin(M_PI / 4 - m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y + sqrt(2.0) * DIS * cos(M_PI / 4 - m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点21*/
	TmpPoint.x = m_PointCenterOrigin.x - DIS * cos(m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y - DIS * sin(m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点22*/
	TmpPoint.x = m_PointCenterOrigin.x;
	TmpPoint.y = m_PointCenterOrigin.y;
	TmpPoint.z = m_PointCenterOrigin.z;
	m_NinePoint.push_back(TmpPoint);

	/*点23*/
	TmpPoint.x = m_PointCenterOrigin.x - DIS * sin(M_PI / 4 - m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y + DIS * cos(M_PI / 4 - m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点31*/
	TmpPoint.x = m_PointCenterOrigin.x - sqrt(2.0) * DIS * sin(M_PI / 4 - m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y - sqrt(2.0) * DIS * cos(M_PI / 4 - m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点32*/
	TmpPoint.x = m_PointCenterOrigin.x + DIS * sin(m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y - DIS * cos(m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);

	/*点33*/
	TmpPoint.x = m_PointCenterOrigin.x + sqrt(2.0) * DIS * sin(M_PI / 4 + m_fPosAngleOrigin);
	TmpPoint.y = m_PointCenterOrigin.y - sqrt(2.0) * DIS * cos(M_PI / 4 + m_fPosAngleOrigin);
	TmpPoint.z = 23.09 * cos((TmpPoint.x + 275) / 40) * cos((TmpPoint.y + 200) / 40);
	m_NinePoint.push_back(TmpPoint);
	return TRUE;
}



/***************************************************************** 
** 函数名称: CalNinePointRotate
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 计算旋转后九个点坐标
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::CalNinePointRotate()
{
	//定义两个1行4列的矩阵
	CMatrix tmpVector(1, 4);
	CMatrix resultVector(1, 4);

	SurfacePoint tmpPoint;
	for (int i = 0; i < 9; ++i)
	{
		tmpVector[0][0] = m_NinePoint[i].x;
		tmpVector[0][1] = m_NinePoint[i].y;
		tmpVector[0][2] = m_NinePoint[i].z;
		tmpVector[0][3] = 1;
		resultVector = tmpVector * m_Matrix;
		tmpPoint.x = resultVector[0][0];
		tmpPoint.y = resultVector[0][1];
		tmpPoint.z = resultVector[0][2];
		m_NinePointRotate.push_back(tmpPoint);
	}

	return TRUE;
}


/***************************************************************** 
** 函数名称: CalRodDisplacement
** 输入参数: 无
** 输出:	     是否成功
** 函数功能: 计算九根推杆的位移
** 创建人:	 刘腾
** Version:1.0
*****************************************************************/
bool CTransferRotateCal::CalRodDisplacement()
{
	int MaxIndex(0);
	double MaxZ(0.0);
	//找到九个点中Z最大的推杆
	for (auto beg = m_NinePointRotate.begin(); beg != m_NinePointRotate.end(); ++beg)
	{
		if (m_NinePointRotate[0].z > MaxZ)
		{
			MaxZ = (*beg).z;
		}
		else
		{
			++MaxIndex;
		}
	}
	//计算每根推杆的位置
	double Diff;
	for (auto beg = m_NinePointRotate.begin(); beg != m_NinePointRotate.end(); ++beg)
	{
		Diff = MaxZ - (*beg).z;
		m_RodDisplacement.push_back(Diff);
	}
	return TRUE;
}


