#include "Turtle.h"
#include "LMakhluk.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <thread>
#include <chrono>
using namespace std;
int dx =1;
int dy =1;

Turtle::Turtle(const Point& P): Hewan(TURTLE_ID, TURTLE_MAXAGE){
    status = 1;
    power = TURTLE_BASEPOWER;
    deltaT = TURTLE_DELTAT;
    pos = P;
    isChallange = 0;
}

