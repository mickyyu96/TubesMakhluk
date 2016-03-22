#ifndef SNAKE_H
#define SNAKE_H

#include "Hewan.h"

/** \class 	    Turtle
 *  \brief 	    Kelas Turunan dari Makhluk berupa Snake
 *  \details 	Kelas Snake merupakan kelas yang berfungsi untuk merepresentasikan objek Snake
 *	\author 	Elvina R. K. Situmorang
 *	\date 		Maret 2016
 */

class Snake : public Hewan
{
	public :
		/** \brief 		Constructor
         *  \details 	Constructor Snake yang akan membentuk objek bertipe Snake
         *   		    dengan masukan variable reference Point sebagai posisi awal objek
         *  \param		konstanta reference Point untuk posisi awal objek
         */
		Snake(const Point&);

		/** \brief 		Getter DeltaT Snake
         *  \details 	Fungsi getter yang akan mengambilkan nilai deltaT dari Snake
         *  		    yang merupakan member dari kelas hewan yang diinisialisasi saat ctor
         *	\return 	Integer DeltaT Snake
         */
		int getDeltaT() { return Hewan::getDeltaT(); }

		/** \brief 		Validasi apakah Snake merupakan Vegetarian
         *  \details 	Validasi akan selalu mengembalikan integer bernilai 0 sebagai
         *  		    validasi bahwa Snake merupakan binatang karnivor
         *	\return 	Bilangan bulat 0
         */
		int isVegetarian() { return 0; }

		/** \brief 		Procedure aksi untuk Snake mendapatkan makanan
         *  \details 	Procedure aksi GetToFood membuat Snake pergi ke point dimana makanannya
         *  		    berasa dan memakannya
         *	\return 	void
         */
		void GetToFood();

		/** \brief 		Procedure aksi untuk Snake berkelana
         *  \details 	Procedure aksi ZigZag membuat Snake bergerak secara zigzag
         *	\return 	void
         */
		void ZigZag();

        /** \brief 		Procedure aksi utama yang mengatur hidup Snake sampai mati
         *  \details 	Procedure aksi utama akan memilih aktivitas kehidupan yang akan dilakukan
         *  		    oleh Snake selama hidupnya
         *	\return 	void
         */
        void Live();

	private :
		static const char SNAKE_ID = 'U';       /**< ID Snake*/
		static const int SNAKE_MAXAGE = 150;    /**< Umur Maksimal Snake*/
		static const int SNAKE_BASEPOWER = 5;   /**< Power Snake*/
		static const int SNAKE_DELTAT = 500;    /**< DeltaT Snake*/
};

#endif

