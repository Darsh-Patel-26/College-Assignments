#include <stdio.h>
#include <stdlib.h>

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

void copyArray(int arr1[], int arr2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

void reverseArray(int arr[], int n)
{
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n)
{
    int max = findMax(arr,n);
    int *counter = (int*)calloc(max+1,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        counter[arr[i]]++;
    }
    //getarray(counter,max+1);
    for (int i = 1; i < max+1; i++)
    {
        counter[i] += counter[i-1];
    }
    //getarray(counter,max+1);
    int *final = (int *)calloc(n,sizeof(int));
    for (int i = n-1; i >= 0; i--)
    {
        final[--counter[arr[i]]] = arr[i];
    }
    //reverseArray(final,n);                            //Enable this to change the operation
    copyArray(arr,final,n);
    free(counter);
    free(final);
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr, n);
    countingSort(arr,n);
    getarray(arr,n);
    return 0;
}