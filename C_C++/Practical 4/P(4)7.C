#include<stdio.h>
#include<conio.h>
void main() 
{
    int i = 1, num, largest = -999999;
    clrscr();
    
    while (i <= 10) 
    {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if (num > largest) 
        {
            largest = num;
        }

        i++;
    }

    printf("The largest number is(while loop) %d\n", largest);
    
    
    i = 1;
    largest = -999999;

loop:
    printf("Enter number %d: ", i);
    scanf("%d", &num);

    if (num > largest) 
    {
        largest = num;
    }

    i++;

    if (i <= 10) 
    {
        goto loop;
    }

    printf("The largest number is(by goto) %d\n", largest);
    getch();
}
