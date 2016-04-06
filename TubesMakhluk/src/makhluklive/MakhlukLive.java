package makhluklive;

import makhluk.Makhluk;
import makhluk.Hewan;
import randomgenerator.RandomGenerator;
import world.World;
import world.LMakhluk;

/** Kelas MakhlukLive merupakan kelas yang menangani kehidupan dari setiap makhluk
 *	Kehidupan yaitu pergerakan, pencarian makan, dan umur hidup 
 *	@author     Elvina R. K. Situmorang / 13514045
 *	@version    1.0
 */
public final class MakhlukLive {
    /** Atribut singleton.
     */
    private static MakhlukLive instance = new MakhlukLive();
    /** Atribut dx.
     */
    private int dxsign = 1;
    /** Atribut dy.
     */
    private int dysign = 1;
    /** Konstruktor menciptakan MakhlukLive.
     */
    private MakhlukLive() {
    }
    /** Mengembalikan pointer dari objek kelas singleton pada kelas MakhlukLive.
     *  @return Pointer yang menunjuk ke singleton instance pada
     *  kelas MakhlukLive
     */
    public static MakhlukLive getInstance() {
        return instance;
    }
    /** Menangani pergerakan dari makhluk.
     */
    public void makhlukMove() {
        int dx, dy;
        LMakhluk lMakhluk = World.getWorldInstance().getObjects();

        for (int i = 0; i < lMakhluk.getSize(); i++) {
                if (lMakhluk.getInfo(i).isAlive() == 1
                     && lMakhluk.getInfo(i).getID() != 'G') {
                Hewan hewan = (Hewan) lMakhluk.getInfo(i);

                dx = RandomGenerator.getInstance().getNextInt(2) * dxsign;
                dy = RandomGenerator.getInstance().getNextInt(2) * dysign;

               if (hewan.shouldRebounced(dx, 0)) {
                   dx *= -1;
                   dxsign *= -1;
               }
               if (hewan.shouldRebounced(0, dy)) {
                    dy *= -1;
                    dysign *= -1;
               }

                hewan.move(dx, dy);
                hewan.ageIncrement();
                if (hewan.getAge() == hewan.getMaxAge()) {
                    hewan.kill();
                }
         } else {
                lMakhluk.getInfo(i).ageIncrement();
                if (lMakhluk.getInfo(i).getAge()
                       == lMakhluk.getInfo(i).getMaxAge()) {
                   lMakhluk.getInfo(i).kill();
                }
            }
        }
    }
    /** Menangani pergerakan dari makhluk untuk mencari makan.
     */
    public void makhlukEat() {
        World worldInstance = World.getWorldInstance();
        LMakhluk lMakhluk = worldInstance.getObjects();

        for (int i = 0; i < lMakhluk.getSize(); i++) {
            if (lMakhluk.getInfo(i).isAlive() == 1
                    && lMakhluk.getInfo(i).getID() != 'G') {
                if (lMakhluk.getInfo(i).isMakhlukInTheSamePoint() == 1) {
                    Makhluk m1 = lMakhluk.getInfo(i);
                    Makhluk m2 =
                            lMakhluk.getInfo(i).makhlukInTheSamePoint();
                    if (((m1).getID() == 'R') || ((m1).getID() == 'T')
                            || ((m1).getID() == 'S')) {
                        if ((m2).getID() == 'G') {
                            m2.kill();
                        }
                    } else {
                        if (m2.getID() != 'G') {
                            if (((Hewan) m2).getPower()
                                < ((Hewan) m1).getPower()) {
                                m2.kill();
                            }
                        }
                    }
                }
            }
        }
    }
}