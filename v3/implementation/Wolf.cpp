// Wolf.cpp

#include "../header/Wolf.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Wolf::Wolf(const Point& P) : Hewan(WOLF_ID, WOLF_MAXAGE)
{
    status = 1;
    power = WOLF_BASEPOWER;
    deltaT = WOLF_DELTAT;
    pos = P;
}

void Wolf::GetToFood()
{
    if (Hewan::isMakhlukinList('*'))
    {
        Hewan::getToPoint(Hewan::FindFood()->getPosition());
        Hewan::FindFood()->Kill();
    }
}

void Wolf::Live()
{
    int nRandom;
    while(isAlive() && !World::getWorldInstance()->isEnded())
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
