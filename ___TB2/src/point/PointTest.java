package point;

import org.junit.*;
import static org.junit.Assert.*;
/**
 * Created by User on 4/6/2016.
 */
public class PointTest {
    @Test
    public void test_consPoint() {

        Point P1 = new Point();
        assertTrue("x bukan 10", P1.getX() == 10);
        assertTrue("y bukan 10", P1.getY() == 10);

        Point P2 = new Point(42,25);
        assertTrue("x bukan 42", P2.getX()==42);
        assertTrue("y bukan 25", P2.getY()==25);
    }
    @Test
    public void test_inc () {
        Point P1 = new Point();
        P1.increment(1,1);
        assertTrue("Hasil incremen x salah", P1.getX()==11);
        assertTrue("Hasil incremen y salah", P1.getY()==11);
    }

    @Test
    public void test_dist () {
        Point S = new Point(0,4);
        Point P = new Point(3,0);
        int i = Point.getDistance(S,P);
        assertTrue("Distance salah", i==5);
    }
}
