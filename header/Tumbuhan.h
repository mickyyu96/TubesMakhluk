// Tumbuhan.h
#ifndef TUMBUHAN_H
#define TUMBUHAN_H

#include "Makhluk.h"

class Tumbuhan : public Makhluk {
	public :
		//ctor
		Tumbuhan();
		Tumbuhan(const Point& P);

		//main thread
		void Live();
	private:
		static const char TUMBUHAN_ID = 'G';
		static const int TUMBUHAN_MAXAGE = 100;
};

#endif
