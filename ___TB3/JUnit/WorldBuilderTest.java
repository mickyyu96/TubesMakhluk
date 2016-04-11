package world;

import exception.*;
import makhluk.*;
import randomgenerator.*;
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

        System.out.println("getStrMakhluk setelah di set : "+WorldBuilder.getBuilderInstance().getStrMakhluk());
        System.out.println();
        System.out.println("Mengeluarkan ID makhluk yang ditambahkan pada LMakhluk pada World: ");
        for(int i = 0; i < World.getWorldInstance().getObjects().getSize(); i++) {
            System.out.println("ID Makhluk "+i+": "+World.getWorldInstance().getObjects().getInfo(i).getID());
        }
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(0).getID()=='W');
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(1).getID()=='S');
        assertTrue("ID Makhluk salah",World.getWorldInstance().getObjects().getInfo(2).getID()=='P');
    }
}
