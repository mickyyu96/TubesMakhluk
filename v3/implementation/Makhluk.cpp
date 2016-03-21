// Makhluk.cpp

#include "../header/Makhluk.h"
#include "../header/World.h"
#include <iostream>
using namespace std;

void Makhluk::MakeAlive(Makhluk* M)
{
	M->Live();
}

Makhluk::Makhluk(char _ID, int _maxAge) : ID(_ID), maxAge(_maxAge)
{
}
