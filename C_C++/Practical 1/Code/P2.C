#include<stdio.h>
#include<conio.h>
void main()
{
   int a=5,b=6;
   clrscr();
   printf("Addition, %d+%d=%d",a,b,a+b);
   printf("\nSubtraction%d-%d=%d",a,b,a-b);
   printf("\nMultiplication, %d x %d=%d",a,b,a*b);
   printf("\nDivision, %d / %d=%f",a,b,(float)a/(float)b);
   printf("\nModulus, %d",a%b);
   getch();
}