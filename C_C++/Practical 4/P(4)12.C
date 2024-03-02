#include<stdio.h>
#include<conio.h>
void main() 
{
    int low, high, i, j, sum;
    clrscr();

    printf("Enter the lower limit: ");
    scanf("%d", &low);

    printf("Enter the upper limit: ");
    scanf("%d", &high);

    printf("Perfect numbers between %d and %d are: ", low, high);

    // Traverse each number in the range
    for (i = low; i <= high; ++i) 
    {
        sum = 0;
        // Check if the number is perfect or not
        for (j = 1; j <= i/2; ++j) 
        {
            if (i % j == 0) 
            {
                sum += j;
            }
        }
        if (sum == i) 
        {
            printf("%d ", i);
        }
    }

    getch();
}
