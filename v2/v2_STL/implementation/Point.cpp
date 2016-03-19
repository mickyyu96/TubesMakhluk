// Point.cpp

#include "Point.h"
#define DEFAULT_X 10
#define DEFAULT_Y 10

// ctor
Point::Point()
{
	x = DEFAULT_X;
	y = DEFAULT_Y;
}

Point::Point(int _x, int _y)
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

int Point::getDistance(Point& P1, Point& P2)
{
	int dx = P1.getX() - P2.getX();
	int dy = P1.getY() - P2.getY();
	return (int)sqrt((double)dx*dx + dy*dy);
}