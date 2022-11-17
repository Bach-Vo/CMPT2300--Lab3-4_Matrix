#include "Matrix.hpp"

template<typename T>
Matrix<T>::Matrix()
{
	headMatrix = nullptr;
}

template <typename T>
Matrix<T>::Matrix(int numRows, int numCols, T* headMatrixPtr)
{
	;
}

template <typename T>
Matrix<T>::~Matrix()
{
	;
}


template <typename T>
Matrix(const Matrix& obj)
{

}
Matrix(Matrix&& obj);
virtual ~Matrix();

getRow(int const row);
getColumn(int const col);
at(int const row, int const col);
transpose(Matrix& obj);
operator+ (const Matrix& obj);
operator* (const Matrix& obj);
friend istream& operator<< (ostream& os, const Matrix& matrix)
