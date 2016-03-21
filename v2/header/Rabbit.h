#ifndef Rabbit_h
#define Rabbit_h

#include <iostream>
#include "Hewan.h"

/** \class      Rabbit
 *  \brief      Kelas Turunan dari Makhluk berupa Rabbit
 *  \details    Kelas Rabbit merupakan kelas yang merepresentasikan objek Rabbit
 *	\author     Atika Azzahra Akbar
 *	\date       Maret 2016
 */

class Rabbit : public Hewan
{
    public :
        /** \brief      Constructor dari objek bertipe Rabbit
         *  \details    Constructor Rabbit yang akan membentuk objek bertipe Rabbit
         *              dengan masukan variable reference Point sebagai posisi awal objek
         *  \param		konstanta reference Point untuk posisi awal objek
         */
        Rabbit(const Point&);

    private :
        static const char RABBIT_ID = 'R';      /**< ID Rabbit*/
        static const int RABBIT_MAXAGE = 60;    /**< Umur maksimal Rabbit*/
        static const int RABBIT_BASEPOWER = 3;  /**< Power Rabbit*/
};

#endif
