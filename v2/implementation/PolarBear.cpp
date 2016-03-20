// PolarBear.cpp

#include "../header/PolarBear.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

using namespace std;

PolarBear::PolarBear(const Point& P) : Hewan(POLARBEAR_ID, POLARBEAR_MAXAGE)
{
	status = 1;
	power = POLARBEAR_BASEPOWER;
	deltaT = POLARBEAR_DELTAT;
	pos = P;
}
