#pragma once


typedef struct st_Param3DMeasure
{

}Param3DMeasure;


typedef struct st_ParamLaserStrip
{

}ParamLaserStrip;


typedef struct st_ParamPrint
{

}ParamPrint;



/************************************************************************/
/* 转印部分数据结构定义
/************************************************************************/

//转印方式，主动和被动
enum enum_TransferType { INITIATIVE = 0, PASSITIVITY };

//转印对象尺寸
enum enum_TransferObjectSize{SIZE11 = 0,  SIZE22, SIZE33, SIZE44, SIZE55, SIZE66};

typedef struct st_ParamTransfer
{
	//转印对象
	struct TRANSFER_OBJECT
	{
		enum_TransferObjectSize      iSize;                         //器件大小
		double                                       fXToCenter;             //mark点距对象中心x距离
		double                                       fYToCenter;              //mark点距对象中心Y距离
	};

	//九个直线推杆的位移
	struct PUSH_ROD
	{
		double fRod11;
		double fRod12;
		double fRod13;
		double fRod21;
		double fRod22;
		double fRod23;
		double fRod31;
		double fRod32;
		double fRod33;
	};

	//贴装位置
	struct TRANSFER_POSITION
	{
		double fPosX;    //x坐标
		double fPosY;     //y坐标
		double fPosA;    //偏转角度，取逆时针为正方向
	};


	/*******************************************参数****************************************/
	
	//实验设定的参数，无须保存
	enum_TransferType           TransferType;           //转印方式，主动或被动
	enum_TransferObjectSize TransferSize;             //转印对象尺寸
	TRANSFER_OBJECT            iPlaceObject;            //转印对象
	TRANSFER_POSITION        iPlacePos;                  //转印位置


	//主动和被动都需要固定学习的参数，需要写入文件
	double fXPosPickCamera;               //转印相机观察PI位置X
	double fZPosPickCamera;               //转印相机观察PI位置Z

	double fXPosPickPicker;                 //拾取PI时机械手位置X
	double fZPosPickPicker;                 //拾取PI时机械手位置Z

	double fXPosPlaceCamera;                //上视相机观测机械手位置X
	double fZPosPlaceCamera;                //上视相机观测机械手位置Z

	double fXPosViewFourAxle;              //上视相机观测四轴位置X
	double fYPosViewFourAxle;              //上视相机观测四轴位置Y

	double fXPosPlacePicker;                  //贴装PI时机械手X轴学习位置
	double fZPosPlacePicker;                   //贴装PI时机械手Z轴学习位置

	//标定的参数，写入另一个独立的APPname中
	double fDisPickerCamX;                      //机械手中心与下视相机中心X偏差
	double fDisPickerCamY;                      //机械手中心与下视相机中心Y偏差

	double fPickerToSurfaceCenterX;    //机械手中心对准曲面中心时，四轴X的位置
	double fPickerToSurfaceCenterY;     //机械手中心对准曲面中心时，四轴Y的位置

	float fDownPixelWidth;                   //转印下视相机一个像素的实际物理宽度
	float fDownPixelHeight;                  //转印下视相机一个像素的实际物理高度
	float fUpPixelWidth;                        //转印下视相机一个像素的实际物理宽度
	float fUpPixelHeight;                      //转印下视相机一个像素的实际物理高度


/********************主动变形方案独有的参数*************************/
	
	double fZPosAfterPicker;                 //机械手将膜拾取后，回到一个固定高度
	double fZPosAfterSurfaceLoc;        //上视相机定位后，机械手回到一个固定高度
	
	//PUSH_ROD RodInit;                        //机械手初始时，推杆位置

	/*计算值，无需保存*/
	PUSH_ROD RodStransform;                 //曲面变形时，推杆的位置
	double fXPosPlaceFourAxle;               //贴装PI时四轴X位置，中心点坐标
	double fYPosPlaceFourAxle;               //贴装PI时四轴Y位置
	double fAPosPlaceFourAxle;              //贴装PI时A旋转自由度位置
	double fBPosPlaceFourAxle;               //贴装PI时B旋转自由度位置

	//double fPositivePressure;         //正压大小
	//double fNegativePressure;      //负压大小
/************************************************************************************************/


/***********************************被动变形方案独有参数***************************************/
	double fStaticV;                         //静电电压大小
	double fStaticF;                          //静电电压频率

/***********************************************************************************************/


	//下视相机定位结果
	double fXOffsetPick;                       //拾取PI时X轴补偿值
	double fYOffsetPick;
	double fAngleOffsetPick;

	//上视相机定位结果
	double fXOffsetPlace;               //上视相机定位误差X
	double fYOffsetPlace;               //上视相机定位误差Y
	double fAngleOffsetPlace;       //上视相机定位误差角度

	//从界面读取参数
	double fFullSpeed;                     //整机速度
	double fZSpeed;                         //Z轴速度

}ParamTransfer;


typedef struct st_ParamCamera
{
	CString		strCamNameLaser;						//激光剥离相机名
	CString		strCamNameTransUp;					//转印上视相机名
	CString		strCamNameTransDown;			//转印下视相机名
	CString		strCamNamePrintLoc;					//打印定位相机名
	CString		strCamNamePrintHoriz;				//打印平视相机名
	CString		strCamNamePrintAskant;			//打印斜视相机名
}ParamCamera;