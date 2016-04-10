package randomgenerator;

import org.junit.Test;

import static org.junit.Assert.*;
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
}
