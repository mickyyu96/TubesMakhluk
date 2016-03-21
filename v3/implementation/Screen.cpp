// Screen.cpp

#include "../header/Screen.h"
#include "../header/LMakhluk.h"
using namespace std;

Screen* Screen::screenInstance = new Screen();

Screen::Screen()
{

}

void Screen::ShowWorld(int deltaT)
{
	while (!World::getWorldInstance()->isEnded())
	{
		World::getWorldInstance()->lockWorld();

		int nBrs = World::getWorldInstance()->getNBrs();
		for(int i=0; i<30; i++) cout << '\n';

		getScreenInstance()->PrintWorldMap();

		World::getWorldInstance()->unlockWorld();


        if (World::getWorldInstance()->getObjects()->IsAllMakhlukDead())
        {
            World::getWorldInstance()->endWorld();
            for(int i=0; i<30; i++) cout << '\n';
            getScreenInstance()->PrintWorldMap();
        }

		std::chrono::milliseconds timespan(deltaT);
		std::this_thread::sleep_for(timespan);
	}
}
