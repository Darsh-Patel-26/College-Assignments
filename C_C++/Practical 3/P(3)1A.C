#include<stdio.h>
#include<conio.h>
void main()
{
   int a;
   clrscr();
   printf("Enter any number:");
   scanf("%d",&a);
   if(a%2==0)
   {
      printf("%d is a Even Number.",a);
   }
   else
   {
      printf("%d is a Odd Number.",a);
   }
   getch();
}