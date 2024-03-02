class Stack {
    int maxSize;
    int[] stackArray;
    int top;

    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    public void push(int data) {
        if (this.top == maxSize - 1) {
            System.out.println("Stack Is FUll");
        } else {
            stackArray[++top] = data;

            System.out.println(data + " is Pushed");
        }
    }

    public void pop() {
        if (this.top == -1) {
            System.out.println("Stack Is Empty");
        } else {
            System.out.println(this.stackArray[top] + " is Poped");
            this.top = this.top - 1;
        }
    }
}

class StackMain {
    public static void main(String[] args) {
        Stack stack = new Stack(10);

        Thread pushThread = new Thread(() -> {
            for (int i = 0; i < stack.maxSize - 1; i++) {
                stack.push((int) (Math.random() * 100));
            }
        });

        Thread popThread = new Thread(() -> {
            for (int i = 1; i <= stack.maxSize; i++) {
                if (!(stack.top == -1)) {
                    stack.pop();
                } else
                    System.out.println("cant pop");
            }
        });

        pushThread.start();
        popThread.start();
    }
}
