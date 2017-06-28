#pragma once
#include "ParamDefine.h"

class CParamData
{
public:
	CParamData(void);
	~CParamData(void);

	Param3DMeasure* GetParam3DMeasure();		
	ParamLaserStrip* GetParamLaserStrip();			
	ParamTransfer* GetParamTransfer();				
	ParamPrint* GetParamPrint();							
	ParamCamera* GetParamCamera();

	CString ReadParam(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpFileName,int paramtype,void *param);		//读取参数
	void WriteParam(LPCSTR lpAppName, LPCSTR lpKeyName , LPCSTR lpFileName,int paramtype,void *param);			//写参数

	CString LoadMeasurePa();
	CString SaveMeasurePa();

	CString LoadLaserStripPa();
	CString SaveLaserStripPa();

	CString LoadTransferPa();
	CString SaveTransferPa();
	CString LoadTransferPa(int TransferType, int PISize);  //重载函数，根据转印方式和，PI尺寸加载数据
	CString SaveTransferPa(int TransferType, int PISize);  

	CString LoadPrintPa();
	CString SavePrintPa();

	CString LoadCameraPa();
	CString SaveCameraPa();

private:
	CString							m_strConfigPath;		
	Param3DMeasure		m_param3DMeasure;				//3D测量配置参数
	ParamLaserStrip			m_paramLaserStrip;				//激光剥离配置参数
	ParamTransfer				m_paramTransfer;					//转印配置参数
	ParamPrint						m_paramPrint;							//打印配置参数
	ParamCamera				m_paramCamera;						//相机配置参数
};

