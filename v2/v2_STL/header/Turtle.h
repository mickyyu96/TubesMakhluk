//  Turtle.hpp
#ifndef Turtle_h
#define Turtle_h
#include "Hewan.h"

/** \class 	Turtle
 *  \brief 	Kelas Turunan dari Makhluk berupa Turtle
 *  \details 	Kelas Rabbit merupakan kelas yang berfungsi untuk merepresentasikan objek Turtle
 *	\author 	Atika Azzahra Akbar
 *	\date 		Maret 2016
 */

class Turtle : public Hewan {
    public :
    /** \brief 		Constructor
     *  \details 	Constructor Turtle yang akan membentuk objek bertipe Turtle
     *   		dengan masukan variable reference Point sebagai posisi awal objek
     *  \param		konstanta reference Point untuk posisi awal objek
     */
    Turtle(const Point&);

    /** \brief 		Validasi apakah Turtle merupakan Vegetarian
     *  \details 	Validasi akan selalu mengembalikan integer bernilai 1 sebagai
     *  		validasi bahwa Turtle merupakan binatang vegetarian
     *	\return 	TRUE
     */
    int isVegetarian() { return 1; }

    /** \brief 		Getter isChallange milik Turtle
     *  \details 	Fungsi getter yang akan mengambilkan nilai isChallange dari Turtle.
     *  		Bernilai 0 jika tidak ada yang mengajak untuk race dan bernilai 1
     *  		jika ada Rabbit yang mengajak
     *	\return 	TRUE bila ada Rabbit yang mengajak dan FALSE bila tidak ada
     */
    int getisChallange() { return isChallange; }

    void setIsChallange(int a) { isChallange = a; }

    /** \brief Getter DeltaT Turtle
     *  \details Fungsi getter yang akan mengambilkan nilai deltaT dari Turtle
     *  yang merupakan member dari kelas hewan yang diinisialisasi saat ctor
     *	\return Integer DeltaT Turtle
     */
    int getDeltaT() { return Hewan::getDeltaT(); }

    private :
    static const char TURTLE_ID = 'T'; /**< ID Turtle*/
    static const int TURTLE_MAXAGE = 15; /**< Umur maksimal Turtle*/
    static const int TURTLE_BASEPOWER = 2; /**< Power Turtle*/
	static const int TURTLE_DELTAT = 600; /**< DeltaT Turtle*/
    int isChallange; /**< Variable ajakan racing oleh Rabbit*/
};

#endif /* Turtle_hpp */
