package makhluk;

import point.*;

/** Kelas turunan dari Hewan yang merepresentasikan seekor polar bear
 *	@author     Atika Azzahra Akbar
 *	@date       April 2016
 *	@version	1.0
 */
 
public class PolarBear extends Hewan {
	private static final char POLARBEAR_ID = 'P'; 
	private static final int POLARBEAR_MAXAGE = 250;    
	private static final int POLARBEAR_BASEPOWER = 8;
	
	/** Menciptakan objek PolarBear dengan posisi P
	 *  @param      P Point Posisi objek PolarBear
	 */
	public PolarBear(Point P){
		super(POLARBEAR_ID, POLARBEAR_MAXAGE);
		age = 0;
		status = 1;
		power = POLARBEAR_BASEPOWER;
		pos = P;
		
	}
}
