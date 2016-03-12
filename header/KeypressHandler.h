// KeypressHandler.h
#ifndef KEYPRESSHANDLER_H
#define KEYPRESSHANDLER

#include <conio.h>
#include <iostream>
#include "World.h"
#include "SnapshotCapturer.h"

/** \class		KeypressHandler
 *  \brief		Handler untuk masukan dari user berupa keypress
 *  \details	Kelas KeypressHandler merupakan kelas yang berfungsi untuk menangani keypress 
				yang dimasukkan oleh user
 *	\author		Robert Sebastian Herlim
 *	\date		Maret 2016
 */
 
class KeypressHandler
{
	public :
		/** \brief		Get Singleton Instance dari kelas KeypressHandler
		 *  \details	Mengembalikan pointer dari objek kelas singleton pada kelas KeypressHandler
		 *	\return		Pointer yang menunjuk ke singleton instance pada kelas KeypressHandler
		 */
		static KeypressHandler* getHandlerInstance() { return handlerInstance; }
		
		/** \brief		Get Last Keypress
		 *  \details	Mengembalikan karakter yang terakhir ditekan oleh pengguna yang disimpan dalam instance KeypressHandler
		 *	\return		Karakter yang terakhir ditekan pengguna
		 */
		char getLastKeypress() { return lastKeypress; }

		/** \brief		Prosedur untuk menangani keypress
		 *  \details	Menangani keypress dengan menunggu pengguna menekan tombol, 
		 *				dan melakukan aksi untuk karakter tersebut
		 *	\return		void
		 */
		static void HandleKeypress();
		
		/** \brief		Prosedur untuk menerima keypress
		 *  \details	Menunggu pengguna menekan tombol, 
		 *				serta mengubah karakter lastKeypress yang tersimpan dalam instance KeypressHandler
		 *	\return		void
		 */
		void getKeypress();
		
		/** \brief		Prosedur untuk menjalankan aksi dari keypress
		 *  \details	Melakukan aksi-aksi yang sesuai dengan karakter lastKeypress 
		 *				yang tersimpan dalam instance KeypressHandler
		 *	\return		void
		 */
		void doAction();

	private:
		/** \brief		Constructor
		 *  \details	Menciptakan sebuah instance dari kelas KeypressHandler
		 */
		KeypressHandler();

	private :
		static KeypressHandler* handlerInstance; /**< singleton instance*/
		char lastKeypress; /**< karakter terakhir yang ditekan*/
};

#endif
