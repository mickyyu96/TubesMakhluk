// Turtle.cpp

#include "../header/Turtle.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Turtle::Turtle(const Point& P): Hewan(TURTLE_ID, TURTLE_MAXAGE)
{
    age = 0;
    status = 1;
    power = TURTLE_BASEPOWER;
    pos = P;
}
