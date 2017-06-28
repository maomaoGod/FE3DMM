#include "StdAfx.h"
#include "ParamData.h"

#define P_INT 0
#define P_FLOAT 1
#define P_LONG 2
#define P_BOOL 3
#define P_STR 4

CParamData::CParamData(void)
{
	m_strConfigPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1) + "Storage\\Config\\";
}


CParamData::~CParamData(void)
{
}


Param3DMeasure* CParamData::GetParam3DMeasure()
{
	return &m_param3DMeasure;
}


ParamLaserStrip* CParamData::GetParamLaserStrip()
{
	return &m_paramLaserStrip;
}


ParamTransfer* CParamData::GetParamTransfer()
{
	return &m_paramTransfer;
}


ParamPrint* CParamData::GetParamPrint()
{
	return &m_paramPrint;
}


ParamCamera* CParamData::GetParamCamera()
{
	return &m_paramCamera;
}


//读取参数
CString CParamData::ReadParam(LPCSTR lpAppName, LPCSTR lpKeyName, LPCSTR lpFileName,int paramtype,void *param)
{
	char strValue[256];
	memset(strValue, 0, 256);
	GetPrivateProfileString(lpAppName, lpKeyName, "READ_FAIL", strValue, 256, lpFileName);

	if (strcmp(strValue, "READ_FAIL") == 0)
	{
		return "read param fail";
	}

	switch(paramtype) {
	case 0: //int  类型
		*(int *)param = atoi(strValue);
		break;
	case 1: //float  类型
		*(float *)param = (float)(atof(strValue));
		break;
	case 2: //long  类型		
		*(long *)param = atol(strValue);
		break;
	case 3: //bool  类型
		*(int *)param = atoi(strValue);
		break;
	case 4: //cstring  类型
		*(CString *)param = strValue;
		break;
	default:
		break;
	}

	return strValue;
}

//写参数		
void CParamData::WriteParam(LPCSTR lpAppName, LPCSTR lpKeyName , LPCSTR lpFileName,int paramtype,void *param)	
{
	CString strValue;

	switch(paramtype) {
	case 0: //int  类型
		strValue.Format("%d", *(int *)param);
		break;
	case 1: //float  类型
		strValue.Format("%f", *(float *)param);
		break;
	case 2: //long  类型		
		strValue.Format("%ld", *(long *)param);
		break;
	case 3: //bool  类型
		strValue.Format("%d", *(bool *)param);
		break;
	case 4: //cstring  类型
		strValue.Format("%s", *(CString *)param);
		break;
	default:
		break;
	}
	WritePrivateProfileString(lpAppName, lpKeyName, strValue, lpFileName);
}

CString CParamData::LoadMeasurePa()
{
	CString strFileName = m_strConfigPath + "3DMeasure" ;
	CString strRe = "";
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现3DMeasure参数文件";
	}
// 	strRe += ReadParam("measure","antennaname",strFileName,P_STR, &(m_param3DMeasure.antennaname) );
// 	strRe += ReadParam("measure","processRowNumber",strFileName,P_INT, &(m_param3DMeasure.processRowNumber) );
// 	strRe += ReadParam("measure","processColNumber",strFileName,P_INT, &(m_param3DMeasure.processColNumber) );
// 	strRe += ReadParam("measure","antennaRowDis",strFileName,P_FLOAT, &(m_param3DMeasure.antennaRowDis) );

	return strRe;
}

CString CParamData::SaveMeasurePa()
{
	CString strFileName = m_strConfigPath + "3DMeasure" ;
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现3DMeasure参数文件";
	}
// 	WriteParam("measure","antennaname",strFileName,P_STR, &(m_param3DMeasure.antennaname) );
// 	WriteParam("measure","processRowNumber",strFileName,P_INT, &(m_param3DMeasure.processRowNumber) );
// 	WriteParam("measure","processColNumber",strFileName,P_INT, &(m_param3DMeasure.processColNumber) );
// 	WriteParam("measure","antennaRowDis",strFileName,P_FLOAT, &(m_param3DMeasure.antennaRowDis) );

	return "";
}

CString CParamData::LoadLaserStripPa()
{
	CString strFileName = m_strConfigPath + "LaserStrip" ;
	CString strRe = "";
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现LaserStrip参数文件";
	}
	// 	strRe += ReadParam("laserstrip","antennaname",strFileName,P_STR, &(m_paramLaserStrip.antennaname) );
	// 	strRe += ReadParam("laserstrip","processRowNumber",strFileName,P_INT, &(m_paramLaserStrip.processRowNumber) );
	// 	strRe += ReadParam("laserstrip","processColNumber",strFileName,P_INT, &(m_paramLaserStrip.processColNumber) );
	// 	strRe += ReadParam("laserstrip","antennaRowDis",strFileName,P_FLOAT, &(m_paramLaserStrip.antennaRowDis) );

	return strRe;
}

