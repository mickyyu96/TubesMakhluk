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
