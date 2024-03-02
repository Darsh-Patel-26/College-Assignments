#include<stdio.h>
#include<conio.h>

int fibonacci(int n);

void main() 
{
    int n;
    clrscr();

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", fibonacci(i));
    }

    getch();
}

int fibonacci(int n) 
{
    if (n <= 1) 
    {
        return n;
    }
    else 
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}