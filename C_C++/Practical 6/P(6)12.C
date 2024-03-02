#include<stdio.h>
#include<conio.h>
#include<string.h>

void main() 
{
    char str1[50] = "Demon";
    char str2[50] = "Slayer";
    char str3[50];
    int result,len;
    clrscr();

    // Concatenate str1 and str2
    strcat(str1, str2);
    printf("strcat(): %s\n",str1);

    // Compare str1 and str2
    result = strcmp(str1, str2);
    if (result == 0) 
    {
        printf("strcmp(): Strings are equal\n");
    } 
    else 
    {
        printf("strcmp(): Strings are not equal\n");
    }

    // Copy str1 to str3
    strcpy(str3, str1);
    printf("strcpy(): %s\n", str3);

    // Get the length of str1
    len = strlen(str1);
    printf("strlen(): %d\n", len);

    getch();
}
