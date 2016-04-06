// SnapshotCapturer.java

package inputoutput;

import java.awt.AWTException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

/** Kelas SnapshotCapturer bertanggung jawab dalam pengambilan snapshot state
 *  dunia dan menyimpan hasil pengambilan snapshot ke sebuah file
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

public class SnapshotCapturer extends IOManager {
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
     *  @throws IOException
     *  @throws AWTException
     */
    public void captureSnapshot() throws IOException, AWTException {
        String text = super.getStrWorldMap();
        BufferedWriter out = new BufferedWriter(new FileWriter("snapshot.txt"));
        out.write(text);
        out.close();
    }
    
    /** Unit test SnapshotCapturer
     *  @param args
     *  @throws IOException
     *  @throws AWTException
     */
    public static void main(String[] args) throws IOException, AWTException {
        SnapshotCapturer.getCapturerInstance().captureSnapshot();
    }
}
