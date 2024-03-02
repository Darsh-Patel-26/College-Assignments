class Market {
    static int resource;
    int capacity;

    public Market(int capacity) {
        this.capacity = capacity;
    }

    synchronized void produce() {
        System.out.println("Produced total = " + (resource+1));
        resource++;
    }

    synchronized void consume() {
        System.out.println("Consumed total = " + (resource-1));
        resource--;
    }
}

public class PC {
    public static void main(String[] args) {
        final Object lock = new Object();
        Market om = new Market(5);

        Thread producer = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                synchronized (lock) {
                    if (Market.resource != om.capacity) {
                        om.produce();
                        lock.notifyAll();
                    }
                    else{
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        });

        Thread consumer = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                synchronized (lock) {
                    if (Market.resource != 0) {
                        om.consume();
                        lock.notifyAll();
                    }
                    else{
                        try {
                            lock.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        });

        producer.start();
        consumer.start();
    }
}