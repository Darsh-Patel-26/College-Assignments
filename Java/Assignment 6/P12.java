import java.io.*;

// Custom exception for invalid shape inputs
class InvalidShapeException extends Exception {
    public InvalidShapeException(String message) {
        super(message);
    }
}

abstract class Shape {
    public float area() {
        return 0;
    }

    public float volume() {
        return 0;
    }
}

class Cube extends Shape {
    float edge;

    public Cube(float edge) {
        this.edge = edge;
    }

    public float getEdge() {
        return this.edge;
    }

    public float area() {
        return 6 * this.edge * this.edge;
    }

    public float volume() {
        return this.edge * this.edge * this.edge;
    }
}

class Square extends Shape {
    float side;

    public Square(float side) {
        this.side = side;
    }

    public float getSide() {
        return this.side;
    }

    public float area() {
        return this.side * this.side;
    }

    public float volume() {
        System.out.println("The volume is undefined as a square is a 2D shape.");
        return 0;
    }
}

class ShapeTest {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            float side, edge;

            System.out.print("Enter Size of side of square : ");
            side = Float.parseFloat(br.readLine());

            System.out.print("Enter Size of edge of cube : ");
            edge = Float.parseFloat(br.readLine());

            if (side <= 0 || edge <= 0) {
                throw new InvalidShapeException("Side and edge lengths must be greater than 0.");
            }

            Shape os1 = new Square(side);
            Shape oc1 = new Cube(edge);

            System.out.println("The area of Square is : " + os1.area());
            System.out.println("The area of Cube is : " + oc1.area());

            System.out.println("The volume of Square is : " + os1.volume());
            System.out.println("The volume of Cube is : " + oc1.volume());
        } catch (IOException e) {
            System.out.println("An error occurred while reading input.");
        } catch (NumberFormatException e) {
            System.out.println("Invalid input format. Please enter a valid number.");
        } catch (InvalidShapeException e) {
            System.out.println("Invalid shape input: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        }
    }
}
