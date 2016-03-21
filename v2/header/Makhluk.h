#ifndef MAKHLUK_H
#define MAKHLUK_H

#include "Point.h"
#include "World.h"

/** \class		Makhluk
*	\brief		Representasi dari makhluk di alam semesta
*	\details	Kelas Makhluk merupakan kelas abstrak yang memiliki member-member dasar
*				yang akan diturunkan ke kelas lain.
*	\author		Atika Azzahra Akbar
*	\date		Maret 2016
*/

class Makhluk
{
	public :
		/** \brief		Get ID
		*	\details	Mengambil sebuah karakter ID makhluk
		*	\return		Karakter ID makhluk
		*/
		char getID() const { return ID; }

		/** \brief		Get Age
		*	\details	Mengambil usia makhluk sekarang
		*	\return		Sebuah bilangan bulat yang merupakan usia makhluk sekarang
		*/
		int getAge() const { return age; }

		/** \brief		Get MaxAge
		*	\details	Mengambil usia maksimum makhluk
		*	\return		Sebuah bilangan bulat yang merupakan usia maksimum makhluk
		*/
		int getMaxAge() const { return maxAge; }

		/** \brief		Get Position
		*	\details	Mengambil posisi makhluk sekarang
		*	\return		Sebuah tipe bentukan Point yang merupakan posisi makhluk
		*/
		Point getPosition() const { return pos; }

        /** \brief		Setter Position
		*	\details	Melakukan assignment terhadap posisi makhluk dengan posisi baru
		*	\param		P const Point& , sebuah posisi baru makhluk
		*	\return		void
		*/
		void setPosition(const Point& P) { pos = P; }

        /** \brief      Fungsi validasi
		*	\details    Fungsi untuk mengecek apakah 2 makhluk berada dalam point yang sama
		*	\return     Bilangan bulat 0 atau 1
		*/
		int isMakhlukInTheSamePoint();

        /** \brief      Fungsi yang mengembalikan makhluk yang berada pada point yang sama
		*	\details    Mengembalikan makhluk yang berada pada point yang sama dengan objek.
                        Objek dipastikan bersama dengan makhluk lain pada suatu point.
		*	\return     Pointer to makhluk
		*/
        Makhluk* MakhlukInTheSamePoint();

		/** \brief		Predikat masih hidup
		*	\details	Mengambil status ke"hidup"an makhluk
		*	\return		True apabila makhluk masih hidup
		*/
		int isAlive() { return (status == 1); }

		/** \brief		Prosedur untuk membunuh makhluk
		*	\details	Prosedur yang digunakan untuk membunuh makhluk dari alam semesta, yaitu apabila
		*				dimangsa atau terlalu tua
		*	\return		void
		*/
		void Kill() { status = 0; }

        /** \brief      Prosedur untuk menambah usia
		*	\details    Prosedur untuk menambah usia objek
		*	\return     void
		*/
		void AgeIncrement(){ age++; }

	protected :
	    /** \brief      Constructor
		*	\details    Menciptakan objek Makhluk
		*/
		Makhluk(char, int);

	protected :
		const char ID;      /**< identitas makhluk yang akan ditampilkan ke layar*/
		const int maxAge;   /**< usia maksimum makhluk*/
		int age;            /**< usia makhluk*/
		int status;			/**< status ke"hidup"an makhluk*/
		Point pos;          /**< posisi makhluk*/
};

#endif
