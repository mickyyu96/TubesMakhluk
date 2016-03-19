// Sheep.h

#ifndef SHEEP_H
#define SHEEP_H

#include <stdio.h>
#include "Hewan.h"

/** \class      Sheep
 *  \brief      Kelas turunan dari Makhluk berupa Sheep
 *  \details    Kelas Sheep merupakan kelas yang berfungsi untuk mengatur behaviour dan
                kehidupan dari objek Sheep
 *	\author     Micky Yudi Utama
 *	\date       Maret 2016
 */

class Sheep : public Hewan
{
    public:
        /** \brief      Constructor
		 *  \details    Menciptakan objek Sheep dengan posisi P
		 *  \param      P const Point& Posisi objek Wolf
		 */
        Sheep(const Point&);

        /** \brief      Fungsi untuk menentukan apakah Sheep vegetarian
		 *  \details    Fungsi akan selalu mengembalikan bilangan bulat 1 karena Sheep vegetarian
		 *	\return     Bilangan bulat 1
		 */
        int isVegetarian() { return 1; }

        /** \brief      Getter DeltaT Wolf
		 *  \details    Fungsi untuk memperoleh DeltaT makhluk Wolf
		 *	\return     Bilangan bulat berupa DeltaT Wolf
		 */
        int getDeltaT() { return Hewan::getDeltaT(); }
    private:
        static const char SHEEP_ID = 'S';       /**< ID Sheep */
        static const int SHEEP_MAXAGE = 25;     /**< Umur maksimal Sheep */
        static const int SHEEP_BASEPOWER = 4;   /**< Power Sheep */
        static const int SHEEP_DELTAT = 500;    /**< DeltaT Sheep */
};

#endif // Sheep.h
