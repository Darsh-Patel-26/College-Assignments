#include<stdio.h>
#include<conio.h>
void main() 
{
    int low, high, i, j, is_prime;
    clrscr();

    printf("Enter the lower limit: ");
    scanf("%d", &low);

    printf("Enter the upper limit: ");
    scanf("%d", &high);

    printf("Prime numbers between %d and %d are: ", low, high);

    // Traverse each number in the range
    for (i = low; i <= high; ++i) 
    {
        // Check if the number is prime or not
        is_prime = 1;
        for (j = 2; j <= i/2; ++j) 
        {
            if (i % j == 0) 
            {
                is_prime = 0;
                break;
            }
        }

        // If the number is prime, print it
        if (is_prime == 1) 
        {
            printf("%d ", i);
        }
    }

    getch();
}
