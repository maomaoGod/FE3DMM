#pragma once
#include "AdoDatabase.h"

class CAdoRecordset
{
public:
	CAdoRecordset(void);
	virtual ~CAdoRecordset(void);
	
	//打开表
	BOOL OpenTable(CString strTable, CAdoDatabase* pDatabase);
	//关闭表
	void CloseTable();
	//获取字段数量
	long GetFieldCount();
	//获取字段标题
	void GetFieldName(long nColIndex, CString& strName);
	//获取字段的值
	CString GetFieldValue(long nColIndex);			//依据列索引
	CString GetFieldValue(CString strFieldName);	//依据字段名
	//设置字段的值
	void SetFieldValue(long nColIndex, CString strValue);
	void SetFieldValue(CString strFieldName, CString strValue);
	//获得记录数(行数)
	long GetRecordCount();							

	//游标操作
	void MoveFirst();
	void MoveLast();
	void MoveNext();
	void Move(long nRowIndex);	//移动至指定的记录位置
	void MovePrevious();		//移动至前一条记录
	BOOL IsBOF();				//游标是否在记录集的起始位置
	BOOL IsEOF();				//游标是否在记录集的结束位置

	//增加新记录
	void AddNew();
	//更新至数据库
	void Update();
	//删除记录
	void Delete();

public:
	_RecordsetPtr m_pSet;    //智能指针

};

