// Hewan.h
#ifndef HEWAN_H
#define HEWAN_H

#include "Makhluk.h"
#include "Point.h"
using namespace std;

/** \class 	Hewan
 *  \brief 	Abstract Base Class yang merupakan Kelas Turunan dari Makhluk
 *  \details 	Kelas Hewan merupakan kelas yang berfungsi untuk mengimplementasikan behaviour yang
   		yang dimiliki oleh turunan kelas Hewan
 *  	\author 	Atika Azzahra Akbar
 *  	\date		Maret 2016
 */
 
class Hewan : public Makhluk {
	public :
		/** \brief 	Procedure virtual tidak pure untuk menggerakan objek bertipe turunan kelas Hewan
     		*   \details 	Menggerakan objek bertipe turunan kelas Hewan berdasarkan dua masukan bertipe integer
     		*   		posisi objek akan berubah sebesar masukan tersebut
     		*   \param	integer delta x
     		*   \param 	integer delta y
     		*   \return 	void
     		*/
		virtual void Move(int, int);
		
		/** \brie	Fungsi pure virtual untuk validasi apakah sebuah objek adalah Vegetarian
     		*   \details 	Fungsi pure virtual isVegetarian dideklarasikan pada setiap turunan kelas Hewan
     		*   \return 	integer
     		*/
		virtual int isVegetarian() = 0;

		/** \brief 	Fungsi getter untuk mendapatkan level kelaparan sebuah objek
     		*   \details 	Mengembalikan level kelaparan sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
     		*   		saat ctor sebuah objek
     		*   \return 	integer
     		*/
		int getHungerLvl() { return hungerLvl; }
		
		/** \brief 	Fungsi getter untuk mendapatkan nilai power sebuah objek
     		*   \details 	Mengembalikan nilai power sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
     		*   		saat ctor sebuah objek
     		*   \return 	integer
     		*/
		int getPower() { return power; }
		
		/** \brief 	Fungsi getter untuk mendapatkan deltaT sebuah objek
     		*   \details 	Mengembalikan deltaT sebuah objek bertipe turunan kelas Hewan yang diinisialisasi
     		*   		saat ctor sebuah objek
     		*   \return 	integer
     		*/
		int getDeltaT() { return deltaT;  }
	
		/** \brief 	Procedure setter untuk level kelaparan
     		*   \details 	Procedure untuk menambahkan atau mengurangkan level kelaparan sebuah objek
     		*   \param 	integer delta hungerLvl
     		*   \return 	void
     		*/
        	void setHungerLvl(int x) { hungerLvl+=x; }
    		
    		/** \brief 	Procedure berjalan random sebuah objek
     		*   \details 	Behaviour semua objek turunan kelas hewan. Objek akan berjalan secara random di World
     		*   \return 	void
     		*/
		void Sleep();
    
    		
    		/** \brief 	Fungsi validasi objek untuk Rebounce
     		*   \details 	Mendapatkan validasi apakah nilai dx dan dy akan mengakibatkan posisi
     		*   		objek lebih dari batas World
     		*   \param	integer delta x
     		*   \param	integer delta y
     		*   \return 	TRUE bila dx atau dy akan membuat posisi objek lebih dari batas
     		*/
    		int shouldRebounced(int dx, int dy);
    
        
	protected :
		/** \brief 	Constructor
     		*   \details 	Constructor Hewan yang akan membentuk objek bertipe Hewan
     		*   		yang dapat dicasting dengan objek bertipe turunan kelas Hewan
     		*   \param	character ID Makhluk
     		*   \param	integer maxAge Makhluk
     		*/
		Hewan(char, int); 

	protected :
		int hungerLvl, power, deltaT; /**< status level kelaparan, power, dan deltaT sebuah objek*/
};

#endif
