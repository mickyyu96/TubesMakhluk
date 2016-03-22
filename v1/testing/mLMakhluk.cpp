// mLMakhluk.cpp

#include "../header/LMakhluk.h"
#include "../header/Wolf.h"
#include "../header/Sheep.h"
#include "../header/PolarBear.h"
#include "../header/RandomGenerator.h"
#include <iostream>

using namespace std;

int main()
{
    LMakhluk *_LMakhluk = new LMakhluk;

    cout << "-----Add Wolf, Sheep, PolarBear ke dalam list-----\n" << endl;
    _LMakhluk->Add(new Wolf(RandomGenerator::getInstance()->getNextPoint(5, 5)));
    _LMakhluk->Add(new Sheep(RandomGenerator::getInstance()->getNextPoint(5, 5)));
    _LMakhluk->Add(new PolarBear(RandomGenerator::getInstance()->getNextPoint(5, 5)));

    char c;
    c = _LMakhluk->getFirst()->getInfo()->getID();
    cout << "Ambil ID first makhluk dalam list : " << c << endl;

    c= _LMakhluk->getLast()->getInfo()->getID();
    cout << "Ambil ID last makhluk dalam list : " << c << endl;

    return 0;
}
