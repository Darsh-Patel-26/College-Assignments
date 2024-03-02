#include<stdio.h>
#include<conio.h>
void main() 
{
    int n, sum = 0, i = 1;
    clrscr();
    
    // Using while loop
    printf("Enter the value of n: ");
    scanf("%d", &n);
    while (i <= n) 
    {
        sum += i;
        i++;
    }
    printf("The sum of the first %d natural numbers (using while loop) is: %d\n", n, sum);

    // Using for loop
    sum = 0;  // Reset sum to zero
    for (i = 1; i <= n; i++) 
    {
        sum += i;
    }
    printf("The sum of the first %d natural numbers (using for loop) is: %d\n", n, sum);

    // Using goto statement
    sum = 0;  // Reset sum to zero
    i = 1;  // Reset i to 1
    start:
        sum += i;
        i++;
        if (i <= n) 
        {
            goto start;
        }
    printf("The sum of the first %d natural numbers (using goto statement) is: %d\n", n, sum);

    getch();
}
