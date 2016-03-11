#include "../header/Tumbuhan.h"
#include "../header/Point.h"
#include <thread>
#include <chrono>
using namespace std;

Tumbuhan::Tumbuhan() : Makhluk(TUMBUHAN_ID, TUMBUHAN_MAXAGE) {
    age = 0;
    status = 1;
    pos = Point();
}

Tumbuhan::Tumbuhan(const Point& P) : Makhluk(TUMBUHAN_ID, TUMBUHAN_MAXAGE)
{
	status = 1;
	age = 0;
	pos = P;
}

void Tumbuhan::Live() {
    while (isAlive()) {

        AgeIncrement();
        std::chrono::miliseconds timespan(500);
        std::this_thread::sleep_for(timespan);
        if (getAge()>=getMaxAge()) {Kill();}
    }
}
