// KeypressHandler.cpp
#include "../header/KeypressHandler.h"
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
		case 'q': World::getWorldInstance()->endWorld();
	}

	// untuk test :
	cout << c << endl;
}