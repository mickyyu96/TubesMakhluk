public class Hewan extends Makhluk
{
	protected int hungerLvl, power, deltaT;

	protected Hewan (char _ID, int _maxAge) {super(_ID,_maxAge);}
	public void Move (int dx, int dy)
	{
		pos.increment(dx, dy);
	}
	int getPower() {return power;}
	int shouldRebounced(int dx, int dy)
	{
		 if (dx+pos.getX()<=0 || dx+pos.getX()>=getWorldInstance().getNBrs()-1)
	    {
	        return 1;
	    }
	    if (dy+pos.getY()<=0 || dy+pos.getY()>=getWorldInstance().getNKol()-1)
	    {
	        return 1;
	    }
	    return 0;
	}
}