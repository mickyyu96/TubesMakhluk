// IOManager.java

package inputoutput;

import matrix.*;
import point.*;
import world.*;

/** Kelas IOManager bertanggung jawab untuk melakukan operasi-operasi Input/Output
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

abstract class IOManager {
    /** Mencetak sebuah matriks ke layar
     *  @param M final Matrix yang merupakan objek matriks
     */
    public void PrintMatrix(final Matrix M) {
        for (int i=0; i<M.getNBrs(); i++) {
            for (int j=0; j<M.getNKol(); j++) {
                System.out.print(M.getInfo(i, j));
            }
            System.out.println();
        }
    }

    /** Mencetak state dunia saat ini beserta isi dari dunia
     */
    public void PrintWorldMap() {
        for (int i=0; i<30; i++) {
            System.out.println();
        }
        World worldInstance = World.getWorldInstance();
        Matrix map = new Matrix(worldInstance.getNBrs(), worldInstance.getNKol());
        LMakhluk _LMakhluk = worldInstance.getObjects();
        for (int i=0; i<_LMakhluk.getSize(); i++) {
            if (_LMakhluk.getInfo(i).isAlive() == 1) {
                char ID1 = _LMakhluk.getInfo(i).getID();
                Point pos1 = _LMakhluk.getInfo(i).getPosition();
                map.setInfo(ID1, pos1.getX(), pos1.getY());
            }
        }
        PrintMatrix(map);
    }

    /** Mengambil string state dunia dan mengkonversinya dalam format
     *  HTML string
     *  @return String state dunia dalam format HTML string
     */
    public String getHTMLStrWorldMap() {
        World worldInstance = World.getWorldInstance();
        Matrix map = new Matrix(worldInstance.getNBrs(), worldInstance.getNKol());
        LMakhluk _LMakhluk = worldInstance.getObjects();
        for (int i=0; i<_LMakhluk.getSize(); i++) {
            if (_LMakhluk.getInfo(i).isAlive() == 1) {
                char ID1 = _LMakhluk.getInfo(i).getID();
                Point pos1 = _LMakhluk.getInfo(i).getPosition();
                map.setInfo(ID1, pos1.getX(), pos1.getY());
            }
        }
        return map.toHTMLString();
    }

    /** Mengambil string state dunia 
     *  @return String state dunia
     */
    public String getStrWorldMap() {
        World worldInstance = World.getWorldInstance();
        Matrix map = new Matrix(worldInstance.getNBrs(), worldInstance.getNKol());
        LMakhluk _LMakhluk = worldInstance.getObjects();
        for (int i=0; i<_LMakhluk.getSize(); i++) {
            if (_LMakhluk.getInfo(i).isAlive() == 1) {
                char ID1 = _LMakhluk.getInfo(i).getID();
                Point pos1 = _LMakhluk.getInfo(i).getPosition();
                map.setInfo(ID1, pos1.getX(), pos1.getY());
            }
        }
        return map.toString();
    }
}
