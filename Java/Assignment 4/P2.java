import shapePackage.*;
import java.io.*;

class ShapeTest {
    public static void main(String[] args) throws IOException,NumberFormatException,Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        System.out.print("Enter Size of side of square : ");
        float side = Float.parseFloat(br.readLine());

        System.out.print("Enter Size of edge of cube : ");
        float edge = Float.parseFloat(br.readLine());

        Shape os1 = new Square(side);
        Shape oc1 = new Cube(edge);

        // Below comments shows error due to Object Slicing
        // System.out.println("The Side of Square is : "+os1.getSide());
        // System.out.println("The Edge of Cube is : "+oc1.getEdge());

        // Below code displays significance of runtime polymorphism
        System.out.println("The area of Square is : "+os1.area());
        System.out.println("The area of Cube is : "+oc1.area());

        System.out.println("The volume of Square is : "+os1.volume());
        System.out.println("The volume of Cube is : "+oc1.volume());
    }
}