#ifdef dll_API 
#else
#define dll_API _declspec(dllimport)
#endif
#include <vector>
#include <string>
#include <Windows.h>
#include "DataStructure.h"
using std::vector;
using std::string;
class dll_API iCloudOperator
{
public: 
	iCloudOperator();
	~iCloudOperator();
public:
	CDS3DPt m_TowCenPt,m_TowMaxPt,m_TowMinPt; //测量点云的中心点
	CDS3DPt m_StdCenPt,m_StdMaxPt,m_StdMinPt; //标准点云的中心点
	CDS3DPt m_StlCenPt,m_StlMaxPt,m_StlMinPt; //STL文件的中心点
public:
	BOOL Read( const CString& file_Name,string& err_Str,TDSVec3DPt& out_PCloud );
	void GetBox( vector<CDS3DPt>& in_Pt, CDS3DPt& box_MaxPt, CDS3DPt& box_MinPt, CDS3DPt& box_CenPt );
	bool GetStdBox( double box_Vec[3] );
	void GetStdCenPt( double cen_Pt[3] );
	bool GetTowBox( double box_Vec[3] );
	void GetTowCenPt( double cen_Pt[3] );
	bool GetStlBox( double box_Vec[3] );
	void GetStlCenPt( double cen_Pt[3] );
};
