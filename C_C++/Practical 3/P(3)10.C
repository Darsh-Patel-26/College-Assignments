#include<stdio.h>
#include<conio.h>
void main() 
{
    int units;
    float bill_amount, meter_charge = 100.00;
    clrscr();
    printf("Enter the number of units consumed: ");
    scanf("%d", &units);

    if (units <= 200) 
    {
        bill_amount = units * 0.80;
    }
    else if (units <= 300) 
    {
        bill_amount = 200 * 0.80 + (units - 200) * 0.90;
    }
    else 
    {
        bill_amount = 200 * 0.80 + 100 * 0.90 + (units - 300) * 1.00;
    }


    if (bill_amount > 400.00) 
    {
        bill_amount += meter_charge;
        bill_amount += bill_amount * 0.15;
    }

    printf("Electricity bill: Rs. %.2f\n", bill_amount);

    getch();
}
