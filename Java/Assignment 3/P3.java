// LivingOrganism.java - The base class for all living organisms
class LivingOrganism 
{
    protected String name;
    
    public LivingOrganism(String name) 
    {
        this.name = name;
    }

    public void eat() 
    {
        System.out.println(name + " is eating.");
    }

    public void breathe() 
    {
        System.out.println(name + " is breathing.");
    }

    public void reproduce() 
    {
        System.out.println(name + " is reproducing.");
    }

    public void move() 
    {
        System.out.println(name + " is moving.");
    }
}

// Plant.java - Represents a plant which is a type of living organism
class Plant extends LivingOrganism 
{
    public Plant(String name) 
    {
        super(name);
    }

    @Override
    public void move() 
    {
        System.out.println(name + " cannot move.");
    }
}

// Animal.java - Represents an animal which is a type of living organism
class Animal extends LivingOrganism 
{
    public Animal(String name) 
    {
        super(name);
    } 

    public static Human takeInput() {
        return null;
    }
}

// Human.java - Represents a human which is a type of animal
class Human extends Animal 
{
    public Human(String name) 
    {
        super(name);
    }

    public void speak() 
    {
        System.out.println(name + " is speaking.");
    }
}

// Main.java - The main class to demonstrate the Living Organisms hierarchy
class AnimalMain 
{
    public static void main(String[] args) 
    {
        Plant tree = new Plant("Tree");
        tree.move();    // Output: Tree cannot move.
        tree.eat();     // Output: Tree is eating.
        tree.breathe(); // Output: Tree is breathing.
        tree.reproduce(); // Output: Tree is reproducing.

        Animal lion = new Animal("Lion");
        lion.move();    // Output: Lion is moving.
        lion.eat();     // Output: Lion is eating.
        lion.breathe(); // Output: Lion is breathing.
        lion.reproduce(); // Output: Lion is reproducing.

        Human person = new Human("John");
        person.move();    // Output: John is moving.
        person.eat();     // Output: John is eating.
        person.breathe(); // Output: John is breathing.
        person.reproduce(); // Output: John is reproducing.
        person.speak();   // Output: John is speaking.
    }
}
