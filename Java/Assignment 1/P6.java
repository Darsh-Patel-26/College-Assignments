import java.util.*;

class RandomString 
{
    public static void main(String[] args) 
	{
        Scanner sc = new Scanner(System.in);

        char[] alphabet = {'A', 'B', 'C', 'D'};
        System.out.print("Enter length of string : ");
        int length = sc.nextInt();

        String random = RandomString.randomStringGenerator(alphabet, length);
        System.out.println("Random String Generated : " + random);
    }

    public static String randomStringGenerator(char[] alphabet, int length) 
	{
        StringBuffer sb = new StringBuffer(); 

        for (int i = 0; i < length; i++) 
		{
            int randomIndex = (int) (Math.random() * alphabet.length);
            char randomChar = alphabet[randomIndex];
            sb.append(randomChar);
        }
        return sb.toString();
    }
}
