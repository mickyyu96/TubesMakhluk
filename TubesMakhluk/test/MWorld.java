import java.util.Scanner;
import exception.ExceptionObject;
import inputoutput.Screen;
import makhluklive.MakhlukLive;
import world.World;
import world.WorldBuilder;

/** Kelas MWorld adalah kelas yang menampung main program.
 *  @author     Robert Sebastian Herlim / 13514061
 *  @version    1.0
 */
public class MWorld {
    /** fungsi validasi apakah id valid.
     * @param s string ID
     * @return boolean true jika ukuran valid
     */
    private static boolean isValidID(final String s) {
        boolean found = false;
        for (int i = 0; i < s.length() && !found; i++) {
            if (s.charAt(i) != 'P' && s.charAt(i) != 'G' && s.charAt(i) != 'R'
                    && s.charAt(i) != 'T' && s.charAt(i) != 'S'
                    && s.charAt(i) != 'W' && s.charAt(i) != 'U') {
                found = true;
             }
        }
        return !found;
    }
    /** fungsi validasi apakah ukuran valid.
     * @param strNBrs string jumlah baris
     * @param strNKol string jumlah kolom
     * @return boolean true jika ukuran valid
     */
     private static boolean isValidUkuran(final String strNBrs,
             final String strNKol) {
        boolean valid = true;
        for (int i = 0; i < strNBrs.length() && valid; i++) {
            if (strNBrs.charAt(i) < '0'
                    || strNBrs.charAt(i) > '9') {
                valid = false;
            }
        }
        for (int i = 0; i < strNKol.length() && valid; i++) {
            if (strNKol.charAt(i) < '0'
                    || strNKol.charAt(i) > '9') {
                valid = false;
            }
        }
        return valid;
     }
     /** Main program animal village.
      * @param args
      * @throws Exception
      */
     public static void main(final String args[]) throws Exception {
         System.out.println("***************************************"
                + "**********************************************");
         System.out.println("       **       ***    **  ***  ***    "
                + "     ***       **       **        **  ********");
         System.out.println("      ****      ****   **  ***  ****   "
                + "    ****      ****      **       **   **      ");
         System.out.println("     **  **     ** **  **  ***  ** **  "
                + "   ** **     **  **     **            **      ");
         System.out.println("    ********    **  ** **  ***  **  ** "
                + "  **  **    ********    **            ********");
         System.out.println("   **      **   **   ****  ***  **   **"
                + " **   **   **      **   **                  **");
         System.out.println("  **        **  **    ***  ***  **    *"
                + "**    **  **        **  ********      ********");
         System.out.println("                                      "
                + "                                               ");
         System.out.println("       **        **  ***  **        ** "
                + "            **       ********  ********       ");
         System.out.println("        **      **   ***  **        **"
                + "            ****      **        **             ");
         System.out.println("         **    **    ***  **        **"
                + "           **  **     **        **             ");
         System.out.println("          **  **     ***  **        **"
                + "          ********    **  ****  ********       ");
         System.out.println("           ****      ***  **        **"
                + "         **      **   **    **  **             ");
         System.out.println("            **       ***  ********  ***"
                + "*****  **        **  ********  ********       ");
         System.out.println("                                       "
                + "                                              ");
         System.out.println("             WOLF     RABBIT     TURTLE"
                + "     POLARBEAR     SNAKE     SHEEP            ");
         System.out.println("                                       "
                + "                                              ");
         System.out.println("                         BY EPIC: NGIONG,"
                + " MICKY, KEPI, ELVINA                        ");
         System.out.println("***************************************"
                + "**********************************************");
        /**************************************************************
        **
        **               Input dimensi ukuran dunia
        **
        **************************************************************/
        Scanner in = new Scanner(System.in);
        int nBrs = 0, nKol = 0;
        String strNBrs = "", strNKol = "";
        do {
           try {
               System.out.println("Masukkan dimensi ukuran"
                   + " ruang dunia.");
               System.out.print("Jumlah baris (panjang) = ");
               strNBrs = in.next();
               System.out.print("Jumlah kolom (lebar)   = ");
               strNKol = in.next();
               if (!isValidUkuran(strNBrs, strNKol)) {
                   throw new ExceptionObject(4);
               }
               nBrs = Integer.parseInt(strNBrs);
               nKol = Integer.parseInt(strNKol);
               if (nBrs < 7 || nKol < 7) {
                  throw new ExceptionObject(0);
               }
            } catch (ExceptionObject e) {
                e.displayErrorMessage();
            }
        } while (nBrs < 7 || nKol < 7
                || !isValidUkuran(strNBrs, strNKol));
        World.getWorldInstance().setnBrs(nBrs+2);
        World.getWorldInstance().setnKol(nKol+2);
        in.close();
        System.out.println("\n========================================="
                + "==================================\n");
        /**************************************************************
        **
        **              Input makhluk-makhluk yang ada
        **
        **************************************************************/
        String input = "";
        do {
            try {
                System.out.println("Masukkan sebuah string "
                        + "yang berisi ID (UPPERCASE) makhluk"
                        + "-makhluk yang ingin dimunculkan "
                        + "pada dunia. ");
                System.out.println("Pilihan :\n\tP = PolarBear,"
                        + " \n\tG = Tumbuhan, \n\tR = Rabbit,"
                        + " \n\tT = Turtle, \n\tS = Sheep, "
                        + "\n\tW = Wolf, \n\tU = Snake");
                System.out.print("String input = ");
                input = in.next();
                if (!isValidID(input)) {
                    throw new ExceptionObject(1);
                }
            } catch (ExceptionObject e) {
                e.displayErrorMessage();
            }
        } while (!isValidID(input));
        WorldBuilder.getBuilderInstance().setStrMakhluk(input);
        WorldBuilder.getBuilderInstance().buildWorldObject();
        System.out.println("\n========================================"
                     + "===================================\n");
        /**************************************************************
         **
         **                       Nyalakan dunia
         **
         **************************************************************/
        Thread viewThread = new Thread(new Screen());
        viewThread.start();
        do {
            while (World.getWorldInstance().isPaused() == 1) {
                Thread.sleep(100);
            }
            MakhlukLive.getInstance().makhlukMove();
            MakhlukLive.getInstance().makhlukEat();
            if (World.getWorldInstance().getObjects().isAllMakhlukDead()) {
                World.getWorldInstance().endWorld();
                break;
            }
            Thread.sleep(500);
        } while (World.getWorldInstance().isEnded() == 0);
    }
}
