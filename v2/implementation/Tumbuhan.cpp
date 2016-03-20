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
