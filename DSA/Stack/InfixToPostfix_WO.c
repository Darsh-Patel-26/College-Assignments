#include<stdio.h>

#define MAX_SIZE 100

// Global Variables
char stack[100];
int top = -1;
char infix[100];
char postfix[100];

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAX_SIZE - 1);
}

void push(char data)
{
    if (isFull())
    {
        printf("Stack Overflow/Full!\n");
        return;
    }
    stack[++top] = data;
}

char pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow/Empty!\n");
        return -1;
    }
    char data = stack[top--];

    return data;
}

char peek()
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

int isOperator(int infix)
{
    if(infix == '+' || infix == '-' || infix == '*' || infix == '/' || infix == '^')
        return 1;

    return 0;
}

int precedance(int infix)
{
    if(infix == '+' || infix == '-')
        return 1;
    if(infix == '*' || infix == '/')
        return 2;
    if(infix == '^')
        return 3;

    return 0;
}

void infixToPostfix()
{
    int i = 0; //Infix counter
    int j = 0; //Postfix counter
    while(infix[i] != '\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else 
        {
            if(precedance(infix[i])>precedance(peek()))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int main(int argc, char const *argv[])
{
    printf("Enter any expression in infix form (The expression should not contain parenthesis): ");
    scanf("%s",&infix);

    infixToPostfix();

    printf("Your Postfix expression is : %s",postfix);

    return 0;
}