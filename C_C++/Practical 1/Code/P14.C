#include<stdio.h>
#include<conio.h>
void main()
{
   float a,b,c,x;
   fflush(stdin);
   clrscr();
   printf("Enter the value of a:\n");
   scanf("%f",&a);
   printf("Enter the value of b:\n");
   scanf("%f",&b);
   printf("Enter the value of c:\n");
   scanf("%f",&c);
   printf("Enter the value of x:\n");
   scanf("%f",&x);
   printf("a. = %f\n",a-b/3+c*2-1);
   printf("b. = %f\n",a-b/(3+c)*(2-1));
   printf("c. = %f\n",a-(b/(3+c)*2)-1);
   printf("d. = %f\n", 3*a*a + 2*a + 1);
   printf("e. = %f\n",2*x*x/a+9*x/8+1);
   printf("f. = %f",a*a+263*b/296+8*b*b+963*a/296);
   getch();
}