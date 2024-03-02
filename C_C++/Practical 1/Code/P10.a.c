#include<stdio.h>
#include<conio.h>
void main()
{
    int x, y, z;
    clrscr();
    printf("Enter No. (1):");
    scanf("%d",&x);
    printf("Enter No. (2):");
    scanf("%d",&y);
    printf("Before Swaping:\n");
    printf("%d\n",x);
    printf("%d",y);
    z=x;
    x=y;
    y=z;
    printf("After Swaping:\n");
    printf("%d\n",x);
    printf("%d\n",y);
    getch();
}