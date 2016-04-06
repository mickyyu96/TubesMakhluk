package makhluk;

import point.Point;

/** {@inheritdoc} Kelas Tumbuhan adalah kelas turunan dari Makhluk 
 *  yang merepresentasikan sebuah tumbuhan.
 *  @author Robert Sebastian Herlim  / 13514061
 *  @version 1.0
 */
public class Tumbuhan extends Makhluk {
    /** Atribut ID tumbuhan.
     */
    private static final char TUMBUHAN_ID = 'G';
    /** Atribut umur maksimal tumbuhan.
     */
    private static final int TUMBUHAN_MAXAGE = 300;
    /** Menciptakan sebuah tumbuhan di koordinat p.
     * @param p koordinat penciptaan tumbuhan
     */
    public Tumbuhan(final Point p) {
        super(TUMBUHAN_ID, TUMBUHAN_MAXAGE);
        age = 0;
        status = 1;
        pos = p;
	}
}
