// KeypressHandler.cpp
#include "../header/KeypressHandler.h"
#include "../header/WorldBuilder.h"
#include "../header/MakhlukLive.h"
#include "../header/Screen.h"
using namespace std;

KeypressHandler* KeypressHandler::handlerInstance = new KeypressHandler();

KeypressHandler::KeypressHandler()
{

}

void KeypressHandler::HandleKeypress()
{
	while (getHandlerInstance()->getLastKeypress() != 'q')
	{
		getHandlerInstance()->getKeypress();
		getHandlerInstance()->doAction();
	}
}

void KeypressHandler::getKeypress()
{
	lastKeypress = _getch();
}

void KeypressHandler::doAction()
{
	char c = getHandlerInstance()->getLastKeypress();
	switch (c)
	{
		case 'q':
			if(World::getWorldInstance()->isPaused()) World::getWorldInstance()->changePauseState();
			World::getWorldInstance()->endWorld();
			break;
		case 'w':
			lastKeypress = '-';
			do
            {
                while(_kbhit())
                {
                    KeypressHandler::getHandlerInstance()->getKeypress();
                    if(lastKeypress == '.')
                    {
                        MakhlukLive::getInstance()->MakhlukMove();
                        Screen::getScreenInstance()->PrintWorldMap();
                        MakhlukLive::getInstance()->MakhlukEat();
                    }
                }
            }while(lastKeypress != 'w');
			break;
		case 'c':
			SnapshotCapturer::getCapturerInstance()->captureSnapshot();
			break;
		case '.':
			try
			{
				if(!World::getWorldInstance()->isPaused()) throw ExceptionObject(2);
				World::getWorldInstance()->singleStepExecution();
			}
			catch(ExceptionObject& E)
			{
				E.DisplayErrorMessage();
			}
			break;
		default :
			WorldBuilder::getBuilderInstance()->addAnObject(c);
	}
}
