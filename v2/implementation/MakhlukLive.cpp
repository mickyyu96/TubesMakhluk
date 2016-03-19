//
//  MakhlukLive.cpp
//  tubesoopstl
//
//  Created by Atika Azzahra Akbar on 3/19/16.
//  Copyright © 2016 Atika Azzahra Akbar. All rights reserved.
//

#include "MakhlukLive.h"
#include "World.h"
#include "Hewan.h"
#include "LMakhluk.h"

int dx_sign = 1;
int dy_sign = 1;

MakhlukLive* MakhlukLive::_instance = new MakhlukLive;

MakhlukLive::MakhlukLive(){    
}

void MakhlukLive::MakhlukMove(){
    int dx, dy;
    World* worldInstance = World::getWorldInstance();
    
    LMakhluk * _LMakhluk = worldInstance->getObjects();
    
    
    for (int i = 0; i<_LMakhluk->getSize(); i++) {
        if (_LMakhluk->getInfo(i)->isAlive() && _LMakhluk->getInfo(i)->getID()!='G')
        {
            Hewan *_Hewan = static_cast<Hewan*>(_LMakhluk->getInfo(i));
            
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
        }
    }
}

void MakhlukLive::MakhlukEat() {
    World* worldInstance = World::getWorldInstance();
    
    LMakhluk * _LMakhluk = worldInstance->getObjects();
    
    
    for (int i = 0; i<_LMakhluk->getSize(); i++) {
        if (_LMakhluk->getInfo(i)->isAlive() && _LMakhluk->getInfo(i)->getID()!='G')
        {
            if (_LMakhluk->getInfo(i)->isMakhlukInTheSamePoint()) {
                //Makhluk Herbivore
                Makhluk *M1 = _LMakhluk->getInfo(i);
                Makhluk *M2 = _LMakhluk->getInfo(i)->MakhlukInTheSamePoint();
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
}