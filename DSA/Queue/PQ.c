#include <stdio.h>
#define SIZE 10

struct PQ
{
    int data;
    int priority;
} pq[SIZE];

int rear = -1;

int isEmpty()
{
    return (rear == -1);
}

int isFull()
{
    return (rear == SIZE - 1);
}

void enqueue(int data, int priority)
{
    if (isFull())
    {
        printf("Queue is Full!!\n");
        return;
    }
    rear++;
    pq[rear].data = data;
    pq[rear].priority = priority;
    printf("%d is in queue with %d priority!!\n", pq[rear].data, pq[rear].priority);
}

int highestPriority()
{
    int i, p = -1;
    if (!isEmpty())
    {
        for (i = 0; i <= rear; i++)
        {
            if (pq[i].priority >= p)
            {
                p = pq[i].priority;
            }
        }
    }
    return p;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("The queue is empty!!\n");
        return -1;
    }
    int i, j, p, data;
    p = highestPriority();
    for (i = 0; i <= rear; i++)
    {
        if (pq[i].priority == p)
        {
            data = pq[i].data;
            break;
        }
    }
    if (i < rear)
    {
        for (j = i; j <= rear; j++)
        {
            pq[j].data = pq[j + 1].data;
            pq[j].priority = pq[j + 1].priority;
        }
    }
    rear = rear - 1;
    return data;
}

void printQ()
{
    if (isEmpty())
    {
        printf("The queue is empty nothing to display!\n");
        return;
    }
    printf("Your Priority Queue is :\n");
    for (int i = 0; i <= rear; i++)
    {
        printf("Data : %d, Priority : %d\n", pq[i].data, pq[i].priority);
    }
}

int main(int argc, char const *argv[])
{
    int ch, data, priority;
    printf("Welcome to Priority Queue Program !!\n");
    printf("1 to Enqueue/Push/Insert.\n");
    printf("2 to Dequeue/Pop/Delete.\n");
    printf("3 to Print Queue.\n");
    printf("0 to exit Program.\n");

loop:
    printf("\nEnter your choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter integer to Enqueue/Push/Insert : ");
        scanf("%d", &data);
        printf("Enter the priority of it : ");
        scanf("%d", &priority);
        enqueue(data, priority);
        goto loop;
    case 2:
        printf("%d Dequeued/Poped/Deleted succesfully!!(if -1 is shown the queue was empty)\n", dequeue());
        goto loop;
    case 3:
        printQ();
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