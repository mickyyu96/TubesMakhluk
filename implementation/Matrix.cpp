// Matrix.cpp
#include "../header/Matrix.h"
#include <cstring>
#include <iostream>
#define DEFAULT_NBRS 20
#define DEFAULT_NKOL 20
using namespace std;

// Implementasi ctor, cctor, dtor, operator=
Matrix::Matrix(int _NBrs = DEFAULT_NBRS, int _NKol = DEFAULT_NKOL) : NBrs(_NBrs), NKol(_NKol)
{
	M = new char* [NBrs];
	for(int i=0; i<NBrs; i++)
		M[i] = new char [NKol];
	
	for(int i=0; i<NBrs; i++)
		for(int j=0; j<NKol; j++)
			M[i][j] = '.';
	
	for(int i=0; i<NBrs; i++)
		M[i][0] = M[i][NKol-1] = '#';
	
	for(int i=0; i<NKol; i++)
		M[0][i] = M[NBrs-1][i] = '#';
}

Matrix::Matrix(const Matrix& Mat) : NBrs(Mat.getNBrs()), NKol(Mat.getNKol())
{
	M = new char* [NBrs];
	for(int i=0; i<NBrs; i++)
		M[i] = new char [NKol];
	
	for(int i=0; i<NBrs; i++)
		for(int j=0; j<NKol; j++)
			M[i][j] = '.';
	
	for(int i=0; i<NBrs; i++)
		M[i][0] = M[i][NKol-1] = '#';
	
	for(int i=0; i<NKol; i++)
		M[0][i] = M[NBrs-1][i] = '#';
}

Matrix::~Matrix()
{
	for(int i=0; i<NBrs; i++)
		delete [] M[i];
	delete [] M;
}

// Implementasi Getter & Setter
char Matrix::getInfo(int i, int j) const { return M[i][j]; }
void Matrix::setInfo(char c, int i, int j) { M[i][j] = c; }

// Implementasi PrintMatrix()
void Matrix::PrintMatrix() const
{
	for(int i=0; i<NBrs; i++)
	{
		for(int j=0; j<NKol; j++)
		{
			cout << getInfo(i,j);
		}
		cout << endl;
	}
}
