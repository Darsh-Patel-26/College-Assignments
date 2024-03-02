#include<stdio.h>
#include<conio.h>

double power(int x, int y);

void main() 
{
    int x, y;
    clrscr();
    
    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);
    
    double result = power(x, y);
    printf("%d raised to the power %d is %.2f\n", x, y, result);
    
    getch();
}

double power(int x, int y) 
{
    double result = 1.0;

    if (y < 0) 
    {
        x = 1 / x;
        y = -y;
    }

    while (y > 0) 
    {
        if (y % 2 == 1) 
        {
            result *= x;
        }
        x *= x;
        y /= 2;
    }

    return result;
}

