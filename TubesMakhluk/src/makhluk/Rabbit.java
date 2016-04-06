package makhluk;

import point.Point;

/** Kelas turunan dari Hewan yang merepresentasikan seekor rabbit.
 *  @author Elvina R. K. Situmorang
 *  @version 1.0
 */
public class Rabbit extends Hewan {
    /** Atribut ID rabbit.
     */
    private static final char RABBIT_ID = 'R';
    /** Atribut umur maksimal rabbit.
     */
    private static final int RABBIT_MAXAGE = 100;
    /** Atribut base power rabbit.
     */
    private static final int RABBIT_BASEPOWER = 3;
    /** Menciptakan objek Rabbit dengan posisi p.
     *  @param p Point Posisi objek Rabbit
     */
    public Rabbit(final Point p) {
        super(RABBIT_ID, RABBIT_MAXAGE);
        age = 0;
        status = 1;
        power = RABBIT_BASEPOWER;
        pos = p;
    }
}
