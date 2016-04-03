// KeypressHandler.java

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

/** Kelas KeypressHandler merupakan kelas yang berfungsi untuk menangani 
 *  keypress yang dimasukkan oleh user
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

class KeypressHandler implements KeyListener {
    private static KeypressHandler handlerInstance = new KeypressHandler();
    char lastKeypress;
    
    private KeypressHandler() {}
    
    public static KeypressHandler getHandlerInstance() {
        return handlerInstance;
    }
    
    public void keyTyped(KeyEvent e) {}
    
    public void keyReleased(KeyEvent e) {}
    
    public void keyPressed(KeyEvent e) {
        if (e.getKeyChar() == 'q')
        {
            if (getWorldInstance().isPaused()) {
                getWorldInstance().changePauseState();
            }
            getWorldInstance().endWorld();
        }
        else if (e.getKeyChar() == "c") {
            getCapturerInstance().captureSnapshot();
        }
    }
}
