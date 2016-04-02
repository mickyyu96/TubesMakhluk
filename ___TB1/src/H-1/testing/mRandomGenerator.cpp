// mRandomGenerator.cpp

#include "../header/RandomGenerator.h"
#include <iostream>

using namespace std;

int main ()
{
    int randNum, i;

    cout << "-----getNextInt-----" << endl;
    for (i=1; i<=3; i++)
    {
        randNum = RandomGenerator::getInstance() -> getNextInt(10);
        cout << "Random Number (10) : " << randNum << endl;
    }
    cout << endl;

    cout << "-----getNextPoint-----" << endl;
    for (i=1; i<=3; i++)
    {
        randNum = RandomGenerator::getInstance() -> getNextIntBetween(-3, 3);
        cout << "Random Number (-3 ,3) : " << randNum << endl;
    }

    system("PAUSE");
    return 0;
}
