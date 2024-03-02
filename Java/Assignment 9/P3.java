import java.io.*;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

class DateDifference2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Input for the first date
        System.out.print("Enter the first date (YYYY-MM-DD): ");
        String input1 = br.readLine();
        LocalDate date1 = LocalDate.parse(input1);

        // Input for the second date
        System.out.print("Enter the second date (YYYY-MM-DD): ");
        String input2 = br.readLine();
        LocalDate date2 = LocalDate.parse(input2);

        // Calculate the difference in days
        long daysBetween = ChronoUnit.DAYS.between(date1, date2);

        System.out.println("Number of days between the two dates: " + Math.abs(daysBetween));
    }
}
