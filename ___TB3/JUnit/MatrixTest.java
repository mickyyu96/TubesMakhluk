package matrix;

import org.junit.Test;
import static org.junit.Assert.*;
/**
 * Created by Elvina R.K. Situmorang on 4/6/2016.
 */
public class MatrixTest {
    Matrix M = new Matrix(50,50);
    @Test
    public void test_consMatrix () {
        assertTrue("Baris salah",M.getnBrs()==50);
        assertTrue("Kolom salah",M.getnKol()==50);
    }

    @Test
    public void test_contain() {
        M.setInfo('#',24,24);
        assertTrue("Isi salah",M.getInfo(24,24)=='#');
    }
}
