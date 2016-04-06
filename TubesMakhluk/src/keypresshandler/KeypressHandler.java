// KeypressHandler.java

package keypresshandler;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import exception.*;
import inputoutput.*;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JLabel;
import makhluklive.*;
import world.*;

/** Kelas KeypressHandler merupakan kelas yang berfungsi untuk menangani
 *  keypress yang dimasukkan oleh user
 *  @author     Micky Yudi Utama / 13514011
 *  @date       April 2016
 *  @version	1.0
 */

public class KeypressHandler implements KeyListener {
    private static char lastKeypress;

    /** Menciptakan sebuah instance dari kelas KeypressHandler
     */
    public KeypressHandler() {}

    /** Mengembalikan karakter yang terakhir ditekan oleh pengguna yang disimpan 
     *  dalam instance KeypressHandler
     *  @return char yang terakhir ditekan pengguna
     */
    public char getLastKeypress() { 
        return lastKeypress; 
    }

    /** Override fungsi keyPressed pada KeyListener sesuai kebutuhan
     *  @param e KeyEvent
     */
    @Override
    public void keyPressed(KeyEvent e) {
        char c = e.getKeyChar();
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '.') {
            lastKeypress = c;
            try {
                doAction();
            }
            catch(Exception v) {}
        }
    }
    
    /** Override fungsi keyReleased pada KeyListener sesuai kebutuhan
     *  @param e KeyEvent
     */
    @Override
    public void keyReleased(KeyEvent e) {}
    
    /** Override fungsi keyTyped pada KeyListener sesuai kebutuhan
     *  @param e KeyEvent
     */
    @Override
    public void keyTyped(KeyEvent e) {}

    /** Melakukan aksi-aksi yang sesuai dengan karakter lastKeypress
     *  yang tersimpan dalam instance KeypressHandler
     *  @throws Exception
     */
    public void doAction() throws Exception {
        char c = getLastKeypress();
        switch (c) {
            case 'q':
                if (World.getWorldInstance().isPaused()==1) {
                    World.getWorldInstance().changePauseState();
                }
                World.getWorldInstance().endWorld();
                break;
            case 'w':
                World.getWorldInstance().changePauseState();
                break;
            case 'c':
                SnapshotCapturer.getCapturerInstance().captureSnapshot();
                break;
            case '.':
                try {
                    if (World.getWorldInstance().isPaused() == 0) {
                        throw new ExceptionObject(2);
                    }
                    MakhlukLive.getInstance().MakhlukMove();
                    MakhlukLive.getInstance().MakhlukEat();
                }
                catch(ExceptionObject E) {
                    E.DisplayErrorMessage();
                }
                break;
            default :
                WorldBuilder.getBuilderInstance().addAnObject(c);
        }
    }
    
    /** Unit test KeypressHandler
     *  @param args 
     */
 /*   public static void main(String[] args) {
        JFrame worldView = new JFrame("Animal's Village");
        JLabel worldLabel = new JLabel("", JLabel.CENTER);
        worldLabel.setFont(new Font("Consolas", Font.PLAIN, 15));
        worldView.setSize(400, 400);
        worldView.addKeyListener(new KeypressHandler());
        worldView.add(worldLabel);
        worldView.setVisible(false);
        while (lastKeypress != 'q') {
            System.out.println(lastKeypress);
        }
        worldView.dispose();
    } */
}
