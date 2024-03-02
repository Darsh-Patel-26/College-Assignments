#include<stdio.h>

int main() 
{
   int a = 10, b = 5;
   int *ptr1 = &a; // pointer to a
   int *ptr2 = &b; // pointer to b

   printf("Value of a: %d\n", a);
   printf("Value of b: %d\n", b);

   // perform arithmetic operations using pointers
   int sum = *ptr1 + *ptr2;
   int diff = *ptr1 - *ptr2;
   int prod = *ptr1 * *ptr2;
   int quot = *ptr1 / *ptr2;

   printf("Sum of a and b: %d\n", sum);
   printf("Difference of a and b: %d\n", diff);
   printf("Product of a and b: %d\n", prod);
   printf("Quotient of a and b: %d\n", quot);

   return 0;
}
