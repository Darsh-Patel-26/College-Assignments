#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
  float a,b;
  clrscr();
  printf("Enter the value of first decimal no.:");
  scanf("%f",&a);
  printf("Enter the value of second decimal no.:");
  scanf("%f",&b);
  printf("Addition=%.3f",a+b);
  printf("\nSubtraction=%.3f",a-b);
  printf("\nMultiplication=%.3f",a*b);
  printf("\nDivision=%.3f",a/b);
  printf("\nModulus=%.3f",fmod(a,b));
  getch();
}