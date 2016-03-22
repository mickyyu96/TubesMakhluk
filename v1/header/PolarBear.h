#ifndef POLARBEAR_H
#define POLARBEAR_H

#include <stdio.h>
#include "Hewan.h"

/** \class      PolarBear
 *  \brief      Kelas turunan dari Makhluk berupa PolarBear
 *  \details    Kelas PolarBear merupakan kelas yang berfungsi untuk mengatur behaviour dan
                kehidupan dari objek PolarBear
 *	\author     Micky Yudi Utama
 *	\date       Maret 2016
 */

class PolarBear : public Hewan
{
	public :
	    /** \brief      Constructor
		 *  \details    Menciptakan objek PolarBear dengan posisi P
		 *  \param      P const Point& Posisi objek PolarBear
		 */
		PolarBear(const Point&);

	private :
		static const char POLARBEAR_ID = 'P';       /**< ID PolarBear */
		static const int POLARBEAR_MAXAGE = 250;    /**< Umur maksimal PolarBear */
		static const int POLARBEAR_BASEPOWER = 8;   /**< Power PolarBear */
};

#endif
