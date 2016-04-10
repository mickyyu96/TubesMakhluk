package inputoutput;

import matrix.Matrix;
import point.Point;
import world.LMakhluk;
import world.World;

/** Kelas IOManager bertanggung jawab untuk melakukan
 *  operasi-operasi Input/Output.
 *  @author  Micky Yudi Utama
 *  @version 1.0
 */
class IOManager {
    /** Mencetak sebuah matriks ke layar.
     *  @param m final Matrix yang merupakan objek matriks
     */
    public void printMatrix(final Matrix m) {
        for (int i = 0; i < m.getnBrs(); i++) {
            for (int j = 0; j < m.getnKol(); j++) {
                System.out.print(m.getInfo(i, j));
            }
            System.out.println();
        }
    }
    /** Mencetak state dunia saat ini beserta isi dari dunia.
     */
    public void printWorldMap() {
        final int num = 30;
        for (int i = 0; i < num; i++) {
            System.out.println();
        }
        World worldInstance = World.getWorldInstance();
        int nBrs1 = worldInstance.getNBrs();
        int nKol1 = worldInstance.getNKol();
        Matrix map = new Matrix(nBrs1, nKol1);
        LMakhluk lMakhluk = worldInstance.getObjects();
        for (int i = 0; i < lMakhluk.getSize(); i++) {
            if (lMakhluk.getInfo(i).isAlive() == 1) {
                char id1 = lMakhluk.getInfo(i).getID();
                Point pos1 = lMakhluk.getInfo(i).getPosition();
                map.setInfo(id1, pos1.getX(), pos1.getY());
            }
        }
        printMatrix(map);
    }
    /** Mengambil string state dunia dan mengkonversinya dalam format
     *  HTML string.
     *  @return String state dunia dalam format HTML string
     */
    public String getHTMLStrWorldMap() {
        World worldInstance = World.getWorldInstance();
        int nBrs1 = worldInstance.getNBrs();
        int nKol1 = worldInstance.getNKol();
        Matrix map = new Matrix(nBrs1, nKol1);
        LMakhluk lMakhluk = worldInstance.getObjects();
        for (int i = 0; i < lMakhluk.getSize(); i++) {
            if (lMakhluk.getInfo(i).isAlive() == 1) {
                char id1 = lMakhluk.getInfo(i).getID();
                Point pos1 = lMakhluk.getInfo(i).getPosition();
                map.setInfo(id1, pos1.getX(), pos1.getY());
            }
        }
        return map.toHTMLString();
    }
    /** Mengambil string state dunia.
     *  @return String state dunia
     */
    public String getStrWorldMap() {
        World worldInstance = World.getWorldInstance();
        int nBrs1 = worldInstance.getNBrs();
        int nKol1 = worldInstance.getNKol();
        Matrix map = new Matrix(nBrs1, nKol1);
        LMakhluk lMakhluk = worldInstance.getObjects();
        for (int i = 0; i < lMakhluk.getSize(); i++) {
            if (lMakhluk.getInfo(i).isAlive() == 1) {
                char id1 = lMakhluk.getInfo(i).getID();
                Point pos1 = lMakhluk.getInfo(i).getPosition();
                map.setInfo(id1, pos1.getX(), pos1.getY());
            }
        }
        return map.toString();
    }
}
