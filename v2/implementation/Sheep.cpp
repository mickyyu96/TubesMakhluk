// Sheep.cpp

#include "../header/Sheep.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Sheep::Sheep(const Point& P): Hewan(SHEEP_ID, SHEEP_MAXAGE)
{
    age = 0;
    status = 1;
    power = SHEEP_BASEPOWER;
    pos = P;
}
