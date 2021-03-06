package inputoutput;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import exception.ExceptionObject;
import makhluklive.MakhlukManager;
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
     *  @throws Exception jika kesalahan masukan pengguna
     */
    public final void doAction() throws Exception {
        char c = getLastKeypress();
        final int arahkepala = 3;
        if (World.getWorldInstance().isSnakeWorld() == 0) {
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
                        MakhlukManager.getInstance().makhlukMove();
                        MakhlukManager.getInstance().makhlukEat();
                    } catch (ExceptionObject e) {
                        e.displayErrorMessage();
                    }
                    break;
                default :
                    WorldBuilder.getBuilderInstance().addAnObject(c);
            }
        } else {
            int arahUlar = World.getWorldInstance().getArahUlar();
            switch (c) {
                case 'd':
                    if (arahUlar != 2) {
                        World.getWorldInstance().setArahUlar(0);
                    }
                    break;
                case 'w':
                    if (arahUlar != arahkepala) {
                        World.getWorldInstance().setArahUlar(1);
                    }
                    break;
                case 'a':
                    if (arahUlar != 0) {
                        World.getWorldInstance().setArahUlar(2);
                    }
                    break;
                case 's':
                    if (arahUlar != 1) {
                        World.getWorldInstance().setArahUlar(arahkepala);
                    }
                    break;
                default :
                    break;
            }
        }
    }
}
