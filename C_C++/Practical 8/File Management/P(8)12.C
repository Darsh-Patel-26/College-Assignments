#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
   FILE *fp;
   char ch;
   clrscr();   

   fp = fopen("P(8)12.txt", "r");
   if (fp == NULL) 
   {
      printf("Error opening file\n");
   }

   printf("The contents are:\n");

   while (fgets(ch, 100, fp) != NULL) 
   {
      printf("%s", ch);
   }

   fclose(fp);
   getch();
}
