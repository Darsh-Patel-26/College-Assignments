package timePackage;

public class Second extends Minute {
    protected int second;

    /**
     * Constructs a new Second instance with the specified hour, minute, and second values.
     */
    public Second(int hour, int minute, int second) {
        super(hour, minute);
        this.second = second;
    }
}
