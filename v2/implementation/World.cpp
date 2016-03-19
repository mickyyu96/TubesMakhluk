// World.cpp
#include "World.h"
#include "LMakhluk.h"

World::World(int _NBrs, int _NKol) : NBrs(_NBrs), NKol(_NKol)
{
	_isPaused = 0; _isEnded = 0;
	objects = new LMakhluk;
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

void World::singleStepExecution()
{
	unlockWorld();

	std::chrono::milliseconds timespan(250); // HATI2 HARUS DIUBAH
	std::this_thread::sleep_for(timespan);

	lockWorld();
}