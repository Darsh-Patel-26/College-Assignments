class Vehicle {
    private String brand;
    private String model;

    public Vehicle(String brand, String model) {
        this.brand = brand;
        this.model = model;
    }

    public void startEngine() {
        System.out.println("Starting the vehicle's engine.");
    }

    public String getBrand() {
        return this.brand;
    }

    public String getModel() {
        return this.model;
    }
}

class Car extends Vehicle {
    private int numOfDoors;

    public Car(String brand, String model, int numOfDoors) {
        super(brand, model);
        this.numOfDoors = numOfDoors;
    }

    @Override
    public void startEngine() {
        System.out.println("Starting the car's engine.");
    }

    public int getNumOfDoors() {
        return this.numOfDoors;
    }
}

class Motorcycle extends Vehicle {
    private boolean hasSideCar;

    public Motorcycle(String brand, String model, boolean hasSideCar) {
        super(brand, model);
        this.hasSideCar = hasSideCar;
    }

    @Override
    public void startEngine() {
        System.out.println("Starting the motorcycle's engine.");
    }

    public boolean hasSideCar() {
        return this.hasSideCar;
    }
}

class VehicleTest {
    public static void main(String[] args) {
        Vehicle ov1 = new Car("Koenigsegg", "Jesko", 2);
        Vehicle ov2 = new Motorcycle("Royal Enfield", "Classic 350", false);

        // Below code Gives error due to object slicing
        //System.out.println("Number of doors in the car: " + ov1.getNumOfDoors());
        //System.out.println("Does the motorcycle have a sidecar? " + ov2.hasSideCar());

        // Runtime Polymorphic method calls
        ov1.startEngine();
        ov2.startEngine(); 
    }
}
