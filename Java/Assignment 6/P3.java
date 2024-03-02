import java.io.*;

class PrimeNumA6 {
    public static void main(String[] args) throws IOException, NumberFormatException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter no. of prime numbers : ");
        int num = Integer.parseInt(br.readLine());
        PrimeNumA6.print(num);
    }

    public static void print(int num) {
        int count = 0;
        int number= 2;

        while (count<num) {
            if(PrimeNumA6.isPrime(number)) {
                System.out.println(count+1+") "+number);
                count++;
            }   
            number++;
        }
    }

    public static boolean isPrime(double num) {
        if(num<=1) {
            return false;
        }

        for(double i=2;i<=Math.sqrt(num);i++) {
            if(num%i==0) {
                return false;
            }
        }

        return true;
    }
}

