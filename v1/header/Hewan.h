#ifndef HEWAN_H
#define HEWAN_H

#include "Makhluk.h"
#include "Point.h"
using namespace std;

/** \class 	    Hewan
 *  \brief 	    Abstract Base Class yang merupakan Kelas Turunan dari Makhluk
 *  \details 	Kelas Hewan merupakan kelas yang berfungsi untuk mengimplementasikan behaviour yang
                yang dimiliki oleh turunan kelas Hewan
 *  \author 	Atika Azzahra Akbar
 *  \date		Maret 2016
 */

class Hewan : public Makhluk
{
	public :
        /** \brief 	    Procedure virtual tidak pure untuk menggerakan objek bertipe turunan kelas Hewan
        *   \details 	Menggerakan objek bertipe turunan kelas Hewan berdasarkan dua masukan bertipe integer
        *   		    posisi objek akan berubah sebesar masukan tersebut
        *   \param	    integer delta x
        *   \param 	    integer delta y
        *   \return 	void
        */
        virtual void Move(int, int);

        /** \brief 	    Fungsi getter untuk mendapatkan nilai power sebuah objek
        *   \details 	Mengembalikan nilai power sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
        *   		    saat ctor sebuah objek
        *   \return 	integer
        */
        int getPower() { return power; }

        /** \brief 	    Fungsi validasi objek untuk Rebounce
        *   \details 	Mendapatkan validasi apakah nilai dx dan dy akan mengakibatkan posisi
        *   		    objek lebih dari batas World
        *   \param	    integer delta x
        *   \param	    integer delta y
        *   \return 	TRUE bila dx atau dy akan membuat posisi objek lebih dari batas
        */
        int shouldRebounced(int dx, int dy);

	protected :
		/** \brief  	Constructor
        *   \details 	Constructor Hewan yang akan membentuk objek bertipe Hewan
        *   		    yang dapat dicasting dengan objek bertipe turunan kelas Hewan
        *   \param	    character ID Makhluk
        *   \param	    integer maxAge Makhluk
        */
		Hewan(char, int);

	protected :
		int hungerLvl, power, deltaT; /**< status level kelaparan, power, dan deltaT sebuah objek*/
};

#endif
