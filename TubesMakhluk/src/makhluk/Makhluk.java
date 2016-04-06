package makhluk;

import point.*;
import world.*;

/** Kelas Makhluk merupakan kelas abstrak yang memiliki member-member
    dasar yang akan diturunkan ke kelas lain.
 *  @author Atika Azzahra Akbar
 *  @version 1.0
 */
public class Makhluk {
    /** Atribut ID Makhluk.
     */
    private final char id;
    /** Atribut umur maksimal Makhluk.
     */
    private final int maxAge;
    /** Atribut umur Makhluk.
     */
    private int age;
    /** Atribut status Makhluk.
     */
    private int status;
    /** Atribut Point posisi Makhluk.
     */
    private Point pos;
    /** Menciptakan sebuah makhluk.
     *  @param idM Makhluk
     *  @param max maksimal Makhluk
     */
    protected Makhluk(final char idM, final int max) {
        id = idM;
        maxAge = max;
    }
    /** Mengambil sebuah karakter ID makhluk.
     *  @return	Karakter ID makhluk
     */
    public final char getID() { return ID; }
    /** Mengambil usia makhluk sekarang
     *   @return Sebuah bilangan bulat yang merupakan usia makhluk sekarang.
     */
    public final int getAge() { return age; }
    /** Mengambil usia maksimum makhluk
     *  @return	Sebuah bilangan bulat yang merupakan usia maksimum makhluk.
     */
    public final int getMaxAge() { return maxAge; }
    /** Mengambil posisi makhluk sekarang
     *  @return	Sebuah tipe bentukan Point yang merupakan posisi makhluk.
     */
    public final Point getPosition() { return pos; }
    /** Melakukan assignment terhadap posisi makhluk dengan posisi baru.
     *  @param P const Point& , sebuah posisi baru makhluk
     *  @return	void
     */
    public void setPosition(final Point p){ pos = p; }
    /** Fungsi validasi untuk mengecek apakah 2 makhluk berada dalam point yang sama.
     *   @return Bilangan bulat 0 atau 1
     */
    public final int isMakhlukInTheSamePoint() {
        int found = 0;
        int i = 0;
        LMakhluk _LMakhluk = World.getWorldInstance().getObjects();
	    while(i<_LMakhluk.getSize() && found==0)
	    {
	        if (_LMakhluk.getInfo(i).isAlive()==1 && _LMakhluk.getInfo(i).getPosition().getX() == getPosition().getX() &&
	            _LMakhluk.getInfo(i).getPosition().getY()==getPosition().getY() && _LMakhluk.getInfo(i).getID() != getID())
	        {
	            found = 1;
	        }
	        else { i++; }
	    }
	    return found;
    }
    /**  Prosedur yang mengembalikan makhluk yang berada pada point yang
         sama dengan objek.
     *   Objek dipastikan bersama dengan makhluk lain pada suatu point.
     *   @return Pointer to makhluk
     */
     public Makhluk MakhlukInTheSamePoint() {
        Makhluk _Makhluk = null;
        int i = 0;
        int found = 0;
        LMakhluk _LMakhluk = World.getWorldInstance().getObjects();
        while(i<_LMakhluk.getSize()&&found==0)
        {
            if (_LMakhluk.getInfo(i).isAlive()==1 && _LMakhluk.getInfo(i).getPosition().getX()==getPosition().getX() && _LMakhluk.getInfo(i).getPosition().getY() == getPosition().getY()&&_LMakhluk.getInfo(i).getID()!=getID())
            {
                _Makhluk = _LMakhluk.getInfo(i);
                found = 1;
            }
            else { i++; }
        }
        return _Makhluk;
    }
    /** Mengambil status ke"hidup"an makhluk.
     *  @return	True apabila makhluk masih hidup
     */
    public int isAlive() { if ( status == 1 ) return 1; else return 0; }
    /** Prosedur yang digunakan untuk membunuh makhluk dari alam semesta, 
        yaitu apabila dimangsa atau terlalu tua.
     *  @return	void
	 */
    public void Kill() { status =  0; }
    /** Prosedur untuk menambah usia objek
     *  @return void
     */
    public void AgeIncrement() { age++; }
}
