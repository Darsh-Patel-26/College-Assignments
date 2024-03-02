#include<stdio.h>
#include<conio.h>
void main()
{
    int n=18,i,c;
    int a=0;
    int b=1;
    clrscr();
    
    printf("Fibonacci Series(for 20 terms):\n");
    printf("%d %d",a,b);
    for(i=0;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        printf(" %d",c);
    }
    getch();
}