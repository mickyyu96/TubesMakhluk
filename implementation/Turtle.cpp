#include "../header/Turtle.h"
#include "../header/LMakhluk.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int dx =1;
int dy =1;

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
        PRabbit = Hewan::FindMakhluk('R')->getPosition();
        if (PRabbit.getX() == 5 && PRabbit.getY()== 1) {
            RabbitCome = true;
        }

        Hewan::getToPoint(Point(5, 1));
        while (!RabbitCome) {
            PRabbit = Hewan::FindMakhluk('R')->getPosition();
            if (PRabbit.getX() == 5 && PRabbit.getY()== 1) {
                RabbitCome = true;
                setIsChallange(0);
            }
        }
        Hewan::getToPoint(Point(5, World::getWorldInstance()->getNKol()-2));
    }
}

void Turtle::GetToFood(){
    if (Hewan::isMakhlukinList('G')) {
        Hewan::getToPoint(Hewan::FindFood()->getPosition());
        Hewan::FindFood()->Kill();
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
