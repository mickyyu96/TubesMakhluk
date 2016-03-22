// mScreen.cpp

#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/Screen.h"
#include "../header/Rabbit.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
using namespace std;

int main()
{
	thread t[55];
	int thread_count = 0;

	int interval = 500; // in miliseconds

	t[thread_count++] = thread(Screen::ShowWorld, interval);

	std::chrono::milliseconds timespan(5000);
	std::this_thread::sleep_for(timespan);
	World::getWorldInstance()->getObjects()->Add(new Rabbit(Point(10,10)));

	for(int i=0; i<thread_count; i++)
	{
		t[i].join();
	}

	return 0;
}
