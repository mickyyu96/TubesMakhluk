// mWorld.cpp
#include "../header/World.h"
#include "../header/Makhluk.h"
#include <algorithm>
#include <thread>
using namespace std;

int main()
{
	//World::getWorldInstance()->PrintMap();
	thread t1(Makhluk::MakeAlive, World::getWorldInstance()->getFirstMakhluk());
	t1.join();
	system("PAUSE");
	return 0;
}
