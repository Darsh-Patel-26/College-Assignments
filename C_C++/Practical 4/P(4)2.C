#include<stdio.h>
#include<conio.h>
void main() 
{
    int num, pos_count = 0, neg_count = 0, pos_sum = 0, neg_sum = 0;
    float pos_avg, neg_mean;
    char choice;
    clrscr();

    // Using goto statement
start:
    printf("Enter a number (enter -1 to stop): ");
    scanf("%d", &num);
    if (num == -1) 
    {
        goto end;
    }
    if (num >= 0) 
    {
        pos_sum += num;
        pos_count++;
    } 
    else 
    {
        neg_sum += num;
        neg_count++;
    }
    goto start;

end:
    if (pos_count > 0) 
    {
        pos_avg = (float) pos_sum / pos_count;
        printf("Sum of positive numbers: %d\n", pos_sum);
        printf("Average of positive numbers: %.2f\n", pos_avg);
    } 
    else 
    {
        printf("No positive numbers were entered.\n");
    }
    if (neg_count > 0) 
    {
        neg_mean = (float) neg_sum / neg_count;
        printf("Sum of negative numbers: %d\n", neg_sum);
        printf("Mean of negative numbers: %.2f\n", neg_mean);
    } 
    else 
    {
        printf("No negative numbers were entered.\n");
    }

    // Using do while loop
    pos_count = 0;
    neg_count = 0;
    pos_sum = 0;
    neg_sum = 0;
    do 
    {
        printf("Enter a number (enter -1 to stop): ");
        scanf("%d", &num);
        if (num >= 0) 
        {
            pos_sum += num;
            pos_count++;
        } 
        else if (num < 0 && num != -1) 
        {
            neg_sum += num;
            neg_count++;
        }
    } while (num != -1);

    if (pos_count > 0) 
    {
        pos_avg = (float) pos_sum / pos_count;
        printf("Sum of positive numbers: %d\n", pos_sum);
        printf("Average of positive numbers: %.2f\n", pos_avg);
    } 
    else 
    {
        printf("No positive numbers were entered.\n");
    }
    if (neg_count > 0) 
    {
        neg_mean = (float) neg_sum / neg_count;
        printf("Sum of negative numbers: %d\n", neg_sum);
        printf("Mean of negative numbers: %.2f\n", neg_mean);
    } 
    else 
    {
        printf("No negative numbers were entered.\n");
    }

    getch();
}
