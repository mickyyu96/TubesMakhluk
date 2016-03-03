// Hewan.cpp
#include "../header/Hewan.h"
using namespace std;

Hewan::Hewan(char _ID, int _maxAge, int _power, int _deltaT, const Point& P) : Makhluk(_ID, _maxAge, P)
{
	hungerLvl = 100;
	power = _power;
	deltaT = _deltaT;
}

void Hewan::Move(int dx, int dy)
{
	pos.increment(dx, dy);
}
