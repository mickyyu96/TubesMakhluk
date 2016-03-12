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

/*
int PolarBear::shouldRebounced(int dx, int dy)
{
    if (dx+pos.getX()<=0 || dx+pos.getX()>=World::getWorldInstance()->getNBrs()-1) {
        return 1;    }
    if (dy+pos.getY()<=0 || dy+pos.getY()>=World::getWorldInstance()->getNKol()-1) {
        return 1;
    }
    return 0;
} */

/*
void PolarBear::Wandering()
{
    int dx = 2;
    int dy = 2;
    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    if (nRandom == 1) {
        for (int i = 0; i<20; i++) {
            if (Hewan::shouldRebounced(dx, 0)) {
                dx *= -1;
            }
            if (Hewan::shouldRebounced(0, dy)) {
                dy *= -1;
            }

            Hewan::Move(dx, dy);
            std::chrono::milliseconds timespan(Hewan::getDeltaT());
            std::this_thread::sleep_for(timespan);
        }
    }
    else{
        for (int i = 0; i<20; i++) {
            if (Hewan::shouldRebounced(dx, 0) && Hewan::shouldRebounced(0, dy)) {
                dx = 0;
                dy = 2;
                if (Hewan::shouldRebounced(0, dy)) {
                    dy *= -1;
                }
            }
            if (Hewan::shouldRebounced(0, dy)) {
                dy = 0;
                dx = 2;
                if (Hewan::shouldRebounced(dx, 0)) {
                    dx *= -1;
                }
            }
            else if (Hewan::shouldRebounced(dx, 0)){
                dx = 0;
                dy = 2;
                if (Hewan::shouldRebounced(0, dy)) {
                    dy *= -1;
                }
            }
            Hewan::Move(dx, dy);
            std::chrono::milliseconds timespan(Hewan::getDeltaT());
            std::this_thread::sleep_for(timespan);
        }
    }
} */

void PolarBear::Live()
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
