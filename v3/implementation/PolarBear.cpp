// PolarBear.cpp

#include "../header/PolarBear.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

PolarBear::PolarBear(const Point& P) : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE)
{
	status = 1;
	power = POLARBEAR_BASEPOWER;
	deltaT = POLARBEAR_DELTAT;
	pos = P;
}

void PolarBear::GetToFood()
{
    if (Hewan::isMakhlukinList('*'))
    {
        Hewan::getToPoint(Hewan::FindFood()->getPosition());
        Hewan::FindFood()->Kill();
    }
}

void PolarBear::Live()
{
    int nRandom;
    while(isAlive() && !World::getWorldInstance()->isEnded())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(2);
        switch (nRandom)
        {
            case 0:
                Wandering();
                break;
            case 1:
                GetToFood();
                break;
        }
        Hewan::Sleep();
    }
}
