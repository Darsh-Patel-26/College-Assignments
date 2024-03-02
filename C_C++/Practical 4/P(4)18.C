#include<stdio.h>
#include<conio.h>
int trailingZeros(int n);

void main() 
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int zeros = trailingZeros(n);
    printf("Number of trailing zeros in %d! = %d\n", n, zeros);
    getch();
}
int trailingZeros(int n) 
{
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5) 
    {
        count += n / i;
    }
    return count;
}
