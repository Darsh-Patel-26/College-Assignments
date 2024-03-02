import java.io.*;
import java.math.*;

class Factorial50A6 {
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.print("Enter no. to find Factorial : ");
		int num = Integer.parseInt(br.readLine());

		BigInteger fact = Factorial50A6.factorial(num);

		System.out.println("The FACTORIAL of "+num+" is : "+fact);
	}

	public static BigInteger factorial(int n) {
		if(n==1)
			return BigInteger.ONE;
		return BigInteger.valueOf(n).multiply(Factorial50A6.factorial(n-1));
	}
}
