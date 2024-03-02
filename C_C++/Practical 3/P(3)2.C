#include<stdio.h>
#include<conio.h>
void main()
{
	int a;
	clrscr();
	printf("Enter any number:");
	scanf("%d",&a);
	if(a>0)
	{
		printf("The number is Positive.");
	}
	else if(a<0)
	{
		printf("The number is Negative.");
	}
	else if(a==0)
	{
		printf("It is equal to ZERO!!");
	}
	else
	{
		printf("Invalid Choice!!!");
	}
	getch();
}