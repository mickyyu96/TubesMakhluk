// mWorld.cpp
#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/KeypressHandler.h"
#include <algorithm>
#include <thread>
using namespace std;

int main()
{
	thread t1(Makhluk::MakeAlive, World::getWorldInstance()->getObjects()->getFirst()->getInfo());
	thread t2(World::Show, 500);
	thread t3(KeypressHandler::HandleKeypress);
	t1.join();
	t2.join();
	t3.join();

	system("PAUSE");
	return 0;
}
