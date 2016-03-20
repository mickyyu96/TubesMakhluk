#ifndef MakhlukLive_h
#define MakhlukLive_h

#include "Point.h"
#include "Makhluk.h"

/** \class      MakhlukLive
 *  \brief      Kelas yang mengatur hidup Makhluk pada LMakhluk
 *  \details    Kelas RandomGenerator yang mengatur semua makhluk di dalam list
 *              untuk bergerak dan makan bila berada lebih dari dua makhluk pada sel yang sama
 *	\author     Atika Azzahra Akbar
 *	\date       Maret 2016
 */
 
class MakhlukLive {
    private:
        /** \brief      Constructor
         *  \details    Menciptakan sebuah MakhlukLive
		 */
        MakhlukLive();
    public:
        /** \brief      Get singleton instance dari kelas MakhlukLive
		 *  \details    Mengembalikan pointer dari objek kelas singleton pada kelas MakhlukLive
		 *	\return     Pointer yang menunjuk ke singleton instance pada kelas MakhlukLive
		 */
        static MakhlukLive* getInstance() { return _instance; };
        
        /** \brief      Procedure untuk mengatur gerak Makhluk
		 *  \details    Menggerakan semua Makhluk pada LMakhluk
		 *	\return     void
		 */
        void MakhlukMove();
        
        /** \brief      Procedure untuk mengatur makan-memakan Makhluk
		 *  \details    Menetapkan siapa yang dimakan ketika terdapat lebih
		 *              dari dua makhluk pada sel yang sama
		 *	\return     void
		 */
        void MakhlukEat();
    private:
        static MakhlukLive* _instance; /**< singleton instance*/
};

#endif /* MakhlukLive_h */
