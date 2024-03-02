#include <stdio.h>

int main() 
{
    int arr[100], n, x, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == x) 
        {
            printf("Element found at index %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        arr[n] = x;
        n++;
        printf("Element not found, inserted at index %d.\n", n-1);
    }

    printf("The elements of the array are: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
