// World.h
#include "LMakhluk.h"

class World {
	public :
		// ctor
		World();
		
		// function member
		void PrintMap();
		
	private :
		Matrix map;
		LMakhluk objects;	
};
