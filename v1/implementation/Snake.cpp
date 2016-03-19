// Rabbit.cpp
#include "../header/Snake.h"
#include <thread>
#include <chrono>
using namespace std;

Snake::Snake() : Hewan(SNAKE_ID, SNAKE_MAXAGE)
{
    status = 1;
    power = SNAKE_BASEPOWER;
    deltaT = SNAKE_DELTAT;
    pos = Point();
}

Snake::Snake(const Point& P): Hewan(SNAKE_ID, SNAKE_MAXAGE) {
    status = 1;
    power = SNAKE_BASEPOWER;
    deltaT = SNAKE_DELTAT;
    pos = P;
}

void GoToFood(Point P) {
    if (P.getX() < Hewan::this->getPosition().getX()) {
        while (Hewan::this->getPosition().getX() > P.getX()) {
            if (Hewan::shouldRebounced(0,1))
                Hewan::Move(0,-1);
            else
                Hewan::Move(0,1);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            Hewan::Move(1,0);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            if (Hewan::shouldRebounced(0,-1))
                Hewan::Move(0,1);
            else
                Hewan::Move(0,-1);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
        }
    }
    else {
        while (Hewan::this->getPosition().getX() < P.getX()) {
            if (Hewan::shouldRebounced(0,1))
                Hewan::Move(0,-1);
            else
                Hewan::Move(0,1);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            Hewan::Move(-1,0);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            if (Hewan::shouldRebounced(0,-1))
                Hewan::Move(0,1);
            else
                Hewan::Move(0,-1);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
        }
    }

    if (P.getY() < Hewan::this->getPosition().getY()) {
        while (Hewan::this->getPosition().getY() > P.getY()) {
            if (Hewan::shouldRebounced(1,0))
                Hewan::Move(-1,0);
            else
                Hewan::Move(1,0);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            Hewan::Move(0,1);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            if (Hewan::shouldRebounced(1,0))
                Hewan::Move(-1,0);
            else
                Hewan::Move(1,0);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
        }
    }
    else {
        while (Hewan::this->getPosition().getY() < P.getY()) {
            if (Hewan::shouldRebounced(1,0))
                Hewan::Move(-1,0);
            else
                Hewan::Move(1,0);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            Hewan::Move(0,-1);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
            if (Hewan::shouldRebounced(1,0))
                Hewan::Move(-1,0);
            else
                Hewan::Move(1,0);
            std::chrono::milliseconds timespan(deltaT);
            std::this_thread::sleep_for(timespan);
        }

    }
    Hewan::Move(P.getX(), P.getY());
}

// actions
void Snake::GetToFood(){
    if ((Hewan::isMakhlukinList('R') || Hewan::isMakhlukinList('T') || Hewan::isMakhlukinList('P')) {
        while (Hewan::isMakhlukinList(Hewan::FindFood())) {
            GoToFood(Hewan::FindFood()->getPosition());
        }
    }
}

void Snake::ZigZag(){
    int dx, dy;

    int nRandom = RandomGenerator::getInstance()->getNextInt(2);
    switch (nRandom) {
        case 0 : {
            if (Hewan::shouldRebounced(0,1)) {
                Hewan::Move(0,-1);
            }
            else
                Hewan::Move(0,1);
            break;
        }

        case 1 : {
            if (Hewan::shouldRebounced(0,-1)) {
                Hewan::Move(0,1);
            }
            else
                Hewan::Move(0,-1);
            break;
        }
    }
    std::chrono::milliseconds timespan(deltaT);
    std::this_thread::sleep_for(timespan);

    nRandom = RandomGenerator::getInstance()->getNextInt(2);
    switch (nRandom) {
        case 0 : {
            if (Hewan::shouldRebounced(1,0)) {
                Hewan::Move(-1,0);
            }
            else
                Hewan::Move(1,0);
            break;
        }
        case 1 : {
            if (Hewan::shouldRebounced(-1,0)) {
                Hewan::Move(1,0);
            }
            else
                Hewan::Move(-1,0);
            break;
        }
    }

    std::this_thread::sleep_for(timespan);
}

// main action
void Snake::Live(){
    int nRandom;
    while(isAlive())
    {
        nRandom = RandomGenerator::getInstance()->getNextInt(2);
        switch (nRandom) {
            case 0: {
                for (int i=0; i<10; ++i)
                    ZigZag();
                break;
            }
            case 1:
                GetToFood();
                break;
        }
        Hewan::Sleep();
    }
}

