// Sheep.cpp

#include "../header/Sheep.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Sheep::Sheep(const Point& P): Hewan(SHEEP_ID, SHEEP_MAXAGE)
{
    status = 1;
    power = SHEEP_BASEPOWER;
    deltaT = SHEEP_DELTAT;
    pos = P;
}
