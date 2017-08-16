#ifndef MATRIX_H
#define MATRIX_H 
#include<iostream>
#include<stdexcept>
template<typename T>
class Matrix
{
	private: 
		T ** m_arrs; //矩阵元素存放在arrs指向的内存中
		unsigned int row;  //矩阵有row行
		unsigned int column;  //矩阵有column列
		static T zero_value;
	public:
		static void set_zero_value(const T &_zero_value);//设置T类型的零元 
		Matrix<T>(const unsigned int _row,const unsigned int _column); 
		Matrix<T>(const unsigned int _row,const unsigned int _column,const T & default_value);
		Matrix<T>(const unsigned int _row,const unsigned int _column,T **arrs);
		Matrix<T>(const Matrix &mat);
		template<typename TT>
			friend std::ostream& operator << (std::ostream &out,const Matrix<TT> &mat);
		Matrix& operator = (const Matrix &mat);
		template<typename TT>
			friend bool operator == (const Matrix<TT> &mat_1,const Matrix<TT> &mat_2);
		template<typename TT>
			friend bool operator != (const Matrix<TT> &mat_1,const Matrix<TT> &mat_2);
		T* const operator[](const unsigned int k);//返回m_arr第k行的指针.
		//若mat是Matrix类型实例，可以用mat[i][j]来访问矩阵上对应的元素. 
		Matrix<T> operator + (void);
		Matrix<T> operator - (void); 
		Matrix<T> operator + (const Matrix &mat);
		Matrix<T> operator - (const Matrix &mat);
		Matrix<T> operator * (const Matrix &mat);
		template<typename TT>
			friend Matrix<TT> operator * (const int num,const Matrix<TT> &mat);
		Matrix<T>& operator += (const Matrix &mat);
		Matrix<T>& operator -= (const Matrix &mat);
		Matrix<T>& operator *= (const int num);
		Matrix<T>& operator *= (const Matrix &mat);
		const int number_of_row(void)const;
		const int number_of_column(void)const;
		Matrix<T> transpose(void)const;//转置矩阵 
		bool is_square(void)const;
		bool is_size_equal(const Matrix &mat)const; 
		~Matrix();
	private:
		T** array_2D(const unsigned int row,const unsigned int column);//申请内存 
		T** array_2D(const unsigned int row,const unsigned int column,const T& default_value);
		void del_array_2D(T** arrs,const unsigned int row);//释放内存 
};

#endif
