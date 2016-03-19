#include "../header/Turtle.h"
#include "../header/LMakhluk.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Turtle::Turtle(const Point& P): Hewan(TURTLE_ID, TURTLE_MAXAGE){
    status = 1;
    power = TURTLE_BASEPOWER;
    deltaT = TURTLE_DELTAT;
    pos = P;
}

void Turtle::Race(){
    bool RabbitCome = false;
    Point PRabbit;
    if (getisChallange()) {        
        while (!RabbitCome) {
            PRabbit = Hewan::FindMakhluk('R')->getPosition();
            if (PRabbit.getX() == 5 && PRabbit.getY()== 1) {
                RabbitCome = true;
                setIsChallange(0);
            }
            else{
                Wandering();
            }
        }
        
        Hewan::getToPoint(Point(5, 1));
        Hewan::getToPoint(Point(5, World::getWorldInstance()->getNKol()-2));
    }
}

void Turtle::GetToFood(){
    if (Hewan::isMakhlukinList('G')) {
        Makhluk *Food = FindFood();
        Hewan::getToPoint(Food->getPosition());
        Food->Kill();
    }
}

int Turtle::isAnyTurtleRacing() {
    int foundRacing = 0;
    LMakhluk* _LMakhluk = new LMakhluk;
    _LMakhluk->setFirst(World::getWorldInstance()->getObjects()->getFirst());
    while (_LMakhluk->getFirst()!=World::getWorldInstance()->getObjects()->getLast() && !foundRacing) {
        if (_LMakhluk->getFirst()->getInfo()->getID() == 'T' && _LMakhluk->getFirst()->getInfo()->isAlive()) {
            if (static_cast<Turtle*>(_LMakhluk->getFirst()->getInfo())->getisChallange()) {
                foundRacing = 1;
            }
        }
        _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
    }
    if (_LMakhluk->getFirst()->getInfo()->getID() == 'R' && _LMakhluk->getFirst()->getInfo()->isAlive() && !foundRacing) {
        if (static_cast<Turtle*>(_LMakhluk->getFirst()->getInfo())->getisChallange()) {
            foundRacing = 1;
        }
    }
    return foundRacing;
}

// main action
void Turtle::Live(){
    int nRandom;
    while(isAlive() && !World::getWorldInstance()->isEnded())
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
                Race();
                break;
        }
        std::chrono::milliseconds timespan(getDeltaT());
        std::this_thread::sleep_for(timespan);
    }
}
