package makhluk;

import point.Point;

/** Kelas turunan dari Hewan yang merepresentasikan seekor ular
 *  @author     Micky Yudi Utama
 *  @version	1.0
 */
public class Snake extends Hewan {
    /** Atribut ID ular.
    */    
    private static final char SNAKE_ID = 'U';
    /** Atribut umur maksimal ular.
    */    
    private static final int SNAKE_MAXAGE = 150;
    /** Atribut ID ular.
    */    
    private static final int SNAKE_BASEPOWER = 5;
    /** Menciptakan seekor ular di koordinat p.
     *  @param P koordinat penciptaan ular
     */
    public Snake(final Point p) {
        super(SNAKE_ID, SNAKE_MAXAGE);
        age = 0;
        status = 1;
        power = SNAKE_BASEPOWER;
        pos = p;
    }
}
