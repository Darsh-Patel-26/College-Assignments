package shapePackage;

public class Square extends Shape {
    float side;

    public Square(float side){
        this.side = side;
    }
    public float getSide(){
        return this.side;
    }
    public float area(){
        return this.side*this.side;
    }
    public float volume(){
        System.out.println("The volume is undefined as square is a 2D shape.");
        return 0;
    } 
} 
