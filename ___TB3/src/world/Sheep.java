package world;

import point.Point;

/** {@inheritDoc} Kelas Sheep adalah kelas turunan dari Hewan
 *  yang merepresentasikan seekor domba.
 *  @author Robert Sebastian Herlim  / 13514061
 *  @version 1.0
 */
public class Sheep extends Hewan {
    /** Atribut ID domba.
    */
    private static final char SHEEP_ID = 'S';
    /** Atribut umur maksimal domba.
    */
    private static final int SHEEP_MAXAGE = 200;
    /** Atribut base power domba.
    */
    private static final int SHEEP_BASEPOWER = 4;
    /** Menciptakan seekor domba di koordinat p.
     * @param p koordinat penciptaan domba
    */
    public Sheep(final Point p) {
        super(SHEEP_ID, SHEEP_MAXAGE);
        age = 0;
        status = 1;
        power = SHEEP_BASEPOWER;
        pos = p;
    }
}
