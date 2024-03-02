#include<stdio.h>
#include<conio.h>
#include<string.h>

char* opposite_case(char* str);

void main() 
{
    char str[100];
    clrscr();

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    printf("Original string: %s\n", str);
    opposite_case(str);
    printf("Opposite case string: %s\n", str);

    getch();
}

char* opposite_case(char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        {
            str[i] = str[i] - 'a' + 'A';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}