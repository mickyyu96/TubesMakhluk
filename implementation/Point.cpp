// Point.cpp

#include "../header/Point.h"
#define DEFAULT_X 10
#define DEFAULT_Y 10

// ctor
Point::Point()
{
	x = DEFAULT_X;
	y = DEFAULT_Y;
}

Point::Point(int _x = DEFAULT_X, int _y = DEFAULT_Y)
{
	x = _x;
	y = _y;
}

Point::Point(const Point& P)
{
	x = P.x;
	y = P.y;
}

// IMPLEMENTASI FUNCTION MEMBER
void Point::increment(int dx, int dy)
{
	x += dx; y += dy;
}
