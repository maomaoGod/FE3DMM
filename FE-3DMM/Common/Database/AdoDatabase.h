#pragma once
class CAdoDatabase
{
public:
	CAdoDatabase(void);
	virtual ~CAdoDatabase(void);

	//打开数据库
	bool OpenMDB(CString strPath);	
	//关闭数据库
	void Close();

	//执行Sql语句，通过该函数操作数据库
	void ExecuteSql(CString strSql);

	//判断数据库是否打开(连接)
	bool IsDatabaseOpen();

public:
	_ConnectionPtr m_pConn;  //智能指针

};

