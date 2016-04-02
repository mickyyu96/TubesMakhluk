// mWorld.cpp

#include "../header/World.h"
#include "../header/MakhlukLive.h"
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

	do
    {
        do
        {
            MakhlukLive::getInstance()->MakhlukMove();
            Screen::getScreenInstance()->PrintWorldMap();
            MakhlukLive::getInstance()->MakhlukEat();

            if (World::getWorldInstance()->getObjects()->IsAllMakhlukDead())
            {
                World::getWorldInstance()->endWorld();
                break;
            }

            std::chrono::milliseconds timespan(500);
            std::this_thread::sleep_for(timespan);

        } while (!_kbhit() && !World::getWorldInstance()->isEnded());

        if(_kbhit())
        {
            KeypressHandler::getHandlerInstance()->getKeypress();
            KeypressHandler::getHandlerInstance()->doAction();
        }

    } while(!World::getWorldInstance()->isEnded());

	delete World::getWorldInstance();
	return 0;
}
