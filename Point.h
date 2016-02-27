// Point.h

class Point {
	public :
		// ctor, cctor (dtor dan op= menggunakan default)
		Point();
		Point(const Point&);
		
		// getter setter
		int getX() { return x; }
		int getY() { return y; }
		void setX(int _x) { x = _x; }
		void setY(int _y) { y = _y; }
		
	private :
		int x, y;	
};
