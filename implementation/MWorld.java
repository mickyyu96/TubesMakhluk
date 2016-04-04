//MWorld.java

import java.util.Scanner;

public class MWorld {
	private static boolean isValidID(String s) {
		boolean found = false;
		for(int i=0; i<s.length() && !found; i++)
		{
			if(s.charAt(i) != 'P' && s.charAt(i) != 'G' && s.charAt(i) != 'R' 
				&& s.charAt(i) != 'T' && s.charAt(i) != 'S' && s.charAt(i) != 'W' 
				&& s.charAt(i) != 'U') {
				found = true;
			}
		}
		return !found;
	}

	private static boolean isValidUkuran (String strNBrs, String strNKol) {
		boolean valid = true;
		for(int i=0; i<strNBrs.length() && valid; i++)
		{
			if(strNBrs.charAt(i) < '0' || strNBrs.charAt(i) >'9') valid = false;
		}
		for(int i=0; i<strNKol.length() && valid; i++)
		{
			if(strNKol.charAt(i) < '0' || strNKol.charAt(i) >'9') valid = false;
		}
		return valid;
	}

	public static void main(String args[]) throws Exception {
	    System.out.println("*************************************************************************************");
	    System.out.println("       **       ***    **  ***  ***         ***       **       **        **  ********");
	    System.out.println("      ****      ****   **  ***  ****       ****      ****      **       **   **      ");
	    System.out.println("     **  **     ** **  **  ***  ** **     ** **     **  **     **            **      ");
	    System.out.println("    ********    **  ** **  ***  **  **   **  **    ********    **            ********");
	    System.out.println("   **      **   **   ****  ***  **   ** **   **   **      **   **                  **");
	    System.out.println("  **        **  **    ***  ***  **    ***    **  **        **  ********      ********");
	    System.out.println("                                                                                     ");
	    System.out.println("       **        **  ***  **        **             **       ********  ********       ");
	    System.out.println("        **      **   ***  **        **            ****      **        **             ");
	    System.out.println("         **    **    ***  **        **           **  **     **        **             ");
	    System.out.println("          **  **     ***  **        **          ********    **  ****  ********       ");
	    System.out.println("           ****      ***  **        **         **      **   **    **  **             ");
	    System.out.println("            **       ***  ********  ********  **        **  ********  ********       ");
	    System.out.println("                                                                                     ");
	    System.out.println("             WOLF     RABBIT     TURTLE     POLARBEAR     SNAKE     SHEEP            ");
	    System.out.println("                                                                                     ");
	    System.out.println("                         BY EPIC: NGIONG, MICKY, KEPI, ELVINA                        ");
	    System.out.println("*************************************************************************************");
		/**************************************************************
		**
		**				Input dimensi ukuran dunia
		**
		**************************************************************/
		Scanner in = new Scanner(System.in);
		int _NBrs = 0, _NKol = 0;
		String strNBrs = "", strNKol = "";
		do
		{
			try
			{

				System.out.println("Masukkan dimensi ukuran ruang dunia.");
				System.out.print("Jumlah baris (panjang) = "); strNBrs = in.next();
				System.out.print("Jumlah kolom (lebar)   = "); strNKol = in.next();
				if(!isValidUkuran(strNBrs, strNKol)) throw new ExceptionObject(4);

				_NBrs = Integer.parseInt(strNBrs); _NKol = Integer.parseInt(strNKol);
				if (_NBrs < 7 || _NKol < 7) throw new ExceptionObject(0);
			}
			catch (ExceptionObject E)
			{
				E.DisplayErrorMessage();
			}

		} while(_NBrs < 7 || _NKol < 7 || !isValidUkuran(strNBrs, strNKol));
		World.getWorldInstance().setNBrs(_NBrs+2); World.getWorldInstance().setNKol(_NKol+2);

		System.out.println("\n===========================================================================\n");

		/**************************************************************
		**
		**				Input makhluk-makhluk yang ada
		**
		**************************************************************/
		String input = "";
		do
		{
			try
			{
				System.out.println("Masukkan sebuah string yang  berisi ID (UPPERCASE) makhluk-makhluk yang ingin dimunculkan pada dunia. ");
				System.out.println("Pilihan :\n\tP = PolarBear, \n\tG = Tumbuhan, \n\tR = Rabbit, \n\tT = Turtle, \n\tS = Sheep, \n\tW = Wolf, \n\tU = Snake");
				System.out.print("String input = ");
				input = in.next();

				if(!isValidID(input)) throw new ExceptionObject(1);
			}
			catch (ExceptionObject E)
			{
				E.DisplayErrorMessage();
			}
		} while (!isValidID(input));
		WorldBuilder.getBuilderInstance().setStrMakhluk(input);
		WorldBuilder.getBuilderInstance().buildWorldObject();

		System.out.println("\n===========================================================================\n");

		/**************************************************************
		**
		**					Nyalakan dunia
		**
		**************************************************************/

	    do
	    {
	        do
	        {
	            MakhlukLive.getInstance().MakhlukMove();
	            Screen.getScreenInstance().PrintWorldMap();
	            MakhlukLive.getInstance().MakhlukEat();

	            if (World.getWorldInstance().getObjects().IsAllMakhlukDead())
	            {
	                World.getWorldInstance().endWorld();
	                break;
	            }

	            Thread.sleep(500);

	        } while (System.in.available() == 0 && World.getWorldInstance().isEnded() == 0);

	        if(System.in.available() != 0)
	        {
	            //KeypressHandler.getHandlerInstance().getKeypress();
	            //KeypressHandler.getHandlerInstance().doAction();
	        }

	    } while(World.getWorldInstance().isEnded() == 0);

	}
}