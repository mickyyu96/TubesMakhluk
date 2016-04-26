package world;

import java.util.Vector;

/** Container yang menampung obyek-obyek Makhluk yang terdapat dalam dunia.
 *  @author  Robert Sebastian Herlim / 13514061
 *  @version 1.0
 */
public class ListMakhluk {
    /** Atribut vector makhluk.
     */
    private Vector<Makhluk> makhlukVector;
    /** Menciptakan sebuah list of makhluk dengan container Java Vector.
     */
    public ListMakhluk() {
        makhlukVector = new Vector<Makhluk>();
    }
    /** Menambah element pada bagian belakang list of makhluk.
     *  @param   makhluk Makhluk yang akan ditambah ke list
     */
    public final void add(final Makhluk makhluk) {
        makhlukVector.add(makhluk);
    }
    /** Predikat yang menyatakan status kekosongan list of makhluk.
     *  @return Bilangan bulat 0 jika list kosong,
     *          1 jika list tidak kosong
     */
    public final int isEmpty() {
        if (makhlukVector.size() == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    /** Mengembalikan jumlah elemen yang ada dalam list of makhluk.
     *   @return Bilangan bulat yang menyatakan jumlah elemen yang ada di list
     */
    public final int getSize() {
        return makhlukVector.size();
    }
   /** Mengakses isi list pada elemen ke-idx, elemen pertama dihitung
    *  sebagai elemen ke-0.
    *  @param  idx Indeks elemen yang mau diakses
    *  @return Makhluk yang berada pada list elemen ke-idx
    */
    public final Makhluk getInfo(final int idx) {
        return makhlukVector.get(idx);
    }
    /** Predikat yang menyatakan seluruh makhluk pada list sudah mati.
     *  @return true apabila tidak ada makhluk yang masih hidup
     */
    public final boolean isAllMakhlukDead() {
        boolean found = false;
        for (int i = 0; i < getSize() && !found; i++) {
            if (getInfo(i).isAlive() == 1) {
                found = true;
            }
        }
        return !found;
    }
    /** Menghitung jumlah makhluk yang ber-ID karakter yang di-passing
     *  melalui parameter.
     *  @param  c Karakter ID makhluk yang ingin dihitung
     *  @return Bilangan bulat yang menyatakan jumlah makhluk ber-ID c
     *          yang masih hidup
     */
    public final int countMakhluk(final char c) {
        int res = 0;
        for (int i = 0; i < getSize(); i++) {
            if (getInfo(i).isAlive() == 1 && getInfo(i).getID() == c) {
                res++;
            }
        }
        return res;
    }
}
