package world;

// LMakhluk.java

/** Container yang menampung obyek-obyek Makhluk yang terdapat dalam dunia
 *	@author     Robert Sebastian Herlim / 13514061
 *	@date       April 2016
 *	@version	1.0
 */

import java.util.Vector;
import makhluk.*;
import randomgenerator.*;

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
	public int getSize () { return makhlukVector.size(); }

	/** Mengakses isi list pada elemen ke-idx, elemen pertama dihitung sebagai elemen ke-0
	*	@param		idx Indeks elemen yang mau diakses
	*	@return     Makhluk yang berada pada list elemen ke-idx
	*/
	public Makhluk getInfo(int idx) { return makhlukVector.get(idx); }

	/** Predikat yang menyatakan seluruh makhluk pada list sudah mati
     *	@return     true apabila tidak ada makhluk yang masih hidup
     */
	public boolean IsAllMakhlukDead() {
		boolean found = false;
		for(int i=0; i<getSize() && !found; i++) {
			if(getInfo(i).isAlive()==1) found = true;
		}
		return !found;
	}

	/** Unit test untuk LMakhluk
     *	@return     void
     */
	public static void main (String args[]) {
		LMakhluk _LMakhluk = new LMakhluk();
		System.out.println("-----Add Wolf, Sheep, PolarBear ke dalam list-----");
	    _LMakhluk.Add(new Wolf(RandomGenerator.getInstance().getNextPoint(5, 5)));
	    _LMakhluk.Add(new Sheep(RandomGenerator.getInstance().getNextPoint(5, 5)));
	    _LMakhluk.Add(new PolarBear(RandomGenerator.getInstance().getNextPoint(5, 5)));

	    char c;
	    c = _LMakhluk.getInfo(0).getID();
	    System.out.println("Ambil ID first makhluk dalam list : "+c);

	    c= _LMakhluk.getInfo(2).getID();
	    System.out.println("Ambil ID last makhluk dalam list : "+c);

	}

}
