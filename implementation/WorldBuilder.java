

/** Kelas WorldBuilder merupakan BUILDER dari kelas World, dan bertanggung jawab untuk melakukan inisialisasi objek-objek dunia
 *	@author     Atika Azzahra Akbar
 *	@date       April 2016
 *	@version	1.0
 */
 
public class WorldBuilder {
	private static WorldBuilder builderInstance = new WorldBuilder();
	private String strMakhluk;
	private int NBrs, NKol;
	
	/** Menciptakan sebuah instance WorldBuilder
	*/
	private WorldBuilder() {}
	
	/** Mengembalikan pointer dari objek singleton pada kelas WorldBuilder
	*   @return	Pointer yang menunjuk ke singleton instance pada kelas WorldBuilder
	*/
	public static WorldBuilder getBuilderInstance() { return builderInstance; }
	
	/** Mengembalikan sebuah string yang tersimpan dalam instance WorldBuilder
	*   yang merupakan karakter-karakter makhluk yang akan diciptakan
	*   @return	String yang berisi karakter-karakter makhluk yang akan diciptakan
	*/
	public String getStrMakhluk() { return strMakhluk; }
	
	/** Melakukan assignment string yang tersimpan dalam instance WorldBuilder
	*   dengan string baru yang di-passing melalui parameter
	*   @param	_str const string& String baru yang akan di-assign
	*   @return	void
	*/
	public void setStrMakhluk(final String str) { strMakhluk = str; }
	
	/** Menambahkan sebuah objek ke dalam container objek di dunia berdasarkan
	*   ID karakter makhluk yang di-passing melalui parameter
	*   @param	_ID char Karakter yang merupakan ID makhluk yang akan ditambahkan
	*   @return	void
	*/
	public void addAnObject(char_ID) {
		int NBrs = World.getWorldInstance().getNBrs();
		int NKol = World.getWorldInstance().getNKol();
		switch (_ID)
		{
			case 'G':
				World.getWorldInstance().getObjects().Add(new Tumbuhan(RandomGenerator.getInstance().getNextPoint(NBrs, NKol)));
				break;
			case 'R':
				World.getWorldInstance().getObjects().Add(new Rabbit(RandomGenerator.getInstance().getNextPoint(NBrs, NKol)));
				break;
			case 'T':
				World.getWorldInstance().getObjects().Add(new Turtle(RandomGenerator.getInstance().getNextPoint(NBrs, NKol)));
				break;
			case 'W':
				World.getWorldInstance().getObjects().Add(new Wolf(RandomGenerator.getInstance().getNextPoint(NBrs, NKol)));
				break;
			case 'S':
				World.getWorldInstance().getObjects().Add(new Sheep(RandomGenerator.getInstance().getNextPoint(NBrs, NKol)));
				break;
			case 'P':
				World.getWorldInstance().getObjects().Add(new PolarBear(RandomGenerator.getInstance().getNextPointPB(NBrs, NKol)));
				break;
	        	case 'U':
				World.getWorldInstance().getObjects().Add(new Snake(RandomGenerator.getInstance().getNextPoint(NBrs, NKol)));
				break;
			default :
				ExceptionObject E = new ExceptionObject(3);
				E.DisplayErrorMessage();
		}

	}
	
	/** Melakukan inisialisasi list of makhluk pada objek singleton kelas World
	*   berdasarkan string yang tersimpan dalam instance WorldBuilder
	*   @return	void
	*/
	public void buildWorldObject() {
		int numOfObjects = getStrMakhluk().length();
		for (int i = 0; i < numOfObjects; i++)
		{
			char c = getStrMakhluk().charAt(i);
			addAnObject(c);
		}
	}
}
