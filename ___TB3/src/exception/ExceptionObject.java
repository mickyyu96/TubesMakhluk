package exception;

import javax.swing.JOptionPane;

/** Kelas untuk membantu menangani exception yang muncul dari kesalahan
 *  masukan pengguna.
 *  @author  Micky Yudi Utama / 13514011
 *  @version 1.0
 */
public class ExceptionObject extends Exception {
    /** Atribut id exception.
     */
    private int id;
    /** Array of string berisi messages.
     */
    private final String[] messages = new String[] {
        ">> ERROR! Dimensi ukuran dunia harus > 6!",
        ">> ERROR! Ada ID yang tidak dikenali!",
        ">> ERROR! Pause World dulu sebelum melakukan Single-step Execution!",
        ">> ERROR! Keypress tidak dikenali!",
        ">> ERROR! Masukan harus berupa bilangan bulat!"
    };
    /** Getter message, mengeluarkan message dari sebuah
        exception.ExceptionObject.ExceptionObject.
     *  @return string berupa message ke-id dari object
     */
    public final String getMessage() {
        return messages[this.id];
    }
    /** Menciptakan sebuah instance dari kelas ExceptionObject dengan id yang
     *  di-passing melalui parameter.
     *  @param id1 int id yang merupakan id kesalahan yang dilakukan
     */
    public ExceptionObject(final int id1) {
        id = id1;
    }
    /** Menampilkan pesan kesalahan ke sebuah message box berdasarkan id
     *  kesalahan yang disimpan dalam data member.
     */
    public final void displayErrorMessage() {
        JOptionPane.showMessageDialog(null, messages[id], "",
        JOptionPane.INFORMATION_MESSAGE);
    }
}
