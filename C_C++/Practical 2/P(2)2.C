#include<stdio.h>
#include<conio.h>
void main()
{
    int days,months,daysR;
    clrscr();
    printf("Enter No. of days:");
    scanf("%d",& days);
    months=days/30;
    daysR=days %30;
    printf("The Output is %d Months and %d Days.", months, daysR);
    getch();
}