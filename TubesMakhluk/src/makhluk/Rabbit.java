//Rabbit.java

package makhluk;

import point.*;

/** Kelas turunan dari Hewan yang merepresentasikan seekor rabbit
 *	@author     Elvina R. K. Situmorang
 *	@date       April 2016
 *	@version	1.0
 */

public class Rabbit extends Hewan {
    private static final char RABBIT_ID = 'R';
    private static final int RABBIT_MAXAGE = 100;
    private static final int RABBIT_BASEPOWER = 3;

    /** Menciptakan objek Rabbit dengan posisi P
     *  @param      P Point Posisi objek Rabbit
     */
	public Rabbit (final Point P) {
		super(RABBIT_ID, RABBIT_MAXAGE);

		age = 0;
		status = 1;
		power = RABBIT_BASEPOWER;
		pos = P;
	}
}