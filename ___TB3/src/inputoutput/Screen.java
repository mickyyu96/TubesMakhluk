package inputoutput;

import java.awt.Color;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import world.World;
/** {@inheritdoc} Kelas Screen merepresentasikan layar pengguna
 *  dan bertanggung jawab untuk melakukan operasi-operasi
 *  Input/Output ke layar.
 *  @author Micky Yudi Utama / 13514011
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
    public final void showWorld(JLabel worldLabel, final int deltaT) {
        
        
        while (World.getWorldInstance().isEnded() == 0) {
            String test = getHTMLStrWorldMap();
            worldLabel.setText(getHTMLStrWorldMap());
            try {
                Thread.sleep(deltaT);
            } catch (Exception e) {
            }
        } 
    }
    
    
    /** Menjalankan dan memulai dunia.
     */
    public final void run() {
        final int num = 500;
        final int sizefont = 15;
        JFrame worldView = new JFrame("Animal's Village");
        worldView.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JLabel worldLabel = new JLabel("", JLabel.CENTER);
        JPanel mainPanel = new JPanel();
        mainPanel.setBackground(Color.YELLOW);
        
        worldLabel.setFont(new Font("Consolas", Font.PLAIN, sizefont));
        worldView.setSize(num, num);
        worldView.addKeyListener(new KeypressHandler());
        worldView.setVisible(true);
        
        mainPanel.add(worldLabel);
        worldView.add(mainPanel);
        
        showWorld(worldLabel, num);
        worldView.setVisible(false);
        worldView.dispose();
        System.out.println("Thread Finished");
    }
}
