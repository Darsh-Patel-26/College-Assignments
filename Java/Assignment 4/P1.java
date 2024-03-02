import timePackage.Time;
import timePackage.Second;

class TimeTest {
    public static void main(String[] args) {
        Second os1 = Time.input();
        Second os2 = Time.input();

        System.out.println("The Elapsed time is :");
        Second os3;
        if (os1.hour>=os2.hour) {
            os3 = Time.elapseTime(os1, os2);
        }else{
            os3 = Time.elapseTime(os2, os1);
        }
        Time.print(os3);
    }
}
