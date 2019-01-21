//**********************************************
//Name: Blake McLachlin
//Last date revised: 02/28/18
//Program Name: matrixTest.cc
//Program function: test file for Matrix class
//**********************************************

#include "./matrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//Function Protypes
void readMatrixData(istream&, Matrix&, Matrix&);

int main()
{
	Matrix m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
	ifstream iStr;
	iStr.open("matrixdat.txt");

	readMatrixData(iStr, m1, m2);
	readMatrixData(iStr, m3, m4);

	m5 = m1 + m2;
	m6 = m1 - m2;
	m7 = m3 * m4;
	m8 = -m3;
	m9 = 5 * m1;
	m10 = m1 * 5;
	Matrix m11(m3);

	cout << "Matrix test program" << endl << endl;

	cout << "Matrix m1:" << endl << m1 << endl;

	cout << "Matrix m2:" << endl << m2 << endl;

	cout << "Matrix m5 = m1 + m2:" << endl << m5 << endl;

	cout << "Matrix m6 = m1 - m2:" << endl << m6 << endl;

	cout << "Matrix m3:" << endl << m3 << endl;

	cout << "Matrix m4:" << endl << m4 << endl;

	cout << "Matrix m7 = m3 * m4:" << endl << m7 << endl;

	cout << "Matrix m8 = -m3:" << endl << m8 << endl;

	cout << "And m3 is still:" << endl << m3 << endl;

	cout << "Matrix m9 = 5 * m1:" << endl << m9 << endl;

	cout << "Matrix m10 = m1 * 5:" << endl << m10 << endl;

	cout << "Matrix m11 becomes a copy of m3:" << endl << m11 << endl;

	cout << "End of test program. The program will now close." << endl;
	iStr.close();

	return 0;
}

//***********************************************************
//Function name: readMatrixData
//Returns: Nothing
//Purpose: Reads at most two matrices from a text file. The
//file is stored in a specific format.
//***********************************************************
void readMatrixData(istream& iStr, Matrix& matA, Matrix& matB)
{
	string line, str;
	stringstream stringIn;
	double elementType;
	char letter, dummy;
	int rows, cols;

	getline(iStr, line);
	stringIn.clear();
	stringIn.str(line);
	stringIn >> letter >> rows >> cols >> elementType;

	Matrix temp1(rows, cols, 0.0);

	getline(iStr, line);
	stringIn.clear();
	stringIn.str(line);
	stringIn >> letter >> rows >> cols >> elementType;

	Matrix temp2(rows, cols, 0.0);

	iStr >> dummy;
	iStr.ignore(100, '\n');

	for (int i = 0; i < temp1.nrows(); i++)
	{
		getline(iStr, line);
		stringIn.clear();
		stringIn.str(line);
		for (int j = 0; j < temp1.ncols(); j++)
			stringIn >> temp1(i, j);
	}

	matA = temp1;

	iStr >> dummy;
	iStr.ignore(100, '\n');

	for (int i = 0; i < temp2.nrows(); i++)
	{
		getline(iStr, line);
		stringIn.clear();
		stringIn.str(line);
		for (int j = 0; j < temp2.ncols(); j++)
			stringIn >> temp2(i, j);
	}

	matB = temp2;
}
