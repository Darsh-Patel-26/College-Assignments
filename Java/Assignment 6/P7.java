import java.io.*;

class ComplexOperator {
    public static void main(String[] args) {
        Complex oc1 = ComplexOperator.takeInput();
        Complex oc2 = ComplexOperator.takeInput();

        System.out.println("1st num : " + oc1.print());
        System.out.println("2nd num : " + oc2.print());

        try {
            Complex addition = oc1.add(oc2);
            System.out.println("Addition : " + addition.print());

            Complex subtraction = oc1.subtract(oc2);
            System.out.println("Subtraction : " + subtraction.print());

            Complex multiplication = oc1.multiply(oc2);
            System.out.println("Multiplication : " + multiplication.print());

            Complex division = oc1.divide(oc2);
            System.out.println("Division : " + division.print());
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        }
    }

    public static Complex takeInput() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Enter real and imaginary : ");
            String input = br.readLine();
            String[] parts = input.split(" ");
            
            if (parts.length != 2) {
                System.out.println("Invalid input format. Please enter real and imaginary parts separated by space.");
                return takeInput(); // Ask for input again if it's not in the correct format.
            }
            
            float real = Float.parseFloat(parts[0]);
            float imaginary = Float.parseFloat(parts[1]);
            
            return new Complex(real, imaginary);
        } catch (IOException e) {
            System.out.println("Error reading input.");
            return null;
        } catch (NumberFormatException e) {
            System.out.println("Invalid input format. Please enter real and imaginary parts as numbers.");
            return takeInput(); // Ask for input again if parsing fails.
        }
    }
}

class Complex {
    private float real;
    private float imaginary;

    public Complex(float real, float imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public String print() {
        if (this.imaginary >= 0) {
            return this.real + " + " + this.imaginary + "i";
        }
        return this.real + " - " + Math.abs(this.imaginary) + "i";
    }

    public Complex add(Complex oc2) {
        float realSum = this.real + oc2.real;
        float imaginarySum = this.imaginary + oc2.imaginary;
        return new Complex(realSum, imaginarySum);
    }

    public Complex subtract(Complex oc2) {
        float realDiff = this.real - oc2.real;
        float imaginaryDiff = this.imaginary - oc2.imaginary;
        return new Complex(realDiff, imaginaryDiff);
    }

    public Complex multiply(Complex oc2) {
        float realProduct = (this.real * oc2.real) - (this.imaginary * oc2.imaginary);
        float imaginaryProduct = (this.real * oc2.imaginary) + (this.imaginary * oc2.real);
        return new Complex(realProduct, imaginaryProduct);
    }

    public Complex divide(Complex oc2) throws ArithmeticException {
        float denominator = (oc2.real * oc2.real) + (oc2.imaginary * oc2.imaginary);
        if (denominator == 0) {
            throw new ArithmeticException("Division by zero");
        }
        float realQuotient = ((this.real * oc2.real) - (this.imaginary * oc2.imaginary)) / denominator;
        float imaginaryQuotient = ((this.real * oc2.imaginary) + (this.imaginary * oc2.real)) / denominator;
        return new Complex(realQuotient, imaginaryQuotient);
    }
}
