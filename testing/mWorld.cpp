// mWorld.cpp
#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/KeypressHandler.h"
#include "../header/WorldBuilder.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
using namespace std;

int main()
{
	string input;
	cin >> input;
	WorldBuilder::getBuilderInstance()->setStrMakhluk(input);
	WorldBuilder::getBuilderInstance()->buildWorldObjects();

	
	thread t1(Makhluk::MakeAlive, World::getWorldInstance()->getObjects()->getFirst()->getInfo());
	thread t4(Makhluk::MakeAlive, World::getWorldInstance()->getObjects()->getFirst()->getNext()->getInfo());
	thread t2(World::Show, 500);
	thread t3(KeypressHandler::HandleKeypress);
	t1.join();
	t2.join();
	t3.join();
	
	system("PAUSE");
	return 0;
}
