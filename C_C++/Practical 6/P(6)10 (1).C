#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    char str[100];
    int i, j, len;
    int counter = 1;
    clrscr();

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str) - 1;

    i = 0;
    j = len - 1;

    while (i < len/2)
    {
        if (str[i] != str[j])
        {
            counter = 0;
            break;
        }

        i++;
        j--;
    }

    if (counter == 1)
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    getch();
}
