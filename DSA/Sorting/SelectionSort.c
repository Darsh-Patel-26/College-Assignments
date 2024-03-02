#include <stdio.h>

void setarray(int arr[], int n)
{
    printf("Enter %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void getarray(int arr[], int n)
{
    printf("Your elements are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[key] > arr[j])              // Change the sign to change operation
            {
                key = j;
            }
        }
        int temp = arr[key];
        arr[key] = arr[i];
        arr[i] = temp;
    }
    printf("The array is sorted by Selection Sort.\n");
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr, n);
    selectionSort(arr, n);
    getarray(arr, n);
    return 0;
}