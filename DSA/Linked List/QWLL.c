#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *initializer(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

struct Queue
{
    struct Node *front;
    struct Node *rear;
}*queue;

struct Queue *constructor()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;

    return q;
}

int isEmpty()
{
    return queue->front == NULL && queue->rear == NULL;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue Underflow, Nothing to display!!");
        return;
    }
    struct Node* temp = queue->front;
    printf("Your queue is :\n");
    while (temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("Null\n\n");
    free(temp);
}

void enqueue(int data)
{
    struct Node *newNode = initializer(data);
    if (isEmpty())
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow, Nothing to dequeue!!");
        return -1;
    }
    
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    return data;
}

void main()
{
    int ch, data;
    queue = constructor();

    printf("Enter operation :\n");
    printf("1 to Enqueue.\n");
    printf("2 to Dequeue.\n");
    printf("0 to exit.\n");

    while (1)
    {
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to enqueue : ");
            scanf("%d",&data);
            enqueue(data);
            display();
            break;

        case 2:
            printf("Dequeued element : %d\n",dequeue());
            display();
            break;

        case 0:
            printf("Succesfully exited\n");
            return;
        
        default:
            printf("Error Try again!!");
            break;
        }
    }
}