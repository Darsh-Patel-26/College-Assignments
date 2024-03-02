#include<stdio.h>
#include<conio.h>
void main()
{
   int age;
   clrscr();
   printf("Enter Age:");
   scanf("%d",&age);
   if(age>=18)
   {
      printf("You are elligible to vote.");
   }
   else
   {
      printf("You are not elligible to vote.");
   }
   getch();
}