//  Turtle.hpp
#ifndef Turtle_h
#define Turtle_h
#include "Hewan.h"
class Turtle : public Hewan {
    public :
    // ctor
    Turtle(const Point&);
    
    int isVegetarian() { return 1; }
    
    // getter
    int getDeltaT() { return Hewan::getDeltaT(); }
    
    // actions
    void Race();
    void GetToFood();
    
    // main action
    void Live();
    
    private :
    static const char TURTLE_ID = 'T';
    static const int TURTLE_MAXAGE = 15;
    static const int TURTLE_BASEPOWER = 2;
    static const int TURTLE_DELTAT = 600;
};

#endif /* Turtle_hpp */
