// mPoint.cpp
#include "../header/Point.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Testing default ctor" << endl;
	Point P;
	cout << P.getX() << "," << P.getY() << endl;
	
	cout << "Testing ctor dengan koordinat (42,25)" << endl;
	Point Q(42,25);
	cout << Q.getX() << "," << Q.getY() << endl;
	
	cout << "Testing cctor dengan mengopy Point yang terakhir dibuat (42,25)" << endl;
	Point R = Q;
	cout << R.getX() << "," << R.getY() << endl;

	cout << "Testing prosedur increment untuk translasi Point (42,25) dengan vektor (1,-1)" << endl;
	R.increment(1, -1);
	cout << R.getX() << "," << R.getY() << endl;
	
	cout << "Testing fungsi getDistance titik (42,25) dengan koordinat (0, 0)" << endl;
	Point S = Point(0,0);
	cout << Point::getDistance(Q, S)<< endl;
	
	return 0;
}
