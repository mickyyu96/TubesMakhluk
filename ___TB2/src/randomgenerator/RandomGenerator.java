package randomgenerator;

import java.util.Random;
import point.Point;

/** Kelas RandomGenerator mengembalikan sebuah random number.
 *  @author  Atika Azzahra Akbar / 13514077
 *  @version 1.0
 */
public final class RandomGenerator {
    /** Atribut singleton random generator.
     */
    private static RandomGenerator instance = new RandomGenerator();
    /** Constructor menciptakan sebuah RandomGenerator.
     */
    private RandomGenerator() {
    }
    /** Mengembalikan pointer dari objek kelas singleton
     *  pada kelas RandomGenerator.
     *  @return Pointer yang menunjuk ke singleton instance pada kelas
     *  RandomGenerator
     */
     public static RandomGenerator getInstance() {
        return instance;
     }
     /** Melakukan pengacakan bilangan bulat dengan batasan (0...a-1).
      * @param a int Batas atas hasil acak
      * @return Bilangan bulat acak dari (0...a-1)
      */
     public int getNextInt(final int a) {
         Random rn = new Random();
         return (rn.nextInt(a) % a);
     }
    /** Melakukan pengacakan bilangan bulat dengan batasan (a...b).
     *  @param  min int Batas bawah hasil acak
     *  @param  max int Batas atas hasil acak
     *  @return     Bilangan bulat acak dari (a...b)
     */
     public int getNextIntBetween(final int min, final int max) {
        Random rand = new Random();
        int randomNum = rand.nextInt((max - min) + 1) + min;
        return randomNum;
     }
    /** Fungsi untuk  elakukan pengacakan point dengan batasan
     *  (1...nBrs-2), (1...nKol-2).
     *  @param nBrs int Jumlah baris
     *  @param nKol int Jumlah kolom
     *  @return Point acak dari (1...nBrs-2), (1...nKol-2)
     */
     public Point getNextPoint(final int nBrs, final int nKol) {
         return new Point(getNextIntBetween(1, nBrs - 2),
                 getNextIntBetween(1, nKol - 2));
     }
     /** Fungsi untuk melakukan pengacakan point dengan batasan
      * (nBrs-(nBrs/5)-2...nBrs-2), (1...nKol-2).
      *  @param      nBrs int Jumlah baris
      *  @param      nKol int Jumlah kolom
      *  @return     Point acak dari (nBrs-(nBrs/5)-2...nBrs-2), (1...nKol-2)
      */
     public Point getNextPointPB(final int nBrs, final int nKol) {
        final int num = 5;
        return new Point(getNextIntBetween(nBrs - (nBrs / num) - 2, nBrs - 2),
                 getNextIntBetween(1, nKol - 2));
     }
}
