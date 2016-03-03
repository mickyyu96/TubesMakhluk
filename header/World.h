// World.h
#ifndef WORLD_H
#define WORLD_H

class LMakhluk; // forward class declaration
class Makhluk; // forward class declaration

class World {
	public :
		// getter
		LMakhluk* getObjects() { return objects; }
		Makhluk* getFirstMakhluk() { return firstMakhluk; }
		static World* getWorldInstance() { return worldInstance; }
		int getNBrs() { return NBrs; }
		int getNKol() { return NKol; }

		// function member
		void PrintMap();

	private :
		// ctor
		World();
		World(int, int);
		
	private :
		LMakhluk* objects;
		Makhluk* firstMakhluk;

		static World* worldInstance;

		const int NBrs, NKol;
};

#endif
