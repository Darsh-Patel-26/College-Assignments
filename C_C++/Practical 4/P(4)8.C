#include<stdio.h>
#include<conio.h>
void main() 
{
    int num, rev = 0, sum = 0, rem;
    clrscr();

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) 
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        sum += rem;
        num /= 10;
    }

    printf("The reverse of the number is: %d\n", rev);
    printf("The sum of its digits is: %d\n", sum);

    getch();
}
