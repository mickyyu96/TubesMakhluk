// PolarBear.h
#ifndef POLARBEAR_H
#define POLARBEAR_H

#include "Carnivore.h"

class PolarBear : public Carnivore {
	public :
		// ctor
		PolarBear();
		
		// actions
		void Move(int, int);
		void FindFood();
		
	private :
		
};

#endif
