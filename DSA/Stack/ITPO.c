#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Global Variables
char stack[100];
int top = -1;

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAX_STACK_SIZE - 1);
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
        printf("%c\n", pop());
    }
}

int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *infix)
{
    int i, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(len + 2);
    for (i = 0; i < len; i++)
    {
        char ch = infix[i];

        if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(ch))
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        else
        {
            postfix[j++] = ch;
        }
    }
    while (!isEmpty())
    {
        if (postfix[j] == '(' || postfix[j] == ')')
        {
            printf("The expression has a parenthesis error!!");
            return NULL;
        }
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

char *revStr(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }

    return str;
}

int main(int argc, char const *argv[])
{
    char *infix = malloc(MAX_STACK_SIZE - 1);
    printf("Enter any expression in infix form : ");
    scanf("%s", infix);

    printf("Your Postfix expression is : %s\n", infixToPostfix(infix));
    printf("Your Prefix expression is : %s\n", revStr(infixToPostfix(infix)));

    return 0;
}