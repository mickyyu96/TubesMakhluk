// Tumbuhan.cpp

#include "../header/Tumbuhan.h"
#include "../header/Point.h"
#include <thread>
#include <chrono>
using namespace std;

Tumbuhan::Tumbuhan(const Point& P) : Makhluk(TUMBUHAN_ID, TUMBUHAN_MAXAGE)
{
	status = 1;
	age = 0;
	pos = P;
}

void Tumbuhan::Live()
{
    while (isAlive() && !World::getWorldInstance()->isEnded())
    {
    }
}
