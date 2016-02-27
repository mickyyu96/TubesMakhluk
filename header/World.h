// World.h
#ifndef WORLD_H
#define WORLD_H

#include "LMakhluk.h"
#include "Matrix.h"

class World {
	public :
		// ctor
		World();
		
		// function member
		void PrintMap();
		
	private :
		LMakhluk* objects;	
};

#endif
