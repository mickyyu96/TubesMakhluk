package makhluk;

import point.*;

public class Rabbit extends Hewan
{
	private static final char RABBIT_ID = 'R';
	private static final int RABBIT_MAXAGE = 100;
	private static final int RABBIT_BASEPOWER = 3;

	public Rabbit (final Point P)
	{
		super(RABBIT_ID, RABBIT_MAXAGE);

		age = 0;
		status = 1;
		power = RABBIT_BASEPOWER;
		pos = P;
	}
}