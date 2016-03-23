#ifndef IOMANAGER_H
#define IOMANAGER_H

#include "World.h"
#include "Matrix.h"
#include <iostream>
#include <mutex>
using namespace std;

/** \class		IOManager
*	\brief		Abstract Base Class yang merupakan kelas dasar Input/Output
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
};

#endif
