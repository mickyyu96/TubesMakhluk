// World.h
#ifndef WORLD_H
#define WORLD_H

#include "RandomGenerator.h"
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

class LMakhluk; // forward class declaration

/** \class		World
*	\brief		Representasi dari alam semesta
*	\details	Kelas World merepresentasikan alam semesta yang terdiri dari 
*				sebuah "ruang" (space) fiktif yang memiliki dimensi panjang dan lebar
*				dan sekumpulan makhluk-makhluk (objects) yang bisa bergerak secara independen.
*	\author		Robert Sebastian Herlim
*	\date		Maret 2016
*/
class World {
	public :
		/** \brief		Get List of Makhluk
		*	\details	Mengambil list of makhluk-makhluk yang hidup di dalam dunia tersebut
		*	\return		List yang berisi pointer ke makhluk-makhluk yang ada dalam dunia
		*/
		LMakhluk* getObjects() { return objects; }

		/** \brief		Get Singleton Instance dari kelas World
		*	\details	Mengembalikan pointer dari objek singleton pada kelas World
		*	\return		Pointer yang menunjuk ke singleton instance pada kelas World
		*/
		static World* getWorldInstance() { return worldInstance; }

		/** \brief		Get jumlah baris
		*	\details	Mengembalikan jumlah baris yang merupakan dimensi panjang dari ukuran ruang dunia
		*	\return		Bilangan bulat yang menyatakan dimensi panjang dari ukuran ruang dunia
		*/
		int getNBrs() { return NBrs; }

		/** \brief		Get jumlah kolom
		*	\details	Mengembalikan jumlah kolom yang merupakan dimensi lebar dari ukuran ruang dunia
		*	\return		Bilangan bulat yang menyatakan dimensi lebar dari ukuran ruang dunia
		*/
		int getNKol() { return NKol; }
		
		/** \brief		Set jumlah baris
		*	\details	Melakukan assignment jumlah baris yang merupakan dimensi panjang dari ukuran ruang dunia
		*	\param		_NBrs int Jumlah baris baru yang akan di-assign
		*	\return		void
		*/
		void setNBrs(int _NBrs) { NBrs = _NBrs; }

		/** \brief		Set jumlah kolom
		*	\details	Mengembalikan jumlah kolom yang merupakan dimensi lebar dari ukuran ruang dunia
		*	\param		_NKol int Jumlah kolom baru yang akan di-assign
		*	\return		void
		*/
		void setNKol(int _NKol) { NKol = _NKol; }

		/** \brief		Get status isEnded
		*	\details	Predikat untuk menyatakan apakah aktivitas dunia sudah berakhir
		*	\return		TRUE apabila aktivitas dunia sudah berakhir
		*/
		int isEnded() { return _isEnded; }

		/** \brief		Get status isPaused
		*	\details	Predikat untuk menyatakan apakah aktivitas dunia sedang diberhentikan
		*	\return		TRUE apabila aktivitas dunia sudah berakhir
		*/
		int isPaused() { return _isPaused; }

		/** \brief		Mengakhiri aktivitas dunia
		*	\details	Mengubah status isEnded menjadi TRUE yang menandakan dunia sudah berakhir
		*	\return		void
		*/
		void endWorld() {_isEnded = 1; }

		/** \brief		Mengubah status berjalannya aktivitas dunia
		*	\details	Mengubah status isPaused menjadi kebalikannya, yang mengakibatkan
		*				apabila dunia sedang bergerak akan berhenti dan 
		*				apabila dunia sedang berhenti akan bergerak kembali 
		*	\return		void
		*/
		void changePauseState();

		/** \brief		Memberhentikan aktivitas dunia
		*	\details	Mengubah status isPaused menjadi TRUE, dan memberhentikan semua aktivitas dunia
		*	\return		void
		*/
		void lockWorld();

		/** \brief		Melanjutkan aktivitas dunia
		*	\details	Mengubah status isPaused menjadi FALSE, dan menjalankan kembali semua aktivitas dunia
		*	\return		void
		*/
		void unlockWorld();

		/** \brief		Mengeksekusi sebuah langkah pergerakan aktivitas dunia
		*	\details	Menampilkan tepat satu langkah perubahan state dunia akibat aktivitas dari objek-objek dunia
		*	\return		void
		*/
		void singleStepExecution();

	private :
		/** \brief		Constructor
		*	\details	Menciptakan sebuah dunia dengan ukuran tertentu yang di-passing melalui parameter
		*	\param		_NBrs int Jumlah baris dunia yang akan diciptakan
		*	\param		_NKol int Jumlah kolom dunia yang akan diciptakan
		*/
		World(int, int);
		
	private :
		LMakhluk* objects; /**< objek-objek yang berada di dalam dunia*/

		int _isEnded; /**< status berakhirnya aktivitas dunia*/
		int _isPaused; /**< status berhentinya aktivitas dunia*/
		mutex worldLock; /**< mutex untuk kunci lock aktivitas saat dunia diberhentikan */

		static World* worldInstance; /**< pointer yang menunjuk ke instance dari kelas singleton*/

		int NBrs; /**< dimensi panjang dari ukuran dunia*/
		int NKol; /**< dimensi lebar dari ukuran dunia*/
};

#endif