CString CParamData::SaveLaserStripPa()
{
	CString strFileName = m_strConfigPath + "LaserStrip" ;
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现LaserStrip参数文件";
	}
	// 	WriteParam("laserstrip","antennaname",strFileName,P_STR, &(m_paramLaserStrip.antennaname) );
	// 	WriteParam("laserstrip","processRowNumber",strFileName,P_INT, &(m_paramLaserStrip.processRowNumber) );
	// 	WriteParam("laserstrip","processColNumber",strFileName,P_INT, &(m_paramLaserStrip.processColNumber) );
	// 	WriteParam("laserstrip","antennaRowDis",strFileName,P_FLOAT, &(m_paramLaserStrip.antennaRowDis) );

	return "";
}

/* 重载了有参数版本和无参数版本，有参数版本需要对于特定的转印方式和PI大小来加载数据，
** 无参数版本用于加载默认的参数，具体加载内容暂时还没有*/
CString CParamData::LoadTransferPa()
{
	return "";
}

CString CParamData::LoadTransferPa(int TransferType, int PISize)
{
	CString strAppName("Transfer");
	switch(TransferType)
	{
	case  INITIATIVE:
		strAppName += "_Initiative";
		break;
	case PASSITIVITY:
		strAppName += "_Passitivity";
		break;
	}

	switch (PISize)
	{
	case SIZE11:
		strAppName += "_1_1";
		break;
	case SIZE22:
		strAppName += "_2_2";
		break;
	case SIZE33:
		strAppName += "_3_3";
		break;
	case SIZE44:
		strAppName += "_4_4";
		break;
	case SIZE55:
		strAppName += "_5_5";
		break;
	case SIZE66:
		strAppName += "_6_6";
		break;
	}

	CString strFileName = m_strConfigPath + "Transfer" ;
	CString strRe = "";
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Transfer参数文件";
	}

	//读取配置文件
	strRe += ReadParam(strAppName,"fXPosPickCamera",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPickCamera) );
	strRe += ReadParam(strAppName,"fZPosPickCamera",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPickCamera) );
	
	strRe += ReadParam(strAppName,"fXPosPickPicker",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPickPicker) );
	strRe += ReadParam(strAppName,"fZPosPickPicker",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPickPicker) );

	strRe += ReadParam(strAppName,"fXPosPlaceCamera",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPlaceCamera) );
	strRe += ReadParam(strAppName,"fZPosPlaceCamera",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPlaceCamera) );

	strRe += ReadParam(strAppName,"fXPosViewFourAxle",strFileName,P_FLOAT, &(m_paramTransfer.fXPosViewFourAxle) );
	strRe += ReadParam(strAppName,"fYPosViewFourAxle",strFileName,P_FLOAT, &(m_paramTransfer.fYPosViewFourAxle) );

	strRe += ReadParam(strAppName,"fXPosPlacePicker",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPlacePicker) );
	strRe += ReadParam(strAppName,"fZPosPlacePicker",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPlacePicker) );
	
	//读取标定参数
	strAppName = "COORD_CALIB";
	strRe += ReadParam(strAppName,"fDisPickerCamX",strFileName,P_FLOAT, &(m_paramTransfer.fDisPickerCamX) );
	strRe += ReadParam(strAppName,"fDisPickerCamY",strFileName,P_FLOAT, &(m_paramTransfer.fDisPickerCamY) );
	strRe += ReadParam(strAppName,"fPickerToSurfaceCenterX",strFileName,P_FLOAT, &(m_paramTransfer.fPickerToSurfaceCenterX) );
	strRe += ReadParam(strAppName,"fPickerToSurfaceCenterY",strFileName,P_FLOAT, &(m_paramTransfer.fPickerToSurfaceCenterY) );
	
	return strRe;
}

//写入标定参数
CString CParamData::SaveTransferPa()
{
	CString strFileName = m_strConfigPath + "Transfer" ;
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Transfer参数文件";
	}

	CString strAppName = "COORD_CALIB";
	WriteParam(strAppName,"fDisPickerCamX",strFileName,P_FLOAT, &(m_paramTransfer.fDisPickerCamX) );
	WriteParam(strAppName,"fDisPickerCamY",strFileName,P_FLOAT, &(m_paramTransfer.fDisPickerCamY) );
	WriteParam(strAppName,"fPickerToSurfaceCenterX",strFileName,P_FLOAT, &(m_paramTransfer.fPickerToSurfaceCenterX) );
	WriteParam(strAppName,"fPickerToSurfaceCenterY",strFileName,P_FLOAT, &(m_paramTransfer.fPickerToSurfaceCenterY) );
	WriteParam(strAppName,"fDownPixelWidth",strFileName,P_FLOAT, &(m_paramTransfer.fDownPixelWidth) );
	WriteParam(strAppName,"fDownPixelHeight",strFileName,P_FLOAT, &(m_paramTransfer.fDownPixelHeight) );
	WriteParam(strAppName,"fUpPixelWidth",strFileName,P_FLOAT, &(m_paramTransfer.fUpPixelWidth) );
	WriteParam(strAppName,"fUpPixelHeight",strFileName,P_FLOAT, &(m_paramTransfer.fUpPixelHeight) );
	return "";
}

