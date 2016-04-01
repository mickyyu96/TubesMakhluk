public class Makhluk {
	protected final char ID;     
	protected final int maxAge;   
	protected int age;          
	protected int status;			
	protected Point pos;
	
	/** Menciptakan sebuah makhluk
	 */
	protected Makhluk(char C, int A){
		ID = C;
		maxAge = A;
	}
	
	/** Mengambil sebuah karakter ID makhluk
	*	@return		Karakter ID makhluk
	*/
	public final char getID() { return ID; }
	
	/** Mengambil usia makhluk sekarang
	*	@return		Sebuah bilangan bulat yang merupakan usia makhluk sekarang
	*/
	public final int getAge() { return age; }
	
	/** Mengambil usia maksimum makhluk
	*	@return		Sebuah bilangan bulat yang merupakan usia maksimum makhluk
	*/
	public final int getMaxAge() { return maxAge; }
	
	/** Mengambil posisi makhluk sekarang
	*	@return		Sebuah tipe bentukan Point yang merupakan posisi makhluk
	*/
	public final Point getPosition() { return pos; }
	
	/** Melakukan assignment terhadap posisi makhluk dengan posisi baru
	*	@param		P const Point& , sebuah posisi baru makhluk
	*	@return		void
	*/
	public void setPosition(final Point P){ pos = P; }
	
	/** \brief      Fungsi validasi
	*	\details    Fungsi untuk mengecek apakah 2 makhluk berada dalam point yang sama
	*	\return     Bilangan bulat 0 atau 1
	*/
	public int isMakhlkukInTheSamePoint(){
		int found = 0;
	    int i = 0;
	    LMakhluk _LMakhluk = new LMakhluk();
	    LMakhluk _LMakhluk = worldInstance.getObjects();

	    while(i<_LMakhluk.getSize() && !found)
	    {
	        if (_LMakhluk.getInfo(i).isAlive() && _LMakhluk.getInfo(i).getPosition().getX() == getPosition().getX() &&
	            _LMakhluk.getInfo(i).getPosition().getY()==getPosition().getY() && _LMakhluk.getInfo(i).getID() != getID())
	        {
	            found = 1;
	        }
	        else { i++; }
	    }
	    return found;
	}
	
	/** Fungsi validasi untuk mengecek apakah 2 makhluk berada dalam point yang sama
	*	@return     Bilangan bulat 0 atau 1
	*/
	public Makhluk MakhlukInTheSamePoint(){
		Makhluk _Makhluk;
	    int i = 0;
	    int found = 0;
	    LMakhluk _LMakhluk = new LMakhluk();
	    LMakhluk _LMakhluk = worldInstance.getObjects();

	    while(i<_LMakhluk.getSize()&&!found)
	    {
	        if (_LMakhluk.getInfo(i).isAlive() && _LMakhluk.getInfo(i).getPosition().getX()==getPosition().getX() &&
	            _LMakhluk.getInfo(i).getPosition().getY() == getPosition().getY()&&_LMakhluk.getInfo(i).getID()!=getID())
	        {
	            _Makhluk = _LMakhluk.getInfo(i);
	            found = 1;
	        }
	        else { i++; }
	    }
	    return _Makhluk;
	}
	
	/** Mengambil status ke"hidup"an makhluk
	*	@return		True apabila makhluk masih hidup
	*/
	public int isAlive() { if ( status == 1 ) return 1; else return 0; }
	
	/** Prosedur yang digunakan untuk membunuh makhluk dari alam semesta, yaitu apabila
	*				dimangsa atau terlalu tua
	*	@return		void
	*/
	public void Kill() { status =  0; }
	
	/** Prosedur untuk menambah usia objek
	*	@return     void
	*/
	public void AgeIncrement() { age++; }
}