#include<stdio.h>
#include<conio.h>
#include<string.h>

void main() 
{
    char str[100];
    clrscr();
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for (int i = 0; i < strlen(str); i++) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] += 'a' - 'A';
        } 
        else if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] -= 'a' - 'A';
        }
    }

    printf("Toggle case string: %s", str);
    getch();
}
