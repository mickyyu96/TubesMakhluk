// IOManager.java

/** Kelas IOManager bertanggung jawab untuk melakukan operasi-operasi Input/Output
 *  @author     Micky Yudi Utama
 *  @date       April 2016
 *  @version	1.0
 */

class IOManager {
    /** Mencetak sebuah matriks ke layar
     *  @param M final Matrix yang merupakan objek matriks
     *  @return void
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
     *  @return void
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
}