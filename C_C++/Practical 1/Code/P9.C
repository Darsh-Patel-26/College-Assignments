#include<stdio.h>
#include<conio.h>
void main() 
{
    short num = 1;
    int i;
    clrscr();
    for (i = 0; i < 16; i++) 
    {
        printf("%hd\n", num);
        num *= 2;
    }

    getch();
}
