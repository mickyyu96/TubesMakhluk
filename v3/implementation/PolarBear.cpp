// PolarBear.cpp

#include "../header/PolarBear.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

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
    RandomGenerator::getInstance()->lockRandom();
    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    RandomGenerator::getInstance()->unlockRandom();
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

void PolarBear::Hibernate()
{
    Hewan::getToPoint(Point(World::getWorldInstance()->getNBrs()-2, 1));
    std::chrono::milliseconds timespan(9000);
    std::this_thread::sleep_for(timespan);
}

void PolarBear::Live()
{
    int nRandom;
    while(isAlive() && !World::getWorldInstance()->isEnded())
    {
        RandomGenerator::getInstance()->lockRandom();
        usleep(10000);
        nRandom = RandomGenerator::getInstance()->getNextInt(5);
        RandomGenerator::getInstance()->unlockRandom();
        switch (nRandom)
        {
            case 0:
                WanderingPB();
                break;
            case 1:
                WanderingPB();
                break;
            case 2:
                Hibernate();
                break;
            case 3:
                GetToFood();
                break;
            case 4:
                GetToFood();
                break;
        }
        Hewan::Sleep();
    }
}
