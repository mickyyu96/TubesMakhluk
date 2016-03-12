// Screen.h
#ifndef SCREEN_H
#define SCREEN_H
#include "World.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

class Screen
{
	public:
		static Screen* getScreenInstance() { return screenInstance; }

		/** \brief Prosedur untuk print sebuah matriks
		*  \details Mencetak matriks ke layar
		*	\return void
		*/
		void PrintMatrix(const Matrix&);

		/** \brief Print dunia beserta isinya
		*	\details Mencetak state dunia beserta dengan makhluk-makhluk yang ada di dalamnya ke layar
		*	\return void
		*/
		void PrintWorldMap();

		/** \brief Print dunia beserta isinya secara berkala
		*	\details Mencetak state dunia beserta dengan isi-isinya ke layar 
		*			 secara berkala dengan interval waktu tertentu
		*	\param deltaT int interval waktu (dalam ms) antar pencetakan state dunia ke layar
		*	\return void
		*/
		static void ShowWorld(int);

	private:
		Screen();

	private:
		static Screen* screenInstance;
};

#endif