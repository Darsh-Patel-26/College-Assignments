#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// Stack Structure
struct Stack
{
    int *arr;
    int top;
    char name;
};

// Creates a Stack
struct Stack initializer(char name, int size)
{
    struct Stack stack;
    stack.top = -1;
    stack.name = name;
    stack.arr = (int *)malloc(size * sizeof(int));

    return stack;
}

// Checks stack is full or not
int isFull(struct Stack *stack)
{
    return (stack->top == MAXSIZE - 1);
}

// Checks if Stack is Empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Pushes data on top of Stack
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow/Full!!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

// Removes and Returns top data of Stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow/Empty!!\n");
        return -1;
    }

    int data = stack->arr[stack->top];
    stack->top--;

    return data;
}

// Returns top data of Stack
int peek(struct Stack *stack)
{
    return stack->arr[stack->top];
}

// Prints Stack
void printStack(struct Stack *stack)
{
    while (!isEmpty(stack))
    {
        int data = pop(stack);
        printf("\n%d", data);
    }
    printf("\n");
}

// Add disks to Source Tower
void addDisksInSrc(int disks, struct Stack *src)
{
    while (disks)
    {
        push(src,disks--);
    }
}

// Tower of Hanoi Solver
void TowerOfHanoi(int disks, struct Stack *src, struct Stack *aux, struct Stack *dest)
{
    if(disks == 1)
    {
        printf("Move %d th disk from %c to %c.\n",peek(src),src->name,dest->name);
        push(dest,pop(src));
        return;
    }
    TowerOfHanoi(disks-1,src,dest,aux);
    printf("Move %d th disk from %c to %c.\n",peek(src),src->name,dest->name);
    push(dest,pop(src));
    TowerOfHanoi(disks-1,aux,src,dest);
}

// Main Function
int main(int argc, char const *argv[])
{
    int disks;

    printf("Welcome to Tower of Hanoi solver!\nHere,\nS means Source Tower,\nA means Auxilary Tower, \nD means Destination Tower.");
    printf("\nEnter no. of disks in tower of hanoi : ");
    scanf("%d", &disks);

    struct Stack src = initializer('S', MAXSIZE);
    struct Stack aux = initializer('A', MAXSIZE);
    struct Stack dest = initializer('D', MAXSIZE);

    addDisksInSrc(disks, &src);
    TowerOfHanoi(disks, &src, &aux, &dest);

    printf("Your Destination Tower after solving is :");
    printStack(&dest);

    return 0;
}