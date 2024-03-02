import java.util.*;

class VectorOperator {
    public static void main(String[] args) {
        Vector ov1 = VectorOperator.takeInput();
        Vector ov2 = VectorOperator.takeInput();

        System.out.println("First vector : " + ov1.print());
        System.out.println("Second vector : " + ov2.print());

        System.out.println("The Scalar Product is : " + ov1.scalarProduct(ov2));

        Vector vectorProduct = ov1.vectorProduct(ov2);
        System.out.println("The Vector Product of vectors is : " + vectorProduct.print());
    }

    public static Vector takeInput() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x, y, z of vector : ");
        float x = sc.nextFloat();
        float y = sc.nextFloat();
        float z = sc.nextFloat();

        return new Vector(x, y, z);
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

    public Vector vectorProduct(Vector ov2) {
        float x = this.y * ov2.z - this.z * ov2.y;
        float y = this.x * ov2.z - this.z * ov2.x;
        float z = this.x * ov2.y - this.y * ov2.x;
        return new Vector(x, -y, z);
    }
}
