#include<stdio.h>
#include<conio.h>
void main() 
{
    int num, digit, rev = 0;

    char* words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    clrscr();

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Number in words: ");

    // Reverse the number
    while (num > 0) 
    {
        digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    // Convert each digit to word
    while (rev > 0) 
    {
        digit = rev % 10;
        printf("%s ", words[digit]);
        rev /= 10;
    }

    getch();
}