CString CParamData::SaveTransferPa(int TransferType, int PISize)
{
	/* 根据PI的尺寸不同选择不同的lpAppName，这里保存的参数是对于同一尺寸的PI是不变的，只需要一次学习即可
	** 使用APPName来保存不同类型的参数，加载时也选择对应的*/
	CString strAppName("Transfer");
	switch(TransferType)
	{
	case  INITIATIVE:
		strAppName += "_Initiative";
		break;
	case PASSITIVITY:
		strAppName += "_Passitivity";
		break;
	}

	switch (PISize)
	{
	case SIZE11:
		strAppName += "_1_1";
		break;
	case SIZE22:
		strAppName += "_2_2";
		break;
	case SIZE33:
		strAppName += "_3_3";
		break;
	case SIZE44:
		strAppName += "_4_4";
		break;
	case SIZE55:
		strAppName += "_5_5";
		break;
	case SIZE66:
		strAppName += "_6_6";
		break;
	}

	CString strFileName = m_strConfigPath + "Transfer" ;
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Transfer参数文件";
	}

	if (TransferType == INITIATIVE)
	{
		WriteParam(strAppName,"fXPosPickCamera",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPickCamera) );
		WriteParam(strAppName,"fZPosPickCamera",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPickCamera) );
		
		WriteParam(strAppName,"fXPosPickPicker",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPickPicker) );
		WriteParam(strAppName,"fZPosPickPicker",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPickPicker) );

		WriteParam(strAppName,"fXPosPlaceCamera",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPlaceCamera) );
		WriteParam(strAppName,"fZPosPlaceCamera",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPlaceCamera) );

		WriteParam(strAppName,"fXPosViewFourAxle",strFileName,P_FLOAT, &(m_paramTransfer.fXPosViewFourAxle) );
		WriteParam(strAppName,"fYPosViewFourAxle",strFileName,P_FLOAT, &(m_paramTransfer.fYPosViewFourAxle) );

		WriteParam(strAppName,"fXPosPlacePicker",strFileName,P_FLOAT, &(m_paramTransfer.fXPosPlacePicker) );
		WriteParam(strAppName,"fZPosPlacePicker",strFileName,P_FLOAT, &(m_paramTransfer.fZPosPlacePicker) );
	}
	else if (TransferType == PASSITIVITY)
	{
		//被动转印需要的参数
	}
	return "";
}

CString CParamData::LoadPrintPa()
{
	CString strFileName = m_strConfigPath + "Print" ;
	CString strRe = "";
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Print参数文件";
	}
	// 	strRe += ReadParam("print","antennaname",strFileName,P_STR, &(m_paramPrint.antennaname) );
	// 	strRe += ReadParam("print","processRowNumber",strFileName,P_INT, &(m_paramPrint.processRowNumber) );
	// 	strRe += ReadParam("print","processColNumber",strFileName,P_INT, &(m_paramPrint.processColNumber) );
	// 	strRe += ReadParam("print","antennaRowDis",strFileName,P_FLOAT, &(m_paramPrint.antennaRowDis) );

	return strRe;
}

CString CParamData::SavePrintPa()
{
	CString strFileName = m_strConfigPath + "Print" ;
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Print参数文件";
	}
	// 	WriteParam("print","antennaname",strFileName,P_STR, &(m_paramPrint.antennaname) );
	// 	WriteParam("print","processRowNumber",strFileName,P_INT, &(m_paramPrint.processRowNumber) );
	// 	WriteParam("print","processColNumber",strFileName,P_INT, &(m_paramPrint.processColNumber) );
	// 	WriteParam("print","antennaRowDis",strFileName,P_FLOAT, &(m_paramPrint.antennaRowDis) );

	return "";
}

CString CParamData::LoadCameraPa()
{
	CString strFileName = m_strConfigPath + "Camera" ;
	CString strRe = "";
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Camera参数文件";
	}
	strRe += ReadParam("camera","laserCamName",strFileName,P_STR, &(m_paramCamera.strCamNameLaser) );
	strRe += ReadParam("camera","transUpCamName",strFileName,P_STR, &(m_paramCamera.strCamNameTransUp) );
	strRe += ReadParam("camera","transDownCamName",strFileName,P_STR, &(m_paramCamera.strCamNameTransDown) );
	strRe += ReadParam("camera","printLocCamName",strFileName,P_STR, &(m_paramCamera.strCamNamePrintLoc) );
	strRe += ReadParam("camera","printHorizCamName",strFileName,P_STR, &(m_paramCamera.strCamNamePrintHoriz) );
	strRe += ReadParam("camera","printAskantCamName",strFileName,P_STR, &(m_paramCamera.strCamNamePrintAskant) );

	return strRe;
}

CString CParamData::SaveCameraPa()
{
	CString strFileName = m_strConfigPath + "Camera" ;
	CFileFind fileFind;
	if (!fileFind.FindFile(strFileName))
	{
		return "未发现Camera参数文件";
	}

	return "";
}