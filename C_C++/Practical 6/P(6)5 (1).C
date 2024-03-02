#include <stdio.h>

int main() 
{
    int arr[] = {1, 5, 3, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0], min = arr[0];

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }

    printf("Maximum element in array: %d\n", max);
    printf("Minimum element in array: %d\n", min);

    return 0;
}
