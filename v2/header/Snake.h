#ifndef SNAKE_H
#define SNAKE_H

#include "Hewan.h"

/** \class 	    Turtle
 *  \brief 	    Kelas Turunan dari Makhluk berupa Snake
 *  \details 	Kelas Snake merupakan kelas yang berfungsi untuk merepresentasikan objek Snake
 *	\author 	Elvina R. K. Situmorang
 *	\date 		Maret 2016
 */

class Snake : public Hewan
{
	public :
		/** \brief 		Constructor
         *  \details 	Constructor Snake yang akan membentuk objek bertipe Snake
         *   		    dengan masukan variable reference Point sebagai posisi awal objek
         *  \param		konstanta reference Point untuk posisi awal objek
         */
		Snake(const Point&);

	private :
		static const char SNAKE_ID = 'U';       /**< ID Snake*/
		static const int SNAKE_MAXAGE = 150;    /**< Umur Maksimal Snake*/
		static const int SNAKE_BASEPOWER = 5;   /**< Power Snake*/
};

#endif

