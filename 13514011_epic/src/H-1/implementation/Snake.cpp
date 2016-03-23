// Snake.cpp

#include "../header/Snake.h"
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;

Snake::Snake(const Point& P): Hewan(SNAKE_ID, SNAKE_MAXAGE)
{
    age = 0;
    status = 1;
    power = SNAKE_BASEPOWER;
    deltaT = SNAKE_DELTAT;
    pos = P;
}

void Snake::GetToFood()
{
    if (Hewan::isMakhlukinList('S')||Hewan::isMakhlukinList('R')||Hewan::isMakhlukinList('T'))
    {
        Makhluk * Food = FindFood();
        if(Food != NULL)
        {
        	Point PSnake = getPosition();
	        Point PFood = Food->getPosition();
	        while (Point::getDistance(PSnake, PFood)<10 && Food->isAlive())
	        {
	            Hewan::moveTowardPoint(Food->getPosition());
	            PSnake = getPosition();
	            if (Food->getPosition().getX()==getPosition().getX() && Food->getPosition().getY()== getPosition().getY()) {Food->Kill(); break;}
	            else{PFood = Food->getPosition();}
	        }
        }
    }
}

void Snake::ZigZag()
{
    int dx, dy;

    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    switch (nRandom)
    {
        case 0 :
        {
            if (Hewan::shouldRebounced(0,1))
            {
                Hewan::Move(0,-1);
            }
            else
            {
                Hewan::Move(0,1);
            }
            break;
        }

        case 1 :
        {
            if (Hewan::shouldRebounced(0,-1))
            {
                Hewan::Move(0,1);
            }
            else
            {
                Hewan::Move(0,-1);
            }
            break;
        }
    }
    std::chrono::milliseconds timespan(deltaT);
    std::this_thread::sleep_for(timespan);

    nRandom = RandomGenerator::getInstance()->getNextInt(2);
    switch (nRandom)
    {
        case 0 :
        {
            if (Hewan::shouldRebounced(1,0))
            {
                Hewan::Move(-1,0);
            }
            else
            {
                Hewan::Move(1,0);
            }
            break;
        }
        case 1 :
        {
            if (Hewan::shouldRebounced(-1,0))
            {
                Hewan::Move(1,0);
            }
            else
            {
                Hewan::Move(-1,0);
            }
            break;
        }
    }
    std::this_thread::sleep_for(timespan);
}

void Snake::Live()
{
    int nRandom;
    while (isAlive() && !World::getWorldInstance()->isEnded())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(2);
        switch (nRandom)
        {
            case 0:
            {
                for(int i=0; i<10; i++) ZigZag();
                break;
            }
            case 1:
            {
                GetToFood();
                break;
            }
        }
        Hewan::Sleep();
    }
}
