// World.cpp
#include "../header/World.h"
#include "../header/PolarBear.h"
#include "../header/Rabbit.h"
#include "../header/Turtle.h"
#include "../header/Matrix.h"
#include "../header/Makhluk.h"
#include "../header/LMakhluk.h"
#define DEFAULT_NBRS 20
#define DEFAULT_NKOL 20
#include <iostream>
#include <mutex>
using namespace std;

// Implementasi Static Data Member Initialization
World* World::worldInstance = new World(DEFAULT_NBRS, DEFAULT_NKOL);

// Implementasi ctor
World::World(int _NBrs, int _NKol) : NBrs(_NBrs), NKol(_NKol)
{
	_isPaused = 0; _isEnded = 0;
	objects = new LMakhluk;
}

// Implementasi PrintMap
void World::PrintMap()
{
	Matrix *map = new Matrix(getNBrs(), getNKol());
	
	LMakhluk * _LMakhluk = new LMakhluk();
    _LMakhluk->setFirst(objects->getFirst());

	if (!_LMakhluk->isEmpty()) {
		while (_LMakhluk->getFirst() != objects->getLast()) {
			if (_LMakhluk->getFirst()->getInfo()->isAlive())
			{
				char ID1 = _LMakhluk->getFirst()->getInfo()->getID();
				Point pos1 = _LMakhluk->getFirst()->getInfo()->getPosition();
				map->setInfo(ID1, pos1.getX(), pos1.getY());
			}
			_LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
		}
		if (_LMakhluk->getFirst()->getInfo()->isAlive())
		{
			char ID1 = _LMakhluk->getFirst()->getInfo()->getID();
			Point pos1 = _LMakhluk->getFirst()->getInfo()->getPosition();
			map->setInfo(ID1, pos1.getX(), pos1.getY());
		}
	}
	map->PrintMatrix();
}

void World::Show(int deltaT)
{
	while (!getWorldInstance()->isEnded())
	{
		getWorldInstance()->lockWorld();
		getWorldInstance()->PrintMap();
		getWorldInstance()->unlockWorld();

		std::chrono::milliseconds timespan(deltaT);
		std::this_thread::sleep_for(timespan);
	}
	delete getWorldInstance()->getObjects();
}

void World::changePauseState()
{
	if (isPaused())
	{
		_isPaused = 0;
		unlockWorld();
	}
	else
	{
		_isPaused = 1;
		lockWorld();
	}
}

void World::lockWorld()
{
	worldLock.lock();
}

void World::unlockWorld()
{
	worldLock.unlock();
}

