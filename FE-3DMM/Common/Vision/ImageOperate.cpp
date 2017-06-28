#include "StdAfx.h"
#include "ImageOperate.h"


CImageOperate::CImageOperate(void)
{
	m_nImgWidth					= 0;
	m_nImgHeight					= 0;
	m_pGrayImg						= NULL;
	m_enumMatchMode		= NCC;
}


CImageOperate::~CImageOperate(void)
{
	cvReleaseImage(&m_pGrayImg);
}


void CImageOperate::Init(const CameraType &camtype, const int &nImgWid, const int &nImgHei)
{
	m_strModelPath = m_gAppExePath.Left(m_gAppExePath.ReverseFind('\\')+1) + "Storage\\Model\\";
	SetCameraType(camtype);

	m_nImgWidth = nImgWid;
	m_nImgHeight = nImgHei;
	m_pGrayImg = cvCreateImage(cvSize(nImgWid, nImgHei), IPL_DEPTH_8U, 1);
	memset(m_pGrayImg->imageData, 0, nImgWid*nImgHei*sizeof(BYTE));
}


IplImage* CImageOperate::HObject2IplImage(HObject &hobj)
{
	if (false == hobj.IsInitialized())
	{
		return NULL;
	}

	HTuple htChannels;
	ConvertImageType(hobj, &hobj, "byte");	 //转换图像格式
	CountChannels(hobj, &htChannels);
	if (htChannels[0].I() == 1)
	{
		HTuple hvPoint, hvType, hvImgWid, hvImgHei;
	
		GetImagePointer1(hobj, &hvPoint, &hvType, &hvImgWid, &hvImgHei);
		int nOrgWid = hvImgWid[0].I();
		int nOrgHei = hvImgHei[0].I();
		BYTE* ptr = (BYTE*)hvPoint[0].L();

		int nTempWid = min(nOrgWid, m_nImgWidth);
		int nTempHei = min(nOrgHei, m_nImgHeight);
		for (int i = 0; i < nTempHei; i++)
		{
			memcpy(m_pGrayImg->imageData+m_pGrayImg->widthStep*i, ptr+hvImgWid*i, nTempWid);
		}

		return m_pGrayImg;
	}

	return NULL;
}


void CImageOperate::SetCameraType(const CameraType &camtype)
{
	m_enumCamType = camtype;
}


void CImageOperate::SetMatchMode(const MatchMode &mode)
{
	m_enumMatchMode = mode;
}


bool CImageOperate::CreateModel(const HObject *phoImg, const CRect &rcRoi, const CString& strModelName)
{
	if (NULL == phoImg || false == phoImg->IsInitialized())
	{
		return false;
	}

	HObject hoROI, hoReduce;
	GenRectangle1(&hoROI, rcRoi.top, rcRoi.left, rcRoi.bottom, rcRoi.right);
	HTuple hlNum;
	CountObj(hoROI, &hlNum);
	if (hlNum < 1)
	{
		AfxMessageBox("Model Region wasnot created!");
		return false;
	}

	ReduceDomain(*phoImg, hoROI, &hoReduce);

	HObject hoImagePart;
	CropDomain(hoReduce, &hoImagePart);
	WriteImage(hoImagePart, "bmp", 0, (HTuple)(m_strModelPath+strModelName));	

	switch(m_enumMatchMode)
	{
	case NCC:
		try
		{
			CreateNccModel(hoReduce, "auto", Degree2Rad(-30), Degree2Rad(60),
				"auto", "use_polarity", &m_hvModelID);
		}
		catch(HalconCpp::HException e)
		{
			return false;
		}
		break;

	case Shape:
		try
		{
			CreateShapeModel(hoReduce, "auto", -0.39, 0.79, 0.0175, "auto", 
				"use_polarity", "auto", "auto", &m_hvModelID);
		}
		catch(HalconCpp::HException)
		{
			return false;
		}
		break;

	default:
		return false;
	}

	if (false == SaveModel(strModelName))  
		return false;

	return true;
}


bool CImageOperate::SaveModel(const CString& strModelName)
{
	if (NCC == m_enumMatchMode)
	{
		switch(m_enumCamType)
		{
		case LASER_VIEW:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"NCC_LaserModel"));
			break;
		case TRANS_DOWN:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+strModelName));
			break;
		case TRANS_UP:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+strModelName));
			break;
		case PRINT_LOCAL:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"NCC_PrintLocalModel"));
			break;
		case PRINT_HORIZONTAL:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"NCC_PrintHorizModel"));
			break;
		case PRINT_ASKANT:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"NCC_PrintAskantModel"));
			break;
		default:
			return false;
		}
	}
	else if (Shape == m_enumMatchMode)
	{
		switch(m_enumCamType)
		{
		case LASER_VIEW:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"Shape_LaserModel"));
			break;
		case TRANS_DOWN:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"Shape_TransDownModel"));
			break;
		case TRANS_UP:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"Shape_TransUpModel"));
			break;
		case PRINT_LOCAL:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"Shape_PrintLocalModel"));
			break;
		case PRINT_HORIZONTAL:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"Shape_PrintHorizModel"));
			break;
		case PRINT_ASKANT:
			WriteNccModel(m_hvModelID, (HTuple)(m_strModelPath+"Shape_PrintAskantModel"));
			break;
		default:
			return false;
		}
	}
	else
		return false;

	return true;
}



