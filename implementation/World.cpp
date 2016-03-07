// World.cpp
#include "../header/World.h"
#include "../header/PolarBear.h"
#include "../header/Matrix.h"
#include "../header/Makhluk.h"
#define DEFAULT_NBRS 20
#define DEFAULT_NKOL 20
#include <iostream>
using namespace std;

// Implementasi Static Data Member Initialization
World* World::worldInstance = new World(DEFAULT_NBRS, DEFAULT_NKOL);

// Implementasi ctor
World::World() : NBrs(DEFAULT_NBRS), NKol(DEFAULT_NKOL)
{
	// ctor LMakhluk
	objects = new LMakhluk;
	// contoh : firstMakhluk
	firstMakhluk = new PolarBear(Point(10,10));
}

World::World(int _NBrs, int _NKol) : NBrs(_NBrs), NKol(_NKol)
{
	objects = new LMakhluk;
	firstMakhluk = new PolarBear(Point(10, 10));
}

// Implementasi PrintMap
void World::PrintMap()
{
	Matrix *map = new Matrix(getNBrs(), getNKol());
	
	// For Each X : Objects -> getPosition -> set di map
	// contoh : firstMakhluk
	LMakhluk * _LMakhluk = new LMakhluk;
    	_LMakhluk->setFirst(objects->getFirst());
    	if (_LMakhluk->getFirst()!= NULL) {
        	while (_LMakhluk->getFirst() != objects->getLast()) {
            	if (_LMakhluk->getFirst()->getInfo()->isAlive())
            	{
                	char ID1 = _LMakhluk->getFirst()->getInfo()->getID();
                	Point pos1 = _LMakhluk->getFirst()->getInfo()->getPosition();
                	map->setInfo(ID1, pos1.getX(), pos1.getY());
            	}
            		_LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
        	}
        char ID1 = _LMakhluk->getFirst()->getInfo()->getID();
        Point pos1 = _LMakhluk->getFirst()->getInfo()->getPosition();
        map->setInfo(ID1, pos1.getX(), pos1.getY());
    	}
	map->PrintMatrix();
}
