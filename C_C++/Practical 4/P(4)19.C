#include<stdio.h>
#include<conio.h>
void main() 
{
    int day, month, year;
    char c;
    clrscr();
    
    do {
        printf("Enter date in dd-mm-yyyy format: ");
        scanf("%d%d%d", &day, &month, &year);

        int q = day;
        int m = month;
        int y = year;

        if (m == 1 || m == 2) 
        {
            m += 12;
            y--;
        }

        int h = (q + 13 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 -1;

        switch (h) 
        {
            case 0:
                printf("Sunday\n");
                break;
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
            default:
                printf("Invalid date\n");
        }

        printf("Do you want to enter another date? (y/n): ");
        scanf(" %c", &c); // notice the space before %c to consume the newline character

    } while (c == 'y' || c == 'Y');

    getch();
}
