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
    isChallange = 0;
}

Turtle::Turtle(const Point& P): Hewan(TURTLE_ID, TURTLE_MAXAGE){
    status = 1;
    power = TURTLE_BASEPOWER;
    deltaT = TURTLE_DELTAT;
    pos = P;
    isChallange = 0;
}

void Turtle::Race(){
    if (getIsChallange()) {
        //
    }
}

Makhluk* Turtle::FindFood(){
    return Hewan::FindMakhluk('V');
}

void Turtle::GetToFood(){
    Makhluk* Food;
    if (Hewan::isMakhlukinList('V')) {
        Food = FindFood();
    }
    Hewan::getToPoint(Food->getPosition());
}

void Turtle::Sleep(int duration){
    std::chrono::milliseconds timespan(duration);
    std::this_thread::sleep_for(timespan);
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
        
        Sleep(getDeltaT());
    }
}
