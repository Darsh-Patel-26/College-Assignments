#include<stdio.h>
#include<conio.h>
void main()
{
   int x=7, y=9;
   clrscr();
   printf("a) Z = %d\n",x++ + ++y - x-- + --y);
   x=5;
   y=2;
   printf("b) Z = %d\n",x++ * y++ / ++x - --y % x++);
   getch();
}