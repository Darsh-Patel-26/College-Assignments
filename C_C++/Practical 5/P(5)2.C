#include<stdio.h>
#include<conio.h>
void main()
{
    int k=1;
    clrscr();
    
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(k<=15)
            {
                printf(" %d ",k);
                k++;
            }
            else
                break;
        }
        printf("\n");
    }
    getch();
}