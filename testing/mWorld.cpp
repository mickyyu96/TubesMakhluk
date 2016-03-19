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
	int _NBrs, _NKol;
	cout << "Masukkan dimensi ukuran ruang dunia." << endl;
	cout << "Jumlah baris (panjang) = "; cin >> _NBrs;
	cout << "Jumlah kolom (lebar)   = "; cin >> _NKol;
	World::getWorldInstance()->setNBrs(_NBrs); World::getWorldInstance()->setNKol(_NKol);

	cout << "Masukkan sebuah string yang  berisi ID (UPPERCASE) makhluk-makhluk yang ingin dimunculkan pada dunia. " << endl;
	cout << "Pilihan : P = PolarBear, G = Tumbuhan, R = Rabbit, T = Turtle, S = Sheep, W = Wolf" << endl;
	cout << "String input = ";
	string input;
	cin >> input;
	WorldBuilder::getBuilderInstance()->setStrMakhluk(input);
	WorldBuilder::getBuilderInstance()->buildWorldObjects();
	
	thread t[55];
	int thread_count = 0;

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
