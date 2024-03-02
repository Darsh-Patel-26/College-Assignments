#include<stdio.h>
#include<conio.h>

void main()
{
    FILE *fp;
    char str[100];
    clrscr();

    // Open the file for writing using fopen()
    fp = fopen("Darsh.txt", "w");

    // Use fputc() to write individual characters to the file
    fputc('H', fp);
    fputc('e', fp);
    fputc('l', fp);
    fputc('l', fp);
    fputc('o', fp);
    fputc('\n', fp);

    // Use fputs() to write a string to the file
    fputs("Printed By fputs.", fp);
    fputs("\n", fp);

    // Close the file using fclose()
    fclose(fp);

    // Open the file for reading using fopen()
    fp = fopen("Darsh.txt", "r");

    // Use fgets() to read a line from the file and print it to the screen
    fgets(str, 100, fp);
    printf("%s", str);

    // Use fgets() again to read another line from the file and print it to the screen
    fgets(str, 100, fp);
    printf("%s", str);

    // Close the file using fclose()
    fclose(fp);

    getch();
}
