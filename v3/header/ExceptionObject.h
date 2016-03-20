// ExceptionObject.h
#ifndef EXCEPTIONOBJECT_H
#define EXCEPTIONOBJECT_H
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

/** \class		ExceptionObject
*	\brief		Kelas untuk membantu menangani exception yang muncul dari kesalahan masukan pengguna
*	\details	Kelas ExceptionObject menyediakan sebuah instance untuk dilempar ke ExceptionHandler apabila masukan pengguna salah
*	\author		Robert Sebastian Herlim
*	\date		Maret 2016
*/
class ExceptionObject
{
	public :
		/** \brief		Constructor
		 *  \details	Menciptakan sebuah instance dari kelas ExceptionObject dengan id yang di-passing melalui parameter
		 *	\param		_ID int id yang merupakan id_kesalahan yang dilakukan
		 */
		ExceptionObject(int);
		/** \brief		Prosedur untuk menampilkan pesan kesalahan
		 *  \details	Menampilkan pesan kesalahan ke sebuah message box berdasarkan id_kesalahan yang disimpan dalam data member
		 */
		void DisplayErrorMessage();
		
	private :
		int id; /**< id_kesalahan */
		const string message[4] = {
			">> ERROR! Dimensi ukuran dunia harus > 6!", 
			">> ERROR! Ada ID yang tidak dikenali!",
			">> ERROR! Pause World dulu sebelum melakukan Single-step Execution!",
			">> ERROR! Keypress tidak dikenali!"
		}; /**< pesan kesalahan */
};

#endif
