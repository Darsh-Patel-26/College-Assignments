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

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    int i = si+1;
    int j = ei;
    do
    {
        while (pivot>=arr[i])           // Change condition to change sorting
        {
            i++;
        }
        
        while (pivot<arr[j])            // Change condition to change sorting
        {
            j--;
        }
        
        if (i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i<j);

    int temp = arr[si];
    arr[si] = arr[j];
    arr[j] = temp;

    return si;
}

void quickSort(int arr[], int si, int ei)
{
    if (si<ei)
    {
        int pivotIdx = partition(arr,si,ei);

        quickSort(arr,si,pivotIdx-1);
        quickSort(arr,pivotIdx+1,ei);
    }   
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr, n);
    quickSort(arr,0,n-1);
    getarray(arr, n);
    return 0;
}