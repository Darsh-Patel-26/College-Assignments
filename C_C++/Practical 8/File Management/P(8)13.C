#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

void main()
{
    FILE *fp1, *fp2;
    char buffer[BUFFER_SIZE];
    clrscr();

    // Open the source file for reading
    fp1 = fopen("source_file.txt", "r");
    if (fp1 == NULL) 
    {
        printf("Error opening source file\n");
    }

    // Open the destination file for writing
    fp2 = fopen("destination_file.txt", "w");
    if (fp2 == NULL) 
    {
        printf("Error opening destination file\n");
    }

    // Read each line from the source file and write it to the destination file
    while (fgets(buffer, BUFFER_SIZE, fp1) != NULL) 
    {
        fputs(buffer, fp2);
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    printf("File contents copied successfully!\n");

    getch();
}
