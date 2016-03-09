// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

/** \class Matrix
 *  \brief Representasi array dua dimensi
 *  \details Kelas Matriks berisi sejumlah elemen karakter yang akan digunakan untuk menampilkan state dunia pada layar.
 *	\author Robert Sebastian Herlim
 *	\date Maret 2016
 */
 
class Matrix {
	public :

	/** \brief Default Constructor
	 *  \details Menciptakan sebuah matriks dengan ukuran default.
	 *			 Matriks yang tercipta akan terisi karakter '#' di bagian tepi matriks sebagai border, 
	 *			 dan '.' pada bagian dalamnya.
	 */
		Matrix();
		
	/** \brief Constructor
	 *  \details Menciptakan sebuah matriks dengan ukuran yang di-pass melalui parameter.
	 *			 Matriks yang tercipta akan terisi karakter '#' di bagian tepi matriks sebagai border, 
	 *			 dan '.' pada bagian dalamnya.
	 *  \param _NBrs int jumlah baris
	 *	\param _NKol int jumlah kolom			
	 */
		Matrix(int, int);
		
	/** \brief Copy Constructor
	 *  \details Menciptakan sebuah matriks yang merupakan salinan dari matriks lain.
	 *			 Matriks yang tercipta akan terisi karakter '#' di bagian tepi matriks sebagai border, 
	 *			 dan '.' pada bagian dalamnya.
	 *  \param Mat const Matrix& Matriks yang akan disalin		
	 */
		Matrix(const Matrix&);
		
	/** \brief Destructor
	 *  \details Memusnahkan sebuah matriks
	 */
		~Matrix();
		
	/** \brief Get jumlah baris
	 *  \details Mengambil nilai NBrs, yaitu jumlah baris pada matriks
	 *	\return nilai konstanta NBrs
	 */
		int getNBrs() const { return NBrs; }
		
	/** \brief Get jumlah kolom
	 *  \details Mengambil nilai NKol, yaitu jumlah kolom pada matriks	
	 *	\return nilai konstanta NKol
	 */
		int getNKol() const { return NKol; }
		
	/** \brief Get nilai sebuah elemen matriks
	 *  \details Mengambil nilai karakter yang tersimpan pada elemen matriks di baris ke-i dan kolom ke-j
	 * 	\param i int Indeks baris elemen matriks
	 *  \param j int Indeks kolom elemen matriks	
	 *	\return Karakter M[i][j]
	 */
		char getInfo(int i, int j) const;
		
	/** \brief Setter nilai sebuah elemen matriks
	 *  \details Melakukan assignment pada elemen matriks yang terletak di baris ke-i dan kolom ke-j
	 *  \param c char Nilai baru yang akan di-assign	
	 * 	\param i int Indeks baris elemen matriks
	 *  \param j int Indeks kolom elemen matriks	
	 *	\return void
	 */
		void setInfo(char c, int i, int j);
		
	/** \brief Prosedur untuk print sebuah matriks
	 *  \details Mencetak matriks ke layar
	 *	\return void
	 */
		void PrintMatrix() const;
		
	private :
		char** M; /**< container matriks*/
		const int NBrs; /**< jumlah baris*/
		const int NKol; /**< jumlah kolom*/
};

#endif
