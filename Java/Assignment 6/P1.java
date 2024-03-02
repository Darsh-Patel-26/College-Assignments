import java.io.*;

class AddMarksA6 {
    public static void main(String[] args) throws IOException, NumberFormatException {
        if(args.length<2) {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            System.out.print("Enter 2 Subject Marks : ");
            int sub1 = Integer.parseInt(br.readLine());
            int sub2 = Integer.parseInt(br.readLine());

            int total = sub1 + sub2;
            System.out.println("Total marks : "+total);
            return;
        }

        int sub1 = Integer.parseInt(args[0]);
        int sub2 = Integer.parseInt(args[1]);
        int total = sub1 + sub2;
        System.out.println("Total marks : "+total);
    }
}