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

        /** \brief      Prosedur aksi Sheep untuk mendapatkan makanan
		 *  \details    Prosedur aksi Sheep untuk pergi ke makanannya
		 *	\return     void
		 */
        void GetToFood();

        /** \brief      Prosedur aksi Sheep
		 *  \details    Prosedur aksi Sheep untuk mengelilingi dunia
		 *	\return     void
		 */
        void WanderingS();

        /** \brief      Prosedur hidup Sheep
		 *  \details    Prosedur untuk menentukan apa yang akan dilakukan oleh Sheep
                        ketika masih hidup
		 *	\return     void
		 */
        void Live();

    private:
        static const char SHEEP_ID = 'S';       /**< ID Sheep */
        static const int SHEEP_MAXAGE = 80;     /**< Umur maksimal Sheep */
        static const int SHEEP_BASEPOWER = 4;   /**< Power Sheep */
        static const int SHEEP_DELTAT = 800;    /**< DeltaT Sheep */
};

#endif
