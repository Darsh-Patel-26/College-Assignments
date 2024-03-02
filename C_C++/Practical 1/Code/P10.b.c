#include<stdio.h>
#include<conio.h>
void main()
{
    int x, y;
    clrscr();
    printf("Enter No. (1):");
    scanf("%d",&x);
    printf("Enter No. (2):");
    scanf("%d",&y);
    printf("\nBefore Swaping:\n");
    printf("%d\n",x);
    printf("%d",y);
    x=x+y;
    y=x-y;
    x=x-y;
    printf("\nAfter Swaping:\n");
    printf("%d\n",x);
    printf("%d\n",y);
    getch();
}