// LMakhluk.cpp
#include <iostream>
#include "../header/LMakhluk.h"
#include "../header/World.h"
using namespace std;

LMakhluk::LMakhluk()
{
    first = NULL;
	thread_count = 0;
}

LMakhluk::~LMakhluk()
{
    while (!isEmpty())
    {
        Del(getLast()->getInfo());
    }
}

void LMakhluk::Add(Makhluk* M)
{
    ElmtMakhluk* EM = new ElmtMakhluk(M, NULL);
	if (isEmpty())
    {
        first = EM;
    }
    else
    {
        ElmtMakhluk* P = getLast();
		P->setNext(EM);
    }
}

void LMakhluk::Del(Makhluk* M)
{
    ElmtMakhluk* EM;
    ElmtMakhluk* _EM;
    EM = findMakhluk(M);
    _EM = findPrecMakhluk(M);
    if (EM == getFirst())
    {
        setFirst(NULL);
    }
    else
    {
        _EM->setNext(EM->getNext());
        delete EM;
    }
}

LMakhluk::ElmtMakhluk::ElmtMakhluk()
{
    info = NULL;
    next = NULL;
}

LMakhluk::ElmtMakhluk::ElmtMakhluk(Makhluk* _info, ElmtMakhluk* _next)
{
    info = _info;
    next = _next;
}

LMakhluk::ElmtMakhluk::~ElmtMakhluk()
{
    delete getInfo();
}

LMakhluk::ElmtMakhluk* LMakhluk::getLast()
{
    ElmtMakhluk* EM;
    EM = getFirst();
    while (EM->getNext() != NULL)
    {
        EM = EM->getNext();
    }
    return EM;
}

LMakhluk::ElmtMakhluk* LMakhluk::findPrecMakhluk(Makhluk* M)
{
    ElmtMakhluk* EM;
    EM = getFirst();
    if (EM->getInfo() == getFirst()->getInfo())
    {
        return NULL;
    }
    else
    {
        while ((EM->getNext())->getInfo() != M)
        {
            EM = EM->getNext();
        }
        return EM;
    }
}

LMakhluk::ElmtMakhluk* LMakhluk::findMakhluk(Makhluk* M)
{
    ElmtMakhluk* EM;
    EM = getFirst();
    while (EM->getInfo() != M)
    {
        EM = EM->getNext();
    }
    return EM;
}

int LMakhluk::getSize()
{
	ElmtMakhluk* P = getFirst();
	int size = 0;
	while (P != NULL)
	{
		P = P->getNext();
		size++;
	}
	return size;
}

Makhluk* LMakhluk::getInfo(int idx)
{
	ElmtMakhluk* P = getFirst();
	for (int i = 0; i < idx; i++)
	{
		P = P->getNext();
	}
	return P->getInfo();
}

int LMakhluk::IsAllMakhlukDead()
{
    ElmtMakhluk *EM;
    EM = getFirst();
    while (EM != getLast())
    {
        if (EM->getInfo()->isAlive())
        {
            return 0;
        }
        else {
            EM = EM->getNext();
        }
    }
    if (EM->getInfo()->isAlive())
    {
        return 0;
    }
    return 1;
}
