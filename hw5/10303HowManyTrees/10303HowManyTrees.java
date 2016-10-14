import java.io.FileInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class 10303HowManyTrees
{
	public static void main ( String[] args )
	{
		BigInteger catalin[] = new BigInteger[1015];
		catalin[0] = catalin[1] = BigInteger.ONE;

		// colculate bunch of them 
		// first i thout to just make a big array and just output one
		// that needed but that will be too essay

		for (int i = 2; i <= 1012; i++ )
		{
			catalin[i] = BigInteger.ZERO;

			for (int j = 0; j < i; j++ )
			{
				catalin[i] = catalin[i].add ( catalin[j].multiply ( catalin[i - j - 1] ) );
			}
		}

		// now output the one that was ask for.
		Scanner in = new Scanner ( System.in );
		while ( in.hasNext() ) { System.out.println ( catalin[in.nextInt()] ); }
	}
}


