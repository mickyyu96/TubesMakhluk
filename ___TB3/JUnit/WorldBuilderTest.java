package world;

import org.junit.Test;
import static org.junit.Assert.*;

/**
 * Created by Elvina R.K. Situmorang on 4/6/2016.
 */
public class WorldBuilderTest {
    @Test
    public void test_WorldBuilder() {
        String input = "WSP";

        WorldBuilder.getBuilderInstance().setStrMakhluk(input);
        WorldBuilder.getBuilderInstance().buildWorldObject();

        assertTrue("getStrMakhluk salah", WorldBuilder.getBuilderInstance().getStrMakhluk()=="WSP");
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(0).getID()=='W');
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(1).getID()=='S');
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(2).getID()=='P');
        
        WorldBuilder.getBuilderInstance().addAnObject('U');
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(3).getID()=='U');
    }
}
