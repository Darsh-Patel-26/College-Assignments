#include<stdio.h>
#include<conio.h>
void main() 
{
    int rows = 5;
    int i, j, k;
    clrscr();
    
    for (i = 1; i <= rows; i++) 
    {
        // Print spaces
        for (j = i; j < rows; j++) 
        {
            printf(" ");
        }

        // Print asterisks
        for (k = 1; k < (i * 2); k++) 
        {
            printf("*");
        }

        // Move to next line
        printf("\n");
    }

    getch();
}
