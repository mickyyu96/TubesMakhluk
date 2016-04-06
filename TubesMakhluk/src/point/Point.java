//Point.java

package point;

/** Kelas Point menangani berbagai hal yang berhubungan dengan
 *	Point. Kelas ini juga digukan dalam pembuatan World dengan
 *	hubungan asosiatif
 *	@author     Elvina R. K. Situmorang
 *	@date       April 2016
 *	@version    1.0
 */

public class Point
{
	private int x;
	private int y;
	private static final int DEFAULT_X = 10;
	private static final int DEFAULT_Y = 10;


	/** Konstruktor Point
	 */
	public Point() {
		x = DEFAULT_X;
		y = DEFAULT_Y;
	}
	/** Konstruktor Point dengan parameter
	 *	@param 	int _x yang akan di assign menjadi x
	 *	@param 	int _y yang akan di assign menjadi y
	 */
	public Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	/**	Mengembalikan nilai x
	 *	@return int x pada sebuah point
	 */
	public int  getX() {
		return x;
	}
	/**	Mengembalikan nilai y
	 *	@return int y pada sebuah point
	 */
	public int getY() {
		return y;
    }
	/**	Melaukan assignment terhadap nilai x sebauh Point
	 *	@param 	int _x yang akan di assign menjadi x
	 *	@return void
	 */
	public void setX(int _x) {
		x=_x;
    }
	/**	Melaukan assignment terhadap nilai y sebauh Point
	 *	@param 	int _y yang akan di assign menjadi xy
	 *	@return void
	 */
	public void setY(int _y) {
		x=_y;
    }
	/** Melakukan penambahan terhadap nilai x dan y pada sebuah Point
	 *	@param 	int dx menjadi delta penambahan x sebuah Point
	 *	@param 	int dy menjadi delta penambahan y sebuah Point
	 *	@return	void
	 */
	public void increment(int dx, int dy) {
		x+=dx;
		y+=dy;
	}
	/** Mengembalikan jarak antara 2 titik (2 Point)
	 * 	@param 	Point P1 berupa titik pertama
	 *	@param 	Point P2 berupa titik kedua
	 *	@return int hasil Jarak 2 titik
	 */
	public static int getDistance(Point P1, Point P2) {
		int dx = P1.getX() - P2.getX();
		int dy = P1.getY() - P2.getY();
		return (int)Math.sqrt((double)dx*dx+dy*dy);
	}
}