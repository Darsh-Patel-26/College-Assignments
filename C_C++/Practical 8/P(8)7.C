#include<stdio.h>
#include<conio.h>
#include<string.h>

void main() 
{
    char str1[50], str2[50], str3[50];
    char *p1, *p2, *p3;
    clrscr();
    
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Copying the first string to the third string using pointers
    p1 = str1;
    p3 = str3;
    while (*p1 != '\0') 
    {
        *p3 = *p1;
        p1++;
        p3++;
    }
    *p3 = '\0';

    printf("The first string is: %s\n", str1);
    printf("The second string is: %s\n", str2);
    printf("The third string (copy of first string) is: %s\n", str3);

    // Comparing the first and second strings using pointers
    p1 = str1;
    p2 = str2;
    while (*p1 == *p2 && *p1 != '\0' && *p2 != '\0') 
    {
        p1++;
        p2++;
    }
    if (*p1 == *p2) 
    {
        printf("The first and second strings are equal.\n");
    } 
    else if (*p1 > *p2) 
    {
        printf("The first string is greater than the second string.\n");
    } 
    else 
    {
        printf("The second string is greater than the first string.\n");
    }

    // Concatenating the first and second strings using pointers
    p1 = str1;
    p3 = str3;
    while (*p1 != '\0') 
    {
        *p3 = *p1;
        p1++;
        p3++;
    }
    p2 = str2;
    while (*p2 != '\0') 
    {
        *p3 = *p2;
        p2++;
        p3++;
    }
    *p3 = '\0';

    printf("The concatenation of the first and second strings is: %s\n", str3);

    getch();
}
    