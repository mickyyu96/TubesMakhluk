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

class KeypressHandler extends KeyAdapter implements KeyListener {
    //private static KeypressHandler handlerInstance = new KeypressHandler();
    //private char lastKeypress;
    
    public KeypressHandler() {
        addKeyListener(this);
    }
    
    /* public static KeypressHandler getHandlerInstance() {
        return handlerInstance;
    } */
    
    public void keyTyped(KeyEvent e) {}
    
    public void keyReleased(KeyEvent e) {}
    
    public void keyPressed(KeyEvent e) {
        char temp = e.getKeyChar();
        switch (temp) {
                case 'q' : 
                    System.out.println("w");
                    break;
                case 'w' :
                    System.out.println("q");
                    break;
        }
    }
    
    public static void main(String[] args) {
        System.out.println('a');
        KeypressHandler k = new KeypressHandler();
        while (1 == 1) {
        }
    }
}
