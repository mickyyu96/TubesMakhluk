package tubesmakhluk;

// ExceptionObject.java

import javax.swing.JOptionPane;

/** Kelas untuk membantu menangani exception yang muncul dari kesalahan 
 *  masukan pengguna
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

class ExceptionObject extends Exception {
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
     *  @return void
     */
    public void DisplayErrorMessage() {
        JOptionPane.showMessageDialog(null, messages[id], "", JOptionPane.INFORMATION_MESSAGE);
    }
}
