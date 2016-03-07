// main.cpp
#include <iostream>
#include "Rabbit.h"
#include "LMakhluk.h"
#include "Makhluk.h"
#include "Matrix.h"
#include "Hewan.h"
#include "Point.h"
#include <algorithm>
#include <time.h>
#include <thread>
using namespace std;
void PrintW(){
    while (1==1) {
        World::getWorldInstance()->PrintMap();
        std::chrono::milliseconds timespan(500);
        std::this_thread::sleep_for(timespan);
    }
}
static const int num_threads = 4;
int main()
{
    thread t[num_threads];
    World::getWorldInstance()->getObjects()->Add(new Rabbit(Point(2,5)));
    World::getWorldInstance()->getObjects()->Add(new Rabbit(Point(3,5)));
    World::getWorldInstance()->getObjects()->Add(new Rabbit(Point(8,5)));
    World::getWorldInstance()->getObjects()->Add(new Rabbit(Point(9,5)));
    thread t3(PrintW);
    
    LMakhluk* _LMakhluk = new LMakhluk;
    _LMakhluk->setFirst(World::getWorldInstance()->getObjects()->getFirst());
    int i = 0;
    while (_LMakhluk->getFirst()!=World::getWorldInstance()->getObjects()->getLast()) {
        t[i] = thread(Makhluk::MakeAlive, _LMakhluk->getFirst()->getInfo());
        _LMakhluk->setFirst(World::getWorldInstance()->getObjects()->getFirst()->getNext());
        i++;
    }
    t[i] = thread(Makhluk::MakeAlive, _LMakhluk->getFirst()->getInfo());
    
    for(int j = 0; j<=i; j++){
        t[j].join();
    }
    t3.join();
	return 0;
}
