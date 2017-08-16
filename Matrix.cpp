#include"Matrix.h"
template<typename T>
	T Matrix<T>::zero_value=T(0);//T类型表示0的值 

template<typename T>
void Matrix<T>::set_zero_value(const T &_zero_value)
{
	Matrix<T>::zero_value=_zero_value;
}

template<typename T>
Matrix<T>::Matrix(const unsigned int _row,const unsigned int _column)
{
	m_arrs=array_2D(_row,_column);
	row=_row;
	column=_column;
}

template<typename T>
Matrix<T>::Matrix(const unsigned int _row,const unsigned int _column,const T& default_value)
{
	m_arrs=array_2D(_row,_column,default_value);
	row=_row;
	column=_column;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &mat)
{
	this->m_arrs=array_2D(mat.row,mat.column);
	this->row=mat.row;
	this->column=mat.column;
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			this->m_arrs[i][j]=mat.m_arrs[i][j]; 
}

template<typename T>
std::ostream& operator << (std::ostream &out,const Matrix<T> &mat)
{
	for(int i=0;i<mat.row;i++)
	{
		for(int j=0;j<mat.column;j++)
			std::cout<<mat.m_arrs[i][j]<<' ';
		std::cout<<std::endl;
	}
	return out;
}

template<typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &mat)
{
	if(this->row!=mat.row || this->column!=mat.column)
	{
		del_array_2D(this->m_arrs,this->row);
		this->m_arrs=array_2D(mat.row,mat.column);
	}
	this->row=mat.row;
	this->column=mat.column;
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			this->m_arrs[i][j]=mat.m_arrs[i][j];
	return *this;		
}

template<typename T>
bool operator == (const Matrix<T> &mat_1,const Matrix<T> &mat_2)
{
	if(mat_1.row!=mat_2.row || mat_1.column!=mat_2.column)return false;
	for(int i=0;i<mat_1.row;i++)
		for(int j=0;j<mat_1.column;j++)
			if(mat_1.m_arrs[i][j]!=mat_2.m_arrs[i][j])return false;
	return true;
}

template<typename T>
bool operator != (const Matrix<T> &mat_1,const Matrix<T> &mat_2)
{
	return !(mat_1==mat_2);
}

template<typename T>
T* const Matrix<T>::operator[](const unsigned int k)
{
	if(k>=row)throw std::out_of_range("k>=row");
	return m_arrs[k];
}

