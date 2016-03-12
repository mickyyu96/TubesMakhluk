//Rabbit.h
#ifndef Rabbit_h
#define Rabbit_h
#include <iostream>
#include "Hewan.h"

/** \class Rabbit
 *  \brief Kelas Turunan dari Makhluk berupa Rabbit
 *  \details Kelas Rabbit merupakan kelas yang berfungsi untuk mengatur behaviour dan kehidupan dari objek Rabbit
 *	\author Atika Azzahra Akbar
 *	\date Maret 2016
 */

class Rabbit : public Hewan {
    public :
    /** \brief Constructor dari objek bertipe Rabbit
     *  \details Constructor Rabbit yang akan membentuk objek bertipe Rabbit
     *   dengan masukan variable reference Point sebagai posisi awal objek
     *	\return Objek bertipe Rabbit
     */
    Rabbit(const Point&);

    /** \brief Validasi apakah Rabbit merupakan Vegetarian
     *  \details Validasi akan selalu mengembalikan integer bernilai 1 sebagai
     *   validasi bahwa Rabbit merupakan binatang vegetarian
     *	\return integer bernilai 1
     */
    int isVegetarian() { return 1; }

    /** \brief Getter DeltaT Rabbit
     *  \details Fungsi getter yang akan mengambilkan nilai deltaT dari Rabbit
     *  yang merupakan member dari kelas hewan yang diinisialisasi saat ctor
     *	\return Integer DeltaT Rabbit
     */
    int getDeltaT() { return Hewan::getDeltaT(); }

    /** \brief Procedure aksi untuk Rabbit melakukan Race dengan objek Turtle
     *  \details Procedure aksi Race ini akan memberikan ajakan race untuk objek Turtle,
     *  pergi ke point start, dan melakukan race bersama Turtle ke finish point
     *	\return void
     */
    void Race();

    /** \brief Procedure aksi untuk Rabbit mendapatkan makanan
     *  \details Procedure aksi GetToFood membuat Rabbit pergi ke point dimana makanannya
     *  berasa dan memakannya
     *	\return void
     */
    void GetToFood();

    /** \brief Procedure aksi untuk Rabbit untuk berjalan di World secara random dengan meloncat
     *  \details Procedure aksi ini merupakan procedure implementasi behaviour khusus Rabbit
     *  dimana Rabbit meloncati dua sel sekali berjalan secara random di World
     *	\return void
     */
    void WanderingHop();

    /** \brief Procedure aksi utama yang mengatur hidup Rabbit sampai mati
     *  \details Procedure aksi utama akan memilih aktivitas kehidupan yang akan dilakukan
     *  oleh Rabbit selama hidupnya
     *	\return void
     */
    void Live();

    private :
    static const char RABBIT_ID = 'R'; /**< ID Rabbit*/
    static const int RABBIT_MAXAGE = 20; /**< Umur maksimal Rabbit*/
    static const int RABBIT_BASEPOWER = 3; /**< Power Rabbit*/
    static const int RABBIT_DELTAT = 1000; /**< DeltaT Rabbit*/
};
#endif /* Rabbit_h */
