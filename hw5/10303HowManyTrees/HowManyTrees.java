import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	public static void main ( String[] args )
	{
		BigInteger catal[] = new BigInteger[1015];
		catal[0] = catal[1] = BigInteger.ONE;

		// make tabel of all cataline numbers 
		// first I wont to make array of them but then 
		// it is probably not fair :)
		for (int i = 2; i < 1015; i++ )
		{
			catal[i] = BigInteger.ZERO;

			for (int j = 0; j < i; j++ )
			{
				catal[i] = catal[i].add ( catal[j].multiply ( catal[i - j - 1] ) );
			}
		}

		// now printing the one thats needed !
		Scanner in = new Scanner ( System.in );
		while ( in.hasNext() ) { System.out.println ( catal[in.nextInt()] ); }
		in.close();
	}
}

