#include<stdio.h>
#include<conio.h>
#include<string.h>

void main() 
{
    char str[1000];
    int i;
    clrscr();

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') 
        {
            str[i] = '*';
        }
    }

    printf("Result: %s", str);

    getch();
}
  