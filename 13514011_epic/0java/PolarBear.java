
public class PolarBear extends Hewan {
	private static final char POLARBEAR_ID = 'P'; 
	private static final int POLARBEAR_MAXAGE = 250;    
	private static final int POLARBEAR_BASEPOWER = 8;
	
	/** Menciptakan objek PolarBear dengan posisi P
	 *  @param      P const Point& Posisi objek PolarBear
	 */
	public PolarBear(){
		super(POLARBEAR_ID, POLARBEAR_MAXAGE);
		
	}
}
