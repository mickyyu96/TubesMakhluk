package world;

/** {@inheritDoc} Kelas Hewan adalah kelas yang merukapan turunan dari Makhluk
 *  yang merepresentasikan Hewan yang ada pada penciptaan World.
 *  @author   Elvina R. K. Situmorang / 13514045
 *  @version  1.0
 */
public abstract class Hewan extends Makhluk {
    /** Atribut hungerLvl, power, deltaT hewan.
     */
    protected int hungerLvl, power, deltaT;
    /** Konstruktor Hewan, yang akan dilakukan passing parameter
     *  kepada kelas Makhluk.
     *  @param id dari Hewan
     *  @param maxAge umur seekor Hewan
     */
    protected Hewan(final char id, final int maxAge) {
        super(id, maxAge);
    }
    /** Mengatur pergerakan makhluk.
     *  @param dx besar perpindahan makhluk yaitu dx
     *  @param dy besar perpindahan makhluk yaitu dy
     */
    public final void move(final int dx, final int dy) {
         pos.increment(dx, dy);
    }
    /** Mengembalikan power yang dimiliki seekor Hewan.
     *  @return int power seekor Hewan
     */
    public final int getPower() {
        return power;
    }
    /** Mengembalikan apakah hewan tersebut akan bergerak menabrak.
     *  @param dx besar perpindahan makhluk yaitu dx
     *  @param dy besar perpindahan makhluk yaitu dy
     *  @return boolean akan bernilai true jika hewan tersebut harus
     *  bergerak ke arah lainnya
     */
    public final boolean shouldRebounced(final int dx, final int dy) {
        if (dx + pos.getX() <= 0 || dx + pos.getX()
             >= World.getWorldInstance().getNBrs() - 1) {
            return true;
        }
        if (dy + pos.getY() <= 0 || dy + pos.getY()
            >= World.getWorldInstance().getNKol() - 1) {
            return true;
        }
        return false;
    }
}
