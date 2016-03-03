// Hewan.h
#ifndef HEWAN_H
#define HEWAN_H

#include "Makhluk.h"
#include "Point.h"
class Hewan : public Makhluk {
	public :
		// virtual method
		virtual void Move(int, int);
		virtual void FindFood() = 0;
		
		// getter
		int getHungerLvl() { return hungerLvl; }
		int getPower() { return power; }
		int getDeltaT() { return deltaT;  }
	
	protected :
		// ctor
		Hewan(char, int);

	protected :
		int hungerLvl, power, deltaT;
};

#endif
