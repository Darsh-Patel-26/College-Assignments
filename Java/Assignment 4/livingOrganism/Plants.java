package livingOrganism;

import java.io.*;

public class Plants extends LivingOrganism {
    static String type = "Plant";

    public Plants(String name, String genus, String location){
        System.out.println("A plant created!!");
        this.name = name;
        this.genus = genus;
        this.location = location;
    }

    public static Plants takeInput() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        System.out.print("Enter name of Plant : ");
        String name = br.readLine();

        System.out.print("Enter genus of Plant : ");
        String genus = br.readLine();

        System.out.print("Enter location of Plant : ");
        String location = br.readLine();

        return new Plants(name,genus,location);
    } 

    public String toString(){
        return "The Name of Organism : "+this.name+".\nType : "+type+".\nGenus : "+this.genus+".\nMainly Found near : "+this.location+".\n";
    }
}
