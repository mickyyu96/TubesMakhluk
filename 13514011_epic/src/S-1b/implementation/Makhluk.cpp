// Makhluk.cpp

#include "../header/Makhluk.h"
#include "../header/LMakhluk.h"
#include "../header/World.h"
#include <iostream>
using namespace std;

Makhluk::Makhluk(char _ID, int _maxAge) : ID(_ID), maxAge(_maxAge)
{
}

int Makhluk::isMakhlukInTheSamePoint()
{
    int found = 0;
    World* worldInstance = World::getWorldInstance();
    LMakhluk * _LMakhluk = new LMakhluk();
    _LMakhluk->setFirst(worldInstance->getObjects()->getFirst());

    if (!_LMakhluk->isEmpty())
        {
        while (_LMakhluk->getFirst() != worldInstance->getObjects()->getLast() && !found)
        {
            if (_LMakhluk->getFirst()->getInfo()->isAlive()&&_LMakhluk->getFirst()->getInfo()->getPosition().getX()==getPosition().getX() &&
                _LMakhluk->getFirst()->getInfo()->getPosition().getY()==getPosition().getY()&&_LMakhluk->getFirst()->getInfo()->getID()!=getID())
            {
                found = 1;
            }
            else {
                _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
    }
        }
        if (!found)
        {
            if (_LMakhluk->getFirst()->getInfo()->isAlive()&&_LMakhluk->getFirst()->getInfo()->getPosition().getX()==getPosition().getX() &&
                _LMakhluk->getFirst()->getInfo()->getPosition().getY()==getPosition().getY()&&_LMakhluk->getFirst()->getInfo()->getID()!=getID())
            {
                found = 1;
            }
        }
    }
    return found;
}

Makhluk* Makhluk::MakhlukInTheSamePoint()
{
    Makhluk *_Makhluk;
    int found = 0;
    World* worldInstance = World::getWorldInstance();
    LMakhluk * _LMakhluk = new LMakhluk();
    _LMakhluk->setFirst(worldInstance->getObjects()->getFirst());

    if (!_LMakhluk->isEmpty()&&!found)
    {
        while (_LMakhluk->getFirst() != worldInstance->getObjects()->getLast() && !found)
        {
            if (_LMakhluk->getFirst()->getInfo()->isAlive()&&_LMakhluk->getFirst()->getInfo()->getPosition().getX()==getPosition().getX() &&
                _LMakhluk->getFirst()->getInfo()->getPosition().getY()==getPosition().getY()&&_LMakhluk->getFirst()->getInfo()->getID()!=getID())
            {
                _Makhluk = _LMakhluk->getFirst()->getInfo();
                found = 1;
            }
            else
            {
                _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
            }
        }
        if (!found)
        {
            if (_LMakhluk->getFirst()->getInfo()->isAlive()&&_LMakhluk->getFirst()->getInfo()->getPosition().getX()==getPosition().getX()
                && _LMakhluk->getFirst()->getInfo()->getPosition().getY()==getPosition().getY()&&_LMakhluk->getFirst()->getInfo()->getID()!=getID())
            {
                _Makhluk = _LMakhluk->getFirst()->getInfo();
            }
        }
    }
    return _Makhluk;
}
