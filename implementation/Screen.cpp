// Screen.cpp
#include "../header/Screen.h"
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
		getScreenInstance()->PrintWorldMap();
		World::getWorldInstance()->unlockWorld();

		std::chrono::milliseconds timespan(deltaT);
		std::this_thread::sleep_for(timespan);
	}
}
