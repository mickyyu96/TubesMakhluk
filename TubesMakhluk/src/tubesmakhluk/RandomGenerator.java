package tubesmakhluk;

import java.util.Random;

/** Kelas RandomGenerator mengembalikan sebuah random number
 *	@author     Atika Azzahra Akbar
 *	@date       April 2016
 *	@version	1.0
 */

public class RandomGenerator {
	private static RandomGenerator _instance = new RandomGenerator();
	
	/** Constructor menciptakan sebuah RandomGenerator
	 */
	private RandomGenerator(){}
	
	/** Mengembalikan pointer dari objek kelas singleton pada kelas RandomGenerator
	 *	@return     Pointer yang menunjuk ke singleton instance pada kelas RandomGenerator
	 */
	public static RandomGenerator getInstance() { return _instance; }
	
	/** Melakukan pengacakan bilangan bulat dengan batasan (0...a-1)
	 *  @param      a int Batas atas hasil acak
	 *	@return     Bilangan bulat acak dari (0...a-1)
	 */
	public int getNextInt(int a) { 
		Random rn = new Random();
		return (rn.nextInt(a) % a); 
	}
	
	/** Melakukan pengacakan bilangan bulat dengan batasan (a...b)
	 *  @param      a int Batas bawah hasil acak
	 *  @param      b int Batas atas hasil acak
	 *	@return     Bilangan bulat acak dari (a...b)
	 */
	public int getNextIntBetween(int min, int max) {
		Random rand = new Random();
		int randomNum = rand.nextInt((max-min)+1)+min;
		return randomNum;
	}
	
	/** Fungsi untuk  elakukan pengacakan point dengan batasan (1...Nbrs-2), (1...NKol-2)
	 *  @param      NBrs int Jumlah baris
	 *  @param      NKol int Jumlah kolom
	 *	@return     Point acak dari (1...Nbrs-2), (1...NKol-2)
	 */
	public Point getNextPoint(int NBrs, int NKol) {
		return new Point(getNextIntBetween(1, NBrs-2), getNextIntBetween(1, NKol-2));
	}
	
	/** Fungsi untuk melakukan pengacakan point dengan batasan (NBrs-(NBrs/5)-2...Nbrs-2), (1...NKol-2)
	 *  @param      NBrs int Jumlah baris
	 *  @param      NKol int Jumlah kolom
	 *	@return     Point acak dari (NBrs-(NBrs/5)-2...Nbrs-2), (1...NKol-2)
	 */
	public Point getNextPointPB(int NBrs, int NKol) {
		return new Point(getNextIntBetween(NBrs-(NBrs/5)-2, NBrs-2), getNextIntBetween(1, NKol-2));
	}
    
    /** Unit test untuk WorldBuilder
     *	@return     void
     */
    public static void main (String args[]) {
        int randNum, i;
        
        System.out.println("-----getNextInt-----");
        for (i=1; i<=3; i++)
        {
            randNum = RandomGenerator.getInstance().getNextInt(10);
            System.out.println("Random Number (10) : " + randNum);
        }
        System.out.println();
        
        System.out.println("-----getNextPoint-----");
        for (i=1; i<=3; i++)
        {
            randNum = RandomGenerator.getInstance().getNextIntBetween(-3, 3);
            System.out.println("Random Number (-3 ,3) : "  + randNum);
        }
    }
}
