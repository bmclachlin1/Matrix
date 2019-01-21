//***********************************************
//Name: Blake McLachlin
//Last date revised: 02/28/18
//Program Name: matrix.h
//Program function: Header file for Matrix class
//***********************************************

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
using namespace std;

class Matrix {

public:
	//Default constructor
	Matrix();

	//Constructor
	Matrix(int r, int c, double val);

	//Copy constructer
	Matrix(const Matrix& m);

	//Destructor
	~Matrix();

	//Index operators
	double& operator()(int i, int j);
	const double& operator()(int i, int j) const;

	//Copy assignment operator
	Matrix& operator=(const Matrix& m);

	//Compound  operators
	Matrix& operator+=(const Matrix& x);
	Matrix& operator-=(const Matrix& x);
	Matrix& operator*=(const Matrix& m);
	Matrix& operator*=(double d);

	//return number of rows or cols
	int ncols();
	int nrows();
	int ncols() const;
	int nrows() const;

private:
	//number of rows and columns
	int rows, cols;
	//pointer to vector to hold matrix elements
	vector<double> *data;
};

//Arithmetic operators are not members
Matrix operator-(const Matrix& m); //return -m
Matrix operator+(const Matrix& l, const Matrix&r); // return l+r
Matrix operator-(const Matrix& l, const Matrix&r); // return l-r

Matrix operator*(const Matrix& l, const Matrix&r); // return l*r
Matrix operator*(double d, const Matrix& m); // return d*m
Matrix operator*(const Matrix& m, double d);// return m*d

											// Overloaded stream insertion operator
ostream& operator<<(ostream& out, const Matrix& x);

#endif
