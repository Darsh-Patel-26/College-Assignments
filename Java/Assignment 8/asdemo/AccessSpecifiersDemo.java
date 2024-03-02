// Package declaration
package asdemo;

// Class with different access specifiers
public class AccessSpecifiersDemo {
    // Public variable
    public int publicVar = 10;

    // Private variable
    private int privateVar = 20;

    // Default (package-private) variable
    int defaultVar = 30;

    // Protected variable
    protected int protectedVar = 40;

    // Public constructor
    public AccessSpecifiersDemo() {
        System.out.println("Inside public constructor");
    }

    // Private method
    private void privateMethod() {
        System.out.println("Inside private method");
    }

    // Default (package-private) method
    void defaultMethod() {
        System.out.println("Inside default method");
    }

    // Protected method
    protected void protectedMethod() {
        System.out.println("Inside protected method");
    }

    // Public method
    public void publicMethod() {
        System.out.println("Inside public method");
    }
}
