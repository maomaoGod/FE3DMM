
#ifndef   _TOWMATRIX_H_
#define   _TOWMATRIX_H_



////////////////////////////////////////////////////////////////////////////
//opengl 头文件
//#include <gl\gl.h>//gl
//#include <gl\glu.h>//glu
//#include <gl\glut.h>//glut

//////////////////////////////////////////////////////////////////////////
//STL  C++ template class  类模板
#include <math.h>
#include <vector>
#include <list>
//#include <cstring>
#include <algorithm>

//#include <gl\glaux.h>//glaux
//////////////////////////////////////////////////////////////////////////
//opengl 库 library
//#pragma comment(lib,"Opengl32.lib")//
//#pragma comment(lib,"Glu32.lib")//
//#pragma comment(lib,"Glut32.lib")//


/////////////////////////////////////////////////////////////////////////////////
//namespace
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//const parameter 常量参数
//const double TOW_PI=3.141592653589793;

/************************************************************************/
/*          matrix  function  define all                                */
/************************************************************************/
//matrix = I 方阵单位化
template<class T>
void __declspec(dllexport)  TowMatrixIdentity(T* matrix,int nrows)
{ //  matrix -  nrows*nrows
   memset(matrix,0,nrows*nrows*sizeof(T));
   for(int i=0;i<nrows;++i)
     matrix[i*nrows+i]=1;
}

//matrix[3][4] change to  matrix0[4][3] 矩阵转置
template<class T,class T0>
void __declspec(dllexport) TowMatrixTranspose(T* matrix,T0* matrix0,int nrows,int ncols)
{// matrix - nrows*ncols    matrix0 - ncols*nrows
   for(int i=0;i<nrows;++i)
     for(int j=0;j<ncols;++j)
        matrix0[j*nrows+i]=matrix[i*ncols+j];
}

//matrix  M1=M  (double , float) =  (float , double)  矩阵相等
template<class TT1,class TT2>//class TT3>
void  __declspec(dllexport) TowMatrixEqual(TT1* M,TT2* M1,int nrows,int ncols)
{//M - nrows*ncols    M1 - nrows*ncols
   for(int i=0;i<nrows;++i)
    for(int j=0;j<ncols;++j)
      M1[i*ncols+j]=M[i*ncols+j];     
}

//matrix  M2=M+M1   (double , float) + (double , float) = (double , float) 矩阵相加
template<class TT1,class TT2,class TT3>
void  __declspec(dllexport) TowMatrixAdd(TT1* M,TT2* M1,TT3* M2,int nrows,int ncols)
{//M - nrows*ncols    M1 - nrows*ncols   M2 - nrows*ncols
   for(int i=0;i<nrows;++i)
    for(int j=0;j<ncols;++j)
       M2[i*ncols+j]=M[i*ncols+j]+M1[i*ncols+j];   
}

// (float,double) * (float,double) =  (double , float) 矩阵相乘
template<class TT1,class TT2,class TT3>
void  __declspec(dllexport) TowMultMatrix(TT1* M,TT2* M1,TT3* M2,int rows,int cols)
{//M - rows*cols    M1 - cols*rows   M2 - rows*rows
  for(int i=0;i<rows;++i)
    for(int j=0;j<rows;++j)
   {
       M2[i*rows+j]=0.0;
       for(int k=0;k<cols;++k)
         M2[i*rows+j]+=M[i*cols+k]*M1[k*rows+j];
   }  
}

// (float,double) * (float,double) =  (double , float) 矩阵相乘
template<class TT1,class TT2,class TT3>
void  __declspec(dllexport) TowMultMatrix(TT1* M,TT2* M1,TT3* M2,int rows,int soms,int cols)
{
//M - rows*soms    M1 - soms*cols   M2 - rows*cols
 for(int i=0;i<rows;++i)
    for(int j=0;j<cols;++j)
   {
       M2[i*cols+j]=0.0;
       for(int k=0;k<soms;++k)
         M2[i*cols+j]+=M[i*soms+k]*M1[k*cols+j];
   } 
}

