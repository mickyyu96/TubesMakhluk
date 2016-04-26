package point;

/** Kelas Point menangani berbagai hal yang berhubungan dengan
 *  Point. Kelas ini juga digukan dalam pembuatan World dengan
 *  hubungan asosiatif.
 *  @author  Elvina R. K. Situmorang / 13514045
 *  @version 1.0
 */
public class Point {
    /** Atribut point x.
     */
    private int x;
    /** Atribut point y.
     */
    private int y;
    /** Atribut default_x.
     */
    private static final int DEFAULT_X = 10;
    /** Atribut default_y.
     */
    private static final int DEFAULT_Y = 10;
    /** Konstruktor Point.
     */
    public Point() {
        x = DEFAULT_X;
        y = DEFAULT_Y;
     }
    /** Konstruktor Point dengan parameter.
     *  @param x1 yang akan di assign
     *  @param y1 yang akan di assign
     */
    public Point(final int x1, final int y1) {
        x = x1;
        y = y1;
     }
    /** Copy Constructor Point.
     *  @param p Point yang akan dicopy
     */
    public Point(final Point p) {
        x = p.getX();
        y = p.getY();
     }
    /** Mengembalikan nilai x.
     * @return int x pada sebuah point
     */
    public final int  getX() {
        return x;
     }
    /** Mengembalikan nilai y.
     *  @return int y pada sebuah point
     */
    public final int getY() {
        return y;
    }
    /** Melakukan assignment terhadap nilai x sebauh Point.
     * @param x1 yang akan di assign menjadi x
     */
    public final void setX(final int x1) {
        x = x1;
    }
    /** Melakukan assignment terhadap nilai y sebauh Point.
     *  @param y1 yang akan di assign menjadi xy
     */
    public final void setY(final int y1) {
        y = y1;
    }
    /** Melakukan penambahan terhadap nilai x dan y pada sebuah Point.
     *  @param dx menjadi delta penambahan x sebuah Point
     *  @param dy menjadi delta penambahan y sebuah Point
     */
    public final void increment(final int dx, final int dy) {
        x += dx;
        y += dy;
    }
    /** Mengembalikan jarak antara 2 titik (2 Point).
     *  @param p1 berupa titik pertama
     *  @param p2 berupa titik kedua
     *  @return int hasil Jarak 2 titik
     */
    public static int getDistance(final Point p1, final Point p2) {
        int dx = p1.getX() - p2.getX();
        int dy = p1.getY() - p2.getY();
        return (int) Math.sqrt((double) dx * dx + dy * dy);
    }
}
