// Makhluk.cpp
#include "../header/Makhluk.h"
#include "../header/World.h"
#include <iostream>
using namespace std;

void Makhluk::MakeAlive(Makhluk* M)
{
	cout << "POLYMORPHISM STARTS HERE" << endl;
	M->Live(); // polymorphism applies here. :)
}

// IMPLEMENTASI CTOR (Protected)
Makhluk::Makhluk(char _ID, int _maxAge, const Point& P) : ID(_ID), maxAge(_maxAge)
{
	pos = P;
	status = 1;
}