package inputoutput;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import exception.ExceptionObject;
import inputoutput.SnapshotCapturer;
import makhluklive.MakhlukLive;
import world.World;
import world.WorldBuilder;


/** Kelas KeypressHandler merupakan kelas yang berfungsi untuk menangani
 *  keypress yang dimasukkan oleh user.
 *  @author  Micky Yudi Utama / 13514011
 *  @version 1.0
 */
public class KeypressHandler implements KeyListener {
    /** Atribut karakter lastkeypress.
     */
    private static char lastKeypress;

    /** Menciptakan sebuah instance dari kelas KeypressHandler.
     */
    public KeypressHandler() {
    }
    /** Mengembalikan karakter yang terakhir ditekan oleh pengguna
     *  yang disimpan dalam instance KeypressHandler.
     *  @return char yang terakhir ditekan pengguna
     */
    public final char getLastKeypress() {
        return lastKeypress;
    }
    /** Override fungsi keyPressed pada KeyListener sesuai kebutuhan.
     *  @param e KeyEvent
     */
    @Override
    public final void keyPressed(final KeyEvent e) {
        char c = e.getKeyChar();
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '.') {
            lastKeypress = c;
            try {
                doAction();
            } catch (Exception v) {
            }
        }
    }
    /** Override fungsi keyReleased pada KeyListener sesuai kebutuhan.
     *  @param e KeyEvent
     */
    @Override
    public void keyReleased(final KeyEvent e) {
    }
    /** Override fungsi keyTyped pada KeyListener sesuai kebutuhan.
     *  @param e KeyEvent
     */
    @Override
    public void keyTyped(final KeyEvent e) {
    }
    /** Melakukan aksi-aksi yang sesuai dengan karakter lastKeypress.
     *  yang tersimpan dalam instance KeypressHandler
     *  @throws Exception
     */
    public final void doAction() throws Exception {
        char c = getLastKeypress();
        switch (c) {
            case 'q':
                if (World.getWorldInstance().isPaused() == 1) {
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
                    MakhlukLive.getInstance().makhlukMove();
                    MakhlukLive.getInstance().makhlukEat();
                } catch (ExceptionObject e) {
                    e.displayErrorMessage();
                }
                break;
            default :
                WorldBuilder.getBuilderInstance().addAnObject(c);
        }
    }
}
