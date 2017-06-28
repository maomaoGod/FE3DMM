#include "DataStructure.h"


class dll_API Calculate
{
public:
	Calculate(void);
	~Calculate(void);

	struct LineSegment { CPoint pt1, pt2; };
	struct LineSegment2 { CDS3DPt pt1, pt2; };

	float Direction(const CPoint &p1, const CPoint &p2, const CPoint &p);
	float Direction2(const CDS3DPt &p1, const CDS3DPt &p2, const CDS3DPt &p);
	int OnSegment(const CPoint &p1, const CPoint &p2, const CPoint &p);
	int OnSegment2(const CDS3DPt &p1, const CDS3DPt &p2, const CDS3DPt &p);
	int SegmentsIntersert(const CPoint &p1, const CPoint &p2, const CPoint &p3, const CPoint &p4);
	int SegmentsIntersert2(const CDS3DPt &p1, const CDS3DPt &p2, const CDS3DPt &p3, const CDS3DPt &p4);
	int InPolygon(const vector<CPoint> &polygon, const CPoint &p);
	int InPolygon2(const vector<CDS3DPt> &polygon, const CDS3DPt &p);
	float TriangleArea(const CPoint &pos1, const CPoint &pos2, const CPoint &pos3);
	BOOL InTriangle(const CPoint &pos, const CPoint &posA, const CPoint &posB, const CPoint &posC);
	

	float calculate_A3(float src[][3], int n);
	float calculate_A4(float src[][4], int n);
	void calculate_A_adjoint3(float src[3][3], float dst[3][3], int n); 
	void calculate_A_adjoint4(float src[4][4], float dst[4][4], int n); 
	int calculate_A_inverse3(float src[3][3], float dst[3][3], int n);  //
	int calculate_A_inverse4(float src[4][4], float dst[4][4], int n);  //
	void Empty(float *matrix[], int row, int column);
	void Inverse(float *matrix1[], float *matrix2[], int n, float d);  //
	float Determinant(float* matrix[], int n);  //
	float AlCo(float* matrix[], int jie, int row, int column);  //
	float Cofactor(float* matrix[], int jie, int row, int column);  //


	BOOL FitCircle(const vector<CDS3DPt> &selectPt, float &oR, CDS3DPt &center);  //
	BOOL Fit2DLine(const vector<CDS3DPt> &selectPt, float &b, float &k);  //
	BOOL Fit3DLine(const vector<CDS3DPt> &selectPt, vector<float> &mk);  //


	vector<CDS3DPtNor> CalMeshToPt(const vector<CMesh> &tMesh);  //
	vector<CDS3DPtNor> CalMeshCenterPt(const vector<CMesh> &tMesh);  //

};
