package tubesmakhluk;

// Sheep.java

/** Kelas turunan dari Hewan yang merepresentasikan seekor domba
 *	@author     Robert Sebastian Herlim
 *	@date       April 2016
 *	@version	1.0
 */

public class Sheep extends Hewan {

	private static final char SHEEP_ID = 'S';
	private static final int SHEEP_MAXAGE = 200;
	private static final int SHEEP_BASEPOWER = 4;

	/** Menciptakan seekor domba di koordinat P
	 * @param P koordinat penciptaan domba
	*/
	public Sheep(final Point P) {
		super(SHEEP_ID, SHEEP_MAXAGE);
		age = 0;
		status = 1;
		power = SHEEP_BASEPOWER;
		pos = P;
	}

}