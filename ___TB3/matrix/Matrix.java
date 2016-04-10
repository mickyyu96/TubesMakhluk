package matrix;

/** Kelas Matrix yang menangani hal-hal yang berhubungan
 *  dengan matriks. Kelas ini digunakan dalam pembuatan World
 *  dengan hubungan asosiatif.
 *  @author     Elvina R. K. Situmorang / 13514045
 *  @version    1.0
 */
public class Matrix {
    /** Atribut member matriks.
     */
    private char[][] m;
    /** Atribut jumlah baris matriks.
     */
    private final int nBrs;
    /** Atribut jumlah kolom matriks.
     */
    private final int nKol;

   /** Konstruktor untuk membentuk matriks dengan
     * banyak baris = brs dan banyak kolom = kol.
     * @param brs Jumlah Baris matriks
     * @param kol Jumlah Kolom matriks
     */
     public Matrix(final int brs, final int kol) {
        nBrs = brs;
        nKol = kol;
        m = new char[nBrs][];
        for (int i = 0; i < nBrs; i++) {
            m[i] = new char[nKol];
        }
        for (int i = 0; i < nBrs; i++) {
            for (int j = 0; j < nKol; j++) {
                m[i][j] = '.';
            }
        }
        for (int i = 0; i < nBrs; i++) {
            m[i][nKol - 1] = '#';
            m[i][0] = m[i][nKol - 1];
        }
        for (int i = 0; i < nKol; i++) {
            m[nBrs - 1][i] = '#';
            m[0][i] = m[nBrs - 1][i];
        }
    }
    /** Mengembalikan nilai nBrs (jumlah baris) dalam matriks.
     *  @return int  Jumlah Baris Matriks
     */
    public final int getnBrs() {
        return nBrs;
    }
    /** Mengembalikan nilai nKol (jumlah kolom) dalam matriks.
     *  @return int Jumlah Kolom Matriks
     */
    public final int getnKol() {
       return nKol;
    }
    /** Mengembalikan nilai informasi yang diberikan.
     *  @param i untuk menentukan baris ke-i
     *  @param j untuk menentukan kolom ke-j
     *  @return char Karakter yang ada pada Matriks baris ke-i dan kolom ke-j
     */
    public final char getInfo(final int i, final int j) {
          return m[i][j];
    }
    /** Melakukan assigment terhadap matriks.
     *  @param c berupa karakter yang mau di-assign
     *  @param i penunjuk baris pada matriks yang akan di-assign
     *  @param j penunjuk kolom pada matriks yang akan di-assign
     */
    public final void setInfo(final char c, final int i, final int j) {
        m[i][j] = c;
    }
    /** Mengkonversi kumpulan karakter yang ada pada matriks
     *  (menjadi sebuah string).
     *  menjadi HTLM String
     *  @return String berupa HTML String
     */
     public final String toHTMLString() {
        String res = "<html>";
        for (int i = 0; i < nBrs; i++) {
            for (int j = 0; j < nKol; j++) {
                res = res.concat(Character.toString(m[i][j]));
        }
            res = res.concat("<br>");
        }
        res = res.concat("</html>");
        return res;
     }
     /** Mengkonversi kumpulan karakter yang ada pada matriks menjadi string.
      *  @return String hasil konkatenasi
      */
     public final String toString() {
        String res = "";
        for (int i = 0; i <  nBrs; i++) {
            for (int j = 0; j < nKol; j++) {
                res = res.concat(Character.toString(m[i][j]));
            }
            res = res.concat("\n");
        }
        return res;
    }
}
