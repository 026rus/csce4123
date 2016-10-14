import java.math.BigInteger;
import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
		run();
	}

	public static void run()
	{
		int n = 0;
		int h = 0;
		Scanner scanner = new Scanner(System.in);
		while ( (n = scanner.nextInt()) != 0)
		{
			h = 2 * n - 1;

			BigInteger a = new BigInteger("1");
			BigInteger b = new BigInteger("2");
			BigInteger c = new BigInteger("0");

			if (n == 1) 		System.out.println("1");
			else if (n == 2) 	System.out.println("3");
			else
			{
				for (int i = 3; i <= h; i++)
				{
					c = a.add(b);
					a = b;
					b = c;

				}
				System.out.println(c);
			}
		}
		scanner.close();
	}
}
