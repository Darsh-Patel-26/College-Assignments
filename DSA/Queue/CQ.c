#include <stdio.h>
#define SIZE 5

// Global Variables
int cQueue[SIZE];
int front = -1;
int rear = -1;
int size = 0;

int isEmpty()
{
    return (rear == -1 && front == -1);
}

int inc(int op)
{
    return (op + 1) % SIZE;
}

int isFull()
{
    return (inc(rear) == front );
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("The is Full!!\n");
        return;
    }

    if (isEmpty())
    {
        front = inc(front);
        rear = inc(rear);
        cQueue[rear] = data;
        size++;
        return;
    }
    rear = inc(rear);
    cQueue[rear] = data;
    size++;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("The queue is empty\n");
        return -1;
    }
    if (front == rear)
    {
        int a = cQueue[front];
        front = -1;
        rear = -1;
        size--;
        return a;
    }
    int a = front;
    front = inc(front);
    size--;
    return cQueue[a];
}

int peek()
{
    if (isEmpty())
    {
        printf("The queue is empty\n");
        return -1;
    }
    return cQueue[front];
}

void printQ()
{
    if (isEmpty())
    {
        printf("The queue is empty nothing to diplay!\n");
        return;
    }
    printf("Queue contents: \n");
    while (!isEmpty())
    {
        printf("%d\n",dequeue());
    }
}

void delete()
{
    for (int i = 0; i < SIZE; i++)
    {
        cQueue[i]=0;
    }
    
    front = -1;
    rear = -1;
    printf("Deleted queue succesfully!\n");
}

int main(int argc, char const *argv[])
{
    int ch, data;
    printf("Welcome to Circular Queue Program !!\n");
    printf("1 to Enqueue/Push/Insert.\n");
    printf("2 to Dequeue/Pop/Delete.\n");
    printf("3 to Peek.\n");
    printf("4 to Print Queue.\n");
    printf("5 to determine size of queue.\n");
    printf("6 to delete whole queue.\n");
    printf("0 to exit Program.\n");

loop:
    printf("\nEnter your choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter integer to Enqueue/Push/Insert : ");
        scanf("%d", &data);
        enqueue(data);
        goto loop;
    case 2:
        printf("%d Dequeued/Poped/Deleted succesfully!!(if -1 is shown the queue was empty)\n", dequeue());
        goto loop;
    case 3:
        printf("%d Peeked succesfully!!(if -1 is shown the queue was empty)\n", peek());
        goto loop;
    case 4:
        printQ();
        goto loop;
    case 5:
        printf("The size is : %d\n", size);
        goto loop;
    case 6:
        delete();
        goto loop;
    case 0:
        printf("Exited succesfully!!\n");
        break;
    default:
        printf("Error try again!!\n");
        goto loop;
    }
    return 0;
}