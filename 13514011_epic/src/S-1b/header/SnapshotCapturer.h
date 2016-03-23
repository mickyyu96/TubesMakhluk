#ifndef SNAPSHOTCAPTURER_H
#define SNAPSHOTCAPTURER_H

#include "IOManager.h"
#include <fstream>
#include <string>
using namespace std;

/** \class		SnapshotCapturer
*	\brief		Kelas untuk mengambil snapshot state dunia
*	\details	Kelas SnapshotCapturer bertanggung jawab dalam pengambilan snapshot state dunia
*				dan menyimpan hasil pengambilan snapshot ke sebuah file
*	\author		Robert Sebastian Herlim
*	\date		Maret 2016
*/

class SnapshotCapturer : public IOManager
{
	public:
		/** \brief		Get Singleton Instance dari kelas SnapshotCapturer
		*	\details	Mengembalikan pointer dari objek singleton pada kelas SnapshotCapturer
		*	\return		pointer yang menunjuk ke singleton instance pada kelas SnapshotCapturer
		*/
		static SnapshotCapturer* getCapturerInstance() { return capturerInstance; }

		/** \brief		Menyimpan buffer cout
		*	\details	Menyimpan buffer cout sekarang ke dalam coutbuf yang tersimpan dalam instance SnapshotCapturer
		*	\return		void
		*/
		void saveOldBuf() { coutbuf = cout.rdbuf(); }

		/** \brief		Reset buffer cout ke standard output
		*	\details	Mengembalikan buffer cout ke standard output
		*	\return		void
		*/
		void resetCoutBuf() { cout.rdbuf(coutbuf); }

		/** \brief		Mengambil sebuah snapshot state dunia
		*	\details	Mengambil snapshot state dunia pada saat tertentu
		*				dan menuliskan hasil snapshot ke directory file yang tersimpan dalam instance SnapshotCapturer
		*	\return		void
		*/
		void captureSnapshot();

	private:
		/** \brief		Constructor
		*	\details	Menciptakan sebuah instance dari kelas SnapshotCapturer dengan melakukan setting pada
		*				data member directory
		*	\param		_filename const string& Nama file tempat penyimpanan hasil snapshot
		*/
		SnapshotCapturer(const string&);

	private:
		streambuf *coutbuf; /**< menyimpan buffer cout terakhir */
		static SnapshotCapturer* capturerInstance; /**< pointer yang menunjuk ke instance dari kelas singleton */

		string directory; /**< menyimpan directory snapshot akan disimpan */
};

#endif
