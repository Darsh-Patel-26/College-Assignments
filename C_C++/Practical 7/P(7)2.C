#include<stdio.h>
#include<conio.h>

int findMax(int num1, int num2, int num3);

void main() 
{
   int num1, num2, num3;
   clrscr();

   printf("Enter three numbers: ");
   scanf("%d %d %d", &num1, &num2, &num3);

   printf("The maximum number is %d", findMax(num1, num2, num3));

   getch();
}

int findMax(int num1, int num2, int num3) 
{
   int max = num1;

   if (num2 > max) 
   {
      max = num2;
   }

   if (num3 > max) 
   {
      max = num3;
   }

   return max;
}