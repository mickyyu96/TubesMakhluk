// RandomGenerator.h

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <stdlib.h>
#include <time.h>
#include "Point.h"

class RandomGenerator
{
    private:
        RandomGenerator();

    public:
        static RandomGenerator* getInstance() { return _instance; }
        int getNextInt(int);
        int getNextIntBetween(int, int);
        Point getNextPoint(int, int); 

    private:
        static RandomGenerator* _instance;
};

# endif // RandomGenerator_H
