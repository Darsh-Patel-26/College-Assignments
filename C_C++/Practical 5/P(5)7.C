#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j;
    clrscr();
    for(i=0;i<=5;i++)
    {
        for(j=5;j>=1;j--)
        {
            if(i>=j)
                printf("* ");  //Space makes it aligned to centre;)
            else
                printf(" ");
        }
        printf("\n");
    }
    getch();
}