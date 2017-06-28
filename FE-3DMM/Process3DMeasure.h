#pragma once
class CFE3DMMDlg;
class CParamData;

class CProcess3DMeasure
{
public:
	CProcess3DMeasure(void);
	~CProcess3DMeasure(void);

	void SetMainDlgPointer(CFE3DMMDlg* pDlg);		//设置主窗口指针
	void Init();
	void Release();
	void Home();									//回零
	void TransferPara();							//向下位机传递参数	
	void SetParamData(CParamData* pData);			//设置配置参数类指针 

private:
	CFE3DMMDlg*				m_pMainDlg;				//主对话框指针
	CParamData*				m_pParamData;			//配置参数类指针

	
};

