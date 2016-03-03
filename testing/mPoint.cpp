// mPoint.cpp
#include "../header/Point.h"
#include <iostream>
using namespace std;

int main()
{
	Point P;
	cout << P.getX() << "," << P.getY() << endl;
	
	Point Q(42,25);
	cout << Q.getX() << "," << Q.getY() << endl;
	
	Point R = Q;
	cout << R.getX() << "," << R.getY() << endl;

	R.increment(1, -1);
	cout << R.getX() << "," << R.getY() << endl;
	
	return 0;
}
