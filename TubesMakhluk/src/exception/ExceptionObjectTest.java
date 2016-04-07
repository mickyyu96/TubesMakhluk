/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exception;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Elvina R. K. Situmorang
 */
public class ExceptionObjectTest {
        @Test
        public void test_DisplayErrorMsg() {
            System.out.println("Tes apakah Pesan Error benar atau tidak");
            ExceptionObject E1 = new ExceptionObject(0);
            assertEquals(">> ERROR! Dimensi ukuran dunia harus > 6!",E1.getMessage());
            ExceptionObject E2 = new ExceptionObject(1);
            assertEquals(">> ERROR! Ada ID yang tidak dikenali!",E2.getMessage());
            ExceptionObject E3 = new ExceptionObject(2);
            assertEquals(">> ERROR! Pause World dulu sebelum melakukan Single-step Execution!",E3.GetMessage());
            ExceptionObject E4 = new ExceptionObject(3);
            assertEquals(">> ERROR! Keypress tidak dikenali!",E4.getMessage());
            ExceptionObject E5 = new ExceptionObject(4);
            assertEquals(">> ERROR! Masukan harus berupa bilangan bulat!", E5.getMessage());
        }
}
