// Snake.h
#ifndef SNAKE_H
#define SNAKE_H

#include "Hewan.h"
#include "Makhluk.h"

class Snake : public Hewan {
	public :
		// ctor
		Snake(const Point&);

		// getter
		int getDeltaT() { return Hewan::getDeltaT(); }

		// base class member overloading
		int isVegetarian() { return 0; }

	private :
		static const char SNAKE_ID = 'U';
		static const int SNAKE_MAXAGE = 20;
		static const int SNAKE_BASEPOWER = 5;
		static const int SNAKE_DELTAT = 400;
};

#endif

