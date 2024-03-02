class Shared {
    static int i = 0;
    static Object lock = new Object();
    boolean flag = false;
}

class P implements Runnable {

    Shared s;

    P(Shared t) {
        s = t;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            synchronized (Shared.lock) {

                if (i < 1) {
                    System.out.println("Produced");
                    Shared.i++;
                    try {
                        Shared.lock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    Shared.lock.notifyAll();
                } else {
                    
                }

            }
        }
    }
}

class C implements Runnable {
    Shared s;

    C(Shared t) {
        s = t;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {

            synchronized (Shared.lock) {

                if (i > 0) {
                    System.out.println("Consumed");
                    Shared.i--;
                    try {
                        Shared.lock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    Shared.lock.notifyAll();
                } else {
                    
                }

            }
        }
    }
}

class Main {
    public static void main(String[] args) {
        Shared s = new Shared();
        P p = new P(s);
        C c = new C(s);

        Thread t1 = new Thread(p);
        Thread t2 = new Thread(c);

        t1.start();
        t2.start();
    }
}