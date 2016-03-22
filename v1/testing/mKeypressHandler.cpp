// mKeypressHandler.cpp

#include "../header/World.h"
#include "../header/LMakhluk.h"
#include "../header/KeypressHandler.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
using namespace std;

void HandleKeypress(int);
// Main procedure untuk KeypressHandler

void GetKeypress();
// Menunggu user melakukan keypress, dan memanggil prosedur sesuai dengan keypress yang dimasukan

void DoAction();
// Berisi switch statement dari state lastKeypress dari instance KeypressHandler
// Untuk unit testing, hanya melakukan print lastKeypress

int main()
{
	thread t[55];
	int thread_count = 0;
	int numOfKeypress = 5;

	cout << "Lakukan 5 keypress, program akan menampilkan keypress yang Anda lakukan" << endl;
	t[thread_count++] = thread(HandleKeypress, numOfKeypress);
	t[0].join();

	cout << "Testing KeypressHandler untuk program Realita, tekan q untuk exit" << endl;
	t[thread_count++] = thread(KeypressHandler::HandleKeypress);
	t[1].join();

	system("PAUSE");
	return 0;
}

void HandleKeypress(int numOfKeypress)
{
	while(numOfKeypress--)
	{
		GetKeypress();
	}
}

void GetKeypress()
{
	// Menunggu user melakukan keypress
	KeypressHandler::getHandlerInstance()->getKeypress();
	// Melakukan aksi setelah keypress dilakukan
	DoAction();

}

void DoAction()
{
	cout << "Baru saja anda menekan : " << KeypressHandler::getHandlerInstance()->getLastKeypress() << endl;
}
