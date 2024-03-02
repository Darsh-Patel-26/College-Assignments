#include<stdio.h>  
#include<conio.h> 
void main()
{
    int a,b,c,max;
    clrscr();
    printf("Enter Three numbers:");
    scanf("%d%d%d",&a,&b,&c);
    max= (a>b)?((a>c)?a:c):((b>c)?b:c);
    printf("The maximum number among %d, %d and %d is %d",a,b,c,max);
    getch();
}