template<typename T>
Matrix<T> Matrix<T>::operator + (void)
{
	Matrix<T> tmp(this->row,this->column);
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			tmp.m_arrs[i][j]=this->m_arrs[i][j];
	return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator - (void)
{
	Matrix<T> tmp(this->row,this->column);
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			tmp.m_arrs[i][j]=-(this->m_arrs[i][j]);
	return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator + (const Matrix<T> &mat)
{
	if(this->row!=mat.row)
		throw(std::invalid_argument("number of row not equal"));
	if(this->column!=mat.column)
		throw(std::invalid_argument("number of column not equal"));
	Matrix<T> tmp(this->row,this->column);
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			tmp.m_arrs[i][j]=this->m_arrs[i][j]+mat.m_arrs[i][j];
	return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator - (const Matrix<T> &mat)
{
	if(this->row!=mat.row)
		throw(std::invalid_argument("number of row not equal"));
	if(this->column!=mat.column)
		throw(std::invalid_argument("number of column not equal"));
	Matrix<T> tmp(this->row,this->column);
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			tmp.m_arrs[i][j]=this->m_arrs[i][j]-mat.m_arrs[i][j];
	return tmp;
}

template<typename T>
Matrix<T> Matrix<T>::operator * (const Matrix<T> &mat)
{ 
	if(this->column != mat.row)
		throw std::invalid_argument("The column of Matrix<T> 1 dosen't equal to the row of Matrix<T> 2");
	Matrix<T> tmp(this->row,mat.column);
	for(int i=0;i<this->row;i++)
		for(int j=0;j<mat.column;j++)
			for(int k=0;k<this->column;k++)
				tmp.m_arrs[i][j]=tmp.m_arrs[i][j]+this->m_arrs[i][k]*mat.m_arrs[k][j];
	return tmp;
}

template<typename T>
Matrix<T> operator * (const int num,const Matrix<T> &mat)
{
	Matrix<T> tmp=mat;
	for(int i=0;i<mat.row;i++)
		for(int j=0;j<mat.column;j++)
			tmp.m_arrs[i][j]=num*tmp.m_arrs[i][j];
	return tmp;
}

template<typename T>
Matrix<T>& Matrix<T>::operator += (const Matrix<T> &mat)
{
	if(this->row!=mat.row)
		throw(std::invalid_argument("number of row not equal"));
	if(this->column!=mat.column)
		throw(std::invalid_argument("number of column not equal"));
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			this->m_arrs[i][j]=this->m_arrs[i][j]+mat.m_arrs[i][j];
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator -= (const Matrix<T> &mat)
{
	if(this->row!=mat.row)
		throw(std::invalid_argument("number of row not equal"));
	if(this->column!=mat.column)
		throw(std::invalid_argument("number of column not equal"));
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			this->m_arrs[i][j]=this->m_arrs[i][j]-mat.m_arrs[i][j];
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator *= (const int num)
{
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			this->m_arrs[i][j]=num*this->m_arrs[i][j];
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator *= (const Matrix<T> &mat)
{
	if(this->column!=mat.row)
		throw std::invalid_argument("The column of Matrix<T> 1 dosen't equal to the row of Matrix<T> 2");
	return *this=(*this)*mat;
}

template<typename T>
const int Matrix<T>::number_of_row(void)const 
{
	return row;
}

template<typename T>
const int Matrix<T>::number_of_column(void)const
{
	return column;
}

template<typename T>
Matrix<T> Matrix<T>::transpose()const
{
	Matrix<T> tmp(this->column,this->row);
	for(int i=0;i<this->row;i++)
		for(int j=0;j<this->column;j++)
			tmp.m_arrs[j][i]=this->m_arrs[i][j];
	return tmp;
}

template<typename T>
inline bool Matrix<T>::is_square(void)const
{
	return row==column;
}

template<typename T> 
Matrix<T>::~Matrix<T>()
{
	del_array_2D(m_arrs,row);
}

template<typename T>
T** Matrix<T>::array_2D(const unsigned int row,const unsigned int column)
{
	T** arrs=NULL;
	unsigned int i;
	try
	{
		arrs=new T*[row];
		for(int k=0;k<row;k++)
			arrs[k]=NULL;
		for(i=0;i<row;i++)
			arrs[i]=new int[column];
		for(i=0;i<row;i++)
			for(int j=0;j<column;j++)
				arrs[i][j]=Matrix<T>::zero_value; 
	}
	catch(std::bad_alloc &e)
	{
		if(arrs!=NULL)
		{
			for(int k=0;k<i;k++)
				delete[] arrs[k];
			delete[] arrs;
		}
		throw e;
	}
	return arrs;
}

template<typename T>
T** Matrix<T>::array_2D(const unsigned int row,const unsigned int column,const T& default_value)
{
	T** arrs=NULL;
	try
	{
		arrs=array_2D(row,column);
		for(int i=0;i<row;i++)
			for(int j=0;j<column;j++)
				arrs[i][j]=default_value;
	}
	catch(std::bad_alloc &e)
	{
		throw e;
	}
	return arrs;
}

template<typename T>
void Matrix<T>::del_array_2D(T** arrs,const unsigned int row)
{
	for(int i=0;i<row;i++)
		delete[] arrs[i];
	delete[] arrs; 
}

/*written by szh,2017/08/16*/ 
