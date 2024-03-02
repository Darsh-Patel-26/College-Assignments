#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    FILE *total_fp, *odd_fp, *even_fp;
    int n, num;
    clrscr();

    // Open the total file for writing
    total_fp = fopen("total.txt", "w");
    if (total_fp == NULL) 
    {
        printf("Error opening total file\n");
    }

    // Open the odd file for writing
    odd_fp = fopen("odd.txt", "w");
    if (odd_fp == NULL) 
    {
        printf("Error opening odd file\n");
    }

    // Open the even file for writing
    even_fp = fopen("even.txt", "w");
    if (even_fp == NULL) 
    {
        printf("Error opening even file\n");
    }

    // Read the number of integers to be entered
    printf("Enter the number of integers to be entered: ");
    scanf("%d", &n);

    // Read each integer and write it to the total file
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &num);
        fprintf(total_fp, "%d ", num);
        
        // Write the number to the odd file if it's odd, or to the even file if it's even
        if (num % 2 == 0) 
        {
            fprintf(even_fp, "%d ", num);
        } 
        else 
        {
            fprintf(odd_fp, "%d ", num);
        }
    }

    // Close the files
    fclose(total_fp);
    fclose(odd_fp);
    fclose(even_fp);

    // Display the contents of all three files
    printf("\nContents of total.txt:\n");
    total_fp = fopen("total.txt", "r");
    while (fscanf(total_fp, "%d", &num) != EOF) 
    {
        printf("%d ", num);
    }
    fclose(total_fp);

    printf("\n\nContents of odd.txt:\n");
    odd_fp = fopen("odd.txt", "r");
    while (fscanf(odd_fp, "%d", &num) != EOF) 
    {
        printf("%d ", num);
    }
    fclose(odd_fp);

    printf("\n\nContents of even.txt:\n");
    even_fp = fopen("even.txt", "r");
    while (fscanf(even_fp, "%d", &num) != EOF) 
    {
        printf("%d ", num);
    }
    fclose(even_fp);

    getch();
}
