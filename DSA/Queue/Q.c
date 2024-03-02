#include <stdio.h>
#define MAX_SIZE 100

// Global Variables
int queue[100];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is Full!!\n");
        return;
    }
    if (isEmpty())
    {
        front++;
        rear++;
        queue[rear] = data;
        printf("%d is in queue!!\n",data);
        return;
    }
    queue[++rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    if (front == rear)
    {
        int a = queue[front];
        front = rear = -1;
        return a;
    }

    return queue[front++];
}

int peek()
{
    if (isEmpty())
        return -1;

    return queue[front];
}

void printQ()
{
    if (isEmpty())
    {
        printf("The queue is empty nothing to display!\n");
        return;
    }
    printf("Your Queue is :\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n",queue[i]);
    }
}

void deleteQ()
{
    front = -1;
    rear = -1;
    if (isEmpty())
    {
        printf("Queue deleted successfully!!\n");
    }
}

int main(int argc, char const *argv[])
{
    int ch, data;
    printf("Welcome to simple Queue Program !!\n");
    printf("1 to Enqueue/Push/Insert.\n");
    printf("2 to Dequeue/Pop/Delete.\n");
    printf("3 to Peek.\n");
    printf("4 to Print Queue.\n");
    printf("5 to Delete whole Queue.\n");
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
        deleteQ();
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