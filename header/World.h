// World.h
#ifndef WORLD_H
#define WORLD_H

#include "RandomGenerator.h"
#include <chrono>
#include <thread>

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

		// static function member
		static void Show(int);

		// function member untuk menangani keypress
		int isEnded() { return _isEnded; }
		int isPaused() { return _isPaused; }
		void endWorld() { _isEnded = 1; }
		void changePauseState() { _isPaused ^= 1; }

	private :
		// ctor
		World();
		World(int, int);
		
	private :
		LMakhluk* objects;
		Makhluk* firstMakhluk;

		int _isEnded, _isPaused;

		static World* worldInstance;

		const int NBrs, NKol;
};

#endif
