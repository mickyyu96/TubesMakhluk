//World.java

package world;

import java.util.*;
import java.time.*;

public class World
{
	private int _isEnded;
	private int _isPaused;

	private static final int DEFAULT_NBRS = 30;
	private static final int DEFAULT_NKOL = 30;

	private static World worldInstance = new World(DEFAULT_NBRS, DEFAULT_NKOL);


	int NBrs;
	int NKol;

	private LMakhluk objects;

	/** Konstruktor World berparameter. Menangani pembentukan world dan 
	 *	hal-hal yang berkaitan dengan keberjalanan world
	 *	@param 	int _NBrs berupa ukuran baris world 
	 *	@param	int _NKol berupa ukuran kolom world
	 */
	private World (int _NBrs, int _NKol)
	{
		NBrs = _NBrs;
		NKol = _NKol;
		_isPaused = 0; _isEnded = 0;
		objects = new LMakhluk();

	}
	/** Mengembalikan makhluk (object) yang ada di world
	 *	@return LMakhluk makhluk yang ada pada world
	 */
	public LMakhluk getObjects () {return objects;}
	/** Pointer untuk mengembalikan worldInstance
	 *  @return World
	 */
	public static World getWorldInstance() {return worldInstance;}
	/** Mengembalikan jumlah baris world
	 *	@return	int NBrs, jumlah baris World
	 */
	public int getNBrs() {return NBrs;}
	/** Mengembalikan jumlah kolom world
	 *	@return	int NKol, jumlah kolom World
	 */
	public int getNKol() {return NKol;}
	/** Melakukan assignment jumlah baris world
	 *	@param 	int _NBrs, jumlah baris yang akan di-assign
	 *	@return	void
	 */
	public void setNBrs(int _NBrs) {NBrs = _NBrs;}
	/** Melakukan assignment jumlah kolom world
	 *	@param 	int _NKol, jumlah kolom yang akan di-assign
	 *	@return	void
	 */
	public void setNKol (int _NKol) {NKol = _NKol;}
	/** Mengembalikan apakah program sudah selesai atau  belum
	 *	@return	int sesuai dengan attribute _isEnded
	 */
	public int isEnded() {return _isEnded;}
	/** Mengembalikan apakah program sedang di-pause oleh user atau tidak
	 *	@return	int sesuai dengan attribute _isPaused
	 */
	public int isPaused() {return _isPaused;}
	/** Untuk mengubah state bahwa program harus berhenti
	 *	@return void
	 */
	public void endWorld() {_isEnded = 1;}
	/** Untuk mengubah state bahwa program sedang di-pause
	 *	@return void
	 */
	public void changePauseState() { _isPaused ^= 1; }
}
