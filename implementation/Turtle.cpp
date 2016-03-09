#include "Turtle.h"
#include <iostream>
#include <cmath>
#include <math.h>
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

void Turtle::Wandering(){
    //int dx = RandomGenerator::getInstance()->getNextDeltaMove();
    if (Hewan::shouldRebounced(dx, 0)) {
        dx *= -1;
    }
    
    //int dy = RandomGenerator::getInstance()->getNextDeltaMove();
    if (Hewan::shouldRebounced(0, dy)) {
        dy *= -1;
    }
    
    if (!Hewan::shouldRebounced(dx, dy)) {
         Hewan::Move(dx, dy);
    }
}

void Turtle::Sleep(int duration){
    std::chrono::milliseconds timespan(duration);
    std::this_thread::sleep_for(timespan);
}

// main action
void Turtle::Live(){
    while(isAlive())
    {
        
        //Wandering();
        Sleep(getDeltaT());
    }
}