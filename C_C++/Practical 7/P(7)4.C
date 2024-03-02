#include<stdio.h>
#include<conio.h>

int factorial(int n);

void main()
{
    int n;
    int result;
    clrscr();
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);
    if (n < 0) 
    {
        printf("Error: negative input.\n");
    }
    result = factorial(n);
    printf("%d! = %d\n", n, result);
    getch();
}

int factorial(int n) 
{
    if (n == 0) 
    { // base case
        return 1;
    } 
    else
    {
        return n * factorial(n-1); // recursive case
    }
}
