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
		BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        BigInteger c = new BigInteger("0");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
 
        for (int i=0; i<n; i++)
        {
            a = scanner.nextBigInteger();
            b = a.multiply( a.subtract(BigInteger.valueOf(1)));
            b = b.multiply(a.subtract(BigInteger.valueOf(2)));
            b =  b.multiply(a.subtract(BigInteger.valueOf(3)));
            b = b.divide(BigInteger.valueOf(24));
            c = a.multiply(a.subtract(BigInteger.valueOf(1)));
            c = c.divide(BigInteger.valueOf(2));
            b = b.add(c);
            b = b.add(BigInteger.valueOf(1));
 
            System.out.printf("%s\n", b.toString());
        }
        scanner.close();
	}
}