///Gauss max elements solve equations 高斯列主元消元法求解多元一次线性方程组
template<class TT1,class TT2,class TT3>//>
void __declspec(dllexport)  TowGauss(TT1* Aa,TT2* Bb,TT3* x,int rows)
{// Aa * x = Bb    root - x[rows]
   int i,j,k;
   int ik;
   double temp,mik;
   double sum,aa;
   double* a=new double[rows*rows];
   double* b=new double[rows];   
   
   for(i=0;i<rows;++i)
   {
     b[i]=Bb[i]; 
	 for(j=0;j<rows;++j)
	   a[i*rows+j]=Aa[i*rows+j];	 
	}
   for(k=0;k<rows-1;++k)
   {
	   ik=k;
	   aa=a[k*rows+k];
	   for(i=k;i<rows;++i)
       {		   
         if(fabs(aa)<fabs(a[i*rows+k]))
		 { 
		   aa=a[i*rows+k];
		   ik=i;			   
		 }
	   }
	   if(ik!=k)
       {
		 for(j=k;j<rows;++j)
		 {
		   temp=a[k*rows+j];
		   a[k*rows+j]=a[ik*rows+j];
		   a[ik*rows+j]=temp;
		 }
	 	temp=b[k];
	 	b[k]=b[ik];
	 	b[ik]=temp;
	   }
       for(i=k+1;i<rows;++i)
	   {
	     mik=a[i*rows+k]/a[k*rows+k];
	     for(j=k+1;j<rows;j++)
	 	   a[i*rows+j]=a[i*rows+j]-mik*a[k*rows+j];
	     b[i]=b[i]-mik*b[k];
	   }
	}
    x[rows-1]=b[rows-1]/a[rows*rows-1];
	for(k=rows-2;k>-1;--k)
	{
	  sum=0.0;
	  for(j=k+1;j<rows;++j)
		  sum+=a[k*rows+j]*x[j];
	  x[k]=(b[k]-sum)/a[k*rows+k];
	}

    delete[]a;
    delete[]b;
    a=NULL;
    b=NULL;	  
}
//////////////////////////////////////////////////////////////////////////

