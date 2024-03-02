#include<stdio.h>
#include<conio.h>
void main() 
{
    int n, i,j;
    float sum = 0;
    clrscr();

    printf("Enter a value for n: ");
    scanf("%d", &n);

    // Calculate the sum of the series.
    for (i = 1; i <= n; ++i) 
    {
        sum += 1.0 / i;
    }

    printf("a)The sum of the series is %f\n", sum);
    
    // Calculate the sum of the series.
    for (i = 1; i <= n; ++i) 
    {
        sum += (float)i / (i + 1);
    }

    printf("b)Sum of the series = %f\n", sum);
    
    
    // Calculate the sum of the series.
    for (i = 1; i <= n; ++i) 
    {
        sum += 1.0 / (i * i);
    }

    printf("c)Sum of the series = %lf\n", sum);
    
    //Error check: Series is defined only for positive integers.
    if (n <= 0) 
    {
        printf("Error: Series is not defined for non-positive numbers.");
    }

    // Calculate the sum of the series.
    for (i = 1; i <= n; ++i) 
    {
        unsigned long long fact = 1;
        for (j = 1; j <= i; ++j) 
        {
            fact *= j;
        }
        sum += fact;
    }

    printf("d)Sum of the series = %llu\n", sum);
    
    for (i = 1; i <= n; ++i) 
    {
        // If i is odd, subtract it from the sum.
        if (i % 2 == 1) 
        {
            sum -= i;
        }
        // If i is even, add it to the sum.
        else 
        {
            sum += i;
        }
    }

    printf("e)The sum of the series up to %d is: %d", n, sum);
    getch();
}
