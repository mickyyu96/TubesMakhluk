// Rabbit.cpp
#include "../header/Rabbit.h"
#include "../header/Turtle.h"
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
    Hewan::lockHewan();
    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    Hewan::unlockHewan();
    if (nRandom == 1) {
        for (int i = 0; i<20; i++) {
            if (Hewan::shouldRebounced(dx, 0)) {
                dx *= -1;
            }
            if (Hewan::shouldRebounced(0, dy)) {
                dy *= -1;
            }
            
            Hewan::Move(dx, dy);
            std::chrono::milliseconds timespan(Hewan::getDeltaT());
            std::this_thread::sleep_for(timespan);
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
            std::chrono::milliseconds timespan(Hewan::getDeltaT());
            std::this_thread::sleep_for(timespan);
        }
    }
}

void Rabbit::Race(){
    if (!Turtle::isAnyTurtleRacing()) {
        bool TurtleCome = false;
        Point PTurtle;
        
        static_cast<Turtle*>(FindMakhluk('T'))->setIsChallange(1);
        PTurtle = Hewan::FindMakhluk('T')->getPosition();
        if (PTurtle.getX() == 5 && PTurtle.getY()== 1) {
            TurtleCome = true;
        }
    
        Hewan::getToPoint(Point(5, 1));
        while (!TurtleCome){
            PTurtle = Hewan::FindMakhluk('T')->getPosition();
            if (PTurtle.getX() == 5 && PTurtle.getY()== 1  && !static_cast<Turtle*>(FindMakhluk('T'))->getisChallange()) {
                TurtleCome = true;
            }
        }
        Hewan::getToPoint(Point(6, World::getWorldInstance()->getNKol()-2));
    }
}

// main action
void Rabbit::Live(){
    int nRandom;
    while(isAlive())
    {
        Hewan::lockHewan();
        nRandom = RandomGenerator::getInstance()->getNextInt(4);
        Hewan::unlockHewan();
        switch (nRandom) {
            case 0:
                Hewan::Wandering();
                break;
            case 1:
                GetToFood();
                break;
            case 2:
                Race();
                break;
            case 3:
                WanderingHop();
                break;
        }
        std::chrono::milliseconds timespan(Hewan::getDeltaT());
        std::this_thread::sleep_for(timespan);
    }
}
