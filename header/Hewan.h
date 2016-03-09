// Hewan.h
#ifndef HEWAN_H
#define HEWAN_H

#include "Makhluk.h"
#include "Point.h"
class Hewan : public Makhluk {
	public :
		// virtual method
		virtual void Move(int, int);
		virtual int isVegetarian() = 0;
        	virtual void GetToFood() = 0;
		
		// getter
		int getHungerLvl() { return hungerLvl; }
		int getPower() { return power; }
		int getDeltaT() { return deltaT;  }
	
		// setter
        	void setHungerLvl(int x) { hungerLvl+=x; }
    
    		void Wandering();
	    	Makhluk* FindFood();
        	Makhluk* FindMakhluk(char _ID);
        	int shouldRebounced(int dx, int dy);
        	bool isMakhlukinList(char _ID);
        	void getToPoint(Point P);
        
	protected :
		// ctor
		Hewan(char, int);

	protected :
		int hungerLvl, power, deltaT;
};

#endif
