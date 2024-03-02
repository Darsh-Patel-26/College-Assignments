#include<stdio.h>
#include<conio.h>

void  main()
{
    int x,y,z,num,s;
    clrscr();
    printf("Enter any 3 digit number:");
    scanf("%d",&num);
    x=num/100;
    y=(num/10)%10;
    z=num%10;
    s=x+y+z;
    printf("First Digit  : %d\n",x);
    printf("Second Digit : %d\n",y);
    printf("Third Digit  : %d\n",z);
    printf("Sum of three digits is %d",s);
    getch();
}