package shapePackage;

public class Cube extends Shape {
    float edge;
 
    public Cube(float edge){
        this.edge = edge;
    }
    public float getEdge(){
        return this.edge;
    }
    public float area(){
        return 6*this.edge*this.edge;
    }
    public float volume(){
        return this.edge*this.edge*this.edge;
    }
}
 