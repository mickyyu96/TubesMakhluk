// Screen.cpp
#include "../header/Screen.h"
#include "../header/LMakhluk.h"
using namespace std;

Screen* Screen::screenInstance = new Screen();

Screen::Screen()
{

}

void Screen::PrintMatrix(const Matrix& M)
{
	for (int i = 0; i<M.getNBrs(); i++)
	{
		for (int j = 0; j<M.getNKol(); j++)
		{
			cout << M.getInfo(i, j);
		}
		cout << endl;
	}
}

void Screen::PrintWorldMap()
{
	World* worldInstance = World::getWorldInstance();
	Matrix *map = new Matrix(worldInstance->getNBrs(), worldInstance->getNKol());

	LMakhluk * _LMakhluk = new LMakhluk();
	_LMakhluk->setFirst(worldInstance->getObjects()->getFirst());

	if (!_LMakhluk->isEmpty()) {
		while (_LMakhluk->getFirst() != worldInstance->getObjects()->getLast()) {
			if (_LMakhluk->getFirst()->getInfo()->isAlive())
			{
				char ID1 = _LMakhluk->getFirst()->getInfo()->getID();
				Point pos1 = _LMakhluk->getFirst()->getInfo()->getPosition();
				map->setInfo(ID1, pos1.getX(), pos1.getY());
			}
			_LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
		}
		if (_LMakhluk->getFirst()->getInfo()->isAlive())
		{
			char ID1 = _LMakhluk->getFirst()->getInfo()->getID();
			Point pos1 = _LMakhluk->getFirst()->getInfo()->getPosition();
			map->setInfo(ID1, pos1.getX(), pos1.getY());
		}
	}

	getScreenInstance()->PrintMatrix(*map);
}

void Screen::ShowWorld(int deltaT)
{
	while (!World::getWorldInstance()->isEnded())
	{
		World::getWorldInstance()->lockWorld();
		getScreenInstance()->PrintWorldMap();
		World::getWorldInstance()->unlockWorld();

		std::chrono::milliseconds timespan(deltaT);
		std::this_thread::sleep_for(timespan);
	}
}