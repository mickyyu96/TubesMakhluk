// mMakhlukLive.cpp

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
	string input = "PGRTSWU";
	WorldBuilder::getBuilderInstance()->setStrMakhluk(input);
	WorldBuilder::getBuilderInstance()->buildWorldObjects();

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

