#include<stdio.h>
#include<conio.h>
void main() 
{
    int n;
    clrscr();
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (int i = n; i >= 0; i--) 
    {
        printf("%d ", i);
    }

    for (int i = 1; i <= n; i++) 
    {
        printf("%d ", i);
    }

    printf("\n");
    getch();
}
