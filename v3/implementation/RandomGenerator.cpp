// RandomGenerator.cpp

#include "../header/RandomGenerator.h"
#include <iostream>

using namespace std;

RandomGenerator* RandomGenerator::_instance = new RandomGenerator;

RandomGenerator::RandomGenerator()
{
    struct timespec ts;
    clock_gettime (CLOCK_MONOTONIC, &ts);
    srand ((time_t)ts.tv_nsec);
}

int RandomGenerator::getNextInt(int a)
{
    usleep(10000);
    return (rand() % a);
    cout << rand() % a << endl;
}

int RandomGenerator::getNextIntBetween(int a, int b)
{
    usleep(10000);
    int intervalLength = b-a+1;
    return ((rand() % intervalLength) + a);
}

Point RandomGenerator::getNextPoint(int NBrs, int NKol)
{
	return Point(getNextIntBetween(1, NBrs-2), getNextIntBetween(1, NKol-2));
}

Point RandomGenerator::getNextPointPB(int NBrs, int NKol)
{
	return Point(getNextIntBetween(NBrs-(NBrs/5)-2, NBrs-2), getNextIntBetween(1, NKol-2));
}

void RandomGenerator::lockRandom()
{
    randomLock.lock();
}

void RandomGenerator::unlockRandom()
{
    randomLock.unlock();
}