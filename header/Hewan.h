// Hewan.h
#ifndef HEWAN_H
#define HEWAN_H

#include "Makhluk.h"
#include "Point.h"
#include <mutex>
using namespace std;

/** \class Hewan
 *  \brief Abstract Base Class yang merupakan Kelas Turunan dari Makhluk
 *  \details Kelas Hewan merupakan kelas yang berfungsi untuk mengimplementasikan behaviour yang
 *  yang dimiliki oleh turunan kelas Hewan
 *  \author Atika Azzahra Akbar
 *  \date Maret 2016
 */

class Hewan : public Makhluk {
	public :
		/** \brief Procedure virtual tidak pure untuk menggerakan objek bertipe turunan kelas Hewan
     		*   \details Menggerakan objek bertipe turunan kelas Hewan berdasarkan dua masukan bertipe integer
     		*   posisi objek akan berubah sebesar masukan tersebut
     		*   \return void
     		*/
		virtual void Move(int, int);
		
		/** \brief Fungsi pure virtual untuk validasi apakah sebuah objek adalah Vegetarian
     		*   \details Fungsi pure virtual isVegetarian dideklarasikan pada setiap turunan kelas Hewan
     		*   \return int
     		*/
		virtual int isVegetarian() = 0;
		
		/** \brief Procedure virtual pure untuk objek mendapatkan makanannya
     		*   \details Fungsi pure virtual GetToFood dideklarasikan pada setiap turunan kelas Hewan untuk
     		*   mendapatkan makanannya yang berbeda-beda
     		*   \return void
     		*/
        	virtual void GetToFood() = 0;
		
		/** \brief Fungsi getter untuk mendapatkan level kelaparan sebuah objek
     		*   \details Mengembalikan level kelaparan sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
     		*   saat ctor sebuah objek
     		*   \return integer
     		*/
		int getHungerLvl() { return hungerLvl; }
		
		/** \brief Fungsi getter untuk mendapatkan nilai power sebuah objek
     		*   \details Mengembalikan nilai power sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
     		*   saat ctor sebuah objek
     		*   \return integer
     		*/
		int getPower() { return power; }
		
		/** \brief Fungsi getter untuk mendapatkan deltaT sebuah objek
     		*   \details Mengembalikan deltaT sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
     		*   saat ctor sebuah objek
     		*   \return integer
     		*/
		int getDeltaT() { return deltaT;  }
	
		/** \brief Procedure setter untuk level kelaparan
     		*   \details Procedure untuk menambahkan atau mengurangkan level kelaparan sebuah objek
     		*   \return void
     		*/
        	void setHungerLvl(int x) { hungerLvl+=x; }
        	
        	/** \brief Procedure mutex untuk mengunci objek
     		*   \details Memberhentikan objek turunan kelas Hewan 
     		*   \return void
     		*/
        	//static void lockHewan() { hewanLock.lock(); }
        	
        	/** \brief Procedure mutex untuk melanjutkan aktivitas objek
     		*   \details Melanjutkan aktivitas objek turunan kelas Hewan 
     		*   \return void
     		*/
        	//static void unlockHewan() { hewanLock.unlock(); }
    		
    		/** \brief Procedure berjalan random sebuah objek
     		*   \details Behaviour semua objek turunan kelas hewan. Objek akan berjalan secara random di World
     		*   \return void
     		*/
		void Wandering();
		
		/** \brief Procedure tidur sebuah objek
     		*   \details Behaviour semua objek turunan kelas hewan. Objek akan tertidur selama deltaT di World
     		*   \return void
     		*/
		void Sleep();
		
		/** \brief Fungsi untuk objek menemukan makanannya
     		*   \details Mendapatkan makanan sebuah objek. Jika objek merupakan vegetarian akan dikembalikan
     		*   objek bertipe tumbuhan dan jika bukan akan dikembalikan makhluk dengan power dibawah power objek
     		*   tersebut
     		*   \return pointer to Makhluk
     		*/
    		Makhluk* FindFood();
    		
    		/** \brief Fungsi untuk objek mendapatkan sebuah Makhluk
     		*   \details Mendapatkan makhluk yang dicari berdasarkan ID pada listMakhluk
     		*   \return pointer to Makhluk
     		*/
    		Makhluk* FindMakhluk(char _ID);
    		
    		/** \brief Fungsi validasi objek untuk Rebounce
     		*   \details Mendapatkan validasi apakah nilai dx dan dy akan mengakibatkan posisi
     		*   objek lebihd dari batas World
     		*   \return TRUE bila dx atau dy akan membuat posisi objek lebih dari batas
     		*/
    		int shouldRebounced(int dx, int dy);
    		
    		/** \brief Fungsi validasi apakah sebuah Makhluk ada di listMakhluk
     		*   \details Mendapatkan validasi apakah sebuah Makhluk ada di listMakhluk berdasarkan masukan
     		*   ID makhluk
     		*   \return TRUE bila ditemukan makhluk dengan ID yang diinput
     		*/
    		bool isMakhlukinList(char _ID);
    		
    		/** \brief Procedure agar objek berpindah ke suatu point
     		*   \details Objek akan bergerak ke suatu point yang telah diinput melalui jalan paling dekat
     		*   \return void
     		*/
    		void getToPoint(Point P);
        
	protected :
		/** \brief Constructor dari objek Hewan
     		*   \details Constructor Hewan yang akan membentuk objek bertipe Hewan
     		*   yang dapat dicasting dengan objek bertipe turunan kelas Hewan
	 	*   \return Objek bertipe Hewan
     		*/
		Hewan(char, int); 

	protected :
		int hungerLvl, power, deltaT; /**< status level kelaparan, power, dan deltaT sebuah objek*/
		//static mutex hewanLock; /**< static mutex*/
};

#endif
