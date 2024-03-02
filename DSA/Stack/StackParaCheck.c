#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack data structure
typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *stack)
{
    stack->top = -1;
}

// Push an element onto the stack
void push(Stack *stack, char element)
{
    stack->data[++stack->top] = element;
}

// Pop an element from the stack
char pop(Stack *stack)
{
    return stack->data[stack->top--];
}

// Check if the stack is empty
bool isEmpty(Stack *stack)
{
    return (stack->top == -1);
}

// Check if the parentheses are balanced
bool isBalanced(char expression[])
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (isEmpty(&stack))
                return false;

            char popped = pop(&stack);

            if ((popped == '(' && expression[i] != ')') ||
                (popped == '{' && expression[i] != '}') ||
                (popped == '[' && expression[i] != ']'))
            {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main()
{
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(expression, MAX_SIZE, stdin);

    if (isBalanced(expression))
    {
        printf("Parentheses are balanced.\n");
    }
    else
    {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}

