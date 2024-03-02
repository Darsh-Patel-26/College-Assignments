#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j;
    int size=5;
    clrscr();
    for(i=1;i<=size;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d",(i+j)%2);
        }
        printf("\n");
    }
    getch();
}