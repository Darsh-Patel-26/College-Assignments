#include"iostream"

using namespace std;

int n;

void setArray(int arr[])
{
    cout<<"Enter "<<n<<" no. :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
}

void getArray(int arr[])
{
    cout<<"Array :"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int findMax(int arr[])
{
    int max = arr[0];
    for(int i = 1;i<n;i++)
    {
        if (max<arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void copyArray(int arr1[], int arr2[])
{
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

void countSort(int arr[])
{
    int max = findMax(arr);
    int *counter = (int*)calloc(max+1,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        counter[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        counter[i] += counter[i-1];
    }
    int *output = (int*)calloc(n,sizeof(int));
    for (int i = n-1; i >= 0; i--)
    {
        output[--counter[arr[i]]] = arr[i];
    }
    copyArray(arr,output);

    delete counter;
    delete output;
}

int main(int argc, char const *argv[])
{
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    setArray(arr);
    countSort(arr);
    getArray(arr);
    return 0;
}