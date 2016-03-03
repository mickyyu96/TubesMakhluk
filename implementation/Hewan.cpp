// Hewan.cpp
#include "../header/Hewan.h"
using namespace std;

// Implementasi Ctor
Hewan::Hewan(char _ID, int _maxAge) : Makhluk(_ID, _maxAge)
{
}

void Hewan::Move(int dx, int dy)
{
	pos.increment(dx, dy);
}
