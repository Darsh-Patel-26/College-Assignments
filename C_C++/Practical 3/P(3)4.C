#include<stdio.h>
#include<conio.h>
void main() 
{
    char ch;
    clrscr();
    // read a character from the user
    printf("Enter a character: ");
    scanf("%c", &ch);

    // check if the character is a number
    if (ch >= '0' && ch <= '9') 
    {
        printf("It is a number.\n");
    }
    // check if the character is an alphabet
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) 
    {
        printf("%c is an alphabet. ", ch);
        // check if the alphabet is uppercase or lowercase
        if (ch >= 'a' && ch <= 'z') 
        {
            printf("It is a lowercase alphabet. ");
            // check if the alphabet is a vowel
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
            {
                printf("It is a vowel.\n");
            }
            else 
            {
                printf("It is not a vowel.\n");
            }
        }
        else 
        {
            printf("It is an uppercase alphabet.\n");
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
            {
                printf("It is a vowel.\n");
            }
            else 
            {
                printf("It is not a vowel.\n");
            }
        }
    }
    // check if the character is a special character
    else 
    {
        printf("%c is a special character.\n", ch);
    }

    getch();
}
