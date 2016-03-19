// RandomGenerator.cpp

#include "RandomGenerator.h"

RandomGenerator* RandomGenerator::_instance = new RandomGenerator;

RandomGenerator::RandomGenerator()
{
    srand ((unsigned int)time(NULL));
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
