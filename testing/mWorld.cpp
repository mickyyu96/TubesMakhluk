// mWorld.cpp
#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/KeypressHandler.h"
#include "../header/WorldBuilder.h"
#include "../header/Screen.h"
#include "../header/SnapshotCapturer.h"
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
	
	thread t[55];
	int thread_count = 0;
	LMakhluk::ElmtMakhluk *P = World::getWorldInstance()->getObjects()->getFirst();
	while(P != NULL)
	{
		t[thread_count++] = thread(Makhluk::MakeAlive, P->getInfo());
		P = P->getNext();
	}
	t[thread_count++] = thread(Screen::ShowWorld, 500);
	t[thread_count++] = thread(KeypressHandler::HandleKeypress);
	
	for(int i=0; i<thread_count; i++)
	{
		t[i].join();
	}

	system("PAUSE");
	delete World::getWorldInstance();
	return 0;
}
