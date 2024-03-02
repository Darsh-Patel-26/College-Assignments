#include<stdio.h>
#include<conio.h>

int sum_of_natural_numbers(int n);

void main()
{
    int n;
    clrscr();
    printf("Enter the value of N: ");
    scanf("%d", &n);

    int sum = sum_of_natural_numbers(n);

    printf("The sum of first %d natural numbers is %d\n", n, sum);

    getch();
}

int sum_of_natural_numbers(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++) 
    {
        sum += i;
    }

    return sum;
}
