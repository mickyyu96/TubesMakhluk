// IOManager.h
#ifndef IOMANAGER_H
#define IOMANAGER_H
#include "World.h"
#include "Matrix.h"
#include <iostream>
#include <mutex>
using namespace std;

/** \class		IOManager
*	\brief		Kelas dasar Input/Output
*	\details	Kelas IOManager bertanggung jawab untuk melakukan operasi-operasi Input/Output.
*	\author		Robert Sebastian Herlim
*	\date		Maret 2016
*/

class IOManager
{
	public :
		/** \brief		Mencetak sebuah matriks ke layar
		*	\details	Mencetak sebuah matriks ke layar
		*	\return		void
		*/
		void PrintMatrix(const Matrix&);

		/** \brief		Mencetak dunia beserta isinya
		*	\details	Mencetak sebuah state dunia beserta pada waktu tertentu
		*				dengan makhluk-makhluk yang ada di dalamnya ke layar
		*	\return		void
		*/
		void PrintWorldMap();

		/** \brief		Mengunci gembok operasi I/O
		*	\details	Mencegah operasi I/O yang berlangsung secara simultan
		*	\return		void
		*/
		static void lockIOLock() { IOLock.lock(); }

		/** \brief		Membuka gembok operasi I/O
		*	\details	Mengizinkan operasi I/O untuk berlangsung secara simultan kembali
		*	\return		void
		*/
		static void unlockIOLock() { IOLock.unlock(); }

	private :
		static mutex IOLock; /**< I/O mutex untuk mencegah I/O yang simultan */
};


#endif