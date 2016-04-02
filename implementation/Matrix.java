public class Matrix 
{
	private char[][] M;
	private final int NBrs;
	private final int NKol;

	public Matrix(int _NBrs, int _NKol)
	{
		NBrs = _NBrs;
		NKol = _NKol;

		M = new char[NBrs][];
		for (int i = 0; i<NBrs; i++)
			M[i] = new char[NKol];
		for (int i = 0; i<NBrs; i++) {
			for (int j = 0; j<NKol; j++)
				M[i][j] = '.';
		}
		for (int i = 0; i<NBrs; i++)
			M[i][0] = M[i][NKol-1] = '#';
		for (int i=0; i<NKol; i++)
			M[0][i] = M[NBrs-1][i] = '#';
	}
	public final int getNBrs() {return NBrs;}
	public final int getNKol() {return NKol;}
	public final char getInfo(int i, int j)
	{
		return M[i][j];
	} 
	public void setInfo(char c, int i, int j)
	{
		M[i][j]=c;
	}
}