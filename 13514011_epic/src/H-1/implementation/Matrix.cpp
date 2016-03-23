// Matrix.cpp

#include "../header/Matrix.h"
#include <cstring>
#include <iostream>
#define DEFAULT_NBRS 20
#define DEFAULT_NKOL 20
using namespace std;

Matrix::Matrix(int _NBrs, int _NKol) : NBrs(_NBrs), NKol(_NKol)
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

char Matrix::getInfo(int i, int j) const { return M[i][j]; }

void Matrix::setInfo(char c, int i, int j) { M[i][j] = c; }
