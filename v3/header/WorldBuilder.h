#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H

#include "World.h"
#include <string>

/** \class		WorldBuilder
*	\brief		Builder kelas World
*	\details	Kelas WorldBuilder merupakan BUILDER dari kelas World, dan bertanggung jawab
*				untuk melakukan inisialisasi objek-objek dunia
*	\author		Robert Sebastian Herlim
*	\date		Maret 2016
*/

class WorldBuilder
{
	public:
		/** \brief		Get Singleton Instance dari kelas WorldBuilder
		*	\details	Mengembalikan pointer dari objek singleton pada kelas WorldBuilder
		*	\return		Pointer yang menunjuk ke singleton instance pada kelas WorldBuilder
		*/
		static WorldBuilder* getBuilderInstance() { return builderInstance; }

		/** \brief		Get string makhluk
		*	\details	Mengembalikan sebuah string yang tersimpan dalam instance WorldBuilder
		*				yang merupakan karakter-karakter makhluk yang akan diciptakan
		*	\return		String yang berisi karakter-karakter makhluk yang akan diciptakan
		*/
		string getStrMakhluk() { return strMakhluk; }

		/** \brief		Setter string makhluk
		*	\details	Melakukan assignment string yang tersimpan dalam instance WorldBuilder
		*				dengan string baru yang di-passing melalui parameter
		*	\param		_str const string& String baru yang akan di-assign
		*	\return		void
		*/
		void setStrMakhluk(const string& _str) { strMakhluk = _str; }

		/** \brief		Menambahkan sebuah objek
		*	\details	Menambahkan sebuah objek ke dalam container objek di dunia berdasarkan
		*				ID karakter makhluk yang di-passing melalui parameter
		*	\param		_ID char Karakter yang merupakan ID makhluk yang akan ditambahkan
		*	\return		void
		*/
		void addAnObject(char);

		/** \brief		Build World Objects
		*	\details	Melakukan inisialisasi list of makhluk pada objek singleton kelas World
		*				berdasarkan string yang tersimpan dalam instance WorldBuilder
		*	\return		void
		*/
		void buildWorldObjects();

	private:
		/** \brief		Constructor
		*	\details	Menciptakan sebuah instance WorldBuilder
		*/
		WorldBuilder();

	private:
		static WorldBuilder* builderInstance; /**< pointer yang menunjuk ke instance dari kelas singleton*/
		string strMakhluk; /**< input dari pengguna yang berisi karakter-karakter makhluk yang akan diciptakan*/
};

#endif
