#pragma once
#include "HalconCpp.h"
using namespace HalconCpp;
#include "opencv2\opencv.hpp"
using namespace cv;

enum CameraType{LASER_VIEW=0, TRANS_DOWN, TRANS_UP, 
	PRINT_LOCAL, PRINT_HORIZONTAL, PRINT_ASKANT};   //相机类型

enum MatchMode{NCC=0, Shape};   //匹配模式

enum CalibPtNumIndex{Three = 0, Four, Five, Six};   //标定点数索引: Three:3*3, Four:4*4, Five:5*5, Six:6*6

typedef struct st_LocRes
{
	bool		 bSuccess;			
	double	 dXPos;
	double	 dYPos;
	double	 dAngle;
	st_LocRes()
	{
		bSuccess = false;
		dXPos = 0.0;
		dYPos = 0.0;
		dAngle = 0.0;
	}
}LocRes;


class CImageOperate
{
public:
	CImageOperate(void);
	~CImageOperate(void);

	void Init(const CameraType &camtype, const int &nImgWid, const int &nImgHei);	//初始化							
	IplImage* HObject2IplImage(HObject &hobj);					//HObject->IplImage

	bool CreateModel(const HObject *phoImg, const CRect &rcRoi, const CString& strModelName = "NULL");	// 创建模板
	bool LoadModel();																	//加载模板
	
	void SetMatchMode(const MatchMode &mode);			//设置匹配模式
	void SetMatchRange(const CRect &rcRoi);						//设置匹配范围
	void GenMatchRoiImg(const HObject *phoImg);				//生成待匹配Roi图像
	bool Match();																			//模板匹配
	LocRes GetMatchRes();															//获得匹配结果
	bool Calibrate(const CRect &rcRoi, const float &fBlackPtCenDis, const float &fBlackPtDiameter,
		const CalibPtNumIndex &enumPtIndex, float &fPixelWid, float &fPixelHei);				//相机标定

private:
	double Degree2Rad(float degree){
			return degree*3.14159265/180.0;
	}
	void SetCameraType(const CameraType &camtype);		//设置相机类型
	bool SaveModel(const CString& strModelName = "NULL");																	//存储模板

private:
	int									m_nImgWidth;									//图像宽
	int									m_nImgHeight;								//图像高
	IplImage							*m_pGrayImg;									//采集图像

	CString							m_strModelPath;								//模板路径
	CameraType					m_enumCamType;							//相机类型
	MatchMode					m_enumMatchMode;						//匹配模式
	HTuple							m_hvModelID;									//模板
	CRect								m_rcMatchRoi;									//待匹配Roi
	HObject							m_hoMatchRoiImg;							//待匹配Roi图像
	LocRes							m_stLocRes;										//定位结果
};

