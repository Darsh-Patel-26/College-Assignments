import java.math.*;
import java.util.*;

class Factorial20
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger factorial = BigInteger.ONE;
		System.out.print("Enter no. to find the factorial : ");
		int n = sc.nextInt();

		factorial = Factorial20.fact(factorial,n);
		System.out.println("The factorial of "+n+" is : "+factorial);
	}

	public static BigInteger fact(BigInteger fact, int n)
	{
		for(int i = n;i>=1;i--)
		{
			fact = fact.multiply(BigInteger.valueOf(i));
		}
		return fact;
	}
}