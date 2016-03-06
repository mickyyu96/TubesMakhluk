// RandomGenerator.cpp

#include "../header/RandomGenerator.h"

RandomGenerator* RandomGenerator::_instance = new RandomGenerator;

RandomGenerator::RandomGenerator()
{
    srand (time(NULL));
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
