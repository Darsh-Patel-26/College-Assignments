import java.io.*;
import java.math.*;

class Factorial20A6 {
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger factorial = BigInteger.ONE;
		System.out.print("Enter no. to find the factorial : ");
		int n = Integer.parseInt(br.readLine());

		factorial = Factorial20A6.fact(factorial,n);
		System.out.println("The factorial of "+n+" is : "+factorial);
	}

	public static BigInteger fact(BigInteger fact, int n) throws ArithmeticException {
		for(int i = n;i>=1;i--) {
			fact = fact.multiply(BigInteger.valueOf(i));
		}
		return fact;
	}
}
