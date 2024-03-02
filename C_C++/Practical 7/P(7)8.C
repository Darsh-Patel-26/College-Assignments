#include<stdio.h>
#include<conio.h>

void add_no_args_no_return();
void add_with_args_no_return(int a, int b);
int add_with_args_one_return(int a, int b);
int add_no_args_one_return();

void main() 
{
    int x = 10, y = 15, result;
    clrscr();

    add_no_args_no_return();

    add_with_args_no_return(x, y);

    result = add_with_args_one_return(x, y);
    printf("Result (args, one return): %d\n", result);

    result = add_no_args_one_return();
    printf("Result (no args, one return): %d\n", result);

    getch();
}

void add_no_args_no_return() 
{
    int a = 5, b = 7, sum;
    sum = a + b;
    printf("Sum (no args, no return): %d\n", sum);
}

void add_with_args_no_return(int a, int b) 
{
    int sum;
    sum = a + b;
    printf("Sum (args, no return): %d\n", sum);
}

int add_with_args_one_return(int a, int b) 
{
    int sum;
    sum = a + b;
    return sum;
}

int add_no_args_one_return() 
{
    int a, b, sum;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    return sum;
}
