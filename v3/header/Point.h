// Point.h
#ifndef POINT_H
#define POINT_H

#include <cmath>

/** \class		Point
 *  \brief		Representasi titik dalam koordinat kartesian
 *  \details	Kelas Point berisi dua buah bilangan bulat untuk merepresentasikan suatu koordinat kartesian
 *	\author		Robert Sebastian Herlim
 *	\date		Maret 2016
 */

class Point {
	public :
	/** \brief		Default Constructor
	 *  \details	Menciptakan sebuah point dengan koordinat default.
	 */
		Point();

	/** \brief		Constructor
	 *  \details	Menciptakan sebuah point dengan koordinat yang di-passing melalui parameter.
	 *  \param		_x int Nilai absis point yang akan diciptakan
	 *  \param		_y int Nilai ordinat point yang akan diciptakan
	 */
		Point(int, int);

	/** \brief		Copy Constructor
	 *  \details	Menciptakan sebuah point dengan menyalin sebuah point yang sudah tercipta
	 *  \param		P const Point& Point yang akan disalin
	 */
		Point(const Point&);


	/** \brief		Get nilai absis
	 *  \details	Mengambil nilai absis dari point
	 *  \return		nilai absis dari point
	 */
		int getX() { return x; }

	/** \brief		Get nilai ordinat
	 *  \details	Mengambil nilai ordinat dari point
	 *  \return		nilai ordinat dari point
	 */
		int getY() { return y; }

	/** \brief		Setter untuk nilai absis
	 *  \details	Melakukan assignment nilai absis dengan sebuah nilai baru
	 *  \param		_x int Nilai absis baru yang akan di-assign
	 *  \return		void
	 */
		void setX(int _x) { x = _x; }

	/** \brief		Setter untuk nilai ordinat
	 *  \details	Melakukan assignment nilai ordinat dengan sebuah nilai baru
	 *  \param		_y int Nilai ordinat baru yang akan di-assign
	 *  \return		void
	 */
		void setY(int _y) { y = _y; }

	/** \brief		Melakukan translasi point
	 *  \details	Menambahkan nilai absis dan ordinat sebesar dx dan dy
	 *  \param		dx int Perubahan nilai absis
	 *  \param		dy int Perubahan nilai ordinat
	 *  \return		void
	 */
		void increment(int, int);

	/** \brief		Menghitung jarak euclidean dari 2 buah point
	*  \details		Menghitung jarak euclidean dari 2 buah point yang di-passing melalui parameter
	*  \param		P1 Point Titik pertama
	*  \param		P2 Point Titik kedua
	*  \return		Bilangan bulat yang merupakan jarak euclidean antara titik pertama dan titik kedua
	*/
		static int getDistance(Point&, Point&);

	private :
		int x; /**< absis*/
		int y; /**< ordinat*/
};

#endif
