#ifndef MATRIX_H
#define MATRIX_H 
#include<iostream>
#include<stdexcept>
template<typename T>
class Matrix
{
	private: 
		T ** m_arrs; //����Ԫ�ش����arrsָ����ڴ���
		unsigned int row;  //������row��
		unsigned int column;  //������column��
		static T zero_value;
	public:
		static void set_zero_value(const T &_zero_value);//����T���͵���Ԫ 
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
		T* const operator[](const unsigned int k);//����m_arr��k�е�ָ��.
		//��mat��Matrix����ʵ����������mat[i][j]�����ʾ����϶�Ӧ��Ԫ��. 
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
		Matrix<T> transpose(void)const;//ת�þ��� 
		bool is_square(void)const;
		bool is_size_equal(const Matrix &mat)const; 
		~Matrix();
	private:
		T** array_2D(const unsigned int row,const unsigned int column);//�����ڴ� 
		T** array_2D(const unsigned int row,const unsigned int column,const T& default_value);
		void del_array_2D(T** arrs,const unsigned int row);//�ͷ��ڴ� 
};

#endif
