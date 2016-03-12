// Screen.h
#ifndef SCREEN_H
#define SCREEN_H
#include "World.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

/** \class Screen
*	\brief Representasi dari layar pengguna
*	\details Kelas Screen merepresentasikan layar pengguna dan bertanggung jawab untuk melakukan
*			 operasi-operasi Input-Output.
*	\author Robert Sebastian Herlim
*	\date Maret 2016
*/

class Screen
{
	public:
		/** \brief Get Singleton Instance dari kelas Screen
		*  \details Mengembalikan pointer dari objek singleton pada kelas Screen
		*	\return pointer yang menunjuk ke singleton instance pada kelas Screen
		*/
		static Screen* getScreenInstance() { return screenInstance; }

		/** \brief Mencetak sebuah matriks ke layar
		*  \details Mencetak sebuah matriks ke layar
		*	\return void
		*/
		void PrintMatrix(const Matrix&);

		/** \brief Mencetak dunia beserta isinya
		*	\details Mencetak sebuah state dunia beserta pada waktu tertentu
		*			 dengan makhluk-makhluk yang ada di dalamnya ke layar
		*	\return void
		*/
		void PrintWorldMap();

		/** \brief Mencetak dunia beserta isinya secara berkala
		*	\details Mencetak state dunia beserta dengan isi-isinya ke layar 
		*			 secara berkala dengan interval waktu tertentu
		*	\param deltaT int interval waktu (dalam ms) antar pencetakan state dunia ke layar
		*	\return void
		*/
		static void ShowWorld(int);

	private:
		/** \brief Constructor
		*	\details Menciptakan sebuah instance dari kelas Screen
		*/
		Screen();

	private:
		static Screen* screenInstance; /**< pointer yang menunjuk ke instance dari kelas singleton*/
};

#endif