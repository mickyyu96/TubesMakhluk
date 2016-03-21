#ifndef LMAKHLUK_H
#define LMAKHLUK_H

#include <vector>
#include "Makhluk.h"
using namespace std;

/** \class      LMakhluk
 *  \brief      Representasi ADT List of Makhluk
 *  \details    Kelas LMakhluk merupakan kelas yang menampung objek-objek (makhluk)
 *				yang terdapat dalam dunia
 *	\author     Micky Yudi Utama
 *	\date       Maret 2016
 */

class LMakhluk
{
	public :
	    /** \brief      Constructor
		 *  \details    Menciptakan sebuah list of makhluk
		 */
		LMakhluk();

		/** \brief      Destructor
		 *  \details    Menghapus list of makhluk
		 */
		~LMakhluk();

        /** \brief      Menambah element pada list of makhluk
		 *  \details    Menambah element pada bagian belakang list of makhluk
		 *  \param      M Makhluk* Makhluk yang akan ditambah ke list
		 *	\return     void
		 */
		void Add(Makhluk*);

		/** \brief      Fungsi untuk mengecek apakah sebuah list kosong
         *  \details    Mengembalikan 0 jika list kosong, 1 jika list tidak kosong
         *	\return     Bilangan bulat 0 atau 1
         */
		int isEmpty() { return getSize() == 0; }

		/** \brief      Get ukuran list of makhluk
		*	\details    Menghitung jumlah elemen yang ada dalam list of makhluk
		*	\return     Bilangan bulat yang menyatakan jumlah elemen yang ada di list
		*/
		int getSize() { return makhlukVector.size(); }

		/** \brief      Get info makhluk ke-idx
		*	\details    Mengakses isi list pada elemen ke-idx, elemen pertama dihitung sebagai elemen ke-0
		*	\param		idx int Indeks elemen yang mau diakses
		*	\return     Pointer yang menunjuk ke makhluk yang berada pada list elemen ke-idx
		*/
		Makhluk* getInfo(int idx) { return makhlukVector[idx]; }

        /** \brief      Fungsi yang mengecek apakah semua makhluk dalam dunia mati
		*	\details    Mengembalikan 1 jika semua makhluk dalam dunia mati, 0 jika tidak
		*	\return     Bilangan bulat 0 atau 1
		*/
		int IsAllMakhlukDead();

	private:
		vector<Makhluk*> makhlukVector; /**< STL Vector */
};

#endif
