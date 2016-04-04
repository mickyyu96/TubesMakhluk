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

    private KeypressHandler() {}

    public char getLastKeypress() { return lastKeypress; }


    public static KeypressHandler getHandlerInstance() {
        return handlerInstance;

    }
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

}
