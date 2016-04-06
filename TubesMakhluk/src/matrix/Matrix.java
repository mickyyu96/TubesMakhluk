//Matrix.java

package matrix;

/** Kelas Matrix yang menangani hal-hal yang berhubungan
 *  dengan matriks. Kelas ini digunakan dalam pembuatan World
 *	dengan hubungan asosiatif.
 *	@author     Elvina R. K. Situmorang / 13514045
 *	@date       April 2016
 *	@version    1.0
 */

public class Matrix {
	private char[][] M;
	private final int NBrs;
	private final int NKol;

    /** Konstruktor untuk membentuk matriks dengan 
	 *	banyak baris = _NBrs dan banyak kolom = _NKol
	 *	@param int Jumlah Baris matriks
	 *	@oaram int Jumlah Kolom matriks
	 */
	public Matrix(int _NBrs, int _NKol) {
		NBrs = _NBrs;
		NKol = _NKol;
		M = new char[NBrs][];
		for (int i = 0; i<NBrs; i++)
			M[i] = new char[NKol];
		for (int i = 0; i<NBrs; i++) {
			for (int j = 0; j<NKol; j++)
				M[i][j] = '.';
		}
		for (int i = 0; i<NBrs; i++)
			M[i][0] = M[i][NKol-1] = '#';
		for (int i=0; i<NKol; i++)
			M[0][i] = M[NBrs-1][i] = '#';
	}
	/** Mengembalikan nilai NBrs (jumlah baris) dalam matriks
	 *	@return 	int  Jumlah Baris Matriks
	 */
	public final int getNBrs() {
		return NBrs;
    }
	/** Mengembalikan nilai NKol (jumlah kolom) dalam matriks
	 *	@return 	int Jumlah Kolom Matriks
	 */
	public final int getNKol() {
		return NKol;
    }
	/** Mengembalikan nilai informasi yang diberikan 
	 *	@param 	int i untuk menentukan baris ke-i
	 *	@param 	int j untuk menentukan kolom ke-j
	 *	@return	char Karakter yang ada pada Matriks baris ke-i dan kolom ke-j
	 */
	public final char getInfo(int i, int j) {
		return M[i][j];
	}
	/** Melakukan assigment terhadap matriks
	 *	@param		char c berupa karakter yang mau di-assign
	 *	@param		int i penunjuk baris pada matriks yang akan di-assign
	 *	@param 		int j penunjuk kolom pada matriks yang akan di-assign
	 *	@return 	void
	 */
	public void setInfo(char c, int i, int j) {
		M[i][j]=c;
	}
	/** Mengkonversi kumpulan karakter yang ada pada matriks (menjadi sebuah string)
	 *	menjadi HTLM String
	 *	@return String berupa HTML String
	 */
	public String toHTMLString() {
		String res = "<html>";
		for(int i=0; i<NBrs; i++) {
			for(int j=0; j<NKol; j++) {
				res = res.concat(Character.toString(M[i][j]));
			}
			res = res.concat("<br>");
		}
		res = res.concat("</html>");
		return res;
	}
	/** Mengkonversi kumpulan karakter yang ada pada matriks menjadi string
	 *	@return String hasil konkatenasi
	 */
	public String toString() {
	    String res = "";
		for(int i=0; i<NBrs; i++) {
			for(int j=0; j<NKol; j++) {
				res = res.concat(Character.toString(M[i][j]));
			}
			res = res.concat("\n");
		}
		return res;
	}
}
