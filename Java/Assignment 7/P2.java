class BankAccount {
    private int balance;

    public BankAccount(int initialBalance) {
        this.balance = initialBalance;
    }

    public void deposit(int amount) {
        balance += amount;
        System.out.println("Deposited: " + amount);
    }

    public void withdraw(int amount) {
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient balance for withdrawal.");
        }
    }
}

class BankWindow {
    private final BankAccount bankAccount;

    public BankWindow(BankAccount account) {
        this.bankAccount = account;
    }

    public void operateDeposit(int amount) {
        bankAccount.deposit(amount);
    }

    public void operateWithdraw(int amount) {
        bankAccount.withdraw(amount);
    }
}

class BankingSystem {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(1000);
        BankWindow depositWindow = new BankWindow(account);
        BankWindow withdrawWindow = new BankWindow(account);

        Thread depositThread = new Thread(() -> {
            int i = 0;
            while (i != 20) {
                depositWindow.operateDeposit(100);
                i++;
            }
        });

        Thread withdrawThread = new Thread(() -> {
            int i = 0;
            while (i != 20) {
                withdrawWindow.operateWithdraw(50);
                i++;
            }
        });

        depositThread.start();
        withdrawThread.start();
    }
}
