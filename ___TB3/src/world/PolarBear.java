package world;

import point.Point;
/** {@inheritdoc} Kelas PolarBear adalah kelas turunan dari Hewan
 *  yang merepresentasikan seekor polar bear.
 *  @author Atika Azzahra Akbar / 13514077
 *  @version 1.0
 */
public class PolarBear extends Hewan {
    /** Atribut ID polar bear.
     */
    private static final char POLARBEAR_ID = 'P';
    /** Atribut umur maksimal polar bear.
     */
    private static final int POLARBEAR_MAXAGE = 250;
    /** Atribut base power polar bear.
     */
    private static final int POLARBEAR_BASEPOWER = 8;
    /** Menciptakan objek PolarBear dengan posisi P.
     *  @param p Point Posisi objek PolarBear
     */
    public PolarBear(final Point p) {
        super(POLARBEAR_ID, POLARBEAR_MAXAGE);
        age = 0;
        status = 1;
        power = POLARBEAR_BASEPOWER;
        pos = p;
   }
}
