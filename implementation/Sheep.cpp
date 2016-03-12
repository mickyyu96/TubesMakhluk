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

void Sheep::GetToFood()
{
    if (Hewan::isMakhlukinList('G'))
    {
        Hewan::getToPoint(Hewan::FindFood()->getPosition());
        Hewan::FindFood()->Kill();
    }
}

void Sheep::Live()
{
    int nRandom;
    while(isAlive())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(2);
        switch (nRandom)
        {
            case 0:
                Hewan::Wandering();
                break;
            case 1:
                GetToFood();
                break;
        }
        Hewan::Sleep();
    }
}
