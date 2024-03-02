#include<stdio.h>
#include<conio.h>

// Define the time_struct data type
struct time_struct 
{
    int hour;
    int minute;
    int second;
};

void main() 
{
    // Create a variable of type time_struct
    struct time_struct time;
    clrscr();
    
    // Assign values to the members of the time_struct
    printf("Enter Hour in 24 hr system:");
    scanf("%d",&time.hour);
        
    printf("Enter Minutes:");
    scanf("%d",&time.minute);
        
    printf("Enter Seconds:");
    scanf("%d",&time.second);
        
    // Display the time in the desired format
    printf("%d:%d:%d\n", time.hour, time.minute, time.second);

    getch();
}
