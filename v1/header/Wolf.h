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

        /** \brief      Fungsi untuk menentukan apakah Wolf vegetarian
		 *  \details    Fungsi akan selalu mengembalikan bilangan bulat 0 karena Wolf
                        bukan vegetarian
		 *	\return     Bilangan bulat 0
		 */
        int isVegetarian() { return 0; }

        /** \brief      Getter DeltaT Wolf
		 *  \details    Fungsi untuk memperoleh DeltaT makhluk Wolf
		 *	\return     Bilangan bulat berupa DeltaT Wolf
		 */
        int getDeltaT() { return Hewan::getDeltaT(); }

    private:
        static const char WOLF_ID = 'W';        /**< ID Wolf */
        static const int WOLF_MAXAGE = 20;      /**< Umur maksimal Wolf */
        static const int WOLF_BASEPOWER = 6;    /**< Power Wolf */
        static const int WOLF_DELTAT = 300;     /**< DeltaT Wolf */
};

#endif // Wolf.h
