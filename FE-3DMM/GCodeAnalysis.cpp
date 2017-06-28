#include "StdAfx.h"
#include "GCodeAnalysis.h"


CGCodeAnalysis::CGCodeAnalysis(void)
{
}


CGCodeAnalysis::~CGCodeAnalysis(void)
{
}


void CGCodeAnalysis::ReadGCodeFile(CString strFileName)
{
	////注意：定义三个P变量, 从第一行XYZ开始解析，解析为X(P1+..),  Y(P2+..), Z(P3+..)

	CStdioFile file;
	if (!file.Open(strFileName, CFile::modeRead))
	{
		AfxMessageBox("打开G代码文件失败!");
		return;
	}

	m_vecStrGCode.clear();      

	CString strLine;
	CString strCommandTemp;
	while (file.ReadString(strLine))
	{
		if (strLine.Left(1) != 'N') continue;
		strLine.Delete(0, strLine.Find(' ')+1);  //先将N开头的一组字符串删之

		while(strLine.GetLength() != 0)
		{
			if (strLine.Find(' ') == 0)
			{
				strLine.Delete(0, 1);  //当第一个字符为' '时，删之
			}
			else if (strLine.Find(' ') > 0)
			{		
				strCommandTemp = strLine.Left(strLine.Find(' '));  //获取一个临时命令
				m_vecStrGCode.push_back(strCommandTemp);  //压栈
				strLine.Delete(0, strLine.Find(' ') + 1);
			}
			else
			{
				m_vecStrGCode.push_back(strLine);
				strLine.Delete(0, strLine.GetLength());
			}
		}	
	}
}
