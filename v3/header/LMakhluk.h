#ifndef LMAKHLUK_H
#define LMAKHLUK_H

#include <cstdlib>
#include <thread>
#include "Makhluk.h"
#define MAX_THREAD 55
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

		/** \brief      Menghapus element pada list of makhluk
		 *  \details    Menghapus makhluk M pada list of makhluk
		 *  \param      M Makhluk* Makhluk yang akan dihapus dari list
		 *	\return     void
		 */
		void Del(Makhluk*);

	private :

	    /** \class      ElmtMakhluk
         *  \brief      Element Makhluk
         *  \details    Menciptakan sebuah makhluk
         */
		class ElmtMakhluk
		{
			public :
			    /** \brief      Constructor
                 *  \details    Menciptakan sebuah makhluk dengan info NULL
                 */
				ElmtMakhluk();

				/** \brief      Constructor
                 *  \details    Menciptakan sebuah makhluk dengan info yang di pass dari parameter
                 *  \param      _info Makhluk* Info dari makhluk
                 *  \param      _next Makhluk* Next dari makhluk
                 */
				ElmtMakhluk(Makhluk*, ElmtMakhluk*);

				/** \brief      Destructor
                 *  \details    Menghapus makhluk
                 */
				~ElmtMakhluk();

                /** \brief      Get info makhluk
                 *  \details    Mengambil info dari makhluk
                 *	\return     Info makhluk
                 */
				Makhluk* getInfo() { return info; }

				/** \brief      Set info makhluk
                 *  \details    Mengassign info makhluk berdasarkan parameter
                 *  \param      _info Makhluk* Info dari makhluk
                 *	\return     void
                 */
				void setInfo(Makhluk* _info) { info = _info; }

				/** \brief      Get next makhluk
                 *  \details    Mengambil next dari makhluk
                 *	\return     Next makhluk
                 */
				ElmtMakhluk* getNext() { return next; }

				/** \brief      Set next makhluk
                 *  \details    Mengassign next makhluk berdasarkan parameter
                 *  \param      _next ElmtMakhluk* Next dari makhluk
                 *	\return     void
                 */
				void setNext(ElmtMakhluk* _next) { next = _next; }

			private:
				Makhluk* info;      /**< info dari makhluk */
				ElmtMakhluk* next;  /**< next dari makhluk */
		};

	private :
		ElmtMakhluk* first;     /**< element pertama dari list of makhluk */
		thread t[MAX_THREAD];   /**< thread-thread dari elemen list */
		int thread_count;       /**< jumlah thread */

	public :
	    /** \brief      Get first element
         *  \details    Mengambil first element dari list of makhluk
         *	\return     First element
         */
		ElmtMakhluk* getFirst() { return first; }

		/** \brief      Set first element
         *  \details    Mengassign first element list berdasarkan parameter
         *  \param      _first ElmtMakhluk* First element dari list of makhluk
         *	\return     void
         */
		void setFirst(ElmtMakhluk* _first) { first = _first; }

		/** \brief      Fungsi untuk mengecek apakah sebuah list kosong
         *  \details    Mengembalikan 0 jika list kosong, 1 jika list tidak kosong
         *	\return     Bilangan bulat 0 atau 1
         */
		int isEmpty() { return getFirst() == NULL; }

		/** \brief      Get ukuran list of makhluk
		*	\details    Menghitung jumlah elemen yang ada dalam list of makhluk
		*	\return     Bilangan bulat yang menyatakan jumlah elemen yang ada di list
		*/
		int getSize();

		/** \brief      Get info makhluk ke-idx
		*	\details    Mengakses isi list pada elemen ke-idx, elemen pertama dihitung sebagai elemen ke-0
		*	\param		idx int Indeks elemen yang mau diakses
		*	\return     Pointer yang menunjuk ke makhluk yang berada pada list elemen ke-idx
		*/
		Makhluk* getInfo(int);

        /** \brief      Get last element
         *  \details    Mengambul last element dari list of makhluk
         *	\return     Last element
         */
		ElmtMakhluk* getLast();

        /** \brief      Mencari element sebelum sebuah makhluk
         *  \details    Mencari element sebelum sebuah makhluk pada list of makhluk
         *  \param      M Makhluk* Makhluk yang akan dicari element sebelumnya
         *	\return     Element sebelum makhluk M
         */
		ElmtMakhluk* findPrecMakhluk(Makhluk*);

		/** \brief      Mencari sebuah makhluk
         *  \details    Mencari sebuah makhluk pada list of makhluk
         *  \param      M Makhluk* Makhluk yang akan dicari
         *	\return     Makhluk M
         */
		ElmtMakhluk* findMakhluk(Makhluk*);

		void ListAgeIncrement();

		int IsAllMakhlukDead();
};

#endif
