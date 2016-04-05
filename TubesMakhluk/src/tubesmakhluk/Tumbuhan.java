package tubesmakhluk;

// Tumbuhan.java

/** Kelas turunan dari Makhluk yang merepresentasikan sebuah tumbuhan
 *	@author     Robert Sebastian Herlim
 *	@date       April 2016
 *	@version	1.0
 */

public class Tumbuhan extends Makhluk {

	private static final char TUMBUHAN_ID = 'G';
	private static final int TUMBUHAN_MAXAGE = 300;

	/** Menciptakan sebuah tumbuhan di koordinat P
	 * @param P koordinat penciptaan tumbuhan
	*/
	public Tumbuhan(final Point P) {
		super(TUMBUHAN_ID, TUMBUHAN_MAXAGE);
		age = 0;
		status = 1;
		pos = P;
	}

}