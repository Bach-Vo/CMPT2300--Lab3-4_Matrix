#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <istream>
#include <iostream>

using namespace std;
/*
A default constructor that creates an empty matrix.
A parameterized constructor that creates a matrix including the values of a two - dimensional array.
A copy constructor and a copy assignment operator.
A move constructor and a move assignment operator.
A destructor.
A method that returns a specific row of the metrix.
A method that returns a specific column of the matrix.
A method that returns a specific element of the matrix.
A method that returns the transpose of the matrix as a Matrix object.
Overload the addition operator to add two matrices of the same size.
Overload the multiplication operator to multiply two matrices of compatible sizes.
Overload the stream insertion operator to insert a matrix in the matrix format into an output stream.
A forward iterator as a subclass of the "Matrix" ADT that traverses the items of the matrix row by row.
*/

template <typename T>
class Node {
public:
	T value;
	Node<T>* nextInRow;
	Node<T>* nextInColumn;

	Node()
	{
		nextInRow = nullptr;
		nextInColumn = nullptr;
	}

	Node(const T& value)
	{
		this->value = value;
		nextInRow = nullptr;
		nextInColumn = nullptr;
	}

	virtual ~Node()
	{
		if (nextInRow != nullptr)
		{
			delete nextInRow;
		}
		if (nextInColumn != nullptr)
		{
			delete nextInColumn;
		}
	}
};

template <typename T>
class MatrixIterator : public std::iterator<std::forward_iterator_tag, T>
{
private:
	Node<T>* current;
public:
	MatrixIterator(Node<T>* n)
	{
		current = n;
	}

	MatrixIterator operator++()
	{
		current = current->nextInRow;
		return *this;
	}

	MatrixIterator operator++ (int dummy)
	{
		MatrixIterator temp(current);
		current = current->nextInRow;
		return temp;
	}

	T& operator* ()
	{
		return current->value;
	}

	bool operator== (const MatrixIterator<T>& iterator)
	{
		return current == iterator->current;
	}
	bool operator!= (const MatrixIterator<T>& iterator)
	{
		return current != iterator->current;
	}
};

template <typename T>
class Matrix
{
public:
	Matrix();
	Matrix(int numRows, int numCols, T* headMatrixPtr); //parameterized
	Matrix(const Matrix& obj);
	Matrix(Matrix&& obj);
	virtual ~Matrix();

	Node<T>* getRow(int const row);
	Node<T>* getColumn(int const col);
	at(int const row, int const col);
	transpose(Matrix& obj);
	operator+ (const Matrix& obj);
	operator* (const Matrix& obj);
	friend istream& operator<< (ostream& os, const Matrix& matrix);
private:
	Node<T>* headMatrix;
};

#include "Matrix.cpp.h"
#endif // !MATRIX_HPP

