#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,c;
	float avg;
	clrscr();
	printf("Enter value of any three numbers:");
	scanf("%d%d%d",&a,&b,&c);
	avg=(a+b+c)/3;
	printf("Average is %.1f.\n",avg);
	if(a>b)
	{
		if(a<c)
		{
			printf("%d is maximum\n",c);
		}
		else
		{
			printf("%d is maximum\n",a);
		}
	}
	if(b>a)
	{
		if(b<c)
		{
			printf("%d is maximum\n",c);
		}
		else
		{
			printf("%d is maximum\n",b);
		}
	}
	if(a<b)
	{
		if(a>c)
		{
			printf("%d is minimum",c);
		}
		else
		{
			printf("%d is minimum",a);
		}
	}
	if(b<a)
	{
		if(b>c)
		{
			printf("%d is minimum",c);
		}
		else
		{
			printf("%d is minimum",b);
		}
	}
	getch();
}