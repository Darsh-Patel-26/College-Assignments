#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,ch1,ch;
	clrscr();
	printf("This is a calculator ;)\n");
	printf("Please select the way to calculate:\n");
	printf("Enter 1 to calculate with if-else syntax.\n");
	printf("Enter 2 to calculate with switch-case syntax.\n");
	scanf("%d",&ch1);
	if(ch1==1)
	{
		printf("Enter 1 to Add two numbers:\n");
		printf("Enter 2 to Subtract two numbers:\n");
		printf("Enter 3 to Multiply two numbers:\n");
		printf("Enter 4 to Divide two numbers:\n");
		printf("Enter 5 to get Remainder of two numbers:\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter Two Numbers:");
			scanf("%d%d",&a,&b);
			printf("The Addition is %d + %d = %d",a,b,a+b);
		}
		else if(ch==2)
		{
			printf("Enter Two Numbers:");
			scanf("%d%d",&a,&b);
			printf("The Subtraction is %d - %d = %d",a,b,a-b);
		}
		else if(ch==3)
		{
			printf("Enter Two Numbers:");
			scanf("%d%d",&a,&b);
			printf("The Multiplication is %d x %d = %d",a,b,a*b);
		}
		else if(ch==4)
		{
			printf("Enter Two Numbers:");
			scanf("%d%d",&a,&b);
			printf("The Division is %d / %d = %d",a,b,a/b);
		}
		else if(ch==5)
		{
			printf("Enter Two Numbers:");
			scanf("%d%d",&a,&b);
			printf("The Remainder is %d",a%b);
		}
		else
		{
			printf("Invalid Choice!!");
		}
	}
	else
	{
		printf("Enter 1 to Add two numbers:\n");
		printf("Enter 2 to Subtract two numbers:\n");
		printf("Enter 3 to Multiply two numbers:\n");
		printf("Enter 4 to Divide two numbers:\n");
		printf("Enter 5 to get Remainder of two numbers:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("Enter Two Numbers:");
				scanf("%d%d",&a,&b);
				printf("The Addition is %d + %d = %d",a,b,a+b);
				break;
			}
			case 2:
			{
				printf("Enter Two Numbers:");
				scanf("%d%d",&a,&b);
				printf("The Subtraction is %d - %d = %d",a,b,a-b);
				break;
			}
			case 3:
			{
				printf("Enter Two Numbers:");
				scanf("%d%d",&a,&b);
				printf("The Multiplication is %d x %d = %d",a,b,a*b);
				break;
			}
			case 4:
			{
				printf("Enter Two Numbers:");
				scanf("%d%d",&a,&b);
				printf("The Division is %d / %d = %d",a,b,a/b);
				break;
			}
			case 5:
			{
				printf("Enter Two Numbers:");
				scanf("%d%d",&a,&b);
				printf("The Remainder is %d % %d = %d",a,b,a%b);
				break;
			}
			default:
			{
				printf("Invalid Choice!!");
			}
		}
	}
	getch();
}