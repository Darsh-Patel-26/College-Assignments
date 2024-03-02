#include <stdio.h>
#include<stdlib.h>

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

void Getarray(int arr[], int m)
{
    printf("Your elements are :\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

void reverseArray(int arr[])
{
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int findMax(int arr[])
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

void countSort(int arr[], int exp)
{
    int range = 10;
    int *counter = (int*)calloc(range,sizeof(int));
    int *final = (int*)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        counter[(arr[i]/exp)%10]++;
    }
    //Getarray(counter,range);
    for (int i = 1; i < range; i++)
    {
        counter[i] += counter[i-1];
    }
    //Getarray(counter,range);
    for (int i = n-1; i >= 0; i--)
    {
        final[--counter[(arr[i]/exp)%10]] = arr[i];
    }
    //Getarray(counter,range);
    //getarray(final);
    copyArray(arr,final);
    //reverseArray(arr);                // Use this to change order
    free(counter);
    free(final);
}

void radixSort(int arr[])
{
    int max = findMax(arr);
    for (int exp = 1; max/exp > 0; exp*=10)
    {
        countSort(arr,exp);
    }
}

int main(int argc, char const *argv[])
{
    int arr[100];

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr);
    radixSort(arr);
    getarray(arr);
    return 0;
}