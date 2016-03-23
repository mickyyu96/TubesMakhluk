// mWorld.cpp

#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/WorldBuilder.h"
#include "../header/Screen.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
using namespace std;


int main()
{
	cout << "Masukan sebuah string yang  berisi ID (UPPERCASE) makhluk-makhluk yang ingin dimunculkan pada dunia! " << endl;
	cout << "Pilihan : P = PolarBear, G = Tumbuhan, R = Rabbit, T = Turtle, S = Sheep, W = Wolf" << endl;
	cout << "String input = ";
	string input;
	cin >> input;
	WorldBuilder::getBuilderInstance()->setStrMakhluk(input);
	WorldBuilder::getBuilderInstance()->buildWorldObjects();

	cout << "Semua makhluk sudah berhasil ditambahkan, dan akan ditampilkan makhluk2 yang sudah hidup" << endl;
	system("PAUSE");

	thread t[55];
	int thread_count = 0;

	t[thread_count++] = thread(Screen::ShowWorld, 500);

	for(int i=0; i<thread_count; i++)
	{
		t[i].join();
	}

	system("PAUSE");
	delete World::getWorldInstance();
	return 0;
}
