// mMatrix.cpp
#include "../header/Matrix.h"
using namespace std;

int main()
{
	Matrix *M = new Matrix();
	M->PrintMatrix();

	Matrix *N = new Matrix(50, 50);
	N->PrintMatrix();

	N->setInfo('#',24,24);
	N->PrintMatrix();
	return 0;
}
