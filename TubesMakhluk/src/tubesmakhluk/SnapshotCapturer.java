package tubesmakhluk;

// SnapshotCapturer.java

import java.awt.AWTException;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import static java.lang.System.out;

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
        BufferedWriter out = new BufferedWriter(new FileWriter("snapshot.txt"));
        out.write(text);
        out.close();
    }
}
