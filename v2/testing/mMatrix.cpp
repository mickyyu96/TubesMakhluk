// mMatrix.cpp

#include "../header/Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix *N = new Matrix(50, 50);
	cout << "NBrs = " << N->getNBrs() << endl;
	cout << "NKol = " << N->getNKol() << endl;
	N->PrintMatrix();

	cout << "Akan diubah elemen[24][24] menjadi karakter '#'" << endl;
	N->setInfo('#',24,24);
	N->PrintMatrix();
	return 0;
}
