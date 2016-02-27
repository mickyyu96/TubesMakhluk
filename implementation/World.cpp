// World.cpp
#include "../header/World.h"
using namespace std;

// Implementasi ctor
World::World()
{
	// ctor LMakhluk
}

// Implementasi PrintMap
void World::PrintMap()
{
	Matrix *map = new Matrix();
	// For Each X : Objects -> getPosition -> set di map
	map->PrintMatrix();
}
