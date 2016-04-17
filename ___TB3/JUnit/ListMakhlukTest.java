package world;

import makhluk.*;
import org.junit.Test;
import static org.junit.Assert.*;
import randomgenerator.*;

/**
 * Created by Elvina R.K.Situmorang on 4/6/2016.
 */
public class ListMakhlukTest {
    @Test
    public void test_ListMakhluk() {
        ListMakhluk _LMakhluk = new ListMakhluk();
        assertTrue("List tidak kosong", _LMakhluk.isEmpty()==1);
        _LMakhluk.add(new Wolf(RandomGenerator.getInstance().getNextPoint(5, 5)));
        _LMakhluk.add(new Sheep(RandomGenerator.getInstance().getNextPoint(5, 5)));
        _LMakhluk.add(new PolarBear(RandomGenerator.getInstance().getNextPoint(5, 5)));
        assertTrue("Ukuran salah", _LMakhluk.getSize()==3);

        assertTrue("Bukan Wolf",_LMakhluk.getInfo(0).getID()=='W');
        assertTrue("Bukan PolarBear",_LMakhluk.getInfo(2).getID()=='P');

        assertTrue("Jumlah makhluk salah", _LMakhluk.countMakhluk('W')==1);
        assertTrue("Jumlah makhluk salah", _LMakhluk.countMakhluk('S')==1);
        assertTrue("Jumlah makhluk salah", _LMakhluk.countMakhluk('P')==1);

        _LMakhluk.getInfo(0).kill();
        _LMakhluk.getInfo(1).kill();
        _LMakhluk.getInfo(2).kill();
        assertTrue("semua makhluk masih hidup", _LMakhluk.isAllMakhlukDead());
    }
}
