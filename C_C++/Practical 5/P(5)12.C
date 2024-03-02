#include<stdio.h>
#include<conio.h>
void main() 
{
    int i, j, num = 1;
    char ch = 'A';
    clrscr();

    for (i = 1; i <= 5; i++) 
    {
        for (j = 1; j <= 5-i; j++) 
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++) 
        {
            if (i % 2 == 0) 
            {
                printf("%c ", ch);
                ch++;
            } 
            else 
            {
                printf("%d ", num);
                num++;
            }
        }
        printf("\n");
    }

    getch();;
}
