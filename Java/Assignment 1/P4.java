import java.util.*;

class Fibonacci 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter terms of Fibonacci : ");
        int n = sc.nextInt();
        long[] fibonacci = new long[100];

        Fibonacci.fibonacci(fibonacci, n);
    }

    public static void fibonacci(long[] fibonacci, int n)
    {
        fibonacci[0] = 0;
        fibonacci[1] = 1;

        for (int i = 2; i < n; i++) 
        {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }

        for (int i = 0; i < n; i++) 
        {
            System.out.println((i+1)+")"+fibonacci[i]);
        }
    }
}