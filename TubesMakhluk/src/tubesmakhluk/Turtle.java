package tubesmakhluk;

public class Turtle extends Hewan
{
	private static final char TURTLE_ID = 'T';
	private static final int TURTLE_MAXAGE = 240;
	private static final int TURTLE_BASEPOWER = 2;

	public Turtle(final Point P)
	{
		super(TURTLE_ID, TURTLE_MAXAGE);

		age = 0;
		status = 1;
		power = TURTLE_BASEPOWER;
		pos = P;
	}
}