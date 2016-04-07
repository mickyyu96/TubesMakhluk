package world;

import makhluk.*;
import org.junit.Test;
import static org.junit.Assert.*;
import randomgenerator.*;

/**
 * Created by Elvina R.K.Situmorang on 4/6/2016.
 */
public class LMakhlukTest {
    @Test
    public void test_LMakhluk() {
        LMakhluk _LMakhluk = new LMakhluk();
        _LMakhluk.addd(new Wolf(RandomGenerator.getInstance().getNextPoint(5, 5)));
        _LMakhluk.add(new Sheep(RandomGenerator.getInstance().getNextPoint(5, 5)));
        _LMakhluk.add(new PolarBear(RandomGenerator.getInstance().getNextPoint(5, 5)));

        char c;
        c = _LMakhluk.getInfo(0).getID();
        System.out.println("Ambil ID first makhluk dalam list : "+c);
        assertTrue("Bukan Wolf",c=='W');

        c= _LMakhluk.getInfo(2).getID();
        System.out.println("Ambil ID first makhluk dalam list : "+c);
        assertTrue("Bukan PolarBear",c=='P');
    }

}
