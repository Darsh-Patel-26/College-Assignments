import asdemo.*;

class ExternalMain {
    public static void main(String[] args) {
        AccessSpecifiersDemo obj = new AccessSpecifiersDemo();

        // Accessing variables
        System.out.println("Public variable: " + obj.publicVar);

        // Cannot access private variable
        // System.out.println("Private variable: " + obj.privateVar);   
        
        // Cannot access outside package
        // System.out.println("Default variable: " + obj.defaultVar);

        // Cannot access until inherited
        // System.out.println("Protected variable: " + obj.protectedVar);

        // Accessing methods
        obj.publicMethod();

        // Cannot access private method
        // obj.privateMethod(); 

        // Cannot access outside package
        // obj.defaultMethod();

        // Cannot access until inherited
        // obj.protectedMethod();
    }
    
}

class InheritedMain extends AccessSpecifiersDemo {
    public static void main(String [] args) {
        InheritedMain obj = new InheritedMain();

        // Accessing variables
        System.out.println("Public variable: " + obj.publicVar);

        // Cannot access private method
        // System.out.println("Private variable: " + obj.privateVar);   
        
        // Cannot access outside package
        // System.out.println("Default variable: " + obj.defaultVar);

        System.out.println("Protected variable: " + obj.protectedVar);

        // Accessing methods
        obj.publicMethod();

        // Cannot access private method
        // obj.privateMethod(); 

        // Cannot access outside package
        // obj.defaultMethod();

        obj.protectedMethod();
    }
}