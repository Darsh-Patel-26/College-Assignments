import java.util.*;

class PrimeNum 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of prime numbers : ");
        int num = sc.nextInt();
        PrimeNum.print(num);
    }

    public static void print(int num)
    {
        int count = 0;
        int number= 2;

        while (count<num) 
        {
            if(PrimeNum.isPrime(number)) 
            {
                System.out.println(count+1+") "+number);
                count++;
            }   
            number++;
        }
    }

    public static boolean isPrime(double num)
    {
        if(num<=1)
        {
            return false;
        }

        for(double i=2;i<=Math.sqrt(num);i++)
        {
            if(num%i==0)
            {
                return false;
            }
        }

        return true;
    }
}