bool CImageOperate::LoadModel()
{
	if (NCC == m_enumMatchMode)
	{
		switch(m_enumCamType)
		{
		case LASER_VIEW:
			ReadNccModel((HTuple)(m_strModelPath+"NCC_LaserModel"), &m_hvModelID);
			break;
		case TRANS_DOWN:
			ReadNccModel((HTuple)(m_strModelPath+"NCC_TransDownModel"), &m_hvModelID);
			break;
		case TRANS_UP:
			ReadNccModel((HTuple)(m_strModelPath+"NCC_TransUpModel"), &m_hvModelID);
			break;
		case PRINT_LOCAL:
			ReadNccModel((HTuple)(m_strModelPath+"NCC_PrintLocalModel"), &m_hvModelID);
			break;
		case PRINT_HORIZONTAL:
			ReadNccModel((HTuple)(m_strModelPath+"NCC_PrintHorizModel"), &m_hvModelID);
			break;
		case PRINT_ASKANT:
			ReadNccModel((HTuple)(m_strModelPath+"NCC_PrintAskantModel"), &m_hvModelID);
			break;
		default:
			return false;
		}
	}
	else if (Shape == m_enumMatchMode)
	{
		switch(m_enumCamType)
		{
		case LASER_VIEW:
			ReadNccModel((HTuple)(m_strModelPath+"Shape_LaserModel"), &m_hvModelID);
			break;
		case TRANS_DOWN:
			ReadNccModel((HTuple)(m_strModelPath+"Shape_TransDownModel"), &m_hvModelID);
			break;
		case TRANS_UP:
			ReadNccModel((HTuple)(m_strModelPath+"Shape_TransUpModel"), &m_hvModelID);
			break;
		case PRINT_LOCAL:
			ReadNccModel((HTuple)(m_strModelPath+"Shape_PrintLocalModel"), &m_hvModelID);
			break;
		case PRINT_HORIZONTAL:
			ReadNccModel((HTuple)(m_strModelPath+"Shape_PrintHorizModel"), &m_hvModelID);
			break;
		case PRINT_ASKANT:
			ReadNccModel((HTuple)(m_strModelPath+"Shape_PrintAskantModel"), &m_hvModelID);
			break;
		default:
			return false;
		}
	}
	else
		return false;

	return true;
}


void CImageOperate::SetMatchRange(const CRect &rcRoi)
{
	m_rcMatchRoi = rcRoi;
}


void CImageOperate::GenMatchRoiImg(const HObject *phoImg)
{
	HObject hoROI, hoReduce;
	GenRectangle1(&hoROI, m_rcMatchRoi.top, m_rcMatchRoi.left, 
		m_rcMatchRoi.bottom, m_rcMatchRoi.right);

	ReduceDomain(*phoImg, hoROI, &hoReduce);
	CropDomain(hoReduce, &m_hoMatchRoiImg);
}


bool CImageOperate::Match()
{
	HTuple hres, row, col, angle, score, s1, s2;

	if (NCC == m_enumMatchMode)
	{
		CountSeconds(&s1);
		FindNccModel(m_hoMatchRoiImg, m_hvModelID, Degree2Rad(-30), Degree2Rad(60), 
			0.6, 1, 0.5, "true", 0, &row, &col, &angle, &score);
		TupleLength(score, &hres);
		CountSeconds(&s2);
	}
	else if (Shape == m_enumMatchMode)
	{
		CountSeconds(&s1);
		FindShapeModel(m_hoMatchRoiImg, m_hvModelID, -0.39, 0.78, 0.4, 1, 0.5, 
			"least_squares", 0, 0.9, &row, &col, &angle, &score);
		TupleLength(score, &hres);
		CountSeconds(&s2);
	}
	else
		return false;

	if (hres[0].I() > 0)
	{
		//匹配成功
		m_stLocRes.bSuccess = true;
		m_stLocRes.dXPos = col[0].D();
		m_stLocRes.dYPos = row[0].D();
		m_stLocRes.dAngle = angle[0].D();
	}
	else
	{
		//匹配失败
		m_stLocRes.bSuccess = false;
		m_stLocRes.dXPos = 0.0;
		m_stLocRes.dYPos = 0.0;
		m_stLocRes.dAngle = 0.0;
		return false;
	}

	return true;
}


LocRes CImageOperate::GetMatchRes()
{
	return m_stLocRes;
}


bool CImageOperate::Calibrate(const CRect &rcRoi, const float &fBlackPtCenDis, const float &fBlackPtDiameter, 
	const CalibPtNumIndex &enumPtIndex, float &fPixelWid, float &fPixelHei)
{
	if (rcRoi.Width() == 0 || rcRoi.Height() == 0)
	{
			AfxMessageBox("区域选择无效,请重新标定！");
			return false;
	}

	switch(enumPtIndex)
	{
	case Three: //3*3
		fPixelWid = (fBlackPtCenDis*2 + fBlackPtDiameter) / rcRoi.Width();
		fPixelHei = (fBlackPtCenDis*2 + fBlackPtDiameter) / rcRoi.Height();
		break;
	case Four: //4*4
		fPixelWid = (fBlackPtCenDis*3 + fBlackPtDiameter) / rcRoi.Width();
		fPixelHei = (fBlackPtCenDis*3 + fBlackPtDiameter) / rcRoi.Height();
		break;
	case Five: //5*5
		fPixelWid = (fBlackPtCenDis*4 + fBlackPtDiameter) / rcRoi.Width();
		fPixelHei = (fBlackPtCenDis*4 + fBlackPtDiameter) / rcRoi.Height();
		break;
	case Six: //6*6
		fPixelWid = (fBlackPtCenDis*5 + fBlackPtDiameter) / rcRoi.Width();
		fPixelHei = (fBlackPtCenDis*5 + fBlackPtDiameter) / rcRoi.Height();
		break;
	default:  
		AfxMessageBox("标定点数选择无效,请重新标定！");
		return false;
	}

	return true;
}