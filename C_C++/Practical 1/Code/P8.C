#include<stdio.h>
#include<conio.h>
void main()
{
   short z;
   int x, y;
   clrscr();
   printf("Enter value of x and y(6 digit):");
   scanf("%d%d",&x,&y);
   z=x+y;
   printf("The Value of z is %d",z);
   getch();
}