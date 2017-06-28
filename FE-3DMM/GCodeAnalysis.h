/////本类将Ug生成的G代码文件解析成下位机命令
#pragma once
#include <vector>
using namespace std;

class CGCodeAnalysis
{
public:
	CGCodeAnalysis(void);
	~CGCodeAnalysis(void);

	void ReadGCodeFile(CString strFileName);

public:
	vector<CString> m_vecStrGCode;

};

