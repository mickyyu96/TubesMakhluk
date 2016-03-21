// Snake.cpp

#include "../header/Snake.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

using namespace std;

Snake::Snake(const Point& P) : Hewan(SNAKE_ID, SNAKE_MAXAGE)
{
	status = 1;
	power = SNAKE_BASEPOWER;
	deltaT = SNAKE_DELTAT;
	pos = P;
}
