// Hewan.cpp
#include "Hewan.h"
#include "LMakhluk.h"
#include <thread>
#include <chrono>

using namespace std;


// Implementasi Ctor
Hewan::Hewan(char _ID, int _maxAge) : Makhluk(_ID, _maxAge)
{
}

void Hewan::Move(int dx, int dy)
{
	World::getWorldInstance()->lockWorld();
	pos.increment(dx, dy);
	World::getWorldInstance()->unlockWorld();
}

void Hewan::Sleep()
{
    std::chrono::milliseconds timespan(deltaT);
    std::this_thread::sleep_for(timespan);
}

int Hewan::shouldRebounced(int dx, int dy){
    if (dx+pos.getX()<=0 || dx+pos.getX()>=World::getWorldInstance()->getNBrs()-1) {
        return 1;    }
    if (dy+pos.getY()<=0 || dy+pos.getY()>=World::getWorldInstance()->getNKol()-1) {
        return 1;
    }
    return 0;
}
