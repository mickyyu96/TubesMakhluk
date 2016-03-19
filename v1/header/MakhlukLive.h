#ifndef MakhlukLive_h
#define MakhlukLive_h

#include "Point.h"
#include "Makhluk.h"

class MakhlukLive {
    private:
        MakhlukLive();
    public:
        static MakhlukLive* getInstance() { return _instance; };
        void MakhlukMove();
        void MakhlukEat();
    private:
        static MakhlukLive* _instance;
};

#endif /* MakhlukLive_h */
