// KeypressHandler.h
#ifndef KEYPRESSHANDLER_H
#define KEYPRESSHANDLER

#include <conio.h>
#include <iostream>
#include "World.h"

class KeypressHandler
{
	public :
		// getter setter
		static KeypressHandler* getHandlerInstance() { return handlerInstance; }
		char getLastKeypress() { return lastKeypress; }

		// member function
		static void HandleKeypress();
		void getKeypress();
		void doAction();

	private:
		// ctor
		KeypressHandler();

	private :
		static KeypressHandler* handlerInstance;
		char lastKeypress;
};

#endif