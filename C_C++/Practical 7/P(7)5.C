#include<stdio.h>
#include<conio.h>

void swap(int *a, int *b);

void main() 
{
    int x = 10, y = 20;
    clrscr();
    
    printf("Before swapping, x = %d and y = %d\n", x, y);

    // call swap function to interchange the values of x and y
    swap(&x, &y);

    printf("After swapping, x = %d and y = %d\n", x, y);

    getch();
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
