#include<stdio.h>
#include<conio.h>
void main() 
{
    int x, n, i;
    long long y = 1;
    clrscr();

    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) 
    {
        y *= x;
    }

    printf("%d raised to %d is %lld\n", x, n, y);

    getch();
}
