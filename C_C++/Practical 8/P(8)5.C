#include<stdio.h>
#include<conio.h>

// Define a union
union Data 
{
    int i;
    float f;
    char str[20];
};

void main() 
{
    union Data data;
    clrscr();

    // Assign a value to the integer member
    data.i = 10;
    printf("data.i: %d\n", data.i);

    // Assign a value to the float member
    data.f = 3.14;
    printf("data.f: %f\n", data.f);

    // Assign a value to the string member
    strcpy(data.str, "Hello World!");
    printf("data.str: %s\n", data.str);

    getch();
}
    