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
    if (Hewan::isMakhlukinList('S')||Hewan::isMakhlukinList('R')||Hewan::isMakhlukinList('T')||Hewan::isMakhlukinList('U'))
    {
        Makhluk * Food = FindFood();
        if(Food != NULL)
        {
        	Point PWolf = getPosition();
	        Point PFood = Food->getPosition();
	        while (Point::getDistance(PWolf, PFood)<10 && Food->isAlive())
	        {
	            Hewan::moveTowardPoint(Food->getPosition());
	            PWolf = getPosition();
	            if (Food->getPosition().getX()==getPosition().getX() && Food->getPosition().getY()== getPosition().getY()) {Food->Kill(); break;}
	            else{PFood = Food->getPosition();}
	        }
        }
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
                Wandering();
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
