package point;

public class Point
{
	private int x;
	private int y;
	private static final int DEFAULT_X = 10;
	private static final int DEFAULT_Y = 10;


	public Point()
	{
		x = DEFAULT_X;
		y = DEFAULT_Y;
	}
	public Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	public int  getX() {return x;}
	public int getY() {return y;}
	public void setX(int _x) {x=_x;}
	public void setY(int _y) {x=_y;}
	public void increment(int dx, int dy)
	{
		x+=dx;
		y+=dy;
	}
	public static int getDistance(Point P1, Point P2) 
	{
		int dx = P1.getX() - P2.getX();
		int dy = P1.getY() - P2.getY();
		return (int)Math.sqrt((double)dx*dx+dy*dy);
	}

}