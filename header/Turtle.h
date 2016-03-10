//  Turtle.hpp
#ifndef Turtle_h
#define Turtle_h
#include "Hewan.h"

/** \class Turtle
 *  \brief Kelas Turunan dari Makhluk berupa Rabbit
 *  \details Kelas Rabbit merupakan kelas yang berfungsi untuk mengatur behaviour dan kehidupan dari objek Rabbit
 *	\author Atika Azzahra Akbar
 *	\date Maret 2016
 */

class Turtle : public Hewan {
    public :
    /** \brief Constructor dari objek bertipe Turle
     *  \details Constructor Turtle yang akan membentuk objek bertipe Turtle
     *   dengan masukan variable reference Point sebagai posisi awal objek
     *	\return Objek bertipe Turtle
     */
    Turtle(const Point&);
    
    /** \brief Validasi apakah Turtle merupakan Vegetarian
     *  \details Validasi akan selalu mengembalikan integer bernilai 1 sebagai
     *   validasi bahwa Turtle merupakan binatang vegetarian 
     *	\return integer bernilai 1
     */
    int isVegetarian() { return 1; }
    
    /** \brief Getter isChallange milik Turtle
     *  \details Fungsi getter yang akan mengambilkan nilai isChallange dari Turtle.
     *  Bernilai 0 jika tidak ada yang mengajak untuk race dan bernilai 1 jika ada Rabbit
     *  yang mengajak
     *	\return Integer
     */
    int getisChallange() { return isChallange; }
    
    /** \brief Getter DeltaT Turtle
     *  \details Fungsi getter yang akan mengambilkan nilai deltaT dari Turtle
     *  yang merupakan member dari kelas hewan yang diinisialisasi saat ctor
     *	\return Integer DeltaT Turtle
     */
    int getDeltaT() { return Hewan::getDeltaT(); }
    
    /** \brief Procedure aksi untuk Turtle melakukan Race dengan objek Rabbit
     *  \details Procedure aksi Race ini akan melakukan validasi apakah ada objek Rabbit yang
     *  mengajak race. Jika ada maka Turtle pergi ke point start, dan melakukan race bersama Rabbit ke finish point
     *	\return void
     */
    void Race();
    
    /** \brief Procedure aksi untuk Rabbit mendapatkan makanan
     *  \details Procedure aksi GetToFood membuat Rabbit pergi ke point dimana makanannya
     *  berasa dan memakannya
     *	\return void
     */
    void GetToFood();
    
    /** \brief Validasi apakah ada objek Turtle yang sedang melakukan Race bertipe static function
     *  \details Validasi akan melakukan pencarian Makhluk Turtle pada listMakhluk yang
     *  nilai isChallange adalah 1
     *	\return integer
     */
    static int isAnyTurtleRacing();
    
    /** \brief Procedure aksi utama yang mengatur hidup Turtle sampai mati
     *  \details Procedure aksi utama akan memilih aktivitas kehidupan yang akan dilakukan
     *  oleh Turtle selama hidupnya
     *	\return void
     */
    void Live();
    
    private :
    static const char TURTLE_ID = 'T'; /**< ID Turtle*/
    static const int TURTLE_MAXAGE = 15; /**< Umur maksimal Turtle*/
    static const int TURTLE_BASEPOWER = 2; /**< Power Turtle*/
    static const int TURTLE_DELTAT = 600 /**< DeltaT Turtle*/
    int isChallange; /**< Variable ajakan racing oleh Rabbit*/
};

#endif /* Turtle_hpp */
