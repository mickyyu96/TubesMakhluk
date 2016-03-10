// PolarBear.h
#ifndef POLARBEAR_H
#define POLARBEAR_H

#include "Hewan.h"

class PolarBear : public Hewan {
	public :
		// ctor
		PolarBear(const Point&);
		
		// getter
		int getDeltaT() { return Hewan::getDeltaT(); }

		// base class member overloading
		int isVegetarian() { return 0; }
		
		// actions
		void FindFood();
		void Sleep(int);

		// main action
		void Live();
		
	private :
		static const char POLARBEAR_ID = 'P';
		static const int POLARBEAR_MAXAGE = 100;
		static const int POLARBEAR_BASEPOWER = 15;
		static const int POLARBEAR_DELTAT = 1000;
};

#endif
