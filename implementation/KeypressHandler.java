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
    private char lastKeypress;
    
    private KeypressHandler() {}

    public char getLastKeypress() { return lastKeypress; }
    
    public static KeypressHandler getHandlerInstance() {
        return handlerInstance;
    }

    public void getKeypress() throws Exception {
        //lastKeypress = (char) System.in.read(); <<masih gak bisa ternyata :( >>
    }

    public void doAction() throws Exception {
        char c = getHandlerInstance().getLastKeypress();
        switch (c)
        {
            case 'q':
                World.getWorldInstance().endWorld();
                break;
            case 'w':
                lastKeypress = '-';
                do
                {
                    while(System.in.available()!=0)
                    {
                        KeypressHandler.getHandlerInstance().getKeypress();
                        if(lastKeypress == '.')
                        {
                            MakhlukLive.getInstance().MakhlukMove();
                            Screen.getScreenInstance().PrintWorldMap();
                            MakhlukLive.getInstance().MakhlukEat();
                        }
                        else if(lastKeypress == 'c')
                        {
                            SnapshotCapturer.getCapturerInstance().captureSnapshot();
                        }
                    }
                }while(lastKeypress != 'w');
                break;
            case 'c':
                SnapshotCapturer.getCapturerInstance().captureSnapshot();
                break;
            case '.':
                try
                {
                    throw new ExceptionObject(2);
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
    
    public void keyTyped(KeyEvent e) {}
    
    public void keyReleased(KeyEvent e) {}
    
    public void keyPressed(KeyEvent e) {
        /*if (e.getKeyChar() == 'q')
        {
            if (getWorldInstance().isPaused()) {
                getWorldInstance().changePauseState();
            }
            getWorldInstance().endWorld();
        }
        else if (e.getKeyChar() == "c") {
            getCapturerInstance().captureSnapshot();
        }*/
    }
}
