// Wolf.cpp

#include "../header/Wolf.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

Wolf::Wolf(const Point& P) : Hewan(WOLF_ID, WOLF_MAXAGE)
{
    age = 0;
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

void Wolf::Howl()
{
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1568, 200);
    Beep(1245, 1000);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1397, 200);
    Beep(1175, 1000);
    cin.get();
}

void Wolf::Live()
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
                Hewan::Wandering();
                break;
            case 2:
                GetToFood();
                break;
            case 3:
                Howl();
                break;
        }
        Hewan::Sleep();
    }
}
