#include<stdio.h>
#include<conio.h>
void main() 
{
    char str[100];
    int i = 0;
    char c;
    clrscr();

    // Using getchar() method
    printf("Enter a string using getchar(): ");
    
    while ((c = getchar()) != '\n') 
    {
        str[i++] = c;
    }
    str[i] = '\0';
    printf("You entered: %s\n", str);

    // Using gets() method
    printf("Enter a string using gets(): ");
    gets(str);
    printf("You entered: %s\n", str);

    // Using scanf() method
    printf("Enter a string using scanf(): ");
    scanf("%s", str);
    printf("You entered: %s\n", str);

    // Using scanf() method with %[^\n] format specifier
    printf("Enter a string using scanf() with %[^\n]: ");
    scanf(" %[^\n]", str);
    printf("You entered: %s\n", str);

    getch();
}
