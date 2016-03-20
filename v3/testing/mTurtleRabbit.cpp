// mTurtleRabbit.cpp

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
    cout << "--------------------------------------Turtle & Rabbit---------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "Turtle dan Rabbit merupakan makhluk herbivora yang memiliki behavior dapat melakukan racing." << endl;
    cout << "Selain itu, Rabbit juga memiliki behavior untuk melompat (melakukan 2 langkah sekaligus)." << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    std::chrono::milliseconds timespan(8000);
    std::this_thread::sleep_for(timespan);
    World::getWorldInstance()->setNBrs(12); World::getWorldInstance()->setNKol(12);
    string input = "TRG";
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

