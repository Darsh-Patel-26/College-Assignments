/**
 * This is the base abstract class representing a Vehicle.
 */
abstract class Vehicle 
{
    private String brand;
    private String model;
    private int year;

    public Vehicle(String brand, String model, int year) 
    {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }

    /**
     * Returns the brand of the vehicle.
     */
    public String getBrand() 
    {
        return brand;
    }

    /**
     * Returns the model of the vehicle.
     */
    public String getModel() 
    {
        return model;
    }

    /**
     * Returns the manufacturing year of the vehicle.
     */
    public int getYear() 
    {
        return year;
    }

    /**
     * Returns a string representation of the Vehicle object.
     */
    public String toString() 
    {
        return "Brand: " + brand + ", Model: " + model + ", Year: " + year;
    }

    // Abstract method to be implemented by subclasses
    public abstract String getType();
}

/**
 * This is a derived class representing a Car, which inherits from the Vehicle class.
 */
class Car extends Vehicle 
{
    private int numDoors;

    public Car(String brand, String model, int year, int numDoors) 
    {
        super(brand, model, year);
        this.numDoors = numDoors;
    }

    /**
     * Returns the number of doors of the car.
     */
    public int getNumDoors() 
    {
        return numDoors;
    } 

    /**
     * Returns a string representation of the Car object.
     */
    public String toString() 
    {
        return super.toString() + ", Number of Doors: " + numDoors;
    }

    @Override
    public String getType() 
    {
        return "Car";
    }
}

/**
 * This is a derived class representing a Bike, which inherits from the Vehicle class.
 */
class Bike extends Vehicle 
{
    private boolean hasBasket;

    public Bike(String brand, String model, int year, boolean hasBasket) 
    {
        super(brand, model, year);
        this.hasBasket = hasBasket;
    }

    /**
     * Returns whether the bike has a basket.
     */
    public boolean hasBasket() 
    {
        return hasBasket;
    }

    /**
     * Returns a string representation of the Bike object.
     */
    public String toString() 
    {
        return super.toString() + ", Has Basket: " + hasBasket;
    }

    @Override
    public String getType() 
    {
        return "Bike";
    }
}

/**
 * A simple demonstration of the Vehicle class, Car subclass, Bike subclass, and SportsCar subclass.
 */
class VMain 
{
    public static void main(String[] args) 
    {
        // Create a Bike object
        Vehicle ob1 = new Bike("Kawasaki", "Ninja", 2019, false);
        System.out.println("Bike Details: \n" + ob1);
        System.out.println("Type: " + ob1.getType());

        // Create a Car object
        Vehicle ob2 = new Car("Koniggsegg", "Jesko", 2019, 2);
        System.out.println("Car details :\n"+ob2);
        System.out.println("Type: "+ob2.getType());
    }
}
