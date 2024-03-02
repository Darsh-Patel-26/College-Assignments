#include<stdio.h>
#include<conio.h>
void main() 
{
    int rows = 5;
    int i, j, k;
    clrscr();

    for (i = 1; i <= rows; i++) 
    {
        // Print numbers 1 to i
        for (j = 1; j <= i; j++) 
        {
            printf("%d", j);
        }

        // Print numbers i-1 down to 1
        for (k = i - 1; k >= 1; k--) 
        {
            printf("%d", k);
        }

        // Move to next line
        printf("\n");

    }

    getch();
}
