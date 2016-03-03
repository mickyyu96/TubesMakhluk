// PolarBear.cpp
#include "../header/PolarBear.h"
#include <thread>
#include <chrono>
using namespace std;

// ctor
PolarBear::PolarBear() : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE, POLARBEAR_BASEPOWER, POLARBEAR_DELTAT, Point())
{
}

PolarBear::PolarBear(const Point& P) : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE, POLARBEAR_BASEPOWER, POLARBEAR_DELTAT, P)
{
}

// actions
void PolarBear::FindFood()
{

}
void PolarBear::Sleep(int duration)
{
	std::chrono::milliseconds timespan(duration);
	std::this_thread::sleep_for(timespan);
}


// main action
void PolarBear::Live()
{
	int counter = 5;
	while(isAlive())
	{
		Hewan::Move(1,1);
		
		World::getWorldInstance()->PrintMap();

		if (!counter) Kill();
		else counter--;

		std::chrono::milliseconds timespan(getDeltaT());
		std::this_thread::sleep_for(timespan);
	}
	World::getWorldInstance()->PrintMap();
}