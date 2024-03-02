#include<stdio.h>
#include<conio.h>
void main() 
{
    int n, i;
    unsigned long long fact = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    // Error check: Factorial is defined only for non-negative integers.
    if (n < 0) 
    {
        printf("Error: Factorial is not defined for negative numbers.");
    }

    // Calculate the factorial of the number.
    for (i = 1; i <= n; ++i) 
    {
        fact *= i;
    }

    printf("Factorial of %d = %llu", n, fact);
    getch();
}
