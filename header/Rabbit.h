#ifndef Rabbit_h
#define Rabbit_h

#include <stdio.h>
#include "Hewan.h"
class Rabbit : public Hewan {
    public :
    // ctor
    Rabbit();
    Rabbit(const Point&);
    
    int isVegetarian() { return 1; }
    
    // getter
    int getDeltaT() { return Hewan::getDeltaT(); }
    
    // actions
    //bool FindTurtle();
    Makhluk* FindFood();
    void Sleep(int);
    void GetToFood();
    void WanderingHop();
    void Wandering();
    
    // main action
    void Live();
    
    private :
    static const char RABBIT_ID = 'R';
    static const int RABBIT_MAXAGE = 20;
    static const int RABBIT_BASEPOWER = 3;
    static const int RABBIT_DELTAT = 500;
};
#endif /* Rabbit_h */