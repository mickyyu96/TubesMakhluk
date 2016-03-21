// mSnake.cpp

#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/WorldBuilder.h"
#include "../header/Screen.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
#include <time.h>

using namespace std;

int main()
{
    cout << "------------------------------------Snake--------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Snake merupakan makhluk karnivora yang memiliki behavior dapat berjalan zigzag." << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    std::chrono::milliseconds timespan(5000);
    std::this_thread::sleep_for(timespan);
    World::getWorldInstance()->setNBrs(12); World::getWorldInstance()->setNKol(12);
    string input = "UUT";
    WorldBuilder::getBuilderInstance()->setStrMakhluk(input);
	WorldBuilder::getBuilderInstance()->buildWorldObjects();
	thread t[55];
	int thread_count = 0;

	t[thread_count++] = thread(Screen::ShowWorld, 500);

	for(int i=0; i<thread_count; i++)
	{
		t[i].join();
	}

	cout << "The Program Ends Here.\n" << endl;
	system("PAUSE");
	delete World::getWorldInstance();
	return 0;
}

