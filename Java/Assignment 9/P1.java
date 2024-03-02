import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class SubstringFinder {
    public static int countOccurrences(String input, String substring) {
        int count = 0;
        int index = input.indexOf(substring);
        while (index != -1) {
            count++;
            index = input.indexOf(substring, index + 1);
        }
        return count;
    }

    public static void findAndPrintOccurrences(String input, String substring) {
        int index = input.indexOf(substring);
        while (index != -1) {
            System.out.print(index);
            index = input.indexOf(substring, index + 1);
            if (index != -1) {
                System.out.print(", ");
            }
        }
        System.out.println();
    }
}

class SubstringOccurrences {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.print("Enter the number of strings: ");
        int numStrings = Integer.parseInt(reader.readLine());

        String[] stringArray = new String[numStrings];

        for (int i = 0; i < numStrings; i++) {
            System.out.print("Enter string " + (i + 1) + ": ");
            stringArray[i] = reader.readLine();
        }

        System.out.print("Enter the substring you want to search for: ");
        String substringToFind = reader.readLine();

        for (int i = 0; i < stringArray.length; i++) {
            String inputString = stringArray[i];
            int count = SubstringFinder.countOccurrences(inputString, substringToFind);

            System.out.println("String " + (i + 1) + ": " + inputString);
            System.out.println("Total occurrences of '" + substringToFind + "': " + count);

            if (count > 0) {
                System.out.print("Positions of occurrences: ");
                SubstringFinder.findAndPrintOccurrences(inputString, substringToFind);
            }

            System.out.println("\n");
        }
    }
}
