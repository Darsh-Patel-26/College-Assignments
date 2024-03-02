package livingOrganism;

public abstract class LivingOrganism {
    String name;
    String location;
    String genus;
    String type;

    public LivingOrganism(){
        System.out.println("\nA living organism created!!");
    }

    abstract public String toString();
} 
