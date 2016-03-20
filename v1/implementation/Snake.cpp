// Snake.cpp
#include "../header/Snake.h"
#include <thread>
#include <chrono>
using namespace std;

Snake::Snake() : Hewan(SNAKE_ID, SNAKE_MAXAGE)
{
    status = 1;
    power = SNAKE_BASEPOWER;
    deltaT = SNAKE_DELTAT;
    pos = Point();
}
