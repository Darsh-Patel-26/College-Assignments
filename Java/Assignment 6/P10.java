import java.io.*;

abstract class Vehicle {
    private String brand;
    private String model;
    private int year;

    public Vehicle() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter brand: ");
            this.brand = br.readLine();
            System.out.print("Enter model: ");
            this.model = br.readLine();
            System.out.print("Enter year: ");
            this.year = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
        }
    }

    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    public int getYear() {
        return year;
    }

    public String toString() {
        return "Brand: " + brand + ", Model: " + model + ", Year: " + year;
    }

    public abstract String getType();
}

class Car extends Vehicle {
    private int numDoors;

    public Car() {
        super();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter number of doors: ");
            this.numDoors = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
        }
    }

    public int getNumDoors() {
        return numDoors;
    }

    public String toString() {
        return super.toString() + ", Number of Doors: " + numDoors;
    }

    @Override
    public String getType() {
        return "Car";
    }
}

class Bike extends Vehicle {
    private boolean hasBasket;

    public Bike() {
        super();
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Does it have a basket? (true/false): ");
            this.hasBasket = Boolean.parseBoolean(br.readLine());
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
        }
    }

    public boolean hasBasket() {
        return hasBasket;
    }

    public String toString() {
        return super.toString() + ", Has Basket: " + hasBasket;
    }

    @Override
    public String getType() {
        return "Bike";
    }
}

class VMain {
    public static void main(String[] args) {
        // Create a Bike object
        Vehicle ob1 = new Bike();
        System.out.println("Bike Details: \n" + ob1);
        System.out.println("Type: " + ob1.getType());

        // Create a Car object
        Vehicle ob2 = new Car();
        System.out.println("Car details :\n" + ob2);
        System.out.println("Type: " + ob2.getType());
    }
}
