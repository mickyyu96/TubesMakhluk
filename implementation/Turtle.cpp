#include "../header/Turtle.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int dx =1;
int dy =1;
Turtle::Turtle(): Hewan(TURTLE_ID, TURTLE_MAXAGE) {
    status = 1;
    power = TURTLE_BASEPOWER;
    deltaT = TURTLE_DELTAT;
    pos = Point();
}

Turtle::Turtle(const Point& P): Hewan(TURTLE_ID, TURTLE_MAXAGE){
    status = 1;
    power = TURTLE_BASEPOWER;
    deltaT = TURTLE_DELTAT;
    pos = P;
}

void Turtle::Race(){
}

void Turtle::GetToFood(){
    if (Hewan::isMakhlukinList('G')) {
        Hewan::getToPoint(Hewan::FindFood()->getPosition());
        Hewan::FindFood()->Kill();
    }
}

// main action
void Turtle::Live(){
    int nRandom;
    while(isAlive())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(2);
        switch (nRandom) {
            case 0:
                Hewan::Wandering();
                break;
            case 1:
                GetToFood();
                break;
        }
        
        Hewan::Sleep();
    }
}
