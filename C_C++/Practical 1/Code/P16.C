#include<stdio.h>
#include<conio.h>
void main()
{
    int a;
    clrscr();
    printf("Enter Number:");
    scanf("%d",&a);
    printf("%d is Multiplication by 2.\n",a<<1);
    printf("%d is Division by 2.",a>>1);
    getch();
}