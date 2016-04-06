package makhluk;

import point.Point;

/** {@inheritDoc} Kelas Turtle adalah kelas turunan dari Hewan
 *  yang merepresentasikan seekor turtle.
 *  @author Elvina R. K. Situmorang / 13514045
 *  @version 1.0
 */
public class Turtle extends Hewan {
    /** Atribut ID rabbit.
     */
    private static final char TURTLE_ID = 'T';
    /** Atribut umur maksimal turtle.
     */
    private static final int TURTLE_MAXAGE = 240;
    /** Atribut base power turtle.
     */
    private static final int TURTLE_BASEPOWER = 2;
    /** Menciptakan objek Turtle dengan posisi p.
     *  @param p Point Posisi objek Trutle
     */
    public Turtle(final Point p) {
        super(TURTLE_ID, TURTLE_MAXAGE);
        age = 0;
        status = 1;
        power = TURTLE_BASEPOWER;
        pos = p;
    }
}
