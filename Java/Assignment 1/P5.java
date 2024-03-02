import java.util.*;
import java.math.*;

class Factorial50
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter no. to find Factorial : ");
		int num = sc.nextInt();
		BigInteger fact = Factorial50.factorial(num);

		System.out.println("The FACTORIAL of "+num+" is : "+fact);
	}

	public static BigInteger factorial(int n)
	{
		if(n==1)
			return BigInteger.ONE;
		return BigInteger.valueOf(n).multiply(Factorial50.factorial(n-1));
	}
}