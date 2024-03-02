#include<stdio.h>
#include<conio.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

void main() 
{
   float a, b;
   char op;
   clrscr();

   printf("Enter an expression (e.g. 2 + 3): ");
   scanf("%f %c %f", &a, &op, &b);

   switch (op) 
   {
      case '+':
         printf("%.2f %c %.2f = %.2f\n", a, op, b, add(a, b));
         break;
      case '-':
         printf("%.2f %c %.2f = %.2f\n", a, op, b, subtract(a, b));
         break;
      case '*':
         printf("%.2f %c %.2f = %.2f\n", a, op, b, multiply(a, b));
         break;
      case '/':
         printf("%.2f %c %.2f = %.2f\n", a, op, b, divide(a, b));
         break;
      default:
         printf("Error: invalid operator\n");
         break;
   }

   getch();
}

float add(float a, float b) 
{
   return a + b;
}

float subtract(float a, float b) 
{
   return a - b;
}

float multiply(float a, float b) 
{
   return a * b;
}

float divide(float a, float b) 
{
   if (b == 0) 
   {
      printf("Error: division by zero\n");
      return 0;
   }
   return a / b;
}