// Makhluk.h
#include "Point.h"

class Makhluk {
	public :
		virtual void Live() = 0;
	
	private :
		char ID;
		int age;
		const int maxAge;
		Point pos;	
};
