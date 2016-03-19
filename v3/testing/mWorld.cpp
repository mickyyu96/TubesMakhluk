// mWorld.cpp
#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/KeypressHandler.h"
#include "../header/WorldBuilder.h"
#include "../header/Screen.h"
#include "../header/SnapshotCapturer.h"
#include "../header/ExceptionObject.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
using namespace std;

int isValidID(string);
// Melakukan pengecekan string masukan pengguna, apakah ID yang dimasukkan benar (valid)

int main()
{
	/**************************************************************
	**
	**				Input dimensi ukuran dunia
	**
	**************************************************************/
	int _NBrs, _NKol;
	do
	{
		try
		{
			cout << "Masukkan dimensi ukuran ruang dunia." << endl;
			cout << "Jumlah baris (panjang) = "; cin >> _NBrs;
			cout << "Jumlah kolom (lebar)   = "; cin >> _NKol;
			if (_NBrs < 7 || _NKol < 7) throw ExceptionObject(0);
		}
		catch (ExceptionObject& E)
		{
			E.DisplayErrorMessage();
		}

	} while(_NBrs < 7 || _NKol < 7);
	World::getWorldInstance()->setNBrs(_NBrs+2); World::getWorldInstance()->setNKol(_NKol+2);

	cout << "\n===========================================================================\n" << endl;

	/**************************************************************
	**
	**				Input makhluk-makhluk yang ada
	**
	**************************************************************/
	string input;
	do
	{
		try
		{
			cout << "Masukkan sebuah string yang  berisi ID (UPPERCASE) makhluk-makhluk yang ingin dimunculkan pada dunia. " << endl;
			cout << "Pilihan : P = PolarBear, G = Tumbuhan, R = Rabbit, T = Turtle, S = Sheep, W = Wolf" << endl;
			cout << "String input = ";
			cin >> input;

			if(!isValidID(input)) throw ExceptionObject(1);
		}
		catch (ExceptionObject& E)
		{
			E.DisplayErrorMessage();
		}
	} while (!isValidID(input));
	WorldBuilder::getBuilderInstance()->setStrMakhluk(input);
	WorldBuilder::getBuilderInstance()->buildWorldObjects();

	cout << "\n===========================================================================\n" << endl;

	/**************************************************************
	**
	**					Nyalakan dunia
	**
	**************************************************************/

	thread t[55];
	int thread_count = 0;

	t[thread_count++] = thread(Screen::ShowWorld, 500);
	t[thread_count++] = thread(KeypressHandler::HandleKeypress);

	for(int i=0; i<thread_count; i++)
	{
		t[i].join();
	}

	cout << "The Program Ends Here.\n" << endl;
	system("PAUSE");
	delete World::getWorldInstance();
	return 0;
}

int isValidID(string s)
{
	int Found = 0;
	for(int i=0; i<(int)s.size() && !Found; i++)
	{
		if(s[i] != 'P' && s[i] != 'G' && s[i] != 'R' && s[i] != 'T' && s[i] != 'S' && s[i] != 'W' ) // Ular belum,
		{
			Found = 1;
		}
	}
	return !Found;
}
