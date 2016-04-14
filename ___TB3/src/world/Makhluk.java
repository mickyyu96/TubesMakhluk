package world;

import point.Point;

/** Kelas Makhluk merupakan kelas abstrak yang memiliki member-member
    dasar yang akan diturunkan ke kelas lain.
 *  @author Atika Azzahra Akbar / 13514077
 *  @version 1.0
 */
public abstract class Makhluk {
    /** Atribut ID Makhluk.
     */
    protected final char id;
    /** Atribut umur maksimal Makhluk.
     */
    protected final int maxAge;
    /** Atribut umur Makhluk.
     */
    protected int age;
    /** Atribut status Makhluk.
     */
    protected int status;
    /** Atribut Point posisi Makhluk.
     */
    protected Point pos;
    /** Menciptakan sebuah makhluk.
     *  @param idM Makhluk
     *  @param max maksimal Makhluk
     */
    protected Makhluk(final char idM, final int max) {
        id = idM;
        maxAge = max;
    }
    /** Mengambil sebuah karakter ID makhluk.
     *  @return Karakter ID makhluk
     */
    public final char getID() {
        return id; }
    /** Mengambil usia makhluk sekarang.
     *   @return Sebuah bilangan bulat yang merupakan usia makhluk sekarang.
     */
    public final int getAge() {
        return age; }
    /** Mengambil usia maksimum makhluk.
     *  @return Sebuah bilangan bulat yang merupakan usia maksimum makhluk.
     */
    public final int getMaxAge() {
        return maxAge; }
    /** Mengambil posisi makhluk sekarang.
     *  @return Sebuah tipe bentukan Point yang merupakan posisi makhluk.
     */
    public final Point getPosition() {
        return pos; }
    /** Melakukan assignment terhadap posisi makhluk dengan posisi baru.
     *  @param p sebuah posisi baru makhluk
     */
    public final void setPosition(final Point p) {
        pos = p; }
    /** Fungsi validasi untuk mengecek apakah 2 makhluk berada dalam
        point yang sama.
     *  @return Bilangan bulat 0 atau 1
     */
    public final int isMakhlukInTheSamePoint() {
        int found = 0;
        int i = 0;
        ListMakhluk lMakhluk = World.getWorldInstance().getObjects();
        while (i < lMakhluk.getSize() && found == 0) {
            if (lMakhluk.getInfo(i).isAlive() == 1
                  && lMakhluk.getInfo(i).getPosition().getX()
                  == getPosition().getX()
                  && lMakhluk.getInfo(i).getPosition().getY()
                  == getPosition().getY() && lMakhluk.getInfo(i).getID()
                  != getID()) {
                found = 1;
            } else {
                i++;
            }
        }
        return found;
    }
    /**  Prosedur yang mengembalikan makhluk yang berada pada point yang
         sama dengan objek.
     *   Objek dipastikan bersama dengan makhluk lain pada suatu point.
     *   @return Pointer to makhluk
     */
     public final Makhluk makhlukInTheSamePoint() {
        Makhluk makhluk = null;
        int i = 0;
        int found = 0;
        ListMakhluk lMakhluk = World.getWorldInstance().getObjects();
        while (i < lMakhluk.getSize() && found == 0) {
            if (lMakhluk.getInfo(i).isAlive() == 1
                  && lMakhluk.getInfo(i).getPosition().getX()
                  == getPosition().getX()
                  && lMakhluk.getInfo(i).getPosition().getY()
                  == getPosition().getY() && lMakhluk.getInfo(i).getID()
                  != getID()) {
                makhluk = lMakhluk.getInfo(i);
                found = 1;
            } else {
                i++;
            }
        }
        return makhluk;
    }
     /** Fungsi validasi untuk mengecek apakah kepala ular dan bagian tubuhnya
      *  berada pada posisi yang sama.
      *  @return Bilangan bulat 0 atau 1
      */
    public final int isSnakeBodyInTheSamePoint() {
        int found = 0;
        int i = 1;
        ListMakhluk snakes = World.getWorldInstance().getSnakes();
        while (i < snakes.getSize() && found == 0) {
            if (snakes.getInfo(i).getPosition().getX() == getPosition().getX()
            && snakes.getInfo(i).getPosition().getY() == getPosition().getY()) {
                found = 1;
            } else {
                i++;
            }
        }
        return found;
    }
    /** Mengambil status ke"hidup"an makhluk.
     *  @return True apabila makhluk masih hidup
     */
    public final int isAlive() {
        if (status == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    /** Prosedur yang digunakan untuk membunuh makhluk dari alam semesta,
        yaitu apabila dimangsa atau terlalu tua.
    */
    public final void kill() {
        status =  0; }
    /** Prosedur untuk menambah usia objek.
     */
    public final void ageIncrement() {
        age++; }
}
