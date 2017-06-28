#include "StdAfx.h"
#include "TransferMatrix.h"

#include <iomanip>  //用于设置输出格式

using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::cerr;
using std::endl;

const CMatrix& CMatrix::operator+=( const CMatrix& m )
{
	if ( rows() != m.rows() || rows() != m.cols() )
	{
		return *this;
	}
	
	int r = rows();
	int c = cols();

	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			array[i][j] += m[i][j];
		}
	}

	return *this;
}


const CMatrix& CMatrix::operator-=( const CMatrix& m )
{
	if ( rows() != m.rows() || cols() != m.cols() )
	{
		return *this;
	}

	int r = rows();
	int c = cols();

	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			array[i][j] -= m[i][j];
		}
	}

	return *this;
}

const CMatrix& CMatrix::operator*=( const CMatrix& m )
{
	if ( cols() != m.rows() || !m.square() )
	{
		return *this;
	}

	CMatrix ret( rows(), cols() );

	int r = rows();
	int c = cols();

	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			double sum = 0.0;
			for ( int k = 0; k < c; ++k )
			{
				sum += array[i][k] * m[k][j];
			}
			ret[i][j] = sum;
		}
	}

	*this = ret;
	return *this;
}



bool operator==( const CMatrix& lhs, const CMatrix& rhs )
{
	if ( lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols() )
	{
		return false;
	}

	for ( int i = 0; i < lhs.rows(); ++i )
	{
		for ( int j = 0; j < lhs.cols(); ++j )
		{
			if ( rhs[i][j] != rhs[i][j] )
			{
				return false;
			}
		}
	}

	return true;
}

bool operator!=( const CMatrix& lhs, const CMatrix& rhs )
{
	return !( lhs == rhs );
}

const CMatrix operator+( const CMatrix& lhs, const CMatrix& rhs )
{
	CMatrix m;
	if ( lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols() )
	{
		return m;
	}

	m = lhs;
	m += rhs;

	return m;
}

const CMatrix operator-( const CMatrix& lhs, const CMatrix& rhs )
{
	CMatrix m;
	if ( lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols() )
	{
		return m;
	}

	m = lhs;
	m -= rhs;

	return m;
}

const CMatrix operator*( const CMatrix& lhs, const CMatrix& rhs )
{
	CMatrix m;
	if ( lhs.cols() != rhs.rows() )
	{
		return m;
	}

	m.resize( lhs.rows(), rhs.cols() );

	int r = m.rows();
	int c = m.cols();
	int K = lhs.cols();

	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			double sum = 0.0;
			for ( int k = 0; k < K; ++k )
			{
				sum += lhs[i][k] * rhs[k][j];
			}
			m[i][j] = sum;
		}
	}

	return m;
}



inline static double LxAbs( double d )
{
	return (d>=0)?(d):(-d);
}

inline 
	static bool isSignRev( const vector<double>& v )
{
	int p = 0;
	int sum = 0;
	int n = (int)v.size();

	for ( int i = 0; i < n; ++i )
	{
		p = (int)v[i];
		if ( p >= 0 )
		{
			sum += p + i;
		}
	}

	if ( sum % 2 == 0 ) // 如果是偶数，说明不变号
	{
		return false;
	}
	return true;
}





// 计算矩阵转置
const CMatrix trans( const CMatrix& m )
{
	CMatrix ret;
	if ( m.empty() ) return ret;

	int r = m.cols();
	int c = m.rows();

	ret.resize(r, c);
	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			ret[i][j] = m[j][i];
		}
	}

	return ret;
}


// 计算绝对值
const CMatrix abs( const CMatrix& m )
{
	CMatrix ret;

	if( m.empty() )
	{
		return ret;
	}

	int r = m.rows();
	int c = m.cols();
	ret.resize( r, c );

	for ( int i = 0; i < r; ++i )
	{
		for ( int j = 0; j < c; ++j )
		{
			double t = m[i][j];
			if ( t < 0 ) ret[i][j] = -t;
			else ret[i][j] = t;
		}
	}

	return ret;
}


// 取矩阵中指定位置的子矩阵 
const CMatrix submatrix(const CMatrix& m,int rb,int re,int cb,int ce)
{
	CMatrix ret;
	if ( m.empty() ) return ret;

	if ( rb < 0 || re >= m.rows() || rb > re ) return ret;
	if ( cb < 0 || ce >= m.cols() || cb > ce ) return ret;

	ret.resize( re-rb+1, ce-cb+1 );

	for ( int i = rb; i <= re; ++i )
	{
		for ( int j = cb; j <= ce; ++j )
		{
			ret[i-rb][j-cb] = m[i][j];
		}
	}
	return ret;
}
