package timePackage;

import java.io.*;

public class Time {
    /**
     * Checks and adjusts time values to ensure minutes and seconds are within valid
     * ranges.
     */
    public static Second checkL60(int h, int m, int s) {
        if (m > 60) {
            m -= 60;
            h++;
        } else if (s > 60) {
            s -= 60;
            m++;
        }
        return new Second(h, m, s);
    }

    /**
     * Reads user input to create a Second instance representing a time value.
     */
    public static Second input() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int h, m, s;
        try {
            System.out.print("Enter Time No. in hour : ");
            h = Integer.parseInt(br.readLine());
            System.out.print("Enter Time No. in minute : ");
            m = Integer.parseInt(br.readLine());
            System.out.print("Enter Time No. in second : ");
            s = Integer.parseInt(br.readLine());

            return Time.checkL60(h, m, s);
        } catch (IOException ioe) {
        } catch (NumberFormatException nfe) {
        }

        return null;
    }

    /**
     * Calculates the elapsed time between two Second instances.
     */
    public static Second elapseTime(Second os1, Second os2) {
        int newHour = os1.hour - os2.hour;
        int newMinute = os1.minute - os2.minute;
        if (newMinute < 0) {
            newHour--;
            newMinute += 60;
        }
        int newSecond = os1.second - os2.second;
        if (newSecond < 0) {
            newMinute--;
            newSecond += 60;
        }

        return new Second(newHour, newMinute, newSecond);
    }

    /**
     * Prints the formatted time values.
     */
    public static void print(Second os) {
        System.out.println(os.hour + "hrs, " + os.minute + "mins, " + os.second + "secs.");
    }
}
