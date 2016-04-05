package tubesmakhluk;

// SnapshotCapturer.java

import java.io.PrintWriter;
import java.awt.AWTException;
import java.awt.Rectangle;
import java.awt.Robot;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

/** Kelas SnapshotCapturer bertanggung jawab dalam pengambilan snapshot state
 *  dunia dan menyimpan hasil pengambilan snapshot ke sebuah file
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

class SnapshotCapturer extends IOManager {
    private static SnapshotCapturer capturerInstance = new SnapshotCapturer();

    /** Menciptakan sebuah instance dari kelas SnapshotCapturer
     */
    private SnapshotCapturer() {}

    /** Mengembalikan pointer dari objek singleton pada kelas SnapshotCapturer
     *  @return pointer yang menunjuk ke singleton instance pada kelas SnapshotCapturer
     */
    public static SnapshotCapturer getCapturerInstance() {
        return capturerInstance;
    }

    /** Mengambil snapshot layar
     *  @return void
     */
    public void captureSnapshot() throws IOException, AWTException {
        String text = super.getStrWorldMap();
        System.out.println(text + "======================");
        PrintWriter out = new PrintWriter("snapshot.txt");
        out.println(text); 
    }
}
