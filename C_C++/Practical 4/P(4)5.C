#include<stdio.h>
#include<conio.h>
void main() 
{
    int start, end, i, even_sum = 0, odd_sum = 0;
    clrscr();

    printf("Enter the starting number: ");
    scanf("%d", &start);

    printf("Enter the ending number: ");
    scanf("%d", &end);

    for (i = start; i <= end; i++) 
    {
        if (i % 2 == 0) 
        {
            even_sum += i;
        } 
        else 
        {
            odd_sum += i;
        }
    }

    printf("Sum of even numbers between %d and %d is %d\n", start, end, even_sum);
    printf("Sum of odd numbers between %d and %d is %d\n", start, end, odd_sum);

    getch();
}
