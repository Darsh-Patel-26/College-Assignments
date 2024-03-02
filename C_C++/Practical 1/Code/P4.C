#include<stdio.h>
#include<conio.h>
void main()
{
  float amount;
  int rupee, paise;
  clrscr();
  printf("Enter Amount in decimal:");
  scanf("%f",&amount);
  rupee=(int)amount;
  paise=(amount-rupee)*100;
  printf("The amount is %d rupees and %d paise.",rupee,paise);
  getch();
}