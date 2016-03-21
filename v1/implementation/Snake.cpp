// Snake.cpp

#include "../header/Snake.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Snake::Snake(const Point& P) : Hewan(SNAKE_ID, SNAKE_MAXAGE)
{
    age = 0;
	status = 1;
	power = SNAKE_BASEPOWER;
	pos = P;
}
