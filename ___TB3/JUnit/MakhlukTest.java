package makhluk;

import org.junit.Test;
import point.*;
import static org.junit.Assert.*;

/**
 * Created by Elvina R. K. Situmorang on 4/6/2016.
 */
public class MakhlukTest {
    @Test
    public void test_Wolf() {
        Point P = new Point(2,2);
        Wolf W = new Wolf(P);
        assertTrue("ID tidak W",W.getID()=='W');
        assertTrue("Umur salah",W.getAge()==0);
        assertTrue("Power salah", W.getPower()==6);
        assertTrue("MaxAge salah", W.getMaxAge()==180);
        assertTrue("Sudah tidak hidup", W.isAlive()==1);
        assertTrue("Posisi salah", W.getPosition().getX()==2);
        assertTrue("Posisi salah", W.getPosition().getY()==2);
        W.ageIncrement();
        assertTrue("Umur salah",W.getAge()==1);
        P.setX(3);
        P.setY(4);
        W.setPosition(P);
        assertTrue("Posisi salah", W.getPosition().getX()==3);
        assertTrue("Posisi salah", W.getPosition().getY()==4);
        W.kill();
        assertTrue("Masih hidup",W.isAlive()==0);
    }

    @Test
    public void test_Turtle() {
        Point P = new Point();
        Turtle T = new Turtle(P);
        assertTrue("ID tidak T",T.getID()=='T');
        assertTrue("Umur salah",T.getAge()==0);
        assertTrue("Power salah", T.getPower()==2);
        assertTrue("MaxAge salah", T.getMaxAge()==240);
        assertTrue("Sudah tidak hidup", T.isAlive()==1);
        assertTrue("Posisi salah", T.getPosition().getX()==10);
        assertTrue("Posisi salah", T.getPosition().getY()==10);
        T.ageIncrement();
        assertTrue("Umur salah",T.getAge()==1);
        Point Q = new Point(3,4);
        T.setPosition(Q);
        assertTrue("Posisi salah", T.getPosition().getX()==3);
        assertTrue("Posisi salah", T.getPosition().getY()==4);
        T.kill();
        assertTrue("Masih hidup",T.isAlive()==0);
    }

    @Test
    public void test_Snake() {
        Point P = new Point(2,3);
        Snake S = new Snake(P);
        assertTrue("ID tidak S",S.getID()=='U');
        assertTrue("Umur salah",S.getAge()==0);
        assertTrue("Power salah", S.getPower()==5);
        assertTrue("MaxAge salah", S.getMaxAge()==150);
        assertTrue("Sudah tidak hidup", S.isAlive()==1);
        assertTrue("Posisi salah", S.getPosition().getX()==2);
        assertTrue("Posisi salah", S.getPosition().getY()==3);
        S.ageIncrement();
        assertTrue("Umur salah",S.getAge()==1);
        Point Q = new Point(3,4);
        S.setPosition(Q);
        assertTrue("Posisi salah", S.getPosition().getX()==3);
        assertTrue("Posisi salah", S.getPosition().getY()==4);
        S.kill();
        assertTrue("Masih hidup",S.isAlive()==0);
    }

    @Test
    public void test_Sheep() {
        Point P = new Point(4,9);
        Sheep S = new Sheep(P);
        assertTrue("ID tidak S",S.getID()=='S');
        assertTrue("Umur salah",S.getAge()==0);
        assertTrue("Power salah", S.getPower()==4);
        assertTrue("MaxAge salah", S.getMaxAge()==200);
        assertTrue("Sudah tidak hidup", S.isAlive()==1);
        assertTrue("Posisi salah", S.getPosition().getX()==4);
        assertTrue("Posisi salah", S.getPosition().getY()==9);
        S.ageIncrement();
        assertTrue("Umur salah",S.getAge()==1);
        Point Q = new Point(3,4);
        S.setPosition(Q);
        assertTrue("Posisi salah", S.getPosition().getX()==3);
        assertTrue("Posisi salah", S.getPosition().getY()==4);
        S.kill();
        assertTrue("Masih hidup",S.isAlive()==0);
    }

    @Test
    public void test_Rabbit() {
        Point P = new Point(3,5);
        Rabbit R = new Rabbit(P);
        assertTrue("ID tidak S",R.getID()=='R');
        assertTrue("Umur salah",R.getAge()==0);
        assertTrue("Power salah", R.getPower()==3);
        assertTrue("MaxAge salah", R.getMaxAge()==100);
        assertTrue("Sudah tidak hidup", R.isAlive()==1);
        assertTrue("Posisi salah", R.getPosition().getX()==3);
        assertTrue("Posisi salah", R.getPosition().getY()==5);
        R.ageIncrement();
        assertTrue("Umur salah",R.getAge()==1);
        Point Q = new Point(3,4);
        R.setPosition(Q);
        assertTrue("Posisi salah", R.getPosition().getX()==3);
        assertTrue("Posisi salah", R.getPosition().getY()==4);
        R.kill();
        assertTrue("Masih hidup",R.isAlive()==0);
    }

    @Test
    public void test_PolarBear() {
        Point Po = new Point(5,2);
        PolarBear P = new PolarBear(Po);
        assertTrue("ID tidak S",P.getID()=='P');
        assertTrue("Umur salah",P.getAge()==0);
        assertTrue("Power salah", P.getPower()==8);
        assertTrue("MaxAge salah", P.getMaxAge()==250);
        assertTrue("Sudah tidak hidup", P.isAlive()==1);
        assertTrue("Posisi salah", P.getPosition().getX()==5);
        assertTrue("Posisi salah", P.getPosition().getY()==2);
        P.ageIncrement();
        assertTrue("Umur salah",P.getAge()==1);
        Point Q = new Point(3,4);
        P.setPosition(Q);
        assertTrue("Posisi salah", P.getPosition().getX()==3);
        assertTrue("Posisi salah", P.getPosition().getY()==4);
        P.kill();
        assertTrue("Masih hidup",P.isAlive()==0);
    }

    @Test
    public void Tumbuhan() {
        Point Po = new Point(1,4);
        Tumbuhan G = new Tumbuhan(Po);
        assertTrue("ID tidak S",G.getID()=='G');
        assertTrue("Umur salah",G.getAge()==0);
        assertTrue("MaxAge salah", G.getMaxAge()==300);
        assertTrue("Sudah tidak hidup", G.isAlive()==1);
        assertTrue("Posisi salah", G.getPosition().getX()==1);
        assertTrue("Posisi salah", G.getPosition().getY()==4);
        G.ageIncrement();
        assertTrue("Umur salah",G.getAge()==1);
        Point Q = new Point(3,4);
        G.setPosition(Q);
        assertTrue("Posisi salah", G.getPosition().getX()==3);
        assertTrue("Posisi salah", G.getPosition().getY()==4);
        G.kill();
        assertTrue("Masih hidup",G.isAlive()==0);
    }
}
