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
		BigInteger[] T = new BigInteger[1001];
		T[0] = new BigInteger("1");
		T[1] = new BigInteger("2");
		T[2] = new BigInteger("5");
		for (int i = 3; i <= 1000; i++)
		{
			T[i] = new BigInteger("0");
			T[i] = T[i].add(T[i - 1]).add(T[i - 1]).add(T[i - 2]).add(T[i - 3]);
		}

		Scanner scanner = new Scanner(System.in);

		while (scanner.hasNextInt())
		{
			int n = scanner.nextInt();
			System.out.printf("%s\n", T[n].toString());
		}
		scanner.close();
	}
}
