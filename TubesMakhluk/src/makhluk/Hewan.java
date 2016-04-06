package makhluk;

import world.*;

/** Kelas Hewan yang merukapan turunan dari Makhluk yang merepresentasikan Hewan
 *	yang ada pada penciptaan World.
 *	@author     Elvina R. K. Situmorang
 *	@version	1.0
 */
public abstract class Hewan extends Makhluk {
	/** Atribut hungerLvl, power, deltaT hewan.
	 */
    protected int hungerLvl, power, deltaT;
    /** Konstruktor Hewan, yang akan dilakukan passing parameter kepada kelas Makhluk.
     *  @param char ID dari Hewan
     *  @param int Maximum umur seekor Hewan
     */
    protected Hewan (char _ID, int _maxAge) {
        super(_ID,_maxAge);
    }
	/** Mengatur pergerakan makhluk.
	 *	@param 	int dx, besar perpindahan makhluk yaitu dx
	 *	@param 	int dy, besar perpindahan makhluk yaitu dy
	 *	@return	void
	 */
    public void Move (int dx, int dy) {
         pos.increment(dx, dy);
    }
    /** Mengembalikan power yang dimiliki seekor Hewan.
     *  @return int power seekor Hewan
     */
    public int getPower() {
        return power;
    }
    /** Mengembalikan apakah hewan tersebut akan bergerak menabrak.
     *	@param 	int dx, besar perpindahan makhluk yaitu dx
     * 	@param 	int dy, besar perpindahan makhluk yaitu dy
	 *	@return	boolean akan bernilai true jika hewan tersebut harus bergerak ke arah lainnya
     */
    public boolean shouldRebounced(int dx, int dy) {
        if (dx+pos.getX() <= 0 || dx+pos.getX() >= World.getWorldInstance().getNBrs()-1) {
            return true;
        }
        if (dy+pos.getY() <= 0 || dy+pos.getY() >= World.getWorldInstance().getNKol()-1) {
            return true;
        }
        return false;
    }
}
