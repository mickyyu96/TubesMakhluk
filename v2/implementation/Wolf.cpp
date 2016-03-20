// Wolf.cpp

#include "../header/Wolf.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Wolf::Wolf(const Point& P) : Hewan(WOLF_ID, WOLF_MAXAGE)
{
    status = 1;
    power = WOLF_BASEPOWER;
    deltaT = WOLF_DELTAT;
    pos = P;
}
