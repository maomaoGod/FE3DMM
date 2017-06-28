#include "StdAfx.h"
#include "Process3DMeasure.h"
#include "FE-3DMMDlg.h"
#include "ParamData.h"

CProcess3DMeasure::CProcess3DMeasure(void)
{
	m_pMainDlg = NULL;
}


CProcess3DMeasure::~CProcess3DMeasure(void)
{
	Release();
}


void CProcess3DMeasure::SetMainDlgPointer(CFE3DMMDlg* pDlg)
{
	m_pMainDlg = pDlg;
}

void CProcess3DMeasure::Init()
{

}

void CProcess3DMeasure::Release()
{

}

void CProcess3DMeasure::Home()
{

}

void CProcess3DMeasure::TransferPara()
{

}

void CProcess3DMeasure::SetParamData(CParamData* pData)
{
	m_pParamData = pData;
}