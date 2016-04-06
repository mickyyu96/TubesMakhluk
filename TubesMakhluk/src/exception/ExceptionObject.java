// ExceptionObject.java

package exception;

import javax.swing.JOptionPane;

/** Kelas untuk membantu menangani exception yang muncul dari kesalahan 
 *  masukan pengguna
 *  @author     Micky Yudi Utama / 13514011
 *  @date       April 2016
 *  @version	1.0
 */

public class ExceptionObject extends Exception {
    private int id;
    private final String messages[] = {
        ">> ERROR! Dimensi ukuran dunia harus > 6!",
        ">> ERROR! Ada ID yang tidak dikenali!",
        ">> ERROR! Pause World dulu sebelum melakukan Single-step Execution!",
        ">> ERROR! Keypress tidak dikenali!",
        ">> ERROR! Masukan harus berupa bilangan bulat!"
    };
    
    /** Menciptakan sebuah instance dari kelas ExceptionObject dengan id yang 
     *  di-passing melalui parameter
     *  @param _id int id yang merupakan id kesalahan yang dilakukan
     */
    public ExceptionObject(int _id) {
        id = _id;
    }
    
    /** Menampilkan pesan kesalahan ke sebuah message box berdasarkan id_
     *  kesalahan yang disimpan dalam data member
     */
    public void DisplayErrorMessage() {
        JOptionPane.showMessageDialog(null, messages[id], "", JOptionPane.INFORMATION_MESSAGE);
    }
    
    /** Unit test ExceptionObject
     *  @param args 
     */
    public static void main(String[] args) {
        ExceptionObject E1 = new ExceptionObject(0);
        E1.DisplayErrorMessage();
        ExceptionObject E2 = new ExceptionObject(1);
        E2.DisplayErrorMessage();
        ExceptionObject E3 = new ExceptionObject(2);
        E3.DisplayErrorMessage();
        ExceptionObject E4 = new ExceptionObject(3);
        E4.DisplayErrorMessage();
        ExceptionObject E5 = new ExceptionObject(4);
        E5.DisplayErrorMessage();
    }
}
