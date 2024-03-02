import java.io.*;

import livingOrganism.*;

class LOTest { 
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("1 for Plant.");
        System.out.println("2 for Animal.");
        System.out.println("3 for Human.");
        System.out.println("0 for exit.");
        
        int ch;
        
        while(true){
            System.out.println("Enter what organism to create : ");
            ch = Integer.parseInt(br.readLine());

            switch (ch){
                case 1:
                    Plants op1 = Plants.takeInput();
                    System.out.println(op1);
                    break;
                case 2:
                    Animal oa1 = Animal.takeInput();
                    System.out.println(oa1);
                    break;
                case 3:
                    Human oh1 = Human.takeInput();
                    System.out.println(oh1);
                    break;
                case 0:
                    System.out.println("Exited Succesfully!!");
                    return;
                default:
                    System.out.println("Try again!!");
                    break;
            }
        }
    }
} 