#include<stdio.h>
#include<conio.h>
void main() 
{
    int rows=5, i, j, k, space;
    clrscr();

    for (i = rows; i >= 1; i--) 
    {
        for (space = 1; space <= rows - i; space++) 
        {
            printf(" ");
        }
        k = i;
        for (j = 1; j <= 2 * i - 1; j++) 
        {
            printf("%d", k);
            if (j < i) 
            {
                k++;
            } 
            else 
            {
                k--;
            }
        }
        printf("\n");
    }

    getch();
}
