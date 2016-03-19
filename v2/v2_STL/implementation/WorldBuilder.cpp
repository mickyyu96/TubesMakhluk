// WorldBuilder.cpp
#include "WorldBuilder.h"
#include "LMakhluk.h"
#include "RandomGenerator.h"
#include "Rabbit.h"
#include "Turtle.h"
#include "Wolf.h"
#include "Sheep.h"
#include "PolarBear.h"
#include "Tumbuhan.h"
#include "Snake.h"
#include <string>

#define DEFAULT_NBRS 20
#define DEFAULT_NKOL 20

World* World::worldInstance = new World(DEFAULT_NBRS, DEFAULT_NKOL);
WorldBuilder* WorldBuilder::builderInstance = new WorldBuilder(World::getWorldInstance()->getNBrs(),
	World::getWorldInstance()->getNKol());

WorldBuilder::WorldBuilder(int _NBrs, int _NKol) : NBrs(_NBrs), NKol(_NKol)
{
}

void WorldBuilder::addAnObject(char _ID)
{
	switch (_ID)
	{
		case 'G':
			World::getWorldInstance()->getObjects()->Add(new Tumbuhan(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
			break;
		case 'R':
			World::getWorldInstance()->getObjects()->Add(new Rabbit(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
			break;
		case 'T':
			World::getWorldInstance()->getObjects()->Add(new Turtle(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
			break;
		case 'W':
			World::getWorldInstance()->getObjects()->Add(new Wolf(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
			break;
		case 'S':
			World::getWorldInstance()->getObjects()->Add(new Sheep(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
			break;
		case 'P':
			World::getWorldInstance()->getObjects()->Add(new PolarBear(RandomGenerator::getInstance()->getNextPointPolarBear(NBrs, NKol)));
			break;
        case 'U':
        {   Point P;
            P = RandomGenerator::getInstance()->getNextPoint(NBrs, NKol);
            World::getWorldInstance()->getObjects()->Add(new Snake(P));
            break;
        }
	}
}

void WorldBuilder::buildWorldObjects()
{
	int numOfObjects = getStrMakhluk().size();
	for (int i = 0; i < numOfObjects; i++)
	{
		char c = getStrMakhluk()[i];
		addAnObject(c);
	}
}
