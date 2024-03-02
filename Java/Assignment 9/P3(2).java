import java.io.*;

class DateDifference {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Input for the first date
        System.out.print("Enter the first date (YYYY-MM-DD): ");
        String input1 = br.readLine();
        CustomDate date1 = new CustomDate(input1);

        // Input for the second date
        System.out.print("Enter the second date (YYYY-MM-DD): ");
        String input2 = br.readLine();
        CustomDate date2 = new CustomDate(input2);

        // Calculate the difference in days
        long daysBetween = date1.daysUntil(date2);

        System.out.println("Number of days between the two dates: " + daysBetween);
    }
}

class CustomDate {
    private int year;
    private int month;
    private int day;

    public CustomDate(String dateStr) {
        String[] parts = dateStr.split("-");
        this.year = Integer.parseInt(parts[0]);
        this.month = Integer.parseInt(parts[1]);
        this.day = Integer.parseInt(parts[2]);
    }

    public long daysUntil(CustomDate other) {
        long daysBetween = 0;

        while (!isEqual(other)) {
            incrementDay();
            daysBetween++;
        }

        return daysBetween;
    }

    private boolean isEqual(CustomDate other) {
        return this.year == other.year && this.month == other.month && this.day == other.day;
    }

    private void incrementDay() {
        if (day < daysInMonth(month)) {
            day++;
        } else {
            day = 1;
            if (month < 12) {
                month++;
            } else {
                month = 1;
                year++;
            }
        }
    }

    private int daysInMonth(int month) {
        switch (month) {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    return 29; // Leap year
                } else {
                    return 28;
                }
            default:
                return 31;
        }
    }
}
