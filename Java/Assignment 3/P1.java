import java.util.Scanner;

/**
 * Represents a time unit in hours.
 */
class Hour 
{
    int hour;

    /**
     * Constructs a new Hour instance with the specified hour value.
     */
    public Hour(int hour) 
    {
        this.hour = hour;
    }
}

/** 
 * Represents a time unit in minutes.
 */
class Minute extends Hour 
{
    int minute;

    /**
     * Constructs a new Minute instance with the specified hour and minute values.
     */
    public Minute(int hour, int minute) 
    {
        super(hour);
        this.minute = minute;
    }
}

/**
 * Represents a time unit in seconds.
 */
class Second extends Minute 
{
    int second;

    /**
     * Constructs a new Second instance with the specified hour, minute, and second values.
     */
    public Second(int hour, int minute, int second) 
    {
        super(hour, minute);
        this.second = second;
    }
}

/**
 * A utility class for working with time calculations and formatting.
 */
class Time 
{
    /**
     * Checks and adjusts time values to ensure minutes and seconds are within valid ranges.
     */
    public static Second checkL60(int h, int m, int s) 
    {
        if (m > 60) 
        {
            m -= 60;
            h++;
        } 
        else if (s > 60) 
        {
            s -= 60;
            m++;
        }
        return new Second(h, m, s);
    }

    /**
     * Reads user input to create a Second instance representing a time value.
     */
    public static Second input() 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Time No. in hour minute second order: ");
        int h = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        return Time.checkL60(h, m, s);
    }

    /**
     * Calculates the elapsed time between two Second instances.
     */
    public static Second elapseTime(Second os1, Second os2) 
    {
        int newHour = os1.hour - os2.hour;
        int newMinute = os1.minute - os2.minute;
        if (newMinute < 0) 
        {
            newHour--;
            newMinute += 60;
        }
        int newSecond = os1.second - os2.second;
        if (newSecond < 0) 
        {
            newMinute--;
            newSecond += 60;
        }

        return new Second(newHour, newMinute, newSecond);
    }

    /**
     * Prints the formatted time values.
     */
    public static void print(Second os) 
    {
        System.out.println(os.hour + "hrs, " + os.minute + "mins, " + os.second + "secs.");
    }

    /**
     * Main method to demonstrate the time calculation and formatting.
     */
    public static void main(String[] args) 
    {
        Second os1 = Time.input();
        Second os2 = Time.input();

        System.out.println("The Elapsed time is :");
        Second os3;
        if (os1.hour >= os2.hour) 
        {
            os3 = Time.elapseTime(os1, os2);
        } 
        else 
        {
            os3 = Time.elapseTime(os2, os1);
        }
        Time.print(os3);
    }
}
