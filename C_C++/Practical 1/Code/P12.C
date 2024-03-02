#include<stdio.h>
#include<conio.h>
enum Direction 
{
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};

void main() 
{
    enum Direction dir = EAST;
    clrscr();
    printf("The current direction is %d\n", dir);
    dir = WEST;
    printf("The current direction is now %d\n", dir);
    getch();
}
