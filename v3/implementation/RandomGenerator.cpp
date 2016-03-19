// RandomGenerator.cpp

#include "../header/RandomGenerator.h"

RandomGenerator* RandomGenerator::_instance = new RandomGenerator;

RandomGenerator::RandomGenerator()
{
    struct timespec ts;
    clock_gettime (CLOCK_MONOTONIC, &ts);
    srand ((time_t)ts.tv_nsec);
}

int RandomGenerator::getNextInt(int a)
{
    return (rand() % a);
}

int RandomGenerator::getNextIntBetween(int a, int b)
{
    int intervalLength = b-a+1;
    return ((rand() % intervalLength) + a);
}

Point RandomGenerator::getNextPoint(int NBrs, int NKol)
{
	return Point(getNextIntBetween(1, NBrs-2), getNextIntBetween(1, NKol-2));
}

Point RandomGenerator::getNextPointPolarBear(int NBrs, int NKol)
{
	return Point(getNextIntBetween(1, NBrs-2), getNextIntBetween(1, NKol-2));
}
