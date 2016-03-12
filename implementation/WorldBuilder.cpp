// WorldBuilder.cpp
#include "../header/WorldBuilder.h"
#include "../header/LMakhluk.h"
#include "../header/RandomGenerator.h"
#include "../header/Rabbit.h"
#include "../header/Turtle.h"
#include "../header/Tumbuhan.h"
#include <string>

WorldBuilder* WorldBuilder::builderInstance = new WorldBuilder( World::getWorldInstance()->getNBrs(),
																World::getWorldInstance() -> getNKol());

WorldBuilder::WorldBuilder(int _NBrs, int _NKol) : NBrs(_NBrs), NKol(_NKol)
{
}

void WorldBuilder::buildWorldObjects()
{
	int numOfObjects = getStrMakhluk().size();
	for (int i = 0; i < numOfObjects; i++)
	{
		char c = getStrMakhluk()[i];
		switch (c)
		{
			case 'G' :
				World::getWorldInstance()->getObjects()->Add(new Tumbuhan(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
				break;
			case 'R':
				World::getWorldInstance()->getObjects()->Add(new Rabbit(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
				break;
			case 'T':
				World::getWorldInstance()->getObjects()->Add(new Turtle(RandomGenerator::getInstance()->getNextPoint(NBrs, NKol)));
				break;
		}
	}
}