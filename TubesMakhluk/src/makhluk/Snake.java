// Snake.java

package makhluk;

import point.*;

/** Kelas turunan dari Hewan yang merepresentasikan seekor ular
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

public class Snake extends Hewan {
    private static final char SNAKE_ID = 'U';
    private static final int SNAKE_MAXAGE = 150;
    private static final int SNAKE_BASEPOWER = 5;

    /** Menciptakan seekor ular di koordinat P
     *  @param P koordinat penciptaan ular
     */
    public Snake(final Point P) {
        super(SNAKE_ID, SNAKE_MAXAGE);
        age = 0;
        status = 1;
        power = SNAKE_BASEPOWER;
        pos = P;
    }
}