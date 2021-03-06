package world;

/** Kelas World merepresentasikan alam semesta yang terdiri dari
 *  sebuah "ruang" (space) fiktif yang memiliki dimensi panjang dan lebar
 *  dan sekumpulan makhluk-makhluk (objects) yang bisa bergerak secara
 *  independen.
 *  @author    Elvina R. K. Situmorang / 13514045
 *  @version   1.0
 */
public final class World {
    /** Atribut isEnded.
     */
    private int isEnded;
    /** Atribut isPaused.
     */
    private int isPaused;
    /** Atribut default nBrs.
     */
    private static final int DEFAULTNBRS = 30;
    /** Atribut default nKol.
     */
    private static final int DEFAULTNKOL = 30;
    /** Menciptakan sebuah instance world.
     */
    private static World worldInstance = new World(DEFAULTNBRS, DEFAULTNKOL);
    /** Atribut class world jumlah baris.
     */
    private int nBrs;
    /** Atribut class world jumlah kolom.
     */
    private int nKol;
    /** Atribut list makhluk.
     */
    private LMakhluk objects;
    /** Konstruktor World berparameter. Menangani pembentukan world dan
     * hal-hal yang berkaitan dengan keberjalanan world.
     * @param  nBrs1 berupa ukuran baris world
     * @param  nKol1 berupa ukuran kolom world
     */
    private World(final int nBrs1, final int nKol1) {
        nBrs = nBrs1;
        nKol = nKol1;
        isPaused = 0;
        isEnded = 0;
        objects = new LMakhluk();
    }
    /** Mengembalikan makhluk (object) yang ada di world.
     * @return LMakhluk makhluk yang ada pada world
     */
    public LMakhluk getObjects() {
        return objects;
    }
    /** Pointer untuk mengembalikan worldInstance.
     * @return World
     */
    public static World getWorldInstance() {
        return worldInstance;
     }
    /** Mengembalikan jumlah baris world.
     *  @return nBrs, jumlah baris World
     */
    public int getNBrs() {
        return nBrs;
    }
    /** Mengembalikan jumlah kolom world.
     * @return nKol, jumlah kolom World
     */
    public int getNKol() {
        return nKol;
     }
    /** Melakukan assignment jumlah baris world.
     * @param nBrs1 jumlah baris yang akan di-assign
     */
    public void setNBrs(final int nBrs1) {
        nBrs = nBrs1;
    }
    /** Melakukan assignment jumlah kolom world.
     * @param nKol1 jumlah kolom yang akan di-assign
     */
    public void setNKol(final int nKol1) {
        nKol = nKol1;
    }
    /** Mengembalikan apakah program sudah selesai atau  belum.
     *  @return int sesuai dengan attribute isEnded
     */
    public int isEnded() {
        return isEnded;
    }
    /** Mengembalikan apakah program sedang di-pause oleh user atau tidak.
     * @return int sesuai dengan attribute isPaused
     */
    public int isPaused() {
        return isPaused;
    }
    /** Untuk mengubah state bahwa program harus berhenti.
     */
    public void endWorld() {
        isEnded = 1;
    }
    /** Untuk mengubah state bahwa program sedang di-pause.
     */
    public void changePauseState() {
        isPaused ^= 1;
    }
}
