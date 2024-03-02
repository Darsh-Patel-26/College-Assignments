#include <stdio.h>
#include <stdlib.h>

int n;

void setarray(int arr[])
{
    printf("Enter %d elements :\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void getarray(int arr[])
{
    printf("Your elements are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] += arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
}

void selectionSort(int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[key])
            {
                key = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
        // arr[i] += arr[key];
        // arr[key] = arr[i] - arr[key];
        // arr[i] = arr[i] - arr[key];
    }
}

void insertionSort(int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeConqueror(int arr[], int si, int mid, int ei)
{
    int sorter[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;

    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            sorter[x++] = arr[idx1++];
        }
        else
        {
            sorter[x++] = arr[idx2++];
        }
    }
    while (idx1 <= mid)
    {
        sorter[x++] = arr[idx1++];
    }
    while (idx2 <= ei)
    {
        sorter[x++] = arr[idx2++];
    }
    for (int i = 0, j = si; i < x; i++, j++)
    {
        arr[j] = sorter[i];
    }
}

void mergeDivider(int arr[], int si, int ei)
{
    if (si < ei)
    {
        int mid = si + (ei - si) / 2;

        mergeDivider(arr, si, mid);
        mergeDivider(arr, mid + 1, ei);

        mergeConqueror(arr, si, mid, ei);
    }
}

int partition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    int i = si + 1;
    int j = ei;
    do
    {
        while (pivot >= arr[i])
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    int temp = arr[j];
    arr[j] = arr[si];
    arr[si] = temp;

    return si;
}

void quickSort(int arr[], int si, int ei)
{
    if (si < ei)
    {
        int pivotIdx = partition(arr, si, ei);

        quickSort(arr, si, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, ei);
    }
}

void copyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

int Max(int arr[])
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[])
{
    int max = Max(arr);
    int *counter = (int*)calloc(sizeof(int),max+1);
    int *final = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        counter[arr[i]]++;
    }
    for (int i = 1; i < max+1; i++)
    {
        counter[i] += counter[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        final[--counter[arr[i]]] = arr[i];
    }
    copyArray(arr,final);
}

void countSortr(int arr[], int exp)
{
    int range = 10;
    int *counter = (int*)calloc(range,sizeof(int));
    int *final = (int*)malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        counter[(arr[i]/exp)%10]++;
    }
    for (int i = 1; i < range; i++)
    {
        counter[i] += counter[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        final[--counter[(arr[i]/exp)%10]] = arr[i];
    }
    copyArray(arr,final);
}

void radixSort(int arr[])
{
    int max = Max(arr);
    for (int exp = 1; max/exp > 0; exp*=10)
    {
        countSortr(arr,exp);
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[100];

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr);
    // bubbleSort(arr);
    // selectionSort(arr);
    // insertionSort(arr);
    // mergeDivider(arr,0,n-1);
    // quickSort(arr,0,n-1);
    // countSort(arr);
    // radixSort(arr);
    getarray(arr);
    return 0;
}