//Doolittle max elements solve equations 
//Doolittle列主元消元法求解多个多元一次线性方程组  求解矩阵 
template<class TT1,class TT2,class TT3>//>
void __declspec(dllexport)  TowDoolittle(TT1* aa,TT2* bb,TT3* xx,int rows)
{// aa * xx = bb        root - xx[rows][rows]
   int k,i,j,t,ik;
   int* M=new int[rows];
   double  *s,*l,*u,*a,*b;
   double temp,smax=0,*y,*x;
   s=new double[rows];
   l=new double[rows*rows];
   u=new double[rows*rows];
   a=new double[rows*rows];
   b=new double[rows];
   y=new double[rows];
   x=new double[rows];
//  QA  =  LU
   for(i=0;i<rows;++i)
   {
     M[i]=0;
     for(j=0;j<rows;++j)
	 {
       a[i*rows+j]=aa[i*rows+j];
	 }
	}
   for(k=0;k<rows;++k)
   {
     for(i=k;i<rows;++i)
	 {
	   s[i]=a[i*rows+k];
	   for(t=0;t<k;++t)
		   s[i]-=l[i*rows+t]*u[t*rows+k];
	   if(i==k)
		{
		     smax=s[i];
			 ik=i;
		 }
       if(fabs(smax)<fabs(s[i]))
		{
		     smax=s[i];
			 ik=i;
		}
	 }
	 M[k]=ik;
	 if(ik!=k)
	 {
       for(t=0;t<k;++t)
		{
           temp=l[k*rows+t];
		   l[k*rows+t]=l[ik*rows+t];
		   l[ik*rows+t]=temp;
		}
       for(t=k;t<rows;++t)
		{
           temp=a[k*rows+t];
		   a[k*rows+t]=a[ik*rows+t];
		   a[ik*rows+t]=temp;
		}
       temp=s[k];
	   s[k]=s[ik];
	   s[ik]=temp;
	 }
     u[k*rows+k]=s[k];
	 if(k<rows-1)
	 {
	    for(j=k+1;j<rows;++j)
		{
		  u[k*rows+j]=a[k*rows+j];
		  for(t=0;t<k;++t)
			  u[k*rows+j]-=l[k*rows+t]*u[t*rows+j];
		}
		for(i=k+1;i<rows;++i)
		  l[i*rows+k]=s[i]/u[k*rows+k];
	 }
   }
   //Qb  =  Ly   AND   Ux  =   y
   for(j=0;j<rows;++j)
   {
      for(i=0;i<rows;++i)
        b[i]=bb[i*rows+j];
      for(k=0;k<rows-1;++k)
      {
         t=M[k];
	     temp=b[k];
	     b[k]=b[t];
	     b[t]=temp;
      }
      y[0]=b[0];
      for(i=1;i<rows;++i)
      {
       y[i]=b[i];
       for(t=0;t<i;++t)
         y[i]-=l[i*rows+t]*y[t];     
       }
      x[rows-1]=y[rows-1]/u[rows*rows-1];
      for(i=rows-2;i>-1;--i)
      {
        x[i]=y[i];
        for(t=i+1;t<rows;++t)
           x[i]-=u[i*rows+t]*x[t];
        x[i]/=u[i*rows+i];
      } 
      for(i=0;i<rows;++i)
      {
        xx[i*rows+j]=x[i];
      }           
   }
   delete[]M;
   delete[]s;
   delete[]l;
   delete[]u;
   delete[]a;
   delete[]b;
   delete[]y;
   delete[]x;
   M=NULL;
   s=NULL;
   l=NULL;
   u=NULL;
   a=NULL;
   b=NULL;
   y=NULL;
   x=NULL;
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// invertible matrice  矩阵求逆
template<class TT1,class TT2>//,class TT3>
void __declspec(dllexport)  TowMatrixAnti(TT1* Matrix,TT2* MatrixA,int rows)
{//  Matrix * MatrixA = I          I = E
   double* E=new double[rows*rows]; 
   TowMatrixIdentity(E,rows); 
/*   memset(E,0,rows*rows*sizeof(double)); 
   int i;
   for(i=0;i<rows;++i)
	   E[i*rows+i]=1.0;*/
/*//Gauss solution
 TT2* b=new TT2[rows];
 TT2* x=new TT2[rows];
 memset(b,0.0,rows*sizeof(TT2));
 memset(x,0.0,rows*sizeof(TT2));
 for(int j=0;j<rows;j++)
	{
       for(i=0;i<rows;i++)
		   b[i]=E[i*rows+j];
	   Gauss(Matrix,b,x,rows);       
	   for(i=0;i<rows;i++)
		   MatrixA[i*rows+j]=x[i];
	}
    delete[]b;
    delete[]x;
    b=NULL;
    x=NULL;*/
//Doolittle solution
   TowDoolittle(Matrix,E,MatrixA,rows); 
   delete[]E;
   E=NULL;
}

//////////////////////////////////////////////////////////////////////////
///Jacobi Solve Eigen of  Matrix 求解矩阵特征值及特征向量
template<class TT1,class TT2>
void __declspec(dllexport) TowEigenJacobi(TT1 *M1,TT2 *M2,int rows)
{//M1 - rows * rows   M2 - rows * rows 
  int i,j,p,q;
  double t,z,cos2w,sin2w,cosw,sinw;
  double *Upq,*D,maxa,*UTpq;
  Upq=new double[rows*rows];
  UTpq=new double[rows*rows];
  D=new double[rows*rows];
  TowMatrixIdentity(M2,rows); 
 /* memset(M2,0,rows*rows*sizeof(double));
  for(i=0;i<rows;++i)
    M2[i*rows+i]=1.0; */
  maxa=M1[0*rows+1];
  p=0;
  q=1;
  for(i=0;i<rows;++i)
   for(j=i+1;j<rows;++j)
     if(fabs(M1[i*rows+j])>fabs(maxa))
     {
       maxa=M1[i*rows+j];
       p=i;
       q=j;
     }
//
  do 
  {
   TowMatrixIdentity(Upq,rows); 
/*   memset(Upq,0,rows*rows*sizeof(double));
   for(i=0;i<rows;++i)
     Upq[i*rows+i]=1.0; */
   t=2.0*M1[p*rows+q]/(M1[p*rows+p]-M1[q*rows+q]);
   z=(M1[p*rows+p]-M1[q*rows+q])/(2.0*M1[p*rows+q]);
   if(fabs(t)<1.0)
   {
     cos2w=1.0/sqrt(1.0+t*t);
     sin2w=t/sqrt(1.0+t*t);
   }
   else
   {
     cos2w=fabs(z)/sqrt(1.0+z*z);
     sin2w=z/(fabs(z)*sqrt(1.0+z*z));
   }
   cosw=sqrt(0.5*(1+cos2w));
   sinw=0.5*sin2w/cosw;
   Upq[p*rows+p]=cosw;
   Upq[q*rows+q]=cosw;
   Upq[p*rows+q]=-sinw;
   Upq[q*rows+p]=sinw;
//
   TowMatrixTranspose(Upq,UTpq,rows,rows);
   TowMultMatrix(UTpq,M1,D,rows,rows);
   TowMultMatrix(D,Upq,M1,rows,rows); 
   TowMultMatrix(M2,Upq,D,rows,rows);
   TowMatrixEqual(D,M2,rows,rows);  
//             
   maxa=M1[0*rows+1];
   p=0;
   q=1;
   for(i=0;i<rows;++i)
   for(j=i+1;j<rows;++j)
     if(fabs(M1[i*rows+j])>fabs(maxa))
     {
       maxa=M1[i*rows+j];
       p=i;
       q=j;
     }
  } while(fabs(maxa)>1.0e-8);
  delete []Upq;
  Upq=NULL;
  delete []UTpq;
  UTpq=NULL;
  delete []D;
  D=NULL; 
}

//EigenVector of  max EigenValue matrix  求解最小特征值 特征向量
template<class TT1,class TT2>
void __declspec(dllexport)  TowEigenVector(TT1 *M,TT2 *M2,int rows)
{// M - rows * rows    M2 - rows 
   TT1 max;
   int i,p;
   TT2 *M1=new TT2[rows*rows];
   TowEigenJacobi(M,M1,rows);
   max=M[0*rows+0];
   p=0;
   for(i=1;i<rows;++i)
     if(max>M[i*rows+i])
     {
       p=i;
       max=M[i*rows+i];
     }
   for(i=0;i<rows;++i)
     M2[i]=M1[i*rows+p];
   delete []M1;
   M1=NULL;
}

#endif