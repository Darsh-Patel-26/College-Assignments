import java.io.*;

class InvalidTypeException extends Exception {
    public InvalidTypeException(String message) {
        super(message);
    }
}

abstract class LivingOrganism {
    String name;
    String location;
    String genus;
    String type;

    public LivingOrganism() {
        System.out.println("\nA living organism created!!");
    }

    abstract public String toString();
}

class Animal extends LivingOrganism {
    static String type = "Animal";

    public Animal(String name, String genus, String location) {
        System.out.println("An animal created!!");
        this.name = name;
        this.genus = genus;
        this.location = location;
    }

    public static Animal takeInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter name of Animal : ");
        String name = br.readLine();

        System.out.print("Enter genus of Animal : ");
        String genus = br.readLine();

        System.out.print("Enter location of Animal : ");
        String location = br.readLine();

        return new Animal(name, genus, location);
    }

    public String toString() {
        return "The Name of Organism : " + this.name + ".\nType : " + type + ".\nGenus : " + this.genus + ".\nMainly Found near : " + this.location + ".\n";
    }
}

class Human extends Animal {
    static String type = "Human";
    String nationality;

    public Human(String name, String genus, String location, String nationality) {
        super(name, genus, location);
        System.out.println("Human created!!");
        this.nationality = nationality;
    }

    public static Human takeInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter name of Human : ");
        String name = br.readLine();

        System.out.print("Enter genus of Human : ");
        String genus = br.readLine();

        System.out.print("Enter location of Human : ");
        String location = br.readLine();

        System.out.print("Enter nationality of Human : ");
        String nationality = br.readLine();

        return new Human(name, genus, location, nationality);
    }

    public String toString() {
        return "The Name of Organism : " + this.name + ".\nNationality : " + this.nationality + ".\nType : " + type + ".\nGenus : " + this.genus + ".\nMainly Found near : " + this.location + ".\n";
    }
}

class Plants extends LivingOrganism {
    static String type = "Plant";

    public Plants(String name, String genus, String location) {
        System.out.println("A plant created!!");
        this.name = name;
        this.genus = genus;
        this.location = location;
    }

    public static Plants takeInput() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter name of Plant : ");
        String name = br.readLine();

        System.out.print("Enter genus of Plant : ");
        String genus = br.readLine();

        System.out.print("Enter location of Plant : ");
        String location = br.readLine();

        return new Plants(name, genus, location);
    }

    public String toString() {
        return "The Name of Organism : " + this.name + ".\nType : " + type + ".\nGenus : " + this.genus + ".\nMainly Found near : " + this.location + ".\n";
    }
}

class LOTest {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("1 for Plant.");
        System.out.println("2 for Animal.");
        System.out.println("3 for Human.");
        System.out.println("0 for exit.");

        int ch;

        while (true) {
            System.out.println("Enter what organism to create : ");
            try {
                ch = Integer.parseInt(br.readLine());

                switch (ch) {
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
                        System.out.println("Exited Successfully!!");
                        return;
                    default:
                        throw new InvalidTypeException("Invalid choice. Try again!!");
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a valid number.");
            } catch (IOException e) {
                System.out.println("An error occurred while reading input.");
            } catch (InvalidTypeException e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
