#include<stdio.h>
#include<conio.h>

int prime(int n);

void main() 
{
   int n;
   clrscr();

   printf("Enter an integer: ");
   scanf("%d", &n);
   if (prime(n)) 
   {
      printf("%d is prime\n", n);
   } 
   else 
   {
      printf("%d is not prime\n", n);
   }
   getch();
}

int prime(int n) 
{
   int i;
   if (n <= 1) 
   {
      return 0;
   }
   for (i = 2; i*i <= n; i++) 
   {
      if (n % i == 0) 
      {
         return 0;
      }
   }
   return 1;
}

