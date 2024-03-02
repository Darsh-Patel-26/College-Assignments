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

int quickDivider(int arr[], int n, int si, int ei)
{
    int pivot = ei;
    int i = si - 1;

    for (int j = si; j < n; j++)
    {
        if (arr[pivot] > arr[j])            // Change condition to change sorting
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;

    return i;
}

void quickSort(int arr[], int n, int si, int ei)
{
    if (si<ei)
    {
        int pivotIdx = quickDivider(arr,n,si,ei);

        quickSort(arr,n,si,pivotIdx-1);
        quickSort(arr,n,pivotIdx+1,ei);
    }   
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr, n);
    quickSort(arr,n,0,n-1);
    getarray(arr, n);
    return 0;
}