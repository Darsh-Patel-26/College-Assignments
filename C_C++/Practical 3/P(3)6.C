#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,c,d,num,deno;
	clrscr();
	printf("Enter values of a,b,c,d:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("Substituting the values in eqn of ratio:  (a+b)/(c-d)\n");
	num=a+b;
	deno=c-d;
	if(deno==0)
	{
		printf("Ratio cannot be calculated since (c-d)=0.");
	}
	else
	{
		printf("The Ratio is : %d",num/deno);
	}
	getch();
}