#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j,k=1;
    clrscr();
    for(i=0;i<=6;i++)
    {
        for(j=6;j>=1;j--)
        {
            if(i>=j)
            {
                printf("%d ",k);
                k+=2;
            }
            else
                printf(" ");
        }
        k=1;
        printf("\n");
    }
    getch();
}