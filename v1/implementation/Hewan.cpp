// Hewan.cpp

#include "../header/Hewan.h"
#include "../header/LMakhluk.h"
#include <thread>
#include <chrono>

using namespace std;

Hewan::Hewan(char _ID, int _maxAge) : Makhluk(_ID, _maxAge)
{
}

void Hewan::Move(int dx, int dy)
{
	World::getWorldInstance()->lockWorld();
	pos.increment(dx, dy);
	World::getWorldInstance()->unlockWorld();
}

int Hewan::shouldRebounced(int dx, int dy)
{
    if (dx+pos.getX()<=0 || dx+pos.getX()>=World::getWorldInstance()->getNBrs()-1)
    {
        return 1;
    }
    if (dy+pos.getY()<=0 || dy+pos.getY()>=World::getWorldInstance()->getNKol()-1)
    {
        return 1;
    }
    return 0;
}
