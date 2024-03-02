class ThMain {
    public static final Object key = new Object();
    public static int count = 1;
    public static final int Max_OP = 100;

    public static void main(String[] args) {
        Thread evenThread = new Thread(() -> {
            while (count <= Max_OP) {
                synchronized (key) {
                    if (count % 2 == 0) {
                        System.out.println("Even\t:\t" + count);
                        count++;
                        key.notify();
                    } else {
                        try {
                            key.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        });

        Thread oddThread = new Thread(() -> {
            while (count <= Max_OP) {
                synchronized (key) {
                    if (count % 2 != 0) {
                        System.out.println("Odd\t:\t" + count);
                        count++;
                        key.notify();
                    } else {
                        try {
                            key.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
        });

        evenThread.start();
        oddThread.start();
    }
}