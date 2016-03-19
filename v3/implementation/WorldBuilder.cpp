// WorldBuilder.cpp
#include "../header/WorldBuilder.h"
#include "../header/LMakhluk.h"
#include "../header/RandomGenerator.h"
#include "../header/ExceptionObject.h"
#include "../header/Rabbit.h"
#include "../header/Turtle.h"
#include "../header/Wolf.h"
#include "../header/Sheep.h"
#include "../header/PolarBear.h"
#include "../header/Tumbuhan.h"
#include <string>

WorldBuilder* WorldBuilder::builderInstance = new WorldBuilder();

WorldBuilder::WorldBuilder()
{
}

void WorldBuilder::addAnObject(char _ID)
{
	int NBrs = World::getWorldInstance()->getNBrs();
	int NKol = World::getWorldInstance()->getNKol();
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
		default :
			ExceptionObject E(3);
			E.DisplayErrorMessage();
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
