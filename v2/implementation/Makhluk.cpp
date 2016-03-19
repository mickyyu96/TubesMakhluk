// Makhluk.cpp
#include "Makhluk.h"
#include "LMakhluk.h"
#include "World.h"
#include <iostream>
using namespace std;

// IMPLEMENTASI CTOR (Protected)
Makhluk::Makhluk(char _ID, int _maxAge) : ID(_ID), maxAge(_maxAge)
{
}

int Makhluk::isMakhlukInTheSamePoint(){
    int found = 0;
    int i = 0;
    World* worldInstance = World::getWorldInstance();

    LMakhluk * _LMakhluk = worldInstance->getObjects();
    
    while(i<_LMakhluk->getSize() && !found) {
        if (_LMakhluk->getInfo(i)->isAlive()&&_LMakhluk->getInfo(i)->getPosition().getX()==getPosition().getX() && _LMakhluk->getInfo(i)->getPosition().getY()==getPosition().getY()&&_LMakhluk->getInfo(i)->getID()!=getID())
        {
            found = 1;
        }
        else { i++; }
    }
    return found;
}

Makhluk* Makhluk::MakhlukInTheSamePoint(){
    // Pasti _Makhluk di point yang sama ada
    
    Makhluk *_Makhluk;
    int i = 0;
    int found = 0;
    World* worldInstance = World::getWorldInstance();
    
    LMakhluk * _LMakhluk = worldInstance->getObjects();
    
    while(i<_LMakhluk->getSize()&&!found) {
        if (_LMakhluk->getInfo(i)->isAlive()&&_LMakhluk->getInfo(i)->getPosition().getX()==getPosition().getX() && _LMakhluk->getInfo(i)->getPosition().getY()==getPosition().getY()&&_LMakhluk->getInfo(i)->getID()!=getID())
        {
            _Makhluk = _LMakhluk->getInfo(i);
            found = 1;
        }
        else { i++; }
    }
    return _Makhluk;
}