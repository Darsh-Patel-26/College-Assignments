package timePackage;

public class Minute extends Hour {
    protected int minute;

    /**
     * Constructs a new Minute instance with the specified hour and minute values.
     */
    public Minute(int hour, int minute) {
        super(hour);
        this.minute = minute;
    }
}
