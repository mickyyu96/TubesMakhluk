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
    deltaT = SHEEP_DELTAT;
    pos = P;
}

void Sheep::GetToFood()
{
    if (Hewan::isMakhlukinList('G'))
    {
    	Makhluk * Food = Hewan::FindFood();
    	if(Food != NULL)
    	{
	        Hewan::getToPoint(Food->getPosition());
	        Food->Kill();
	    }
    }
}

void Sheep::WanderingS()
{
    Hewan::getToPoint(Point(1, 1));
    Hewan::getToPoint(Point(1, World::getWorldInstance()->getNKol()-2));
    Hewan::getToPoint(Point(World::getWorldInstance()->getNBrs()-2, World::getWorldInstance()->getNKol()-2));
    Hewan::getToPoint(Point(World::getWorldInstance()->getNBrs()-2, 1));
    Hewan::getToPoint(Point(1, 1));
}

void Sheep::Live()
{
    int nRandom;
    while(isAlive() && !World::getWorldInstance()->isEnded())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(4);
        switch (nRandom)
        {
            case 0:
                Hewan::Wandering();
                break;
            case 1:
                WanderingS();
                break;
            case 2:
                GetToFood();
                break;
            case 3:
                WanderingS();
                break;
        }
        Hewan::Sleep();
    }
}