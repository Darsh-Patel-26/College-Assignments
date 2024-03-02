#include<stdio.h>
#include<conio.h>
void main() 
{
    int number,i;
    const char* words[] = {"zero", "one", "two", "three", "four",
                           "five", "six", "seven", "eight", "nine", "ten"};
    clrscr();
    
    printf("Enter a number between 0 and 10: ");
    scanf("%d", &number);

    
    if (number < 0 || number > 10) 
    {
        printf("Error: number out of range (0-10)\n");
    }

    printf("Number in words: ");

    for ( i = 0; i <= number; ++i) 
    {
    }
    printf("%s ", words[i-1]);
    getch();
}
