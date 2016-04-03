public class MakhlukLive
{
	private static MakhlukLive _instance;
	
	private MakhlukLive() {}
	public static MakhlukLive getInstance() {return _instance;}
	public void MakhlukMove()
	{
		int dx, dy;
		LMakhluk _LMakhluk = new LMakhluk();
		LMakhluk _LMakhluk = worldInstance.getObjects;

		for (int i = 0; i<_LMakhluk.getSize(); i++)
	    {
	        if (_LMakhluk.getInfo(i).isAlive() && _LMakhluk.getInfo(i).getID()!='G')
	        {
	            Hewan _Hewan = new Hewan(_LMakhluk.getInfo(i));

	            dx = getInstance().getNextInt(2)*dx_sign;
	            dy = getInstance().getNextInt(2)*dy_sign;

	            if (_Hewan.shouldRebounced(dx, 0))
	            {
	                dx *= -1;
	                dx_sign *= -1;
	            }
	            if (_Hewan.shouldRebounced(0, dy))
	            {
	                dy *= -1;
	                dy_sign *= -1;
	            }

	            _Hewan.Move(dx, dy);
	            _Hewan.AgeIncrement();
	            if(_Hewan.getAge()==_Hewan.getMaxAge())
	            {
	                _Hewan.Kill();
	            }
	        }
	        else
	        {
	            _LMakhluk.getInfo(i).AgeIncrement();
	            if(_LMakhluk.getInfo(i).getAge()==_LMakhluk.getInfo(i).getMaxAge())
	            {
	                _LMakhluk.getInfo(i).Kill();
	            }
	        }
	    }
	}
	public void MakhlukEat()
	{
		World worldInstance = super.getWorldInstance();

		LMakhluk _LMakhluk = worldInstance.getObjects;

		for (int i = 0; i<_LMakhluk.getSize(); i++) {
	        if (_LMakhluk.getInfo(i).isAlive() && _LMakhluk.getInfo(i).getID()!='G')
	        {
	            if (_LMakhluk.getInfo(i).isMakhlukInTheSamePoint())
	            {
	                Makhluk M1 = new Makhluk();
	                M1 = _LMakhluk.getInfo(i);
	                Makhluk M2 = new Makhluk();
	                M2 = _LMakhluk.getInfo(i).MakhlukInTheSamePoint();
	                if (((M1).getID()=='R')||((M1).getID()=='T')||((M1).getID()=='S'))
	                {
	                    if ((M2).getID()=='G')
	                    {
	                        M2.Kill();
	                    }
	                }
	                else
	                {
	                    if (M2.getID()!='G')
	                    {
	                        if (((Hewan)M2).getPower()<((Hewan) M1).getPower())
	                        {
	                            M2.Kill();
	                        }
	                    }
	                }
	            }
	        }
    	}		
	}
}