// Hewan.cpp
#include "../header/Hewan.h"
using namespace std;

// Implementasi Ctor
Hewan::Hewan(char _ID, int _maxAge) : Makhluk(_ID, _maxAge)
{
}

void Hewan::Move(int dx, int dy)
{
	pos.increment(dx, dy);
}

Makhluk* Hewan::FindFood(){
    if (isVegetarian()) {
        return FindMakhluk('G');
    }
    else{
        return FindMakhluk('*');
    }
}

bool Hewan::isMakhlukinList(char _ID){
    bool found = false;
    LMakhluk * _LMakhluk = new LMakhluk;
    _LMakhluk->setFirst(World::getWorldInstance()->getObjects()->getFirst());
    while (_LMakhluk->getFirst()!=_LMakhluk->getLast() && !found) {
        if (_LMakhluk->getFirst()->getInfo()->getID() == _ID && _LMakhluk->getFirst()->getInfo()->isAlive()) {
            found = true;
        }
        _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
    }
    if (_LMakhluk->getFirst()->getInfo()->getID() == _ID && _LMakhluk->getFirst()->getInfo()->isAlive()) {
        found = true;
    }
    return found;
}

Makhluk* Hewan::FindMakhluk(char _ID){
    // Sudah dipastikan Makhluk ada di List
    // Cari berdasarkan ID di ListMakhluk
    // ID = '*' cari berdasarkan power
    bool found = false;
    int distance = 999;
    Makhluk * _Makhluk = new Rabbit;
    LMakhluk* _LMakhluk = new LMakhluk;
    _LMakhluk->setFirst(World::getWorldInstance()->getObjects()->getFirst());
    while (_LMakhluk->getFirst()!=World::getWorldInstance()->getObjects()->getLast()) {
        if (_LMakhluk->getFirst()->getInfo()->getID() == _ID && _LMakhluk->getFirst()->getInfo()->isAlive()) {
            Point PSearchedMakhluk = _LMakhluk->getFirst()->getInfo()->getPosition();
            Point PThisMakhluk = this->getPosition();
            if (Point::getDistance(PSearchedMakhluk, PThisMakhluk)<distance) {
                distance = Point::getDistance(PSearchedMakhluk, PThisMakhluk);
                _Makhluk = _LMakhluk->getFirst()->getInfo();
            }
        }
        _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
    }
    if (_LMakhluk->getFirst()->getInfo()->getID() == _ID && _LMakhluk->getFirst()->getInfo()->isAlive()) {
        Point PSearchedMakhluk = _LMakhluk->getFirst()->getInfo()->getPosition();
        Point PThisMakhluk = this->getPosition();
        if (Point::getDistance(PSearchedMakhluk, PThisMakhluk)<distance) {
            distance = Point::getDistance(PSearchedMakhluk, PThisMakhluk);
            _Makhluk = _LMakhluk->getFirst()->getInfo();
        }
    }
    
    return _Makhluk;
}

void Hewan::getToPoint(Point P){
    int dx = P.getX()-getPosition().getX();
    int dy = P.getY()-getPosition().getY();
    int i = abs(dx);
    int j = abs(dy);
    int _dx = 1, _dy = 1;
    while (i>0 || j>0) {
        if (dx<0) { _dx = -1; } else if (dx==0) { _dx = 0; }
        if (dy<0) { _dy = -1; } else if (dy==0) { _dy = 0; }
        
        if (i <= 0) { _dx = 0; } else if (j <= 0){ _dy = 0; }
        Move(_dx, _dy);
        std::chrono::milliseconds timespan(deltaT);
        std::this_thread::sleep_for(timespan);
        --i; --j;
    }
}


int Hewan::shouldRebounced(int dx, int dy){
    if (dx+pos.getX()<=0 || dx+pos.getX()>=World::getWorldInstance()->getNBrs()-1) {
        return 1;    }
    if (dy+pos.getY()<=0 || dy+pos.getY()>=World::getWorldInstance()->getNKol()-1) {
        return 1;
    }
    return 0;
}
