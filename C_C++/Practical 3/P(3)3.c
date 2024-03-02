#include<stdio.h>
#include<conio.h>
void main() 
{
    char ch;

    // read a character from the user
    printf("Enter a character: ");
    scanf("%c", &ch);

    // print the ASCII value of the character
    printf("ASCII value of %c is %d\n", ch, ch);

    // check if the character is uppercase and convert to lowercase
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += 32;  // ASCII value difference between uppercase and lowercase
        printf("Lowercase of %c is %c\n", ch-32, ch);
    }
    // check if the character is lowercase and convert to uppercase
    else if (ch >= 'a' && ch <= 'z') 
    {
        ch -= 32;  // ASCII value difference between lowercase and uppercase
        printf("Uppercase of %c is %c\n", ch+32, ch);
    }

    // check if the character is a vowel or not
    switch (ch) 
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            printf("%c is a vowel.\n", ch);
            break;
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            printf("%c is a vowel.\n", ch);
            break;
        default:
            printf("%c is not a vowel.\n", ch);
    }

    getch();
}
