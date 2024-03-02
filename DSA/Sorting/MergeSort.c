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

void mergeConquerer(int arr[], int si, int midi, int ei)
{
    int sorter[ei-si+1];
    int indx1 = si;
    int indx2 = midi + 1;
    int x = 0;

    while (indx1 <= midi && indx2<= ei)
    {
        if(arr[indx1]<=arr[indx2])                  // Change the sign to change operation
        {
            sorter[x++] = arr[indx1++];
        }
        else
        {
            sorter[x++] = arr[indx2++];
        }
    }
    
    while (indx1 <= midi)
    {
        sorter[x++] = arr[indx1++];
    }
    
    while (indx2 <= ei)
    {
        sorter[x++] = arr[indx2++];
    }
    
    for (int i = 0, j = si; i < x; i++, j++)
    {
        arr[j] = sorter[i];
    }
    
}

void mergeDivider(int arr[], int si, int ei)
{
    if(si>=ei)
    {
        return;
    }
    //int midi = (ei + si)/2;
    int midi = si + (ei - si)/2;
    mergeDivider(arr, si, midi);
    mergeDivider(arr,midi+1,ei);

    mergeConquerer(arr,si,midi,ei);
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;

    printf("Enter no. of elements of array : ");
    scanf("%d", &n);
    setarray(arr, n);
    mergeDivider(arr,0,n-1);
    getarray(arr, n);
    return 0;
}