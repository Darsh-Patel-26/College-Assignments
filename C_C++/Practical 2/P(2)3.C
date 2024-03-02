#include<stdio.h>  
#include<conio.h> 
void main()
{
    int a,b,max;
    clrscr();
    printf("Enter Two numbers:");
    scanf("%d%d",&a,&b);
    max= (a>b)?a:b;
    printf("The maximum number among %d and %d is %d",a,b,max);
    getch();
}