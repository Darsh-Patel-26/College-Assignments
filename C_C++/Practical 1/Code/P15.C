#include<stdio.h>
#include<conio.h>
void main()
{
   float radius,volume;
   clrscr();
   printf("Enter Value of Radius of sphere(cm):");
   scanf("%f",&radius);
   volume= 1.34*3.14*radius*radius*radius;
   printf("The Volume of Sphere of Radius %.2f cm is %.2f cm cube.",radius,volume);
   getch();
}