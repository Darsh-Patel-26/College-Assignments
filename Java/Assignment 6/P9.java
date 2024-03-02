import java.io.*;

class InvalidHourException extends Exception {
    public InvalidHourException(String message) {
        super(message);
    }
}

class InvalidMinuteException extends Exception {
    public InvalidMinuteException(String message) {
        super(message);
    }
} 

class InvalidSecondException extends Exception {
    public InvalidSecondException(String message) {
        super(message);
    }
}

class Hour {
    int hour;

    public Hour(int hour) {
        this.hour = hour;
    }
}

class Minute extends Hour {
    int minute;

    public Minute(int hour, int minute) {
        super(hour);
        this.minute = minute;
    }
}

class Second extends Minute {
    int second;

    public Second(int hour, int minute, int second) throws InvalidHourException, InvalidMinuteException, InvalidSecondException {
        super(hour, minute);
        if (hour < 0 || hour > 24) {
            throw new InvalidHourException("Invalid hour value. Hour must be between 0 and 23.");
        }
        if (minute < 0 || minute > 60) {
            throw new InvalidMinuteException("Invalid minute value. Minute must be between 0 and 59.");
        }
        if (second < 0 || second > 60) {
            throw new InvalidSecondException("Invalid second value. Second must be between 0 and 59.");
        }
        this.second = second;
    }
}

class Time {
    public static Second checkL60(int h, int m, int s) throws InvalidHourException, InvalidMinuteException, InvalidSecondException {
        if (m >= 60) {
            m %= 60;
            h += m / 60;
        } else if (s >= 60) {
            s %= 60;
            m += s / 60;
        }
        return new Second(h, m, s);
    }

    public static Second input() {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.print("Enter Time No. in hour minute second order: ");
            String input = br.readLine();
            String[] parts = input.split(" ");
            
            if (parts.length != 3) {
                throw new IllegalArgumentException("Invalid input format. Please enter hour, minute, and second separated by spaces.");
            }
            
            int h = Integer.parseInt(parts[0]);
            int m = Integer.parseInt(parts[1]);
            int s = Integer.parseInt(parts[2]);
            
            return new Second(h, m, s);
        } catch (IOException e) {
            System.out.println("Error reading input.");
            return null;
        } catch (NumberFormatException e) {
            System.out.println("Invalid input format. Please enter valid numbers.");
            return null;
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
            return null;
        } catch (InvalidHourException | InvalidMinuteException | InvalidSecondException e) {
            System.out.println(e.getMessage());
            return null;
        }
    }

    public static Second elapseTime(Second os1, Second os2) throws InvalidHourException, InvalidMinuteException, InvalidSecondException {
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

    public static void print(Second os) {
        System.out.println(os.hour + "hrs, " + os.minute + "mins, " + os.second + "secs.");
    }
}

class TMain {
    public static void main(String[] args) {
        Second os1 = Time.input();
        Second os2 = Time.input();

        System.out.println("The Elapsed time is :");
        Second os3;
        if (os1.hour >= os2.hour) {
            try {
                os3 = Time.elapseTime(os1, os2);
                Time.print(os3);
            } catch (InvalidHourException | InvalidMinuteException | InvalidSecondException e) {
                e.printStackTrace();
            }
        } else {
            try {
                os3 = Time.elapseTime(os2, os1);
                Time.print(os3);
            } catch (InvalidHourException | InvalidMinuteException | InvalidSecondException e) {
                e.printStackTrace();
            }
        }
    }
}
