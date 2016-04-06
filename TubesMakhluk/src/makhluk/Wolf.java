package makhluk;

import point.Point;

/** {@inheritdoc} Kelas Wolf adalah kelas turunan dari Hewan 
 *  yang merepresentasikan seekor serigala.
 *  @author Robert Sebastian Herlim / 13514061
 *  @version 1.0
 */
public class Wolf extends Hewan {
    /** Atribut ID serigala.
     */
    private static final char WOLF_ID = 'W';
    /** Atribut umur maksimal serigala.
     */
    private static final int WOLF_MAXAGE = 180;
    /** Atribut base power serigala.
     */
    private static final int WOLF_BASEPOWER = 6;
    /** Menciptakan seekor serigala di koordinat p.
     * @param p koordinat penciptaan serigala
     */
    public Wolf(final Point p) {
        super(WOLF_ID, WOLF_MAXAGE);
        age = 0;
        status = 1;
        power = WOLF_BASEPOWER;
        pos = p;
    }
}
