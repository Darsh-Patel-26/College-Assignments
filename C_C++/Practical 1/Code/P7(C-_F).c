#include<stdio.h>
#include<conio.h>
void main()
{
    float Celsius, Fahrenheit;
    clrscr();
    printf("Enter Temperature in Celsius:");
    scanf("%f",& Celsius);
    Fahrenheit=1.8*Celsius+32;
    printf("The Temperature Conversion in Fahrenheit is %.2f °F", Fahrenheit);
    getch();
}