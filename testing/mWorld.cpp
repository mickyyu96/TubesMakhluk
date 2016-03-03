// mWorld.cpp
#include "../header/World.h"
#include "../header/Makhluk.h"
#include <algorithm>
using namespace std;

int main()
{
	//World::getWorldInstance()->PrintMap();
	Makhluk::MakeAlive(World::getWorldInstance()->getFirstMakhluk());
	system("PAUSE");
	return 0;
}
