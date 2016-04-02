// Screen.java

import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/** Kelas Screen merepresentasikan layar pengguna dan bertanggung jawab untuk 
 *  melakukan operasi-operasi Input/Output ke layar
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

class Screen extends IOManager {
    private static Screen screenInstance = new Screen();
    
    /** Mencipatkan sebuah instance dari kelas Screen
     */
    private Screen() {}
    
    /** Mengembalikan pointer dari objek singleton pada kelas Screen
     *  @return pointer yang menunjuk ke singleton instance pada kelas Screen
     */
    public static Screen getScreenInstance() {
        return screenInstance;
    }
    
    /** Mencetak state dunia beserta dengan isi-isinya ke layar secara berkala 
     *  dengan interval waktu tertentu
     *  @param deltaT int interval waktu (dalam ms) antar pencetakan state 
     *  dunia ke layar
     *  @return void
     */
    public static void showWorld(int deltaT) {
        while (!getWorldInstance().isEnded()) {
            getWorldInstance().lockWorld();
            int nBrs = getWorldInstance().getNBrs();
            for (int i=0; i<nBrs; i++) {
                System.out.println();
            }
            getScreenInstance().PrintWorldMap();
            getWorldInstance().unlockWorld();
        }
        try {
            TimeUnit.MILLISECONDS.sleep(deltaT);
        } catch (InterruptedException ex) {
            Logger.getLogger(Screen.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}