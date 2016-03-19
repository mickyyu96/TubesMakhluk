#include "Rabbit.h"
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

Rabbit::Rabbit(const Point& P): Hewan(RABBIT_ID, RABBIT_MAXAGE) {
    status = 1;
    power = RABBIT_BASEPOWER;
    deltaT = RABBIT_DELTAT;
    pos = P;
}
