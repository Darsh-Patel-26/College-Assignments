#include<stdio.h>
#include<conio.h>
void main()
{
    float Celsius, Fahrenheit;
    clrscr();
    printf("Enter Temperature in Fahrenheit:");
    scanf("%f",& Fahrenheit);
    Celsius=(Fahrenheit-32)/1.8;
    printf("The Temperature Conversion in Celsius is %.2f °C", Celsius);
    getch();
}