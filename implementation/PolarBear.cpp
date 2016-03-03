// PolarBear.cpp
#include "../header/PolarBear.h"
#include <thread>
#include <chrono>
using namespace std;

// ctor
PolarBear::PolarBear() : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE)
{
	status = 1;
	power = POLARBEAR_BASEPOWER;
	deltaT = POLARBEAR_DELTAT;
	pos = Point();
}

PolarBear::PolarBear(const Point& P) : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE)
{
	status = 1;
	power = POLARBEAR_BASEPOWER;
	deltaT = POLARBEAR_DELTAT;
	pos = P;
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
	while(isAlive())
	{
		Hewan::Move(1,1);
		
		World::getWorldInstance()->PrintMap();

		std::chrono::milliseconds timespan(getDeltaT());
		std::this_thread::sleep_for(timespan);
	}
	World::getWorldInstance()->PrintMap();
}