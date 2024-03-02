#include<stdio.h>
#include<conio.h>
void main() 
{
    int num, remainder;
    clrscr();
    printf("Enter a number: ");
    scanf("%d", &num);

    remainder = num % 2;

    switch(remainder) 
    {
        case 0:
            printf("%d is even\n", num);
            break;
        case 1:
        case -1:
            printf("%d is odd\n", num);
            break;
        default:
            printf("Invalid number\n");
    }

    getch();
}
