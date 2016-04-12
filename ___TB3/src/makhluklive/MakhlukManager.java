package makhluklive;

import randomgenerator.RandomGenerator;
import world.World;
import world.Makhluk;
import world.ListMakhluk;
import world.Hewan;
import point.Point;
/** Kelas MakhlukGenerator merupakan kelas yang menangani kehidupan dari
 *  setiap makhluk Kehidupan yaitu pergerakan, pencarian makan, dan umur hidup.
 *  @author     Elvina R. K. Situmorang / 13514045
 *  @version    1.0
 */
public final class MakhlukManager implements Runnable {
    /** Atribut singleton.
     */
    private static MakhlukManager instance = new MakhlukManager();
    /** Atribut dx.
     */
    private int dxsign = 1;
    /** Atribut dy.
     */
    private int dysign = 1;
    /** Konstruktor menciptakan MakhlukGenerator.
     */
    public MakhlukManager() {
    }
    /** Mengembalikan pointer dari objek kelas singleton pada kelas MakhlukGenerator.
     *  @return Pointer yang menunjuk ke singleton instance pada
     *  kelas MakhlukGenerator
     */
    public static MakhlukManager getInstance() {
        return instance;
    }
    /** Menangani pergerakan dari makhluk.
     */
    public void makhlukMove() {
        int dx, dy;
        ListMakhluk lMakhluk = World.getWorldInstance().getObjects();

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

        if (World.getWorldInstance().isSnakeWorld() == 1) {
            ListMakhluk snakes = World.getWorldInstance().getSnakes();
            Hewan kepalaUlar = (Hewan) snakes.getInfo(0);
            int arahGerak = World.getWorldInstance().getArahUlar();
            dx = 0; dy = 0;
            switch (arahGerak) {
                case 0: // timur
                    dy = 1;
                    break;
                case 1: // utara
                    dx = -1;
                    break;
                case 2: // barat
                    dy = -1;
                    break;
                default:
                    dx = 1;
                    break;
            }
            Point lastPos = new Point(kepalaUlar.getPosition());
            
            kepalaUlar.move(dx, dy);
            
            for (int i = 1; i < snakes.getSize(); i++) {
                if (snakes.getInfo(i).isAlive() == 1) {
                    Hewan ular = (Hewan) snakes.getInfo(i);

                    Point tmpPos = new Point(ular.getPosition());
                    ular.setPosition(lastPos);
                    lastPos = tmpPos;
                } 
           }
        }
        
    }
    /** Menangani pergerakan dari makhluk untuk mencari makan.
     */
    public void makhlukEat() {
        World worldInstance = World.getWorldInstance();
        ListMakhluk lMakhluk = worldInstance.getObjects();

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
    /** Prosedur run yang digunakan saat penciptaan sebuah thread.
     */
    @Override
    public void run() {
        do {
            while (World.getWorldInstance().isPaused() == 1) {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException ex) {
                }
            }
            MakhlukManager.getInstance().makhlukMove();
            MakhlukManager.getInstance().makhlukEat();
            if (World.getWorldInstance().getObjects().isAllMakhlukDead() &&
                    World.getWorldInstance().getSnakes().isAllMakhlukDead()) {
                World.getWorldInstance().endWorld();
                break;
            }
            try {
                Thread.sleep(500);
            } catch (InterruptedException ex) {
            }
        } while (World.getWorldInstance().isEnded() == 0);
    }
}
