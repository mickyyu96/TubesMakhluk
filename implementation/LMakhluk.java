// LMakhluk.java

/** Container yang menampung obyek-obyek Makhluk yang terdapat dalam dunia
 *	@author     Robert Sebastian Herlim
 *	@date       April 2016
 *	@version	1.0
 */

import java.util.Vector;

public class LMakhluk {

	private Vector<Makhluk> makhlukVector;

	/** Menciptakan sebuah list of makhluk dengan container Java Vector
	 */
	public LMakhluk() {
		makhlukVector = new Vector<Makhluk>();
	}

	/** Menambah element pada bagian belakang list of makhluk
	 *  @param      _makhluk Makhluk yang akan ditambah ke list
	 *	@return     void
	 */
	public void Add(Makhluk _makhluk) {
		makhlukVector.add(_makhluk);
	}

	/** Predikat yang menyatakan status kekosongan list of makhluk
     *	@return     Bilangan bulat 0 jika list kosong,
     *				1 jika list tidak kosong
     */
	public int isEmpty() { return (makhlukVector.capacity() == 0)?1:0; }

	/** Mengembalikan jumlah elemen yang ada dalam list of makhluk
	*	@return     Bilangan bulat yang menyatakan jumlah elemen yang ada di list
	*/
	public int getSize () { return makhlukVector.capacity(); }

	/** Mengakses isi list pada elemen ke-idx, elemen pertama dihitung sebagai elemen ke-0
	*	@param		idx Indeks elemen yang mau diakses
	*	@return     Makhluk yang berada pada list elemen ke-idx
	*/
	public Makhluk getInfo(int idx) { return makhlukVector.get(idx); }

	/** Predikat yang menyatakan seluruh makhluk pada list sudah mati
     *	@return     Bilangan bulat 0 jika semua makhluk sudah mati,
     *				1 jika masih ada makhluk yang hidup
     */
	public int IsAllMakhlukDead() {
		int found = 0;
		for(int i=0; i<getSize() && found==0; i++) {
			if(getInfo(i).isAlive()==1) found = 1;
		}
		return found;
	}

}
