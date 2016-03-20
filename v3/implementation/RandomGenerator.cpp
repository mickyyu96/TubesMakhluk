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
    struct timespec ts;
    clock_gettime (CLOCK_MONOTONIC, &ts);
    srand ((time_t)ts.tv_nsec);
    lockRandom();
    std::chrono::milliseconds timespan(10);
    std::this_thread::sleep_for(timespan);
    int res = (rand() % a);
    unlockRandom();
    return res;
}

int RandomGenerator::getNextIntBetween(int a, int b)
{
    struct timespec ts;
    clock_gettime (CLOCK_MONOTONIC, &ts);
    srand ((time_t)ts.tv_nsec);
    lockRandom();
    std::chrono::milliseconds timespan(10);
    std::this_thread::sleep_for(timespan);
    int intervalLength = b-a+1;
    int res = ((rand() % intervalLength) + a);
    unlockRandom();
    return res;
}

Point RandomGenerator::getNextPoint(int NBrs, int NKol)
{
	return Point(getNextIntBetween(1, NBrs-2), getNextIntBetween(1, NKol-2));
}

Point RandomGenerator::getNextPointPB(int NBrs, int NKol)
{
	return Point(getNextIntBetween(NBrs-(NBrs/7)-2, NBrs-2), getNextIntBetween(1, NKol-2));
}

void RandomGenerator::lockRandom()
{
    randomLock.lock();
}

void RandomGenerator::unlockRandom()
{
    randomLock.unlock();
}
