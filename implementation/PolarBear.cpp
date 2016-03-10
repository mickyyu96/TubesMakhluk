// PolarBear.cpp
#include "../header/PolarBear.h"
#include <thread>
#include <chrono>
using namespace std;

// ctor

PolarBear::PolarBear(const Point& P) : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE)
{
	status = 1; age = 0;
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
	int counter = 5;
	while (isAlive() && !World::getWorldInstance()->isEnded())
	{
		Hewan::Move(1,1);
		
		// World::getWorldInstance()->PrintMap();

		std::chrono::milliseconds timespan(getDeltaT());
		std::this_thread::sleep_for(timespan);
		
		if (counter) counter--;
		else Kill();
	}
	// World::getWorldInstance()->PrintMap();
}
