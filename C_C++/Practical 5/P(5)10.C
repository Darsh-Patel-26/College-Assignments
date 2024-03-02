#include<stdio.h>
#include<conio.h>
void main() 
{
    int i, j,k;
    int size=3;
    clrscr();

    for (i =size; i >= -size; i--) 
    {
        for (j = 1; j <= abs(i); j++) 
        {
            printf(" ");
        }
        for (k =size; k >= abs(i);k--) 
        {
            printf("*");
        }
        printf("\n");
    }

    getch();
}
