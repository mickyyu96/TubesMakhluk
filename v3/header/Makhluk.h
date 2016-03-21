#ifndef MAKHLUK_H
#define MAKHLUK_H

#include "Point.h"
#include "World.h"

/** \class		Makhluk
*	\brief		Representasi dari makhluk di alam semesta
*	\details	Kelas Makhluk merupakan kelas abstrak yang memiliki member-member dasar
*				yang akan diturunkan ke kelas lain.
*	\author		Elvina R. K. Situmorang
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

        /** \brief		Prosedur untuk melakukan increment age
		*	\details	Prosedur untuk melakukan increment age semua makhluk
		*	\return		void
		*/
		void AgeIncrement(){age++;}

		/** \brief		Prosedur "Hidup"
		*	\details	Prosedur pure virtual yang akan dioverload dengan aksi-aksi "kehidupan" tiap makhluk
		*	\return		void
		*/
		virtual void Live() = 0;

		/** \brief		Prosedur "Buat Hidup"
		*	\details	Prosedur static yang dimiliki kelas Makhluk, untuk menghidupkan makhluk
		*				yang memanggil prosedur Live dengan memanfaatkan gejala polymorphism
		*	\param		M Makhluk* , pointer-to-Makhluk yang akan dihidupkan
		*	\return		void
		*/
		static void MakeAlive(Makhluk*);

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

	protected :
		/** \brief		Constructor
		*	\details	Merupakan konstruktor protected yang digunakan untuk melakukan set konstanta ID dan maxAge
		*/
		Makhluk(char, int);

	protected :
		const char ID; 			/**< identitas makhluk yang akan ditampilkan ke layar*/
		const int maxAge;		/**< usia maksimum makhluk*/
		int age;				/**< usia makhluk*/
		int status;				/**< status ke"hidup"an makhluk*/
		Point pos;				/**< posisi makhluk*/
};

#endif
