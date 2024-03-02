#include<stdio.h>

int main() 
{
   int x = 286128;
   int *ptr = &x; // declare a pointer and initialize it to the address of x

   printf("Value of x: %d\n", x);
   printf("Value of ptr: %p\n", (void *)ptr);
   printf("Value pointed by ptr: %d\n", *ptr); // use indirection operator to access value pointed by ptr

   return 0;
}
