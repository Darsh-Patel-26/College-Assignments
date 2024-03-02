package livingOrganism;

import java.io.*;

public class Animal extends LivingOrganism{
    static String type = "Animal";

    public Animal(String name, String genus, String location){
        System.out.println("A animal created!!");
        this.name = name;
        this.genus = genus;
        this.location = location;
    }

    public static Animal takeInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        System.out.print("Enter name of Animal : ");
        String name = br.readLine();

        System.out.print("Enter genus of Animal : ");
        String genus = br.readLine();

        System.out.print("Enter location of Animal : ");
        String location = br.readLine();
 
        return new Animal(name,genus,location);
    }

    public String toString(){
        return "The Name of Organism : "+this.name+".\nType : "+type+".\nGenus : "+this.genus+".\nMainly Found near : "+this.location+".\n";
    }
}
