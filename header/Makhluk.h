// Makhluk.h
#ifndef MAKHLUK_H
#define MAKHLUK_H
#include "Point.h"
#include "World.h"

class Makhluk {
	public :
		// getter
		char getID() const { return ID; }
		int getAge() const { return age; }
		int getMaxAge() const { return maxAge; }
		Point getPosition() const { return pos; }

		void setPosition(const Point& P) { pos = P; }

		// method untuk hidup
		virtual void Live() = 0;
		static void MakeAlive(Makhluk*);

		// method untuk eliminate
		int isAlive() { return (status == 1); }
		void Kill() { status = 0; }

	protected :
		// ctor
		Makhluk(char, int, const Point&);
	
	protected :
		const char ID;
		int age;
		const int maxAge;
		Point pos;
		int status;
};

#endif
