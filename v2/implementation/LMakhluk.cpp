// LMakhluk.cpp

#include "../header/LMakhluk.h"
using namespace std;

LMakhluk::LMakhluk()
{
}

LMakhluk::~LMakhluk()
{
    int size = getSize();
    for(int i=0; i<size; i++)
    {
    	delete makhlukVector[i];
    }
}

void LMakhluk::Add(Makhluk* M)
{
    makhlukVector.push_back(M);
}

int LMakhluk::IsAllMakhlukDead()
{
    int i=0;
    while (i<getSize())
    {
        if (getInfo(i)->isAlive())
        {
            return 0;
        }
        else { i++; }
    }
    if (getInfo(i)->isAlive())
    {
        return 0;
    }
    return 1;
}
