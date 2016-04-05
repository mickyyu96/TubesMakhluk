package tubesmakhluk;

// Wolf.java

/** Kelas turunan dari Hewan yang merepresentasikan seekor serigala
 *	@author     Robert Sebastian Herlim
 *	@date       April 2016
 *	@version	1.0
 */

public class Wolf extends Hewan {

	private static final char WOLF_ID = 'W';
	private static final int WOLF_MAXAGE = 180;
	private static final int WOLF_BASEPOWER = 6;

	/** Menciptakan seekor serigala di koordinat P
	 * @param P koordinat penciptaan serigala
	*/
	public Wolf(final Point P) {
		super(WOLF_ID, WOLF_MAXAGE);
		age = 0;
		status = 1;
		power = WOLF_BASEPOWER;
		pos = P;
	}

}