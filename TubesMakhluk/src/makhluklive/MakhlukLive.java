//MakhlukLive.java

package makhluklive;

import makhluk.*;
import randomgenerator.*;
import world.*;

/** Kelas MakhlukLive merupakan kelas yang menangani kehidupan dari setiap makhluk
 *	Kehidupan yaitu pergerakan, pencarian makan, dan umur hidup 
 *	@author     Elvina R. K. Situmorang / 13514045
 *	@version    1.0
 */
public class MakhlukLive
{
	private static MakhlukLive _instance = new MakhlukLive();
	private int dx_sign = 1;
	private int dy_sign = 1;
	/** Konstruktor menciptakan MakhlukLive
	 */
	private MakhlukLive() {
    }
	/** Mengembalikan pointer dari objek kelas singleton pada kelas MakhlukLive
	 *	@return	Pointer yang menunjuk ke singleton instance pada kelas MakhlukLive
	 */
	public static MakhlukLive getInstance() {
        return _instance;
    }
	/** Menangani pergerakan dari makhluk
	 *  @return  void
	 */
	public void MakhlukMove() {
		int dx, dy;
		LMakhluk _LMakhluk = World.getWorldInstance().getObjects();

		for (int i = 0; i<_LMakhluk.getSize(); i++) {
	        if (_LMakhluk.getInfo(i).isAlive()==1 && _LMakhluk.getInfo(i).getID()!='G') {
	            Hewan _Hewan = (Hewan)_LMakhluk.getInfo(i);

	            dx = RandomGenerator.getInstance().getNextInt(2)*dx_sign;
	            dy = RandomGenerator.getInstance().getNextInt(2)*dy_sign;

	            if (_Hewan.shouldRebounced(dx, 0)) {
	                dx *= -1;
	                dx_sign *= -1;
	            }
	            if (_Hewan.shouldRebounced(0, dy)) {
	                dy *= -1;
	                dy_sign *= -1;
	            }

	            _Hewan.Move(dx, dy);
	            _Hewan.ageIncrement();
	            if(_Hewan.getAge()==_Hewan.getMaxAge()) {
	                _Hewan.kill();
	            }
	        }
	        else {
	            _LMakhluk.getInfo(i).ageIncrement();
	            if(_LMakhluk.getInfo(i).getAge()==_LMakhluk.getInfo(i).getMaxAge()) {
	                _LMakhluk.getInfo(i).kill();
	            }
	        }
	    }
	}
	/** Menangani pergerakan dari makhluk untuk mencari makan
	 *  @return  void
	 */
	public void MakhlukEat(){
		World worldInstance = World.getWorldInstance();

		LMakhluk _LMakhluk = worldInstance.getObjects();

		for (int i = 0; i<_LMakhluk.getSize(); i++) {
	        if (_LMakhluk.getInfo(i).isAlive() == 1 && _LMakhluk.getInfo(i).getID()!='G') {
	            if (_LMakhluk.getInfo(i).isMakhlukInTheSamePoint() == 1){
	                Makhluk M1 = _LMakhluk.getInfo(i);
	                Makhluk M2 = _LMakhluk.getInfo(i).makhlukInTheSamePoint();
	                if (((M1).getID()=='R')||((M1).getID()=='T')||((M1).getID()=='S')) {
	                    if ((M2).getID()=='G'){
	                        M2.kill();
	                    }
	                }
	                else {
	                    if (M2.getID()!='G') {
	                        if (((Hewan)M2).getPower()<((Hewan) M1).getPower()) {
	                            M2.kill();
	                        }
	                    }
	                }
	            }
	        }
    	}		
	}
}