// KeypressHandler.cpp
#include "../header/KeypressHandler.h"
#include "../header/WorldBuilder.h"
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
	cout << "The Program Ends Here.\n" << endl;
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
			World::getWorldInstance()->endWorld();
			break;
		case 'w':
			World::getWorldInstance()->changePauseState();
			break;
		case 'c':
			SnapshotCapturer::getCapturerInstance()->captureSnapshot();
			break;
		case '.':
			World::getWorldInstance()->singleStepExecution();
			break;
		default :
			WorldBuilder::getBuilderInstance()->addAnObject(c);
	}
}