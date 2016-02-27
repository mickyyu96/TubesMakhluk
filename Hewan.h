// Hewan.h
#include "Makhluk.h"
class Hewan : public Makhluk {
	public :
		virtual void Move();
		virtual void FindFood();
	private :
		int hungerLvl, power, deltaT;
};
