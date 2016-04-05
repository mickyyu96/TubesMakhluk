package tubesmakhluk;

// Screen.java

import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import java.awt.Font;

/** Kelas Screen merepresentasikan layar pengguna dan bertanggung jawab untuk
 *  melakukan operasi-operasi Input/Output ke layar
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

public class Screen extends IOManager implements Runnable {
    private static Screen screenInstance = new Screen();

    /** Mencipatkan sebuah instance dari kelas Screen
     */
    public Screen() {}

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
    public void showWorld(int deltaT) {
        JFrame worldView = new JFrame("Animal's Village");
        JLabel worldLabel = new JLabel("", JLabel.CENTER);
        worldLabel.setFont(new Font("Consolas", Font.PLAIN, 15));

        worldView.setSize(400,400);
        worldView.addKeyListener(new KeypressHandler());
        worldView.add(worldLabel);
        worldView.setVisible(true);

        while (World.getWorldInstance().isEnded()==0) {
            worldLabel.setText(getHTMLStrWorldMap());
            try {
                Thread.sleep(deltaT);
            }
            catch(Exception e) {}
        }
        worldView.setVisible(false);
        worldView.dispose();
    }

    public void run() {
        showWorld(500);
        System.out.println("Thread Finished");

    }
}
