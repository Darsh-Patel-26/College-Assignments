import java.io.*;

class VectorOperator {
    public static void main(String[] args) {
        Vector ov1 = VectorOperator.takeInput();
        Vector ov2 = VectorOperator.takeInput();

        System.out.println("First vector : " + ov1.print());
        System.out.println("Second vector : " + ov2.print());

        try {
            float scalarProduct = ov1.scalarProduct(ov2);
            System.out.println("The Scalar Product is : " + scalarProduct);

            Vector vectorProduct = ov1.vectorProduct(ov2);
            System.out.println("The Vector Product of vectors is : " + vectorProduct.print());
        } catch (ParallelVectorsException e) {
            System.out.println("Error: Vectors are parallel. Vector product is undefined.");
        }
    }

    public static Vector takeInput() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            System.out.print("Enter x, y, z of vector : ");
            String input = br.readLine();
            String[] parts = input.split(" ");

            if (parts.length != 3) {
                throw new InvalidInputException("Invalid input format. Please enter x, y, and z separated by spaces.");
            }

            // Intentionally enter a non-numeric string for 'z' to trigger NumberFormatException
            float x = Float.parseFloat(parts[0]);
            float y = Float.parseFloat(parts[1]);
            float z = Float.parseFloat(parts[2]);
            // float z = Float.parseFloat("InvalidInput");

            return new Vector(x, y, z);
        } catch (IOException e) {
            System.out.println("Error reading input.");
            return null;
        } catch (NumberFormatException e) {
            System.out.println("Invalid input format. Please enter x, y, and z as numbers.");
            return takeInput();
        } catch (InvalidInputException e) {
            System.out.println(e.getMessage());
            return takeInput();
        }
    }
}

class Vector {
    private float x;
    private float y;
    private float z;

    public Vector(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public String print() {
        return "(" + this.x + ")i + (" + this.y + ")j + (" + this.z + ")k";
    }

    public float scalarProduct(Vector ov2) {
        return ((this.x * ov2.x) + (this.y * ov2.y) + (this.z * ov2.z));
    }

    public Vector vectorProduct(Vector ov2) throws ParallelVectorsException {
        float x = this.y * ov2.z - this.z * ov2.y;
        float y = this.z * ov2.x - this.x * ov2.z;
        float z = this.x * ov2.y - this.y * ov2.x;

        if (x == 0 && y == 0 && z == 0) {
            throw new ParallelVectorsException("Vectors are parallel.");
        }

        return new Vector(x, y, z);
    }
}

class InvalidInputException extends Exception {
    public InvalidInputException(String message) {
        super(message);
    }
}

class ParallelVectorsException extends Exception {
    public ParallelVectorsException(String message) {
        super(message);
    }
}
