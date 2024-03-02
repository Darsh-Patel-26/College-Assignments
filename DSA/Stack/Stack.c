#include <stdio.h>
#define MAX_SIZE 100

// Global Variables
int stack[100];
int top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAX_SIZE - 1);
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack Overflow/Full!\n");
        return;
    }
    stack[++top] = data;
    printf("%d pushed succesfully.\n", data);
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow/Empty!\n");
        return -1;
    }
    int data = stack[top--];

    return data;
}

int peek()
{
    return stack[top];
}

void printStack()
{
    if (isEmpty())
    {
        printf("The Stack is empty, nothing to print!\n");
        return;
    }
    while (!isEmpty())
    {
        printf("%d\n", pop());
    }
}

int main()
{
    int data;
    int ch;
    
    printf("1 for push.\n");
    printf("2 for pop.\n");
    printf("3 for peek.\n");
    printf("4 for print stack.\n");
    printf("0 to exit.\n");

loop:
    printf("\nEnter operation to perform : ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter data to push : ");
        scanf("%d", &data);
        push(data);
        goto loop;

    case 2:
        printf("%d poped succesfully.\n", pop());
        goto loop;

    case 3:
        printf("%d peeked.\n", peek());
        goto loop;

    case 4:
        printf("Your stack is :\n");
        printStack();
        goto loop;

    case 0:
        printf("Exited Successfully!!\n");
        break;

    default:
        printf("Error, Try again!!\n");
        goto loop;
    }

    return 0;
}