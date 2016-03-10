// Rabbit.cpp
#include "../header/Rabbit.h"
#include <thread>
#include <chrono>
using namespace std;

Rabbit::Rabbit(const Point& P): Hewan(RABBIT_ID, RABBIT_MAXAGE) {
    status = 1;
    power = RABBIT_BASEPOWER;
    deltaT = RABBIT_DELTAT;
    pos = P;
}

// actions
void Rabbit::GetToFood(){
    if (Hewan::isMakhlukinList('G')) {
        Hewan::getToPoint(Hewan::FindFood()->getPosition());
        Hewan::FindFood()->Kill();
    }
}


void Rabbit::WanderingHop(){
    int dx = 2;
    int dy = 2;
    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    if (nRandom == 1) {
        for (int i = 0; i<20; i++) {
            if (Hewan::shouldRebounced(dx, 0)) {
                dx *= -1;
            }
            if (Hewan::shouldRebounced(0, dy)) {
                dy *= -1;
            }
            
            Hewan::Move(dx, dy);
            Hewan::Sleep();
        }
    }
    else{
        for (int i = 0; i<20; i++) {
            if (Hewan::shouldRebounced(dx, 0) && Hewan::shouldRebounced(0, dy)) {
                dx = 0;
                dy = 2;
                if (Hewan::shouldRebounced(0, dy)) {
                    dy *= -1;
                }
            }
            if (Hewan::shouldRebounced(0, dy)) {
                dy = 0;
                dx = 2;
                if (Hewan::shouldRebounced(dx, 0)) {
                    dx *= -1;
                }
            }
            else if (Hewan::shouldRebounced(dx, 0)){
                dx = 0;
                dy = 2;
                if (Hewan::shouldRebounced(0, dy)) {
                    dy *= -1;
                }
            }
            Hewan::Move(dx, dy);
            Hewan::Sleep();
        }
    }
}

// main action
void Rabbit::Live(){
    int nRandom;
    while(isAlive())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(3);
        switch (nRandom) {
            case 0:
                Hewan::Wandering();
                break;
            case 1:
                GetToFood();
                break;
            case 2:
                WanderingHop();
                break;
        }
        
        Hewan::Sleep();
    }
}
