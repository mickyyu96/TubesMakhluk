#ifndef Turtle_h
#define Turtle_h

#include "Hewan.h"

/** \class  	Turtle
 *  \brief 	    Kelas Turunan dari Makhluk berupa Turtle
 *  \details 	Kelas Rabbit merupakan kelas yang berfungsi untuk merepresentasikan objek Turtle
 *	\author 	Atika Azzahra Akbar
 *	\date 		Maret 2016
 */

class Turtle : public Hewan
{
    public :
        /** \brief 		Constructor
         *  \details 	Constructor Turtle yang akan membentuk objek bertipe Turtle
         *   		    dengan masukan variable reference Point sebagai posisi awal objek
         *  \param		konstanta reference Point untuk posisi awal objek
         */
        Turtle(const Point&);

    private :
        static const char TURTLE_ID = 'T';      /**< ID Turtle*/
        static const int TURTLE_MAXAGE = 240;    /**< Umur maksimal Turtle*/
        static const int TURTLE_BASEPOWER = 2;  /**< Power Turtle*/
};

#endif
