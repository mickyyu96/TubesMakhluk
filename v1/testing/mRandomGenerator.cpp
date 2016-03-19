// mRandomGenerator.cpp

#include "../header/RandomGenerator.h"
#include <iostream>

using namespace std;

int main ()
{
    int randNum1, randNum2, i;

    for (i=1; i<=10; i++)
    {
        randNum1 = RandomGenerator::getInstance() -> getNextInt(10);
        randNum2 = RandomGenerator::getInstance() -> getNextIntBetween(-3, 3);
        cout << "Random Number (10) : " << randNum1  << "\tRandom Number (-3, 3) : " << randNum2 << endl;
    }

    return 0;
}
