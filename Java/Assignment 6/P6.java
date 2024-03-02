import java.io.*;

class RandomStringA6 {
    public static void main(String[] args) throws IOException, NumberFormatException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] alphabet = {'A', 'B', 'C', 'D'};
        System.out.print("Enter length of string : ");
        int length = Integer.parseInt(br.readLine());

        String random = RandomStringA6.randomStringGenerator(alphabet, length);
        System.out.println("Random String Generated : " + random);
    }

    public static String randomStringGenerator(char[] alphabet, int length) throws ArrayIndexOutOfBoundsException {
        StringBuffer sb = new StringBuffer(); 

        for (int i = 0; i < length; i++) {
            int randomIndex = (int) (Math.random() * alphabet.length);
            char randomChar = alphabet[randomIndex];
            sb.append(randomChar);
        }
        return sb.toString();
    }
}
