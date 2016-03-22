#ifndef WOLF_H
#define WOLF_H

#include <stdio.h>
#include "Hewan.h"

/** \class      Wolf
 *  \brief      Kelas turunan dari Makhluk berupa Wolf
 *  \details    Kelas Wolf merupakan kelas yang berfungsi untuk mengatur behaviour dan
                kehidupan dari objek Wolf
 *	\author     Micky Yudi Utama
 *	\date       Maret 2016
 */

class Wolf : public Hewan
{
    public:
        /** \brief      Constructor
		 *  \details    Menciptakan objek Wolf dengan posisi P
		 *  \param      P const Point& Posisi objek Wolf
		 */
        Wolf(const Point&);

    private:
        static const char WOLF_ID = 'W';        /**< ID Wolf */
        static const int WOLF_MAXAGE = 180;     /**< Umur maksimal Wolf */
        static const int WOLF_BASEPOWER = 6;    /**< Power Wolf */
};

#endif
