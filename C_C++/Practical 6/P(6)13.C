#include<stdio.h>
#include<conio.h>
#include<string.h>

void main() 
{
    char str[100];
    int counter = 0, i;
    clrscr();
    
    printf("Enter a string: ");
    scanf("%s", str);
    char last_char = str[strlen(str)-1]; // Get the last character of the string 

    for(i = 0; i < strlen(str); i++) 
    {
        if(str[i] == last_char) 
        {
            counter++;
        }
    }

    printf("The frequency of '%c' in the string is %d\n", last_char, counter);

    getch();
}
