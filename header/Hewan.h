// Hewan.h
#ifndef HEWAN_H
#define HEWAN_H

#include "Makhluk.h"
class Hewan : public Makhluk {
	public :
		virtual void Move();
		virtual void FindFood();
	private :
		int hungerLvl, power, deltaT;
};

#endif
