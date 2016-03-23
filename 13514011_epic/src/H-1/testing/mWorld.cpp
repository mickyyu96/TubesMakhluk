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

int isValidID(const string&);
// Melakukan pengecekan string masukan pengguna, apakah ID yang dimasukkan benar (valid)

int isValidUkuran(const string&, const string&);
// Melakukan pengecekan string masukan pengguna, apakah ID yang dimasukkan benar (valid)

int main()
{
    cout << "*************************************************************************************" << endl;
    cout << "       **       ***    **  ***  ***         ***       **       **        **  ********" << endl;
    cout << "      ****      ****   **  ***  ****       ****      ****      **       **   **      " << endl;
    cout << "     **  **     ** **  **  ***  ** **     ** **     **  **     **            **      " << endl;
    cout << "    ********    **  ** **  ***  **  **   **  **    ********    **            ********" << endl;
    cout << "   **      **   **   ****  ***  **   ** **   **   **      **   **                  **" << endl;
    cout << "  **        **  **    ***  ***  **    ***    **  **        **  ********      ********" << endl;
    cout << "                                                                                     " << endl;
    cout << "       **        **  ***  **        **             **       ********  ********       " << endl;
    cout << "        **      **   ***  **        **            ****      **        **             " << endl;
    cout << "         **    **    ***  **        **           **  **     **        **             " << endl;
    cout << "          **  **     ***  **        **          ********    **  ****  ********       " << endl;
    cout << "           ****      ***  **        **         **      **   **    **  **             " << endl;
    cout << "            **       ***  ********  ********  **        **  ********  ********       " << endl;
    cout << "                                                                                     " << endl;
    cout << "             WOLF     RABBIT     TURTLE     POLARBEAR     SNAKE     SHEEP            " << endl;
    cout << "                                                                                     " << endl;
    cout << "                         BY EPIC: NGIONG, MICKY, KEPI, ELVINA                        " << endl;
    cout << "*************************************************************************************" << endl;
	/**************************************************************
	**
	**				Input dimensi ukuran dunia
	**
	**************************************************************/
	int _NBrs, _NKol;
	string strNBrs, strNKol;
	do
	{
		try
		{
			cout << "Masukkan dimensi ukuran ruang dunia." << endl;
			cout << "Jumlah baris (panjang) = "; cin >> strNBrs;
			cout << "Jumlah kolom (lebar)   = "; cin >> strNKol;
			if(!isValidUkuran(strNBrs, strNKol)) throw ExceptionObject(4);

			_NBrs = atoi(strNBrs.c_str()); _NKol = atoi(strNKol.c_str());
			if (_NBrs < 7 || _NKol < 7) throw ExceptionObject(0);
		}
		catch (ExceptionObject& E)
		{
			E.DisplayErrorMessage();
		}

	} while(_NBrs < 7 || _NKol < 7 || !isValidUkuran(strNBrs, strNKol));
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
			cout << "Pilihan :\n\tP = PolarBear, \n\tG = Tumbuhan, \n\tR = Rabbit, \n\tT = Turtle, \n\tS = Sheep, \n\tW = Wolf, \n\tU = Snake" << endl;
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

	thread t[100];
	int thread_count = 0;

	t[thread_count++] = thread(Screen::ShowWorld, 500);
	t[thread_count++] = thread(KeypressHandler::HandleKeypress);

	t[0].join();
	t[1].detach();

	cout << "The Program Ends Here.\n" << endl;
	//system("PAUSE");
	delete World::getWorldInstance();
	return 0;
}

int isValidID(const string& s)
{
	int Found = 0;
	for(int i=0; i<(int)s.size() && !Found; i++)
	{
		if(s[i] != 'P' && s[i] != 'G' && s[i] != 'R' && s[i] != 'T' && s[i] != 'S' && s[i] != 'W' && s[i] != 'U')
		{
			Found = 1;
		}
	}
	return !Found;
}

int isValidUkuran(const string& strNBrs, const string& strNKol)
{
	int valid = 1;
	for(int i=0; i<strNBrs.size() && valid; i++)
	{
		if(strNBrs[i] < '0' || strNBrs[i] >'9') valid = 0;
	}
	for(int i=0; i<strNKol.size() && valid; i++)
	{
		if(strNKol[i] < '0' || strNKol[i] >'9') valid = 0;
	}
	return valid;
}
