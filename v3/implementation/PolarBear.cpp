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

int PolarBear::shouldRebouncedPB(int dx, int dy)
{
    if ((dx+pos.getX()<=World::getWorldInstance()->getNBrs()-(World::getWorldInstance()->getNBrs()/5)-3) ||
        (dx+pos.getX()>=World::getWorldInstance()->getNBrs()-1))
    {
        return 1;
    }
    if (dy+pos.getY()<=0 || dy+pos.getY()>=World::getWorldInstance()->getNKol()-1)
    {
        return 1;
    }
    return 0;
}

void PolarBear::WanderingPB()
{
    int dx = 1;
    int dy = 1;
    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    if (nRandom == 1)
    {
        for (int i=0; i<20; i++)
        {
            if (shouldRebouncedPB(dx, 0))
            {
                dx *= -1;
            }
            if (shouldRebouncedPB(0, dy))
            {
                dy *= -1;
            }
            Hewan::Move(dx, dy);
            Sleep();
        }
    }
    else
    {
        for (int i=0; i<20; i++)
        {
            if (shouldRebouncedPB(dx, 0) && shouldRebouncedPB(0, dy))
            {
                dx = 0;
                dy = 1;
                if (shouldRebouncedPB(0, dy))
                {
                    dy *= -1;
                }
            }
            if (shouldRebouncedPB(0, dy))
            {
                dy = 0;
                dx = 1;
                if (shouldRebouncedPB(dx, 0))
                {
                    dx *= -1;
                }
            }
            else if (shouldRebouncedPB(dx, 0))
            {
                dx = 0;
                dy = 1;
                if (shouldRebouncedPB(0, dy))
                {
                    dy *= -1;
                }
            }
            Move(dx, dy);
            Sleep();
        }
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
                WanderingPB();
                break;
            case 1:
                GetToFood();
                break;
        }
        Hewan::Sleep();
    }
}
