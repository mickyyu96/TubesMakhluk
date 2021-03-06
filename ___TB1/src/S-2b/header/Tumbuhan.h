#ifndef TUMBUHAN_H
#define TUMBUHAN_H

#include "Makhluk.h"

/** \class      Tumbuhan
*	\brief      Kelas Turunan dari Makhluk berupa Tumbuhan
*	\details    Kelas Tumbuhan merupakan kelas yang berfungsi untuk mengatur behaviour dan kehidupan dari objek Tumbuhan
*	\author     Elvina Riama K. Situmorang
*	\date       Maret 2016
*/

class Tumbuhan : public Makhluk
{
	public :
		/** \brief      Constructor dari objek bertipe Tumbuhan
	    *   \details    Constructor Tumbuhan yang akan membentuk objek bertipe Tumbuhan
	    *               dengan masukan variable reference Point sebagai posisi awal objek
	    * 	\param      P Point posisi objek akan terbentuk
	    *	\return     Objek bertipe Tumbuhan
	    */
		Tumbuhan(const Point& P);

	private:
		static const char TUMBUHAN_ID = 'G';	    /**< ID Tumbuhan*/
		static const int TUMBUHAN_MAXAGE = 300;	    /**< Umur maksimal Tumbuhan*/
};

#endif
