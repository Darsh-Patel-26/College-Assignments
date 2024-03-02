package livingOrganism;

import java.io.*;

public class Human extends Animal {
    static String type = "Human";
    String nationality;
    public Human(String name, String genus, String location, String nationality){
        super(name, genus, location);
        System.out.println("Human created!!");
        this.nationality = nationality;
    }

    public static Human takeInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        System.out.print("Enter name of Human : ");
        String name = br.readLine();

        System.out.print("Enter genus of Human : ");
        String genus = br.readLine();

        System.out.print("Enter location of Human : ");
        String location = br.readLine();

        System.out.print("Enter nationality of Human : ");
        String nationality = br.readLine();
 
        return new Human(name,genus,location,nationality);
    }

    public String toString(){
        return "The Name of Organism : "+this.name+".\nNationality : "+this.nationality+".\nType : "+type+".\nGenus : "+this.genus+".\nMainly Found near : "+this.location+".\n" ;
    }
}
