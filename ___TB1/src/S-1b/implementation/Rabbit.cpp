// Rabbit.cpp

#include "../header/Rabbit.h"
#include <thread>
#include <chrono>
using namespace std;

Rabbit::Rabbit(const Point& P): Hewan(RABBIT_ID, RABBIT_MAXAGE)
{
    age = 0;
    status = 1;
    power = RABBIT_BASEPOWER;
    pos = P;
}
