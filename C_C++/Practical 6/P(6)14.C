#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX_LENGTH 100
#define MAX_WORDS 100

void main() 
{
    char words[MAX_WORDS][MAX_LENGTH];
    int n, i, j;
    char temp[MAX_LENGTH];
    clrscr();

    printf("Enter the number of words: ");
    scanf("%d", &n);

    printf("Enter %d words: ", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%s", words[i]);
    }

    for (i = 0; i < n-1; i++) 
    {
        for (j = 0; j < n-i-1; j++) 
        {
            if (strcmp(words[j], words[j+1]) > 0) 
            {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
        }
    }

    printf("\nSorted words:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    getch();
}
