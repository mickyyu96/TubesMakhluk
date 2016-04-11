package world;

import point.Point;
import exception.ExceptionObject;
import randomgenerator.RandomGenerator;

/** Kelas WorldBuilder merupakan BUILDER dari kelas World dan bertanggung
 *  jawab untuk melakukan inisialisasi objek-objek dunia.
 *  @author  Atika Azzahra Akbar / 13514077
 *  @version 1.0
 */
public final class WorldBuilder {
    /** Atribut instance worldbuilder.
     */
    private static WorldBuilder builderInstance = new WorldBuilder();
    /** Atribut string makhluk.
     */
    private String strMakhluk;
    /** Menciptakan sebuah instance WorldBuilder.
     */
    private WorldBuilder() {
    }
    /** Mengembalikan pointer dari objek singleton pada kelas WorldBuilder.
     * @return Pointer yang menunjuk ke singleton instance pada
     * kelas WorldBuilder
     */
    public static WorldBuilder getBuilderInstance() {
        return builderInstance;
    }
    /** Mengembalikan sebuah string yang tersimpan dalam instance WorldBuilder
     * yang merupakan karakter-karakter makhluk yang akan diciptakan.
     * @return String yang berisi karakter-karakter makhluk yang akan diciptakan
     */
    public String getStrMakhluk() {
        return strMakhluk;
    }
    /** Melakukan assignment string yang tersimpan dalam instance WorldBuilder
     * dengan string baru yang di-passing melalui parameter.
     * @param str const string& String baru yang akan di-assign
     */
    public void setStrMakhluk(final String str) {
        strMakhluk = str;
    }
    /** Menambahkan sebuah objek ke dalam container objek di dunia berdasarkan
     * ID karakter makhluk yang di-passing melalui parameter.
     * @param id char Karakter yang merupakan ID makhluk yang akan ditambahkan
     */
    public void addAnObject(final char id) {
        int nBrs1 = World.getWorldInstance().getNBrs();
        int nKol1 = World.getWorldInstance().getNKol();
        RandomGenerator rnd = RandomGenerator.getInstance();
        Point p = rnd.getNextPoint(nBrs1, nKol1);
        switch (id) {
            case 'G':
                World.getWorldInstance().getObjects().add(new Tumbuhan(p));
                break;
            case 'R':
                World.getWorldInstance().getObjects().add(new Rabbit(p));
            case 'T':
                World.getWorldInstance().getObjects().add(new Turtle(p));
                break;
            case 'W':
                World.getWorldInstance().getObjects().add(new Wolf(p));
                break;
            case 'S':
                World.getWorldInstance().getObjects().add(new Sheep(p));
                break;
            case 'P':
                World.getWorldInstance().getObjects().add(new PolarBear(p));
                break;
            case 'U':
                World.getWorldInstance().getObjects().add(new Snake(p));
                break;
            default :
                final int num = 3;
                ExceptionObject e = new ExceptionObject(num);
                e.displayErrorMessage();
        }
   }
    /** Melakukan inisialisasi list of makhluk pada objek singleton kelas World.
     * berdasarkan string yang tersimpan dalam instance WorldBuilder.
     */
    public void buildWorldObject() {
        int numOfObjects = getStrMakhluk().length();
        for (int i = 0; i < numOfObjects; i++) {
            char c = getStrMakhluk().charAt(i);
            addAnObject(c);
        }
    }
}
