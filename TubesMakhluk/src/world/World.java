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

	private World (int _NBrs, int _NKol)
	{
		NBrs = _NBrs;
		NKol = _NKol;
		_isPaused = 0; _isEnded = 0;
		objects = new LMakhluk();

	}
	public LMakhluk getObjects () {return objects;}
	public static World getWorldInstance() {return worldInstance;}
	public int getNBrs() {return NBrs;}
	public int getNKol() {return NKol;}
	public void setNBrs(int _NBrs) {NBrs = _NBrs;}
	public void setNKol (int _NKol) {NKol = _NKol;}
	public int isEnded() {return _isEnded;}
	public int isPaused() {return _isPaused;}
	public void endWorld() {_isEnded = 1;}
	public void changePauseState() { _isPaused ^= 1; }
}
