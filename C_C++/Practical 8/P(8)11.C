#include<stdio.h>

// function that takes an integer argument by value
void callByValue(int x);

// function that takes an integer argument by reference
void callByReference(int *y);

int main() 
{
   int num = 5;

   printf("Before function calls:\n");
   printf("Value of num: %d\n", num);

   // call function using call by value
   callByValue(num);
   printf("After callByValue function call:\n");
   printf("Value of num: %d\n", num);

   // call function using call by reference
   callByReference(&num);
   printf("After callByReference function call:\n");
   printf("Value of num: %d\n", num);

   return 0;
}

void callByValue(int x) 
{
   x = x + 10;
   printf("Inside callByValue function: %d\n", x);
}

void callByReference(int *y) 
{
   *y = *y + 10;
   printf("Inside callByReference function: %d\n", *y);
}