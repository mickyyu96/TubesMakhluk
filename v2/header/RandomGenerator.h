#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <stdlib.h>
#include <time.h>
#include <mutex>
#include <unistd.h>
#include "Point.h"

using namespace std;

/** \class      RandomGenerator
 *  \brief      Mengembalikan random number
 *  \details    Kelas RandomGenerator mengembalikan sebuah random number
                berdasarkan batasan yang diberikan
 *	\author     Micky Yudi Utama
 *	\date       Maret 2016
 */

class RandomGenerator
{
    private:
        /** \brief      Constructor
         *  \details    Menciptakan sebuah RandomGenerator
		 */
        RandomGenerator();

    public:
        /** \brief      Get singleton instance dari kelas RandomGenerator
		 *  \details    Mengembalikan pointer dari objek kelas singleton pada kelas RandomGenerator
		 *	\return     Pointer yang menunjuk ke singleton instance pada kelas RandomGenerator
		 */
        static RandomGenerator* getInstance() { return _instance; }

        /** \brief      Fungsi untuk mengacak bilangan bulat berdasarkan batasan
		 *  \details    Melakukan pengacakan bilangan bulat dengan batasan (0...a-1)
		 *  \param      a int Batas atas hasil acak
		 *	\return     Bilangan bulat acak dari (0...a-1)
		 */
        int getNextInt(int);

        /** \brief      Fungsi untuk mengacak bilangan bulat berdasarkan batasan
		 *  \details    Melakukan pengacakan bilangan bulat dengan batasan (a...b)
		 *  \param      a int Batas bawah hasil acak
		 *  \param      b int Batas atas hasil acak
		 *	\return     Bilangan bulat acak dari (a...b)
		 */
        int getNextIntBetween(int, int);

        /** \brief      Fungsi untuk mengacak point berdasarkan batasan
		 *  \details    Melakukan pengacakan point dengan batasan (1...Nbrs-2), (1...NKol-2)
		 *  \param      NBrs int Jumlah baris
		 *  \param      NKol int Jumlah kolom
		 *	\return     Point acak dari (1...Nbrs-2), (1...NKol-2)
		 */
        Point getNextPoint(int, int);

        /** \brief      Fungsi untuk mengacak point berdasarkan batasan
		 *  \details    Melakukan pengacakan point dengan batasan (NBrs-(NBrs/5)-2...Nbrs-2), (1...NKol-2)
		 *  \param      NBrs int Jumlah baris
		 *  \param      NKol int Jumlah kolom
		 *	\return     Point acak dari (NBrs-(NBrs/5)-2...Nbrs-2), (1...NKol-2)
		 */
        Point getNextPointPB(int , int);

        /** \brief		Mutex
		*	\details	Mengunci akses untuk menggunakan random
		*	\return		void
		*/
        void lockRandom();

        /** \brief		Mutex
		*	\details	Membuka akses untuk menggunakan random
		*	\return		void
		*/
        void unlockRandom();

    private:
        static RandomGenerator* _instance;  /**< singleton instance*/
        mutex randomLock;
};

# endif // RandomGenerator_H
