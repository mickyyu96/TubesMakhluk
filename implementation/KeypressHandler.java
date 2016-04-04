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
        lastKeypress = e.getKeyChar(); 
        System.out.println("##"+lastKeypress);
        try {
            doAction();
        }
        catch(Exception v) {

        }
    }
    public void keyReleased(KeyEvent e) { }
    public void keyTyped(KeyEvent e) { }

    public void doAction() throws Exception {
        char c = getLastKeypress();
        switch (c)
        {
            case 'q':
                World.getWorldInstance().endWorld();
                break;
            case 'w':
                // KARENA SKRG STATUSNYA DUALTHREAD, ARTINYA HARUS PAKE MUTEX LAGI UNTUK NGEPAUSE
                /*
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
                */
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
