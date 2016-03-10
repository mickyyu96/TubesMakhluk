// World.h
#ifndef WORLD_H
#define WORLD_H

#include "RandomGenerator.h"
#include <chrono>
#include <thread>

class LMakhluk; // forward class declaration

class World {
	public :
		// getter
		LMakhluk* getObjects() { return objects; }
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
		void changePauseState();
		void pauseWorld();
		void resumeWorld();

	private :
		// ctor
		World();
		World(int, int);
		
	private :
		LMakhluk* objects;

		int _isEnded, _isPaused;

		static World* worldInstance;

		const int NBrs, NKol;
};

#endif
