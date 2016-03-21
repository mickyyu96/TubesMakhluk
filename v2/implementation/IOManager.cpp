// IOManager.cpp
#include "../header/IOManager.h"
#include "../header/RandomGenerator.h"
#include "../header/LMakhluk.h"
#include "../header/Hewan.h"
#include "../header/MakhlukLive.h"
using namespace std;

void IOManager::PrintMatrix(const Matrix& M)
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

void IOManager::PrintWorldMap()
{
	for(int i=0; i<30; i++) cout << '\n';
	World* worldInstance = World::getWorldInstance();
	Matrix *map = new Matrix(worldInstance->getNBrs(), worldInstance->getNKol());

    LMakhluk * _LMakhluk = worldInstance->getObjects();

    for (int i = 0; i<_LMakhluk->getSize(); i++) {
        if (_LMakhluk->getInfo(i)->isAlive())
        {
            char ID1 = _LMakhluk->getInfo(i)->getID();
            Point pos1 = _LMakhluk->getInfo(i)->getPosition();
            map->setInfo(ID1, pos1.getX(), pos1.getY());
        }
    }
	PrintMatrix(*map);
}



