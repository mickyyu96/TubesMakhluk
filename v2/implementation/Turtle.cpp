#include "../header/Turtle.h"
#include "../header/LMakhluk.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Turtle::Turtle(const Point& P): Hewan(TURTLE_ID, TURTLE_MAXAGE){
    status = 1;
    power = TURTLE_BASEPOWER;
    deltaT = TURTLE_DELTAT;
    pos = P;
}
