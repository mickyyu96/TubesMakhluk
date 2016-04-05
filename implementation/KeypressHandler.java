// KeypressHandler.java

import static com.sun.java.accessibility.util.AWTEventMonitor.addKeyListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/** Kelas KeypressHandler merupakan kelas yang berfungsi untuk menangani
 *  keypress yang dimasukkan oleh user
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

class KeypressHandler implements KeyListener {
    private char lastKeypress;

    public KeypressHandler() {}

    public char getLastKeypress() { return lastKeypress; }

    public void keyPressed(KeyEvent e) {
        char c = e.getKeyChar();
        if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c == '.') {
            lastKeypress = c;
            try {
                doAction();
            }
            catch(Exception v) {

            }
        }
    }
    public void keyReleased(KeyEvent e) { }
    public void keyTyped(KeyEvent e) { }

    public void doAction() throws Exception {
        char c = getLastKeypress();
        switch (c)
        {
            case 'q':
                if(World.getWorldInstance().isPaused()==1) World.getWorldInstance().changePauseState();
                World.getWorldInstance().endWorld();
                break;
            case 'w':
                World.getWorldInstance().changePauseState();
                break;
            case 'c':
                SnapshotCapturer.getCapturerInstance().captureSnapshot();
                break;
            case '.':
                try
                {
                    if(World.getWorldInstance().isPaused() == 0) throw new ExceptionObject(2);
                    MakhlukLive.getInstance().MakhlukMove();
                    MakhlukLive.getInstance().MakhlukEat();
                }
                catch(ExceptionObject E)
                {
                    E.DisplayErrorMessage();
                }
                break;
            default :
                WorldBuilder.getBuilderInstance().addAnObject(c);
        }
    }

}
