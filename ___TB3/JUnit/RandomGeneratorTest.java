package randomgenerator;

import org.junit.Test;
import static org.junit.Assert.*;
import point.*;
/**
 * Created by Elvina R. K. Situmorang on 4/6/2016.
 */
public class RandomGeneratorTest {
    @Test
    public void test_Random() {
        int x1, x2, x3;
        x1 = RandomGenerator.getInstance().getNextInt(10);
        x2 = RandomGenerator.getInstance().getNextInt(10);
        x3 = RandomGenerator.getInstance().getNextInt(10);
        assertTrue("Angka tidak ter-Random", (x1!=x2 || x2!=x3 || x3!=x1));
    }

    @Test
    public void test_RndBetween() {
        int x1, x2, x3;
        x1 = RandomGenerator.getInstance().getNextIntBetween(-3,3);
        x2 = RandomGenerator.getInstance().getNextIntBetween(-3,3);
        x3 = RandomGenerator.getInstance().getNextIntBetween(-3,3);
        assertTrue("Angka tidak ter-Random", (x1!=x2 || x2!=x3 || x3!=x1));
    }

    @Test
    public void test_RndPoint() {
        Point P1 = RandomGenerator.getInstance().getNextPoint(5,5);
        Point P2 = RandomGenerator.getInstance().getNextPoint(5,5);
        Point P3 = RandomGenerator.getInstance().getNextPoint(5,5);
        assertTrue("Angka tidak ter-Random", (P1.getX()!=P2.getX() || P1.getX()!= P3.getX() || P2.getX()!=P3.getX() ||
            P1.getY()!=P2.getY() || P2.getY()!= P3.getY() || P3.getY()!= P1.getY()));
    }

    @Test
    public void test_RndPointPB() {
        Point P1 = RandomGenerator.getInstance().getNextPointPB(5,5);
        Point P2 = RandomGenerator.getInstance().getNextPointPB(5,5);
        Point P3 = RandomGenerator.getInstance().getNextPointPB(5,5);
        assertTrue("Angka tidak ter-Random", (P1.getX()!=P2.getX() || P1.getX()!= P3.getX() || P2.getX()!=P3.getX() ||
                P1.getY()!=P2.getY() || P2.getY()!= P3.getY() || P3.getY()!= P1.getY()));
    }
}