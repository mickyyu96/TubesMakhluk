#include "../header/MakhlukLive.h"
#include "../header/World.h"
#include "../header/Hewan.h"
#include "../header/LMakhluk.h"
#include <iostream>
int dx_sign = 1;
int dy_sign = 1;

MakhlukLive* MakhlukLive::_instance = new MakhlukLive;

MakhlukLive::MakhlukLive(){
}

void MakhlukLive::MakhlukMove(){
    int dx, dy;
    World* worldInstance = World::getWorldInstance();
    LMakhluk * _LMakhluk = new LMakhluk();
    _LMakhluk->setFirst(worldInstance->getObjects()->getFirst());

    if (!_LMakhluk->isEmpty())
    {
        while (_LMakhluk->getFirst() != worldInstance->getObjects()->getLast())
        {
            if (_LMakhluk->getFirst()->getInfo()->isAlive() && _LMakhluk->getFirst()->getInfo()->getID()!='G')
            {

                Hewan *_Hewan = static_cast<Hewan*>(_LMakhluk->getFirst()->getInfo());

                dx = RandomGenerator::getInstance()->getNextInt(2)*dx_sign;
                dy = RandomGenerator::getInstance()->getNextInt(2)*dy_sign;

                if (_Hewan->shouldRebounced(dx, 0)) {
                    dx *= -1;
                    dx_sign *= -1;
                }
                if (_Hewan->shouldRebounced(0, dy)) {
                    dy *= -1;
                    dy_sign *= -1;
                }

                _Hewan->Move(dx, dy);
                _Hewan->AgeIncrement();
                //std::cout<<"Y"<<std::endl;
                if(_Hewan->getAge()==_Hewan->getMaxAge())
                {
                    _Hewan->Kill();
                }
            }
            _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
        }

        if (_LMakhluk->getFirst()->getInfo()->isAlive() && _LMakhluk->getFirst()->getInfo()->getID()!='G')
        {
            Hewan *_Hewan = static_cast<Hewan*>(_LMakhluk->getFirst()->getInfo());
            dx = RandomGenerator::getInstance()->getNextInt(2)*dx_sign;
            dy = RandomGenerator::getInstance()->getNextInt(2)*dy_sign;

            if (_Hewan->shouldRebounced(dx, 0)) {
                dx *= -1;
                dx_sign *= -1;
            }
            if (_Hewan->shouldRebounced(0, dy)) {
                dy *= -1;
                dy_sign *= -1;
            }

            _Hewan->Move(dx, dy);
            _Hewan->AgeIncrement();
                if(_Hewan->getAge()==_Hewan->getMaxAge())
                {
                    _Hewan->Kill();
                }
        }
    }
}

void MakhlukLive::MakhlukEat() {
    World* worldInstance = World::getWorldInstance();
    LMakhluk * _LMakhluk = new LMakhluk();
    _LMakhluk->setFirst(worldInstance->getObjects()->getFirst());

    while (_LMakhluk->getFirst() != worldInstance->getObjects()->getLast()) {
        if (_LMakhluk->getFirst()->getInfo()->isAlive() && _LMakhluk->getFirst()->getInfo()->getID()!='G')
        {
            if (_LMakhluk->getFirst()->getInfo()->isMakhlukInTheSamePoint()) {
                //Makhluk Herbivore
                Makhluk *M1 = _LMakhluk->getFirst()->getInfo();
                Makhluk *M2 = _LMakhluk->getFirst()->getInfo()->MakhlukInTheSamePoint();
                if (((M1)->getID()=='R')||((M1)->getID()=='T')||((M1)->getID()=='S')) {
                    if ((M2)->getID()=='G') {
                        M2->Kill();
                    }
                }
                else{
                    //Makhluk Karnivor
                    if (M2->getID()!='G'&& M2->getID()!=M1->getID()) {
                        if (static_cast<Hewan*>(M2)->getPower()<static_cast<Hewan*>(M1)->getPower()) {
                            M2->Kill();
                        }
                    }
                }
            }
        }
        _LMakhluk->setFirst(_LMakhluk->getFirst()->getNext());
    }
    if (_LMakhluk->getFirst()->getInfo()->isAlive() && _LMakhluk->getFirst()->getInfo()->getID()!='G')
    {
        if (_LMakhluk->getFirst()->getInfo()->isMakhlukInTheSamePoint()) {
            //Makhluk Herbivore
            Makhluk *M1 = _LMakhluk->getFirst()->getInfo();
            Makhluk *M2 = _LMakhluk->getFirst()->getInfo()->MakhlukInTheSamePoint();
            if (((M1)->getID()=='R')||((M1)->getID()=='T')||((M1)->getID()=='S')) {
                if ((*M2).getID()=='G') {
                    M2->Kill();
                }
            }
            else{
                //Makhluk Karnivor
                if (M2->getID()!='G') {
                    if (static_cast<Hewan*>(M2)->getPower()<static_cast<Hewan*>(M1)->getPower()) {
                        M2->Kill();
                    }
                }
            }
        }
    }
}
