import java.io.*;
import java.math.*;

class FibonacciA6 {
    public static void main(String[] args) throws IOException, NumberFormatException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter terms of Fibonacci : ");
        int n = Integer.parseInt(br.readLine());
        BigInteger[] fibonacci = new BigInteger[n];

        FibonacciA6.fibonacci(fibonacci, n);
    }

    public static void fibonacci(BigInteger[] fibonacci, int n) throws ArrayIndexOutOfBoundsException {
        fibonacci[0] = BigInteger.ZERO;
        fibonacci[1] = BigInteger.ONE;

        for (int i = 2; i < n; i++) {
            fibonacci[i] = fibonacci[i-1].add(fibonacci[i-2]);
        }

        for (int i = 0; i < n; i++) {
            System.out.println((i+1)+")"+fibonacci[i]);
        }
    }
}