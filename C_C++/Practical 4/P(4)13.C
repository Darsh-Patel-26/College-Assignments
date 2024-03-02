#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() 
{
    int low, high, num, digit, sum, temp;
    clrscr();

    printf("Enter the lower limit: ");
    scanf("%d", &low);

    printf("Enter the upper limit: ");
    scanf("%d", &high);

    printf("Armstrong numbers between %d and %d are: ", low, high);

    // Traverse each number in the range
    for (num = low; num <= high; num++) 
    {
        // Find the number of digits in the number
        temp = num;
        int n = 0;
        while (temp != 0) 
        {
            n++;
            temp /= 10;
        }

        // Calculate the sum of the cubes of the digits
        temp = num;
        sum = 0;
        while (temp != 0) 
        {
            digit = temp % 10;
            sum += pow(digit, n);
            temp /= 10;
        }

        // Check if the number is Armstrong or not
        if (num == sum) 
        {
            printf("%d ", num);
        }
    }

    getch();
}
    