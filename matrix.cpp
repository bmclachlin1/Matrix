//***********************************************
//Name: Blake McLachlin
//Last date revised: 02/28/18
//Program Name: matrix.cc
//Program function: Implementation file for
//Matrix class.
//***********************************************

#include "./matrix.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
using namespace std;

//***********************************************************
//Function name: Matrix
//Returns: Nothing
//Purpose: Default constructor which creates an empty Matrix
//object and sets data to point to nothing.
//***********************************************************
Matrix::Matrix() :
	rows(0), cols(0), data(nullptr)
{}

//***********************************************************
//Function name: Matrix
//Returns: Nothing
//Purpose: Constructor which creates a matrix object that
//sets rows, cols, and data to whatever the user declares.
//***********************************************************
Matrix::Matrix(int r, int c, double val) :
	rows(r), cols(c), data(new vector<double>(rows*cols, val))
{
	assert(rows > 0 && cols > 0);
}

//***********************************************************
//Function name: Matrix
//Returns: Nothing
//Purpose: Copy constructor for Matrix object
//***********************************************************
Matrix::Matrix(const Matrix& m) :
	rows(m.nrows()), cols(m.ncols()), data(new vector<double>(rows*cols, 0.0))
{
	for (unsigned int i = 0; i < data->size(); i++)
		data->at(i) = m.data->at(i);
}


//***********************************************************
//Function name: ~Matrix
//Returns: Nothing
//Purpose: Destructor for Matrix object
//***********************************************************
Matrix::~Matrix()
{
	delete data;
	data = nullptr;
}

//***********************************************************
//Function name: operator()
//Returns: double
//Purpose: Returns value in the i'th row and j'th column
//in a matrix. Uses row mapping formula.
//***********************************************************
double& Matrix::operator()(int i, int j)
{
	assert(i >= 0 && j >= 0 && i < rows && j < cols);
	return data->at(i*cols + j);
}

//***********************************************************
//Function name: operator() - const
//Returns: double
//Purpose: Returns value in the i'th row and j'th column
//in the matrix. Uses row mapping formula. Is for const
//object
//***********************************************************
const double& Matrix::operator()(int i, int j) const
{
	assert(i >= 0 && j >= 0 && i < rows && j < cols);
	return data->at(i*cols + j);
}

//***********************************************************
//Function name: ncols 
//Returns: int
//Purpose: Returns the number of columns in a matrix object
//***********************************************************
int Matrix::ncols()
{
	return cols;
}

//***********************************************************
//Function name: nrows
//Returns: int
//Purpose: Returns the number of rows in a matrix object
//***********************************************************
int Matrix::nrows()
{
	return rows;
}

//***********************************************************
//Function name: ncols - const
//Returns: int
//Purpose: Returns the number of columns in a const matrix
//object
//***********************************************************
int Matrix::ncols() const
{
	return cols;
}

//***********************************************************
//Function name: nrows - const
//Returns: int
//Purpose: Returns the number of rows in a const matrix
//object
//***********************************************************
int Matrix::nrows() const
{
	return rows;
}

//***********************************************************
//Function name: operator=
//Returns: Matrix
//Purpose: Performs deep copy assignment of Matrix
//***********************************************************
Matrix& Matrix::operator=(const Matrix& m)
{
	if (this != &m)
	{
		delete data;
		rows = m.nrows();
		cols = m.ncols();
		data = new vector<double>(rows*cols, 0.0);
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				(*this)(i, j) = m(i, j);
	}
	return *this;
}

//***********************************************************
//Function name: operator+=
//Returns: Matrix
//Purpose: Assigns a Matrix to itself plus another Matrix
//***********************************************************
Matrix& Matrix::operator+=(const Matrix& x)
{
	assert(rows == x.nrows() && cols == x.ncols());
	for (unsigned int i = 0; i < data->size(); i++)
		data->at(i) += x.data->at(i);
	return *this;
}

//***********************************************************
//Function name: operator-=
//Returns: Matrix
//Purpose: Assigns a Matrix to itself minus another Matrix
//***********************************************************
Matrix& Matrix::operator-=(const Matrix& x)
{
	assert(rows == x.nrows() && cols == x.ncols());
	for (unsigned int i = 0; i < data->size(); i++)
		data->at(i) -= x.data->at(i);
	return *this;
}

//***********************************************************
//Function name: operator*=
//Returns: Matrix
//Purpose: Assigns a Matrix to itself times a another Matrix
//***********************************************************
Matrix& Matrix::operator*=(const Matrix& m)
{
	assert(cols == m.nrows());
	Matrix temp(rows, m.ncols(), 0.0);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < m.ncols(); j++)
			for (int k = 0; k < cols; k++)
				(temp)(i, j) += (*this)(i, k) * m(k, j);
	*this = temp;
	return *this;
}

//***********************************************************
//Function name: operator*=
//Returns: Matrix
//Purpose: Assigns a Matrix to itself times a scalar multiple
//***********************************************************
Matrix& Matrix::operator*=(double d)
{
	for (unsigned int i = 0; i < data->size(); i++)
		data->at(i) *= d;
	return *this;
}

//***********************************************************
//Function name: operator<<
//Returns: ostream
//Purpose: Outputs a Matrix object to the screen
//***********************************************************
ostream& operator<<(ostream& oStr, const Matrix &m)
{
	for (int i = 0; i<m.nrows(); i++)
	{
		oStr << "|";
		for (int j = 0; j<m.ncols(); j++)
			oStr << setw(5) << m(i, j);
		oStr << setw(5) << " |" << endl;
	}
	return oStr;
}

//***********************************************************
//Function name: operator-
//Returns: Matrix
//Purpose: Returns the unary minus operator of a matrix
//***********************************************************
Matrix operator-(const Matrix &m)
{
	Matrix temp(m);
	temp *= -1;
	return temp;
}

//***********************************************************
//Function name: operator+
//Returns: Matrix
//Purpose: Adds two Matrices together
//***********************************************************
Matrix operator+(const Matrix& l, const Matrix& r)
{
	Matrix temp(l);
	temp += r;
	return temp;
}

//***********************************************************
//Function name: operator-
//Returns: Matrix
//Purpose: Subtracts two Matrices
//***********************************************************
Matrix operator-(const Matrix& l, const Matrix& r)
{
	Matrix temp(l);
	temp -= r;
	return temp;
}

//***********************************************************
//Function name: operator*
//Returns: Matrix
//Purpose: Multiplies two matrices together
//***********************************************************
Matrix operator*(const Matrix& l, const Matrix&r)
{
	Matrix temp(l);
	temp *= r;
	return temp;
}

//***********************************************************
//Function name: operator*
//Returns: Matrix
//Purpose: Multiplies a matrix by a scalar multiple
//***********************************************************
Matrix operator*(double d, const Matrix& m)
{
	Matrix temp(m);
	temp *= d;
	return temp;
}

//***********************************************************
//Function name: operator*
//Returns: Matrix
//Purpose: Multiplies a matrix by a scalar multiple
//***********************************************************
Matrix operator*(const Matrix& m, double d)
{
	Matrix temp(m);
	temp *= d;
	return temp;
}
