#include<stdio.h>
#include<conio.h>
double findNthRoot(double num, int n);

void main() 
{
    double num, n, result;
    clrscr();
    printf("Enter a number: ");
    scanf("%lf", &num);

    printf("Enter the root value: ");
    scanf("%lf", &n);

    result = findNthRoot(num, n);

    printf("The %gth root of %g is %g.\n", n, num, result);

    getch();
}

double findNthRoot(double num, int n) 
{
    double x0 = num / n;  // initial guess for x0
    double x1 = (1.0/n) * ((n-1)*x0 + num/pow(x0, n-1));  // iterative formula

    while (fabs(x1 - x0) > 0.00001)    // repeat until convergence
    {  
        x0 = x1;
        x1 = (1.0/n) * ((n-1)*x0 + num/pow(x0, n-1));
    }

    return x1;
}
