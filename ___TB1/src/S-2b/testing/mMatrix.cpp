// mMatrix.cpp

#include "../header/Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	Matrix *N = new Matrix(50, 50);

	cout << "Melihat apakah Ctor berhasil?" << endl;
	cout << "NBrs = " << N->getNBrs() << endl;
	cout << "NKol = " << N->getNKol() << endl;
	cout << N->getInfo(24,24) << endl;

	cout << "Akan diubah elemen[24][24] menjadi karakter '#'" << endl;
	N->setInfo('#',24,24);
	cout << N->getInfo(24,24) << endl;

    system("PAUSE");
	return 0;
}
