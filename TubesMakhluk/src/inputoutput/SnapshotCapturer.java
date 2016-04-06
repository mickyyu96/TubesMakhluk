package inputoutput;

import java.awt.AWTException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

/** {@inheritdoc} Kelas SnapshotCapturer bertanggung jawab dalam pengambilan snapshot state
 *  dunia dan menyimpan hasil pengambilan snapshot ke sebuah file.
 *  @author  Micky Yudi Utama
 *  @version 1.0
 */
public final class SnapshotCapturer extends IOManager {
    /** Atribut instance snapshot capturer.
     */
    private static SnapshotCapturer capturerInstance = new SnapshotCapturer();
    /** Menciptakan sebuah instance dari kelas SnapshotCapturer.
     */
    private SnapshotCapturer() {
    }
    /** Mengembalikan pointer dari objek singleton pada kelas SnapshotCapturer.
     *  @return pointer yang menunjuk ke singleton instance pada
     *  kelas SnapshotCapturer
     */
    public static SnapshotCapturer getCapturerInstance() {
        return capturerInstance;
    }
    /** Mengambil snapshot layar.
     *  @throws IOException
     *  @throws AWTException
     */
    public void captureSnapshot() throws IOException, AWTException {
        String text = super.getStrWorldMap();
        BufferedWriter out = new BufferedWriter(new FileWriter("snapshot.txt"));
        out.write(text);
        out.close();
    }
}
