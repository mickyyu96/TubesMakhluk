//Turtle.java

package makhluk;

import point.*;

/** Kelas turunan dari Hewan yang merepresentasikan seekor turtle
 *	@author     Elvina R. K. Situmorang
 *	@date       April 2016
 *	@version    1.0
 */

public class Turtle extends Hewan
{
    private static final char TURTLE_ID = 'T';
    private static final int TURTLE_MAXAGE = 240;
    private static final int TURTLE_BASEPOWER = 2;

	/** Menciptakan objek Turtle dengan posisi P
	 *  @param      P Point Posisi objek Trutle
	 */
	public Turtle(final Point P) {
        super(TURTLE_ID, TURTLE_MAXAGE);

        age = 0;
        status = 1;
        power = TURTLE_BASEPOWER;
        pos = P;
    }
}