package inputoutput;

import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JLabel;
import keypresshandler.KeypressHandler;
import world.World;
/** {@inheritdoc} Kelas Screen merepresentasikan layar pengguna
 *  dan bertanggung jawab untuk melakukan operasi-operasi
 *  Input/Output ke layar.
 *  @author Micky Yudi Utama
 *  @version 1.0
 */
public class Screen extends IOManager implements Runnable {
    /** Atribut screen instance.
     */
    private static Screen screenInstance = new Screen();
    /** Mencipatkan sebuah instance dari kelas Screen.
     */
    public Screen() {
    }
    /** Mengembalikan pointer dari objek singleton pada kelas Screen.
     *  @return pointer yang menunjuk ke singleton instance pada kelas Screen
     */
    public static Screen getScreenInstance() {
        return screenInstance;
    }
    /** Mencetak state dunia beserta dengan isi-isinya ke layar secara berkala
     *  dengan interval waktu tertentu.
     *  @param deltaT int interval waktu (dalam ms) antar pencetakan state
     *  dunia ke layar
     */
    public final void showWorld(final int deltaT) {
        JFrame worldView = new JFrame("Animal's Village");
        JLabel worldLabel = new JLabel("", JLabel.CENTER);
        worldLabel.setFont(new Font("Consolas", Font.PLAIN, 15));
        worldView.setSize(400, 400);
        worldView.addKeyListener(new KeypressHandler());
        worldView.add(worldLabel);
        worldView.setVisible(true);
        while (World.getWorldInstance().isEnded() == 0) {
            worldLabel.setText(getHTMLStrWorldMap());
            try {
                Thread.sleep(deltaT);
            } catch (Exception e) {
            }
        }
        worldView.setVisible(false);
        worldView.dispose();
    }
    /** Menjalankan dan memulai dunia.
     */
    public final void run() {
        showWorld(500);
        System.out.println("Thread Finished");
    }
}
